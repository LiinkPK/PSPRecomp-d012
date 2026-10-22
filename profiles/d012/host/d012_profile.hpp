#pragma once
#include <cstdint>
#include <cstdio>
#include <string>

namespace psprecomp {
class Runtime;
class Elf32Image;
} // namespace psprecomp

namespace d012 {
void register_hle(psprecomp::Runtime &rt);
void set_runtime(psprecomp::Runtime &rt);
void scan_and_register_stubs(psprecomp::Runtime &rt, const psprecomp::Elf32Image &elf);
std::uint32_t hle_alloc(std::uint32_t size);
std::uint32_t hle_alloc_size();
std::uint32_t hle_last_addr();
std::uint32_t hle_get_addr(std::uint32_t uid);
bool hle_has_pending_threads();
void hle_run_next_thread(psprecomp::Runtime &rt);
void hle_run_ctors(psprecomp::Runtime &rt, const psprecomp::Elf32Image &elf);

// Game root directory for PSP path translation
extern std::string g_game_root;

// Jump table snapshot: 12 entries saved by INIT-DONE hook, restored when corrupted.
extern std::uint32_t g_jump_table_snapshot[12];
extern bool          g_jump_table_snapshot_valid;

// Callback table snapshot: 16 entries at 0x089C96B0, same post-INIT corruption issue.
extern std::uint32_t g_cb_table_snapshot[16];
extern bool          g_cb_table_snapshot_valid;

// File I/O state — used from generated_unit_0014.cpp
std::uint32_t io_open(const std::string &psp_path, std::uint32_t flags);
std::int32_t  io_read(std::uint32_t fd, void *buf, std::uint32_t size);
std::int32_t  io_close(std::uint32_t fd);
std::int64_t  io_lseek(std::uint32_t fd, std::int64_t offset, std::uint32_t whence);

// Display framebuffer state — set by sceDisplaySetFrameBuf, read by present code
struct DisplayFbInfo { std::uint32_t vaddr; std::uint32_t stride; int fmt; };
extern DisplayFbInfo g_display_fb;

// Kernel HLE — used from generated_unit_0014.cpp labels
std::uint32_t hle_create_callback(std::uint32_t func);
void          hle_delete_callback(std::uint32_t uid);
std::uint32_t hle_create_sema(std::uint32_t init_val);
void          hle_delete_sema(std::uint32_t uid);
void          hle_signal_sema(std::uint32_t uid, std::uint32_t signal);
std::uint32_t hle_create_thread(std::uint32_t entry, std::uint32_t priority, std::uint32_t stack_size);
void          hle_start_thread(std::uint32_t uid, std::uint32_t arglen, std::uint32_t argp);
std::uint32_t hle_create_event_flag();

// Cooperative thread scheduler — runs all live threads in round-robin, yielding
// at GE sync points. Call this instead of hle_run_next_thread in main after
// the initial entry thread exits.
void hle_run_cooperative(psprecomp::Runtime &rt);
} // namespace d012