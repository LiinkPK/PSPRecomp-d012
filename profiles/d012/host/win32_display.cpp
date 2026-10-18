#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <cstdio>
#include <cstring>
#include <cstdint>
#include <fstream>
#include <filesystem>
#include <string>
#include <vector>
#include "win32_display.hpp"

namespace d012 {

static HWND   s_hwnd   = nullptr;
static HDC    s_hdc    = nullptr;
static int    s_width  = 480;
static int    s_height = 272;

// Scratch RGBA8888 buffer for converting from RGB565
static std::vector<std::uint32_t> s_rgba;

static LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp) {
    if (msg == WM_DESTROY) { PostQuitMessage(0); return 0; }
    if (msg == WM_CLOSE)   { DestroyWindow(hwnd); return 0; }
    return DefWindowProcA(hwnd, msg, wp, lp);
}

void display_init(int width, int height) {
    s_width  = width;
    s_height = height;
    s_rgba.resize(static_cast<std::size_t>(width * height));

    WNDCLASSEXA wc = {};
    wc.cbSize        = sizeof(wc);
    wc.lpfnWndProc   = WndProc;
    wc.hInstance     = GetModuleHandleA(nullptr);
    wc.hCursor       = LoadCursor(nullptr, IDC_ARROW);
    wc.lpszClassName = "PSPRecompWindow";
    RegisterClassExA(&wc);

    // Size the window so the client area is exactly width x height
    RECT rc = { 0, 0, width, height };
    AdjustWindowRect(&rc, WS_OVERLAPPEDWINDOW & ~WS_THICKFRAME & ~WS_MAXIMIZEBOX, FALSE);

    s_hwnd = CreateWindowExA(
        0, "PSPRecompWindow", "Dissidia 012 - PSPRecomp",
        WS_OVERLAPPEDWINDOW & ~WS_THICKFRAME & ~WS_MAXIMIZEBOX,
        CW_USEDEFAULT, CW_USEDEFAULT,
        rc.right - rc.left, rc.bottom - rc.top,
        nullptr, nullptr, GetModuleHandleA(nullptr), nullptr);

    ShowWindow(s_hwnd, SW_SHOW);
    UpdateWindow(s_hwnd);
    s_hdc = GetDC(s_hwnd);
}

void display_present(const void *vram_ptr, int buf_width, int fmt) {
    if (!s_hwnd || !vram_ptr) return;

    // Convert to RGBA8888 into s_rgba
    const int rows = s_height;
    const int cols = s_width;

    if (fmt == 3) {
        // RGBA8888 — copy directly (swap R/B for GDI BGRA)
        const auto *src = static_cast<const std::uint32_t *>(vram_ptr);
        for (int y = 0; y < rows; ++y) {
            const std::uint32_t *row = src + y * buf_width;
            std::uint32_t       *dst = s_rgba.data() + y * cols;
            for (int x = 0; x < cols; ++x) {
                const std::uint32_t p = row[x];
                // RGBA -> BGRA for GDI
                dst[x] = ((p & 0x00FF0000u) >> 16)   // B
                       | ( p & 0x0000FF00u)            // G
                       | ((p & 0x000000FFu) << 16)     // R
                       | ( p & 0xFF000000u);            // A
            }
        }
    } else if (fmt == 1) {
        // RGBA5551 — 16-bit: R[15:11] G[10:6] B[5:1] A[0]
        const auto *src = static_cast<const std::uint16_t *>(vram_ptr);
        for (int y = 0; y < rows; ++y) {
            const std::uint16_t *row = src + y * buf_width;
            std::uint32_t       *dst = s_rgba.data() + y * cols;
            for (int x = 0; x < cols; ++x) {
                const std::uint16_t p = row[x];
                const std::uint8_t r = static_cast<std::uint8_t>(((p >> 11) & 0x1F) * 255 / 31);
                const std::uint8_t g = static_cast<std::uint8_t>(((p >>  6) & 0x1F) * 255 / 31);
                const std::uint8_t b = static_cast<std::uint8_t>(((p >>  1) & 0x1F) * 255 / 31);
                // BGRA for GDI
                dst[x] = (static_cast<std::uint32_t>(r) << 16)
                       | (static_cast<std::uint32_t>(g) <<  8)
                       |  static_cast<std::uint32_t>(b)
                       | 0xFF000000u;
            }
        }
    } else if (fmt == 0) {
        // RGB565 — 16-bit: R[15:11] G[10:5] B[4:0]
        const auto *src = static_cast<const std::uint16_t *>(vram_ptr);
        for (int y = 0; y < rows; ++y) {
            const std::uint16_t *row = src + y * buf_width;
            std::uint32_t       *dst = s_rgba.data() + y * cols;
            for (int x = 0; x < cols; ++x) {
                const std::uint16_t p = row[x];
                const std::uint8_t r = static_cast<std::uint8_t>(((p >> 11) & 0x1F) * 255 / 31);
                const std::uint8_t g = static_cast<std::uint8_t>(((p >>  5) & 0x3F) * 255 / 63);
                const std::uint8_t b = static_cast<std::uint8_t>(( p        & 0x1F) * 255 / 31);
                dst[x] = (static_cast<std::uint32_t>(r) << 16)
                       | (static_cast<std::uint32_t>(g) <<  8)
                       |  static_cast<std::uint32_t>(b);
            }
        }
    } else {
        // Unknown format: fill magenta for debugging
        std::fill(s_rgba.begin(), s_rgba.end(), 0xFF00FFFFu);
    }

    // Diagnostic capture of the framebuffer produced by the guest GE path.
    // This writes the already-converted display buffer; it does not alter it.
    static unsigned dump_count = 0;
    if (dump_count++ < 5u) {
        BITMAPFILEHEADER bfh = {};
        BITMAPINFOHEADER bih = {};
        bih.biSize = sizeof(BITMAPINFOHEADER);
        bih.biWidth = cols;
        bih.biHeight = -rows;
        bih.biPlanes = 1;
        bih.biBitCount = 32;
        bih.biCompression = BI_RGB;
        bfh.bfType = 0x4D42;
        bfh.bfOffBits = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);
        bfh.bfSize = bfh.bfOffBits + static_cast<DWORD>(s_rgba.size() * sizeof(std::uint32_t));
        char dump_path[256] = {};
        const auto dump_dir = std::filesystem::temp_directory_path();
        const auto dump_file = dump_dir / ("psprecomp-guest-frame-" + std::to_string(dump_count) + ".bmp");
        std::snprintf(dump_path, sizeof(dump_path), "%s", dump_file.string().c_str());
        std::ofstream dump(dump_path, std::ios::binary);
        dump.write(reinterpret_cast<const char *>(&bfh), sizeof(bfh));
        dump.write(reinterpret_cast<const char *>(&bih), sizeof(bih));
        dump.write(reinterpret_cast<const char *>(s_rgba.data()), static_cast<std::streamsize>(s_rgba.size() * sizeof(std::uint32_t)));
    }

    BITMAPINFO bmi = {};
    bmi.bmiHeader.biSize        = sizeof(BITMAPINFOHEADER);
    bmi.bmiHeader.biWidth       = cols;
    bmi.bmiHeader.biHeight      = -rows; // top-down
    bmi.bmiHeader.biPlanes      = 1;
    bmi.bmiHeader.biBitCount    = 32;
    bmi.bmiHeader.biCompression = BI_RGB;

    SetDIBitsToDevice(s_hdc,
        0, 0, cols, rows,
        0, 0, 0, rows,
        s_rgba.data(), &bmi, DIB_RGB_COLORS);
}

bool display_pump() {
    if (!s_hwnd) return true;
    MSG msg;
    while (PeekMessageA(&msg, nullptr, 0, 0, PM_REMOVE)) {
        if (msg.message == WM_QUIT) return false;
        TranslateMessage(&msg);
        DispatchMessageA(&msg);
    }
    return IsWindow(s_hwnd) != 0;
}

} // namespace d012
