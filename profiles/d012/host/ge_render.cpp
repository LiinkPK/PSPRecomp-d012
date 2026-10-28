// PSP GE software rasterizer — minimal implementation for title-screen rendering.
// Handles: CLEAR, 2D textured sprites (PRIM GU_SPRITES), flat-color primitives,
//          texture sampling (RGBA8888, RGB565, RGBA4444, RGBA5551, DXT), CLUT.
// Does NOT handle: 3D perspective, lighting, fog, stencil, depth test, blend modes
//                  beyond alpha-blend-over, mipmaps.  Sufficient for UI/title screens.

#include "ge_render.hpp"
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

namespace d012 {

// ---- helpers ----------------------------------------------------------------

static inline std::uint32_t to_abgr8888(std::uint32_t psp_color, int fmt) {
    // PSP pixel formats → ABGR8888 (our internal format = same as VRAM RGBA8888 layout)
    switch (fmt) {
    case 0: { // RGB565
        std::uint16_t p = static_cast<std::uint16_t>(psp_color);
        std::uint8_t r = (p >> 11) & 0x1F; r = (r << 3) | (r >> 2);
        std::uint8_t g = (p >>  5) & 0x3F; g = (g << 2) | (g >> 4);
        std::uint8_t b =  p        & 0x1F; b = (b << 3) | (b >> 2);
        return 0xFF000000u | (static_cast<std::uint32_t>(b) << 16) |
               (static_cast<std::uint32_t>(g) << 8) | r;
    }
    case 1: { // RGBA5551
        std::uint16_t p = static_cast<std::uint16_t>(psp_color);
        std::uint8_t r = (p >> 11) & 0x1F; r = (r << 3) | (r >> 2);
        std::uint8_t g = (p >>  6) & 0x1F; g = (g << 3) | (g >> 2);
        std::uint8_t b = (p >>  1) & 0x1F; b = (b << 3) | (b >> 2);
        std::uint8_t a = (p & 1) ? 0xFF : 0;
        return (static_cast<std::uint32_t>(a) << 24) | (static_cast<std::uint32_t>(b) << 16) |
               (static_cast<std::uint32_t>(g) << 8) | r;
    }
    case 2: { // RGBA4444
        std::uint16_t p = static_cast<std::uint16_t>(psp_color);
        std::uint8_t r = (p >> 12) & 0xF; r = (r << 4) | r;
        std::uint8_t g = (p >>  8) & 0xF; g = (g << 4) | g;
        std::uint8_t b = (p >>  4) & 0xF; b = (b << 4) | b;
        std::uint8_t a =  p        & 0xF; a = (a << 4) | a;
        return (static_cast<std::uint32_t>(a) << 24) | (static_cast<std::uint32_t>(b) << 16) |
               (static_cast<std::uint32_t>(g) << 8) | r;
    }
    case 3: // RGBA8888 — already in right format (ABGR on PSP = RGBA in memory)
        return psp_color;
    default:
        return 0xFF00FFFFu; // magenta = unknown
    }
}

static inline void blend_pixel(std::uint32_t *dst, std::uint32_t src_abgr) {
    const std::uint32_t sa = (src_abgr >> 24) & 0xFF;
    if (sa == 0) return;
    if (sa == 0xFF) { *dst = src_abgr; return; }
    const std::uint32_t da = 255 - sa;
    const std::uint32_t dr = ((*dst >>  0) & 0xFF) * da / 255 + ((src_abgr >>  0) & 0xFF) * sa / 255;
    const std::uint32_t dg = ((*dst >>  8) & 0xFF) * da / 255 + ((src_abgr >>  8) & 0xFF) * sa / 255;
    const std::uint32_t db = ((*dst >> 16) & 0xFF) * da / 255 + ((src_abgr >> 16) & 0xFF) * sa / 255;
    *dst = 0xFF000000u | (db << 16) | (dg << 8) | dr;
}

// ---- GE state ---------------------------------------------------------------

struct GeState {
    // Addresses (host physical — already masked to 0x1FFFFFFF)
    std::uint32_t base_extended = 0;      // BASE register: bits 24-27 of address
    std::uint32_t offset_address = 0;     // OFFSETADDR: added on top of base_extended
    std::uint32_t base_addr = 0;          // combined = base_extended | offset_address (legacy, keep for JUMP)
    std::uint32_t vaddr     = 0;          // VADDR (vertex buffer)
    std::uint32_t iaddr     = 0;          // IADDR (index buffer)

    // Texture
    std::uint32_t tbp[8]    = {};         // TBP0-7: texture base pointers (phys)
    std::uint32_t tbw[8]    = {};         // TBW0-7: texture buffer widths (pixels)
    std::uint32_t tw = 1, th = 1;        // texture dimensions (actual, not log2)
    int  tfmt       = 3;                 // texture pixel format (0=RGB565,3=RGBA8888)
    bool tex_enabled = false;

    // Vertex type (VTYPE register 0xA0)
    std::uint32_t vtype     = 0;

    // Color register (for flat primitives)
    std::uint32_t color     = 0xFFFFFFFFu;

    // Framebuffer target (set by DRAW* commands)
    std::uint32_t fbp       = 0;         // framebuffer base (phys, into VRAM, byte offset)
    std::uint32_t fbw       = 512;       // framebuffer stride (pixels)
    int           fbfmt     = 3;         // 0=RGB565, 1=RGBA5551, 2=RGBA4444, 3=RGBA8888

    // Scissor
    int sc_x1 = 0, sc_y1 = 0, sc_x2 = 480, sc_y2 = 272;

    // Clear mode
    bool clear_mode = false;
    std::uint32_t clear_color = 0;

    // Depth buffer (phys)
    std::uint32_t zbp = 0;
    std::uint32_t zbw = 512;

    // Offset (for 2D pixel-center adjustment)
    int offset_x = 0, offset_y = 0;
};

// ---- vertex decoding --------------------------------------------------------
// VTYPE bits:
//  1:0  = texture coord type  (0=none,1=u8,2=s16,3=f32)
//  3:2  = color type          (0=none,4=RGBA8888,5=...,7=RGBA8888)
//  6:4  = normal type         (0=none,1=u8,2=s16,3=f32)
//  9:7  = position type       (1=u8,2=s16,3=f32)
// 11:10 = weight type
// 14:12 = index type          (0=none,1=u8,2=u16)
// 23:18 = num weights
// 26:24 = num bones
// 27    = morph count
// 28    = bypass transform (1 = screen-space / 2D)

struct Vertex {
    float u = 0, v = 0;   // texture coords (in [0..1] if BYPASS else [0..tw])
    std::uint32_t color = 0xFFFFFFFFu;
    float x = 0, y = 0, z = 0;
};

static std::uint32_t vtype_tex_type(std::uint32_t vt)  { return  vt        & 3; }
static std::uint32_t vtype_col_type(std::uint32_t vt)  { return (vt >>  2) & 7; }
static std::uint32_t vtype_nor_type(std::uint32_t vt)  { return (vt >>  5) & 3; }  // was 4 bits — actually bits 6:5
static std::uint32_t vtype_pos_type(std::uint32_t vt)  { return (vt >>  7) & 3; }
static std::uint32_t vtype_wgt_type(std::uint32_t vt)  { return (vt >> 10) & 3; }
static std::uint32_t vtype_idx_type(std::uint32_t vt)  { return (vt >> 11) & 3; }
static std::uint32_t vtype_nwgt(std::uint32_t vt)      { return (vt >> 14) & 7; }  // was 18..23
static bool          vtype_bypass(std::uint32_t vt)    { return  (vt >> 23) & 1; }

// Read an aligned value from the vertex stream and advance ptr
static float read_f32(const std::uint8_t *&p) {
    float v; std::memcpy(&v, p, 4); p += 4; return v;
}
static float read_s16n(const std::uint8_t *&p) {
    std::int16_t v; std::memcpy(&v, p, 2); p += 2;
    return v / 32767.0f;
}
static float read_u8n(const std::uint8_t *&p) {
    return (*p++) / 255.0f;
}

static Vertex decode_vertex(const std::uint8_t *&p, std::uint32_t vt) {
    Vertex v;
    const std::uint32_t tc  = vtype_tex_type(vt);
    const std::uint32_t cc  = vtype_col_type(vt);
    const std::uint32_t nc  = vtype_nor_type(vt);
    const std::uint32_t pc  = vtype_pos_type(vt);
    const std::uint32_t wc  = vtype_wgt_type(vt);
    const std::uint32_t nw  = vtype_nwgt(vt);

    // Align to natural boundary before each field
    auto align = [&](int a) { p = reinterpret_cast<const std::uint8_t*>((reinterpret_cast<std::uintptr_t>(p) + a - 1) & ~(std::uintptr_t)(a - 1)); };

    // Weights (skip)
    for (std::uint32_t i = 0; i < nw; ++i) {
        if (wc == 1) { ++p; }
        else if (wc == 2) { align(2); p += 2; }
        else if (wc == 3) { align(4); p += 4; }
    }

    // Texture coords
    if (tc == 1) { v.u = read_u8n(p); v.v = read_u8n(p); }
    else if (tc == 2) { align(2); v.u = read_s16n(p); v.v = read_s16n(p); }
    else if (tc == 3) { align(4); v.u = read_f32(p); v.v = read_f32(p); }

    // Color
    if (cc == 4 || cc == 7) { align(4); std::uint32_t c; std::memcpy(&c, p, 4); v.color = c; p += 4; }
    else if (cc == 5) { align(2); std::uint16_t c; std::memcpy(&c, p, 2); v.color = to_abgr8888(c, 1); p += 2; }
    else if (cc == 6) { align(2); std::uint16_t c; std::memcpy(&c, p, 2); v.color = to_abgr8888(c, 2); p += 2; }

    // Normal (skip)
    if (nc == 1) { p += 3; }
    else if (nc == 2) { align(2); p += 6; }
    else if (nc == 3) { align(4); p += 12; }

    // Position
    if (pc == 1) { v.x = *p++; v.y = *p++; v.z = *p++; }
    else if (pc == 2) { align(2); std::int16_t x,y,z; std::memcpy(&x,p,2);p+=2; std::memcpy(&y,p,2);p+=2; std::memcpy(&z,p,2);p+=2; v.x=(float)x; v.y=(float)y; v.z=(float)z; }
    else if (pc == 3) { align(4); v.x=read_f32(p); v.y=read_f32(p); v.z=read_f32(p); }

    return v;
}

// ---- texture sampling -------------------------------------------------------

// Resolve a PSP physical texture address to a host pointer into mem or vram.
// mem starts at kPhysicalBase (0x08000000); vram starts at 0x04000000.
static const std::uint8_t *resolve_tex_ptr(std::uint32_t phys, std::size_t nbytes,
                                             const void *mem, std::size_t mem_size,
                                             const void *vram, std::size_t vram_size) {
    // If upper byte is 0, default to VRAM (same as PortableKit resolve_ge_address)
    if ((phys & 0xFF000000u) == 0u) phys |= 0x04000000u;
    static constexpr std::uint32_t kPhysBase = 0x08000000u;
    if (phys >= 0x04000000u && phys < 0x08000000u) {
        const std::uint32_t off = phys & 0x1FFFFFu;
        if (off + nbytes <= vram_size) return static_cast<const std::uint8_t*>(vram) + off;
    } else if (phys >= kPhysBase) {
        const std::uint32_t off = phys - kPhysBase;
        if (off + nbytes <= mem_size) return static_cast<const std::uint8_t*>(mem) + off;
    }
    return nullptr;
}

static std::uint32_t sample_tex(const GeState &gs, float u, float v,
                                 const void *mem, std::size_t mem_size,
                                 const void *vram = nullptr, std::size_t vram_size = 0) {
    if (!gs.tex_enabled || gs.tbp[0] == 0) return 0xFFFFFFFFu;
    // Clamp
    int tw = static_cast<int>(gs.tw), th = static_cast<int>(gs.th);
    int tx = static_cast<int>(u) % tw; if (tx < 0) tx += tw;
    int ty = static_cast<int>(v) % th; if (ty < 0) ty += th;
    tx = std::clamp(tx, 0, tw - 1);
    ty = std::clamp(ty, 0, th - 1);

    const std::uint32_t stride = gs.tbw[0] ? gs.tbw[0] : static_cast<std::uint32_t>(tw);
    std::uint32_t raw = 0;
    switch (gs.tfmt) {
    case 0: { // RGB565 (2 bytes/pixel)
        const std::uint32_t poff = (static_cast<std::uint32_t>(ty) * stride + static_cast<std::uint32_t>(tx)) * 2;
        const std::uint8_t *p = resolve_tex_ptr(gs.tbp[0] + poff, 2, mem, mem_size, vram, vram_size);
        if (p) { std::uint16_t v16; std::memcpy(&v16, p, 2); raw = v16; }
        return to_abgr8888(raw, 0);
    }
    case 1: { // RGBA5551
        const std::uint32_t poff = (static_cast<std::uint32_t>(ty) * stride + static_cast<std::uint32_t>(tx)) * 2;
        const std::uint8_t *p = resolve_tex_ptr(gs.tbp[0] + poff, 2, mem, mem_size, vram, vram_size);
        if (p) { std::uint16_t v16; std::memcpy(&v16, p, 2); raw = v16; }
        return to_abgr8888(raw, 1);
    }
    case 2: { // RGBA4444
        const std::uint32_t poff = (static_cast<std::uint32_t>(ty) * stride + static_cast<std::uint32_t>(tx)) * 2;
        const std::uint8_t *p = resolve_tex_ptr(gs.tbp[0] + poff, 2, mem, mem_size, vram, vram_size);
        if (p) { std::uint16_t v16; std::memcpy(&v16, p, 2); raw = v16; }
        return to_abgr8888(raw, 2);
    }
    case 3: { // RGBA8888
        const std::uint32_t poff = (static_cast<std::uint32_t>(ty) * stride + static_cast<std::uint32_t>(tx)) * 4;
        const std::uint8_t *p = resolve_tex_ptr(gs.tbp[0] + poff, 4, mem, mem_size, vram, vram_size);
        if (p) std::memcpy(&raw, p, 4);
        return raw;
    }
    default:
        return 0xFFFFFFFFu;
    }
}

// ---- draw sprite (2-vertex quad, screen-space) ------------------------------

static void draw_sprite(const GeState &gs, const Vertex &v0, const Vertex &v1,
                        void *vram, std::size_t vram_size,
                        const void *mem, std::size_t mem_size) {
    // v0 = top-left UV + XY, v1 = bottom-right UV + XY
    int x0 = static_cast<int>(v0.x), y0 = static_cast<int>(v0.y);
    int x1 = static_cast<int>(v1.x), y1 = static_cast<int>(v1.y);
    if (x0 > x1) std::swap(x0, x1);
    if (y0 > y1) std::swap(y0, y1);

    // Clip to scissor
    x0 = std::max(x0, gs.sc_x1); y0 = std::max(y0, gs.sc_y1);
    x1 = std::min(x1, gs.sc_x2); y1 = std::min(y1, gs.sc_y2);
    x0 = std::max(x0, 0); y0 = std::max(y0, 0); x1 = std::min(x1, 512); y1 = std::min(y1, 272);
    if (x0 >= x1 || y0 >= y1) return;

    const float du = (gs.tex_enabled && x1 > x0)
        ? (v1.u - v0.u) / static_cast<float>(static_cast<int>(v1.x) - static_cast<int>(v0.x))
        : 0.0f;
    const float dv = (gs.tex_enabled && y1 > y0)
        ? (v1.v - v0.v) / static_cast<float>(static_cast<int>(v1.y) - static_cast<int>(v0.y))
        : 0.0f;

    const int bpp = (gs.fbfmt == 3) ? 4 : 2;
    const std::size_t row_bytes = static_cast<std::size_t>(gs.fbw) * bpp;

    for (int y = y0; y < y1; ++y) {
        const float fv = v0.v + static_cast<float>(y - static_cast<int>(v0.y)) * dv;
        const std::size_t row_off = gs.fbp + static_cast<std::size_t>(y) * row_bytes;
        if (row_off + static_cast<std::size_t>(x1) * bpp > vram_size) continue;
        auto *dst32 = reinterpret_cast<std::uint32_t *>(static_cast<char *>(vram) + row_off);
        auto *dst16 = reinterpret_cast<std::uint16_t *>(static_cast<char *>(vram) + row_off);

        for (int x = x0; x < x1; ++x) {
            const float fu = v0.u + static_cast<float>(x - static_cast<int>(v0.x)) * du;
            std::uint32_t pixel;
            if (gs.tex_enabled)
                pixel = sample_tex(gs, fu, fv, mem, mem_size, vram, vram_size);
            else
                pixel = v1.color;

            if (gs.fbfmt == 3) {
                blend_pixel(&dst32[x], pixel);
            } else {
                const std::uint8_t r = (pixel >>  0) & 0xFF;
                const std::uint8_t g = (pixel >>  8) & 0xFF;
                const std::uint8_t b = (pixel >> 16) & 0xFF;
                const std::uint8_t a = (pixel >> 24) & 0xFF;
                if (gs.fbfmt == 0) // RGB565
                    dst16[x] = static_cast<std::uint16_t>(((r>>3)<<11)|((g>>2)<<5)|(b>>3));
                else if (gs.fbfmt == 1) // RGBA5551
                    dst16[x] = static_cast<std::uint16_t>(((r>>3)<<11)|((g>>3)<<6)|((b>>3)<<1)|(a>>7));
                else // RGBA4444
                    dst16[x] = static_cast<std::uint16_t>(((r>>4)<<12)|((g>>4)<<8)|((b>>4)<<4)|(a>>4));
            }
        }
    }
}

// ---- draw triangle ----------------------------------------------------------

static void draw_triangle(const GeState &gs,
                           const Vertex &v0, const Vertex &v1, const Vertex &v2,
                           void *vram, std::size_t vram_size,
                           const void *mem,  std::size_t mem_size) {
    // Simple scanline rasterizer (no perspective correction)
    // Bounding box
    int minx = std::max(gs.sc_x1, (int)std::min({v0.x, v1.x, v2.x}));
    int maxx = std::min(gs.sc_x2, (int)std::max({v0.x, v1.x, v2.x}) + 1);
    int miny = std::max(gs.sc_y1, (int)std::min({v0.y, v1.y, v2.y}));
    int maxy = std::min(gs.sc_y2, (int)std::max({v0.y, v1.y, v2.y}) + 1);
    minx = std::max(minx, 0); miny = std::max(miny, 0); maxx = std::min(maxx, 512); maxy = std::min(maxy, 272);
    if (minx >= maxx || miny >= maxy) return;

    const float denom = (v1.y - v2.y) * (v0.x - v2.x) + (v2.x - v1.x) * (v0.y - v2.y);
    if (std::abs(denom) < 1e-6f) return;
    const float inv_denom = 1.0f / denom;

    const int bpp = (gs.fbfmt == 3) ? 4 : 2;
    const std::size_t row_bytes = static_cast<std::size_t>(gs.fbw) * bpp;

    for (int y = miny; y < maxy; ++y) {
        const std::size_t row_off = gs.fbp + static_cast<std::size_t>(y) * row_bytes;
        if (row_off + static_cast<std::size_t>(maxx) * bpp > vram_size) continue;
        auto *dst32 = reinterpret_cast<std::uint32_t *>(static_cast<char *>(vram) + row_off);
        auto *dst16 = reinterpret_cast<std::uint16_t *>(static_cast<char *>(vram) + row_off);

        for (int x = minx; x < maxx; ++x) {
            const float px = static_cast<float>(x) + 0.5f;
            const float py = static_cast<float>(y) + 0.5f;
            float w0 = ((v1.y - v2.y) * (px - v2.x) + (v2.x - v1.x) * (py - v2.y)) * inv_denom;
            float w1 = ((v2.y - v0.y) * (px - v2.x) + (v0.x - v2.x) * (py - v2.y)) * inv_denom;
            float w2 = 1.0f - w0 - w1;
            if (w0 < 0 || w1 < 0 || w2 < 0) continue;

            std::uint32_t pixel;
            if (gs.tex_enabled) {
                float fu = w0 * v0.u + w1 * v1.u + w2 * v2.u;
                float fv = w0 * v0.v + w1 * v1.v + w2 * v2.v;
                pixel = sample_tex(gs, fu, fv, mem, mem_size, vram, vram_size);
            } else {
                std::uint32_t c0 = v0.color, c1 = v1.color, c2 = v2.color;
                auto chan = [&](int shift) -> std::uint32_t {
                    return static_cast<std::uint32_t>(
                        w0 * ((c0 >> shift) & 0xFF) +
                        w1 * ((c1 >> shift) & 0xFF) +
                        w2 * ((c2 >> shift) & 0xFF));
                };
                pixel = (chan(24) << 24) | (chan(16) << 16) | (chan(8) << 8) | chan(0);
            }

            if (gs.fbfmt == 3) {
                blend_pixel(&dst32[x], pixel);
            } else {
                const std::uint8_t r = (pixel >>  0) & 0xFF;
                const std::uint8_t g = (pixel >>  8) & 0xFF;
                const std::uint8_t b = (pixel >> 16) & 0xFF;
                const std::uint8_t a = (pixel >> 24) & 0xFF;
                if (gs.fbfmt == 0)
                    dst16[x] = static_cast<std::uint16_t>(((r>>3)<<11)|((g>>2)<<5)|(b>>3));
                else if (gs.fbfmt == 1)
                    dst16[x] = static_cast<std::uint16_t>(((r>>3)<<11)|((g>>3)<<6)|((b>>3)<<1)|(a>>7));
                else
                    dst16[x] = static_cast<std::uint16_t>(((r>>4)<<12)|((g>>4)<<8)|((b>>4)<<4)|(a>>4));
            }
        }
    }
}

// ---- draw line (Bresenham) --------------------------------------------------

static void draw_line(const GeState &gs, const Vertex &v0, const Vertex &v1,
                      void *vram, std::size_t vram_size) {
    int x0 = static_cast<int>(v0.x), y0 = static_cast<int>(v0.y);
    int x1 = static_cast<int>(v1.x), y1 = static_cast<int>(v1.y);
    const int bpp = (gs.fbfmt == 3) ? 4 : 2;
    const std::size_t row_bytes = static_cast<std::size_t>(gs.fbw) * bpp;

    if (std::abs(static_cast<long long>(x1) - x0) > 2048 || std::abs(static_cast<long long>(y1) - y0) > 2048) return;
    const int dx = std::abs(x1 - x0), sx = (x0 < x1) ? 1 : -1;
    const int dy = -std::abs(y1 - y0), sy = (y0 < y1) ? 1 : -1;
    int err = dx + dy;

    const std::uint32_t line_color = v1.color != 0xFFFFFFFFu ? v1.color : gs.color;

    for (;;) {
        if (x0 >= gs.sc_x1 && x0 < gs.sc_x2 && y0 >= gs.sc_y1 && y0 < gs.sc_y2) {
            const std::size_t off = gs.fbp + static_cast<std::size_t>(y0) * row_bytes;
            if (off + static_cast<std::size_t>(x0 + 1) * bpp <= vram_size) {
                if (gs.fbfmt == 3) {
                    auto *dst = reinterpret_cast<std::uint32_t*>(static_cast<char*>(vram) + off);
                    blend_pixel(&dst[x0], line_color);
                } else {
                    auto *dst = reinterpret_cast<std::uint16_t*>(static_cast<char*>(vram) + off);
                    const std::uint8_t r = (line_color >>  0) & 0xFF;
                    const std::uint8_t g = (line_color >>  8) & 0xFF;
                    const std::uint8_t b = (line_color >> 16) & 0xFF;
                    const std::uint8_t a = (line_color >> 24) & 0xFF;
                    if (gs.fbfmt == 0)
                        dst[x0] = static_cast<std::uint16_t>(((r>>3)<<11)|((g>>2)<<5)|(b>>3));
                    else if (gs.fbfmt == 1)
                        dst[x0] = static_cast<std::uint16_t>(((r>>3)<<11)|((g>>3)<<6)|((b>>3)<<1)|(a>>7));
                    else
                        dst[x0] = static_cast<std::uint16_t>(((r>>4)<<12)|((g>>4)<<8)|((b>>4)<<4)|(a>>4));
                }
            }
        }
        if (x0 == x1 && y0 == y1) break;
        const int e2 = 2 * err;
        if (e2 >= dy) { err += dy; x0 += sx; }
        if (e2 <= dx) { err += dx; y0 += sy; }
    }
}

// ---- main executor ----------------------------------------------------------

int          d012::g_ge_last_fbfmt = 3;
std::uint32_t d012::g_ge_last_fbp  = 0;
std::uint32_t d012::g_ge_last_fbw  = 512;

void ge_exec(const std::uint32_t *dl, const std::uint32_t *dl_end,
             void *vram, std::size_t vram_size,
             const void *mem, std::size_t mem_size,
             std::uint32_t initial_base_addr) {
    if (!dl || !vram) return;

    GeState gs;
    gs.base_extended = initial_base_addr;
    gs.base_addr = initial_base_addr;
    static std::uint32_t s_exec_count = 0;
    ++s_exec_count;
    std::printf("[GE] exec #%u dl=%p dl_end=%p span=%zu\n", s_exec_count, (void*)dl, (void*)dl_end, (std::size_t)(dl_end - dl));
    std::fflush(stdout);

    // Dump raw DL for diagnosis — first 4 execs OR after scene activation (execs 5-20)
    { static std::uint32_t s_dc = 0; ++s_dc;
      const bool do_dump = (s_dc <= 4) || (s_dc >= 5 && s_dc <= 20);
      if (do_dump) {
        std::size_t lim = (std::size_t)(dl_end - dl); if (lim > 512) lim = 512;
        std::printf("[GE-RAW#%u] span=%zu words:\n", s_dc, lim);
        for (std::size_t i = 0; i < lim; ++i) {
            if (i % 8 == 0) std::printf("  %04zx:", i*4);
            std::printf(" %08X", dl[i]);
            if (i % 8 == 7 || i+1 == lim) std::printf("\n");
        }
        fflush(stdout);
      }
    }
    // Parse commands. dl_end is the hard limit for the initial segment.
    // After a JUMP we follow the chain freely but still respect memory bounds.
    std::uint32_t jump_history[16] = {};
    int jump_history_cnt = 0;
    const std::uint32_t *p = dl;
    bool jumped = false; // set true after first JUMP
    for (std::uint32_t insn_limit = 0; insn_limit < 1000000u; ++insn_limit, ++p) {
        // Before a JUMP, stop at dl_end (don't read past the submitted range)
        if (!jumped && p >= dl_end) break;
        // After a JUMP, verify we're in a known region
        if (jumped) {
            const uintptr_t p_host = reinterpret_cast<uintptr_t>(p);
            const uintptr_t mem_base = reinterpret_cast<uintptr_t>(mem);
            const uintptr_t vram_base = reinterpret_cast<uintptr_t>(vram);
            bool in_mem  = (p_host >= mem_base  && p_host + 4 <= mem_base  + mem_size);
            bool in_vram = (p_host >= vram_base && p_host + 4 <= vram_base + vram_size);
            if (!in_mem && !in_vram) break;
        }
        const std::uint32_t cmd = *p;
        const std::uint8_t  op  = static_cast<std::uint8_t>(cmd >> 24);
        const std::uint32_t arg = cmd & 0x00FFFFFFu;

        switch (op) {
        case 0x00: case 0xFF: break; // NOP

        // Control flow
        case 0x08: { // JUMP — unconditional jump to address (base_extended | arg, lower 2 bits = 0)
            const std::uint32_t target_phys = ((gs.base_extended & 0xFF000000u) | arg) & 0x1FFFFFFFu;
            const std::uint32_t *new_p = nullptr;
            if (target_phys >= 0x08000000u && (target_phys - 0x08000000u) < mem_size)
                new_p = reinterpret_cast<const std::uint32_t *>(static_cast<const char *>(mem) + (target_phys - 0x08000000u));
            else if (target_phys >= 0x04000000u && target_phys < 0x06000000u) {
                const std::uint32_t voff = target_phys & 0x1FFFFFu;
                if (voff < vram_size)
                    new_p = reinterpret_cast<const std::uint32_t *>(static_cast<const char *>(vram) + voff);
            }
            { static std::uint32_t s_jmp = 0;
              if (++s_jmp <= 8) {
                  std::printf("[GE-JUMP] target=0x%08X %s\n", target_phys, new_p?"OK":"MISS");
                  fflush(stdout);
              } }
            // Guard: detect jump cycles (render chain node pointing to itself)
            if (new_p && new_p == p + 1) { goto done; }
            if (new_p && new_p == p)     { goto done; }
            if (new_p) {
                // Detect cycles: stop if we've jumped to this target before
                bool cycle = false;
                for (int i = 0; i < jump_history_cnt; ++i)
                    if (jump_history[i] == target_phys) { cycle = true; break; }
                if (cycle) { goto done; }
                if (jump_history_cnt < 16) jump_history[jump_history_cnt++] = target_phys;
                p = new_p - 1; jumped = true;
            }
            break;
        }
        case 0x09: break; // BJUMP — conditional branch (ignore, treat as not-taken)
        case 0x0A: break; // CALL — subroutine call (stub: ignore for now)
        case 0x0B: break; // RET — return from subroutine (stub: ignore)
        case 0x0C: goto done; // END terminates the list
        case 0x0E: break; // SIGNAL — ignore
        case 0x0F:        // FINISH — end of list
            goto done;

        // Address/BASE — BASE supplies the four high bits; OFFSETADDR is added on top.
        // These must be kept separate: letting OFFSETADDR overwrite BASE corrupts all
        // subsequent vertex/index/texture address resolution (PortableKit ge_state.cpp).
        case 0x10: // BASE — bits 23:20 of arg are bits 27:24 of physical address
            gs.base_extended = (arg & 0x00F00000u) << 4u;
            gs.base_addr     = gs.base_extended | gs.offset_address;
            { static std::uint32_t s_base_log = 0;
              if (++s_base_log <= 10) {
                  std::printf("[GE-BASE] arg=0x%06X base_extended=0x%08X\n", arg, gs.base_extended);
                  fflush(stdout);
              }
            }
            break;
        case 0x13: // OFFSETADDR
            gs.offset_address = arg << 8u;
            gs.base_addr      = gs.base_extended | gs.offset_address;
            break;

        // Vertex/Index addresses: combine base + OFFSETADDR + lower 24 bits of arg
        case 0x01: // VADDR
            { static std::uint32_t s_vaddr_log = 0;
              gs.vaddr = (gs.offset_address + (gs.base_extended | (arg & 0x00FFFFFFu))) & 0x0FFFFFFFu;
              if (++s_vaddr_log <= 10) {
                  std::printf("[GE-VADDR] arg=0x%06X base_ext=0x%08X off=0x%08X resolved=0x%08X\n",
                              arg, gs.base_extended, gs.offset_address, gs.vaddr);
                  fflush(stdout);
              }
            }
            break;
        case 0x02: // IADDR
            gs.iaddr = (gs.offset_address + (gs.base_extended | (arg & 0x00FFFFFFu))) & 0x0FFFFFFFu;
            break;

        // Vertex type
        case 0x12: // VERTEXTYPE
            gs.vtype = arg;
            break;

        // Scissor
        case 0xD4: // SCISSOR1 (x0 | y0<<10)
            gs.sc_x1 = arg & 0x3FFu;
            gs.sc_y1 = (arg >> 10) & 0x3FFu;
            break;
        case 0xD5: // SCISSOR2 (x1 | y1<<10)
            gs.sc_x2 = (arg & 0x3FFu) + 1;
            gs.sc_y2 = ((arg >> 10) & 0x3FFu) + 1;
            break;

        // Framebuffer / draw target
        case 0x9C: // FBPTR — framebuffer base address (byte offset into VRAM, bits [23:0])
            gs.fbp = arg & 0x00FFFFFFu;
            break;
        case 0x9D: // FBWIDTH — framebuffer stride in pixels
            gs.fbw = arg & 0x7FCu;
            break;
        case 0x9E: break; // ZBUFPTR — depth buffer, ignore
        case 0x9F: break; // ZBUFWIDTH — depth buffer width, ignore

        // Texture addresses (TEXADDR0-7 = 0xA0-0xA7, TEXBUFWIDTH0-7 = 0xA8-0xAF)
        case 0xA0: gs.tbp[0] = (gs.base_extended & 0xFF000000u) | arg; break;
        case 0xA1: gs.tbp[1] = (gs.base_extended & 0xFF000000u) | arg; break;
        case 0xA2: gs.tbp[2] = (gs.base_extended & 0xFF000000u) | arg; break;
        case 0xA3: gs.tbp[3] = (gs.base_extended & 0xFF000000u) | arg; break;
        case 0xA4: gs.tbp[4] = (gs.base_extended & 0xFF000000u) | arg; break;
        case 0xA5: gs.tbp[5] = (gs.base_extended & 0xFF000000u) | arg; break;
        case 0xA6: gs.tbp[6] = (gs.base_extended & 0xFF000000u) | arg; break;
        case 0xA7: gs.tbp[7] = (gs.base_extended & 0xFF000000u) | arg; break;
        case 0xA8: gs.tbw[0] = arg & 0xFFFFu; break;
        case 0xA9: gs.tbw[1] = arg & 0xFFFFu; break;
        case 0xAA: gs.tbw[2] = arg & 0xFFFFu; break;
        case 0xAB: gs.tbw[3] = arg & 0xFFFFu; break;
        case 0xAC: gs.tbw[4] = arg & 0xFFFFu; break;
        case 0xAD: gs.tbw[5] = arg & 0xFFFFu; break;
        case 0xAE: gs.tbw[6] = arg & 0xFFFFu; break;
        case 0xAF: gs.tbw[7] = arg & 0xFFFFu; break;

        // Texture size (TEXSIZE0-7 = 0xB8-0xBF)
        case 0xB8: { // TEXSIZE0 — width and height as log2
            int tw_log = arg & 0xFu;
            int th_log = (arg >> 8) & 0xFu;
            gs.tw = 1u << tw_log;
            gs.th = 1u << th_log;
            break;
        }
        case 0xB9: case 0xBA: case 0xBB: case 0xBC: case 0xBD: case 0xBE: case 0xBF: break; // TEXSIZE1-7

        // Texture format / filter / etc.
        case 0xC3: gs.tfmt = arg & 0xFu; break; // TEXFORMAT (TPSM)
        case 0x1E: gs.tex_enabled = (arg & 1) != 0; break; // TEXTUREMAPENABLE

        // Framebuffer pixel format
        case 0xD2: // FRAMEBUFPIXFORMAT
            gs.fbfmt = arg & 0xFu;
            break;

        // Clear mode
        case 0xD3: { // CLEARMODE
            gs.clear_mode = (arg & 1) != 0;
            break;
        }

        default: break;
        }

        // COLOR register for clear / ambient (AMBIENTCOLOR=0x5C, AMBIENTALPHA=0x5D, CLEARCOLOR via 0xD3 path)
        if (op == 0x5C) {
            gs.color = (gs.color & 0xFF000000u) | (arg & 0x00FFFFFFu);
            gs.clear_color = gs.color;
        }
        if (op == 0x5D) {
            gs.color = (gs.color & 0x00FFFFFFu) | ((arg & 0xFFu) << 24);
            gs.clear_color = gs.color;
        }

        // Draw primitive: PSP GE PRIM opcode is 0x04
        if (op == 0x04) { // PRIM (prim_type<<16 | vertex_count)
            static std::uint32_t s_prim_log = 0;
            if (++s_prim_log <= 20) std::printf("[GE-PRIM] type=%u count=%u vtype=0x%X vaddr=0x%08X fbp=0x%X fbfmt=%d sc=(%d,%d)-(%d,%d) clr=%d cc=0x%08X\n",
                (arg>>16)&7, arg&0xFFFF, gs.vtype, gs.vaddr, gs.fbp, gs.fbfmt,
                gs.sc_x1, gs.sc_y1, gs.sc_x2, gs.sc_y2, gs.clear_mode, gs.clear_color);
            const std::uint32_t prim_type = (arg >> 16) & 7;
            const std::uint32_t count     = arg & 0xFFFFu;
            if (count == 0) break;

            // Resolve GE address: if upper byte is 0, default to VRAM (same as PortableKit
            // resolve_ge_address: (address & 0xFF000000) == 0 → address | 0x04000000).
            // PSP physical map: 0x04000000-0x041FFFFF = VRAM; 0x08000000-0x09FFFFFF = RAM.
            std::uint32_t va = gs.vaddr;
            if ((va & 0xFF000000u) == 0u) va |= 0x04000000u;
            const std::uint8_t *vptr = nullptr;
            if (va >= 0x04000000u && va < 0x08000000u) {
                // VRAM aliases: 0x04000000-0x07FFFFFF all map into 2MB VRAM via & 0x1FFFFF
                const std::uint32_t voff = va & 0x1FFFFFu;
                if (voff < vram_size)
                    vptr = static_cast<const std::uint8_t*>(vram) + voff;
            } else if (va >= 0x08000000u && va < 0x0A000000u) {
                // GE bus RAM range 0x08000000 - 0x09FFFFFF (same physical RAM)
                const std::uint32_t ram_off = va - 0x08000000u;
                if (ram_off < mem_size)
                    vptr = static_cast<const std::uint8_t*>(mem) + ram_off;
            }
            if (!vptr) {
                static std::uint32_t s_vptr_miss = 0;
                if (++s_vptr_miss <= 5) std::printf("[GE-VPTR-MISS] va=0x%08X mem_size=0x%zX vram_size=0x%zX\n", va, mem_size, vram_size);
                break;
            }
            { // Dump vertex data for diagnostics — sample first 3 bytes to detect non-zero
                static std::uint32_t s_last_va = 0xFFFFFFFFu;
                static std::uint32_t s_vdump = 0;
                const bool has_nonzero = (vptr[0]|vptr[1]|vptr[2]|vptr[3]) != 0;
                if (va != s_last_va || has_nonzero) {
                    s_last_va = va;
                    if (++s_vdump <= 20 || has_nonzero) {
                        std::printf("[GE-VDATA] va=0x%08X vtype=0x%X bytes:", va, gs.vtype);
                        for (int _b = 0; _b < 32; ++_b) std::printf(" %02X", vptr[_b]);
                        std::printf("\n");
                        fflush(stdout);
                    }
                }
            }

            if (prim_type == 6) { // GU_SPRITES (2 vertices per sprite)
                for (std::uint32_t i = 0; i + 1 < count; i += 2) {
                    const std::uint8_t *vp = vptr;
                    Vertex v0 = decode_vertex(vp, gs.vtype);
                    Vertex v1 = decode_vertex(vp, gs.vtype);
                    vptr = vp;
                    // Scale UV from [0..1] to texture pixels if bypass
                    if (vtype_bypass(gs.vtype)) {
                        v0.u *= gs.tw; v0.v *= gs.th;
                        v1.u *= gs.tw; v1.v *= gs.th;
                    }
                    draw_sprite(gs, v0, v1, vram, vram_size, mem, mem_size);
                }
            } else if (prim_type == 3) { // GU_TRIANGLES
                for (std::uint32_t i = 0; i + 2 < count; i += 3) {
                    const std::uint8_t *vp = vptr;
                    Vertex v0 = decode_vertex(vp, gs.vtype);
                    Vertex v1 = decode_vertex(vp, gs.vtype);
                    Vertex v2 = decode_vertex(vp, gs.vtype);
                    vptr = vp;
                    draw_triangle(gs, v0, v1, v2, vram, vram_size, mem, mem_size);
                }
            } else if (prim_type == 4) { // GU_TRIANGLE_STRIP
                const std::uint8_t *vp = vptr;
                Vertex prev0 = decode_vertex(vp, gs.vtype);
                Vertex prev1 = decode_vertex(vp, gs.vtype);
                for (std::uint32_t i = 2; i < count; ++i) {
                    Vertex v2 = decode_vertex(vp, gs.vtype);
                    draw_triangle(gs, (i & 1) ? prev1 : prev0, (i & 1) ? prev0 : prev1, v2, vram, vram_size, mem, mem_size);
                    prev0 = prev1; prev1 = v2;
                }
                vptr = vp;
            } else if (prim_type == 1) { // GU_LINES (pairs of vertices)
                const std::uint8_t *vp = vptr;
                static std::uint32_t s_lines_log = 0;
                for (std::uint32_t i = 0; i + 1 < count; i += 2) {
                    Vertex va2 = decode_vertex(vp, gs.vtype);
                    Vertex vb  = decode_vertex(vp, gs.vtype);
                    if (++s_lines_log <= 4) std::printf("[GE-LINE] (%.1f,%.1f)-(%.1f,%.1f) col=0x%08X\n", va2.x,va2.y,vb.x,vb.y,vb.color);
                    draw_line(gs, va2, vb, vram, vram_size);
                }
                vptr = vp;
            } else if (prim_type == 2) { // GU_LINE_STRIP
                const std::uint8_t *vp = vptr;
                Vertex prev = decode_vertex(vp, gs.vtype);
                for (std::uint32_t i = 1; i < count; ++i) {
                    Vertex cur = decode_vertex(vp, gs.vtype);
                    draw_line(gs, prev, cur, vram, vram_size);
                    prev = cur;
                }
                vptr = vp;
            }
            // When in clear mode, the PRIM just fills the scissor rect with the clear color
            if (gs.clear_mode) {
                const std::uint32_t cc = gs.clear_color;
                // bpp: formats 0(RGB565),1(RGBA5551),2(RGBA4444) = 2 bytes; 3(RGBA8888) = 4 bytes
                const int bpp = (gs.fbfmt == 3) ? 4 : 2;
                const std::uint32_t stride = (gs.fbw > 0) ? gs.fbw : 512u;
                { static std::uint32_t s_clr = 0;
                  if (++s_clr <= 5) std::printf("[GE-CLEAR] fbp=0x%X fbw=%u fbfmt=%d sc=(%d,%d)-(%d,%d) cc=0x%08X bpp=%d\n",
                      gs.fbp,gs.fbw,gs.fbfmt,gs.sc_x1,gs.sc_y1,gs.sc_x2,gs.sc_y2,cc,bpp); fflush(stdout); }
                for (int y = gs.sc_y1; y < gs.sc_y2 && y < 272; ++y) {
                    std::uint8_t *row = static_cast<std::uint8_t*>(vram)
                                      + gs.fbp + static_cast<std::size_t>(y) * stride * bpp;
                    if (row < static_cast<std::uint8_t*>(vram)) continue;
                    if (row + gs.sc_x2 * bpp > static_cast<std::uint8_t*>(vram) + vram_size) continue;
                    if (bpp == 2) {
                        auto *dst = reinterpret_cast<std::uint16_t*>(row);
                        std::uint16_t px16 = 0;
                        if (gs.fbfmt == 0) { // RGB565
                            const std::uint8_t r=(cc>>0)&0xFF, g=(cc>>8)&0xFF, b=(cc>>16)&0xFF;
                            px16 = static_cast<std::uint16_t>(((r>>3)<<11)|((g>>2)<<5)|(b>>3));
                        } else if (gs.fbfmt == 1) { // RGBA5551
                            const std::uint8_t r=(cc>>0)&0xFF, g=(cc>>8)&0xFF, b=(cc>>16)&0xFF, a=(cc>>24)&0xFF;
                            px16 = static_cast<std::uint16_t>(((r>>3)<<11)|((g>>3)<<6)|((b>>3)<<1)|(a>>7));
                        } else { // RGBA4444
                            const std::uint8_t r=(cc>>0)&0xFF, g=(cc>>8)&0xFF, b=(cc>>16)&0xFF, a=(cc>>24)&0xFF;
                            px16 = static_cast<std::uint16_t>(((r>>4)<<12)|((g>>4)<<8)|((b>>4)<<4)|(a>>4));
                        }
                        for (int x = gs.sc_x1; x < gs.sc_x2; ++x) dst[x] = px16;
                    } else {
                        auto *dst = reinterpret_cast<std::uint32_t*>(row);
                        for (int x = gs.sc_x1; x < gs.sc_x2; ++x) dst[x] = cc;
                    }
                }
            }
        }
    }
done:
    g_ge_last_fbfmt = gs.fbfmt;
    g_ge_last_fbp   = gs.fbp;
    g_ge_last_fbw   = (gs.fbw > 0) ? gs.fbw : 512u;
    (void)s_exec_count;
}

} // namespace d012
