#include "psprecomp/runtime.hpp"
namespace psprecomp {
void ovl_menu_recomp_unit_0012(Runtime &rt, AllegrexContext &ctx) {
    rt.unsupported(ctx.pc, 0u, "missing recovered overlay unit 0012");
}
void ovl_menu_recomp_unit_0073(Runtime &rt, AllegrexContext &ctx) {
    rt.unsupported(ctx.pc, 0u, "missing recovered overlay unit 0073");
}
void ovl_menu_recomp_unit_0113(Runtime &rt, AllegrexContext &ctx) {
    rt.unsupported(ctx.pc, 0u, "missing recovered overlay unit 0113");
}
void register_ovl_menu_generated_unit_1(Runtime &);
void register_ovl_menu_generated_unit_2(Runtime &);
void register_ovl_menu_generated_unit_3(Runtime &);
void register_ovl_menu_generated_unit_0(Runtime &);
void register_ovl_menu_generated_unit_4(Runtime &);
void register_ovl_menu_generated_unit_5(Runtime &);
void register_ovl_menu_generated_unit_6(Runtime &);
void register_ovl_menu_generated_unit_7(Runtime &);
void register_ovl_menu_generated_unit_8(Runtime &);
void register_ovl_menu_generated_unit_9(Runtime &);
void register_ovl_menu_generated_unit_10(Runtime &);
void register_ovl_menu_generated_unit_11(Runtime &);
void register_ovl_menu_target_functions(Runtime &rt) {
    register_ovl_menu_generated_unit_1(rt);
    register_ovl_menu_generated_unit_2(rt);
    register_ovl_menu_generated_unit_3(rt);
    register_ovl_menu_generated_unit_4(rt);
    register_ovl_menu_generated_unit_5(rt);
    register_ovl_menu_generated_unit_6(rt);
    register_ovl_menu_generated_unit_7(rt);
    register_ovl_menu_generated_unit_8(rt);
    register_ovl_menu_generated_unit_9(rt);
    register_ovl_menu_generated_unit_10(rt);
    register_ovl_menu_generated_unit_11(rt);
}
}
