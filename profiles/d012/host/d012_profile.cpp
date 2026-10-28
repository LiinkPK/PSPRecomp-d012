#include "d012_profile.hpp"
#include "d012_embedded_assets_v2.hpp"
#include "ge_render.hpp"
#include "win32_display.hpp"
#include "psprecomp/runtime.hpp"
#include "psprecomp/elf32.hpp"
#include "kernel/kernel.hpp"
#include "kernel/iso_image.hpp"

#include <cstdint>
#include <cstdio>
#include <cstring>
#include <filesystem>
#include <functional>
#include <span>
#include <string>
#include <thread>
#include <unordered_map>
#include <vector>
#include <deque>
#include <chrono>

// These globals were defined in PSPRecomp's runtime.cpp; define them here
// when building against PortableKit's runtime which doesn't have them.
// g_ge_list_start, g_ge_exec_cursor, g_ge_list_executed are defined in
// generated_unit_0014.cpp — only define the ones not already there.
namespace psprecomp {
std::uint32_t g_frame_recovery_pc = 0u;
std::uint32_t (*g_frame_complete_hook)() = nullptr;
std::uint32_t g_frame_reset_sp = 0u;
extern std::uint32_t g_ge_list_start;
extern std::uint32_t g_ge_exec_cursor;
extern bool          g_ge_list_executed;
}

namespace d012 {

// Game root directory set from main.cpp before any file I/O
std::string g_game_root;

// Display framebuffer info: updated by sceDisplaySetFrameBuf
DisplayFbInfo g_display_fb = {0x04000000u, 512u, 1};

// Jump table snapshot for restoring after data-init copy clobbers BSS
std::uint32_t g_jump_table_snapshot[12] = {};
bool          g_jump_table_snapshot_valid = false;

// Callback table snapshot (0x089C96B0, 16 entries) — same corruption
std::uint32_t g_cb_table_snapshot[16] = {};
bool          g_cb_table_snapshot_valid = false;

namespace {

// Per-VA dispatch table populated before the first run
static std::unordered_map<
    std::uint32_t,
    std::function<void(psprecomp::Runtime &, psprecomp::AllegrexContext &)>>
    s_handlers;

// Thread queue for multi-thread simulation
struct ThreadDesc {
    std::uint32_t entry;
    std::uint32_t uid;
    std::uint32_t arglen;
    std::uint32_t argp;
    std::uint32_t priority;
};
static std::deque<ThreadDesc> s_thread_queue;
static std::uint32_t s_next_thread_uid = 1u;
static std::uint32_t s_next_cb_uid   = 0x100u;
static std::uint32_t s_next_sema_uid = 0x200u;

// Cooperative multitasking: saved per-thread register state
struct SavedThreadCtx {
    psprecomp::AllegrexContext ctx{};
    std::uint32_t resume_pc{0u};
    std::uint32_t uid{0u};
    bool alive{false};
};
static std::vector<SavedThreadCtx> s_live_threads;
static int s_current_thread_idx = -1; // which thread is currently running
// When set, the currently running thread should yield at the next sync point
static bool s_yield_requested = false;
static std::unordered_map<std::uint32_t, std::uint32_t>  s_callbacks;
static std::unordered_map<std::uint32_t, std::int32_t>   s_semas;
// Map uid -> entry for StartThread
static std::unordered_map<std::uint32_t, ThreadDesc> s_threads;

// Thread entry address saved when sceKernelCreateThread is intercepted
static std::uint32_t s_thread_entry = 0u;
static std::uint32_t s_alloc_size = 0u;
// Frame thread restart state: set when thread is started, used by ExitDeleteThread to restart
static std::uint32_t s_frame_thread_entry = 0u;
static std::uint32_t s_frame_thread_sp    = 0u;
static std::uint32_t s_frame_count = 0u;

// SysMem partition allocator — bump allocator in upper RAM
// 0x09A00000..0x09EE0000 = ~5MB, enough for EFFECT_ALLOCATOR (0x3DD000)
static constexpr std::uint32_t kHeapBase = 0x09A00000u;
static constexpr std::uint32_t kHeapEnd  = 0x09EE0000u;
static std::uint32_t s_heap_next = kHeapBase;
struct MemBlock { std::uint32_t addr; std::uint32_t size; };
static std::unordered_map<std::uint32_t, MemBlock> s_mem_blocks;
static std::uint32_t s_next_uid = 1u;

// Runtime pointer — set by register_hle; used by hle_start_thread to call PortableKit's kernel.
static psprecomp::Runtime *s_runtime_ptr = nullptr;

// File I/O — host file descriptor table (also used by io_open/read/close/lseek below)
} // end anonymous namespace
struct HostFd {
    FILE *fp;           // non-null for host-file or disc-backed reads
    std::string path;
    // Disc-backed fields (valid when disc_iso != nullptr):
    std::shared_ptr<portablekit::IsoImage> disc_iso;
    std::uint64_t disc_offset = 0u; // byte offset of file start in ISO
    std::uint64_t disc_size   = 0u; // file size in bytes
    std::uint64_t disc_pos    = 0u; // current read position
};
static std::shared_ptr<portablekit::IsoImage> s_disc_iso;  // lazily loaded
static std::unordered_map<std::uint32_t, HostFd> s_fds;
static std::uint32_t s_next_fd = 0x10u;
namespace { // resume anonymous namespace

// Display — last submitted framebuffer params
struct FrameBufInfo { std::uint32_t vaddr; std::uint32_t bufferwidth; std::uint32_t pixelformat; std::uint32_t sync; };
static FrameBufInfo s_framebuf{};
static std::uint32_t s_display_frame_count = 0u;

// sceGu HLE write-pointer state
static std::uint32_t s_gu_wp   = 0u;  // guest VA of next GE write slot
static std::uint32_t s_gu_base = 0u;  // list base VA

// sceUtilitySavedata state
static std::uint32_t s_sdp_addr = 0u;
static int s_sd_state = 0;

// GE callback slot array (ported from 3rd Birthday h_GeSetCallback)
struct GeCallback { int used; std::uint32_t signal_func, signal_arg, finish_func, finish_arg; };
static GeCallback s_ge_cb[16] = {};
static std::uint32_t s_ge_list_next = 1u;

static void gu_emit(psprecomp::Runtime &rt2, std::uint32_t cmd) {
    if (s_gu_wp == 0u || !rt2.memory().contains(s_gu_wp, 4u)) return;
    rt2.memory().store32(s_gu_wp, cmd);
    s_gu_wp += 4u;
}

static bool present_and_pump(psprecomp::Runtime &rt2) {
    const auto &vram = rt2.memory().vram_bytes();
    const std::uint32_t vram_off = d012::g_ge_last_fbp & 0x1FFFFFu;
    const int fmt = g_display_fb.fmt;
    const std::size_t stride = g_display_fb.stride > 0u ? g_display_fb.stride : 512u;
    const std::size_t fb_bytes = stride * 272u * (fmt == 3 ? 4u : 2u);
    const std::uint8_t *fb_ptr = (vram_off + fb_bytes <= vram.size()) ? vram.data() + vram_off : vram.data();
    d012::display_present(fb_ptr, static_cast<int>(stride), fmt);
    return d012::display_pump();
}

// Run a submitted GE list right now (the game may reuse its memory before vblank).
static void run_ge_list_now(psprecomp::Runtime &rt2, std::uint32_t list_phys, std::uint32_t stall_phys) {
    if (list_phys == 0u || !rt2.memory().contains(list_phys, 4u)) return;
    void *vram_ptr = rt2.memory().raw_pointer(0x04000000u, 0x200000u);
    const void *dl_raw = rt2.memory().raw_pointer(list_phys, 4u);
    if (!vram_ptr || !dl_raw) return;
    const auto *dl = reinterpret_cast<const std::uint32_t *>(dl_raw);
    const std::size_t span = (stall_phys > list_phys && stall_phys - list_phys < 0x100000u)
                           ? (stall_phys - list_phys) / 4u : 0x10000u;
    const auto &mem_vec = rt2.memory().bytes();
    d012::ge_exec(dl, dl + span, vram_ptr, 0x200000u, mem_vec.data(), mem_vec.size(), 0x08000000u);
}

// Call a guest function from an HLE handler and restore the caller's registers.
static void call_guest(psprecomp::Runtime &rt2, psprecomp::AllegrexContext &ctx,
                       std::uint32_t fn, std::uint32_t a0, std::uint32_t a1, std::uint32_t a2) {
    if (fn == 0u) return;
    const psprecomp::AllegrexContext saved = ctx;
    ctx.gpr[4] = a0; ctx.gpr[5] = a1; ctx.gpr[6] = a2;
    ctx.gpr[31] = 2u;
    ctx.pc = fn;
    (void)rt2.invoke_chained_call(ctx);
    ctx = saved;
}

static void ge_finish_callback(psprecomp::Runtime &rt2, psprecomp::AllegrexContext &ctx,
                               std::uint32_t cbid, std::uint32_t list_id, std::uint32_t user_arg) {
    if (cbid >= 16u || !s_ge_cb[cbid].used || s_ge_cb[cbid].finish_func == 0u) return;
    call_guest(rt2, ctx, s_ge_cb[cbid].finish_func, list_id,
               s_ge_cb[cbid].finish_arg ? s_ge_cb[cbid].finish_arg : user_arg, cbid);
}

// Single raw-function-pointer registered for every discovered syscall stub.
// Dispatches by ctx.pc at call time.
void generic_stub(psprecomp::Runtime &rt, psprecomp::AllegrexContext &ctx) {
    const std::uint32_t va = ctx.pc;

    auto it = s_handlers.find(va);
    if (it != s_handlers.end()) {
        it->second(rt, ctx);
        return;
    }

    static std::unordered_map<std::uint32_t, bool> s_warned;
    if (!s_warned[va]) {
        s_warned[va] = true;
        std::printf("[STUB] unhandled VA=0x%08X RA=0x%08X a0=0x%08X\n",
                    va, ctx.gpr[31], ctx.gpr[4]);
    }
    ctx.gpr[2] = 0u;
    ctx.pc     = ctx.gpr[31];
}

} // anonymous namespace

void scan_and_register_stubs(psprecomp::Runtime &rt, const psprecomp::Elf32Image &elf) {
    // ---- Known handlers keyed by VA ----
    s_handlers[0x089C5F40u] = [](psprecomp::Runtime &, psprecomp::AllegrexContext &ctx) {
        std::printf("[HLE] sceKernelSetCompiledSdkVersion603_605(0x%08X)\n", ctx.gpr[4]);
        ctx.gpr[2] = 0u;
        ctx.pc     = ctx.gpr[31];
    };
    s_handlers[0x089C5F28u] = [](psprecomp::Runtime &, psprecomp::AllegrexContext &ctx) {
        std::printf("[HLE] sceKernelSetCompilerVersion(0x%08X)\n", ctx.gpr[4]);
        ctx.gpr[2] = 0u;
        ctx.pc     = ctx.gpr[31];
    };

    // ---- File I/O (IoFileMgrForUser) ----
    // sceIoOpen(path, flags, mode) -> fd or error
    s_handlers[0x089C5EA8u] = [](psprecomp::Runtime &rt, psprecomp::AllegrexContext &ctx) {
        const std::string psp_path = rt.memory().read_c_string(ctx.gpr[4]);
        const std::uint32_t flags = ctx.gpr[5];
        // Translate PSP path to host path
        std::string host_path;
        try { host_path = rt.translate_path(psp_path).string(); } catch (...) { host_path = psp_path; }
        const char *mode = (flags & 2u) ? ((flags & 0x200u) ? "w+b" : "wb") : "rb";
        // Special-case files before translate_path:
        {
            const std::string &pp = psp_path;
            // package.bin: check D012_PACKAGE_BIN env var
            const bool is_pkg = pp == "data/package.bin" || pp == "data/PACKAGE.BIN" ||
                (pp.size() >= 11 && pp.substr(pp.size()-11) == "package.bin");
            if (is_pkg && !(flags & 2u)) {
                const char *pkg_env = std::getenv("D012_PACKAGE_BIN");
                if (pkg_env && std::strlen(pkg_env) > 0) {
                    FILE *fp2 = std::fopen(pkg_env, "rb");
                    if (fp2) {
                        const std::uint32_t fd2 = s_next_fd++;
                        s_fds[fd2] = {fp2, psp_path};
                        std::printf("[IO] sceIoOpen: \"%s\" -> fd=%u (D012_PACKAGE_BIN)\n", psp_path.c_str(), fd2);
                        ctx.gpr[2] = fd2;
                        ctx.pc = ctx.gpr[31];
                        return;
                    }
                }
                // Lazy-load disc image: PSP_ISO env var first, then disc.iso candidates
                if (!s_disc_iso) {
                    std::vector<std::filesystem::path> candidates;
                    if (const char *iso_env = std::getenv("PSP_ISO"))
                        candidates.push_back(std::filesystem::path(iso_env));
                    try { candidates.push_back(rt.translate_path("disc.iso")); } catch (...) {}
                    if (const char *gp = std::getenv("D012_GAME_PATH")) {
                        candidates.push_back(std::filesystem::path(gp) / "disc.iso");
                        candidates.push_back(std::filesystem::path(gp) / "D012" / "disc.iso");
                    }
                    if (!g_game_root.empty())
                        candidates.push_back(std::filesystem::path(g_game_root) / "disc.iso");
                    for (const auto &disc_path : candidates) {
                        if (std::filesystem::exists(disc_path)) {
                            try { s_disc_iso = std::make_shared<portablekit::IsoImage>(disc_path); }
                            catch (const std::exception &e) {
                                std::printf("[ISO] open failed: %s\n", e.what()); std::fflush(stdout);
                            }
                            if (s_disc_iso) {
                                std::printf("[ISO] loaded '%s'\n", disc_path.string().c_str());
                                std::fflush(stdout);
                                break;
                            }
                        }
                    }
                }
                if (s_disc_iso) {
                    // Resolve "data/package.bin" under disc0:/PSP_GAME/USRDIR
                    const std::string disc_rel = "PSP_GAME/USRDIR/" + pp;
                    std::printf("[PKG-ISO] disc loaded, looking up '%s'\n", disc_rel.c_str()); std::fflush(stdout);
                    if (const auto entry = s_disc_iso->find(disc_rel); entry && !entry->directory) {
                        const std::uint32_t fd2 = s_next_fd++;
                        HostFd hfd{};
                        hfd.path = psp_path;
                        hfd.disc_iso    = s_disc_iso;
                        hfd.disc_offset = static_cast<std::uint64_t>(entry->lba) * portablekit::IsoImage::kSectorSize;
                        hfd.disc_size   = entry->size;
                        hfd.disc_pos    = 0u;
                        hfd.fp          = nullptr;
                        s_fds[fd2] = std::move(hfd);
                        std::printf("[IO] sceIoOpen: \"%s\" -> fd=%u (disc ISO entry, size=%llu)\n",
                            psp_path.c_str(), fd2, (unsigned long long)entry->size);
                        ctx.gpr[2] = fd2;
                        ctx.pc = ctx.gpr[31];
                        return;
                    }
                }
            }
            // package_info.bin: serve directly from D012_GAME_PATH/data/
            const bool is_pkg_info = pp == "data/package_info.bin" || pp == "data/PACKAGE_INFO.BIN" ||
                (pp.size() >= 16 && (pp.substr(pp.size()-16) == "package_info.bin" || pp.substr(pp.size()-16) == "PACKAGE_INFO.BIN"));
            if (is_pkg_info && !(flags & 2u)) {
                const char *gp = std::getenv("D012_GAME_PATH");
                if (gp && std::strlen(gp) > 0) {
                    const std::string info_path = std::string(gp) + "/data/PACKAGE_INFO.BIN";
                    const std::string info_path2 = std::string(gp) + "/data/package_info.bin";
                    FILE *fp2 = std::fopen(info_path.c_str(), "rb");
                    if (!fp2) fp2 = std::fopen(info_path2.c_str(), "rb");
                    if (fp2) {
                        const std::uint32_t fd2 = s_next_fd++;
                        s_fds[fd2] = {fp2, psp_path};
                        std::printf("[IO] sceIoOpen: \"%s\" -> fd=%u (D012_GAME_PATH/data/PACKAGE_INFO.BIN)\n", psp_path.c_str(), fd2);
                        ctx.gpr[2] = fd2;
                        ctx.pc = ctx.gpr[31];
                        return;
                    }
                }
            }
        }
        // Lazy-load ISO for any read-only open (PSP_ISO env var)
        if (!(flags & 2u) && !s_disc_iso) {
            std::vector<std::filesystem::path> iso_candidates;
            if (const char *iso_env = std::getenv("PSP_ISO"))
                iso_candidates.push_back(std::filesystem::path(iso_env));
            if (const char *gp = std::getenv("D012_GAME_PATH")) {
                iso_candidates.push_back(std::filesystem::path(gp) / "disc.iso");
                iso_candidates.push_back(std::filesystem::path(gp) / "D012" / "disc.iso");
            }
            if (!g_game_root.empty())
                iso_candidates.push_back(std::filesystem::path(g_game_root) / "disc.iso");
            for (const auto &disc_path : iso_candidates) {
                if (std::filesystem::exists(disc_path)) {
                    try { s_disc_iso = std::make_shared<portablekit::IsoImage>(disc_path); }
                    catch (const std::exception &e) {
                        std::printf("[ISO] open failed: %s\n", e.what()); std::fflush(stdout);
                    }
                    if (s_disc_iso) { std::printf("[ISO] loaded '%s'\n", disc_path.string().c_str()); std::fflush(stdout); break; }
                }
            }
        }
        // For read-only opens: try the disc ISO before the host filesystem
        if (!(flags & 2u) && s_disc_iso) {
            // Normalise path: strip leading "disc0:/PSP_GAME/USRDIR/" or "data/" prefix
            auto try_disc = [&](const std::string &rel) -> bool {
                if (const auto entry = s_disc_iso->find(rel); entry && !entry->directory) {
                    const std::uint32_t fd2 = s_next_fd++;
                    HostFd hfd{};
                    hfd.path        = psp_path;
                    hfd.disc_iso    = s_disc_iso;
                    hfd.disc_offset = static_cast<std::uint64_t>(entry->lba) * portablekit::IsoImage::kSectorSize;
                    hfd.disc_size   = entry->size;
                    hfd.disc_pos    = 0u;
                    hfd.fp          = nullptr;
                    s_fds[fd2] = std::move(hfd);
                    std::printf("[IO] sceIoOpen: \"%s\" -> fd=%u (ISO size=%llu)\n",
                        psp_path.c_str(), fd2, (unsigned long long)entry->size);
                    ctx.gpr[2] = fd2;
                    ctx.pc = ctx.gpr[31];
                    return true;
                }
                return false;
            };
            const std::string &pp2 = psp_path;
            // Try "PSP_GAME/USRDIR/<path>" and "<path>" directly
            if (try_disc("PSP_GAME/USRDIR/" + pp2)) return;
            if (try_disc(pp2)) return;
            // Strip disc0:/PSP_GAME/USRDIR/ prefix if present
            auto strip = [](const std::string &s, const char *pfx) -> std::string {
                std::size_t n = std::strlen(pfx);
                return (s.size() > n && s.substr(0, n) == pfx) ? s.substr(n) : s;
            };
            std::string bare = strip(pp2, "disc0:/PSP_GAME/USRDIR/");
            bare = strip(bare, "disc0:/");
            if (bare != pp2) {
                if (try_disc("PSP_GAME/USRDIR/" + bare)) return;
                if (try_disc(bare)) return;
            }
        }
        FILE *fp = std::fopen(host_path.c_str(), mode);
        if (!fp) {
            static std::unordered_map<std::string, bool> s_warned;
            if (!s_warned[psp_path]) {
                s_warned[psp_path] = true;
                std::printf("[IO] sceIoOpen: \"%s\" -> NOT FOUND\n", psp_path.c_str());
            }
            ctx.gpr[2] = static_cast<std::uint32_t>(-2); // SCE_KERNEL_ERROR_NOFILE
        } else {
            const std::uint32_t fd = s_next_fd++;
            s_fds[fd] = {fp, psp_path};
            std::printf("[IO] sceIoOpen: \"%s\" -> fd=%u\n", psp_path.c_str(), fd);
            ctx.gpr[2] = fd;
        }
        ctx.pc = ctx.gpr[31];
    };
    // sceIoRead(fd, buf, size) -> bytes read
    s_handlers[0x089C5E30u] = [](psprecomp::Runtime &rt, psprecomp::AllegrexContext &ctx) {
        const std::uint32_t fd   = ctx.gpr[4];
        const std::uint32_t buf  = ctx.gpr[5];
        const std::uint32_t size = ctx.gpr[6];
        auto it = s_fds.find(fd);
        if (it == s_fds.end()) { ctx.gpr[2] = static_cast<std::uint32_t>(-1); ctx.pc = ctx.gpr[31]; return; }
        HostFd &hfd = it->second;
        std::size_t n = 0u;
        std::vector<std::uint8_t> tmp(size);
        if (hfd.disc_iso) {
            const std::uint64_t avail = hfd.disc_size > hfd.disc_pos ? hfd.disc_size - hfd.disc_pos : 0u;
            const std::size_t want = static_cast<std::size_t>(std::min<std::uint64_t>(size, avail));
            if (want > 0u) {
                n = hfd.disc_iso->read(hfd.disc_offset + hfd.disc_pos, std::span<std::uint8_t>(tmp.data(), want));
                hfd.disc_pos += n;
            }
        } else {
            n = std::fread(tmp.data(), 1, size, hfd.fp);
        }
        if (n > 0u) rt.memory().copy_in(buf, std::span<const std::uint8_t>(tmp.data(), n));
        std::printf("[IO-READ-HLE] fd=%u requested=%u read=%zu guest_buf=0x%08X\n", fd, size, n, buf);
        std::fflush(stdout);
        ctx.gpr[2] = static_cast<std::uint32_t>(n);
        ctx.pc = ctx.gpr[31];
    };
    // sceIoClose(fd) -> 0
    s_handlers[0x089C5E48u] = [](psprecomp::Runtime &, psprecomp::AllegrexContext &ctx) {
        const std::uint32_t fd = ctx.gpr[4];
        auto it = s_fds.find(fd);
        if (it != s_fds.end()) {
            if (it->second.fp) std::fclose(it->second.fp);
            s_fds.erase(it);
        }
        ctx.gpr[2] = 0u;
        ctx.pc = ctx.gpr[31];
    };
    // sceIoLseek(fd, offset_hi, offset_lo, whence) -> new position
    s_handlers[0x089C5EB8u] = [](psprecomp::Runtime &, psprecomp::AllegrexContext &ctx) {
        const std::uint32_t fd = ctx.gpr[4];
        // 64-bit offset in a5:a4 (hi in gpr[5], lo in gpr[6]) — PSP ABI for 64-bit args
        const std::int64_t offset = (static_cast<std::int64_t>(ctx.gpr[5]) << 32) | ctx.gpr[6];
        const int whence = static_cast<int>(ctx.gpr[7]);
        auto it = s_fds.find(fd);
        if (it == s_fds.end()) { ctx.gpr[2] = static_cast<std::uint32_t>(-1); ctx.pc = ctx.gpr[31]; return; }
        HostFd &hfd = it->second;
        std::int64_t pos = -1;
        if (hfd.disc_iso) {
            std::int64_t new_pos = static_cast<std::int64_t>(hfd.disc_pos);
            if      (whence == SEEK_SET) new_pos = offset;
            else if (whence == SEEK_CUR) new_pos += offset;
            else if (whence == SEEK_END) new_pos = static_cast<std::int64_t>(hfd.disc_size) + offset;
            if (new_pos < 0) new_pos = 0;
            hfd.disc_pos = static_cast<std::uint64_t>(new_pos);
            pos = new_pos;
        } else {
            const int r = std::fseek(hfd.fp, static_cast<long>(offset), whence);
            pos = r == 0 ? std::ftell(hfd.fp) : -1;
        }
        ctx.gpr[2] = static_cast<std::uint32_t>(pos & 0xFFFFFFFFu);
        ctx.gpr[3] = static_cast<std::uint32_t>((pos >> 32) & 0xFFFFFFFFu);
        ctx.pc = ctx.gpr[31];
    };
    // sceIoWaitAsync(fd, res_ptr) -> 0
    s_handlers[0x089C5E90u] = [](psprecomp::Runtime &rt, psprecomp::AllegrexContext &ctx) {
        const std::uint32_t res_ptr = ctx.gpr[5];
        if (res_ptr && rt.memory().contains(res_ptr, 8u)) {
            rt.memory().store32(res_ptr,     0u);
            rt.memory().store32(res_ptr + 4u, 0u);
        }
        ctx.gpr[2] = 0u;
        ctx.pc = ctx.gpr[31];
    };
    // sceIoPollAsync(fd, res_ptr) -> 0
    s_handlers[0x089C5EC0u] = [](psprecomp::Runtime &rt, psprecomp::AllegrexContext &ctx) {
        const std::uint32_t res_ptr = ctx.gpr[5];
        if (res_ptr && rt.memory().contains(res_ptr, 8u)) {
            rt.memory().store32(res_ptr,     0u);
            rt.memory().store32(res_ptr + 4u, 0u);
        }
        ctx.gpr[2] = 0u;
        ctx.pc = ctx.gpr[31];
    };

    // ---- Display (sceDisplay) ----
    // sceDisplaySetFrameBuf(topaddr, bufferwidth, pixelformat, sync) -> 0
    s_handlers[0x089C5AC0u] = [](psprecomp::Runtime &rt, psprecomp::AllegrexContext &ctx) {
        s_framebuf = {ctx.gpr[4], ctx.gpr[5], ctx.gpr[6], ctx.gpr[7]};
        ++s_display_frame_count;
        if (s_display_frame_count <= 3u || (s_display_frame_count & 0x3Fu) == 0u)
            std::printf("[DISPLAY] SetFrameBuf vaddr=0x%08X bw=%u fmt=%u sync=%u frame=%u\n",
                        s_framebuf.vaddr, s_framebuf.bufferwidth, s_framebuf.pixelformat,
                        s_framebuf.sync, s_display_frame_count);
        // Update global display fb info for present code
        g_display_fb.vaddr  = ctx.gpr[4];
        g_display_fb.stride = ctx.gpr[5];
        g_display_fb.fmt    = static_cast<int>(ctx.gpr[6]);
        // Execute any pending GE display list and present the framebuffer.
        // This drives the frame pump even when the render thread scheduler crashes.
        if (psprecomp::g_ge_list_start != 0u && rt.memory().contains(psprecomp::g_ge_list_start, 4u)) {
            void *vram_ptr = rt.memory().raw_pointer(0x04000000u, 0x200000u);
            if (vram_ptr) {
                const auto *dl = reinterpret_cast<const std::uint32_t *>(
                    rt.memory().raw_pointer(psprecomp::g_ge_list_start, 4u));
                const auto &mem_vec = rt.memory().bytes();
                d012::ge_exec(dl, dl + 0x10000u, vram_ptr, 0x200000u,
                              mem_vec.data(), mem_vec.size(), 0x08000000u);
                psprecomp::g_ge_list_start = 0u;
            }
        }
        {
            const auto &vram = rt.memory().vram_bytes();
            const std::uint32_t vram_off = g_display_fb.vaddr & 0x1FFFFFu;
            const int fmt = g_display_fb.fmt;
            const std::size_t stride = d012::g_ge_last_fbw > 0 ? d012::g_ge_last_fbw
                                     : (g_display_fb.stride > 0 ? g_display_fb.stride : 512u);
            const std::size_t bpp = fmt == 3 ? 4u : 2u;
            const std::size_t fb_bytes = stride * 272u * bpp;
            const std::uint8_t *fb_ptr = (vram_off + fb_bytes <= vram.size())
                ? vram.data() + vram_off : vram.data();
            d012::display_present(fb_ptr, static_cast<int>(stride), fmt);
            d012::display_pump();
        }
        ctx.gpr[2] = 0u;
        ctx.pc = ctx.gpr[31];
    };
    // sceDisplaySetMode(mode, width, height) -> 0
    s_handlers[0x089C5AE0u] = [](psprecomp::Runtime &, psprecomp::AllegrexContext &ctx) {
        std::printf("[DISPLAY] SetMode mode=%u w=%u h=%u\n", ctx.gpr[4], ctx.gpr[5], ctx.gpr[6]);
        ctx.gpr[2] = 0u;
        ctx.pc = ctx.gpr[31];
    };
    // sceDisplayWaitVblankStart() -> present + 0
    auto vblank_present = [](psprecomp::Runtime &rt, psprecomp::AllegrexContext &ctx) {
        if (psprecomp::g_ge_list_start != 0u && rt.memory().contains(psprecomp::g_ge_list_start, 4u)) {
            void *vram_ptr = rt.memory().raw_pointer(0x04000000u, 0x200000u);
            if (vram_ptr) {
                const auto *dl = reinterpret_cast<const std::uint32_t *>(
                    rt.memory().raw_pointer(psprecomp::g_ge_list_start, 4u));
                const auto &mem_vec = rt.memory().bytes();
                d012::ge_exec(dl, dl + 0x10000u, vram_ptr, 0x200000u,
                              mem_vec.data(), mem_vec.size(), 0x08000000u);
                psprecomp::g_ge_list_start = 0u;
            }
        }
        {
            const auto &vram = rt.memory().vram_bytes();
            const std::uint32_t vram_off = g_display_fb.vaddr & 0x1FFFFFu;
            const int fmt = g_display_fb.fmt;
            const std::size_t stride = d012::g_ge_last_fbw > 0 ? d012::g_ge_last_fbw
                                     : (g_display_fb.stride > 0 ? g_display_fb.stride : 512u);
            const std::size_t bpp = fmt == 3 ? 4u : 2u;
            const std::size_t fb_bytes = stride * 272u * bpp;
            const std::uint8_t *fb_ptr = (vram_off + fb_bytes <= vram.size())
                ? vram.data() + vram_off : vram.data();
            d012::display_present(fb_ptr, static_cast<int>(stride), fmt);
            d012::display_pump();
        }
        ctx.gpr[2] = 0u;
        ctx.pc = ctx.gpr[31];
    };
    s_handlers[0x089C5AD8u] = vblank_present;
    s_handlers[0x089C5AD0u] = vblank_present;
    s_handlers[0x089C5AC8u] = vblank_present;
    // sceCtrlReadBufferPositive — must be in s_handlers so generic_stub overrides the
    // generated stub and invoke_chained_call can find it (lookup_function_override path).
    s_handlers[0x089C5AA8u] = [](psprecomp::Runtime &rt2, psprecomp::AllegrexContext &ctx) {
        static std::uint32_t s_ctrl_frame = 0u;
        ++s_ctrl_frame;
        const bool inject_start = (s_ctrl_frame >= 60u && s_ctrl_frame <= 180u);
        const std::uint32_t buttons = inject_start ? 0x0008u : 0u;
        const std::uint32_t buf = ctx.gpr[4];
        const std::uint32_t count = ctx.gpr[5];
        for (std::uint32_t i = 0u; i < count && i < 64u; ++i) {
            const std::uint32_t entry = buf + i * 12u;
            if (rt2.memory().contains(entry, 12u)) {
                rt2.memory().store32(entry,      0u);
                rt2.memory().store32(entry + 4u, buttons);
                rt2.memory().store32(entry + 8u, 0x00808000u);
            }
        }
        ctx.gpr[2] = count;
        ctx.pc = ctx.gpr[31];
    };
    // 0x089C5AB8 = sceDisplaySetMode(mode, width, height)
    s_handlers[0x089C5AB8u] = [](psprecomp::Runtime &, psprecomp::AllegrexContext &ctx) {
        ctx.gpr[2] = 0u;
        ctx.pc = ctx.gpr[31];
    };

    // Force-register generic_stub at every known handler VA — PortableKit's
    // register_import_stub already claimed all syscall stub VAs before patch_d012_image
    // runs, so the ELF cluster scan below won't install generic_stub there
    // (has_function returns true). We must overwrite with generic_stub explicitly;
    // generic_stub dispatches at call-time through s_handlers so all entries are served.
    for (auto &[va, fn_] : s_handlers) {
        (void)fn_;
        rt.register_function(va, generic_stub, "d012_stub");
    }

    // Cluster scan: runs of 3+ consecutive (jr $ra / nop) pairs = stub table
    const auto &bytes = elf.bytes();
    const auto &segs  = elf.segments();
    if (segs.empty()) { std::printf("[scan] No segments\n"); return; }

    const std::uint32_t bias      = segs[0].vaddr - segs[0].offset;
    const std::size_t   seg_start = segs[0].offset;
    const std::size_t   seg_end   = segs[0].offset + segs[0].file_size;

    int           run          = 0;
    std::uint32_t run_start_va = 0u;
    std::uint32_t total        = 0u;

    auto flush = [&]() {
        if (run >= 3) {
            for (int k = 0; k < run; ++k) {
                const std::uint32_t va = run_start_va + static_cast<std::uint32_t>(k) * 8u;
                if (!rt.has_function(va)) {
                    rt.register_function(va, generic_stub, "stub");
                    ++total;
                }
            }
        }
        run = 0;
    };

    for (std::size_t off = seg_start; off + 8u <= seg_end; off += 8u) {
        const std::uint32_t w0 =
            static_cast<std::uint32_t>(bytes[off+0])        |
            (static_cast<std::uint32_t>(bytes[off+1]) <<  8)|
            (static_cast<std::uint32_t>(bytes[off+2]) << 16)|
            (static_cast<std::uint32_t>(bytes[off+3]) << 24);
        const std::uint32_t w1 =
            static_cast<std::uint32_t>(bytes[off+4])        |
            (static_cast<std::uint32_t>(bytes[off+5]) <<  8)|
            (static_cast<std::uint32_t>(bytes[off+6]) << 16)|
            (static_cast<std::uint32_t>(bytes[off+7]) << 24);

        if (w0 == 0x03E00008u && w1 == 0x00000000u) {
            if (run == 0) run_start_va = static_cast<std::uint32_t>(off) + bias;
            ++run;
        } else {
            flush();
        }
    }
    flush();
    std::printf("[scan] Registered %u stubs\n", total);
}

void set_runtime(psprecomp::Runtime &rt) {
    s_runtime_ptr = &rt;
}

void register_hle(psprecomp::Runtime &rt) {
    s_runtime_ptr = &rt;
    std::thread([&rt]() {
        for (;;) {
            std::this_thread::sleep_for(std::chrono::seconds(3));
            std::printf("[WATCHDOG] cpu.pc=0x%08X dispatch_pc=0x%08X ra=0x%08X sp=0x%08X\n",
                        rt.cpu().pc, psprecomp::runtime_dispatch_pc(), rt.cpu().gpr[31], rt.cpu().gpr[29]);
            {
                const auto &v = rt.memory().vram_bytes();
                const std::size_t off = g_display_fb.vaddr & 0x1FFFFFu;
                std::size_t nz = 0;
                for (std::size_t i = 0; i < 512u * 272u * 2u && off + i < v.size(); ++i) nz += v[off + i] != 0;
                std::printf("[WATCHDOG] display fb 0x%08X fmt=%d nonzero bytes=%zu\n", g_display_fb.vaddr, g_display_fb.fmt, nz);
                {
                    std::size_t blk[8] = {};
                    for (std::size_t i = 0; i < v.size() && i < 0x200000u; ++i) blk[i >> 18] += v[i] != 0;
                    std::printf("[WATCHDOG] vram nonzero per 256KB: %zu %zu %zu %zu %zu %zu %zu %zu\n",
                                blk[0], blk[1], blk[2], blk[3], blk[4], blk[5], blk[6], blk[7]);
                }
                if (const char *tmp = std::getenv("TEMP")) {
                    const std::size_t offs[2] = { d012::g_ge_last_fbp & 0x1FFFFFu, 0u };
                    for (int k = 0; k < 2; ++k) {
                        const std::string path = std::string(tmp) + "\\d012_fb" + std::to_string(k) + ".bin";
                        if (FILE *fp = std::fopen(path.c_str(), "wb")) {
                            if (offs[k] + 512u * 272u * 2u <= v.size()) std::fwrite(v.data() + offs[k], 1, 512u * 272u * 2u, fp);
                            std::fclose(fp);
                        }
                    }
                }
                std::printf("[WATCHDOG] scene pending(09B4CF98)=0x%08X active(09B48358)=0x%08X rendergate(089D69DC)=%u\n",
                    rt.memory().aot_load32(0x09B4CF98u), rt.memory().aot_load32(0x09B48358u), rt.memory().aot_load32(0x089D69DCu));
                const std::uint32_t gp = rt.memory().aot_load32(0x089D5EC0u);
                std::printf("[WATCHDOG] DISPFLAG(09AF67F0)=%u ctxinit(09AF67E8)=%u gfx=0x%08X state2cd0=%u drawbuf(09AF6818)=0x%X dispbuf(09AF6814)=0x%X\n",
                    rt.memory().aot_load32(0x09AF67F0u), rt.memory().aot_load32(0x09AF67E8u), gp,
                    gp ? rt.memory().aot_load32(gp + 0x2cd0u) & 0xFFu : 99u,
                    rt.memory().aot_load32(0x09AF6818u), rt.memory().aot_load32(0x09AF6814u));
            }
            std::fflush(stdout);
        }
    }).detach();
    psprecomp::g_runtime_starvation_interval_fast = 0u;
    // NOTE: 0x08800000 is PortableKit's kThreadExitStub (kernel().thread_exit_stub).
    // Do NOT register anything at this address — PortableKit owns it for cooperative
    // thread scheduling. Overwriting it causes module_start to stop the runtime
    // instead of yielding to the next ready thread.
    // Install frame-complete hook: when a function returns via ra=0 (null-PC)
    // while inside the render thread (after FUN_08933398 init), redirect to
    // L_089333E0 to re-enter the per-frame render loop.
    // Before the render thread starts, return 0 so runtime.run() stops and
    // hle_run_next_thread() can be called.
    psprecomp::g_frame_reset_sp = 0x09EF0000u; // render thread stack base
    psprecomp::g_frame_complete_hook = []() -> std::uint32_t {
        static bool s_render_thread_running = false;
        static std::uint32_t s = 0u;
        if (!s_render_thread_running) {
            // First null-PC: main game thread has queued the render thread and exited.
            // Let runtime.run() stop so hle_run_next_thread() can be called.
            s_render_thread_running = true;
            std::printf("[FRAME-RECOVERY] main thread done, stopping for render thread handoff\n");
            std::fflush(stdout);
            return 0u; // -> sentinel -> rt.stop() -> hle_run_next_thread()
        }
        // Subsequent null-PCs: inside the render thread, redirect through scheduler.
        // 0x089333F0 calls the task scheduler (L_08933458) then enters L_0893354C,
        // ensuring tasks run every frame. gpr[16] (callee-saved) holds the task list ptr.
        if (++s <= 10u) std::printf("[FRAME-RECOVERY] null-PC in render thread -> 0x089333F0 (via scheduler)\n");
        std::fflush(stdout);
        return 0x089333F0u;
    };
    // NOTE: sceIoOpen (0x109F50BC) and sceIoClose (0x810C4BC3) must NOT be
    // overridden here. PortableKit's real IO HLE handles disc image reads.
    // Returning -1 for sceIoOpen causes an infinite retry loop on package_info.bin.
    // NOTE: ThreadManForUser and SysMemUserForUser overrides removed.
    // PortableKit provides real sceKernelTerminateThread, sceKernelAllocPartitionMemory,
    // sceKernelGetBlockHeadAddr, and sceKernelFreePartitionMemory. Overriding them with
    // stubs breaks memory management and thread handling.

    // FUN_088635ec is missing from AOT output (only reachable via vtable): sprintf path, then FUN_08935d58.
    rt.register_function(0x088635ECu, [](psprecomp::Runtime &rt2, psprecomp::AllegrexContext &ctx) {
        const std::uint32_t ra = ctx.gpr[31], sp = ctx.gpr[29], s0 = ctx.gpr[16];
        const std::uint32_t out = ctx.gpr[5];
        ctx.gpr[4] = out; ctx.gpr[5] = 0x089C9168u; ctx.gpr[31] = 2u; ctx.pc = 0x0893476Cu;
        (void)rt2.invoke_chained_call(ctx);
        ctx.gpr[4] = out; ctx.gpr[31] = 2u; ctx.pc = 0x08935D58u;
        (void)rt2.invoke_chained_call(ctx);
        ctx.gpr[31] = ra; ctx.gpr[29] = sp; ctx.gpr[16] = s0;
        ctx.pc = ra;
    }, "hle_088635EC");

// The game loads LIBFONT.PRX into heap via PortableKit's sceKernelStartModule.
// The PRX entry lands at 0x09AE7070 (seen in logs). invoke_chained_call returns
// false (direct_chainable_ is null for heap addresses), so the main dispatch loop
// calls lookup_function(0x09AE7070). Register our nop there so it returns 0.
    rt.register_function(0x09AE7070u, [](psprecomp::Runtime &, psprecomp::AllegrexContext &ctx) {
        static unsigned s_n = 0;
        if (s_n++ < 4) { std::printf("[HLE-STUB] PRX-init nop 0x09AE7070 ra=0x%08X\n", ctx.gpr[31]); std::fflush(stdout); }
        ctx.gpr[2] = 0u;
        ctx.pc = ctx.gpr[31];
    }, "hle_prx_09AE7070_nop");

// Stub out the jump-table dispatch function that crashes when task object
// byte[96] indexes into an uninitialised table (null ptr + offset).
    rt.register_function(0x08844F84u, [](psprecomp::Runtime &, psprecomp::AllegrexContext &ctx) {
        ctx.gpr[2] = 0u;
        ctx.pc = ctx.gpr[31];
    }, "task_jt_dispatch_stub");

// sceDisplayWaitVblankStart variants — present here so any thread calling vblank wait
// gets a frame. This fires every time the game's render tasks yield to the display.
    auto frame_present_fn = [](psprecomp::Runtime &rt2, psprecomp::AllegrexContext &ctx) {
        static std::uint32_t s_frame = 0u;
        ++s_frame;
        // Execute any pending GE display list
        if (psprecomp::g_ge_list_start != 0u && rt2.memory().contains(psprecomp::g_ge_list_start, 4u)) {
            void *vram_ptr = rt2.memory().raw_pointer(0x04000000u, 0x200000u);
            if (vram_ptr) {
                const auto *dl = reinterpret_cast<const std::uint32_t *>(
                    rt2.memory().raw_pointer(psprecomp::g_ge_list_start, 4u));
                const auto &mem_vec = rt2.memory().bytes();
                d012::ge_exec(dl, dl + 0x10000u, vram_ptr, 0x200000u,
                              mem_vec.data(), mem_vec.size(), 0x08000000u);
                psprecomp::g_ge_list_start = 0u;
            }
        }
        if (d012::g_ge_last_fbw > 0u || g_display_fb.stride > 0u) {
            const auto &vram = rt2.memory().vram_bytes();
            const std::uint32_t vram_off = g_display_fb.vaddr & 0x1FFFFFu;
            const int fmt = g_display_fb.fmt;
            const std::size_t stride = g_display_fb.stride > 0u ? g_display_fb.stride : 512u;
            const std::size_t bpp = fmt == 3 ? 4u : 2u;
            const std::size_t fb_bytes = stride * 272u * bpp;
            const std::uint8_t *fb_ptr = (vram_off + fb_bytes <= vram.size())
                ? vram.data() + vram_off : vram.data();
            if (s_frame <= 3u || (s_frame & 0x3Fu) == 0u)
                std::printf("[VBLANK-PRESENT] frame=%u vram_off=0x%X stride=%zu fmt=%d\n",
                            s_frame, vram_off, stride, fmt);
            d012::display_present(fb_ptr, static_cast<int>(stride), fmt);
            if (!d012::display_pump()) { rt2.stop("window closed"); return; }
        }
        ctx.gpr[2] = 0u;
        ctx.pc = ctx.gpr[31];

        // ARCH-SYNTH: scene activation — once pending scene is set, call FUN_088A2664
        // to run the scene's vtable startup (sets render state), then promote to active.
        { static bool s_scene_activated = false;
          if (!s_scene_activated) {
              const std::uint32_t pending = rt2.memory().aot_load32(0x09B4CF98u);
              const std::uint32_t active  = rt2.memory().aot_load32(0x09B48358u);
              if (pending != 0u && active == 0u) {
                  std::printf("[FRAME-SCENE-ACT] pending=0x%08X → calling FUN_088A2664\n", pending); fflush(stdout);
                  // Save registers, call FUN_088A2664(pending, 0, 0.0f) via chained call,
                  // then restore caller registers and promote pending→active.
                  const std::uint32_t saved_pc  = ctx.pc;
                  const std::uint32_t saved_ra  = ctx.gpr[31];
                  const std::uint32_t saved_sp  = ctx.gpr[29];
                  ctx.gpr[4]  = pending;
                  ctx.gpr[5]  = 0u;
                  ctx.fpr[12] = 0.0f;
                  ctx.gpr[31] = 0x088A26DCu; // epilog/return address inside FUN_088A2664
                  ctx.pc      = 0x088A2664u;
                  rt2.invoke_chained_call(ctx);
                  ctx.pc     = saved_pc;
                  ctx.gpr[31]= saved_ra;
                  ctx.gpr[29]= saved_sp;
                  // Now promote pending → active
                  rt2.memory().aot_store32(0x09B48358u, pending);
                  rt2.memory().aot_store32(0x09B4835Cu, pending);
                  rt2.memory().aot_store32(0x09B4CF98u, 0u);
                  std::printf("[FRAME-SCENE-ACT] promoted 0x%08X to active\n", pending); fflush(stdout);
                  s_scene_activated = true;
              }
          }
        }

        // ARCH-SYNTH: scene tick — call FUN_08874DFC and FUN_08873E6C every frame
        // once the scene is active. These fill the GE display list with geometry.
        { const std::uint32_t active = rt2.memory().aot_load32(0x09B48358u);
          if (active != 0u) {
              const std::uint32_t saved_pc  = ctx.pc;
              const std::uint32_t saved_ra  = ctx.gpr[31];
              const std::uint32_t saved_sp  = ctx.gpr[29];
              // FUN_08874DFC(active)
              ctx.gpr[4]  = active;
              ctx.gpr[31] = 0x00000002u; // dummy return address (chained call ignores it)
              ctx.pc      = 0x08874DFCu;
              rt2.invoke_chained_call(ctx);
              // FUN_08873E6C(active)
              ctx.gpr[4]  = active;
              ctx.gpr[31] = 0x00000002u;
              ctx.pc      = 0x08873E6Cu;
              rt2.invoke_chained_call(ctx);
              ctx.pc     = saved_pc;
              ctx.gpr[31]= saved_ra;
              ctx.gpr[29]= saved_sp;
          }
        }

    };
    // Wire frame_present_fn to all sceDisplayWaitVblank* stubs so any path through them presents
    rt.register_function(0x089C5AD8u, frame_present_fn, "sceDisplayWaitVblankStart");
    rt.register_function(0x089C5AD0u, frame_present_fn, "sceDisplayWaitVblankStartCB");
    rt.register_function(0x089C5AC8u, frame_present_fn, "sceDisplayWaitVblank");
    // sceCtrlReadBufferPositive is now in s_handlers (registered via generic_stub above)

// Explicit HLE for CreateThread / StartThread wrapper addresses

    rt.register_function(0x00000000u, [](psprecomp::Runtime &rt, psprecomp::AllegrexContext &ctx) {
        std::printf("[HLE] null_fptr_stub: ra=0x%08X a0=0x%08X\n", ctx.gpr[31], ctx.gpr[4]);
        if (ctx.gpr[31] == 0u) { rt.stop("thread exited normally"); return; }
        ctx.pc = ctx.gpr[31];
    }, "null_fptr_stub");
    rt.register_function(0x00000001u, [](psprecomp::Runtime &rt, psprecomp::AllegrexContext &ctx) {
        std::printf("[HLE] sentinel hit ra=0x%08X pc=0x%08X\n", ctx.gpr[31], ctx.pc);
        std::fflush(stdout);
        if (ctx.gpr[31] == 0x00000001u || ctx.gpr[31] == 0u) {
            rt.stop("thread exited normally");
        }
    }, "hle_thread_exit");

    // NOTE: 0x089C6000 (sceKernelExitDeleteThread) and 0x089C6030 (sceKernelExitThread)
    // must NOT be overridden. PortableKit's force_import_stub binds them to
    // kernel().exit_current_thread() which properly switches cooperative threads.
    // Nop-return overrides break the scheduler.

    // ThreadManForUser stubs

    // sceKernelCreateCallback(name, func, arg) -> uid
    rt.register_function(0x089C5F80u, [](psprecomp::Runtime &, psprecomp::AllegrexContext &ctx) {
        const std::uint32_t uid = s_next_cb_uid++;
        s_callbacks[uid] = ctx.gpr[5];
        std::printf("[HLE] sceKernelCreateCallback func=0x%08X -> uid=%u\n", ctx.gpr[5], uid);
        ctx.gpr[2] = uid;
        ctx.pc     = ctx.gpr[31];
    }, "recomp_unit_createcallback");

    // sceKernelDeleteCallback(uid) -> 0
    rt.register_function(0x089C5F90u, [](psprecomp::Runtime &, psprecomp::AllegrexContext &ctx) {
        s_callbacks.erase(ctx.gpr[4]);
        ctx.gpr[2] = 0u;
        ctx.pc     = ctx.gpr[31];
    }, "recomp_unit_deletecallback");

    // sceKernelChangeCurrentThreadAttr -> 0
    rt.register_function(0x089C5F88u, [](psprecomp::Runtime &, psprecomp::AllegrexContext &ctx) {
        ctx.gpr[2] = 0u;
        ctx.pc     = ctx.gpr[31];
    }, "recomp_unit_changethreadattr");

#if 0 // stubs replaced by PortableKit's real blocking kernel
    // sceKernelDelayThread(us) -> 0; yield to other threads
    rt.register_function(0x089C5F68u, [](psprecomp::Runtime &rt2, psprecomp::AllegrexContext &ctx) {
        ctx.gpr[2] = 0u;
        ctx.pc     = ctx.gpr[31];
        if (s_live_threads.size() > 1u) rt2.stop("yield");
    }, "recomp_unit_delaythread");

    // sceKernelDelayThreadCB(us) -> 0; yield to other threads
    rt.register_function(0x089C5FF0u, [](psprecomp::Runtime &rt2, psprecomp::AllegrexContext &ctx) {
        ctx.gpr[2] = 0u;
        ctx.pc     = ctx.gpr[31];
        if (s_live_threads.size() > 1u) rt2.stop("yield");
    }, "recomp_unit_delaythreadcb");

    // sceKernelCreateSema(name, attr, initVal, maxVal, opt) -> uid
    rt.register_function(0x089C5F70u, [](psprecomp::Runtime &, psprecomp::AllegrexContext &ctx) {
        const std::uint32_t uid = s_next_sema_uid++;
        s_semas[uid] = static_cast<std::int32_t>(ctx.gpr[6]);
        std::printf("[HLE] sceKernelCreateSema initVal=%d -> uid=%u\n", ctx.gpr[6], uid);
        ctx.gpr[2] = uid;
        ctx.pc     = ctx.gpr[31];
    }, "recomp_unit_createsema");

    // sceKernelDeleteSema(uid) -> 0
    rt.register_function(0x089C5F78u, [](psprecomp::Runtime &, psprecomp::AllegrexContext &ctx) {
        s_semas.erase(ctx.gpr[4]);
        ctx.gpr[2] = 0u;
        ctx.pc     = ctx.gpr[31];
    }, "recomp_unit_deletesema");

    // sceKernelSignalSema(uid, signal) -> 0
    rt.register_function(0x089C5FC0u, [](psprecomp::Runtime &, psprecomp::AllegrexContext &ctx) {
        auto it = s_semas.find(ctx.gpr[4]);
        if (it != s_semas.end()) it->second += static_cast<std::int32_t>(ctx.gpr[5]);
        ctx.gpr[2] = 0u;
        ctx.pc     = ctx.gpr[31];
    }, "recomp_unit_signalsema");

    // sceKernelWaitSema(uid, signal, timeout) -> 0; yield to other threads
    rt.register_function(0x089C5FC8u, [](psprecomp::Runtime &rt2, psprecomp::AllegrexContext &ctx) {
        ctx.gpr[2] = 0u;
        ctx.pc     = ctx.gpr[31];
        if (s_live_threads.size() > 1u) rt2.stop("yield");
    }, "recomp_unit_waitsema");

    // sceKernelWaitThreadEnd(uid, timeout) -> 0
    rt.register_function(0x089C5FB0u, [](psprecomp::Runtime &, psprecomp::AllegrexContext &ctx) {
        ctx.gpr[2] = 0u;
        ctx.pc     = ctx.gpr[31];
    }, "recomp_unit_waitthreadend");
#endif


    rt.register_function(0x089C5FD0u, [](psprecomp::Runtime &, psprecomp::AllegrexContext &ctx) {
        const std::uint32_t uid = s_next_thread_uid++;
        ThreadDesc td{ctx.gpr[5], uid, 0u, 0u, ctx.gpr[6]};
        s_threads[uid] = td;
        s_thread_entry = ctx.gpr[5]; // keep compat
        ctx.gpr[2] = uid;
        ctx.pc     = ctx.gpr[31];
        std::printf("[HLE] sceKernelCreateThread uid=%u entry=0x%08X priority=%u\n", uid, td.entry, td.priority);
    }, "recomp_unit_createthread");

    rt.register_function(0x089C5FA0u, [](psprecomp::Runtime &, psprecomp::AllegrexContext &ctx) {
        const std::uint32_t uid    = ctx.gpr[4];
        const std::uint32_t arglen = ctx.gpr[5];
        const std::uint32_t argp   = ctx.gpr[6];
        auto it = s_threads.find(uid);
        if (it != s_threads.end()) {
            ThreadDesc td = it->second;
            td.arglen = arglen;
            td.argp   = argp;
            s_thread_queue.push_back(td);
            std::printf("[HLE] sceKernelStartThread uid=%u entry=0x%08X queued\n", uid, td.entry);
        } else {
            std::printf("[HLE] sceKernelStartThread uid=%u NOT FOUND\n", uid);
        }
        ctx.gpr[2] = 0u;
        ctx.pc     = ctx.gpr[31];
    }, "recomp_unit_startthread");

#if 0 // event flag stubs replaced by PortableKit
    // sceKernelCreateEventFlag(name, attr, bits, opt) -> uid
    rt.register_function(0x089C5FE0u, [](psprecomp::Runtime &, psprecomp::AllegrexContext &ctx) {
        static std::uint32_t s_next_evf = 0x300u;
        const std::uint32_t uid = s_next_evf++;
        ctx.gpr[2] = uid;
        ctx.pc     = ctx.gpr[31];
        std::printf("[HLE] sceKernelCreateEventFlag -> uid=%u\n", uid);
    }, "recomp_unit_createeventflag");

    // sceKernelDeleteEventFlag(uid) -> 0
    rt.register_function(0x089C5F98u, [](psprecomp::Runtime &, psprecomp::AllegrexContext &ctx) {
        ctx.gpr[2] = 0u;
        ctx.pc     = ctx.gpr[31];
    }, "recomp_unit_deleteeventflag");
#endif

    // sceKernelRegisterExitCallback(uid) -> 0
    rt.register_function(0x089C5EF8u, [](psprecomp::Runtime &, psprecomp::AllegrexContext &ctx) {
        ctx.gpr[2] = 0u;
        ctx.pc     = ctx.gpr[31];
    }, "recomp_unit_registerexitcb");

    // sceKernelExitGame() -> noreturn; just stop
    rt.register_function(0x089C5EF0u, [](psprecomp::Runtime &rt, psprecomp::AllegrexContext &) {
        rt.stop("sceKernelExitGame");
    }, "recomp_unit_exitgame");

    // sceGeEdramGetAddr() -> 0x04000000 (VRAM base on PSP)
    rt.register_function(0x089C5A98u, [](psprecomp::Runtime &, psprecomp::AllegrexContext &ctx) {
        ctx.gpr[2] = 0x04000000u;
        ctx.pc     = ctx.gpr[31];
    }, "recomp_unit_geedramgetaddr");

    // sceGeEdramGetSize() -> 0x200000
    rt.register_function(0x089C5A60u, [](psprecomp::Runtime &, psprecomp::AllegrexContext &ctx) {
        ctx.gpr[2] = 0x00200000u;
        ctx.pc     = ctx.gpr[31];
    }, "recomp_unit_geedramgetsize");

    // sceGeSetCallback(cb_struct_ptr) -> slot index (ported from 3rd Birthday h_GeSetCallback)
    rt.register_function(0x089C5A70u, [](psprecomp::Runtime &rt2, psprecomp::AllegrexContext &ctx) {
        const std::uint32_t info = ctx.gpr[4];
        for (std::uint32_t i = 0u; i < 16u; ++i) {
            if (!s_ge_cb[i].used) {
                s_ge_cb[i].used = 1;
                s_ge_cb[i].signal_func = (info && rt2.memory().contains(info,     4u)) ? rt2.memory().load32(info)      : 0u;
                s_ge_cb[i].signal_arg  = (info && rt2.memory().contains(info + 4u, 4u)) ? rt2.memory().load32(info + 4u)  : 0u;
                s_ge_cb[i].finish_func = (info && rt2.memory().contains(info + 8u, 4u)) ? rt2.memory().load32(info + 8u)  : 0u;
                s_ge_cb[i].finish_arg  = (info && rt2.memory().contains(info +12u, 4u)) ? rt2.memory().load32(info + 12u) : 0u;
                std::printf("[GE-SETCB] slot=%u sig=0x%08X fin=0x%08X\n", i, s_ge_cb[i].signal_func, s_ge_cb[i].finish_func);
                ctx.gpr[2] = i;
                ctx.pc     = ctx.gpr[31];
                return;
            }
        }
        ctx.gpr[2] = 0xFFFFFFFFu;
        ctx.pc     = ctx.gpr[31];
    }, "recomp_unit_gesetcallback");

    // sceGeUnsetCallback(id) -> 0
    rt.register_function(0x089C5A50u, [](psprecomp::Runtime &, psprecomp::AllegrexContext &ctx) {
        const std::uint32_t id = ctx.gpr[4];
        if (id < 16u) s_ge_cb[id].used = 0;
        ctx.gpr[2] = 0u;
        ctx.pc     = ctx.gpr[31];
    }, "recomp_unit_geunsetcallback");

    // FUN_0899FA64: thin wrapper around sceGeListEnQueue/sceGeListEnQueueHead.
    // param_1(gpr4)==1 -> EnQueueHead, else EnQueue. param_2(gpr5) = display list ptr.
    // DAT_09af67e0=0x09AF67E0 (flag cleared), DAT_09af6808=0x09AF6808 (cbid),
    // DAT_09af6804=0x09AF6804 (stores returned list_id). Returns 0 on success.
    rt.register_function(0x0899FA64u, [](psprecomp::Runtime &rt2, psprecomp::AllegrexContext &ctx) {
        static std::uint32_t s_n = 0u;
        const std::uint32_t param1  = ctx.gpr[4];
        const std::uint32_t list_va = ctx.gpr[5];
        const std::uint32_t list_phys = list_va & 0x1FFFFFFFu;
        // DAT_09af67e0 = 0
        rt2.memory().aot_store32(0x09AF67E0u, 0u);
        // DAT_09af6808 = cbid (from sceGeSetCallback); read it
        const std::uint32_t cbid = rt2.memory().aot_load32(0x09AF6808u);
        static std::uint32_t s_list_id = 1u;
        if (++s_n <= 6u) std::printf("[FUN_0899FA64] #%u param1=%u list=0x%08X cbid=%u\n", s_n, param1, list_phys, cbid);
        // Drive sceGeListEnQueue HLE logic inline (same as 0x089C5A78)
        const std::uint32_t list_id = 0x35000000u | (s_list_id++ & 0x00FFFFFFu);
        // DAT_09af6804 = list_id
        rt2.memory().aot_store32(0x09AF6804u, list_id);
        run_ge_list_now(rt2, list_phys, 0u);
        psprecomp::g_ge_list_start    = 0u;
        psprecomp::g_ge_list_executed = true;
        ge_finish_callback(rt2, ctx, cbid, list_id, 0u);
        if (!present_and_pump(rt2)) { rt2.stop("window closed"); return; }
        ctx.gpr[2] = 0u; // return 0 (success)
        ctx.pc     = ctx.gpr[31];
    }, "recomp_unit_0012_hle_0899FA64");

    // sceGeListEnQueue(list, stall, cbid, arg) -> list_id
    rt.register_function(0x089C5A78u, [](psprecomp::Runtime &rt2, psprecomp::AllegrexContext &ctx) {
        static std::uint32_t s_list_id = 1u;
        static std::uint32_t s_enq = 0u;
        const std::uint32_t list_phys  = ctx.gpr[4] & 0x1FFFFFFFu;
        const std::uint32_t stall_phys = ctx.gpr[5] & 0x1FFFFFFFu;
        const std::uint32_t list_id = 0x35000000u | (s_list_id++ & 0x00FFFFFFu);
        const std::uint32_t cbid = ctx.gpr[6], user_arg = ctx.gpr[7];
        run_ge_list_now(rt2, list_phys, stall_phys);
        psprecomp::g_ge_list_start    = 0u;
        psprecomp::g_ge_list_executed = true;
        if (++s_enq <= 20u) std::printf("[GE-ENQUEUE] list=0x%08X stall=0x%08X cbid=%u ra=0x%08X\n", list_phys, stall_phys, cbid, ctx.gpr[31]); std::fflush(stdout);
        ge_finish_callback(rt2, ctx, cbid, list_id, user_arg);
        ctx.gpr[2] = list_id;
        ctx.pc     = ctx.gpr[31];
    }, "recomp_unit_gelistenqueue");

    // sceGeListEnQueueHead(list, stall, cbid, arg) -> list_id
    rt.register_function(0x089C5A58u, [](psprecomp::Runtime &, psprecomp::AllegrexContext &ctx) {
        static std::uint32_t s_list_id_h = 0x80u;
        ctx.gpr[2] = s_list_id_h++;
        ctx.pc     = ctx.gpr[31];
    }, "recomp_unit_gelistenqueuehead");

    // sceGeListSync(listid, syncType) -> 0; yield to other threads
    rt.register_function(0x089C5A48u, [](psprecomp::Runtime &rt2, psprecomp::AllegrexContext &ctx) {
        static std::uint32_t s_gls = 0u; ++s_gls;
        if (s_gls <= 6u) std::printf("[HLE] sceGeListSync #%u list=0x%08X ra=0x%08X\n",
            s_gls, psprecomp::g_ge_list_start, ctx.gpr[31]);
        ctx.gpr[2] = 0u;
        ctx.pc     = ctx.gpr[31];
        if (s_live_threads.size() > 1u) rt2.stop("yield");
    }, "recomp_unit_gelistsync");

    // sceGeDrawSync(syncType) -> 0; present frame and yield to other threads
    rt.register_function(0x089C5A80u, [](psprecomp::Runtime &rt2, psprecomp::AllegrexContext &ctx) {
        // Execute any still-pending GE list
        if (psprecomp::g_ge_list_start != 0u && rt2.memory().contains(psprecomp::g_ge_list_start, 4u)) {
            void *vram_ptr = rt2.memory().raw_pointer(0x04000000u, 0x200000u);
            if (vram_ptr) {
                const auto *dl = reinterpret_cast<const std::uint32_t *>(
                    rt2.memory().raw_pointer(psprecomp::g_ge_list_start, 4u));
                const auto &mem_vec = rt2.memory().bytes();
                d012::ge_exec(dl, dl + 0x10000u, vram_ptr, 0x200000u,
                              mem_vec.data(), mem_vec.size(), 0x08000000u);
                psprecomp::g_ge_list_start = 0u;
            }
        }
        // Present after draw sync — this is the frame boundary
        {
            static std::uint32_t s_ds = 0u; ++s_ds;
            const auto &vram = rt2.memory().vram_bytes();
            const std::uint32_t vram_off = g_display_fb.vaddr & 0x1FFFFFu;
            const int fmt = g_display_fb.fmt;
            const std::size_t stride = g_display_fb.stride > 0u ? g_display_fb.stride : 512u;
            if (stride > 0u && fmt >= 0) {
                const std::size_t bpp = fmt == 3 ? 4u : 2u;
                const std::size_t fb_bytes = stride * 272u * bpp;
                const std::uint8_t *fb_ptr = (vram_off + fb_bytes <= vram.size())
                    ? vram.data() + vram_off : vram.data();
                if (s_ds <= 3u || (s_ds & 0x3Fu) == 0u)
                    std::printf("[DRAWSYNC-PRESENT] #%u vram_off=0x%X stride=%zu fmt=%d\n", s_ds, vram_off, stride, fmt);
                d012::display_present(fb_ptr, static_cast<int>(stride), fmt);
                if (!d012::display_pump()) { rt2.stop("window closed"); return; }
            }
        }
        // Set return value and resume PC before yielding so cooperative scheduler can resume
        ctx.gpr[2] = 0u;
        ctx.pc     = ctx.gpr[31];
        // Yield to other threads (loading, audio, etc.) — this is what PortableKit's
        // Kernel does at every sceGeDrawSync: switch to the next ready thread
        if (s_live_threads.size() > 1u) {
            rt2.stop("yield");
        }
    }, "recomp_unit_gedrawsync");

    // sceGeBreak(mode, pbresult) -> 0
    rt.register_function(0x089C5A88u, [](psprecomp::Runtime &, psprecomp::AllegrexContext &ctx) {
        ctx.gpr[2] = 0u;
        ctx.pc     = ctx.gpr[31];
    }, "recomp_unit_gebreak");

    // sceGeContinue() -> 0
    rt.register_function(0x089C5A68u, [](psprecomp::Runtime &, psprecomp::AllegrexContext &ctx) {
        ctx.gpr[2] = 0u;
        ctx.pc     = ctx.gpr[31];
    }, "recomp_unit_gecontinue");

    // sceGeListUpdateStallAddr(listid, stall) -> 0
    // On PSP this tells the GE "I've written more DL commands up to 'stall', go execute them."
    // We must execute from g_ge_exec_cursor up to new stall.
    rt.register_function(0x089C5A90u, [](psprecomp::Runtime &rt, psprecomp::AllegrexContext &ctx) {
        static std::uint32_t s_upd = 0u;
        const std::uint32_t new_stall = ctx.gpr[5] & 0x1FFFFFFFu;
        const std::uint32_t cursor    = psprecomp::g_ge_exec_cursor & 0x1FFFFFFFu;
        if (++s_upd <= 6u)
            std::printf("[GE-UPDATESTALL] #%u listid=%u stall=0x%08X cursor=0x%08X\n",
                        s_upd, ctx.gpr[4], new_stall, cursor);
        if (new_stall != 0u && new_stall > cursor &&
            rt.memory().contains(cursor, 4u) && rt.memory().contains(new_stall - 4u, 4u)) {
            const auto *dl_ptr = reinterpret_cast<const std::uint32_t *>(rt.memory().raw_pointer(cursor, 4u));
            const auto *dl_end = reinterpret_cast<const std::uint32_t *>(rt.memory().raw_pointer(new_stall, 4u));
            void *vram_ptr = rt.memory().raw_pointer(0x04000000u, 0x200000u);
            const auto &mem_vec = rt.memory().bytes();
            if (vram_ptr && dl_ptr && dl_end) {
                if (s_upd <= 6u) std::printf("[GE-UPDATESTALL] executing cursor..stall\n");
                d012::ge_exec(dl_ptr, dl_end, vram_ptr, 0x200000u, mem_vec.data(), mem_vec.size(), 0x08000000u);
                psprecomp::g_ge_exec_cursor = new_stall;
            }
        } else if (new_stall == 0u && cursor != 0u && s_upd <= 6u) {
            std::printf("[GE-UPDATESTALL] stall=0 (flush signal), cursor=0x%08X\n", cursor);
        }
        ctx.gpr[2] = 0u;
        ctx.pc     = ctx.gpr[31];
    }, "recomp_unit_gelistupdatestall");

    // ---- sceUtilitySavedata HLE -----------------------------------------------
    // D012 calls sceUtilitySavedata* for the AUTOSAVE/AUTOLOAD check at startup.
    // We return "no save found" for AUTOLOAD so the game proceeds to title screen.
    // SceUtilitySavedataParam offsets (PPSSPP-compatible):
    //   +0x1c result, +0x30 mode, +0x3c gameName[13], +0x4c saveName[20]
    //   +0x64 fileName[13], +0x74 dataBuf, +0x78 dataBufSize, +0x7c dataSize
    // Mode values: AUTOLOAD=0, AUTOSAVE=1, LOAD=2, SAVE=3
    // GetStatus return: 2=running, 3=done
    // sceUtilitySavedataInitStart(SceUtilitySavedataParam*) -> 0
    auto sd_init_fn = [](psprecomp::Runtime &rt2, psprecomp::AllegrexContext &ctx) {
        s_sdp_addr = ctx.gpr[4];
        s_sd_state = 1;
        const std::uint32_t mode = (s_sdp_addr && rt2.memory().contains(s_sdp_addr + 0x30u, 4u))
            ? rt2.memory().load32(s_sdp_addr + 0x30u) : 0xFFu;
        std::printf("[SAVEDATA] InitStart sdp=0x%08X mode=%u\n", s_sdp_addr, mode);
        std::fflush(stdout);
        // For AUTOSAVE (1): write result=0 (success) — game doesn't need a read-back
        // For AUTOLOAD (0): write result=ERR_LOAD_NOT_FOUND (0x80110309) — no save exists
        if (rt2.memory().contains(s_sdp_addr + 0x1cu, 4u)) {
            const std::uint32_t result = (mode == 0u || mode == 2u || mode == 4u)
                ? 0x80110309u  // AUTOLOAD/LOAD: not found
                : 0u;           // AUTOSAVE/SAVE: success
            rt2.memory().store32(s_sdp_addr + 0x1cu, result);
        }
        ctx.gpr[2] = 0u;
        ctx.pc     = ctx.gpr[31];
    };
    // sceUtilitySavedataGetStatus() -> 3 (complete/done)
    auto sd_getstatus_fn = [](psprecomp::Runtime &, psprecomp::AllegrexContext &ctx) {
        const int st = s_sd_state;
        if (st == 1) s_sd_state = 2;  // advance: running -> complete
        ctx.gpr[2] = (st >= 1) ? 3u : 0u;  // 3=PSP_UTILITY_DIALOG_NONE (done)
        ctx.pc     = ctx.gpr[31];
    };
    // sceUtilitySavedataShutdownStart() -> 0
    auto sd_shutdown_fn = [](psprecomp::Runtime &, psprecomp::AllegrexContext &ctx) {
        std::printf("[SAVEDATA] ShutdownStart\n"); std::fflush(stdout);
        s_sd_state = 0;
        ctx.gpr[2] = 0u;
        ctx.pc     = ctx.gpr[31];
    };
    // Register at all observed VAs in the generated stub table
    // 0x089C5A08 = sceUtilitySavedataInitStart (called from unit_0008 L_089055C0)
    // 0x089C5A18 = sceUtilitySavedataGetStatus  (called from unit_0007)
    // 0x089C5A28 = sceUtilitySavedataShutdownStart (called from unit_0008)
    // The other slots in the 0x089C5Axx range are covered by nop stubs in unit_0014.
    rt.register_function(0x089C5A08u, sd_init_fn,     "sceUtilitySavedataInitStart");
    rt.register_function(0x089C5A10u, sd_getstatus_fn,"sceUtilitySavedataGetStatus");
    rt.register_function(0x089C5A18u, sd_getstatus_fn,"sceUtilitySavedataGetStatus2");
    rt.register_function(0x089C5A20u, sd_shutdown_fn, "sceUtilitySavedataShutdownStart");
    rt.register_function(0x089C5A28u, sd_init_fn,     "sceUtilitySavedataInitStart2");
    rt.register_function(0x089C5A30u, sd_getstatus_fn,"sceUtilitySavedataGetStatus3");
    rt.register_function(0x089C5A38u, sd_shutdown_fn, "sceUtilitySavedataShutdownStart2");
    rt.register_function(0x089C5A40u, sd_getstatus_fn,"sceUtilitySavedataGetStatus4");

    // sceKernelCpuSuspendIntr() -> saved state (just return 0)
    rt.register_function(0x089C5EC8u, [](psprecomp::Runtime &, psprecomp::AllegrexContext &ctx) {
        ctx.gpr[2] = 0u;
        ctx.pc     = ctx.gpr[31];
    }, "recomp_unit_cpususpendintr");

    // sceKernelCpuResumeIntr(state) -> void
    rt.register_function(0x089C5EE8u, [](psprecomp::Runtime &, psprecomp::AllegrexContext &ctx) {
        ctx.gpr[2] = 0u;
        ctx.pc     = ctx.gpr[31];
    }, "recomp_unit_cpuresumeintr");


    // 0x08C10DA0 is a GE object in BSS; the task scheduler writes a function
    // pointer into it. Trap it so we can see what's calling and what it expects.
    rt.register_function(0x08C10DA0u, [](psprecomp::Runtime &rt2, psprecomp::AllegrexContext &ctx) {
        static int count = 0;
        if (count++ < 3) {
            std::printf("[DBG] CALLED 0x08C10DA0 ra=0x%08X a0=0x%08X task[0]=0x%08X\n",
                        ctx.gpr[31], ctx.gpr[4],
                        (ctx.gpr[4] >= 0x08800000u && ctx.gpr[4] < 0x0A000000u)
                            ? rt2.memory().load32(ctx.gpr[4]) : 0u);
        }
        ctx.gpr[2] = 0u;
        ctx.pc     = ctx.gpr[31];
    }, "hle_unit14");

    // sceKernelGetSystemTimeLow, sceDisplayWaitVblankStartCB implemented
    // directly in generated_unit_0014.cpp labels to keep unit 14 AOT-chainable.

    // ---- sceGu HLE stubs -------------------------------------------------------
    // sceGu write-pointer: maintained as file-scope statics to avoid lambda capture issues.
    // sceGuStart sets the base; drawing fns append GE command words.

    // sceGuStart(int type, void *list)  [0x089C5780]
    rt.register_function(0x089C5780u, [](psprecomp::Runtime &, psprecomp::AllegrexContext &ctx) {
        const std::uint32_t list_va = ctx.gpr[5] & 0x1FFFFFFFu;
        s_gu_base = list_va;
        s_gu_wp   = list_va;
        static std::uint32_t s_n = 0u;
        if (++s_n <= 3u) std::printf("[sceGuStart] type=%u list=0x%08X\n", ctx.gpr[4], list_va);
        ctx.gpr[2] = 0u;
        ctx.pc     = ctx.gpr[31];
    }, "hle_unit14");

    // sceGuFinish()  [0x089C5770, 0x089C5778]
    // Writes END command and directly executes the accumulated GE list.
    auto gu_finish_fn = [](psprecomp::Runtime &rt2, psprecomp::AllegrexContext &ctx) {
        static std::uint32_t s_n = 0u;
        if (++s_n <= 3u) std::printf("[sceGuFinish] wp=0x%08X base=0x%08X\n", s_gu_wp, s_gu_base);
        if (s_gu_wp != 0u && rt2.memory().contains(s_gu_wp, 4u))
            rt2.memory().store32(s_gu_wp, 0x0F000000u); // END
        const std::uint32_t list_phys  = s_gu_base  & 0x1FFFFFFFu;
        const std::uint32_t stall_phys = (s_gu_wp + 4u) & 0x1FFFFFFFu;
        if (list_phys != 0u && stall_phys > list_phys &&
            rt2.memory().contains(list_phys, 4u) && rt2.memory().contains(stall_phys - 4u, 4u)) {
            const auto *dl_ptr = reinterpret_cast<const std::uint32_t *>(
                rt2.memory().raw_pointer(list_phys, 4u));
            const auto *dl_end = reinterpret_cast<const std::uint32_t *>(
                rt2.memory().raw_pointer(stall_phys, 4u));
            void *vram_ptr = rt2.memory().raw_pointer(0x04000000u, 0x200000u);
            const auto &mem_vec = rt2.memory().bytes();
            if (vram_ptr && dl_ptr && dl_end)
                d012::ge_exec(dl_ptr, dl_end, vram_ptr, 0x200000u,
                              mem_vec.data(), mem_vec.size(), 0x04000000u);
        }
        ctx.gpr[2] = 0u;
        ctx.pc     = ctx.gpr[31];
    };
    rt.register_function(0x089C5770u, gu_finish_fn, "hle_unit14");
    rt.register_function(0x089C5778u, gu_finish_fn, "hle_unit14");

    // sceGuClear(flags)  [0x089C5630]
    rt.register_function(0x089C5630u, [](psprecomp::Runtime &rt2, psprecomp::AllegrexContext &ctx) {
        static std::uint32_t s_n = 0u;
        if (++s_n <= 3u) std::printf("[sceGuClear] flags=0x%08X wp=0x%08X\n", ctx.gpr[4], s_gu_wp);
        gu_emit(rt2, 0xD2000001u); // CLEARMODE on
        gu_emit(rt2, 0x04000000u); // PRIM NOP (count=0)
        gu_emit(rt2, 0xD2000000u); // CLEARMODE off
        ctx.gpr[2] = 0u;
        ctx.pc     = ctx.gpr[31];
    }, "hle_unit14");

    // sceGuClearColor(color)  [0x089C5650]
    rt.register_function(0x089C5650u, [](psprecomp::Runtime &rt2, psprecomp::AllegrexContext &ctx) {
        static std::uint32_t s_n = 0u;
        if (++s_n <= 3u) std::printf("[sceGuClearColor] color=0x%08X\n", ctx.gpr[4]);
        gu_emit(rt2, 0x02000000u | (ctx.gpr[4] & 0xFFFFFFu));
        gu_emit(rt2, 0x03000000u | ((ctx.gpr[4] >> 24) & 0xFFu));
        ctx.gpr[2] = 0u;
        ctx.pc     = ctx.gpr[31];
    }, "hle_unit14");

    // sceGuClearDepth(depth)  [0x089C5688]
    rt.register_function(0x089C5688u, [](psprecomp::Runtime &rt2, psprecomp::AllegrexContext &ctx) {
        static std::uint32_t s_n = 0u;
        if (++s_n <= 3u) std::printf("[sceGuClearDepth] depth=0x%04X\n", ctx.gpr[4]);
        gu_emit(rt2, 0x55000000u | (ctx.gpr[4] & 0xFFFFu));
        ctx.gpr[2] = 0u;
        ctx.pc     = ctx.gpr[31];
    }, "hle_unit14");

    // sceGuDrawArray(prim, vtype, count, indices, vertices)  [0x089C56C0]
    // a0=prim, a1=vtype, a2=count, a3=indices_ptr, [sp+16]=vertices_ptr
    rt.register_function(0x089C56C0u, [](psprecomp::Runtime &rt2, psprecomp::AllegrexContext &ctx) {
        const std::uint32_t prim  = ctx.gpr[4];
        const std::uint32_t vtype = ctx.gpr[5];
        const std::uint32_t count = ctx.gpr[6];
        const std::uint32_t iptr  = ctx.gpr[7];
        const std::uint32_t vptr  = rt2.memory().load32(ctx.gpr[29] + 16u);
        static std::uint32_t s_n = 0u;
        if (++s_n <= 6u) std::printf("[sceGuDrawArray] prim=%u vtype=0x%X count=%u iptr=0x%08X vptr=0x%08X\n",
                                      prim, vtype, count, iptr, vptr);
        const std::uint32_t vphys = vptr & 0x1FFFFFFFu;
        const std::uint32_t iphys = iptr & 0x1FFFFFFFu;
        gu_emit(rt2, 0xA0000000u | (vtype & 0xFFFFFFu)); // VTYPE
        gu_emit(rt2, 0x10000000u | ((vphys >> 8) & 0xFF0000u)); // BASE
        if (iphys != 0u)
            gu_emit(rt2, 0x09000000u | (iphys & 0xFFFFFFu)); // IADDR
        gu_emit(rt2, 0x01000000u | (vphys & 0xFFFFFFu)); // VADDR
        gu_emit(rt2, 0x04000000u | ((prim & 0x7u) << 16) | (count & 0xFFFFu)); // PRIM
        ctx.gpr[2] = 0u;
        ctx.pc     = ctx.gpr[31];
    }, "hle_unit14");

    // Unknown sceGu stubs — log and NOP-return  [0x089C56E0, 5700, 5718, 5730]
    auto gu_nop_fn = [](psprecomp::Runtime &, psprecomp::AllegrexContext &ctx) {
        static std::uint32_t s_n = 0u;
        if (++s_n <= 8u) std::printf("[sceGu-unk] va=0x%08X a0=0x%08X a1=0x%08X a2=0x%08X a3=0x%08X\n",
                                      ctx.pc, ctx.gpr[4], ctx.gpr[5], ctx.gpr[6], ctx.gpr[7]);
        ctx.gpr[2] = 0u;
        ctx.pc     = ctx.gpr[31];
    };
    rt.register_function(0x089C56E0u, gu_nop_fn, "hle_unit14");
    rt.register_function(0x089C5700u, gu_nop_fn, "hle_unit14");
    rt.register_function(0x089C5718u, gu_nop_fn, "hle_unit14");
    rt.register_function(0x089C5730u, gu_nop_fn, "hle_unit14");

    // Stub uncompiled functions in the 0x089DDxxx gap (called from FUN_0887801C init chain)
    // 089DD4D0: one-time struct initializer for DAT_09ae7070 — stub returns 0, caller guards with flag
    rt.register_function(0x089DD4D0u, [](psprecomp::Runtime &, psprecomp::AllegrexContext &ctx) {
        static bool s_once = false;
        if (!s_once) { s_once = true;
            std::printf("[STUB] 089DD4D0 init struct a0=0x%08X ra=0x%08X\n", ctx.gpr[4], ctx.gpr[31]);
            std::fflush(stdout); }
        ctx.gpr[2] = 0u;
        ctx.pc = ctx.gpr[31];
    }, "hle_unit15");
    rt.register_function(0x089E0B0Cu, [](psprecomp::Runtime &, psprecomp::AllegrexContext &ctx) {
        static bool s_once = false;
        if (!s_once) { s_once = true;
            std::printf("[STUB] 089E0B0C init struct a0=0x%08X ra=0x%08X\n", ctx.gpr[4], ctx.gpr[31]);
            std::fflush(stdout); }
        ctx.gpr[2] = 0u;
        ctx.pc = ctx.gpr[31];
    }, "hle_unit15");

    // FUN_08992F6C: linked-list push. *param_1 = DAT_09af6780; DAT_09af6780 = param_1.
    // Compiled in unit_0012 but invoke_chained_call from unit_0015 can't cross units — provide HLE.
    rt.register_function(0x08992F6Cu, [](psprecomp::Runtime &rt2, psprecomp::AllegrexContext &ctx) {
        const std::uint32_t list_head_va = 0x09AF6780u;
        const std::uint32_t param1 = ctx.gpr[4];
        if (param1 && rt2.memory().contains(param1, 4u) && rt2.memory().contains(list_head_va, 4u)) {
            const std::uint32_t head = rt2.memory().load32(list_head_va);
            rt2.memory().store32(param1, head);
            rt2.memory().store32(list_head_va, param1);
        }
        ctx.gpr[2] = 0u;
        ctx.pc = ctx.gpr[31];
    }, "recomp_unit_0012_hle_init_08992F6C");

    // FUN_0883DFA8: INIT function — calls FUN_08882950, FUN_0883F014, FUN_08992F6C.
    // Cross-unit invoke_chained_call chain breaks; HLE does equivalent work directly.
    rt.register_function(0x0883DFA8u, [](psprecomp::Runtime &rt2, psprecomp::AllegrexContext &ctx) {
        static bool s_once = false;
        if (!s_once) { s_once = true; std::printf("[HLE] FUN_0883DFA8 init\n"); std::fflush(stdout); }
        // FUN_0883F014(DAT_09AFE820): sets fields at +0x5e4=100, +0x5e8=0, +0x5ec=0, +0x630=0
        const std::uint32_t p = 0x09AFE820u;
        if (rt2.memory().contains(p + 0x5e4u, 4u)) {
            rt2.memory().store32(p + 0x5e4u, 100u);
            rt2.memory().store32(p + 0x5e8u, 0u);
            rt2.memory().store32(p + 0x5ecu, 0u);
            rt2.memory().store32(p + 0x630u, 0u);
        }
        // FUN_08992F6C(&DAT_089D4948): linked-list push
        const std::uint32_t list_head_va = 0x09AF6780u;
        const std::uint32_t param1 = 0x089D4948u;
        if (rt2.memory().contains(param1, 4u) && rt2.memory().contains(list_head_va, 4u)) {
            const std::uint32_t head = rt2.memory().load32(list_head_va);
            rt2.memory().store32(param1, head);
            rt2.memory().store32(list_head_va, param1);
        }
        ctx.gpr[2] = 0u;
        ctx.pc = ctx.gpr[31];
    }, "recomp_unit_0002_hle_init_0883DFA8");

    // FUN_08874508: init — calls FUN_08993560, sets floats in 09b48xxx, calls FUN_08992F6C
    rt.register_function(0x08874508u, [](psprecomp::Runtime &rt2, psprecomp::AllegrexContext &ctx) {
        static bool s_once = false;
        if (!s_once) { s_once = true; std::printf("[HLE] FUN_08874508 init\n"); std::fflush(stdout); }
        const std::uint32_t base = 0x09B48210u;
        const float f_max = 255.9375f; // 0x437f0000
        std::uint32_t fmax_bits = 0x437f0000u;
        auto st = [&](std::uint32_t off, std::uint32_t v) { if (rt2.memory().contains(base+off,4u)) rt2.memory().store32(base+off,v); };
        st(0u,0u); st(4u,0u); st(8u,0u); st(12u,0u); st(16u,0u); st(20u,0u); st(24u,0u);
        st(28u,fmax_bits); st(32u,fmax_bits); st(36u,fmax_bits); st(40u,fmax_bits);
        st(44u,0u); st(48u,fmax_bits); st(52u,fmax_bits); st(56u,fmax_bits); st(60u,fmax_bits);
        // FUN_08992F6C(&DAT_089D6018)
        const std::uint32_t lh = 0x09AF6780u, p1 = 0x089D6018u;
        if (rt2.memory().contains(p1,4u)&&rt2.memory().contains(lh,4u)) { rt2.memory().store32(p1, rt2.memory().load32(lh)); rt2.memory().store32(lh,p1); }
        ctx.gpr[2] = 0u; ctx.pc = ctx.gpr[31];
    }, "recomp_unit_0003");

    // FUN_0888E65C: init — calls FUN_088698FC, calls FUN_08992F6C
    rt.register_function(0x0888E65Cu, [](psprecomp::Runtime &rt2, psprecomp::AllegrexContext &ctx) {
        static bool s_once = false;
        if (!s_once) { s_once = true; std::printf("[HLE] FUN_0888E65C init\n"); std::fflush(stdout); }
        // FUN_08992F6C(&DAT_089D6A98)
        const std::uint32_t lh = 0x09AF6780u, p1 = 0x089D6A98u;
        if (rt2.memory().contains(p1,4u)&&rt2.memory().contains(lh,4u)) { rt2.memory().store32(p1, rt2.memory().load32(lh)); rt2.memory().store32(lh,p1); }
        ctx.gpr[2] = 0u; ctx.pc = ctx.gpr[31];
    }, "recomp_unit_0004");

    // FUN_0887801C: subsystem registry — inits 40+ subsystems and stores their pointers.
    // All constructors (func_0x089DDxxx, func_0x08ACxxxx etc) are uncompiled gaps.
    // HLE: skip all constructors, just write the pointer assignments the game reads later.
    rt.register_function(0x0887801Cu, [](psprecomp::Runtime &rt2, psprecomp::AllegrexContext &ctx) {
        static bool s_once = false;
        if (!s_once) { s_once = true; std::printf("[HLE] FUN_0887801C subsystem registry\n"); std::fflush(stdout); }
        auto store = [&](std::uint32_t dst, std::uint32_t src) {
            if (rt2.memory().contains(dst, 4u)) rt2.memory().store32(dst, src);
        };
        // All _DAT_xxx = &DAT_yyy pointer assignments from FUN_0887801C pseudocode:
        store(0x089E09C0u, 0x09AE7070u); store(0x089E75C4u, 0x09AE6F00u);
        store(0x08AC7500u, 0x09AE6DA0u); store(0x08B01CF8u, 0x09AE6C40u);
        store(0x08B243C0u, 0x09AE6AF0u); store(0x08AC4560u, 0x09AE6990u);
        store(0x08B22E98u, 0x09AE6840u); store(0x08B1CB00u, 0x09AE66F0u);
        store(0x08ABB9E4u, 0x09AE65A0u); store(0x08B25044u, 0x09AE6450u);
        store(0x08B29CF8u, 0x09AE62F0u); store(0x08B32D90u, 0x09AE61A0u);
        store(0x08A457ECu, 0x09AE6030u); store(0x08A457F0u, 0x09AE5EE0u);
        store(0x08A35A00u, 0x09AE5E84u); store(0x08A0B6A0u, 0x09AE5D30u);
        store(0x089E75C8u, 0x09AE5BE0u); store(0x08A23FF0u, 0x09AE5A50u);
        store(0x089E9D38u, 0x09AE58A0u); store(0x08A4C0FCu, 0x09AE5740u);
        store(0x08A4FFF4u, 0x09AE56D4u); store(0x08A51CBCu, 0x09AE5674u);
        store(0x08AA3F44u, 0x09AE4680u); store(0x08A6D710u, 0x09AE43F0u);
        store(0x08A6D7E0u, 0x09AE43E4u); store(0x08A8B7A8u, 0x09AE40D0u);
        store(0x08A87EACu, 0x09AE3F70u); store(0x08B54058u, 0x09AE3E10u);
        store(0x08A96A28u, 0x09AE3E04u); store(0x08B41CC0u, 0x09AE3D2Cu);
        store(0x08B42088u, 0x09AE3CECu); store(0x08B42C28u, 0x09AE3CE0u);
        store(0x08B42288u, 0x09AE3CD4u); store(0x08B44F08u, 0x09AE3CBCu);
        store(0x08B45878u, 0x09AE3CB0u); store(0x08B438C0u, 0x09AE3CA4u);
        store(0x08B426B0u, 0x09AE3C90u); store(0x08B42A98u, 0x09AE3C84u);
        store(0x08B54C38u, 0x09AE3B20u); store(0x08B59230u, 0x09AE3B0Cu);
        // Non-underscore DAT_ assignments:
        store(0x089D7F20u, 0x09AE6EECu); store(0x089D7F10u, 0x09AE6EE4u);
        ctx.gpr[2] = 0u;
        ctx.pc = ctx.gpr[31];
    }, "recomp_unit_0003");

    // FUN_08890780: init — clears 3 words at DAT_09b491f8, then FUN_08992F6C(&DAT_089d6ab0)
    rt.register_function(0x08890780u, [](psprecomp::Runtime &rt2, psprecomp::AllegrexContext &ctx) {
        const std::uint32_t p = 0x09B491F8u;
        if (rt2.memory().contains(p, 16u)) {
            rt2.memory().store32(p + 0u, 0u);
            rt2.memory().store32(p + 4u, 0u);
            rt2.memory().store32(p + 12u, 0u);
        }
        const std::uint32_t lh = 0x09AF6780u, p1 = 0x089D6AB0u;
        if (rt2.memory().contains(p1, 4u) && rt2.memory().contains(lh, 4u)) {
            rt2.memory().store32(p1, rt2.memory().load32(lh));
            rt2.memory().store32(lh, p1);
        }
        ctx.gpr[2] = 0u; ctx.pc = ctx.gpr[31];
    }, "recomp_unit_0004");

    // FUN_088A4168: init — FUN_08993560 (allocates array at DAT_09b4d3b0), then FUN_08992F6C(&DAT_089d6d3c)
    // FUN_08993560 / FUN_08993300: array allocator — stub as no-op (array at 09b4d3b0 stays zeroed)
    rt.register_function(0x088A4168u, [](psprecomp::Runtime &rt2, psprecomp::AllegrexContext &ctx) {
        const std::uint32_t lh = 0x09AF6780u, p1 = 0x089D6D3Cu;
        if (rt2.memory().contains(p1, 4u) && rt2.memory().contains(lh, 4u)) {
            rt2.memory().store32(p1, rt2.memory().load32(lh));
            rt2.memory().store32(lh, p1);
        }
        ctx.gpr[2] = 0u; ctx.pc = ctx.gpr[31];
    }, "recomp_unit_0005");

    // 0x08BA77D0 is stored in the pre-init global table as a data object pointer.
    // The game (or PortableKit's module HLE) reads it back and calls it as a function.
    // Units 27-31 are not recompiled, so the interpreter would run into data.
    // Register it as a no-op so any call to it returns immediately.
    // L_0886453C: the game's internal sceIoOpen wrapper — stub it so fd is always
    // returned correctly regardless of UMD-readiness state or chain depth.
    // L_0886453C: the game's sceIoOpen wrapper.
    // Calling convention: a0=handle/struct, a1=path ptr, a2=mode byte (0=retry, 1=no-retry).
    // The generated code extracts a1 as the path and calls sceIoOpen(a1, flags).
    // L_0886453C: the game's sceIoOpen wrapper.
    // a0=handle, a1=path ptr, a2=mode byte (1=O_RDONLY, other=0x40000001).
    rt.register_function(0x0886453Cu, [](psprecomp::Runtime &rt2, psprecomp::AllegrexContext &ctx) {
        const std::string path = rt2.memory().read_c_string(ctx.gpr[5]); // a1 = path string
        const std::uint32_t mode = ctx.gpr[6] & 0xFFu;                   // a2 low byte
        const std::uint32_t flags = (mode == 1u) ? 1u : 0x40000001u;    // O_RDONLY or create
        const std::uint32_t fd = d012::io_open(path, flags);
        std::printf("[HLE-OPEN] path='%s' flags=0x%X -> fd=%u\n", path.c_str(), flags, fd);
        std::fflush(stdout);
        ctx.gpr[2] = fd;
        ctx.pc = ctx.gpr[31];
    }, "hle_FUN_0886453C_open");

    rt.register_function(0x08BA77D0u, [](psprecomp::Runtime &rt2, psprecomp::AllegrexContext &ctx) {
        static unsigned s_n = 0;
        if (s_n++ < 4) { std::printf("[HLE-STUB] 0x08BA77D0 called ra=0x%08X -> nop\n", ctx.gpr[31]); std::fflush(stdout); }
        ctx.gpr[2] = 0u;
        // Avoid self-loop: if ra points back here, treat as thread exit
        if (ctx.gpr[31] == 0x08BA77D0u || ctx.gpr[31] == 0u) {
            rt2.stop("thread exited normally");
            return;
        }
        ctx.pc = ctx.gpr[31];
    }, "hle_stub_08BA77D0");
    std::printf("[REGISTER] 0x08BA77D0 stub registered, has_fn=%d\n", (int)rt.has_function(0x08BA77D0u));
    std::fflush(stdout);
}

static std::uint32_t s_last_addr = 0u;
static std::uint32_t s_last_uid  = 0u;

std::uint32_t hle_alloc(std::uint32_t size) {
    const std::uint32_t addr = (s_heap_next + 63u) & ~63u;
    if (addr + size > kHeapEnd) return 0u;
    const std::uint32_t uid = s_next_uid++;
    s_mem_blocks[uid] = {addr, size};
    s_alloc_size = size;
    s_last_addr  = addr;
    s_last_uid   = uid;
    s_heap_next  = addr + size;
    std::printf("[HLE] AllocPartitionMemory size=0x%X -> uid=%u addr=0x%08X\n", size, uid, addr);
    return uid;
}

std::uint32_t hle_alloc_size() { return s_alloc_size; }
std::uint32_t hle_last_addr()  { return s_last_addr; }
std::uint32_t hle_get_addr(std::uint32_t uid) {
    auto it = s_mem_blocks.find(uid);
    return (it != s_mem_blocks.end()) ? it->second.addr : 0u;
}

bool hle_has_pending_threads() { return !s_thread_queue.empty(); }

std::uint32_t hle_create_callback(std::uint32_t func) {
    const std::uint32_t uid = s_next_cb_uid++;
    s_callbacks[uid] = func;
    std::printf("[HLE] sceKernelCreateCallback func=0x%08X -> uid=%u\n", func, uid);
    return uid;
}
void hle_delete_callback(std::uint32_t uid) { s_callbacks.erase(uid); }

std::uint32_t hle_create_sema(std::uint32_t init_val) {
    const std::uint32_t uid = s_next_sema_uid++;
    s_semas[uid] = static_cast<std::int32_t>(init_val);
    std::printf("[HLE] sceKernelCreateSema initVal=%u -> uid=%u\n", init_val, uid);
    return uid;
}
void hle_delete_sema(std::uint32_t uid) { s_semas.erase(uid); }
void hle_signal_sema(std::uint32_t uid, std::uint32_t signal) {
    auto it = s_semas.find(uid);
    if (it != s_semas.end()) it->second += static_cast<std::int32_t>(signal);
}

std::uint32_t hle_create_thread(std::uint32_t entry, std::uint32_t priority, std::uint32_t stack_size) {
    // Delegate to PortableKit's kernel so it owns the thread lifecycle.
    const std::uint32_t gp = s_runtime_ptr ? s_runtime_ptr->cpu().gpr[28] : 0u;
    const std::int32_t uid = portablekit::kernel().create_thread("d012_thread", entry, priority, stack_size, 0u, gp);
    std::printf("[HLE] sceKernelCreateThread uid=%d entry=0x%08X priority=%u stack=0x%X\n",
                uid, entry, priority, stack_size);
    return static_cast<std::uint32_t>(uid);
}
void hle_start_thread(std::uint32_t uid, std::uint32_t arglen, std::uint32_t argp) {
    if (!s_runtime_ptr) { std::printf("[HLE] sceKernelStartThread: no runtime\n"); return; }
    auto &ctx = s_runtime_ptr->cpu();
    const std::int32_t result = portablekit::kernel().start_thread(ctx, static_cast<portablekit::SceUID>(uid), arglen, argp);
    ctx.gpr[2] = static_cast<std::uint32_t>(result);
    std::printf("[HLE] sceKernelStartThread uid=%u result=%d\n", uid, result);
}
std::uint32_t hle_create_event_flag() {
    static std::uint32_t s_next_evf = 0x300u;
    const std::uint32_t uid = s_next_evf++;
    std::printf("[HLE] sceKernelCreateEventFlag -> uid=%u\n", uid);
    return uid;
}

void hle_run_ctors(psprecomp::Runtime &rt, const psprecomp::Elf32Image &elf) {
    const auto &sections = elf.sections();
    for (const auto &sec : sections) {
        if (sec.name != ".ctors" && sec.name != ".init_array") continue;
        const std::uint32_t base = elf.section_runtime_address(sec);
        const std::uint32_t count = sec.size / 4u;
        std::printf("[HLE] Running %u ctors from %s at 0x%08X\n", count, sec.name.c_str(), base);
        for (std::uint32_t i = 0u; i < count; ++i) {
            const std::uint32_t fn = rt.memory().load32(base + i * 4u);
            if (fn == 0u || fn == 0xFFFFFFFFu) continue;
            std::printf("[HLE] ctor[%u] = 0x%08X\n", i, fn);
            auto &ctx = rt.cpu();
            ctx.gpr[29] = 0x09F00000u;
            ctx.gpr[31] = 0x00000001u;
            rt.run(fn, 100'000'000u);
        }
    }
}

void hle_run_next_thread(psprecomp::Runtime &rt) {
    if (s_thread_queue.empty()) return;
    ThreadDesc td = s_thread_queue.front();
    s_thread_queue.pop_front();
    std::printf("[HLE] Running queued thread entry=0x%08X uid=%u\n", td.entry, td.uid);

    auto &ctx = rt.cpu();
    ctx.gpr[4]  = td.arglen;
    ctx.gpr[5]  = td.argp;
    ctx.gpr[29] = 0x09EF0000u;
    ctx.gpr[26] = 0x09EE0000u;
    ctx.gpr[28] = 0x08B6B260u;
    ctx.gpr[31] = 0x00000001u;
    s_frame_thread_entry = td.entry;
    s_frame_thread_sp    = ctx.gpr[29];
    psprecomp::g_frame_reset_sp = ctx.gpr[29];
    std::printf("[HLE] Thread ctx before run: sp=0x%08X ra=0x%08X\n", ctx.gpr[29], ctx.gpr[31]);
    for (std::uint32_t a = 0x09EC0000u; a < 0x09EFF000u; a += 4u)
        rt.memory().store32(a, 0x00000001u);
    rt.run(td.entry, 2'000'000'000u);
    std::printf("[HLE] Thread uid=%u exited: %s\n", td.uid, rt.stop_reason().c_str());
}

// Cooperative round-robin scheduler — the real fix for multi-threaded PSP games.
// Called from main.cpp after the initial entry thread exits with threads queued.
// Allocates separate stacks per thread so context switches don't corrupt each other.
void hle_run_cooperative(psprecomp::Runtime &rt) {
    // Stack slots: render thread gets the standard slot; each extra thread gets its own
    // We allocate stacks downward from 0x09F00000 (top of RAM), 128KB each
    constexpr std::uint32_t kStackSize  = 0x20000u;  // 128 KB per thread
    constexpr std::uint32_t kStacksTop  = 0x09F00000u;
    const std::uint32_t slot_count = static_cast<std::uint32_t>(s_thread_queue.size()) + 1u;
    (void)slot_count;

    // Add all queued threads to s_live_threads
    std::uint32_t stack_idx = 0u;
    while (!s_thread_queue.empty()) {
        ThreadDesc td = s_thread_queue.front();
        s_thread_queue.pop_front();

        SavedThreadCtx stc;
        stc.uid       = td.uid;
        stc.alive     = true;
        stc.resume_pc = td.entry;
        // Assign a fresh stack for this thread (below render thread's stack)
        const std::uint32_t sp = kStacksTop - (stack_idx + 1u) * kStackSize;
        stc.ctx.gpr[4]  = td.arglen;
        stc.ctx.gpr[5]  = td.argp;
        stc.ctx.gpr[29] = sp;
        stc.ctx.gpr[26] = sp - kStackSize;
        stc.ctx.gpr[28] = 0x08B6B260u;
        stc.ctx.gpr[31] = 0x00000001u;
        // Zero-init the stack region
        for (std::uint32_t a = sp - kStackSize; a < sp; a += 4u)
            if (rt.memory().contains(a, 4u)) rt.memory().store32(a, 0u);
        std::printf("[COOP] queued thread uid=%u entry=0x%08X sp=0x%08X\n", td.uid, td.entry, sp);
        s_live_threads.push_back(stc);
        ++stack_idx;
    }

    if (s_live_threads.empty()) {
        std::printf("[COOP] no threads to run\n");
        return;
    }

    std::printf("[COOP] starting cooperative scheduler with %zu threads\n", s_live_threads.size());
    int idx = 0;
    int consecutive_dead = 0;

    while (true) {
        // Find next alive thread
        int found = -1;
        for (int i = 0; i < (int)s_live_threads.size(); ++i) {
            int j = (idx + i) % (int)s_live_threads.size();
            if (s_live_threads[j].alive) { found = j; break; }
        }
        if (found < 0) { std::printf("[COOP] all threads dead, done\n"); break; }
        idx = found;

        SavedThreadCtx &stc = s_live_threads[idx];
        s_current_thread_idx = idx;

        // Restore context and run
        rt.cpu() = stc.ctx;
        rt.cpu().pc = stc.resume_pc;
        const std::uint32_t run_pc = stc.resume_pc;
        static std::uint64_t s_slice = 0u;
        if ((++s_slice & 0xFFu) == 0u)
            std::printf("[COOP] thread[%d] uid=%u resume=0x%08X\n", idx, stc.uid, run_pc);

        rt.run(run_pc, 50'000'000u); // 50M dispatches per slice

        const std::string &reason = rt.stop_reason();
        // Save context
        stc.ctx       = rt.cpu();
        stc.resume_pc = rt.cpu().pc;

        if (reason == "yield") {
            // Thread yielded — context already saved, advance to next
            consecutive_dead = 0;
        } else if (reason == "window closed") {
            std::printf("[COOP] window closed, exiting\n");
            return;
        } else if (reason == "thread exited normally" || reason == "sceKernelTerminateThread") {
            std::printf("[COOP] thread[%d] uid=%u done: %s\n", idx, stc.uid, reason.c_str());
            stc.alive = false;
            ++consecutive_dead;
        } else {
            // Slice expired or unknown stop — resume from current PC
            consecutive_dead = 0;
        }

        // Check if any new threads were queued during execution
        while (!s_thread_queue.empty()) {
            ThreadDesc td = s_thread_queue.front();
            s_thread_queue.pop_front();
            SavedThreadCtx nstc;
            nstc.uid       = td.uid;
            nstc.alive     = true;
            nstc.resume_pc = td.entry;
            ++stack_idx;
            const std::uint32_t sp = kStacksTop - stack_idx * kStackSize;
            nstc.ctx.gpr[4]  = td.arglen;
            nstc.ctx.gpr[5]  = td.argp;
            nstc.ctx.gpr[29] = sp;
            nstc.ctx.gpr[26] = sp - kStackSize;
            nstc.ctx.gpr[28] = 0x08B6B260u;
            nstc.ctx.gpr[31] = 0x00000001u;
            std::printf("[COOP] new thread uid=%u entry=0x%08X sp=0x%08X\n", td.uid, td.entry, sp);
            s_live_threads.push_back(nstc);
        }

        // Advance to next thread
        idx = (idx + 1) % (int)s_live_threads.size();
    }
}

// ---- Public file I/O helpers (called from generated_unit_0014.cpp) ----

std::uint32_t io_open(const std::string &psp_path, std::uint32_t flags) {
    // Translate disc0:/PSP_GAME/USRDIR/... to a host path via the game root
    // (game root set in main.cpp; stored inside Runtime — we use a cached copy)
    std::string host_path;
    if (!g_game_root.empty()) {
        // strip "disc0:" prefix, replace with game root
        std::string rel = psp_path;
        const char *prefixes[] = { "disc0:", "ms0:", "host0:", nullptr };
        for (int i = 0; prefixes[i]; ++i) {
            const std::size_t plen = std::strlen(prefixes[i]);
            if (rel.compare(0, plen, prefixes[i]) == 0) { rel = rel.substr(plen); break; }
        }
        // strip leading slash
        if (!rel.empty() && (rel[0] == '/' || rel[0] == '\\')) rel = rel.substr(1);
        // The guest requests USRDIR-relative paths such as data/package_info.bin.
        // A decrypted PSP directory supplied as BOOT.bin stores these under
        // PSP_GAME/USRDIR, so resolve that guest-relative prefix accordingly.
        if (rel.size() >= 5 && (rel.compare(0, 5, "data/") == 0 || rel.compare(0, 5, "data\\") == 0))
            rel = "PSP_GAME/USRDIR/" + rel;
        host_path = g_game_root + "/" + rel;
    } else {
        host_path = psp_path;
    }
    // Embedded extracted assets are the production source.  Keep the guest's
    // PSP path semantics, but serve the bytes from the executable so no ISO or
    // extracted directory is required after the build.
    std::string guest_rel = psp_path;
    for (const char *prefix : {"disc0:", "ms0:", "host0:"}) {
        const std::size_t n = std::strlen(prefix);
        if (guest_rel.compare(0, n, prefix) == 0) { guest_rel.erase(0, n); break; }
    }
    while (!guest_rel.empty() && (guest_rel.front() == '/' || guest_rel.front() == '\\')) guest_rel.erase(0, 1);
    if (guest_rel.rfind("PSP_GAME/USRDIR/", 0) == 0) guest_rel.erase(0, 16);
    if (guest_rel.rfind("data/", 0) == 0) guest_rel.erase(0, 5);
    auto embedded = d012::embedded::find(guest_rel);
    const char *mode = (flags & 2u) ? ((flags & 0x200u) ? "w+b" : "wb") : "rb";
    // PACKAGE.BIN is the original monolithic container.  The native build
    // embeds the extracted assets actually consumed by startup, so opening
    // the unused container must not reintroduce an ISO/filesystem dependency.
    if (!embedded.data && guest_rel == "package.bin" && !(flags & 2u)) {
        const char *pkg_path = std::getenv("D012_PACKAGE_BIN");
        FILE *fp = pkg_path ? std::fopen(pkg_path, "rb") : nullptr;
        if (!fp) {
            std::printf("[IO-EMBEDDED] sceIoOpen: \"%s\" -> PACKAGE.BIN not found (set D012_PACKAGE_BIN)\n", psp_path.c_str());
            fp = std::tmpfile();
            if (!fp) return static_cast<std::uint32_t>(-2);
        }
        const std::uint32_t fd = s_next_fd++;
        s_fds[fd] = {fp, psp_path};
        std::printf("[IO-EMBEDDED] sceIoOpen: \"%s\" -> fd=%u serving PACKAGE.BIN\n", psp_path.c_str(), fd);
        return fd;
    }
    // Real ss descriptor from PACKAGE.BIN (84 bytes). byte[0]=0x06 dispatches
    // to a valid function table entry that initializes the scene state machine.
    // An empty stub caused byte[0]=0 -> invalid dispatch -> GE_shutdown.
    if (!embedded.data && guest_rel == "ss" && !(flags & 2u)) {
        static const unsigned char ss_data[] = {
            0x06,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x65,0x75,0x00,0x00,0x3d,0x00,0x00,0x00,
            0x00,0x00,0x00,0x00,0x55,0x4c,0x45,0x53,0x30,0x31,0x35,0x30,0x35,0x00,0x00,0x00,
            0x00,0x00,0x00,0x00,0x4e,0x50,0x45,0x48,0x30,0x30,0x31,0x30,0x38,0x00,0x00,0x00,
            0x00,0x00,0x00,0x00,0x55,0x4c,0x45,0x53,0x30,0x31,0x32,0x37,0x30,0x00,0x00,0x00,
            0x00,0x00,0x00,0x00,0x55,0x43,0x45,0x53,0x30,0x31,0x32,0x32,0x39,0x00,0x00,0x00,
            0x00,0x00,0x00,0x00
        };
        FILE *fp = std::tmpfile();
        if (!fp) return static_cast<std::uint32_t>(-2);
        std::fwrite(ss_data, 1, sizeof(ss_data), fp);
        std::rewind(fp);
        const std::uint32_t fd = s_next_fd++;
        s_fds[fd] = {fp, psp_path};
        std::printf("[IO-EMBEDDED] sceIoOpen: \"%s\" -> fd=%u real ss data (%zu bytes)\n", psp_path.c_str(), fd, sizeof(ss_data));
        return fd;
    }
    if (embedded.data && !(flags & 2u)) {
        FILE *fp = std::tmpfile();
        if (!fp) return static_cast<std::uint32_t>(-2);
        std::fwrite(embedded.data, 1, embedded.size, fp);
        std::rewind(fp);
        const std::uint32_t fd = s_next_fd++;
        s_fds[fd] = {fp, psp_path};
        std::printf("[IO-EMBEDDED] sceIoOpen: \"%s\" -> fd=%u bytes=%zu\n", psp_path.c_str(), fd, embedded.size);
        return fd;
    }
    FILE *fp = std::fopen(host_path.c_str(), mode);
    if (!fp) {
        static std::unordered_map<std::string, bool> s_warned;
        if (!s_warned[psp_path]) {
            s_warned[psp_path] = true;
            std::printf("[IO] sceIoOpen: \"%s\" -> NOT FOUND (host: %s)\n",
                        psp_path.c_str(), host_path.c_str());
        }
        return static_cast<std::uint32_t>(-2); // SCE_KERNEL_ERROR_NOFILE
    }
    const std::uint32_t fd = s_next_fd++;
    s_fds[fd] = {fp, psp_path};
    std::printf("[IO] sceIoOpen: \"%s\" -> fd=%u\n", psp_path.c_str(), fd);
    return fd;
}

std::int32_t io_read(std::uint32_t fd, void *buf, std::uint32_t size) {
    auto it = s_fds.find(fd);
    if (it == s_fds.end()) return -1;
    HostFd &hfd = it->second;
    std::int32_t count = 0;
    if (hfd.disc_iso) {
        const std::uint64_t avail = hfd.disc_size > hfd.disc_pos ? hfd.disc_size - hfd.disc_pos : 0u;
        const std::size_t want = static_cast<std::size_t>(std::min<std::uint64_t>(size, avail));
        if (want > 0u) {
            count = static_cast<std::int32_t>(hfd.disc_iso->read(
                hfd.disc_offset + hfd.disc_pos, std::span<std::uint8_t>(static_cast<std::uint8_t*>(buf), want)));
            hfd.disc_pos += count;
        }
    } else {
        count = static_cast<std::int32_t>(std::fread(buf, 1, size, hfd.fp));
    }
    std::printf("[IO-READ] fd=%u requested=%u read=%d path=%s\n", fd, size, count, hfd.path.c_str());
    std::fflush(stdout);
    return count;
}

std::int32_t io_close(std::uint32_t fd) {
    auto it = s_fds.find(fd);
    if (it != s_fds.end()) {
        if (it->second.fp) std::fclose(it->second.fp);
        s_fds.erase(it);
    }
    return 0;
}

std::int64_t io_lseek(std::uint32_t fd, std::int64_t offset, std::uint32_t whence) {
    auto it = s_fds.find(fd);
    if (it == s_fds.end()) return -1;
    HostFd &hfd = it->second;
    if (hfd.disc_iso) {
        std::int64_t new_pos = static_cast<std::int64_t>(hfd.disc_pos);
        if      (whence == SEEK_SET) new_pos = offset;
        else if (whence == SEEK_CUR) new_pos += offset;
        else if (whence == SEEK_END) new_pos = static_cast<std::int64_t>(hfd.disc_size) + offset;
        if (new_pos < 0) new_pos = 0;
        hfd.disc_pos = static_cast<std::uint64_t>(new_pos);
        return new_pos;
    }
    if (std::fseek(hfd.fp, static_cast<long>(offset), static_cast<int>(whence)) != 0)
        return -1;
    return static_cast<std::int64_t>(std::ftell(hfd.fp));
}

} // namespace d012

// Exposed for use by generated stubs that need synchronous file I/O
extern "C" const char* d012_get_game_root() {
    return d012::g_game_root.c_str();
}
