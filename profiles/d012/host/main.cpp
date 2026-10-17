#include "psprecomp/runtime.hpp"
#include "psprecomp/elf32.hpp"
#include "psprecomp/guest_memory.hpp"
#include "d012_profile.hpp"
#include "win32_display.hpp"
#include <cstdio>
#include <cstdlib>
#include <stdexcept>
#include <filesystem>
#include <fstream>
#include <vector>

namespace psprecomp {
void register_generated_functions(Runtime &runtime);
void register_ovl_menu_target_functions(Runtime &runtime);
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
    const char *eboot = argc > 1 ? argv[1] : "ULES01505_FFSTJP.BIN";
    std::printf("Loading: %s\n", eboot);
    try {
        psprecomp::Runtime runtime;
        auto elf = psprecomp::Elf32Image::from_file(eboot);
        std::printf("ELF loaded, type=%d\n", (int)elf.type());
        elf.load_and_relocate(runtime.memory());
        std::printf("ELF mapped to guest memory\n");
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
            runtime.set_game_root(dir);
            d012::g_game_root = dir.string();
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
        std::printf("HLE registered\n");
        d012::hle_run_ctors(runtime, elf);
        std::printf("Ctors done\n");
        const std::uint32_t entry     = elf.runtime_entry();
        const std::uint32_t run_entry = entry == 0 ? 0x08804040u : entry;
        std::printf("Entry: 0x%08X  Running from: 0x%08X\n", entry, run_entry);
        runtime.context().gpr[29] = 0x09F00000u;
        runtime.run(run_entry, 1'000'000'000u);
        std::printf("Exited: %s\n", runtime.stop_reason().c_str());
        while (d012::hle_has_pending_threads()) {
            d012::hle_run_next_thread(runtime);
        }
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
