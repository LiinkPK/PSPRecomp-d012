// Dissidia 012 [duodecim] Final Fantasy — PortableKit game profile.
// Defines portablekit::game() and the D012-specific patches needed on top of
// the framework's kernel/GE/display/audio HLE.

#include "profile.hpp"

#include "psprecomp/elf32.hpp"
#include "psprecomp/runtime.hpp"
#include "kernel/kernel.hpp"
#include "d012_profile.hpp"

#include <cstdint>
#include <cstdio>
#include <cstring>
#include <filesystem>
#include <fstream>
#include <vector>

namespace psprecomp {
void register_generated_functions(Runtime &runtime);
void register_ovl_menu_target_functions(Runtime &runtime);
void recomp_unit_0002(Runtime &runtime, AllegrexContext &ctx);
} // namespace psprecomp

namespace portablekit {
namespace {

// ---- overlay loader --------------------------------------------------------
static void load_overlay_from_bytes(psprecomp::Runtime &rt, const std::uint8_t *data, std::size_t size) {
    if (!data || size < 0x54) return;
    auto u32 = [&](std::size_t p) {
        return static_cast<std::uint32_t>(data[p]) | (static_cast<std::uint32_t>(data[p+1])<<8) |
               (static_cast<std::uint32_t>(data[p+2])<<16) | (static_cast<std::uint32_t>(data[p+3])<<24);
    };
    const std::uint32_t off = u32(0x38), va = u32(0x3c), img_size = u32(0x44);
    if (off > size || img_size > size - off || !rt.memory().contains(va, img_size)) return;
    for (std::uint32_t i = 0; i < img_size; i += 4)
        rt.memory().store32(va + i, u32(off + i));
    std::printf("[OVERLAY] menu overlay mapped at 0x%08X size=0x%X\n", va, img_size);
}

static void load_overlay_from_file(psprecomp::Runtime &rt, const std::filesystem::path &path) {
    std::ifstream in(path, std::ios::binary);
    if (!in) return;
    std::vector<std::uint8_t> b((std::istreambuf_iterator<char>(in)), {});
    load_overlay_from_bytes(rt, b.data(), b.size());
}

// ---- AOT registrations that must survive register_hle overrides ------------
static void register_aot_fixes(psprecomp::Runtime &rt) {
    rt.register_function(0x088644DCu, &psprecomp::recomp_unit_0002, "recomp_unit_0002");
    rt.register_function(0x0886450Cu, &psprecomp::recomp_unit_0002, "recomp_unit_0002");
    rt.register_function(0x0886452Cu, &psprecomp::recomp_unit_0002, "recomp_unit_0002");
}

// ---- thread control block setup --------------------------------------------
static void setup_thread_control_block(psprecomp::Runtime &rt) {
    constexpr std::uint32_t kStackTop   = 0x09F00000u;
    constexpr std::uint32_t kCBSize     = 0x200u;
    const std::uint32_t control_blk = kStackTop - kCBSize;
    for (std::uint32_t off = 0; off < kCBSize; off += 4u)
        rt.memory().store32(control_blk + off, 0u);
    rt.memory().store32(control_blk + 0xC0u, 1u);
    rt.memory().store32(control_blk + 0xC8u, 0x09E00000u);
    rt.memory().store32(control_blk + 0xF8u, 0xFFFFFFFFu);
    rt.memory().store32(control_blk + 0xFCu, 0xFFFFFFFFu);
    rt.cpu().gpr[26] = control_blk;  // $k0
    rt.cpu().gpr[29] = control_blk;  // $sp
    std::printf("[D012] thread control block at 0x%08X\n", control_blk);
}

// ---- extra HLE: D012-specific stubs PortableKit doesn't cover --------------
static void register_d012_extra_hle(HleRegistrar &) {
    // PortableKit's kernel, IO, GE, display, and memory HLE handle everything
    // Dissidia 012 needs. No additional NID-based overrides are required here.
    // Address-based stubs (jump table dispatch, etc.) go in patch_loaded_image.
}

// ---- patch_loaded_image: runs after ELF is in memory ----------------------
static void patch_d012_image(psprecomp::Runtime &rt, const psprecomp::Elf32Image &elf) {
    // Give d012_profile.cpp access to the runtime for PortableKit kernel calls.
    d012::set_runtime(rt);

    // Load generated AOT code
    psprecomp::register_generated_functions(rt);
    psprecomp::register_ovl_menu_target_functions(rt);

    // Restore AOT helpers that HLE registration may overwrite
    register_aot_fixes(rt);

    // Menu overlay: try embedded asset first, then file next to executable
    // (The embedded asset is compiled in via d012_embedded_assets_v2.cpp,
    //  but that requires the old d012_profile.cpp; skip for now and use file.)
    {
        const std::filesystem::path game_dir = portablekit::game().boot_path
            ? std::filesystem::path(portablekit::game().boot_path).parent_path()
            : std::filesystem::path{};
        if (!game_dir.empty())
            load_overlay_from_file(rt, game_dir / "OVL_MENU_APP.ELF");
    }

    // Thread control block ($k0) — PortableKit's kernel sets this up, but
    // D012 boots through the raw entry, so set it explicitly.
    setup_thread_control_block(rt);

    // The decrypted BOOT.bin has ELF entry=0; redirect to the real load base.
    rt.register_function(0x00000000u, [](psprecomp::Runtime &, psprecomp::AllegrexContext &ctx) {
        ctx.pc = portablekit::game().load_base;
    }, "d012_entry_redirect");

    // unit_0014 intercepts sceKernelCreateThread/StartThread inline and routes
    // them to d012::hle_create/start_thread, bypassing PortableKit's kernel.
    // Override those addresses so PortableKit's kernel handles them instead.
    rt.register_function(0x089C5FD0u, [](psprecomp::Runtime &, psprecomp::AllegrexContext &ctx) {
        // sceKernelCreateThread(name, entry, priority, stackSize, attr, opt)
        // gpr[4]=name ptr, gpr[5]=entry, gpr[6]=priority, gpr[7]=stackSize
        const std::int32_t uid = portablekit::kernel().create_thread(
            "d012_thread", ctx.gpr[5], ctx.gpr[6], ctx.gpr[7], 0u, ctx.gpr[28]);
        std::printf("[HLE] sceKernelCreateThread uid=%d entry=0x%08X\n", uid, ctx.gpr[5]);
        portablekit::kernel().finish(ctx, static_cast<std::uint32_t>(uid));
        ctx.pc = ctx.gpr[31];
    }, "d012_sceKernelCreateThread");

    rt.register_function(0x089C5FA0u, [](psprecomp::Runtime &, psprecomp::AllegrexContext &ctx) {
        // sceKernelStartThread(uid, arglen, argp)
        const std::int32_t result = portablekit::kernel().start_thread(
            ctx, static_cast<portablekit::SceUID>(ctx.gpr[4]), ctx.gpr[5], ctx.gpr[6]);
        std::printf("[HLE] sceKernelStartThread uid=%u result=%d\n", ctx.gpr[4], result);
        portablekit::kernel().finish(ctx, static_cast<std::uint32_t>(result));
        ctx.pc = ctx.gpr[31];
    }, "d012_sceKernelStartThread");

    // Task jump-table dispatch stub at 0x08844F84 — crashes if not intercepted.
    rt.register_function(0x08844F84u, [](psprecomp::Runtime &, psprecomp::AllegrexContext &ctx) {
        ctx.gpr[2] = 0u;
        ctx.pc = ctx.gpr[31];
    }, "d012_task_jt_dispatch_stub");

    (void)elf;
}

constexpr SaveFolder kSaveFolders[] = {
    {"ULES01505",     "Game data",    true},
    {"ULES01505INST", "Install data", false},
};

} // namespace

const GameProfile &game() {
    static const GameProfile profile{
        .app_name          = "d012_native",
        .project_name      = "Dissidia012",
        .env_prefix        = "D012",
        .data_organization = "Dissidia012",
        .data_application  = "D012",

        .disc_id              = "ULES01505",
        .disc_id_display      = "ULES-01505",
        .game_title           = "Dissidia 012 [duodecim] Final Fantasy",
        .executable_path_on_disc = "PSP_GAME/SYSDIR/EBOOT.BIN",
        .param_sfo_path_on_disc  = "PSP_GAME/PARAM.SFO",

        // We use a pre-decrypted embedded BOOT.bin.
        .encrypted_executable_sha256 = "",
        .executable_sha256           = "",
        .decryption_tag  = 0u,
        .decryption_key  = {},

        .load_base      = 0x08804040u,
        .guest_ram_bytes = 64u * 1024u * 1024u,
        .boot_path      = "disc0:/PSP_GAME/SYSDIR/EBOOT.BIN",
        .overlay_slots  = {},

        .save_game_name = "ULES01505",
        .save_folders   = kSaveFolders,
        .adhoc_product_code = "ULES01505",

        .register_extra_hle  = register_d012_extra_hle,
        .patch_loaded_image  = patch_d012_image,
    };
    return profile;
}

} // namespace portablekit
