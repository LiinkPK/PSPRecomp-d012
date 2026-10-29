#include "psprecomp/runtime.hpp"
#include <cstdint>

namespace psprecomp {
void register_recomp_unit_0(Runtime &runtime);
void register_recomp_unit_1(Runtime &runtime);
void register_recomp_unit_2(Runtime &runtime);
void register_recomp_unit_3(Runtime &runtime);
void register_recomp_unit_4(Runtime &runtime);
void register_recomp_unit_5(Runtime &runtime);
void register_recomp_unit_6(Runtime &runtime);
void register_recomp_unit_7(Runtime &runtime);
void register_recomp_unit_8(Runtime &runtime);
void register_recomp_unit_9(Runtime &runtime);
void register_recomp_unit_10(Runtime &runtime);
void register_recomp_unit_11(Runtime &runtime);
void register_recomp_unit_12(Runtime &runtime);
void register_recomp_unit_13(Runtime &runtime);
void register_recomp_unit_14(Runtime &runtime);
void register_recomp_unit_15(Runtime &runtime);
void register_recomp_unit_16(Runtime &runtime);
void register_recomp_unit_17(Runtime &runtime);
void register_recomp_unit_18(Runtime &runtime);
void register_recomp_unit_19(Runtime &runtime);
void register_recomp_unit_20(Runtime &runtime);
void register_recomp_unit_21(Runtime &runtime);
void register_recomp_unit_22(Runtime &runtime);
void register_recomp_unit_23(Runtime &runtime);
void register_recomp_unit_24(Runtime &runtime);
void register_recomp_unit_25(Runtime &runtime);
void register_recomp_unit_26(Runtime &runtime);
void register_recomp_unit_27(Runtime &runtime);
void register_recomp_unit_28(Runtime &runtime);
void register_recomp_unit_29(Runtime &runtime);
void register_recomp_unit_30(Runtime &runtime);
void register_recomp_unit_31(Runtime &runtime);
void register_recomp_unit_32(Runtime &runtime);
void register_recomp_unit_33(Runtime &runtime);
void register_recomp_unit_34(Runtime &runtime);
void register_recomp_unit_35(Runtime &runtime);
void register_recomp_unit_36(Runtime &runtime);
void register_recomp_unit_37(Runtime &runtime);
void register_recomp_unit_38(Runtime &runtime);
void register_recomp_unit_39(Runtime &runtime);
void register_recomp_unit_40(Runtime &runtime);
void register_recomp_unit_41(Runtime &runtime);
void register_recomp_unit_42(Runtime &runtime);
void register_recomp_unit_43(Runtime &runtime);
void register_recomp_unit_44(Runtime &runtime);
void register_recomp_unit_45(Runtime &runtime);
void register_recomp_unit_46(Runtime &runtime);
void register_recomp_unit_47(Runtime &runtime);
void register_recomp_unit_48(Runtime &runtime);
void register_recomp_unit_49(Runtime &runtime);
void register_recomp_unit_50(Runtime &runtime);
void register_recomp_unit_51(Runtime &runtime);
void register_recomp_unit_52(Runtime &runtime);
void register_recomp_unit_53(Runtime &runtime);
void register_recomp_unit_54(Runtime &runtime);
void register_recomp_unit_55(Runtime &runtime);
void register_recomp_unit_56(Runtime &runtime);
void register_recomp_unit_57(Runtime &runtime);
void register_recomp_unit_58(Runtime &runtime);
void register_recomp_unit_59(Runtime &runtime);
void register_recomp_unit_60(Runtime &runtime);
void register_recomp_unit_61(Runtime &runtime);
void register_recomp_unit_62(Runtime &runtime);
void register_recomp_unit_63(Runtime &runtime);
void register_recomp_unit_64(Runtime &runtime);
void register_recomp_unit_65(Runtime &runtime);
void register_recomp_unit_66(Runtime &runtime);
void register_recomp_unit_67(Runtime &runtime);
void register_recomp_unit_68(Runtime &runtime);
void register_recomp_unit_69(Runtime &runtime);
void register_recomp_unit_70(Runtime &runtime);
void register_recomp_unit_71(Runtime &runtime);
void register_recomp_unit_72(Runtime &runtime);
void register_recomp_unit_73(Runtime &runtime);
void register_recomp_unit_74(Runtime &runtime);
void register_recomp_unit_75(Runtime &runtime);
void register_recomp_unit_76(Runtime &runtime);
void register_recomp_unit_77(Runtime &runtime);
void register_recomp_unit_78(Runtime &runtime);
void register_recomp_unit_79(Runtime &runtime);
void register_recomp_unit_80(Runtime &runtime);
void register_recomp_unit_81(Runtime &runtime);
void register_recomp_unit_82(Runtime &runtime);
void register_recomp_unit_83(Runtime &runtime);
void register_recomp_unit_84(Runtime &runtime);
void register_recomp_unit_85(Runtime &runtime);
void register_recomp_unit_86(Runtime &runtime);
void register_recomp_unit_87(Runtime &runtime);
void register_recomp_unit_88(Runtime &runtime);
void register_recomp_unit_89(Runtime &runtime);
void register_recomp_unit_90(Runtime &runtime);
void register_recomp_unit_91(Runtime &runtime);
void register_recomp_unit_92(Runtime &runtime);
void register_recomp_unit_93(Runtime &runtime);
void register_recomp_unit_94(Runtime &runtime);
void register_recomp_unit_95(Runtime &runtime);
void register_recomp_unit_96(Runtime &runtime);
void register_recomp_unit_97(Runtime &runtime);
void register_recomp_unit_98(Runtime &runtime);
void register_recomp_unit_99(Runtime &runtime);
void register_recomp_unit_100(Runtime &runtime);
void register_recomp_unit_101(Runtime &runtime);
void register_recomp_unit_102(Runtime &runtime);
void register_recomp_unit_103(Runtime &runtime);
void register_recomp_unit_104(Runtime &runtime);
void register_recomp_unit_105(Runtime &runtime);
void register_recomp_unit_106(Runtime &runtime);
void register_recomp_unit_107(Runtime &runtime);
void register_recomp_unit_108(Runtime &runtime);
void register_recomp_unit_109(Runtime &runtime);
void register_recomp_unit_110(Runtime &runtime);
void register_recomp_unit_111(Runtime &runtime);
void register_recomp_unit_112(Runtime &runtime);

static void import_0(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(0u, "sceNetAdhocMatching", 0x2A2A1E07u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_1(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(1u, "sceNetAdhocMatching", 0x32B156B3u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_2(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(2u, "sceNetAdhocMatching", 0x5E3D4B79u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_3(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(3u, "sceNetAdhocMatching", 0x7945ECDAu, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_4(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(4u, "sceNetAdhocMatching", 0x93EF3843u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_5(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(5u, "sceNetAdhocMatching", 0xB58E61B7u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_6(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(6u, "sceNetAdhocMatching", 0xCA5EDA6Fu, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_7(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(7u, "sceNetAdhocMatching", 0xEA3C6108u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_8(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(8u, "sceNetAdhocMatching", 0xF16EAF4Fu, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_9(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(9u, "sceNetAdhocMatching", 0xF79472D7u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_10(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(10u, "ModuleMgrForUser", 0x2E0911AAu, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_11(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(11u, "ModuleMgrForUser", 0x50F0C1ECu, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_12(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(12u, "ModuleMgrForUser", 0x8F2DF740u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_13(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(13u, "ModuleMgrForUser", 0x977DE386u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_14(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(14u, "ModuleMgrForUser", 0xD1FF982Au, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_15(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(15u, "ModuleMgrForUser", 0xD8B73127u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_16(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(16u, "ModuleMgrForUser", 0xF0A26395u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_17(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(17u, "scePower", 0x04B7766Eu, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_18(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(18u, "scePower", 0x469989ADu, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_19(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(19u, "scePower", 0xA85880D0u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_20(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(20u, "scePower", 0xDFA8BAF8u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_21(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(21u, "scePower", 0xFDB5BFE9u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_22(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(22u, "sceUtility", 0x0251B134u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_23(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(23u, "sceUtility", 0x2A2B3DE0u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_24(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(24u, "sceUtility", 0x2AD8E239u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_25(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(25u, "sceUtility", 0x34B78343u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_26(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(26u, "sceUtility", 0x3DFAEBA9u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_27(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(27u, "sceUtility", 0x4928BD96u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_28(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(28u, "sceUtility", 0x4B85C861u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_29(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(29u, "sceUtility", 0x50C4CD57u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_30(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(30u, "sceUtility", 0x67AF3428u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_31(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(31u, "sceUtility", 0x8874DBE0u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_32(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(32u, "sceUtility", 0x95FC253Bu, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_33(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(33u, "sceUtility", 0x9790B33Cu, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_34(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(34u, "sceUtility", 0x9A1C91D7u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_35(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(35u, "sceUtility", 0xA5DA2406u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_36(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(36u, "sceUtility", 0xAB083EA9u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_37(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(37u, "sceUtility", 0xD4B95FFBu, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_38(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(38u, "sceUtility", 0xD81957B7u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_39(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(39u, "sceUtility", 0xE49BFE92u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_40(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(40u, "sceUtility", 0xF3F76017u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_41(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(41u, "sceUtility", 0xF6269B82u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_42(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(42u, "sceUtility", 0xF9E0008Cu, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_43(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(43u, "sceLibFont", 0x0DA7535Eu, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_44(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(44u, "sceLibFont", 0x27F6E642u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_45(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(45u, "sceLibFont", 0x3AEA8CB6u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_46(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(46u, "sceLibFont", 0x67F17ED7u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_47(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(47u, "sceLibFont", 0x681E61A7u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_48(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(48u, "sceLibFont", 0x980F4895u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_49(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(49u, "sceLibFont", 0xA834319Du, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_50(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(50u, "sceLibFont", 0xBC75D85Bu, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_51(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(51u, "sceLibFont", 0xDCC80C2Fu, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_52(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(52u, "sceLibFont", 0xEE232411u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_53(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(53u, "sceWlanDrv", 0x0C622081u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_54(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(54u, "sceWlanDrv", 0xD7763699u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_55(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(55u, "sceNetAdhocDiscover", 0x52DE1B97u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_56(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(56u, "sceNetAdhocDiscover", 0x941B3877u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_57(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(57u, "sceNetAdhocDiscover", 0x944DDBC6u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_58(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(58u, "sceNetAdhocDiscover", 0xA2246614u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_59(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(59u, "sceNetAdhocctl", 0x08FFF7A0u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_60(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(60u, "sceNetAdhocctl", 0x0AD043EDu, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_61(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(61u, "sceNetAdhocctl", 0x20B317A0u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_62(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(62u, "sceNetAdhocctl", 0x34401D65u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_63(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(63u, "sceNetAdhocctl", 0x5E7F79C9u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_64(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(64u, "sceNetAdhocctl", 0x6402490Bu, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_65(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(65u, "sceNetAdhocctl", 0x81AEE1BEu, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_66(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(66u, "sceNetAdhocctl", 0x8DB83FDCu, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_67(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(67u, "sceNetAdhocctl", 0x9D689E13u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_68(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(68u, "sceNetAdhocctl", 0xE162CB14u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_69(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(69u, "sceNetAdhocctl", 0xE26F226Eu, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_70(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(70u, "sceNetAdhocctl", 0xEC0635C1u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_71(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(71u, "sceNetAdhoc", 0x157E6225u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_72(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(72u, "sceNetAdhoc", 0x4DA4C788u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_73(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(73u, "sceNetAdhoc", 0x6F92741Bu, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_74(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(74u, "sceNetAdhoc", 0x7F27BB5Eu, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_75(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(75u, "sceNetAdhoc", 0x877F6D66u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_76(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(76u, "sceNetAdhoc", 0x8BEA2B3Eu, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_77(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(77u, "sceNetAdhoc", 0x9AC2EEACu, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_78(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(78u, "sceNetAdhoc", 0x9DF81198u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_79(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(79u, "sceNetAdhoc", 0xA62C6F57u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_80(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(80u, "sceNetAdhoc", 0xABED3790u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_81(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(81u, "sceNetAdhoc", 0xB9685118u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_82(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(82u, "sceNetAdhoc", 0xC7C1FC57u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_83(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(83u, "sceNetAdhoc", 0xDFE53E03u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_84(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(84u, "sceNetAdhoc", 0xE08BDAC1u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_85(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(85u, "sceNetAdhoc", 0xE1D621D7u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_86(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(86u, "sceNetAdhoc", 0xFC6FC07Bu, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_87(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(87u, "sceNet", 0x0BF0A3AEu, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_88(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(88u, "sceNet", 0x281928A9u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_89(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(89u, "sceNet", 0x39AF39A6u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_90(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(90u, "sceNet", 0x89360950u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_91(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(91u, "sceGe_user", 0x03444EB4u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_92(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(92u, "sceGe_user", 0x05DB22CEu, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_93(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(93u, "sceGe_user", 0x1C0D95A6u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_94(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(94u, "sceGe_user", 0x1F6752ADu, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_95(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(95u, "sceGe_user", 0x4C06E472u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_96(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(96u, "sceGe_user", 0xA4FC06A4u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_97(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(97u, "sceGe_user", 0xAB49E76Au, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_98(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(98u, "sceGe_user", 0xB287BD61u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_99(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(99u, "sceGe_user", 0xB448EC0Du, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_100(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(100u, "sceGe_user", 0xE0D68148u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_101(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(101u, "sceGe_user", 0xE47E40E4u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_102(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(102u, "sceCtrl", 0x1F4011E6u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_103(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(103u, "sceCtrl", 0x1F803938u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_104(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(104u, "sceCtrl", 0x6A2774F3u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_105(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(105u, "sceDisplay", 0x0E20F177u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_106(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(106u, "sceDisplay", 0x289D82FEu, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_107(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(107u, "sceDisplay", 0x46F186C3u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_108(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(108u, "sceDisplay", 0x984C27E7u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_109(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(109u, "sceDisplay", 0x9C6EAAD7u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_110(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(110u, "sceDisplay", 0xEEDA2E54u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_111(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(111u, "sceDmac", 0x617F3FE6u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_112(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(112u, "sceMpeg", 0x0E3C2E9Du, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_113(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(113u, "sceMpeg", 0x13407F13u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_114(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(114u, "sceMpeg", 0x167AFD9Eu, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_115(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(115u, "sceMpeg", 0x21FF80E4u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_116(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(116u, "sceMpeg", 0x37295ED8u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_117(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(117u, "sceMpeg", 0x42560F23u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_118(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(118u, "sceMpeg", 0x4571CC64u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_119(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(119u, "sceMpeg", 0x591A4AA2u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_120(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(120u, "sceMpeg", 0x606A4649u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_121(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(121u, "sceMpeg", 0x682A619Bu, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_122(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(122u, "sceMpeg", 0x707B7629u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_123(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(123u, "sceMpeg", 0x800C44DFu, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_124(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(124u, "sceMpeg", 0x874624D6u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_125(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(125u, "sceMpeg", 0x8C1E027Du, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_126(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(126u, "sceMpeg", 0xA11C7026u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_127(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(127u, "sceMpeg", 0xA780CF7Eu, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_128(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(128u, "sceMpeg", 0xB240A59Eu, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_129(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(129u, "sceMpeg", 0xB5F6DC87u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_130(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(130u, "sceMpeg", 0xC132E22Fu, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_131(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(131u, "sceMpeg", 0xCEB870B1u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_132(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(132u, "sceMpeg", 0xD7A29F46u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_133(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(133u, "sceMpeg", 0xD8C5F121u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_134(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(134u, "sceMpeg", 0xE1CE83A7u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_135(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(135u, "sceMpeg", 0xF8DCB679u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_136(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(136u, "sceMpeg", 0xFE246728u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_137(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(137u, "sceUmdUser", 0x46EBB729u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_138(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(138u, "sceUmdUser", 0x6B4A146Cu, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_139(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(139u, "sceUmdUser", 0x8EF08FCEu, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_140(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(140u, "sceUmdUser", 0xAEE7404Du, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_141(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(141u, "sceUmdUser", 0xBD2BDE07u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_142(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(142u, "sceUmdUser", 0xC6183D47u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_143(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(143u, "sceSasCore", 0x019B25EBu, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_144(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(144u, "sceSasCore", 0x07F58C24u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_145(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(145u, "sceSasCore", 0x267A6DD2u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_146(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(146u, "sceSasCore", 0x2C8E6AB3u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_147(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(147u, "sceSasCore", 0x33D4AB37u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_148(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(148u, "sceSasCore", 0x42778A9Fu, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_149(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(149u, "sceSasCore", 0x440CA7D8u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_150(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(150u, "sceSasCore", 0x50A14DFCu, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_151(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(151u, "sceSasCore", 0x5F9529F6u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_152(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(152u, "sceSasCore", 0x68A46B95u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_153(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(153u, "sceSasCore", 0x74AE582Au, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_154(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(154u, "sceSasCore", 0x76F01ACAu, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_155(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(155u, "sceSasCore", 0x787D04D5u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_156(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(156u, "sceSasCore", 0x99944089u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_157(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(157u, "sceSasCore", 0x9EC3676Au, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_158(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(158u, "sceSasCore", 0xA0CF2FA4u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_159(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(159u, "sceSasCore", 0xA3589D81u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_160(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(160u, "sceSasCore", 0xAD84D37Fu, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_161(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(161u, "sceSasCore", 0xB7660A23u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_162(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(162u, "sceSasCore", 0xBD11B7C2u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_163(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(163u, "sceSasCore", 0xCBCD4F79u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_164(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(164u, "sceSasCore", 0xD1E0A01Eu, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_165(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(165u, "sceSasCore", 0xD5A229C9u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_166(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(166u, "sceSasCore", 0xE175EF66u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_167(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(167u, "sceSasCore", 0xE1CD9561u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_168(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(168u, "sceSasCore", 0xE855BF76u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_169(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(169u, "sceSasCore", 0xF983B186u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_170(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(170u, "sceAtrac3plus", 0x5D268707u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_171(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(171u, "sceAtrac3plus", 0x61EB33F5u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_172(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(172u, "sceAtrac3plus", 0x644E5607u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_173(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(173u, "sceAtrac3plus", 0x6A8C3CD5u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_174(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(174u, "sceAtrac3plus", 0x7A20E7AFu, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_175(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(175u, "sceAtrac3plus", 0x7DB31251u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_176(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(176u, "sceAtrac3plus", 0x868120B5u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_177(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(177u, "sceAtrac3plus", 0x9AE849A7u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_178(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(178u, "sceAtrac3plus", 0xA2BBA8BEu, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_179(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(179u, "sceAtrac3plus", 0xE88F759Bu, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_180(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(180u, "scesupPreAcc", 0x110E318Bu, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_181(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(181u, "scesupPreAcc", 0x13AE25B3u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_182(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(182u, "scesupPreAcc", 0x28C5F696u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_183(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(183u, "scesupPreAcc", 0x2EC3F4D9u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_184(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(184u, "scesupPreAcc", 0x348BA3E2u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_185(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(185u, "scesupPreAcc", 0x86DEBD66u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_186(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(186u, "scesupPreAcc", 0xA0EAF444u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_187(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(187u, "scesupPreAcc", 0xB03FF882u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_188(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(188u, "scePspNpDrm_user", 0x08D98894u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_189(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(189u, "scePspNpDrm_user", 0xA1336091u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_190(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(190u, "sceImpose", 0x24FD7BCFu, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_191(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(191u, "sceImpose", 0x36AA6E91u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_192(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(192u, "sceRtc", 0x57726BC1u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_193(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(193u, "sceRtc", 0x6FF40ACCu, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_194(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(194u, "sceRtc", 0x7ED29E40u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_195(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(195u, "sceRtc", 0xC41C2853u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_196(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(196u, "sceRtc", 0xE51B4B7Au, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_197(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(197u, "sceRtc", 0xE7C27D1Bu, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_198(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(198u, "sceRtc", 0xF2A4AFE5u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_199(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(199u, "sceAudio", 0x01562BA3u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_200(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(200u, "sceAudio", 0x2D53F36Eu, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_201(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(201u, "sceAudio", 0x43196845u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_202(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(202u, "sceAudio", 0x647CEF33u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_203(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(203u, "sceAudio", 0x136CAF51u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_204(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(204u, "sceAudio", 0x13F592BCu, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_205(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(205u, "sceAudio", 0x5EC81C55u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_206(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(206u, "sceAudio", 0x6FC46853u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_207(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(207u, "sceAudio", 0x95FD0C2Du, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_208(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(208u, "sceAudio", 0xB011922Fu, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_209(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(209u, "sceAudio", 0xB7E1D8E7u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_210(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(210u, "sceAudio", 0xCB2E439Eu, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_211(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(211u, "sceAudio", 0xE2D56B2Du, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_212(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(212u, "IoFileMgrForUser", 0x06A70004u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_213(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(213u, "IoFileMgrForUser", 0x42EC03ACu, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_214(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(214u, "IoFileMgrForUser", 0x54F5FB11u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_215(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(215u, "IoFileMgrForUser", 0x55F4717Du, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_216(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(216u, "IoFileMgrForUser", 0x6A638D83u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_217(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(217u, "IoFileMgrForUser", 0x71B19E77u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_218(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(218u, "IoFileMgrForUser", 0x779103A0u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_219(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(219u, "IoFileMgrForUser", 0x810C4BC3u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_220(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(220u, "IoFileMgrForUser", 0x89AA9906u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_221(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(221u, "IoFileMgrForUser", 0xA0B5A7C2u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_222(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(222u, "IoFileMgrForUser", 0xA12A0514u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_223(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(223u, "IoFileMgrForUser", 0xACE946E8u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_224(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(224u, "IoFileMgrForUser", 0xB29DDF9Cu, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_225(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(225u, "IoFileMgrForUser", 0xB8A740F4u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_226(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(226u, "IoFileMgrForUser", 0xE23EEC33u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_227(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(227u, "IoFileMgrForUser", 0xE3EB004Cu, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_228(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(228u, "IoFileMgrForUser", 0xE95A012Bu, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_229(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(229u, "IoFileMgrForUser", 0xEB092469u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_230(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(230u, "IoFileMgrForUser", 0xF27A9C51u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_231(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(231u, "IoFileMgrForUser", 0x109F50BCu, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_232(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(232u, "IoFileMgrForUser", 0x1117C65Fu, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_233(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(233u, "IoFileMgrForUser", 0x27EB27B8u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_234(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(234u, "IoFileMgrForUser", 0x3251EA56u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_235(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(235u, "Kernel_Library", 0x092968F4u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_236(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(236u, "Kernel_Library", 0xA089ECA4u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_237(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(237u, "Kernel_Library", 0x1839852Au, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_238(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(238u, "Kernel_Library", 0x293B45B8u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_239(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(239u, "Kernel_Library", 0x5F10D406u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_240(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(240u, "LoadExecForUser", 0x05572A5Fu, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_241(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(241u, "LoadExecForUser", 0x4AC57943u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_242(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(242u, "StdioForUser", 0x172D316Eu, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_243(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(243u, "StdioForUser", 0xA6BAB2E9u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_244(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(244u, "StdioForUser", 0xF78BA90Au, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_245(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(245u, "SysMemUserForUser", 0x13A5ABEFu, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_246(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(246u, "SysMemUserForUser", 0xDB83A952u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_247(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(247u, "SysMemUserForUser", 0xF77D77CBu, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_248(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(248u, "SysMemUserForUser", 0xF919F628u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_249(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(249u, "SysMemUserForUser", 0xFE707FDFu, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_250(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(250u, "SysMemUserForUser", 0x1B4217BCu, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_251(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(251u, "SysMemUserForUser", 0x237DBD4Fu, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_252(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(252u, "SysMemUserForUser", 0x50F61D8Au, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_253(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(253u, "SysMemUserForUser", 0x9D9A5BA1u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_254(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(254u, "SysMemUserForUser", 0xB6D61D02u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_255(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(255u, "ThreadManForUser", 0xCEADEB47u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_256(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(256u, "ThreadManForUser", 0xD6DA4BA1u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_257(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(257u, "ThreadManForUser", 0x1FB15A32u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_258(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(258u, "ThreadManForUser", 0xE81CAF8Fu, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_259(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(259u, "ThreadManForUser", 0xEA748E31u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_260(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(260u, "ThreadManForUser", 0xEDBA5844u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_261(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(261u, "ThreadManForUser", 0xEF9E4C70u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_262(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(262u, "ThreadManForUser", 0xF475845Du, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_263(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(263u, "ThreadManForUser", 0x278C0DF5u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_264(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(264u, "ThreadManForUser", 0x28B6489Cu, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_265(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(265u, "ThreadManForUser", 0x369ED59Du, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_266(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(266u, "ThreadManForUser", 0x3F53E640u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_267(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(267u, "ThreadManForUser", 0x402FCF22u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_268(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(268u, "ThreadManForUser", 0x446D8DE6u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_269(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(269u, "ThreadManForUser", 0x4E3A1105u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_270(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(270u, "ThreadManForUser", 0x55C20A00u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_271(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(271u, "ThreadManForUser", 0x616403BAu, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_272(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(272u, "ThreadManForUser", 0x68DA9E36u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_273(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(273u, "ThreadManForUser", 0x71BC9871u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_274(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(274u, "ThreadManForUser", 0x809CE29Bu, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_275(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(275u, "ThreadManForUser", 0x812346E4u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_276(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(276u, "ThreadManForUser", 0x82BC5777u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_277(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(277u, "ThreadManForUser", 0x840E8133u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_278(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(278u, "ThreadManForUser", 0x8FFDF9A2u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_279(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(279u, "ThreadManForUser", 0x9FA03CD3u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_280(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(280u, "ThreadManForUser", 0xAA73C935u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_281(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(281u, "UtilsForUser", 0x71EC4271u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_282(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(282u, "UtilsForUser", 0x79D1C3FAu, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_283(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(283u, "UtilsForUser", 0x91E4F6A7u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_284(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(284u, "UtilsForUser", 0xB435DEC5u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_285(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(285u, "UtilsForUser", 0xBFA98062u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_286(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(286u, "UtilsForUser", 0xC2DF770Eu, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_287(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(287u, "UtilsForUser", 0x27CC57F0u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_288(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(288u, "UtilsForUser", 0x34B9FA9Eu, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_289(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(289u, "UtilsForUser", 0x37FB5C42u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_290(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(290u, "UtilsForUser", 0x3EE30821u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_291(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(291u, "sceSuspendForUser", 0x090CCB3Fu, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_292(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(292u, "sceSuspendForUser", 0x3AEE7261u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_293(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(293u, "sceSuspendForUser", 0x3E0271D3u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_294(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(294u, "sceSuspendForUser", 0xA569E425u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

static void import_295(Runtime &rt, AllegrexContext &ctx) {
    const RuntimeExecutionContextToken caller_context = capture_runtime_execution_context();
    const std::uint32_t import_pc = ctx.pc;
    const std::uint32_t return_address = ctx.gpr[31];
    rt.invoke_import_cached(295u, "sceSuspendForUser", 0xEADB1BD7u, ctx);
    if (!rt.stopped() && runtime_execution_context_matches(caller_context) &&
        ctx.pc == import_pc) ctx.pc = return_address;
}

void register_generated_functions(Runtime &runtime) {
    register_recomp_unit_0(runtime);
    register_recomp_unit_1(runtime);
    register_recomp_unit_2(runtime);
    register_recomp_unit_3(runtime);
    register_recomp_unit_4(runtime);
    register_recomp_unit_5(runtime);
    register_recomp_unit_6(runtime);
    register_recomp_unit_7(runtime);
    register_recomp_unit_8(runtime);
    register_recomp_unit_9(runtime);
    register_recomp_unit_10(runtime);
    register_recomp_unit_11(runtime);
    register_recomp_unit_12(runtime);
    register_recomp_unit_13(runtime);
    register_recomp_unit_14(runtime);
    register_recomp_unit_15(runtime);
    register_recomp_unit_16(runtime);
    register_recomp_unit_17(runtime);
    register_recomp_unit_18(runtime);
    register_recomp_unit_19(runtime);
    register_recomp_unit_20(runtime);
    register_recomp_unit_21(runtime);
    register_recomp_unit_22(runtime);
    register_recomp_unit_23(runtime);
    register_recomp_unit_24(runtime);
    register_recomp_unit_25(runtime);
    register_recomp_unit_26(runtime);
    register_recomp_unit_27(runtime);
    register_recomp_unit_28(runtime);
    register_recomp_unit_29(runtime);
    register_recomp_unit_30(runtime);
    register_recomp_unit_31(runtime);
    register_recomp_unit_32(runtime);
    register_recomp_unit_33(runtime);
    register_recomp_unit_34(runtime);
    register_recomp_unit_35(runtime);
    register_recomp_unit_36(runtime);
    register_recomp_unit_37(runtime);
    register_recomp_unit_38(runtime);
    register_recomp_unit_39(runtime);
    register_recomp_unit_40(runtime);
    register_recomp_unit_41(runtime);
    register_recomp_unit_42(runtime);
    register_recomp_unit_43(runtime);
    register_recomp_unit_44(runtime);
    register_recomp_unit_45(runtime);
    register_recomp_unit_46(runtime);
    register_recomp_unit_47(runtime);
    register_recomp_unit_48(runtime);
    register_recomp_unit_49(runtime);
    register_recomp_unit_50(runtime);
    register_recomp_unit_51(runtime);
    register_recomp_unit_52(runtime);
    register_recomp_unit_53(runtime);
    register_recomp_unit_54(runtime);
    register_recomp_unit_55(runtime);
    register_recomp_unit_56(runtime);
    register_recomp_unit_57(runtime);
    register_recomp_unit_58(runtime);
    register_recomp_unit_59(runtime);
    register_recomp_unit_60(runtime);
    register_recomp_unit_61(runtime);
    register_recomp_unit_62(runtime);
    register_recomp_unit_63(runtime);
    register_recomp_unit_64(runtime);
    register_recomp_unit_65(runtime);
    register_recomp_unit_66(runtime);
    register_recomp_unit_67(runtime);
    register_recomp_unit_68(runtime);
    register_recomp_unit_69(runtime);
    register_recomp_unit_70(runtime);
    register_recomp_unit_71(runtime);
    register_recomp_unit_72(runtime);
    register_recomp_unit_73(runtime);
    register_recomp_unit_74(runtime);
    register_recomp_unit_75(runtime);
    register_recomp_unit_76(runtime);
    register_recomp_unit_77(runtime);
    register_recomp_unit_78(runtime);
    register_recomp_unit_79(runtime);
    register_recomp_unit_80(runtime);
    register_recomp_unit_81(runtime);
    register_recomp_unit_82(runtime);
    register_recomp_unit_83(runtime);
    register_recomp_unit_84(runtime);
    register_recomp_unit_85(runtime);
    register_recomp_unit_86(runtime);
    register_recomp_unit_87(runtime);
    register_recomp_unit_88(runtime);
    register_recomp_unit_89(runtime);
    register_recomp_unit_90(runtime);
    register_recomp_unit_91(runtime);
    register_recomp_unit_92(runtime);
    register_recomp_unit_93(runtime);
    register_recomp_unit_94(runtime);
    register_recomp_unit_95(runtime);
    register_recomp_unit_96(runtime);
    register_recomp_unit_97(runtime);
    register_recomp_unit_98(runtime);
    register_recomp_unit_99(runtime);
    register_recomp_unit_100(runtime);
    register_recomp_unit_101(runtime);
    register_recomp_unit_102(runtime);
    register_recomp_unit_103(runtime);
    register_recomp_unit_104(runtime);
    register_recomp_unit_105(runtime);
    register_recomp_unit_106(runtime);
    register_recomp_unit_107(runtime);
    register_recomp_unit_108(runtime);
    register_recomp_unit_109(runtime);
    register_recomp_unit_110(runtime);
    register_recomp_unit_111(runtime);
    register_recomp_unit_112(runtime);
    runtime.register_function(0x089C5770u, &import_0, "sceNetAdhocMatching::0x2A2A1E07");
    runtime.register_function(0x089C5778u, &import_1, "sceNetAdhocMatching::0x32B156B3");
    runtime.register_function(0x089C5780u, &import_2, "sceNetAdhocMatching::0x5E3D4B79");
    runtime.register_function(0x089C5788u, &import_3, "sceNetAdhocMatching::0x7945ECDA");
    runtime.register_function(0x089C5790u, &import_4, "sceNetAdhocMatching::0x93EF3843");
    runtime.register_function(0x089C5798u, &import_5, "sceNetAdhocMatching::0xB58E61B7");
    runtime.register_function(0x089C57A0u, &import_6, "sceNetAdhocMatching::0xCA5EDA6F");
    runtime.register_function(0x089C57A8u, &import_7, "sceNetAdhocMatching::0xEA3C6108");
    runtime.register_function(0x089C57B0u, &import_8, "sceNetAdhocMatching::0xF16EAF4F");
    runtime.register_function(0x089C57B8u, &import_9, "sceNetAdhocMatching::0xF79472D7");
    runtime.register_function(0x089C57C0u, &import_10, "ModuleMgrForUser::0x2E0911AA");
    runtime.register_function(0x089C57C8u, &import_11, "ModuleMgrForUser::0x50F0C1EC");
    runtime.register_function(0x089C57D0u, &import_12, "ModuleMgrForUser::0x8F2DF740");
    runtime.register_function(0x089C57D8u, &import_13, "ModuleMgrForUser::0x977DE386");
    runtime.register_function(0x089C57E0u, &import_14, "ModuleMgrForUser::0xD1FF982A");
    runtime.register_function(0x089C57E8u, &import_15, "ModuleMgrForUser::0xD8B73127");
    runtime.register_function(0x089C57F0u, &import_16, "ModuleMgrForUser::0xF0A26395");
    runtime.register_function(0x089C57F8u, &import_17, "scePower::0x04B7766E");
    runtime.register_function(0x089C5800u, &import_18, "scePower::0x469989AD");
    runtime.register_function(0x089C5808u, &import_19, "scePower::0xA85880D0");
    runtime.register_function(0x089C5810u, &import_20, "scePower::0xDFA8BAF8");
    runtime.register_function(0x089C5818u, &import_21, "scePower::0xFDB5BFE9");
    runtime.register_function(0x089C5820u, &import_22, "sceUtility::0x0251B134");
    runtime.register_function(0x089C5828u, &import_23, "sceUtility::0x2A2B3DE0");
    runtime.register_function(0x089C5830u, &import_24, "sceUtility::0x2AD8E239");
    runtime.register_function(0x089C5838u, &import_25, "sceUtility::0x34B78343");
    runtime.register_function(0x089C5840u, &import_26, "sceUtility::0x3DFAEBA9");
    runtime.register_function(0x089C5848u, &import_27, "sceUtility::0x4928BD96");
    runtime.register_function(0x089C5850u, &import_28, "sceUtility::0x4B85C861");
    runtime.register_function(0x089C5858u, &import_29, "sceUtility::0x50C4CD57");
    runtime.register_function(0x089C5860u, &import_30, "sceUtility::0x67AF3428");
    runtime.register_function(0x089C5868u, &import_31, "sceUtility::0x8874DBE0");
    runtime.register_function(0x089C5870u, &import_32, "sceUtility::0x95FC253B");
    runtime.register_function(0x089C5878u, &import_33, "sceUtility::0x9790B33C");
    runtime.register_function(0x089C5880u, &import_34, "sceUtility::0x9A1C91D7");
    runtime.register_function(0x089C5888u, &import_35, "sceUtility::0xA5DA2406");
    runtime.register_function(0x089C5890u, &import_36, "sceUtility::0xAB083EA9");
    runtime.register_function(0x089C5898u, &import_37, "sceUtility::0xD4B95FFB");
    runtime.register_function(0x089C58A0u, &import_38, "sceUtility::0xD81957B7");
    runtime.register_function(0x089C58A8u, &import_39, "sceUtility::0xE49BFE92");
    runtime.register_function(0x089C58B0u, &import_40, "sceUtility::0xF3F76017");
    runtime.register_function(0x089C58B8u, &import_41, "sceUtility::0xF6269B82");
    runtime.register_function(0x089C58C0u, &import_42, "sceUtility::0xF9E0008C");
    runtime.register_function(0x089C58C8u, &import_43, "sceLibFont::0x0DA7535E");
    runtime.register_function(0x089C58D0u, &import_44, "sceLibFont::0x27F6E642");
    runtime.register_function(0x089C58D8u, &import_45, "sceLibFont::0x3AEA8CB6");
    runtime.register_function(0x089C58E0u, &import_46, "sceLibFont::0x67F17ED7");
    runtime.register_function(0x089C58E8u, &import_47, "sceLibFont::0x681E61A7");
    runtime.register_function(0x089C58F0u, &import_48, "sceLibFont::0x980F4895");
    runtime.register_function(0x089C58F8u, &import_49, "sceLibFont::0xA834319D");
    runtime.register_function(0x089C5900u, &import_50, "sceLibFont::0xBC75D85B");
    runtime.register_function(0x089C5908u, &import_51, "sceLibFont::0xDCC80C2F");
    runtime.register_function(0x089C5910u, &import_52, "sceLibFont::0xEE232411");
    runtime.register_function(0x089C5918u, &import_53, "sceWlanDrv::0x0C622081");
    runtime.register_function(0x089C5920u, &import_54, "sceWlanDrv::0xD7763699");
    runtime.register_function(0x089C5928u, &import_55, "sceNetAdhocDiscover::0x52DE1B97");
    runtime.register_function(0x089C5930u, &import_56, "sceNetAdhocDiscover::0x941B3877");
    runtime.register_function(0x089C5938u, &import_57, "sceNetAdhocDiscover::0x944DDBC6");
    runtime.register_function(0x089C5940u, &import_58, "sceNetAdhocDiscover::0xA2246614");
    runtime.register_function(0x089C5948u, &import_59, "sceNetAdhocctl::0x08FFF7A0");
    runtime.register_function(0x089C5950u, &import_60, "sceNetAdhocctl::0x0AD043ED");
    runtime.register_function(0x089C5958u, &import_61, "sceNetAdhocctl::0x20B317A0");
    runtime.register_function(0x089C5960u, &import_62, "sceNetAdhocctl::0x34401D65");
    runtime.register_function(0x089C5968u, &import_63, "sceNetAdhocctl::0x5E7F79C9");
    runtime.register_function(0x089C5970u, &import_64, "sceNetAdhocctl::0x6402490B");
    runtime.register_function(0x089C5978u, &import_65, "sceNetAdhocctl::0x81AEE1BE");
    runtime.register_function(0x089C5980u, &import_66, "sceNetAdhocctl::0x8DB83FDC");
    runtime.register_function(0x089C5988u, &import_67, "sceNetAdhocctl::0x9D689E13");
    runtime.register_function(0x089C5990u, &import_68, "sceNetAdhocctl::0xE162CB14");
    runtime.register_function(0x089C5998u, &import_69, "sceNetAdhocctl::0xE26F226E");
    runtime.register_function(0x089C59A0u, &import_70, "sceNetAdhocctl::0xEC0635C1");
    runtime.register_function(0x089C59A8u, &import_71, "sceNetAdhoc::0x157E6225");
    runtime.register_function(0x089C59B0u, &import_72, "sceNetAdhoc::0x4DA4C788");
    runtime.register_function(0x089C59B8u, &import_73, "sceNetAdhoc::0x6F92741B");
    runtime.register_function(0x089C59C0u, &import_74, "sceNetAdhoc::0x7F27BB5E");
    runtime.register_function(0x089C59C8u, &import_75, "sceNetAdhoc::0x877F6D66");
    runtime.register_function(0x089C59D0u, &import_76, "sceNetAdhoc::0x8BEA2B3E");
    runtime.register_function(0x089C59D8u, &import_77, "sceNetAdhoc::0x9AC2EEAC");
    runtime.register_function(0x089C59E0u, &import_78, "sceNetAdhoc::0x9DF81198");
    runtime.register_function(0x089C59E8u, &import_79, "sceNetAdhoc::0xA62C6F57");
    runtime.register_function(0x089C59F0u, &import_80, "sceNetAdhoc::0xABED3790");
    runtime.register_function(0x089C59F8u, &import_81, "sceNetAdhoc::0xB9685118");
    runtime.register_function(0x089C5A00u, &import_82, "sceNetAdhoc::0xC7C1FC57");
    runtime.register_function(0x089C5A08u, &import_83, "sceNetAdhoc::0xDFE53E03");
    runtime.register_function(0x089C5A10u, &import_84, "sceNetAdhoc::0xE08BDAC1");
    runtime.register_function(0x089C5A18u, &import_85, "sceNetAdhoc::0xE1D621D7");
    runtime.register_function(0x089C5A20u, &import_86, "sceNetAdhoc::0xFC6FC07B");
    runtime.register_function(0x089C5A28u, &import_87, "sceNet::0x0BF0A3AE");
    runtime.register_function(0x089C5A30u, &import_88, "sceNet::0x281928A9");
    runtime.register_function(0x089C5A38u, &import_89, "sceNet::0x39AF39A6");
    runtime.register_function(0x089C5A40u, &import_90, "sceNet::0x89360950");
    runtime.register_function(0x089C5A48u, &import_91, "sceGe_user::0x03444EB4");
    runtime.register_function(0x089C5A50u, &import_92, "sceGe_user::0x05DB22CE");
    runtime.register_function(0x089C5A58u, &import_93, "sceGe_user::0x1C0D95A6");
    runtime.register_function(0x089C5A60u, &import_94, "sceGe_user::0x1F6752AD");
    runtime.register_function(0x089C5A68u, &import_95, "sceGe_user::0x4C06E472");
    runtime.register_function(0x089C5A70u, &import_96, "sceGe_user::0xA4FC06A4");
    runtime.register_function(0x089C5A78u, &import_97, "sceGe_user::0xAB49E76A");
    runtime.register_function(0x089C5A80u, &import_98, "sceGe_user::0xB287BD61");
    runtime.register_function(0x089C5A88u, &import_99, "sceGe_user::0xB448EC0D");
    runtime.register_function(0x089C5A90u, &import_100, "sceGe_user::0xE0D68148");
    runtime.register_function(0x089C5A98u, &import_101, "sceGe_user::0xE47E40E4");
    runtime.register_function(0x089C5AA0u, &import_102, "sceCtrl::0x1F4011E6");
    runtime.register_function(0x089C5AA8u, &import_103, "sceCtrl::0x1F803938");
    runtime.register_function(0x089C5AB0u, &import_104, "sceCtrl::0x6A2774F3");
    runtime.register_function(0x089C5AB8u, &import_105, "sceDisplay::0x0E20F177");
    runtime.register_function(0x089C5AC0u, &import_106, "sceDisplay::0x289D82FE");
    runtime.register_function(0x089C5AC8u, &import_107, "sceDisplay::0x46F186C3");
    runtime.register_function(0x089C5AD0u, &import_108, "sceDisplay::0x984C27E7");
    runtime.register_function(0x089C5AD8u, &import_109, "sceDisplay::0x9C6EAAD7");
    runtime.register_function(0x089C5AE0u, &import_110, "sceDisplay::0xEEDA2E54");
    runtime.register_function(0x089C5AE8u, &import_111, "sceDmac::0x617F3FE6");
    runtime.register_function(0x089C5AF0u, &import_112, "sceMpeg::0x0E3C2E9D");
    runtime.register_function(0x089C5AF8u, &import_113, "sceMpeg::0x13407F13");
    runtime.register_function(0x089C5B00u, &import_114, "sceMpeg::0x167AFD9E");
    runtime.register_function(0x089C5B08u, &import_115, "sceMpeg::0x21FF80E4");
    runtime.register_function(0x089C5B10u, &import_116, "sceMpeg::0x37295ED8");
    runtime.register_function(0x089C5B18u, &import_117, "sceMpeg::0x42560F23");
    runtime.register_function(0x089C5B20u, &import_118, "sceMpeg::0x4571CC64");
    runtime.register_function(0x089C5B28u, &import_119, "sceMpeg::0x591A4AA2");
    runtime.register_function(0x089C5B30u, &import_120, "sceMpeg::0x606A4649");
    runtime.register_function(0x089C5B38u, &import_121, "sceMpeg::0x682A619B");
    runtime.register_function(0x089C5B40u, &import_122, "sceMpeg::0x707B7629");
    runtime.register_function(0x089C5B48u, &import_123, "sceMpeg::0x800C44DF");
    runtime.register_function(0x089C5B50u, &import_124, "sceMpeg::0x874624D6");
    runtime.register_function(0x089C5B58u, &import_125, "sceMpeg::0x8C1E027D");
    runtime.register_function(0x089C5B60u, &import_126, "sceMpeg::0xA11C7026");
    runtime.register_function(0x089C5B68u, &import_127, "sceMpeg::0xA780CF7E");
    runtime.register_function(0x089C5B70u, &import_128, "sceMpeg::0xB240A59E");
    runtime.register_function(0x089C5B78u, &import_129, "sceMpeg::0xB5F6DC87");
    runtime.register_function(0x089C5B80u, &import_130, "sceMpeg::0xC132E22F");
    runtime.register_function(0x089C5B88u, &import_131, "sceMpeg::0xCEB870B1");
    runtime.register_function(0x089C5B90u, &import_132, "sceMpeg::0xD7A29F46");
    runtime.register_function(0x089C5B98u, &import_133, "sceMpeg::0xD8C5F121");
    runtime.register_function(0x089C5BA0u, &import_134, "sceMpeg::0xE1CE83A7");
    runtime.register_function(0x089C5BA8u, &import_135, "sceMpeg::0xF8DCB679");
    runtime.register_function(0x089C5BB0u, &import_136, "sceMpeg::0xFE246728");
    runtime.register_function(0x089C5BB8u, &import_137, "sceUmdUser::0x46EBB729");
    runtime.register_function(0x089C5BC0u, &import_138, "sceUmdUser::0x6B4A146C");
    runtime.register_function(0x089C5BC8u, &import_139, "sceUmdUser::0x8EF08FCE");
    runtime.register_function(0x089C5BD0u, &import_140, "sceUmdUser::0xAEE7404D");
    runtime.register_function(0x089C5BD8u, &import_141, "sceUmdUser::0xBD2BDE07");
    runtime.register_function(0x089C5BE0u, &import_142, "sceUmdUser::0xC6183D47");
    runtime.register_function(0x089C5BE8u, &import_143, "sceSasCore::0x019B25EB");
    runtime.register_function(0x089C5BF0u, &import_144, "sceSasCore::0x07F58C24");
    runtime.register_function(0x089C5BF8u, &import_145, "sceSasCore::0x267A6DD2");
    runtime.register_function(0x089C5C00u, &import_146, "sceSasCore::0x2C8E6AB3");
    runtime.register_function(0x089C5C08u, &import_147, "sceSasCore::0x33D4AB37");
    runtime.register_function(0x089C5C10u, &import_148, "sceSasCore::0x42778A9F");
    runtime.register_function(0x089C5C18u, &import_149, "sceSasCore::0x440CA7D8");
    runtime.register_function(0x089C5C20u, &import_150, "sceSasCore::0x50A14DFC");
    runtime.register_function(0x089C5C28u, &import_151, "sceSasCore::0x5F9529F6");
    runtime.register_function(0x089C5C30u, &import_152, "sceSasCore::0x68A46B95");
    runtime.register_function(0x089C5C38u, &import_153, "sceSasCore::0x74AE582A");
    runtime.register_function(0x089C5C40u, &import_154, "sceSasCore::0x76F01ACA");
    runtime.register_function(0x089C5C48u, &import_155, "sceSasCore::0x787D04D5");
    runtime.register_function(0x089C5C50u, &import_156, "sceSasCore::0x99944089");
    runtime.register_function(0x089C5C58u, &import_157, "sceSasCore::0x9EC3676A");
    runtime.register_function(0x089C5C60u, &import_158, "sceSasCore::0xA0CF2FA4");
    runtime.register_function(0x089C5C68u, &import_159, "sceSasCore::0xA3589D81");
    runtime.register_function(0x089C5C70u, &import_160, "sceSasCore::0xAD84D37F");
    runtime.register_function(0x089C5C78u, &import_161, "sceSasCore::0xB7660A23");
    runtime.register_function(0x089C5C80u, &import_162, "sceSasCore::0xBD11B7C2");
    runtime.register_function(0x089C5C88u, &import_163, "sceSasCore::0xCBCD4F79");
    runtime.register_function(0x089C5C90u, &import_164, "sceSasCore::0xD1E0A01E");
    runtime.register_function(0x089C5C98u, &import_165, "sceSasCore::0xD5A229C9");
    runtime.register_function(0x089C5CA0u, &import_166, "sceSasCore::0xE175EF66");
    runtime.register_function(0x089C5CA8u, &import_167, "sceSasCore::0xE1CD9561");
    runtime.register_function(0x089C5CB0u, &import_168, "sceSasCore::0xE855BF76");
    runtime.register_function(0x089C5CB8u, &import_169, "sceSasCore::0xF983B186");
    runtime.register_function(0x089C5CC0u, &import_170, "sceAtrac3plus::0x5D268707");
    runtime.register_function(0x089C5CC8u, &import_171, "sceAtrac3plus::0x61EB33F5");
    runtime.register_function(0x089C5CD0u, &import_172, "sceAtrac3plus::0x644E5607");
    runtime.register_function(0x089C5CD8u, &import_173, "sceAtrac3plus::0x6A8C3CD5");
    runtime.register_function(0x089C5CE0u, &import_174, "sceAtrac3plus::0x7A20E7AF");
    runtime.register_function(0x089C5CE8u, &import_175, "sceAtrac3plus::0x7DB31251");
    runtime.register_function(0x089C5CF0u, &import_176, "sceAtrac3plus::0x868120B5");
    runtime.register_function(0x089C5CF8u, &import_177, "sceAtrac3plus::0x9AE849A7");
    runtime.register_function(0x089C5D00u, &import_178, "sceAtrac3plus::0xA2BBA8BE");
    runtime.register_function(0x089C5D08u, &import_179, "sceAtrac3plus::0xE88F759B");
    runtime.register_function(0x089C5D10u, &import_180, "scesupPreAcc::0x110E318B");
    runtime.register_function(0x089C5D18u, &import_181, "scesupPreAcc::0x13AE25B3");
    runtime.register_function(0x089C5D20u, &import_182, "scesupPreAcc::0x28C5F696");
    runtime.register_function(0x089C5D28u, &import_183, "scesupPreAcc::0x2EC3F4D9");
    runtime.register_function(0x089C5D30u, &import_184, "scesupPreAcc::0x348BA3E2");
    runtime.register_function(0x089C5D38u, &import_185, "scesupPreAcc::0x86DEBD66");
    runtime.register_function(0x089C5D40u, &import_186, "scesupPreAcc::0xA0EAF444");
    runtime.register_function(0x089C5D48u, &import_187, "scesupPreAcc::0xB03FF882");
    runtime.register_function(0x089C5D50u, &import_188, "scePspNpDrm_user::0x08D98894");
    runtime.register_function(0x089C5D58u, &import_189, "scePspNpDrm_user::0xA1336091");
    runtime.register_function(0x089C5D60u, &import_190, "sceImpose::0x24FD7BCF");
    runtime.register_function(0x089C5D68u, &import_191, "sceImpose::0x36AA6E91");
    runtime.register_function(0x089C5D70u, &import_192, "sceRtc::0x57726BC1");
    runtime.register_function(0x089C5D78u, &import_193, "sceRtc::0x6FF40ACC");
    runtime.register_function(0x089C5D80u, &import_194, "sceRtc::0x7ED29E40");
    runtime.register_function(0x089C5D88u, &import_195, "sceRtc::0xC41C2853");
    runtime.register_function(0x089C5D90u, &import_196, "sceRtc::0xE51B4B7A");
    runtime.register_function(0x089C5D98u, &import_197, "sceRtc::0xE7C27D1B");
    runtime.register_function(0x089C5DA0u, &import_198, "sceRtc::0xF2A4AFE5");
    runtime.register_function(0x089C5DA8u, &import_199, "sceAudio::0x01562BA3");
    runtime.register_function(0x089C5DB0u, &import_200, "sceAudio::0x2D53F36E");
    runtime.register_function(0x089C5DB8u, &import_201, "sceAudio::0x43196845");
    runtime.register_function(0x089C5DC0u, &import_202, "sceAudio::0x647CEF33");
    runtime.register_function(0x089C5DC8u, &import_203, "sceAudio::0x136CAF51");
    runtime.register_function(0x089C5DD0u, &import_204, "sceAudio::0x13F592BC");
    runtime.register_function(0x089C5DD8u, &import_205, "sceAudio::0x5EC81C55");
    runtime.register_function(0x089C5DE0u, &import_206, "sceAudio::0x6FC46853");
    runtime.register_function(0x089C5DE8u, &import_207, "sceAudio::0x95FD0C2D");
    runtime.register_function(0x089C5DF0u, &import_208, "sceAudio::0xB011922F");
    runtime.register_function(0x089C5DF8u, &import_209, "sceAudio::0xB7E1D8E7");
    runtime.register_function(0x089C5E00u, &import_210, "sceAudio::0xCB2E439E");
    runtime.register_function(0x089C5E08u, &import_211, "sceAudio::0xE2D56B2D");
    runtime.register_function(0x089C5E10u, &import_212, "IoFileMgrForUser::0x06A70004");
    runtime.register_function(0x089C5E18u, &import_213, "IoFileMgrForUser::0x42EC03AC");
    runtime.register_function(0x089C5E20u, &import_214, "IoFileMgrForUser::0x54F5FB11");
    runtime.register_function(0x089C5E28u, &import_215, "IoFileMgrForUser::0x55F4717D");
    runtime.register_function(0x089C5E30u, &import_216, "IoFileMgrForUser::0x6A638D83");
    runtime.register_function(0x089C5E38u, &import_217, "IoFileMgrForUser::0x71B19E77");
    runtime.register_function(0x089C5E40u, &import_218, "IoFileMgrForUser::0x779103A0");
    runtime.register_function(0x089C5E48u, &import_219, "IoFileMgrForUser::0x810C4BC3");
    runtime.register_function(0x089C5E50u, &import_220, "IoFileMgrForUser::0x89AA9906");
    runtime.register_function(0x089C5E58u, &import_221, "IoFileMgrForUser::0xA0B5A7C2");
    runtime.register_function(0x089C5E60u, &import_222, "IoFileMgrForUser::0xA12A0514");
    runtime.register_function(0x089C5E68u, &import_223, "IoFileMgrForUser::0xACE946E8");
    runtime.register_function(0x089C5E70u, &import_224, "IoFileMgrForUser::0xB29DDF9C");
    runtime.register_function(0x089C5E78u, &import_225, "IoFileMgrForUser::0xB8A740F4");
    runtime.register_function(0x089C5E80u, &import_226, "IoFileMgrForUser::0xE23EEC33");
    runtime.register_function(0x089C5E88u, &import_227, "IoFileMgrForUser::0xE3EB004C");
    runtime.register_function(0x089C5E90u, &import_228, "IoFileMgrForUser::0xE95A012B");
    runtime.register_function(0x089C5E98u, &import_229, "IoFileMgrForUser::0xEB092469");
    runtime.register_function(0x089C5EA0u, &import_230, "IoFileMgrForUser::0xF27A9C51");
    runtime.register_function(0x089C5EA8u, &import_231, "IoFileMgrForUser::0x109F50BC");
    runtime.register_function(0x089C5EB0u, &import_232, "IoFileMgrForUser::0x1117C65F");
    runtime.register_function(0x089C5EB8u, &import_233, "IoFileMgrForUser::0x27EB27B8");
    runtime.register_function(0x089C5EC0u, &import_234, "IoFileMgrForUser::0x3251EA56");
    runtime.register_function(0x089C5EC8u, &import_235, "Kernel_Library::0x092968F4");
    runtime.register_function(0x089C5ED0u, &import_236, "Kernel_Library::0xA089ECA4");
    runtime.register_function(0x089C5ED8u, &import_237, "Kernel_Library::0x1839852A");
    runtime.register_function(0x089C5EE0u, &import_238, "Kernel_Library::0x293B45B8");
    runtime.register_function(0x089C5EE8u, &import_239, "Kernel_Library::0x5F10D406");
    runtime.register_function(0x089C5EF0u, &import_240, "LoadExecForUser::0x05572A5F");
    runtime.register_function(0x089C5EF8u, &import_241, "LoadExecForUser::0x4AC57943");
    runtime.register_function(0x089C5F00u, &import_242, "StdioForUser::0x172D316E");
    runtime.register_function(0x089C5F08u, &import_243, "StdioForUser::0xA6BAB2E9");
    runtime.register_function(0x089C5F10u, &import_244, "StdioForUser::0xF78BA90A");
    runtime.register_function(0x089C5F18u, &import_245, "SysMemUserForUser::0x13A5ABEF");
    runtime.register_function(0x089C5F20u, &import_246, "SysMemUserForUser::0xDB83A952");
    runtime.register_function(0x089C5F28u, &import_247, "SysMemUserForUser::0xF77D77CB");
    runtime.register_function(0x089C5F30u, &import_248, "SysMemUserForUser::0xF919F628");
    runtime.register_function(0x089C5F38u, &import_249, "SysMemUserForUser::0xFE707FDF");
    runtime.register_function(0x089C5F40u, &import_250, "SysMemUserForUser::0x1B4217BC");
    runtime.register_function(0x089C5F48u, &import_251, "SysMemUserForUser::0x237DBD4F");
    runtime.register_function(0x089C5F50u, &import_252, "SysMemUserForUser::0x50F61D8A");
    runtime.register_function(0x089C5F58u, &import_253, "SysMemUserForUser::0x9D9A5BA1");
    runtime.register_function(0x089C5F60u, &import_254, "SysMemUserForUser::0xB6D61D02");
    runtime.register_function(0x089C5F68u, &import_255, "ThreadManForUser::0xCEADEB47");
    runtime.register_function(0x089C5F70u, &import_256, "ThreadManForUser::0xD6DA4BA1");
    runtime.register_function(0x089C5F78u, &import_257, "ThreadManForUser::0x1FB15A32");
    runtime.register_function(0x089C5F80u, &import_258, "ThreadManForUser::0xE81CAF8F");
    runtime.register_function(0x089C5F88u, &import_259, "ThreadManForUser::0xEA748E31");
    runtime.register_function(0x089C5F90u, &import_260, "ThreadManForUser::0xEDBA5844");
    runtime.register_function(0x089C5F98u, &import_261, "ThreadManForUser::0xEF9E4C70");
    runtime.register_function(0x089C5FA0u, &import_262, "ThreadManForUser::0xF475845D");
    runtime.register_function(0x089C5FA8u, &import_263, "ThreadManForUser::0x278C0DF5");
    runtime.register_function(0x089C5FB0u, &import_264, "ThreadManForUser::0x28B6489C");
    runtime.register_function(0x089C5FB8u, &import_265, "ThreadManForUser::0x369ED59D");
    runtime.register_function(0x089C5FC0u, &import_266, "ThreadManForUser::0x3F53E640");
    runtime.register_function(0x089C5FC8u, &import_267, "ThreadManForUser::0x402FCF22");
    runtime.register_function(0x089C5FD0u, &import_268, "ThreadManForUser::0x446D8DE6");
    runtime.register_function(0x089C5FD8u, &import_269, "ThreadManForUser::0x4E3A1105");
    runtime.register_function(0x089C5FE0u, &import_270, "ThreadManForUser::0x55C20A00");
    runtime.register_function(0x089C5FE8u, &import_271, "ThreadManForUser::0x616403BA");
    runtime.register_function(0x089C5FF0u, &import_272, "ThreadManForUser::0x68DA9E36");
    runtime.register_function(0x089C5FF8u, &import_273, "ThreadManForUser::0x71BC9871");
    runtime.register_function(0x089C6000u, &import_274, "ThreadManForUser::0x809CE29B");
    runtime.register_function(0x089C6008u, &import_275, "ThreadManForUser::0x812346E4");
    runtime.register_function(0x089C6010u, &import_276, "ThreadManForUser::0x82BC5777");
    runtime.register_function(0x089C6018u, &import_277, "ThreadManForUser::0x840E8133");
    runtime.register_function(0x089C6020u, &import_278, "ThreadManForUser::0x8FFDF9A2");
    runtime.register_function(0x089C6028u, &import_279, "ThreadManForUser::0x9FA03CD3");
    runtime.register_function(0x089C6030u, &import_280, "ThreadManForUser::0xAA73C935");
    runtime.register_function(0x089C6038u, &import_281, "UtilsForUser::0x71EC4271");
    runtime.register_function(0x089C6040u, &import_282, "UtilsForUser::0x79D1C3FA");
    runtime.register_function(0x089C6048u, &import_283, "UtilsForUser::0x91E4F6A7");
    runtime.register_function(0x089C6050u, &import_284, "UtilsForUser::0xB435DEC5");
    runtime.register_function(0x089C6058u, &import_285, "UtilsForUser::0xBFA98062");
    runtime.register_function(0x089C6060u, &import_286, "UtilsForUser::0xC2DF770E");
    runtime.register_function(0x089C6068u, &import_287, "UtilsForUser::0x27CC57F0");
    runtime.register_function(0x089C6070u, &import_288, "UtilsForUser::0x34B9FA9E");
    runtime.register_function(0x089C6078u, &import_289, "UtilsForUser::0x37FB5C42");
    runtime.register_function(0x089C6080u, &import_290, "UtilsForUser::0x3EE30821");
    runtime.register_function(0x089C6088u, &import_291, "sceSuspendForUser::0x090CCB3F");
    runtime.register_function(0x089C6090u, &import_292, "sceSuspendForUser::0x3AEE7261");
    runtime.register_function(0x089C6098u, &import_293, "sceSuspendForUser::0x3E0271D3");
    runtime.register_function(0x089C60A0u, &import_294, "sceSuspendForUser::0xA569E425");
    runtime.register_function(0x089C60A8u, &import_295, "sceSuspendForUser::0xEADB1BD7");
}
} // namespace psprecomp
