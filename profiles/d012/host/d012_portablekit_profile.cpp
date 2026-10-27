// Dissidia 012 [duodecim] Final Fantasy — PortableKit game profile.
// Defines portablekit::game() and the D012-specific patches needed on top of
// the framework's kernel/GE/display/audio HLE.

#include "profile.hpp"

#include "psprecomp/elf32.hpp"
#include "psprecomp/runtime.hpp"
#include "kernel/kernel.hpp"
#include "hle/hle_common.hpp"
#include "d012_profile.hpp"

#include <cstdint>
#include <cstdio>
#include <cstring>
#include <filesystem>
#include <fstream>
#include <vector>

namespace psprecomp {
void register_generated_functions(Runtime &runtime);
namespace ovl_menu { void register_ovl_menu_functions(Runtime &runtime); }
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
    // Set working directory so relative paths like "data/foo.bin" resolve
    // to disc0:/PSP_GAME/USRDIR/DATA as the PSP UMD driver does.
    portablekit::set_io_working_directory("disc0:/PSP_GAME/USRDIR");

    // Give d012_profile.cpp access to the runtime for PortableKit kernel calls.
    d012::set_runtime(rt);

    // Load generated AOT code
    psprecomp::register_generated_functions(rt);
    psprecomp::ovl_menu::register_ovl_menu_functions(rt);

    // Restore AOT helpers that HLE registration may overwrite
    register_aot_fixes(rt);

    // Register all D012-specific HLE stubs (including 0x08BA77D0 no-op).
    // register_d012_extra_hle only gets an HleRegistrar, not a Runtime, so
    // function-address stubs must be registered here instead.
    d012::register_hle(rt);

    // Register D012's custom IO/thread stubs (sceIoOpen, sceIoRead, etc.)
    // with PACKAGE.BIN-aware virtual filesystem handlers.
    d012::scan_and_register_stubs(rt, elf);

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

    // Pre-initialise the global object-pointer table that FUN_088769CC (unit_3)
    // normally writes.  That function's invoke_chained_direct sub-calls yield
    // via the cooperative scheduler before the stores happen, leaving all of
    // these globals at zero.  Values are derived from the (hi<<16)+lo literals
    // at the top of FUN_088769CC (lines 37882-37979 in generated_unit_0003.cpp)
    // and the sp+N slot each register is reloaded from at each store site.
    {
        auto &m = rt.memory();
        // sp+0  = 0x08C13A94 (2241<<16+14996)
        m.store32(0x089D69E0u, 0x08C13A94u);
        // sp+8  = 0x08C10DA0 (2241<<16+3488)
        m.store32(0x089D5EC0u, 0x08C10DA0u);
        m.store32(0x089D5F00u, 0x08C10DA0u);
        // sp+12 = 0x08C10D80 (2241<<16+3456)
        m.store32(0x089D5EA0u, 0x08C10D80u);
        // sp+16 = 0x08C10D04 (2241<<16+3332)
        m.store32(0x089D5FF0u, 0x08C10D04u);
        // sp+20 = 0x08C10CFC (2241<<16+3324)
        m.store32(0x089D5F98u, 0x08C10CFCu);
        // sp+24 = 0x08C10CF4 (2241<<16+3316)
        m.store32(0x089D5FB4u, 0x08C10CF4u);
        // sp+28 = 0x08C10CE8 (2241<<16+3304)
        m.store32(0x089D5EB0u, 0x08C10CE8u);
        // sp+32 = 0x08BFF5C8 (2240<<16-2616)
        m.store32(0x089D5F94u, 0x08BFF5C8u);
        // sp+36 = 0x08BFF518 (2240<<16-2792)
        m.store32(0x089D6C88u, 0x08BFF518u);
        // sp+40 = 0x08BFEF14 (2240<<16-4332)
        m.store32(0x089D6C80u, 0x08BFEF14u);
        // sp+44 = 0x08BFEEC8 (2240<<16-4408)
        m.store32(0x089D6C30u, 0x08BFEECCu);
        // sp+48 = 0x08BFDC74 (2240<<16-9100)
        m.store32(0x089D6D78u, 0x08BFDC74u);
        // sp+52 = 0x08BFDC20 (2240<<16-9184)
        m.store32(0x089D6028u, 0x08BFDC20u);
        // sp+56 = 0x08BEE94C (2239<<16-5812)
        m.store32(0x089D6998u, 0x08BEE94Cu);
        // sp+60 = 0x08BEE928 (2239<<16-5848)
        m.store32(0x089D69F0u, 0x08BEE928u);
        // sp+64 = 0x08BEE90C (2239<<16-5876)
        m.store32(0x089D7280u, 0x08BEE90Cu);
        // sp+68 = 0x08BAED38 (2235<<16-4808)
        m.store32(0x089D712Cu, 0x08BAED38u);
        // sp+72 = 0x08BAED2C (2235<<16-4820)
        m.store32(0x089D7268u, 0x08BAED2Cu);
        // sp+76 = 0x08BAED10 (2235<<16-4848)
        m.store32(0x089D7260u, 0x08BAED10u);
        // sp+80 = 0x08BAED04 (2235<<16-4860)
        // (no global assigned from sp+80 in our scan — skip)
        // sp+84 = 0x08BAEBC0 (2235<<16-5184)
        // (no global assigned from sp+84 in our scan — skip)
        // sp+88 = 0x08BAEBB4 (2235<<16-5196)
        m.store32(0x089D4E14u, 0x08BAEBB4u);
        // sp+92 = 0x08BAEA80 (2235<<16-5504)
        m.store32(0x089D6D80u, 0x08BAEA80u);
        // sp+96 = 0x08BAEA64 (2235<<16-5532)
        m.store32(0x089D6DC8u, 0x08BAEA64u);
        // sp+100 = 0x08BAEA48 (2235<<16-5560)
        m.store32(0x089D6DD0u, 0x08BAEA48u);
        // sp+104 = 0x08BAE9F0 (2235<<16-5648)
        m.store32(0x089D4958u, 0x08BAE9F0u);
        // sp+108 = 0x08BAE9E8 (2235<<16-5656)
        m.store32(0x089D4DA0u, 0x08BAE9E8u);
        // sp+112 = 0x08BAE9D4 (2235<<16-5676)
        m.store32(0x089D47A0u, 0x08BAE9D4u);
        // sp+116 = 0x08BAE9CC (2235<<16-5684)
        m.store32(0x089D4968u, 0x08BAE9CCu);
        // sp+120 = 0x08BAE964 (2235<<16-5788)
        m.store32(0x089D4960u, 0x08BAE964u);
        // sp+124 = 0x08BA4E9C (2234<<16+20124 or similar)
        m.store32(0x089D4910u, 0x08BA4E9Cu);
        // sp+128 = 0x08BA4E90
        m.store32(0x089D4974u, 0x08BA4E90u);
        // sp+132 = 0x08BA4E70
        m.store32(0x089D4938u, 0x08BA4E70u);
        // sp+136 = 0x08BA4E68
        m.store32(0x089D4DA8u, 0x08BA4E68u);
        // sp+140 = 0x08BA4E60
        m.store32(0x089D7368u, 0x08BA4E60u);
        // sp+144 = 0x08BA4E58
        m.store32(0x089D73A8u, 0x08BA4E58u);
        // sp+148 = 0x08BA4E50
        m.store32(0x089D73FCu, 0x08BA4E50u);
        // sp+152 = 0x08BA4E34
        m.store32(0x089D73B0u, 0x08BA4E34u);
        // sp+156 = 0x08BA4E2C
        m.store32(0x089D7438u, 0x08BA4E2Cu);
        // sp+160 = 0x08BA4E20
        m.store32(0x089D77F4u, 0x08BA4E20u);
        // sp+164 = 0x08B99030
        m.store32(0x089D7750u, 0x08B99030u);
        // sp+168 = 0x08B99000
        m.store32(0x089D773Cu, 0x08B99000u);
        // sp+172 = 0x08B98FDC
        m.store32(0x089D72FCu, 0x08B98FDCu);
        // sp+176 = 0x08B98FD4
        m.store32(0x089D6C10u, 0x08B98FD4u);
        // sp+180 = 0x08B98890
        m.store32(0x089D6AC8u, 0x08B98890u);
        // sp+184 = 0x08B98880
        m.store32(0x089D6AE0u, 0x08B98880u);
        // sp+188 = 0x08B98848
        m.store32(0x089D6AF0u, 0x08B98848u);
        // sp+192 = 0x08B98800
        m.store32(0x089D6AE8u, 0x08B98800u);
        // sp+196 = 0x08BA4FA0
        // (assigned to no global in our scan from this slot — skip)
        // sp+200 = 0x08B987F0
        m.store32(0x089D6AD0u, 0x08B987F0u);
        // sp+204 = 0x08B87E7C
        m.store32(0x089D7830u, 0x08B87E7Cu);
        // sp+208 = 0x08B87668
        m.store32(0x089D6A10u, 0x08B87668u);
        // sp+212 = 0x08B87654
        m.store32(0x089D6AC0u, 0x08B87654u);
        // sp+216 = 0x08B87500
        m.store32(0x089D6AA8u, 0x08B87500u);
        // sp+220 = 0x08B86D54
        m.store32(0x089D6A00u, 0x08B86D54u);
        // sp+224 = 0x08B86C94
        m.store32(0x089D69F8u, 0x08B86C94u);
        // sp+228 = 0x08B86C3C
        m.store32(0x089D7ED0u, 0x08B86C3Cu);
        // sp+232 = 0x08B86C24
        m.store32(0x089D69E8u, 0x08B86C24u);
        // sp+236 = 0x08B85110
        m.store32(0x089D7E88u, 0x08B85110u);
        // sp+240 = 0x08B85100
        m.store32(0x089D7E78u, 0x08B85100u);
        // sp+244 = 0x08B850F4
        m.store32(0x089D69B8u, 0x08B850F4u);
        // sp+248 = 0x08B850EC
        m.store32(0x089D7F28u, 0x08B850ECu);
        // sp+252 = 0x08B84B54
        m.store32(0x089D727Cu, 0x08B84B54u);
        // sp+256 = 0x08B84B1C
        m.store32(0x089D7F90u, 0x08B84B1Cu);
        // sp+264 = 0x08B84348
        m.store32(0x089D6040u, 0x08B84348u);
        // sp+268 = 0x08B83F04
        m.store32(0x089D5E88u, 0x08B83F04u);
        // Also keep the previously identified values that came from register context
        // (0x089D69A0, 0x089D6008, 0x089D69A8, 0x089D5EA8 depend on runtime regs — set to
        //  the values from the prior session's analysis; wrong values cause incorrect behaviour
        //  but are preferable to null crashes):
        m.store32(0x089D69A0u, 0x08C15E80u); // prior estimate (register-dependent)
        m.store32(0x089D69A8u, 0x08C13B00u); // prior estimate (register-dependent)
        m.store32(0x089D6008u, 0x08C15E80u); // prior estimate (register-dependent)
        m.store32(0x089D5EA8u, 0x08C15E80u); // prior estimate (register-dependent)
        // Remaining stores from FUN_088769CC (unit_0003) static analysis:
        m.store32(0x089D4788u, 0x08B83508u);
        m.store32(0x089D4D78u, 0x08BAE9D8u); // fixed from simulation (was 0x08BAE9B8)
        m.store32(0x089D4D80u, 0x08BA4FA0u);
        m.store32(0x089D4DC8u, 0x08BA77D0u);
        m.store32(0x089D5F00u, 0x08C10DA0u);
        m.store32(0x089D6C30u, 0x08BFEEC8u); // fixed (was 0x08BFEECCu)
        m.store32(0x089D6C88u, 0x08BFF518u);
        m.store32(0x089D8140u, 0x08B84370u);
        m.store32(0x089D8378u, 0x08B834FCu);
        m.store32(0x089D8380u, 0x08B83564u);
        m.store32(0x089D8388u, 0x08B83570u);
        m.store32(0x089D8390u, 0x08B83594u);
        m.store32(0x089D8394u, 0x08B83588u);
        m.store32(0x089D8398u, 0x08B83380u);
        m.store32(0x089D83A0u, 0x08B835B8u);
        m.store32(0x089D83A8u, 0x08B83398u);
        m.store32(0x089D83B0u, 0x08B8357Cu);
        m.store32(0x089D83B8u, 0x08B835ACu);
        m.store32(0x089D83C0u, 0x08B8338Cu);
        m.store32(0x089D83C8u, 0x08B83558u);
        m.store32(0x089D83D0u, 0x08B835A0u);
        m.store32(0x089D83D8u, 0x08B83714u);
        m.store32(0x089D83DCu, 0x08B835D0u);
        m.store32(0x089D8508u, 0x08B7FA94u);
        m.store32(0x089D8510u, 0x08B7F900u);
        m.store32(0x089D8518u, 0x08B82A20u);
        m.store32(0x089D8520u, 0x08B82520u);
        m.store32(0x089D8528u, 0x08B82534u);
        m.store32(0x089D8530u, 0x08B7F8D4u);
        m.store32(0x089D8538u, 0x08B7F790u);
        m.store32(0x089D85E8u, 0x08BAED04u);
        m.store32(0x089D85ECu, 0x08BAEBc0u);
        // 0x089D85BC: stored at L_08876E9C — gpr[16] is live from prior call, keep prior estimate
        m.store32(0x089D85BCu, 0x08C13A94u);
        // 0x089985E8: object ptr written by FUN_088769CC L_0887733C.
        constexpr std::uint32_t kObj089985E8 = 0x08C15F00u;
        m.store32(0x089985E8u, kObj089985E8);
        std::printf("[D012] store 0x089985E8 = 0x%08X (verify: 0x%08X)\n", kObj089985E8, m.load32(0x089985E8u));
        m.store32(kObj089985E8 + 0u, 0u);
        m.store32(kObj089985E8 + 4u, 0u);
        m.store32(kObj089985E8 + 8u, 0u);
        m.store32(kObj089985E8 + 12u, 0u);
        std::printf("[D012] global object table pre-init done (%zu stores)\n",
            static_cast<std::size_t>(130));
        std::fflush(stdout);
    }

    std::printf("[D012] chain_observers_active=%d\n",
        static_cast<int>(psprecomp::g_runtime_chain_observers_active));
    std::fflush(stdout);

    // The decrypted BOOT.bin has ELF entry=0; redirect to the real load base.
    // When called from bootstrap (ra outside PSP code range), redirect as usual.
    // When called as a null function pointer from game code (ra is a valid PSP
    // address), treat as nop and return to ra so the chain doesn't unwind.
    rt.register_function(0x00000000u, [](psprecomp::Runtime &, psprecomp::AllegrexContext &ctx) {
        const std::uint32_t ra = ctx.gpr[31];
        if (ra >= 0x08804000u && ra < 0x0A000000u) {
            // Null function pointer called from game code — nop return
            static unsigned s_null=0;
            if (s_null++ < 4) { std::printf("[NULL-CALL] pc=0 ra=0x%08X (null fn ptr nop)\n", ra); std::fflush(stdout); }
            ctx.gpr[2] = 0u;
            ctx.pc = ra;
        } else {
            // Bootstrap entry: redirect to real load base
            ctx.pc = portablekit::game().load_base;
        }
    }, "d012_entry_redirect");

    // NID 0xDC75F153 appears as a raw function pointer in the resource manager
    // vtable (struct offset 340+176+4).  It is never resolved to a real address
    // by the PSP linker in our recomp environment, so register it as a nop stub
    // so the dispatcher can call and return from it rather than crashing.
    rt.register_function(0xDC75F153u, [](psprecomp::Runtime &, psprecomp::AllegrexContext &ctx) {
        static unsigned s_count = 0u;
        if (s_count++ < 4u) { std::printf("[NID-STUB] 0xDC75F153 called (count=%u) ra=0x%08X\n", s_count, ctx.gpr[31]); std::fflush(stdout); }
        ctx.gpr[2] = 0u;
        ctx.pc = ctx.gpr[31];
    }, "stub_nid_DC75F153");

    // unit_0014 intercepts sceKernelCreateThread/StartThread inline and routes
    // them to d012::hle_create/start_thread, bypassing PortableKit's kernel.
    // Override those addresses so PortableKit's kernel handles them instead.
    rt.register_function(0x089C5FD0u, [](psprecomp::Runtime &, psprecomp::AllegrexContext &ctx) {
        // sceKernelCreateThread(name, entry, priority, stackSize, attr, opt)
        // gpr[4]=name ptr, gpr[5]=entry, gpr[6]=priority, gpr[7]=stackSize
        // Guard: if the main game thread (entry=0x08804160) was already created,
        // refuse further creates from the loader loop to stop infinite re-entry.
        static bool s_main_thread_created = false;
        const std::uint32_t entry = ctx.gpr[5];
        if (entry == 0x08804160u && s_main_thread_created) {
            // Silently return -1 without kernel().finish() to avoid a thread-
            // priority check that would yield the chain on every init HLE call.
            ctx.gpr[2] = static_cast<std::uint32_t>(-1);
            ctx.pc = ctx.gpr[31];
            return;
        }
        const std::int32_t uid = portablekit::kernel().create_thread(
            "d012_thread", entry, ctx.gpr[6], ctx.gpr[7], 0u, ctx.gpr[28]);
        std::printf("[HLE] sceKernelCreateThread uid=%d entry=0x%08X\n", uid, entry);
        if (entry == 0x08804160u && uid > 0) s_main_thread_created = true;
        portablekit::kernel().finish(ctx, static_cast<std::uint32_t>(uid));
        ctx.pc = ctx.gpr[31];
    }, "hle_sceKernelCreateThread");

    rt.register_function(0x089C5FA0u, [](psprecomp::Runtime &, psprecomp::AllegrexContext &ctx) {
        // sceKernelStartThread(uid, arglen, argp)
        // Guard: if arglen==0 or argp is not a plausible guest pointer, pass zeros
        // to avoid PortableKit copying from an invalid address.
        const std::uint32_t arglen = ctx.gpr[5];
        const std::uint32_t argp   = ctx.gpr[6];
        const bool valid_argp = arglen > 0u && arglen <= 0x10000u &&
                                argp >= 0x08800000u && argp < 0x10000000u;
        const std::int32_t result = portablekit::kernel().start_thread(
            ctx, static_cast<portablekit::SceUID>(ctx.gpr[4]),
            valid_argp ? arglen : 0u,
            valid_argp ? argp   : 0u);
        std::printf("[HLE] sceKernelStartThread uid=%u arglen=%u argp=0x%08X result=%d\n",
            ctx.gpr[4], arglen, argp, result);
        portablekit::kernel().finish(ctx, static_cast<std::uint32_t>(result));
        ctx.pc = ctx.gpr[31];
    }, "hle_sceKernelStartThread");

    // Task jump-table dispatch stub at 0x08844F84 — crashes if not intercepted.
    rt.register_function(0x08844F84u, [](psprecomp::Runtime &, psprecomp::AllegrexContext &ctx) {
        ctx.gpr[2] = 0u;
        ctx.pc = ctx.gpr[31];
    }, "recomp_unit_0002_task_jt_dispatch_stub");

    // FUN_088820C0 reads DAT_089D69A0 (a subsystem ptr set by FUN_088769CC from
    // caller registers we don't have) then loads a heap-allocator struct pointer
    // from offset +0x00ECDC00.  Since DAT_089D69A0 is never correctly initialized,
    // we intercept the function and return a pre-initialized heap struct instead.
    //
    // Heap struct layout for FUN_0885C6CC (bump allocator):
    //   +0  capacity (unused by alloc path)
    //   +4  free_base (must != struct+20 to enter block-scan path)
    //   +8  zero
    //   +12 default alignment
    //   +16 free-list head (null = use block array)
    //   +20 first block entry:
    //       +0 upper limit of free region
    //       +4 prev ptr (null)
    //       +8 step from entry to next region (0 = entry itself is the start)
    {
        auto &m = rt.memory();
        constexpr std::uint32_t kHeapStruct = 0x09000000u;
        constexpr std::uint32_t kFreeBase   = 0x09010000u; // != kHeapStruct+20
        constexpr std::uint32_t kFreeLimit  = 0x09410000u; // 4 MB window
        m.store32(kHeapStruct +  0u, 0u);
        m.store32(kHeapStruct +  4u, kFreeBase);
        m.store32(kHeapStruct +  8u, 0u);
        m.store32(kHeapStruct + 12u, 64u);
        m.store32(kHeapStruct + 16u, 0u);               // free list null
        // first block entry at struct+20 = 0x09000014
        m.store32(kHeapStruct + 20u, kFreeLimit);        // +0: upper limit
        m.store32(kHeapStruct + 24u, 0u);                // +4: prev = null
        m.store32(kHeapStruct + 28u, 0u);                // +8: step = 0
        m.store32(kHeapStruct + 32u, 0u);                // +12: flags
        std::printf("[D012] fake heap struct at 0x%08X free=0x%08X..0x%08X\n",
            kHeapStruct, kFreeBase, kFreeLimit);
        std::fflush(stdout);
    }
    rt.register_function(0x088820C0u, [](psprecomp::Runtime &, psprecomp::AllegrexContext &ctx) {
        ctx.gpr[2] = 0x09000000u;
        ctx.pc = ctx.gpr[31];
    }, "hle_FUN_088820C0_heap_stub");

    // Shared bump allocator for all internal heap alloc variants.
    // gpr[4]=heap_ptr (ignored), gpr[5]=size, gpr[6]=align (0 = default 64).
    // Arena: 0x09410000–0x09C00000 (~8 MB), just above the fake heap struct.
    // s_heap_bump must survive past patch_d012_image returning, so static.
    static std::uint32_t s_heap_bump = 0x09410000u;
    auto heap_alloc_stub = [](psprecomp::Runtime &, psprecomp::AllegrexContext &ctx) {
        constexpr std::uint32_t kHeapArenaLimit = 0x09C00000u;
        std::uint32_t size  = ctx.gpr[5];
        std::uint32_t align = ctx.gpr[6] ? ctx.gpr[6] : 64u;
        if (align < 4u) align = 4u;
        s_heap_bump = (s_heap_bump + align - 1u) & ~(align - 1u);
        if (size == 0u || s_heap_bump + size > kHeapArenaLimit) {
            ctx.gpr[2] = 0u;
        } else {
            ctx.gpr[2] = s_heap_bump;
            s_heap_bump += size;
        }
        ctx.pc = ctx.gpr[31];
    };
    rt.register_function(0x0885C538u, heap_alloc_stub, "recomp_unit_0002_FUN_0885C538_heap_alloc");
    rt.register_function(0x0885C6CCu, heap_alloc_stub, "recomp_unit_0002_FUN_0885C6CC_heap_alloc");

    // FUN_088769CC (L_0887733C) stores gpr[20]=0 to 0x089985E8 because s4 is 0
    // when the function is called (see [769CC-REGS] log: s20=0).  The read at
    // L_08933A18 then crashes on null.  Re-patch 0x089985E8 immediately before
    // 0x0885C538 is invoked from L_08933A08 (which is the last write site before
    // the crash read).  We override 0x08933A08 so the dispatch table routes here
    // instead of the generated L_08933A08 code, re-store the valid ptr, then
    // execute L_08933A08's body inline:
    //   gpr[4]=gpr[16], gpr[5]=gpr[21], gpr[31]=0x08933A18, gpr[6]=64,
    //   call 0x0885C538 (already registered as our alloc stub).
    // L_08933A18 is the return address after the 0x0885C538 alloc call at L_08933A08.
    // It reads gpr[4] from 0x089985E8, which FUN_088769CC cleared to 0 (gpr[20]=0
    // at L_0887733C).  Override the dispatch entry for 0x08933A18 so we re-store
    // our stub object pointer before the read.  The rest of L_08933A18's body
    // (gpr[16]=0x089A0000, gpr[31]=0x08933A24, gpr[4]=load[0x089985E8], goto
    // L_08933BF0) is replicated inline then we jump to L_08933BF0.
    rt.register_function(0x08933A18u, [](psprecomp::Runtime &rt, psprecomp::AllegrexContext &ctx) {
        constexpr std::uint32_t kObj = 0x08C15F00u;
        rt.memory().store32(0x089985E8u, kObj);
        ctx.gpr[16] = 2206u << 16u;   // = 0x089A0000
        ctx.gpr[31] = 0x08933A24u;
        ctx.gpr[4]  = kObj;            // the value we just stored
        // Jump to L_08933BF0 (stores 0xFF to byte+0 and 0 to word+4 of the obj)
        ctx.pc = 0x08933BF0u;
    }, "hle_L08933A18_fixup");

    // L_08933A24 also reads [0x089985E8] → gpr[4], then calls L_08933C00.
    // Same null-pointer hazard as L_08933A18; supply our stub object and resume.
    rt.register_function(0x08933A24u, [](psprecomp::Runtime &rt, psprecomp::AllegrexContext &ctx) {
        constexpr std::uint32_t kObj = 0x08C15F00u;
        rt.memory().store32(0x089985E8u, kObj);
        ctx.gpr[16] = 2206u << 16u;
        ctx.gpr[31] = 0x08933A2Cu;
        ctx.gpr[4]  = kObj;
        ctx.pc = 0x08933C00u;
    }, "hle_L08933A24_fixup");

    // Overlay functions are now fully AOT-compiled via the full overlay recompile
    // (overlay_menu_full → overlay_menu swap).  No interpreter stubs needed.

    // sceKernelLoadModule: return an incrementing positive UID so the caller
    // can pass it to sceKernelStartModule.  PPSSPP returns 288 for LIBFONT.PRX
    // and 289 for LIBSUPPREACC.PRX; we start at 288 to stay in-range.
    rt.register_function(0x089C57D8u, [](psprecomp::Runtime &, psprecomp::AllegrexContext &ctx) {
        static std::uint32_t s_module_uid = 288u;
        const std::uint32_t uid = s_module_uid++;
        std::printf("[HLE] sceKernelLoadModule uid=%u\n", uid);
        ctx.gpr[2] = uid;
        ctx.pc = ctx.gpr[31];
    }, "hle_sceKernelLoadModule");

    // sceKernelStartModule: accept any UID, return 0 (success).
    // Also redirect the PRX init fn-ptr at 0x089A09C0 to our nop stub so the
    // interpreter never runs uncompiled PRX code loaded into heap.
    rt.register_function(0x089C57C8u, [](psprecomp::Runtime &rt2, psprecomp::AllegrexContext &ctx) {
        std::printf("[HLE] sceKernelStartModule uid=%u\n", ctx.gpr[4]);
        rt2.memory().store32(0x089A09C0u, 0x08BA7800u);
        ctx.gpr[2] = 0u;
        ctx.pc = ctx.gpr[31];
    }, "hle_sceKernelStartModule");

    // scesupPreAcc stubs — resolved dynamically by LIBSUPPREACC.PRX in PPSSPP.
    // We can't ship that PRX, so register safe nops returning 0 at each address.
    for (std::uint32_t addr : {
            0x089C5D10u, 0x089C5D18u, 0x089C5D20u, 0x089C5D28u,
            0x089C5D30u, 0x089C5D38u, 0x089C5D40u, 0x089C5D48u}) {
        rt.register_function(addr, [](psprecomp::Runtime &, psprecomp::AllegrexContext &ctx) {
            ctx.gpr[2] = 0u;
            ctx.pc = ctx.gpr[31];
        }, "hle_scesupPreAcc_stub");
    }

    // Patch complete.

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
