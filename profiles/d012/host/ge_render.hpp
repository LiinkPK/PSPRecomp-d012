#pragma once
#include <cstdint>
#include <cstddef>

namespace d012 {

// Execute a GE display list.
// dl / dl_end: host pointers to DL command words (32-bit big-endian PSP GE format).
// vram:       writable host pointer to the 2MB PSP VRAM (framebuffer lives here).
// vram_size:  size of the VRAM buffer in bytes (typically 0x200000).
// mem:        host pointer to the flat guest RAM view (physical offset 0).
// mem_size:   size of the guest RAM flat view.
void ge_exec(const std::uint32_t *dl, const std::uint32_t *dl_end,
             void *vram, std::size_t vram_size,
             const void *mem, std::size_t mem_size,
             std::uint32_t initial_base_addr = 0u);

// Framebuffer state written by the most recent ge_exec call.
extern int          g_ge_last_fbfmt;   // 0=RGB565, 1=RGBA5551, 2=RGBA4444, 3=RGBA8888
extern std::uint32_t g_ge_last_fbp;   // byte offset into VRAM
extern std::uint32_t g_ge_last_fbw;   // stride in pixels

} // namespace d012
