#include "psprecomp/runtime.hpp"
#include "psprecomp/elf32.hpp"
#include "psprecomp/guest_memory.hpp"
#include "d012_profile.hpp"
#include "win32_display.hpp"
#include "d012_embedded_assets_v2.hpp"
#include <cstdio>
#include <cstdlib>
#include <stdexcept>
#include <filesystem>
#include <fstream>
#include <vector>

namespace psprecomp {
void register_generated_functions(Runtime &runtime);
void register_ovl_menu_target_functions(Runtime &runtime);
void recomp_unit_0002(Runtime &runtime, AllegrexContext &ctx);
}

static void load_menu_overlay_bytes(psprecomp::Runtime &rt, const unsigned char *data, std::size_t size) {
    if (!data || size < 0x54) return;
    std::vector<std::uint8_t> b(data, data + size);
    if (b.size() < 0x54) return;
    auto u32 = [&](std::size_t p) { return static_cast<std::uint32_t>(b[p]) | (static_cast<std::uint32_t>(b[p+1])<<8) | (static_cast<std::uint32_t>(b[p+2])<<16) | (static_cast<std::uint32_t>(b[p+3])<<24); };
    const auto off=u32(0x38), va=u32(0x3c), image_size=u32(0x44);
    if (off > b.size() || image_size > b.size()-off || !rt.memory().contains(va,image_size)) return;
    for (std::uint32_t i=0; i<image_size; i+=4) rt.memory().store32(va+i,u32(off+i));
    std::printf("[OVERLAY] embedded menu mapped at 0x%08X size=0x%X\n",va,image_size);
}

static void load_menu_overlay(psprecomp::Runtime &rt, const std::filesystem::path &path) {
    std::ifstream in(path, std::ios::binary);
    if (!in) return;
    std::vector<std::uint8_t> b((std::istreambuf_iterator<char>(in)), {});
    if (b.size() < 0x54) return;
    auto u32 = [&](std::size_t p) { return static_cast<std::uint32_t>(b[p]) | (static_cast<std::uint32_t>(b[p+1])<<8) | (static_cast<std::uint32_t>(b[p+2])<<16) | (static_cast<std::uint32_t>(b[p+3])<<24); };
    const auto off=u32(0x38), va=u32(0x3c), size=u32(0x44);
    if (off > b.size() || size > b.size()-off || !rt.memory().contains(va,size)) return;
    for (std::uint32_t i=0; i<size; i+=4) rt.memory().store32(va+i,u32(off+i));
    std::printf("[OVERLAY] menu mapped at 0x%08X size=0x%X\n",va,size);
}

int main(int argc, char *argv[]) {
    setvbuf(stdout, nullptr, _IONBF, 0);
    setvbuf(stderr, nullptr, _IONBF, 0);
    std::printf("D012 native starting\n");
    std::filesystem::path embedded_boot;
    std::string embedded_boot_string;
    const char *eboot = argc > 1 ? argv[1] : nullptr;
    if (!eboot) {
        embedded_boot = std::filesystem::temp_directory_path() / "d012_embedded_boot.bin";
        auto a = d012::embedded::find("BOOT.bin");
        std::ofstream out(embedded_boot, std::ios::binary | std::ios::trunc);
        out.write(reinterpret_cast<const char *>(a.data), static_cast<std::streamsize>(a.size));
        out.close();
        embedded_boot_string = embedded_boot.string();
        eboot = embedded_boot_string.c_str();
        std::printf("Loading embedded BOOT.bin\n");
    } else {
        std::printf("Loading: %s\n", eboot);
    }
    try {
        psprecomp::Runtime runtime;
        auto elf = psprecomp::Elf32Image::from_file(eboot);
        std::printf("ELF loaded, type=%d\n", (int)elf.type());
        elf.load_and_relocate(runtime.memory());
        std::printf("ELF mapped to guest memory\n");
        auto embedded_overlay = d012::embedded::find("OVL_MENU_APP.ELF");
        load_menu_overlay_bytes(runtime, embedded_overlay.data, embedded_overlay.size);
        if (!embedded_overlay.data)
            load_menu_overlay(runtime, std::filesystem::path(eboot).parent_path() / "OVL_MENU_APP.ELF");


        // Set game root to directory containing the BIN so file I/O can find assets
        {
            std::filesystem::path bin_path(eboot);
            auto dir = bin_path.parent_path();
            if (dir.empty()) dir = ".";
            // BOOT.bin may be supplied from the extracted-package parent while
            // the actual PSP_GAME tree is one directory below it.
            if (!std::filesystem::exists(dir / "PSP_GAME")) {
                for (const auto &entry : std::filesystem::directory_iterator(dir)) {
                    if (entry.is_directory() && std::filesystem::exists(entry.path() / "PSP_GAME")) {
                        dir = entry.path();
                        break;
                    }
                }
            }
            // A decrypted BOOT.bin is commonly kept in PSPRecomp/original,
            // while the extracted disc is kept separately.  Keep the guest's
            // I/O rooted at the actual extracted PSP tree when the executable
            // input directory is only the BIN staging area.
            // If the resolved dir still has no PSP_GAME, try the known extracted ISO location.
            static const std::filesystem::path kFallbackGameRoot =
                std::getenv("D012_GAME_ROOT") ? std::getenv("D012_GAME_ROOT") : "";
            if (!std::filesystem::exists(dir / "PSP_GAME") &&
                std::filesystem::exists(kFallbackGameRoot / "PSP_GAME")) {
                dir = kFallbackGameRoot;
                std::printf("[GAME-ROOT] using fallback: %s\n", dir.string().c_str());
            }
            runtime.set_game_root(dir);
            d012::g_game_root = dir.string();
            std::printf("[GAME-ROOT] set to: %s\n", d012::g_game_root.c_str());
        }

        // Scan for embedded syscall stubs BEFORE generated functions so
        // has_function() correctly skips anything already registered.
        d012::display_init(480, 272);

        d012::scan_and_register_stubs(runtime, elf);

        std::printf("Starting AOT registration...\n");
        fflush(stdout);
        psprecomp::register_generated_functions(runtime);
        psprecomp::register_ovl_menu_target_functions(runtime);
        std::printf("AOT functions registered\n");
        d012::register_hle(runtime);
        // HLE stub registration can overwrite callback addresses; restore the
        // real generated helper registrations after that phase.
        runtime.register_function(0x088644DCu, &psprecomp::recomp_unit_0002, "recomp_unit_0002");
        runtime.register_function(0x0886450Cu, &psprecomp::recomp_unit_0002, "recomp_unit_0002");
        runtime.register_function(0x0886452Cu, &psprecomp::recomp_unit_0002, "recomp_unit_0002");
        std::printf("HLE registered\n");
        d012::hle_run_ctors(runtime, elf);
        std::printf("Ctors done\n");
        const std::uint32_t entry     = elf.runtime_entry();
        const std::uint32_t run_entry = entry == 0 ? 0x08804040u : entry;
        std::printf("Entry: 0x%08X  Running from: 0x%08X\n", entry, run_entry);

        // Set up the PSP thread control block ($k0 / gpr[26]) at the top of the
        // initial stack, exactly as PortableKit's Kernel::prepare_thread_stack does.
        // Without this, $k0 = 0 and the game reads from 0x00000054-0x000000F8
        // (all GUEST-READ32-UNMAPPED → 0), corrupting MPK object construction.
        {
            constexpr std::uint32_t kStackTop   = 0x09F00000u;
            constexpr std::uint32_t kCBSize     = 0x200u;       // 512-byte control block
            const std::uint32_t     control_blk = kStackTop - kCBSize;
            // Zero the control block
            for (std::uint32_t off = 0; off < kCBSize; off += 4u)
                runtime.memory().store32(control_blk + off, 0u);
            // Write sentinel values matching Tenkawa (UID=1, stack_bottom, -1 sentinels)
            runtime.memory().store32(control_blk + 0xC0u, 1u);            // uid
            runtime.memory().store32(control_blk + 0xC8u, 0x09E00000u);   // stack_bottom
            runtime.memory().store32(control_blk + 0xF8u, 0x08800000u);
            runtime.memory().store32(control_blk + 0xFCu, 0x08800000u);
            runtime.context().gpr[26] = control_blk;  // $k0
            runtime.context().gpr[29] = control_blk;  // $sp just below control block
            std::printf("[MAIN] thread control block at 0x%08X, $k0=gpr[26]=0x%08X\n",
                        control_blk, control_blk);
        }
        // Bootstrap thread exits via sentinel; PortableKit has queued the game
        // thread (d012_thread) at 0x08804160. Run it directly.
        runtime.run(run_entry, 2'000'000'000u);
        std::printf("Exited: %s  pc=0x%08X\n", runtime.stop_reason().c_str(), runtime.cpu().pc);
        std::printf("[MAIN] launching game thread at 0x08804160\n");
        std::fflush(stdout);
        runtime.run(0x08804160u, 2'000'000'000u);
        std::printf("Game thread exited: %s  pc=0x%08X\n", runtime.stop_reason().c_str(), runtime.cpu().pc);
        std::printf("All threads done\n");
    } catch (const std::exception &e) {
        std::fprintf(stderr, "Exception: %s\n", e.what());
        return 1;
    } catch (...) {
        std::fprintf(stderr, "Unknown exception\n");
        return 1;
    }
    return 0;
}
