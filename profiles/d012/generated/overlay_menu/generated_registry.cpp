#include "psprecomp/runtime.hpp"
#include "psprecomp/allegrex_context.hpp"
#include <cstdint>

namespace psprecomp {

// Stub for main-ELF unit 0113, which the overlay calls via invoke_chained_direct but which has
// no compiled body (it would start in the import stub area, past the end of the code).
void recomp_unit_0113(Runtime &rt, AllegrexContext &ctx) {
    rt.unsupported(ctx.pc, 0u, "missing main unit 0113");
}

namespace ovl_menu {
void register_generated_unit_0(Runtime &runtime);
void register_generated_unit_1(Runtime &runtime);
void register_generated_unit_2(Runtime &runtime);
void register_generated_unit_3(Runtime &runtime);
void register_generated_unit_4(Runtime &runtime);
void register_generated_unit_5(Runtime &runtime);
void register_generated_unit_6(Runtime &runtime);
void register_generated_unit_7(Runtime &runtime);
void register_generated_unit_8(Runtime &runtime);
void register_generated_unit_9(Runtime &runtime);
void register_generated_unit_10(Runtime &runtime);
void register_generated_unit_11(Runtime &runtime);
void register_extras_functions(Runtime &runtime);

void register_ovl_menu_functions(Runtime &runtime) {
    register_generated_unit_0(runtime);
    register_generated_unit_1(runtime);
    register_generated_unit_2(runtime);
    register_generated_unit_3(runtime);
    register_generated_unit_4(runtime);
    register_generated_unit_5(runtime);
    register_generated_unit_6(runtime);
    register_generated_unit_7(runtime);
    register_generated_unit_8(runtime);
    register_generated_unit_9(runtime);
    register_generated_unit_10(runtime);
    register_generated_unit_11(runtime);
    register_extras_functions(runtime);
}
} // namespace ovl_menu

} // namespace psprecomp
