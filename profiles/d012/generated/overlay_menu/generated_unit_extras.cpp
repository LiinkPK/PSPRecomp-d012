#include "psprecomp/runtime.hpp"
#include <bit>
#include <cmath>
#include <cstdint>
#include <limits>

namespace psprecomp { namespace ovl_menu {
static const std::uint16_t kEntryIds____sub_089E7678[64] = {
    1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31,
    32, 33, 34, 0, 35, 36, 37, 38, 0, 39, 40, 41, 42, 43, 0, 44, 45, 46, 47, 48, 49, 50, 0, 51, 52, 0, 53, 54, 55, 0, 56, 57,
};
void ___sub_089E7678_entry(Runtime &rt, AllegrexContext &ctx, std::uint16_t direct_entry_id, GuestMemory::AotFastView &aot_mem) {
    std::uint32_t jump_target = 0u;
    std::uint32_t local_transfers = 0u;
    std::uint32_t local_pc = ctx.pc;
    std::uint32_t entry_id = direct_entry_id;
LOCAL_DISPATCH:
    {
    if (entry_id == 0u) {
        const std::uint32_t entry_delta = local_pc - 0x089E7678u;
        entry_id = (entry_delta < 256u && (entry_delta & 3u) == 0u) ? kEntryIds____sub_089E7678[entry_delta >> 2u] : 0u;
    }
    switch (entry_id) {
    case 1u: goto L_089E7678;
    case 2u: goto L_089E767C;
    case 3u: goto L_089E7680;
    case 4u: goto L_089E7684;
    case 5u: goto L_089E7688;
    case 6u: goto L_089E768C;
    case 7u: goto L_089E7690;
    case 8u: goto L_089E7694;
    case 9u: goto L_089E7698;
    case 10u: goto L_089E76A0;
    case 11u: goto L_089E76A4;
    case 12u: goto L_089E76A8;
    case 13u: goto L_089E76AC;
    case 14u: goto L_089E76B0;
    case 15u: goto L_089E76B4;
    case 16u: goto L_089E76B8;
    case 17u: goto L_089E76BC;
    case 18u: goto L_089E76C0;
    case 19u: goto L_089E76C4;
    case 20u: goto L_089E76C8;
    case 21u: goto L_089E76CC;
    case 22u: goto L_089E76D0;
    case 23u: goto L_089E76D4;
    case 24u: goto L_089E76D8;
    case 25u: goto L_089E76DC;
    case 26u: goto L_089E76E0;
    case 27u: goto L_089E76E4;
    case 28u: goto L_089E76E8;
    case 29u: goto L_089E76EC;
    case 30u: goto L_089E76F0;
    case 31u: goto L_089E76F4;
    case 32u: goto L_089E76F8;
    case 33u: goto L_089E76FC;
    case 34u: goto L_089E7700;
    case 35u: goto L_089E7708;
    case 36u: goto L_089E770C;
    case 37u: goto L_089E7710;
    case 38u: goto L_089E7714;
    case 39u: goto L_089E771C;
    case 40u: goto L_089E7720;
    case 41u: goto L_089E7724;
    case 42u: goto L_089E7728;
    case 43u: goto L_089E772C;
    case 44u: goto L_089E7734;
    case 45u: goto L_089E7738;
    case 46u: goto L_089E773C;
    case 47u: goto L_089E7740;
    case 48u: goto L_089E7744;
    case 49u: goto L_089E7748;
    case 50u: goto L_089E774C;
    case 51u: goto L_089E7754;
    case 52u: goto L_089E7758;
    case 53u: goto L_089E7760;
    case 54u: goto L_089E7764;
    case 55u: goto L_089E7768;
    case 56u: goto L_089E7770;
    case 57u: goto L_089E7774;
    default:
        if (local_transfers == 0u) rt.unsupported(ctx.pc, 0u, "invalid internal function entry");
        else ctx.pc = local_pc;
        return;
    }
    }
L_089E7678:
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(-16));
    goto L_089E767C;
L_089E767C:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(0), ctx.gpr[16]);
    goto L_089E7680;
L_089E7680:
    ctx.set_gpr(16, ctx.gpr[4] | 0u);
    goto L_089E7684;
L_089E7684:
    ctx.set_gpr(6, 1u << 16u);
    goto L_089E7688;
L_089E7688:
    ctx.set_gpr(4, ctx.gpr[16] + static_cast<std::uint32_t>(256));
    goto L_089E768C;
L_089E768C:
    ctx.set_gpr(5, 0u | 1u);
    goto L_089E7690;
L_089E7690:
    ctx.set_gpr(7, 0u | 65u);
    goto L_089E7694;
L_089E7694:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(4), ctx.gpr[31]);
    goto L_089E7698;
L_089E7698:
    ctx.set_gpr(31, 0x089E76A0u);
    ctx.set_gpr(6, ctx.gpr[6] + static_cast<std::uint32_t>(4484));
    ctx.pc = 0x08864FF0u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x089E76A0u) goto L_089E76A0;
    return;
L_089E76A0:
    rt.memory().aot_store32(ctx.gpr[16] + static_cast<std::uint32_t>(308), 0u);
    goto L_089E76A4;
L_089E76A4:
    rt.memory().aot_store32(ctx.gpr[16] + static_cast<std::uint32_t>(312), 0u);
    goto L_089E76A8;
L_089E76A8:
    rt.memory().aot_store32(ctx.gpr[16] + static_cast<std::uint32_t>(316), 0u);
    goto L_089E76AC;
L_089E76AC:
    rt.memory().aot_store32(ctx.gpr[16] + static_cast<std::uint32_t>(320), 0u);
    goto L_089E76B0;
L_089E76B0:
    rt.memory().aot_store32(ctx.gpr[16] + static_cast<std::uint32_t>(324), 0u);
    goto L_089E76B4;
L_089E76B4:
    rt.memory().aot_store32(ctx.gpr[16] + static_cast<std::uint32_t>(328), 0u);
    goto L_089E76B8;
L_089E76B8:
    rt.memory().aot_store8(ctx.gpr[16] + static_cast<std::uint32_t>(400), static_cast<std::uint8_t>(0u));
    goto L_089E76BC;
L_089E76BC:
    rt.memory().aot_store8(ctx.gpr[16] + static_cast<std::uint32_t>(401), static_cast<std::uint8_t>(0u));
    goto L_089E76C0;
L_089E76C0:
    rt.memory().aot_store32(ctx.gpr[16] + static_cast<std::uint32_t>(336), 0u);
    goto L_089E76C4;
L_089E76C4:
    rt.memory().aot_store32(ctx.gpr[16] + static_cast<std::uint32_t>(332), 0u);
    goto L_089E76C8;
L_089E76C8:
    rt.memory().aot_store32(ctx.gpr[16] + static_cast<std::uint32_t>(340), 0u);
    goto L_089E76CC;
L_089E76CC:
    rt.memory().aot_store32(ctx.gpr[16] + static_cast<std::uint32_t>(344), 0u);
    goto L_089E76D0;
L_089E76D0:
    rt.memory().aot_store32(ctx.gpr[16] + static_cast<std::uint32_t>(348), 0u);
    goto L_089E76D4;
L_089E76D4:
    rt.memory().aot_store32(ctx.gpr[16] + static_cast<std::uint32_t>(352), 0u);
    goto L_089E76D8;
L_089E76D8:
    rt.memory().aot_store32(ctx.gpr[16] + static_cast<std::uint32_t>(356), 0u);
    goto L_089E76DC;
L_089E76DC:
    rt.memory().aot_store32(ctx.gpr[16] + static_cast<std::uint32_t>(360), 0u);
    goto L_089E76E0;
L_089E76E0:
    rt.memory().aot_store32(ctx.gpr[16] + static_cast<std::uint32_t>(364), 0u);
    goto L_089E76E4;
L_089E76E4:
    ctx.fpr[12] = std::bit_cast<float>(0u);
    goto L_089E76E8;
L_089E76E8:
    rt.memory().aot_store32(ctx.gpr[16] + static_cast<std::uint32_t>(368), 0u);
    goto L_089E76EC;
L_089E76EC:
    rt.memory().aot_store32(ctx.gpr[16] + static_cast<std::uint32_t>(372), std::bit_cast<std::uint32_t>(ctx.fpr[12]));
    goto L_089E76F0;
L_089E76F0:
    rt.memory().aot_store32(ctx.gpr[16] + static_cast<std::uint32_t>(376), 0u);
    goto L_089E76F4;
L_089E76F4:
    rt.memory().aot_store8(ctx.gpr[16] + static_cast<std::uint32_t>(380), static_cast<std::uint8_t>(0u));
    goto L_089E76F8;
L_089E76F8:
    ctx.set_gpr(4, ctx.gpr[16] + static_cast<std::uint32_t>(384));
    goto L_089E76FC;
L_089E76FC:
    ctx.set_gpr(5, 0u | 0u);
    goto L_089E7700;
L_089E7700:
    ctx.set_gpr(31, 0x089E7708u);
    ctx.set_gpr(6, 0u | 16u);
    ctx.pc = 0x08935828u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x089E7708u) goto L_089E7708;
    return;
L_089E7708:
    ctx.set_gpr(2, ctx.gpr[16] | 0u);
    goto L_089E770C;
L_089E770C:
    ctx.set_gpr(16, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(0)));
    goto L_089E7710;
L_089E7710:
    ctx.set_gpr(31, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(4)));
    goto L_089E7714;
L_089E7714:
    jump_target = ctx.gpr[31];
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(16));
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_089E771C:
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(-32));
    goto L_089E7720;
L_089E7720:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(20), ctx.gpr[16]);
    goto L_089E7724;
L_089E7724:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(24), ctx.gpr[17]);
    goto L_089E7728;
L_089E7728:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(28), ctx.gpr[31]);
    goto L_089E772C;
L_089E772C:
    ctx.set_gpr(31, 0x089E7734u);
    ctx.set_gpr(16, ctx.gpr[4] | 0u);
    ctx.pc = 0x08883F78u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x089E7734u) goto L_089E7734;
    return;
L_089E7734:
    ctx.set_gpr(7, 2207u << 16u);
    goto L_089E7738;
L_089E7738:
    ctx.set_gpr(8, 2207u << 16u);
    goto L_089E773C;
L_089E773C:
    ctx.set_gpr(4, ctx.gpr[16] + static_cast<std::uint32_t>(256));
    goto L_089E7740;
L_089E7740:
    ctx.set_gpr(5, 0u | 0u);
    goto L_089E7744;
L_089E7744:
    ctx.set_gpr(6, 0u | 0u);
    goto L_089E7748;
L_089E7748:
    ctx.set_gpr(7, ctx.gpr[7] + static_cast<std::uint32_t>(-27680));
    goto L_089E774C;
L_089E774C:
    ctx.set_gpr(31, 0x089E7754u);
    ctx.set_gpr(8, ctx.gpr[8] + static_cast<std::uint32_t>(-25472));
    ctx.pc = 0x08865088u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x089E7754u) goto L_089E7754;
    return;
L_089E7754:
    ctx.set_gpr(4, 2205u << 16u);
    goto L_089E7758;
L_089E7758:
    ctx.set_gpr(31, 0x089E7760u);
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(18784)));
    ctx.pc = 0x08844588u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x089E7760u) goto L_089E7760;
    return;
L_089E7760:
    ctx.set_gpr(4, 2205u << 16u);
    goto L_089E7764;
L_089E7764:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(30768)));
    goto L_089E7768;
L_089E7768:
    ctx.set_gpr(31, 0x089E7770u);
    ctx.set_gpr(5, 0u | 0u);
    ctx.pc = 0x088D1604u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x089E7770u) goto L_089E7770;
    return;
L_089E7770:
    ctx.set_gpr(17, 32u << 16u);
    goto L_089E7774;
L_089E7774:
    ctx.set_gpr(31, 0x089E777Cu);
    ctx.set_gpr(4, ctx.gpr[17] | 0u);
    ctx.pc = 0x0888204Cu;
    (void)rt.invoke_chained_call(ctx, &aot_mem);
    return;
}

void ___sub_089E7678(Runtime &rt, AllegrexContext &ctx) {
    auto aot_mem = rt.memory().aot_fast_view();
    ___sub_089E7678_entry(rt, ctx, 0u, aot_mem);
}

static const std::uint16_t kEntryIds_sub_089FE524[64] = {
    1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 10, 11, 12, 13, 0, 14, 15, 16, 0, 17, 0, 18, 0, 19, 20, 0, 21, 22, 0, 23, 24, 0,
    25, 26, 0, 27, 28, 0, 29, 30, 31, 32, 33, 34, 0, 35, 36, 37, 38, 39, 40, 0, 41, 42, 43, 44, 45, 0, 46, 47, 0, 48, 49, 50,
};
void sub_089FE524_entry(Runtime &rt, AllegrexContext &ctx, std::uint16_t direct_entry_id, GuestMemory::AotFastView &aot_mem) {
    std::uint32_t jump_target = 0u;
    std::uint32_t local_transfers = 0u;
    std::uint32_t local_pc = ctx.pc;
    std::uint32_t entry_id = direct_entry_id;
LOCAL_DISPATCH:
    {
    if (entry_id == 0u) {
        const std::uint32_t entry_delta = local_pc - 0x089FE524u;
        entry_id = (entry_delta < 256u && (entry_delta & 3u) == 0u) ? kEntryIds_sub_089FE524[entry_delta >> 2u] : 0u;
    }
    switch (entry_id) {
    case 1u: goto L_089FE524;
    case 2u: goto L_089FE528;
    case 3u: goto L_089FE52C;
    case 4u: goto L_089FE530;
    case 5u: goto L_089FE534;
    case 6u: goto L_089FE538;
    case 7u: goto L_089FE53C;
    case 8u: goto L_089FE540;
    case 9u: goto L_089FE544;
    case 10u: goto L_089FE54C;
    case 11u: goto L_089FE550;
    case 12u: goto L_089FE554;
    case 13u: goto L_089FE558;
    case 14u: goto L_089FE560;
    case 15u: goto L_089FE564;
    case 16u: goto L_089FE568;
    case 17u: goto L_089FE570;
    case 18u: goto L_089FE578;
    case 19u: goto L_089FE580;
    case 20u: goto L_089FE584;
    case 21u: goto L_089FE58C;
    case 22u: goto L_089FE590;
    case 23u: goto L_089FE598;
    case 24u: goto L_089FE59C;
    case 25u: goto L_089FE5A4;
    case 26u: goto L_089FE5A8;
    case 27u: goto L_089FE5B0;
    case 28u: goto L_089FE5B4;
    case 29u: goto L_089FE5BC;
    case 30u: goto L_089FE5C0;
    case 31u: goto L_089FE5C4;
    case 32u: goto L_089FE5C8;
    case 33u: goto L_089FE5CC;
    case 34u: goto L_089FE5D0;
    case 35u: goto L_089FE5D8;
    case 36u: goto L_089FE5DC;
    case 37u: goto L_089FE5E0;
    case 38u: goto L_089FE5E4;
    case 39u: goto L_089FE5E8;
    case 40u: goto L_089FE5EC;
    case 41u: goto L_089FE5F4;
    case 42u: goto L_089FE5F8;
    case 43u: goto L_089FE5FC;
    case 44u: goto L_089FE600;
    case 45u: goto L_089FE604;
    case 46u: goto L_089FE60C;
    case 47u: goto L_089FE610;
    case 48u: goto L_089FE618;
    case 49u: goto L_089FE61C;
    case 50u: goto L_089FE620;
    default:
        if (local_transfers == 0u) rt.unsupported(ctx.pc, 0u, "invalid internal function entry");
        else ctx.pc = local_pc;
        return;
    }
    }
L_089FE524:
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(-16));
    goto L_089FE528;
L_089FE528:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(0), ctx.gpr[16]);
    goto L_089FE52C;
L_089FE52C:
    ctx.set_gpr(16, ctx.gpr[4] | 0u);
    goto L_089FE530;
L_089FE530:
    ctx.set_gpr(6, 1u << 16u);
    goto L_089FE534;
L_089FE534:
    ctx.set_gpr(4, ctx.gpr[16] + static_cast<std::uint32_t>(256));
    goto L_089FE538;
L_089FE538:
    ctx.set_gpr(5, 0u | 1u);
    goto L_089FE53C;
L_089FE53C:
    ctx.set_gpr(7, 0u | 76u);
    goto L_089FE540;
L_089FE540:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(4), ctx.gpr[31]);
    goto L_089FE544;
L_089FE544:
    ctx.set_gpr(31, 0x089FE54Cu);
    ctx.set_gpr(6, ctx.gpr[6] + static_cast<std::uint32_t>(4477));
    ctx.pc = 0x08864FF0u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x089FE54Cu) goto L_089FE54C;
    return;
L_089FE54C:
    ctx.set_gpr(2, ctx.gpr[16] | 0u);
    goto L_089FE550;
L_089FE550:
    ctx.set_gpr(16, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(0)));
    goto L_089FE554;
L_089FE554:
    ctx.set_gpr(31, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(4)));
    goto L_089FE558;
L_089FE558:
    jump_target = ctx.gpr[31];
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(16));
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_089FE560:
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(-16));
    goto L_089FE564;
L_089FE564:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(0), ctx.gpr[31]);
    goto L_089FE568;
L_089FE568:
    { const bool branch_taken = ctx.gpr[4] == 0u;
    ctx.set_gpr(5, ctx.gpr[5] & 1u);
      if (branch_taken) {
          goto L_089FE580;
      }
      goto L_089FE570;
    }
L_089FE570:
    { const bool branch_taken = ctx.gpr[5] == 0u;
    // nop
      if (branch_taken) {
          goto L_089FE580;
      }
      goto L_089FE578;
    }
L_089FE578:
    ctx.set_gpr(31, 0x089FE580u);
    // nop
    ctx.pc = 0x08992F04u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x089FE580u) goto L_089FE580;
    return;
L_089FE580:
    ctx.set_gpr(31, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(0)));
    goto L_089FE584;
L_089FE584:
    jump_target = ctx.gpr[31];
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(16));
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_089FE58C:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(332)));
    goto L_089FE590;
L_089FE590:
    jump_target = ctx.gpr[31];
    ctx.set_gpr(2, rt.memory().aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(13028)));
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_089FE598:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(332)));
    goto L_089FE59C;
L_089FE59C:
    jump_target = ctx.gpr[31];
    ctx.set_gpr(2, rt.memory().aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(13032)));
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_089FE5A4:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(332)));
    goto L_089FE5A8;
L_089FE5A8:
    jump_target = ctx.gpr[31];
    ctx.set_gpr(2, rt.memory().aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(13036)));
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_089FE5B0:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(332)));
    goto L_089FE5B4;
L_089FE5B4:
    jump_target = ctx.gpr[31];
    ctx.set_gpr(2, rt.memory().aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(13040)));
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_089FE5BC:
    ctx.set_gpr(4, 2209u << 16u);
    goto L_089FE5C0;
L_089FE5C0:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(-18784)));
    goto L_089FE5C4;
L_089FE5C4:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(332)));
    goto L_089FE5C8;
L_089FE5C8:
    ctx.set_gpr(5, rt.memory().aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(12928)));
    goto L_089FE5CC;
L_089FE5CC:
    ctx.set_gpr(5, ctx.gpr[5] | 2u);
    goto L_089FE5D0;
L_089FE5D0:
    jump_target = ctx.gpr[31];
    rt.memory().aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(12928), ctx.gpr[5]);
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_089FE5D8:
    ctx.set_gpr(4, 2209u << 16u);
    goto L_089FE5DC;
L_089FE5DC:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(-18784)));
    goto L_089FE5E0;
L_089FE5E0:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(332)));
    goto L_089FE5E4;
L_089FE5E4:
    ctx.set_gpr(5, rt.memory().aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(12928)));
    goto L_089FE5E8;
L_089FE5E8:
    ctx.set_gpr(5, ctx.gpr[5] | 4u);
    goto L_089FE5EC;
L_089FE5EC:
    jump_target = ctx.gpr[31];
    rt.memory().aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(12928), ctx.gpr[5]);
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_089FE5F4:
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(-16));
    goto L_089FE5F8;
L_089FE5F8:
    ctx.set_gpr(5, ctx.gpr[4] | 0u);
    goto L_089FE5FC;
L_089FE5FC:
    ctx.set_gpr(4, 2209u << 16u);
    goto L_089FE600;
L_089FE600:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(0), ctx.gpr[31]);
    goto L_089FE604;
L_089FE604:
    ctx.set_gpr(31, 0x089FE60Cu);
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(-18784)));
    ctx.pc = 0x089FA3E8u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x089FE60Cu) goto L_089FE60C;
    return;
L_089FE60C:
    ctx.set_gpr(31, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(0)));
    goto L_089FE610;
L_089FE610:
    jump_target = ctx.gpr[31];
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(16));
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_089FE618:
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(-16));
    goto L_089FE61C;
L_089FE61C:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(0), ctx.gpr[31]);
    goto L_089FE620;
L_089FE620:
    ctx.set_gpr(31, 0x089FE628u);
    // nop
    ctx.pc = 0x088F29D0u;
    (void)rt.invoke_chained_call(ctx, &aot_mem);
    return;
}

void sub_089FE524(Runtime &rt, AllegrexContext &ctx) {
    auto aot_mem = rt.memory().aot_fast_view();
    sub_089FE524_entry(rt, ctx, 0u, aot_mem);
}

static const std::uint16_t kEntryIds_sub_08A1D364[64] = {
    1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31,
    32, 33, 34, 35, 36, 37, 0, 38, 39, 40, 0, 41, 0, 42, 0, 43, 44, 0, 45, 46, 47, 48, 49, 50, 51, 52, 53, 0, 54, 55, 0, 56,
};
void sub_08A1D364_entry(Runtime &rt, AllegrexContext &ctx, std::uint16_t direct_entry_id, GuestMemory::AotFastView &aot_mem) {
    std::uint32_t jump_target = 0u;
    std::uint32_t local_transfers = 0u;
    std::uint32_t local_pc = ctx.pc;
    std::uint32_t entry_id = direct_entry_id;
LOCAL_DISPATCH:
    {
    if (entry_id == 0u) {
        const std::uint32_t entry_delta = local_pc - 0x08A1D364u;
        entry_id = (entry_delta < 256u && (entry_delta & 3u) == 0u) ? kEntryIds_sub_08A1D364[entry_delta >> 2u] : 0u;
    }
    switch (entry_id) {
    case 1u: goto L_08A1D364;
    case 2u: goto L_08A1D368;
    case 3u: goto L_08A1D36C;
    case 4u: goto L_08A1D370;
    case 5u: goto L_08A1D374;
    case 6u: goto L_08A1D378;
    case 7u: goto L_08A1D37C;
    case 8u: goto L_08A1D380;
    case 9u: goto L_08A1D384;
    case 10u: goto L_08A1D38C;
    case 11u: goto L_08A1D390;
    case 12u: goto L_08A1D394;
    case 13u: goto L_08A1D398;
    case 14u: goto L_08A1D39C;
    case 15u: goto L_08A1D3A0;
    case 16u: goto L_08A1D3A4;
    case 17u: goto L_08A1D3A8;
    case 18u: goto L_08A1D3AC;
    case 19u: goto L_08A1D3B0;
    case 20u: goto L_08A1D3B4;
    case 21u: goto L_08A1D3B8;
    case 22u: goto L_08A1D3BC;
    case 23u: goto L_08A1D3C0;
    case 24u: goto L_08A1D3C4;
    case 25u: goto L_08A1D3C8;
    case 26u: goto L_08A1D3CC;
    case 27u: goto L_08A1D3D0;
    case 28u: goto L_08A1D3D4;
    case 29u: goto L_08A1D3D8;
    case 30u: goto L_08A1D3DC;
    case 31u: goto L_08A1D3E0;
    case 32u: goto L_08A1D3E4;
    case 33u: goto L_08A1D3E8;
    case 34u: goto L_08A1D3EC;
    case 35u: goto L_08A1D3F0;
    case 36u: goto L_08A1D3F4;
    case 37u: goto L_08A1D3F8;
    case 38u: goto L_08A1D400;
    case 39u: goto L_08A1D404;
    case 40u: goto L_08A1D408;
    case 41u: goto L_08A1D410;
    case 42u: goto L_08A1D418;
    case 43u: goto L_08A1D420;
    case 44u: goto L_08A1D424;
    case 45u: goto L_08A1D42C;
    case 46u: goto L_08A1D430;
    case 47u: goto L_08A1D434;
    case 48u: goto L_08A1D438;
    case 49u: goto L_08A1D43C;
    case 50u: goto L_08A1D440;
    case 51u: goto L_08A1D444;
    case 52u: goto L_08A1D448;
    case 53u: goto L_08A1D44C;
    case 54u: goto L_08A1D454;
    case 55u: goto L_08A1D458;
    case 56u: goto L_08A1D460;
    default:
        if (local_transfers == 0u) rt.unsupported(ctx.pc, 0u, "invalid internal function entry");
        else ctx.pc = local_pc;
        return;
    }
    }
L_08A1D364:
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(-16));
    goto L_08A1D368;
L_08A1D368:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(0), ctx.gpr[16]);
    goto L_08A1D36C;
L_08A1D36C:
    ctx.set_gpr(16, ctx.gpr[4] | 0u);
    goto L_08A1D370;
L_08A1D370:
    ctx.set_gpr(6, 1u << 16u);
    goto L_08A1D374;
L_08A1D374:
    ctx.set_gpr(4, ctx.gpr[16] + static_cast<std::uint32_t>(256));
    goto L_08A1D378;
L_08A1D378:
    ctx.set_gpr(5, 0u | 1u);
    goto L_08A1D37C;
L_08A1D37C:
    ctx.set_gpr(7, 0u | 76u);
    goto L_08A1D380;
L_08A1D380:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(4), ctx.gpr[31]);
    goto L_08A1D384;
L_08A1D384:
    ctx.set_gpr(31, 0x08A1D38Cu);
    ctx.set_gpr(6, ctx.gpr[6] + static_cast<std::uint32_t>(4473));
    ctx.pc = 0x08864FF0u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08A1D38Cu) goto L_08A1D38C;
    return;
L_08A1D38C:
    ctx.set_gpr(4, 2210u << 16u);
    goto L_08A1D390;
L_08A1D390:
    ctx.set_gpr(4, ctx.gpr[4] + static_cast<std::uint32_t>(13328));
    goto L_08A1D394;
L_08A1D394:
    rt.memory().aot_store32(ctx.gpr[16] + static_cast<std::uint32_t>(348), ctx.gpr[4]);
    goto L_08A1D398;
L_08A1D398:
    ctx.set_gpr(4, 2210u << 16u);
    goto L_08A1D39C;
L_08A1D39C:
    rt.memory().aot_store32(ctx.gpr[16] + static_cast<std::uint32_t>(352), ctx.gpr[16]);
    goto L_08A1D3A0;
L_08A1D3A0:
    ctx.set_gpr(4, ctx.gpr[4] + static_cast<std::uint32_t>(13400));
    goto L_08A1D3A4;
L_08A1D3A4:
    rt.memory().aot_store32(ctx.gpr[16] + static_cast<std::uint32_t>(356), ctx.gpr[4]);
    goto L_08A1D3A8;
L_08A1D3A8:
    ctx.set_gpr(4, 2210u << 16u);
    goto L_08A1D3AC;
L_08A1D3AC:
    rt.memory().aot_store32(ctx.gpr[16] + static_cast<std::uint32_t>(360), ctx.gpr[16]);
    goto L_08A1D3B0;
L_08A1D3B0:
    ctx.set_gpr(4, ctx.gpr[4] + static_cast<std::uint32_t>(13472));
    goto L_08A1D3B4;
L_08A1D3B4:
    rt.memory().aot_store32(ctx.gpr[16] + static_cast<std::uint32_t>(368), ctx.gpr[4]);
    goto L_08A1D3B8;
L_08A1D3B8:
    rt.memory().aot_store32(ctx.gpr[16] + static_cast<std::uint32_t>(372), ctx.gpr[16]);
    goto L_08A1D3BC;
L_08A1D3BC:
    ctx.set_gpr(4, 2487u << 16u);
    goto L_08A1D3C0;
L_08A1D3C0:
    rt.memory().aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(-10176), 0u);
    goto L_08A1D3C4;
L_08A1D3C4:
    ctx.set_gpr(4, ctx.gpr[4] + static_cast<std::uint32_t>(-10176));
    goto L_08A1D3C8;
L_08A1D3C8:
    rt.memory().aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(28), 0u);
    goto L_08A1D3CC;
L_08A1D3CC:
    ctx.set_gpr(5, 0u + static_cast<std::uint32_t>(-1));
    goto L_08A1D3D0;
L_08A1D3D0:
    rt.memory().aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(4), ctx.gpr[5]);
    goto L_08A1D3D4;
L_08A1D3D4:
    rt.memory().aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(8), 0u);
    goto L_08A1D3D8;
L_08A1D3D8:
    ctx.set_gpr(5, 0u | 1u);
    goto L_08A1D3DC;
L_08A1D3DC:
    rt.memory().aot_store8(ctx.gpr[4] + static_cast<std::uint32_t>(25), static_cast<std::uint8_t>(ctx.gpr[5]));
    goto L_08A1D3E0;
L_08A1D3E0:
    rt.memory().aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(16), 0u);
    goto L_08A1D3E4;
L_08A1D3E4:
    rt.memory().aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(20), 0u);
    goto L_08A1D3E8;
L_08A1D3E8:
    rt.memory().aot_store8(ctx.gpr[4] + static_cast<std::uint32_t>(32), static_cast<std::uint8_t>(0u));
    goto L_08A1D3EC;
L_08A1D3EC:
    ctx.set_gpr(2, ctx.gpr[16] | 0u);
    goto L_08A1D3F0;
L_08A1D3F0:
    ctx.set_gpr(16, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(0)));
    goto L_08A1D3F4;
L_08A1D3F4:
    ctx.set_gpr(31, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(4)));
    goto L_08A1D3F8;
L_08A1D3F8:
    jump_target = ctx.gpr[31];
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(16));
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08A1D400:
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(-16));
    goto L_08A1D404;
L_08A1D404:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(0), ctx.gpr[31]);
    goto L_08A1D408;
L_08A1D408:
    { const bool branch_taken = ctx.gpr[4] == 0u;
    ctx.set_gpr(5, ctx.gpr[5] & 1u);
      if (branch_taken) {
          goto L_08A1D420;
      }
      goto L_08A1D410;
    }
L_08A1D410:
    { const bool branch_taken = ctx.gpr[5] == 0u;
    // nop
      if (branch_taken) {
          goto L_08A1D420;
      }
      goto L_08A1D418;
    }
L_08A1D418:
    ctx.set_gpr(31, 0x08A1D420u);
    // nop
    ctx.pc = 0x08992F04u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08A1D420u) goto L_08A1D420;
    return;
L_08A1D420:
    ctx.set_gpr(31, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(0)));
    goto L_08A1D424;
L_08A1D424:
    jump_target = ctx.gpr[31];
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(16));
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08A1D42C:
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(-16));
    goto L_08A1D430;
L_08A1D430:
    ctx.set_gpr(9, ctx.gpr[8] | 0u);
    goto L_08A1D434;
L_08A1D434:
    ctx.set_gpr(8, ctx.gpr[7] | 0u);
    goto L_08A1D438;
L_08A1D438:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(340)));
    goto L_08A1D43C;
L_08A1D43C:
    ctx.set_gpr(7, ctx.gpr[6] | 0u);
    goto L_08A1D440;
L_08A1D440:
    ctx.set_gpr(6, ctx.gpr[5] | 0u);
    goto L_08A1D444;
L_08A1D444:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(2188)));
    goto L_08A1D448;
L_08A1D448:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(0), ctx.gpr[31]);
    goto L_08A1D44C;
L_08A1D44C:
    ctx.set_gpr(31, 0x08A1D454u);
    ctx.set_gpr(5, 0u | 1u);
    ctx.pc = 0x0887B3ECu;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08A1D454u) goto L_08A1D454;
    return;
L_08A1D454:
    ctx.set_gpr(31, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(0)));
    goto L_08A1D458;
L_08A1D458:
    jump_target = ctx.gpr[31];
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(16));
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08A1D460:
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(-16));
    ctx.pc = 0x08A1D464u; return;
}

void sub_08A1D364(Runtime &rt, AllegrexContext &ctx) {
    auto aot_mem = rt.memory().aot_fast_view();
    sub_08A1D364_entry(rt, ctx, 0u, aot_mem);
}

static const std::uint16_t kEntryIds_sub_08A2BCE4[64] = {
    1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 10, 11, 12, 13, 0, 14, 15, 16, 0, 17, 0, 18, 0, 19, 20, 0, 21, 22, 23, 24, 25, 26,
    0, 27, 28, 29, 30, 31, 32, 0, 33, 34, 35, 36, 37, 38, 39, 40, 0, 41, 42, 43, 44, 0, 45, 46, 47, 48, 49, 50, 51, 52, 0, 53,
};
void sub_08A2BCE4_entry(Runtime &rt, AllegrexContext &ctx, std::uint16_t direct_entry_id, GuestMemory::AotFastView &aot_mem) {
    std::uint32_t jump_target = 0u;
    std::uint32_t local_transfers = 0u;
    std::uint32_t local_pc = ctx.pc;
    std::uint32_t entry_id = direct_entry_id;
LOCAL_DISPATCH:
    {
    if (entry_id == 0u) {
        const std::uint32_t entry_delta = local_pc - 0x08A2BCE4u;
        entry_id = (entry_delta < 256u && (entry_delta & 3u) == 0u) ? kEntryIds_sub_08A2BCE4[entry_delta >> 2u] : 0u;
    }
    switch (entry_id) {
    case 1u: goto L_08A2BCE4;
    case 2u: goto L_08A2BCE8;
    case 3u: goto L_08A2BCEC;
    case 4u: goto L_08A2BCF0;
    case 5u: goto L_08A2BCF4;
    case 6u: goto L_08A2BCF8;
    case 7u: goto L_08A2BCFC;
    case 8u: goto L_08A2BD00;
    case 9u: goto L_08A2BD04;
    case 10u: goto L_08A2BD0C;
    case 11u: goto L_08A2BD10;
    case 12u: goto L_08A2BD14;
    case 13u: goto L_08A2BD18;
    case 14u: goto L_08A2BD20;
    case 15u: goto L_08A2BD24;
    case 16u: goto L_08A2BD28;
    case 17u: goto L_08A2BD30;
    case 18u: goto L_08A2BD38;
    case 19u: goto L_08A2BD40;
    case 20u: goto L_08A2BD44;
    case 21u: goto L_08A2BD4C;
    case 22u: goto L_08A2BD50;
    case 23u: goto L_08A2BD54;
    case 24u: goto L_08A2BD58;
    case 25u: goto L_08A2BD5C;
    case 26u: goto L_08A2BD60;
    case 27u: goto L_08A2BD68;
    case 28u: goto L_08A2BD6C;
    case 29u: goto L_08A2BD70;
    case 30u: goto L_08A2BD74;
    case 31u: goto L_08A2BD78;
    case 32u: goto L_08A2BD7C;
    case 33u: goto L_08A2BD84;
    case 34u: goto L_08A2BD88;
    case 35u: goto L_08A2BD8C;
    case 36u: goto L_08A2BD90;
    case 37u: goto L_08A2BD94;
    case 38u: goto L_08A2BD98;
    case 39u: goto L_08A2BD9C;
    case 40u: goto L_08A2BDA0;
    case 41u: goto L_08A2BDA8;
    case 42u: goto L_08A2BDAC;
    case 43u: goto L_08A2BDB0;
    case 44u: goto L_08A2BDB4;
    case 45u: goto L_08A2BDBC;
    case 46u: goto L_08A2BDC0;
    case 47u: goto L_08A2BDC4;
    case 48u: goto L_08A2BDC8;
    case 49u: goto L_08A2BDCC;
    case 50u: goto L_08A2BDD0;
    case 51u: goto L_08A2BDD4;
    case 52u: goto L_08A2BDD8;
    case 53u: goto L_08A2BDE0;
    default:
        if (local_transfers == 0u) rt.unsupported(ctx.pc, 0u, "invalid internal function entry");
        else ctx.pc = local_pc;
        return;
    }
    }
L_08A2BCE4:
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(-16));
    goto L_08A2BCE8;
L_08A2BCE8:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(0), ctx.gpr[16]);
    goto L_08A2BCEC;
L_08A2BCEC:
    ctx.set_gpr(16, ctx.gpr[4] | 0u);
    goto L_08A2BCF0;
L_08A2BCF0:
    ctx.set_gpr(6, 1u << 16u);
    goto L_08A2BCF4;
L_08A2BCF4:
    ctx.set_gpr(4, ctx.gpr[16] + static_cast<std::uint32_t>(256));
    goto L_08A2BCF8;
L_08A2BCF8:
    ctx.set_gpr(5, 0u | 4u);
    goto L_08A2BCFC;
L_08A2BCFC:
    ctx.set_gpr(7, 0u | 85u);
    goto L_08A2BD00;
L_08A2BD00:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(4), ctx.gpr[31]);
    goto L_08A2BD04;
L_08A2BD04:
    ctx.set_gpr(31, 0x08A2BD0Cu);
    ctx.set_gpr(6, ctx.gpr[6] + static_cast<std::uint32_t>(4474));
    ctx.pc = 0x08864FF0u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08A2BD0Cu) goto L_08A2BD0C;
    return;
L_08A2BD0C:
    ctx.set_gpr(2, ctx.gpr[16] | 0u);
    goto L_08A2BD10;
L_08A2BD10:
    ctx.set_gpr(16, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(0)));
    goto L_08A2BD14;
L_08A2BD14:
    ctx.set_gpr(31, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(4)));
    goto L_08A2BD18;
L_08A2BD18:
    jump_target = ctx.gpr[31];
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(16));
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08A2BD20:
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(-16));
    goto L_08A2BD24;
L_08A2BD24:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(0), ctx.gpr[31]);
    goto L_08A2BD28;
L_08A2BD28:
    { const bool branch_taken = ctx.gpr[4] == 0u;
    ctx.set_gpr(5, ctx.gpr[5] & 1u);
      if (branch_taken) {
          goto L_08A2BD40;
      }
      goto L_08A2BD30;
    }
L_08A2BD30:
    { const bool branch_taken = ctx.gpr[5] == 0u;
    // nop
      if (branch_taken) {
          goto L_08A2BD40;
      }
      goto L_08A2BD38;
    }
L_08A2BD38:
    ctx.set_gpr(31, 0x08A2BD40u);
    // nop
    ctx.pc = 0x08992F04u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08A2BD40u) goto L_08A2BD40;
    return;
L_08A2BD40:
    ctx.set_gpr(31, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(0)));
    goto L_08A2BD44;
L_08A2BD44:
    jump_target = ctx.gpr[31];
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(16));
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08A2BD4C:
    ctx.set_gpr(4, 2206u << 16u);
    goto L_08A2BD50;
L_08A2BD50:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(30152)));
    goto L_08A2BD54;
L_08A2BD54:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(312)));
    goto L_08A2BD58;
L_08A2BD58:
    ctx.set_gpr(5, rt.memory().aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(5368)));
    goto L_08A2BD5C;
L_08A2BD5C:
    ctx.set_gpr(5, ctx.gpr[5] | 128u);
    goto L_08A2BD60;
L_08A2BD60:
    jump_target = ctx.gpr[31];
    rt.memory().aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(5368), ctx.gpr[5]);
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08A2BD68:
    ctx.set_gpr(4, 2206u << 16u);
    goto L_08A2BD6C;
L_08A2BD6C:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(30152)));
    goto L_08A2BD70;
L_08A2BD70:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(312)));
    goto L_08A2BD74;
L_08A2BD74:
    ctx.set_gpr(5, rt.memory().aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(5368)));
    goto L_08A2BD78;
L_08A2BD78:
    ctx.set_gpr(5, ctx.gpr[5] | 256u);
    goto L_08A2BD7C;
L_08A2BD7C:
    jump_target = ctx.gpr[31];
    rt.memory().aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(5368), ctx.gpr[5]);
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08A2BD84:
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(-16));
    goto L_08A2BD88;
L_08A2BD88:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(4), ctx.gpr[16]);
    goto L_08A2BD8C;
L_08A2BD8C:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(8), ctx.gpr[17]);
    goto L_08A2BD90;
L_08A2BD90:
    ctx.set_gpr(16, ctx.gpr[4] | 0u);
    goto L_08A2BD94;
L_08A2BD94:
    ctx.set_gpr(17, 2211u << 16u);
    goto L_08A2BD98;
L_08A2BD98:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[17] + static_cast<std::uint32_t>(-6036)));
    goto L_08A2BD9C;
L_08A2BD9C:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(12), ctx.gpr[31]);
    goto L_08A2BDA0;
L_08A2BDA0:
    ctx.set_gpr(31, 0x08A2BDA8u);
    ctx.set_gpr(5, 0u | 1u);
    ctx.pc = 0x08862C40u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08A2BDA8u) goto L_08A2BDA8;
    return;
L_08A2BDA8:
    ctx.set_gpr(5, ctx.gpr[2] | 0u);
    goto L_08A2BDAC;
L_08A2BDAC:
    ctx.set_gpr(4, 0u | 16384u);
    goto L_08A2BDB0;
L_08A2BDB0:
    ctx.set_gpr(6, ctx.gpr[4] < ctx.gpr[5] ? 1u : 0u);
    goto L_08A2BDB4;
L_08A2BDB4:
    { const bool branch_taken = ctx.gpr[6] == 0u;
    // nop
      if (branch_taken) {
          goto L_08A2BDC0;
      }
      goto L_08A2BDBC;
    }
L_08A2BDBC:
    ctx.set_gpr(4, ctx.gpr[5] | 0u);
    goto L_08A2BDC0;
L_08A2BDC0:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(0), ctx.gpr[5]);
    goto L_08A2BDC4;
L_08A2BDC4:
    ctx.set_gpr(5, ctx.gpr[4] | 0u);
    goto L_08A2BDC8;
L_08A2BDC8:
    ctx.set_gpr(8, 0u | 1u);
    goto L_08A2BDCC;
L_08A2BDCC:
    ctx.set_gpr(4, ctx.gpr[16] | 0u);
    goto L_08A2BDD0;
L_08A2BDD0:
    ctx.set_gpr(6, 0u | 0u);
    goto L_08A2BDD4;
L_08A2BDD4:
    ctx.set_gpr(7, 0u | 0u);
    goto L_08A2BDD8;
L_08A2BDD8:
    ctx.set_gpr(31, 0x08A2BDE0u);
    ctx.set_gpr(9, 0u | 0u);
    ctx.pc = 0x0885C6CCu;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08A2BDE0u) goto L_08A2BDE0;
    return;
L_08A2BDE0:
    ctx.set_gpr(16, ctx.gpr[2] | 0u);
    ctx.pc = 0x08A2BDE4u; return;
}

void sub_08A2BCE4(Runtime &rt, AllegrexContext &ctx) {
    auto aot_mem = rt.memory().aot_fast_view();
    sub_08A2BCE4_entry(rt, ctx, 0u, aot_mem);
}

static const std::uint16_t kEntryIds_sub_08A323E4[64] = {
    1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 10, 11, 12, 13, 0, 14, 15, 16, 0, 17, 0, 18, 0, 19, 20, 0, 21, 22, 23, 24, 0, 25,
    26, 0, 27, 28, 29, 30, 0, 31, 32, 0, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54,
};
void sub_08A323E4_entry(Runtime &rt, AllegrexContext &ctx, std::uint16_t direct_entry_id, GuestMemory::AotFastView &aot_mem) {
    std::uint32_t jump_target = 0u;
    std::uint32_t local_transfers = 0u;
    std::uint32_t local_pc = ctx.pc;
    std::uint32_t entry_id = direct_entry_id;
LOCAL_DISPATCH:
    {
    if (entry_id == 0u) {
        const std::uint32_t entry_delta = local_pc - 0x08A323E4u;
        entry_id = (entry_delta < 256u && (entry_delta & 3u) == 0u) ? kEntryIds_sub_08A323E4[entry_delta >> 2u] : 0u;
    }
    switch (entry_id) {
    case 1u: goto L_08A323E4;
    case 2u: goto L_08A323E8;
    case 3u: goto L_08A323EC;
    case 4u: goto L_08A323F0;
    case 5u: goto L_08A323F4;
    case 6u: goto L_08A323F8;
    case 7u: goto L_08A323FC;
    case 8u: goto L_08A32400;
    case 9u: goto L_08A32404;
    case 10u: goto L_08A3240C;
    case 11u: goto L_08A32410;
    case 12u: goto L_08A32414;
    case 13u: goto L_08A32418;
    case 14u: goto L_08A32420;
    case 15u: goto L_08A32424;
    case 16u: goto L_08A32428;
    case 17u: goto L_08A32430;
    case 18u: goto L_08A32438;
    case 19u: goto L_08A32440;
    case 20u: goto L_08A32444;
    case 21u: goto L_08A3244C;
    case 22u: goto L_08A32450;
    case 23u: goto L_08A32454;
    case 24u: goto L_08A32458;
    case 25u: goto L_08A32460;
    case 26u: goto L_08A32464;
    case 27u: goto L_08A3246C;
    case 28u: goto L_08A32470;
    case 29u: goto L_08A32474;
    case 30u: goto L_08A32478;
    case 31u: goto L_08A32480;
    case 32u: goto L_08A32484;
    case 33u: goto L_08A3248C;
    case 34u: goto L_08A32490;
    case 35u: goto L_08A32494;
    case 36u: goto L_08A32498;
    case 37u: goto L_08A3249C;
    case 38u: goto L_08A324A0;
    case 39u: goto L_08A324A4;
    case 40u: goto L_08A324A8;
    case 41u: goto L_08A324AC;
    case 42u: goto L_08A324B0;
    case 43u: goto L_08A324B4;
    case 44u: goto L_08A324B8;
    case 45u: goto L_08A324BC;
    case 46u: goto L_08A324C0;
    case 47u: goto L_08A324C4;
    case 48u: goto L_08A324C8;
    case 49u: goto L_08A324CC;
    case 50u: goto L_08A324D0;
    case 51u: goto L_08A324D4;
    case 52u: goto L_08A324D8;
    case 53u: goto L_08A324DC;
    case 54u: goto L_08A324E0;
    default:
        if (local_transfers == 0u) rt.unsupported(ctx.pc, 0u, "invalid internal function entry");
        else ctx.pc = local_pc;
        return;
    }
    }
L_08A323E4:
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(-16));
    goto L_08A323E8;
L_08A323E8:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(0), ctx.gpr[16]);
    goto L_08A323EC;
L_08A323EC:
    ctx.set_gpr(16, ctx.gpr[4] | 0u);
    goto L_08A323F0;
L_08A323F0:
    ctx.set_gpr(6, 1u << 16u);
    goto L_08A323F4;
L_08A323F4:
    ctx.set_gpr(4, ctx.gpr[16] + static_cast<std::uint32_t>(4));
    goto L_08A323F8;
L_08A323F8:
    ctx.set_gpr(5, 0u | 4u);
    goto L_08A323FC;
L_08A323FC:
    ctx.set_gpr(7, 0u | 79u);
    goto L_08A32400;
L_08A32400:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(4), ctx.gpr[31]);
    goto L_08A32404;
L_08A32404:
    ctx.set_gpr(31, 0x08A3240Cu);
    ctx.set_gpr(6, ctx.gpr[6] + static_cast<std::uint32_t>(4501));
    ctx.pc = 0x08864FF0u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08A3240Cu) goto L_08A3240C;
    return;
L_08A3240C:
    ctx.set_gpr(2, ctx.gpr[16] | 0u);
    goto L_08A32410;
L_08A32410:
    ctx.set_gpr(16, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(0)));
    goto L_08A32414;
L_08A32414:
    ctx.set_gpr(31, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(4)));
    goto L_08A32418;
L_08A32418:
    jump_target = ctx.gpr[31];
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(16));
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08A32420:
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(-16));
    goto L_08A32424;
L_08A32424:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(0), ctx.gpr[31]);
    goto L_08A32428;
L_08A32428:
    { const bool branch_taken = ctx.gpr[4] == 0u;
    ctx.set_gpr(5, ctx.gpr[5] & 1u);
      if (branch_taken) {
          goto L_08A32440;
      }
      goto L_08A32430;
    }
L_08A32430:
    { const bool branch_taken = ctx.gpr[5] == 0u;
    // nop
      if (branch_taken) {
          goto L_08A32440;
      }
      goto L_08A32438;
    }
L_08A32438:
    ctx.set_gpr(31, 0x08A32440u);
    // nop
    ctx.pc = 0x08992F04u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08A32440u) goto L_08A32440;
    return;
L_08A32440:
    ctx.set_gpr(31, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(0)));
    goto L_08A32444;
L_08A32444:
    jump_target = ctx.gpr[31];
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(16));
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08A3244C:
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(-16));
    goto L_08A32450;
L_08A32450:
    ctx.set_gpr(4, 2205u << 16u);
    goto L_08A32454;
L_08A32454:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(0), ctx.gpr[31]);
    goto L_08A32458;
L_08A32458:
    ctx.set_gpr(31, 0x08A32460u);
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(19912)));
    ctx.pc = 0x0885A398u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08A32460u) goto L_08A32460;
    return;
L_08A32460:
    ctx.set_gpr(31, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(0)));
    goto L_08A32464;
L_08A32464:
    jump_target = ctx.gpr[31];
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(16));
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08A3246C:
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(-16));
    goto L_08A32470;
L_08A32470:
    ctx.set_gpr(4, 2205u << 16u);
    goto L_08A32474;
L_08A32474:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(0), ctx.gpr[31]);
    goto L_08A32478;
L_08A32478:
    ctx.set_gpr(31, 0x08A32480u);
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(19912)));
    ctx.pc = 0x0885A41Cu;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08A32480u) goto L_08A32480;
    return;
L_08A32480:
    ctx.set_gpr(31, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(0)));
    goto L_08A32484;
L_08A32484:
    jump_target = ctx.gpr[31];
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(16));
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08A3248C:
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(-64));
    goto L_08A32490;
L_08A32490:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(28), ctx.gpr[18]);
    goto L_08A32494;
L_08A32494:
    ctx.set_gpr(18, ctx.gpr[4] | 0u);
    goto L_08A32498;
L_08A32498:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[5] + static_cast<std::uint32_t>(0)));
    goto L_08A3249C;
L_08A3249C:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(36), ctx.gpr[20]);
    goto L_08A324A0;
L_08A324A0:
    ctx.set_gpr(20, rt.memory().aot_load32(ctx.gpr[18] + static_cast<std::uint32_t>(1756)));
    goto L_08A324A4;
L_08A324A4:
    ctx.set_gpr(4, ctx.gpr[4] << 2u);
    goto L_08A324A8;
L_08A324A8:
    ctx.set_gpr(4, ctx.gpr[20] + ctx.gpr[4]);
    goto L_08A324AC;
L_08A324AC:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(1688)));
    goto L_08A324B0;
L_08A324B0:
    ctx.set_gpr(7, 0u | 0u);
    goto L_08A324B4;
L_08A324B4:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(12), ctx.gpr[4]);
    goto L_08A324B8;
L_08A324B8:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(0), ctx.gpr[7]);
    goto L_08A324BC;
L_08A324BC:
    ctx.set_gpr(7, 2205u << 16u);
    goto L_08A324C0;
L_08A324C0:
    ctx.set_gpr(7, rt.memory().aot_load32(ctx.gpr[7] + static_cast<std::uint32_t>(28972)));
    goto L_08A324C4;
L_08A324C4:
    ctx.set_gpr(4, 0u | 63200u);
    goto L_08A324C8;
L_08A324C8:
    ctx.set_gpr(4, ctx.gpr[7] + ctx.gpr[4]);
    goto L_08A324CC;
L_08A324CC:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(4), ctx.gpr[4]);
    goto L_08A324D0;
L_08A324D0:
    ctx.set_gpr(4, 2211u << 16u);
    goto L_08A324D4;
L_08A324D4:
    ctx.set_gpr(7, ctx.gpr[4] + static_cast<std::uint32_t>(22772));
    goto L_08A324D8;
L_08A324D8:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[20] + static_cast<std::uint32_t>(160)));
    goto L_08A324DC;
L_08A324DC:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(8), ctx.gpr[7]);
    goto L_08A324E0;
L_08A324E0:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(40), ctx.gpr[21]);
    ctx.pc = 0x08A324E4u; return;
}

void sub_08A323E4(Runtime &rt, AllegrexContext &ctx) {
    auto aot_mem = rt.memory().aot_fast_view();
    sub_08A323E4_entry(rt, ctx, 0u, aot_mem);
}

static const std::uint16_t kEntryIds_sub_08A42C1C[64] = {
    1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 10, 11, 12, 13, 0, 14, 15, 16, 0, 17, 0, 18, 0, 19, 20, 0, 21, 22, 23, 24, 25, 0,
    26, 27, 0, 28, 29, 30, 31, 32, 0, 33, 34, 0, 35, 36, 37, 38, 39, 40, 0, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 0, 52,
};
void sub_08A42C1C_entry(Runtime &rt, AllegrexContext &ctx, std::uint16_t direct_entry_id, GuestMemory::AotFastView &aot_mem) {
    std::uint32_t jump_target = 0u;
    std::uint32_t local_transfers = 0u;
    std::uint32_t local_pc = ctx.pc;
    std::uint32_t entry_id = direct_entry_id;
LOCAL_DISPATCH:
    {
    if (entry_id == 0u) {
        const std::uint32_t entry_delta = local_pc - 0x08A42C1Cu;
        entry_id = (entry_delta < 256u && (entry_delta & 3u) == 0u) ? kEntryIds_sub_08A42C1C[entry_delta >> 2u] : 0u;
    }
    switch (entry_id) {
    case 1u: goto L_08A42C1C;
    case 2u: goto L_08A42C20;
    case 3u: goto L_08A42C24;
    case 4u: goto L_08A42C28;
    case 5u: goto L_08A42C2C;
    case 6u: goto L_08A42C30;
    case 7u: goto L_08A42C34;
    case 8u: goto L_08A42C38;
    case 9u: goto L_08A42C3C;
    case 10u: goto L_08A42C44;
    case 11u: goto L_08A42C48;
    case 12u: goto L_08A42C4C;
    case 13u: goto L_08A42C50;
    case 14u: goto L_08A42C58;
    case 15u: goto L_08A42C5C;
    case 16u: goto L_08A42C60;
    case 17u: goto L_08A42C68;
    case 18u: goto L_08A42C70;
    case 19u: goto L_08A42C78;
    case 20u: goto L_08A42C7C;
    case 21u: goto L_08A42C84;
    case 22u: goto L_08A42C88;
    case 23u: goto L_08A42C8C;
    case 24u: goto L_08A42C90;
    case 25u: goto L_08A42C94;
    case 26u: goto L_08A42C9C;
    case 27u: goto L_08A42CA0;
    case 28u: goto L_08A42CA8;
    case 29u: goto L_08A42CAC;
    case 30u: goto L_08A42CB0;
    case 31u: goto L_08A42CB4;
    case 32u: goto L_08A42CB8;
    case 33u: goto L_08A42CC0;
    case 34u: goto L_08A42CC4;
    case 35u: goto L_08A42CCC;
    case 36u: goto L_08A42CD0;
    case 37u: goto L_08A42CD4;
    case 38u: goto L_08A42CD8;
    case 39u: goto L_08A42CDC;
    case 40u: goto L_08A42CE0;
    case 41u: goto L_08A42CE8;
    case 42u: goto L_08A42CEC;
    case 43u: goto L_08A42CF0;
    case 44u: goto L_08A42CF4;
    case 45u: goto L_08A42CF8;
    case 46u: goto L_08A42CFC;
    case 47u: goto L_08A42D00;
    case 48u: goto L_08A42D04;
    case 49u: goto L_08A42D08;
    case 50u: goto L_08A42D0C;
    case 51u: goto L_08A42D10;
    case 52u: goto L_08A42D18;
    default:
        if (local_transfers == 0u) rt.unsupported(ctx.pc, 0u, "invalid internal function entry");
        else ctx.pc = local_pc;
        return;
    }
    }
L_08A42C1C:
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(-16));
    goto L_08A42C20;
L_08A42C20:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(0), ctx.gpr[16]);
    goto L_08A42C24;
L_08A42C24:
    ctx.set_gpr(16, ctx.gpr[4] | 0u);
    goto L_08A42C28;
L_08A42C28:
    ctx.set_gpr(6, 1u << 16u);
    goto L_08A42C2C;
L_08A42C2C:
    ctx.set_gpr(4, ctx.gpr[16] + static_cast<std::uint32_t>(256));
    goto L_08A42C30;
L_08A42C30:
    ctx.set_gpr(5, 0u | 1u);
    goto L_08A42C34;
L_08A42C34:
    ctx.set_gpr(7, 0u | 83u);
    goto L_08A42C38;
L_08A42C38:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(4), ctx.gpr[31]);
    goto L_08A42C3C;
L_08A42C3C:
    ctx.set_gpr(31, 0x08A42C44u);
    ctx.set_gpr(6, ctx.gpr[6] + static_cast<std::uint32_t>(4478));
    ctx.pc = 0x08864FF0u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08A42C44u) goto L_08A42C44;
    return;
L_08A42C44:
    ctx.set_gpr(2, ctx.gpr[16] | 0u);
    goto L_08A42C48;
L_08A42C48:
    ctx.set_gpr(16, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(0)));
    goto L_08A42C4C;
L_08A42C4C:
    ctx.set_gpr(31, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(4)));
    goto L_08A42C50;
L_08A42C50:
    jump_target = ctx.gpr[31];
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(16));
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08A42C58:
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(-16));
    goto L_08A42C5C;
L_08A42C5C:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(0), ctx.gpr[31]);
    goto L_08A42C60;
L_08A42C60:
    { const bool branch_taken = ctx.gpr[4] == 0u;
    ctx.set_gpr(5, ctx.gpr[5] & 1u);
      if (branch_taken) {
          goto L_08A42C78;
      }
      goto L_08A42C68;
    }
L_08A42C68:
    { const bool branch_taken = ctx.gpr[5] == 0u;
    // nop
      if (branch_taken) {
          goto L_08A42C78;
      }
      goto L_08A42C70;
    }
L_08A42C70:
    ctx.set_gpr(31, 0x08A42C78u);
    // nop
    ctx.pc = 0x08992F04u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08A42C78u) goto L_08A42C78;
    return;
L_08A42C78:
    ctx.set_gpr(31, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(0)));
    goto L_08A42C7C;
L_08A42C7C:
    jump_target = ctx.gpr[31];
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(16));
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08A42C84:
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(-16));
    goto L_08A42C88;
L_08A42C88:
    ctx.set_gpr(4, 2212u << 16u);
    goto L_08A42C8C;
L_08A42C8C:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(22508)));
    goto L_08A42C90;
L_08A42C90:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(0), ctx.gpr[31]);
    goto L_08A42C94;
L_08A42C94:
    ctx.set_gpr(31, 0x08A42C9Cu);
    ctx.set_gpr(5, 0u + static_cast<std::uint32_t>(-1));
    ctx.pc = 0x08A40FE0u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08A42C9Cu) goto L_08A42C9C;
    return;
L_08A42C9C:
    ctx.set_gpr(31, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(0)));
    goto L_08A42CA0;
L_08A42CA0:
    jump_target = ctx.gpr[31];
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(16));
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08A42CA8:
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(-16));
    goto L_08A42CAC;
L_08A42CAC:
    ctx.set_gpr(4, 2212u << 16u);
    goto L_08A42CB0;
L_08A42CB0:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(22508)));
    goto L_08A42CB4;
L_08A42CB4:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(0), ctx.gpr[31]);
    goto L_08A42CB8;
L_08A42CB8:
    ctx.set_gpr(31, 0x08A42CC0u);
    ctx.set_gpr(5, 0u | 4u);
    ctx.pc = 0x08A40FE0u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08A42CC0u) goto L_08A42CC0;
    return;
L_08A42CC0:
    ctx.set_gpr(31, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(0)));
    goto L_08A42CC4;
L_08A42CC4:
    jump_target = ctx.gpr[31];
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(16));
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08A42CCC:
    ctx.set_gpr(4, 2212u << 16u);
    goto L_08A42CD0;
L_08A42CD0:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(22508)));
    goto L_08A42CD4;
L_08A42CD4:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(332)));
    goto L_08A42CD8;
L_08A42CD8:
    ctx.set_gpr(5, rt.memory().aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(3648)));
    goto L_08A42CDC;
L_08A42CDC:
    ctx.set_gpr(5, ctx.gpr[5] | 8u);
    goto L_08A42CE0;
L_08A42CE0:
    jump_target = ctx.gpr[31];
    rt.memory().aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(3648), ctx.gpr[5]);
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08A42CE8:
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(-32));
    goto L_08A42CEC;
L_08A42CEC:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(4), ctx.gpr[17]);
    goto L_08A42CF0;
L_08A42CF0:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(8), ctx.gpr[18]);
    goto L_08A42CF4;
L_08A42CF4:
    ctx.set_gpr(18, ctx.gpr[4] | 0u);
    goto L_08A42CF8;
L_08A42CF8:
    ctx.set_gpr(17, ctx.gpr[6] | 0u);
    goto L_08A42CFC;
L_08A42CFC:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(0), ctx.gpr[16]);
    goto L_08A42D00;
L_08A42D00:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(12), ctx.gpr[19]);
    goto L_08A42D04;
L_08A42D04:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(16), ctx.gpr[20]);
    goto L_08A42D08;
L_08A42D08:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(20), ctx.gpr[21]);
    goto L_08A42D0C;
L_08A42D0C:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(24), ctx.gpr[31]);
    goto L_08A42D10;
L_08A42D10:
    { const bool branch_taken = ctx.gpr[7] == 0u;
    ctx.set_gpr(16, ctx.gpr[7] | 0u);
      if (branch_taken) {
          ctx.pc = 0x08A42D30u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
      }
      goto L_08A42D18;
    }
L_08A42D18:
    ctx.set_gpr(21, 0u | 0u);
    ctx.pc = 0x08A42D1Cu; return;
}

void sub_08A42C1C(Runtime &rt, AllegrexContext &ctx) {
    auto aot_mem = rt.memory().aot_fast_view();
    sub_08A42C1C_entry(rt, ctx, 0u, aot_mem);
}

static const std::uint16_t kEntryIds_sub_08A436C0[64] = {
    1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 10, 11, 12, 13, 0, 14, 15, 16, 0, 17, 0, 18, 0, 19, 20, 0, 21, 22, 23, 24, 25, 26,
    27, 28, 29, 30, 31, 0, 32, 33, 34, 35, 36, 0, 37, 0, 38, 0, 39, 40, 41, 42, 43, 44, 0, 45, 46, 0, 47, 0, 48, 0, 49, 50,
};
void sub_08A436C0_entry(Runtime &rt, AllegrexContext &ctx, std::uint16_t direct_entry_id, GuestMemory::AotFastView &aot_mem) {
    std::uint32_t jump_target = 0u;
    std::uint32_t local_transfers = 0u;
    std::uint32_t local_pc = ctx.pc;
    std::uint32_t entry_id = direct_entry_id;
LOCAL_DISPATCH:
    {
    if (entry_id == 0u) {
        const std::uint32_t entry_delta = local_pc - 0x08A436C0u;
        entry_id = (entry_delta < 256u && (entry_delta & 3u) == 0u) ? kEntryIds_sub_08A436C0[entry_delta >> 2u] : 0u;
    }
    switch (entry_id) {
    case 1u: goto L_08A436C0;
    case 2u: goto L_08A436C4;
    case 3u: goto L_08A436C8;
    case 4u: goto L_08A436CC;
    case 5u: goto L_08A436D0;
    case 6u: goto L_08A436D4;
    case 7u: goto L_08A436D8;
    case 8u: goto L_08A436DC;
    case 9u: goto L_08A436E0;
    case 10u: goto L_08A436E8;
    case 11u: goto L_08A436EC;
    case 12u: goto L_08A436F0;
    case 13u: goto L_08A436F4;
    case 14u: goto L_08A436FC;
    case 15u: goto L_08A43700;
    case 16u: goto L_08A43704;
    case 17u: goto L_08A4370C;
    case 18u: goto L_08A43714;
    case 19u: goto L_08A4371C;
    case 20u: goto L_08A43720;
    case 21u: goto L_08A43728;
    case 22u: goto L_08A4372C;
    case 23u: goto L_08A43730;
    case 24u: goto L_08A43734;
    case 25u: goto L_08A43738;
    case 26u: goto L_08A4373C;
    case 27u: goto L_08A43740;
    case 28u: goto L_08A43744;
    case 29u: goto L_08A43748;
    case 30u: goto L_08A4374C;
    case 31u: goto L_08A43750;
    case 32u: goto L_08A43758;
    case 33u: goto L_08A4375C;
    case 34u: goto L_08A43760;
    case 35u: goto L_08A43764;
    case 36u: goto L_08A43768;
    case 37u: goto L_08A43770;
    case 38u: goto L_08A43778;
    case 39u: goto L_08A43780;
    case 40u: goto L_08A43784;
    case 41u: goto L_08A43788;
    case 42u: goto L_08A4378C;
    case 43u: goto L_08A43790;
    case 44u: goto L_08A43794;
    case 45u: goto L_08A4379C;
    case 46u: goto L_08A437A0;
    case 47u: goto L_08A437A8;
    case 48u: goto L_08A437B0;
    case 49u: goto L_08A437B8;
    case 50u: goto L_08A437BC;
    default:
        if (local_transfers == 0u) rt.unsupported(ctx.pc, 0u, "invalid internal function entry");
        else ctx.pc = local_pc;
        return;
    }
    }
L_08A436C0:
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(-16));
    goto L_08A436C4;
L_08A436C4:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(0), ctx.gpr[16]);
    goto L_08A436C8;
L_08A436C8:
    ctx.set_gpr(16, ctx.gpr[4] | 0u);
    goto L_08A436CC;
L_08A436CC:
    ctx.set_gpr(6, 1u << 16u);
    goto L_08A436D0;
L_08A436D0:
    ctx.set_gpr(4, ctx.gpr[16] + static_cast<std::uint32_t>(256));
    goto L_08A436D4;
L_08A436D4:
    ctx.set_gpr(5, 0u | 4u);
    goto L_08A436D8;
L_08A436D8:
    ctx.set_gpr(7, 0u | 69u);
    goto L_08A436DC;
L_08A436DC:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(4), ctx.gpr[31]);
    goto L_08A436E0;
L_08A436E0:
    ctx.set_gpr(31, 0x08A436E8u);
    ctx.set_gpr(6, ctx.gpr[6] + static_cast<std::uint32_t>(4478));
    ctx.pc = 0x08864FF0u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08A436E8u) goto L_08A436E8;
    return;
L_08A436E8:
    ctx.set_gpr(2, ctx.gpr[16] | 0u);
    goto L_08A436EC;
L_08A436EC:
    ctx.set_gpr(16, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(0)));
    goto L_08A436F0;
L_08A436F0:
    ctx.set_gpr(31, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(4)));
    goto L_08A436F4;
L_08A436F4:
    jump_target = ctx.gpr[31];
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(16));
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08A436FC:
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(-16));
    goto L_08A43700;
L_08A43700:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(0), ctx.gpr[31]);
    goto L_08A43704;
L_08A43704:
    { const bool branch_taken = ctx.gpr[4] == 0u;
    ctx.set_gpr(5, ctx.gpr[5] & 1u);
      if (branch_taken) {
          goto L_08A4371C;
      }
      goto L_08A4370C;
    }
L_08A4370C:
    { const bool branch_taken = ctx.gpr[5] == 0u;
    // nop
      if (branch_taken) {
          goto L_08A4371C;
      }
      goto L_08A43714;
    }
L_08A43714:
    ctx.set_gpr(31, 0x08A4371Cu);
    // nop
    ctx.pc = 0x08992F04u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08A4371Cu) goto L_08A4371C;
    return;
L_08A4371C:
    ctx.set_gpr(31, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(0)));
    goto L_08A43720;
L_08A43720:
    jump_target = ctx.gpr[31];
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(16));
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08A43728:
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(-32));
    goto L_08A4372C;
L_08A4372C:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(0), ctx.gpr[16]);
    goto L_08A43730;
L_08A43730:
    ctx.set_gpr(16, ctx.gpr[4] | 0u);
    goto L_08A43734;
L_08A43734:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[16] + static_cast<std::uint32_t>(332)));
    goto L_08A43738;
L_08A43738:
    ctx.set_gpr(5, rt.memory().aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(3660)));
    goto L_08A4373C;
L_08A4373C:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(4), ctx.gpr[17]);
    goto L_08A43740;
L_08A43740:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(8), ctx.gpr[18]);
    goto L_08A43744;
L_08A43744:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(12), ctx.gpr[19]);
    goto L_08A43748;
L_08A43748:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(16), ctx.gpr[20]);
    goto L_08A4374C;
L_08A4374C:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(20), ctx.gpr[31]);
    goto L_08A43750;
L_08A43750:
    { const bool branch_taken = static_cast<std::int32_t>(ctx.gpr[5]) <= 0;
    // nop
      if (branch_taken) {
          goto L_08A43780;
      }
      goto L_08A43758;
    }
L_08A43758:
    ctx.set_gpr(5, ctx.gpr[5] + static_cast<std::uint32_t>(-1));
    goto L_08A4375C;
L_08A4375C:
    rt.memory().aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(3660), ctx.gpr[5]);
    goto L_08A43760;
L_08A43760:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[16] + static_cast<std::uint32_t>(332)));
    goto L_08A43764;
L_08A43764:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(3660)));
    goto L_08A43768;
L_08A43768:
    { const bool branch_taken = ctx.gpr[4] != 0u;
    // nop
      if (branch_taken) {
          goto L_08A43778;
      }
      goto L_08A43770;
    }
L_08A43770:
    { const bool branch_taken = 0u == 0u;
    ctx.set_gpr(2, 0u | 1u);
      if (branch_taken) {
          ctx.pc = 0x08A43A7Cu; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
      }
      goto L_08A43778;
    }
L_08A43778:
    { const bool branch_taken = 0u == 0u;
    ctx.set_gpr(2, 0u | 0u);
      if (branch_taken) {
          ctx.pc = 0x08A43A7Cu; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
      }
      goto L_08A43780;
    }
L_08A43780:
    ctx.set_gpr(19, ctx.gpr[4] + static_cast<std::uint32_t>(1024));
    goto L_08A43784;
L_08A43784:
    ctx.set_gpr(5, rt.memory().aot_load32(ctx.gpr[19] + static_cast<std::uint32_t>(84)));
    goto L_08A43788;
L_08A43788:
    ctx.set_gpr(17, 0u | 0u);
    goto L_08A4378C;
L_08A4378C:
    ctx.set_gpr(6, static_cast<std::uint32_t>(static_cast<std::int32_t>(static_cast<std::int16_t>(rt.memory().aot_load16(ctx.gpr[5] + static_cast<std::uint32_t>(12))))));
    goto L_08A43790;
L_08A43790:
    ctx.set_gpr(7, 0u | 5u);
    goto L_08A43794;
L_08A43794:
    { const bool branch_taken = ctx.gpr[6] == ctx.gpr[7];
    ctx.set_gpr(18, 0u | 0u);
      if (branch_taken) {
          goto L_08A437B8;
      }
      goto L_08A4379C;
    }
L_08A4379C:
    ctx.set_gpr(20, 0u | 3u);
    goto L_08A437A0;
L_08A437A0:
    { const bool branch_taken = ctx.gpr[6] == ctx.gpr[20];
    ctx.set_gpr(7, 0u + static_cast<std::uint32_t>(-1));
      if (branch_taken) {
          ctx.pc = 0x08A43824u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
      }
      goto L_08A437A8;
    }
L_08A437A8:
    { const bool branch_taken = ctx.gpr[6] == ctx.gpr[7];
    // nop
      if (branch_taken) {
          ctx.pc = 0x08A43980u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
      }
      goto L_08A437B0;
    }
L_08A437B0:
    { const bool branch_taken = 0u == 0u;
    // nop
      if (branch_taken) {
          ctx.pc = 0x08A439B0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
      }
      goto L_08A437B8;
    }
L_08A437B8:
    ctx.set_gpr(6, rt.memory().aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(1108)));
    goto L_08A437BC;
L_08A437BC:
    ctx.set_gpr(6, rt.memory().aot_load16(ctx.gpr[6] + static_cast<std::uint32_t>(32)));
    ctx.pc = 0x08A437C0u; return;
}

void sub_08A436C0(Runtime &rt, AllegrexContext &ctx) {
    auto aot_mem = rt.memory().aot_fast_view();
    sub_08A436C0_entry(rt, ctx, 0u, aot_mem);
}

static const std::uint16_t kEntryIds_sub_08A4ABFC[63] = {
    1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 10, 11, 12, 13, 0, 14, 15, 16, 0, 17, 0, 18, 0, 19, 20, 0, 21, 22, 23, 24, 0, 25,
    26, 27, 0, 28, 29, 0, 30, 31, 32, 33, 0, 34, 35, 36, 0, 37, 38, 0, 39, 40, 41, 42, 43, 44, 0, 45, 46, 47, 48, 49, 50,
};
void sub_08A4ABFC_entry(Runtime &rt, AllegrexContext &ctx, std::uint16_t direct_entry_id, GuestMemory::AotFastView &aot_mem) {
    std::uint32_t jump_target = 0u;
    std::uint32_t local_transfers = 0u;
    std::uint32_t local_pc = ctx.pc;
    std::uint32_t entry_id = direct_entry_id;
LOCAL_DISPATCH:
    {
    if (entry_id == 0u) {
        const std::uint32_t entry_delta = local_pc - 0x08A4ABFCu;
        entry_id = (entry_delta < 252u && (entry_delta & 3u) == 0u) ? kEntryIds_sub_08A4ABFC[entry_delta >> 2u] : 0u;
    }
    switch (entry_id) {
    case 1u: goto L_08A4ABFC;
    case 2u: goto L_08A4AC00;
    case 3u: goto L_08A4AC04;
    case 4u: goto L_08A4AC08;
    case 5u: goto L_08A4AC0C;
    case 6u: goto L_08A4AC10;
    case 7u: goto L_08A4AC14;
    case 8u: goto L_08A4AC18;
    case 9u: goto L_08A4AC1C;
    case 10u: goto L_08A4AC24;
    case 11u: goto L_08A4AC28;
    case 12u: goto L_08A4AC2C;
    case 13u: goto L_08A4AC30;
    case 14u: goto L_08A4AC38;
    case 15u: goto L_08A4AC3C;
    case 16u: goto L_08A4AC40;
    case 17u: goto L_08A4AC48;
    case 18u: goto L_08A4AC50;
    case 19u: goto L_08A4AC58;
    case 20u: goto L_08A4AC5C;
    case 21u: goto L_08A4AC64;
    case 22u: goto L_08A4AC68;
    case 23u: goto L_08A4AC6C;
    case 24u: goto L_08A4AC70;
    case 25u: goto L_08A4AC78;
    case 26u: goto L_08A4AC7C;
    case 27u: goto L_08A4AC80;
    case 28u: goto L_08A4AC88;
    case 29u: goto L_08A4AC8C;
    case 30u: goto L_08A4AC94;
    case 31u: goto L_08A4AC98;
    case 32u: goto L_08A4AC9C;
    case 33u: goto L_08A4ACA0;
    case 34u: goto L_08A4ACA8;
    case 35u: goto L_08A4ACAC;
    case 36u: goto L_08A4ACB0;
    case 37u: goto L_08A4ACB8;
    case 38u: goto L_08A4ACBC;
    case 39u: goto L_08A4ACC4;
    case 40u: goto L_08A4ACC8;
    case 41u: goto L_08A4ACCC;
    case 42u: goto L_08A4ACD0;
    case 43u: goto L_08A4ACD4;
    case 44u: goto L_08A4ACD8;
    case 45u: goto L_08A4ACE0;
    case 46u: goto L_08A4ACE4;
    case 47u: goto L_08A4ACE8;
    case 48u: goto L_08A4ACEC;
    case 49u: goto L_08A4ACF0;
    case 50u: goto L_08A4ACF4;
    default:
        if (local_transfers == 0u) rt.unsupported(ctx.pc, 0u, "invalid internal function entry");
        else ctx.pc = local_pc;
        return;
    }
    }
L_08A4ABFC:
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(-16));
    goto L_08A4AC00;
L_08A4AC00:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(0), ctx.gpr[16]);
    goto L_08A4AC04;
L_08A4AC04:
    ctx.set_gpr(16, ctx.gpr[4] | 0u);
    goto L_08A4AC08;
L_08A4AC08:
    ctx.set_gpr(6, 1u << 16u);
    goto L_08A4AC0C;
L_08A4AC0C:
    ctx.set_gpr(4, ctx.gpr[16] + static_cast<std::uint32_t>(256));
    goto L_08A4AC10;
L_08A4AC10:
    ctx.set_gpr(5, 0u | 1u);
    goto L_08A4AC14;
L_08A4AC14:
    ctx.set_gpr(7, 0u | 76u);
    goto L_08A4AC18;
L_08A4AC18:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(4), ctx.gpr[31]);
    goto L_08A4AC1C;
L_08A4AC1C:
    ctx.set_gpr(31, 0x08A4AC24u);
    ctx.set_gpr(6, ctx.gpr[6] + static_cast<std::uint32_t>(4479));
    ctx.pc = 0x08864FF0u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08A4AC24u) goto L_08A4AC24;
    return;
L_08A4AC24:
    ctx.set_gpr(2, ctx.gpr[16] | 0u);
    goto L_08A4AC28;
L_08A4AC28:
    ctx.set_gpr(16, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(0)));
    goto L_08A4AC2C;
L_08A4AC2C:
    ctx.set_gpr(31, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(4)));
    goto L_08A4AC30;
L_08A4AC30:
    jump_target = ctx.gpr[31];
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(16));
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08A4AC38:
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(-16));
    goto L_08A4AC3C;
L_08A4AC3C:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(0), ctx.gpr[31]);
    goto L_08A4AC40;
L_08A4AC40:
    { const bool branch_taken = ctx.gpr[4] == 0u;
    ctx.set_gpr(5, ctx.gpr[5] & 1u);
      if (branch_taken) {
          goto L_08A4AC58;
      }
      goto L_08A4AC48;
    }
L_08A4AC48:
    { const bool branch_taken = ctx.gpr[5] == 0u;
    // nop
      if (branch_taken) {
          goto L_08A4AC58;
      }
      goto L_08A4AC50;
    }
L_08A4AC50:
    ctx.set_gpr(31, 0x08A4AC58u);
    // nop
    ctx.pc = 0x08992F04u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08A4AC58u) goto L_08A4AC58;
    return;
L_08A4AC58:
    ctx.set_gpr(31, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(0)));
    goto L_08A4AC5C;
L_08A4AC5C:
    jump_target = ctx.gpr[31];
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(16));
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08A4AC64:
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(-16));
    goto L_08A4AC68;
L_08A4AC68:
    ctx.set_gpr(4, 2206u << 16u);
    goto L_08A4AC6C;
L_08A4AC6C:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(0), ctx.gpr[31]);
    goto L_08A4AC70;
L_08A4AC70:
    ctx.set_gpr(31, 0x08A4AC78u);
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(-31440)));
    ctx.pc = 0x08927458u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08A4AC78u) goto L_08A4AC78;
    return;
L_08A4AC78:
    ctx.set_gpr(4, 2213u << 16u);
    goto L_08A4AC7C;
L_08A4AC7C:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(-16132)));
    goto L_08A4AC80;
L_08A4AC80:
    ctx.set_gpr(31, 0x08A4AC88u);
    ctx.set_gpr(5, 0u | 0u);
    ctx.pc = 0x08A49BDCu;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08A4AC88u) goto L_08A4AC88;
    return;
L_08A4AC88:
    ctx.set_gpr(31, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(0)));
    goto L_08A4AC8C;
L_08A4AC8C:
    jump_target = ctx.gpr[31];
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(16));
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08A4AC94:
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(-16));
    goto L_08A4AC98;
L_08A4AC98:
    ctx.set_gpr(4, 2206u << 16u);
    goto L_08A4AC9C;
L_08A4AC9C:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(0), ctx.gpr[31]);
    goto L_08A4ACA0;
L_08A4ACA0:
    ctx.set_gpr(31, 0x08A4ACA8u);
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(-31440)));
    ctx.pc = 0x089274E4u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08A4ACA8u) goto L_08A4ACA8;
    return;
L_08A4ACA8:
    ctx.set_gpr(4, 2206u << 16u);
    goto L_08A4ACAC;
L_08A4ACAC:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(30148)));
    goto L_08A4ACB0;
L_08A4ACB0:
    ctx.set_gpr(31, 0x08A4ACB8u);
    ctx.set_gpr(5, 0u | 0u);
    ctx.pc = 0x089E0BDCu;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08A4ACB8u) goto L_08A4ACB8;
    return;
L_08A4ACB8:
    ctx.set_gpr(31, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(0)));
    goto L_08A4ACBC;
L_08A4ACBC:
    jump_target = ctx.gpr[31];
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(16));
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08A4ACC4:
    ctx.set_gpr(4, 2213u << 16u);
    goto L_08A4ACC8;
L_08A4ACC8:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(-16132)));
    goto L_08A4ACCC;
L_08A4ACCC:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(332)));
    goto L_08A4ACD0;
L_08A4ACD0:
    ctx.set_gpr(5, rt.memory().aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(2688)));
    goto L_08A4ACD4;
L_08A4ACD4:
    ctx.set_gpr(5, ctx.gpr[5] | 2u);
    goto L_08A4ACD8;
L_08A4ACD8:
    jump_target = ctx.gpr[31];
    rt.memory().aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(2688), ctx.gpr[5]);
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08A4ACE0:
    ctx.set_gpr(4, 2213u << 16u);
    goto L_08A4ACE4;
L_08A4ACE4:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(-16132)));
    goto L_08A4ACE8;
L_08A4ACE8:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(332)));
    goto L_08A4ACEC;
L_08A4ACEC:
    ctx.set_gpr(5, rt.memory().aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(2688)));
    goto L_08A4ACF0;
L_08A4ACF0:
    ctx.set_gpr(5, ctx.gpr[5] | 4u);
    goto L_08A4ACF4;
L_08A4ACF4:
    jump_target = ctx.gpr[31];
    rt.memory().aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(2688), ctx.gpr[5]);
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
}

void sub_08A4ABFC(Runtime &rt, AllegrexContext &ctx) {
    auto aot_mem = rt.memory().aot_fast_view();
    sub_08A4ABFC_entry(rt, ctx, 0u, aot_mem);
}

static const std::uint16_t kEntryIds_sub_08A4D4DC[64] = {
    1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 0, 28, 29, 30,
    0, 31, 0, 32, 0, 33, 34, 0, 35, 36, 37, 38, 39, 40, 41, 0, 42, 43, 0, 44, 45, 46, 47, 48, 49, 0, 50, 51, 0, 52, 53, 54,
};
void sub_08A4D4DC_entry(Runtime &rt, AllegrexContext &ctx, std::uint16_t direct_entry_id, GuestMemory::AotFastView &aot_mem) {
    std::uint32_t jump_target = 0u;
    std::uint32_t local_transfers = 0u;
    std::uint32_t local_pc = ctx.pc;
    std::uint32_t entry_id = direct_entry_id;
LOCAL_DISPATCH:
    {
    if (entry_id == 0u) {
        const std::uint32_t entry_delta = local_pc - 0x08A4D4DCu;
        entry_id = (entry_delta < 256u && (entry_delta & 3u) == 0u) ? kEntryIds_sub_08A4D4DC[entry_delta >> 2u] : 0u;
    }
    switch (entry_id) {
    case 1u: goto L_08A4D4DC;
    case 2u: goto L_08A4D4E0;
    case 3u: goto L_08A4D4E4;
    case 4u: goto L_08A4D4E8;
    case 5u: goto L_08A4D4EC;
    case 6u: goto L_08A4D4F0;
    case 7u: goto L_08A4D4F4;
    case 8u: goto L_08A4D4F8;
    case 9u: goto L_08A4D4FC;
    case 10u: goto L_08A4D504;
    case 11u: goto L_08A4D508;
    case 12u: goto L_08A4D50C;
    case 13u: goto L_08A4D510;
    case 14u: goto L_08A4D514;
    case 15u: goto L_08A4D518;
    case 16u: goto L_08A4D51C;
    case 17u: goto L_08A4D520;
    case 18u: goto L_08A4D524;
    case 19u: goto L_08A4D528;
    case 20u: goto L_08A4D52C;
    case 21u: goto L_08A4D530;
    case 22u: goto L_08A4D534;
    case 23u: goto L_08A4D538;
    case 24u: goto L_08A4D53C;
    case 25u: goto L_08A4D540;
    case 26u: goto L_08A4D544;
    case 27u: goto L_08A4D548;
    case 28u: goto L_08A4D550;
    case 29u: goto L_08A4D554;
    case 30u: goto L_08A4D558;
    case 31u: goto L_08A4D560;
    case 32u: goto L_08A4D568;
    case 33u: goto L_08A4D570;
    case 34u: goto L_08A4D574;
    case 35u: goto L_08A4D57C;
    case 36u: goto L_08A4D580;
    case 37u: goto L_08A4D584;
    case 38u: goto L_08A4D588;
    case 39u: goto L_08A4D58C;
    case 40u: goto L_08A4D590;
    case 41u: goto L_08A4D594;
    case 42u: goto L_08A4D59C;
    case 43u: goto L_08A4D5A0;
    case 44u: goto L_08A4D5A8;
    case 45u: goto L_08A4D5AC;
    case 46u: goto L_08A4D5B0;
    case 47u: goto L_08A4D5B4;
    case 48u: goto L_08A4D5B8;
    case 49u: goto L_08A4D5BC;
    case 50u: goto L_08A4D5C4;
    case 51u: goto L_08A4D5C8;
    case 52u: goto L_08A4D5D0;
    case 53u: goto L_08A4D5D4;
    case 54u: goto L_08A4D5D8;
    default:
        if (local_transfers == 0u) rt.unsupported(ctx.pc, 0u, "invalid internal function entry");
        else ctx.pc = local_pc;
        return;
    }
    }
L_08A4D4DC:
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(-16));
    goto L_08A4D4E0;
L_08A4D4E0:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(0), ctx.gpr[16]);
    goto L_08A4D4E4;
L_08A4D4E4:
    ctx.set_gpr(16, ctx.gpr[4] | 0u);
    goto L_08A4D4E8;
L_08A4D4E8:
    ctx.set_gpr(6, 1u << 16u);
    goto L_08A4D4EC;
L_08A4D4EC:
    ctx.set_gpr(4, ctx.gpr[16] + static_cast<std::uint32_t>(4));
    goto L_08A4D4F0;
L_08A4D4F0:
    ctx.set_gpr(5, 0u | 1u);
    goto L_08A4D4F4;
L_08A4D4F4:
    ctx.set_gpr(7, 0u | 76u);
    goto L_08A4D4F8;
L_08A4D4F8:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(4), ctx.gpr[31]);
    goto L_08A4D4FC;
L_08A4D4FC:
    ctx.set_gpr(31, 0x08A4D504u);
    ctx.set_gpr(6, ctx.gpr[6] + static_cast<std::uint32_t>(4480));
    ctx.pc = 0x08864FF0u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08A4D504u) goto L_08A4D504;
    return;
L_08A4D504:
    ctx.set_gpr(4, 2487u << 16u);
    goto L_08A4D508;
L_08A4D508:
    ctx.set_gpr(5, ctx.gpr[4] + static_cast<std::uint32_t>(-8984));
    goto L_08A4D50C;
L_08A4D50C:
    rt.memory().aot_store8(ctx.gpr[5] + static_cast<std::uint32_t>(17), static_cast<std::uint8_t>(0u));
    goto L_08A4D510;
L_08A4D510:
    rt.memory().aot_store8(ctx.gpr[5] + static_cast<std::uint32_t>(18), static_cast<std::uint8_t>(0u));
    goto L_08A4D514;
L_08A4D514:
    rt.memory().aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(-8984), 0u);
    goto L_08A4D518;
L_08A4D518:
    ctx.set_gpr(4, 0u | 1u);
    goto L_08A4D51C;
L_08A4D51C:
    rt.memory().aot_store8(ctx.gpr[5] + static_cast<std::uint32_t>(16), static_cast<std::uint8_t>(ctx.gpr[4]));
    goto L_08A4D520;
L_08A4D520:
    rt.memory().aot_store32(ctx.gpr[5] + static_cast<std::uint32_t>(4), 0u);
    goto L_08A4D524;
L_08A4D524:
    rt.memory().aot_store8(ctx.gpr[5] + static_cast<std::uint32_t>(19), static_cast<std::uint8_t>(0u));
    goto L_08A4D528;
L_08A4D528:
    rt.memory().aot_store8(ctx.gpr[5] + static_cast<std::uint32_t>(20), static_cast<std::uint8_t>(0u));
    goto L_08A4D52C;
L_08A4D52C:
    rt.memory().aot_store8(ctx.gpr[5] + static_cast<std::uint32_t>(21), static_cast<std::uint8_t>(0u));
    goto L_08A4D530;
L_08A4D530:
    rt.memory().aot_store32(ctx.gpr[16] + static_cast<std::uint32_t>(0), 0u);
    goto L_08A4D534;
L_08A4D534:
    rt.memory().aot_store32(ctx.gpr[16] + static_cast<std::uint32_t>(72), 0u);
    goto L_08A4D538;
L_08A4D538:
    rt.memory().aot_store32(ctx.gpr[16] + static_cast<std::uint32_t>(64), 0u);
    goto L_08A4D53C;
L_08A4D53C:
    ctx.set_gpr(2, ctx.gpr[16] | 0u);
    goto L_08A4D540;
L_08A4D540:
    ctx.set_gpr(16, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(0)));
    goto L_08A4D544;
L_08A4D544:
    ctx.set_gpr(31, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(4)));
    goto L_08A4D548;
L_08A4D548:
    jump_target = ctx.gpr[31];
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(16));
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08A4D550:
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(-16));
    goto L_08A4D554;
L_08A4D554:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(0), ctx.gpr[31]);
    goto L_08A4D558;
L_08A4D558:
    { const bool branch_taken = ctx.gpr[4] == 0u;
    ctx.set_gpr(5, ctx.gpr[5] & 1u);
      if (branch_taken) {
          goto L_08A4D570;
      }
      goto L_08A4D560;
    }
L_08A4D560:
    { const bool branch_taken = ctx.gpr[5] == 0u;
    // nop
      if (branch_taken) {
          goto L_08A4D570;
      }
      goto L_08A4D568;
    }
L_08A4D568:
    ctx.set_gpr(31, 0x08A4D570u);
    // nop
    ctx.pc = 0x08992F04u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08A4D570u) goto L_08A4D570;
    return;
L_08A4D570:
    ctx.set_gpr(31, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(0)));
    goto L_08A4D574;
L_08A4D574:
    jump_target = ctx.gpr[31];
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(16));
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08A4D57C:
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(-16));
    goto L_08A4D580;
L_08A4D580:
    ctx.set_gpr(6, 2213u << 16u);
    goto L_08A4D584;
L_08A4D584:
    ctx.set_gpr(7, rt.memory().aot_load32(ctx.gpr[6] + static_cast<std::uint32_t>(-12)));
    goto L_08A4D588;
L_08A4D588:
    ctx.set_gpr(5, ctx.gpr[4] & 255u);
    goto L_08A4D58C;
L_08A4D58C:
    rt.memory().aot_store32(ctx.gpr[7] + static_cast<std::uint32_t>(68), 0u);
    goto L_08A4D590;
L_08A4D590:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(0), ctx.gpr[31]);
    goto L_08A4D594;
L_08A4D594:
    ctx.set_gpr(31, 0x08A4D59Cu);
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[6] + static_cast<std::uint32_t>(-12)));
    ctx.pc = 0x08A4C2B8u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08A4D59Cu) goto L_08A4D59C;
    return;
L_08A4D59C:
    ctx.set_gpr(31, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(0)));
    goto L_08A4D5A0;
L_08A4D5A0:
    jump_target = ctx.gpr[31];
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(16));
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08A4D5A8:
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(-16));
    goto L_08A4D5AC;
L_08A4D5AC:
    ctx.set_gpr(5, 2213u << 16u);
    goto L_08A4D5B0;
L_08A4D5B0:
    ctx.set_gpr(6, rt.memory().aot_load32(ctx.gpr[5] + static_cast<std::uint32_t>(-12)));
    goto L_08A4D5B4;
L_08A4D5B4:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(0), ctx.gpr[31]);
    goto L_08A4D5B8;
L_08A4D5B8:
    rt.memory().aot_store32(ctx.gpr[6] + static_cast<std::uint32_t>(68), ctx.gpr[4]);
    goto L_08A4D5BC;
L_08A4D5BC:
    ctx.set_gpr(31, 0x08A4D5C4u);
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[5] + static_cast<std::uint32_t>(-12)));
    ctx.pc = 0x08A4C304u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08A4D5C4u) goto L_08A4D5C4;
    return;
L_08A4D5C4:
    ctx.set_gpr(31, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(0)));
    goto L_08A4D5C8;
L_08A4D5C8:
    jump_target = ctx.gpr[31];
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(16));
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08A4D5D0:
    ctx.set_gpr(4, 2213u << 16u);
    goto L_08A4D5D4;
L_08A4D5D4:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(-12)));
    goto L_08A4D5D8;
L_08A4D5D8:
    ctx.set_gpr(5, 0u + static_cast<std::uint32_t>(-3));
    ctx.pc = 0x08A4D5DCu; return;
}

void sub_08A4D4DC(Runtime &rt, AllegrexContext &ctx) {
    auto aot_mem = rt.memory().aot_fast_view();
    sub_08A4D4DC_entry(rt, ctx, 0u, aot_mem);
}

static const std::uint16_t kEntryIds_sub_08A500A8[64] = {
    1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 10, 0, 11, 12, 13, 14, 0, 15, 16, 17, 0, 18, 0, 19, 0, 20, 21, 0, 22, 23, 24, 25,
    26, 27, 0, 28, 29, 30, 31, 32, 33, 34, 0, 35, 36, 0, 37, 38, 39, 40, 41, 42, 43, 0, 44, 45, 0, 46, 47, 48, 49, 0, 50, 51,
};
void sub_08A500A8_entry(Runtime &rt, AllegrexContext &ctx, std::uint16_t direct_entry_id, GuestMemory::AotFastView &aot_mem) {
    std::uint32_t jump_target = 0u;
    std::uint32_t local_transfers = 0u;
    std::uint32_t local_pc = ctx.pc;
    std::uint32_t entry_id = direct_entry_id;
LOCAL_DISPATCH:
    {
    if (entry_id == 0u) {
        const std::uint32_t entry_delta = local_pc - 0x08A500A8u;
        entry_id = (entry_delta < 256u && (entry_delta & 3u) == 0u) ? kEntryIds_sub_08A500A8[entry_delta >> 2u] : 0u;
    }
    switch (entry_id) {
    case 1u: goto L_08A500A8;
    case 2u: goto L_08A500AC;
    case 3u: goto L_08A500B0;
    case 4u: goto L_08A500B4;
    case 5u: goto L_08A500B8;
    case 6u: goto L_08A500BC;
    case 7u: goto L_08A500C0;
    case 8u: goto L_08A500C4;
    case 9u: goto L_08A500C8;
    case 10u: goto L_08A500D0;
    case 11u: goto L_08A500D8;
    case 12u: goto L_08A500DC;
    case 13u: goto L_08A500E0;
    case 14u: goto L_08A500E4;
    case 15u: goto L_08A500EC;
    case 16u: goto L_08A500F0;
    case 17u: goto L_08A500F4;
    case 18u: goto L_08A500FC;
    case 19u: goto L_08A50104;
    case 20u: goto L_08A5010C;
    case 21u: goto L_08A50110;
    case 22u: goto L_08A50118;
    case 23u: goto L_08A5011C;
    case 24u: goto L_08A50120;
    case 25u: goto L_08A50124;
    case 26u: goto L_08A50128;
    case 27u: goto L_08A5012C;
    case 28u: goto L_08A50134;
    case 29u: goto L_08A50138;
    case 30u: goto L_08A5013C;
    case 31u: goto L_08A50140;
    case 32u: goto L_08A50144;
    case 33u: goto L_08A50148;
    case 34u: goto L_08A5014C;
    case 35u: goto L_08A50154;
    case 36u: goto L_08A50158;
    case 37u: goto L_08A50160;
    case 38u: goto L_08A50164;
    case 39u: goto L_08A50168;
    case 40u: goto L_08A5016C;
    case 41u: goto L_08A50170;
    case 42u: goto L_08A50174;
    case 43u: goto L_08A50178;
    case 44u: goto L_08A50180;
    case 45u: goto L_08A50184;
    case 46u: goto L_08A5018C;
    case 47u: goto L_08A50190;
    case 48u: goto L_08A50194;
    case 49u: goto L_08A50198;
    case 50u: goto L_08A501A0;
    case 51u: goto L_08A501A4;
    default:
        if (local_transfers == 0u) rt.unsupported(ctx.pc, 0u, "invalid internal function entry");
        else ctx.pc = local_pc;
        return;
    }
    }
L_08A500A8:
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(-16));
    goto L_08A500AC;
L_08A500AC:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(0), ctx.gpr[16]);
    goto L_08A500B0;
L_08A500B0:
    ctx.set_gpr(16, ctx.gpr[4] | 0u);
    goto L_08A500B4;
L_08A500B4:
    ctx.set_gpr(6, 1u << 16u);
    goto L_08A500B8;
L_08A500B8:
    ctx.set_gpr(4, ctx.gpr[16] + static_cast<std::uint32_t>(20));
    goto L_08A500BC;
L_08A500BC:
    ctx.set_gpr(5, 0u | 1u);
    goto L_08A500C0;
L_08A500C0:
    ctx.set_gpr(7, 0u | 76u);
    goto L_08A500C4;
L_08A500C4:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(4), ctx.gpr[31]);
    goto L_08A500C8;
L_08A500C8:
    ctx.set_gpr(31, 0x08A500D0u);
    ctx.set_gpr(6, ctx.gpr[6] + static_cast<std::uint32_t>(4480));
    ctx.pc = 0x08864FF0u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08A500D0u) goto L_08A500D0;
    return;
L_08A500D0:
    ctx.set_gpr(31, 0x08A500D8u);
    ctx.set_gpr(4, ctx.gpr[16] | 0u);
    goto L_08A50118;
L_08A500D8:
    ctx.set_gpr(2, ctx.gpr[16] | 0u);
    goto L_08A500DC;
L_08A500DC:
    ctx.set_gpr(16, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(0)));
    goto L_08A500E0;
L_08A500E0:
    ctx.set_gpr(31, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(4)));
    goto L_08A500E4;
L_08A500E4:
    jump_target = ctx.gpr[31];
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(16));
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08A500EC:
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(-16));
    goto L_08A500F0;
L_08A500F0:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(0), ctx.gpr[31]);
    goto L_08A500F4;
L_08A500F4:
    { const bool branch_taken = ctx.gpr[4] == 0u;
    ctx.set_gpr(5, ctx.gpr[5] & 1u);
      if (branch_taken) {
          goto L_08A5010C;
      }
      goto L_08A500FC;
    }
L_08A500FC:
    { const bool branch_taken = ctx.gpr[5] == 0u;
    // nop
      if (branch_taken) {
          goto L_08A5010C;
      }
      goto L_08A50104;
    }
L_08A50104:
    ctx.set_gpr(31, 0x08A5010Cu);
    // nop
    ctx.pc = 0x08992F04u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08A5010Cu) goto L_08A5010C;
    return;
L_08A5010C:
    ctx.set_gpr(31, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(0)));
    goto L_08A50110;
L_08A50110:
    jump_target = ctx.gpr[31];
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(16));
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08A50118:
    ctx.set_gpr(5, 2487u << 16u);
    goto L_08A5011C;
L_08A5011C:
    rt.memory().aot_store32(ctx.gpr[5] + static_cast<std::uint32_t>(-8960), 0u);
    goto L_08A50120;
L_08A50120:
    rt.memory().aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(8), 0u);
    goto L_08A50124;
L_08A50124:
    rt.memory().aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(12), 0u);
    goto L_08A50128;
L_08A50128:
    rt.memory().aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(16), 0u);
    goto L_08A5012C;
L_08A5012C:
    jump_target = ctx.gpr[31];
    rt.memory().aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(88), 0u);
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08A50134:
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(-16));
    goto L_08A50138;
L_08A50138:
    ctx.set_gpr(6, 2213u << 16u);
    goto L_08A5013C;
L_08A5013C:
    ctx.set_gpr(5, 2487u << 16u);
    goto L_08A50140;
L_08A50140:
    ctx.set_gpr(6, rt.memory().aot_load32(ctx.gpr[6] + static_cast<std::uint32_t>(7356)));
    goto L_08A50144;
L_08A50144:
    rt.memory().aot_store32(ctx.gpr[5] + static_cast<std::uint32_t>(-8960), ctx.gpr[4]);
    goto L_08A50148;
L_08A50148:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(0), ctx.gpr[31]);
    goto L_08A5014C;
L_08A5014C:
    ctx.set_gpr(31, 0x08A50154u);
    ctx.set_gpr(4, ctx.gpr[6] | 0u);
    ctx.pc = 0x08A50270u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08A50154u) goto L_08A50154;
    return;
L_08A50154:
    ctx.set_gpr(31, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(0)));
    goto L_08A50158;
L_08A50158:
    jump_target = ctx.gpr[31];
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(16));
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08A50160:
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(-16));
    goto L_08A50164;
L_08A50164:
    ctx.set_gpr(4, 2205u << 16u);
    goto L_08A50168;
L_08A50168:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(32392)));
    goto L_08A5016C;
L_08A5016C:
    ctx.set_gpr(5, 2213u << 16u);
    goto L_08A50170;
L_08A50170:
    rt.memory().aot_store8(ctx.gpr[4] + static_cast<std::uint32_t>(6221), static_cast<std::uint8_t>(0u));
    goto L_08A50174;
L_08A50174:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(0), ctx.gpr[31]);
    goto L_08A50178;
L_08A50178:
    ctx.set_gpr(31, 0x08A50180u);
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[5] + static_cast<std::uint32_t>(7356)));
    ctx.pc = 0x08A50650u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08A50180u) goto L_08A50180;
    return;
L_08A50180:
    ctx.set_gpr(31, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(0)));
    goto L_08A50184;
L_08A50184:
    jump_target = ctx.gpr[31];
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(16));
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08A5018C:
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(-16));
    goto L_08A50190;
L_08A50190:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(0), ctx.gpr[16]);
    goto L_08A50194;
L_08A50194:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(4), ctx.gpr[31]);
    goto L_08A50198;
L_08A50198:
    ctx.set_gpr(31, 0x08A501A0u);
    ctx.set_gpr(4, 0u | 8192u);
    ctx.pc = 0x088820D8u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08A501A0u) goto L_08A501A0;
    return;
L_08A501A0:
    ctx.set_gpr(16, 2213u << 16u);
    goto L_08A501A4;
L_08A501A4:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[16] + static_cast<std::uint32_t>(7356)));
    ctx.pc = 0x08A501A8u; return;
}

void sub_08A500A8(Runtime &rt, AllegrexContext &ctx) {
    auto aot_mem = rt.memory().aot_fast_view();
    sub_08A500A8_entry(rt, ctx, 0u, aot_mem);
}

static const std::uint16_t kEntryIds_sub_08A6CBFC[64] = {
    1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 10, 11, 12, 13, 14, 15, 0, 16, 0, 17, 0, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28,
    29, 30, 31, 32, 33, 34, 35, 36, 37, 0, 38, 39, 40, 41, 42, 43, 44, 45, 0, 46, 0, 47, 48, 49, 50, 51, 52, 53, 0, 54, 55, 56,
};
void sub_08A6CBFC_entry(Runtime &rt, AllegrexContext &ctx, std::uint16_t direct_entry_id, GuestMemory::AotFastView &aot_mem) {
    std::uint32_t jump_target = 0u;
    std::uint32_t local_transfers = 0u;
    std::uint32_t local_pc = ctx.pc;
    std::uint32_t entry_id = direct_entry_id;
LOCAL_DISPATCH:
    {
    if (entry_id == 0u) {
        const std::uint32_t entry_delta = local_pc - 0x08A6CBFCu;
        entry_id = (entry_delta < 256u && (entry_delta & 3u) == 0u) ? kEntryIds_sub_08A6CBFC[entry_delta >> 2u] : 0u;
    }
    switch (entry_id) {
    case 1u: goto L_08A6CBFC;
    case 2u: goto L_08A6CC00;
    case 3u: goto L_08A6CC04;
    case 4u: goto L_08A6CC08;
    case 5u: goto L_08A6CC0C;
    case 6u: goto L_08A6CC10;
    case 7u: goto L_08A6CC14;
    case 8u: goto L_08A6CC18;
    case 9u: goto L_08A6CC1C;
    case 10u: goto L_08A6CC24;
    case 11u: goto L_08A6CC28;
    case 12u: goto L_08A6CC2C;
    case 13u: goto L_08A6CC30;
    case 14u: goto L_08A6CC34;
    case 15u: goto L_08A6CC38;
    case 16u: goto L_08A6CC40;
    case 17u: goto L_08A6CC48;
    case 18u: goto L_08A6CC50;
    case 19u: goto L_08A6CC54;
    case 20u: goto L_08A6CC58;
    case 21u: goto L_08A6CC5C;
    case 22u: goto L_08A6CC60;
    case 23u: goto L_08A6CC64;
    case 24u: goto L_08A6CC68;
    case 25u: goto L_08A6CC6C;
    case 26u: goto L_08A6CC70;
    case 27u: goto L_08A6CC74;
    case 28u: goto L_08A6CC78;
    case 29u: goto L_08A6CC7C;
    case 30u: goto L_08A6CC80;
    case 31u: goto L_08A6CC84;
    case 32u: goto L_08A6CC88;
    case 33u: goto L_08A6CC8C;
    case 34u: goto L_08A6CC90;
    case 35u: goto L_08A6CC94;
    case 36u: goto L_08A6CC98;
    case 37u: goto L_08A6CC9C;
    case 38u: goto L_08A6CCA4;
    case 39u: goto L_08A6CCA8;
    case 40u: goto L_08A6CCAC;
    case 41u: goto L_08A6CCB0;
    case 42u: goto L_08A6CCB4;
    case 43u: goto L_08A6CCB8;
    case 44u: goto L_08A6CCBC;
    case 45u: goto L_08A6CCC0;
    case 46u: goto L_08A6CCC8;
    case 47u: goto L_08A6CCD0;
    case 48u: goto L_08A6CCD4;
    case 49u: goto L_08A6CCD8;
    case 50u: goto L_08A6CCDC;
    case 51u: goto L_08A6CCE0;
    case 52u: goto L_08A6CCE4;
    case 53u: goto L_08A6CCE8;
    case 54u: goto L_08A6CCF0;
    case 55u: goto L_08A6CCF4;
    case 56u: goto L_08A6CCF8;
    default:
        if (local_transfers == 0u) rt.unsupported(ctx.pc, 0u, "invalid internal function entry");
        else ctx.pc = local_pc;
        return;
    }
    }
L_08A6CBFC:
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(-16));
    goto L_08A6CC00;
L_08A6CC00:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(0), ctx.gpr[16]);
    goto L_08A6CC04;
L_08A6CC04:
    ctx.set_gpr(16, ctx.gpr[4] | 0u);
    goto L_08A6CC08;
L_08A6CC08:
    ctx.set_gpr(6, 1u << 16u);
    goto L_08A6CC0C;
L_08A6CC0C:
    ctx.set_gpr(4, ctx.gpr[16] + static_cast<std::uint32_t>(256));
    goto L_08A6CC10;
L_08A6CC10:
    ctx.set_gpr(5, 0u | 1u);
    goto L_08A6CC14;
L_08A6CC14:
    ctx.set_gpr(7, 0u | 77u);
    goto L_08A6CC18;
L_08A6CC18:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(4), ctx.gpr[31]);
    goto L_08A6CC1C;
L_08A6CC1C:
    ctx.set_gpr(31, 0x08A6CC24u);
    ctx.set_gpr(6, ctx.gpr[6] + static_cast<std::uint32_t>(4488));
    ctx.pc = 0x08864FF0u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08A6CC24u) goto L_08A6CC24;
    return;
L_08A6CC24:
    rt.memory().aot_store32(ctx.gpr[16] + static_cast<std::uint32_t>(308), 0u);
    goto L_08A6CC28;
L_08A6CC28:
    rt.memory().aot_store32(ctx.gpr[16] + static_cast<std::uint32_t>(312), 0u);
    goto L_08A6CC2C;
L_08A6CC2C:
    rt.memory().aot_store32(ctx.gpr[16] + static_cast<std::uint32_t>(316), 0u);
    goto L_08A6CC30;
L_08A6CC30:
    rt.memory().aot_store32(ctx.gpr[16] + static_cast<std::uint32_t>(320), 0u);
    goto L_08A6CC34;
L_08A6CC34:
    rt.memory().aot_store32(ctx.gpr[16] + static_cast<std::uint32_t>(324), 0u);
    goto L_08A6CC38;
L_08A6CC38:
    ctx.set_gpr(31, 0x08A6CC40u);
    ctx.set_gpr(4, ctx.gpr[16] + static_cast<std::uint32_t>(328));
    ctx.pc = 0x08A74588u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08A6CC40u) goto L_08A6CC40;
    return;
L_08A6CC40:
    ctx.set_gpr(31, 0x08A6CC48u);
    ctx.set_gpr(4, ctx.gpr[16] + static_cast<std::uint32_t>(388));
    ctx.pc = 0x08A723D8u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08A6CC48u) goto L_08A6CC48;
    return;
L_08A6CC48:
    ctx.set_gpr(31, 0x08A6CC50u);
    ctx.set_gpr(4, ctx.gpr[16] + static_cast<std::uint32_t>(432));
    ctx.pc = 0x08A79C30u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08A6CC50u) goto L_08A6CC50;
    return;
L_08A6CC50:
    ctx.set_gpr(4, 2215u << 16u);
    goto L_08A6CC54;
L_08A6CC54:
    rt.memory().aot_store32(ctx.gpr[16] + static_cast<std::uint32_t>(568), 0u);
    goto L_08A6CC58;
L_08A6CC58:
    ctx.set_gpr(4, ctx.gpr[4] + static_cast<std::uint32_t>(-10672));
    goto L_08A6CC5C;
L_08A6CC5C:
    rt.memory().aot_store32(ctx.gpr[16] + static_cast<std::uint32_t>(572), ctx.gpr[4]);
    goto L_08A6CC60;
L_08A6CC60:
    ctx.set_gpr(4, 2215u << 16u);
    goto L_08A6CC64;
L_08A6CC64:
    rt.memory().aot_store32(ctx.gpr[16] + static_cast<std::uint32_t>(576), ctx.gpr[16]);
    goto L_08A6CC68;
L_08A6CC68:
    ctx.set_gpr(4, ctx.gpr[4] + static_cast<std::uint32_t>(-10656));
    goto L_08A6CC6C;
L_08A6CC6C:
    rt.memory().aot_store32(ctx.gpr[16] + static_cast<std::uint32_t>(580), ctx.gpr[4]);
    goto L_08A6CC70;
L_08A6CC70:
    ctx.set_gpr(4, 2215u << 16u);
    goto L_08A6CC74;
L_08A6CC74:
    rt.memory().aot_store32(ctx.gpr[16] + static_cast<std::uint32_t>(584), ctx.gpr[16]);
    goto L_08A6CC78;
L_08A6CC78:
    ctx.set_gpr(4, ctx.gpr[4] + static_cast<std::uint32_t>(-10584));
    goto L_08A6CC7C;
L_08A6CC7C:
    rt.memory().aot_store32(ctx.gpr[16] + static_cast<std::uint32_t>(592), ctx.gpr[4]);
    goto L_08A6CC80;
L_08A6CC80:
    ctx.set_gpr(4, 0u + static_cast<std::uint32_t>(-1));
    goto L_08A6CC84;
L_08A6CC84:
    rt.memory().aot_store32(ctx.gpr[16] + static_cast<std::uint32_t>(596), ctx.gpr[16]);
    goto L_08A6CC88;
L_08A6CC88:
    rt.memory().aot_store32(ctx.gpr[16] + static_cast<std::uint32_t>(628), ctx.gpr[4]);
    goto L_08A6CC8C;
L_08A6CC8C:
    rt.memory().aot_store8(ctx.gpr[16] + static_cast<std::uint32_t>(632), static_cast<std::uint8_t>(0u));
    goto L_08A6CC90;
L_08A6CC90:
    ctx.set_gpr(2, ctx.gpr[16] | 0u);
    goto L_08A6CC94;
L_08A6CC94:
    ctx.set_gpr(16, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(0)));
    goto L_08A6CC98;
L_08A6CC98:
    ctx.set_gpr(31, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(4)));
    goto L_08A6CC9C;
L_08A6CC9C:
    jump_target = ctx.gpr[31];
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(16));
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08A6CCA4:
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(-32));
    goto L_08A6CCA8;
L_08A6CCA8:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(4), ctx.gpr[16]);
    goto L_08A6CCAC;
L_08A6CCAC:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(8), ctx.gpr[17]);
    goto L_08A6CCB0;
L_08A6CCB0:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(12), ctx.gpr[18]);
    goto L_08A6CCB4;
L_08A6CCB4:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(16), ctx.gpr[19]);
    goto L_08A6CCB8;
L_08A6CCB8:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(20), ctx.gpr[20]);
    goto L_08A6CCBC;
L_08A6CCBC:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(24), ctx.gpr[31]);
    goto L_08A6CCC0;
L_08A6CCC0:
    ctx.set_gpr(31, 0x08A6CCC8u);
    ctx.set_gpr(16, ctx.gpr[4] | 0u);
    ctx.pc = 0x08860E78u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08A6CCC8u) goto L_08A6CCC8;
    return;
L_08A6CCC8:
    ctx.set_gpr(31, 0x08A6CCD0u);
    // nop
    ctx.pc = 0x08883F78u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08A6CCD0u) goto L_08A6CCD0;
    return;
L_08A6CCD0:
    ctx.set_gpr(7, 2215u << 16u);
    goto L_08A6CCD4;
L_08A6CCD4:
    ctx.set_gpr(8, 2215u << 16u);
    goto L_08A6CCD8;
L_08A6CCD8:
    ctx.set_gpr(4, ctx.gpr[16] + static_cast<std::uint32_t>(256));
    goto L_08A6CCDC;
L_08A6CCDC:
    ctx.set_gpr(5, 0u | 0u);
    goto L_08A6CCE0;
L_08A6CCE0:
    ctx.set_gpr(6, 0u | 0u);
    goto L_08A6CCE4;
L_08A6CCE4:
    ctx.set_gpr(7, ctx.gpr[7] + static_cast<std::uint32_t>(-11580));
    goto L_08A6CCE8;
L_08A6CCE8:
    ctx.set_gpr(31, 0x08A6CCF0u);
    ctx.set_gpr(8, ctx.gpr[8] + static_cast<std::uint32_t>(-10568));
    ctx.pc = 0x08865088u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08A6CCF0u) goto L_08A6CCF0;
    return;
L_08A6CCF0:
    ctx.set_gpr(4, 39u << 16u);
    goto L_08A6CCF4;
L_08A6CCF4:
    ctx.set_gpr(17, ctx.gpr[4] + static_cast<std::uint32_t>(2048));
    goto L_08A6CCF8;
L_08A6CCF8:
    ctx.set_gpr(31, 0x08A6CD00u);
    ctx.set_gpr(4, ctx.gpr[17] | 0u);
    ctx.pc = 0x0888204Cu;
    (void)rt.invoke_chained_call(ctx, &aot_mem);
    return;
}

void sub_08A6CBFC(Runtime &rt, AllegrexContext &ctx) {
    auto aot_mem = rt.memory().aot_fast_view();
    sub_08A6CBFC_entry(rt, ctx, 0u, aot_mem);
}

static const std::uint16_t kEntryIds_sub_08A6D7CC[64] = {
    1, 2, 3, 0, 4, 5, 6, 7, 8, 9, 0, 10, 11, 12, 0, 13, 0, 14, 15, 0, 16, 17, 18, 19, 20, 0, 21, 0, 22, 0, 23, 0,
    24, 0, 25, 26, 27, 28, 29, 30, 31, 32, 0, 33, 34, 35, 0, 36, 37, 38, 39, 40, 41, 0, 42, 0, 43, 44, 45, 46, 47, 48, 49, 50,
};
void sub_08A6D7CC_entry(Runtime &rt, AllegrexContext &ctx, std::uint16_t direct_entry_id, GuestMemory::AotFastView &aot_mem) {
    std::uint32_t jump_target = 0u;
    std::uint32_t local_transfers = 0u;
    std::uint32_t local_pc = ctx.pc;
    std::uint32_t entry_id = direct_entry_id;
LOCAL_DISPATCH:
    {
    if (entry_id == 0u) {
        const std::uint32_t entry_delta = local_pc - 0x08A6D7CCu;
        entry_id = (entry_delta < 256u && (entry_delta & 3u) == 0u) ? kEntryIds_sub_08A6D7CC[entry_delta >> 2u] : 0u;
    }
    switch (entry_id) {
    case 1u: goto L_08A6D7CC;
    case 2u: goto L_08A6D7D0;
    case 3u: goto L_08A6D7D4;
    case 4u: goto L_08A6D7DC;
    case 5u: goto L_08A6D7E0;
    case 6u: goto L_08A6D7E4;
    case 7u: goto L_08A6D7E8;
    case 8u: goto L_08A6D7EC;
    case 9u: goto L_08A6D7F0;
    case 10u: goto L_08A6D7F8;
    case 11u: goto L_08A6D7FC;
    case 12u: goto L_08A6D800;
    case 13u: goto L_08A6D808;
    case 14u: goto L_08A6D810;
    case 15u: goto L_08A6D814;
    case 16u: goto L_08A6D81C;
    case 17u: goto L_08A6D820;
    case 18u: goto L_08A6D824;
    case 19u: goto L_08A6D828;
    case 20u: goto L_08A6D82C;
    case 21u: goto L_08A6D834;
    case 22u: goto L_08A6D83C;
    case 23u: goto L_08A6D844;
    case 24u: goto L_08A6D84C;
    case 25u: goto L_08A6D854;
    case 26u: goto L_08A6D858;
    case 27u: goto L_08A6D85C;
    case 28u: goto L_08A6D860;
    case 29u: goto L_08A6D864;
    case 30u: goto L_08A6D868;
    case 31u: goto L_08A6D86C;
    case 32u: goto L_08A6D870;
    case 33u: goto L_08A6D878;
    case 34u: goto L_08A6D87C;
    case 35u: goto L_08A6D880;
    case 36u: goto L_08A6D888;
    case 37u: goto L_08A6D88C;
    case 38u: goto L_08A6D890;
    case 39u: goto L_08A6D894;
    case 40u: goto L_08A6D898;
    case 41u: goto L_08A6D89C;
    case 42u: goto L_08A6D8A4;
    case 43u: goto L_08A6D8AC;
    case 44u: goto L_08A6D8B0;
    case 45u: goto L_08A6D8B4;
    case 46u: goto L_08A6D8B8;
    case 47u: goto L_08A6D8BC;
    case 48u: goto L_08A6D8C0;
    case 49u: goto L_08A6D8C4;
    case 50u: goto L_08A6D8C8;
    default:
        if (local_transfers == 0u) rt.unsupported(ctx.pc, 0u, "invalid internal function entry");
        else ctx.pc = local_pc;
        return;
    }
    }
L_08A6D7CC:
    rt.memory().aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(0), 0u);
    goto L_08A6D7D0;
L_08A6D7D0:
    rt.memory().aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(4), 0u);
    goto L_08A6D7D4;
L_08A6D7D4:
    jump_target = ctx.gpr[31];
    ctx.set_gpr(2, ctx.gpr[4] | 0u);
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08A6D7DC:
    // nop
    goto L_08A6D7E0;
L_08A6D7E0:
    // nop
    goto L_08A6D7E4;
L_08A6D7E4:
    // nop
    goto L_08A6D7E8;
L_08A6D7E8:
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(-16));
    goto L_08A6D7EC;
L_08A6D7EC:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(0), ctx.gpr[31]);
    goto L_08A6D7F0;
L_08A6D7F0:
    { const bool branch_taken = ctx.gpr[4] == 0u;
    ctx.set_gpr(6, 2215u << 16u);
      if (branch_taken) {
          goto L_08A6D810;
      }
      goto L_08A6D7F8;
    }
L_08A6D7F8:
    ctx.set_gpr(6, ctx.gpr[6] + static_cast<std::uint32_t>(-10208));
    goto L_08A6D7FC;
L_08A6D7FC:
    ctx.set_gpr(5, ctx.gpr[5] & 1u);
    goto L_08A6D800;
L_08A6D800:
    { const bool branch_taken = ctx.gpr[5] == 0u;
    rt.memory().aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(0), ctx.gpr[6]);
      if (branch_taken) {
          goto L_08A6D810;
      }
      goto L_08A6D808;
    }
L_08A6D808:
    ctx.set_gpr(31, 0x08A6D810u);
    // nop
    ctx.pc = 0x08992F04u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08A6D810u) goto L_08A6D810;
    return;
L_08A6D810:
    ctx.set_gpr(31, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(0)));
    goto L_08A6D814;
L_08A6D814:
    jump_target = ctx.gpr[31];
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(16));
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08A6D81C:
    // nop
    goto L_08A6D820;
L_08A6D820:
    // nop
    goto L_08A6D824;
L_08A6D824:
    // nop
    goto L_08A6D828;
L_08A6D828:
    // nop
    goto L_08A6D82C;
L_08A6D82C:
    // nop
    ctx.pc = 0x0264C3D0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_08A6D834:
    // nop
    ctx.pc = 0x0264C3D0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_08A6D83C:
    // nop
    ctx.pc = 0x0264C3D0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_08A6D844:
    // nop
    ctx.pc = 0x0264C3D0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_08A6D84C:
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(-16));
    ctx.pc = 0x0264C3D0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_08A6D854:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(0), ctx.gpr[16]);
    goto L_08A6D858;
L_08A6D858:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(4), ctx.gpr[17]);
    goto L_08A6D85C;
L_08A6D85C:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(8), ctx.gpr[18]);
    goto L_08A6D860;
L_08A6D860:
    ctx.set_gpr(16, ctx.gpr[4] | 0u);
    goto L_08A6D864;
L_08A6D864:
    ctx.set_gpr(17, ctx.gpr[5] + static_cast<std::uint32_t>(8));
    goto L_08A6D868;
L_08A6D868:
    ctx.set_gpr(18, ctx.gpr[5] + static_cast<std::uint32_t>(552));
    goto L_08A6D86C;
L_08A6D86C:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(12), ctx.gpr[31]);
    goto L_08A6D870;
L_08A6D870:
    ctx.set_gpr(31, 0x08A6D878u);
    ctx.set_gpr(4, ctx.gpr[5] | 0u);
    ctx.pc = 0x08A6EF6Cu;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08A6D878u) goto L_08A6D878;
    return;
L_08A6D878:
    ctx.set_gpr(4, ctx.gpr[17] | 0u);
    goto L_08A6D87C;
L_08A6D87C:
    ctx.set_gpr(5, ctx.gpr[18] | 0u);
    goto L_08A6D880;
L_08A6D880:
    ctx.set_gpr(31, 0x08A6D888u);
    ctx.set_gpr(6, 0u | 2416u);
    ctx.pc = 0x0890AAE4u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08A6D888u) goto L_08A6D888;
    return;
L_08A6D888:
    rt.memory().aot_store32(ctx.gpr[16] + static_cast<std::uint32_t>(4), 0u);
    goto L_08A6D88C;
L_08A6D88C:
    ctx.set_gpr(16, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(0)));
    goto L_08A6D890;
L_08A6D890:
    ctx.set_gpr(17, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(4)));
    goto L_08A6D894;
L_08A6D894:
    ctx.set_gpr(18, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(8)));
    goto L_08A6D898;
L_08A6D898:
    ctx.set_gpr(31, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(12)));
    goto L_08A6D89C;
L_08A6D89C:
    jump_target = ctx.gpr[31];
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(16));
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08A6D8A4:
    jump_target = ctx.gpr[31];
    // nop
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08A6D8AC:
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(-48));
    goto L_08A6D8B0;
L_08A6D8B0:
    rt.memory().aot_store16(ctx.gpr[29] + static_cast<std::uint32_t>(0), static_cast<std::uint16_t>(0u));
    goto L_08A6D8B4;
L_08A6D8B4:
    ctx.set_gpr(6, 2215u << 16u);
    goto L_08A6D8B8;
L_08A6D8B8:
    rt.memory().aot_store16(ctx.gpr[29] + static_cast<std::uint32_t>(2), static_cast<std::uint16_t>(0u));
    goto L_08A6D8BC;
L_08A6D8BC:
    ctx.set_gpr(6, ctx.gpr[6] + static_cast<std::uint32_t>(-9772));
    goto L_08A6D8C0;
L_08A6D8C0:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(4), ctx.gpr[6]);
    goto L_08A6D8C4;
L_08A6D8C4:
    rt.memory().aot_store16(ctx.gpr[29] + static_cast<std::uint32_t>(8), static_cast<std::uint16_t>(0u));
    goto L_08A6D8C8;
L_08A6D8C8:
    ctx.set_gpr(6, 2215u << 16u);
    ctx.pc = 0x08A6D8CCu; return;
}

void sub_08A6D7CC(Runtime &rt, AllegrexContext &ctx) {
    auto aot_mem = rt.memory().aot_fast_view();
    sub_08A6D7CC_entry(rt, ctx, 0u, aot_mem);
}

static const std::uint16_t kEntryIds_sub_08A87428[63] = {
    1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 10, 11, 12, 13, 0, 14, 15, 16, 0, 17, 0, 18, 0, 19, 20, 0, 21, 22, 23, 24, 25, 26,
    0, 27, 28, 29, 30, 31, 32, 0, 33, 34, 35, 36, 37, 0, 38, 39, 0, 40, 41, 42, 0, 43, 44, 45, 46, 47, 48, 0, 49, 50, 51,
};
void sub_08A87428_entry(Runtime &rt, AllegrexContext &ctx, std::uint16_t direct_entry_id, GuestMemory::AotFastView &aot_mem) {
    std::uint32_t jump_target = 0u;
    std::uint32_t local_transfers = 0u;
    std::uint32_t local_pc = ctx.pc;
    std::uint32_t entry_id = direct_entry_id;
LOCAL_DISPATCH:
    {
    if (entry_id == 0u) {
        const std::uint32_t entry_delta = local_pc - 0x08A87428u;
        entry_id = (entry_delta < 252u && (entry_delta & 3u) == 0u) ? kEntryIds_sub_08A87428[entry_delta >> 2u] : 0u;
    }
    switch (entry_id) {
    case 1u: goto L_08A87428;
    case 2u: goto L_08A8742C;
    case 3u: goto L_08A87430;
    case 4u: goto L_08A87434;
    case 5u: goto L_08A87438;
    case 6u: goto L_08A8743C;
    case 7u: goto L_08A87440;
    case 8u: goto L_08A87444;
    case 9u: goto L_08A87448;
    case 10u: goto L_08A87450;
    case 11u: goto L_08A87454;
    case 12u: goto L_08A87458;
    case 13u: goto L_08A8745C;
    case 14u: goto L_08A87464;
    case 15u: goto L_08A87468;
    case 16u: goto L_08A8746C;
    case 17u: goto L_08A87474;
    case 18u: goto L_08A8747C;
    case 19u: goto L_08A87484;
    case 20u: goto L_08A87488;
    case 21u: goto L_08A87490;
    case 22u: goto L_08A87494;
    case 23u: goto L_08A87498;
    case 24u: goto L_08A8749C;
    case 25u: goto L_08A874A0;
    case 26u: goto L_08A874A4;
    case 27u: goto L_08A874AC;
    case 28u: goto L_08A874B0;
    case 29u: goto L_08A874B4;
    case 30u: goto L_08A874B8;
    case 31u: goto L_08A874BC;
    case 32u: goto L_08A874C0;
    case 33u: goto L_08A874C8;
    case 34u: goto L_08A874CC;
    case 35u: goto L_08A874D0;
    case 36u: goto L_08A874D4;
    case 37u: goto L_08A874D8;
    case 38u: goto L_08A874E0;
    case 39u: goto L_08A874E4;
    case 40u: goto L_08A874EC;
    case 41u: goto L_08A874F0;
    case 42u: goto L_08A874F4;
    case 43u: goto L_08A874FC;
    case 44u: goto L_08A87500;
    case 45u: goto L_08A87504;
    case 46u: goto L_08A87508;
    case 47u: goto L_08A8750C;
    case 48u: goto L_08A87510;
    case 49u: goto L_08A87518;
    case 50u: goto L_08A8751C;
    case 51u: goto L_08A87520;
    default:
        if (local_transfers == 0u) rt.unsupported(ctx.pc, 0u, "invalid internal function entry");
        else ctx.pc = local_pc;
        return;
    }
    }
L_08A87428:
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(-16));
    goto L_08A8742C;
L_08A8742C:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(0), ctx.gpr[16]);
    goto L_08A87430;
L_08A87430:
    ctx.set_gpr(16, ctx.gpr[4] | 0u);
    goto L_08A87434;
L_08A87434:
    ctx.set_gpr(6, 1u << 16u);
    goto L_08A87438;
L_08A87438:
    ctx.set_gpr(4, ctx.gpr[16] + static_cast<std::uint32_t>(256));
    goto L_08A8743C;
L_08A8743C:
    ctx.set_gpr(5, 0u | 1u);
    goto L_08A87440;
L_08A87440:
    ctx.set_gpr(7, 0u | 76u);
    goto L_08A87444;
L_08A87444:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(4), ctx.gpr[31]);
    goto L_08A87448;
L_08A87448:
    ctx.set_gpr(31, 0x08A87450u);
    ctx.set_gpr(6, ctx.gpr[6] + static_cast<std::uint32_t>(4491));
    ctx.pc = 0x08864FF0u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08A87450u) goto L_08A87450;
    return;
L_08A87450:
    ctx.set_gpr(2, ctx.gpr[16] | 0u);
    goto L_08A87454;
L_08A87454:
    ctx.set_gpr(16, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(0)));
    goto L_08A87458;
L_08A87458:
    ctx.set_gpr(31, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(4)));
    goto L_08A8745C;
L_08A8745C:
    jump_target = ctx.gpr[31];
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(16));
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08A87464:
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(-16));
    goto L_08A87468;
L_08A87468:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(0), ctx.gpr[31]);
    goto L_08A8746C;
L_08A8746C:
    { const bool branch_taken = ctx.gpr[4] == 0u;
    ctx.set_gpr(5, ctx.gpr[5] & 1u);
      if (branch_taken) {
          goto L_08A87484;
      }
      goto L_08A87474;
    }
L_08A87474:
    { const bool branch_taken = ctx.gpr[5] == 0u;
    // nop
      if (branch_taken) {
          goto L_08A87484;
      }
      goto L_08A8747C;
    }
L_08A8747C:
    ctx.set_gpr(31, 0x08A87484u);
    // nop
    ctx.pc = 0x08992F04u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08A87484u) goto L_08A87484;
    return;
L_08A87484:
    ctx.set_gpr(31, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(0)));
    goto L_08A87488;
L_08A87488:
    jump_target = ctx.gpr[31];
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(16));
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08A87490:
    ctx.set_gpr(4, 2216u << 16u);
    goto L_08A87494;
L_08A87494:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(32428)));
    goto L_08A87498;
L_08A87498:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(332)));
    goto L_08A8749C;
L_08A8749C:
    ctx.set_gpr(5, rt.memory().aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(2328)));
    goto L_08A874A0;
L_08A874A0:
    ctx.set_gpr(5, ctx.gpr[5] | 2u);
    goto L_08A874A4;
L_08A874A4:
    jump_target = ctx.gpr[31];
    rt.memory().aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(2328), ctx.gpr[5]);
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08A874AC:
    ctx.set_gpr(4, 2216u << 16u);
    goto L_08A874B0;
L_08A874B0:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(32428)));
    goto L_08A874B4;
L_08A874B4:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(332)));
    goto L_08A874B8;
L_08A874B8:
    ctx.set_gpr(5, rt.memory().aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(2328)));
    goto L_08A874BC;
L_08A874BC:
    ctx.set_gpr(5, ctx.gpr[5] | 4u);
    goto L_08A874C0;
L_08A874C0:
    jump_target = ctx.gpr[31];
    rt.memory().aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(2328), ctx.gpr[5]);
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08A874C8:
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(-16));
    goto L_08A874CC;
L_08A874CC:
    ctx.set_gpr(5, ctx.gpr[4] | 0u);
    goto L_08A874D0;
L_08A874D0:
    ctx.set_gpr(4, 2216u << 16u);
    goto L_08A874D4;
L_08A874D4:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(0), ctx.gpr[31]);
    goto L_08A874D8;
L_08A874D8:
    ctx.set_gpr(31, 0x08A874E0u);
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(32428)));
    ctx.pc = 0x08A870A4u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08A874E0u) goto L_08A874E0;
    return;
L_08A874E0:
    ctx.set_gpr(31, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(0)));
    goto L_08A874E4;
L_08A874E4:
    jump_target = ctx.gpr[31];
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(16));
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08A874EC:
    ctx.set_gpr(5, 2487u << 16u);
    goto L_08A874F0;
L_08A874F0:
    ctx.set_gpr(5, ctx.gpr[5] + static_cast<std::uint32_t>(-12920));
    goto L_08A874F4;
L_08A874F4:
    jump_target = ctx.gpr[31];
    rt.memory().aot_store32(ctx.gpr[5] + static_cast<std::uint32_t>(4), ctx.gpr[4]);
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08A874FC:
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(-32));
    goto L_08A87500;
L_08A87500:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(4), ctx.gpr[16]);
    goto L_08A87504;
L_08A87504:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(8), ctx.gpr[17]);
    goto L_08A87508;
L_08A87508:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(12), ctx.gpr[18]);
    goto L_08A8750C;
L_08A8750C:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(16), ctx.gpr[31]);
    goto L_08A87510;
L_08A87510:
    ctx.set_gpr(31, 0x08A87518u);
    ctx.set_gpr(16, ctx.gpr[4] | 0u);
    ctx.pc = 0x08A872F4u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08A87518u) goto L_08A87518;
    return;
L_08A87518:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[16] + static_cast<std::uint32_t>(332)));
    goto L_08A8751C;
L_08A8751C:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(2180)));
    goto L_08A87520;
L_08A87520:
    { const bool branch_taken = ctx.gpr[4] == 0u;
    // nop
      if (branch_taken) {
          ctx.pc = 0x08A87538u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
      }
      ctx.pc = 0x08A87528u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
    }
}

void sub_08A87428(Runtime &rt, AllegrexContext &ctx) {
    auto aot_mem = rt.memory().aot_fast_view();
    sub_08A87428_entry(rt, ctx, 0u, aot_mem);
}

static const std::uint16_t kEntryIds_sub_08A8A194[63] = {
    1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 10, 11, 12, 13, 0, 14, 15, 16, 0, 17, 0, 18, 0, 19, 20, 0, 21, 22, 23, 24, 25, 26,
    27, 0, 28, 29, 30, 31, 32, 33, 34, 0, 35, 36, 37, 38, 39, 0, 40, 41, 0, 42, 43, 0, 44, 45, 0, 46, 47, 0, 48, 0, 49,
};
void sub_08A8A194_entry(Runtime &rt, AllegrexContext &ctx, std::uint16_t direct_entry_id, GuestMemory::AotFastView &aot_mem) {
    std::uint32_t jump_target = 0u;
    std::uint32_t local_transfers = 0u;
    std::uint32_t local_pc = ctx.pc;
    std::uint32_t entry_id = direct_entry_id;
LOCAL_DISPATCH:
    {
    if (entry_id == 0u) {
        const std::uint32_t entry_delta = local_pc - 0x08A8A194u;
        entry_id = (entry_delta < 252u && (entry_delta & 3u) == 0u) ? kEntryIds_sub_08A8A194[entry_delta >> 2u] : 0u;
    }
    switch (entry_id) {
    case 1u: goto L_08A8A194;
    case 2u: goto L_08A8A198;
    case 3u: goto L_08A8A19C;
    case 4u: goto L_08A8A1A0;
    case 5u: goto L_08A8A1A4;
    case 6u: goto L_08A8A1A8;
    case 7u: goto L_08A8A1AC;
    case 8u: goto L_08A8A1B0;
    case 9u: goto L_08A8A1B4;
    case 10u: goto L_08A8A1BC;
    case 11u: goto L_08A8A1C0;
    case 12u: goto L_08A8A1C4;
    case 13u: goto L_08A8A1C8;
    case 14u: goto L_08A8A1D0;
    case 15u: goto L_08A8A1D4;
    case 16u: goto L_08A8A1D8;
    case 17u: goto L_08A8A1E0;
    case 18u: goto L_08A8A1E8;
    case 19u: goto L_08A8A1F0;
    case 20u: goto L_08A8A1F4;
    case 21u: goto L_08A8A1FC;
    case 22u: goto L_08A8A200;
    case 23u: goto L_08A8A204;
    case 24u: goto L_08A8A208;
    case 25u: goto L_08A8A20C;
    case 26u: goto L_08A8A210;
    case 27u: goto L_08A8A214;
    case 28u: goto L_08A8A21C;
    case 29u: goto L_08A8A220;
    case 30u: goto L_08A8A224;
    case 31u: goto L_08A8A228;
    case 32u: goto L_08A8A22C;
    case 33u: goto L_08A8A230;
    case 34u: goto L_08A8A234;
    case 35u: goto L_08A8A23C;
    case 36u: goto L_08A8A240;
    case 37u: goto L_08A8A244;
    case 38u: goto L_08A8A248;
    case 39u: goto L_08A8A24C;
    case 40u: goto L_08A8A254;
    case 41u: goto L_08A8A258;
    case 42u: goto L_08A8A260;
    case 43u: goto L_08A8A264;
    case 44u: goto L_08A8A26C;
    case 45u: goto L_08A8A270;
    case 46u: goto L_08A8A278;
    case 47u: goto L_08A8A27C;
    case 48u: goto L_08A8A284;
    case 49u: goto L_08A8A28C;
    default:
        if (local_transfers == 0u) rt.unsupported(ctx.pc, 0u, "invalid internal function entry");
        else ctx.pc = local_pc;
        return;
    }
    }
L_08A8A194:
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(-16));
    goto L_08A8A198;
L_08A8A198:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(0), ctx.gpr[16]);
    goto L_08A8A19C;
L_08A8A19C:
    ctx.set_gpr(16, ctx.gpr[4] | 0u);
    goto L_08A8A1A0;
L_08A8A1A0:
    ctx.set_gpr(6, 1u << 16u);
    goto L_08A8A1A4;
L_08A8A1A4:
    ctx.set_gpr(4, ctx.gpr[16] + static_cast<std::uint32_t>(256));
    goto L_08A8A1A8;
L_08A8A1A8:
    ctx.set_gpr(5, 0u | 1u);
    goto L_08A8A1AC;
L_08A8A1AC:
    ctx.set_gpr(7, 0u | 76u);
    goto L_08A8A1B0;
L_08A8A1B0:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(4), ctx.gpr[31]);
    goto L_08A8A1B4;
L_08A8A1B4:
    ctx.set_gpr(31, 0x08A8A1BCu);
    ctx.set_gpr(6, ctx.gpr[6] + static_cast<std::uint32_t>(4489));
    ctx.pc = 0x08864FF0u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08A8A1BCu) goto L_08A8A1BC;
    return;
L_08A8A1BC:
    ctx.set_gpr(2, ctx.gpr[16] | 0u);
    goto L_08A8A1C0;
L_08A8A1C0:
    ctx.set_gpr(16, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(0)));
    goto L_08A8A1C4;
L_08A8A1C4:
    ctx.set_gpr(31, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(4)));
    goto L_08A8A1C8;
L_08A8A1C8:
    jump_target = ctx.gpr[31];
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(16));
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08A8A1D0:
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(-16));
    goto L_08A8A1D4;
L_08A8A1D4:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(0), ctx.gpr[31]);
    goto L_08A8A1D8;
L_08A8A1D8:
    { const bool branch_taken = ctx.gpr[4] == 0u;
    ctx.set_gpr(5, ctx.gpr[5] & 1u);
      if (branch_taken) {
          goto L_08A8A1F0;
      }
      goto L_08A8A1E0;
    }
L_08A8A1E0:
    { const bool branch_taken = ctx.gpr[5] == 0u;
    // nop
      if (branch_taken) {
          goto L_08A8A1F0;
      }
      goto L_08A8A1E8;
    }
L_08A8A1E8:
    ctx.set_gpr(31, 0x08A8A1F0u);
    // nop
    ctx.pc = 0x08992F04u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08A8A1F0u) goto L_08A8A1F0;
    return;
L_08A8A1F0:
    ctx.set_gpr(31, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(0)));
    goto L_08A8A1F4;
L_08A8A1F4:
    jump_target = ctx.gpr[31];
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(16));
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08A8A1FC:
    ctx.set_gpr(4, 2217u << 16u);
    goto L_08A8A200;
L_08A8A200:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(-18520)));
    goto L_08A8A204;
L_08A8A204:
    ctx.set_gpr(5, 2u << 16u);
    goto L_08A8A208;
L_08A8A208:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(780)));
    goto L_08A8A20C;
L_08A8A20C:
    ctx.set_gpr(6, rt.memory().aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(1052)));
    goto L_08A8A210;
L_08A8A210:
    ctx.set_gpr(5, ctx.gpr[6] | ctx.gpr[5]);
    goto L_08A8A214;
L_08A8A214:
    jump_target = ctx.gpr[31];
    rt.memory().aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(1052), ctx.gpr[5]);
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08A8A21C:
    ctx.set_gpr(4, 2217u << 16u);
    goto L_08A8A220;
L_08A8A220:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(-18520)));
    goto L_08A8A224;
L_08A8A224:
    ctx.set_gpr(5, 4u << 16u);
    goto L_08A8A228;
L_08A8A228:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(780)));
    goto L_08A8A22C;
L_08A8A22C:
    ctx.set_gpr(6, rt.memory().aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(1052)));
    goto L_08A8A230;
L_08A8A230:
    ctx.set_gpr(5, ctx.gpr[6] | ctx.gpr[5]);
    goto L_08A8A234;
L_08A8A234:
    jump_target = ctx.gpr[31];
    rt.memory().aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(1052), ctx.gpr[5]);
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08A8A23C:
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(-16));
    goto L_08A8A240;
L_08A8A240:
    ctx.set_gpr(5, ctx.gpr[4] | 0u);
    goto L_08A8A244;
L_08A8A244:
    ctx.set_gpr(4, 2217u << 16u);
    goto L_08A8A248;
L_08A8A248:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(0), ctx.gpr[31]);
    goto L_08A8A24C;
L_08A8A24C:
    ctx.set_gpr(31, 0x08A8A254u);
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(-18520)));
    ctx.pc = 0x08A89894u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08A8A254u) goto L_08A8A254;
    return;
L_08A8A254:
    ctx.set_gpr(31, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(0)));
    goto L_08A8A258;
L_08A8A258:
    jump_target = ctx.gpr[31];
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(16));
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08A8A260:
    ctx.set_gpr(5, 2487u << 16u);
    goto L_08A8A264;
L_08A8A264:
    { const bool branch_taken = ctx.gpr[4] == 0u;
    ctx.set_gpr(5, ctx.gpr[5] + static_cast<std::uint32_t>(-12960));
      if (branch_taken) {
          ctx.pc = 0x08A8A294u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
      }
      goto L_08A8A26C;
    }
L_08A8A26C:
    ctx.set_gpr(6, 0u | 1u);
    goto L_08A8A270;
L_08A8A270:
    { const bool branch_taken = ctx.gpr[4] == ctx.gpr[6];
    // nop
      if (branch_taken) {
          goto L_08A8A28C;
      }
      goto L_08A8A278;
    }
L_08A8A278:
    ctx.set_gpr(6, 0u | 2u);
    goto L_08A8A27C;
L_08A8A27C:
    { const bool branch_taken = ctx.gpr[4] != ctx.gpr[6];
    // nop
      if (branch_taken) {
          ctx.pc = 0x08A8A29Cu; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
      }
      goto L_08A8A284;
    }
L_08A8A284:
    { const bool branch_taken = 0u == 0u;
    ctx.set_gpr(2, rt.memory().aot_load32(ctx.gpr[5] + static_cast<std::uint32_t>(28)));
      if (branch_taken) {
          ctx.pc = 0x08A8A2A0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
      }
      goto L_08A8A28C;
    }
L_08A8A28C:
    { const bool branch_taken = 0u == 0u;
    ctx.set_gpr(2, rt.memory().aot_load32(ctx.gpr[5] + static_cast<std::uint32_t>(24)));
      if (branch_taken) {
          ctx.pc = 0x08A8A2A0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
      }
      ctx.pc = 0x08A8A294u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
    }
}

void sub_08A8A194(Runtime &rt, AllegrexContext &ctx) {
    auto aot_mem = rt.memory().aot_fast_view();
    sub_08A8A194_entry(rt, ctx, 0u, aot_mem);
}

static const std::uint16_t kEntryIds_sub_08A969CC[63] = {
    1, 0, 2, 3, 4, 5, 0, 6, 7, 8, 9, 0, 10, 11, 0, 12, 13, 14, 15, 0, 16, 17, 0, 18, 19, 20, 21, 0, 22, 23, 24, 0,
    25, 0, 26, 0, 27, 28, 0, 29, 30, 31, 32, 0, 33, 34, 0, 35, 36, 37, 38, 39, 40, 41, 0, 42, 43, 44, 45, 46, 47, 48, 49,
};
void sub_08A969CC_entry(Runtime &rt, AllegrexContext &ctx, std::uint16_t direct_entry_id, GuestMemory::AotFastView &aot_mem) {
    std::uint32_t jump_target = 0u;
    std::uint32_t local_transfers = 0u;
    std::uint32_t local_pc = ctx.pc;
    std::uint32_t entry_id = direct_entry_id;
LOCAL_DISPATCH:
    {
    if (entry_id == 0u) {
        const std::uint32_t entry_delta = local_pc - 0x08A969CCu;
        entry_id = (entry_delta < 252u && (entry_delta & 3u) == 0u) ? kEntryIds_sub_08A969CC[entry_delta >> 2u] : 0u;
    }
    switch (entry_id) {
    case 1u: goto L_08A969CC;
    case 2u: goto L_08A969D4;
    case 3u: goto L_08A969D8;
    case 4u: goto L_08A969DC;
    case 5u: goto L_08A969E0;
    case 6u: goto L_08A969E8;
    case 7u: goto L_08A969EC;
    case 8u: goto L_08A969F0;
    case 9u: goto L_08A969F4;
    case 10u: goto L_08A969FC;
    case 11u: goto L_08A96A00;
    case 12u: goto L_08A96A08;
    case 13u: goto L_08A96A0C;
    case 14u: goto L_08A96A10;
    case 15u: goto L_08A96A14;
    case 16u: goto L_08A96A1C;
    case 17u: goto L_08A96A20;
    case 18u: goto L_08A96A28;
    case 19u: goto L_08A96A2C;
    case 20u: goto L_08A96A30;
    case 21u: goto L_08A96A34;
    case 22u: goto L_08A96A3C;
    case 23u: goto L_08A96A40;
    case 24u: goto L_08A96A44;
    case 25u: goto L_08A96A4C;
    case 26u: goto L_08A96A54;
    case 27u: goto L_08A96A5C;
    case 28u: goto L_08A96A60;
    case 29u: goto L_08A96A68;
    case 30u: goto L_08A96A6C;
    case 31u: goto L_08A96A70;
    case 32u: goto L_08A96A74;
    case 33u: goto L_08A96A7C;
    case 34u: goto L_08A96A80;
    case 35u: goto L_08A96A88;
    case 36u: goto L_08A96A8C;
    case 37u: goto L_08A96A90;
    case 38u: goto L_08A96A94;
    case 39u: goto L_08A96A98;
    case 40u: goto L_08A96A9C;
    case 41u: goto L_08A96AA0;
    case 42u: goto L_08A96AA8;
    case 43u: goto L_08A96AAC;
    case 44u: goto L_08A96AB0;
    case 45u: goto L_08A96AB4;
    case 46u: goto L_08A96AB8;
    case 47u: goto L_08A96ABC;
    case 48u: goto L_08A96AC0;
    case 49u: goto L_08A96AC4;
    default:
        if (local_transfers == 0u) rt.unsupported(ctx.pc, 0u, "invalid internal function entry");
        else ctx.pc = local_pc;
        return;
    }
    }
L_08A969CC:
    jump_target = ctx.gpr[31];
    ctx.set_gpr(2, ctx.gpr[4] | 0u);
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08A969D4:
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(-16));
    goto L_08A969D8;
L_08A969D8:
    ctx.set_gpr(4, 2206u << 16u);
    goto L_08A969DC;
L_08A969DC:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(0), ctx.gpr[31]);
    goto L_08A969E0;
L_08A969E0:
    ctx.set_gpr(31, 0x08A969E8u);
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(-31256)));
    ctx.pc = 0x08933C00u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08A969E8u) goto L_08A969E8;
    return;
L_08A969E8:
    ctx.set_gpr(4, 2217u << 16u);
    goto L_08A969EC;
L_08A969EC:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(-18520)));
    goto L_08A969F0;
L_08A969F0:
    ctx.set_gpr(5, 0u | 0u);
    goto L_08A969F4;
L_08A969F4:
    ctx.set_gpr(31, 0x08A969FCu);
    ctx.set_gpr(6, 0u + static_cast<std::uint32_t>(-1));
    ctx.pc = 0x08A88EDCu;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08A969FCu) goto L_08A969FC;
    return;
L_08A969FC:
    ctx.set_gpr(31, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(0)));
    goto L_08A96A00;
L_08A96A00:
    jump_target = ctx.gpr[31];
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(16));
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08A96A08:
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(-16));
    goto L_08A96A0C;
L_08A96A0C:
    ctx.set_gpr(4, 2217u << 16u);
    goto L_08A96A10;
L_08A96A10:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(0), ctx.gpr[31]);
    goto L_08A96A14;
L_08A96A14:
    ctx.set_gpr(31, 0x08A96A1Cu);
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(27176)));
    goto L_08A969D4;
L_08A96A1C:
    ctx.set_gpr(31, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(0)));
    goto L_08A96A20;
L_08A96A20:
    jump_target = ctx.gpr[31];
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(16));
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08A96A28:
    // nop
    goto L_08A96A2C;
L_08A96A2C:
    // nop
    goto L_08A96A30;
L_08A96A30:
    rt.memory().aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(4), 0u);
    goto L_08A96A34;
L_08A96A34:
    jump_target = ctx.gpr[31];
    ctx.set_gpr(2, ctx.gpr[4] | 0u);
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08A96A3C:
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(-16));
    goto L_08A96A40;
L_08A96A40:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(0), ctx.gpr[31]);
    goto L_08A96A44;
L_08A96A44:
    { const bool branch_taken = ctx.gpr[4] == 0u;
    ctx.set_gpr(5, ctx.gpr[5] & 1u);
      if (branch_taken) {
          goto L_08A96A5C;
      }
      goto L_08A96A4C;
    }
L_08A96A4C:
    { const bool branch_taken = ctx.gpr[5] == 0u;
    // nop
      if (branch_taken) {
          goto L_08A96A5C;
      }
      goto L_08A96A54;
    }
L_08A96A54:
    ctx.set_gpr(31, 0x08A96A5Cu);
    // nop
    ctx.pc = 0x08992F04u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08A96A5Cu) goto L_08A96A5C;
    return;
L_08A96A5C:
    ctx.set_gpr(31, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(0)));
    goto L_08A96A60;
L_08A96A60:
    jump_target = ctx.gpr[31];
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(16));
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08A96A68:
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(-16));
    goto L_08A96A6C;
L_08A96A6C:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(0)));
    goto L_08A96A70;
L_08A96A70:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(0), ctx.gpr[31]);
    goto L_08A96A74;
L_08A96A74:
    ctx.set_gpr(31, 0x08A96A7Cu);
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(4)));
    ctx.pc = 0x08B2BA5Cu;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08A96A7Cu) goto L_08A96A7C;
    return;
L_08A96A7C:
    ctx.set_gpr(31, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(0)));
    goto L_08A96A80;
L_08A96A80:
    jump_target = ctx.gpr[31];
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(16));
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08A96A88:
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(-16));
    goto L_08A96A8C;
L_08A96A8C:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(0), ctx.gpr[16]);
    goto L_08A96A90;
L_08A96A90:
    ctx.set_gpr(16, ctx.gpr[4] | 0u);
    goto L_08A96A94;
L_08A96A94:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[16] + static_cast<std::uint32_t>(0)));
    goto L_08A96A98;
L_08A96A98:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(4), ctx.gpr[31]);
    goto L_08A96A9C;
L_08A96A9C:
    ctx.set_gpr(5, rt.memory().aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(60)));
    goto L_08A96AA0;
L_08A96AA0:
    ctx.set_gpr(31, 0x08A96AA8u);
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(4)));
    ctx.pc = 0x08B2BB2Cu;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08A96AA8u) goto L_08A96AA8;
    return;
L_08A96AA8:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[16] + static_cast<std::uint32_t>(0)));
    goto L_08A96AAC;
L_08A96AAC:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(4)));
    goto L_08A96AB0;
L_08A96AB0:
    ctx.set_gpr(6, rt.memory().aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(2588)));
    goto L_08A96AB4;
L_08A96AB4:
    ctx.set_gpr(6, ctx.gpr[6] + static_cast<std::uint32_t>(8));
    goto L_08A96AB8;
L_08A96AB8:
    ctx.set_gpr(7, static_cast<std::uint32_t>(static_cast<std::int32_t>(static_cast<std::int16_t>(rt.memory().aot_load16(ctx.gpr[6] + static_cast<std::uint32_t>(0))))));
    goto L_08A96ABC;
L_08A96ABC:
    ctx.set_gpr(6, rt.memory().aot_load32(ctx.gpr[6] + static_cast<std::uint32_t>(4)));
    goto L_08A96AC0;
L_08A96AC0:
    ctx.set_gpr(5, 0u | 2u);
    goto L_08A96AC4;
L_08A96AC4:
    jump_target = ctx.gpr[6];
    ctx.set_gpr(31, 0x08A96ACCu);
    ctx.set_gpr(4, ctx.gpr[4] + ctx.gpr[7]);
    ctx.pc = jump_target;
    (void)rt.invoke_chained_call(ctx, &aot_mem);
    return;
}

void sub_08A969CC(Runtime &rt, AllegrexContext &ctx) {
    auto aot_mem = rt.memory().aot_fast_view();
    sub_08A969CC_entry(rt, ctx, 0u, aot_mem);
}

static const std::uint16_t kEntryIds_sub_08A9CBDC[64] = {
    1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 10, 0, 11, 0, 12, 13, 14, 15, 0, 16, 17, 18, 19, 20, 21, 0, 22, 23, 0, 24, 25, 0,
    26, 0, 27, 28, 29, 30, 0, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 0, 53, 54,
};
void sub_08A9CBDC_entry(Runtime &rt, AllegrexContext &ctx, std::uint16_t direct_entry_id, GuestMemory::AotFastView &aot_mem) {
    std::uint32_t jump_target = 0u;
    std::uint32_t local_transfers = 0u;
    std::uint32_t local_pc = ctx.pc;
    std::uint32_t entry_id = direct_entry_id;
LOCAL_DISPATCH:
    {
    if (entry_id == 0u) {
        const std::uint32_t entry_delta = local_pc - 0x08A9CBDCu;
        entry_id = (entry_delta < 256u && (entry_delta & 3u) == 0u) ? kEntryIds_sub_08A9CBDC[entry_delta >> 2u] : 0u;
    }
    switch (entry_id) {
    case 1u: goto L_08A9CBDC;
    case 2u: goto L_08A9CBE0;
    case 3u: goto L_08A9CBE4;
    case 4u: goto L_08A9CBE8;
    case 5u: goto L_08A9CBEC;
    case 6u: goto L_08A9CBF0;
    case 7u: goto L_08A9CBF4;
    case 8u: goto L_08A9CBF8;
    case 9u: goto L_08A9CBFC;
    case 10u: goto L_08A9CC04;
    case 11u: goto L_08A9CC0C;
    case 12u: goto L_08A9CC14;
    case 13u: goto L_08A9CC18;
    case 14u: goto L_08A9CC1C;
    case 15u: goto L_08A9CC20;
    case 16u: goto L_08A9CC28;
    case 17u: goto L_08A9CC2C;
    case 18u: goto L_08A9CC30;
    case 19u: goto L_08A9CC34;
    case 20u: goto L_08A9CC38;
    case 21u: goto L_08A9CC3C;
    case 22u: goto L_08A9CC44;
    case 23u: goto L_08A9CC48;
    case 24u: goto L_08A9CC50;
    case 25u: goto L_08A9CC54;
    case 26u: goto L_08A9CC5C;
    case 27u: goto L_08A9CC64;
    case 28u: goto L_08A9CC68;
    case 29u: goto L_08A9CC6C;
    case 30u: goto L_08A9CC70;
    case 31u: goto L_08A9CC78;
    case 32u: goto L_08A9CC7C;
    case 33u: goto L_08A9CC80;
    case 34u: goto L_08A9CC84;
    case 35u: goto L_08A9CC88;
    case 36u: goto L_08A9CC8C;
    case 37u: goto L_08A9CC90;
    case 38u: goto L_08A9CC94;
    case 39u: goto L_08A9CC98;
    case 40u: goto L_08A9CC9C;
    case 41u: goto L_08A9CCA0;
    case 42u: goto L_08A9CCA4;
    case 43u: goto L_08A9CCA8;
    case 44u: goto L_08A9CCAC;
    case 45u: goto L_08A9CCB0;
    case 46u: goto L_08A9CCB4;
    case 47u: goto L_08A9CCB8;
    case 48u: goto L_08A9CCBC;
    case 49u: goto L_08A9CCC0;
    case 50u: goto L_08A9CCC4;
    case 51u: goto L_08A9CCC8;
    case 52u: goto L_08A9CCCC;
    case 53u: goto L_08A9CCD4;
    case 54u: goto L_08A9CCD8;
    default:
        if (local_transfers == 0u) rt.unsupported(ctx.pc, 0u, "invalid internal function entry");
        else ctx.pc = local_pc;
        return;
    }
    }
L_08A9CBDC:
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(-16));
    goto L_08A9CBE0;
L_08A9CBE0:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(0), ctx.gpr[16]);
    goto L_08A9CBE4;
L_08A9CBE4:
    ctx.set_gpr(16, ctx.gpr[4] | 0u);
    goto L_08A9CBE8;
L_08A9CBE8:
    ctx.set_gpr(6, 1u << 16u);
    goto L_08A9CBEC;
L_08A9CBEC:
    ctx.set_gpr(4, ctx.gpr[16] + static_cast<std::uint32_t>(256));
    goto L_08A9CBF0;
L_08A9CBF0:
    ctx.set_gpr(5, 0u | 1u);
    goto L_08A9CBF4;
L_08A9CBF4:
    ctx.set_gpr(7, 0u | 76u);
    goto L_08A9CBF8;
L_08A9CBF8:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(4), ctx.gpr[31]);
    goto L_08A9CBFC;
L_08A9CBFC:
    ctx.set_gpr(31, 0x08A9CC04u);
    ctx.set_gpr(6, ctx.gpr[6] + static_cast<std::uint32_t>(4487));
    ctx.pc = 0x08864FF0u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08A9CC04u) goto L_08A9CC04;
    return;
L_08A9CC04:
    ctx.set_gpr(31, 0x08A9CC0Cu);
    ctx.set_gpr(4, ctx.gpr[16] + static_cast<std::uint32_t>(344));
    ctx.pc = 0x0891A810u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08A9CC0Cu) goto L_08A9CC0C;
    return;
L_08A9CC0C:
    ctx.set_gpr(31, 0x08A9CC14u);
    ctx.set_gpr(4, ctx.gpr[16] + static_cast<std::uint32_t>(2196));
    ctx.pc = 0x08AB41E0u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08A9CC14u) goto L_08A9CC14;
    return;
L_08A9CC14:
    ctx.set_gpr(2, ctx.gpr[16] | 0u);
    goto L_08A9CC18;
L_08A9CC18:
    ctx.set_gpr(16, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(0)));
    goto L_08A9CC1C;
L_08A9CC1C:
    ctx.set_gpr(31, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(4)));
    goto L_08A9CC20;
L_08A9CC20:
    jump_target = ctx.gpr[31];
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(16));
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08A9CC28:
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(-16));
    goto L_08A9CC2C;
L_08A9CC2C:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(4), ctx.gpr[17]);
    goto L_08A9CC30;
L_08A9CC30:
    ctx.set_gpr(17, ctx.gpr[4] | 0u);
    goto L_08A9CC34;
L_08A9CC34:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(0), ctx.gpr[16]);
    goto L_08A9CC38;
L_08A9CC38:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(8), ctx.gpr[31]);
    goto L_08A9CC3C;
L_08A9CC3C:
    { const bool branch_taken = ctx.gpr[4] == 0u;
    ctx.set_gpr(16, ctx.gpr[5] | 0u);
      if (branch_taken) {
          goto L_08A9CC64;
      }
      goto L_08A9CC44;
    }
L_08A9CC44:
    ctx.set_gpr(4, ctx.gpr[17] + static_cast<std::uint32_t>(2196));
    goto L_08A9CC48;
L_08A9CC48:
    ctx.set_gpr(31, 0x08A9CC50u);
    ctx.set_gpr(5, 0u | 2u);
    ctx.pc = 0x08AB4228u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08A9CC50u) goto L_08A9CC50;
    return;
L_08A9CC50:
    ctx.set_gpr(4, ctx.gpr[16] & 1u);
    goto L_08A9CC54;
L_08A9CC54:
    { const bool branch_taken = ctx.gpr[4] == 0u;
    // nop
      if (branch_taken) {
          goto L_08A9CC64;
      }
      goto L_08A9CC5C;
    }
L_08A9CC5C:
    ctx.set_gpr(31, 0x08A9CC64u);
    ctx.set_gpr(4, ctx.gpr[17] | 0u);
    ctx.pc = 0x08992F04u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08A9CC64u) goto L_08A9CC64;
    return;
L_08A9CC64:
    ctx.set_gpr(16, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(0)));
    goto L_08A9CC68;
L_08A9CC68:
    ctx.set_gpr(17, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(4)));
    goto L_08A9CC6C;
L_08A9CC6C:
    ctx.set_gpr(31, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(8)));
    goto L_08A9CC70;
L_08A9CC70:
    jump_target = ctx.gpr[31];
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(16));
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08A9CC78:
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(-32));
    goto L_08A9CC7C;
L_08A9CC7C:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(12), ctx.gpr[16]);
    goto L_08A9CC80;
L_08A9CC80:
    ctx.set_gpr(16, ctx.gpr[7] | 0u);
    goto L_08A9CC84;
L_08A9CC84:
    ctx.set_gpr(4, static_cast<std::uint32_t>(static_cast<std::int32_t>(static_cast<std::int8_t>(rt.memory().aot_load8(ctx.gpr[9] + static_cast<std::uint32_t>(0))))));
    goto L_08A9CC88;
L_08A9CC88:
    ctx.set_gpr(7, ctx.gpr[6] | 0u);
    goto L_08A9CC8C;
L_08A9CC8C:
    ctx.set_gpr(5, static_cast<std::uint32_t>(static_cast<std::int32_t>(static_cast<std::int8_t>(rt.memory().aot_load8(ctx.gpr[9] + static_cast<std::uint32_t>(1))))));
    goto L_08A9CC90;
L_08A9CC90:
    ctx.set_gpr(6, static_cast<std::uint32_t>(static_cast<std::int32_t>(static_cast<std::int8_t>(rt.memory().aot_load8(ctx.gpr[9] + static_cast<std::uint32_t>(2))))));
    goto L_08A9CC94;
L_08A9CC94:
    rt.memory().aot_store8(ctx.gpr[29] + static_cast<std::uint32_t>(6), static_cast<std::uint8_t>(ctx.gpr[4]));
    goto L_08A9CC98;
L_08A9CC98:
    rt.memory().aot_store8(ctx.gpr[29] + static_cast<std::uint32_t>(7), static_cast<std::uint8_t>(ctx.gpr[5]));
    goto L_08A9CC9C;
L_08A9CC9C:
    rt.memory().aot_store8(ctx.gpr[29] + static_cast<std::uint32_t>(8), static_cast<std::uint8_t>(ctx.gpr[6]));
    goto L_08A9CCA0;
L_08A9CCA0:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(16), ctx.gpr[17]);
    goto L_08A9CCA4;
L_08A9CCA4:
    ctx.set_gpr(17, static_cast<std::uint32_t>(static_cast<std::int32_t>(static_cast<std::int8_t>(rt.memory().aot_load8(ctx.gpr[9] + static_cast<std::uint32_t>(3))))));
    goto L_08A9CCA8;
L_08A9CCA8:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(20), ctx.gpr[18]);
    goto L_08A9CCAC;
L_08A9CCAC:
    ctx.set_gpr(18, static_cast<std::uint32_t>(static_cast<std::int32_t>(static_cast<std::int8_t>(rt.memory().aot_load8(ctx.gpr[9] + static_cast<std::uint32_t>(4))))));
    goto L_08A9CCB0;
L_08A9CCB0:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(24), ctx.gpr[19]);
    goto L_08A9CCB4;
L_08A9CCB4:
    ctx.set_gpr(19, static_cast<std::uint32_t>(static_cast<std::int32_t>(static_cast<std::int8_t>(rt.memory().aot_load8(ctx.gpr[9] + static_cast<std::uint32_t>(5))))));
    goto L_08A9CCB8;
L_08A9CCB8:
    ctx.set_gpr(4, 2218u << 16u);
    goto L_08A9CCBC;
L_08A9CCBC:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(16196)));
    goto L_08A9CCC0;
L_08A9CCC0:
    ctx.set_gpr(5, 0u | 3u);
    goto L_08A9CCC4;
L_08A9CCC4:
    ctx.set_gpr(6, 0u | 0u);
    goto L_08A9CCC8;
L_08A9CCC8:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(28), ctx.gpr[31]);
    goto L_08A9CCCC;
L_08A9CCCC:
    ctx.set_gpr(31, 0x08A9CCD4u);
    ctx.set_gpr(8, 0u | 0u);
    ctx.pc = 0x08A97E34u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08A9CCD4u) goto L_08A9CCD4;
    return;
L_08A9CCD4:
    ctx.set_gpr(5, ctx.gpr[16] | 0u);
    goto L_08A9CCD8;
L_08A9CCD8:
    ctx.set_gpr(4, 2487u << 16u);
    ctx.pc = 0x08A9CCDCu; return;
}

void sub_08A9CBDC(Runtime &rt, AllegrexContext &ctx) {
    auto aot_mem = rt.memory().aot_fast_view();
    sub_08A9CBDC_entry(rt, ctx, 0u, aot_mem);
}

static const std::uint16_t kEntryIds_sub_08B1F0BC[64] = {
    1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 10, 11, 12, 13, 0, 14, 15, 16, 0, 17, 0, 18, 0, 19, 20, 0, 21, 22, 23, 24, 25, 26,
    27, 28, 29, 30, 31, 32, 0, 33, 34, 35, 0, 36, 37, 38, 39, 0, 40, 41, 42, 43, 44, 45, 46, 47, 48, 0, 49, 50, 0, 51, 52, 53,
};
void sub_08B1F0BC_entry(Runtime &rt, AllegrexContext &ctx, std::uint16_t direct_entry_id, GuestMemory::AotFastView &aot_mem) {
    std::uint32_t jump_target = 0u;
    std::uint32_t local_transfers = 0u;
    std::uint32_t local_pc = ctx.pc;
    std::uint32_t entry_id = direct_entry_id;
LOCAL_DISPATCH:
    {
    if (entry_id == 0u) {
        const std::uint32_t entry_delta = local_pc - 0x08B1F0BCu;
        entry_id = (entry_delta < 256u && (entry_delta & 3u) == 0u) ? kEntryIds_sub_08B1F0BC[entry_delta >> 2u] : 0u;
    }
    switch (entry_id) {
    case 1u: goto L_08B1F0BC;
    case 2u: goto L_08B1F0C0;
    case 3u: goto L_08B1F0C4;
    case 4u: goto L_08B1F0C8;
    case 5u: goto L_08B1F0CC;
    case 6u: goto L_08B1F0D0;
    case 7u: goto L_08B1F0D4;
    case 8u: goto L_08B1F0D8;
    case 9u: goto L_08B1F0DC;
    case 10u: goto L_08B1F0E4;
    case 11u: goto L_08B1F0E8;
    case 12u: goto L_08B1F0EC;
    case 13u: goto L_08B1F0F0;
    case 14u: goto L_08B1F0F8;
    case 15u: goto L_08B1F0FC;
    case 16u: goto L_08B1F100;
    case 17u: goto L_08B1F108;
    case 18u: goto L_08B1F110;
    case 19u: goto L_08B1F118;
    case 20u: goto L_08B1F11C;
    case 21u: goto L_08B1F124;
    case 22u: goto L_08B1F128;
    case 23u: goto L_08B1F12C;
    case 24u: goto L_08B1F130;
    case 25u: goto L_08B1F134;
    case 26u: goto L_08B1F138;
    case 27u: goto L_08B1F13C;
    case 28u: goto L_08B1F140;
    case 29u: goto L_08B1F144;
    case 30u: goto L_08B1F148;
    case 31u: goto L_08B1F14C;
    case 32u: goto L_08B1F150;
    case 33u: goto L_08B1F158;
    case 34u: goto L_08B1F15C;
    case 35u: goto L_08B1F160;
    case 36u: goto L_08B1F168;
    case 37u: goto L_08B1F16C;
    case 38u: goto L_08B1F170;
    case 39u: goto L_08B1F174;
    case 40u: goto L_08B1F17C;
    case 41u: goto L_08B1F180;
    case 42u: goto L_08B1F184;
    case 43u: goto L_08B1F188;
    case 44u: goto L_08B1F18C;
    case 45u: goto L_08B1F190;
    case 46u: goto L_08B1F194;
    case 47u: goto L_08B1F198;
    case 48u: goto L_08B1F19C;
    case 49u: goto L_08B1F1A4;
    case 50u: goto L_08B1F1A8;
    case 51u: goto L_08B1F1B0;
    case 52u: goto L_08B1F1B4;
    case 53u: goto L_08B1F1B8;
    default:
        if (local_transfers == 0u) rt.unsupported(ctx.pc, 0u, "invalid internal function entry");
        else ctx.pc = local_pc;
        return;
    }
    }
L_08B1F0BC:
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(-16));
    goto L_08B1F0C0;
L_08B1F0C0:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(0), ctx.gpr[16]);
    goto L_08B1F0C4;
L_08B1F0C4:
    ctx.set_gpr(16, ctx.gpr[4] | 0u);
    goto L_08B1F0C8;
L_08B1F0C8:
    ctx.set_gpr(6, 1u << 16u);
    goto L_08B1F0CC;
L_08B1F0CC:
    ctx.set_gpr(4, ctx.gpr[16] + static_cast<std::uint32_t>(256));
    goto L_08B1F0D0;
L_08B1F0D0:
    ctx.set_gpr(5, 0u | 2u);
    goto L_08B1F0D4;
L_08B1F0D4:
    ctx.set_gpr(7, 0u | 67u);
    goto L_08B1F0D8;
L_08B1F0D8:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(4), ctx.gpr[31]);
    goto L_08B1F0DC;
L_08B1F0DC:
    ctx.set_gpr(31, 0x08B1F0E4u);
    ctx.set_gpr(6, ctx.gpr[6] + static_cast<std::uint32_t>(4470));
    ctx.pc = 0x08864FF0u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B1F0E4u) goto L_08B1F0E4;
    return;
L_08B1F0E4:
    ctx.set_gpr(2, ctx.gpr[16] | 0u);
    goto L_08B1F0E8;
L_08B1F0E8:
    ctx.set_gpr(16, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(0)));
    goto L_08B1F0EC;
L_08B1F0EC:
    ctx.set_gpr(31, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(4)));
    goto L_08B1F0F0;
L_08B1F0F0:
    jump_target = ctx.gpr[31];
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(16));
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08B1F0F8:
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(-16));
    goto L_08B1F0FC;
L_08B1F0FC:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(0), ctx.gpr[31]);
    goto L_08B1F100;
L_08B1F100:
    { const bool branch_taken = ctx.gpr[4] == 0u;
    ctx.set_gpr(5, ctx.gpr[5] & 1u);
      if (branch_taken) {
          goto L_08B1F118;
      }
      goto L_08B1F108;
    }
L_08B1F108:
    { const bool branch_taken = ctx.gpr[5] == 0u;
    // nop
      if (branch_taken) {
          goto L_08B1F118;
      }
      goto L_08B1F110;
    }
L_08B1F110:
    ctx.set_gpr(31, 0x08B1F118u);
    // nop
    ctx.pc = 0x08992F04u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B1F118u) goto L_08B1F118;
    return;
L_08B1F118:
    ctx.set_gpr(31, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(0)));
    goto L_08B1F11C;
L_08B1F11C:
    jump_target = ctx.gpr[31];
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(16));
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08B1F124:
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(-16));
    goto L_08B1F128;
L_08B1F128:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(0), ctx.gpr[16]);
    goto L_08B1F12C;
L_08B1F12C:
    ctx.set_gpr(16, ctx.gpr[4] | 0u);
    goto L_08B1F130;
L_08B1F130:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(4), ctx.gpr[17]);
    goto L_08B1F134;
L_08B1F134:
    ctx.set_gpr(17, ctx.gpr[16] + static_cast<std::uint32_t>(256));
    goto L_08B1F138;
L_08B1F138:
    ctx.set_gpr(5, 2226u << 16u);
    goto L_08B1F13C;
L_08B1F13C:
    ctx.set_gpr(6, 2226u << 16u);
    goto L_08B1F140;
L_08B1F140:
    ctx.set_gpr(4, ctx.gpr[17] | 0u);
    goto L_08B1F144;
L_08B1F144:
    ctx.set_gpr(7, 0u | 0u);
    goto L_08B1F148;
L_08B1F148:
    ctx.set_gpr(5, ctx.gpr[5] + static_cast<std::uint32_t>(-2764));
    goto L_08B1F14C;
L_08B1F14C:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(8), ctx.gpr[31]);
    goto L_08B1F150;
L_08B1F150:
    ctx.set_gpr(31, 0x08B1F158u);
    ctx.set_gpr(6, ctx.gpr[6] + static_cast<std::uint32_t>(-2732));
    ctx.pc = 0x0886503Cu;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B1F158u) goto L_08B1F158;
    return;
L_08B1F158:
    ctx.set_gpr(4, ctx.gpr[17] | 0u);
    goto L_08B1F15C;
L_08B1F15C:
    ctx.set_gpr(5, ctx.gpr[16] | 0u);
    goto L_08B1F160;
L_08B1F160:
    ctx.set_gpr(31, 0x08B1F168u);
    ctx.set_gpr(6, 0u | 256u);
    ctx.pc = 0x0886504Cu;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B1F168u) goto L_08B1F168;
    return;
L_08B1F168:
    ctx.set_gpr(16, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(0)));
    goto L_08B1F16C;
L_08B1F16C:
    ctx.set_gpr(17, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(4)));
    goto L_08B1F170;
L_08B1F170:
    ctx.set_gpr(31, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(8)));
    goto L_08B1F174;
L_08B1F174:
    jump_target = ctx.gpr[31];
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(16));
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08B1F17C:
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(-16));
    goto L_08B1F180;
L_08B1F180:
    ctx.set_gpr(9, 2487u << 16u);
    goto L_08B1F184;
L_08B1F184:
    rt.memory().aot_store32(ctx.gpr[9] + static_cast<std::uint32_t>(-9680), ctx.gpr[5]);
    goto L_08B1F188;
L_08B1F188:
    ctx.set_gpr(5, ctx.gpr[9] + static_cast<std::uint32_t>(-9680));
    goto L_08B1F18C;
L_08B1F18C:
    rt.memory().aot_store32(ctx.gpr[5] + static_cast<std::uint32_t>(4), ctx.gpr[6]);
    goto L_08B1F190;
L_08B1F190:
    rt.memory().aot_store32(ctx.gpr[5] + static_cast<std::uint32_t>(8), ctx.gpr[7]);
    goto L_08B1F194;
L_08B1F194:
    rt.memory().aot_store32(ctx.gpr[5] + static_cast<std::uint32_t>(12), ctx.gpr[8]);
    goto L_08B1F198;
L_08B1F198:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(0), ctx.gpr[31]);
    goto L_08B1F19C;
L_08B1F19C:
    ctx.set_gpr(31, 0x08B1F1A4u);
    ctx.set_gpr(4, ctx.gpr[4] + static_cast<std::uint32_t>(256));
    ctx.pc = 0x088650A4u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B1F1A4u) goto L_08B1F1A4;
    return;
L_08B1F1A4:
    ctx.set_gpr(31, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(0)));
    goto L_08B1F1A8;
L_08B1F1A8:
    jump_target = ctx.gpr[31];
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(16));
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08B1F1B0:
    ctx.set_gpr(4, 2226u << 16u);
    goto L_08B1F1B4;
L_08B1F1B4:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(11928)));
    goto L_08B1F1B8;
L_08B1F1B8:
    ctx.set_gpr(5, 1u << 16u);
    ctx.pc = 0x08B1F1BCu; return;
}

void sub_08B1F0BC(Runtime &rt, AllegrexContext &ctx) {
    auto aot_mem = rt.memory().aot_fast_view();
    sub_08B1F0BC_entry(rt, ctx, 0u, aot_mem);
}

static const std::uint16_t kEntryIds_sub_08B0C00C[64] = {
    1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 10, 11, 12, 13, 0, 14, 15, 16, 0, 17, 0, 18, 0, 19, 20, 0, 21, 22, 23, 24, 25, 26,
    27, 28, 29, 30, 31, 32, 0, 33, 34, 35, 0, 36, 37, 38, 39, 0, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 0, 50, 51, 0, 52, 53,
};
void sub_08B0C00C_entry(Runtime &rt, AllegrexContext &ctx, std::uint16_t direct_entry_id, GuestMemory::AotFastView &aot_mem) {
    std::uint32_t jump_target = 0u;
    std::uint32_t local_transfers = 0u;
    std::uint32_t local_pc = ctx.pc;
    std::uint32_t entry_id = direct_entry_id;
LOCAL_DISPATCH:
    {
    if (entry_id == 0u) {
        const std::uint32_t entry_delta = local_pc - 0x08B0C00Cu;
        entry_id = (entry_delta < 256u && (entry_delta & 3u) == 0u) ? kEntryIds_sub_08B0C00C[entry_delta >> 2u] : 0u;
    }
    switch (entry_id) {
    case 1u: goto L_08B0C00C;
    case 2u: goto L_08B0C010;
    case 3u: goto L_08B0C014;
    case 4u: goto L_08B0C018;
    case 5u: goto L_08B0C01C;
    case 6u: goto L_08B0C020;
    case 7u: goto L_08B0C024;
    case 8u: goto L_08B0C028;
    case 9u: goto L_08B0C02C;
    case 10u: goto L_08B0C034;
    case 11u: goto L_08B0C038;
    case 12u: goto L_08B0C03C;
    case 13u: goto L_08B0C040;
    case 14u: goto L_08B0C048;
    case 15u: goto L_08B0C04C;
    case 16u: goto L_08B0C050;
    case 17u: goto L_08B0C058;
    case 18u: goto L_08B0C060;
    case 19u: goto L_08B0C068;
    case 20u: goto L_08B0C06C;
    case 21u: goto L_08B0C074;
    case 22u: goto L_08B0C078;
    case 23u: goto L_08B0C07C;
    case 24u: goto L_08B0C080;
    case 25u: goto L_08B0C084;
    case 26u: goto L_08B0C088;
    case 27u: goto L_08B0C08C;
    case 28u: goto L_08B0C090;
    case 29u: goto L_08B0C094;
    case 30u: goto L_08B0C098;
    case 31u: goto L_08B0C09C;
    case 32u: goto L_08B0C0A0;
    case 33u: goto L_08B0C0A8;
    case 34u: goto L_08B0C0AC;
    case 35u: goto L_08B0C0B0;
    case 36u: goto L_08B0C0B8;
    case 37u: goto L_08B0C0BC;
    case 38u: goto L_08B0C0C0;
    case 39u: goto L_08B0C0C4;
    case 40u: goto L_08B0C0CC;
    case 41u: goto L_08B0C0D0;
    case 42u: goto L_08B0C0D4;
    case 43u: goto L_08B0C0D8;
    case 44u: goto L_08B0C0DC;
    case 45u: goto L_08B0C0E0;
    case 46u: goto L_08B0C0E4;
    case 47u: goto L_08B0C0E8;
    case 48u: goto L_08B0C0EC;
    case 49u: goto L_08B0C0F0;
    case 50u: goto L_08B0C0F8;
    case 51u: goto L_08B0C0FC;
    case 52u: goto L_08B0C104;
    case 53u: goto L_08B0C108;
    default:
        if (local_transfers == 0u) rt.unsupported(ctx.pc, 0u, "invalid internal function entry");
        else ctx.pc = local_pc;
        return;
    }
    }
L_08B0C00C:
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(-16));
    goto L_08B0C010;
L_08B0C010:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(0), ctx.gpr[16]);
    goto L_08B0C014;
L_08B0C014:
    ctx.set_gpr(16, ctx.gpr[4] | 0u);
    goto L_08B0C018;
L_08B0C018:
    ctx.set_gpr(6, 1u << 16u);
    goto L_08B0C01C;
L_08B0C01C:
    ctx.set_gpr(4, ctx.gpr[16] + static_cast<std::uint32_t>(256));
    goto L_08B0C020;
L_08B0C020:
    ctx.set_gpr(5, 0u | 2u);
    goto L_08B0C024;
L_08B0C024:
    ctx.set_gpr(7, 0u | 67u);
    goto L_08B0C028;
L_08B0C028:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(4), ctx.gpr[31]);
    goto L_08B0C02C;
L_08B0C02C:
    ctx.set_gpr(31, 0x08B0C034u);
    ctx.set_gpr(6, ctx.gpr[6] + static_cast<std::uint32_t>(4470));
    ctx.pc = 0x08864FF0u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B0C034u) goto L_08B0C034;
    return;
L_08B0C034:
    ctx.set_gpr(2, ctx.gpr[16] | 0u);
    goto L_08B0C038;
L_08B0C038:
    ctx.set_gpr(16, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(0)));
    goto L_08B0C03C;
L_08B0C03C:
    ctx.set_gpr(31, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(4)));
    goto L_08B0C040;
L_08B0C040:
    jump_target = ctx.gpr[31];
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(16));
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08B0C048:
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(-16));
    goto L_08B0C04C;
L_08B0C04C:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(0), ctx.gpr[31]);
    goto L_08B0C050;
L_08B0C050:
    { const bool branch_taken = ctx.gpr[4] == 0u;
    ctx.set_gpr(5, ctx.gpr[5] & 1u);
      if (branch_taken) {
          goto L_08B0C068;
      }
      goto L_08B0C058;
    }
L_08B0C058:
    { const bool branch_taken = ctx.gpr[5] == 0u;
    // nop
      if (branch_taken) {
          goto L_08B0C068;
      }
      goto L_08B0C060;
    }
L_08B0C060:
    ctx.set_gpr(31, 0x08B0C068u);
    // nop
    ctx.pc = 0x08992F04u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B0C068u) goto L_08B0C068;
    return;
L_08B0C068:
    ctx.set_gpr(31, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(0)));
    goto L_08B0C06C;
L_08B0C06C:
    jump_target = ctx.gpr[31];
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(16));
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08B0C074:
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(-16));
    goto L_08B0C078;
L_08B0C078:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(0), ctx.gpr[16]);
    goto L_08B0C07C;
L_08B0C07C:
    ctx.set_gpr(16, ctx.gpr[4] | 0u);
    goto L_08B0C080;
L_08B0C080:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(4), ctx.gpr[17]);
    goto L_08B0C084;
L_08B0C084:
    ctx.set_gpr(17, ctx.gpr[16] + static_cast<std::uint32_t>(256));
    goto L_08B0C088;
L_08B0C088:
    ctx.set_gpr(5, 2225u << 16u);
    goto L_08B0C08C;
L_08B0C08C:
    ctx.set_gpr(6, 2225u << 16u);
    goto L_08B0C090;
L_08B0C090:
    ctx.set_gpr(4, ctx.gpr[17] | 0u);
    goto L_08B0C094;
L_08B0C094:
    ctx.set_gpr(7, 0u | 0u);
    goto L_08B0C098;
L_08B0C098:
    ctx.set_gpr(5, ctx.gpr[5] + static_cast<std::uint32_t>(-15552));
    goto L_08B0C09C;
L_08B0C09C:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(8), ctx.gpr[31]);
    goto L_08B0C0A0;
L_08B0C0A0:
    ctx.set_gpr(31, 0x08B0C0A8u);
    ctx.set_gpr(6, ctx.gpr[6] + static_cast<std::uint32_t>(-15520));
    ctx.pc = 0x0886503Cu;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B0C0A8u) goto L_08B0C0A8;
    return;
L_08B0C0A8:
    ctx.set_gpr(4, ctx.gpr[17] | 0u);
    goto L_08B0C0AC;
L_08B0C0AC:
    ctx.set_gpr(5, ctx.gpr[16] | 0u);
    goto L_08B0C0B0;
L_08B0C0B0:
    ctx.set_gpr(31, 0x08B0C0B8u);
    ctx.set_gpr(6, 0u | 256u);
    ctx.pc = 0x0886504Cu;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B0C0B8u) goto L_08B0C0B8;
    return;
L_08B0C0B8:
    ctx.set_gpr(16, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(0)));
    goto L_08B0C0BC;
L_08B0C0BC:
    ctx.set_gpr(17, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(4)));
    goto L_08B0C0C0;
L_08B0C0C0:
    ctx.set_gpr(31, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(8)));
    goto L_08B0C0C4;
L_08B0C0C4:
    jump_target = ctx.gpr[31];
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(16));
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08B0C0CC:
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(-16));
    goto L_08B0C0D0;
L_08B0C0D0:
    ctx.set_gpr(8, 2487u << 16u);
    goto L_08B0C0D4;
L_08B0C0D4:
    rt.memory().aot_store32(ctx.gpr[8] + static_cast<std::uint32_t>(-10136), ctx.gpr[5]);
    goto L_08B0C0D8;
L_08B0C0D8:
    ctx.set_gpr(5, ctx.gpr[8] + static_cast<std::uint32_t>(-10136));
    goto L_08B0C0DC;
L_08B0C0DC:
    rt.memory().aot_store32(ctx.gpr[5] + static_cast<std::uint32_t>(4), 0u);
    goto L_08B0C0E0;
L_08B0C0E0:
    rt.memory().aot_store32(ctx.gpr[5] + static_cast<std::uint32_t>(356), 0u);
    goto L_08B0C0E4;
L_08B0C0E4:
    rt.memory().aot_store32(ctx.gpr[5] + static_cast<std::uint32_t>(360), ctx.gpr[6]);
    goto L_08B0C0E8;
L_08B0C0E8:
    rt.memory().aot_store32(ctx.gpr[5] + static_cast<std::uint32_t>(364), ctx.gpr[7]);
    goto L_08B0C0EC;
L_08B0C0EC:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(0), ctx.gpr[31]);
    goto L_08B0C0F0;
L_08B0C0F0:
    ctx.set_gpr(31, 0x08B0C0F8u);
    ctx.set_gpr(4, ctx.gpr[4] + static_cast<std::uint32_t>(256));
    ctx.pc = 0x088650A4u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B0C0F8u) goto L_08B0C0F8;
    return;
L_08B0C0F8:
    ctx.set_gpr(31, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(0)));
    goto L_08B0C0FC;
L_08B0C0FC:
    jump_target = ctx.gpr[31];
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(16));
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08B0C104:
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(-16));
    goto L_08B0C108;
L_08B0C108:
    ctx.set_gpr(7, 2487u << 16u);
    ctx.pc = 0x08B0C10Cu; return;
}

void sub_08B0C00C(Runtime &rt, AllegrexContext &ctx) {
    auto aot_mem = rt.memory().aot_fast_view();
    sub_08B0C00C_entry(rt, ctx, 0u, aot_mem);
}

static const std::uint16_t kEntryIds_sub_08AB9C18[64] = {
    1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 10, 11, 12, 13, 0, 14, 15, 16, 0, 17, 0, 18, 0, 19, 20, 0, 21, 22, 23, 24, 25, 26,
    0, 27, 28, 29, 30, 31, 32, 0, 33, 34, 35, 36, 37, 38, 39, 0, 40, 41, 42, 43, 44, 45, 46, 47, 48, 0, 49, 50, 51, 52, 53, 54,
};
void sub_08AB9C18_entry(Runtime &rt, AllegrexContext &ctx, std::uint16_t direct_entry_id, GuestMemory::AotFastView &aot_mem) {
    std::uint32_t jump_target = 0u;
    std::uint32_t local_transfers = 0u;
    std::uint32_t local_pc = ctx.pc;
    std::uint32_t entry_id = direct_entry_id;
LOCAL_DISPATCH:
    {
    if (entry_id == 0u) {
        const std::uint32_t entry_delta = local_pc - 0x08AB9C18u;
        entry_id = (entry_delta < 256u && (entry_delta & 3u) == 0u) ? kEntryIds_sub_08AB9C18[entry_delta >> 2u] : 0u;
    }
    switch (entry_id) {
    case 1u: goto L_08AB9C18;
    case 2u: goto L_08AB9C1C;
    case 3u: goto L_08AB9C20;
    case 4u: goto L_08AB9C24;
    case 5u: goto L_08AB9C28;
    case 6u: goto L_08AB9C2C;
    case 7u: goto L_08AB9C30;
    case 8u: goto L_08AB9C34;
    case 9u: goto L_08AB9C38;
    case 10u: goto L_08AB9C40;
    case 11u: goto L_08AB9C44;
    case 12u: goto L_08AB9C48;
    case 13u: goto L_08AB9C4C;
    case 14u: goto L_08AB9C54;
    case 15u: goto L_08AB9C58;
    case 16u: goto L_08AB9C5C;
    case 17u: goto L_08AB9C64;
    case 18u: goto L_08AB9C6C;
    case 19u: goto L_08AB9C74;
    case 20u: goto L_08AB9C78;
    case 21u: goto L_08AB9C80;
    case 22u: goto L_08AB9C84;
    case 23u: goto L_08AB9C88;
    case 24u: goto L_08AB9C8C;
    case 25u: goto L_08AB9C90;
    case 26u: goto L_08AB9C94;
    case 27u: goto L_08AB9C9C;
    case 28u: goto L_08AB9CA0;
    case 29u: goto L_08AB9CA4;
    case 30u: goto L_08AB9CA8;
    case 31u: goto L_08AB9CAC;
    case 32u: goto L_08AB9CB0;
    case 33u: goto L_08AB9CB8;
    case 34u: goto L_08AB9CBC;
    case 35u: goto L_08AB9CC0;
    case 36u: goto L_08AB9CC4;
    case 37u: goto L_08AB9CC8;
    case 38u: goto L_08AB9CCC;
    case 39u: goto L_08AB9CD0;
    case 40u: goto L_08AB9CD8;
    case 41u: goto L_08AB9CDC;
    case 42u: goto L_08AB9CE0;
    case 43u: goto L_08AB9CE4;
    case 44u: goto L_08AB9CE8;
    case 45u: goto L_08AB9CEC;
    case 46u: goto L_08AB9CF0;
    case 47u: goto L_08AB9CF4;
    case 48u: goto L_08AB9CF8;
    case 49u: goto L_08AB9D00;
    case 50u: goto L_08AB9D04;
    case 51u: goto L_08AB9D08;
    case 52u: goto L_08AB9D0C;
    case 53u: goto L_08AB9D10;
    case 54u: goto L_08AB9D14;
    default:
        if (local_transfers == 0u) rt.unsupported(ctx.pc, 0u, "invalid internal function entry");
        else ctx.pc = local_pc;
        return;
    }
    }
L_08AB9C18:
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(-16));
    goto L_08AB9C1C;
L_08AB9C1C:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(0), ctx.gpr[16]);
    goto L_08AB9C20;
L_08AB9C20:
    ctx.set_gpr(16, ctx.gpr[4] | 0u);
    goto L_08AB9C24;
L_08AB9C24:
    ctx.set_gpr(6, 1u << 16u);
    goto L_08AB9C28;
L_08AB9C28:
    ctx.set_gpr(4, ctx.gpr[16] + static_cast<std::uint32_t>(256));
    goto L_08AB9C2C;
L_08AB9C2C:
    ctx.set_gpr(5, 0u | 4u);
    goto L_08AB9C30;
L_08AB9C30:
    ctx.set_gpr(7, 0u | 79u);
    goto L_08AB9C34;
L_08AB9C34:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(4), ctx.gpr[31]);
    goto L_08AB9C38;
L_08AB9C38:
    ctx.set_gpr(31, 0x08AB9C40u);
    ctx.set_gpr(6, ctx.gpr[6] + static_cast<std::uint32_t>(4475));
    ctx.pc = 0x08864FF0u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08AB9C40u) goto L_08AB9C40;
    return;
L_08AB9C40:
    ctx.set_gpr(2, ctx.gpr[16] | 0u);
    goto L_08AB9C44;
L_08AB9C44:
    ctx.set_gpr(16, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(0)));
    goto L_08AB9C48;
L_08AB9C48:
    ctx.set_gpr(31, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(4)));
    goto L_08AB9C4C;
L_08AB9C4C:
    jump_target = ctx.gpr[31];
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(16));
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08AB9C54:
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(-16));
    goto L_08AB9C58;
L_08AB9C58:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(0), ctx.gpr[31]);
    goto L_08AB9C5C;
L_08AB9C5C:
    { const bool branch_taken = ctx.gpr[4] == 0u;
    ctx.set_gpr(5, ctx.gpr[5] & 1u);
      if (branch_taken) {
          goto L_08AB9C74;
      }
      goto L_08AB9C64;
    }
L_08AB9C64:
    { const bool branch_taken = ctx.gpr[5] == 0u;
    // nop
      if (branch_taken) {
          goto L_08AB9C74;
      }
      goto L_08AB9C6C;
    }
L_08AB9C6C:
    ctx.set_gpr(31, 0x08AB9C74u);
    // nop
    ctx.pc = 0x08992F04u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08AB9C74u) goto L_08AB9C74;
    return;
L_08AB9C74:
    ctx.set_gpr(31, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(0)));
    goto L_08AB9C78;
L_08AB9C78:
    jump_target = ctx.gpr[31];
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(16));
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08AB9C80:
    ctx.set_gpr(4, 2220u << 16u);
    goto L_08AB9C84;
L_08AB9C84:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(-17948)));
    goto L_08AB9C88;
L_08AB9C88:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(312)));
    goto L_08AB9C8C;
L_08AB9C8C:
    ctx.set_gpr(5, rt.memory().aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(3376)));
    goto L_08AB9C90;
L_08AB9C90:
    ctx.set_gpr(5, ctx.gpr[5] | 32u);
    goto L_08AB9C94;
L_08AB9C94:
    jump_target = ctx.gpr[31];
    rt.memory().aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(3376), ctx.gpr[5]);
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08AB9C9C:
    ctx.set_gpr(4, 2220u << 16u);
    goto L_08AB9CA0;
L_08AB9CA0:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(-17948)));
    goto L_08AB9CA4;
L_08AB9CA4:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(312)));
    goto L_08AB9CA8;
L_08AB9CA8:
    ctx.set_gpr(5, rt.memory().aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(3376)));
    goto L_08AB9CAC;
L_08AB9CAC:
    ctx.set_gpr(5, ctx.gpr[5] | 16u);
    goto L_08AB9CB0;
L_08AB9CB0:
    jump_target = ctx.gpr[31];
    rt.memory().aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(3376), ctx.gpr[5]);
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08AB9CB8:
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(-32));
    goto L_08AB9CBC;
L_08AB9CBC:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(8), ctx.gpr[16]);
    goto L_08AB9CC0;
L_08AB9CC0:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(12), ctx.gpr[17]);
    goto L_08AB9CC4;
L_08AB9CC4:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(16), ctx.gpr[18]);
    goto L_08AB9CC8;
L_08AB9CC8:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(20), ctx.gpr[19]);
    goto L_08AB9CCC;
L_08AB9CCC:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(24), ctx.gpr[31]);
    goto L_08AB9CD0;
L_08AB9CD0:
    ctx.set_gpr(31, 0x08AB9CD8u);
    ctx.set_gpr(16, ctx.gpr[4] | 0u);
    ctx.pc = 0x08AB99DCu;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08AB9CD8u) goto L_08AB9CD8;
    return;
L_08AB9CD8:
    ctx.set_gpr(5, rt.memory().aot_load32(ctx.gpr[16] + static_cast<std::uint32_t>(308)));
    goto L_08AB9CDC;
L_08AB9CDC:
    ctx.set_gpr(4, 2205u << 16u);
    goto L_08AB9CE0;
L_08AB9CE0:
    ctx.set_gpr(6, 11u << 16u);
    goto L_08AB9CE4;
L_08AB9CE4:
    ctx.set_gpr(8, 2220u << 16u);
    goto L_08AB9CE8;
L_08AB9CE8:
    ctx.set_gpr(7, 0u | 15u);
    goto L_08AB9CEC;
L_08AB9CEC:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(30768)));
    goto L_08AB9CF0;
L_08AB9CF0:
    ctx.set_gpr(9, 0u | 0u);
    goto L_08AB9CF4;
L_08AB9CF4:
    ctx.set_gpr(6, ctx.gpr[6] + static_cast<std::uint32_t>(26624));
    goto L_08AB9CF8;
L_08AB9CF8:
    ctx.set_gpr(31, 0x08AB9D00u);
    ctx.set_gpr(8, ctx.gpr[8] + static_cast<std::uint32_t>(-18028));
    ctx.pc = 0x088D00FCu;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08AB9D00u) goto L_08AB9D00;
    return;
L_08AB9D00:
    ctx.set_gpr(17, 0u | 1u);
    goto L_08AB9D04;
L_08AB9D04:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[16] + static_cast<std::uint32_t>(308)));
    goto L_08AB9D08;
L_08AB9D08:
    ctx.set_gpr(5, 0u | 3708u);
    goto L_08AB9D0C;
L_08AB9D0C:
    ctx.set_gpr(6, 0u | 0u);
    goto L_08AB9D10;
L_08AB9D10:
    ctx.set_gpr(7, 0u | 0u);
    goto L_08AB9D14;
L_08AB9D14:
    ctx.set_gpr(8, ctx.gpr[17] | 0u);
    ctx.pc = 0x08AB9D18u; return;
}

void sub_08AB9C18(Runtime &rt, AllegrexContext &ctx) {
    auto aot_mem = rt.memory().aot_fast_view();
    sub_08AB9C18_entry(rt, ctx, 0u, aot_mem);
}

static const std::uint16_t kEntryIds_sub_08B24A0C[64] = {
    1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 10, 11, 12, 13, 0, 14, 15, 16, 0, 17, 0, 18, 0, 19, 20, 0, 21, 22, 23, 24, 25, 26,
    27, 28, 29, 30, 31, 32, 0, 33, 34, 35, 0, 36, 37, 38, 39, 0, 40, 41, 42, 43, 44, 45, 46, 47, 0, 48, 49, 0, 50, 51, 52, 53,
};
void sub_08B24A0C_entry(Runtime &rt, AllegrexContext &ctx, std::uint16_t direct_entry_id, GuestMemory::AotFastView &aot_mem) {
    std::uint32_t jump_target = 0u;
    std::uint32_t local_transfers = 0u;
    std::uint32_t local_pc = ctx.pc;
    std::uint32_t entry_id = direct_entry_id;
LOCAL_DISPATCH:
    {
    if (entry_id == 0u) {
        const std::uint32_t entry_delta = local_pc - 0x08B24A0Cu;
        entry_id = (entry_delta < 256u && (entry_delta & 3u) == 0u) ? kEntryIds_sub_08B24A0C[entry_delta >> 2u] : 0u;
    }
    switch (entry_id) {
    case 1u: goto L_08B24A0C;
    case 2u: goto L_08B24A10;
    case 3u: goto L_08B24A14;
    case 4u: goto L_08B24A18;
    case 5u: goto L_08B24A1C;
    case 6u: goto L_08B24A20;
    case 7u: goto L_08B24A24;
    case 8u: goto L_08B24A28;
    case 9u: goto L_08B24A2C;
    case 10u: goto L_08B24A34;
    case 11u: goto L_08B24A38;
    case 12u: goto L_08B24A3C;
    case 13u: goto L_08B24A40;
    case 14u: goto L_08B24A48;
    case 15u: goto L_08B24A4C;
    case 16u: goto L_08B24A50;
    case 17u: goto L_08B24A58;
    case 18u: goto L_08B24A60;
    case 19u: goto L_08B24A68;
    case 20u: goto L_08B24A6C;
    case 21u: goto L_08B24A74;
    case 22u: goto L_08B24A78;
    case 23u: goto L_08B24A7C;
    case 24u: goto L_08B24A80;
    case 25u: goto L_08B24A84;
    case 26u: goto L_08B24A88;
    case 27u: goto L_08B24A8C;
    case 28u: goto L_08B24A90;
    case 29u: goto L_08B24A94;
    case 30u: goto L_08B24A98;
    case 31u: goto L_08B24A9C;
    case 32u: goto L_08B24AA0;
    case 33u: goto L_08B24AA8;
    case 34u: goto L_08B24AAC;
    case 35u: goto L_08B24AB0;
    case 36u: goto L_08B24AB8;
    case 37u: goto L_08B24ABC;
    case 38u: goto L_08B24AC0;
    case 39u: goto L_08B24AC4;
    case 40u: goto L_08B24ACC;
    case 41u: goto L_08B24AD0;
    case 42u: goto L_08B24AD4;
    case 43u: goto L_08B24AD8;
    case 44u: goto L_08B24ADC;
    case 45u: goto L_08B24AE0;
    case 46u: goto L_08B24AE4;
    case 47u: goto L_08B24AE8;
    case 48u: goto L_08B24AF0;
    case 49u: goto L_08B24AF4;
    case 50u: goto L_08B24AFC;
    case 51u: goto L_08B24B00;
    case 52u: goto L_08B24B04;
    case 53u: goto L_08B24B08;
    default:
        if (local_transfers == 0u) rt.unsupported(ctx.pc, 0u, "invalid internal function entry");
        else ctx.pc = local_pc;
        return;
    }
    }
L_08B24A0C:
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(-16));
    goto L_08B24A10;
L_08B24A10:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(0), ctx.gpr[16]);
    goto L_08B24A14;
L_08B24A14:
    ctx.set_gpr(16, ctx.gpr[4] | 0u);
    goto L_08B24A18;
L_08B24A18:
    ctx.set_gpr(6, 1u << 16u);
    goto L_08B24A1C;
L_08B24A1C:
    ctx.set_gpr(4, ctx.gpr[16] + static_cast<std::uint32_t>(256));
    goto L_08B24A20;
L_08B24A20:
    ctx.set_gpr(5, 0u | 2u);
    goto L_08B24A24;
L_08B24A24:
    ctx.set_gpr(7, 0u | 67u);
    goto L_08B24A28;
L_08B24A28:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(4), ctx.gpr[31]);
    goto L_08B24A2C;
L_08B24A2C:
    ctx.set_gpr(31, 0x08B24A34u);
    ctx.set_gpr(6, ctx.gpr[6] + static_cast<std::uint32_t>(4470));
    ctx.pc = 0x08864FF0u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B24A34u) goto L_08B24A34;
    return;
L_08B24A34:
    ctx.set_gpr(2, ctx.gpr[16] | 0u);
    goto L_08B24A38;
L_08B24A38:
    ctx.set_gpr(16, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(0)));
    goto L_08B24A3C;
L_08B24A3C:
    ctx.set_gpr(31, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(4)));
    goto L_08B24A40;
L_08B24A40:
    jump_target = ctx.gpr[31];
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(16));
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08B24A48:
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(-16));
    goto L_08B24A4C;
L_08B24A4C:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(0), ctx.gpr[31]);
    goto L_08B24A50;
L_08B24A50:
    { const bool branch_taken = ctx.gpr[4] == 0u;
    ctx.set_gpr(5, ctx.gpr[5] & 1u);
      if (branch_taken) {
          goto L_08B24A68;
      }
      goto L_08B24A58;
    }
L_08B24A58:
    { const bool branch_taken = ctx.gpr[5] == 0u;
    // nop
      if (branch_taken) {
          goto L_08B24A68;
      }
      goto L_08B24A60;
    }
L_08B24A60:
    ctx.set_gpr(31, 0x08B24A68u);
    // nop
    ctx.pc = 0x08992F04u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B24A68u) goto L_08B24A68;
    return;
L_08B24A68:
    ctx.set_gpr(31, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(0)));
    goto L_08B24A6C;
L_08B24A6C:
    jump_target = ctx.gpr[31];
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(16));
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08B24A74:
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(-16));
    goto L_08B24A78;
L_08B24A78:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(0), ctx.gpr[16]);
    goto L_08B24A7C;
L_08B24A7C:
    ctx.set_gpr(16, ctx.gpr[4] | 0u);
    goto L_08B24A80;
L_08B24A80:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(4), ctx.gpr[17]);
    goto L_08B24A84;
L_08B24A84:
    ctx.set_gpr(17, ctx.gpr[16] + static_cast<std::uint32_t>(256));
    goto L_08B24A88;
L_08B24A88:
    ctx.set_gpr(5, 2226u << 16u);
    goto L_08B24A8C;
L_08B24A8C:
    ctx.set_gpr(6, 2226u << 16u);
    goto L_08B24A90;
L_08B24A90:
    ctx.set_gpr(4, ctx.gpr[17] | 0u);
    goto L_08B24A94;
L_08B24A94:
    ctx.set_gpr(7, 0u | 0u);
    goto L_08B24A98;
L_08B24A98:
    ctx.set_gpr(5, ctx.gpr[5] + static_cast<std::uint32_t>(20024));
    goto L_08B24A9C;
L_08B24A9C:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(8), ctx.gpr[31]);
    goto L_08B24AA0;
L_08B24AA0:
    ctx.set_gpr(31, 0x08B24AA8u);
    ctx.set_gpr(6, ctx.gpr[6] + static_cast<std::uint32_t>(20056));
    ctx.pc = 0x0886503Cu;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B24AA8u) goto L_08B24AA8;
    return;
L_08B24AA8:
    ctx.set_gpr(4, ctx.gpr[17] | 0u);
    goto L_08B24AAC;
L_08B24AAC:
    ctx.set_gpr(5, ctx.gpr[16] | 0u);
    goto L_08B24AB0;
L_08B24AB0:
    ctx.set_gpr(31, 0x08B24AB8u);
    ctx.set_gpr(6, 0u | 256u);
    ctx.pc = 0x0886504Cu;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B24AB8u) goto L_08B24AB8;
    return;
L_08B24AB8:
    ctx.set_gpr(16, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(0)));
    goto L_08B24ABC;
L_08B24ABC:
    ctx.set_gpr(17, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(4)));
    goto L_08B24AC0;
L_08B24AC0:
    ctx.set_gpr(31, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(8)));
    goto L_08B24AC4;
L_08B24AC4:
    jump_target = ctx.gpr[31];
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(16));
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08B24ACC:
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(-16));
    goto L_08B24AD0;
L_08B24AD0:
    ctx.set_gpr(8, 2487u << 16u);
    goto L_08B24AD4;
L_08B24AD4:
    rt.memory().aot_store32(ctx.gpr[8] + static_cast<std::uint32_t>(-2984), ctx.gpr[5]);
    goto L_08B24AD8;
L_08B24AD8:
    ctx.set_gpr(5, ctx.gpr[8] + static_cast<std::uint32_t>(-2984));
    goto L_08B24ADC;
L_08B24ADC:
    rt.memory().aot_store32(ctx.gpr[5] + static_cast<std::uint32_t>(8), ctx.gpr[6]);
    goto L_08B24AE0;
L_08B24AE0:
    rt.memory().aot_store32(ctx.gpr[5] + static_cast<std::uint32_t>(12), ctx.gpr[7]);
    goto L_08B24AE4;
L_08B24AE4:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(0), ctx.gpr[31]);
    goto L_08B24AE8;
L_08B24AE8:
    ctx.set_gpr(31, 0x08B24AF0u);
    ctx.set_gpr(4, ctx.gpr[4] + static_cast<std::uint32_t>(256));
    ctx.pc = 0x088650A4u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B24AF0u) goto L_08B24AF0;
    return;
L_08B24AF0:
    ctx.set_gpr(31, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(0)));
    goto L_08B24AF4;
L_08B24AF4:
    jump_target = ctx.gpr[31];
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(16));
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08B24AFC:
    ctx.set_gpr(4, 2226u << 16u);
    goto L_08B24B00;
L_08B24B00:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(20548)));
    goto L_08B24B04;
L_08B24B04:
    ctx.set_gpr(5, 2u << 16u);
    goto L_08B24B08;
L_08B24B08:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(316)));
    ctx.pc = 0x08B24B0Cu; return;
}

void sub_08B24A0C(Runtime &rt, AllegrexContext &ctx) {
    auto aot_mem = rt.memory().aot_fast_view();
    sub_08B24A0C_entry(rt, ctx, 0u, aot_mem);
}

static const std::uint16_t kEntryIds_sub_08B296E8[64] = {
    1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 10, 11, 12, 13, 0, 14, 15, 16, 0, 17, 0, 18, 0, 19, 20, 0, 21, 22, 23, 24, 25, 26,
    0, 27, 28, 29, 30, 31, 32, 0, 33, 34, 35, 36, 37, 0, 38, 39, 0, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54,
};
void sub_08B296E8_entry(Runtime &rt, AllegrexContext &ctx, std::uint16_t direct_entry_id, GuestMemory::AotFastView &aot_mem) {
    std::uint32_t jump_target = 0u;
    std::uint32_t local_transfers = 0u;
    std::uint32_t local_pc = ctx.pc;
    std::uint32_t entry_id = direct_entry_id;
LOCAL_DISPATCH:
    {
    if (entry_id == 0u) {
        const std::uint32_t entry_delta = local_pc - 0x08B296E8u;
        entry_id = (entry_delta < 256u && (entry_delta & 3u) == 0u) ? kEntryIds_sub_08B296E8[entry_delta >> 2u] : 0u;
    }
    switch (entry_id) {
    case 1u: goto L_08B296E8;
    case 2u: goto L_08B296EC;
    case 3u: goto L_08B296F0;
    case 4u: goto L_08B296F4;
    case 5u: goto L_08B296F8;
    case 6u: goto L_08B296FC;
    case 7u: goto L_08B29700;
    case 8u: goto L_08B29704;
    case 9u: goto L_08B29708;
    case 10u: goto L_08B29710;
    case 11u: goto L_08B29714;
    case 12u: goto L_08B29718;
    case 13u: goto L_08B2971C;
    case 14u: goto L_08B29724;
    case 15u: goto L_08B29728;
    case 16u: goto L_08B2972C;
    case 17u: goto L_08B29734;
    case 18u: goto L_08B2973C;
    case 19u: goto L_08B29744;
    case 20u: goto L_08B29748;
    case 21u: goto L_08B29750;
    case 22u: goto L_08B29754;
    case 23u: goto L_08B29758;
    case 24u: goto L_08B2975C;
    case 25u: goto L_08B29760;
    case 26u: goto L_08B29764;
    case 27u: goto L_08B2976C;
    case 28u: goto L_08B29770;
    case 29u: goto L_08B29774;
    case 30u: goto L_08B29778;
    case 31u: goto L_08B2977C;
    case 32u: goto L_08B29780;
    case 33u: goto L_08B29788;
    case 34u: goto L_08B2978C;
    case 35u: goto L_08B29790;
    case 36u: goto L_08B29794;
    case 37u: goto L_08B29798;
    case 38u: goto L_08B297A0;
    case 39u: goto L_08B297A4;
    case 40u: goto L_08B297AC;
    case 41u: goto L_08B297B0;
    case 42u: goto L_08B297B4;
    case 43u: goto L_08B297B8;
    case 44u: goto L_08B297BC;
    case 45u: goto L_08B297C0;
    case 46u: goto L_08B297C4;
    case 47u: goto L_08B297C8;
    case 48u: goto L_08B297CC;
    case 49u: goto L_08B297D0;
    case 50u: goto L_08B297D4;
    case 51u: goto L_08B297D8;
    case 52u: goto L_08B297DC;
    case 53u: goto L_08B297E0;
    case 54u: goto L_08B297E4;
    default:
        if (local_transfers == 0u) rt.unsupported(ctx.pc, 0u, "invalid internal function entry");
        else ctx.pc = local_pc;
        return;
    }
    }
L_08B296E8:
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(-16));
    goto L_08B296EC;
L_08B296EC:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(0), ctx.gpr[16]);
    goto L_08B296F0;
L_08B296F0:
    ctx.set_gpr(16, ctx.gpr[4] | 0u);
    goto L_08B296F4;
L_08B296F4:
    ctx.set_gpr(6, 1u << 16u);
    goto L_08B296F8;
L_08B296F8:
    ctx.set_gpr(4, ctx.gpr[16] + static_cast<std::uint32_t>(256));
    goto L_08B296FC;
L_08B296FC:
    ctx.set_gpr(5, 0u | 1u);
    goto L_08B29700;
L_08B29700:
    ctx.set_gpr(7, 0u | 76u);
    goto L_08B29704;
L_08B29704:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(4), ctx.gpr[31]);
    goto L_08B29708;
L_08B29708:
    ctx.set_gpr(31, 0x08B29710u);
    ctx.set_gpr(6, ctx.gpr[6] + static_cast<std::uint32_t>(4482));
    ctx.pc = 0x08864FF0u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B29710u) goto L_08B29710;
    return;
L_08B29710:
    ctx.set_gpr(2, ctx.gpr[16] | 0u);
    goto L_08B29714;
L_08B29714:
    ctx.set_gpr(16, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(0)));
    goto L_08B29718;
L_08B29718:
    ctx.set_gpr(31, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(4)));
    goto L_08B2971C;
L_08B2971C:
    jump_target = ctx.gpr[31];
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(16));
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08B29724:
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(-16));
    goto L_08B29728;
L_08B29728:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(0), ctx.gpr[31]);
    goto L_08B2972C;
L_08B2972C:
    { const bool branch_taken = ctx.gpr[4] == 0u;
    ctx.set_gpr(5, ctx.gpr[5] & 1u);
      if (branch_taken) {
          goto L_08B29744;
      }
      goto L_08B29734;
    }
L_08B29734:
    { const bool branch_taken = ctx.gpr[5] == 0u;
    // nop
      if (branch_taken) {
          goto L_08B29744;
      }
      goto L_08B2973C;
    }
L_08B2973C:
    ctx.set_gpr(31, 0x08B29744u);
    // nop
    ctx.pc = 0x08992F04u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B29744u) goto L_08B29744;
    return;
L_08B29744:
    ctx.set_gpr(31, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(0)));
    goto L_08B29748;
L_08B29748:
    jump_target = ctx.gpr[31];
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(16));
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08B29750:
    ctx.set_gpr(4, 2227u << 16u);
    goto L_08B29754;
L_08B29754:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(-25352)));
    goto L_08B29758;
L_08B29758:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(332)));
    goto L_08B2975C;
L_08B2975C:
    ctx.set_gpr(5, rt.memory().aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(1036)));
    goto L_08B29760;
L_08B29760:
    ctx.set_gpr(5, ctx.gpr[5] | 2u);
    goto L_08B29764;
L_08B29764:
    jump_target = ctx.gpr[31];
    rt.memory().aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(1036), ctx.gpr[5]);
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08B2976C:
    ctx.set_gpr(4, 2227u << 16u);
    goto L_08B29770;
L_08B29770:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(-25352)));
    goto L_08B29774;
L_08B29774:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(332)));
    goto L_08B29778;
L_08B29778:
    ctx.set_gpr(5, rt.memory().aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(1036)));
    goto L_08B2977C;
L_08B2977C:
    ctx.set_gpr(5, ctx.gpr[5] | 4u);
    goto L_08B29780;
L_08B29780:
    jump_target = ctx.gpr[31];
    rt.memory().aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(1036), ctx.gpr[5]);
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08B29788:
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(-16));
    goto L_08B2978C;
L_08B2978C:
    ctx.set_gpr(5, ctx.gpr[4] | 0u);
    goto L_08B29790;
L_08B29790:
    ctx.set_gpr(4, 2227u << 16u);
    goto L_08B29794;
L_08B29794:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(0), ctx.gpr[31]);
    goto L_08B29798;
L_08B29798:
    ctx.set_gpr(31, 0x08B297A0u);
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(-25352)));
    ctx.pc = 0x08B2934Cu;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B297A0u) goto L_08B297A0;
    return;
L_08B297A0:
    ctx.set_gpr(31, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(0)));
    goto L_08B297A4;
L_08B297A4:
    jump_target = ctx.gpr[31];
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(16));
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08B297AC:
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(-16));
    goto L_08B297B0;
L_08B297B0:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(0), ctx.gpr[16]);
    goto L_08B297B4;
L_08B297B4:
    ctx.set_gpr(16, ctx.gpr[4] | 0u);
    goto L_08B297B8;
L_08B297B8:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[16] + static_cast<std::uint32_t>(332)));
    goto L_08B297BC;
L_08B297BC:
    ctx.set_gpr(6, ctx.gpr[4] + static_cast<std::uint32_t>(4));
    goto L_08B297C0;
L_08B297C0:
    rt.memory().aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(1048), ctx.gpr[6]);
    goto L_08B297C4;
L_08B297C4:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[16] + static_cast<std::uint32_t>(332)));
    goto L_08B297C8;
L_08B297C8:
    ctx.set_gpr(5, 0u | 25u);
    goto L_08B297CC;
L_08B297CC:
    rt.memory().aot_store8(ctx.gpr[4] + static_cast<std::uint32_t>(1052), static_cast<std::uint8_t>(ctx.gpr[5]));
    goto L_08B297D0;
L_08B297D0:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[16] + static_cast<std::uint32_t>(332)));
    goto L_08B297D4;
L_08B297D4:
    rt.memory().aot_store16(ctx.gpr[4] + static_cast<std::uint32_t>(1054), static_cast<std::uint16_t>(0u));
    goto L_08B297D8;
L_08B297D8:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[16] + static_cast<std::uint32_t>(332)));
    goto L_08B297DC;
L_08B297DC:
    ctx.set_gpr(5, rt.memory().aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(1028)));
    goto L_08B297E0;
L_08B297E0:
    rt.memory().aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(1056), ctx.gpr[5]);
    goto L_08B297E4;
L_08B297E4:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[16] + static_cast<std::uint32_t>(332)));
    ctx.pc = 0x08B297E8u; return;
}

void sub_08B296E8(Runtime &rt, AllegrexContext &ctx) {
    auto aot_mem = rt.memory().aot_fast_view();
    sub_08B296E8_entry(rt, ctx, 0u, aot_mem);
}

static const std::uint16_t kEntryIds_sub_08B326F8[64] = {
    1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 10, 11, 12, 13, 0, 14, 15, 16, 0, 17, 0, 18, 0, 19, 20, 0, 21, 22, 23, 24, 25, 26,
    0, 27, 28, 29, 30, 31, 32, 0, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 0, 49, 50, 51, 52, 53, 54, 55,
};
void sub_08B326F8_entry(Runtime &rt, AllegrexContext &ctx, std::uint16_t direct_entry_id, GuestMemory::AotFastView &aot_mem) {
    std::uint32_t jump_target = 0u;
    std::uint32_t local_transfers = 0u;
    std::uint32_t local_pc = ctx.pc;
    std::uint32_t entry_id = direct_entry_id;
LOCAL_DISPATCH:
    {
    if (entry_id == 0u) {
        const std::uint32_t entry_delta = local_pc - 0x08B326F8u;
        entry_id = (entry_delta < 256u && (entry_delta & 3u) == 0u) ? kEntryIds_sub_08B326F8[entry_delta >> 2u] : 0u;
    }
    switch (entry_id) {
    case 1u: goto L_08B326F8;
    case 2u: goto L_08B326FC;
    case 3u: goto L_08B32700;
    case 4u: goto L_08B32704;
    case 5u: goto L_08B32708;
    case 6u: goto L_08B3270C;
    case 7u: goto L_08B32710;
    case 8u: goto L_08B32714;
    case 9u: goto L_08B32718;
    case 10u: goto L_08B32720;
    case 11u: goto L_08B32724;
    case 12u: goto L_08B32728;
    case 13u: goto L_08B3272C;
    case 14u: goto L_08B32734;
    case 15u: goto L_08B32738;
    case 16u: goto L_08B3273C;
    case 17u: goto L_08B32744;
    case 18u: goto L_08B3274C;
    case 19u: goto L_08B32754;
    case 20u: goto L_08B32758;
    case 21u: goto L_08B32760;
    case 22u: goto L_08B32764;
    case 23u: goto L_08B32768;
    case 24u: goto L_08B3276C;
    case 25u: goto L_08B32770;
    case 26u: goto L_08B32774;
    case 27u: goto L_08B3277C;
    case 28u: goto L_08B32780;
    case 29u: goto L_08B32784;
    case 30u: goto L_08B32788;
    case 31u: goto L_08B3278C;
    case 32u: goto L_08B32790;
    case 33u: goto L_08B32798;
    case 34u: goto L_08B3279C;
    case 35u: goto L_08B327A0;
    case 36u: goto L_08B327A4;
    case 37u: goto L_08B327A8;
    case 38u: goto L_08B327AC;
    case 39u: goto L_08B327B0;
    case 40u: goto L_08B327B4;
    case 41u: goto L_08B327B8;
    case 42u: goto L_08B327BC;
    case 43u: goto L_08B327C0;
    case 44u: goto L_08B327C4;
    case 45u: goto L_08B327C8;
    case 46u: goto L_08B327CC;
    case 47u: goto L_08B327D0;
    case 48u: goto L_08B327D4;
    case 49u: goto L_08B327DC;
    case 50u: goto L_08B327E0;
    case 51u: goto L_08B327E4;
    case 52u: goto L_08B327E8;
    case 53u: goto L_08B327EC;
    case 54u: goto L_08B327F0;
    case 55u: goto L_08B327F4;
    default:
        if (local_transfers == 0u) rt.unsupported(ctx.pc, 0u, "invalid internal function entry");
        else ctx.pc = local_pc;
        return;
    }
    }
L_08B326F8:
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(-16));
    goto L_08B326FC;
L_08B326FC:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(0), ctx.gpr[16]);
    goto L_08B32700;
L_08B32700:
    ctx.set_gpr(16, ctx.gpr[4] | 0u);
    goto L_08B32704;
L_08B32704:
    ctx.set_gpr(6, 1u << 16u);
    goto L_08B32708;
L_08B32708:
    ctx.set_gpr(4, ctx.gpr[16] + static_cast<std::uint32_t>(256));
    goto L_08B3270C;
L_08B3270C:
    ctx.set_gpr(5, 0u | 2u);
    goto L_08B32710;
L_08B32710:
    ctx.set_gpr(7, 0u | 76u);
    goto L_08B32714;
L_08B32714:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(4), ctx.gpr[31]);
    goto L_08B32718;
L_08B32718:
    ctx.set_gpr(31, 0x08B32720u);
    ctx.set_gpr(6, ctx.gpr[6] + static_cast<std::uint32_t>(4483));
    ctx.pc = 0x08864FF0u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B32720u) goto L_08B32720;
    return;
L_08B32720:
    ctx.set_gpr(2, ctx.gpr[16] | 0u);
    goto L_08B32724;
L_08B32724:
    ctx.set_gpr(16, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(0)));
    goto L_08B32728;
L_08B32728:
    ctx.set_gpr(31, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(4)));
    goto L_08B3272C;
L_08B3272C:
    jump_target = ctx.gpr[31];
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(16));
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08B32734:
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(-16));
    goto L_08B32738;
L_08B32738:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(0), ctx.gpr[31]);
    goto L_08B3273C;
L_08B3273C:
    { const bool branch_taken = ctx.gpr[4] == 0u;
    ctx.set_gpr(5, ctx.gpr[5] & 1u);
      if (branch_taken) {
          goto L_08B32754;
      }
      goto L_08B32744;
    }
L_08B32744:
    { const bool branch_taken = ctx.gpr[5] == 0u;
    // nop
      if (branch_taken) {
          goto L_08B32754;
      }
      goto L_08B3274C;
    }
L_08B3274C:
    ctx.set_gpr(31, 0x08B32754u);
    // nop
    ctx.pc = 0x08992F04u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B32754u) goto L_08B32754;
    return;
L_08B32754:
    ctx.set_gpr(31, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(0)));
    goto L_08B32758;
L_08B32758:
    jump_target = ctx.gpr[31];
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(16));
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08B32760:
    ctx.set_gpr(4, 2227u << 16u);
    goto L_08B32764;
L_08B32764:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(11664)));
    goto L_08B32768;
L_08B32768:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(312)));
    goto L_08B3276C;
L_08B3276C:
    ctx.set_gpr(5, rt.memory().aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(1028)));
    goto L_08B32770;
L_08B32770:
    ctx.set_gpr(5, ctx.gpr[5] | 2u);
    goto L_08B32774;
L_08B32774:
    jump_target = ctx.gpr[31];
    rt.memory().aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(1028), ctx.gpr[5]);
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08B3277C:
    ctx.set_gpr(4, 2227u << 16u);
    goto L_08B32780;
L_08B32780:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(11664)));
    goto L_08B32784;
L_08B32784:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(312)));
    goto L_08B32788;
L_08B32788:
    ctx.set_gpr(5, rt.memory().aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(1028)));
    goto L_08B3278C;
L_08B3278C:
    ctx.set_gpr(5, ctx.gpr[5] | 4u);
    goto L_08B32790;
L_08B32790:
    jump_target = ctx.gpr[31];
    rt.memory().aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(1028), ctx.gpr[5]);
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08B32798:
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(-48));
    goto L_08B3279C;
L_08B3279C:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(12), ctx.gpr[18]);
    goto L_08B327A0;
L_08B327A0:
    ctx.set_gpr(18, ctx.gpr[4] | 0u);
    goto L_08B327A4;
L_08B327A4:
    ctx.set_gpr(4, 2487u << 16u);
    goto L_08B327A8;
L_08B327A8:
    ctx.set_gpr(4, ctx.gpr[4] + static_cast<std::uint32_t>(-8944));
    goto L_08B327AC;
L_08B327AC:
    ctx.set_gpr(5, rt.memory().aot_load8(ctx.gpr[4] + static_cast<std::uint32_t>(8)));
    goto L_08B327B0;
L_08B327B0:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(4), ctx.gpr[16]);
    goto L_08B327B4;
L_08B327B4:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(8), ctx.gpr[17]);
    goto L_08B327B8;
L_08B327B8:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(16), ctx.gpr[19]);
    goto L_08B327BC;
L_08B327BC:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(20), ctx.gpr[20]);
    goto L_08B327C0;
L_08B327C0:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(24), ctx.gpr[21]);
    goto L_08B327C4;
L_08B327C4:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(28), ctx.gpr[22]);
    goto L_08B327C8;
L_08B327C8:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(32), ctx.gpr[23]);
    goto L_08B327CC;
L_08B327CC:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(36), ctx.gpr[30]);
    goto L_08B327D0;
L_08B327D0:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(40), ctx.gpr[31]);
    goto L_08B327D4;
L_08B327D4:
    { const bool branch_taken = ctx.gpr[5] == 0u;
    ctx.set_gpr(16, 2224u << 16u);
      if (branch_taken) {
          ctx.pc = 0x08B32844u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
      }
      goto L_08B327DC;
    }
L_08B327DC:
    ctx.set_gpr(5, rt.memory().aot_load32(ctx.gpr[18] + static_cast<std::uint32_t>(312)));
    goto L_08B327E0;
L_08B327E0:
    ctx.set_gpr(8, ctx.gpr[4] | 0u);
    goto L_08B327E4;
L_08B327E4:
    ctx.set_gpr(5, ctx.gpr[5] + static_cast<std::uint32_t>(1092));
    goto L_08B327E8;
L_08B327E8:
    ctx.set_gpr(6, 0u | 0u);
    goto L_08B327EC;
L_08B327EC:
    ctx.set_gpr(7, 0u | 37u);
    goto L_08B327F0;
L_08B327F0:
    ctx.set_gpr(9, rt.memory().aot_load32(ctx.gpr[8] + static_cast<std::uint32_t>(8)));
    goto L_08B327F4;
L_08B327F4:
    ctx.set_gpr(10, ctx.gpr[5] | 0u);
    ctx.pc = 0x08B327F8u; return;
}

void sub_08B326F8(Runtime &rt, AllegrexContext &ctx) {
    auto aot_mem = rt.memory().aot_fast_view();
    sub_08B326F8_entry(rt, ctx, 0u, aot_mem);
}

static const std::uint16_t kEntryIds_sub_08B34C18[64] = {
    1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 10, 11, 12, 13, 0, 14, 0, 15, 0, 16, 17, 18, 19, 20, 21, 22, 0, 23, 24, 25, 26, 27,
    28, 0, 29, 0, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57,
};
void sub_08B34C18_entry(Runtime &rt, AllegrexContext &ctx, std::uint16_t direct_entry_id, GuestMemory::AotFastView &aot_mem) {
    std::uint32_t jump_target = 0u;
    std::uint32_t local_transfers = 0u;
    std::uint32_t local_pc = ctx.pc;
    std::uint32_t entry_id = direct_entry_id;
LOCAL_DISPATCH:
    {
    if (entry_id == 0u) {
        const std::uint32_t entry_delta = local_pc - 0x08B34C18u;
        entry_id = (entry_delta < 256u && (entry_delta & 3u) == 0u) ? kEntryIds_sub_08B34C18[entry_delta >> 2u] : 0u;
    }
    switch (entry_id) {
    case 1u: goto L_08B34C18;
    case 2u: goto L_08B34C1C;
    case 3u: goto L_08B34C20;
    case 4u: goto L_08B34C24;
    case 5u: goto L_08B34C28;
    case 6u: goto L_08B34C2C;
    case 7u: goto L_08B34C30;
    case 8u: goto L_08B34C34;
    case 9u: goto L_08B34C38;
    case 10u: goto L_08B34C40;
    case 11u: goto L_08B34C44;
    case 12u: goto L_08B34C48;
    case 13u: goto L_08B34C4C;
    case 14u: goto L_08B34C54;
    case 15u: goto L_08B34C5C;
    case 16u: goto L_08B34C64;
    case 17u: goto L_08B34C68;
    case 18u: goto L_08B34C6C;
    case 19u: goto L_08B34C70;
    case 20u: goto L_08B34C74;
    case 21u: goto L_08B34C78;
    case 22u: goto L_08B34C7C;
    case 23u: goto L_08B34C84;
    case 24u: goto L_08B34C88;
    case 25u: goto L_08B34C8C;
    case 26u: goto L_08B34C90;
    case 27u: goto L_08B34C94;
    case 28u: goto L_08B34C98;
    case 29u: goto L_08B34CA0;
    case 30u: goto L_08B34CA8;
    case 31u: goto L_08B34CAC;
    case 32u: goto L_08B34CB0;
    case 33u: goto L_08B34CB4;
    case 34u: goto L_08B34CB8;
    case 35u: goto L_08B34CBC;
    case 36u: goto L_08B34CC0;
    case 37u: goto L_08B34CC4;
    case 38u: goto L_08B34CC8;
    case 39u: goto L_08B34CCC;
    case 40u: goto L_08B34CD0;
    case 41u: goto L_08B34CD4;
    case 42u: goto L_08B34CD8;
    case 43u: goto L_08B34CDC;
    case 44u: goto L_08B34CE0;
    case 45u: goto L_08B34CE4;
    case 46u: goto L_08B34CE8;
    case 47u: goto L_08B34CEC;
    case 48u: goto L_08B34CF0;
    case 49u: goto L_08B34CF4;
    case 50u: goto L_08B34CF8;
    case 51u: goto L_08B34CFC;
    case 52u: goto L_08B34D00;
    case 53u: goto L_08B34D04;
    case 54u: goto L_08B34D08;
    case 55u: goto L_08B34D0C;
    case 56u: goto L_08B34D10;
    case 57u: goto L_08B34D14;
    default:
        if (local_transfers == 0u) rt.unsupported(ctx.pc, 0u, "invalid internal function entry");
        else ctx.pc = local_pc;
        return;
    }
    }
L_08B34C18:
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(-16));
    goto L_08B34C1C;
L_08B34C1C:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(0), ctx.gpr[16]);
    goto L_08B34C20;
L_08B34C20:
    ctx.set_gpr(16, ctx.gpr[4] | 0u);
    goto L_08B34C24;
L_08B34C24:
    ctx.set_gpr(6, 1u << 16u);
    goto L_08B34C28;
L_08B34C28:
    ctx.set_gpr(4, ctx.gpr[16] + static_cast<std::uint32_t>(92));
    goto L_08B34C2C;
L_08B34C2C:
    ctx.set_gpr(5, 0u | 1u);
    goto L_08B34C30;
L_08B34C30:
    ctx.set_gpr(7, 0u | 84u);
    goto L_08B34C34;
L_08B34C34:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(4), ctx.gpr[31]);
    goto L_08B34C38;
L_08B34C38:
    ctx.set_gpr(31, 0x08B34C40u);
    ctx.set_gpr(6, ctx.gpr[6] + static_cast<std::uint32_t>(4466));
    ctx.pc = 0x08864FF0u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B34C40u) goto L_08B34C40;
    return;
L_08B34C40:
    rt.memory().aot_store32(ctx.gpr[16] + static_cast<std::uint32_t>(88), 0u);
    goto L_08B34C44;
L_08B34C44:
    rt.memory().aot_store32(ctx.gpr[16] + static_cast<std::uint32_t>(144), 0u);
    goto L_08B34C48;
L_08B34C48:
    rt.memory().aot_store32(ctx.gpr[16] + static_cast<std::uint32_t>(148), 0u);
    goto L_08B34C4C;
L_08B34C4C:
    ctx.set_gpr(31, 0x08B34C54u);
    ctx.set_gpr(4, ctx.gpr[16] | 0u);
    ctx.pc = 0x08B35A64u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B34C54u) goto L_08B34C54;
    return;
L_08B34C54:
    ctx.set_gpr(31, 0x08B34C5Cu);
    ctx.set_gpr(4, ctx.gpr[16] | 0u);
    ctx.pc = 0x08B35ABCu;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B34C5Cu) goto L_08B34C5C;
    return;
L_08B34C5C:
    ctx.set_gpr(31, 0x08B34C64u);
    ctx.set_gpr(4, ctx.gpr[16] | 0u);
    ctx.pc = 0x08B35A44u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B34C64u) goto L_08B34C64;
    return;
L_08B34C64:
    rt.memory().aot_store32(ctx.gpr[16] + static_cast<std::uint32_t>(184), 0u);
    goto L_08B34C68;
L_08B34C68:
    rt.memory().aot_store32(ctx.gpr[16] + static_cast<std::uint32_t>(188), 0u);
    goto L_08B34C6C;
L_08B34C6C:
    rt.memory().aot_store32(ctx.gpr[16] + static_cast<std::uint32_t>(192), 0u);
    goto L_08B34C70;
L_08B34C70:
    ctx.set_gpr(2, ctx.gpr[16] | 0u);
    goto L_08B34C74;
L_08B34C74:
    ctx.set_gpr(16, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(0)));
    goto L_08B34C78;
L_08B34C78:
    ctx.set_gpr(31, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(4)));
    goto L_08B34C7C;
L_08B34C7C:
    jump_target = ctx.gpr[31];
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(16));
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08B34C84:
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(-64));
    goto L_08B34C88;
L_08B34C88:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(48), ctx.gpr[16]);
    goto L_08B34C8C;
L_08B34C8C:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(52), ctx.gpr[17]);
    goto L_08B34C90;
L_08B34C90:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(56), ctx.gpr[18]);
    goto L_08B34C94;
L_08B34C94:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(60), ctx.gpr[31]);
    goto L_08B34C98;
L_08B34C98:
    ctx.set_gpr(31, 0x08B34CA0u);
    ctx.set_gpr(16, ctx.gpr[4] | 0u);
    ctx.pc = 0x08B42B40u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B34CA0u) goto L_08B34CA0;
    return;
L_08B34CA0:
    ctx.set_gpr(31, 0x08B34CA8u);
    ctx.set_gpr(4, ctx.gpr[2] | 0u);
    ctx.pc = 0x08841EB4u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B34CA8u) goto L_08B34CA8;
    return;
L_08B34CA8:
    ctx.set_gpr(7, 1u << 16u);
    goto L_08B34CAC;
L_08B34CAC:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[16] + static_cast<std::uint32_t>(92)));
    goto L_08B34CB0;
L_08B34CB0:
    ctx.set_gpr(13, ctx.gpr[7] + static_cast<std::uint32_t>(3464));
    goto L_08B34CB4;
L_08B34CB4:
    ctx.set_gpr(10, 0u + static_cast<std::uint32_t>(-1));
    goto L_08B34CB8;
L_08B34CB8:
    ctx.set_gpr(11, 1u << 16u);
    goto L_08B34CBC;
L_08B34CBC:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(0), ctx.gpr[13]);
    goto L_08B34CC0;
L_08B34CC0:
    ctx.set_gpr(14, ctx.gpr[11] + static_cast<std::uint32_t>(7464));
    goto L_08B34CC4;
L_08B34CC4:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(4), ctx.gpr[10]);
    goto L_08B34CC8;
L_08B34CC8:
    ctx.set_gpr(17, 0u | 1u);
    goto L_08B34CCC;
L_08B34CCC:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(8), ctx.gpr[14]);
    goto L_08B34CD0;
L_08B34CD0:
    ctx.set_gpr(2, 0u | 31000u);
    goto L_08B34CD4;
L_08B34CD4:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(12), ctx.gpr[17]);
    goto L_08B34CD8;
L_08B34CD8:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(16), ctx.gpr[2]);
    goto L_08B34CDC;
L_08B34CDC:
    ctx.set_gpr(3, 0u | 31100u);
    goto L_08B34CE0;
L_08B34CE0:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(20), ctx.gpr[17]);
    goto L_08B34CE4;
L_08B34CE4:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(24), ctx.gpr[3]);
    goto L_08B34CE8;
L_08B34CE8:
    ctx.set_gpr(12, 0u | 58000u);
    goto L_08B34CEC;
L_08B34CEC:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(28), ctx.gpr[10]);
    goto L_08B34CF0;
L_08B34CF0:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(32), ctx.gpr[12]);
    goto L_08B34CF4;
L_08B34CF4:
    ctx.set_gpr(2, 2u << 16u);
    goto L_08B34CF8;
L_08B34CF8:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(36), ctx.gpr[10]);
    goto L_08B34CFC;
L_08B34CFC:
    ctx.set_gpr(2, ctx.gpr[2] + static_cast<std::uint32_t>(-30072));
    goto L_08B34D00;
L_08B34D00:
    ctx.set_gpr(10, 1u << 16u);
    goto L_08B34D04;
L_08B34D04:
    ctx.set_gpr(8, 0u | 40000u);
    goto L_08B34D08;
L_08B34D08:
    ctx.set_gpr(5, 0u | 1u);
    goto L_08B34D0C;
L_08B34D0C:
    ctx.set_gpr(6, 0u | 30000u);
    goto L_08B34D10;
L_08B34D10:
    ctx.set_gpr(7, 0u | 1u);
    goto L_08B34D14;
L_08B34D14:
    ctx.set_gpr(9, 0u + static_cast<std::uint32_t>(-1));
    ctx.pc = 0x08B34D18u; return;
}

void sub_08B34C18(Runtime &rt, AllegrexContext &ctx) {
    auto aot_mem = rt.memory().aot_fast_view();
    sub_08B34C18_entry(rt, ctx, 0u, aot_mem);
}

static const std::uint16_t kEntryIds_sub_08B41F00[64] = {
    1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 10, 11, 12, 13, 14, 15, 0, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30,
    0, 31, 0, 32, 33, 34, 35, 36, 37, 0, 38, 39, 40, 41, 42, 43, 0, 44, 45, 46, 47, 48, 0, 49, 50, 51, 52, 53, 54, 55, 56, 57,
};
void sub_08B41F00_entry(Runtime &rt, AllegrexContext &ctx, std::uint16_t direct_entry_id, GuestMemory::AotFastView &aot_mem) {
    std::uint32_t jump_target = 0u;
    std::uint32_t local_transfers = 0u;
    std::uint32_t local_pc = ctx.pc;
    std::uint32_t entry_id = direct_entry_id;
LOCAL_DISPATCH:
    {
    if (entry_id == 0u) {
        const std::uint32_t entry_delta = local_pc - 0x08B41F00u;
        entry_id = (entry_delta < 256u && (entry_delta & 3u) == 0u) ? kEntryIds_sub_08B41F00[entry_delta >> 2u] : 0u;
    }
    switch (entry_id) {
    case 1u: goto L_08B41F00;
    case 2u: goto L_08B41F04;
    case 3u: goto L_08B41F08;
    case 4u: goto L_08B41F0C;
    case 5u: goto L_08B41F10;
    case 6u: goto L_08B41F14;
    case 7u: goto L_08B41F18;
    case 8u: goto L_08B41F1C;
    case 9u: goto L_08B41F20;
    case 10u: goto L_08B41F28;
    case 11u: goto L_08B41F2C;
    case 12u: goto L_08B41F30;
    case 13u: goto L_08B41F34;
    case 14u: goto L_08B41F38;
    case 15u: goto L_08B41F3C;
    case 16u: goto L_08B41F44;
    case 17u: goto L_08B41F48;
    case 18u: goto L_08B41F4C;
    case 19u: goto L_08B41F50;
    case 20u: goto L_08B41F54;
    case 21u: goto L_08B41F58;
    case 22u: goto L_08B41F5C;
    case 23u: goto L_08B41F60;
    case 24u: goto L_08B41F64;
    case 25u: goto L_08B41F68;
    case 26u: goto L_08B41F6C;
    case 27u: goto L_08B41F70;
    case 28u: goto L_08B41F74;
    case 29u: goto L_08B41F78;
    case 30u: goto L_08B41F7C;
    case 31u: goto L_08B41F84;
    case 32u: goto L_08B41F8C;
    case 33u: goto L_08B41F90;
    case 34u: goto L_08B41F94;
    case 35u: goto L_08B41F98;
    case 36u: goto L_08B41F9C;
    case 37u: goto L_08B41FA0;
    case 38u: goto L_08B41FA8;
    case 39u: goto L_08B41FAC;
    case 40u: goto L_08B41FB0;
    case 41u: goto L_08B41FB4;
    case 42u: goto L_08B41FB8;
    case 43u: goto L_08B41FBC;
    case 44u: goto L_08B41FC4;
    case 45u: goto L_08B41FC8;
    case 46u: goto L_08B41FCC;
    case 47u: goto L_08B41FD0;
    case 48u: goto L_08B41FD4;
    case 49u: goto L_08B41FDC;
    case 50u: goto L_08B41FE0;
    case 51u: goto L_08B41FE4;
    case 52u: goto L_08B41FE8;
    case 53u: goto L_08B41FEC;
    case 54u: goto L_08B41FF0;
    case 55u: goto L_08B41FF4;
    case 56u: goto L_08B41FF8;
    case 57u: goto L_08B41FFC;
    default:
        if (local_transfers == 0u) rt.unsupported(ctx.pc, 0u, "invalid internal function entry");
        else ctx.pc = local_pc;
        return;
    }
    }
L_08B41F00:
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(-16));
    goto L_08B41F04;
L_08B41F04:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(0), ctx.gpr[16]);
    goto L_08B41F08;
L_08B41F08:
    ctx.set_gpr(16, ctx.gpr[4] | 0u);
    goto L_08B41F0C;
L_08B41F0C:
    ctx.set_gpr(6, 1u << 16u);
    goto L_08B41F10;
L_08B41F10:
    ctx.set_gpr(4, ctx.gpr[16] + static_cast<std::uint32_t>(4));
    goto L_08B41F14;
L_08B41F14:
    ctx.set_gpr(5, 0u | 1u);
    goto L_08B41F18;
L_08B41F18:
    ctx.set_gpr(7, 0u | 84u);
    goto L_08B41F1C;
L_08B41F1C:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(4), ctx.gpr[31]);
    goto L_08B41F20;
L_08B41F20:
    ctx.set_gpr(31, 0x08B41F28u);
    ctx.set_gpr(6, ctx.gpr[6] + static_cast<std::uint32_t>(4466));
    ctx.pc = 0x08864FF0u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B41F28u) goto L_08B41F28;
    return;
L_08B41F28:
    ctx.set_gpr(4, 0u | 8u);
    goto L_08B41F2C;
L_08B41F2C:
    rt.memory().aot_store32(ctx.gpr[16] + static_cast<std::uint32_t>(56), ctx.gpr[4]);
    goto L_08B41F30;
L_08B41F30:
    ctx.set_gpr(2, ctx.gpr[16] | 0u);
    goto L_08B41F34;
L_08B41F34:
    ctx.set_gpr(16, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(0)));
    goto L_08B41F38;
L_08B41F38:
    ctx.set_gpr(31, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(4)));
    goto L_08B41F3C;
L_08B41F3C:
    jump_target = ctx.gpr[31];
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(16));
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08B41F44:
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(-16));
    goto L_08B41F48;
L_08B41F48:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(0), ctx.gpr[16]);
    goto L_08B41F4C;
L_08B41F4C:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(4), ctx.gpr[17]);
    goto L_08B41F50;
L_08B41F50:
    ctx.set_gpr(16, ctx.gpr[4] | 0u);
    goto L_08B41F54;
L_08B41F54:
    ctx.set_gpr(17, ctx.gpr[5] | 0u);
    goto L_08B41F58;
L_08B41F58:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(8), ctx.gpr[18]);
    goto L_08B41F5C;
L_08B41F5C:
    ctx.set_gpr(18, ctx.gpr[16] + static_cast<std::uint32_t>(4));
    goto L_08B41F60;
L_08B41F60:
    ctx.set_gpr(5, 2228u << 16u);
    goto L_08B41F64;
L_08B41F64:
    ctx.set_gpr(6, 2228u << 16u);
    goto L_08B41F68;
L_08B41F68:
    ctx.set_gpr(7, 2228u << 16u);
    goto L_08B41F6C;
L_08B41F6C:
    ctx.set_gpr(4, ctx.gpr[18] | 0u);
    goto L_08B41F70;
L_08B41F70:
    ctx.set_gpr(5, ctx.gpr[5] + static_cast<std::uint32_t>(7808));
    goto L_08B41F74;
L_08B41F74:
    ctx.set_gpr(6, ctx.gpr[6] + static_cast<std::uint32_t>(7872));
    goto L_08B41F78;
L_08B41F78:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(12), ctx.gpr[31]);
    goto L_08B41F7C;
L_08B41F7C:
    ctx.set_gpr(31, 0x08B41F84u);
    ctx.set_gpr(7, ctx.gpr[7] + static_cast<std::uint32_t>(7904));
    ctx.pc = 0x0886503Cu;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B41F84u) goto L_08B41F84;
    return;
L_08B41F84:
    ctx.set_gpr(31, 0x08B41F8Cu);
    ctx.set_gpr(4, ctx.gpr[18] | 0u);
    ctx.pc = 0x088650A4u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B41F8Cu) goto L_08B41F8C;
    return;
L_08B41F8C:
    rt.memory().aot_store32(ctx.gpr[16] + static_cast<std::uint32_t>(56), ctx.gpr[17]);
    goto L_08B41F90;
L_08B41F90:
    ctx.set_gpr(16, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(0)));
    goto L_08B41F94;
L_08B41F94:
    ctx.set_gpr(17, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(4)));
    goto L_08B41F98;
L_08B41F98:
    ctx.set_gpr(18, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(8)));
    goto L_08B41F9C;
L_08B41F9C:
    ctx.set_gpr(31, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(12)));
    goto L_08B41FA0;
L_08B41FA0:
    jump_target = ctx.gpr[31];
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(16));
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08B41FA8:
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(-16));
    goto L_08B41FAC;
L_08B41FAC:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(0), ctx.gpr[16]);
    goto L_08B41FB0;
L_08B41FB0:
    ctx.set_gpr(16, ctx.gpr[4] | 0u);
    goto L_08B41FB4;
L_08B41FB4:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(4), ctx.gpr[17]);
    goto L_08B41FB8;
L_08B41FB8:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(8), ctx.gpr[31]);
    goto L_08B41FBC;
L_08B41FBC:
    ctx.set_gpr(31, 0x08B41FC4u);
    ctx.set_gpr(4, 0u | 1024u);
    ctx.pc = 0x088820D8u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B41FC4u) goto L_08B41FC4;
    return;
L_08B41FC4:
    ctx.set_gpr(17, ctx.gpr[16] + static_cast<std::uint32_t>(4));
    goto L_08B41FC8;
L_08B41FC8:
    rt.memory().aot_store32(ctx.gpr[16] + static_cast<std::uint32_t>(0), ctx.gpr[2]);
    goto L_08B41FCC;
L_08B41FCC:
    ctx.set_gpr(4, ctx.gpr[17] | 0u);
    goto L_08B41FD0;
L_08B41FD0:
    ctx.set_gpr(5, ctx.gpr[2] | 0u);
    goto L_08B41FD4;
L_08B41FD4:
    ctx.set_gpr(31, 0x08B41FDCu);
    ctx.set_gpr(6, 0u | 1024u);
    ctx.pc = 0x0886504Cu;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B41FDCu) goto L_08B41FDC;
    return;
L_08B41FDC:
    ctx.set_gpr(4, 0u + static_cast<std::uint32_t>(-1));
    goto L_08B41FE0;
L_08B41FE0:
    rt.memory().aot_store32(ctx.gpr[16] + static_cast<std::uint32_t>(44), ctx.gpr[4]);
    goto L_08B41FE4;
L_08B41FE4:
    rt.memory().aot_store32(ctx.gpr[16] + static_cast<std::uint32_t>(48), ctx.gpr[4]);
    goto L_08B41FE8;
L_08B41FE8:
    ctx.set_gpr(7, 2228u << 16u);
    goto L_08B41FEC;
L_08B41FEC:
    ctx.set_gpr(8, 2228u << 16u);
    goto L_08B41FF0;
L_08B41FF0:
    ctx.set_gpr(4, ctx.gpr[17] | 0u);
    goto L_08B41FF4;
L_08B41FF4:
    ctx.set_gpr(5, 0u + static_cast<std::uint32_t>(-1));
    goto L_08B41FF8;
L_08B41FF8:
    ctx.set_gpr(6, 0u | 1000u);
    goto L_08B41FFC;
L_08B41FFC:
    ctx.set_gpr(7, ctx.gpr[7] + static_cast<std::uint32_t>(7840));
    ctx.pc = 0x08B42000u; return;
}

void sub_08B41F00(Runtime &rt, AllegrexContext &ctx) {
    auto aot_mem = rt.memory().aot_fast_view();
    sub_08B41F00_entry(rt, ctx, 0u, aot_mem);
}

static const std::uint16_t kEntryIds_sub_08B42234[64] = {
    1, 2, 0, 3, 4, 5, 0, 6, 0, 7, 0, 8, 9, 0, 10, 11, 12, 13, 14, 15, 16, 17, 18, 0, 19, 0, 20, 21, 22, 0, 23, 24,
    0, 25, 26, 27, 28, 29, 30, 31, 0, 32, 0, 33, 34, 35, 0, 36, 37, 38, 39, 40, 0, 41, 42, 43, 44, 45, 46, 47, 0, 48, 49, 50,
};
void sub_08B42234_entry(Runtime &rt, AllegrexContext &ctx, std::uint16_t direct_entry_id, GuestMemory::AotFastView &aot_mem) {
    std::uint32_t jump_target = 0u;
    std::uint32_t local_transfers = 0u;
    std::uint32_t local_pc = ctx.pc;
    std::uint32_t entry_id = direct_entry_id;
LOCAL_DISPATCH:
    {
    if (entry_id == 0u) {
        const std::uint32_t entry_delta = local_pc - 0x08B42234u;
        entry_id = (entry_delta < 256u && (entry_delta & 3u) == 0u) ? kEntryIds_sub_08B42234[entry_delta >> 2u] : 0u;
    }
    switch (entry_id) {
    case 1u: goto L_08B42234;
    case 2u: goto L_08B42238;
    case 3u: goto L_08B42240;
    case 4u: goto L_08B42244;
    case 5u: goto L_08B42248;
    case 6u: goto L_08B42250;
    case 7u: goto L_08B42258;
    case 8u: goto L_08B42260;
    case 9u: goto L_08B42264;
    case 10u: goto L_08B4226C;
    case 11u: goto L_08B42270;
    case 12u: goto L_08B42274;
    case 13u: goto L_08B42278;
    case 14u: goto L_08B4227C;
    case 15u: goto L_08B42280;
    case 16u: goto L_08B42284;
    case 17u: goto L_08B42288;
    case 18u: goto L_08B4228C;
    case 19u: goto L_08B42294;
    case 20u: goto L_08B4229C;
    case 21u: goto L_08B422A0;
    case 22u: goto L_08B422A4;
    case 23u: goto L_08B422AC;
    case 24u: goto L_08B422B0;
    case 25u: goto L_08B422B8;
    case 26u: goto L_08B422BC;
    case 27u: goto L_08B422C0;
    case 28u: goto L_08B422C4;
    case 29u: goto L_08B422C8;
    case 30u: goto L_08B422CC;
    case 31u: goto L_08B422D0;
    case 32u: goto L_08B422D8;
    case 33u: goto L_08B422E0;
    case 34u: goto L_08B422E4;
    case 35u: goto L_08B422E8;
    case 36u: goto L_08B422F0;
    case 37u: goto L_08B422F4;
    case 38u: goto L_08B422F8;
    case 39u: goto L_08B422FC;
    case 40u: goto L_08B42300;
    case 41u: goto L_08B42308;
    case 42u: goto L_08B4230C;
    case 43u: goto L_08B42310;
    case 44u: goto L_08B42314;
    case 45u: goto L_08B42318;
    case 46u: goto L_08B4231C;
    case 47u: goto L_08B42320;
    case 48u: goto L_08B42328;
    case 49u: goto L_08B4232C;
    case 50u: goto L_08B42330;
    default:
        if (local_transfers == 0u) rt.unsupported(ctx.pc, 0u, "invalid internal function entry");
        else ctx.pc = local_pc;
        return;
    }
    }
L_08B42234:
    rt.memory().aot_store8(ctx.gpr[4] + static_cast<std::uint32_t>(4), static_cast<std::uint8_t>(0u));
    goto L_08B42238;
L_08B42238:
    jump_target = ctx.gpr[31];
    ctx.set_gpr(2, ctx.gpr[4] | 0u);
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08B42240:
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(-16));
    goto L_08B42244;
L_08B42244:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(0), ctx.gpr[31]);
    goto L_08B42248;
L_08B42248:
    { const bool branch_taken = ctx.gpr[4] == 0u;
    ctx.set_gpr(5, ctx.gpr[5] & 1u);
      if (branch_taken) {
          goto L_08B42260;
      }
      goto L_08B42250;
    }
L_08B42250:
    { const bool branch_taken = ctx.gpr[5] == 0u;
    // nop
      if (branch_taken) {
          goto L_08B42260;
      }
      goto L_08B42258;
    }
L_08B42258:
    ctx.set_gpr(31, 0x08B42260u);
    // nop
    ctx.pc = 0x08992F04u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B42260u) goto L_08B42260;
    return;
L_08B42260:
    ctx.set_gpr(31, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(0)));
    goto L_08B42264;
L_08B42264:
    jump_target = ctx.gpr[31];
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(16));
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08B4226C:
    // nop
    goto L_08B42270;
L_08B42270:
    rt.unsupported(0x08B42270u, 0x69676572u, "unknown not lowered yet"); return;
L_08B42274:
    rt.unsupported(0x08B42274u, 0x722F6E6Fu, "unknown not lowered yet"); return;
L_08B42278:
    rt.unsupported(0x08B42278u, 0x7379735Fu, "unknown not lowered yet"); return;
L_08B4227C:
    ctx.set_gpr(13, ctx.gpr[11] < static_cast<std::uint32_t>(25972) ? 1u : 0u);
    goto L_08B42280;
L_08B42280:
    ctx.execute_vfpu_vscl(101u, 102u, 102u, 1u);
    goto L_08B42284;
L_08B42284:
    // nop
    goto L_08B42288;
L_08B42288:
    // nop
    goto L_08B4228C;
L_08B4228C:
    rt.memory().aot_store16(ctx.gpr[4] + static_cast<std::uint32_t>(0), static_cast<std::uint16_t>(ctx.gpr[5]));
    ctx.pc = 0x02D089C0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_08B42294:
    jump_target = ctx.gpr[31];
    ctx.set_gpr(2, ctx.gpr[4] | 0u);
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08B4229C:
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(-16));
    goto L_08B422A0;
L_08B422A0:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(0), ctx.gpr[31]);
    goto L_08B422A4;
L_08B422A4:
    ctx.set_gpr(31, 0x08B422ACu);
    rt.memory().aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(0), ctx.gpr[5]);
    ctx.pc = 0x08B423D0u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B422ACu) goto L_08B422AC;
    return;
L_08B422AC:
    ctx.set_gpr(31, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(0)));
    goto L_08B422B0;
L_08B422B0:
    jump_target = ctx.gpr[31];
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(16));
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08B422B8:
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(-16));
    goto L_08B422BC;
L_08B422BC:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(0), ctx.gpr[16]);
    goto L_08B422C0;
L_08B422C0:
    ctx.set_gpr(16, ctx.gpr[4] | 0u);
    goto L_08B422C4;
L_08B422C4:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[16] + static_cast<std::uint32_t>(0)));
    goto L_08B422C8;
L_08B422C8:
    ctx.set_gpr(5, rt.memory().aot_load32(ctx.gpr[16] + static_cast<std::uint32_t>(12)));
    goto L_08B422CC;
L_08B422CC:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(4), ctx.gpr[31]);
    goto L_08B422D0;
L_08B422D0:
    ctx.set_gpr(31, 0x08B422D8u);
    ctx.set_gpr(6, 0u | 64u);
    ctx.pc = 0x0885C538u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B422D8u) goto L_08B422D8;
    return;
L_08B422D8:
    ctx.set_gpr(31, 0x08B422E0u);
    ctx.set_gpr(4, ctx.gpr[16] | 0u);
    ctx.pc = 0x08B423BCu;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B422E0u) goto L_08B422E0;
    return;
L_08B422E0:
    ctx.set_gpr(16, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(0)));
    goto L_08B422E4;
L_08B422E4:
    ctx.set_gpr(31, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(4)));
    goto L_08B422E8;
L_08B422E8:
    jump_target = ctx.gpr[31];
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(16));
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08B422F0:
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(-48));
    goto L_08B422F4;
L_08B422F4:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(32), ctx.gpr[16]);
    goto L_08B422F8;
L_08B422F8:
    ctx.set_gpr(16, ctx.gpr[4] | 0u);
    goto L_08B422FC;
L_08B422FC:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(36), ctx.gpr[31]);
    goto L_08B42300;
L_08B42300:
    ctx.set_gpr(31, 0x08B42308u);
    ctx.set_gpr(4, ctx.gpr[29] | 0u);
    ctx.pc = 0x08B42290u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B42308u) goto L_08B42308;
    return;
L_08B42308:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[16] + static_cast<std::uint32_t>(4)));
    goto L_08B4230C;
L_08B4230C:
    ctx.set_gpr(5, rt.memory().aot_load32(ctx.gpr[16] + static_cast<std::uint32_t>(8)));
    goto L_08B42310;
L_08B42310:
    ctx.set_gpr(4, ctx.gpr[4] << 5u);
    goto L_08B42314;
L_08B42314:
    ctx.set_gpr(6, ctx.gpr[5] + ctx.gpr[4]);
    goto L_08B42318;
L_08B42318:
    ctx.set_gpr(4, ctx.gpr[5] | 0u);
    goto L_08B4231C;
L_08B4231C:
    ctx.set_gpr(5, ctx.gpr[6] | 0u);
    goto L_08B42320;
L_08B42320:
    ctx.set_gpr(31, 0x08B42328u);
    ctx.set_gpr(6, ctx.gpr[29] | 0u);
    ctx.pc = 0x08B42524u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B42328u) goto L_08B42328;
    return;
L_08B42328:
    ctx.set_gpr(5, rt.memory().aot_load32(ctx.gpr[16] + static_cast<std::uint32_t>(4)));
    goto L_08B4232C;
L_08B4232C:
    ctx.set_gpr(6, rt.memory().aot_load32(ctx.gpr[16] + static_cast<std::uint32_t>(8)));
    goto L_08B42330;
L_08B42330:
    ctx.set_gpr(5, ctx.gpr[5] << 5u);
    ctx.pc = 0x08B42334u; return;
}

void sub_08B42234(Runtime &rt, AllegrexContext &ctx) {
    auto aot_mem = rt.memory().aot_fast_view();
    sub_08B42234_entry(rt, ctx, 0u, aot_mem);
}

static const std::uint16_t kEntryIds_sub_08B42368[64] = {
    1, 2, 3, 4, 0, 5, 6, 7, 8, 0, 9, 10, 11, 0, 12, 0, 13, 0, 14, 15, 0, 16, 17, 18, 19, 0, 20, 21, 22, 23, 24, 25,
    26, 27, 28, 29, 0, 30, 31, 32, 33, 34, 35, 36, 0, 37, 38, 39, 40, 41, 0, 42, 43, 44, 0, 45, 46, 47, 48, 0, 49, 50, 51, 52,
};
void sub_08B42368_entry(Runtime &rt, AllegrexContext &ctx, std::uint16_t direct_entry_id, GuestMemory::AotFastView &aot_mem) {
    std::uint32_t jump_target = 0u;
    std::uint32_t local_transfers = 0u;
    std::uint32_t local_pc = ctx.pc;
    std::uint32_t entry_id = direct_entry_id;
LOCAL_DISPATCH:
    {
    if (entry_id == 0u) {
        const std::uint32_t entry_delta = local_pc - 0x08B42368u;
        entry_id = (entry_delta < 256u && (entry_delta & 3u) == 0u) ? kEntryIds_sub_08B42368[entry_delta >> 2u] : 0u;
    }
    switch (entry_id) {
    case 1u: goto L_08B42368;
    case 2u: goto L_08B4236C;
    case 3u: goto L_08B42370;
    case 4u: goto L_08B42374;
    case 5u: goto L_08B4237C;
    case 6u: goto L_08B42380;
    case 7u: goto L_08B42384;
    case 8u: goto L_08B42388;
    case 9u: goto L_08B42390;
    case 10u: goto L_08B42394;
    case 11u: goto L_08B42398;
    case 12u: goto L_08B423A0;
    case 13u: goto L_08B423A8;
    case 14u: goto L_08B423B0;
    case 15u: goto L_08B423B4;
    case 16u: goto L_08B423BC;
    case 17u: goto L_08B423C0;
    case 18u: goto L_08B423C4;
    case 19u: goto L_08B423C8;
    case 20u: goto L_08B423D0;
    case 21u: goto L_08B423D4;
    case 22u: goto L_08B423D8;
    case 23u: goto L_08B423DC;
    case 24u: goto L_08B423E0;
    case 25u: goto L_08B423E4;
    case 26u: goto L_08B423E8;
    case 27u: goto L_08B423EC;
    case 28u: goto L_08B423F0;
    case 29u: goto L_08B423F4;
    case 30u: goto L_08B423FC;
    case 31u: goto L_08B42400;
    case 32u: goto L_08B42404;
    case 33u: goto L_08B42408;
    case 34u: goto L_08B4240C;
    case 35u: goto L_08B42410;
    case 36u: goto L_08B42414;
    case 37u: goto L_08B4241C;
    case 38u: goto L_08B42420;
    case 39u: goto L_08B42424;
    case 40u: goto L_08B42428;
    case 41u: goto L_08B4242C;
    case 42u: goto L_08B42434;
    case 43u: goto L_08B42438;
    case 44u: goto L_08B4243C;
    case 45u: goto L_08B42444;
    case 46u: goto L_08B42448;
    case 47u: goto L_08B4244C;
    case 48u: goto L_08B42450;
    case 49u: goto L_08B42458;
    case 50u: goto L_08B4245C;
    case 51u: goto L_08B42460;
    case 52u: goto L_08B42464;
    default:
        if (local_transfers == 0u) rt.unsupported(ctx.pc, 0u, "invalid internal function entry");
        else ctx.pc = local_pc;
        return;
    }
    }
L_08B42368:
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(-16));
    goto L_08B4236C;
L_08B4236C:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(0), ctx.gpr[16]);
    goto L_08B42370;
L_08B42370:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(4), ctx.gpr[31]);
    goto L_08B42374;
L_08B42374:
    ctx.set_gpr(31, 0x08B4237Cu);
    ctx.set_gpr(16, ctx.gpr[4] | 0u);
    goto L_08B423BC;
L_08B4237C:
    ctx.set_gpr(2, ctx.gpr[16] | 0u);
    goto L_08B42380;
L_08B42380:
    ctx.set_gpr(16, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(0)));
    goto L_08B42384;
L_08B42384:
    ctx.set_gpr(31, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(4)));
    goto L_08B42388;
L_08B42388:
    jump_target = ctx.gpr[31];
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(16));
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08B42390:
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(-16));
    goto L_08B42394;
L_08B42394:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(0), ctx.gpr[31]);
    goto L_08B42398;
L_08B42398:
    { const bool branch_taken = ctx.gpr[4] == 0u;
    ctx.set_gpr(5, ctx.gpr[5] & 1u);
      if (branch_taken) {
          goto L_08B423B0;
      }
      goto L_08B423A0;
    }
L_08B423A0:
    { const bool branch_taken = ctx.gpr[5] == 0u;
    // nop
      if (branch_taken) {
          goto L_08B423B0;
      }
      goto L_08B423A8;
    }
L_08B423A8:
    ctx.set_gpr(31, 0x08B423B0u);
    // nop
    ctx.pc = 0x08992F04u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B423B0u) goto L_08B423B0;
    return;
L_08B423B0:
    ctx.set_gpr(31, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(0)));
    goto L_08B423B4;
L_08B423B4:
    jump_target = ctx.gpr[31];
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(16));
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08B423BC:
    rt.memory().aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(0), 0u);
    goto L_08B423C0;
L_08B423C0:
    rt.memory().aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(4), 0u);
    goto L_08B423C4;
L_08B423C4:
    rt.memory().aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(8), 0u);
    goto L_08B423C8;
L_08B423C8:
    jump_target = ctx.gpr[31];
    rt.memory().aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(12), 0u);
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08B423D0:
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(-16));
    goto L_08B423D4;
L_08B423D4:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(0), ctx.gpr[16]);
    goto L_08B423D8;
L_08B423D8:
    ctx.set_gpr(16, ctx.gpr[4] | 0u);
    goto L_08B423DC;
L_08B423DC:
    ctx.set_gpr(4, 2228u << 16u);
    goto L_08B423E0;
L_08B423E0:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(4), ctx.gpr[17]);
    goto L_08B423E4;
L_08B423E4:
    ctx.set_gpr(17, ctx.gpr[4] + static_cast<std::uint32_t>(9864));
    goto L_08B423E8;
L_08B423E8:
    ctx.set_gpr(4, ctx.gpr[17] | 0u);
    goto L_08B423EC;
L_08B423EC:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(8), ctx.gpr[18]);
    goto L_08B423F0;
L_08B423F0:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(12), ctx.gpr[31]);
    goto L_08B423F4;
L_08B423F4:
    ctx.set_gpr(31, 0x08B423FCu);
    ctx.set_gpr(5, 0u | 0u);
    ctx.pc = 0x088FE7C8u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B423FCu) goto L_08B423FC;
    return;
L_08B423FC:
    ctx.set_gpr(18, ctx.gpr[2] | 0u);
    goto L_08B42400;
L_08B42400:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[16] + static_cast<std::uint32_t>(0)));
    goto L_08B42404;
L_08B42404:
    ctx.set_gpr(5, ctx.gpr[18] | 0u);
    goto L_08B42408;
L_08B42408:
    ctx.set_gpr(6, 0u | 64u);
    goto L_08B4240C;
L_08B4240C:
    ctx.set_gpr(7, 0u | 0u);
    goto L_08B42410;
L_08B42410:
    ctx.set_gpr(8, 0u | 1u);
    goto L_08B42414;
L_08B42414:
    ctx.set_gpr(31, 0x08B4241Cu);
    ctx.set_gpr(9, 0u | 0u);
    ctx.pc = 0x0885C6CCu;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B4241Cu) goto L_08B4241C;
    return;
L_08B4241C:
    rt.memory().aot_store32(ctx.gpr[16] + static_cast<std::uint32_t>(12), ctx.gpr[2]);
    goto L_08B42420;
L_08B42420:
    ctx.set_gpr(4, ctx.gpr[17] | 0u);
    goto L_08B42424;
L_08B42424:
    ctx.set_gpr(5, ctx.gpr[2] | 0u);
    goto L_08B42428;
L_08B42428:
    ctx.set_gpr(6, ctx.gpr[18] | 0u);
    goto L_08B4242C;
L_08B4242C:
    ctx.set_gpr(31, 0x08B42434u);
    ctx.set_gpr(7, 0u | 0u);
    ctx.pc = 0x088FE708u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B42434u) goto L_08B42434;
    return;
L_08B42434:
    ctx.set_gpr(5, rt.memory().aot_load32(ctx.gpr[16] + static_cast<std::uint32_t>(12)));
    goto L_08B42438;
L_08B42438:
    ctx.set_gpr(4, ctx.gpr[17] | 0u);
    goto L_08B4243C;
L_08B4243C:
    ctx.set_gpr(31, 0x08B42444u);
    ctx.set_gpr(6, ctx.gpr[2] | 0u);
    ctx.pc = 0x088FE944u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B42444u) goto L_08B42444;
    return;
L_08B42444:
    ctx.set_gpr(5, 2228u << 16u);
    goto L_08B42448;
L_08B42448:
    ctx.set_gpr(17, rt.memory().aot_load32(ctx.gpr[16] + static_cast<std::uint32_t>(12)));
    goto L_08B4244C;
L_08B4244C:
    ctx.set_gpr(5, ctx.gpr[5] + static_cast<std::uint32_t>(9900));
    goto L_08B42450;
L_08B42450:
    ctx.set_gpr(31, 0x08B42458u);
    ctx.set_gpr(4, ctx.gpr[17] | 0u);
    ctx.pc = 0x08935970u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B42458u) goto L_08B42458;
    return;
L_08B42458:
    ctx.set_gpr(4, static_cast<std::uint32_t>(static_cast<std::int32_t>(static_cast<std::int16_t>(rt.memory().aot_load16(ctx.gpr[17] + static_cast<std::uint32_t>(8))))));
    goto L_08B4245C;
L_08B4245C:
    ctx.set_gpr(5, ctx.gpr[17] + static_cast<std::uint32_t>(16));
    goto L_08B42460;
L_08B42460:
    rt.memory().aot_store32(ctx.gpr[16] + static_cast<std::uint32_t>(4), ctx.gpr[4]);
    goto L_08B42464;
L_08B42464:
    rt.memory().aot_store32(ctx.gpr[16] + static_cast<std::uint32_t>(8), ctx.gpr[5]);
    ctx.pc = 0x08B42468u; return;
}

void sub_08B42368(Runtime &rt, AllegrexContext &ctx) {
    auto aot_mem = rt.memory().aot_fast_view();
    sub_08B42368_entry(rt, ctx, 0u, aot_mem);
}

static const std::uint16_t kEntryIds_sub_08B42A04[64] = {
    1, 2, 3, 4, 0, 5, 6, 7, 8, 0, 9, 10, 11, 0, 12, 0, 13, 0, 14, 15, 0, 16, 17, 0, 18, 19, 20, 21, 22, 23, 24, 25,
    26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 0, 36, 37, 38, 39, 40, 41, 42, 43, 0, 44, 45, 46, 47, 48, 49, 0, 50, 51, 52, 53, 54,
};
void sub_08B42A04_entry(Runtime &rt, AllegrexContext &ctx, std::uint16_t direct_entry_id, GuestMemory::AotFastView &aot_mem) {
    std::uint32_t jump_target = 0u;
    std::uint32_t local_transfers = 0u;
    std::uint32_t local_pc = ctx.pc;
    std::uint32_t entry_id = direct_entry_id;
LOCAL_DISPATCH:
    {
    if (entry_id == 0u) {
        const std::uint32_t entry_delta = local_pc - 0x08B42A04u;
        entry_id = (entry_delta < 256u && (entry_delta & 3u) == 0u) ? kEntryIds_sub_08B42A04[entry_delta >> 2u] : 0u;
    }
    switch (entry_id) {
    case 1u: goto L_08B42A04;
    case 2u: goto L_08B42A08;
    case 3u: goto L_08B42A0C;
    case 4u: goto L_08B42A10;
    case 5u: goto L_08B42A18;
    case 6u: goto L_08B42A1C;
    case 7u: goto L_08B42A20;
    case 8u: goto L_08B42A24;
    case 9u: goto L_08B42A2C;
    case 10u: goto L_08B42A30;
    case 11u: goto L_08B42A34;
    case 12u: goto L_08B42A3C;
    case 13u: goto L_08B42A44;
    case 14u: goto L_08B42A4C;
    case 15u: goto L_08B42A50;
    case 16u: goto L_08B42A58;
    case 17u: goto L_08B42A5C;
    case 18u: goto L_08B42A64;
    case 19u: goto L_08B42A68;
    case 20u: goto L_08B42A6C;
    case 21u: goto L_08B42A70;
    case 22u: goto L_08B42A74;
    case 23u: goto L_08B42A78;
    case 24u: goto L_08B42A7C;
    case 25u: goto L_08B42A80;
    case 26u: goto L_08B42A84;
    case 27u: goto L_08B42A88;
    case 28u: goto L_08B42A8C;
    case 29u: goto L_08B42A90;
    case 30u: goto L_08B42A94;
    case 31u: goto L_08B42A98;
    case 32u: goto L_08B42A9C;
    case 33u: goto L_08B42AA0;
    case 34u: goto L_08B42AA4;
    case 35u: goto L_08B42AA8;
    case 36u: goto L_08B42AB0;
    case 37u: goto L_08B42AB4;
    case 38u: goto L_08B42AB8;
    case 39u: goto L_08B42ABC;
    case 40u: goto L_08B42AC0;
    case 41u: goto L_08B42AC4;
    case 42u: goto L_08B42AC8;
    case 43u: goto L_08B42ACC;
    case 44u: goto L_08B42AD4;
    case 45u: goto L_08B42AD8;
    case 46u: goto L_08B42ADC;
    case 47u: goto L_08B42AE0;
    case 48u: goto L_08B42AE4;
    case 49u: goto L_08B42AE8;
    case 50u: goto L_08B42AF0;
    case 51u: goto L_08B42AF4;
    case 52u: goto L_08B42AF8;
    case 53u: goto L_08B42AFC;
    case 54u: goto L_08B42B00;
    default:
        if (local_transfers == 0u) rt.unsupported(ctx.pc, 0u, "invalid internal function entry");
        else ctx.pc = local_pc;
        return;
    }
    }
L_08B42A04:
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(-16));
    goto L_08B42A08;
L_08B42A08:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(0), ctx.gpr[16]);
    goto L_08B42A0C;
L_08B42A0C:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(4), ctx.gpr[31]);
    goto L_08B42A10;
L_08B42A10:
    ctx.set_gpr(31, 0x08B42A18u);
    ctx.set_gpr(16, ctx.gpr[4] | 0u);
    goto L_08B42A58;
L_08B42A18:
    ctx.set_gpr(2, ctx.gpr[16] | 0u);
    goto L_08B42A1C;
L_08B42A1C:
    ctx.set_gpr(16, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(0)));
    goto L_08B42A20;
L_08B42A20:
    ctx.set_gpr(31, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(4)));
    goto L_08B42A24;
L_08B42A24:
    jump_target = ctx.gpr[31];
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(16));
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08B42A2C:
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(-16));
    goto L_08B42A30;
L_08B42A30:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(0), ctx.gpr[31]);
    goto L_08B42A34;
L_08B42A34:
    { const bool branch_taken = ctx.gpr[4] == 0u;
    ctx.set_gpr(5, ctx.gpr[5] & 1u);
      if (branch_taken) {
          goto L_08B42A4C;
      }
      goto L_08B42A3C;
    }
L_08B42A3C:
    { const bool branch_taken = ctx.gpr[5] == 0u;
    // nop
      if (branch_taken) {
          goto L_08B42A4C;
      }
      goto L_08B42A44;
    }
L_08B42A44:
    ctx.set_gpr(31, 0x08B42A4Cu);
    // nop
    ctx.pc = 0x08992F04u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B42A4Cu) goto L_08B42A4C;
    return;
L_08B42A4C:
    ctx.set_gpr(31, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(0)));
    goto L_08B42A50;
L_08B42A50:
    jump_target = ctx.gpr[31];
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(16));
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08B42A58:
    rt.memory().aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(0), 0u);
    goto L_08B42A5C;
L_08B42A5C:
    jump_target = ctx.gpr[31];
    rt.memory().aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(4), 0u);
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08B42A64:
    // nop
    goto L_08B42A68;
L_08B42A68:
    rt.unsupported(0x08B42A68u, 0x676E7564u, "vfpu1 not lowered yet"); return;
L_08B42A6C:
    ctx.set_gpr(14, ctx.gpr[27] < static_cast<std::uint32_t>(28517) ? 1u : 0u);
    goto L_08B42A70;
L_08B42A70:
    rt.unsupported(0x08B42A70u, 0x61776572u, "vfpu0 not lowered yet"); return;
L_08B42A74:
    { float vfpu_s[4]{}, vfpu_t[4]{}, vfpu_d[4]{};
      ctx.read_vfpu_vector_with_source_prefix(vfpu_s, 100u, 1u, 0u);
      ctx.read_vfpu_vector_with_source_prefix(vfpu_t, 47u, 1u, 1u);
      for (std::uint32_t i = 0; i < 1u; ++i) vfpu_d[i] = vfpu_s[i] * vfpu_t[i];
      ctx.write_vfpu_vector_with_destination_prefix(vfpu_d, 114u, 1u); }
    goto L_08B42A78;
L_08B42A78:
    ctx.execute_vfpu_vscl(117u, 110u, 103u, 1u);
    goto L_08B42A7C;
L_08B42A7C:
    rt.unsupported(0x08B42A7Cu, 0x725F6E6Fu, "unknown not lowered yet"); return;
L_08B42A80:
    rt.unsupported(0x08B42A80u, 0x72617765u, "unknown not lowered yet"); return;
L_08B42A84:
    rt.unsupported(0x08B42A84u, 0x61725F64u, "vfpu0 not lowered yet"); return;
L_08B42A88:
    ctx.execute_vfpu_vminmax(110u, 100u, 111u, 1u, false);
    goto L_08B42A8C;
L_08B42A8C:
    rt.unsupported(0x08B42A8Cu, 0x7272642Eu, "unknown not lowered yet"); return;
L_08B42A90:
    // nop
    goto L_08B42A94;
L_08B42A94:
    ctx.set_gpr(14, ctx.gpr[3] & ctx.gpr[18]);
    goto L_08B42A98;
L_08B42A98:
    // nop
    goto L_08B42A9C;
L_08B42A9C:
    // nop
    goto L_08B42AA0;
L_08B42AA0:
    rt.memory().aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(4), 0u);
    goto L_08B42AA4;
L_08B42AA4:
    rt.memory().aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(0), 0u);
    goto L_08B42AA8;
L_08B42AA8:
    jump_target = ctx.gpr[31];
    ctx.set_gpr(2, ctx.gpr[4] | 0u);
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08B42AB0:
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(-16));
    goto L_08B42AB4;
L_08B42AB4:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(0), ctx.gpr[16]);
    goto L_08B42AB8;
L_08B42AB8:
    ctx.set_gpr(16, ctx.gpr[4] | 0u);
    goto L_08B42ABC;
L_08B42ABC:
    ctx.set_gpr(4, 39u << 16u);
    goto L_08B42AC0;
L_08B42AC0:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(4), ctx.gpr[17]);
    goto L_08B42AC4;
L_08B42AC4:
    ctx.set_gpr(17, ctx.gpr[4] + static_cast<std::uint32_t>(2048));
    goto L_08B42AC8;
L_08B42AC8:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(8), ctx.gpr[31]);
    goto L_08B42ACC;
L_08B42ACC:
    ctx.set_gpr(31, 0x08B42AD4u);
    ctx.set_gpr(4, ctx.gpr[17] | 0u);
    ctx.pc = 0x0888204Cu;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B42AD4u) goto L_08B42AD4;
    return;
L_08B42AD4:
    ctx.set_gpr(6, 2228u << 16u);
    goto L_08B42AD8;
L_08B42AD8:
    rt.memory().aot_store32(ctx.gpr[16] + static_cast<std::uint32_t>(0), ctx.gpr[2]);
    goto L_08B42ADC;
L_08B42ADC:
    ctx.set_gpr(4, ctx.gpr[2] | 0u);
    goto L_08B42AE0;
L_08B42AE0:
    ctx.set_gpr(5, ctx.gpr[17] | 0u);
    goto L_08B42AE4;
L_08B42AE4:
    ctx.set_gpr(7, 0u | 16u);
    goto L_08B42AE8;
L_08B42AE8:
    ctx.set_gpr(31, 0x08B42AF0u);
    ctx.set_gpr(6, ctx.gpr[6] + static_cast<std::uint32_t>(11288));
    ctx.pc = 0x0885C40Cu;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B42AF0u) goto L_08B42AF0;
    return;
L_08B42AF0:
    rt.memory().aot_store32(ctx.gpr[16] + static_cast<std::uint32_t>(4), ctx.gpr[2]);
    goto L_08B42AF4;
L_08B42AF4:
    ctx.set_gpr(16, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(0)));
    goto L_08B42AF8;
L_08B42AF8:
    ctx.set_gpr(17, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(4)));
    goto L_08B42AFC;
L_08B42AFC:
    ctx.set_gpr(31, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(8)));
    goto L_08B42B00;
L_08B42B00:
    jump_target = ctx.gpr[31];
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(16));
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
}

void sub_08B42A04(Runtime &rt, AllegrexContext &ctx) {
    auto aot_mem = rt.memory().aot_fast_view();
    sub_08B42A04_entry(rt, ctx, 0u, aot_mem);
}

static const std::uint16_t kEntryIds_sub_08B42AA0[64] = {
    1, 2, 3, 0, 4, 5, 6, 7, 8, 9, 10, 11, 0, 12, 13, 14, 15, 16, 17, 0, 18, 19, 20, 21, 22, 0, 23, 24, 25, 26, 27, 0,
    28, 29, 0, 30, 31, 32, 33, 0, 34, 35, 36, 0, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 0, 47, 48, 0, 49, 50, 51, 52, 53, 54,
};
void sub_08B42AA0_entry(Runtime &rt, AllegrexContext &ctx, std::uint16_t direct_entry_id, GuestMemory::AotFastView &aot_mem) {
    std::uint32_t jump_target = 0u;
    std::uint32_t local_transfers = 0u;
    std::uint32_t local_pc = ctx.pc;
    std::uint32_t entry_id = direct_entry_id;
LOCAL_DISPATCH:
    {
    if (entry_id == 0u) {
        const std::uint32_t entry_delta = local_pc - 0x08B42AA0u;
        entry_id = (entry_delta < 256u && (entry_delta & 3u) == 0u) ? kEntryIds_sub_08B42AA0[entry_delta >> 2u] : 0u;
    }
    switch (entry_id) {
    case 1u: goto L_08B42AA0;
    case 2u: goto L_08B42AA4;
    case 3u: goto L_08B42AA8;
    case 4u: goto L_08B42AB0;
    case 5u: goto L_08B42AB4;
    case 6u: goto L_08B42AB8;
    case 7u: goto L_08B42ABC;
    case 8u: goto L_08B42AC0;
    case 9u: goto L_08B42AC4;
    case 10u: goto L_08B42AC8;
    case 11u: goto L_08B42ACC;
    case 12u: goto L_08B42AD4;
    case 13u: goto L_08B42AD8;
    case 14u: goto L_08B42ADC;
    case 15u: goto L_08B42AE0;
    case 16u: goto L_08B42AE4;
    case 17u: goto L_08B42AE8;
    case 18u: goto L_08B42AF0;
    case 19u: goto L_08B42AF4;
    case 20u: goto L_08B42AF8;
    case 21u: goto L_08B42AFC;
    case 22u: goto L_08B42B00;
    case 23u: goto L_08B42B08;
    case 24u: goto L_08B42B0C;
    case 25u: goto L_08B42B10;
    case 26u: goto L_08B42B14;
    case 27u: goto L_08B42B18;
    case 28u: goto L_08B42B20;
    case 29u: goto L_08B42B24;
    case 30u: goto L_08B42B2C;
    case 31u: goto L_08B42B30;
    case 32u: goto L_08B42B34;
    case 33u: goto L_08B42B38;
    case 34u: goto L_08B42B40;
    case 35u: goto L_08B42B44;
    case 36u: goto L_08B42B48;
    case 37u: goto L_08B42B50;
    case 38u: goto L_08B42B54;
    case 39u: goto L_08B42B58;
    case 40u: goto L_08B42B5C;
    case 41u: goto L_08B42B60;
    case 42u: goto L_08B42B64;
    case 43u: goto L_08B42B68;
    case 44u: goto L_08B42B6C;
    case 45u: goto L_08B42B70;
    case 46u: goto L_08B42B74;
    case 47u: goto L_08B42B7C;
    case 48u: goto L_08B42B80;
    case 49u: goto L_08B42B88;
    case 50u: goto L_08B42B8C;
    case 51u: goto L_08B42B90;
    case 52u: goto L_08B42B94;
    case 53u: goto L_08B42B98;
    case 54u: goto L_08B42B9C;
    default:
        if (local_transfers == 0u) rt.unsupported(ctx.pc, 0u, "invalid internal function entry");
        else ctx.pc = local_pc;
        return;
    }
    }
L_08B42AA0:
    rt.memory().aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(4), 0u);
    goto L_08B42AA4;
L_08B42AA4:
    rt.memory().aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(0), 0u);
    goto L_08B42AA8;
L_08B42AA8:
    jump_target = ctx.gpr[31];
    ctx.set_gpr(2, ctx.gpr[4] | 0u);
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08B42AB0:
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(-16));
    goto L_08B42AB4;
L_08B42AB4:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(0), ctx.gpr[16]);
    goto L_08B42AB8;
L_08B42AB8:
    ctx.set_gpr(16, ctx.gpr[4] | 0u);
    goto L_08B42ABC;
L_08B42ABC:
    ctx.set_gpr(4, 39u << 16u);
    goto L_08B42AC0;
L_08B42AC0:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(4), ctx.gpr[17]);
    goto L_08B42AC4;
L_08B42AC4:
    ctx.set_gpr(17, ctx.gpr[4] + static_cast<std::uint32_t>(2048));
    goto L_08B42AC8;
L_08B42AC8:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(8), ctx.gpr[31]);
    goto L_08B42ACC;
L_08B42ACC:
    ctx.set_gpr(31, 0x08B42AD4u);
    ctx.set_gpr(4, ctx.gpr[17] | 0u);
    ctx.pc = 0x0888204Cu;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B42AD4u) goto L_08B42AD4;
    return;
L_08B42AD4:
    ctx.set_gpr(6, 2228u << 16u);
    goto L_08B42AD8;
L_08B42AD8:
    rt.memory().aot_store32(ctx.gpr[16] + static_cast<std::uint32_t>(0), ctx.gpr[2]);
    goto L_08B42ADC;
L_08B42ADC:
    ctx.set_gpr(4, ctx.gpr[2] | 0u);
    goto L_08B42AE0;
L_08B42AE0:
    ctx.set_gpr(5, ctx.gpr[17] | 0u);
    goto L_08B42AE4;
L_08B42AE4:
    ctx.set_gpr(7, 0u | 16u);
    goto L_08B42AE8;
L_08B42AE8:
    ctx.set_gpr(31, 0x08B42AF0u);
    ctx.set_gpr(6, ctx.gpr[6] + static_cast<std::uint32_t>(11288));
    ctx.pc = 0x0885C40Cu;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B42AF0u) goto L_08B42AF0;
    return;
L_08B42AF0:
    rt.memory().aot_store32(ctx.gpr[16] + static_cast<std::uint32_t>(4), ctx.gpr[2]);
    goto L_08B42AF4;
L_08B42AF4:
    ctx.set_gpr(16, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(0)));
    goto L_08B42AF8;
L_08B42AF8:
    ctx.set_gpr(17, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(4)));
    goto L_08B42AFC;
L_08B42AFC:
    ctx.set_gpr(31, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(8)));
    goto L_08B42B00;
L_08B42B00:
    jump_target = ctx.gpr[31];
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(16));
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08B42B08:
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(-16));
    goto L_08B42B0C;
L_08B42B0C:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(0), ctx.gpr[16]);
    goto L_08B42B10;
L_08B42B10:
    ctx.set_gpr(16, ctx.gpr[4] | 0u);
    goto L_08B42B14;
L_08B42B14:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(4), ctx.gpr[31]);
    goto L_08B42B18;
L_08B42B18:
    ctx.set_gpr(31, 0x08B42B20u);
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[16] + static_cast<std::uint32_t>(4)));
    ctx.pc = 0x0885C488u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B42B20u) goto L_08B42B20;
    return;
L_08B42B20:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[16] + static_cast<std::uint32_t>(0)));
    goto L_08B42B24;
L_08B42B24:
    ctx.set_gpr(31, 0x08B42B2Cu);
    rt.memory().aot_store32(ctx.gpr[16] + static_cast<std::uint32_t>(4), 0u);
    ctx.pc = 0x0888208Cu;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B42B2Cu) goto L_08B42B2C;
    return;
L_08B42B2C:
    rt.memory().aot_store32(ctx.gpr[16] + static_cast<std::uint32_t>(0), 0u);
    goto L_08B42B30;
L_08B42B30:
    ctx.set_gpr(16, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(0)));
    goto L_08B42B34;
L_08B42B34:
    ctx.set_gpr(31, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(4)));
    goto L_08B42B38;
L_08B42B38:
    jump_target = ctx.gpr[31];
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(16));
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08B42B40:
    ctx.set_gpr(4, 2228u << 16u);
    goto L_08B42B44;
L_08B42B44:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(11304)));
    goto L_08B42B48;
L_08B42B48:
    jump_target = ctx.gpr[31];
    ctx.set_gpr(2, rt.memory().aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(4)));
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08B42B50:
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(-16));
    goto L_08B42B54;
L_08B42B54:
    ctx.set_gpr(5, ctx.gpr[4] | 0u);
    goto L_08B42B58;
L_08B42B58:
    ctx.set_gpr(4, 2228u << 16u);
    goto L_08B42B5C;
L_08B42B5C:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(11304)));
    goto L_08B42B60;
L_08B42B60:
    ctx.set_gpr(7, 0u | 0u);
    goto L_08B42B64;
L_08B42B64:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(4)));
    goto L_08B42B68;
L_08B42B68:
    ctx.set_gpr(8, 0u | 1u);
    goto L_08B42B6C;
L_08B42B6C:
    ctx.set_gpr(6, 0u | 0u);
    goto L_08B42B70;
L_08B42B70:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(0), ctx.gpr[31]);
    goto L_08B42B74;
L_08B42B74:
    ctx.set_gpr(31, 0x08B42B7Cu);
    ctx.set_gpr(9, 0u | 0u);
    ctx.pc = 0x0885C6CCu;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B42B7Cu) goto L_08B42B7C;
    return;
L_08B42B7C:
    ctx.set_gpr(31, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(0)));
    goto L_08B42B80;
L_08B42B80:
    jump_target = ctx.gpr[31];
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(16));
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08B42B88:
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(-16));
    goto L_08B42B8C;
L_08B42B8C:
    ctx.set_gpr(5, ctx.gpr[4] | 0u);
    goto L_08B42B90;
L_08B42B90:
    ctx.set_gpr(4, 2228u << 16u);
    goto L_08B42B94;
L_08B42B94:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(11304)));
    goto L_08B42B98;
L_08B42B98:
    ctx.set_gpr(6, 0u | 0u);
    goto L_08B42B9C;
L_08B42B9C:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(0), ctx.gpr[31]);
    ctx.pc = 0x08B42BA0u; return;
}

void sub_08B42AA0(Runtime &rt, AllegrexContext &ctx) {
    auto aot_mem = rt.memory().aot_fast_view();
    sub_08B42AA0_entry(rt, ctx, 0u, aot_mem);
}

static const std::uint16_t kEntryIds_sub_08B43620[64] = {
    1, 2, 3, 4, 0, 5, 6, 7, 8, 0, 9, 10, 11, 0, 12, 0, 13, 0, 14, 15, 0, 16, 17, 0, 18, 19, 20, 21, 22, 23, 24, 25,
    26, 27, 28, 29, 30, 0, 31, 32, 33, 0, 34, 35, 36, 0, 37, 38, 39, 40, 41, 0, 42, 43, 0, 44, 45, 46, 47, 48, 49, 50, 51, 52,
};
void sub_08B43620_entry(Runtime &rt, AllegrexContext &ctx, std::uint16_t direct_entry_id, GuestMemory::AotFastView &aot_mem) {
    std::uint32_t jump_target = 0u;
    std::uint32_t local_transfers = 0u;
    std::uint32_t local_pc = ctx.pc;
    std::uint32_t entry_id = direct_entry_id;
LOCAL_DISPATCH:
    {
    if (entry_id == 0u) {
        const std::uint32_t entry_delta = local_pc - 0x08B43620u;
        entry_id = (entry_delta < 256u && (entry_delta & 3u) == 0u) ? kEntryIds_sub_08B43620[entry_delta >> 2u] : 0u;
    }
    switch (entry_id) {
    case 1u: goto L_08B43620;
    case 2u: goto L_08B43624;
    case 3u: goto L_08B43628;
    case 4u: goto L_08B4362C;
    case 5u: goto L_08B43634;
    case 6u: goto L_08B43638;
    case 7u: goto L_08B4363C;
    case 8u: goto L_08B43640;
    case 9u: goto L_08B43648;
    case 10u: goto L_08B4364C;
    case 11u: goto L_08B43650;
    case 12u: goto L_08B43658;
    case 13u: goto L_08B43660;
    case 14u: goto L_08B43668;
    case 15u: goto L_08B4366C;
    case 16u: goto L_08B43674;
    case 17u: goto L_08B43678;
    case 18u: goto L_08B43680;
    case 19u: goto L_08B43684;
    case 20u: goto L_08B43688;
    case 21u: goto L_08B4368C;
    case 22u: goto L_08B43690;
    case 23u: goto L_08B43694;
    case 24u: goto L_08B43698;
    case 25u: goto L_08B4369C;
    case 26u: goto L_08B436A0;
    case 27u: goto L_08B436A4;
    case 28u: goto L_08B436A8;
    case 29u: goto L_08B436AC;
    case 30u: goto L_08B436B0;
    case 31u: goto L_08B436B8;
    case 32u: goto L_08B436BC;
    case 33u: goto L_08B436C0;
    case 34u: goto L_08B436C8;
    case 35u: goto L_08B436CC;
    case 36u: goto L_08B436D0;
    case 37u: goto L_08B436D8;
    case 38u: goto L_08B436DC;
    case 39u: goto L_08B436E0;
    case 40u: goto L_08B436E4;
    case 41u: goto L_08B436E8;
    case 42u: goto L_08B436F0;
    case 43u: goto L_08B436F4;
    case 44u: goto L_08B436FC;
    case 45u: goto L_08B43700;
    case 46u: goto L_08B43704;
    case 47u: goto L_08B43708;
    case 48u: goto L_08B4370C;
    case 49u: goto L_08B43710;
    case 50u: goto L_08B43714;
    case 51u: goto L_08B43718;
    case 52u: goto L_08B4371C;
    default:
        if (local_transfers == 0u) rt.unsupported(ctx.pc, 0u, "invalid internal function entry");
        else ctx.pc = local_pc;
        return;
    }
    }
L_08B43620:
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(-16));
    goto L_08B43624;
L_08B43624:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(0), ctx.gpr[16]);
    goto L_08B43628;
L_08B43628:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(4), ctx.gpr[31]);
    goto L_08B4362C;
L_08B4362C:
    ctx.set_gpr(31, 0x08B43634u);
    ctx.set_gpr(16, ctx.gpr[4] | 0u);
    goto L_08B43674;
L_08B43634:
    ctx.set_gpr(2, ctx.gpr[16] | 0u);
    goto L_08B43638;
L_08B43638:
    ctx.set_gpr(16, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(0)));
    goto L_08B4363C;
L_08B4363C:
    ctx.set_gpr(31, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(4)));
    goto L_08B43640;
L_08B43640:
    jump_target = ctx.gpr[31];
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(16));
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08B43648:
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(-16));
    goto L_08B4364C;
L_08B4364C:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(0), ctx.gpr[31]);
    goto L_08B43650;
L_08B43650:
    { const bool branch_taken = ctx.gpr[4] == 0u;
    ctx.set_gpr(5, ctx.gpr[5] & 1u);
      if (branch_taken) {
          goto L_08B43668;
      }
      goto L_08B43658;
    }
L_08B43658:
    { const bool branch_taken = ctx.gpr[5] == 0u;
    // nop
      if (branch_taken) {
          goto L_08B43668;
      }
      goto L_08B43660;
    }
L_08B43660:
    ctx.set_gpr(31, 0x08B43668u);
    // nop
    ctx.pc = 0x08992F04u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B43668u) goto L_08B43668;
    return;
L_08B43668:
    ctx.set_gpr(31, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(0)));
    goto L_08B4366C;
L_08B4366C:
    jump_target = ctx.gpr[31];
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(16));
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08B43674:
    rt.memory().aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(0), 0u);
    goto L_08B43678;
L_08B43678:
    jump_target = ctx.gpr[31];
    rt.memory().aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(4), 0u);
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08B43680:
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(-16));
    goto L_08B43684;
L_08B43684:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(0), ctx.gpr[16]);
    goto L_08B43688;
L_08B43688:
    ctx.set_gpr(16, ctx.gpr[4] | 0u);
    goto L_08B4368C;
L_08B4368C:
    ctx.set_gpr(4, 2u << 16u);
    goto L_08B43690;
L_08B43690:
    ctx.set_gpr(6, ctx.gpr[4] + static_cast<std::uint32_t>(4));
    goto L_08B43694;
L_08B43694:
    rt.memory().aot_store32(ctx.gpr[16] + static_cast<std::uint32_t>(0), ctx.gpr[5]);
    goto L_08B43698;
L_08B43698:
    ctx.set_gpr(4, ctx.gpr[5] | 0u);
    goto L_08B4369C;
L_08B4369C:
    ctx.set_gpr(5, ctx.gpr[6] | 0u);
    goto L_08B436A0;
L_08B436A0:
    ctx.set_gpr(8, 0u | 1u);
    goto L_08B436A4;
L_08B436A4:
    ctx.set_gpr(6, 0u | 0u);
    goto L_08B436A8;
L_08B436A8:
    ctx.set_gpr(7, 0u | 0u);
    goto L_08B436AC;
L_08B436AC:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(4), ctx.gpr[31]);
    goto L_08B436B0;
L_08B436B0:
    ctx.set_gpr(31, 0x08B436B8u);
    ctx.set_gpr(9, 0u | 0u);
    ctx.pc = 0x0885C6CCu;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B436B8u) goto L_08B436B8;
    return;
L_08B436B8:
    rt.memory().aot_store32(ctx.gpr[16] + static_cast<std::uint32_t>(4), ctx.gpr[2]);
    goto L_08B436BC;
L_08B436BC:
    rt.memory().aot_store32(ctx.gpr[2] + static_cast<std::uint32_t>(0), 0u);
    goto L_08B436C0;
L_08B436C0:
    ctx.set_gpr(31, 0x08B436C8u);
    ctx.set_gpr(4, ctx.gpr[16] | 0u);
    goto L_08B436FC;
L_08B436C8:
    ctx.set_gpr(16, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(0)));
    goto L_08B436CC;
L_08B436CC:
    ctx.set_gpr(31, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(4)));
    goto L_08B436D0;
L_08B436D0:
    jump_target = ctx.gpr[31];
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(16));
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08B436D8:
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(-16));
    goto L_08B436DC;
L_08B436DC:
    ctx.set_gpr(5, rt.memory().aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(4)));
    goto L_08B436E0;
L_08B436E0:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(0)));
    goto L_08B436E4;
L_08B436E4:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(0), ctx.gpr[31]);
    goto L_08B436E8;
L_08B436E8:
    ctx.set_gpr(31, 0x08B436F0u);
    ctx.set_gpr(6, 0u | 0u);
    ctx.pc = 0x0885C538u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B436F0u) goto L_08B436F0;
    return;
L_08B436F0:
    ctx.set_gpr(31, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(0)));
    goto L_08B436F4;
L_08B436F4:
    jump_target = ctx.gpr[31];
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(16));
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08B436FC:
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(-32));
    goto L_08B43700;
L_08B43700:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(8), ctx.gpr[4]);
    goto L_08B43704;
L_08B43704:
    ctx.set_gpr(4, 2228u << 16u);
    goto L_08B43708;
L_08B43708:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(12), ctx.gpr[16]);
    goto L_08B4370C;
L_08B4370C:
    ctx.set_gpr(16, ctx.gpr[4] + static_cast<std::uint32_t>(14488));
    goto L_08B43710;
L_08B43710:
    ctx.set_gpr(4, ctx.gpr[16] | 0u);
    goto L_08B43714;
L_08B43714:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(16), ctx.gpr[17]);
    goto L_08B43718;
L_08B43718:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(20), ctx.gpr[31]);
    goto L_08B4371C;
L_08B4371C:
    ctx.set_gpr(31, 0x08B43724u);
    ctx.set_gpr(5, 0u | 0u);
    ctx.pc = 0x088FE7C8u;
    (void)rt.invoke_chained_call(ctx, &aot_mem);
    return;
}

void sub_08B43620(Runtime &rt, AllegrexContext &ctx) {
    auto aot_mem = rt.memory().aot_fast_view();
    sub_08B43620_entry(rt, ctx, 0u, aot_mem);
}

static const std::uint16_t kEntryIds_sub_08B44750[64] = {
    1, 2, 3, 4, 5, 0, 6, 7, 8, 0, 9, 0, 10, 0, 11, 12, 0, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27,
    28, 29, 30, 31, 0, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 0, 42, 0, 43, 0, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55,
};
void sub_08B44750_entry(Runtime &rt, AllegrexContext &ctx, std::uint16_t direct_entry_id, GuestMemory::AotFastView &aot_mem) {
    std::uint32_t jump_target = 0u;
    std::uint32_t local_transfers = 0u;
    std::uint32_t local_pc = ctx.pc;
    std::uint32_t entry_id = direct_entry_id;
LOCAL_DISPATCH:
    {
    if (entry_id == 0u) {
        const std::uint32_t entry_delta = local_pc - 0x08B44750u;
        entry_id = (entry_delta < 256u && (entry_delta & 3u) == 0u) ? kEntryIds_sub_08B44750[entry_delta >> 2u] : 0u;
    }
    switch (entry_id) {
    case 1u: goto L_08B44750;
    case 2u: goto L_08B44754;
    case 3u: goto L_08B44758;
    case 4u: goto L_08B4475C;
    case 5u: goto L_08B44760;
    case 6u: goto L_08B44768;
    case 7u: goto L_08B4476C;
    case 8u: goto L_08B44770;
    case 9u: goto L_08B44778;
    case 10u: goto L_08B44780;
    case 11u: goto L_08B44788;
    case 12u: goto L_08B4478C;
    case 13u: goto L_08B44794;
    case 14u: goto L_08B44798;
    case 15u: goto L_08B4479C;
    case 16u: goto L_08B447A0;
    case 17u: goto L_08B447A4;
    case 18u: goto L_08B447A8;
    case 19u: goto L_08B447AC;
    case 20u: goto L_08B447B0;
    case 21u: goto L_08B447B4;
    case 22u: goto L_08B447B8;
    case 23u: goto L_08B447BC;
    case 24u: goto L_08B447C0;
    case 25u: goto L_08B447C4;
    case 26u: goto L_08B447C8;
    case 27u: goto L_08B447CC;
    case 28u: goto L_08B447D0;
    case 29u: goto L_08B447D4;
    case 30u: goto L_08B447D8;
    case 31u: goto L_08B447DC;
    case 32u: goto L_08B447E4;
    case 33u: goto L_08B447E8;
    case 34u: goto L_08B447EC;
    case 35u: goto L_08B447F0;
    case 36u: goto L_08B447F4;
    case 37u: goto L_08B447F8;
    case 38u: goto L_08B447FC;
    case 39u: goto L_08B44800;
    case 40u: goto L_08B44804;
    case 41u: goto L_08B44808;
    case 42u: goto L_08B44810;
    case 43u: goto L_08B44818;
    case 44u: goto L_08B44820;
    case 45u: goto L_08B44824;
    case 46u: goto L_08B44828;
    case 47u: goto L_08B4482C;
    case 48u: goto L_08B44830;
    case 49u: goto L_08B44834;
    case 50u: goto L_08B44838;
    case 51u: goto L_08B4483C;
    case 52u: goto L_08B44840;
    case 53u: goto L_08B44844;
    case 54u: goto L_08B44848;
    case 55u: goto L_08B4484C;
    default:
        if (local_transfers == 0u) rt.unsupported(ctx.pc, 0u, "invalid internal function entry");
        else ctx.pc = local_pc;
        return;
    }
    }
L_08B44750:
    rt.memory().aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(8), 0u);
    goto L_08B44754;
L_08B44754:
    rt.memory().aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(4), 0u);
    goto L_08B44758;
L_08B44758:
    rt.memory().aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(16), 0u);
    goto L_08B4475C;
L_08B4475C:
    rt.memory().aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(12), 0u);
    goto L_08B44760;
L_08B44760:
    jump_target = ctx.gpr[31];
    ctx.set_gpr(2, ctx.gpr[4] | 0u);
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08B44768:
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(-16));
    goto L_08B4476C;
L_08B4476C:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(0), ctx.gpr[31]);
    goto L_08B44770;
L_08B44770:
    { const bool branch_taken = ctx.gpr[4] == 0u;
    ctx.set_gpr(5, ctx.gpr[5] & 1u);
      if (branch_taken) {
          goto L_08B44788;
      }
      goto L_08B44778;
    }
L_08B44778:
    { const bool branch_taken = ctx.gpr[5] == 0u;
    // nop
      if (branch_taken) {
          goto L_08B44788;
      }
      goto L_08B44780;
    }
L_08B44780:
    ctx.set_gpr(31, 0x08B44788u);
    // nop
    ctx.pc = 0x08992F04u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B44788u) goto L_08B44788;
    return;
L_08B44788:
    ctx.set_gpr(31, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(0)));
    goto L_08B4478C;
L_08B4478C:
    jump_target = ctx.gpr[31];
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(16));
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08B44794:
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(-480));
    goto L_08B44798;
L_08B44798:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(432), ctx.gpr[16]);
    goto L_08B4479C;
L_08B4479C:
    ctx.set_gpr(16, ctx.gpr[4] | 0u);
    goto L_08B447A0;
L_08B447A0:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[16] + static_cast<std::uint32_t>(8)));
    goto L_08B447A4;
L_08B447A4:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(416), std::bit_cast<std::uint32_t>(ctx.fpr[20]));
    goto L_08B447A8;
L_08B447A8:
    ctx.set_gpr(5, ctx.gpr[4] & 1u);
    goto L_08B447AC;
L_08B447AC:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(420), std::bit_cast<std::uint32_t>(ctx.fpr[22]));
    goto L_08B447B0;
L_08B447B0:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(424), std::bit_cast<std::uint32_t>(ctx.fpr[24]));
    goto L_08B447B4;
L_08B447B4:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(428), std::bit_cast<std::uint32_t>(ctx.fpr[26]));
    goto L_08B447B8;
L_08B447B8:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(436), ctx.gpr[17]);
    goto L_08B447BC;
L_08B447BC:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(440), ctx.gpr[18]);
    goto L_08B447C0;
L_08B447C0:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(444), ctx.gpr[19]);
    goto L_08B447C4;
L_08B447C4:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(448), ctx.gpr[20]);
    goto L_08B447C8;
L_08B447C8:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(452), ctx.gpr[21]);
    goto L_08B447CC;
L_08B447CC:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(456), ctx.gpr[22]);
    goto L_08B447D0;
L_08B447D0:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(460), ctx.gpr[23]);
    goto L_08B447D4;
L_08B447D4:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(464), ctx.gpr[30]);
    goto L_08B447D8;
L_08B447D8:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(468), ctx.gpr[31]);
    goto L_08B447DC;
L_08B447DC:
    { const bool branch_taken = ctx.gpr[5] == 0u;
    // nop
      if (branch_taken) {
          goto L_08B44818;
      }
      goto L_08B447E4;
    }
L_08B447E4:
    ctx.set_gpr(6, 16128u << 16u);
    goto L_08B447E8;
L_08B447E8:
    ctx.fpr[20] = std::bit_cast<float>(0u);
    goto L_08B447EC;
L_08B447EC:
    ctx.set_gpr(5, ctx.gpr[4] & 2u);
    goto L_08B447F0;
L_08B447F0:
    ctx.fpr[22] = std::bit_cast<float>(ctx.gpr[6]);
    goto L_08B447F4;
L_08B447F4:
    ctx.set_gpr(5, 0u < ctx.gpr[5] ? 1u : 0u);
    goto L_08B447F8;
L_08B447F8:
    ctx.set_gpr(6, 16256u << 16u);
    goto L_08B447FC;
L_08B447FC:
    ctx.set_gpr(17, 0u + static_cast<std::uint32_t>(-1));
    goto L_08B44800;
L_08B44800:
    ctx.fpr[24] = std::bit_cast<float>(ctx.gpr[6]);
    goto L_08B44804;
L_08B44804:
    ctx.set_gpr(5, ctx.gpr[5] & 255u);
    goto L_08B44808;
L_08B44808:
    { const bool branch_taken = ctx.gpr[5] != 0u;
    ctx.set_gpr(18, 2228u << 16u);
      if (branch_taken) {
          goto L_08B44820;
      }
      goto L_08B44810;
    }
L_08B44810:
    { const bool branch_taken = 0u == 0u;
    // nop
      if (branch_taken) {
          ctx.pc = 0x08B44954u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
      }
      goto L_08B44818;
    }
L_08B44818:
    { const bool branch_taken = 0u == 0u;
    // nop
      if (branch_taken) {
          ctx.pc = 0x08B44E30u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
      }
      goto L_08B44820;
    }
L_08B44820:
    ctx.set_gpr(5, 2228u << 16u);
    goto L_08B44824;
L_08B44824:
    ctx.fpr[13] = std::bit_cast<float>(rt.memory().aot_load32(ctx.gpr[5] + static_cast<std::uint32_t>(20212)));
    goto L_08B44828;
L_08B44828:
    ctx.set_gpr(6, 16384u << 16u);
    goto L_08B4482C;
L_08B4482C:
    ctx.fpr[12] = std::bit_cast<float>(ctx.gpr[6]);
    goto L_08B44830;
L_08B44830:
    ctx.fpr[14] = std::bit_cast<float>(rt.memory().aot_load32(ctx.gpr[16] + static_cast<std::uint32_t>(48)));
    goto L_08B44834;
L_08B44834:
    { const float fs = ctx.fpr[13]; const float ft = ctx.fpr[12]; if ((std::isinf(fs) && ft == 0.0f) || (std::isinf(ft) && fs == 0.0f)) ctx.set_fpr_bits(13, 0x7FC00000u); else ctx.fpr[13] = fs * ft; }
    goto L_08B44838;
L_08B44838:
    ctx.fpr[15] = std::bit_cast<float>(rt.memory().aot_load32(ctx.gpr[16] + static_cast<std::uint32_t>(44)));
    goto L_08B4483C;
L_08B4483C:
    ctx.set_gpr(17, 256u << 16u);
    goto L_08B44840;
L_08B44840:
    ctx.fpr[16] = ctx.fpr[13] + ctx.fpr[14];
    goto L_08B44844;
L_08B44844:
    ctx.set_fpu_condition((ctx.fpr[16] < ctx.fpr[15]));
    goto L_08B44848;
L_08B44848:
    // nop
    goto L_08B4484C;
L_08B4484C:
    { const bool branch_taken = !ctx.fpu_condition();
    ctx.set_gpr(17, ctx.gpr[17] + static_cast<std::uint32_t>(-1));
      if (branch_taken) {
          ctx.pc = 0x08B44870u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
      }
      ctx.pc = 0x08B44854u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
    }
}

void sub_08B44750(Runtime &rt, AllegrexContext &ctx) {
    auto aot_mem = rt.memory().aot_fast_view();
    sub_08B44750_entry(rt, ctx, 0u, aot_mem);
}

static const std::uint16_t kEntryIds_sub_08B45444[64] = {
    1, 2, 3, 0, 4, 5, 6, 0, 7, 0, 8, 0, 9, 10, 0, 11, 12, 13, 14, 15, 16, 17, 18, 0, 19, 0, 20, 21, 22, 23, 24, 25,
    26, 0, 27, 28, 29, 30, 31, 32, 33, 34, 35, 0, 36, 37, 38, 39, 40, 41, 42, 0, 43, 0, 44, 45, 46, 47, 48, 49, 50, 0, 51, 52,
};
void sub_08B45444_entry(Runtime &rt, AllegrexContext &ctx, std::uint16_t direct_entry_id, GuestMemory::AotFastView &aot_mem) {
    std::uint32_t jump_target = 0u;
    std::uint32_t local_transfers = 0u;
    std::uint32_t local_pc = ctx.pc;
    std::uint32_t entry_id = direct_entry_id;
LOCAL_DISPATCH:
    {
    if (entry_id == 0u) {
        const std::uint32_t entry_delta = local_pc - 0x08B45444u;
        entry_id = (entry_delta < 256u && (entry_delta & 3u) == 0u) ? kEntryIds_sub_08B45444[entry_delta >> 2u] : 0u;
    }
    switch (entry_id) {
    case 1u: goto L_08B45444;
    case 2u: goto L_08B45448;
    case 3u: goto L_08B4544C;
    case 4u: goto L_08B45454;
    case 5u: goto L_08B45458;
    case 6u: goto L_08B4545C;
    case 7u: goto L_08B45464;
    case 8u: goto L_08B4546C;
    case 9u: goto L_08B45474;
    case 10u: goto L_08B45478;
    case 11u: goto L_08B45480;
    case 12u: goto L_08B45484;
    case 13u: goto L_08B45488;
    case 14u: goto L_08B4548C;
    case 15u: goto L_08B45490;
    case 16u: goto L_08B45494;
    case 17u: goto L_08B45498;
    case 18u: goto L_08B4549C;
    case 19u: goto L_08B454A4;
    case 20u: goto L_08B454AC;
    case 21u: goto L_08B454B0;
    case 22u: goto L_08B454B4;
    case 23u: goto L_08B454B8;
    case 24u: goto L_08B454BC;
    case 25u: goto L_08B454C0;
    case 26u: goto L_08B454C4;
    case 27u: goto L_08B454CC;
    case 28u: goto L_08B454D0;
    case 29u: goto L_08B454D4;
    case 30u: goto L_08B454D8;
    case 31u: goto L_08B454DC;
    case 32u: goto L_08B454E0;
    case 33u: goto L_08B454E4;
    case 34u: goto L_08B454E8;
    case 35u: goto L_08B454EC;
    case 36u: goto L_08B454F4;
    case 37u: goto L_08B454F8;
    case 38u: goto L_08B454FC;
    case 39u: goto L_08B45500;
    case 40u: goto L_08B45504;
    case 41u: goto L_08B45508;
    case 42u: goto L_08B4550C;
    case 43u: goto L_08B45514;
    case 44u: goto L_08B4551C;
    case 45u: goto L_08B45520;
    case 46u: goto L_08B45524;
    case 47u: goto L_08B45528;
    case 48u: goto L_08B4552C;
    case 49u: goto L_08B45530;
    case 50u: goto L_08B45534;
    case 51u: goto L_08B4553C;
    case 52u: goto L_08B45540;
    default:
        if (local_transfers == 0u) rt.unsupported(ctx.pc, 0u, "invalid internal function entry");
        else ctx.pc = local_pc;
        return;
    }
    }
L_08B45444:
    rt.memory().aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(0), 0u);
    goto L_08B45448;
L_08B45448:
    rt.memory().aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(4), 0u);
    goto L_08B4544C;
L_08B4544C:
    jump_target = ctx.gpr[31];
    ctx.set_gpr(2, ctx.gpr[4] | 0u);
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08B45454:
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(-16));
    goto L_08B45458;
L_08B45458:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(0), ctx.gpr[31]);
    goto L_08B4545C;
L_08B4545C:
    { const bool branch_taken = ctx.gpr[4] == 0u;
    ctx.set_gpr(5, ctx.gpr[5] & 1u);
      if (branch_taken) {
          goto L_08B45474;
      }
      goto L_08B45464;
    }
L_08B45464:
    { const bool branch_taken = ctx.gpr[5] == 0u;
    // nop
      if (branch_taken) {
          goto L_08B45474;
      }
      goto L_08B4546C;
    }
L_08B4546C:
    ctx.set_gpr(31, 0x08B45474u);
    // nop
    ctx.pc = 0x08992F04u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B45474u) goto L_08B45474;
    return;
L_08B45474:
    ctx.set_gpr(31, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(0)));
    goto L_08B45478;
L_08B45478:
    jump_target = ctx.gpr[31];
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(16));
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08B45480:
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(-32));
    goto L_08B45484;
L_08B45484:
    ctx.set_gpr(6, rt.memory().aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(4)));
    goto L_08B45488;
L_08B45488:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(0), ctx.gpr[16]);
    goto L_08B4548C;
L_08B4548C:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(4), ctx.gpr[17]);
    goto L_08B45490;
L_08B45490:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(8), ctx.gpr[18]);
    goto L_08B45494;
L_08B45494:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(12), ctx.gpr[19]);
    goto L_08B45498;
L_08B45498:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(16), ctx.gpr[31]);
    goto L_08B4549C;
L_08B4549C:
    { const bool branch_taken = ctx.gpr[6] == 0u;
    ctx.set_gpr(16, ctx.gpr[4] | 0u);
      if (branch_taken) {
          goto L_08B454AC;
      }
      goto L_08B454A4;
    }
L_08B454A4:
    { const bool branch_taken = 0u == 0u;
    // nop
      if (branch_taken) {
          goto L_08B4553C;
      }
      goto L_08B454AC;
    }
L_08B454AC:
    rt.memory().aot_store32(ctx.gpr[16] + static_cast<std::uint32_t>(0), ctx.gpr[5]);
    goto L_08B454B0;
L_08B454B0:
    ctx.set_gpr(4, ctx.gpr[5] | 0u);
    goto L_08B454B4;
L_08B454B4:
    ctx.set_gpr(8, 0u | 1u);
    goto L_08B454B8;
L_08B454B8:
    ctx.set_gpr(5, 0u | 12u);
    goto L_08B454BC;
L_08B454BC:
    ctx.set_gpr(6, 0u | 0u);
    goto L_08B454C0;
L_08B454C0:
    ctx.set_gpr(7, 0u | 0u);
    goto L_08B454C4;
L_08B454C4:
    ctx.set_gpr(31, 0x08B454CCu);
    ctx.set_gpr(9, 0u | 0u);
    ctx.pc = 0x0885C6CCu;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B454CCu) goto L_08B454CC;
    return;
L_08B454CC:
    rt.memory().aot_store32(ctx.gpr[16] + static_cast<std::uint32_t>(4), ctx.gpr[2]);
    goto L_08B454D0;
L_08B454D0:
    ctx.set_gpr(19, 0u | 0u);
    goto L_08B454D4;
L_08B454D4:
    ctx.set_gpr(18, 0u | 0u);
    goto L_08B454D8;
L_08B454D8:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[16] + static_cast<std::uint32_t>(0)));
    goto L_08B454DC;
L_08B454DC:
    ctx.set_gpr(8, 0u | 1u);
    goto L_08B454E0;
L_08B454E0:
    ctx.set_gpr(5, 0u | 12u);
    goto L_08B454E4;
L_08B454E4:
    ctx.set_gpr(6, 0u | 0u);
    goto L_08B454E8;
L_08B454E8:
    ctx.set_gpr(7, 0u | 0u);
    goto L_08B454EC;
L_08B454EC:
    ctx.set_gpr(31, 0x08B454F4u);
    ctx.set_gpr(9, 0u | 0u);
    ctx.pc = 0x0885C6CCu;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B454F4u) goto L_08B454F4;
    return;
L_08B454F4:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[16] + static_cast<std::uint32_t>(4)));
    goto L_08B454F8;
L_08B454F8:
    ctx.set_gpr(4, ctx.gpr[4] + ctx.gpr[18]);
    goto L_08B454FC;
L_08B454FC:
    rt.memory().aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(0), ctx.gpr[2]);
    goto L_08B45500;
L_08B45500:
    ctx.set_gpr(5, rt.memory().aot_load32(ctx.gpr[16] + static_cast<std::uint32_t>(4)));
    goto L_08B45504;
L_08B45504:
    ctx.set_gpr(5, ctx.gpr[5] + ctx.gpr[18]);
    goto L_08B45508;
L_08B45508:
    ctx.set_gpr(17, rt.memory().aot_load32(ctx.gpr[5] + static_cast<std::uint32_t>(0)));
    goto L_08B4550C;
L_08B4550C:
    { const bool branch_taken = ctx.gpr[17] == 0u;
    ctx.set_gpr(4, 0u | 0u);
      if (branch_taken) {
          goto L_08B45520;
      }
      goto L_08B45514;
    }
L_08B45514:
    ctx.set_gpr(31, 0x08B4551Cu);
    ctx.set_gpr(4, ctx.gpr[17] | 0u);
    ctx.pc = 0x08B45260u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B4551Cu) goto L_08B4551C;
    return;
L_08B4551C:
    ctx.set_gpr(4, ctx.gpr[17] | 0u);
    goto L_08B45520;
L_08B45520:
    ctx.set_gpr(5, rt.memory().aot_load32(ctx.gpr[16] + static_cast<std::uint32_t>(4)));
    goto L_08B45524;
L_08B45524:
    ctx.set_gpr(19, ctx.gpr[19] + static_cast<std::uint32_t>(1));
    goto L_08B45528;
L_08B45528:
    ctx.set_gpr(5, ctx.gpr[5] + ctx.gpr[18]);
    goto L_08B4552C;
L_08B4552C:
    rt.memory().aot_store32(ctx.gpr[5] + static_cast<std::uint32_t>(0), ctx.gpr[4]);
    goto L_08B45530;
L_08B45530:
    ctx.set_gpr(4, static_cast<std::int32_t>(ctx.gpr[19]) < 3 ? 1u : 0u);
    goto L_08B45534;
L_08B45534:
    { const bool branch_taken = ctx.gpr[4] != 0u;
    ctx.set_gpr(18, ctx.gpr[18] + static_cast<std::uint32_t>(4));
      if (branch_taken) {
          goto L_08B454D8;
      }
      goto L_08B4553C;
    }
L_08B4553C:
    ctx.set_gpr(16, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(0)));
    goto L_08B45540;
L_08B45540:
    ctx.set_gpr(17, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(4)));
    ctx.pc = 0x08B45544u; return;
}

void sub_08B45444(Runtime &rt, AllegrexContext &ctx) {
    auto aot_mem = rt.memory().aot_fast_view();
    sub_08B45444_entry(rt, ctx, 0u, aot_mem);
}

static const std::uint16_t kEntryIds_sub_08B53B88[64] = {
    1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 10, 11, 12, 13, 14, 15, 16, 17, 0, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30,
    0, 31, 32, 33, 0, 34, 35, 36, 37, 38, 39, 40, 0, 41, 42, 43, 44, 45, 46, 47, 0, 48, 49, 50, 51, 52, 53, 54, 55, 0, 56, 57,
};
void sub_08B53B88_entry(Runtime &rt, AllegrexContext &ctx, std::uint16_t direct_entry_id, GuestMemory::AotFastView &aot_mem) {
    std::uint32_t jump_target = 0u;
    std::uint32_t local_transfers = 0u;
    std::uint32_t local_pc = ctx.pc;
    std::uint32_t entry_id = direct_entry_id;
LOCAL_DISPATCH:
    {
    if (entry_id == 0u) {
        const std::uint32_t entry_delta = local_pc - 0x08B53B88u;
        entry_id = (entry_delta < 256u && (entry_delta & 3u) == 0u) ? kEntryIds_sub_08B53B88[entry_delta >> 2u] : 0u;
    }
    switch (entry_id) {
    case 1u: goto L_08B53B88;
    case 2u: goto L_08B53B8C;
    case 3u: goto L_08B53B90;
    case 4u: goto L_08B53B94;
    case 5u: goto L_08B53B98;
    case 6u: goto L_08B53B9C;
    case 7u: goto L_08B53BA0;
    case 8u: goto L_08B53BA4;
    case 9u: goto L_08B53BA8;
    case 10u: goto L_08B53BB0;
    case 11u: goto L_08B53BB4;
    case 12u: goto L_08B53BB8;
    case 13u: goto L_08B53BBC;
    case 14u: goto L_08B53BC0;
    case 15u: goto L_08B53BC4;
    case 16u: goto L_08B53BC8;
    case 17u: goto L_08B53BCC;
    case 18u: goto L_08B53BD4;
    case 19u: goto L_08B53BD8;
    case 20u: goto L_08B53BDC;
    case 21u: goto L_08B53BE0;
    case 22u: goto L_08B53BE4;
    case 23u: goto L_08B53BE8;
    case 24u: goto L_08B53BEC;
    case 25u: goto L_08B53BF0;
    case 26u: goto L_08B53BF4;
    case 27u: goto L_08B53BF8;
    case 28u: goto L_08B53BFC;
    case 29u: goto L_08B53C00;
    case 30u: goto L_08B53C04;
    case 31u: goto L_08B53C0C;
    case 32u: goto L_08B53C10;
    case 33u: goto L_08B53C14;
    case 34u: goto L_08B53C1C;
    case 35u: goto L_08B53C20;
    case 36u: goto L_08B53C24;
    case 37u: goto L_08B53C28;
    case 38u: goto L_08B53C2C;
    case 39u: goto L_08B53C30;
    case 40u: goto L_08B53C34;
    case 41u: goto L_08B53C3C;
    case 42u: goto L_08B53C40;
    case 43u: goto L_08B53C44;
    case 44u: goto L_08B53C48;
    case 45u: goto L_08B53C4C;
    case 46u: goto L_08B53C50;
    case 47u: goto L_08B53C54;
    case 48u: goto L_08B53C5C;
    case 49u: goto L_08B53C60;
    case 50u: goto L_08B53C64;
    case 51u: goto L_08B53C68;
    case 52u: goto L_08B53C6C;
    case 53u: goto L_08B53C70;
    case 54u: goto L_08B53C74;
    case 55u: goto L_08B53C78;
    case 56u: goto L_08B53C80;
    case 57u: goto L_08B53C84;
    default:
        if (local_transfers == 0u) rt.unsupported(ctx.pc, 0u, "invalid internal function entry");
        else ctx.pc = local_pc;
        return;
    }
    }
L_08B53B88:
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(-16));
    goto L_08B53B8C;
L_08B53B8C:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(0), ctx.gpr[16]);
    goto L_08B53B90;
L_08B53B90:
    ctx.set_gpr(16, ctx.gpr[4] | 0u);
    goto L_08B53B94;
L_08B53B94:
    ctx.set_gpr(6, 1u << 16u);
    goto L_08B53B98;
L_08B53B98:
    ctx.set_gpr(4, ctx.gpr[16] + static_cast<std::uint32_t>(256));
    goto L_08B53B9C;
L_08B53B9C:
    ctx.set_gpr(5, 0u | 1u);
    goto L_08B53BA0;
L_08B53BA0:
    ctx.set_gpr(7, 0u | 84u);
    goto L_08B53BA4;
L_08B53BA4:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(4), ctx.gpr[31]);
    goto L_08B53BA8;
L_08B53BA8:
    ctx.set_gpr(31, 0x08B53BB0u);
    ctx.set_gpr(6, ctx.gpr[6] + static_cast<std::uint32_t>(4492));
    ctx.pc = 0x08864FF0u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B53BB0u) goto L_08B53BB0;
    return;
L_08B53BB0:
    rt.memory().aot_store32(ctx.gpr[16] + static_cast<std::uint32_t>(308), 0u);
    goto L_08B53BB4;
L_08B53BB4:
    rt.memory().aot_store32(ctx.gpr[16] + static_cast<std::uint32_t>(312), 0u);
    goto L_08B53BB8;
L_08B53BB8:
    rt.memory().aot_store32(ctx.gpr[16] + static_cast<std::uint32_t>(316), 0u);
    goto L_08B53BBC;
L_08B53BBC:
    rt.memory().aot_store8(ctx.gpr[16] + static_cast<std::uint32_t>(320), static_cast<std::uint8_t>(0u));
    goto L_08B53BC0;
L_08B53BC0:
    ctx.set_gpr(2, ctx.gpr[16] | 0u);
    goto L_08B53BC4;
L_08B53BC4:
    ctx.set_gpr(16, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(0)));
    goto L_08B53BC8;
L_08B53BC8:
    ctx.set_gpr(31, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(4)));
    goto L_08B53BCC;
L_08B53BCC:
    jump_target = ctx.gpr[31];
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(16));
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08B53BD4:
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(-32));
    goto L_08B53BD8;
L_08B53BD8:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(4), ctx.gpr[16]);
    goto L_08B53BDC;
L_08B53BDC:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(8), ctx.gpr[17]);
    goto L_08B53BE0;
L_08B53BE0:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(12), ctx.gpr[18]);
    goto L_08B53BE4;
L_08B53BE4:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(16), ctx.gpr[31]);
    goto L_08B53BE8;
L_08B53BE8:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(0), ctx.gpr[4]);
    goto L_08B53BEC;
L_08B53BEC:
    ctx.set_gpr(7, 2229u << 16u);
    goto L_08B53BF0;
L_08B53BF0:
    ctx.set_gpr(8, 2229u << 16u);
    goto L_08B53BF4;
L_08B53BF4:
    ctx.set_gpr(4, ctx.gpr[4] + static_cast<std::uint32_t>(256));
    goto L_08B53BF8;
L_08B53BF8:
    ctx.set_gpr(5, 0u | 0u);
    goto L_08B53BFC;
L_08B53BFC:
    ctx.set_gpr(6, 0u | 0u);
    goto L_08B53C00;
L_08B53C00:
    ctx.set_gpr(7, ctx.gpr[7] + static_cast<std::uint32_t>(16356));
    goto L_08B53C04;
L_08B53C04:
    ctx.set_gpr(31, 0x08B53C0Cu);
    ctx.set_gpr(8, ctx.gpr[8] + static_cast<std::uint32_t>(16424));
    ctx.pc = 0x08865088u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B53C0Cu) goto L_08B53C0C;
    return;
L_08B53C0C:
    ctx.set_gpr(4, 39u << 16u);
    goto L_08B53C10;
L_08B53C10:
    ctx.set_gpr(16, ctx.gpr[4] + static_cast<std::uint32_t>(2048));
    goto L_08B53C14;
L_08B53C14:
    ctx.set_gpr(31, 0x08B53C1Cu);
    ctx.set_gpr(4, ctx.gpr[16] | 0u);
    ctx.pc = 0x0888204Cu;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B53C1Cu) goto L_08B53C1C;
    return;
L_08B53C1C:
    ctx.set_gpr(5, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(0)));
    goto L_08B53C20;
L_08B53C20:
    ctx.set_gpr(6, 2229u << 16u);
    goto L_08B53C24;
L_08B53C24:
    rt.memory().aot_store32(ctx.gpr[5] + static_cast<std::uint32_t>(308), ctx.gpr[2]);
    goto L_08B53C28;
L_08B53C28:
    ctx.set_gpr(4, ctx.gpr[2] | 0u);
    goto L_08B53C2C;
L_08B53C2C:
    ctx.set_gpr(5, ctx.gpr[16] | 0u);
    goto L_08B53C30;
L_08B53C30:
    ctx.set_gpr(7, 0u | 4u);
    goto L_08B53C34;
L_08B53C34:
    ctx.set_gpr(31, 0x08B53C3Cu);
    ctx.set_gpr(6, ctx.gpr[6] + static_cast<std::uint32_t>(16432));
    ctx.pc = 0x0885C40Cu;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B53C3Cu) goto L_08B53C3C;
    return;
L_08B53C3C:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(0)));
    goto L_08B53C40;
L_08B53C40:
    ctx.set_gpr(5, 2229u << 16u);
    goto L_08B53C44;
L_08B53C44:
    rt.memory().aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(312), ctx.gpr[2]);
    goto L_08B53C48;
L_08B53C48:
    ctx.set_gpr(16, ctx.gpr[5] + static_cast<std::uint32_t>(16444));
    goto L_08B53C4C;
L_08B53C4C:
    ctx.set_gpr(17, 0u | 1u);
    goto L_08B53C50;
L_08B53C50:
    ctx.set_gpr(4, ctx.gpr[16] | 0u);
    goto L_08B53C54;
L_08B53C54:
    ctx.set_gpr(31, 0x08B53C5Cu);
    ctx.set_gpr(5, 0u | 1u);
    ctx.pc = 0x08862C40u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B53C5Cu) goto L_08B53C5C;
    return;
L_08B53C5C:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(0)));
    goto L_08B53C60;
L_08B53C60:
    ctx.set_gpr(18, ctx.gpr[2] | 0u);
    goto L_08B53C64;
L_08B53C64:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(312)));
    goto L_08B53C68;
L_08B53C68:
    ctx.set_gpr(8, 0u | 1u);
    goto L_08B53C6C;
L_08B53C6C:
    ctx.set_gpr(5, ctx.gpr[18] | 0u);
    goto L_08B53C70;
L_08B53C70:
    ctx.set_gpr(6, 0u | 0u);
    goto L_08B53C74;
L_08B53C74:
    ctx.set_gpr(7, 0u | 0u);
    goto L_08B53C78;
L_08B53C78:
    ctx.set_gpr(31, 0x08B53C80u);
    ctx.set_gpr(9, 0u | 0u);
    ctx.pc = 0x0885C6CCu;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B53C80u) goto L_08B53C80;
    return;
L_08B53C80:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(0)));
    goto L_08B53C84;
L_08B53C84:
    ctx.set_gpr(5, ctx.gpr[2] | 0u);
    ctx.pc = 0x08B53C88u; return;
}

void sub_08B53B88(Runtime &rt, AllegrexContext &ctx) {
    auto aot_mem = rt.memory().aot_fast_view();
    sub_08B53B88_entry(rt, ctx, 0u, aot_mem);
}

static const std::uint16_t kEntryIds_sub_08B54060[64] = {
    1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 0, 28, 29, 30,
    31, 32, 33, 0, 34, 0, 35, 36, 0, 37, 38, 0, 39, 40, 41, 42, 0, 43, 44, 45, 46, 0, 47, 48, 49, 50, 0, 51, 0, 52, 53, 54,
};
void sub_08B54060_entry(Runtime &rt, AllegrexContext &ctx, std::uint16_t direct_entry_id, GuestMemory::AotFastView &aot_mem) {
    std::uint32_t jump_target = 0u;
    std::uint32_t local_transfers = 0u;
    std::uint32_t local_pc = ctx.pc;
    std::uint32_t entry_id = direct_entry_id;
LOCAL_DISPATCH:
    {
    if (entry_id == 0u) {
        const std::uint32_t entry_delta = local_pc - 0x08B54060u;
        entry_id = (entry_delta < 256u && (entry_delta & 3u) == 0u) ? kEntryIds_sub_08B54060[entry_delta >> 2u] : 0u;
    }
    switch (entry_id) {
    case 1u: goto L_08B54060;
    case 2u: goto L_08B54064;
    case 3u: goto L_08B54068;
    case 4u: goto L_08B5406C;
    case 5u: goto L_08B54070;
    case 6u: goto L_08B54074;
    case 7u: goto L_08B54078;
    case 8u: goto L_08B5407C;
    case 9u: goto L_08B54080;
    case 10u: goto L_08B54088;
    case 11u: goto L_08B5408C;
    case 12u: goto L_08B54090;
    case 13u: goto L_08B54094;
    case 14u: goto L_08B54098;
    case 15u: goto L_08B5409C;
    case 16u: goto L_08B540A0;
    case 17u: goto L_08B540A4;
    case 18u: goto L_08B540A8;
    case 19u: goto L_08B540AC;
    case 20u: goto L_08B540B0;
    case 21u: goto L_08B540B4;
    case 22u: goto L_08B540B8;
    case 23u: goto L_08B540BC;
    case 24u: goto L_08B540C0;
    case 25u: goto L_08B540C4;
    case 26u: goto L_08B540C8;
    case 27u: goto L_08B540CC;
    case 28u: goto L_08B540D4;
    case 29u: goto L_08B540D8;
    case 30u: goto L_08B540DC;
    case 31u: goto L_08B540E0;
    case 32u: goto L_08B540E4;
    case 33u: goto L_08B540E8;
    case 34u: goto L_08B540F0;
    case 35u: goto L_08B540F8;
    case 36u: goto L_08B540FC;
    case 37u: goto L_08B54104;
    case 38u: goto L_08B54108;
    case 39u: goto L_08B54110;
    case 40u: goto L_08B54114;
    case 41u: goto L_08B54118;
    case 42u: goto L_08B5411C;
    case 43u: goto L_08B54124;
    case 44u: goto L_08B54128;
    case 45u: goto L_08B5412C;
    case 46u: goto L_08B54130;
    case 47u: goto L_08B54138;
    case 48u: goto L_08B5413C;
    case 49u: goto L_08B54140;
    case 50u: goto L_08B54144;
    case 51u: goto L_08B5414C;
    case 52u: goto L_08B54154;
    case 53u: goto L_08B54158;
    case 54u: goto L_08B5415C;
    default:
        if (local_transfers == 0u) rt.unsupported(ctx.pc, 0u, "invalid internal function entry");
        else ctx.pc = local_pc;
        return;
    }
    }
L_08B54060:
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(-16));
    goto L_08B54064;
L_08B54064:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(0), ctx.gpr[16]);
    goto L_08B54068;
L_08B54068:
    ctx.set_gpr(16, ctx.gpr[4] | 0u);
    goto L_08B5406C;
L_08B5406C:
    ctx.set_gpr(6, 1u << 16u);
    goto L_08B54070;
L_08B54070:
    ctx.set_gpr(4, ctx.gpr[16] + static_cast<std::uint32_t>(256));
    goto L_08B54074;
L_08B54074:
    ctx.set_gpr(5, 0u | 1u);
    goto L_08B54078;
L_08B54078:
    ctx.set_gpr(7, 0u | 80u);
    goto L_08B5407C;
L_08B5407C:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(4), ctx.gpr[31]);
    goto L_08B54080;
L_08B54080:
    ctx.set_gpr(31, 0x08B54088u);
    ctx.set_gpr(6, ctx.gpr[6] + static_cast<std::uint32_t>(4486));
    ctx.pc = 0x08864FF0u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B54088u) goto L_08B54088;
    return;
L_08B54088:
    rt.memory().aot_store32(ctx.gpr[16] + static_cast<std::uint32_t>(308), 0u);
    goto L_08B5408C;
L_08B5408C:
    rt.memory().aot_store32(ctx.gpr[16] + static_cast<std::uint32_t>(312), 0u);
    goto L_08B54090;
L_08B54090:
    rt.memory().aot_store32(ctx.gpr[16] + static_cast<std::uint32_t>(316), 0u);
    goto L_08B54094;
L_08B54094:
    rt.memory().aot_store32(ctx.gpr[16] + static_cast<std::uint32_t>(320), 0u);
    goto L_08B54098;
L_08B54098:
    rt.memory().aot_store32(ctx.gpr[16] + static_cast<std::uint32_t>(324), 0u);
    goto L_08B5409C;
L_08B5409C:
    rt.memory().aot_store32(ctx.gpr[16] + static_cast<std::uint32_t>(328), 0u);
    goto L_08B540A0;
L_08B540A0:
    rt.memory().aot_store8(ctx.gpr[16] + static_cast<std::uint32_t>(332), static_cast<std::uint8_t>(0u));
    goto L_08B540A4;
L_08B540A4:
    rt.memory().aot_store8(ctx.gpr[16] + static_cast<std::uint32_t>(333), static_cast<std::uint8_t>(0u));
    goto L_08B540A8;
L_08B540A8:
    ctx.set_gpr(4, 2229u << 16u);
    goto L_08B540AC;
L_08B540AC:
    rt.memory().aot_store8(ctx.gpr[16] + static_cast<std::uint32_t>(334), static_cast<std::uint8_t>(0u));
    goto L_08B540B0;
L_08B540B0:
    ctx.set_gpr(4, ctx.gpr[4] + static_cast<std::uint32_t>(19328));
    goto L_08B540B4;
L_08B540B4:
    rt.memory().aot_store32(ctx.gpr[16] + static_cast<std::uint32_t>(336), ctx.gpr[4]);
    goto L_08B540B8;
L_08B540B8:
    rt.memory().aot_store32(ctx.gpr[16] + static_cast<std::uint32_t>(340), ctx.gpr[16]);
    goto L_08B540BC;
L_08B540BC:
    rt.memory().aot_store32(ctx.gpr[16] + static_cast<std::uint32_t>(344), 0u);
    goto L_08B540C0;
L_08B540C0:
    ctx.set_gpr(2, ctx.gpr[16] | 0u);
    goto L_08B540C4;
L_08B540C4:
    ctx.set_gpr(16, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(0)));
    goto L_08B540C8;
L_08B540C8:
    ctx.set_gpr(31, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(4)));
    goto L_08B540CC;
L_08B540CC:
    jump_target = ctx.gpr[31];
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(16));
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08B540D4:
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(-16));
    goto L_08B540D8;
L_08B540D8:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(0), ctx.gpr[16]);
    goto L_08B540DC;
L_08B540DC:
    ctx.set_gpr(16, ctx.gpr[4] | 0u);
    goto L_08B540E0;
L_08B540E0:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[16] + static_cast<std::uint32_t>(316)));
    goto L_08B540E4;
L_08B540E4:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(4), ctx.gpr[31]);
    goto L_08B540E8;
L_08B540E8:
    { const bool branch_taken = ctx.gpr[4] == 0u;
    // nop
      if (branch_taken) {
          goto L_08B54128;
      }
      goto L_08B540F0;
    }
L_08B540F0:
    ctx.set_gpr(31, 0x08B540F8u);
    // nop
    ctx.pc = 0x08B54CA4u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B540F8u) goto L_08B540F8;
    return;
L_08B540F8:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[16] + static_cast<std::uint32_t>(316)));
    goto L_08B540FC;
L_08B540FC:
    { const bool branch_taken = ctx.gpr[4] == 0u;
    // nop
      if (branch_taken) {
          goto L_08B54114;
      }
      goto L_08B54104;
    }
L_08B54104:
    ctx.set_gpr(4, ctx.gpr[4] + static_cast<std::uint32_t>(40));
    goto L_08B54108;
L_08B54108:
    ctx.set_gpr(31, 0x08B54110u);
    ctx.set_gpr(5, 0u | 2u);
    ctx.pc = 0x0887B1F4u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B54110u) goto L_08B54110;
    return;
L_08B54110:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[16] + static_cast<std::uint32_t>(316)));
    goto L_08B54114;
L_08B54114:
    ctx.set_gpr(5, ctx.gpr[4] | 0u);
    goto L_08B54118;
L_08B54118:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[16] + static_cast<std::uint32_t>(308)));
    goto L_08B5411C;
L_08B5411C:
    ctx.set_gpr(31, 0x08B54124u);
    ctx.set_gpr(6, 0u | 0u);
    ctx.pc = 0x0885C538u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B54124u) goto L_08B54124;
    return;
L_08B54124:
    rt.memory().aot_store32(ctx.gpr[16] + static_cast<std::uint32_t>(316), 0u);
    goto L_08B54128;
L_08B54128:
    ctx.set_gpr(4, 2206u << 16u);
    goto L_08B5412C;
L_08B5412C:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(-31900)));
    goto L_08B54130;
L_08B54130:
    { const bool branch_taken = ctx.gpr[4] == 0u;
    // nop
      if (branch_taken) {
          goto L_08B54144;
      }
      goto L_08B54138;
    }
L_08B54138:
    ctx.set_gpr(5, rt.memory().aot_load32(ctx.gpr[16] + static_cast<std::uint32_t>(344)));
    goto L_08B5413C;
L_08B5413C:
    rt.memory().aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(5728), ctx.gpr[5]);
    goto L_08B54140;
L_08B54140:
    rt.memory().aot_store32(ctx.gpr[16] + static_cast<std::uint32_t>(344), 0u);
    goto L_08B54144;
L_08B54144:
    ctx.set_gpr(31, 0x08B5414Cu);
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[16] + static_cast<std::uint32_t>(308)));
    ctx.pc = 0x0885C488u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B5414Cu) goto L_08B5414C;
    return;
L_08B5414C:
    ctx.set_gpr(31, 0x08B54154u);
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[16] + static_cast<std::uint32_t>(312)));
    ctx.pc = 0x0888208Cu;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B54154u) goto L_08B54154;
    return;
L_08B54154:
    rt.memory().aot_store32(ctx.gpr[16] + static_cast<std::uint32_t>(308), 0u);
    goto L_08B54158;
L_08B54158:
    rt.memory().aot_store32(ctx.gpr[16] + static_cast<std::uint32_t>(312), 0u);
    goto L_08B5415C;
L_08B5415C:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[16] + static_cast<std::uint32_t>(320)));
    ctx.pc = 0x08B54160u; return;
}

void sub_08B54060(Runtime &rt, AllegrexContext &ctx) {
    auto aot_mem = rt.memory().aot_fast_view();
    sub_08B54060_entry(rt, ctx, 0u, aot_mem);
}

static const std::uint16_t kEntryIds_sub_08B58B30[64] = {
    1, 0, 2, 3, 4, 0, 5, 0, 6, 0, 7, 8, 0, 9, 10, 0, 11, 0, 12, 13, 14, 15, 16, 0, 17, 18, 19, 20, 21, 22, 23, 24,
    25, 26, 27, 28, 29, 30, 31, 32, 33, 0, 34, 35, 36, 37, 38, 39, 40, 41, 0, 42, 0, 43, 44, 45, 46, 47, 48, 49, 0, 50, 51, 52,
};
void sub_08B58B30_entry(Runtime &rt, AllegrexContext &ctx, std::uint16_t direct_entry_id, GuestMemory::AotFastView &aot_mem) {
    std::uint32_t jump_target = 0u;
    std::uint32_t local_transfers = 0u;
    std::uint32_t local_pc = ctx.pc;
    std::uint32_t entry_id = direct_entry_id;
LOCAL_DISPATCH:
    {
    if (entry_id == 0u) {
        const std::uint32_t entry_delta = local_pc - 0x08B58B30u;
        entry_id = (entry_delta < 256u && (entry_delta & 3u) == 0u) ? kEntryIds_sub_08B58B30[entry_delta >> 2u] : 0u;
    }
    switch (entry_id) {
    case 1u: goto L_08B58B30;
    case 2u: goto L_08B58B38;
    case 3u: goto L_08B58B3C;
    case 4u: goto L_08B58B40;
    case 5u: goto L_08B58B48;
    case 6u: goto L_08B58B50;
    case 7u: goto L_08B58B58;
    case 8u: goto L_08B58B5C;
    case 9u: goto L_08B58B64;
    case 10u: goto L_08B58B68;
    case 11u: goto L_08B58B70;
    case 12u: goto L_08B58B78;
    case 13u: goto L_08B58B7C;
    case 14u: goto L_08B58B80;
    case 15u: goto L_08B58B84;
    case 16u: goto L_08B58B88;
    case 17u: goto L_08B58B90;
    case 18u: goto L_08B58B94;
    case 19u: goto L_08B58B98;
    case 20u: goto L_08B58B9C;
    case 21u: goto L_08B58BA0;
    case 22u: goto L_08B58BA4;
    case 23u: goto L_08B58BA8;
    case 24u: goto L_08B58BAC;
    case 25u: goto L_08B58BB0;
    case 26u: goto L_08B58BB4;
    case 27u: goto L_08B58BB8;
    case 28u: goto L_08B58BBC;
    case 29u: goto L_08B58BC0;
    case 30u: goto L_08B58BC4;
    case 31u: goto L_08B58BC8;
    case 32u: goto L_08B58BCC;
    case 33u: goto L_08B58BD0;
    case 34u: goto L_08B58BD8;
    case 35u: goto L_08B58BDC;
    case 36u: goto L_08B58BE0;
    case 37u: goto L_08B58BE4;
    case 38u: goto L_08B58BE8;
    case 39u: goto L_08B58BEC;
    case 40u: goto L_08B58BF0;
    case 41u: goto L_08B58BF4;
    case 42u: goto L_08B58BFC;
    case 43u: goto L_08B58C04;
    case 44u: goto L_08B58C08;
    case 45u: goto L_08B58C0C;
    case 46u: goto L_08B58C10;
    case 47u: goto L_08B58C14;
    case 48u: goto L_08B58C18;
    case 49u: goto L_08B58C1C;
    case 50u: goto L_08B58C24;
    case 51u: goto L_08B58C28;
    case 52u: goto L_08B58C2C;
    default:
        if (local_transfers == 0u) rt.unsupported(ctx.pc, 0u, "invalid internal function entry");
        else ctx.pc = local_pc;
        return;
    }
    }
L_08B58B30:
    jump_target = ctx.gpr[31];
    ctx.set_gpr(2, ctx.gpr[4] | 0u);
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08B58B38:
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(-16));
    goto L_08B58B3C;
L_08B58B3C:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(0), ctx.gpr[31]);
    goto L_08B58B40;
L_08B58B40:
    { const bool branch_taken = ctx.gpr[4] == 0u;
    ctx.set_gpr(5, ctx.gpr[5] & 1u);
      if (branch_taken) {
          goto L_08B58B58;
      }
      goto L_08B58B48;
    }
L_08B58B48:
    { const bool branch_taken = ctx.gpr[5] == 0u;
    // nop
      if (branch_taken) {
          goto L_08B58B58;
      }
      goto L_08B58B50;
    }
L_08B58B50:
    ctx.set_gpr(31, 0x08B58B58u);
    // nop
    ctx.pc = 0x08992F04u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B58B58u) goto L_08B58B58;
    return;
L_08B58B58:
    ctx.set_gpr(31, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(0)));
    goto L_08B58B5C;
L_08B58B5C:
    jump_target = ctx.gpr[31];
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(16));
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08B58B64:
    rt.memory().aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(0), ctx.gpr[5]);
    goto L_08B58B68;
L_08B58B68:
    jump_target = ctx.gpr[31];
    rt.memory().aot_store32(ctx.gpr[5] + static_cast<std::uint32_t>(0), 0u);
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08B58B70:
    jump_target = ctx.gpr[31];
    rt.memory().aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(0), 0u);
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08B58B78:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(0)));
    goto L_08B58B7C;
L_08B58B7C:
    ctx.set_gpr(5, 0u + static_cast<std::uint32_t>(-2));
    goto L_08B58B80;
L_08B58B80:
    ctx.set_gpr(6, rt.memory().aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(0)));
    goto L_08B58B84;
L_08B58B84:
    ctx.set_gpr(5, ctx.gpr[6] & ctx.gpr[5]);
    goto L_08B58B88;
L_08B58B88:
    jump_target = ctx.gpr[31];
    rt.memory().aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(0), ctx.gpr[5]);
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08B58B90:
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(-16));
    goto L_08B58B94;
L_08B58B94:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(0), ctx.gpr[16]);
    goto L_08B58B98;
L_08B58B98:
    ctx.set_gpr(16, ctx.gpr[4] | 0u);
    goto L_08B58B9C;
L_08B58B9C:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[16] + static_cast<std::uint32_t>(0)));
    goto L_08B58BA0;
L_08B58BA0:
    ctx.set_gpr(5, 2205u << 16u);
    goto L_08B58BA4;
L_08B58BA4:
    ctx.set_gpr(5, rt.memory().aot_load32(ctx.gpr[5] + static_cast<std::uint32_t>(28972)));
    goto L_08B58BA8;
L_08B58BA8:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(4)));
    goto L_08B58BAC;
L_08B58BAC:
    ctx.set_gpr(6, 2230u << 16u);
    goto L_08B58BB0;
L_08B58BB0:
    ctx.set_gpr(4, ctx.gpr[4] + ctx.gpr[4]);
    goto L_08B58BB4;
L_08B58BB4:
    ctx.set_gpr(6, ctx.gpr[6] + static_cast<std::uint32_t>(-28160));
    goto L_08B58BB8;
L_08B58BB8:
    ctx.set_gpr(5, rt.memory().aot_load32(ctx.gpr[5] + static_cast<std::uint32_t>(3808)));
    goto L_08B58BBC;
L_08B58BBC:
    ctx.set_gpr(4, ctx.gpr[4] + ctx.gpr[6]);
    goto L_08B58BC0;
L_08B58BC0:
    ctx.set_gpr(6, rt.memory().aot_load16(ctx.gpr[4] + static_cast<std::uint32_t>(0)));
    goto L_08B58BC4;
L_08B58BC4:
    ctx.set_gpr(4, ctx.gpr[5] | 0u);
    goto L_08B58BC8;
L_08B58BC8:
    ctx.set_gpr(5, ctx.gpr[6] | 0u);
    goto L_08B58BCC;
L_08B58BCC:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(4), ctx.gpr[31]);
    goto L_08B58BD0;
L_08B58BD0:
    ctx.set_gpr(31, 0x08B58BD8u);
    ctx.set_gpr(6, 0u | 0u);
    ctx.pc = 0x0887AFBCu;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B58BD8u) goto L_08B58BD8;
    return;
L_08B58BD8:
    ctx.set_gpr(4, 2205u << 16u);
    goto L_08B58BDC;
L_08B58BDC:
    ctx.set_gpr(6, 2230u << 16u);
    goto L_08B58BE0;
L_08B58BE0:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(29308)));
    goto L_08B58BE4;
L_08B58BE4:
    ctx.set_gpr(5, ctx.gpr[2] | 0u);
    goto L_08B58BE8;
L_08B58BE8:
    ctx.set_gpr(7, 0u | 0u);
    goto L_08B58BEC;
L_08B58BEC:
    ctx.set_gpr(8, 0u | 163u);
    goto L_08B58BF0;
L_08B58BF0:
    ctx.set_gpr(9, 0u | 0u);
    goto L_08B58BF4;
L_08B58BF4:
    ctx.set_gpr(31, 0x08B58BFCu);
    ctx.set_gpr(6, ctx.gpr[6] + static_cast<std::uint32_t>(-28828));
    ctx.pc = 0x088B1230u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08B58BFCu) goto L_08B58BFC;
    return;
L_08B58BFC:
    { const bool branch_taken = ctx.gpr[2] == 0u;
    // nop
      if (branch_taken) {
          goto L_08B58C14;
      }
      goto L_08B58C04;
    }
L_08B58C04:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[16] + static_cast<std::uint32_t>(0)));
    goto L_08B58C08;
L_08B58C08:
    ctx.set_gpr(5, rt.memory().aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(0)));
    goto L_08B58C0C;
L_08B58C0C:
    ctx.set_gpr(5, ctx.gpr[5] | 1u);
    goto L_08B58C10;
L_08B58C10:
    rt.memory().aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(0), ctx.gpr[5]);
    goto L_08B58C14;
L_08B58C14:
    ctx.set_gpr(16, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(0)));
    goto L_08B58C18;
L_08B58C18:
    ctx.set_gpr(31, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(4)));
    goto L_08B58C1C;
L_08B58C1C:
    jump_target = ctx.gpr[31];
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(16));
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
L_08B58C24:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(0)));
    goto L_08B58C28;
L_08B58C28:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(0)));
    goto L_08B58C2C;
L_08B58C2C:
    ctx.set_gpr(4, ctx.gpr[4] & 1u);
    ctx.pc = 0x08B58C30u; return;
}

void sub_08B58B30(Runtime &rt, AllegrexContext &ctx) {
    auto aot_mem = rt.memory().aot_fast_view();
    sub_08B58B30_entry(rt, ctx, 0u, aot_mem);
}

void register_extras_functions(Runtime &runtime) {
    runtime.register_function(0x089E7678u, &___sub_089E7678, "﻿sub_089E7678");
    runtime.register_function(0x089E767Cu, &___sub_089E7678, "﻿sub_089E7678");
    runtime.register_function(0x089E7680u, &___sub_089E7678, "﻿sub_089E7678");
    runtime.register_function(0x089E7684u, &___sub_089E7678, "﻿sub_089E7678");
    runtime.register_function(0x089E7688u, &___sub_089E7678, "﻿sub_089E7678");
    runtime.register_function(0x089E768Cu, &___sub_089E7678, "﻿sub_089E7678");
    runtime.register_function(0x089E7690u, &___sub_089E7678, "﻿sub_089E7678");
    runtime.register_function(0x089E7694u, &___sub_089E7678, "﻿sub_089E7678");
    runtime.register_function(0x089E7698u, &___sub_089E7678, "﻿sub_089E7678");
    runtime.register_function(0x089E76A0u, &___sub_089E7678, "﻿sub_089E7678");
    runtime.register_function(0x089E76A4u, &___sub_089E7678, "﻿sub_089E7678");
    runtime.register_function(0x089E76A8u, &___sub_089E7678, "﻿sub_089E7678");
    runtime.register_function(0x089E76ACu, &___sub_089E7678, "﻿sub_089E7678");
    runtime.register_function(0x089E76B0u, &___sub_089E7678, "﻿sub_089E7678");
    runtime.register_function(0x089E76B4u, &___sub_089E7678, "﻿sub_089E7678");
    runtime.register_function(0x089E76B8u, &___sub_089E7678, "﻿sub_089E7678");
    runtime.register_function(0x089E76BCu, &___sub_089E7678, "﻿sub_089E7678");
    runtime.register_function(0x089E76C0u, &___sub_089E7678, "﻿sub_089E7678");
    runtime.register_function(0x089E76C4u, &___sub_089E7678, "﻿sub_089E7678");
    runtime.register_function(0x089E76C8u, &___sub_089E7678, "﻿sub_089E7678");
    runtime.register_function(0x089E76CCu, &___sub_089E7678, "﻿sub_089E7678");
    runtime.register_function(0x089E76D0u, &___sub_089E7678, "﻿sub_089E7678");
    runtime.register_function(0x089E76D4u, &___sub_089E7678, "﻿sub_089E7678");
    runtime.register_function(0x089E76D8u, &___sub_089E7678, "﻿sub_089E7678");
    runtime.register_function(0x089E76DCu, &___sub_089E7678, "﻿sub_089E7678");
    runtime.register_function(0x089E76E0u, &___sub_089E7678, "﻿sub_089E7678");
    runtime.register_function(0x089E76E4u, &___sub_089E7678, "﻿sub_089E7678");
    runtime.register_function(0x089E76E8u, &___sub_089E7678, "﻿sub_089E7678");
    runtime.register_function(0x089E76ECu, &___sub_089E7678, "﻿sub_089E7678");
    runtime.register_function(0x089E76F0u, &___sub_089E7678, "﻿sub_089E7678");
    runtime.register_function(0x089E76F4u, &___sub_089E7678, "﻿sub_089E7678");
    runtime.register_function(0x089E76F8u, &___sub_089E7678, "﻿sub_089E7678");
    runtime.register_function(0x089E76FCu, &___sub_089E7678, "﻿sub_089E7678");
    runtime.register_function(0x089E7700u, &___sub_089E7678, "﻿sub_089E7678");
    runtime.register_function(0x089E7708u, &___sub_089E7678, "﻿sub_089E7678");
    runtime.register_function(0x089E770Cu, &___sub_089E7678, "﻿sub_089E7678");
    runtime.register_function(0x089E7710u, &___sub_089E7678, "﻿sub_089E7678");
    runtime.register_function(0x089E7714u, &___sub_089E7678, "﻿sub_089E7678");
    runtime.register_function(0x089E771Cu, &___sub_089E7678, "﻿sub_089E7678");
    runtime.register_function(0x089E7720u, &___sub_089E7678, "﻿sub_089E7678");
    runtime.register_function(0x089E7724u, &___sub_089E7678, "﻿sub_089E7678");
    runtime.register_function(0x089E7728u, &___sub_089E7678, "﻿sub_089E7678");
    runtime.register_function(0x089E772Cu, &___sub_089E7678, "﻿sub_089E7678");
    runtime.register_function(0x089E7734u, &___sub_089E7678, "﻿sub_089E7678");
    runtime.register_function(0x089E7738u, &___sub_089E7678, "﻿sub_089E7678");
    runtime.register_function(0x089E773Cu, &___sub_089E7678, "﻿sub_089E7678");
    runtime.register_function(0x089E7740u, &___sub_089E7678, "﻿sub_089E7678");
    runtime.register_function(0x089E7744u, &___sub_089E7678, "﻿sub_089E7678");
    runtime.register_function(0x089E7748u, &___sub_089E7678, "﻿sub_089E7678");
    runtime.register_function(0x089E774Cu, &___sub_089E7678, "﻿sub_089E7678");
    runtime.register_function(0x089E7754u, &___sub_089E7678, "﻿sub_089E7678");
    runtime.register_function(0x089E7758u, &___sub_089E7678, "﻿sub_089E7678");
    runtime.register_function(0x089E7760u, &___sub_089E7678, "﻿sub_089E7678");
    runtime.register_function(0x089E7764u, &___sub_089E7678, "﻿sub_089E7678");
    runtime.register_function(0x089E7768u, &___sub_089E7678, "﻿sub_089E7678");
    runtime.register_function(0x089E7770u, &___sub_089E7678, "﻿sub_089E7678");
    runtime.register_function(0x089E7774u, &___sub_089E7678, "﻿sub_089E7678");
    runtime.register_function(0x089FE524u, &sub_089FE524, "sub_089FE524");
    runtime.register_function(0x089FE528u, &sub_089FE524, "sub_089FE524");
    runtime.register_function(0x089FE52Cu, &sub_089FE524, "sub_089FE524");
    runtime.register_function(0x089FE530u, &sub_089FE524, "sub_089FE524");
    runtime.register_function(0x089FE534u, &sub_089FE524, "sub_089FE524");
    runtime.register_function(0x089FE538u, &sub_089FE524, "sub_089FE524");
    runtime.register_function(0x089FE53Cu, &sub_089FE524, "sub_089FE524");
    runtime.register_function(0x089FE540u, &sub_089FE524, "sub_089FE524");
    runtime.register_function(0x089FE544u, &sub_089FE524, "sub_089FE524");
    runtime.register_function(0x089FE54Cu, &sub_089FE524, "sub_089FE524");
    runtime.register_function(0x089FE550u, &sub_089FE524, "sub_089FE524");
    runtime.register_function(0x089FE554u, &sub_089FE524, "sub_089FE524");
    runtime.register_function(0x089FE558u, &sub_089FE524, "sub_089FE524");
    runtime.register_function(0x089FE560u, &sub_089FE524, "sub_089FE524");
    runtime.register_function(0x089FE564u, &sub_089FE524, "sub_089FE524");
    runtime.register_function(0x089FE568u, &sub_089FE524, "sub_089FE524");
    runtime.register_function(0x089FE570u, &sub_089FE524, "sub_089FE524");
    runtime.register_function(0x089FE578u, &sub_089FE524, "sub_089FE524");
    runtime.register_function(0x089FE580u, &sub_089FE524, "sub_089FE524");
    runtime.register_function(0x089FE584u, &sub_089FE524, "sub_089FE524");
    runtime.register_function(0x089FE58Cu, &sub_089FE524, "sub_089FE524");
    runtime.register_function(0x089FE590u, &sub_089FE524, "sub_089FE524");
    runtime.register_function(0x089FE598u, &sub_089FE524, "sub_089FE524");
    runtime.register_function(0x089FE59Cu, &sub_089FE524, "sub_089FE524");
    runtime.register_function(0x089FE5A4u, &sub_089FE524, "sub_089FE524");
    runtime.register_function(0x089FE5A8u, &sub_089FE524, "sub_089FE524");
    runtime.register_function(0x089FE5B0u, &sub_089FE524, "sub_089FE524");
    runtime.register_function(0x089FE5B4u, &sub_089FE524, "sub_089FE524");
    runtime.register_function(0x089FE5BCu, &sub_089FE524, "sub_089FE524");
    runtime.register_function(0x089FE5C0u, &sub_089FE524, "sub_089FE524");
    runtime.register_function(0x089FE5C4u, &sub_089FE524, "sub_089FE524");
    runtime.register_function(0x089FE5C8u, &sub_089FE524, "sub_089FE524");
    runtime.register_function(0x089FE5CCu, &sub_089FE524, "sub_089FE524");
    runtime.register_function(0x089FE5D0u, &sub_089FE524, "sub_089FE524");
    runtime.register_function(0x089FE5D8u, &sub_089FE524, "sub_089FE524");
    runtime.register_function(0x089FE5DCu, &sub_089FE524, "sub_089FE524");
    runtime.register_function(0x089FE5E0u, &sub_089FE524, "sub_089FE524");
    runtime.register_function(0x089FE5E4u, &sub_089FE524, "sub_089FE524");
    runtime.register_function(0x089FE5E8u, &sub_089FE524, "sub_089FE524");
    runtime.register_function(0x089FE5ECu, &sub_089FE524, "sub_089FE524");
    runtime.register_function(0x089FE5F4u, &sub_089FE524, "sub_089FE524");
    runtime.register_function(0x089FE5F8u, &sub_089FE524, "sub_089FE524");
    runtime.register_function(0x089FE5FCu, &sub_089FE524, "sub_089FE524");
    runtime.register_function(0x089FE600u, &sub_089FE524, "sub_089FE524");
    runtime.register_function(0x089FE604u, &sub_089FE524, "sub_089FE524");
    runtime.register_function(0x089FE60Cu, &sub_089FE524, "sub_089FE524");
    runtime.register_function(0x089FE610u, &sub_089FE524, "sub_089FE524");
    runtime.register_function(0x089FE618u, &sub_089FE524, "sub_089FE524");
    runtime.register_function(0x089FE61Cu, &sub_089FE524, "sub_089FE524");
    runtime.register_function(0x089FE620u, &sub_089FE524, "sub_089FE524");
    runtime.register_function(0x08A1D364u, &sub_08A1D364, "sub_08A1D364");
    runtime.register_function(0x08A1D368u, &sub_08A1D364, "sub_08A1D364");
    runtime.register_function(0x08A1D36Cu, &sub_08A1D364, "sub_08A1D364");
    runtime.register_function(0x08A1D370u, &sub_08A1D364, "sub_08A1D364");
    runtime.register_function(0x08A1D374u, &sub_08A1D364, "sub_08A1D364");
    runtime.register_function(0x08A1D378u, &sub_08A1D364, "sub_08A1D364");
    runtime.register_function(0x08A1D37Cu, &sub_08A1D364, "sub_08A1D364");
    runtime.register_function(0x08A1D380u, &sub_08A1D364, "sub_08A1D364");
    runtime.register_function(0x08A1D384u, &sub_08A1D364, "sub_08A1D364");
    runtime.register_function(0x08A1D38Cu, &sub_08A1D364, "sub_08A1D364");
    runtime.register_function(0x08A1D390u, &sub_08A1D364, "sub_08A1D364");
    runtime.register_function(0x08A1D394u, &sub_08A1D364, "sub_08A1D364");
    runtime.register_function(0x08A1D398u, &sub_08A1D364, "sub_08A1D364");
    runtime.register_function(0x08A1D39Cu, &sub_08A1D364, "sub_08A1D364");
    runtime.register_function(0x08A1D3A0u, &sub_08A1D364, "sub_08A1D364");
    runtime.register_function(0x08A1D3A4u, &sub_08A1D364, "sub_08A1D364");
    runtime.register_function(0x08A1D3A8u, &sub_08A1D364, "sub_08A1D364");
    runtime.register_function(0x08A1D3ACu, &sub_08A1D364, "sub_08A1D364");
    runtime.register_function(0x08A1D3B0u, &sub_08A1D364, "sub_08A1D364");
    runtime.register_function(0x08A1D3B4u, &sub_08A1D364, "sub_08A1D364");
    runtime.register_function(0x08A1D3B8u, &sub_08A1D364, "sub_08A1D364");
    runtime.register_function(0x08A1D3BCu, &sub_08A1D364, "sub_08A1D364");
    runtime.register_function(0x08A1D3C0u, &sub_08A1D364, "sub_08A1D364");
    runtime.register_function(0x08A1D3C4u, &sub_08A1D364, "sub_08A1D364");
    runtime.register_function(0x08A1D3C8u, &sub_08A1D364, "sub_08A1D364");
    runtime.register_function(0x08A1D3CCu, &sub_08A1D364, "sub_08A1D364");
    runtime.register_function(0x08A1D3D0u, &sub_08A1D364, "sub_08A1D364");
    runtime.register_function(0x08A1D3D4u, &sub_08A1D364, "sub_08A1D364");
    runtime.register_function(0x08A1D3D8u, &sub_08A1D364, "sub_08A1D364");
    runtime.register_function(0x08A1D3DCu, &sub_08A1D364, "sub_08A1D364");
    runtime.register_function(0x08A1D3E0u, &sub_08A1D364, "sub_08A1D364");
    runtime.register_function(0x08A1D3E4u, &sub_08A1D364, "sub_08A1D364");
    runtime.register_function(0x08A1D3E8u, &sub_08A1D364, "sub_08A1D364");
    runtime.register_function(0x08A1D3ECu, &sub_08A1D364, "sub_08A1D364");
    runtime.register_function(0x08A1D3F0u, &sub_08A1D364, "sub_08A1D364");
    runtime.register_function(0x08A1D3F4u, &sub_08A1D364, "sub_08A1D364");
    runtime.register_function(0x08A1D3F8u, &sub_08A1D364, "sub_08A1D364");
    runtime.register_function(0x08A1D400u, &sub_08A1D364, "sub_08A1D364");
    runtime.register_function(0x08A1D404u, &sub_08A1D364, "sub_08A1D364");
    runtime.register_function(0x08A1D408u, &sub_08A1D364, "sub_08A1D364");
    runtime.register_function(0x08A1D410u, &sub_08A1D364, "sub_08A1D364");
    runtime.register_function(0x08A1D418u, &sub_08A1D364, "sub_08A1D364");
    runtime.register_function(0x08A1D420u, &sub_08A1D364, "sub_08A1D364");
    runtime.register_function(0x08A1D424u, &sub_08A1D364, "sub_08A1D364");
    runtime.register_function(0x08A1D42Cu, &sub_08A1D364, "sub_08A1D364");
    runtime.register_function(0x08A1D430u, &sub_08A1D364, "sub_08A1D364");
    runtime.register_function(0x08A1D434u, &sub_08A1D364, "sub_08A1D364");
    runtime.register_function(0x08A1D438u, &sub_08A1D364, "sub_08A1D364");
    runtime.register_function(0x08A1D43Cu, &sub_08A1D364, "sub_08A1D364");
    runtime.register_function(0x08A1D440u, &sub_08A1D364, "sub_08A1D364");
    runtime.register_function(0x08A1D444u, &sub_08A1D364, "sub_08A1D364");
    runtime.register_function(0x08A1D448u, &sub_08A1D364, "sub_08A1D364");
    runtime.register_function(0x08A1D44Cu, &sub_08A1D364, "sub_08A1D364");
    runtime.register_function(0x08A1D454u, &sub_08A1D364, "sub_08A1D364");
    runtime.register_function(0x08A1D458u, &sub_08A1D364, "sub_08A1D364");
    runtime.register_function(0x08A1D460u, &sub_08A1D364, "sub_08A1D364");
    runtime.register_function(0x08A2BCE4u, &sub_08A2BCE4, "sub_08A2BCE4");
    runtime.register_function(0x08A2BCE8u, &sub_08A2BCE4, "sub_08A2BCE4");
    runtime.register_function(0x08A2BCECu, &sub_08A2BCE4, "sub_08A2BCE4");
    runtime.register_function(0x08A2BCF0u, &sub_08A2BCE4, "sub_08A2BCE4");
    runtime.register_function(0x08A2BCF4u, &sub_08A2BCE4, "sub_08A2BCE4");
    runtime.register_function(0x08A2BCF8u, &sub_08A2BCE4, "sub_08A2BCE4");
    runtime.register_function(0x08A2BCFCu, &sub_08A2BCE4, "sub_08A2BCE4");
    runtime.register_function(0x08A2BD00u, &sub_08A2BCE4, "sub_08A2BCE4");
    runtime.register_function(0x08A2BD04u, &sub_08A2BCE4, "sub_08A2BCE4");
    runtime.register_function(0x08A2BD0Cu, &sub_08A2BCE4, "sub_08A2BCE4");
    runtime.register_function(0x08A2BD10u, &sub_08A2BCE4, "sub_08A2BCE4");
    runtime.register_function(0x08A2BD14u, &sub_08A2BCE4, "sub_08A2BCE4");
    runtime.register_function(0x08A2BD18u, &sub_08A2BCE4, "sub_08A2BCE4");
    runtime.register_function(0x08A2BD20u, &sub_08A2BCE4, "sub_08A2BCE4");
    runtime.register_function(0x08A2BD24u, &sub_08A2BCE4, "sub_08A2BCE4");
    runtime.register_function(0x08A2BD28u, &sub_08A2BCE4, "sub_08A2BCE4");
    runtime.register_function(0x08A2BD30u, &sub_08A2BCE4, "sub_08A2BCE4");
    runtime.register_function(0x08A2BD38u, &sub_08A2BCE4, "sub_08A2BCE4");
    runtime.register_function(0x08A2BD40u, &sub_08A2BCE4, "sub_08A2BCE4");
    runtime.register_function(0x08A2BD44u, &sub_08A2BCE4, "sub_08A2BCE4");
    runtime.register_function(0x08A2BD4Cu, &sub_08A2BCE4, "sub_08A2BCE4");
    runtime.register_function(0x08A2BD50u, &sub_08A2BCE4, "sub_08A2BCE4");
    runtime.register_function(0x08A2BD54u, &sub_08A2BCE4, "sub_08A2BCE4");
    runtime.register_function(0x08A2BD58u, &sub_08A2BCE4, "sub_08A2BCE4");
    runtime.register_function(0x08A2BD5Cu, &sub_08A2BCE4, "sub_08A2BCE4");
    runtime.register_function(0x08A2BD60u, &sub_08A2BCE4, "sub_08A2BCE4");
    runtime.register_function(0x08A2BD68u, &sub_08A2BCE4, "sub_08A2BCE4");
    runtime.register_function(0x08A2BD6Cu, &sub_08A2BCE4, "sub_08A2BCE4");
    runtime.register_function(0x08A2BD70u, &sub_08A2BCE4, "sub_08A2BCE4");
    runtime.register_function(0x08A2BD74u, &sub_08A2BCE4, "sub_08A2BCE4");
    runtime.register_function(0x08A2BD78u, &sub_08A2BCE4, "sub_08A2BCE4");
    runtime.register_function(0x08A2BD7Cu, &sub_08A2BCE4, "sub_08A2BCE4");
    runtime.register_function(0x08A2BD84u, &sub_08A2BCE4, "sub_08A2BCE4");
    runtime.register_function(0x08A2BD88u, &sub_08A2BCE4, "sub_08A2BCE4");
    runtime.register_function(0x08A2BD8Cu, &sub_08A2BCE4, "sub_08A2BCE4");
    runtime.register_function(0x08A2BD90u, &sub_08A2BCE4, "sub_08A2BCE4");
    runtime.register_function(0x08A2BD94u, &sub_08A2BCE4, "sub_08A2BCE4");
    runtime.register_function(0x08A2BD98u, &sub_08A2BCE4, "sub_08A2BCE4");
    runtime.register_function(0x08A2BD9Cu, &sub_08A2BCE4, "sub_08A2BCE4");
    runtime.register_function(0x08A2BDA0u, &sub_08A2BCE4, "sub_08A2BCE4");
    runtime.register_function(0x08A2BDA8u, &sub_08A2BCE4, "sub_08A2BCE4");
    runtime.register_function(0x08A2BDACu, &sub_08A2BCE4, "sub_08A2BCE4");
    runtime.register_function(0x08A2BDB0u, &sub_08A2BCE4, "sub_08A2BCE4");
    runtime.register_function(0x08A2BDB4u, &sub_08A2BCE4, "sub_08A2BCE4");
    runtime.register_function(0x08A2BDBCu, &sub_08A2BCE4, "sub_08A2BCE4");
    runtime.register_function(0x08A2BDC0u, &sub_08A2BCE4, "sub_08A2BCE4");
    runtime.register_function(0x08A2BDC4u, &sub_08A2BCE4, "sub_08A2BCE4");
    runtime.register_function(0x08A2BDC8u, &sub_08A2BCE4, "sub_08A2BCE4");
    runtime.register_function(0x08A2BDCCu, &sub_08A2BCE4, "sub_08A2BCE4");
    runtime.register_function(0x08A2BDD0u, &sub_08A2BCE4, "sub_08A2BCE4");
    runtime.register_function(0x08A2BDD4u, &sub_08A2BCE4, "sub_08A2BCE4");
    runtime.register_function(0x08A2BDD8u, &sub_08A2BCE4, "sub_08A2BCE4");
    runtime.register_function(0x08A2BDE0u, &sub_08A2BCE4, "sub_08A2BCE4");
    runtime.register_function(0x08A323E4u, &sub_08A323E4, "sub_08A323E4");
    runtime.register_function(0x08A323E8u, &sub_08A323E4, "sub_08A323E4");
    runtime.register_function(0x08A323ECu, &sub_08A323E4, "sub_08A323E4");
    runtime.register_function(0x08A323F0u, &sub_08A323E4, "sub_08A323E4");
    runtime.register_function(0x08A323F4u, &sub_08A323E4, "sub_08A323E4");
    runtime.register_function(0x08A323F8u, &sub_08A323E4, "sub_08A323E4");
    runtime.register_function(0x08A323FCu, &sub_08A323E4, "sub_08A323E4");
    runtime.register_function(0x08A32400u, &sub_08A323E4, "sub_08A323E4");
    runtime.register_function(0x08A32404u, &sub_08A323E4, "sub_08A323E4");
    runtime.register_function(0x08A3240Cu, &sub_08A323E4, "sub_08A323E4");
    runtime.register_function(0x08A32410u, &sub_08A323E4, "sub_08A323E4");
    runtime.register_function(0x08A32414u, &sub_08A323E4, "sub_08A323E4");
    runtime.register_function(0x08A32418u, &sub_08A323E4, "sub_08A323E4");
    runtime.register_function(0x08A32420u, &sub_08A323E4, "sub_08A323E4");
    runtime.register_function(0x08A32424u, &sub_08A323E4, "sub_08A323E4");
    runtime.register_function(0x08A32428u, &sub_08A323E4, "sub_08A323E4");
    runtime.register_function(0x08A32430u, &sub_08A323E4, "sub_08A323E4");
    runtime.register_function(0x08A32438u, &sub_08A323E4, "sub_08A323E4");
    runtime.register_function(0x08A32440u, &sub_08A323E4, "sub_08A323E4");
    runtime.register_function(0x08A32444u, &sub_08A323E4, "sub_08A323E4");
    runtime.register_function(0x08A3244Cu, &sub_08A323E4, "sub_08A323E4");
    runtime.register_function(0x08A32450u, &sub_08A323E4, "sub_08A323E4");
    runtime.register_function(0x08A32454u, &sub_08A323E4, "sub_08A323E4");
    runtime.register_function(0x08A32458u, &sub_08A323E4, "sub_08A323E4");
    runtime.register_function(0x08A32460u, &sub_08A323E4, "sub_08A323E4");
    runtime.register_function(0x08A32464u, &sub_08A323E4, "sub_08A323E4");
    runtime.register_function(0x08A3246Cu, &sub_08A323E4, "sub_08A323E4");
    runtime.register_function(0x08A32470u, &sub_08A323E4, "sub_08A323E4");
    runtime.register_function(0x08A32474u, &sub_08A323E4, "sub_08A323E4");
    runtime.register_function(0x08A32478u, &sub_08A323E4, "sub_08A323E4");
    runtime.register_function(0x08A32480u, &sub_08A323E4, "sub_08A323E4");
    runtime.register_function(0x08A32484u, &sub_08A323E4, "sub_08A323E4");
    runtime.register_function(0x08A3248Cu, &sub_08A323E4, "sub_08A323E4");
    runtime.register_function(0x08A32490u, &sub_08A323E4, "sub_08A323E4");
    runtime.register_function(0x08A32494u, &sub_08A323E4, "sub_08A323E4");
    runtime.register_function(0x08A32498u, &sub_08A323E4, "sub_08A323E4");
    runtime.register_function(0x08A3249Cu, &sub_08A323E4, "sub_08A323E4");
    runtime.register_function(0x08A324A0u, &sub_08A323E4, "sub_08A323E4");
    runtime.register_function(0x08A324A4u, &sub_08A323E4, "sub_08A323E4");
    runtime.register_function(0x08A324A8u, &sub_08A323E4, "sub_08A323E4");
    runtime.register_function(0x08A324ACu, &sub_08A323E4, "sub_08A323E4");
    runtime.register_function(0x08A324B0u, &sub_08A323E4, "sub_08A323E4");
    runtime.register_function(0x08A324B4u, &sub_08A323E4, "sub_08A323E4");
    runtime.register_function(0x08A324B8u, &sub_08A323E4, "sub_08A323E4");
    runtime.register_function(0x08A324BCu, &sub_08A323E4, "sub_08A323E4");
    runtime.register_function(0x08A324C0u, &sub_08A323E4, "sub_08A323E4");
    runtime.register_function(0x08A324C4u, &sub_08A323E4, "sub_08A323E4");
    runtime.register_function(0x08A324C8u, &sub_08A323E4, "sub_08A323E4");
    runtime.register_function(0x08A324CCu, &sub_08A323E4, "sub_08A323E4");
    runtime.register_function(0x08A324D0u, &sub_08A323E4, "sub_08A323E4");
    runtime.register_function(0x08A324D4u, &sub_08A323E4, "sub_08A323E4");
    runtime.register_function(0x08A324D8u, &sub_08A323E4, "sub_08A323E4");
    runtime.register_function(0x08A324DCu, &sub_08A323E4, "sub_08A323E4");
    runtime.register_function(0x08A324E0u, &sub_08A323E4, "sub_08A323E4");
    runtime.register_function(0x08A42C1Cu, &sub_08A42C1C, "sub_08A42C1C");
    runtime.register_function(0x08A42C20u, &sub_08A42C1C, "sub_08A42C1C");
    runtime.register_function(0x08A42C24u, &sub_08A42C1C, "sub_08A42C1C");
    runtime.register_function(0x08A42C28u, &sub_08A42C1C, "sub_08A42C1C");
    runtime.register_function(0x08A42C2Cu, &sub_08A42C1C, "sub_08A42C1C");
    runtime.register_function(0x08A42C30u, &sub_08A42C1C, "sub_08A42C1C");
    runtime.register_function(0x08A42C34u, &sub_08A42C1C, "sub_08A42C1C");
    runtime.register_function(0x08A42C38u, &sub_08A42C1C, "sub_08A42C1C");
    runtime.register_function(0x08A42C3Cu, &sub_08A42C1C, "sub_08A42C1C");
    runtime.register_function(0x08A42C44u, &sub_08A42C1C, "sub_08A42C1C");
    runtime.register_function(0x08A42C48u, &sub_08A42C1C, "sub_08A42C1C");
    runtime.register_function(0x08A42C4Cu, &sub_08A42C1C, "sub_08A42C1C");
    runtime.register_function(0x08A42C50u, &sub_08A42C1C, "sub_08A42C1C");
    runtime.register_function(0x08A42C58u, &sub_08A42C1C, "sub_08A42C1C");
    runtime.register_function(0x08A42C5Cu, &sub_08A42C1C, "sub_08A42C1C");
    runtime.register_function(0x08A42C60u, &sub_08A42C1C, "sub_08A42C1C");
    runtime.register_function(0x08A42C68u, &sub_08A42C1C, "sub_08A42C1C");
    runtime.register_function(0x08A42C70u, &sub_08A42C1C, "sub_08A42C1C");
    runtime.register_function(0x08A42C78u, &sub_08A42C1C, "sub_08A42C1C");
    runtime.register_function(0x08A42C7Cu, &sub_08A42C1C, "sub_08A42C1C");
    runtime.register_function(0x08A42C84u, &sub_08A42C1C, "sub_08A42C1C");
    runtime.register_function(0x08A42C88u, &sub_08A42C1C, "sub_08A42C1C");
    runtime.register_function(0x08A42C8Cu, &sub_08A42C1C, "sub_08A42C1C");
    runtime.register_function(0x08A42C90u, &sub_08A42C1C, "sub_08A42C1C");
    runtime.register_function(0x08A42C94u, &sub_08A42C1C, "sub_08A42C1C");
    runtime.register_function(0x08A42C9Cu, &sub_08A42C1C, "sub_08A42C1C");
    runtime.register_function(0x08A42CA0u, &sub_08A42C1C, "sub_08A42C1C");
    runtime.register_function(0x08A42CA8u, &sub_08A42C1C, "sub_08A42C1C");
    runtime.register_function(0x08A42CACu, &sub_08A42C1C, "sub_08A42C1C");
    runtime.register_function(0x08A42CB0u, &sub_08A42C1C, "sub_08A42C1C");
    runtime.register_function(0x08A42CB4u, &sub_08A42C1C, "sub_08A42C1C");
    runtime.register_function(0x08A42CB8u, &sub_08A42C1C, "sub_08A42C1C");
    runtime.register_function(0x08A42CC0u, &sub_08A42C1C, "sub_08A42C1C");
    runtime.register_function(0x08A42CC4u, &sub_08A42C1C, "sub_08A42C1C");
    runtime.register_function(0x08A42CCCu, &sub_08A42C1C, "sub_08A42C1C");
    runtime.register_function(0x08A42CD0u, &sub_08A42C1C, "sub_08A42C1C");
    runtime.register_function(0x08A42CD4u, &sub_08A42C1C, "sub_08A42C1C");
    runtime.register_function(0x08A42CD8u, &sub_08A42C1C, "sub_08A42C1C");
    runtime.register_function(0x08A42CDCu, &sub_08A42C1C, "sub_08A42C1C");
    runtime.register_function(0x08A42CE0u, &sub_08A42C1C, "sub_08A42C1C");
    runtime.register_function(0x08A42CE8u, &sub_08A42C1C, "sub_08A42C1C");
    runtime.register_function(0x08A42CECu, &sub_08A42C1C, "sub_08A42C1C");
    runtime.register_function(0x08A42CF0u, &sub_08A42C1C, "sub_08A42C1C");
    runtime.register_function(0x08A42CF4u, &sub_08A42C1C, "sub_08A42C1C");
    runtime.register_function(0x08A42CF8u, &sub_08A42C1C, "sub_08A42C1C");
    runtime.register_function(0x08A42CFCu, &sub_08A42C1C, "sub_08A42C1C");
    runtime.register_function(0x08A42D00u, &sub_08A42C1C, "sub_08A42C1C");
    runtime.register_function(0x08A42D04u, &sub_08A42C1C, "sub_08A42C1C");
    runtime.register_function(0x08A42D08u, &sub_08A42C1C, "sub_08A42C1C");
    runtime.register_function(0x08A42D0Cu, &sub_08A42C1C, "sub_08A42C1C");
    runtime.register_function(0x08A42D10u, &sub_08A42C1C, "sub_08A42C1C");
    runtime.register_function(0x08A42D18u, &sub_08A42C1C, "sub_08A42C1C");
    runtime.register_function(0x08A436C0u, &sub_08A436C0, "sub_08A436C0");
    runtime.register_function(0x08A436C4u, &sub_08A436C0, "sub_08A436C0");
    runtime.register_function(0x08A436C8u, &sub_08A436C0, "sub_08A436C0");
    runtime.register_function(0x08A436CCu, &sub_08A436C0, "sub_08A436C0");
    runtime.register_function(0x08A436D0u, &sub_08A436C0, "sub_08A436C0");
    runtime.register_function(0x08A436D4u, &sub_08A436C0, "sub_08A436C0");
    runtime.register_function(0x08A436D8u, &sub_08A436C0, "sub_08A436C0");
    runtime.register_function(0x08A436DCu, &sub_08A436C0, "sub_08A436C0");
    runtime.register_function(0x08A436E0u, &sub_08A436C0, "sub_08A436C0");
    runtime.register_function(0x08A436E8u, &sub_08A436C0, "sub_08A436C0");
    runtime.register_function(0x08A436ECu, &sub_08A436C0, "sub_08A436C0");
    runtime.register_function(0x08A436F0u, &sub_08A436C0, "sub_08A436C0");
    runtime.register_function(0x08A436F4u, &sub_08A436C0, "sub_08A436C0");
    runtime.register_function(0x08A436FCu, &sub_08A436C0, "sub_08A436C0");
    runtime.register_function(0x08A43700u, &sub_08A436C0, "sub_08A436C0");
    runtime.register_function(0x08A43704u, &sub_08A436C0, "sub_08A436C0");
    runtime.register_function(0x08A4370Cu, &sub_08A436C0, "sub_08A436C0");
    runtime.register_function(0x08A43714u, &sub_08A436C0, "sub_08A436C0");
    runtime.register_function(0x08A4371Cu, &sub_08A436C0, "sub_08A436C0");
    runtime.register_function(0x08A43720u, &sub_08A436C0, "sub_08A436C0");
    runtime.register_function(0x08A43728u, &sub_08A436C0, "sub_08A436C0");
    runtime.register_function(0x08A4372Cu, &sub_08A436C0, "sub_08A436C0");
    runtime.register_function(0x08A43730u, &sub_08A436C0, "sub_08A436C0");
    runtime.register_function(0x08A43734u, &sub_08A436C0, "sub_08A436C0");
    runtime.register_function(0x08A43738u, &sub_08A436C0, "sub_08A436C0");
    runtime.register_function(0x08A4373Cu, &sub_08A436C0, "sub_08A436C0");
    runtime.register_function(0x08A43740u, &sub_08A436C0, "sub_08A436C0");
    runtime.register_function(0x08A43744u, &sub_08A436C0, "sub_08A436C0");
    runtime.register_function(0x08A43748u, &sub_08A436C0, "sub_08A436C0");
    runtime.register_function(0x08A4374Cu, &sub_08A436C0, "sub_08A436C0");
    runtime.register_function(0x08A43750u, &sub_08A436C0, "sub_08A436C0");
    runtime.register_function(0x08A43758u, &sub_08A436C0, "sub_08A436C0");
    runtime.register_function(0x08A4375Cu, &sub_08A436C0, "sub_08A436C0");
    runtime.register_function(0x08A43760u, &sub_08A436C0, "sub_08A436C0");
    runtime.register_function(0x08A43764u, &sub_08A436C0, "sub_08A436C0");
    runtime.register_function(0x08A43768u, &sub_08A436C0, "sub_08A436C0");
    runtime.register_function(0x08A43770u, &sub_08A436C0, "sub_08A436C0");
    runtime.register_function(0x08A43778u, &sub_08A436C0, "sub_08A436C0");
    runtime.register_function(0x08A43780u, &sub_08A436C0, "sub_08A436C0");
    runtime.register_function(0x08A43784u, &sub_08A436C0, "sub_08A436C0");
    runtime.register_function(0x08A43788u, &sub_08A436C0, "sub_08A436C0");
    runtime.register_function(0x08A4378Cu, &sub_08A436C0, "sub_08A436C0");
    runtime.register_function(0x08A43790u, &sub_08A436C0, "sub_08A436C0");
    runtime.register_function(0x08A43794u, &sub_08A436C0, "sub_08A436C0");
    runtime.register_function(0x08A4379Cu, &sub_08A436C0, "sub_08A436C0");
    runtime.register_function(0x08A437A0u, &sub_08A436C0, "sub_08A436C0");
    runtime.register_function(0x08A437A8u, &sub_08A436C0, "sub_08A436C0");
    runtime.register_function(0x08A437B0u, &sub_08A436C0, "sub_08A436C0");
    runtime.register_function(0x08A437B8u, &sub_08A436C0, "sub_08A436C0");
    runtime.register_function(0x08A437BCu, &sub_08A436C0, "sub_08A436C0");
    runtime.register_function(0x08A4ABFCu, &sub_08A4ABFC, "sub_08A4ABFC");
    runtime.register_function(0x08A4AC00u, &sub_08A4ABFC, "sub_08A4ABFC");
    runtime.register_function(0x08A4AC04u, &sub_08A4ABFC, "sub_08A4ABFC");
    runtime.register_function(0x08A4AC08u, &sub_08A4ABFC, "sub_08A4ABFC");
    runtime.register_function(0x08A4AC0Cu, &sub_08A4ABFC, "sub_08A4ABFC");
    runtime.register_function(0x08A4AC10u, &sub_08A4ABFC, "sub_08A4ABFC");
    runtime.register_function(0x08A4AC14u, &sub_08A4ABFC, "sub_08A4ABFC");
    runtime.register_function(0x08A4AC18u, &sub_08A4ABFC, "sub_08A4ABFC");
    runtime.register_function(0x08A4AC1Cu, &sub_08A4ABFC, "sub_08A4ABFC");
    runtime.register_function(0x08A4AC24u, &sub_08A4ABFC, "sub_08A4ABFC");
    runtime.register_function(0x08A4AC28u, &sub_08A4ABFC, "sub_08A4ABFC");
    runtime.register_function(0x08A4AC2Cu, &sub_08A4ABFC, "sub_08A4ABFC");
    runtime.register_function(0x08A4AC30u, &sub_08A4ABFC, "sub_08A4ABFC");
    runtime.register_function(0x08A4AC38u, &sub_08A4ABFC, "sub_08A4ABFC");
    runtime.register_function(0x08A4AC3Cu, &sub_08A4ABFC, "sub_08A4ABFC");
    runtime.register_function(0x08A4AC40u, &sub_08A4ABFC, "sub_08A4ABFC");
    runtime.register_function(0x08A4AC48u, &sub_08A4ABFC, "sub_08A4ABFC");
    runtime.register_function(0x08A4AC50u, &sub_08A4ABFC, "sub_08A4ABFC");
    runtime.register_function(0x08A4AC58u, &sub_08A4ABFC, "sub_08A4ABFC");
    runtime.register_function(0x08A4AC5Cu, &sub_08A4ABFC, "sub_08A4ABFC");
    runtime.register_function(0x08A4AC64u, &sub_08A4ABFC, "sub_08A4ABFC");
    runtime.register_function(0x08A4AC68u, &sub_08A4ABFC, "sub_08A4ABFC");
    runtime.register_function(0x08A4AC6Cu, &sub_08A4ABFC, "sub_08A4ABFC");
    runtime.register_function(0x08A4AC70u, &sub_08A4ABFC, "sub_08A4ABFC");
    runtime.register_function(0x08A4AC78u, &sub_08A4ABFC, "sub_08A4ABFC");
    runtime.register_function(0x08A4AC7Cu, &sub_08A4ABFC, "sub_08A4ABFC");
    runtime.register_function(0x08A4AC80u, &sub_08A4ABFC, "sub_08A4ABFC");
    runtime.register_function(0x08A4AC88u, &sub_08A4ABFC, "sub_08A4ABFC");
    runtime.register_function(0x08A4AC8Cu, &sub_08A4ABFC, "sub_08A4ABFC");
    runtime.register_function(0x08A4AC94u, &sub_08A4ABFC, "sub_08A4ABFC");
    runtime.register_function(0x08A4AC98u, &sub_08A4ABFC, "sub_08A4ABFC");
    runtime.register_function(0x08A4AC9Cu, &sub_08A4ABFC, "sub_08A4ABFC");
    runtime.register_function(0x08A4ACA0u, &sub_08A4ABFC, "sub_08A4ABFC");
    runtime.register_function(0x08A4ACA8u, &sub_08A4ABFC, "sub_08A4ABFC");
    runtime.register_function(0x08A4ACACu, &sub_08A4ABFC, "sub_08A4ABFC");
    runtime.register_function(0x08A4ACB0u, &sub_08A4ABFC, "sub_08A4ABFC");
    runtime.register_function(0x08A4ACB8u, &sub_08A4ABFC, "sub_08A4ABFC");
    runtime.register_function(0x08A4ACBCu, &sub_08A4ABFC, "sub_08A4ABFC");
    runtime.register_function(0x08A4ACC4u, &sub_08A4ABFC, "sub_08A4ABFC");
    runtime.register_function(0x08A4ACC8u, &sub_08A4ABFC, "sub_08A4ABFC");
    runtime.register_function(0x08A4ACCCu, &sub_08A4ABFC, "sub_08A4ABFC");
    runtime.register_function(0x08A4ACD0u, &sub_08A4ABFC, "sub_08A4ABFC");
    runtime.register_function(0x08A4ACD4u, &sub_08A4ABFC, "sub_08A4ABFC");
    runtime.register_function(0x08A4ACD8u, &sub_08A4ABFC, "sub_08A4ABFC");
    runtime.register_function(0x08A4ACE0u, &sub_08A4ABFC, "sub_08A4ABFC");
    runtime.register_function(0x08A4ACE4u, &sub_08A4ABFC, "sub_08A4ABFC");
    runtime.register_function(0x08A4ACE8u, &sub_08A4ABFC, "sub_08A4ABFC");
    runtime.register_function(0x08A4ACECu, &sub_08A4ABFC, "sub_08A4ABFC");
    runtime.register_function(0x08A4ACF0u, &sub_08A4ABFC, "sub_08A4ABFC");
    runtime.register_function(0x08A4ACF4u, &sub_08A4ABFC, "sub_08A4ABFC");
    runtime.register_function(0x08A4D4DCu, &sub_08A4D4DC, "sub_08A4D4DC");
    runtime.register_function(0x08A4D4E0u, &sub_08A4D4DC, "sub_08A4D4DC");
    runtime.register_function(0x08A4D4E4u, &sub_08A4D4DC, "sub_08A4D4DC");
    runtime.register_function(0x08A4D4E8u, &sub_08A4D4DC, "sub_08A4D4DC");
    runtime.register_function(0x08A4D4ECu, &sub_08A4D4DC, "sub_08A4D4DC");
    runtime.register_function(0x08A4D4F0u, &sub_08A4D4DC, "sub_08A4D4DC");
    runtime.register_function(0x08A4D4F4u, &sub_08A4D4DC, "sub_08A4D4DC");
    runtime.register_function(0x08A4D4F8u, &sub_08A4D4DC, "sub_08A4D4DC");
    runtime.register_function(0x08A4D4FCu, &sub_08A4D4DC, "sub_08A4D4DC");
    runtime.register_function(0x08A4D504u, &sub_08A4D4DC, "sub_08A4D4DC");
    runtime.register_function(0x08A4D508u, &sub_08A4D4DC, "sub_08A4D4DC");
    runtime.register_function(0x08A4D50Cu, &sub_08A4D4DC, "sub_08A4D4DC");
    runtime.register_function(0x08A4D510u, &sub_08A4D4DC, "sub_08A4D4DC");
    runtime.register_function(0x08A4D514u, &sub_08A4D4DC, "sub_08A4D4DC");
    runtime.register_function(0x08A4D518u, &sub_08A4D4DC, "sub_08A4D4DC");
    runtime.register_function(0x08A4D51Cu, &sub_08A4D4DC, "sub_08A4D4DC");
    runtime.register_function(0x08A4D520u, &sub_08A4D4DC, "sub_08A4D4DC");
    runtime.register_function(0x08A4D524u, &sub_08A4D4DC, "sub_08A4D4DC");
    runtime.register_function(0x08A4D528u, &sub_08A4D4DC, "sub_08A4D4DC");
    runtime.register_function(0x08A4D52Cu, &sub_08A4D4DC, "sub_08A4D4DC");
    runtime.register_function(0x08A4D530u, &sub_08A4D4DC, "sub_08A4D4DC");
    runtime.register_function(0x08A4D534u, &sub_08A4D4DC, "sub_08A4D4DC");
    runtime.register_function(0x08A4D538u, &sub_08A4D4DC, "sub_08A4D4DC");
    runtime.register_function(0x08A4D53Cu, &sub_08A4D4DC, "sub_08A4D4DC");
    runtime.register_function(0x08A4D540u, &sub_08A4D4DC, "sub_08A4D4DC");
    runtime.register_function(0x08A4D544u, &sub_08A4D4DC, "sub_08A4D4DC");
    runtime.register_function(0x08A4D548u, &sub_08A4D4DC, "sub_08A4D4DC");
    runtime.register_function(0x08A4D550u, &sub_08A4D4DC, "sub_08A4D4DC");
    runtime.register_function(0x08A4D554u, &sub_08A4D4DC, "sub_08A4D4DC");
    runtime.register_function(0x08A4D558u, &sub_08A4D4DC, "sub_08A4D4DC");
    runtime.register_function(0x08A4D560u, &sub_08A4D4DC, "sub_08A4D4DC");
    runtime.register_function(0x08A4D568u, &sub_08A4D4DC, "sub_08A4D4DC");
    runtime.register_function(0x08A4D570u, &sub_08A4D4DC, "sub_08A4D4DC");
    runtime.register_function(0x08A4D574u, &sub_08A4D4DC, "sub_08A4D4DC");
    runtime.register_function(0x08A4D57Cu, &sub_08A4D4DC, "sub_08A4D4DC");
    runtime.register_function(0x08A4D580u, &sub_08A4D4DC, "sub_08A4D4DC");
    runtime.register_function(0x08A4D584u, &sub_08A4D4DC, "sub_08A4D4DC");
    runtime.register_function(0x08A4D588u, &sub_08A4D4DC, "sub_08A4D4DC");
    runtime.register_function(0x08A4D58Cu, &sub_08A4D4DC, "sub_08A4D4DC");
    runtime.register_function(0x08A4D590u, &sub_08A4D4DC, "sub_08A4D4DC");
    runtime.register_function(0x08A4D594u, &sub_08A4D4DC, "sub_08A4D4DC");
    runtime.register_function(0x08A4D59Cu, &sub_08A4D4DC, "sub_08A4D4DC");
    runtime.register_function(0x08A4D5A0u, &sub_08A4D4DC, "sub_08A4D4DC");
    runtime.register_function(0x08A4D5A8u, &sub_08A4D4DC, "sub_08A4D4DC");
    runtime.register_function(0x08A4D5ACu, &sub_08A4D4DC, "sub_08A4D4DC");
    runtime.register_function(0x08A4D5B0u, &sub_08A4D4DC, "sub_08A4D4DC");
    runtime.register_function(0x08A4D5B4u, &sub_08A4D4DC, "sub_08A4D4DC");
    runtime.register_function(0x08A4D5B8u, &sub_08A4D4DC, "sub_08A4D4DC");
    runtime.register_function(0x08A4D5BCu, &sub_08A4D4DC, "sub_08A4D4DC");
    runtime.register_function(0x08A4D5C4u, &sub_08A4D4DC, "sub_08A4D4DC");
    runtime.register_function(0x08A4D5C8u, &sub_08A4D4DC, "sub_08A4D4DC");
    runtime.register_function(0x08A4D5D0u, &sub_08A4D4DC, "sub_08A4D4DC");
    runtime.register_function(0x08A4D5D4u, &sub_08A4D4DC, "sub_08A4D4DC");
    runtime.register_function(0x08A4D5D8u, &sub_08A4D4DC, "sub_08A4D4DC");
    runtime.register_function(0x08A500A8u, &sub_08A500A8, "sub_08A500A8");
    runtime.register_function(0x08A500ACu, &sub_08A500A8, "sub_08A500A8");
    runtime.register_function(0x08A500B0u, &sub_08A500A8, "sub_08A500A8");
    runtime.register_function(0x08A500B4u, &sub_08A500A8, "sub_08A500A8");
    runtime.register_function(0x08A500B8u, &sub_08A500A8, "sub_08A500A8");
    runtime.register_function(0x08A500BCu, &sub_08A500A8, "sub_08A500A8");
    runtime.register_function(0x08A500C0u, &sub_08A500A8, "sub_08A500A8");
    runtime.register_function(0x08A500C4u, &sub_08A500A8, "sub_08A500A8");
    runtime.register_function(0x08A500C8u, &sub_08A500A8, "sub_08A500A8");
    runtime.register_function(0x08A500D0u, &sub_08A500A8, "sub_08A500A8");
    runtime.register_function(0x08A500D8u, &sub_08A500A8, "sub_08A500A8");
    runtime.register_function(0x08A500DCu, &sub_08A500A8, "sub_08A500A8");
    runtime.register_function(0x08A500E0u, &sub_08A500A8, "sub_08A500A8");
    runtime.register_function(0x08A500E4u, &sub_08A500A8, "sub_08A500A8");
    runtime.register_function(0x08A500ECu, &sub_08A500A8, "sub_08A500A8");
    runtime.register_function(0x08A500F0u, &sub_08A500A8, "sub_08A500A8");
    runtime.register_function(0x08A500F4u, &sub_08A500A8, "sub_08A500A8");
    runtime.register_function(0x08A500FCu, &sub_08A500A8, "sub_08A500A8");
    runtime.register_function(0x08A50104u, &sub_08A500A8, "sub_08A500A8");
    runtime.register_function(0x08A5010Cu, &sub_08A500A8, "sub_08A500A8");
    runtime.register_function(0x08A50110u, &sub_08A500A8, "sub_08A500A8");
    runtime.register_function(0x08A50118u, &sub_08A500A8, "sub_08A500A8");
    runtime.register_function(0x08A5011Cu, &sub_08A500A8, "sub_08A500A8");
    runtime.register_function(0x08A50120u, &sub_08A500A8, "sub_08A500A8");
    runtime.register_function(0x08A50124u, &sub_08A500A8, "sub_08A500A8");
    runtime.register_function(0x08A50128u, &sub_08A500A8, "sub_08A500A8");
    runtime.register_function(0x08A5012Cu, &sub_08A500A8, "sub_08A500A8");
    runtime.register_function(0x08A50134u, &sub_08A500A8, "sub_08A500A8");
    runtime.register_function(0x08A50138u, &sub_08A500A8, "sub_08A500A8");
    runtime.register_function(0x08A5013Cu, &sub_08A500A8, "sub_08A500A8");
    runtime.register_function(0x08A50140u, &sub_08A500A8, "sub_08A500A8");
    runtime.register_function(0x08A50144u, &sub_08A500A8, "sub_08A500A8");
    runtime.register_function(0x08A50148u, &sub_08A500A8, "sub_08A500A8");
    runtime.register_function(0x08A5014Cu, &sub_08A500A8, "sub_08A500A8");
    runtime.register_function(0x08A50154u, &sub_08A500A8, "sub_08A500A8");
    runtime.register_function(0x08A50158u, &sub_08A500A8, "sub_08A500A8");
    runtime.register_function(0x08A50160u, &sub_08A500A8, "sub_08A500A8");
    runtime.register_function(0x08A50164u, &sub_08A500A8, "sub_08A500A8");
    runtime.register_function(0x08A50168u, &sub_08A500A8, "sub_08A500A8");
    runtime.register_function(0x08A5016Cu, &sub_08A500A8, "sub_08A500A8");
    runtime.register_function(0x08A50170u, &sub_08A500A8, "sub_08A500A8");
    runtime.register_function(0x08A50174u, &sub_08A500A8, "sub_08A500A8");
    runtime.register_function(0x08A50178u, &sub_08A500A8, "sub_08A500A8");
    runtime.register_function(0x08A50180u, &sub_08A500A8, "sub_08A500A8");
    runtime.register_function(0x08A50184u, &sub_08A500A8, "sub_08A500A8");
    runtime.register_function(0x08A5018Cu, &sub_08A500A8, "sub_08A500A8");
    runtime.register_function(0x08A50190u, &sub_08A500A8, "sub_08A500A8");
    runtime.register_function(0x08A50194u, &sub_08A500A8, "sub_08A500A8");
    runtime.register_function(0x08A50198u, &sub_08A500A8, "sub_08A500A8");
    runtime.register_function(0x08A501A0u, &sub_08A500A8, "sub_08A500A8");
    runtime.register_function(0x08A501A4u, &sub_08A500A8, "sub_08A500A8");
    runtime.register_function(0x08A6CBFCu, &sub_08A6CBFC, "sub_08A6CBFC");
    runtime.register_function(0x08A6CC00u, &sub_08A6CBFC, "sub_08A6CBFC");
    runtime.register_function(0x08A6CC04u, &sub_08A6CBFC, "sub_08A6CBFC");
    runtime.register_function(0x08A6CC08u, &sub_08A6CBFC, "sub_08A6CBFC");
    runtime.register_function(0x08A6CC0Cu, &sub_08A6CBFC, "sub_08A6CBFC");
    runtime.register_function(0x08A6CC10u, &sub_08A6CBFC, "sub_08A6CBFC");
    runtime.register_function(0x08A6CC14u, &sub_08A6CBFC, "sub_08A6CBFC");
    runtime.register_function(0x08A6CC18u, &sub_08A6CBFC, "sub_08A6CBFC");
    runtime.register_function(0x08A6CC1Cu, &sub_08A6CBFC, "sub_08A6CBFC");
    runtime.register_function(0x08A6CC24u, &sub_08A6CBFC, "sub_08A6CBFC");
    runtime.register_function(0x08A6CC28u, &sub_08A6CBFC, "sub_08A6CBFC");
    runtime.register_function(0x08A6CC2Cu, &sub_08A6CBFC, "sub_08A6CBFC");
    runtime.register_function(0x08A6CC30u, &sub_08A6CBFC, "sub_08A6CBFC");
    runtime.register_function(0x08A6CC34u, &sub_08A6CBFC, "sub_08A6CBFC");
    runtime.register_function(0x08A6CC38u, &sub_08A6CBFC, "sub_08A6CBFC");
    runtime.register_function(0x08A6CC40u, &sub_08A6CBFC, "sub_08A6CBFC");
    runtime.register_function(0x08A6CC48u, &sub_08A6CBFC, "sub_08A6CBFC");
    runtime.register_function(0x08A6CC50u, &sub_08A6CBFC, "sub_08A6CBFC");
    runtime.register_function(0x08A6CC54u, &sub_08A6CBFC, "sub_08A6CBFC");
    runtime.register_function(0x08A6CC58u, &sub_08A6CBFC, "sub_08A6CBFC");
    runtime.register_function(0x08A6CC5Cu, &sub_08A6CBFC, "sub_08A6CBFC");
    runtime.register_function(0x08A6CC60u, &sub_08A6CBFC, "sub_08A6CBFC");
    runtime.register_function(0x08A6CC64u, &sub_08A6CBFC, "sub_08A6CBFC");
    runtime.register_function(0x08A6CC68u, &sub_08A6CBFC, "sub_08A6CBFC");
    runtime.register_function(0x08A6CC6Cu, &sub_08A6CBFC, "sub_08A6CBFC");
    runtime.register_function(0x08A6CC70u, &sub_08A6CBFC, "sub_08A6CBFC");
    runtime.register_function(0x08A6CC74u, &sub_08A6CBFC, "sub_08A6CBFC");
    runtime.register_function(0x08A6CC78u, &sub_08A6CBFC, "sub_08A6CBFC");
    runtime.register_function(0x08A6CC7Cu, &sub_08A6CBFC, "sub_08A6CBFC");
    runtime.register_function(0x08A6CC80u, &sub_08A6CBFC, "sub_08A6CBFC");
    runtime.register_function(0x08A6CC84u, &sub_08A6CBFC, "sub_08A6CBFC");
    runtime.register_function(0x08A6CC88u, &sub_08A6CBFC, "sub_08A6CBFC");
    runtime.register_function(0x08A6CC8Cu, &sub_08A6CBFC, "sub_08A6CBFC");
    runtime.register_function(0x08A6CC90u, &sub_08A6CBFC, "sub_08A6CBFC");
    runtime.register_function(0x08A6CC94u, &sub_08A6CBFC, "sub_08A6CBFC");
    runtime.register_function(0x08A6CC98u, &sub_08A6CBFC, "sub_08A6CBFC");
    runtime.register_function(0x08A6CC9Cu, &sub_08A6CBFC, "sub_08A6CBFC");
    runtime.register_function(0x08A6CCA4u, &sub_08A6CBFC, "sub_08A6CBFC");
    runtime.register_function(0x08A6CCA8u, &sub_08A6CBFC, "sub_08A6CBFC");
    runtime.register_function(0x08A6CCACu, &sub_08A6CBFC, "sub_08A6CBFC");
    runtime.register_function(0x08A6CCB0u, &sub_08A6CBFC, "sub_08A6CBFC");
    runtime.register_function(0x08A6CCB4u, &sub_08A6CBFC, "sub_08A6CBFC");
    runtime.register_function(0x08A6CCB8u, &sub_08A6CBFC, "sub_08A6CBFC");
    runtime.register_function(0x08A6CCBCu, &sub_08A6CBFC, "sub_08A6CBFC");
    runtime.register_function(0x08A6CCC0u, &sub_08A6CBFC, "sub_08A6CBFC");
    runtime.register_function(0x08A6CCC8u, &sub_08A6CBFC, "sub_08A6CBFC");
    runtime.register_function(0x08A6CCD0u, &sub_08A6CBFC, "sub_08A6CBFC");
    runtime.register_function(0x08A6CCD4u, &sub_08A6CBFC, "sub_08A6CBFC");
    runtime.register_function(0x08A6CCD8u, &sub_08A6CBFC, "sub_08A6CBFC");
    runtime.register_function(0x08A6CCDCu, &sub_08A6CBFC, "sub_08A6CBFC");
    runtime.register_function(0x08A6CCE0u, &sub_08A6CBFC, "sub_08A6CBFC");
    runtime.register_function(0x08A6CCE4u, &sub_08A6CBFC, "sub_08A6CBFC");
    runtime.register_function(0x08A6CCE8u, &sub_08A6CBFC, "sub_08A6CBFC");
    runtime.register_function(0x08A6CCF0u, &sub_08A6CBFC, "sub_08A6CBFC");
    runtime.register_function(0x08A6CCF4u, &sub_08A6CBFC, "sub_08A6CBFC");
    runtime.register_function(0x08A6CCF8u, &sub_08A6CBFC, "sub_08A6CBFC");
    runtime.register_function(0x08A6D7CCu, &sub_08A6D7CC, "sub_08A6D7CC");
    runtime.register_function(0x08A6D7D0u, &sub_08A6D7CC, "sub_08A6D7CC");
    runtime.register_function(0x08A6D7D4u, &sub_08A6D7CC, "sub_08A6D7CC");
    runtime.register_function(0x08A6D7DCu, &sub_08A6D7CC, "sub_08A6D7CC");
    runtime.register_function(0x08A6D7E0u, &sub_08A6D7CC, "sub_08A6D7CC");
    runtime.register_function(0x08A6D7E4u, &sub_08A6D7CC, "sub_08A6D7CC");
    runtime.register_function(0x08A6D7E8u, &sub_08A6D7CC, "sub_08A6D7CC");
    runtime.register_function(0x08A6D7ECu, &sub_08A6D7CC, "sub_08A6D7CC");
    runtime.register_function(0x08A6D7F0u, &sub_08A6D7CC, "sub_08A6D7CC");
    runtime.register_function(0x08A6D7F8u, &sub_08A6D7CC, "sub_08A6D7CC");
    runtime.register_function(0x08A6D7FCu, &sub_08A6D7CC, "sub_08A6D7CC");
    runtime.register_function(0x08A6D800u, &sub_08A6D7CC, "sub_08A6D7CC");
    runtime.register_function(0x08A6D808u, &sub_08A6D7CC, "sub_08A6D7CC");
    runtime.register_function(0x08A6D810u, &sub_08A6D7CC, "sub_08A6D7CC");
    runtime.register_function(0x08A6D814u, &sub_08A6D7CC, "sub_08A6D7CC");
    runtime.register_function(0x08A6D81Cu, &sub_08A6D7CC, "sub_08A6D7CC");
    runtime.register_function(0x08A6D820u, &sub_08A6D7CC, "sub_08A6D7CC");
    runtime.register_function(0x08A6D824u, &sub_08A6D7CC, "sub_08A6D7CC");
    runtime.register_function(0x08A6D828u, &sub_08A6D7CC, "sub_08A6D7CC");
    runtime.register_function(0x08A6D82Cu, &sub_08A6D7CC, "sub_08A6D7CC");
    runtime.register_function(0x08A6D834u, &sub_08A6D7CC, "sub_08A6D7CC");
    runtime.register_function(0x08A6D83Cu, &sub_08A6D7CC, "sub_08A6D7CC");
    runtime.register_function(0x08A6D844u, &sub_08A6D7CC, "sub_08A6D7CC");
    runtime.register_function(0x08A6D84Cu, &sub_08A6D7CC, "sub_08A6D7CC");
    runtime.register_function(0x08A6D854u, &sub_08A6D7CC, "sub_08A6D7CC");
    runtime.register_function(0x08A6D858u, &sub_08A6D7CC, "sub_08A6D7CC");
    runtime.register_function(0x08A6D85Cu, &sub_08A6D7CC, "sub_08A6D7CC");
    runtime.register_function(0x08A6D860u, &sub_08A6D7CC, "sub_08A6D7CC");
    runtime.register_function(0x08A6D864u, &sub_08A6D7CC, "sub_08A6D7CC");
    runtime.register_function(0x08A6D868u, &sub_08A6D7CC, "sub_08A6D7CC");
    runtime.register_function(0x08A6D86Cu, &sub_08A6D7CC, "sub_08A6D7CC");
    runtime.register_function(0x08A6D870u, &sub_08A6D7CC, "sub_08A6D7CC");
    runtime.register_function(0x08A6D878u, &sub_08A6D7CC, "sub_08A6D7CC");
    runtime.register_function(0x08A6D87Cu, &sub_08A6D7CC, "sub_08A6D7CC");
    runtime.register_function(0x08A6D880u, &sub_08A6D7CC, "sub_08A6D7CC");
    runtime.register_function(0x08A6D888u, &sub_08A6D7CC, "sub_08A6D7CC");
    runtime.register_function(0x08A6D88Cu, &sub_08A6D7CC, "sub_08A6D7CC");
    runtime.register_function(0x08A6D890u, &sub_08A6D7CC, "sub_08A6D7CC");
    runtime.register_function(0x08A6D894u, &sub_08A6D7CC, "sub_08A6D7CC");
    runtime.register_function(0x08A6D898u, &sub_08A6D7CC, "sub_08A6D7CC");
    runtime.register_function(0x08A6D89Cu, &sub_08A6D7CC, "sub_08A6D7CC");
    runtime.register_function(0x08A6D8A4u, &sub_08A6D7CC, "sub_08A6D7CC");
    runtime.register_function(0x08A6D8ACu, &sub_08A6D7CC, "sub_08A6D7CC");
    runtime.register_function(0x08A6D8B0u, &sub_08A6D7CC, "sub_08A6D7CC");
    runtime.register_function(0x08A6D8B4u, &sub_08A6D7CC, "sub_08A6D7CC");
    runtime.register_function(0x08A6D8B8u, &sub_08A6D7CC, "sub_08A6D7CC");
    runtime.register_function(0x08A6D8BCu, &sub_08A6D7CC, "sub_08A6D7CC");
    runtime.register_function(0x08A6D8C0u, &sub_08A6D7CC, "sub_08A6D7CC");
    runtime.register_function(0x08A6D8C4u, &sub_08A6D7CC, "sub_08A6D7CC");
    runtime.register_function(0x08A6D8C8u, &sub_08A6D7CC, "sub_08A6D7CC");
    runtime.register_function(0x08A87428u, &sub_08A87428, "sub_08A87428");
    runtime.register_function(0x08A8742Cu, &sub_08A87428, "sub_08A87428");
    runtime.register_function(0x08A87430u, &sub_08A87428, "sub_08A87428");
    runtime.register_function(0x08A87434u, &sub_08A87428, "sub_08A87428");
    runtime.register_function(0x08A87438u, &sub_08A87428, "sub_08A87428");
    runtime.register_function(0x08A8743Cu, &sub_08A87428, "sub_08A87428");
    runtime.register_function(0x08A87440u, &sub_08A87428, "sub_08A87428");
    runtime.register_function(0x08A87444u, &sub_08A87428, "sub_08A87428");
    runtime.register_function(0x08A87448u, &sub_08A87428, "sub_08A87428");
    runtime.register_function(0x08A87450u, &sub_08A87428, "sub_08A87428");
    runtime.register_function(0x08A87454u, &sub_08A87428, "sub_08A87428");
    runtime.register_function(0x08A87458u, &sub_08A87428, "sub_08A87428");
    runtime.register_function(0x08A8745Cu, &sub_08A87428, "sub_08A87428");
    runtime.register_function(0x08A87464u, &sub_08A87428, "sub_08A87428");
    runtime.register_function(0x08A87468u, &sub_08A87428, "sub_08A87428");
    runtime.register_function(0x08A8746Cu, &sub_08A87428, "sub_08A87428");
    runtime.register_function(0x08A87474u, &sub_08A87428, "sub_08A87428");
    runtime.register_function(0x08A8747Cu, &sub_08A87428, "sub_08A87428");
    runtime.register_function(0x08A87484u, &sub_08A87428, "sub_08A87428");
    runtime.register_function(0x08A87488u, &sub_08A87428, "sub_08A87428");
    runtime.register_function(0x08A87490u, &sub_08A87428, "sub_08A87428");
    runtime.register_function(0x08A87494u, &sub_08A87428, "sub_08A87428");
    runtime.register_function(0x08A87498u, &sub_08A87428, "sub_08A87428");
    runtime.register_function(0x08A8749Cu, &sub_08A87428, "sub_08A87428");
    runtime.register_function(0x08A874A0u, &sub_08A87428, "sub_08A87428");
    runtime.register_function(0x08A874A4u, &sub_08A87428, "sub_08A87428");
    runtime.register_function(0x08A874ACu, &sub_08A87428, "sub_08A87428");
    runtime.register_function(0x08A874B0u, &sub_08A87428, "sub_08A87428");
    runtime.register_function(0x08A874B4u, &sub_08A87428, "sub_08A87428");
    runtime.register_function(0x08A874B8u, &sub_08A87428, "sub_08A87428");
    runtime.register_function(0x08A874BCu, &sub_08A87428, "sub_08A87428");
    runtime.register_function(0x08A874C0u, &sub_08A87428, "sub_08A87428");
    runtime.register_function(0x08A874C8u, &sub_08A87428, "sub_08A87428");
    runtime.register_function(0x08A874CCu, &sub_08A87428, "sub_08A87428");
    runtime.register_function(0x08A874D0u, &sub_08A87428, "sub_08A87428");
    runtime.register_function(0x08A874D4u, &sub_08A87428, "sub_08A87428");
    runtime.register_function(0x08A874D8u, &sub_08A87428, "sub_08A87428");
    runtime.register_function(0x08A874E0u, &sub_08A87428, "sub_08A87428");
    runtime.register_function(0x08A874E4u, &sub_08A87428, "sub_08A87428");
    runtime.register_function(0x08A874ECu, &sub_08A87428, "sub_08A87428");
    runtime.register_function(0x08A874F0u, &sub_08A87428, "sub_08A87428");
    runtime.register_function(0x08A874F4u, &sub_08A87428, "sub_08A87428");
    runtime.register_function(0x08A874FCu, &sub_08A87428, "sub_08A87428");
    runtime.register_function(0x08A87500u, &sub_08A87428, "sub_08A87428");
    runtime.register_function(0x08A87504u, &sub_08A87428, "sub_08A87428");
    runtime.register_function(0x08A87508u, &sub_08A87428, "sub_08A87428");
    runtime.register_function(0x08A8750Cu, &sub_08A87428, "sub_08A87428");
    runtime.register_function(0x08A87510u, &sub_08A87428, "sub_08A87428");
    runtime.register_function(0x08A87518u, &sub_08A87428, "sub_08A87428");
    runtime.register_function(0x08A8751Cu, &sub_08A87428, "sub_08A87428");
    runtime.register_function(0x08A87520u, &sub_08A87428, "sub_08A87428");
    runtime.register_function(0x08A8A194u, &sub_08A8A194, "sub_08A8A194");
    runtime.register_function(0x08A8A198u, &sub_08A8A194, "sub_08A8A194");
    runtime.register_function(0x08A8A19Cu, &sub_08A8A194, "sub_08A8A194");
    runtime.register_function(0x08A8A1A0u, &sub_08A8A194, "sub_08A8A194");
    runtime.register_function(0x08A8A1A4u, &sub_08A8A194, "sub_08A8A194");
    runtime.register_function(0x08A8A1A8u, &sub_08A8A194, "sub_08A8A194");
    runtime.register_function(0x08A8A1ACu, &sub_08A8A194, "sub_08A8A194");
    runtime.register_function(0x08A8A1B0u, &sub_08A8A194, "sub_08A8A194");
    runtime.register_function(0x08A8A1B4u, &sub_08A8A194, "sub_08A8A194");
    runtime.register_function(0x08A8A1BCu, &sub_08A8A194, "sub_08A8A194");
    runtime.register_function(0x08A8A1C0u, &sub_08A8A194, "sub_08A8A194");
    runtime.register_function(0x08A8A1C4u, &sub_08A8A194, "sub_08A8A194");
    runtime.register_function(0x08A8A1C8u, &sub_08A8A194, "sub_08A8A194");
    runtime.register_function(0x08A8A1D0u, &sub_08A8A194, "sub_08A8A194");
    runtime.register_function(0x08A8A1D4u, &sub_08A8A194, "sub_08A8A194");
    runtime.register_function(0x08A8A1D8u, &sub_08A8A194, "sub_08A8A194");
    runtime.register_function(0x08A8A1E0u, &sub_08A8A194, "sub_08A8A194");
    runtime.register_function(0x08A8A1E8u, &sub_08A8A194, "sub_08A8A194");
    runtime.register_function(0x08A8A1F0u, &sub_08A8A194, "sub_08A8A194");
    runtime.register_function(0x08A8A1F4u, &sub_08A8A194, "sub_08A8A194");
    runtime.register_function(0x08A8A1FCu, &sub_08A8A194, "sub_08A8A194");
    runtime.register_function(0x08A8A200u, &sub_08A8A194, "sub_08A8A194");
    runtime.register_function(0x08A8A204u, &sub_08A8A194, "sub_08A8A194");
    runtime.register_function(0x08A8A208u, &sub_08A8A194, "sub_08A8A194");
    runtime.register_function(0x08A8A20Cu, &sub_08A8A194, "sub_08A8A194");
    runtime.register_function(0x08A8A210u, &sub_08A8A194, "sub_08A8A194");
    runtime.register_function(0x08A8A214u, &sub_08A8A194, "sub_08A8A194");
    runtime.register_function(0x08A8A21Cu, &sub_08A8A194, "sub_08A8A194");
    runtime.register_function(0x08A8A220u, &sub_08A8A194, "sub_08A8A194");
    runtime.register_function(0x08A8A224u, &sub_08A8A194, "sub_08A8A194");
    runtime.register_function(0x08A8A228u, &sub_08A8A194, "sub_08A8A194");
    runtime.register_function(0x08A8A22Cu, &sub_08A8A194, "sub_08A8A194");
    runtime.register_function(0x08A8A230u, &sub_08A8A194, "sub_08A8A194");
    runtime.register_function(0x08A8A234u, &sub_08A8A194, "sub_08A8A194");
    runtime.register_function(0x08A8A23Cu, &sub_08A8A194, "sub_08A8A194");
    runtime.register_function(0x08A8A240u, &sub_08A8A194, "sub_08A8A194");
    runtime.register_function(0x08A8A244u, &sub_08A8A194, "sub_08A8A194");
    runtime.register_function(0x08A8A248u, &sub_08A8A194, "sub_08A8A194");
    runtime.register_function(0x08A8A24Cu, &sub_08A8A194, "sub_08A8A194");
    runtime.register_function(0x08A8A254u, &sub_08A8A194, "sub_08A8A194");
    runtime.register_function(0x08A8A258u, &sub_08A8A194, "sub_08A8A194");
    runtime.register_function(0x08A8A260u, &sub_08A8A194, "sub_08A8A194");
    runtime.register_function(0x08A8A264u, &sub_08A8A194, "sub_08A8A194");
    runtime.register_function(0x08A8A26Cu, &sub_08A8A194, "sub_08A8A194");
    runtime.register_function(0x08A8A270u, &sub_08A8A194, "sub_08A8A194");
    runtime.register_function(0x08A8A278u, &sub_08A8A194, "sub_08A8A194");
    runtime.register_function(0x08A8A27Cu, &sub_08A8A194, "sub_08A8A194");
    runtime.register_function(0x08A8A284u, &sub_08A8A194, "sub_08A8A194");
    runtime.register_function(0x08A8A28Cu, &sub_08A8A194, "sub_08A8A194");
    runtime.register_function(0x08A969CCu, &sub_08A969CC, "sub_08A969CC");
    runtime.register_function(0x08A969D4u, &sub_08A969CC, "sub_08A969CC");
    runtime.register_function(0x08A969D8u, &sub_08A969CC, "sub_08A969CC");
    runtime.register_function(0x08A969DCu, &sub_08A969CC, "sub_08A969CC");
    runtime.register_function(0x08A969E0u, &sub_08A969CC, "sub_08A969CC");
    runtime.register_function(0x08A969E8u, &sub_08A969CC, "sub_08A969CC");
    runtime.register_function(0x08A969ECu, &sub_08A969CC, "sub_08A969CC");
    runtime.register_function(0x08A969F0u, &sub_08A969CC, "sub_08A969CC");
    runtime.register_function(0x08A969F4u, &sub_08A969CC, "sub_08A969CC");
    runtime.register_function(0x08A969FCu, &sub_08A969CC, "sub_08A969CC");
    runtime.register_function(0x08A96A00u, &sub_08A969CC, "sub_08A969CC");
    runtime.register_function(0x08A96A08u, &sub_08A969CC, "sub_08A969CC");
    runtime.register_function(0x08A96A0Cu, &sub_08A969CC, "sub_08A969CC");
    runtime.register_function(0x08A96A10u, &sub_08A969CC, "sub_08A969CC");
    runtime.register_function(0x08A96A14u, &sub_08A969CC, "sub_08A969CC");
    runtime.register_function(0x08A96A1Cu, &sub_08A969CC, "sub_08A969CC");
    runtime.register_function(0x08A96A20u, &sub_08A969CC, "sub_08A969CC");
    runtime.register_function(0x08A96A28u, &sub_08A969CC, "sub_08A969CC");
    runtime.register_function(0x08A96A2Cu, &sub_08A969CC, "sub_08A969CC");
    runtime.register_function(0x08A96A30u, &sub_08A969CC, "sub_08A969CC");
    runtime.register_function(0x08A96A34u, &sub_08A969CC, "sub_08A969CC");
    runtime.register_function(0x08A96A3Cu, &sub_08A969CC, "sub_08A969CC");
    runtime.register_function(0x08A96A40u, &sub_08A969CC, "sub_08A969CC");
    runtime.register_function(0x08A96A44u, &sub_08A969CC, "sub_08A969CC");
    runtime.register_function(0x08A96A4Cu, &sub_08A969CC, "sub_08A969CC");
    runtime.register_function(0x08A96A54u, &sub_08A969CC, "sub_08A969CC");
    runtime.register_function(0x08A96A5Cu, &sub_08A969CC, "sub_08A969CC");
    runtime.register_function(0x08A96A60u, &sub_08A969CC, "sub_08A969CC");
    runtime.register_function(0x08A96A68u, &sub_08A969CC, "sub_08A969CC");
    runtime.register_function(0x08A96A6Cu, &sub_08A969CC, "sub_08A969CC");
    runtime.register_function(0x08A96A70u, &sub_08A969CC, "sub_08A969CC");
    runtime.register_function(0x08A96A74u, &sub_08A969CC, "sub_08A969CC");
    runtime.register_function(0x08A96A7Cu, &sub_08A969CC, "sub_08A969CC");
    runtime.register_function(0x08A96A80u, &sub_08A969CC, "sub_08A969CC");
    runtime.register_function(0x08A96A88u, &sub_08A969CC, "sub_08A969CC");
    runtime.register_function(0x08A96A8Cu, &sub_08A969CC, "sub_08A969CC");
    runtime.register_function(0x08A96A90u, &sub_08A969CC, "sub_08A969CC");
    runtime.register_function(0x08A96A94u, &sub_08A969CC, "sub_08A969CC");
    runtime.register_function(0x08A96A98u, &sub_08A969CC, "sub_08A969CC");
    runtime.register_function(0x08A96A9Cu, &sub_08A969CC, "sub_08A969CC");
    runtime.register_function(0x08A96AA0u, &sub_08A969CC, "sub_08A969CC");
    runtime.register_function(0x08A96AA8u, &sub_08A969CC, "sub_08A969CC");
    runtime.register_function(0x08A96AACu, &sub_08A969CC, "sub_08A969CC");
    runtime.register_function(0x08A96AB0u, &sub_08A969CC, "sub_08A969CC");
    runtime.register_function(0x08A96AB4u, &sub_08A969CC, "sub_08A969CC");
    runtime.register_function(0x08A96AB8u, &sub_08A969CC, "sub_08A969CC");
    runtime.register_function(0x08A96ABCu, &sub_08A969CC, "sub_08A969CC");
    runtime.register_function(0x08A96AC0u, &sub_08A969CC, "sub_08A969CC");
    runtime.register_function(0x08A96AC4u, &sub_08A969CC, "sub_08A969CC");
    runtime.register_function(0x08A9CBDCu, &sub_08A9CBDC, "sub_08A9CBDC");
    runtime.register_function(0x08A9CBE0u, &sub_08A9CBDC, "sub_08A9CBDC");
    runtime.register_function(0x08A9CBE4u, &sub_08A9CBDC, "sub_08A9CBDC");
    runtime.register_function(0x08A9CBE8u, &sub_08A9CBDC, "sub_08A9CBDC");
    runtime.register_function(0x08A9CBECu, &sub_08A9CBDC, "sub_08A9CBDC");
    runtime.register_function(0x08A9CBF0u, &sub_08A9CBDC, "sub_08A9CBDC");
    runtime.register_function(0x08A9CBF4u, &sub_08A9CBDC, "sub_08A9CBDC");
    runtime.register_function(0x08A9CBF8u, &sub_08A9CBDC, "sub_08A9CBDC");
    runtime.register_function(0x08A9CBFCu, &sub_08A9CBDC, "sub_08A9CBDC");
    runtime.register_function(0x08A9CC04u, &sub_08A9CBDC, "sub_08A9CBDC");
    runtime.register_function(0x08A9CC0Cu, &sub_08A9CBDC, "sub_08A9CBDC");
    runtime.register_function(0x08A9CC14u, &sub_08A9CBDC, "sub_08A9CBDC");
    runtime.register_function(0x08A9CC18u, &sub_08A9CBDC, "sub_08A9CBDC");
    runtime.register_function(0x08A9CC1Cu, &sub_08A9CBDC, "sub_08A9CBDC");
    runtime.register_function(0x08A9CC20u, &sub_08A9CBDC, "sub_08A9CBDC");
    runtime.register_function(0x08A9CC28u, &sub_08A9CBDC, "sub_08A9CBDC");
    runtime.register_function(0x08A9CC2Cu, &sub_08A9CBDC, "sub_08A9CBDC");
    runtime.register_function(0x08A9CC30u, &sub_08A9CBDC, "sub_08A9CBDC");
    runtime.register_function(0x08A9CC34u, &sub_08A9CBDC, "sub_08A9CBDC");
    runtime.register_function(0x08A9CC38u, &sub_08A9CBDC, "sub_08A9CBDC");
    runtime.register_function(0x08A9CC3Cu, &sub_08A9CBDC, "sub_08A9CBDC");
    runtime.register_function(0x08A9CC44u, &sub_08A9CBDC, "sub_08A9CBDC");
    runtime.register_function(0x08A9CC48u, &sub_08A9CBDC, "sub_08A9CBDC");
    runtime.register_function(0x08A9CC50u, &sub_08A9CBDC, "sub_08A9CBDC");
    runtime.register_function(0x08A9CC54u, &sub_08A9CBDC, "sub_08A9CBDC");
    runtime.register_function(0x08A9CC5Cu, &sub_08A9CBDC, "sub_08A9CBDC");
    runtime.register_function(0x08A9CC64u, &sub_08A9CBDC, "sub_08A9CBDC");
    runtime.register_function(0x08A9CC68u, &sub_08A9CBDC, "sub_08A9CBDC");
    runtime.register_function(0x08A9CC6Cu, &sub_08A9CBDC, "sub_08A9CBDC");
    runtime.register_function(0x08A9CC70u, &sub_08A9CBDC, "sub_08A9CBDC");
    runtime.register_function(0x08A9CC78u, &sub_08A9CBDC, "sub_08A9CBDC");
    runtime.register_function(0x08A9CC7Cu, &sub_08A9CBDC, "sub_08A9CBDC");
    runtime.register_function(0x08A9CC80u, &sub_08A9CBDC, "sub_08A9CBDC");
    runtime.register_function(0x08A9CC84u, &sub_08A9CBDC, "sub_08A9CBDC");
    runtime.register_function(0x08A9CC88u, &sub_08A9CBDC, "sub_08A9CBDC");
    runtime.register_function(0x08A9CC8Cu, &sub_08A9CBDC, "sub_08A9CBDC");
    runtime.register_function(0x08A9CC90u, &sub_08A9CBDC, "sub_08A9CBDC");
    runtime.register_function(0x08A9CC94u, &sub_08A9CBDC, "sub_08A9CBDC");
    runtime.register_function(0x08A9CC98u, &sub_08A9CBDC, "sub_08A9CBDC");
    runtime.register_function(0x08A9CC9Cu, &sub_08A9CBDC, "sub_08A9CBDC");
    runtime.register_function(0x08A9CCA0u, &sub_08A9CBDC, "sub_08A9CBDC");
    runtime.register_function(0x08A9CCA4u, &sub_08A9CBDC, "sub_08A9CBDC");
    runtime.register_function(0x08A9CCA8u, &sub_08A9CBDC, "sub_08A9CBDC");
    runtime.register_function(0x08A9CCACu, &sub_08A9CBDC, "sub_08A9CBDC");
    runtime.register_function(0x08A9CCB0u, &sub_08A9CBDC, "sub_08A9CBDC");
    runtime.register_function(0x08A9CCB4u, &sub_08A9CBDC, "sub_08A9CBDC");
    runtime.register_function(0x08A9CCB8u, &sub_08A9CBDC, "sub_08A9CBDC");
    runtime.register_function(0x08A9CCBCu, &sub_08A9CBDC, "sub_08A9CBDC");
    runtime.register_function(0x08A9CCC0u, &sub_08A9CBDC, "sub_08A9CBDC");
    runtime.register_function(0x08A9CCC4u, &sub_08A9CBDC, "sub_08A9CBDC");
    runtime.register_function(0x08A9CCC8u, &sub_08A9CBDC, "sub_08A9CBDC");
    runtime.register_function(0x08A9CCCCu, &sub_08A9CBDC, "sub_08A9CBDC");
    runtime.register_function(0x08A9CCD4u, &sub_08A9CBDC, "sub_08A9CBDC");
    runtime.register_function(0x08A9CCD8u, &sub_08A9CBDC, "sub_08A9CBDC");
    runtime.register_function(0x08B1F0BCu, &sub_08B1F0BC, "sub_08B1F0BC");
    runtime.register_function(0x08B1F0C0u, &sub_08B1F0BC, "sub_08B1F0BC");
    runtime.register_function(0x08B1F0C4u, &sub_08B1F0BC, "sub_08B1F0BC");
    runtime.register_function(0x08B1F0C8u, &sub_08B1F0BC, "sub_08B1F0BC");
    runtime.register_function(0x08B1F0CCu, &sub_08B1F0BC, "sub_08B1F0BC");
    runtime.register_function(0x08B1F0D0u, &sub_08B1F0BC, "sub_08B1F0BC");
    runtime.register_function(0x08B1F0D4u, &sub_08B1F0BC, "sub_08B1F0BC");
    runtime.register_function(0x08B1F0D8u, &sub_08B1F0BC, "sub_08B1F0BC");
    runtime.register_function(0x08B1F0DCu, &sub_08B1F0BC, "sub_08B1F0BC");
    runtime.register_function(0x08B1F0E4u, &sub_08B1F0BC, "sub_08B1F0BC");
    runtime.register_function(0x08B1F0E8u, &sub_08B1F0BC, "sub_08B1F0BC");
    runtime.register_function(0x08B1F0ECu, &sub_08B1F0BC, "sub_08B1F0BC");
    runtime.register_function(0x08B1F0F0u, &sub_08B1F0BC, "sub_08B1F0BC");
    runtime.register_function(0x08B1F0F8u, &sub_08B1F0BC, "sub_08B1F0BC");
    runtime.register_function(0x08B1F0FCu, &sub_08B1F0BC, "sub_08B1F0BC");
    runtime.register_function(0x08B1F100u, &sub_08B1F0BC, "sub_08B1F0BC");
    runtime.register_function(0x08B1F108u, &sub_08B1F0BC, "sub_08B1F0BC");
    runtime.register_function(0x08B1F110u, &sub_08B1F0BC, "sub_08B1F0BC");
    runtime.register_function(0x08B1F118u, &sub_08B1F0BC, "sub_08B1F0BC");
    runtime.register_function(0x08B1F11Cu, &sub_08B1F0BC, "sub_08B1F0BC");
    runtime.register_function(0x08B1F124u, &sub_08B1F0BC, "sub_08B1F0BC");
    runtime.register_function(0x08B1F128u, &sub_08B1F0BC, "sub_08B1F0BC");
    runtime.register_function(0x08B1F12Cu, &sub_08B1F0BC, "sub_08B1F0BC");
    runtime.register_function(0x08B1F130u, &sub_08B1F0BC, "sub_08B1F0BC");
    runtime.register_function(0x08B1F134u, &sub_08B1F0BC, "sub_08B1F0BC");
    runtime.register_function(0x08B1F138u, &sub_08B1F0BC, "sub_08B1F0BC");
    runtime.register_function(0x08B1F13Cu, &sub_08B1F0BC, "sub_08B1F0BC");
    runtime.register_function(0x08B1F140u, &sub_08B1F0BC, "sub_08B1F0BC");
    runtime.register_function(0x08B1F144u, &sub_08B1F0BC, "sub_08B1F0BC");
    runtime.register_function(0x08B1F148u, &sub_08B1F0BC, "sub_08B1F0BC");
    runtime.register_function(0x08B1F14Cu, &sub_08B1F0BC, "sub_08B1F0BC");
    runtime.register_function(0x08B1F150u, &sub_08B1F0BC, "sub_08B1F0BC");
    runtime.register_function(0x08B1F158u, &sub_08B1F0BC, "sub_08B1F0BC");
    runtime.register_function(0x08B1F15Cu, &sub_08B1F0BC, "sub_08B1F0BC");
    runtime.register_function(0x08B1F160u, &sub_08B1F0BC, "sub_08B1F0BC");
    runtime.register_function(0x08B1F168u, &sub_08B1F0BC, "sub_08B1F0BC");
    runtime.register_function(0x08B1F16Cu, &sub_08B1F0BC, "sub_08B1F0BC");
    runtime.register_function(0x08B1F170u, &sub_08B1F0BC, "sub_08B1F0BC");
    runtime.register_function(0x08B1F174u, &sub_08B1F0BC, "sub_08B1F0BC");
    runtime.register_function(0x08B1F17Cu, &sub_08B1F0BC, "sub_08B1F0BC");
    runtime.register_function(0x08B1F180u, &sub_08B1F0BC, "sub_08B1F0BC");
    runtime.register_function(0x08B1F184u, &sub_08B1F0BC, "sub_08B1F0BC");
    runtime.register_function(0x08B1F188u, &sub_08B1F0BC, "sub_08B1F0BC");
    runtime.register_function(0x08B1F18Cu, &sub_08B1F0BC, "sub_08B1F0BC");
    runtime.register_function(0x08B1F190u, &sub_08B1F0BC, "sub_08B1F0BC");
    runtime.register_function(0x08B1F194u, &sub_08B1F0BC, "sub_08B1F0BC");
    runtime.register_function(0x08B1F198u, &sub_08B1F0BC, "sub_08B1F0BC");
    runtime.register_function(0x08B1F19Cu, &sub_08B1F0BC, "sub_08B1F0BC");
    runtime.register_function(0x08B1F1A4u, &sub_08B1F0BC, "sub_08B1F0BC");
    runtime.register_function(0x08B1F1A8u, &sub_08B1F0BC, "sub_08B1F0BC");
    runtime.register_function(0x08B1F1B0u, &sub_08B1F0BC, "sub_08B1F0BC");
    runtime.register_function(0x08B1F1B4u, &sub_08B1F0BC, "sub_08B1F0BC");
    runtime.register_function(0x08B1F1B8u, &sub_08B1F0BC, "sub_08B1F0BC");
    runtime.register_function(0x08B0C00Cu, &sub_08B0C00C, "sub_08B0C00C");
    runtime.register_function(0x08B0C010u, &sub_08B0C00C, "sub_08B0C00C");
    runtime.register_function(0x08B0C014u, &sub_08B0C00C, "sub_08B0C00C");
    runtime.register_function(0x08B0C018u, &sub_08B0C00C, "sub_08B0C00C");
    runtime.register_function(0x08B0C01Cu, &sub_08B0C00C, "sub_08B0C00C");
    runtime.register_function(0x08B0C020u, &sub_08B0C00C, "sub_08B0C00C");
    runtime.register_function(0x08B0C024u, &sub_08B0C00C, "sub_08B0C00C");
    runtime.register_function(0x08B0C028u, &sub_08B0C00C, "sub_08B0C00C");
    runtime.register_function(0x08B0C02Cu, &sub_08B0C00C, "sub_08B0C00C");
    runtime.register_function(0x08B0C034u, &sub_08B0C00C, "sub_08B0C00C");
    runtime.register_function(0x08B0C038u, &sub_08B0C00C, "sub_08B0C00C");
    runtime.register_function(0x08B0C03Cu, &sub_08B0C00C, "sub_08B0C00C");
    runtime.register_function(0x08B0C040u, &sub_08B0C00C, "sub_08B0C00C");
    runtime.register_function(0x08B0C048u, &sub_08B0C00C, "sub_08B0C00C");
    runtime.register_function(0x08B0C04Cu, &sub_08B0C00C, "sub_08B0C00C");
    runtime.register_function(0x08B0C050u, &sub_08B0C00C, "sub_08B0C00C");
    runtime.register_function(0x08B0C058u, &sub_08B0C00C, "sub_08B0C00C");
    runtime.register_function(0x08B0C060u, &sub_08B0C00C, "sub_08B0C00C");
    runtime.register_function(0x08B0C068u, &sub_08B0C00C, "sub_08B0C00C");
    runtime.register_function(0x08B0C06Cu, &sub_08B0C00C, "sub_08B0C00C");
    runtime.register_function(0x08B0C074u, &sub_08B0C00C, "sub_08B0C00C");
    runtime.register_function(0x08B0C078u, &sub_08B0C00C, "sub_08B0C00C");
    runtime.register_function(0x08B0C07Cu, &sub_08B0C00C, "sub_08B0C00C");
    runtime.register_function(0x08B0C080u, &sub_08B0C00C, "sub_08B0C00C");
    runtime.register_function(0x08B0C084u, &sub_08B0C00C, "sub_08B0C00C");
    runtime.register_function(0x08B0C088u, &sub_08B0C00C, "sub_08B0C00C");
    runtime.register_function(0x08B0C08Cu, &sub_08B0C00C, "sub_08B0C00C");
    runtime.register_function(0x08B0C090u, &sub_08B0C00C, "sub_08B0C00C");
    runtime.register_function(0x08B0C094u, &sub_08B0C00C, "sub_08B0C00C");
    runtime.register_function(0x08B0C098u, &sub_08B0C00C, "sub_08B0C00C");
    runtime.register_function(0x08B0C09Cu, &sub_08B0C00C, "sub_08B0C00C");
    runtime.register_function(0x08B0C0A0u, &sub_08B0C00C, "sub_08B0C00C");
    runtime.register_function(0x08B0C0A8u, &sub_08B0C00C, "sub_08B0C00C");
    runtime.register_function(0x08B0C0ACu, &sub_08B0C00C, "sub_08B0C00C");
    runtime.register_function(0x08B0C0B0u, &sub_08B0C00C, "sub_08B0C00C");
    runtime.register_function(0x08B0C0B8u, &sub_08B0C00C, "sub_08B0C00C");
    runtime.register_function(0x08B0C0BCu, &sub_08B0C00C, "sub_08B0C00C");
    runtime.register_function(0x08B0C0C0u, &sub_08B0C00C, "sub_08B0C00C");
    runtime.register_function(0x08B0C0C4u, &sub_08B0C00C, "sub_08B0C00C");
    runtime.register_function(0x08B0C0CCu, &sub_08B0C00C, "sub_08B0C00C");
    runtime.register_function(0x08B0C0D0u, &sub_08B0C00C, "sub_08B0C00C");
    runtime.register_function(0x08B0C0D4u, &sub_08B0C00C, "sub_08B0C00C");
    runtime.register_function(0x08B0C0D8u, &sub_08B0C00C, "sub_08B0C00C");
    runtime.register_function(0x08B0C0DCu, &sub_08B0C00C, "sub_08B0C00C");
    runtime.register_function(0x08B0C0E0u, &sub_08B0C00C, "sub_08B0C00C");
    runtime.register_function(0x08B0C0E4u, &sub_08B0C00C, "sub_08B0C00C");
    runtime.register_function(0x08B0C0E8u, &sub_08B0C00C, "sub_08B0C00C");
    runtime.register_function(0x08B0C0ECu, &sub_08B0C00C, "sub_08B0C00C");
    runtime.register_function(0x08B0C0F0u, &sub_08B0C00C, "sub_08B0C00C");
    runtime.register_function(0x08B0C0F8u, &sub_08B0C00C, "sub_08B0C00C");
    runtime.register_function(0x08B0C0FCu, &sub_08B0C00C, "sub_08B0C00C");
    runtime.register_function(0x08B0C104u, &sub_08B0C00C, "sub_08B0C00C");
    runtime.register_function(0x08B0C108u, &sub_08B0C00C, "sub_08B0C00C");
    runtime.register_function(0x08AB9C18u, &sub_08AB9C18, "sub_08AB9C18");
    runtime.register_function(0x08AB9C1Cu, &sub_08AB9C18, "sub_08AB9C18");
    runtime.register_function(0x08AB9C20u, &sub_08AB9C18, "sub_08AB9C18");
    runtime.register_function(0x08AB9C24u, &sub_08AB9C18, "sub_08AB9C18");
    runtime.register_function(0x08AB9C28u, &sub_08AB9C18, "sub_08AB9C18");
    runtime.register_function(0x08AB9C2Cu, &sub_08AB9C18, "sub_08AB9C18");
    runtime.register_function(0x08AB9C30u, &sub_08AB9C18, "sub_08AB9C18");
    runtime.register_function(0x08AB9C34u, &sub_08AB9C18, "sub_08AB9C18");
    runtime.register_function(0x08AB9C38u, &sub_08AB9C18, "sub_08AB9C18");
    runtime.register_function(0x08AB9C40u, &sub_08AB9C18, "sub_08AB9C18");
    runtime.register_function(0x08AB9C44u, &sub_08AB9C18, "sub_08AB9C18");
    runtime.register_function(0x08AB9C48u, &sub_08AB9C18, "sub_08AB9C18");
    runtime.register_function(0x08AB9C4Cu, &sub_08AB9C18, "sub_08AB9C18");
    runtime.register_function(0x08AB9C54u, &sub_08AB9C18, "sub_08AB9C18");
    runtime.register_function(0x08AB9C58u, &sub_08AB9C18, "sub_08AB9C18");
    runtime.register_function(0x08AB9C5Cu, &sub_08AB9C18, "sub_08AB9C18");
    runtime.register_function(0x08AB9C64u, &sub_08AB9C18, "sub_08AB9C18");
    runtime.register_function(0x08AB9C6Cu, &sub_08AB9C18, "sub_08AB9C18");
    runtime.register_function(0x08AB9C74u, &sub_08AB9C18, "sub_08AB9C18");
    runtime.register_function(0x08AB9C78u, &sub_08AB9C18, "sub_08AB9C18");
    runtime.register_function(0x08AB9C80u, &sub_08AB9C18, "sub_08AB9C18");
    runtime.register_function(0x08AB9C84u, &sub_08AB9C18, "sub_08AB9C18");
    runtime.register_function(0x08AB9C88u, &sub_08AB9C18, "sub_08AB9C18");
    runtime.register_function(0x08AB9C8Cu, &sub_08AB9C18, "sub_08AB9C18");
    runtime.register_function(0x08AB9C90u, &sub_08AB9C18, "sub_08AB9C18");
    runtime.register_function(0x08AB9C94u, &sub_08AB9C18, "sub_08AB9C18");
    runtime.register_function(0x08AB9C9Cu, &sub_08AB9C18, "sub_08AB9C18");
    runtime.register_function(0x08AB9CA0u, &sub_08AB9C18, "sub_08AB9C18");
    runtime.register_function(0x08AB9CA4u, &sub_08AB9C18, "sub_08AB9C18");
    runtime.register_function(0x08AB9CA8u, &sub_08AB9C18, "sub_08AB9C18");
    runtime.register_function(0x08AB9CACu, &sub_08AB9C18, "sub_08AB9C18");
    runtime.register_function(0x08AB9CB0u, &sub_08AB9C18, "sub_08AB9C18");
    runtime.register_function(0x08AB9CB8u, &sub_08AB9C18, "sub_08AB9C18");
    runtime.register_function(0x08AB9CBCu, &sub_08AB9C18, "sub_08AB9C18");
    runtime.register_function(0x08AB9CC0u, &sub_08AB9C18, "sub_08AB9C18");
    runtime.register_function(0x08AB9CC4u, &sub_08AB9C18, "sub_08AB9C18");
    runtime.register_function(0x08AB9CC8u, &sub_08AB9C18, "sub_08AB9C18");
    runtime.register_function(0x08AB9CCCu, &sub_08AB9C18, "sub_08AB9C18");
    runtime.register_function(0x08AB9CD0u, &sub_08AB9C18, "sub_08AB9C18");
    runtime.register_function(0x08AB9CD8u, &sub_08AB9C18, "sub_08AB9C18");
    runtime.register_function(0x08AB9CDCu, &sub_08AB9C18, "sub_08AB9C18");
    runtime.register_function(0x08AB9CE0u, &sub_08AB9C18, "sub_08AB9C18");
    runtime.register_function(0x08AB9CE4u, &sub_08AB9C18, "sub_08AB9C18");
    runtime.register_function(0x08AB9CE8u, &sub_08AB9C18, "sub_08AB9C18");
    runtime.register_function(0x08AB9CECu, &sub_08AB9C18, "sub_08AB9C18");
    runtime.register_function(0x08AB9CF0u, &sub_08AB9C18, "sub_08AB9C18");
    runtime.register_function(0x08AB9CF4u, &sub_08AB9C18, "sub_08AB9C18");
    runtime.register_function(0x08AB9CF8u, &sub_08AB9C18, "sub_08AB9C18");
    runtime.register_function(0x08AB9D00u, &sub_08AB9C18, "sub_08AB9C18");
    runtime.register_function(0x08AB9D04u, &sub_08AB9C18, "sub_08AB9C18");
    runtime.register_function(0x08AB9D08u, &sub_08AB9C18, "sub_08AB9C18");
    runtime.register_function(0x08AB9D0Cu, &sub_08AB9C18, "sub_08AB9C18");
    runtime.register_function(0x08AB9D10u, &sub_08AB9C18, "sub_08AB9C18");
    runtime.register_function(0x08AB9D14u, &sub_08AB9C18, "sub_08AB9C18");
    runtime.register_function(0x08B24A0Cu, &sub_08B24A0C, "sub_08B24A0C");
    runtime.register_function(0x08B24A10u, &sub_08B24A0C, "sub_08B24A0C");
    runtime.register_function(0x08B24A14u, &sub_08B24A0C, "sub_08B24A0C");
    runtime.register_function(0x08B24A18u, &sub_08B24A0C, "sub_08B24A0C");
    runtime.register_function(0x08B24A1Cu, &sub_08B24A0C, "sub_08B24A0C");
    runtime.register_function(0x08B24A20u, &sub_08B24A0C, "sub_08B24A0C");
    runtime.register_function(0x08B24A24u, &sub_08B24A0C, "sub_08B24A0C");
    runtime.register_function(0x08B24A28u, &sub_08B24A0C, "sub_08B24A0C");
    runtime.register_function(0x08B24A2Cu, &sub_08B24A0C, "sub_08B24A0C");
    runtime.register_function(0x08B24A34u, &sub_08B24A0C, "sub_08B24A0C");
    runtime.register_function(0x08B24A38u, &sub_08B24A0C, "sub_08B24A0C");
    runtime.register_function(0x08B24A3Cu, &sub_08B24A0C, "sub_08B24A0C");
    runtime.register_function(0x08B24A40u, &sub_08B24A0C, "sub_08B24A0C");
    runtime.register_function(0x08B24A48u, &sub_08B24A0C, "sub_08B24A0C");
    runtime.register_function(0x08B24A4Cu, &sub_08B24A0C, "sub_08B24A0C");
    runtime.register_function(0x08B24A50u, &sub_08B24A0C, "sub_08B24A0C");
    runtime.register_function(0x08B24A58u, &sub_08B24A0C, "sub_08B24A0C");
    runtime.register_function(0x08B24A60u, &sub_08B24A0C, "sub_08B24A0C");
    runtime.register_function(0x08B24A68u, &sub_08B24A0C, "sub_08B24A0C");
    runtime.register_function(0x08B24A6Cu, &sub_08B24A0C, "sub_08B24A0C");
    runtime.register_function(0x08B24A74u, &sub_08B24A0C, "sub_08B24A0C");
    runtime.register_function(0x08B24A78u, &sub_08B24A0C, "sub_08B24A0C");
    runtime.register_function(0x08B24A7Cu, &sub_08B24A0C, "sub_08B24A0C");
    runtime.register_function(0x08B24A80u, &sub_08B24A0C, "sub_08B24A0C");
    runtime.register_function(0x08B24A84u, &sub_08B24A0C, "sub_08B24A0C");
    runtime.register_function(0x08B24A88u, &sub_08B24A0C, "sub_08B24A0C");
    runtime.register_function(0x08B24A8Cu, &sub_08B24A0C, "sub_08B24A0C");
    runtime.register_function(0x08B24A90u, &sub_08B24A0C, "sub_08B24A0C");
    runtime.register_function(0x08B24A94u, &sub_08B24A0C, "sub_08B24A0C");
    runtime.register_function(0x08B24A98u, &sub_08B24A0C, "sub_08B24A0C");
    runtime.register_function(0x08B24A9Cu, &sub_08B24A0C, "sub_08B24A0C");
    runtime.register_function(0x08B24AA0u, &sub_08B24A0C, "sub_08B24A0C");
    runtime.register_function(0x08B24AA8u, &sub_08B24A0C, "sub_08B24A0C");
    runtime.register_function(0x08B24AACu, &sub_08B24A0C, "sub_08B24A0C");
    runtime.register_function(0x08B24AB0u, &sub_08B24A0C, "sub_08B24A0C");
    runtime.register_function(0x08B24AB8u, &sub_08B24A0C, "sub_08B24A0C");
    runtime.register_function(0x08B24ABCu, &sub_08B24A0C, "sub_08B24A0C");
    runtime.register_function(0x08B24AC0u, &sub_08B24A0C, "sub_08B24A0C");
    runtime.register_function(0x08B24AC4u, &sub_08B24A0C, "sub_08B24A0C");
    runtime.register_function(0x08B24ACCu, &sub_08B24A0C, "sub_08B24A0C");
    runtime.register_function(0x08B24AD0u, &sub_08B24A0C, "sub_08B24A0C");
    runtime.register_function(0x08B24AD4u, &sub_08B24A0C, "sub_08B24A0C");
    runtime.register_function(0x08B24AD8u, &sub_08B24A0C, "sub_08B24A0C");
    runtime.register_function(0x08B24ADCu, &sub_08B24A0C, "sub_08B24A0C");
    runtime.register_function(0x08B24AE0u, &sub_08B24A0C, "sub_08B24A0C");
    runtime.register_function(0x08B24AE4u, &sub_08B24A0C, "sub_08B24A0C");
    runtime.register_function(0x08B24AE8u, &sub_08B24A0C, "sub_08B24A0C");
    runtime.register_function(0x08B24AF0u, &sub_08B24A0C, "sub_08B24A0C");
    runtime.register_function(0x08B24AF4u, &sub_08B24A0C, "sub_08B24A0C");
    runtime.register_function(0x08B24AFCu, &sub_08B24A0C, "sub_08B24A0C");
    runtime.register_function(0x08B24B00u, &sub_08B24A0C, "sub_08B24A0C");
    runtime.register_function(0x08B24B04u, &sub_08B24A0C, "sub_08B24A0C");
    runtime.register_function(0x08B24B08u, &sub_08B24A0C, "sub_08B24A0C");
    runtime.register_function(0x08B296E8u, &sub_08B296E8, "sub_08B296E8");
    runtime.register_function(0x08B296ECu, &sub_08B296E8, "sub_08B296E8");
    runtime.register_function(0x08B296F0u, &sub_08B296E8, "sub_08B296E8");
    runtime.register_function(0x08B296F4u, &sub_08B296E8, "sub_08B296E8");
    runtime.register_function(0x08B296F8u, &sub_08B296E8, "sub_08B296E8");
    runtime.register_function(0x08B296FCu, &sub_08B296E8, "sub_08B296E8");
    runtime.register_function(0x08B29700u, &sub_08B296E8, "sub_08B296E8");
    runtime.register_function(0x08B29704u, &sub_08B296E8, "sub_08B296E8");
    runtime.register_function(0x08B29708u, &sub_08B296E8, "sub_08B296E8");
    runtime.register_function(0x08B29710u, &sub_08B296E8, "sub_08B296E8");
    runtime.register_function(0x08B29714u, &sub_08B296E8, "sub_08B296E8");
    runtime.register_function(0x08B29718u, &sub_08B296E8, "sub_08B296E8");
    runtime.register_function(0x08B2971Cu, &sub_08B296E8, "sub_08B296E8");
    runtime.register_function(0x08B29724u, &sub_08B296E8, "sub_08B296E8");
    runtime.register_function(0x08B29728u, &sub_08B296E8, "sub_08B296E8");
    runtime.register_function(0x08B2972Cu, &sub_08B296E8, "sub_08B296E8");
    runtime.register_function(0x08B29734u, &sub_08B296E8, "sub_08B296E8");
    runtime.register_function(0x08B2973Cu, &sub_08B296E8, "sub_08B296E8");
    runtime.register_function(0x08B29744u, &sub_08B296E8, "sub_08B296E8");
    runtime.register_function(0x08B29748u, &sub_08B296E8, "sub_08B296E8");
    runtime.register_function(0x08B29750u, &sub_08B296E8, "sub_08B296E8");
    runtime.register_function(0x08B29754u, &sub_08B296E8, "sub_08B296E8");
    runtime.register_function(0x08B29758u, &sub_08B296E8, "sub_08B296E8");
    runtime.register_function(0x08B2975Cu, &sub_08B296E8, "sub_08B296E8");
    runtime.register_function(0x08B29760u, &sub_08B296E8, "sub_08B296E8");
    runtime.register_function(0x08B29764u, &sub_08B296E8, "sub_08B296E8");
    runtime.register_function(0x08B2976Cu, &sub_08B296E8, "sub_08B296E8");
    runtime.register_function(0x08B29770u, &sub_08B296E8, "sub_08B296E8");
    runtime.register_function(0x08B29774u, &sub_08B296E8, "sub_08B296E8");
    runtime.register_function(0x08B29778u, &sub_08B296E8, "sub_08B296E8");
    runtime.register_function(0x08B2977Cu, &sub_08B296E8, "sub_08B296E8");
    runtime.register_function(0x08B29780u, &sub_08B296E8, "sub_08B296E8");
    runtime.register_function(0x08B29788u, &sub_08B296E8, "sub_08B296E8");
    runtime.register_function(0x08B2978Cu, &sub_08B296E8, "sub_08B296E8");
    runtime.register_function(0x08B29790u, &sub_08B296E8, "sub_08B296E8");
    runtime.register_function(0x08B29794u, &sub_08B296E8, "sub_08B296E8");
    runtime.register_function(0x08B29798u, &sub_08B296E8, "sub_08B296E8");
    runtime.register_function(0x08B297A0u, &sub_08B296E8, "sub_08B296E8");
    runtime.register_function(0x08B297A4u, &sub_08B296E8, "sub_08B296E8");
    runtime.register_function(0x08B297ACu, &sub_08B296E8, "sub_08B296E8");
    runtime.register_function(0x08B297B0u, &sub_08B296E8, "sub_08B296E8");
    runtime.register_function(0x08B297B4u, &sub_08B296E8, "sub_08B296E8");
    runtime.register_function(0x08B297B8u, &sub_08B296E8, "sub_08B296E8");
    runtime.register_function(0x08B297BCu, &sub_08B296E8, "sub_08B296E8");
    runtime.register_function(0x08B297C0u, &sub_08B296E8, "sub_08B296E8");
    runtime.register_function(0x08B297C4u, &sub_08B296E8, "sub_08B296E8");
    runtime.register_function(0x08B297C8u, &sub_08B296E8, "sub_08B296E8");
    runtime.register_function(0x08B297CCu, &sub_08B296E8, "sub_08B296E8");
    runtime.register_function(0x08B297D0u, &sub_08B296E8, "sub_08B296E8");
    runtime.register_function(0x08B297D4u, &sub_08B296E8, "sub_08B296E8");
    runtime.register_function(0x08B297D8u, &sub_08B296E8, "sub_08B296E8");
    runtime.register_function(0x08B297DCu, &sub_08B296E8, "sub_08B296E8");
    runtime.register_function(0x08B297E0u, &sub_08B296E8, "sub_08B296E8");
    runtime.register_function(0x08B297E4u, &sub_08B296E8, "sub_08B296E8");
    runtime.register_function(0x08B326F8u, &sub_08B326F8, "sub_08B326F8");
    runtime.register_function(0x08B326FCu, &sub_08B326F8, "sub_08B326F8");
    runtime.register_function(0x08B32700u, &sub_08B326F8, "sub_08B326F8");
    runtime.register_function(0x08B32704u, &sub_08B326F8, "sub_08B326F8");
    runtime.register_function(0x08B32708u, &sub_08B326F8, "sub_08B326F8");
    runtime.register_function(0x08B3270Cu, &sub_08B326F8, "sub_08B326F8");
    runtime.register_function(0x08B32710u, &sub_08B326F8, "sub_08B326F8");
    runtime.register_function(0x08B32714u, &sub_08B326F8, "sub_08B326F8");
    runtime.register_function(0x08B32718u, &sub_08B326F8, "sub_08B326F8");
    runtime.register_function(0x08B32720u, &sub_08B326F8, "sub_08B326F8");
    runtime.register_function(0x08B32724u, &sub_08B326F8, "sub_08B326F8");
    runtime.register_function(0x08B32728u, &sub_08B326F8, "sub_08B326F8");
    runtime.register_function(0x08B3272Cu, &sub_08B326F8, "sub_08B326F8");
    runtime.register_function(0x08B32734u, &sub_08B326F8, "sub_08B326F8");
    runtime.register_function(0x08B32738u, &sub_08B326F8, "sub_08B326F8");
    runtime.register_function(0x08B3273Cu, &sub_08B326F8, "sub_08B326F8");
    runtime.register_function(0x08B32744u, &sub_08B326F8, "sub_08B326F8");
    runtime.register_function(0x08B3274Cu, &sub_08B326F8, "sub_08B326F8");
    runtime.register_function(0x08B32754u, &sub_08B326F8, "sub_08B326F8");
    runtime.register_function(0x08B32758u, &sub_08B326F8, "sub_08B326F8");
    runtime.register_function(0x08B32760u, &sub_08B326F8, "sub_08B326F8");
    runtime.register_function(0x08B32764u, &sub_08B326F8, "sub_08B326F8");
    runtime.register_function(0x08B32768u, &sub_08B326F8, "sub_08B326F8");
    runtime.register_function(0x08B3276Cu, &sub_08B326F8, "sub_08B326F8");
    runtime.register_function(0x08B32770u, &sub_08B326F8, "sub_08B326F8");
    runtime.register_function(0x08B32774u, &sub_08B326F8, "sub_08B326F8");
    runtime.register_function(0x08B3277Cu, &sub_08B326F8, "sub_08B326F8");
    runtime.register_function(0x08B32780u, &sub_08B326F8, "sub_08B326F8");
    runtime.register_function(0x08B32784u, &sub_08B326F8, "sub_08B326F8");
    runtime.register_function(0x08B32788u, &sub_08B326F8, "sub_08B326F8");
    runtime.register_function(0x08B3278Cu, &sub_08B326F8, "sub_08B326F8");
    runtime.register_function(0x08B32790u, &sub_08B326F8, "sub_08B326F8");
    runtime.register_function(0x08B32798u, &sub_08B326F8, "sub_08B326F8");
    runtime.register_function(0x08B3279Cu, &sub_08B326F8, "sub_08B326F8");
    runtime.register_function(0x08B327A0u, &sub_08B326F8, "sub_08B326F8");
    runtime.register_function(0x08B327A4u, &sub_08B326F8, "sub_08B326F8");
    runtime.register_function(0x08B327A8u, &sub_08B326F8, "sub_08B326F8");
    runtime.register_function(0x08B327ACu, &sub_08B326F8, "sub_08B326F8");
    runtime.register_function(0x08B327B0u, &sub_08B326F8, "sub_08B326F8");
    runtime.register_function(0x08B327B4u, &sub_08B326F8, "sub_08B326F8");
    runtime.register_function(0x08B327B8u, &sub_08B326F8, "sub_08B326F8");
    runtime.register_function(0x08B327BCu, &sub_08B326F8, "sub_08B326F8");
    runtime.register_function(0x08B327C0u, &sub_08B326F8, "sub_08B326F8");
    runtime.register_function(0x08B327C4u, &sub_08B326F8, "sub_08B326F8");
    runtime.register_function(0x08B327C8u, &sub_08B326F8, "sub_08B326F8");
    runtime.register_function(0x08B327CCu, &sub_08B326F8, "sub_08B326F8");
    runtime.register_function(0x08B327D0u, &sub_08B326F8, "sub_08B326F8");
    runtime.register_function(0x08B327D4u, &sub_08B326F8, "sub_08B326F8");
    runtime.register_function(0x08B327DCu, &sub_08B326F8, "sub_08B326F8");
    runtime.register_function(0x08B327E0u, &sub_08B326F8, "sub_08B326F8");
    runtime.register_function(0x08B327E4u, &sub_08B326F8, "sub_08B326F8");
    runtime.register_function(0x08B327E8u, &sub_08B326F8, "sub_08B326F8");
    runtime.register_function(0x08B327ECu, &sub_08B326F8, "sub_08B326F8");
    runtime.register_function(0x08B327F0u, &sub_08B326F8, "sub_08B326F8");
    runtime.register_function(0x08B327F4u, &sub_08B326F8, "sub_08B326F8");
    runtime.register_function(0x08B34C18u, &sub_08B34C18, "sub_08B34C18");
    runtime.register_function(0x08B34C1Cu, &sub_08B34C18, "sub_08B34C18");
    runtime.register_function(0x08B34C20u, &sub_08B34C18, "sub_08B34C18");
    runtime.register_function(0x08B34C24u, &sub_08B34C18, "sub_08B34C18");
    runtime.register_function(0x08B34C28u, &sub_08B34C18, "sub_08B34C18");
    runtime.register_function(0x08B34C2Cu, &sub_08B34C18, "sub_08B34C18");
    runtime.register_function(0x08B34C30u, &sub_08B34C18, "sub_08B34C18");
    runtime.register_function(0x08B34C34u, &sub_08B34C18, "sub_08B34C18");
    runtime.register_function(0x08B34C38u, &sub_08B34C18, "sub_08B34C18");
    runtime.register_function(0x08B34C40u, &sub_08B34C18, "sub_08B34C18");
    runtime.register_function(0x08B34C44u, &sub_08B34C18, "sub_08B34C18");
    runtime.register_function(0x08B34C48u, &sub_08B34C18, "sub_08B34C18");
    runtime.register_function(0x08B34C4Cu, &sub_08B34C18, "sub_08B34C18");
    runtime.register_function(0x08B34C54u, &sub_08B34C18, "sub_08B34C18");
    runtime.register_function(0x08B34C5Cu, &sub_08B34C18, "sub_08B34C18");
    runtime.register_function(0x08B34C64u, &sub_08B34C18, "sub_08B34C18");
    runtime.register_function(0x08B34C68u, &sub_08B34C18, "sub_08B34C18");
    runtime.register_function(0x08B34C6Cu, &sub_08B34C18, "sub_08B34C18");
    runtime.register_function(0x08B34C70u, &sub_08B34C18, "sub_08B34C18");
    runtime.register_function(0x08B34C74u, &sub_08B34C18, "sub_08B34C18");
    runtime.register_function(0x08B34C78u, &sub_08B34C18, "sub_08B34C18");
    runtime.register_function(0x08B34C7Cu, &sub_08B34C18, "sub_08B34C18");
    runtime.register_function(0x08B34C84u, &sub_08B34C18, "sub_08B34C18");
    runtime.register_function(0x08B34C88u, &sub_08B34C18, "sub_08B34C18");
    runtime.register_function(0x08B34C8Cu, &sub_08B34C18, "sub_08B34C18");
    runtime.register_function(0x08B34C90u, &sub_08B34C18, "sub_08B34C18");
    runtime.register_function(0x08B34C94u, &sub_08B34C18, "sub_08B34C18");
    runtime.register_function(0x08B34C98u, &sub_08B34C18, "sub_08B34C18");
    runtime.register_function(0x08B34CA0u, &sub_08B34C18, "sub_08B34C18");
    runtime.register_function(0x08B34CA8u, &sub_08B34C18, "sub_08B34C18");
    runtime.register_function(0x08B34CACu, &sub_08B34C18, "sub_08B34C18");
    runtime.register_function(0x08B34CB0u, &sub_08B34C18, "sub_08B34C18");
    runtime.register_function(0x08B34CB4u, &sub_08B34C18, "sub_08B34C18");
    runtime.register_function(0x08B34CB8u, &sub_08B34C18, "sub_08B34C18");
    runtime.register_function(0x08B34CBCu, &sub_08B34C18, "sub_08B34C18");
    runtime.register_function(0x08B34CC0u, &sub_08B34C18, "sub_08B34C18");
    runtime.register_function(0x08B34CC4u, &sub_08B34C18, "sub_08B34C18");
    runtime.register_function(0x08B34CC8u, &sub_08B34C18, "sub_08B34C18");
    runtime.register_function(0x08B34CCCu, &sub_08B34C18, "sub_08B34C18");
    runtime.register_function(0x08B34CD0u, &sub_08B34C18, "sub_08B34C18");
    runtime.register_function(0x08B34CD4u, &sub_08B34C18, "sub_08B34C18");
    runtime.register_function(0x08B34CD8u, &sub_08B34C18, "sub_08B34C18");
    runtime.register_function(0x08B34CDCu, &sub_08B34C18, "sub_08B34C18");
    runtime.register_function(0x08B34CE0u, &sub_08B34C18, "sub_08B34C18");
    runtime.register_function(0x08B34CE4u, &sub_08B34C18, "sub_08B34C18");
    runtime.register_function(0x08B34CE8u, &sub_08B34C18, "sub_08B34C18");
    runtime.register_function(0x08B34CECu, &sub_08B34C18, "sub_08B34C18");
    runtime.register_function(0x08B34CF0u, &sub_08B34C18, "sub_08B34C18");
    runtime.register_function(0x08B34CF4u, &sub_08B34C18, "sub_08B34C18");
    runtime.register_function(0x08B34CF8u, &sub_08B34C18, "sub_08B34C18");
    runtime.register_function(0x08B34CFCu, &sub_08B34C18, "sub_08B34C18");
    runtime.register_function(0x08B34D00u, &sub_08B34C18, "sub_08B34C18");
    runtime.register_function(0x08B34D04u, &sub_08B34C18, "sub_08B34C18");
    runtime.register_function(0x08B34D08u, &sub_08B34C18, "sub_08B34C18");
    runtime.register_function(0x08B34D0Cu, &sub_08B34C18, "sub_08B34C18");
    runtime.register_function(0x08B34D10u, &sub_08B34C18, "sub_08B34C18");
    runtime.register_function(0x08B34D14u, &sub_08B34C18, "sub_08B34C18");
    runtime.register_function(0x08B41F00u, &sub_08B41F00, "sub_08B41F00");
    runtime.register_function(0x08B41F04u, &sub_08B41F00, "sub_08B41F00");
    runtime.register_function(0x08B41F08u, &sub_08B41F00, "sub_08B41F00");
    runtime.register_function(0x08B41F0Cu, &sub_08B41F00, "sub_08B41F00");
    runtime.register_function(0x08B41F10u, &sub_08B41F00, "sub_08B41F00");
    runtime.register_function(0x08B41F14u, &sub_08B41F00, "sub_08B41F00");
    runtime.register_function(0x08B41F18u, &sub_08B41F00, "sub_08B41F00");
    runtime.register_function(0x08B41F1Cu, &sub_08B41F00, "sub_08B41F00");
    runtime.register_function(0x08B41F20u, &sub_08B41F00, "sub_08B41F00");
    runtime.register_function(0x08B41F28u, &sub_08B41F00, "sub_08B41F00");
    runtime.register_function(0x08B41F2Cu, &sub_08B41F00, "sub_08B41F00");
    runtime.register_function(0x08B41F30u, &sub_08B41F00, "sub_08B41F00");
    runtime.register_function(0x08B41F34u, &sub_08B41F00, "sub_08B41F00");
    runtime.register_function(0x08B41F38u, &sub_08B41F00, "sub_08B41F00");
    runtime.register_function(0x08B41F3Cu, &sub_08B41F00, "sub_08B41F00");
    runtime.register_function(0x08B41F44u, &sub_08B41F00, "sub_08B41F00");
    runtime.register_function(0x08B41F48u, &sub_08B41F00, "sub_08B41F00");
    runtime.register_function(0x08B41F4Cu, &sub_08B41F00, "sub_08B41F00");
    runtime.register_function(0x08B41F50u, &sub_08B41F00, "sub_08B41F00");
    runtime.register_function(0x08B41F54u, &sub_08B41F00, "sub_08B41F00");
    runtime.register_function(0x08B41F58u, &sub_08B41F00, "sub_08B41F00");
    runtime.register_function(0x08B41F5Cu, &sub_08B41F00, "sub_08B41F00");
    runtime.register_function(0x08B41F60u, &sub_08B41F00, "sub_08B41F00");
    runtime.register_function(0x08B41F64u, &sub_08B41F00, "sub_08B41F00");
    runtime.register_function(0x08B41F68u, &sub_08B41F00, "sub_08B41F00");
    runtime.register_function(0x08B41F6Cu, &sub_08B41F00, "sub_08B41F00");
    runtime.register_function(0x08B41F70u, &sub_08B41F00, "sub_08B41F00");
    runtime.register_function(0x08B41F74u, &sub_08B41F00, "sub_08B41F00");
    runtime.register_function(0x08B41F78u, &sub_08B41F00, "sub_08B41F00");
    runtime.register_function(0x08B41F7Cu, &sub_08B41F00, "sub_08B41F00");
    runtime.register_function(0x08B41F84u, &sub_08B41F00, "sub_08B41F00");
    runtime.register_function(0x08B41F8Cu, &sub_08B41F00, "sub_08B41F00");
    runtime.register_function(0x08B41F90u, &sub_08B41F00, "sub_08B41F00");
    runtime.register_function(0x08B41F94u, &sub_08B41F00, "sub_08B41F00");
    runtime.register_function(0x08B41F98u, &sub_08B41F00, "sub_08B41F00");
    runtime.register_function(0x08B41F9Cu, &sub_08B41F00, "sub_08B41F00");
    runtime.register_function(0x08B41FA0u, &sub_08B41F00, "sub_08B41F00");
    runtime.register_function(0x08B41FA8u, &sub_08B41F00, "sub_08B41F00");
    runtime.register_function(0x08B41FACu, &sub_08B41F00, "sub_08B41F00");
    runtime.register_function(0x08B41FB0u, &sub_08B41F00, "sub_08B41F00");
    runtime.register_function(0x08B41FB4u, &sub_08B41F00, "sub_08B41F00");
    runtime.register_function(0x08B41FB8u, &sub_08B41F00, "sub_08B41F00");
    runtime.register_function(0x08B41FBCu, &sub_08B41F00, "sub_08B41F00");
    runtime.register_function(0x08B41FC4u, &sub_08B41F00, "sub_08B41F00");
    runtime.register_function(0x08B41FC8u, &sub_08B41F00, "sub_08B41F00");
    runtime.register_function(0x08B41FCCu, &sub_08B41F00, "sub_08B41F00");
    runtime.register_function(0x08B41FD0u, &sub_08B41F00, "sub_08B41F00");
    runtime.register_function(0x08B41FD4u, &sub_08B41F00, "sub_08B41F00");
    runtime.register_function(0x08B41FDCu, &sub_08B41F00, "sub_08B41F00");
    runtime.register_function(0x08B41FE0u, &sub_08B41F00, "sub_08B41F00");
    runtime.register_function(0x08B41FE4u, &sub_08B41F00, "sub_08B41F00");
    runtime.register_function(0x08B41FE8u, &sub_08B41F00, "sub_08B41F00");
    runtime.register_function(0x08B41FECu, &sub_08B41F00, "sub_08B41F00");
    runtime.register_function(0x08B41FF0u, &sub_08B41F00, "sub_08B41F00");
    runtime.register_function(0x08B41FF4u, &sub_08B41F00, "sub_08B41F00");
    runtime.register_function(0x08B41FF8u, &sub_08B41F00, "sub_08B41F00");
    runtime.register_function(0x08B41FFCu, &sub_08B41F00, "sub_08B41F00");
    runtime.register_function(0x08B42234u, &sub_08B42234, "sub_08B42234");
    runtime.register_function(0x08B42238u, &sub_08B42234, "sub_08B42234");
    runtime.register_function(0x08B42240u, &sub_08B42234, "sub_08B42234");
    runtime.register_function(0x08B42244u, &sub_08B42234, "sub_08B42234");
    runtime.register_function(0x08B42248u, &sub_08B42234, "sub_08B42234");
    runtime.register_function(0x08B42250u, &sub_08B42234, "sub_08B42234");
    runtime.register_function(0x08B42258u, &sub_08B42234, "sub_08B42234");
    runtime.register_function(0x08B42260u, &sub_08B42234, "sub_08B42234");
    runtime.register_function(0x08B42264u, &sub_08B42234, "sub_08B42234");
    runtime.register_function(0x08B4226Cu, &sub_08B42234, "sub_08B42234");
    runtime.register_function(0x08B42270u, &sub_08B42234, "sub_08B42234");
    runtime.register_function(0x08B42274u, &sub_08B42234, "sub_08B42234");
    runtime.register_function(0x08B42278u, &sub_08B42234, "sub_08B42234");
    runtime.register_function(0x08B4227Cu, &sub_08B42234, "sub_08B42234");
    runtime.register_function(0x08B42280u, &sub_08B42234, "sub_08B42234");
    runtime.register_function(0x08B42284u, &sub_08B42234, "sub_08B42234");
    runtime.register_function(0x08B42288u, &sub_08B42234, "sub_08B42234");
    runtime.register_function(0x08B4228Cu, &sub_08B42234, "sub_08B42234");
    runtime.register_function(0x08B42294u, &sub_08B42234, "sub_08B42234");
    runtime.register_function(0x08B4229Cu, &sub_08B42234, "sub_08B42234");
    runtime.register_function(0x08B422A0u, &sub_08B42234, "sub_08B42234");
    runtime.register_function(0x08B422A4u, &sub_08B42234, "sub_08B42234");
    runtime.register_function(0x08B422ACu, &sub_08B42234, "sub_08B42234");
    runtime.register_function(0x08B422B0u, &sub_08B42234, "sub_08B42234");
    runtime.register_function(0x08B422B8u, &sub_08B42234, "sub_08B42234");
    runtime.register_function(0x08B422BCu, &sub_08B42234, "sub_08B42234");
    runtime.register_function(0x08B422C0u, &sub_08B42234, "sub_08B42234");
    runtime.register_function(0x08B422C4u, &sub_08B42234, "sub_08B42234");
    runtime.register_function(0x08B422C8u, &sub_08B42234, "sub_08B42234");
    runtime.register_function(0x08B422CCu, &sub_08B42234, "sub_08B42234");
    runtime.register_function(0x08B422D0u, &sub_08B42234, "sub_08B42234");
    runtime.register_function(0x08B422D8u, &sub_08B42234, "sub_08B42234");
    runtime.register_function(0x08B422E0u, &sub_08B42234, "sub_08B42234");
    runtime.register_function(0x08B422E4u, &sub_08B42234, "sub_08B42234");
    runtime.register_function(0x08B422E8u, &sub_08B42234, "sub_08B42234");
    runtime.register_function(0x08B422F0u, &sub_08B42234, "sub_08B42234");
    runtime.register_function(0x08B422F4u, &sub_08B42234, "sub_08B42234");
    runtime.register_function(0x08B422F8u, &sub_08B42234, "sub_08B42234");
    runtime.register_function(0x08B422FCu, &sub_08B42234, "sub_08B42234");
    runtime.register_function(0x08B42300u, &sub_08B42234, "sub_08B42234");
    runtime.register_function(0x08B42308u, &sub_08B42234, "sub_08B42234");
    runtime.register_function(0x08B4230Cu, &sub_08B42234, "sub_08B42234");
    runtime.register_function(0x08B42310u, &sub_08B42234, "sub_08B42234");
    runtime.register_function(0x08B42314u, &sub_08B42234, "sub_08B42234");
    runtime.register_function(0x08B42318u, &sub_08B42234, "sub_08B42234");
    runtime.register_function(0x08B4231Cu, &sub_08B42234, "sub_08B42234");
    runtime.register_function(0x08B42320u, &sub_08B42234, "sub_08B42234");
    runtime.register_function(0x08B42328u, &sub_08B42234, "sub_08B42234");
    runtime.register_function(0x08B4232Cu, &sub_08B42234, "sub_08B42234");
    runtime.register_function(0x08B42330u, &sub_08B42234, "sub_08B42234");
    runtime.register_function(0x08B42368u, &sub_08B42368, "sub_08B42368");
    runtime.register_function(0x08B4236Cu, &sub_08B42368, "sub_08B42368");
    runtime.register_function(0x08B42370u, &sub_08B42368, "sub_08B42368");
    runtime.register_function(0x08B42374u, &sub_08B42368, "sub_08B42368");
    runtime.register_function(0x08B4237Cu, &sub_08B42368, "sub_08B42368");
    runtime.register_function(0x08B42380u, &sub_08B42368, "sub_08B42368");
    runtime.register_function(0x08B42384u, &sub_08B42368, "sub_08B42368");
    runtime.register_function(0x08B42388u, &sub_08B42368, "sub_08B42368");
    runtime.register_function(0x08B42390u, &sub_08B42368, "sub_08B42368");
    runtime.register_function(0x08B42394u, &sub_08B42368, "sub_08B42368");
    runtime.register_function(0x08B42398u, &sub_08B42368, "sub_08B42368");
    runtime.register_function(0x08B423A0u, &sub_08B42368, "sub_08B42368");
    runtime.register_function(0x08B423A8u, &sub_08B42368, "sub_08B42368");
    runtime.register_function(0x08B423B0u, &sub_08B42368, "sub_08B42368");
    runtime.register_function(0x08B423B4u, &sub_08B42368, "sub_08B42368");
    runtime.register_function(0x08B423BCu, &sub_08B42368, "sub_08B42368");
    runtime.register_function(0x08B423C0u, &sub_08B42368, "sub_08B42368");
    runtime.register_function(0x08B423C4u, &sub_08B42368, "sub_08B42368");
    runtime.register_function(0x08B423C8u, &sub_08B42368, "sub_08B42368");
    runtime.register_function(0x08B423D0u, &sub_08B42368, "sub_08B42368");
    runtime.register_function(0x08B423D4u, &sub_08B42368, "sub_08B42368");
    runtime.register_function(0x08B423D8u, &sub_08B42368, "sub_08B42368");
    runtime.register_function(0x08B423DCu, &sub_08B42368, "sub_08B42368");
    runtime.register_function(0x08B423E0u, &sub_08B42368, "sub_08B42368");
    runtime.register_function(0x08B423E4u, &sub_08B42368, "sub_08B42368");
    runtime.register_function(0x08B423E8u, &sub_08B42368, "sub_08B42368");
    runtime.register_function(0x08B423ECu, &sub_08B42368, "sub_08B42368");
    runtime.register_function(0x08B423F0u, &sub_08B42368, "sub_08B42368");
    runtime.register_function(0x08B423F4u, &sub_08B42368, "sub_08B42368");
    runtime.register_function(0x08B423FCu, &sub_08B42368, "sub_08B42368");
    runtime.register_function(0x08B42400u, &sub_08B42368, "sub_08B42368");
    runtime.register_function(0x08B42404u, &sub_08B42368, "sub_08B42368");
    runtime.register_function(0x08B42408u, &sub_08B42368, "sub_08B42368");
    runtime.register_function(0x08B4240Cu, &sub_08B42368, "sub_08B42368");
    runtime.register_function(0x08B42410u, &sub_08B42368, "sub_08B42368");
    runtime.register_function(0x08B42414u, &sub_08B42368, "sub_08B42368");
    runtime.register_function(0x08B4241Cu, &sub_08B42368, "sub_08B42368");
    runtime.register_function(0x08B42420u, &sub_08B42368, "sub_08B42368");
    runtime.register_function(0x08B42424u, &sub_08B42368, "sub_08B42368");
    runtime.register_function(0x08B42428u, &sub_08B42368, "sub_08B42368");
    runtime.register_function(0x08B4242Cu, &sub_08B42368, "sub_08B42368");
    runtime.register_function(0x08B42434u, &sub_08B42368, "sub_08B42368");
    runtime.register_function(0x08B42438u, &sub_08B42368, "sub_08B42368");
    runtime.register_function(0x08B4243Cu, &sub_08B42368, "sub_08B42368");
    runtime.register_function(0x08B42444u, &sub_08B42368, "sub_08B42368");
    runtime.register_function(0x08B42448u, &sub_08B42368, "sub_08B42368");
    runtime.register_function(0x08B4244Cu, &sub_08B42368, "sub_08B42368");
    runtime.register_function(0x08B42450u, &sub_08B42368, "sub_08B42368");
    runtime.register_function(0x08B42458u, &sub_08B42368, "sub_08B42368");
    runtime.register_function(0x08B4245Cu, &sub_08B42368, "sub_08B42368");
    runtime.register_function(0x08B42460u, &sub_08B42368, "sub_08B42368");
    runtime.register_function(0x08B42464u, &sub_08B42368, "sub_08B42368");
    runtime.register_function(0x08B42A04u, &sub_08B42A04, "sub_08B42A04");
    runtime.register_function(0x08B42A08u, &sub_08B42A04, "sub_08B42A04");
    runtime.register_function(0x08B42A0Cu, &sub_08B42A04, "sub_08B42A04");
    runtime.register_function(0x08B42A10u, &sub_08B42A04, "sub_08B42A04");
    runtime.register_function(0x08B42A18u, &sub_08B42A04, "sub_08B42A04");
    runtime.register_function(0x08B42A1Cu, &sub_08B42A04, "sub_08B42A04");
    runtime.register_function(0x08B42A20u, &sub_08B42A04, "sub_08B42A04");
    runtime.register_function(0x08B42A24u, &sub_08B42A04, "sub_08B42A04");
    runtime.register_function(0x08B42A2Cu, &sub_08B42A04, "sub_08B42A04");
    runtime.register_function(0x08B42A30u, &sub_08B42A04, "sub_08B42A04");
    runtime.register_function(0x08B42A34u, &sub_08B42A04, "sub_08B42A04");
    runtime.register_function(0x08B42A3Cu, &sub_08B42A04, "sub_08B42A04");
    runtime.register_function(0x08B42A44u, &sub_08B42A04, "sub_08B42A04");
    runtime.register_function(0x08B42A4Cu, &sub_08B42A04, "sub_08B42A04");
    runtime.register_function(0x08B42A50u, &sub_08B42A04, "sub_08B42A04");
    runtime.register_function(0x08B42A58u, &sub_08B42A04, "sub_08B42A04");
    runtime.register_function(0x08B42A5Cu, &sub_08B42A04, "sub_08B42A04");
    runtime.register_function(0x08B42A64u, &sub_08B42A04, "sub_08B42A04");
    runtime.register_function(0x08B42A68u, &sub_08B42A04, "sub_08B42A04");
    runtime.register_function(0x08B42A6Cu, &sub_08B42A04, "sub_08B42A04");
    runtime.register_function(0x08B42A70u, &sub_08B42A04, "sub_08B42A04");
    runtime.register_function(0x08B42A74u, &sub_08B42A04, "sub_08B42A04");
    runtime.register_function(0x08B42A78u, &sub_08B42A04, "sub_08B42A04");
    runtime.register_function(0x08B42A7Cu, &sub_08B42A04, "sub_08B42A04");
    runtime.register_function(0x08B42A80u, &sub_08B42A04, "sub_08B42A04");
    runtime.register_function(0x08B42A84u, &sub_08B42A04, "sub_08B42A04");
    runtime.register_function(0x08B42A88u, &sub_08B42A04, "sub_08B42A04");
    runtime.register_function(0x08B42A8Cu, &sub_08B42A04, "sub_08B42A04");
    runtime.register_function(0x08B42A90u, &sub_08B42A04, "sub_08B42A04");
    runtime.register_function(0x08B42A94u, &sub_08B42A04, "sub_08B42A04");
    runtime.register_function(0x08B42A98u, &sub_08B42A04, "sub_08B42A04");
    runtime.register_function(0x08B42A9Cu, &sub_08B42A04, "sub_08B42A04");
    runtime.register_function(0x08B42AA0u, &sub_08B42A04, "sub_08B42A04");
    runtime.register_function(0x08B42AA4u, &sub_08B42A04, "sub_08B42A04");
    runtime.register_function(0x08B42AA8u, &sub_08B42A04, "sub_08B42A04");
    runtime.register_function(0x08B42AB0u, &sub_08B42A04, "sub_08B42A04");
    runtime.register_function(0x08B42AB4u, &sub_08B42A04, "sub_08B42A04");
    runtime.register_function(0x08B42AB8u, &sub_08B42A04, "sub_08B42A04");
    runtime.register_function(0x08B42ABCu, &sub_08B42A04, "sub_08B42A04");
    runtime.register_function(0x08B42AC0u, &sub_08B42A04, "sub_08B42A04");
    runtime.register_function(0x08B42AC4u, &sub_08B42A04, "sub_08B42A04");
    runtime.register_function(0x08B42AC8u, &sub_08B42A04, "sub_08B42A04");
    runtime.register_function(0x08B42ACCu, &sub_08B42A04, "sub_08B42A04");
    runtime.register_function(0x08B42AD4u, &sub_08B42A04, "sub_08B42A04");
    runtime.register_function(0x08B42AD8u, &sub_08B42A04, "sub_08B42A04");
    runtime.register_function(0x08B42ADCu, &sub_08B42A04, "sub_08B42A04");
    runtime.register_function(0x08B42AE0u, &sub_08B42A04, "sub_08B42A04");
    runtime.register_function(0x08B42AE4u, &sub_08B42A04, "sub_08B42A04");
    runtime.register_function(0x08B42AE8u, &sub_08B42A04, "sub_08B42A04");
    runtime.register_function(0x08B42AF0u, &sub_08B42A04, "sub_08B42A04");
    runtime.register_function(0x08B42AF4u, &sub_08B42A04, "sub_08B42A04");
    runtime.register_function(0x08B42AF8u, &sub_08B42A04, "sub_08B42A04");
    runtime.register_function(0x08B42AFCu, &sub_08B42A04, "sub_08B42A04");
    runtime.register_function(0x08B42B00u, &sub_08B42A04, "sub_08B42A04");
    runtime.register_function(0x08B42AA0u, &sub_08B42AA0, "sub_08B42AA0");
    runtime.register_function(0x08B42AA4u, &sub_08B42AA0, "sub_08B42AA0");
    runtime.register_function(0x08B42AA8u, &sub_08B42AA0, "sub_08B42AA0");
    runtime.register_function(0x08B42AB0u, &sub_08B42AA0, "sub_08B42AA0");
    runtime.register_function(0x08B42AB4u, &sub_08B42AA0, "sub_08B42AA0");
    runtime.register_function(0x08B42AB8u, &sub_08B42AA0, "sub_08B42AA0");
    runtime.register_function(0x08B42ABCu, &sub_08B42AA0, "sub_08B42AA0");
    runtime.register_function(0x08B42AC0u, &sub_08B42AA0, "sub_08B42AA0");
    runtime.register_function(0x08B42AC4u, &sub_08B42AA0, "sub_08B42AA0");
    runtime.register_function(0x08B42AC8u, &sub_08B42AA0, "sub_08B42AA0");
    runtime.register_function(0x08B42ACCu, &sub_08B42AA0, "sub_08B42AA0");
    runtime.register_function(0x08B42AD4u, &sub_08B42AA0, "sub_08B42AA0");
    runtime.register_function(0x08B42AD8u, &sub_08B42AA0, "sub_08B42AA0");
    runtime.register_function(0x08B42ADCu, &sub_08B42AA0, "sub_08B42AA0");
    runtime.register_function(0x08B42AE0u, &sub_08B42AA0, "sub_08B42AA0");
    runtime.register_function(0x08B42AE4u, &sub_08B42AA0, "sub_08B42AA0");
    runtime.register_function(0x08B42AE8u, &sub_08B42AA0, "sub_08B42AA0");
    runtime.register_function(0x08B42AF0u, &sub_08B42AA0, "sub_08B42AA0");
    runtime.register_function(0x08B42AF4u, &sub_08B42AA0, "sub_08B42AA0");
    runtime.register_function(0x08B42AF8u, &sub_08B42AA0, "sub_08B42AA0");
    runtime.register_function(0x08B42AFCu, &sub_08B42AA0, "sub_08B42AA0");
    runtime.register_function(0x08B42B00u, &sub_08B42AA0, "sub_08B42AA0");
    runtime.register_function(0x08B42B08u, &sub_08B42AA0, "sub_08B42AA0");
    runtime.register_function(0x08B42B0Cu, &sub_08B42AA0, "sub_08B42AA0");
    runtime.register_function(0x08B42B10u, &sub_08B42AA0, "sub_08B42AA0");
    runtime.register_function(0x08B42B14u, &sub_08B42AA0, "sub_08B42AA0");
    runtime.register_function(0x08B42B18u, &sub_08B42AA0, "sub_08B42AA0");
    runtime.register_function(0x08B42B20u, &sub_08B42AA0, "sub_08B42AA0");
    runtime.register_function(0x08B42B24u, &sub_08B42AA0, "sub_08B42AA0");
    runtime.register_function(0x08B42B2Cu, &sub_08B42AA0, "sub_08B42AA0");
    runtime.register_function(0x08B42B30u, &sub_08B42AA0, "sub_08B42AA0");
    runtime.register_function(0x08B42B34u, &sub_08B42AA0, "sub_08B42AA0");
    runtime.register_function(0x08B42B38u, &sub_08B42AA0, "sub_08B42AA0");
    runtime.register_function(0x08B42B40u, &sub_08B42AA0, "sub_08B42AA0");
    runtime.register_function(0x08B42B44u, &sub_08B42AA0, "sub_08B42AA0");
    runtime.register_function(0x08B42B48u, &sub_08B42AA0, "sub_08B42AA0");
    runtime.register_function(0x08B42B50u, &sub_08B42AA0, "sub_08B42AA0");
    runtime.register_function(0x08B42B54u, &sub_08B42AA0, "sub_08B42AA0");
    runtime.register_function(0x08B42B58u, &sub_08B42AA0, "sub_08B42AA0");
    runtime.register_function(0x08B42B5Cu, &sub_08B42AA0, "sub_08B42AA0");
    runtime.register_function(0x08B42B60u, &sub_08B42AA0, "sub_08B42AA0");
    runtime.register_function(0x08B42B64u, &sub_08B42AA0, "sub_08B42AA0");
    runtime.register_function(0x08B42B68u, &sub_08B42AA0, "sub_08B42AA0");
    runtime.register_function(0x08B42B6Cu, &sub_08B42AA0, "sub_08B42AA0");
    runtime.register_function(0x08B42B70u, &sub_08B42AA0, "sub_08B42AA0");
    runtime.register_function(0x08B42B74u, &sub_08B42AA0, "sub_08B42AA0");
    runtime.register_function(0x08B42B7Cu, &sub_08B42AA0, "sub_08B42AA0");
    runtime.register_function(0x08B42B80u, &sub_08B42AA0, "sub_08B42AA0");
    runtime.register_function(0x08B42B88u, &sub_08B42AA0, "sub_08B42AA0");
    runtime.register_function(0x08B42B8Cu, &sub_08B42AA0, "sub_08B42AA0");
    runtime.register_function(0x08B42B90u, &sub_08B42AA0, "sub_08B42AA0");
    runtime.register_function(0x08B42B94u, &sub_08B42AA0, "sub_08B42AA0");
    runtime.register_function(0x08B42B98u, &sub_08B42AA0, "sub_08B42AA0");
    runtime.register_function(0x08B42B9Cu, &sub_08B42AA0, "sub_08B42AA0");
    runtime.register_function(0x08B43620u, &sub_08B43620, "sub_08B43620");
    runtime.register_function(0x08B43624u, &sub_08B43620, "sub_08B43620");
    runtime.register_function(0x08B43628u, &sub_08B43620, "sub_08B43620");
    runtime.register_function(0x08B4362Cu, &sub_08B43620, "sub_08B43620");
    runtime.register_function(0x08B43634u, &sub_08B43620, "sub_08B43620");
    runtime.register_function(0x08B43638u, &sub_08B43620, "sub_08B43620");
    runtime.register_function(0x08B4363Cu, &sub_08B43620, "sub_08B43620");
    runtime.register_function(0x08B43640u, &sub_08B43620, "sub_08B43620");
    runtime.register_function(0x08B43648u, &sub_08B43620, "sub_08B43620");
    runtime.register_function(0x08B4364Cu, &sub_08B43620, "sub_08B43620");
    runtime.register_function(0x08B43650u, &sub_08B43620, "sub_08B43620");
    runtime.register_function(0x08B43658u, &sub_08B43620, "sub_08B43620");
    runtime.register_function(0x08B43660u, &sub_08B43620, "sub_08B43620");
    runtime.register_function(0x08B43668u, &sub_08B43620, "sub_08B43620");
    runtime.register_function(0x08B4366Cu, &sub_08B43620, "sub_08B43620");
    runtime.register_function(0x08B43674u, &sub_08B43620, "sub_08B43620");
    runtime.register_function(0x08B43678u, &sub_08B43620, "sub_08B43620");
    runtime.register_function(0x08B43680u, &sub_08B43620, "sub_08B43620");
    runtime.register_function(0x08B43684u, &sub_08B43620, "sub_08B43620");
    runtime.register_function(0x08B43688u, &sub_08B43620, "sub_08B43620");
    runtime.register_function(0x08B4368Cu, &sub_08B43620, "sub_08B43620");
    runtime.register_function(0x08B43690u, &sub_08B43620, "sub_08B43620");
    runtime.register_function(0x08B43694u, &sub_08B43620, "sub_08B43620");
    runtime.register_function(0x08B43698u, &sub_08B43620, "sub_08B43620");
    runtime.register_function(0x08B4369Cu, &sub_08B43620, "sub_08B43620");
    runtime.register_function(0x08B436A0u, &sub_08B43620, "sub_08B43620");
    runtime.register_function(0x08B436A4u, &sub_08B43620, "sub_08B43620");
    runtime.register_function(0x08B436A8u, &sub_08B43620, "sub_08B43620");
    runtime.register_function(0x08B436ACu, &sub_08B43620, "sub_08B43620");
    runtime.register_function(0x08B436B0u, &sub_08B43620, "sub_08B43620");
    runtime.register_function(0x08B436B8u, &sub_08B43620, "sub_08B43620");
    runtime.register_function(0x08B436BCu, &sub_08B43620, "sub_08B43620");
    runtime.register_function(0x08B436C0u, &sub_08B43620, "sub_08B43620");
    runtime.register_function(0x08B436C8u, &sub_08B43620, "sub_08B43620");
    runtime.register_function(0x08B436CCu, &sub_08B43620, "sub_08B43620");
    runtime.register_function(0x08B436D0u, &sub_08B43620, "sub_08B43620");
    runtime.register_function(0x08B436D8u, &sub_08B43620, "sub_08B43620");
    runtime.register_function(0x08B436DCu, &sub_08B43620, "sub_08B43620");
    runtime.register_function(0x08B436E0u, &sub_08B43620, "sub_08B43620");
    runtime.register_function(0x08B436E4u, &sub_08B43620, "sub_08B43620");
    runtime.register_function(0x08B436E8u, &sub_08B43620, "sub_08B43620");
    runtime.register_function(0x08B436F0u, &sub_08B43620, "sub_08B43620");
    runtime.register_function(0x08B436F4u, &sub_08B43620, "sub_08B43620");
    runtime.register_function(0x08B436FCu, &sub_08B43620, "sub_08B43620");
    runtime.register_function(0x08B43700u, &sub_08B43620, "sub_08B43620");
    runtime.register_function(0x08B43704u, &sub_08B43620, "sub_08B43620");
    runtime.register_function(0x08B43708u, &sub_08B43620, "sub_08B43620");
    runtime.register_function(0x08B4370Cu, &sub_08B43620, "sub_08B43620");
    runtime.register_function(0x08B43710u, &sub_08B43620, "sub_08B43620");
    runtime.register_function(0x08B43714u, &sub_08B43620, "sub_08B43620");
    runtime.register_function(0x08B43718u, &sub_08B43620, "sub_08B43620");
    runtime.register_function(0x08B4371Cu, &sub_08B43620, "sub_08B43620");
    runtime.register_function(0x08B44750u, &sub_08B44750, "sub_08B44750");
    runtime.register_function(0x08B44754u, &sub_08B44750, "sub_08B44750");
    runtime.register_function(0x08B44758u, &sub_08B44750, "sub_08B44750");
    runtime.register_function(0x08B4475Cu, &sub_08B44750, "sub_08B44750");
    runtime.register_function(0x08B44760u, &sub_08B44750, "sub_08B44750");
    runtime.register_function(0x08B44768u, &sub_08B44750, "sub_08B44750");
    runtime.register_function(0x08B4476Cu, &sub_08B44750, "sub_08B44750");
    runtime.register_function(0x08B44770u, &sub_08B44750, "sub_08B44750");
    runtime.register_function(0x08B44778u, &sub_08B44750, "sub_08B44750");
    runtime.register_function(0x08B44780u, &sub_08B44750, "sub_08B44750");
    runtime.register_function(0x08B44788u, &sub_08B44750, "sub_08B44750");
    runtime.register_function(0x08B4478Cu, &sub_08B44750, "sub_08B44750");
    runtime.register_function(0x08B44794u, &sub_08B44750, "sub_08B44750");
    runtime.register_function(0x08B44798u, &sub_08B44750, "sub_08B44750");
    runtime.register_function(0x08B4479Cu, &sub_08B44750, "sub_08B44750");
    runtime.register_function(0x08B447A0u, &sub_08B44750, "sub_08B44750");
    runtime.register_function(0x08B447A4u, &sub_08B44750, "sub_08B44750");
    runtime.register_function(0x08B447A8u, &sub_08B44750, "sub_08B44750");
    runtime.register_function(0x08B447ACu, &sub_08B44750, "sub_08B44750");
    runtime.register_function(0x08B447B0u, &sub_08B44750, "sub_08B44750");
    runtime.register_function(0x08B447B4u, &sub_08B44750, "sub_08B44750");
    runtime.register_function(0x08B447B8u, &sub_08B44750, "sub_08B44750");
    runtime.register_function(0x08B447BCu, &sub_08B44750, "sub_08B44750");
    runtime.register_function(0x08B447C0u, &sub_08B44750, "sub_08B44750");
    runtime.register_function(0x08B447C4u, &sub_08B44750, "sub_08B44750");
    runtime.register_function(0x08B447C8u, &sub_08B44750, "sub_08B44750");
    runtime.register_function(0x08B447CCu, &sub_08B44750, "sub_08B44750");
    runtime.register_function(0x08B447D0u, &sub_08B44750, "sub_08B44750");
    runtime.register_function(0x08B447D4u, &sub_08B44750, "sub_08B44750");
    runtime.register_function(0x08B447D8u, &sub_08B44750, "sub_08B44750");
    runtime.register_function(0x08B447DCu, &sub_08B44750, "sub_08B44750");
    runtime.register_function(0x08B447E4u, &sub_08B44750, "sub_08B44750");
    runtime.register_function(0x08B447E8u, &sub_08B44750, "sub_08B44750");
    runtime.register_function(0x08B447ECu, &sub_08B44750, "sub_08B44750");
    runtime.register_function(0x08B447F0u, &sub_08B44750, "sub_08B44750");
    runtime.register_function(0x08B447F4u, &sub_08B44750, "sub_08B44750");
    runtime.register_function(0x08B447F8u, &sub_08B44750, "sub_08B44750");
    runtime.register_function(0x08B447FCu, &sub_08B44750, "sub_08B44750");
    runtime.register_function(0x08B44800u, &sub_08B44750, "sub_08B44750");
    runtime.register_function(0x08B44804u, &sub_08B44750, "sub_08B44750");
    runtime.register_function(0x08B44808u, &sub_08B44750, "sub_08B44750");
    runtime.register_function(0x08B44810u, &sub_08B44750, "sub_08B44750");
    runtime.register_function(0x08B44818u, &sub_08B44750, "sub_08B44750");
    runtime.register_function(0x08B44820u, &sub_08B44750, "sub_08B44750");
    runtime.register_function(0x08B44824u, &sub_08B44750, "sub_08B44750");
    runtime.register_function(0x08B44828u, &sub_08B44750, "sub_08B44750");
    runtime.register_function(0x08B4482Cu, &sub_08B44750, "sub_08B44750");
    runtime.register_function(0x08B44830u, &sub_08B44750, "sub_08B44750");
    runtime.register_function(0x08B44834u, &sub_08B44750, "sub_08B44750");
    runtime.register_function(0x08B44838u, &sub_08B44750, "sub_08B44750");
    runtime.register_function(0x08B4483Cu, &sub_08B44750, "sub_08B44750");
    runtime.register_function(0x08B44840u, &sub_08B44750, "sub_08B44750");
    runtime.register_function(0x08B44844u, &sub_08B44750, "sub_08B44750");
    runtime.register_function(0x08B44848u, &sub_08B44750, "sub_08B44750");
    runtime.register_function(0x08B4484Cu, &sub_08B44750, "sub_08B44750");
    runtime.register_function(0x08B45444u, &sub_08B45444, "sub_08B45444");
    runtime.register_function(0x08B45448u, &sub_08B45444, "sub_08B45444");
    runtime.register_function(0x08B4544Cu, &sub_08B45444, "sub_08B45444");
    runtime.register_function(0x08B45454u, &sub_08B45444, "sub_08B45444");
    runtime.register_function(0x08B45458u, &sub_08B45444, "sub_08B45444");
    runtime.register_function(0x08B4545Cu, &sub_08B45444, "sub_08B45444");
    runtime.register_function(0x08B45464u, &sub_08B45444, "sub_08B45444");
    runtime.register_function(0x08B4546Cu, &sub_08B45444, "sub_08B45444");
    runtime.register_function(0x08B45474u, &sub_08B45444, "sub_08B45444");
    runtime.register_function(0x08B45478u, &sub_08B45444, "sub_08B45444");
    runtime.register_function(0x08B45480u, &sub_08B45444, "sub_08B45444");
    runtime.register_function(0x08B45484u, &sub_08B45444, "sub_08B45444");
    runtime.register_function(0x08B45488u, &sub_08B45444, "sub_08B45444");
    runtime.register_function(0x08B4548Cu, &sub_08B45444, "sub_08B45444");
    runtime.register_function(0x08B45490u, &sub_08B45444, "sub_08B45444");
    runtime.register_function(0x08B45494u, &sub_08B45444, "sub_08B45444");
    runtime.register_function(0x08B45498u, &sub_08B45444, "sub_08B45444");
    runtime.register_function(0x08B4549Cu, &sub_08B45444, "sub_08B45444");
    runtime.register_function(0x08B454A4u, &sub_08B45444, "sub_08B45444");
    runtime.register_function(0x08B454ACu, &sub_08B45444, "sub_08B45444");
    runtime.register_function(0x08B454B0u, &sub_08B45444, "sub_08B45444");
    runtime.register_function(0x08B454B4u, &sub_08B45444, "sub_08B45444");
    runtime.register_function(0x08B454B8u, &sub_08B45444, "sub_08B45444");
    runtime.register_function(0x08B454BCu, &sub_08B45444, "sub_08B45444");
    runtime.register_function(0x08B454C0u, &sub_08B45444, "sub_08B45444");
    runtime.register_function(0x08B454C4u, &sub_08B45444, "sub_08B45444");
    runtime.register_function(0x08B454CCu, &sub_08B45444, "sub_08B45444");
    runtime.register_function(0x08B454D0u, &sub_08B45444, "sub_08B45444");
    runtime.register_function(0x08B454D4u, &sub_08B45444, "sub_08B45444");
    runtime.register_function(0x08B454D8u, &sub_08B45444, "sub_08B45444");
    runtime.register_function(0x08B454DCu, &sub_08B45444, "sub_08B45444");
    runtime.register_function(0x08B454E0u, &sub_08B45444, "sub_08B45444");
    runtime.register_function(0x08B454E4u, &sub_08B45444, "sub_08B45444");
    runtime.register_function(0x08B454E8u, &sub_08B45444, "sub_08B45444");
    runtime.register_function(0x08B454ECu, &sub_08B45444, "sub_08B45444");
    runtime.register_function(0x08B454F4u, &sub_08B45444, "sub_08B45444");
    runtime.register_function(0x08B454F8u, &sub_08B45444, "sub_08B45444");
    runtime.register_function(0x08B454FCu, &sub_08B45444, "sub_08B45444");
    runtime.register_function(0x08B45500u, &sub_08B45444, "sub_08B45444");
    runtime.register_function(0x08B45504u, &sub_08B45444, "sub_08B45444");
    runtime.register_function(0x08B45508u, &sub_08B45444, "sub_08B45444");
    runtime.register_function(0x08B4550Cu, &sub_08B45444, "sub_08B45444");
    runtime.register_function(0x08B45514u, &sub_08B45444, "sub_08B45444");
    runtime.register_function(0x08B4551Cu, &sub_08B45444, "sub_08B45444");
    runtime.register_function(0x08B45520u, &sub_08B45444, "sub_08B45444");
    runtime.register_function(0x08B45524u, &sub_08B45444, "sub_08B45444");
    runtime.register_function(0x08B45528u, &sub_08B45444, "sub_08B45444");
    runtime.register_function(0x08B4552Cu, &sub_08B45444, "sub_08B45444");
    runtime.register_function(0x08B45530u, &sub_08B45444, "sub_08B45444");
    runtime.register_function(0x08B45534u, &sub_08B45444, "sub_08B45444");
    runtime.register_function(0x08B4553Cu, &sub_08B45444, "sub_08B45444");
    runtime.register_function(0x08B45540u, &sub_08B45444, "sub_08B45444");
    runtime.register_function(0x08B53B88u, &sub_08B53B88, "sub_08B53B88");
    runtime.register_function(0x08B53B8Cu, &sub_08B53B88, "sub_08B53B88");
    runtime.register_function(0x08B53B90u, &sub_08B53B88, "sub_08B53B88");
    runtime.register_function(0x08B53B94u, &sub_08B53B88, "sub_08B53B88");
    runtime.register_function(0x08B53B98u, &sub_08B53B88, "sub_08B53B88");
    runtime.register_function(0x08B53B9Cu, &sub_08B53B88, "sub_08B53B88");
    runtime.register_function(0x08B53BA0u, &sub_08B53B88, "sub_08B53B88");
    runtime.register_function(0x08B53BA4u, &sub_08B53B88, "sub_08B53B88");
    runtime.register_function(0x08B53BA8u, &sub_08B53B88, "sub_08B53B88");
    runtime.register_function(0x08B53BB0u, &sub_08B53B88, "sub_08B53B88");
    runtime.register_function(0x08B53BB4u, &sub_08B53B88, "sub_08B53B88");
    runtime.register_function(0x08B53BB8u, &sub_08B53B88, "sub_08B53B88");
    runtime.register_function(0x08B53BBCu, &sub_08B53B88, "sub_08B53B88");
    runtime.register_function(0x08B53BC0u, &sub_08B53B88, "sub_08B53B88");
    runtime.register_function(0x08B53BC4u, &sub_08B53B88, "sub_08B53B88");
    runtime.register_function(0x08B53BC8u, &sub_08B53B88, "sub_08B53B88");
    runtime.register_function(0x08B53BCCu, &sub_08B53B88, "sub_08B53B88");
    runtime.register_function(0x08B53BD4u, &sub_08B53B88, "sub_08B53B88");
    runtime.register_function(0x08B53BD8u, &sub_08B53B88, "sub_08B53B88");
    runtime.register_function(0x08B53BDCu, &sub_08B53B88, "sub_08B53B88");
    runtime.register_function(0x08B53BE0u, &sub_08B53B88, "sub_08B53B88");
    runtime.register_function(0x08B53BE4u, &sub_08B53B88, "sub_08B53B88");
    runtime.register_function(0x08B53BE8u, &sub_08B53B88, "sub_08B53B88");
    runtime.register_function(0x08B53BECu, &sub_08B53B88, "sub_08B53B88");
    runtime.register_function(0x08B53BF0u, &sub_08B53B88, "sub_08B53B88");
    runtime.register_function(0x08B53BF4u, &sub_08B53B88, "sub_08B53B88");
    runtime.register_function(0x08B53BF8u, &sub_08B53B88, "sub_08B53B88");
    runtime.register_function(0x08B53BFCu, &sub_08B53B88, "sub_08B53B88");
    runtime.register_function(0x08B53C00u, &sub_08B53B88, "sub_08B53B88");
    runtime.register_function(0x08B53C04u, &sub_08B53B88, "sub_08B53B88");
    runtime.register_function(0x08B53C0Cu, &sub_08B53B88, "sub_08B53B88");
    runtime.register_function(0x08B53C10u, &sub_08B53B88, "sub_08B53B88");
    runtime.register_function(0x08B53C14u, &sub_08B53B88, "sub_08B53B88");
    runtime.register_function(0x08B53C1Cu, &sub_08B53B88, "sub_08B53B88");
    runtime.register_function(0x08B53C20u, &sub_08B53B88, "sub_08B53B88");
    runtime.register_function(0x08B53C24u, &sub_08B53B88, "sub_08B53B88");
    runtime.register_function(0x08B53C28u, &sub_08B53B88, "sub_08B53B88");
    runtime.register_function(0x08B53C2Cu, &sub_08B53B88, "sub_08B53B88");
    runtime.register_function(0x08B53C30u, &sub_08B53B88, "sub_08B53B88");
    runtime.register_function(0x08B53C34u, &sub_08B53B88, "sub_08B53B88");
    runtime.register_function(0x08B53C3Cu, &sub_08B53B88, "sub_08B53B88");
    runtime.register_function(0x08B53C40u, &sub_08B53B88, "sub_08B53B88");
    runtime.register_function(0x08B53C44u, &sub_08B53B88, "sub_08B53B88");
    runtime.register_function(0x08B53C48u, &sub_08B53B88, "sub_08B53B88");
    runtime.register_function(0x08B53C4Cu, &sub_08B53B88, "sub_08B53B88");
    runtime.register_function(0x08B53C50u, &sub_08B53B88, "sub_08B53B88");
    runtime.register_function(0x08B53C54u, &sub_08B53B88, "sub_08B53B88");
    runtime.register_function(0x08B53C5Cu, &sub_08B53B88, "sub_08B53B88");
    runtime.register_function(0x08B53C60u, &sub_08B53B88, "sub_08B53B88");
    runtime.register_function(0x08B53C64u, &sub_08B53B88, "sub_08B53B88");
    runtime.register_function(0x08B53C68u, &sub_08B53B88, "sub_08B53B88");
    runtime.register_function(0x08B53C6Cu, &sub_08B53B88, "sub_08B53B88");
    runtime.register_function(0x08B53C70u, &sub_08B53B88, "sub_08B53B88");
    runtime.register_function(0x08B53C74u, &sub_08B53B88, "sub_08B53B88");
    runtime.register_function(0x08B53C78u, &sub_08B53B88, "sub_08B53B88");
    runtime.register_function(0x08B53C80u, &sub_08B53B88, "sub_08B53B88");
    runtime.register_function(0x08B53C84u, &sub_08B53B88, "sub_08B53B88");
    runtime.register_function(0x08B54060u, &sub_08B54060, "sub_08B54060");
    runtime.register_function(0x08B54064u, &sub_08B54060, "sub_08B54060");
    runtime.register_function(0x08B54068u, &sub_08B54060, "sub_08B54060");
    runtime.register_function(0x08B5406Cu, &sub_08B54060, "sub_08B54060");
    runtime.register_function(0x08B54070u, &sub_08B54060, "sub_08B54060");
    runtime.register_function(0x08B54074u, &sub_08B54060, "sub_08B54060");
    runtime.register_function(0x08B54078u, &sub_08B54060, "sub_08B54060");
    runtime.register_function(0x08B5407Cu, &sub_08B54060, "sub_08B54060");
    runtime.register_function(0x08B54080u, &sub_08B54060, "sub_08B54060");
    runtime.register_function(0x08B54088u, &sub_08B54060, "sub_08B54060");
    runtime.register_function(0x08B5408Cu, &sub_08B54060, "sub_08B54060");
    runtime.register_function(0x08B54090u, &sub_08B54060, "sub_08B54060");
    runtime.register_function(0x08B54094u, &sub_08B54060, "sub_08B54060");
    runtime.register_function(0x08B54098u, &sub_08B54060, "sub_08B54060");
    runtime.register_function(0x08B5409Cu, &sub_08B54060, "sub_08B54060");
    runtime.register_function(0x08B540A0u, &sub_08B54060, "sub_08B54060");
    runtime.register_function(0x08B540A4u, &sub_08B54060, "sub_08B54060");
    runtime.register_function(0x08B540A8u, &sub_08B54060, "sub_08B54060");
    runtime.register_function(0x08B540ACu, &sub_08B54060, "sub_08B54060");
    runtime.register_function(0x08B540B0u, &sub_08B54060, "sub_08B54060");
    runtime.register_function(0x08B540B4u, &sub_08B54060, "sub_08B54060");
    runtime.register_function(0x08B540B8u, &sub_08B54060, "sub_08B54060");
    runtime.register_function(0x08B540BCu, &sub_08B54060, "sub_08B54060");
    runtime.register_function(0x08B540C0u, &sub_08B54060, "sub_08B54060");
    runtime.register_function(0x08B540C4u, &sub_08B54060, "sub_08B54060");
    runtime.register_function(0x08B540C8u, &sub_08B54060, "sub_08B54060");
    runtime.register_function(0x08B540CCu, &sub_08B54060, "sub_08B54060");
    runtime.register_function(0x08B540D4u, &sub_08B54060, "sub_08B54060");
    runtime.register_function(0x08B540D8u, &sub_08B54060, "sub_08B54060");
    runtime.register_function(0x08B540DCu, &sub_08B54060, "sub_08B54060");
    runtime.register_function(0x08B540E0u, &sub_08B54060, "sub_08B54060");
    runtime.register_function(0x08B540E4u, &sub_08B54060, "sub_08B54060");
    runtime.register_function(0x08B540E8u, &sub_08B54060, "sub_08B54060");
    runtime.register_function(0x08B540F0u, &sub_08B54060, "sub_08B54060");
    runtime.register_function(0x08B540F8u, &sub_08B54060, "sub_08B54060");
    runtime.register_function(0x08B540FCu, &sub_08B54060, "sub_08B54060");
    runtime.register_function(0x08B54104u, &sub_08B54060, "sub_08B54060");
    runtime.register_function(0x08B54108u, &sub_08B54060, "sub_08B54060");
    runtime.register_function(0x08B54110u, &sub_08B54060, "sub_08B54060");
    runtime.register_function(0x08B54114u, &sub_08B54060, "sub_08B54060");
    runtime.register_function(0x08B54118u, &sub_08B54060, "sub_08B54060");
    runtime.register_function(0x08B5411Cu, &sub_08B54060, "sub_08B54060");
    runtime.register_function(0x08B54124u, &sub_08B54060, "sub_08B54060");
    runtime.register_function(0x08B54128u, &sub_08B54060, "sub_08B54060");
    runtime.register_function(0x08B5412Cu, &sub_08B54060, "sub_08B54060");
    runtime.register_function(0x08B54130u, &sub_08B54060, "sub_08B54060");
    runtime.register_function(0x08B54138u, &sub_08B54060, "sub_08B54060");
    runtime.register_function(0x08B5413Cu, &sub_08B54060, "sub_08B54060");
    runtime.register_function(0x08B54140u, &sub_08B54060, "sub_08B54060");
    runtime.register_function(0x08B54144u, &sub_08B54060, "sub_08B54060");
    runtime.register_function(0x08B5414Cu, &sub_08B54060, "sub_08B54060");
    runtime.register_function(0x08B54154u, &sub_08B54060, "sub_08B54060");
    runtime.register_function(0x08B54158u, &sub_08B54060, "sub_08B54060");
    runtime.register_function(0x08B5415Cu, &sub_08B54060, "sub_08B54060");
    runtime.register_function(0x08B58B30u, &sub_08B58B30, "sub_08B58B30");
    runtime.register_function(0x08B58B38u, &sub_08B58B30, "sub_08B58B30");
    runtime.register_function(0x08B58B3Cu, &sub_08B58B30, "sub_08B58B30");
    runtime.register_function(0x08B58B40u, &sub_08B58B30, "sub_08B58B30");
    runtime.register_function(0x08B58B48u, &sub_08B58B30, "sub_08B58B30");
    runtime.register_function(0x08B58B50u, &sub_08B58B30, "sub_08B58B30");
    runtime.register_function(0x08B58B58u, &sub_08B58B30, "sub_08B58B30");
    runtime.register_function(0x08B58B5Cu, &sub_08B58B30, "sub_08B58B30");
    runtime.register_function(0x08B58B64u, &sub_08B58B30, "sub_08B58B30");
    runtime.register_function(0x08B58B68u, &sub_08B58B30, "sub_08B58B30");
    runtime.register_function(0x08B58B70u, &sub_08B58B30, "sub_08B58B30");
    runtime.register_function(0x08B58B78u, &sub_08B58B30, "sub_08B58B30");
    runtime.register_function(0x08B58B7Cu, &sub_08B58B30, "sub_08B58B30");
    runtime.register_function(0x08B58B80u, &sub_08B58B30, "sub_08B58B30");
    runtime.register_function(0x08B58B84u, &sub_08B58B30, "sub_08B58B30");
    runtime.register_function(0x08B58B88u, &sub_08B58B30, "sub_08B58B30");
    runtime.register_function(0x08B58B90u, &sub_08B58B30, "sub_08B58B30");
    runtime.register_function(0x08B58B94u, &sub_08B58B30, "sub_08B58B30");
    runtime.register_function(0x08B58B98u, &sub_08B58B30, "sub_08B58B30");
    runtime.register_function(0x08B58B9Cu, &sub_08B58B30, "sub_08B58B30");
    runtime.register_function(0x08B58BA0u, &sub_08B58B30, "sub_08B58B30");
    runtime.register_function(0x08B58BA4u, &sub_08B58B30, "sub_08B58B30");
    runtime.register_function(0x08B58BA8u, &sub_08B58B30, "sub_08B58B30");
    runtime.register_function(0x08B58BACu, &sub_08B58B30, "sub_08B58B30");
    runtime.register_function(0x08B58BB0u, &sub_08B58B30, "sub_08B58B30");
    runtime.register_function(0x08B58BB4u, &sub_08B58B30, "sub_08B58B30");
    runtime.register_function(0x08B58BB8u, &sub_08B58B30, "sub_08B58B30");
    runtime.register_function(0x08B58BBCu, &sub_08B58B30, "sub_08B58B30");
    runtime.register_function(0x08B58BC0u, &sub_08B58B30, "sub_08B58B30");
    runtime.register_function(0x08B58BC4u, &sub_08B58B30, "sub_08B58B30");
    runtime.register_function(0x08B58BC8u, &sub_08B58B30, "sub_08B58B30");
    runtime.register_function(0x08B58BCCu, &sub_08B58B30, "sub_08B58B30");
    runtime.register_function(0x08B58BD0u, &sub_08B58B30, "sub_08B58B30");
    runtime.register_function(0x08B58BD8u, &sub_08B58B30, "sub_08B58B30");
    runtime.register_function(0x08B58BDCu, &sub_08B58B30, "sub_08B58B30");
    runtime.register_function(0x08B58BE0u, &sub_08B58B30, "sub_08B58B30");
    runtime.register_function(0x08B58BE4u, &sub_08B58B30, "sub_08B58B30");
    runtime.register_function(0x08B58BE8u, &sub_08B58B30, "sub_08B58B30");
    runtime.register_function(0x08B58BECu, &sub_08B58B30, "sub_08B58B30");
    runtime.register_function(0x08B58BF0u, &sub_08B58B30, "sub_08B58B30");
    runtime.register_function(0x08B58BF4u, &sub_08B58B30, "sub_08B58B30");
    runtime.register_function(0x08B58BFCu, &sub_08B58B30, "sub_08B58B30");
    runtime.register_function(0x08B58C04u, &sub_08B58B30, "sub_08B58B30");
    runtime.register_function(0x08B58C08u, &sub_08B58B30, "sub_08B58B30");
    runtime.register_function(0x08B58C0Cu, &sub_08B58B30, "sub_08B58B30");
    runtime.register_function(0x08B58C10u, &sub_08B58B30, "sub_08B58B30");
    runtime.register_function(0x08B58C14u, &sub_08B58B30, "sub_08B58B30");
    runtime.register_function(0x08B58C18u, &sub_08B58B30, "sub_08B58B30");
    runtime.register_function(0x08B58C1Cu, &sub_08B58B30, "sub_08B58B30");
    runtime.register_function(0x08B58C24u, &sub_08B58B30, "sub_08B58B30");
    runtime.register_function(0x08B58C28u, &sub_08B58B30, "sub_08B58B30");
    runtime.register_function(0x08B58C2Cu, &sub_08B58B30, "sub_08B58B30");
}
} } // namespace ovl_menu psprecomp
