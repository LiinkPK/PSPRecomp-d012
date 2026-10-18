#include "psprecomp/runtime.hpp"
#include "generated_units.hpp"
#include "d012_profile.hpp"
#include "win32_display.hpp"
#include "ge_render.hpp"
#include <bit>
#include <chrono>
#include <cstdio>
#include <cmath>
#include <cstdint>
#include <limits>
#include <string>
#include <vector>

namespace psprecomp {

// GE list tracking: set at EnQueue, advanced by UpdateStall, reset at ListSync
std::uint32_t g_ge_list_start    = 0u;
std::uint32_t g_ge_exec_cursor   = 0u;
bool          g_ge_list_executed = false;
// The render-chain node is not yet a bounded PSP display list. Replaying it
// as a synthetic 65536-word list causes an unbounded host-side GE loop.
// Keep the switch explicit so the path can be re-enabled independently.
constexpr bool kBackupExecuteRenderChain = false;
constexpr bool kBackupRejectUnboundedGeLists = true;
constexpr bool kBackupExecuteSyntheticPendingList = false;
constexpr bool kBackupExecuteSlotLists = true;
std::uint32_t g_ge_stall_updates = 0u;
void recomp_unit_0014_entry(Runtime &rt, AllegrexContext &ctx, std::uint16_t direct_entry_id, GuestMemory::AotFastView &aot_mem) {
    (void)direct_entry_id;
    { static std::uint32_t s_u14 = 0u; ++s_u14;
      if (s_u14 <= 5u) { std::printf("[U14] entry pc=0x%08X\n", ctx.pc); std::fflush(stdout); }
    }
    std::uint32_t jump_target = 0u;
    std::uint32_t local_transfers = 0u;
    std::uint32_t local_pc = 0u;
    std::uint32_t entry_id = 0u;
LOCAL_DISPATCH:
    switch (ctx.pc) {
    case 0x089C4044u: goto L_089C4044;
    case 0x089C4050u: goto L_089C4050;
    case 0x089C408Cu: goto L_089C408C;
    case 0x089C4094u: goto L_089C4094;
    case 0x089C409Cu: goto L_089C409C;
    case 0x089C40FCu: goto L_089C40FC;
    case 0x089C4104u: goto L_089C4104;
    case 0x089C410Cu: goto L_089C410C;
    case 0x089C4114u: goto L_089C4114;
    case 0x089C411Cu: goto L_089C411C;
    case 0x089C4124u: goto L_089C4124;
    case 0x089C412Cu: goto L_089C412C;
    case 0x089C4130u: goto L_089C4130;
    case 0x089C4148u: goto L_089C4148;
    case 0x089C4158u: goto L_089C4158;
    case 0x089C4168u: goto L_089C4168;
    case 0x089C4174u: goto L_089C4174;
    case 0x089C419Cu: goto L_089C419C;
    case 0x089C41C4u: goto L_089C41C4;
    case 0x089C41D4u: goto L_089C41D4;
    case 0x089C41E0u: goto L_089C41E0;
    case 0x089C4208u: goto L_089C4208;
    case 0x089C422Cu: goto L_089C422C;
    case 0x089C4240u: goto L_089C4240;
    case 0x089C4248u: goto L_089C4248;
    case 0x089C4258u: goto L_089C4258;
    case 0x089C426Cu: goto L_089C426C;
    case 0x089C4298u: goto L_089C4298;
    case 0x089C42B4u: goto L_089C42B4;
    case 0x089C43D8u: goto L_089C43D8;
    case 0x089C43ECu: goto L_089C43EC;
    case 0x089C4400u: goto L_089C4400;
    case 0x089C4420u: goto L_089C4420;
    case 0x089C442Cu: goto L_089C442C;
    case 0x089C4448u: goto L_089C4448;
    case 0x089C4454u: goto L_089C4454;
    case 0x089C4470u: goto L_089C4470;
    case 0x089C44B0u: goto L_089C44B0;
    case 0x089C44D0u: goto L_089C44D0;
    case 0x089C4504u: goto L_089C4504;
    case 0x089C4520u: goto L_089C4520;
    case 0x089C452Cu: goto L_089C452C;
    case 0x089C4548u: goto L_089C4548;
    case 0x089C4578u: goto L_089C4578;
    case 0x089C4580u: goto L_089C4580;
    case 0x089C4588u: goto L_089C4588;
    case 0x089C4590u: goto L_089C4590;
    case 0x089C4598u: goto L_089C4598;
    case 0x089C45A0u: goto L_089C45A0;
    case 0x089C45A8u: goto L_089C45A8;
    case 0x089C45C8u: goto L_089C45C8;
    case 0x089C46FCu: goto L_089C46FC;
    case 0x089C47BCu: goto L_089C47BC;
    case 0x089C48D0u: goto L_089C48D0;
    case 0x089C4A08u: goto L_089C4A08;
    case 0x089C4AA4u: goto L_089C4AA4;
    case 0x089C4AFCu: goto L_089C4AFC;
    case 0x089C4B34u: goto L_089C4B34;
    case 0x089C4B3Cu: goto L_089C4B3C;
    case 0x089C4BB0u: goto L_089C4BB0;
    case 0x089C4C4Cu: goto L_089C4C4C;
    case 0x089C4C54u: goto L_089C4C54;
    case 0x089C4C8Cu: goto L_089C4C8C;
    case 0x089C4CB8u: goto L_089C4CB8;
    case 0x089C4CCCu: goto L_089C4CCC;
    case 0x089C4D04u: goto L_089C4D04;
    case 0x089C4D44u: goto L_089C4D44;
    case 0x089C4D7Cu: goto L_089C4D7C;
    case 0x089C5468u: goto L_089C5468;
    case 0x089C54A0u: goto L_089C54A0;
    case 0x089C54D8u: goto L_089C54D8;
    case 0x089C5508u: goto L_089C5508;
    case 0x089C5528u: goto L_089C5528;
    case 0x089C5540u: goto L_089C5540;
    case 0x089C5550u: goto L_089C5550;
    case 0x089C5560u: goto L_089C5560;
    case 0x089C5570u: goto L_089C5570;
    case 0x089C55A8u: goto L_089C55A8;
    case 0x089C55E0u: goto L_089C55E0;
    case 0x089C55F8u: goto L_089C55F8;
    case 0x089C5630u: goto L_089C5630;
    case 0x089C5650u: goto L_089C5650;
    case 0x089C5688u: goto L_089C5688;
    case 0x089C56C0u: goto L_089C56C0;
    case 0x089C56E0u: goto L_089C56E0;
    case 0x089C5700u: goto L_089C5700;
    case 0x089C5718u: goto L_089C5718;
    case 0x089C5730u: goto L_089C5730;
    case 0x089C5770u: goto L_089C5770;
    case 0x089C5778u: goto L_089C5778;
    case 0x089C5780u: goto L_089C5780;
    case 0x089C5788u: goto L_089C5788;
    case 0x089C5790u: goto L_089C5790;
    case 0x089C5798u: goto L_089C5798;
    case 0x089C57A0u: goto L_089C57A0;
    case 0x089C57A8u: goto L_089C57A8;
    case 0x089C57B0u: goto L_089C57B0;
    case 0x089C57B8u: goto L_089C57B8;
    case 0x089C57C0u: goto L_089C57C0;
    case 0x089C57C8u: goto L_089C57C8;
    case 0x089C57D0u: goto L_089C57D0;
    case 0x089C57D8u: goto L_089C57D8;
    case 0x089C57E0u: goto L_089C57E0;
    case 0x089C57E8u: goto L_089C57E8;
    case 0x089C57F0u: goto L_089C57F0;
    case 0x089C57F8u: goto L_089C57F8;
    case 0x089C5800u: goto L_089C5800;
    case 0x089C5808u: goto L_089C5808;
    case 0x089C5810u: goto L_089C5810;
    case 0x089C5818u: goto L_089C5818;
    case 0x089C5820u: goto L_089C5820;
    case 0x089C5828u: goto L_089C5828;
    case 0x089C5830u: goto L_089C5830;
    case 0x089C5838u: goto L_089C5838;
    case 0x089C5858u: goto L_089C5858;
    case 0x089C5860u: goto L_089C5860;
    case 0x089C5868u: goto L_089C5868;
    case 0x089C5870u: goto L_089C5870;
    case 0x089C5878u: goto L_089C5878;
    case 0x089C5880u: goto L_089C5880;
    case 0x089C5888u: goto L_089C5888;
    case 0x089C5890u: goto L_089C5890;
    case 0x089C5898u: goto L_089C5898;
    case 0x089C58A0u: goto L_089C58A0;
    case 0x089C58A8u: goto L_089C58A8;
    case 0x089C58C0u: goto L_089C58C0;
    case 0x089C58C8u: goto L_089C58C8;
    case 0x089C58D0u: goto L_089C58D0;
    case 0x089C58E0u: goto L_089C58E0;
    case 0x089C58E8u: goto L_089C58E8;
    case 0x089C58F0u: goto L_089C58F0;
    case 0x089C58F8u: goto L_089C58F8;
    case 0x089C5900u: goto L_089C5900;
    case 0x089C5908u: goto L_089C5908;
    case 0x089C5910u: goto L_089C5910;
    case 0x089C5918u: goto L_089C5918;
    case 0x089C5928u: goto L_089C5928;
    case 0x089C5930u: goto L_089C5930;
    case 0x089C5938u: goto L_089C5938;
    case 0x089C5940u: goto L_089C5940;
    case 0x089C5948u: goto L_089C5948;
    case 0x089C5950u: goto L_089C5950;
    case 0x089C5958u: goto L_089C5958;
    case 0x089C5960u: goto L_089C5960;
    case 0x089C5968u: goto L_089C5968;
    case 0x089C5970u: goto L_089C5970;
    case 0x089C5978u: goto L_089C5978;
    case 0x089C5980u: goto L_089C5980;
    case 0x089C5988u: goto L_089C5988;
    case 0x089C5990u: goto L_089C5990;
    case 0x089C5998u: goto L_089C5998;
    case 0x089C59A0u: goto L_089C59A0;
    case 0x089C59A8u: goto L_089C59A8;
    case 0x089C59B0u: goto L_089C59B0;
    case 0x089C59B8u: goto L_089C59B8;
    case 0x089C59C0u: goto L_089C59C0;
    case 0x089C59C8u: goto L_089C59C8;
    case 0x089C59D0u: goto L_089C59D0;
    case 0x089C59D8u: goto L_089C59D8;
    case 0x089C59E0u: goto L_089C59E0;
    case 0x089C59E8u: goto L_089C59E8;
    case 0x089C59F0u: goto L_089C59F0;
    case 0x089C59F8u: goto L_089C59F8;
    case 0x089C5A08u: goto L_089C5A08;
    case 0x089C5A10u: goto L_089C5A10;
    case 0x089C5A18u: goto L_089C5A18;
    case 0x089C5A20u: goto L_089C5A20;
    case 0x089C5A28u: goto L_089C5A28;
    case 0x089C5A30u: goto L_089C5A30;
    case 0x089C5A38u: goto L_089C5A38;
    case 0x089C5A40u: goto L_089C5A40;
    case 0x089C5A48u: goto L_089C5A48;
    case 0x089C5A50u: goto L_089C5A50;
    case 0x089C5A58u: goto L_089C5A58;
    case 0x089C5A60u: goto L_089C5A60;
    case 0x089C5A70u: goto L_089C5A70;
    case 0x089C5A78u: goto L_089C5A78;
    case 0x089C5A80u: goto L_089C5A80;
    case 0x089C5A90u: goto L_089C5A90;
    case 0x089C5A98u: goto L_089C5A98;
    case 0x089C5AA0u: goto L_089C5AA0;
    case 0x089C5AA8u: goto L_089C5AA8;
    case 0x089C5AB0u: goto L_089C5AB0;
    case 0x089C5AB8u: goto L_089C5AB8;
    case 0x089C5AC0u: goto L_089C5AC0;
    case 0x089C5AC8u: goto L_089C5AC8;
    case 0x089C5AD0u: goto L_089C5AD0;
    case 0x089C5AD8u: goto L_089C5AD8;
    case 0x089C5AE0u: goto L_089C5AE0;
    case 0x089C5AE8u: goto L_089C5AE8;
    case 0x089C5AF0u: goto L_089C5AF0;
    case 0x089C5AF8u: goto L_089C5AF8;
    case 0x089C5B00u: goto L_089C5B00;
    case 0x089C5B08u: goto L_089C5B08;
    case 0x089C5B10u: goto L_089C5B10;
    case 0x089C5B18u: goto L_089C5B18;
    case 0x089C5B20u: goto L_089C5B20;
    case 0x089C5B28u: goto L_089C5B28;
    case 0x089C5B30u: goto L_089C5B30;
    case 0x089C5B38u: goto L_089C5B38;
    case 0x089C5B40u: goto L_089C5B40;
    case 0x089C5B48u: goto L_089C5B48;
    case 0x089C5B50u: goto L_089C5B50;
    case 0x089C5B58u: goto L_089C5B58;
    case 0x089C5B60u: goto L_089C5B60;
    case 0x089C5B68u: goto L_089C5B68;
    case 0x089C5B70u: goto L_089C5B70;
    case 0x089C5B78u: goto L_089C5B78;
    case 0x089C5B80u: goto L_089C5B80;
    case 0x089C5B88u: goto L_089C5B88;
    case 0x089C5B90u: goto L_089C5B90;
    case 0x089C5B98u: goto L_089C5B98;
    case 0x089C5BA0u: goto L_089C5BA0;
    case 0x089C5BA8u: goto L_089C5BA8;
    case 0x089C5BB0u: goto L_089C5BB0;
    case 0x089C5BB8u: goto L_089C5BB8;
    case 0x089C5BC0u: goto L_089C5BC0;
    case 0x089C5BC8u: goto L_089C5BC8;
    case 0x089C5BD0u: goto L_089C5BD0;
    case 0x089C5BD8u: goto L_089C5BD8;
    case 0x089C5BE0u: goto L_089C5BE0;
    case 0x089C5C00u: goto L_089C5C00;
    case 0x089C5C08u: goto L_089C5C08;
    case 0x089C5C10u: goto L_089C5C10;
    case 0x089C5C18u: goto L_089C5C18;
    case 0x089C5C20u: goto L_089C5C20;
    case 0x089C5C30u: goto L_089C5C30;
    case 0x089C5C38u: goto L_089C5C38;
    case 0x089C5C40u: goto L_089C5C40;
    case 0x089C5C48u: goto L_089C5C48;
    case 0x089C5C50u: goto L_089C5C50;
    case 0x089C5C60u: goto L_089C5C60;
    case 0x089C5C70u: goto L_089C5C70;
    case 0x089C5C88u: goto L_089C5C88;
    case 0x089C5C98u: goto L_089C5C98;
    case 0x089C5CA0u: goto L_089C5CA0;
    case 0x089C5CB8u: goto L_089C5CB8;
    case 0x089C5CC0u: goto L_089C5CC0;
    case 0x089C5CC8u: goto L_089C5CC8;
    case 0x089C5CD0u: goto L_089C5CD0;
    case 0x089C5CD8u: goto L_089C5CD8;
    case 0x089C5CE0u: goto L_089C5CE0;
    case 0x089C5CE8u: goto L_089C5CE8;
    case 0x089C5CF0u: goto L_089C5CF0;
    case 0x089C5CF8u: goto L_089C5CF8;
    case 0x089C5D00u: goto L_089C5D00;
    case 0x089C5D08u: goto L_089C5D08;
    case 0x089C5D18u: goto L_089C5D18;
    case 0x089C5D20u: goto L_089C5D20;
    case 0x089C5D30u: goto L_089C5D30;
    case 0x089C5D38u: goto L_089C5D38;
    case 0x089C5D48u: goto L_089C5D48;
    case 0x089C5D50u: goto L_089C5D50;
    case 0x089C5D58u: goto L_089C5D58;
    case 0x089C5D60u: goto L_089C5D60;
    case 0x089C5D68u: goto L_089C5D68;
    case 0x089C5D70u: goto L_089C5D70;
    case 0x089C5D78u: goto L_089C5D78;
    case 0x089C5D80u: goto L_089C5D80;
    case 0x089C5D88u: goto L_089C5D88;
    case 0x089C5D90u: goto L_089C5D90;
    case 0x089C5D98u: goto L_089C5D98;
    case 0x089C5DA0u: goto L_089C5DA0;
    case 0x089C5DA8u: goto L_089C5DA8;
    case 0x089C5DB0u: goto L_089C5DB0;
    case 0x089C5DB8u: goto L_089C5DB8;
    case 0x089C5DC0u: goto L_089C5DC0;
    case 0x089C5DC8u: goto L_089C5DC8;
    case 0x089C5DD0u: goto L_089C5DD0;
    case 0x089C5DD8u: goto L_089C5DD8;
    case 0x089C5DE0u: goto L_089C5DE0;
    case 0x089C5E00u: goto L_089C5E00;
    case 0x089C5E10u: goto L_089C5E10;
    case 0x089C5E18u: goto L_089C5E18;
    case 0x089C5E20u: goto L_089C5E20;
    case 0x089C5E30u: goto L_089C5E30;
    case 0x089C5E38u: goto L_089C5E38;
    case 0x089C5E40u: goto L_089C5E40;
    case 0x089C5E48u: goto L_089C5E48;
    case 0x089C5E50u: goto L_089C5E50;
    case 0x089C5E58u: goto L_089C5E58;
    case 0x089C5E60u: goto L_089C5E60;
    case 0x089C5E68u: goto L_089C5E68;
    case 0x089C5E70u: goto L_089C5E70;
    case 0x089C5E78u: goto L_089C5E78;
    case 0x089C5E80u: goto L_089C5E80;
    case 0x089C5E88u: goto L_089C5E88;
    case 0x089C5E90u: goto L_089C5E90;
    case 0x089C5E98u: goto L_089C5E98;
    case 0x089C5EA0u: goto L_089C5EA0;
    case 0x089C5EA8u: goto L_089C5EA8;
    case 0x089C5EB0u: goto L_089C5EB0;
    case 0x089C5EB8u: goto L_089C5EB8;
    case 0x089C5EC8u: goto L_089C5EC8;
    case 0x089C5ED0u: goto L_089C5ED0;
    case 0x089C5ED8u: goto L_089C5ED8;
    case 0x089C5EE0u: goto L_089C5EE0;
    case 0x089C5EE8u: goto L_089C5EE8;
    case 0x089C5EF0u: goto L_089C5EF0;
    case 0x089C5EF8u: goto L_089C5EF8;
    case 0x089C5F00u: goto L_089C5F00;
    case 0x089C5F08u: goto L_089C5F08;
    case 0x089C5F10u: goto L_089C5F10;
    case 0x089C5F18u: goto L_089C5F18;
    case 0x089C5F20u: goto L_089C5F20;
    case 0x089C5F28u: goto L_089C5F28;
    case 0x089C5F30u: goto L_089C5F30;
    case 0x089C5F38u: goto L_089C5F38;
    case 0x089C5F40u: goto L_089C5F40;
    case 0x089C5F48u: goto L_089C5F48;
    case 0x089C5F50u: goto L_089C5F50;
    case 0x089C5F58u: goto L_089C5F58;
    case 0x089C5F60u: goto L_089C5F60;
    case 0x089C5F68u: goto L_089C5F68;
    case 0x089C5F70u: goto L_089C5F70;
    case 0x089C5F78u: goto L_089C5F78;
    case 0x089C5F80u: goto L_089C5F80;
    case 0x089C5F88u: goto L_089C5F88;
    case 0x089C5F90u: goto L_089C5F90;
    case 0x089C5F98u: goto L_089C5F98;
    case 0x089C5FA0u: goto L_089C5FA0;
    case 0x089C5FA8u: goto L_089C5FA8;
    case 0x089C5FB0u: goto L_089C5FB0;
    case 0x089C5FB8u: goto L_089C5FB8;
    case 0x089C5FC0u: goto L_089C5FC0;
    case 0x089C5FC8u: goto L_089C5FC8;
    case 0x089C5FD0u: goto L_089C5FD0;
    case 0x089C5FD8u: goto L_089C5FD8;
    case 0x089C5FE0u: goto L_089C5FE0;
    case 0x089C5FE8u: goto L_089C5FE8;
    case 0x089C5FF0u: goto L_089C5FF0;
    case 0x089C5FF8u: goto L_089C5FF8;
    case 0x089C6000u: goto L_089C6000;
    case 0x089C6010u: goto L_089C6010;
    case 0x089C6018u: goto L_089C6018;
    case 0x089C6020u: goto L_089C6020;
    case 0x089C6028u: goto L_089C6028;
    case 0x089C6030u: goto L_089C6030;
    case 0x089C6040u: goto L_089C6040;
    case 0x089C6050u: goto L_089C6050;
    case 0x089C6058u: goto L_089C6058;
    case 0x089C6060u: goto L_089C6060;
    case 0x089C6070u: goto L_089C6070;
    case 0x089C6078u: goto L_089C6078;
    case 0x089C6080u: goto L_089C6080;
    case 0x089C6088u: goto L_089C6088;
    case 0x089C6090u: goto L_089C6090;
    case 0x089C6098u: goto L_089C6098;
    case 0x089C60A0u: goto L_089C60A0;
    case 0x089C60A8u: goto L_089C60A8;
    case 0x089C60B0u: goto L_089C60B0;
    case 0x089C63F8u: goto L_089C63F8;
    case 0x089C640Cu: goto L_089C640C;
    case 0x089C645Cu: goto L_089C645C;
    case 0x089C64C0u: goto L_089C64C0;
    case 0x089C64DCu: goto L_089C64DC;
    case 0x089C6500u: goto L_089C6500;
    case 0x089C6548u: goto L_089C6548;
    case 0x089C6580u: goto L_089C6580;
    case 0x089C65A8u: goto L_089C65A8;
    case 0x089C65B0u: goto L_089C65B0;
    case 0x089C69A8u: goto L_089C69A8;
    case 0x089C69B4u: goto L_089C69B4;
    case 0x089C6A20u: goto L_089C6A20;
    case 0x089C6C40u: goto L_089C6C40;
    case 0x089C6C7Cu: goto L_089C6C7C;
    case 0x089C6CA8u: goto L_089C6CA8;
    case 0x089C6CE0u: goto L_089C6CE0;
    case 0x089C6D18u: goto L_089C6D18;
    case 0x089C6D60u: goto L_089C6D60;
    case 0x089C6D70u: goto L_089C6D70;
    case 0x089C6D80u: goto L_089C6D80;
    case 0x089C6DA0u: goto L_089C6DA0;
    case 0x089C6DB0u: goto L_089C6DB0;
    case 0x089C6DC0u: goto L_089C6DC0;
    case 0x089C6DD0u: goto L_089C6DD0;
    case 0x089C6DE0u: goto L_089C6DE0;
    case 0x089C6DF0u: goto L_089C6DF0;
    case 0x089C6E00u: goto L_089C6E00;
    case 0x089C6ED4u: goto L_089C6ED4;
    case 0x089C6EDCu: goto L_089C6EDC;
    case 0x089C6EE4u: goto L_089C6EE4;
    case 0x089C6EECu: goto L_089C6EEC;
    case 0x089C6EF4u: goto L_089C6EF4;
    case 0x089C6EFCu: goto L_089C6EFC;
    case 0x089C6F04u: goto L_089C6F04;
    case 0x089C6F0Cu: goto L_089C6F0C;
    case 0x089C6F14u: goto L_089C6F14;
    case 0x089C6F1Cu: goto L_089C6F1C;
    case 0x089C6F24u: goto L_089C6F24;
    case 0x089C6F2Cu: goto L_089C6F2C;
    case 0x089C6F34u: goto L_089C6F34;
    case 0x089C6F3Cu: goto L_089C6F3C;
    case 0x089C6F44u: goto L_089C6F44;
    case 0x089C6F4Cu: goto L_089C6F4C;
    case 0x089C6F54u: goto L_089C6F54;
    case 0x089C6F5Cu: goto L_089C6F5C;
    case 0x089C6F64u: goto L_089C6F64;
    case 0x089C6F6Cu: goto L_089C6F6C;
    case 0x089C6F74u: goto L_089C6F74;
    case 0x089C6F7Cu: goto L_089C6F7C;
    case 0x089C6F88u: goto L_089C6F88;
    case 0x089C6FB8u: goto L_089C6FB8;
    case 0x089C6FE8u: goto L_089C6FE8;
    case 0x089C7030u: goto L_089C7030;
    case 0x089C7248u: goto L_089C7248;
    case 0x089C74B0u: goto L_089C74B0;
    case 0x089C74C8u: goto L_089C74C8;
    case 0x089C74E8u: goto L_089C74E8;
    case 0x089C74ECu: goto L_089C74EC;
    case 0x089C74F8u: goto L_089C74F8;
    case 0x089C7510u: goto L_089C7510;
    case 0x089C7520u: goto L_089C7520;
    case 0x089C7530u: goto L_089C7530;
    case 0x089C7548u: goto L_089C7548;
    case 0x089C7558u: goto L_089C7558;
    case 0x089C7568u: goto L_089C7568;
    case 0x089C7578u: goto L_089C7578;
    case 0x089C7588u: goto L_089C7588;
    case 0x089C7598u: goto L_089C7598;
    case 0x089C75A8u: goto L_089C75A8;
    case 0x089C75B8u: goto L_089C75B8;
    case 0x089C75C8u: goto L_089C75C8;
    case 0x089C75D8u: goto L_089C75D8;
    case 0x089C75E8u: goto L_089C75E8;
    case 0x089C75F8u: goto L_089C75F8;
    case 0x089C7608u: goto L_089C7608;
    case 0x089C7618u: goto L_089C7618;
    case 0x089C7638u: goto L_089C7638;
    case 0x089C7650u: goto L_089C7650;
    case 0x089C7668u: goto L_089C7668;
    case 0x089C7680u: goto L_089C7680;
    case 0x089C7690u: goto L_089C7690;
    case 0x089C76A8u: goto L_089C76A8;
    case 0x089C78C0u: goto L_089C78C0;
    case 0x089C78D0u: goto L_089C78D0;
    case 0x089C7C48u: goto L_089C7C48;
    case 0x089C7C78u: goto L_089C7C78;
    case 0x089C7FECu: goto L_089C7FEC;
    case 0x089C8148u: goto L_089C8148;
    case 0x089C8150u: goto L_089C8150;
    case 0x089C86A0u: goto L_089C86A0;
    case 0x089C86A8u: goto L_089C86A8;
    case 0x089C86B0u: goto L_089C86B0;
    case 0x089C86C0u: goto L_089C86C0;
    case 0x089C86C8u: goto L_089C86C8;
    case 0x089C86DCu: goto L_089C86DC;
    case 0x089C86E4u: goto L_089C86E4;
    case 0x089C86F8u: goto L_089C86F8;
    case 0x089C8700u: goto L_089C8700;
    case 0x089C8710u: goto L_089C8710;
    case 0x089C8718u: goto L_089C8718;
    case 0x089C872Cu: goto L_089C872C;
    case 0x089C8734u: goto L_089C8734;
    case 0x089C8750u: goto L_089C8750;
    case 0x089C8758u: goto L_089C8758;
    case 0x089C876Cu: goto L_089C876C;
    case 0x089C8774u: goto L_089C8774;
    case 0x089C8788u: goto L_089C8788;
    case 0x089C8790u: goto L_089C8790;
    case 0x089C87B0u: goto L_089C87B0;
    case 0x089C87B8u: goto L_089C87B8;
    case 0x089C87C8u: goto L_089C87C8;
    case 0x089C87D0u: goto L_089C87D0;
    case 0x089C87E0u: goto L_089C87E0;
    case 0x089C87E8u: goto L_089C87E8;
    case 0x089C87FCu: goto L_089C87FC;
    case 0x089C8808u: goto L_089C8808;
    case 0x089C8814u: goto L_089C8814;
    case 0x089C8820u: goto L_089C8820;
    case 0x089C8828u: goto L_089C8828;
    case 0x089C882Cu: goto L_089C882C;
    case 0x089C8838u: goto L_089C8838;
    case 0x089C8850u: goto L_089C8850;
    case 0x089C8858u: goto L_089C8858;
    case 0x089C8878u: goto L_089C8878;
    case 0x089C8898u: goto L_089C8898;
    case 0x089C88A0u: goto L_089C88A0;
    case 0x089C88A8u: goto L_089C88A8;
    case 0x089C88ACu: goto L_089C88AC;
    case 0x089C88B8u: goto L_089C88B8;
    case 0x089C88C0u: goto L_089C88C0;
    case 0x089C88CCu: goto L_089C88CC;
    case 0x089C88D8u: goto L_089C88D8;
    case 0x089C88E4u: goto L_089C88E4;
    case 0x089C8908u: goto L_089C8908;
    case 0x089C8924u: goto L_089C8924;
    case 0x089C892Cu: goto L_089C892C;
    case 0x089C8944u: goto L_089C8944;
    case 0x089C8948u: goto L_089C8948;
    case 0x089C8950u: goto L_089C8950;
    case 0x089C8958u: goto L_089C8958;
    case 0x089C8960u: goto L_089C8960;
    case 0x089C8968u: goto L_089C8968;
    case 0x089C8970u: goto L_089C8970;
    case 0x089C8978u: goto L_089C8978;
    case 0x089C8980u: goto L_089C8980;
    case 0x089C8988u: goto L_089C8988;
    case 0x089C8990u: goto L_089C8990;
    case 0x089C8998u: goto L_089C8998;
    case 0x089C89A0u: goto L_089C89A0;
    case 0x089C89A8u: goto L_089C89A8;
    case 0x089C89B0u: goto L_089C89B0;
    case 0x089C89B8u: goto L_089C89B8;
    case 0x089C8A00u: goto L_089C8A00;
    case 0x089C8A74u: goto L_089C8A74;
    case 0x089C8A80u: goto L_089C8A80;
    case 0x089C8AD8u: goto L_089C8AD8;
    case 0x089C8D3Cu: goto L_089C8D3C;
    case 0x089C8D40u: goto L_089C8D40;
    case 0x089C8D44u: goto L_089C8D44;
    case 0x089C8D8Cu: goto L_089C8D8C;
    case 0x089C8D94u: goto L_089C8D94;
    case 0x089C8DC4u: goto L_089C8DC4;
    case 0x089C8E10u: goto L_089C8E10;
    case 0x089C8E28u: goto L_089C8E28;
    case 0x089C8E60u: goto L_089C8E60;
    case 0x089C8ED8u: goto L_089C8ED8;
    case 0x089C8EE0u: goto L_089C8EE0;
    case 0x089C8EE8u: goto L_089C8EE8;
    case 0x089C8EF0u: goto L_089C8EF0;
    case 0x089C8EF8u: goto L_089C8EF8;
    case 0x089C8F08u: goto L_089C8F08;
    case 0x089C8F10u: goto L_089C8F10;
    case 0x089C8F1Cu: goto L_089C8F1C;
    case 0x089C8F24u: goto L_089C8F24;
    case 0x089C8F2Cu: goto L_089C8F2C;
    case 0x089C8F34u: goto L_089C8F34;
    case 0x089C8F48u: goto L_089C8F48;
    case 0x089C8F54u: goto L_089C8F54;
    case 0x089C8F5Cu: goto L_089C8F5C;
    case 0x089C8F64u: goto L_089C8F64;
    case 0x089C8F6Cu: goto L_089C8F6C;
    case 0x089C8F78u: goto L_089C8F78;
    case 0x089C8F88u: goto L_089C8F88;
    case 0x089C8F94u: goto L_089C8F94;
    case 0x089C8F9Cu: goto L_089C8F9C;
    case 0x089C8FA8u: goto L_089C8FA8;
    case 0x089C8FC0u: goto L_089C8FC0;
    case 0x089C8FC8u: goto L_089C8FC8;
    case 0x089C8FD4u: goto L_089C8FD4;
    case 0x089C8FDCu: goto L_089C8FDC;
    case 0x089C8FE0u: goto L_089C8FE0;
    case 0x089C90F0u: goto L_089C90F0;
    case 0x089C9100u: goto L_089C9100;
    case 0x089C9110u: goto L_089C9110;
    case 0x089C9118u: goto L_089C9118;
    case 0x089C9120u: goto L_089C9120;
    case 0x089C912Cu: goto L_089C912C;
    case 0x089C9148u: goto L_089C9148;
    case 0x089C9154u: goto L_089C9154;
    case 0x089C9168u: goto L_089C9168;
    case 0x089C9174u: goto L_089C9174;
    case 0x089C9188u: goto L_089C9188;
    case 0x089C9298u: goto L_089C9298;
    case 0x089C929Cu: goto L_089C929C;
    case 0x089C92A0u: goto L_089C92A0;
    case 0x089C92B0u: goto L_089C92B0;
    case 0x089C92B8u: goto L_089C92B8;
    case 0x089C92C8u: goto L_089C92C8;
    case 0x089C92D0u: goto L_089C92D0;
    case 0x089C92E0u: goto L_089C92E0;
    case 0x089C92E8u: goto L_089C92E8;
    case 0x089C92F8u: goto L_089C92F8;
    case 0x089C9300u: goto L_089C9300;
    case 0x089C9310u: goto L_089C9310;
    case 0x089C9318u: goto L_089C9318;
    case 0x089C9330u: goto L_089C9330;
    case 0x089C9344u: goto L_089C9344;
    case 0x089C9348u: goto L_089C9348;
    case 0x089C9370u: goto L_089C9370;
    case 0x089C937Cu: goto L_089C937C;
    case 0x089C9390u: goto L_089C9390;
    case 0x089C9398u: goto L_089C9398;
    case 0x089C93A0u: goto L_089C93A0;
    case 0x089C93B0u: goto L_089C93B0;
    case 0x089C93B8u: goto L_089C93B8;
    case 0x089C93C8u: goto L_089C93C8;
    case 0x089C93D0u: goto L_089C93D0;
    case 0x089C93E0u: goto L_089C93E0;
    case 0x089C93E8u: goto L_089C93E8;
    case 0x089C93F0u: goto L_089C93F0;
    case 0x089C93F4u: goto L_089C93F4;
    case 0x089C93FCu: goto L_089C93FC;
    case 0x089C9424u: goto L_089C9424;
    case 0x089C942Cu: goto L_089C942C;
    case 0x089C955Cu: goto L_089C955C;
    case 0x089C9560u: goto L_089C9560;
    case 0x089C9564u: goto L_089C9564;
    case 0x089C9574u: goto L_089C9574;
    case 0x089C9584u: goto L_089C9584;
    case 0x089C9594u: goto L_089C9594;
    case 0x089C9598u: goto L_089C9598;
    case 0x089C959Cu: goto L_089C959C;
    case 0x089C95A4u: goto L_089C95A4;
    case 0x089C95ACu: goto L_089C95AC;
    case 0x089C95B8u: goto L_089C95B8;
    case 0x089C95C0u: goto L_089C95C0;
    case 0x089C95C8u: goto L_089C95C8;
    case 0x089C95CCu: goto L_089C95CC;
    case 0x089C95E0u: goto L_089C95E0;
    case 0x089C95E8u: goto L_089C95E8;
    case 0x089C9600u: goto L_089C9600;
    case 0x089C9614u: goto L_089C9614;
    case 0x089C9628u: goto L_089C9628;
    case 0x089C9634u: goto L_089C9634;
    case 0x089C963Cu: goto L_089C963C;
    case 0x089C9650u: goto L_089C9650;
    case 0x089C965Cu: goto L_089C965C;
    case 0x089C9664u: goto L_089C9664;
    case 0x089C966Cu: goto L_089C966C;
    case 0x089C9674u: goto L_089C9674;
    case 0x089C967Cu: goto L_089C967C;
    case 0x089C9680u: goto L_089C9680;
    case 0x089C96B0u: goto L_089C96B0;
    case 0x089C96E8u: goto L_089C96E8;
    case 0x089C9738u: goto L_089C9738;
    case 0x089C9740u: goto L_089C9740;
    case 0x089C9888u: goto L_089C9888;
    case 0x089C98E4u: goto L_089C98E4;
    case 0x089C98E8u: goto L_089C98E8;
    case 0x089C9AC8u: goto L_089C9AC8;
    case 0x089C9AD0u: goto L_089C9AD0;
    case 0x089C9AFCu: goto L_089C9AFC;
    case 0x089C9B00u: goto L_089C9B00;
    case 0x089C9B50u: goto L_089C9B50;
    case 0x089C9B6Cu: goto L_089C9B6C;
    case 0x089C9B88u: goto L_089C9B88;
    case 0x089C9BACu: goto L_089C9BAC;
    case 0x089C9BB8u: goto L_089C9BB8;
    case 0x089C9BC8u: goto L_089C9BC8;
    case 0x089C9BD4u: goto L_089C9BD4;
    case 0x089C9BE0u: goto L_089C9BE0;
    case 0x089C9BE8u: goto L_089C9BE8;
    case 0x089C9BF0u: goto L_089C9BF0;
    case 0x089C9BF8u: goto L_089C9BF8;
    case 0x089C9C04u: goto L_089C9C04;
    case 0x089C9C38u: goto L_089C9C38;
    case 0x089C9C48u: goto L_089C9C48;
    case 0x089C9C50u: goto L_089C9C50;
    case 0x089C9C54u: goto L_089C9C54;
    case 0x089C9C5Cu: goto L_089C9C5C;
    case 0x089C9C70u: goto L_089C9C70;
    case 0x089C9D30u: goto L_089C9D30;
    case 0x089C9D40u: goto L_089C9D40;
    case 0x089C9D48u: goto L_089C9D48;
    case 0x089C9D58u: goto L_089C9D58;
    case 0x089C9D6Cu: goto L_089C9D6C;
    case 0x089C9DACu: goto L_089C9DAC;
    case 0x089C9DB4u: goto L_089C9DB4;
    case 0x089C9DBCu: goto L_089C9DBC;
    case 0x089C9DC4u: goto L_089C9DC4;
    case 0x089C9DCCu: goto L_089C9DCC;
    case 0x089C9DD4u: goto L_089C9DD4;
    case 0x089C9DD8u: goto L_089C9DD8;
    case 0x089C9DE0u: goto L_089C9DE0;
    case 0x089C9DE8u: goto L_089C9DE8;
    case 0x089C9DF4u: goto L_089C9DF4;
    case 0x089C9DFCu: goto L_089C9DFC;
    case 0x089C9E08u: goto L_089C9E08;
    case 0x089C9E10u: goto L_089C9E10;
    case 0x089C9EC0u: goto L_089C9EC0;
    case 0x089C9EC8u: goto L_089C9EC8;
    case 0x089C9ED0u: goto L_089C9ED0;
    case 0x089C9ED8u: goto L_089C9ED8;
    case 0x089C9EE0u: goto L_089C9EE0;
    case 0x089C9EE8u: goto L_089C9EE8;
    case 0x089C9F00u: goto L_089C9F00;
    case 0x089C9F14u: goto L_089C9F14;
    case 0x089C9F20u: goto L_089C9F20;
    case 0x089C9F34u: goto L_089C9F34;
    case 0x089C9F38u: goto L_089C9F38;
    case 0x089C9F58u: goto L_089C9F58;
    case 0x089C9F64u: goto L_089C9F64;
    case 0x089C9F70u: goto L_089C9F70;
    case 0x089C9F88u: goto L_089C9F88;
    case 0x089C9FA0u: goto L_089C9FA0;
    case 0x089C9FB8u: goto L_089C9FB8;
    case 0x089C9FC4u: goto L_089C9FC4;
    case 0x089C9FD8u: goto L_089C9FD8;
    case 0x089C9FE8u: goto L_089C9FE8;
    case 0x089CA004u: goto L_089CA004;
    case 0x089CA0C0u: goto L_089CA0C0;
    case 0x089CA0C4u: goto L_089CA0C4;
    case 0x089CA0C8u: goto L_089CA0C8;
    case 0x089CA0E0u: goto L_089CA0E0;
    case 0x089CA0ECu: goto L_089CA0EC;
    case 0x089CA100u: goto L_089CA100;
    case 0x089CA10Cu: goto L_089CA10C;
    case 0x089CA11Cu: goto L_089CA11C;
    case 0x089CA128u: goto L_089CA128;
    case 0x089CA134u: goto L_089CA134;
    case 0x089CA13Cu: goto L_089CA13C;
    case 0x089CA148u: goto L_089CA148;
    case 0x089CA154u: goto L_089CA154;
    case 0x089CA15Cu: goto L_089CA15C;
    case 0x089CA160u: goto L_089CA160;
    case 0x089CA16Cu: goto L_089CA16C;
    case 0x089CA17Cu: goto L_089CA17C;
    case 0x089CA188u: goto L_089CA188;
    case 0x089CA194u: goto L_089CA194;
    case 0x089CA19Cu: goto L_089CA19C;
    case 0x089CA1B0u: goto L_089CA1B0;
    case 0x089CA1B8u: goto L_089CA1B8;
    case 0x089CA1D0u: goto L_089CA1D0;
    case 0x089CA1D8u: goto L_089CA1D8;
    case 0x089CA1F0u: goto L_089CA1F0;
    case 0x089CA1F8u: goto L_089CA1F8;
    case 0x089CA20Cu: goto L_089CA20C;
    case 0x089CA224u: goto L_089CA224;
    case 0x089CA23Cu: goto L_089CA23C;
    case 0x089CA258u: goto L_089CA258;
    case 0x089CA260u: goto L_089CA260;
    case 0x089CA26Cu: goto L_089CA26C;
    case 0x089CA274u: goto L_089CA274;
    case 0x089CA280u: goto L_089CA280;
    case 0x089CA298u: goto L_089CA298;
    case 0x089CA2B8u: goto L_089CA2B8;
    case 0x089CA2D8u: goto L_089CA2D8;
    case 0x089CA2F4u: goto L_089CA2F4;
    case 0x089CA304u: goto L_089CA304;
    case 0x089CA310u: goto L_089CA310;
    case 0x089CA320u: goto L_089CA320;
    case 0x089CA32Cu: goto L_089CA32C;
    case 0x089CA334u: goto L_089CA334;
    case 0x089CA34Cu: goto L_089CA34C;
    case 0x089CA354u: goto L_089CA354;
    case 0x089CA364u: goto L_089CA364;
    case 0x089CA36Cu: goto L_089CA36C;
    case 0x089CA380u: goto L_089CA380;
    case 0x089CA388u: goto L_089CA388;
    case 0x089CA398u: goto L_089CA398;
    case 0x089CA3A0u: goto L_089CA3A0;
    case 0x089CA3B4u: goto L_089CA3B4;
    case 0x089CA3C4u: goto L_089CA3C4;
    case 0x089CA3D0u: goto L_089CA3D0;
    case 0x089CA3E0u: goto L_089CA3E0;
    case 0x089CA3E8u: goto L_089CA3E8;
    case 0x089CA3F0u: goto L_089CA3F0;
    case 0x089CA3FCu: goto L_089CA3FC;
    case 0x089CA418u: goto L_089CA418;
    case 0x089CA430u: goto L_089CA430;
    case 0x089CA434u: goto L_089CA434;
    case 0x089CA44Cu: goto L_089CA44C;
    case 0x089CA464u: goto L_089CA464;
    case 0x089CA470u: goto L_089CA470;
    case 0x089CA488u: goto L_089CA488;
    case 0x089CA4A4u: goto L_089CA4A4;
    case 0x089CA4A8u: goto L_089CA4A8;
    case 0x089CA4B0u: goto L_089CA4B0;
    case 0x089CA4B8u: goto L_089CA4B8;
    case 0x089CA4C4u: goto L_089CA4C4;
    case 0x089CA4DCu: goto L_089CA4DC;
    case 0x089CA4E8u: goto L_089CA4E8;
    case 0x089CA580u: goto L_089CA580;
    case 0x089CA59Cu: goto L_089CA59C;
    case 0x089CA5A4u: goto L_089CA5A4;
    case 0x089CA5B0u: goto L_089CA5B0;
    case 0x089CA5F8u: goto L_089CA5F8;
    case 0x089CA600u: goto L_089CA600;
    case 0x089CA638u: goto L_089CA638;
    case 0x089CA670u: goto L_089CA670;
    case 0x089CA6A8u: goto L_089CA6A8;
    case 0x089CA6E0u: goto L_089CA6E0;
    case 0x089CA720u: goto L_089CA720;
    case 0x089CA730u: goto L_089CA730;
    case 0x089CA740u: goto L_089CA740;
    case 0x089CA748u: goto L_089CA748;
    case 0x089CA758u: goto L_089CA758;
    case 0x089CA768u: goto L_089CA768;
    case 0x089CA778u: goto L_089CA778;
    case 0x089CA77Cu: goto L_089CA77C;
    case 0x089CA788u: goto L_089CA788;
    case 0x089CA78Cu: goto L_089CA78C;
    case 0x089CA790u: goto L_089CA790;
    case 0x089CA798u: goto L_089CA798;
    case 0x089CA7A8u: goto L_089CA7A8;
    case 0x089CA7ACu: goto L_089CA7AC;
    case 0x089CA7B0u: goto L_089CA7B0;
    case 0x089CA7B8u: goto L_089CA7B8;
    case 0x089CA7C8u: goto L_089CA7C8;
    case 0x089CA7D8u: goto L_089CA7D8;
    case 0x089CA7F0u: goto L_089CA7F0;
    case 0x089CA804u: goto L_089CA804;
    case 0x089CA814u: goto L_089CA814;
    case 0x089CA820u: goto L_089CA820;
    case 0x089CA82Cu: goto L_089CA82C;
    case 0x089CA868u: goto L_089CA868;
    case 0x089CA878u: goto L_089CA878;
    case 0x089CA884u: goto L_089CA884;
    case 0x089CA888u: goto L_089CA888;
    case 0x089CA890u: goto L_089CA890;
    case 0x089CA8B0u: goto L_089CA8B0;
    case 0x089CA8D0u: goto L_089CA8D0;
    case 0x089CA8D8u: goto L_089CA8D8;
    case 0x089CA8F0u: goto L_089CA8F0;
    case 0x089CA8F8u: goto L_089CA8F8;
    case 0x089CA910u: goto L_089CA910;
    case 0x089CA918u: goto L_089CA918;
    case 0x089CA920u: goto L_089CA920;
    case 0x089CA928u: goto L_089CA928;
    case 0x089CA938u: goto L_089CA938;
    case 0x089CA940u: goto L_089CA940;
    case 0x089CA948u: goto L_089CA948;
    case 0x089CA954u: goto L_089CA954;
    case 0x089CA95Cu: goto L_089CA95C;
    case 0x089CAA10u: goto L_089CAA10;
    case 0x089CAAB0u: goto L_089CAAB0;
    case 0x089CAAB8u: goto L_089CAAB8;
    case 0x089CAAC4u: goto L_089CAAC4;
    case 0x089CAACCu: goto L_089CAACC;
    case 0x089CAAD0u: goto L_089CAAD0;
    case 0x089CAB04u: goto L_089CAB04;
    case 0x089CAB10u: goto L_089CAB10;
    case 0x089CAB14u: goto L_089CAB14;
    case 0x089CAB18u: goto L_089CAB18;
    case 0x089CAB28u: goto L_089CAB28;
    case 0x089CAB38u: goto L_089CAB38;
    case 0x089CAB50u: goto L_089CAB50;
    case 0x089CAB58u: goto L_089CAB58;
    case 0x089CAB60u: goto L_089CAB60;
    case 0x089CAB68u: goto L_089CAB68;
    case 0x089CAB70u: goto L_089CAB70;
    case 0x089CAB80u: goto L_089CAB80;
    case 0x089CAB88u: goto L_089CAB88;
    case 0x089CAB94u: goto L_089CAB94;
    case 0x089CABA0u: goto L_089CABA0;
    case 0x089CABB8u: goto L_089CABB8;
    case 0x089CABD0u: goto L_089CABD0;
    case 0x089CABE0u: goto L_089CABE0;
    case 0x089CABF8u: goto L_089CABF8;
    case 0x089CAC10u: goto L_089CAC10;
    case 0x089CAC20u: goto L_089CAC20;
    case 0x089CAC38u: goto L_089CAC38;
    case 0x089CAC90u: goto L_089CAC90;
    case 0x089CACE8u: goto L_089CACE8;
    case 0x089CAE48u: goto L_089CAE48;
    case 0x089CAE58u: goto L_089CAE58;
    case 0x089CAE70u: goto L_089CAE70;
    case 0x089CAE7Cu: goto L_089CAE7C;
    case 0x089CAE8Cu: goto L_089CAE8C;
    case 0x089CAEA8u: goto L_089CAEA8;
    case 0x089CAEB8u: goto L_089CAEB8;
    case 0x089CAECCu: goto L_089CAECC;
    case 0x089CAEF8u: goto L_089CAEF8;
    case 0x089CAF0Cu: goto L_089CAF0C;
    case 0x089CAF18u: goto L_089CAF18;
    case 0x089CAF24u: goto L_089CAF24;
    case 0x089CAF28u: goto L_089CAF28;
    case 0x089CAF38u: goto L_089CAF38;
    case 0x089CAF58u: goto L_089CAF58;
    case 0x089CAF68u: goto L_089CAF68;
    case 0x089CAF78u: goto L_089CAF78;
    case 0x089CAF94u: goto L_089CAF94;
    case 0x089CAFB0u: goto L_089CAFB0;
    case 0x089CAFCCu: goto L_089CAFCC;
    case 0x089CAFE8u: goto L_089CAFE8;
    case 0x089CB004u: goto L_089CB004;
    case 0x089CB020u: goto L_089CB020;
    case 0x089CB03Cu: goto L_089CB03C;
    case 0x089CB05Cu: goto L_089CB05C;
    case 0x089CB104u: goto L_089CB104;
    case 0x089CB188u: goto L_089CB188;
    case 0x089CB1B0u: goto L_089CB1B0;
    case 0x089CB1F8u: goto L_089CB1F8;
    case 0x089CB228u: goto L_089CB228;
    case 0x089CB238u: goto L_089CB238;
    case 0x089CB248u: goto L_089CB248;
    case 0x089CB290u: goto L_089CB290;
    case 0x089CB298u: goto L_089CB298;
    case 0x089CB2ACu: goto L_089CB2AC;
    case 0x089CB2C4u: goto L_089CB2C4;
    case 0x089CB2D4u: goto L_089CB2D4;
    case 0x089CB2E8u: goto L_089CB2E8;
    case 0x089CB2F8u: goto L_089CB2F8;
    case 0x089CB314u: goto L_089CB314;
    case 0x089CB334u: goto L_089CB334;
    case 0x089CB354u: goto L_089CB354;
    case 0x089CB358u: goto L_089CB358;
    case 0x089CB360u: goto L_089CB360;
    case 0x089CB36Cu: goto L_089CB36C;
    case 0x089CB3BCu: goto L_089CB3BC;
    case 0x089CB3D8u: goto L_089CB3D8;
    case 0x089CB3E8u: goto L_089CB3E8;
    case 0x089CB3F0u: goto L_089CB3F0;
    case 0x089CB3FCu: goto L_089CB3FC;
    case 0x089CB408u: goto L_089CB408;
    case 0x089CB410u: goto L_089CB410;
    case 0x089CB428u: goto L_089CB428;
    case 0x089CB434u: goto L_089CB434;
    case 0x089CB480u: goto L_089CB480;
    case 0x089CB488u: goto L_089CB488;
    case 0x089CB494u: goto L_089CB494;
    case 0x089CB4A4u: goto L_089CB4A4;
    case 0x089CB4B4u: goto L_089CB4B4;
    case 0x089CB4C4u: goto L_089CB4C4;
    case 0x089CB4CCu: goto L_089CB4CC;
    case 0x089CB4D4u: goto L_089CB4D4;
    case 0x089CB538u: goto L_089CB538;
    case 0x089CB650u: goto L_089CB650;
    case 0x089CB680u: goto L_089CB680;
    case 0x089CB6E8u: goto L_089CB6E8;
    case 0x089CB6F8u: goto L_089CB6F8;
    case 0x089CB700u: goto L_089CB700;
    case 0x089CB708u: goto L_089CB708;
    case 0x089CB718u: goto L_089CB718;
    case 0x089CB724u: goto L_089CB724;
    case 0x089CB728u: goto L_089CB728;
    case 0x089CB72Cu: goto L_089CB72C;
    case 0x089CB740u: goto L_089CB740;
    case 0x089CB758u: goto L_089CB758;
    case 0x089CB760u: goto L_089CB760;
    case 0x089CB768u: goto L_089CB768;
    case 0x089CB770u: goto L_089CB770;
    case 0x089CB774u: goto L_089CB774;
    case 0x089CB778u: goto L_089CB778;
    case 0x089CB788u: goto L_089CB788;
    case 0x089CB7A0u: goto L_089CB7A0;
    case 0x089CB7B0u: goto L_089CB7B0;
    case 0x089CB7C8u: goto L_089CB7C8;
    case 0x089CB7E8u: goto L_089CB7E8;
    case 0x089CB898u: goto L_089CB898;
    case 0x089CB8A0u: goto L_089CB8A0;
    case 0x089CB8A8u: goto L_089CB8A8;
    case 0x089CB8B0u: goto L_089CB8B0;
    case 0x089CB8B8u: goto L_089CB8B8;
    case 0x089CB8C0u: goto L_089CB8C0;
    case 0x089CB8C8u: goto L_089CB8C8;
    case 0x089CB8D0u: goto L_089CB8D0;
    case 0x089CB8D8u: goto L_089CB8D8;
    case 0x089CB8E0u: goto L_089CB8E0;
    case 0x089CB8E8u: goto L_089CB8E8;
    case 0x089CB8F0u: goto L_089CB8F0;
    case 0x089CB8F8u: goto L_089CB8F8;
    case 0x089CB900u: goto L_089CB900;
    case 0x089CB908u: goto L_089CB908;
    case 0x089CB910u: goto L_089CB910;
    case 0x089CB918u: goto L_089CB918;
    case 0x089CB920u: goto L_089CB920;
    case 0x089CB928u: goto L_089CB928;
    case 0x089CB930u: goto L_089CB930;
    case 0x089CB938u: goto L_089CB938;
    case 0x089CB940u: goto L_089CB940;
    case 0x089CB948u: goto L_089CB948;
    case 0x089CB950u: goto L_089CB950;
    case 0x089CB958u: goto L_089CB958;
    case 0x089CB960u: goto L_089CB960;
    case 0x089CB968u: goto L_089CB968;
    case 0x089CB970u: goto L_089CB970;
    case 0x089CB978u: goto L_089CB978;
    case 0x089CB980u: goto L_089CB980;
    case 0x089CB988u: goto L_089CB988;
    case 0x089CB990u: goto L_089CB990;
    case 0x089CB998u: goto L_089CB998;
    case 0x089CB9A0u: goto L_089CB9A0;
    case 0x089CB9A8u: goto L_089CB9A8;
    case 0x089CB9B0u: goto L_089CB9B0;
    case 0x089CB9B8u: goto L_089CB9B8;
    case 0x089CB9C0u: goto L_089CB9C0;
    case 0x089CB9C8u: goto L_089CB9C8;
    case 0x089CB9D0u: goto L_089CB9D0;
    case 0x089CB9D8u: goto L_089CB9D8;
    case 0x089CB9E0u: goto L_089CB9E0;
    case 0x089CB9E8u: goto L_089CB9E8;
    case 0x089CB9ECu: goto L_089CB9EC;
    case 0x089CB9F8u: goto L_089CB9F8;
    case 0x089CBA00u: goto L_089CBA00;
    case 0x089CBA0Cu: goto L_089CBA0C;
    case 0x089CBA18u: goto L_089CBA18;
    case 0x089CBA28u: goto L_089CBA28;
    case 0x089CBA38u: goto L_089CBA38;
    case 0x089CBA50u: goto L_089CBA50;
    case 0x089CBA68u: goto L_089CBA68;
    case 0x089CBA70u: goto L_089CBA70;
    case 0x089CBA78u: goto L_089CBA78;
    case 0x089CBA80u: goto L_089CBA80;
    case 0x089CBA88u: goto L_089CBA88;
    case 0x089CBA94u: goto L_089CBA94;
    case 0x089CBAB0u: goto L_089CBAB0;
    case 0x089CBB70u: goto L_089CBB70;
    case 0x089CBB7Cu: goto L_089CBB7C;
    case 0x089CBB9Cu: goto L_089CBB9C;
    case 0x089CBBECu: goto L_089CBBEC;
    case 0x089CBC38u: goto L_089CBC38;
    case 0x089CBC58u: goto L_089CBC58;
    case 0x089CBC98u: goto L_089CBC98;
    case 0x089CBCA0u: goto L_089CBCA0;
    case 0x089CBCA8u: goto L_089CBCA8;
    case 0x089CBCB0u: goto L_089CBCB0;
    case 0x089CBCB8u: goto L_089CBCB8;
    case 0x089CBCC8u: goto L_089CBCC8;
    case 0x089CBCE0u: goto L_089CBCE0;
    case 0x089CBCF4u: goto L_089CBCF4;
    case 0x089CBD04u: goto L_089CBD04;
    case 0x089CBD10u: goto L_089CBD10;
    case 0x089CBD24u: goto L_089CBD24;
    case 0x089CBD2Cu: goto L_089CBD2C;
    case 0x089CBD50u: goto L_089CBD50;
    case 0x089CBD74u: goto L_089CBD74;
    case 0x089CBD84u: goto L_089CBD84;
    case 0x089CBD90u: goto L_089CBD90;
    case 0x089CBDA4u: goto L_089CBDA4;
    case 0x089CBDB0u: goto L_089CBDB0;
    case 0x089CBDBCu: goto L_089CBDBC;
    case 0x089CBDC8u: goto L_089CBDC8;
    case 0x089CBDD4u: goto L_089CBDD4;
    case 0x089CBDDCu: goto L_089CBDDC;
    case 0x089CBDE4u: goto L_089CBDE4;
    case 0x089CBDECu: goto L_089CBDEC;
    case 0x089CBDF4u: goto L_089CBDF4;
    case 0x089CBE00u: goto L_089CBE00;
    case 0x089CBE08u: goto L_089CBE08;
    case 0x089CBE10u: goto L_089CBE10;
    case 0x089CBE14u: goto L_089CBE14;
    case 0x089CBE1Cu: goto L_089CBE1C;
    case 0x089CBE24u: goto L_089CBE24;
    case 0x089CBE2Cu: goto L_089CBE2C;
    case 0x089CBE40u: goto L_089CBE40;
    case 0x089CBE48u: goto L_089CBE48;
    case 0x089CBE50u: goto L_089CBE50;
    case 0x089CBE60u: goto L_089CBE60;
    case 0x089CBF04u: goto L_089CBF04;
    case 0x089CC00Cu: goto L_089CC00C;
    case 0x089CC020u: goto L_089CC020;
    case 0x089CC0A4u: goto L_089CC0A4;
    case 0x089CC0B0u: goto L_089CC0B0;
    case 0x089CC0C0u: goto L_089CC0C0;
    case 0x089CC0C8u: goto L_089CC0C8;
    case 0x089CC0D8u: goto L_089CC0D8;
    case 0x089CC0F0u: goto L_089CC0F0;
    case 0x089CC110u: goto L_089CC110;
    case 0x089CC128u: goto L_089CC128;
    case 0x089CC148u: goto L_089CC148;
    case 0x089CC160u: goto L_089CC160;
    case 0x089CC180u: goto L_089CC180;
    case 0x089CC188u: goto L_089CC188;
    case 0x089CC1C0u: goto L_089CC1C0;
    case 0x089CC1D8u: goto L_089CC1D8;
    case 0x089CC1E8u: goto L_089CC1E8;
    case 0x089CC200u: goto L_089CC200;
    case 0x089CC204u: goto L_089CC204;
    case 0x089CC21Cu: goto L_089CC21C;
    case 0x089CC220u: goto L_089CC220;
    case 0x089CC238u: goto L_089CC238;
    case 0x089CC240u: goto L_089CC240;
    case 0x089CC250u: goto L_089CC250;
    case 0x089CC268u: goto L_089CC268;
    case 0x089CC270u: goto L_089CC270;
    case 0x089CC290u: goto L_089CC290;
    case 0x089CC2A0u: goto L_089CC2A0;
    case 0x089CC2A8u: goto L_089CC2A8;
    case 0x089CC2B8u: goto L_089CC2B8;
    case 0x089CC2C0u: goto L_089CC2C0;
    case 0x089CC2C8u: goto L_089CC2C8;
    case 0x089CC2D0u: goto L_089CC2D0;
    case 0x089CC2E0u: goto L_089CC2E0;
    case 0x089CC2E8u: goto L_089CC2E8;
    case 0x089CC2F0u: goto L_089CC2F0;
    case 0x089CC2F8u: goto L_089CC2F8;
    case 0x089CC308u: goto L_089CC308;
    case 0x089CC330u: goto L_089CC330;
    case 0x089CC348u: goto L_089CC348;
    case 0x089CC358u: goto L_089CC358;
    case 0x089CC37Cu: goto L_089CC37C;
    case 0x089CC384u: goto L_089CC384;
    case 0x089CC4A0u: goto L_089CC4A0;
    case 0x089CC538u: goto L_089CC538;
    case 0x089CC548u: goto L_089CC548;
    case 0x089CC568u: goto L_089CC568;
    case 0x089CC58Cu: goto L_089CC58C;
    case 0x089CC59Cu: goto L_089CC59C;
    case 0x089CC5A8u: goto L_089CC5A8;
    case 0x089CC5ACu: goto L_089CC5AC;
    case 0x089CC5B4u: goto L_089CC5B4;
    case 0x089CC610u: goto L_089CC610;
    case 0x089CC710u: goto L_089CC710;
    case 0x089CC72Cu: goto L_089CC72C;
    case 0x089CC738u: goto L_089CC738;
    case 0x089CC7A0u: goto L_089CC7A0;
    case 0x089CC7B0u: goto L_089CC7B0;
    case 0x089CC7B8u: goto L_089CC7B8;
    case 0x089CC7CCu: goto L_089CC7CC;
    case 0x089CC7D4u: goto L_089CC7D4;
    case 0x089CC7E0u: goto L_089CC7E0;
    case 0x089CC7F0u: goto L_089CC7F0;
    case 0x089CC800u: goto L_089CC800;
    case 0x089CC808u: goto L_089CC808;
    case 0x089CC810u: goto L_089CC810;
    case 0x089CC820u: goto L_089CC820;
    case 0x089CC834u: goto L_089CC834;
    case 0x089CC840u: goto L_089CC840;
    case 0x089CC84Cu: goto L_089CC84C;
    case 0x089CC85Cu: goto L_089CC85C;
    case 0x089CC870u: goto L_089CC870;
    case 0x089CC878u: goto L_089CC878;
    case 0x089CC884u: goto L_089CC884;
    case 0x089CC898u: goto L_089CC898;
    case 0x089CC8A0u: goto L_089CC8A0;
    case 0x089CC8ACu: goto L_089CC8AC;
    case 0x089CC8C4u: goto L_089CC8C4;
    case 0x089CC8CCu: goto L_089CC8CC;
    case 0x089CC8D8u: goto L_089CC8D8;
    case 0x089CC8F0u: goto L_089CC8F0;
    case 0x089CC8F8u: goto L_089CC8F8;
    case 0x089CC904u: goto L_089CC904;
    case 0x089CC918u: goto L_089CC918;
    case 0x089CC92Cu: goto L_089CC92C;
    case 0x089CC934u: goto L_089CC934;
    case 0x089CC93Cu: goto L_089CC93C;
    case 0x089CC950u: goto L_089CC950;
    case 0x089CC958u: goto L_089CC958;
    case 0x089CC95Cu: goto L_089CC95C;
    case 0x089CC964u: goto L_089CC964;
    case 0x089CC970u: goto L_089CC970;
    case 0x089CC97Cu: goto L_089CC97C;
    case 0x089CC9A8u: goto L_089CC9A8;
    case 0x089CC9B8u: goto L_089CC9B8;
    case 0x089CC9C8u: goto L_089CC9C8;
    case 0x089CC9D8u: goto L_089CC9D8;
    case 0x089CC9E8u: goto L_089CC9E8;
    case 0x089CC9F8u: goto L_089CC9F8;
    case 0x089CCA0Cu: goto L_089CCA0C;
    case 0x089CCA28u: goto L_089CCA28;
    case 0x089CCA60u: goto L_089CCA60;
    case 0x089CCA6Cu: goto L_089CCA6C;
    case 0x089CCA74u: goto L_089CCA74;
    case 0x089CCA7Cu: goto L_089CCA7C;
    case 0x089CCA98u: goto L_089CCA98;
    case 0x089CCAA4u: goto L_089CCAA4;
    case 0x089CCAACu: goto L_089CCAAC;
    case 0x089CCAB4u: goto L_089CCAB4;
    case 0x089CCAD0u: goto L_089CCAD0;
    case 0x089CCB08u: goto L_089CCB08;
    case 0x089CCB48u: goto L_089CCB48;
    case 0x089CCB54u: goto L_089CCB54;
    case 0x089CCB80u: goto L_089CCB80;
    case 0x089CCB90u: goto L_089CCB90;
    case 0x089CCBB8u: goto L_089CCBB8;
    case 0x089CCBC0u: goto L_089CCBC0;
    case 0x089CCBDCu: goto L_089CCBDC;
    case 0x089CCBE4u: goto L_089CCBE4;
    case 0x089CCBFCu: goto L_089CCBFC;
    case 0x089CCC04u: goto L_089CCC04;
    case 0x089CCC0Cu: goto L_089CCC0C;
    case 0x089CCC14u: goto L_089CCC14;
    case 0x089CCC1Cu: goto L_089CCC1C;
    case 0x089CCC2Cu: goto L_089CCC2C;
    case 0x089CCC34u: goto L_089CCC34;
    case 0x089CCC44u: goto L_089CCC44;
    case 0x089CCC4Cu: goto L_089CCC4C;
    case 0x089CCC70u: goto L_089CCC70;
    case 0x089CCC88u: goto L_089CCC88;
    case 0x089CCCF8u: goto L_089CCCF8;
    case 0x089CCD20u: goto L_089CCD20;
    case 0x089CCD30u: goto L_089CCD30;
    case 0x089CCD70u: goto L_089CCD70;
    case 0x089CCDB8u: goto L_089CCDB8;
    case 0x089CCDC8u: goto L_089CCDC8;
    case 0x089CCE20u: goto L_089CCE20;
    case 0x089CCE28u: goto L_089CCE28;
    case 0x089CCE38u: goto L_089CCE38;
    case 0x089CCE68u: goto L_089CCE68;
    case 0x089CCE9Cu: goto L_089CCE9C;
    case 0x089CCEBCu: goto L_089CCEBC;
    case 0x089CCF44u: goto L_089CCF44;
    case 0x089CCFACu: goto L_089CCFAC;
    case 0x089CCFD4u: goto L_089CCFD4;
    case 0x089CD03Cu: goto L_089CD03C;
    case 0x089CD048u: goto L_089CD048;
    case 0x089CD050u: goto L_089CD050;
    case 0x089CD06Cu: goto L_089CD06C;
    case 0x089CD070u: goto L_089CD070;
    case 0x089CD1FCu: goto L_089CD1FC;
    case 0x089CD220u: goto L_089CD220;
    case 0x089CD258u: goto L_089CD258;
    case 0x089CD2B0u: goto L_089CD2B0;
    case 0x089CD2D4u: goto L_089CD2D4;
    case 0x089CD314u: goto L_089CD314;
    case 0x089CD328u: goto L_089CD328;
    case 0x089CD408u: goto L_089CD408;
    case 0x089CD410u: goto L_089CD410;
    case 0x089CD420u: goto L_089CD420;
    case 0x089CD434u: goto L_089CD434;
    case 0x089CD448u: goto L_089CD448;
    case 0x089CD45Cu: goto L_089CD45C;
    case 0x089CD470u: goto L_089CD470;
    case 0x089CD484u: goto L_089CD484;
    case 0x089CD498u: goto L_089CD498;
    case 0x089CD4ACu: goto L_089CD4AC;
    case 0x089CD4C0u: goto L_089CD4C0;
    case 0x089CD4D4u: goto L_089CD4D4;
    case 0x089CD4E8u: goto L_089CD4E8;
    case 0x089CD4FCu: goto L_089CD4FC;
    case 0x089CD510u: goto L_089CD510;
    case 0x089CD524u: goto L_089CD524;
    case 0x089CD538u: goto L_089CD538;
    case 0x089CD54Cu: goto L_089CD54C;
    case 0x089CD560u: goto L_089CD560;
    case 0x089CD574u: goto L_089CD574;
    case 0x089CD588u: goto L_089CD588;
    case 0x089CD59Cu: goto L_089CD59C;
    case 0x089CD5B0u: goto L_089CD5B0;
    case 0x089CD5C4u: goto L_089CD5C4;
    case 0x089CD5D8u: goto L_089CD5D8;
    case 0x089CD5ECu: goto L_089CD5EC;
    case 0x089CD600u: goto L_089CD600;
    case 0x089CD614u: goto L_089CD614;
    case 0x089CD628u: goto L_089CD628;
    case 0x089CD63Cu: goto L_089CD63C;
    case 0x089CD65Cu: goto L_089CD65C;
    case 0x089CD66Cu: goto L_089CD66C;
    case 0x089CD68Cu: goto L_089CD68C;
    case 0x089CD694u: goto L_089CD694;
    case 0x089CD72Cu: goto L_089CD72C;
    case 0x089CD74Cu: goto L_089CD74C;
    case 0x089CD75Cu: goto L_089CD75C;
    case 0x089CD790u: goto L_089CD790;
    case 0x089CD858u: goto L_089CD858;
    case 0x089CD880u: goto L_089CD880;
    case 0x089CD8D0u: goto L_089CD8D0;
    case 0x089CD90Cu: goto L_089CD90C;
    case 0x089CD9D8u: goto L_089CD9D8;
    case 0x089CD9F8u: goto L_089CD9F8;
    case 0x089CDA18u: goto L_089CDA18;
    case 0x089CDA20u: goto L_089CDA20;
    case 0x089CDA28u: goto L_089CDA28;
    case 0x089CDA50u: goto L_089CDA50;
    case 0x089CDA60u: goto L_089CDA60;
    case 0x089CDA70u: goto L_089CDA70;
    case 0x089CDA80u: goto L_089CDA80;
    case 0x089CDA98u: goto L_089CDA98;
    case 0x089CDAA8u: goto L_089CDAA8;
    case 0x089CDB18u: goto L_089CDB18;
    case 0x089CDB28u: goto L_089CDB28;
    case 0x089CDB70u: goto L_089CDB70;
    case 0x089CDBC0u: goto L_089CDBC0;
    case 0x089CDBE0u: goto L_089CDBE0;
    case 0x089CDC40u: goto L_089CDC40;
    case 0x089CDCA0u: goto L_089CDCA0;
    case 0x089CDCC0u: goto L_089CDCC0;
    case 0x089CDD18u: goto L_089CDD18;
    case 0x089CDD30u: goto L_089CDD30;
    case 0x089CDD60u: goto L_089CDD60;
    case 0x089CDD78u: goto L_089CDD78;
    case 0x089CDD88u: goto L_089CDD88;
    case 0x089CDE50u: goto L_089CDE50;
    case 0x089CDF18u: goto L_089CDF18;
    case 0x089CE038u: goto L_089CE038;
    case 0x089CE040u: goto L_089CE040;
    case 0x089CE060u: goto L_089CE060;
    case 0x089CE068u: goto L_089CE068;
    case 0x089CE070u: goto L_089CE070;
    case 0x089CE078u: goto L_089CE078;
    case 0x089CE084u: goto L_089CE084;
    case 0x089CE08Cu: goto L_089CE08C;
    case 0x089CE094u: goto L_089CE094;
    case 0x089CE09Cu: goto L_089CE09C;
    case 0x089CE0A4u: goto L_089CE0A4;
    case 0x089CE0ACu: goto L_089CE0AC;
    case 0x089CE0B4u: goto L_089CE0B4;
    case 0x089CE0BCu: goto L_089CE0BC;
    case 0x089CE0C4u: goto L_089CE0C4;
    case 0x089CE0CCu: goto L_089CE0CC;
    case 0x089CE0D4u: goto L_089CE0D4;
    case 0x089CE0F8u: goto L_089CE0F8;
    case 0x089CE138u: goto L_089CE138;
    case 0x089CE140u: goto L_089CE140;
    case 0x089CE154u: goto L_089CE154;
    case 0x089CE15Cu: goto L_089CE15C;
    case 0x089CE168u: goto L_089CE168;
    case 0x089CE178u: goto L_089CE178;
    case 0x089CE188u: goto L_089CE188;
    case 0x089CE190u: goto L_089CE190;
    case 0x089CE198u: goto L_089CE198;
    case 0x089CE1A0u: goto L_089CE1A0;
    case 0x089CE1A8u: goto L_089CE1A8;
    case 0x089CE1B4u: goto L_089CE1B4;
    case 0x089CE1C0u: goto L_089CE1C0;
    case 0x089CE1D0u: goto L_089CE1D0;
    case 0x089CE1E8u: goto L_089CE1E8;
    case 0x089CE200u: goto L_089CE200;
    case 0x089CE230u: goto L_089CE230;
    case 0x089CE244u: goto L_089CE244;
    case 0x089CE250u: goto L_089CE250;
    case 0x089CE3B0u: goto L_089CE3B0;
    case 0x089CE3C4u: goto L_089CE3C4;
    case 0x089CE3D0u: goto L_089CE3D0;
    case 0x089CE3D4u: goto L_089CE3D4;
    case 0x089CE3E4u: goto L_089CE3E4;
    case 0x089CE3E8u: goto L_089CE3E8;
    case 0x089CE3F8u: goto L_089CE3F8;
    case 0x089CE400u: goto L_089CE400;
    case 0x089CE40Cu: goto L_089CE40C;
    case 0x089CE418u: goto L_089CE418;
    case 0x089CE424u: goto L_089CE424;
    case 0x089CE460u: goto L_089CE460;
    case 0x089CE468u: goto L_089CE468;
    case 0x089CE474u: goto L_089CE474;
    case 0x089CE488u: goto L_089CE488;
    case 0x089CE490u: goto L_089CE490;
    case 0x089CE49Cu: goto L_089CE49C;
    case 0x089CE4B4u: goto L_089CE4B4;
    case 0x089CE4BCu: goto L_089CE4BC;
    case 0x089CE4C8u: goto L_089CE4C8;
    case 0x089CE4E0u: goto L_089CE4E0;
    case 0x089CE4E8u: goto L_089CE4E8;
    case 0x089CE4F4u: goto L_089CE4F4;
    case 0x089CE508u: goto L_089CE508;
    case 0x089CE51Cu: goto L_089CE51C;
    case 0x089CE524u: goto L_089CE524;
    case 0x089CE52Cu: goto L_089CE52C;
    case 0x089CE540u: goto L_089CE540;
    case 0x089CE548u: goto L_089CE548;
    case 0x089CE54Cu: goto L_089CE54C;
    case 0x089CE554u: goto L_089CE554;
    case 0x089CE560u: goto L_089CE560;
    case 0x089CE56Cu: goto L_089CE56C;
    case 0x089CE580u: goto L_089CE580;
    case 0x089CE594u: goto L_089CE594;
    case 0x089CE5ACu: goto L_089CE5AC;
    case 0x089CE5BCu: goto L_089CE5BC;
    case 0x089CE620u: goto L_089CE620;
    case 0x089CE630u: goto L_089CE630;
    case 0x089CE640u: goto L_089CE640;
    case 0x089CE650u: goto L_089CE650;
    case 0x089CE690u: goto L_089CE690;
    case 0x089CE698u: goto L_089CE698;
    case 0x089CE6A0u: goto L_089CE6A0;
    case 0x089CE6ACu: goto L_089CE6AC;
    case 0x089CE6B0u: goto L_089CE6B0;
    case 0x089CE6D4u: goto L_089CE6D4;
    case 0x089CE6DCu: goto L_089CE6DC;
    case 0x089CE700u: goto L_089CE700;
    case 0x089CE708u: goto L_089CE708;
    case 0x089CE730u: goto L_089CE730;
    case 0x089CE738u: goto L_089CE738;
    case 0x089CE74Cu: goto L_089CE74C;
    case 0x089CE768u: goto L_089CE768;
    case 0x089CE76Cu: goto L_089CE76C;
    case 0x089CE780u: goto L_089CE780;
    case 0x089CE7C0u: goto L_089CE7C0;
    case 0x089CE7D4u: goto L_089CE7D4;
    case 0x089CE7DCu: goto L_089CE7DC;
    case 0x089CE7E0u: goto L_089CE7E0;
    case 0x089CE878u: goto L_089CE878;
    case 0x089CE894u: goto L_089CE894;
    case 0x089CEA88u: goto L_089CEA88;
    case 0x089CEA90u: goto L_089CEA90;
    case 0x089CEA9Cu: goto L_089CEA9C;
    case 0x089CEAA4u: goto L_089CEAA4;
    case 0x089CEAC0u: goto L_089CEAC0;
    case 0x089CEAC8u: goto L_089CEAC8;
    case 0x089CEAE0u: goto L_089CEAE0;
    case 0x089CEAECu: goto L_089CEAEC;
    case 0x089CEB58u: goto L_089CEB58;
    case 0x089CEB60u: goto L_089CEB60;
    case 0x089CEB64u: goto L_089CEB64;
    case 0x089CEB78u: goto L_089CEB78;
    case 0x089CEB80u: goto L_089CEB80;
    case 0x089CEB88u: goto L_089CEB88;
    case 0x089CEBE0u: goto L_089CEBE0;
    case 0x089CEBE8u: goto L_089CEBE8;
    case 0x089CEBF0u: goto L_089CEBF0;
    case 0x089CEBFCu: goto L_089CEBFC;
    case 0x089CEC00u: goto L_089CEC00;
    case 0x089CEC50u: goto L_089CEC50;
    case 0x089CEC58u: goto L_089CEC58;
    case 0x089CECA0u: goto L_089CECA0;
    case 0x089CECC8u: goto L_089CECC8;
    case 0x089CECE0u: goto L_089CECE0;
    case 0x089CECF8u: goto L_089CECF8;
    case 0x089CED1Cu: goto L_089CED1C;
    case 0x089CED38u: goto L_089CED38;
    case 0x089CED80u: goto L_089CED80;
    case 0x089CED98u: goto L_089CED98;
    case 0x089CEDA8u: goto L_089CEDA8;
    case 0x089CEDF0u: goto L_089CEDF0;
    case 0x089CEE20u: goto L_089CEE20;
    case 0x089CEE68u: goto L_089CEE68;
    case 0x089CEE88u: goto L_089CEE88;
    case 0x089CEE90u: goto L_089CEE90;
    case 0x089CEEE0u: goto L_089CEEE0;
    case 0x089CEF30u: goto L_089CEF30;
    case 0x089CEF48u: goto L_089CEF48;
    case 0x089CEF60u: goto L_089CEF60;
    case 0x089CEF68u: goto L_089CEF68;
    case 0x089CEFF0u: goto L_089CEFF0;
    case 0x089CF000u: goto L_089CF000;
    case 0x089CF010u: goto L_089CF010;
    case 0x089CF058u: goto L_089CF058;
    case 0x089CF080u: goto L_089CF080;
    case 0x089CF090u: goto L_089CF090;
    case 0x089CF0A0u: goto L_089CF0A0;
    case 0x089CF0D0u: goto L_089CF0D0;
    case 0x089CF0F0u: goto L_089CF0F0;
    case 0x089CF138u: goto L_089CF138;
    case 0x089CF148u: goto L_089CF148;
    case 0x089CF158u: goto L_089CF158;
    case 0x089CF1A0u: goto L_089CF1A0;
    case 0x089CF1B8u: goto L_089CF1B8;
    case 0x089CF1CCu: goto L_089CF1CC;
    case 0x089CF1DCu: goto L_089CF1DC;
    case 0x089CF200u: goto L_089CF200;
    case 0x089CF230u: goto L_089CF230;
    case 0x089CF260u: goto L_089CF260;
    case 0x089CF290u: goto L_089CF290;
    case 0x089CF2D8u: goto L_089CF2D8;
    case 0x089CF2E8u: goto L_089CF2E8;
    case 0x089CF308u: goto L_089CF308;
    case 0x089CF340u: goto L_089CF340;
    case 0x089CF350u: goto L_089CF350;
    case 0x089CF3DCu: goto L_089CF3DC;
    case 0x089CF3E8u: goto L_089CF3E8;
    case 0x089CF3F8u: goto L_089CF3F8;
    case 0x089CF400u: goto L_089CF400;
    case 0x089CF420u: goto L_089CF420;
    case 0x089CF434u: goto L_089CF434;
    case 0x089CF448u: goto L_089CF448;
    case 0x089CF470u: goto L_089CF470;
    case 0x089CF494u: goto L_089CF494;
    case 0x089CF49Cu: goto L_089CF49C;
    case 0x089CF4A0u: goto L_089CF4A0;
    case 0x089CF4B8u: goto L_089CF4B8;
    case 0x089CF4C0u: goto L_089CF4C0;
    case 0x089CF4D4u: goto L_089CF4D4;
    case 0x089CF4E8u: goto L_089CF4E8;
    case 0x089CF4FCu: goto L_089CF4FC;
    case 0x089CF508u: goto L_089CF508;
    case 0x089CF510u: goto L_089CF510;
    case 0x089CF518u: goto L_089CF518;
    case 0x089CF530u: goto L_089CF530;
    case 0x089CF55Cu: goto L_089CF55C;
    case 0x089CF580u: goto L_089CF580;
    case 0x089CF584u: goto L_089CF584;
    case 0x089CF590u: goto L_089CF590;
    case 0x089CF5B8u: goto L_089CF5B8;
    case 0x089CF5C0u: goto L_089CF5C0;
    case 0x089CF5D0u: goto L_089CF5D0;
    case 0x089CF5F4u: goto L_089CF5F4;
    case 0x089CF614u: goto L_089CF614;
    case 0x089CF6A0u: goto L_089CF6A0;
    case 0x089CF6B0u: goto L_089CF6B0;
    case 0x089CF6D8u: goto L_089CF6D8;
    case 0x089CF6E8u: goto L_089CF6E8;
    case 0x089CF6F8u: goto L_089CF6F8;
    case 0x089CF70Cu: goto L_089CF70C;
    case 0x089CF714u: goto L_089CF714;
    case 0x089CF728u: goto L_089CF728;
    case 0x089CF970u: goto L_089CF970;
    case 0x089CF980u: goto L_089CF980;
    case 0x089CF990u: goto L_089CF990;
    case 0x089CF9A4u: goto L_089CF9A4;
    case 0x089CF9ACu: goto L_089CF9AC;
    case 0x089CF9C0u: goto L_089CF9C0;
    case 0x089CFB70u: goto L_089CFB70;
    case 0x089CFB84u: goto L_089CFB84;
    case 0x089CFBC0u: goto L_089CFBC0;
    case 0x089CFBE0u: goto L_089CFBE0;
    case 0x089CFC00u: goto L_089CFC00;
    case 0x089CFC24u: goto L_089CFC24;
    case 0x089CFC34u: goto L_089CFC34;
    case 0x089CFC58u: goto L_089CFC58;
    case 0x089CFE90u: goto L_089CFE90;
    case 0x089CFEB0u: goto L_089CFEB0;
    case 0x089CFED0u: goto L_089CFED0;
    case 0x089CFEF4u: goto L_089CFEF4;
    case 0x089CFF04u: goto L_089CFF04;
    case 0x089CFF28u: goto L_089CFF28;
    case 0x089D0000u: goto L_089D0000;
    case 0x089D00D0u: goto L_089D00D0;
    case 0x089D0128u: goto L_089D0128;
    case 0x089D0158u: goto L_089D0158;
    case 0x089D0170u: goto L_089D0170;
    case 0x089D0198u: goto L_089D0198;
    case 0x089D01A0u: goto L_089D01A0;
    case 0x089D01A8u: goto L_089D01A8;
    case 0x089D01B8u: goto L_089D01B8;
    case 0x089D01C8u: goto L_089D01C8;
    case 0x089D01D4u: goto L_089D01D4;
    case 0x089D0200u: goto L_089D0200;
    case 0x089D0214u: goto L_089D0214;
    case 0x089D022Cu: goto L_089D022C;
    case 0x089D02C0u: goto L_089D02C0;
    case 0x089D04F0u: goto L_089D04F0;
    case 0x089D05DCu: goto L_089D05DC;
    case 0x089D0628u: goto L_089D0628;
    case 0x089D0648u: goto L_089D0648;
    case 0x089D0660u: goto L_089D0660;
    case 0x089D066Cu: goto L_089D066C;
    case 0x089D067Cu: goto L_089D067C;
    case 0x089D0908u: goto L_089D0908;
    case 0x089D091Cu: goto L_089D091C;
    case 0x089D0928u: goto L_089D0928;
    case 0x089D0988u: goto L_089D0988;
    case 0x089D0990u: goto L_089D0990;
    case 0x089D0998u: goto L_089D0998;
    case 0x089D09B4u: goto L_089D09B4;
    case 0x089D09BCu: goto L_089D09BC;
    case 0x089D09D0u: goto L_089D09D0;
    case 0x089D09D8u: goto L_089D09D8;
    case 0x089D09E0u: goto L_089D09E0;
    case 0x089D09E4u: goto L_089D09E4;
    case 0x089D0A04u: goto L_089D0A04;
    case 0x089D0A08u: goto L_089D0A08;
    case 0x089D0A18u: goto L_089D0A18;
    case 0x089D0A1Cu: goto L_089D0A1C;
    case 0x089D0A24u: goto L_089D0A24;
    case 0x089D0A2Cu: goto L_089D0A2C;
    case 0x089D0A34u: goto L_089D0A34;
    case 0x089D0A3Cu: goto L_089D0A3C;
    case 0x089D0A44u: goto L_089D0A44;
    case 0x089D0A54u: goto L_089D0A54;
    case 0x089D0A60u: goto L_089D0A60;
    case 0x089D0A6Cu: goto L_089D0A6C;
    case 0x089D0A78u: goto L_089D0A78;
    case 0x089D0A80u: goto L_089D0A80;
    case 0x089D0A84u: goto L_089D0A84;
    case 0x089D0A90u: goto L_089D0A90;
    case 0x089D0A98u: goto L_089D0A98;
    case 0x089D0AA0u: goto L_089D0AA0;
    case 0x089D0AA8u: goto L_089D0AA8;
    case 0x089D0AB4u: goto L_089D0AB4;
    case 0x089D0ABCu: goto L_089D0ABC;
    case 0x089D0AE8u: goto L_089D0AE8;
    case 0x089D0B0Cu: goto L_089D0B0C;
    case 0x089D0B1Cu: goto L_089D0B1C;
    case 0x089D0B20u: goto L_089D0B20;
    case 0x089D0B34u: goto L_089D0B34;
    case 0x089D0B6Cu: goto L_089D0B6C;
    case 0x089D0BA0u: goto L_089D0BA0;
    case 0x089D0BE4u: goto L_089D0BE4;
    case 0x089D0C04u: goto L_089D0C04;
    case 0x089D0C28u: goto L_089D0C28;
    case 0x089D0C40u: goto L_089D0C40;
    case 0x089D0C5Cu: goto L_089D0C5C;
    case 0x089D0C94u: goto L_089D0C94;
    case 0x089D0CF8u: goto L_089D0CF8;
    case 0x089D0D28u: goto L_089D0D28;
    case 0x089D0D38u: goto L_089D0D38;
    case 0x089D0D50u: goto L_089D0D50;
    case 0x089D0D60u: goto L_089D0D60;
    case 0x089D0D70u: goto L_089D0D70;
    case 0x089D0D80u: goto L_089D0D80;
    case 0x089D0DD8u: goto L_089D0DD8;
    case 0x089D0DF8u: goto L_089D0DF8;
    case 0x089D0E00u: goto L_089D0E00;
    case 0x089D0E30u: goto L_089D0E30;
    case 0x089D0E50u: goto L_089D0E50;
    case 0x089D0E80u: goto L_089D0E80;
    case 0x089D0E98u: goto L_089D0E98;
    case 0x089D0ED4u: goto L_089D0ED4;
    case 0x089D0F30u: goto L_089D0F30;
    case 0x089D0FA0u: goto L_089D0FA0;
    case 0x089D1044u: goto L_089D1044;
    case 0x089D1048u: goto L_089D1048;
    case 0x089D104Cu: goto L_089D104C;
    case 0x089D1050u: goto L_089D1050;
    case 0x089D1054u: goto L_089D1054;
    case 0x089D1058u: goto L_089D1058;
    case 0x089D107Cu: goto L_089D107C;
    case 0x089D1088u: goto L_089D1088;
    case 0x089D1098u: goto L_089D1098;
    case 0x089D1120u: goto L_089D1120;
    case 0x089D1128u: goto L_089D1128;
    case 0x089D1130u: goto L_089D1130;
    case 0x089D1138u: goto L_089D1138;
    case 0x089D1140u: goto L_089D1140;
    case 0x089D1170u: goto L_089D1170;
    case 0x089D11E0u: goto L_089D11E0;
    case 0x089D11F8u: goto L_089D11F8;
    case 0x089D131Cu: goto L_089D131C;
    case 0x089D13C0u: goto L_089D13C0;
    case 0x089D13D0u: goto L_089D13D0;
    case 0x089D13E0u: goto L_089D13E0;
    case 0x089D1454u: goto L_089D1454;
    case 0x089D14C8u: goto L_089D14C8;
    case 0x089D14E0u: goto L_089D14E0;
    case 0x089D14F8u: goto L_089D14F8;
    case 0x089D1508u: goto L_089D1508;
    case 0x089D1510u: goto L_089D1510;
    case 0x089D1520u: goto L_089D1520;
    case 0x089D1524u: goto L_089D1524;
    case 0x089D1528u: goto L_089D1528;
    case 0x089D152Cu: goto L_089D152C;
    case 0x089D1530u: goto L_089D1530;
    case 0x089D1534u: goto L_089D1534;
    case 0x089D1538u: goto L_089D1538;
    case 0x089D153Cu: goto L_089D153C;
    case 0x089D1540u: goto L_089D1540;
    case 0x089D1544u: goto L_089D1544;
    case 0x089D1548u: goto L_089D1548;
    case 0x089D154Cu: goto L_089D154C;
    case 0x089D1550u: goto L_089D1550;
    case 0x089D1554u: goto L_089D1554;
    case 0x089D1558u: goto L_089D1558;
    case 0x089D15DCu: goto L_089D15DC;
    case 0x089D15E0u: goto L_089D15E0;
    case 0x089D15ECu: goto L_089D15EC;
    case 0x089D15F0u: goto L_089D15F0;
    case 0x089D1600u: goto L_089D1600;
    case 0x089D1604u: goto L_089D1604;
    case 0x089D1608u: goto L_089D1608;
    case 0x089D160Cu: goto L_089D160C;
    case 0x089D1610u: goto L_089D1610;
    case 0x089D1614u: goto L_089D1614;
    case 0x089D1618u: goto L_089D1618;
    case 0x089D161Cu: goto L_089D161C;
    case 0x089D1620u: goto L_089D1620;
    case 0x089D1624u: goto L_089D1624;
    case 0x089D1628u: goto L_089D1628;
    case 0x089D162Cu: goto L_089D162C;
    case 0x089D1630u: goto L_089D1630;
    case 0x089D1634u: goto L_089D1634;
    case 0x089D1830u: goto L_089D1830;
    case 0x089D1860u: goto L_089D1860;
    case 0x089D18CCu: goto L_089D18CC;
    case 0x089D18E0u: goto L_089D18E0;
    case 0x089D18F4u: goto L_089D18F4;
    case 0x089D18F8u: goto L_089D18F8;
    case 0x089D18FCu: goto L_089D18FC;
    case 0x089D1900u: goto L_089D1900;
    case 0x089D1904u: goto L_089D1904;
    case 0x089D1908u: goto L_089D1908;
    case 0x089D190Cu: goto L_089D190C;
    case 0x089D1910u: goto L_089D1910;
    case 0x089D1914u: goto L_089D1914;
    case 0x089D1918u: goto L_089D1918;
    case 0x089D191Cu: goto L_089D191C;
    case 0x089D1920u: goto L_089D1920;
    case 0x089D1924u: goto L_089D1924;
    case 0x089D1928u: goto L_089D1928;
    case 0x089D192Cu: goto L_089D192C;
    case 0x089D1930u: goto L_089D1930;
    case 0x089D1934u: goto L_089D1934;
    case 0x089D1938u: goto L_089D1938;
    case 0x089D193Cu: goto L_089D193C;
    case 0x089D1940u: goto L_089D1940;
    case 0x089D1944u: goto L_089D1944;
    case 0x089D1948u: goto L_089D1948;
    case 0x089D194Cu: goto L_089D194C;
    case 0x089D19CCu: goto L_089D19CC;
    case 0x089D1C80u: goto L_089D1C80;
    case 0x089D1CA8u: goto L_089D1CA8;
    case 0x089D1CF0u: goto L_089D1CF0;
    case 0x089D1D00u: goto L_089D1D00;
    case 0x089D1D08u: goto L_089D1D08;
    case 0x089D1D10u: goto L_089D1D10;
    case 0x089D1D14u: goto L_089D1D14;
    case 0x089D1E00u: goto L_089D1E00;
    case 0x089D1E14u: goto L_089D1E14;
    case 0x089D1E1Cu: goto L_089D1E1C;
    case 0x089D1E24u: goto L_089D1E24;
    case 0x089D1E34u: goto L_089D1E34;
    case 0x089D1E3Cu: goto L_089D1E3C;
    case 0x089D1E54u: goto L_089D1E54;
    case 0x089D1EACu: goto L_089D1EAC;
    case 0x089D1EB4u: goto L_089D1EB4;
    case 0x089D1ECCu: goto L_089D1ECC;
    case 0x089D1ED4u: goto L_089D1ED4;
    case 0x089D1EDCu: goto L_089D1EDC;
    case 0x089D1EE4u: goto L_089D1EE4;
    case 0x089D1F00u: goto L_089D1F00;
    case 0x089D1F0Cu: goto L_089D1F0C;
    case 0x089D1F14u: goto L_089D1F14;
    case 0x089D1F74u: goto L_089D1F74;
    case 0x089D1F7Cu: goto L_089D1F7C;
    case 0x089D1F88u: goto L_089D1F88;
    case 0x089D1F94u: goto L_089D1F94;
    case 0x089D1FA0u: goto L_089D1FA0;
    case 0x089D1FB4u: goto L_089D1FB4;
    case 0x089D2084u: goto L_089D2084;
    case 0x089D2130u: goto L_089D2130;
    case 0x089D2144u: goto L_089D2144;
    case 0x089D216Cu: goto L_089D216C;
    case 0x089D21B8u: goto L_089D21B8;
    case 0x089D21BCu: goto L_089D21BC;
    case 0x089D21C0u: goto L_089D21C0;
    case 0x089D21E0u: goto L_089D21E0;
    case 0x089D21ECu: goto L_089D21EC;
    case 0x089D21F8u: goto L_089D21F8;
    case 0x089D2204u: goto L_089D2204;
    case 0x089D2210u: goto L_089D2210;
    case 0x089D221Cu: goto L_089D221C;
    case 0x089D2228u: goto L_089D2228;
    case 0x089D2250u: goto L_089D2250;
    case 0x089D2264u: goto L_089D2264;
    case 0x089D22E4u: goto L_089D22E4;
    case 0x089D22F4u: goto L_089D22F4;
    case 0x089D2330u: goto L_089D2330;
    case 0x089D2338u: goto L_089D2338;
    case 0x089D235Cu: goto L_089D235C;
    case 0x089D2640u: goto L_089D2640;
    case 0x089D2650u: goto L_089D2650;
    case 0x089D2660u: goto L_089D2660;
    case 0x089D2690u: goto L_089D2690;
    case 0x089D26A8u: goto L_089D26A8;
    case 0x089D26ECu: goto L_089D26EC;
    case 0x089D26F4u: goto L_089D26F4;
    case 0x089D2748u: goto L_089D2748;
    case 0x089D2770u: goto L_089D2770;
    case 0x089D2784u: goto L_089D2784;
    case 0x089D2794u: goto L_089D2794;
    case 0x089D27ACu: goto L_089D27AC;
    case 0x089D27C4u: goto L_089D27C4;
    case 0x089D27D4u: goto L_089D27D4;
    case 0x089D2800u: goto L_089D2800;
    case 0x089D2808u: goto L_089D2808;
    case 0x089D280Cu: goto L_089D280C;
    case 0x089D291Cu: goto L_089D291C;
    case 0x089D2A18u: goto L_089D2A18;
    case 0x089D35FCu: goto L_089D35FC;
    case 0x089D3630u: goto L_089D3630;
    case 0x089D3650u: goto L_089D3650;
    case 0x089D4320u: goto L_089D4320;
    case 0x089D4750u: goto L_089D4750;
    case 0x089D4754u: goto L_089D4754;
    case 0x089D4770u: goto L_089D4770;
    case 0x089D47B0u: goto L_089D47B0;
    case 0x089D48C0u: goto L_089D48C0;
    case 0x089D4900u: goto L_089D4900;
    case 0x089D4948u: goto L_089D4948;
    case 0x089D4978u: goto L_089D4978;
    case 0x089D4D84u: goto L_089D4D84;
    case 0x089D4DD0u: goto L_089D4DD0;
    case 0x089D4E38u: goto L_089D4E38;
    case 0x089D4E3Cu: goto L_089D4E3C;
    case 0x089D4E48u: goto L_089D4E48;
    case 0x089D4E80u: goto L_089D4E80;
    case 0x089D4E84u: goto L_089D4E84;
    case 0x089D530Cu: goto L_089D530C;
    case 0x089D5324u: goto L_089D5324;
    case 0x089D536Cu: goto L_089D536C;
    case 0x089D5384u: goto L_089D5384;
    case 0x089D53A0u: goto L_089D53A0;
    case 0x089D53B8u: goto L_089D53B8;
    case 0x089D53C0u: goto L_089D53C0;
    case 0x089D53F8u: goto L_089D53F8;
    case 0x089D5400u: goto L_089D5400;
    case 0x089D5404u: goto L_089D5404;
    case 0x089D540Cu: goto L_089D540C;
    case 0x089D5414u: goto L_089D5414;
    case 0x089D5424u: goto L_089D5424;
    case 0x089D5434u: goto L_089D5434;
    case 0x089D5444u: goto L_089D5444;
    case 0x089D545Cu: goto L_089D545C;
    case 0x089D5474u: goto L_089D5474;
    case 0x089D5480u: goto L_089D5480;
    case 0x089D5488u: goto L_089D5488;
    case 0x089D54C4u: goto L_089D54C4;
    case 0x089D54D8u: goto L_089D54D8;
    case 0x089D550Cu: goto L_089D550C;
    case 0x089D5540u: goto L_089D5540;
    case 0x089D5548u: goto L_089D5548;
    case 0x089D5558u: goto L_089D5558;
    case 0x089D5564u: goto L_089D5564;
    case 0x089D556Cu: goto L_089D556C;
    case 0x089D5578u: goto L_089D5578;
    case 0x089D5588u: goto L_089D5588;
    case 0x089D55CCu: goto L_089D55CC;
    case 0x089D55E4u: goto L_089D55E4;
    case 0x089D55F0u: goto L_089D55F0;
    case 0x089D55F8u: goto L_089D55F8;
    case 0x089D5600u: goto L_089D5600;
    case 0x089D562Cu: goto L_089D562C;
    case 0x089D5640u: goto L_089D5640;
    case 0x089D5654u: goto L_089D5654;
    case 0x089D565Cu: goto L_089D565C;
    case 0x089D5678u: goto L_089D5678;
    case 0x089D56B4u: goto L_089D56B4;
    case 0x089D56C0u: goto L_089D56C0;
    case 0x089D56ECu: goto L_089D56EC;
    case 0x089D56FCu: goto L_089D56FC;
    case 0x089D570Cu: goto L_089D570C;
    case 0x089D5748u: goto L_089D5748;
    case 0x089D5778u: goto L_089D5778;
    case 0x089D5788u: goto L_089D5788;
    case 0x089D57A0u: goto L_089D57A0;
    case 0x089D57D4u: goto L_089D57D4;
    case 0x089D57F4u: goto L_089D57F4;
    case 0x089D5838u: goto L_089D5838;
    case 0x089D5EA8u: goto L_089D5EA8;
    case 0x089D5ED0u: goto L_089D5ED0;
    case 0x089D5EF4u: goto L_089D5EF4;
    case 0x089D5F30u: goto L_089D5F30;
    case 0x089D5FF8u: goto L_089D5FF8;
    case 0x089D6018u: goto L_089D6018;
    case 0x089D6050u: goto L_089D6050;
    case 0x089D6090u: goto L_089D6090;
    case 0x089D60D0u: goto L_089D60D0;
    case 0x089D6110u: goto L_089D6110;
    case 0x089D6114u: goto L_089D6114;
    case 0x089D6118u: goto L_089D6118;
    case 0x089D618Cu: goto L_089D618C;
    case 0x089D6190u: goto L_089D6190;
    case 0x089D6264u: goto L_089D6264;
    case 0x089D6268u: goto L_089D6268;
    case 0x089D63A0u: goto L_089D63A0;
    case 0x089D63ACu: goto L_089D63AC;
    case 0x089D63B8u: goto L_089D63B8;
    case 0x089D63C4u: goto L_089D63C4;
    case 0x089D63D0u: goto L_089D63D0;
    case 0x089D63DCu: goto L_089D63DC;
    case 0x089D63E8u: goto L_089D63E8;
    case 0x089D63F4u: goto L_089D63F4;
    case 0x089D6400u: goto L_089D6400;
    case 0x089D640Cu: goto L_089D640C;
    case 0x089D6418u: goto L_089D6418;
    case 0x089D6424u: goto L_089D6424;
    case 0x089D6430u: goto L_089D6430;
    case 0x089D643Cu: goto L_089D643C;
    case 0x089D6448u: goto L_089D6448;
    case 0x089D6454u: goto L_089D6454;
    case 0x089D6460u: goto L_089D6460;
    case 0x089D646Cu: goto L_089D646C;
    case 0x089D6478u: goto L_089D6478;
    case 0x089D6484u: goto L_089D6484;
    case 0x089D6490u: goto L_089D6490;
    case 0x089D649Cu: goto L_089D649C;
    case 0x089D64A8u: goto L_089D64A8;
    case 0x089D64B4u: goto L_089D64B4;
    case 0x089D64C0u: goto L_089D64C0;
    case 0x089D64CCu: goto L_089D64CC;
    case 0x089D64D8u: goto L_089D64D8;
    case 0x089D64E4u: goto L_089D64E4;
    case 0x089D64F0u: goto L_089D64F0;
    case 0x089D64FCu: goto L_089D64FC;
    case 0x089D6508u: goto L_089D6508;
    case 0x089D6514u: goto L_089D6514;
    case 0x089D6520u: goto L_089D6520;
    case 0x089D652Cu: goto L_089D652C;
    case 0x089D6538u: goto L_089D6538;
    case 0x089D6544u: goto L_089D6544;
    case 0x089D6550u: goto L_089D6550;
    case 0x089D655Cu: goto L_089D655C;
    case 0x089D6568u: goto L_089D6568;
    case 0x089D6574u: goto L_089D6574;
    case 0x089D6580u: goto L_089D6580;
    case 0x089D658Cu: goto L_089D658C;
    case 0x089D6598u: goto L_089D6598;
    case 0x089D65A4u: goto L_089D65A4;
    case 0x089D65B0u: goto L_089D65B0;
    case 0x089D65BCu: goto L_089D65BC;
    case 0x089D65C8u: goto L_089D65C8;
    case 0x089D65D4u: goto L_089D65D4;
    case 0x089D65E0u: goto L_089D65E0;
    case 0x089D65ECu: goto L_089D65EC;
    case 0x089D65F8u: goto L_089D65F8;
    case 0x089D6604u: goto L_089D6604;
    case 0x089D6610u: goto L_089D6610;
    case 0x089D661Cu: goto L_089D661C;
    case 0x089D6628u: goto L_089D6628;
    case 0x089D6634u: goto L_089D6634;
    case 0x089D6640u: goto L_089D6640;
    case 0x089D664Cu: goto L_089D664C;
    case 0x089D6658u: goto L_089D6658;
    case 0x089D6664u: goto L_089D6664;
    case 0x089D6670u: goto L_089D6670;
    case 0x089D667Cu: goto L_089D667C;
    case 0x089D6688u: goto L_089D6688;
    case 0x089D6694u: goto L_089D6694;
    case 0x089D66A0u: goto L_089D66A0;
    case 0x089D66ACu: goto L_089D66AC;
    case 0x089D66B8u: goto L_089D66B8;
    case 0x089D66C4u: goto L_089D66C4;
    case 0x089D66D0u: goto L_089D66D0;
    case 0x089D66DCu: goto L_089D66DC;
    case 0x089D66E8u: goto L_089D66E8;
    case 0x089D66F4u: goto L_089D66F4;
    case 0x089D6700u: goto L_089D6700;
    case 0x089D670Cu: goto L_089D670C;
    case 0x089D6718u: goto L_089D6718;
    case 0x089D6724u: goto L_089D6724;
    case 0x089D6730u: goto L_089D6730;
    case 0x089D673Cu: goto L_089D673C;
    case 0x089D6748u: goto L_089D6748;
    case 0x089D6754u: goto L_089D6754;
    case 0x089D6760u: goto L_089D6760;
    case 0x089D676Cu: goto L_089D676C;
    case 0x089D6778u: goto L_089D6778;
    case 0x089D6784u: goto L_089D6784;
    case 0x089D6790u: goto L_089D6790;
    case 0x089D679Cu: goto L_089D679C;
    case 0x089D67A8u: goto L_089D67A8;
    case 0x089D67B4u: goto L_089D67B4;
    case 0x089D67C0u: goto L_089D67C0;
    case 0x089D67CCu: goto L_089D67CC;
    case 0x089D67D8u: goto L_089D67D8;
    case 0x089D67E4u: goto L_089D67E4;
    case 0x089D67F0u: goto L_089D67F0;
    case 0x089D67FCu: goto L_089D67FC;
    case 0x089D6808u: goto L_089D6808;
    case 0x089D6814u: goto L_089D6814;
    case 0x089D6820u: goto L_089D6820;
    case 0x089D682Cu: goto L_089D682C;
    case 0x089D6838u: goto L_089D6838;
    case 0x089D6844u: goto L_089D6844;
    case 0x089D6850u: goto L_089D6850;
    case 0x089D685Cu: goto L_089D685C;
    case 0x089D6868u: goto L_089D6868;
    case 0x089D6874u: goto L_089D6874;
    case 0x089D6880u: goto L_089D6880;
    case 0x089D688Cu: goto L_089D688C;
    case 0x089D6898u: goto L_089D6898;
    case 0x089D68D0u: goto L_089D68D0;
    case 0x089D68D8u: goto L_089D68D8;
    case 0x089D68E0u: goto L_089D68E0;
    case 0x089D68F0u: goto L_089D68F0;
    case 0x089D6904u: goto L_089D6904;
    case 0x089D6914u: goto L_089D6914;
    case 0x089D6924u: goto L_089D6924;
    case 0x089D6960u: goto L_089D6960;
    case 0x089D6964u: goto L_089D6964;
    case 0x089D6970u: goto L_089D6970;
    case 0x089D6988u: goto L_089D6988;
    case 0x089D6A18u: goto L_089D6A18;
    case 0x089D6A48u: goto L_089D6A48;
    case 0x089D6A98u: goto L_089D6A98;
    case 0x089D6AB0u: goto L_089D6AB0;
    case 0x089D6AF8u: goto L_089D6AF8;
    case 0x089D6BF8u: goto L_089D6BF8;
    case 0x089D6BFCu: goto L_089D6BFC;
    case 0x089D6C18u: goto L_089D6C18;
    case 0x089D6C20u: goto L_089D6C20;
    case 0x089D6CA8u: goto L_089D6CA8;
    case 0x089D6D3Cu: goto L_089D6D3C;
    case 0x089D6D98u: goto L_089D6D98;
    case 0x089D6DB8u: goto L_089D6DB8;
    case 0x089D6DDCu: goto L_089D6DDC;
    case 0x089D6DE8u: goto L_089D6DE8;
    case 0x089D6F58u: goto L_089D6F58;
    case 0x089D70FCu: goto L_089D70FC;
    case 0x089D7130u: goto L_089D7130;
    case 0x089D7140u: goto L_089D7140;
    case 0x089D7270u: goto L_089D7270;
    case 0x089D7298u: goto L_089D7298;
    case 0x089D72C4u: goto L_089D72C4;
    case 0x089D72D0u: goto L_089D72D0;
    case 0x089D7390u: goto L_089D7390;
    case 0x089D739Cu: goto L_089D739C;
    case 0x089D73C0u: goto L_089D73C0;
    case 0x089D7418u: goto L_089D7418;
    case 0x089D7424u: goto L_089D7424;
    case 0x089D7440u: goto L_089D7440;
    case 0x089D7490u: goto L_089D7490;
    case 0x089D74E0u: goto L_089D74E0;
    case 0x089D7758u: goto L_089D7758;
    case 0x089D7820u: goto L_089D7820;
    case 0x089D7838u: goto L_089D7838;
    case 0x089D79E8u: goto L_089D79E8;
    case 0x089D7A10u: goto L_089D7A10;
    case 0x089D7A30u: goto L_089D7A30;
    case 0x089D7BE0u: goto L_089D7BE0;
    case 0x089D7CD4u: goto L_089D7CD4;
    case 0x089D7DFCu: goto L_089D7DFC;
    case 0x089D7E8Cu: goto L_089D7E8C;
    case 0x089D7ED8u: goto L_089D7ED8;
    case 0x089D7F00u: goto L_089D7F00;
    case 0x089D7F48u: goto L_089D7F48;
    case 0x089D7F58u: goto L_089D7F58;
    case 0x089D7F6Cu: goto L_089D7F6C;
    case 0x089D7FA0u: goto L_089D7FA0;
    case 0x089D7FC8u: goto L_089D7FC8;
    case 0x089D8018u: goto L_089D8018;
    case 0x089D8088u: goto L_089D8088;
    case 0x089D80B8u: goto L_089D80B8;
    case 0x089D80D0u: goto L_089D80D0;
    case 0x089D8150u: goto L_089D8150;
    case 0x089D81B8u: goto L_089D81B8;
    case 0x089D8220u: goto L_089D8220;
    case 0x089D8250u: goto L_089D8250;
    case 0x089D8280u: goto L_089D8280;
    case 0x089D82B0u: goto L_089D82B0;
    case 0x089D82E0u: goto L_089D82E0;
    case 0x089D8320u: goto L_089D8320;
    case 0x089D83E0u: goto L_089D83E0;
    case 0x089D8408u: goto L_089D8408;
    case 0x089D84B8u: goto L_089D84B8;
    case 0x089D84D8u: goto L_089D84D8;
    case 0x089D84ECu: goto L_089D84EC;
    case 0x089D8540u: goto L_089D8540;
    case 0x089D8568u: goto L_089D8568;
    case 0x089D8598u: goto L_089D8598;
    case 0x089D85A4u: goto L_089D85A4;
    case 0x089D85A8u: goto L_089D85A8;
    case 0x089D85C4u: goto L_089D85C4;
    case 0x089D85D0u: goto L_089D85D0;
    case 0x089D85DCu: goto L_089D85DC;
    case 0x089D886Cu: goto L_089D886C;
    case 0x089D88E8u: goto L_089D88E8;
    case 0x089D8920u: goto L_089D8920;
    case 0x089D8978u: goto L_089D8978;
    case 0x089D8A88u: goto L_089D8A88;
    case 0x089D8A98u: goto L_089D8A98;
    case 0x089D8D74u: goto L_089D8D74;
    case 0x089D8DA8u: goto L_089D8DA8;
    case 0x089D8DC8u: goto L_089D8DC8;
    case 0x089D8DF4u: goto L_089D8DF4;
    case 0x089D8F78u: goto L_089D8F78;
    case 0x089D8FE8u: goto L_089D8FE8;
    case 0x089D9000u: goto L_089D9000;
    case 0x089D900Cu: goto L_089D900C;
    case 0x089D901Cu: goto L_089D901C;
    case 0x089D9038u: goto L_089D9038;
    case 0x089D9040u: goto L_089D9040;
    case 0x089D9050u: goto L_089D9050;
    case 0x089D906Cu: goto L_089D906C;
    case 0x089D9090u: goto L_089D9090;
    case 0x089D90ACu: goto L_089D90AC;
    case 0x089D90C8u: goto L_089D90C8;
    case 0x089D90F0u: goto L_089D90F0;
    case 0x089D9108u: goto L_089D9108;
    case 0x089D9120u: goto L_089D9120;
    case 0x089D9140u: goto L_089D9140;
    case 0x089D914Cu: goto L_089D914C;
    case 0x089D9180u: goto L_089D9180;
    case 0x089D9190u: goto L_089D9190;
    case 0x089D91D0u: goto L_089D91D0;
    case 0x089D91E0u: goto L_089D91E0;
    case 0x089D91F0u: goto L_089D91F0;
    case 0x089D9204u: goto L_089D9204;
    case 0x089D9218u: goto L_089D9218;
    case 0x089D9278u: goto L_089D9278;
    case 0x089D9290u: goto L_089D9290;
    case 0x089D92BCu: goto L_089D92BC;
    case 0x089D92F0u: goto L_089D92F0;
    case 0x089D9300u: goto L_089D9300;
    case 0x089D9310u: goto L_089D9310;
    case 0x089D9324u: goto L_089D9324;
    case 0x089D9340u: goto L_089D9340;
    case 0x089D93F8u: goto L_089D93F8;
    case 0x089D945Cu: goto L_089D945C;
    case 0x089D94E8u: goto L_089D94E8;
    case 0x089D9544u: goto L_089D9544;
    case 0x089D95D0u: goto L_089D95D0;
    case 0x089D99E0u: goto L_089D99E0;
    case 0x089D9A88u: goto L_089D9A88;
    case 0x089D9A98u: goto L_089D9A98;
    case 0x089D9AF8u: goto L_089D9AF8;
    case 0x089D9B30u: goto L_089D9B30;
    case 0x089D9B50u: goto L_089D9B50;
    case 0x089D9B58u: goto L_089D9B58;
    case 0x089D9B68u: goto L_089D9B68;
    case 0x089D9B70u: goto L_089D9B70;
    case 0x089D9BB8u: goto L_089D9BB8;
    case 0x089D9FB0u: goto L_089D9FB0;
    case 0x089D9FC0u: goto L_089D9FC0;
    case 0x089D9FD0u: goto L_089D9FD0;
    case 0x089D9FE0u: goto L_089D9FE0;
    case 0x089D9FF0u: goto L_089D9FF0;
    case 0x089DA000u: goto L_089DA000;
    case 0x089DA00Cu: goto L_089DA00C;
    case 0x089DA010u: goto L_089DA010;
    case 0x089DA020u: goto L_089DA020;
    case 0x089DA060u: goto L_089DA060;
    case 0x089DA070u: goto L_089DA070;
    case 0x089DA080u: goto L_089DA080;
    case 0x089DA090u: goto L_089DA090;
    case 0x089DA0A0u: goto L_089DA0A0;
    case 0x089DA0B0u: goto L_089DA0B0;
    case 0x089DA0C0u: goto L_089DA0C0;
    case 0x089DA0C8u: goto L_089DA0C8;
    case 0x089DA0D4u: goto L_089DA0D4;
    case 0x089DA0D8u: goto L_089DA0D8;
    case 0x089DA0E0u: goto L_089DA0E0;
    case 0x089DA0E8u: goto L_089DA0E8;
    case 0x089DA0F0u: goto L_089DA0F0;
    case 0x089DA0F8u: goto L_089DA0F8;
    case 0x089DA100u: goto L_089DA100;
    case 0x089DA108u: goto L_089DA108;
    case 0x089DA110u: goto L_089DA110;
    case 0x089DA118u: goto L_089DA118;
    case 0x089DA130u: goto L_089DA130;
    case 0x089DA170u: goto L_089DA170;
    case 0x089DA1F0u: goto L_089DA1F0;
    case 0x089DA28Cu: goto L_089DA28C;
    case 0x089DA298u: goto L_089DA298;
    case 0x089DA2C0u: goto L_089DA2C0;
    case 0x089DA2E4u: goto L_089DA2E4;
    case 0x089DA2F0u: goto L_089DA2F0;
    case 0x089DA2FCu: goto L_089DA2FC;
    case 0x089DA308u: goto L_089DA308;
    case 0x089DA340u: goto L_089DA340;
    case 0x089DA350u: goto L_089DA350;
    case 0x089DA360u: goto L_089DA360;
    case 0x089DA370u: goto L_089DA370;
    case 0x089DA3B0u: goto L_089DA3B0;
    case 0x089DA3C0u: goto L_089DA3C0;
    case 0x089DA400u: goto L_089DA400;
    case 0x089DA410u: goto L_089DA410;
    case 0x089DA4C0u: goto L_089DA4C0;
    case 0x089DA4CCu: goto L_089DA4CC;
    case 0x089DA4D8u: goto L_089DA4D8;
    case 0x089DA69Cu: goto L_089DA69C;
    case 0x089DA6CCu: goto L_089DA6CC;
    case 0x089DA6E8u: goto L_089DA6E8;
    case 0x089DA708u: goto L_089DA708;
    case 0x089DA728u: goto L_089DA728;
    case 0x089DA74Cu: goto L_089DA74C;
    case 0x089DA774u: goto L_089DA774;
    case 0x089DA8D0u: goto L_089DA8D0;
    case 0x089DA8D8u: goto L_089DA8D8;
    case 0x089DA8E8u: goto L_089DA8E8;
    case 0x089DA900u: goto L_089DA900;
    case 0x089DA930u: goto L_089DA930;
    case 0x089DAA38u: goto L_089DAA38;
    case 0x089DAA58u: goto L_089DAA58;
    case 0x089DAA68u: goto L_089DAA68;
    case 0x089DAAC4u: goto L_089DAAC4;
    case 0x089DAE00u: goto L_089DAE00;
    case 0x089DAE08u: goto L_089DAE08;
    case 0x089DAE28u: goto L_089DAE28;
    case 0x089DAE48u: goto L_089DAE48;
    case 0x089DAE58u: goto L_089DAE58;
    case 0x089DAE68u: goto L_089DAE68;
    case 0x089DAE7Cu: goto L_089DAE7C;
    case 0x089DAEE8u: goto L_089DAEE8;
    case 0x089DAF30u: goto L_089DAF30;
    case 0x089DAF84u: goto L_089DAF84;
    case 0x089DAFC0u: goto L_089DAFC0;
    case 0x089DB014u: goto L_089DB014;
    case 0x089DB028u: goto L_089DB028;
    case 0x089DB030u: goto L_089DB030;
    case 0x089DB090u: goto L_089DB090;
    case 0x089DB0D0u: goto L_089DB0D0;
    case 0x089DB0E0u: goto L_089DB0E0;
    case 0x089DB130u: goto L_089DB130;
    case 0x089DB180u: goto L_089DB180;
    case 0x089DB1B8u: goto L_089DB1B8;
    case 0x089DB1D0u: goto L_089DB1D0;
    case 0x089DB220u: goto L_089DB220;
    case 0x089DB270u: goto L_089DB270;
    case 0x089DB2C0u: goto L_089DB2C0;
    case 0x089DB310u: goto L_089DB310;
    case 0x089DB314u: goto L_089DB314;
    case 0x089DB360u: goto L_089DB360;
    case 0x089DB3B0u: goto L_089DB3B0;
    case 0x089DB400u: goto L_089DB400;
    case 0x089DB450u: goto L_089DB450;
    case 0x089DB4A0u: goto L_089DB4A0;
    case 0x089DB4F0u: goto L_089DB4F0;
    case 0x089DB540u: goto L_089DB540;
    case 0x089DB590u: goto L_089DB590;
    case 0x089DB5E0u: goto L_089DB5E0;
    case 0x089DB618u: goto L_089DB618;
    case 0x089DB630u: goto L_089DB630;
    case 0x089DB680u: goto L_089DB680;
    case 0x089DB6D0u: goto L_089DB6D0;
    case 0x089DB720u: goto L_089DB720;
    case 0x089DB770u: goto L_089DB770;
    case 0x089DB7C0u: goto L_089DB7C0;
    case 0x089DB810u: goto L_089DB810;
    case 0x089DB860u: goto L_089DB860;
    case 0x089DB8B0u: goto L_089DB8B0;
    case 0x089DB900u: goto L_089DB900;
    case 0x089DB950u: goto L_089DB950;
    case 0x089DB9A0u: goto L_089DB9A0;
    case 0x089DB9F0u: goto L_089DB9F0;
    case 0x089DBA40u: goto L_089DBA40;
    case 0x089DBA7Cu: goto L_089DBA7C;
    case 0x089DBA90u: goto L_089DBA90;
    case 0x089DBAD4u: goto L_089DBAD4;
    case 0x089DBAE0u: goto L_089DBAE0;
    case 0x089DBAECu: goto L_089DBAEC;
    case 0x089DBB30u: goto L_089DBB30;
    case 0x089DBB80u: goto L_089DBB80;
    case 0x089DBBD0u: goto L_089DBBD0;
    case 0x089DBC20u: goto L_089DBC20;
    case 0x089DBC70u: goto L_089DBC70;
    case 0x089DBCA4u: goto L_089DBCA4;
    case 0x089DBCC0u: goto L_089DBCC0;
    case 0x089DBD10u: goto L_089DBD10;
    case 0x089DBD60u: goto L_089DBD60;
    case 0x089DBDB0u: goto L_089DBDB0;
    case 0x089DBE00u: goto L_089DBE00;
    case 0x089DBE50u: goto L_089DBE50;
    case 0x089DBE70u: goto L_089DBE70;
    case 0x089DBEA0u: goto L_089DBEA0;
    case 0x089DBEF0u: goto L_089DBEF0;
    case 0x089DBF40u: goto L_089DBF40;
    case 0x089DBF48u: goto L_089DBF48;
    case 0x089DBF50u: goto L_089DBF50;
    case 0x089DBF60u: goto L_089DBF60;
    case 0x089DBF70u: goto L_089DBF70;
    case 0x089DBF90u: goto L_089DBF90;
    case 0x089DBFC0u: goto L_089DBFC0;
    case 0x089DBFD8u: goto L_089DBFD8;
    case 0x089DC008u: goto L_089DC008;
    case 0x089DC020u: goto L_089DC020;
    case 0x089DC050u: goto L_089DC050;
    case 0x089DC068u: goto L_089DC068;
    case 0x089DC0B8u: goto L_089DC0B8;
    case 0x089DC0F4u: goto L_089DC0F4;
    case 0x089DC108u: goto L_089DC108;
    case 0x089DC158u: goto L_089DC158;
    case 0x089DC1A8u: goto L_089DC1A8;
    case 0x089DC1E8u: goto L_089DC1E8;
    case 0x089DC1F8u: goto L_089DC1F8;
    case 0x089DC238u: goto L_089DC238;
    case 0x089DC248u: goto L_089DC248;
    case 0x089DC28Cu: goto L_089DC28C;
    case 0x089DC298u: goto L_089DC298;
    case 0x089DC2E8u: goto L_089DC2E8;
    case 0x089DC338u: goto L_089DC338;
    case 0x089DC388u: goto L_089DC388;
    case 0x089DC3D8u: goto L_089DC3D8;
    case 0x089DC428u: goto L_089DC428;
    case 0x089DC478u: goto L_089DC478;
    case 0x089DC4C8u: goto L_089DC4C8;
    case 0x089DC4E8u: goto L_089DC4E8;
    case 0x089DC508u: goto L_089DC508;
    case 0x089DC528u: goto L_089DC528;
    case 0x089DC548u: goto L_089DC548;
    case 0x089DC568u: goto L_089DC568;
    case 0x089DC57Cu: goto L_089DC57C;
    case 0x089DC5B8u: goto L_089DC5B8;
    case 0x089DC608u: goto L_089DC608;
    case 0x089DC658u: goto L_089DC658;
    case 0x089DC6A8u: goto L_089DC6A8;
    case 0x089DC6F8u: goto L_089DC6F8;
    case 0x089DC748u: goto L_089DC748;
    case 0x089DC798u: goto L_089DC798;
    case 0x089DC7CCu: goto L_089DC7CC;
    case 0x089DC7E4u: goto L_089DC7E4;
    case 0x089DC7E8u: goto L_089DC7E8;
    case 0x089DC7FCu: goto L_089DC7FC;
    case 0x089DC814u: goto L_089DC814;
    case 0x089DC82Cu: goto L_089DC82C;
    case 0x089DC838u: goto L_089DC838;
    case 0x089DC888u: goto L_089DC888;
    case 0x089DC8D8u: goto L_089DC8D8;
    case 0x089DC928u: goto L_089DC928;
    case 0x089DC960u: goto L_089DC960;
    case 0x089DC9C8u: goto L_089DC9C8;
    case 0x089DCA30u: goto L_089DCA30;
    case 0x089DCA98u: goto L_089DCA98;
    case 0x089DCAE8u: goto L_089DCAE8;
    case 0x089DCB38u: goto L_089DCB38;
    case 0x089DCB88u: goto L_089DCB88;
    case 0x089DCBD8u: goto L_089DCBD8;
    case 0x089DCC28u: goto L_089DCC28;
    case 0x089DCC78u: goto L_089DCC78;
    case 0x089DCCC8u: goto L_089DCCC8;
    case 0x089DCD0Cu: goto L_089DCD0C;
    case 0x089DCD18u: goto L_089DCD18;
    case 0x089DCD68u: goto L_089DCD68;
    case 0x089DCDB4u: goto L_089DCDB4;
    case 0x089DCDB8u: goto L_089DCDB8;
    case 0x089DCDDCu: goto L_089DCDDC;
    case 0x089DCE08u: goto L_089DCE08;
    case 0x089DCE34u: goto L_089DCE34;
    case 0x089DCE58u: goto L_089DCE58;
    case 0x089DCEA8u: goto L_089DCEA8;
    case 0x089DCEF8u: goto L_089DCEF8;
    case 0x089DCF48u: goto L_089DCF48;
    case 0x089DCF98u: goto L_089DCF98;
    case 0x089DCFE8u: goto L_089DCFE8;
    case 0x089DD038u: goto L_089DD038;
    case 0x089DD088u: goto L_089DD088;
    case 0x089DD0D8u: goto L_089DD0D8;
    case 0x089DD0F0u: goto L_089DD0F0;
    case 0x089DD108u: goto L_089DD108;
    case 0x089DD120u: goto L_089DD120;
    case 0x089DD170u: goto L_089DD170;
    case 0x089DD1C0u: goto L_089DD1C0;
    case 0x089DD210u: goto L_089DD210;
    case 0x089DD230u: goto L_089DD230;
    case 0x089DD250u: goto L_089DD250;
    case 0x089DD270u: goto L_089DD270;
    case 0x089DD2A8u: goto L_089DD2A8;
    case 0x089DD2C8u: goto L_089DD2C8;
    case 0x089DD2E8u: goto L_089DD2E8;
    case 0x089DD308u: goto L_089DD308;
    case 0x089DD30Cu: goto L_089DD30C;
    case 0x089DD31Cu: goto L_089DD31C;
    case 0x089DD320u: goto L_089DD320;
    case 0x089DD338u: goto L_089DD338;
    case 0x089DD34Cu: goto L_089DD34C;
    case 0x089DD370u: goto L_089DD370;
    case 0x089DD378u: goto L_089DD378;
    case 0x089DD380u: goto L_089DD380;
    case 0x089DD38Cu: goto L_089DD38C;
    default:
        ctx.pc = local_pc;
        return;
    }
L_089C4044:
    ctx.gpr[22] = (ctx.gpr[29] + static_cast<std::uint32_t>(16));
    ctx.gpr[19] = (0u | 0u);
    ctx.gpr[20] = (0u | 0u);
    goto L_089C4050;
L_089C4050:
    ctx.gpr[4] = (aot_mem.aot_load32(ctx.gpr[16] + static_cast<std::uint32_t>(88)));
    ctx.gpr[5] = (aot_mem.aot_load32(ctx.gpr[17] + static_cast<std::uint32_t>(164)));
    ctx.gpr[4] = (ctx.gpr[4] + ctx.gpr[19]);
    ctx.gpr[5] = (aot_mem.aot_load32(ctx.gpr[5] + static_cast<std::uint32_t>(0)));
    ctx.gpr[4] = (aot_mem.aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(0)));
    ctx.gpr[4] = (ctx.gpr[4] << 2u);
    ctx.gpr[4] = (ctx.gpr[5] + ctx.gpr[4]);
    ctx.gpr[4] = (aot_mem.aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(0)));
    ctx.gpr[6] = (aot_mem.aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(0)));
    ctx.gpr[7] = (aot_mem.aot_load32(ctx.gpr[16] + static_cast<std::uint32_t>(80)));
    ctx.gpr[5] = (ctx.gpr[6] + static_cast<std::uint32_t>(24));
    ctx.gpr[5] = (aot_mem.aot_load32(ctx.gpr[5] + static_cast<std::uint32_t>(0)));
    ctx.gpr[8] = (ctx.gpr[6] + ctx.gpr[5]);
    { const bool branch_taken = ctx.gpr[8] != 0u;
    ctx.gpr[7] = (ctx.gpr[7] + ctx.gpr[20]);
      if (branch_taken) {
          goto L_089C4094;
      }
      goto L_089C408C;
    }
L_089C408C:
    { const bool branch_taken = 0u == 0u;
    ctx.gpr[5] = (0u | 0u);
      if (branch_taken) {
          goto L_089C409C;
      }
      goto L_089C4094;
    }
L_089C4094:
    ctx.gpr[5] = (ctx.gpr[6] + ctx.gpr[5]);
    ctx.gpr[5] = (ctx.gpr[5] + static_cast<std::uint32_t>(16));
    goto L_089C409C;
L_089C409C:
    aot_mem.aot_store32(ctx.gpr[7] + static_cast<std::uint32_t>(12), ctx.gpr[5]);
    ctx.gpr[5] = (aot_mem.aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(0)));
    ctx.gpr[6] = (aot_mem.aot_load32(ctx.gpr[16] + static_cast<std::uint32_t>(80)));
    ctx.gpr[7] = (ctx.gpr[5] + static_cast<std::uint32_t>(24));
    ctx.gpr[7] = (aot_mem.aot_load32(ctx.gpr[7] + static_cast<std::uint32_t>(0)));
    ctx.gpr[6] = (ctx.gpr[6] + ctx.gpr[20]);
    ctx.gpr[5] = (ctx.gpr[5] + ctx.gpr[7]);
    ctx.gpr[5] = (aot_mem.aot_load32(ctx.gpr[5] + static_cast<std::uint32_t>(0)));
    aot_mem.aot_store32(ctx.gpr[6] + static_cast<std::uint32_t>(0), ctx.gpr[5]);
    ctx.gpr[5] = (aot_mem.aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(0)));
    ctx.gpr[6] = (aot_mem.aot_load32(ctx.gpr[16] + static_cast<std::uint32_t>(80)));
    ctx.gpr[7] = (ctx.gpr[5] + static_cast<std::uint32_t>(24));
    ctx.gpr[7] = (aot_mem.aot_load32(ctx.gpr[7] + static_cast<std::uint32_t>(0)));
    ctx.gpr[6] = (ctx.gpr[6] + ctx.gpr[20]);
    ctx.gpr[5] = (ctx.gpr[5] + ctx.gpr[7]);
    ctx.gpr[5] = (aot_mem.aot_load32(ctx.gpr[5] + static_cast<std::uint32_t>(4)));
    aot_mem.aot_store32(ctx.gpr[6] + static_cast<std::uint32_t>(4), ctx.gpr[5]);
    ctx.gpr[4] = (aot_mem.aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(0)));
    ctx.gpr[7] = (aot_mem.aot_load32(ctx.gpr[16] + static_cast<std::uint32_t>(80)));
    ctx.gpr[5] = (ctx.gpr[4] + static_cast<std::uint32_t>(24));
    ctx.gpr[5] = (aot_mem.aot_load32(ctx.gpr[5] + static_cast<std::uint32_t>(0)));
    ctx.gpr[6] = (ctx.gpr[4] + ctx.gpr[5]);
    { const bool branch_taken = ctx.gpr[6] != 0u;
    ctx.gpr[7] = (ctx.gpr[7] + ctx.gpr[20]);
      if (branch_taken) {
          goto L_089C4104;
      }
      goto L_089C40FC;
    }
L_089C40FC:
    { const bool branch_taken = 0u == 0u;
    ctx.gpr[4] = (0u | 0u);
      if (branch_taken) {
          goto L_089C410C;
      }
      goto L_089C4104;
    }
L_089C4104:
    ctx.gpr[4] = (ctx.gpr[4] + ctx.gpr[5]);
    ctx.gpr[4] = (ctx.gpr[4] + static_cast<std::uint32_t>(16));
    goto L_089C410C;
L_089C410C:
    if (ctx.gpr[4] != 0u) {
    ctx.gpr[4] = (aot_mem.aot_load32(ctx.gpr[6] + static_cast<std::uint32_t>(4)));
        goto L_089C411C;
    }
    goto L_089C4114;
L_089C4114:
    { const bool branch_taken = 0u == 0u;
    ctx.gpr[6] = (0u | 0u);
      if (branch_taken) {
          goto L_089C4130;
      }
      goto L_089C411C;
    }
L_089C411C:
    { const bool branch_taken = ctx.gpr[4] != 0u;
    ctx.gpr[6] = (aot_mem.aot_load32(ctx.gpr[6] + static_cast<std::uint32_t>(0)));
      if (branch_taken) {
          goto L_089C412C;
      }
      goto L_089C4124;
    }
L_089C4124:
    { const bool branch_taken = 0u == 0u;
    ctx.gpr[6] = (ctx.gpr[6] << 2u);
      if (branch_taken) {
          goto L_089C4130;
      }
      goto L_089C412C;
    }
L_089C412C:
    ctx.gpr[6] = (ctx.gpr[6] + ctx.gpr[6]);
    goto L_089C4130;
L_089C4130:
    aot_mem.aot_store32(ctx.gpr[7] + static_cast<std::uint32_t>(8), ctx.gpr[6]);
    ctx.gpr[7] = (aot_mem.aot_load32(ctx.gpr[16] + static_cast<std::uint32_t>(80)));
    ctx.gpr[7] = (ctx.gpr[7] + ctx.gpr[20]);
    ctx.gpr[4] = (aot_mem.aot_load32(ctx.gpr[7] + static_cast<std::uint32_t>(12)));
    { const bool branch_taken = ctx.gpr[4] == 0u;
    // nop
      if (branch_taken) {
          goto L_089C4248;
      }
      goto L_089C4148;
    }
L_089C4148:
    ctx.gpr[5] = (aot_mem.aot_load32(ctx.gpr[7] + static_cast<std::uint32_t>(4)));
    ctx.gpr[4] = (aot_mem.aot_load32(ctx.gpr[17] + static_cast<std::uint32_t>(24)));
    { const bool branch_taken = ctx.gpr[5] != 0u;
    ctx.gpr[7] = (aot_mem.aot_load32(ctx.gpr[7] + static_cast<std::uint32_t>(8)));
      if (branch_taken) {
          goto L_089C41C4;
      }
      goto L_089C4158;
    }
L_089C4158:
    ctx.gpr[5] = (ctx.gpr[7] | 0u);
    ctx.gpr[6] = (ctx.gpr[21] | 0u);
    ctx.gpr[31] = (0x089C4168u);
    ctx.gpr[7] = (0u | 1u);
    if (rt.invoke_chained_direct<&recomp_unit_0011_entry, 11u, 923u, 0x08971134u>(ctx, &aot_mem) && ctx.pc == 0x089C4168u) goto L_089C4168;
    return;
L_089C4168:
    ctx.gpr[4] = (ctx.gpr[2] | 0u);
    if (ctx.gpr[4] == 0u) {
    ctx.gpr[5] = (aot_mem.aot_load32(ctx.gpr[16] + static_cast<std::uint32_t>(92)));
        goto L_089C419C;
    }
    goto L_089C4174;
L_089C4174:
    ctx.gpr[5] = (aot_mem.aot_load32(ctx.gpr[17] + static_cast<std::uint32_t>(136)));
    ctx.gpr[5] = (aot_mem.aot_load32(ctx.gpr[5] + static_cast<std::uint32_t>(456)));
    ctx.gpr[5] = (aot_mem.aot_load16(ctx.gpr[5] + static_cast<std::uint32_t>(24)));
    ctx.gpr[6] = (aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(12)));
    ctx.gpr[5] = (ctx.gpr[5] << 2u);
    ctx.gpr[5] = (ctx.gpr[17] + ctx.gpr[5]);
    ctx.gpr[7] = (aot_mem.aot_load32(ctx.gpr[5] + static_cast<std::uint32_t>(180)));
    ctx.gpr[6] = (ctx.gpr[7] + ctx.gpr[6]);
    aot_mem.aot_store32(ctx.gpr[5] + static_cast<std::uint32_t>(180), ctx.gpr[6]);
    ctx.gpr[5] = (aot_mem.aot_load32(ctx.gpr[16] + static_cast<std::uint32_t>(92)));
    goto L_089C419C;
L_089C419C:
    ctx.gpr[5] = (ctx.gpr[5] + ctx.gpr[19]);
    aot_mem.aot_store32(ctx.gpr[5] + static_cast<std::uint32_t>(0), ctx.gpr[4]);
    ctx.gpr[4] = (aot_mem.aot_load32(ctx.gpr[16] + static_cast<std::uint32_t>(80)));
    ctx.gpr[5] = (aot_mem.aot_load32(ctx.gpr[16] + static_cast<std::uint32_t>(92)));
    ctx.gpr[6] = (ctx.gpr[4] + ctx.gpr[20]);
    ctx.gpr[4] = (aot_mem.aot_load32(ctx.gpr[6] + static_cast<std::uint32_t>(12)));
    ctx.gpr[7] = (ctx.gpr[5] + ctx.gpr[19]);
    ctx.gpr[5] = (aot_mem.aot_load32(ctx.gpr[6] + static_cast<std::uint32_t>(8)));
    { const bool branch_taken = 0u == 0u;
    ctx.gpr[6] = (aot_mem.aot_load32(ctx.gpr[7] + static_cast<std::uint32_t>(0)));
      if (branch_taken) {
          goto L_089C422C;
      }
      goto L_089C41C4;
    }
L_089C41C4:
    ctx.gpr[5] = (ctx.gpr[7] | 0u);
    ctx.gpr[6] = (ctx.gpr[22] | 0u);
    ctx.gpr[31] = (0x089C41D4u);
    ctx.gpr[7] = (0u | 1u);
    if (rt.invoke_chained_direct<&recomp_unit_0011_entry, 11u, 923u, 0x08971134u>(ctx, &aot_mem) && ctx.pc == 0x089C41D4u) goto L_089C41D4;
    return;
L_089C41D4:
    ctx.gpr[4] = (ctx.gpr[2] | 0u);
    if (ctx.gpr[4] == 0u) {
    ctx.gpr[5] = (aot_mem.aot_load32(ctx.gpr[16] + static_cast<std::uint32_t>(92)));
        goto L_089C4208;
    }
    goto L_089C41E0;
L_089C41E0:
    ctx.gpr[5] = (aot_mem.aot_load32(ctx.gpr[17] + static_cast<std::uint32_t>(136)));
    ctx.gpr[5] = (aot_mem.aot_load32(ctx.gpr[5] + static_cast<std::uint32_t>(456)));
    ctx.gpr[5] = (aot_mem.aot_load16(ctx.gpr[5] + static_cast<std::uint32_t>(24)));
    ctx.gpr[6] = (aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(16)));
    ctx.gpr[5] = (ctx.gpr[5] << 2u);
    ctx.gpr[5] = (ctx.gpr[17] + ctx.gpr[5]);
    ctx.gpr[7] = (aot_mem.aot_load32(ctx.gpr[5] + static_cast<std::uint32_t>(180)));
    ctx.gpr[6] = (ctx.gpr[7] + ctx.gpr[6]);
    aot_mem.aot_store32(ctx.gpr[5] + static_cast<std::uint32_t>(180), ctx.gpr[6]);
    ctx.gpr[5] = (aot_mem.aot_load32(ctx.gpr[16] + static_cast<std::uint32_t>(92)));
    goto L_089C4208;
L_089C4208:
    ctx.gpr[5] = (ctx.gpr[5] + ctx.gpr[19]);
    aot_mem.aot_store32(ctx.gpr[5] + static_cast<std::uint32_t>(0), ctx.gpr[4]);
    ctx.gpr[4] = (aot_mem.aot_load32(ctx.gpr[16] + static_cast<std::uint32_t>(80)));
    ctx.gpr[5] = (aot_mem.aot_load32(ctx.gpr[16] + static_cast<std::uint32_t>(92)));
    ctx.gpr[6] = (ctx.gpr[4] + ctx.gpr[20]);
    ctx.gpr[4] = (aot_mem.aot_load32(ctx.gpr[6] + static_cast<std::uint32_t>(12)));
    ctx.gpr[7] = (ctx.gpr[5] + ctx.gpr[19]);
    ctx.gpr[5] = (aot_mem.aot_load32(ctx.gpr[6] + static_cast<std::uint32_t>(8)));
    ctx.gpr[6] = (aot_mem.aot_load32(ctx.gpr[7] + static_cast<std::uint32_t>(0)));
    goto L_089C422C;
L_089C422C:
    ctx.gpr[7] = (ctx.gpr[5] | 0u);
    ctx.gpr[5] = (ctx.gpr[4] | 0u);
    ctx.gpr[4] = (ctx.gpr[6] | 0u);
    ctx.gpr[31] = (0x089C4240u);
    ctx.gpr[6] = (ctx.gpr[7] | 0u);
    if (rt.invoke_chained_direct<&recomp_unit_0009_entry, 9u, 2651u, 0x08935524u>(ctx, &aot_mem) && ctx.pc == 0x089C4240u) goto L_089C4240;
    return;
L_089C4240:
    { const bool branch_taken = 0u == 0u;
    ctx.gpr[4] = (aot_mem.aot_load32(ctx.gpr[16] + static_cast<std::uint32_t>(84)));
      if (branch_taken) {
          goto L_089C4258;
      }
      goto L_089C4248;
    }
L_089C4248:
    ctx.gpr[4] = (aot_mem.aot_load32(ctx.gpr[16] + static_cast<std::uint32_t>(92)));
    ctx.gpr[4] = (ctx.gpr[4] + ctx.gpr[19]);
    aot_mem.aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(0), 0u);
    ctx.gpr[4] = (aot_mem.aot_load32(ctx.gpr[16] + static_cast<std::uint32_t>(84)));
    goto L_089C4258;
L_089C4258:
    ctx.gpr[18] = (ctx.gpr[18] + static_cast<std::uint32_t>(1));
    ctx.gpr[19] = (ctx.gpr[19] + static_cast<std::uint32_t>(4));
    ctx.gpr[4] = (ctx.gpr[18] < ctx.gpr[4] ? 1u : 0u);
    { const bool branch_taken = ctx.gpr[4] != 0u;
    ctx.gpr[20] = (ctx.gpr[20] + static_cast<std::uint32_t>(16));
      if (branch_taken) {
          goto L_089C4050;
      }
      goto L_089C426C;
    }
L_089C426C:
    ctx.gpr[2] = (0u | 1u);
    ctx.gpr[16] = (aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(20)));
    ctx.gpr[17] = (aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(24)));
    ctx.gpr[18] = (aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(28)));
    ctx.gpr[19] = (aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(32)));
    ctx.gpr[20] = (aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(36)));
    ctx.gpr[21] = (aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(40)));
    ctx.gpr[22] = (aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(44)));
    ctx.gpr[31] = (aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(48)));
    jump_target = ctx.gpr[31];
    ctx.gpr[29] = (ctx.gpr[29] + static_cast<std::uint32_t>(64));
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C4298:
    ctx.gpr[29] = (ctx.gpr[29] + static_cast<std::uint32_t>(-32));
    ctx.gpr[6] = (aot_mem.aot_load8(ctx.gpr[5] + static_cast<std::uint32_t>(110)));
    ctx.gpr[8] = (ctx.gpr[29] + static_cast<std::uint32_t>(12));
    ctx.gpr[2] = (ctx.gpr[4] + static_cast<std::uint32_t>(64));
    ctx.gpr[3] = (ctx.gpr[4] + static_cast<std::uint32_t>(68));
    { const bool branch_taken = ctx.gpr[6] == 0u;
    ctx.gpr[12] = (ctx.gpr[4] + static_cast<std::uint32_t>(72));
      if (branch_taken) {
          goto L_089C43D8;
      }
      goto L_089C42B4;
    }
L_089C42B4:
    ctx.gpr[6] = (2206u << 16u);
    ctx.gpr[7] = (aot_mem.aot_load32(ctx.gpr[6] + static_cast<std::uint32_t>(-24288)));
    ctx.gpr[9] = (3u << 16u);
    ctx.gpr[9] = (ctx.gpr[9] + static_cast<std::uint32_t>(17405));
    { const std::int64_t product = static_cast<std::int64_t>(static_cast<std::int32_t>(ctx.gpr[7])) * static_cast<std::int64_t>(static_cast<std::int32_t>(ctx.gpr[9])); ctx.lo = static_cast<std::uint32_t>(product); ctx.hi = static_cast<std::uint32_t>(static_cast<std::uint64_t>(product) >> 32u); }
    ctx.gpr[7] = (39u << 16u);
    ctx.gpr[7] = (ctx.gpr[7] + static_cast<std::uint32_t>(-24893));
    ctx.gpr[10] = (18175u << 16u);
    ctx.gpr[10] = (ctx.gpr[10] | 65024u);
    ctx.gpr[11] = (ctx.lo);
    ctx.fpr[13] = std::bit_cast<float>(ctx.gpr[10]);
    ctx.gpr[11] = (ctx.gpr[11] + ctx.gpr[7]);
    ctx.gpr[13] = (static_cast<std::uint32_t>(static_cast<std::int32_t>(ctx.gpr[11]) >> 16u));
    ctx.gpr[13] = (ctx.gpr[13] & 32767u);
    ctx.fpr[12] = std::bit_cast<float>(ctx.gpr[13]);
    ctx.fpr[12] = static_cast<float>(static_cast<std::int32_t>(std::bit_cast<std::uint32_t>(ctx.fpr[12])));
    ctx.fpr[12] = ctx.fpr[12] / ctx.fpr[13];
    ctx.gpr[13] = (16384u << 16u);
    ctx.gpr[10] = (ctx.gpr[5] + static_cast<std::uint32_t>(72));
    ctx.fpr[14] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[10] + static_cast<std::uint32_t>(0)));
    aot_mem.aot_store32(ctx.gpr[6] + static_cast<std::uint32_t>(-24288), ctx.gpr[11]);
    ctx.fpr[15] = std::bit_cast<float>(ctx.gpr[13]);
    { const float fs = ctx.fpr[12]; const float ft = ctx.fpr[15]; if ((std::isinf(fs) && ft == 0.0f) || (std::isinf(ft) && fs == 0.0f)) ctx.fpr[12] = std::bit_cast<float>(0x7FC00000u); else ctx.fpr[12] = fs * ft; }
    { const float fs = ctx.fpr[12]; const float ft = ctx.fpr[14]; if ((std::isinf(fs) && ft == 0.0f) || (std::isinf(ft) && fs == 0.0f)) ctx.fpr[12] = std::bit_cast<float>(0x7FC00000u); else ctx.fpr[12] = fs * ft; }
    ctx.fpr[12] = ctx.fpr[12] - ctx.fpr[14];
    aot_mem.aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(0), std::bit_cast<std::uint32_t>(ctx.fpr[12]));
    ctx.gpr[11] = (aot_mem.aot_load32(ctx.gpr[6] + static_cast<std::uint32_t>(-24288)));
    { const std::int64_t product = static_cast<std::int64_t>(static_cast<std::int32_t>(ctx.gpr[11])) * static_cast<std::int64_t>(static_cast<std::int32_t>(ctx.gpr[9])); ctx.lo = static_cast<std::uint32_t>(product); ctx.hi = static_cast<std::uint32_t>(static_cast<std::uint64_t>(product) >> 32u); }
    ctx.gpr[11] = (ctx.lo);
    ctx.gpr[11] = (ctx.gpr[11] + ctx.gpr[7]);
    ctx.gpr[13] = (static_cast<std::uint32_t>(static_cast<std::int32_t>(ctx.gpr[11]) >> 16u));
    ctx.gpr[13] = (ctx.gpr[13] & 32767u);
    ctx.fpr[12] = std::bit_cast<float>(ctx.gpr[13]);
    ctx.fpr[12] = static_cast<float>(static_cast<std::int32_t>(std::bit_cast<std::uint32_t>(ctx.fpr[12])));
    ctx.fpr[12] = ctx.fpr[12] / ctx.fpr[13];
    ctx.fpr[14] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[10] + static_cast<std::uint32_t>(4)));
    aot_mem.aot_store32(ctx.gpr[6] + static_cast<std::uint32_t>(-24288), ctx.gpr[11]);
    ctx.gpr[10] = (ctx.gpr[5] + static_cast<std::uint32_t>(80));
    { const float fs = ctx.fpr[12]; const float ft = ctx.fpr[15]; if ((std::isinf(fs) && ft == 0.0f) || (std::isinf(ft) && fs == 0.0f)) ctx.fpr[12] = std::bit_cast<float>(0x7FC00000u); else ctx.fpr[12] = fs * ft; }
    { const float fs = ctx.fpr[12]; const float ft = ctx.fpr[14]; if ((std::isinf(fs) && ft == 0.0f) || (std::isinf(ft) && fs == 0.0f)) ctx.fpr[12] = std::bit_cast<float>(0x7FC00000u); else ctx.fpr[12] = fs * ft; }
    ctx.fpr[12] = ctx.fpr[12] - ctx.fpr[14];
    aot_mem.aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(4), std::bit_cast<std::uint32_t>(ctx.fpr[12]));
    ctx.gpr[11] = (aot_mem.aot_load32(ctx.gpr[6] + static_cast<std::uint32_t>(-24288)));
    { const std::int64_t product = static_cast<std::int64_t>(static_cast<std::int32_t>(ctx.gpr[11])) * static_cast<std::int64_t>(static_cast<std::int32_t>(ctx.gpr[9])); ctx.lo = static_cast<std::uint32_t>(product); ctx.hi = static_cast<std::uint32_t>(static_cast<std::uint64_t>(product) >> 32u); }
    ctx.gpr[11] = (ctx.lo);
    ctx.gpr[11] = (ctx.gpr[11] + ctx.gpr[7]);
    ctx.gpr[13] = (static_cast<std::uint32_t>(static_cast<std::int32_t>(ctx.gpr[11]) >> 16u));
    ctx.gpr[13] = (ctx.gpr[13] & 32767u);
    ctx.fpr[12] = std::bit_cast<float>(ctx.gpr[13]);
    ctx.fpr[12] = static_cast<float>(static_cast<std::int32_t>(std::bit_cast<std::uint32_t>(ctx.fpr[12])));
    ctx.fpr[12] = ctx.fpr[12] / ctx.fpr[13];
    ctx.fpr[14] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[10] + static_cast<std::uint32_t>(0)));
    aot_mem.aot_store32(ctx.gpr[6] + static_cast<std::uint32_t>(-24288), ctx.gpr[11]);
    { const float fs = ctx.fpr[12]; const float ft = ctx.fpr[15]; if ((std::isinf(fs) && ft == 0.0f) || (std::isinf(ft) && fs == 0.0f)) ctx.fpr[12] = std::bit_cast<float>(0x7FC00000u); else ctx.fpr[12] = fs * ft; }
    { const float fs = ctx.fpr[12]; const float ft = ctx.fpr[14]; if ((std::isinf(fs) && ft == 0.0f) || (std::isinf(ft) && fs == 0.0f)) ctx.fpr[12] = std::bit_cast<float>(0x7FC00000u); else ctx.fpr[12] = fs * ft; }
    ctx.fpr[12] = ctx.fpr[12] - ctx.fpr[14];
    aot_mem.aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(8), std::bit_cast<std::uint32_t>(ctx.fpr[12]));
    ctx.gpr[11] = (aot_mem.aot_load32(ctx.gpr[6] + static_cast<std::uint32_t>(-24288)));
    { const std::int64_t product = static_cast<std::int64_t>(static_cast<std::int32_t>(ctx.gpr[11])) * static_cast<std::int64_t>(static_cast<std::int32_t>(ctx.gpr[9])); ctx.lo = static_cast<std::uint32_t>(product); ctx.hi = static_cast<std::uint32_t>(static_cast<std::uint64_t>(product) >> 32u); }
    ctx.gpr[9] = (ctx.lo);
    ctx.gpr[7] = (ctx.gpr[9] + ctx.gpr[7]);
    ctx.gpr[9] = (static_cast<std::uint32_t>(static_cast<std::int32_t>(ctx.gpr[7]) >> 16u));
    ctx.gpr[9] = (ctx.gpr[9] & 32767u);
    ctx.fpr[12] = std::bit_cast<float>(ctx.gpr[9]);
    ctx.fpr[12] = static_cast<float>(static_cast<std::int32_t>(std::bit_cast<std::uint32_t>(ctx.fpr[12])));
    ctx.fpr[12] = ctx.fpr[12] / ctx.fpr[13];
    ctx.fpr[14] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[10] + static_cast<std::uint32_t>(4)));
    aot_mem.aot_store32(ctx.gpr[6] + static_cast<std::uint32_t>(-24288), ctx.gpr[7]);
    { const float fs = ctx.fpr[12]; const float ft = ctx.fpr[15]; if ((std::isinf(fs) && ft == 0.0f) || (std::isinf(ft) && fs == 0.0f)) ctx.fpr[12] = std::bit_cast<float>(0x7FC00000u); else ctx.fpr[12] = fs * ft; }
    { const float fs = ctx.fpr[12]; const float ft = ctx.fpr[14]; if ((std::isinf(fs) && ft == 0.0f) || (std::isinf(ft) && fs == 0.0f)) ctx.fpr[12] = std::bit_cast<float>(0x7FC00000u); else ctx.fpr[12] = fs * ft; }
    ctx.fpr[12] = ctx.fpr[12] - ctx.fpr[14];
    { const bool branch_taken = 0u == 0u;
    aot_mem.aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(12), std::bit_cast<std::uint32_t>(ctx.fpr[12]));
      if (branch_taken) {
          goto L_089C43EC;
      }
      goto L_089C43D8;
    }
L_089C43D8:
    ctx.fpr[12] = std::bit_cast<float>(0u);
    aot_mem.aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(0), std::bit_cast<std::uint32_t>(ctx.fpr[12]));
    aot_mem.aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(4), std::bit_cast<std::uint32_t>(ctx.fpr[12]));
    aot_mem.aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(8), std::bit_cast<std::uint32_t>(ctx.fpr[12]));
    aot_mem.aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(12), std::bit_cast<std::uint32_t>(ctx.fpr[12]));
    goto L_089C43EC;
L_089C43EC:
    ctx.gpr[6] = (ctx.gpr[5] | 0u);
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(0), ctx.gpr[5]);
    ctx.gpr[7] = (ctx.gpr[6] + static_cast<std::uint32_t>(92));
    ctx.gpr[9] = (0u | 0u);
    ctx.gpr[10] = (ctx.gpr[4] | 0u);
    goto L_089C4400;
L_089C4400:
    ctx.fpr[12] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[7] + static_cast<std::uint32_t>(0)));
    ctx.gpr[9] = (ctx.gpr[9] + static_cast<std::uint32_t>(1));
    aot_mem.aot_store32(ctx.gpr[10] + static_cast<std::uint32_t>(20), std::bit_cast<std::uint32_t>(ctx.fpr[12]));
    aot_mem.aot_store32(ctx.gpr[10] + static_cast<std::uint32_t>(16), std::bit_cast<std::uint32_t>(ctx.fpr[12]));
    ctx.gpr[7] = (ctx.gpr[7] + static_cast<std::uint32_t>(4));
    ctx.gpr[11] = (ctx.gpr[9] < static_cast<std::uint32_t>(1) ? 1u : 0u);
    { const bool branch_taken = ctx.gpr[11] != 0u;
    ctx.gpr[10] = (ctx.gpr[10] + static_cast<std::uint32_t>(4));
      if (branch_taken) {
          goto L_089C4400;
      }
      goto L_089C4420;
    }
L_089C4420:
    ctx.gpr[7] = (ctx.gpr[6] + static_cast<std::uint32_t>(96));
    ctx.gpr[9] = (0u | 0u);
    ctx.gpr[10] = (ctx.gpr[4] | 0u);
    goto L_089C442C;
L_089C442C:
    ctx.fpr[12] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[7] + static_cast<std::uint32_t>(0)));
    ctx.gpr[9] = (ctx.gpr[9] + static_cast<std::uint32_t>(1));
    aot_mem.aot_store32(ctx.gpr[10] + static_cast<std::uint32_t>(24), std::bit_cast<std::uint32_t>(ctx.fpr[12]));
    ctx.gpr[7] = (ctx.gpr[7] + static_cast<std::uint32_t>(4));
    ctx.gpr[11] = (ctx.gpr[9] < static_cast<std::uint32_t>(1) ? 1u : 0u);
    { const bool branch_taken = ctx.gpr[11] != 0u;
    ctx.gpr[10] = (ctx.gpr[10] + static_cast<std::uint32_t>(4));
      if (branch_taken) {
          goto L_089C442C;
      }
      goto L_089C4448;
    }
L_089C4448:
    ctx.gpr[6] = (ctx.gpr[6] + static_cast<std::uint32_t>(100));
    ctx.gpr[7] = (0u | 0u);
    ctx.gpr[9] = (ctx.gpr[4] | 0u);
    goto L_089C4454;
L_089C4454:
    ctx.fpr[12] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[6] + static_cast<std::uint32_t>(0)));
    ctx.gpr[7] = (ctx.gpr[7] + static_cast<std::uint32_t>(1));
    aot_mem.aot_store32(ctx.gpr[9] + static_cast<std::uint32_t>(28), std::bit_cast<std::uint32_t>(ctx.fpr[12]));
    ctx.gpr[6] = (ctx.gpr[6] + static_cast<std::uint32_t>(4));
    ctx.gpr[10] = (ctx.gpr[7] < static_cast<std::uint32_t>(1) ? 1u : 0u);
    { const bool branch_taken = ctx.gpr[10] != 0u;
    ctx.gpr[9] = (ctx.gpr[9] + static_cast<std::uint32_t>(4));
      if (branch_taken) {
          goto L_089C4454;
      }
      goto L_089C4470;
    }
L_089C4470:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(4), ctx.gpr[5]);
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(8), ctx.gpr[4]);
    ctx.gpr[7] = (ctx.gpr[4] | 0u);
    ctx.gpr[6] = (ctx.gpr[5] | 0u);
    ctx.fpr[12] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[7] + static_cast<std::uint32_t>(0)));
    ctx.gpr[13] = (ctx.gpr[6] + static_cast<std::uint32_t>(48));
    ctx.fpr[13] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[13] + static_cast<std::uint32_t>(0)));
    ctx.fpr[12] = ctx.fpr[13] + ctx.fpr[12];
    ctx.gpr[9] = (ctx.gpr[8] | 0u);
    ctx.gpr[10] = (0u | 0u);
    ctx.gpr[11] = (ctx.gpr[4] | 0u);
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(12), std::bit_cast<std::uint32_t>(ctx.fpr[12]));
    ctx.fpr[12] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[7] + static_cast<std::uint32_t>(4)));
    ctx.fpr[14] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[13] + static_cast<std::uint32_t>(4)));
    ctx.fpr[12] = ctx.fpr[14] + ctx.fpr[12];
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(16), std::bit_cast<std::uint32_t>(ctx.fpr[12]));
    goto L_089C44B0;
L_089C44B0:
    ctx.fpr[12] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[9] + static_cast<std::uint32_t>(0)));
    ctx.gpr[10] = (ctx.gpr[10] + static_cast<std::uint32_t>(1));
    aot_mem.aot_store32(ctx.gpr[11] + static_cast<std::uint32_t>(40), std::bit_cast<std::uint32_t>(ctx.fpr[12]));
    aot_mem.aot_store32(ctx.gpr[11] + static_cast<std::uint32_t>(32), std::bit_cast<std::uint32_t>(ctx.fpr[12]));
    ctx.gpr[9] = (ctx.gpr[9] + static_cast<std::uint32_t>(4));
    ctx.gpr[13] = (ctx.gpr[10] < static_cast<std::uint32_t>(2) ? 1u : 0u);
    { const bool branch_taken = ctx.gpr[13] != 0u;
    ctx.gpr[11] = (ctx.gpr[11] + static_cast<std::uint32_t>(4));
      if (branch_taken) {
          goto L_089C44B0;
      }
      goto L_089C44D0;
    }
L_089C44D0:
    ctx.gpr[9] = (ctx.gpr[7] + static_cast<std::uint32_t>(8));
    ctx.gpr[10] = (ctx.gpr[6] + static_cast<std::uint32_t>(56));
    ctx.fpr[12] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[9] + static_cast<std::uint32_t>(0)));
    ctx.fpr[13] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[10] + static_cast<std::uint32_t>(0)));
    ctx.gpr[11] = (ctx.gpr[7] + static_cast<std::uint32_t>(8));
    ctx.fpr[12] = ctx.fpr[13] + ctx.fpr[12];
    ctx.gpr[7] = (0u | 0u);
    ctx.gpr[9] = (ctx.gpr[4] | 0u);
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(12), std::bit_cast<std::uint32_t>(ctx.fpr[12]));
    ctx.fpr[12] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[11] + static_cast<std::uint32_t>(4)));
    ctx.fpr[14] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[10] + static_cast<std::uint32_t>(4)));
    ctx.fpr[12] = ctx.fpr[14] + ctx.fpr[12];
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(16), std::bit_cast<std::uint32_t>(ctx.fpr[12]));
    goto L_089C4504;
L_089C4504:
    ctx.fpr[12] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[8] + static_cast<std::uint32_t>(0)));
    ctx.gpr[7] = (ctx.gpr[7] + static_cast<std::uint32_t>(1));
    aot_mem.aot_store32(ctx.gpr[9] + static_cast<std::uint32_t>(48), std::bit_cast<std::uint32_t>(ctx.fpr[12]));
    ctx.gpr[8] = (ctx.gpr[8] + static_cast<std::uint32_t>(4));
    ctx.gpr[10] = (ctx.gpr[7] < static_cast<std::uint32_t>(2) ? 1u : 0u);
    { const bool branch_taken = ctx.gpr[10] != 0u;
    ctx.gpr[9] = (ctx.gpr[9] + static_cast<std::uint32_t>(4));
      if (branch_taken) {
          goto L_089C4504;
      }
      goto L_089C4520;
    }
L_089C4520:
    ctx.gpr[6] = (ctx.gpr[6] + static_cast<std::uint32_t>(64));
    ctx.gpr[7] = (0u | 0u);
    ctx.gpr[8] = (ctx.gpr[4] | 0u);
    goto L_089C452C;
L_089C452C:
    ctx.fpr[12] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[6] + static_cast<std::uint32_t>(0)));
    ctx.gpr[7] = (ctx.gpr[7] + static_cast<std::uint32_t>(1));
    aot_mem.aot_store32(ctx.gpr[8] + static_cast<std::uint32_t>(56), std::bit_cast<std::uint32_t>(ctx.fpr[12]));
    ctx.gpr[6] = (ctx.gpr[6] + static_cast<std::uint32_t>(4));
    ctx.gpr[9] = (ctx.gpr[7] < static_cast<std::uint32_t>(2) ? 1u : 0u);
    { const bool branch_taken = ctx.gpr[9] != 0u;
    ctx.gpr[8] = (ctx.gpr[8] + static_cast<std::uint32_t>(4));
      if (branch_taken) {
          goto L_089C452C;
      }
      goto L_089C4548;
    }
L_089C4548:
    ctx.gpr[6] = (2206u << 16u);
    ctx.gpr[6] = (ctx.gpr[6] + static_cast<std::uint32_t>(-12072));
    aot_mem.aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(64), ctx.gpr[6]);
    ctx.gpr[6] = (2206u << 16u);
    ctx.gpr[6] = (ctx.gpr[6] + static_cast<std::uint32_t>(-12048));
    aot_mem.aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(68), ctx.gpr[6]);
    ctx.gpr[6] = (2206u << 16u);
    ctx.gpr[6] = (ctx.gpr[6] + static_cast<std::uint32_t>(-12024));
    aot_mem.aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(72), ctx.gpr[6]);
    ctx.gpr[5] = (aot_mem.aot_load8(ctx.gpr[5] + static_cast<std::uint32_t>(111)));
    { const bool branch_taken = static_cast<std::int32_t>(ctx.gpr[5]) > 0;
    ctx.gpr[6] = (static_cast<std::int32_t>(ctx.gpr[5]) < 2 ? 1u : 0u);
      if (branch_taken) {
          goto L_089C4588;
      }
      goto L_089C4578;
    }
L_089C4578:
    { const bool branch_taken = static_cast<std::int32_t>(ctx.gpr[5]) < 0;
    ctx.gpr[3] = (0u | 0u);
      if (branch_taken) {
          goto L_089C45A8;
      }
      goto L_089C4580;
    }
L_089C4580:
    { const bool branch_taken = 0u == 0u;
    ctx.gpr[3] = (ctx.gpr[2] | 0u);
      if (branch_taken) {
          goto L_089C45A8;
      }
      goto L_089C4588;
    }
L_089C4588:
    { const bool branch_taken = ctx.gpr[6] != 0u;
    ctx.gpr[5] = (static_cast<std::int32_t>(ctx.gpr[5]) < 3 ? 1u : 0u);
      if (branch_taken) {
          goto L_089C45A0;
      }
      goto L_089C4590;
    }
L_089C4590:
    { const bool branch_taken = ctx.gpr[5] == 0u;
    ctx.gpr[3] = (0u | 0u);
      if (branch_taken) {
          goto L_089C45A8;
      }
      goto L_089C4598;
    }
L_089C4598:
    { const bool branch_taken = 0u == 0u;
    ctx.gpr[3] = (ctx.gpr[12] | 0u);
      if (branch_taken) {
          goto L_089C45A8;
      }
      goto L_089C45A0;
    }
L_089C45A0:
    { const bool branch_taken = 0u == 0u;
    // nop
      if (branch_taken) {
          goto L_089C45A8;
      }
      goto L_089C45A8;
    }
L_089C45A8:
    aot_mem.aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(76), ctx.gpr[3]);
    aot_mem.aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(80), 0u);
    aot_mem.aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(84), 0u);
    aot_mem.aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(88), 0u);
    aot_mem.aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(92), 0u);
    ctx.gpr[2] = (ctx.gpr[4] | 0u);
    jump_target = ctx.gpr[31];
    ctx.gpr[29] = (ctx.gpr[29] + static_cast<std::uint32_t>(32));
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C45C8:
    ctx.gpr[7] = (aot_mem.aot_load32(ctx.gpr[5] + static_cast<std::uint32_t>(4)));
    ctx.gpr[8] = (aot_mem.aot_load32(ctx.gpr[5] + static_cast<std::uint32_t>(0)));
    ctx.fpr[13] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[7] + static_cast<std::uint32_t>(0)));
    ctx.gpr[7] = (ctx.gpr[8] + static_cast<std::uint32_t>(48));
    ctx.fpr[14] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[7] + static_cast<std::uint32_t>(0)));
    ctx.gpr[7] = (aot_mem.aot_load32(ctx.gpr[5] + static_cast<std::uint32_t>(4)));
    ctx.fpr[13] = ctx.fpr[14] + ctx.fpr[13];
    ctx.gpr[8] = (aot_mem.aot_load32(ctx.gpr[5] + static_cast<std::uint32_t>(0)));
    ctx.gpr[8] = (ctx.gpr[8] + static_cast<std::uint32_t>(48));
    aot_mem.aot_store32(ctx.gpr[5] + static_cast<std::uint32_t>(8), std::bit_cast<std::uint32_t>(ctx.fpr[13]));
    ctx.fpr[13] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[7] + static_cast<std::uint32_t>(4)));
    ctx.fpr[15] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[8] + static_cast<std::uint32_t>(4)));
    ctx.gpr[7] = (aot_mem.aot_load32(ctx.gpr[5] + static_cast<std::uint32_t>(4)));
    ctx.fpr[13] = ctx.fpr[15] + ctx.fpr[13];
    ctx.gpr[8] = (aot_mem.aot_load32(ctx.gpr[5] + static_cast<std::uint32_t>(0)));
    ctx.gpr[7] = (ctx.gpr[7] + static_cast<std::uint32_t>(8));
    ctx.gpr[8] = (ctx.gpr[8] + static_cast<std::uint32_t>(56));
    aot_mem.aot_store32(ctx.gpr[5] + static_cast<std::uint32_t>(12), std::bit_cast<std::uint32_t>(ctx.fpr[13]));
    ctx.fpr[13] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[7] + static_cast<std::uint32_t>(0)));
    ctx.fpr[14] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[8] + static_cast<std::uint32_t>(0)));
    ctx.gpr[7] = (aot_mem.aot_load32(ctx.gpr[5] + static_cast<std::uint32_t>(4)));
    ctx.fpr[13] = ctx.fpr[14] + ctx.fpr[13];
    ctx.gpr[8] = (aot_mem.aot_load32(ctx.gpr[5] + static_cast<std::uint32_t>(0)));
    ctx.gpr[7] = (ctx.gpr[7] + static_cast<std::uint32_t>(8));
    ctx.gpr[8] = (ctx.gpr[8] + static_cast<std::uint32_t>(56));
    aot_mem.aot_store32(ctx.gpr[5] + static_cast<std::uint32_t>(8), std::bit_cast<std::uint32_t>(ctx.fpr[13]));
    ctx.fpr[13] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[7] + static_cast<std::uint32_t>(4)));
    ctx.fpr[15] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[8] + static_cast<std::uint32_t>(4)));
    ctx.gpr[7] = (aot_mem.aot_load32(ctx.gpr[5] + static_cast<std::uint32_t>(0)));
    ctx.fpr[13] = ctx.fpr[15] + ctx.fpr[13];
    ctx.gpr[3] = (ctx.gpr[4] + static_cast<std::uint32_t>(8));
    ctx.gpr[2] = (ctx.gpr[4] + static_cast<std::uint32_t>(16));
    ctx.gpr[11] = (ctx.gpr[4] + static_cast<std::uint32_t>(24));
    aot_mem.aot_store32(ctx.gpr[5] + static_cast<std::uint32_t>(12), std::bit_cast<std::uint32_t>(ctx.fpr[13]));
    ctx.gpr[8] = (aot_mem.aot_load32(ctx.gpr[6] + static_cast<std::uint32_t>(4)));
    ctx.gpr[9] = (aot_mem.aot_load32(ctx.gpr[6] + static_cast<std::uint32_t>(0)));
    ctx.fpr[13] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[8] + static_cast<std::uint32_t>(0)));
    ctx.gpr[8] = (ctx.gpr[9] + static_cast<std::uint32_t>(48));
    ctx.fpr[14] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[8] + static_cast<std::uint32_t>(0)));
    ctx.gpr[4] = (aot_mem.aot_load32(ctx.gpr[6] + static_cast<std::uint32_t>(4)));
    ctx.fpr[13] = ctx.fpr[14] + ctx.fpr[13];
    ctx.gpr[8] = (aot_mem.aot_load32(ctx.gpr[6] + static_cast<std::uint32_t>(0)));
    ctx.gpr[8] = (ctx.gpr[8] + static_cast<std::uint32_t>(48));
    aot_mem.aot_store32(ctx.gpr[6] + static_cast<std::uint32_t>(8), std::bit_cast<std::uint32_t>(ctx.fpr[13]));
    ctx.fpr[13] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(4)));
    ctx.fpr[15] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[8] + static_cast<std::uint32_t>(4)));
    ctx.gpr[4] = (aot_mem.aot_load32(ctx.gpr[6] + static_cast<std::uint32_t>(4)));
    ctx.fpr[13] = ctx.fpr[15] + ctx.fpr[13];
    ctx.gpr[8] = (aot_mem.aot_load32(ctx.gpr[6] + static_cast<std::uint32_t>(0)));
    ctx.gpr[4] = (ctx.gpr[4] + static_cast<std::uint32_t>(8));
    ctx.gpr[8] = (ctx.gpr[8] + static_cast<std::uint32_t>(56));
    ctx.gpr[12] = (ctx.gpr[7] + static_cast<std::uint32_t>(64));
    aot_mem.aot_store32(ctx.gpr[6] + static_cast<std::uint32_t>(12), std::bit_cast<std::uint32_t>(ctx.fpr[13]));
    ctx.fpr[13] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(0)));
    ctx.fpr[14] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[8] + static_cast<std::uint32_t>(0)));
    ctx.gpr[4] = (aot_mem.aot_load32(ctx.gpr[6] + static_cast<std::uint32_t>(4)));
    ctx.fpr[13] = ctx.fpr[14] + ctx.fpr[13];
    ctx.gpr[7] = (aot_mem.aot_load32(ctx.gpr[6] + static_cast<std::uint32_t>(0)));
    ctx.gpr[4] = (ctx.gpr[4] + static_cast<std::uint32_t>(8));
    ctx.gpr[7] = (ctx.gpr[7] + static_cast<std::uint32_t>(56));
    aot_mem.aot_store32(ctx.gpr[6] + static_cast<std::uint32_t>(8), std::bit_cast<std::uint32_t>(ctx.fpr[13]));
    ctx.fpr[13] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(4)));
    ctx.fpr[15] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[7] + static_cast<std::uint32_t>(4)));
    ctx.gpr[4] = (16128u << 16u);
    ctx.fpr[13] = ctx.fpr[15] + ctx.fpr[13];
    ctx.gpr[8] = (aot_mem.aot_load32(ctx.gpr[6] + static_cast<std::uint32_t>(0)));
    ctx.fpr[14] = std::bit_cast<float>(ctx.gpr[4]);
    ctx.gpr[10] = (ctx.gpr[6] + static_cast<std::uint32_t>(8));
    { const float fs = ctx.fpr[12]; const float ft = ctx.fpr[14]; if ((std::isinf(fs) && ft == 0.0f) || (std::isinf(ft) && fs == 0.0f)) ctx.fpr[14] = std::bit_cast<float>(0x7FC00000u); else ctx.fpr[14] = fs * ft; }
    ctx.gpr[7] = (ctx.gpr[5] + static_cast<std::uint32_t>(8));
    ctx.gpr[8] = (ctx.gpr[8] + static_cast<std::uint32_t>(64));
    aot_mem.aot_store32(ctx.gpr[6] + static_cast<std::uint32_t>(12), std::bit_cast<std::uint32_t>(ctx.fpr[13]));
    ctx.gpr[9] = (ctx.gpr[10] | 0u);
    ctx.gpr[6] = (ctx.gpr[7] | 0u);
    { const float fs = ctx.fpr[14]; const float ft = ctx.fpr[12]; if ((std::isinf(fs) && ft == 0.0f) || (std::isinf(ft) && fs == 0.0f)) ctx.fpr[13] = std::bit_cast<float>(0x7FC00000u); else ctx.fpr[13] = fs * ft; }
    ctx.gpr[5] = (ctx.gpr[12] | 0u);
    ctx.gpr[4] = (0u | 0u);
    goto L_089C46FC;
L_089C46FC:
    ctx.fpr[14] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[8] + static_cast<std::uint32_t>(0)));
    ctx.fpr[15] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[9] + static_cast<std::uint32_t>(0)));
    ctx.fpr[16] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[11] + static_cast<std::uint32_t>(0)));
    { const float fs = ctx.fpr[14]; const float ft = ctx.fpr[13]; if ((std::isinf(fs) && ft == 0.0f) || (std::isinf(ft) && fs == 0.0f)) ctx.fpr[14] = std::bit_cast<float>(0x7FC00000u); else ctx.fpr[14] = fs * ft; }
    ctx.fpr[17] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[2] + static_cast<std::uint32_t>(0)));
    { const float fs = ctx.fpr[15]; const float ft = ctx.fpr[12]; if ((std::isinf(fs) && ft == 0.0f) || (std::isinf(ft) && fs == 0.0f)) ctx.fpr[15] = std::bit_cast<float>(0x7FC00000u); else ctx.fpr[15] = fs * ft; }
    { const float fs = ctx.fpr[16]; const float ft = ctx.fpr[13]; if ((std::isinf(fs) && ft == 0.0f) || (std::isinf(ft) && fs == 0.0f)) ctx.fpr[16] = std::bit_cast<float>(0x7FC00000u); else ctx.fpr[16] = fs * ft; }
    ctx.fpr[18] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[10] + static_cast<std::uint32_t>(0)));
    { const float fs = ctx.fpr[17]; const float ft = ctx.fpr[12]; if ((std::isinf(fs) && ft == 0.0f) || (std::isinf(ft) && fs == 0.0f)) ctx.fpr[17] = std::bit_cast<float>(0x7FC00000u); else ctx.fpr[17] = fs * ft; }
    ctx.fpr[19] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[3] + static_cast<std::uint32_t>(0)));
    ctx.fpr[14] = ctx.fpr[14] + ctx.fpr[15];
    ctx.fpr[0] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[7] + static_cast<std::uint32_t>(0)));
    ctx.fpr[16] = ctx.fpr[16] + ctx.fpr[17];
    ctx.fpr[14] = ctx.fpr[14] + ctx.fpr[18];
    ctx.fpr[16] = ctx.fpr[16] + ctx.fpr[19];
    ctx.fpr[14] = ctx.fpr[16] - ctx.fpr[14];
    ctx.fpr[14] = ctx.fpr[0] + ctx.fpr[14];
    aot_mem.aot_store32(ctx.gpr[3] + static_cast<std::uint32_t>(0), std::bit_cast<std::uint32_t>(ctx.fpr[14]));
    ctx.fpr[14] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[8] + static_cast<std::uint32_t>(0)));
    ctx.fpr[15] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[11] + static_cast<std::uint32_t>(0)));
    { const float fs = ctx.fpr[14]; const float ft = ctx.fpr[12]; if ((std::isinf(fs) && ft == 0.0f) || (std::isinf(ft) && fs == 0.0f)) ctx.fpr[14] = std::bit_cast<float>(0x7FC00000u); else ctx.fpr[14] = fs * ft; }
    ctx.fpr[17] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[9] + static_cast<std::uint32_t>(0)));
    { const float fs = ctx.fpr[15]; const float ft = ctx.fpr[12]; if ((std::isinf(fs) && ft == 0.0f) || (std::isinf(ft) && fs == 0.0f)) ctx.fpr[15] = std::bit_cast<float>(0x7FC00000u); else ctx.fpr[15] = fs * ft; }
    ctx.fpr[16] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[2] + static_cast<std::uint32_t>(0)));
    ctx.fpr[18] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[6] + static_cast<std::uint32_t>(0)));
    ctx.fpr[14] = ctx.fpr[14] + ctx.fpr[17];
    ctx.fpr[15] = ctx.fpr[15] + ctx.fpr[16];
    ctx.gpr[4] = (ctx.gpr[4] + static_cast<std::uint32_t>(1));
    ctx.fpr[14] = ctx.fpr[15] - ctx.fpr[14];
    ctx.gpr[3] = (ctx.gpr[3] + static_cast<std::uint32_t>(4));
    ctx.gpr[10] = (ctx.gpr[10] + static_cast<std::uint32_t>(4));
    ctx.fpr[14] = ctx.fpr[18] + ctx.fpr[14];
    ctx.gpr[9] = (ctx.gpr[9] + static_cast<std::uint32_t>(4));
    ctx.gpr[7] = (ctx.gpr[7] + static_cast<std::uint32_t>(4));
    ctx.gpr[6] = (ctx.gpr[6] + static_cast<std::uint32_t>(4));
    aot_mem.aot_store32(ctx.gpr[2] + static_cast<std::uint32_t>(0), std::bit_cast<std::uint32_t>(ctx.fpr[14]));
    ctx.fpr[14] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[11] + static_cast<std::uint32_t>(0)));
    ctx.fpr[16] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[8] + static_cast<std::uint32_t>(0)));
    ctx.fpr[17] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[5] + static_cast<std::uint32_t>(0)));
    ctx.fpr[14] = ctx.fpr[14] - ctx.fpr[16];
    ctx.gpr[2] = (ctx.gpr[2] + static_cast<std::uint32_t>(4));
    ctx.gpr[8] = (ctx.gpr[8] + static_cast<std::uint32_t>(4));
    ctx.gpr[5] = (ctx.gpr[5] + static_cast<std::uint32_t>(4));
    ctx.gpr[12] = (ctx.gpr[4] < static_cast<std::uint32_t>(2) ? 1u : 0u);
    ctx.fpr[14] = ctx.fpr[17] + ctx.fpr[14];
    aot_mem.aot_store32(ctx.gpr[11] + static_cast<std::uint32_t>(0), std::bit_cast<std::uint32_t>(ctx.fpr[14]));
    { const bool branch_taken = ctx.gpr[12] != 0u;
    ctx.gpr[11] = (ctx.gpr[11] + static_cast<std::uint32_t>(4));
      if (branch_taken) {
          goto L_089C46FC;
      }
      goto L_089C47BC;
    }
L_089C47BC:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C48D0:
    ctx.gpr[7] = (16128u << 16u);
    ctx.fpr[15] = std::bit_cast<float>(ctx.gpr[7]);
    { const float fs = ctx.fpr[12]; const float ft = ctx.fpr[15]; if ((std::isinf(fs) && ft == 0.0f) || (std::isinf(ft) && fs == 0.0f)) ctx.fpr[14] = std::bit_cast<float>(0x7FC00000u); else ctx.fpr[14] = fs * ft; }
    ctx.gpr[7] = (ctx.gpr[5] + static_cast<std::uint32_t>(8));
    { const float fs = ctx.fpr[14]; const float ft = ctx.fpr[12]; if ((std::isinf(fs) && ft == 0.0f) || (std::isinf(ft) && fs == 0.0f)) ctx.fpr[14] = std::bit_cast<float>(0x7FC00000u); else ctx.fpr[14] = fs * ft; }
    ctx.gpr[13] = (ctx.gpr[6] | 0u);
    ctx.gpr[6] = (aot_mem.aot_load32(ctx.gpr[5] + static_cast<std::uint32_t>(4)));
    ctx.gpr[8] = (aot_mem.aot_load32(ctx.gpr[5] + static_cast<std::uint32_t>(0)));
    ctx.fpr[16] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[6] + static_cast<std::uint32_t>(0)));
    ctx.gpr[6] = (ctx.gpr[8] + static_cast<std::uint32_t>(48));
    ctx.fpr[17] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[6] + static_cast<std::uint32_t>(0)));
    ctx.gpr[6] = (aot_mem.aot_load32(ctx.gpr[5] + static_cast<std::uint32_t>(4)));
    ctx.fpr[16] = ctx.fpr[17] + ctx.fpr[16];
    ctx.gpr[8] = (aot_mem.aot_load32(ctx.gpr[5] + static_cast<std::uint32_t>(0)));
    ctx.gpr[8] = (ctx.gpr[8] + static_cast<std::uint32_t>(48));
    aot_mem.aot_store32(ctx.gpr[5] + static_cast<std::uint32_t>(8), std::bit_cast<std::uint32_t>(ctx.fpr[16]));
    ctx.fpr[16] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[6] + static_cast<std::uint32_t>(4)));
    ctx.fpr[18] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[8] + static_cast<std::uint32_t>(4)));
    ctx.gpr[6] = (aot_mem.aot_load32(ctx.gpr[5] + static_cast<std::uint32_t>(4)));
    ctx.fpr[16] = ctx.fpr[18] + ctx.fpr[16];
    ctx.gpr[8] = (aot_mem.aot_load32(ctx.gpr[5] + static_cast<std::uint32_t>(0)));
    ctx.gpr[6] = (ctx.gpr[6] + static_cast<std::uint32_t>(8));
    ctx.gpr[8] = (ctx.gpr[8] + static_cast<std::uint32_t>(56));
    aot_mem.aot_store32(ctx.gpr[5] + static_cast<std::uint32_t>(12), std::bit_cast<std::uint32_t>(ctx.fpr[16]));
    ctx.fpr[16] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[6] + static_cast<std::uint32_t>(0)));
    ctx.fpr[17] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[8] + static_cast<std::uint32_t>(0)));
    ctx.gpr[6] = (aot_mem.aot_load32(ctx.gpr[5] + static_cast<std::uint32_t>(4)));
    ctx.fpr[16] = ctx.fpr[17] + ctx.fpr[16];
    ctx.gpr[8] = (aot_mem.aot_load32(ctx.gpr[5] + static_cast<std::uint32_t>(0)));
    ctx.gpr[6] = (ctx.gpr[6] + static_cast<std::uint32_t>(8));
    ctx.gpr[8] = (ctx.gpr[8] + static_cast<std::uint32_t>(56));
    aot_mem.aot_store32(ctx.gpr[5] + static_cast<std::uint32_t>(8), std::bit_cast<std::uint32_t>(ctx.fpr[16]));
    ctx.fpr[16] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[6] + static_cast<std::uint32_t>(4)));
    ctx.fpr[18] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[8] + static_cast<std::uint32_t>(4)));
    ctx.gpr[8] = (aot_mem.aot_load32(ctx.gpr[5] + static_cast<std::uint32_t>(0)));
    ctx.fpr[16] = ctx.fpr[18] + ctx.fpr[16];
    aot_mem.aot_store32(ctx.gpr[5] + static_cast<std::uint32_t>(12), std::bit_cast<std::uint32_t>(ctx.fpr[16]));
    ctx.gpr[6] = (aot_mem.aot_load32(ctx.gpr[13] + static_cast<std::uint32_t>(4)));
    ctx.gpr[9] = (aot_mem.aot_load32(ctx.gpr[13] + static_cast<std::uint32_t>(0)));
    ctx.fpr[16] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[6] + static_cast<std::uint32_t>(0)));
    ctx.gpr[6] = (ctx.gpr[9] + static_cast<std::uint32_t>(48));
    ctx.fpr[17] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[6] + static_cast<std::uint32_t>(0)));
    ctx.gpr[6] = (aot_mem.aot_load32(ctx.gpr[13] + static_cast<std::uint32_t>(4)));
    ctx.fpr[16] = ctx.fpr[17] + ctx.fpr[16];
    ctx.gpr[9] = (aot_mem.aot_load32(ctx.gpr[13] + static_cast<std::uint32_t>(0)));
    ctx.gpr[9] = (ctx.gpr[9] + static_cast<std::uint32_t>(48));
    aot_mem.aot_store32(ctx.gpr[13] + static_cast<std::uint32_t>(8), std::bit_cast<std::uint32_t>(ctx.fpr[16]));
    ctx.fpr[16] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[6] + static_cast<std::uint32_t>(4)));
    ctx.fpr[18] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[9] + static_cast<std::uint32_t>(4)));
    ctx.gpr[6] = (aot_mem.aot_load32(ctx.gpr[13] + static_cast<std::uint32_t>(4)));
    ctx.fpr[16] = ctx.fpr[18] + ctx.fpr[16];
    ctx.gpr[9] = (aot_mem.aot_load32(ctx.gpr[13] + static_cast<std::uint32_t>(0)));
    ctx.gpr[6] = (ctx.gpr[6] + static_cast<std::uint32_t>(8));
    ctx.gpr[9] = (ctx.gpr[9] + static_cast<std::uint32_t>(56));
    { const float fs = ctx.fpr[13]; const float ft = ctx.fpr[15]; if ((std::isinf(fs) && ft == 0.0f) || (std::isinf(ft) && fs == 0.0f)) ctx.fpr[15] = std::bit_cast<float>(0x7FC00000u); else ctx.fpr[15] = fs * ft; }
    aot_mem.aot_store32(ctx.gpr[13] + static_cast<std::uint32_t>(12), std::bit_cast<std::uint32_t>(ctx.fpr[16]));
    ctx.fpr[16] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[6] + static_cast<std::uint32_t>(0)));
    ctx.fpr[17] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[9] + static_cast<std::uint32_t>(0)));
    ctx.gpr[6] = (aot_mem.aot_load32(ctx.gpr[13] + static_cast<std::uint32_t>(4)));
    ctx.fpr[16] = ctx.fpr[17] + ctx.fpr[16];
    ctx.gpr[9] = (aot_mem.aot_load32(ctx.gpr[13] + static_cast<std::uint32_t>(0)));
    ctx.gpr[6] = (ctx.gpr[6] + static_cast<std::uint32_t>(8));
    ctx.gpr[9] = (ctx.gpr[9] + static_cast<std::uint32_t>(56));
    { const float fs = ctx.fpr[15]; const float ft = ctx.fpr[13]; if ((std::isinf(fs) && ft == 0.0f) || (std::isinf(ft) && fs == 0.0f)) ctx.fpr[15] = std::bit_cast<float>(0x7FC00000u); else ctx.fpr[15] = fs * ft; }
    aot_mem.aot_store32(ctx.gpr[13] + static_cast<std::uint32_t>(8), std::bit_cast<std::uint32_t>(ctx.fpr[16]));
    ctx.fpr[16] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[6] + static_cast<std::uint32_t>(4)));
    ctx.fpr[18] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[9] + static_cast<std::uint32_t>(4)));
    ctx.gpr[10] = (aot_mem.aot_load32(ctx.gpr[13] + static_cast<std::uint32_t>(0)));
    ctx.fpr[16] = ctx.fpr[18] + ctx.fpr[16];
    ctx.gpr[12] = (ctx.gpr[4] + static_cast<std::uint32_t>(8));
    ctx.gpr[3] = (ctx.gpr[4] + static_cast<std::uint32_t>(16));
    ctx.gpr[2] = (ctx.gpr[4] + static_cast<std::uint32_t>(24));
    ctx.gpr[8] = (ctx.gpr[8] + static_cast<std::uint32_t>(64));
    ctx.gpr[11] = (ctx.gpr[13] + static_cast<std::uint32_t>(8));
    ctx.gpr[10] = (ctx.gpr[10] + static_cast<std::uint32_t>(64));
    ctx.gpr[9] = (ctx.gpr[7] | 0u);
    ctx.gpr[6] = (0u | 0u);
    aot_mem.aot_store32(ctx.gpr[13] + static_cast<std::uint32_t>(12), std::bit_cast<std::uint32_t>(ctx.fpr[16]));
    goto L_089C4A08;
L_089C4A08:
    ctx.fpr[16] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[2] + static_cast<std::uint32_t>(0)));
    ctx.fpr[17] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[3] + static_cast<std::uint32_t>(0)));
    ctx.fpr[18] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[10] + static_cast<std::uint32_t>(0)));
    { const float fs = ctx.fpr[16]; const float ft = ctx.fpr[13]; if ((std::isinf(fs) && ft == 0.0f) || (std::isinf(ft) && fs == 0.0f)) ctx.fpr[19] = std::bit_cast<float>(0x7FC00000u); else ctx.fpr[19] = fs * ft; }
    ctx.fpr[0] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[11] + static_cast<std::uint32_t>(0)));
    { const float fs = ctx.fpr[18]; const float ft = ctx.fpr[13]; if ((std::isinf(fs) && ft == 0.0f) || (std::isinf(ft) && fs == 0.0f)) ctx.fpr[18] = std::bit_cast<float>(0x7FC00000u); else ctx.fpr[18] = fs * ft; }
    ctx.fpr[2] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[12] + static_cast<std::uint32_t>(0)));
    ctx.fpr[1] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[9] + static_cast<std::uint32_t>(0)));
    ctx.fpr[19] = ctx.fpr[19] + ctx.fpr[17];
    ctx.fpr[18] = ctx.fpr[18] + ctx.fpr[0];
    { const float fs = ctx.fpr[16]; const float ft = ctx.fpr[15]; if ((std::isinf(fs) && ft == 0.0f) || (std::isinf(ft) && fs == 0.0f)) ctx.fpr[16] = std::bit_cast<float>(0x7FC00000u); else ctx.fpr[16] = fs * ft; }
    { const float fs = ctx.fpr[17]; const float ft = ctx.fpr[13]; if ((std::isinf(fs) && ft == 0.0f) || (std::isinf(ft) && fs == 0.0f)) ctx.fpr[17] = std::bit_cast<float>(0x7FC00000u); else ctx.fpr[17] = fs * ft; }
    ctx.fpr[18] = ctx.fpr[19] - ctx.fpr[18];
    ctx.fpr[16] = ctx.fpr[16] + ctx.fpr[17];
    ctx.fpr[18] = ctx.fpr[1] + ctx.fpr[18];
    aot_mem.aot_store32(ctx.gpr[3] + static_cast<std::uint32_t>(0), std::bit_cast<std::uint32_t>(ctx.fpr[18]));
    ctx.fpr[18] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[2] + static_cast<std::uint32_t>(0)));
    ctx.fpr[0] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[10] + static_cast<std::uint32_t>(0)));
    ctx.fpr[3] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[8] + static_cast<std::uint32_t>(0)));
    ctx.fpr[18] = ctx.fpr[18] - ctx.fpr[0];
    ctx.fpr[16] = ctx.fpr[16] + ctx.fpr[2];
    ctx.gpr[6] = (ctx.gpr[6] + static_cast<std::uint32_t>(1));
    ctx.fpr[17] = ctx.fpr[3] + ctx.fpr[18];
    ctx.gpr[11] = (ctx.gpr[11] + static_cast<std::uint32_t>(4));
    ctx.gpr[10] = (ctx.gpr[10] + static_cast<std::uint32_t>(4));
    aot_mem.aot_store32(ctx.gpr[2] + static_cast<std::uint32_t>(0), std::bit_cast<std::uint32_t>(ctx.fpr[17]));
    ctx.fpr[19] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[3] + static_cast<std::uint32_t>(0)));
    { const float fs = ctx.fpr[17]; const float ft = ctx.fpr[14]; if ((std::isinf(fs) && ft == 0.0f) || (std::isinf(ft) && fs == 0.0f)) ctx.fpr[17] = std::bit_cast<float>(0x7FC00000u); else ctx.fpr[17] = fs * ft; }
    { const float fs = ctx.fpr[19]; const float ft = ctx.fpr[12]; if ((std::isinf(fs) && ft == 0.0f) || (std::isinf(ft) && fs == 0.0f)) ctx.fpr[19] = std::bit_cast<float>(0x7FC00000u); else ctx.fpr[19] = fs * ft; }
    ctx.gpr[3] = (ctx.gpr[3] + static_cast<std::uint32_t>(4));
    ctx.gpr[2] = (ctx.gpr[2] + static_cast<std::uint32_t>(4));
    ctx.gpr[9] = (ctx.gpr[9] + static_cast<std::uint32_t>(4));
    ctx.fpr[17] = ctx.fpr[17] + ctx.fpr[19];
    ctx.gpr[8] = (ctx.gpr[8] + static_cast<std::uint32_t>(4));
    ctx.gpr[13] = (ctx.gpr[6] < static_cast<std::uint32_t>(2) ? 1u : 0u);
    ctx.fpr[16] = ctx.fpr[16] - ctx.fpr[17];
    aot_mem.aot_store32(ctx.gpr[12] + static_cast<std::uint32_t>(0), std::bit_cast<std::uint32_t>(ctx.fpr[16]));
    { const bool branch_taken = ctx.gpr[13] != 0u;
    ctx.gpr[12] = (ctx.gpr[12] + static_cast<std::uint32_t>(4));
      if (branch_taken) {
          goto L_089C4A08;
      }
      goto L_089C4AA4;
    }
L_089C4AA4:
    ctx.gpr[8] = (ctx.gpr[5] | 0u);
    ctx.gpr[6] = (aot_mem.aot_load32(ctx.gpr[8] + static_cast<std::uint32_t>(0)));
    ctx.gpr[5] = (aot_mem.aot_load32(ctx.gpr[8] + static_cast<std::uint32_t>(4)));
    ctx.gpr[9] = (ctx.gpr[6] + static_cast<std::uint32_t>(56));
    ctx.gpr[5] = (ctx.gpr[5] + static_cast<std::uint32_t>(8));
    ctx.fpr[13] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[5] + static_cast<std::uint32_t>(0)));
    ctx.fpr[15] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[9] + static_cast<std::uint32_t>(0)));
    ctx.gpr[9] = (ctx.gpr[4] | 0u);
    ctx.fpr[13] = ctx.fpr[15] + ctx.fpr[13];
    ctx.gpr[4] = (aot_mem.aot_load32(ctx.gpr[8] + static_cast<std::uint32_t>(4)));
    ctx.gpr[5] = (aot_mem.aot_load32(ctx.gpr[8] + static_cast<std::uint32_t>(0)));
    ctx.gpr[4] = (ctx.gpr[4] + static_cast<std::uint32_t>(8));
    aot_mem.aot_store32(ctx.gpr[8] + static_cast<std::uint32_t>(8), std::bit_cast<std::uint32_t>(ctx.fpr[13]));
    ctx.fpr[13] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(4)));
    ctx.gpr[4] = (ctx.gpr[5] + static_cast<std::uint32_t>(56));
    ctx.fpr[15] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(4)));
    ctx.gpr[5] = (ctx.gpr[7] | 0u);
    ctx.fpr[13] = ctx.fpr[15] + ctx.fpr[13];
    ctx.gpr[6] = (ctx.gpr[6] + static_cast<std::uint32_t>(64));
    ctx.gpr[4] = (0u | 0u);
    ctx.gpr[7] = (ctx.gpr[9] | 0u);
    aot_mem.aot_store32(ctx.gpr[8] + static_cast<std::uint32_t>(12), std::bit_cast<std::uint32_t>(ctx.fpr[13]));
    goto L_089C4AFC;
L_089C4AFC:
    ctx.fpr[13] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[6] + static_cast<std::uint32_t>(0)));
    ctx.fpr[15] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[5] + static_cast<std::uint32_t>(0)));
    { const float fs = ctx.fpr[13]; const float ft = ctx.fpr[14]; if ((std::isinf(fs) && ft == 0.0f) || (std::isinf(ft) && fs == 0.0f)) ctx.fpr[13] = std::bit_cast<float>(0x7FC00000u); else ctx.fpr[13] = fs * ft; }
    ctx.fpr[16] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[7] + static_cast<std::uint32_t>(8)));
    { const float fs = ctx.fpr[15]; const float ft = ctx.fpr[12]; if ((std::isinf(fs) && ft == 0.0f) || (std::isinf(ft) && fs == 0.0f)) ctx.fpr[15] = std::bit_cast<float>(0x7FC00000u); else ctx.fpr[15] = fs * ft; }
    ctx.gpr[4] = (ctx.gpr[4] + static_cast<std::uint32_t>(1));
    ctx.gpr[6] = (ctx.gpr[6] + static_cast<std::uint32_t>(4));
    ctx.gpr[5] = (ctx.gpr[5] + static_cast<std::uint32_t>(4));
    ctx.fpr[13] = ctx.fpr[13] + ctx.fpr[15];
    ctx.gpr[8] = (ctx.gpr[4] < static_cast<std::uint32_t>(2) ? 1u : 0u);
    ctx.fpr[16] = ctx.fpr[13] + ctx.fpr[16];
    aot_mem.aot_store32(ctx.gpr[7] + static_cast<std::uint32_t>(0), std::bit_cast<std::uint32_t>(ctx.fpr[16]));
    { const bool branch_taken = ctx.gpr[8] != 0u;
    ctx.gpr[7] = (ctx.gpr[7] + static_cast<std::uint32_t>(4));
      if (branch_taken) {
          goto L_089C4AFC;
      }
      goto L_089C4B34;
    }
L_089C4B34:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C4B3C:
    ctx.gpr[29] = (ctx.gpr[29] + static_cast<std::uint32_t>(-80));
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(60), std::bit_cast<std::uint32_t>(ctx.fpr[20]));
    ctx.fpr[20] = std::bit_cast<float>(std::bit_cast<std::uint32_t>(ctx.fpr[12]));
    ctx.gpr[7] = (16128u << 16u);
    ctx.fpr[12] = std::bit_cast<float>(std::bit_cast<std::uint32_t>(ctx.fpr[13]));
    ctx.fpr[13] = std::bit_cast<float>(ctx.gpr[7]);
    { const float fs = ctx.fpr[20]; const float ft = ctx.fpr[13]; if ((std::isinf(fs) && ft == 0.0f) || (std::isinf(ft) && fs == 0.0f)) ctx.fpr[14] = std::bit_cast<float>(0x7FC00000u); else ctx.fpr[14] = fs * ft; }
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(68), ctx.gpr[16]);
    ctx.gpr[16] = (ctx.gpr[4] | 0u);
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(64), std::bit_cast<std::uint32_t>(ctx.fpr[22]));
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(72), ctx.gpr[17]);
    ctx.gpr[17] = (ctx.gpr[5] | 0u);
    { const float fs = ctx.fpr[14]; const float ft = ctx.fpr[20]; if ((std::isinf(fs) && ft == 0.0f) || (std::isinf(ft) && fs == 0.0f)) ctx.fpr[22] = std::bit_cast<float>(0x7FC00000u); else ctx.fpr[22] = fs * ft; }
    ctx.gpr[4] = (ctx.gpr[6] | 0u);
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(76), ctx.gpr[31]);
    { const float fs = ctx.fpr[12]; const float ft = ctx.fpr[13]; if ((std::isinf(fs) && ft == 0.0f) || (std::isinf(ft) && fs == 0.0f)) ctx.fpr[13] = std::bit_cast<float>(0x7FC00000u); else ctx.fpr[13] = fs * ft; }
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(0), ctx.gpr[17]);
    ctx.gpr[8] = (ctx.gpr[17] + static_cast<std::uint32_t>(96));
    ctx.gpr[9] = (ctx.gpr[17] + static_cast<std::uint32_t>(100));
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(4), ctx.gpr[4]);
    ctx.gpr[5] = (ctx.gpr[16] + static_cast<std::uint32_t>(20));
    { const float fs = ctx.fpr[13]; const float ft = ctx.fpr[12]; if ((std::isinf(fs) && ft == 0.0f) || (std::isinf(ft) && fs == 0.0f)) ctx.fpr[13] = std::bit_cast<float>(0x7FC00000u); else ctx.fpr[13] = fs * ft; }
    ctx.gpr[6] = (ctx.gpr[16] + static_cast<std::uint32_t>(24));
    ctx.gpr[7] = (ctx.gpr[16] + static_cast<std::uint32_t>(28));
    ctx.gpr[10] = (ctx.gpr[4] + static_cast<std::uint32_t>(96));
    ctx.gpr[11] = (ctx.gpr[4] + static_cast<std::uint32_t>(100));
    ctx.gpr[2] = (ctx.gpr[8] | 0u);
    ctx.gpr[3] = (ctx.gpr[9] | 0u);
    ctx.gpr[12] = (0u | 0u);
    goto L_089C4BB0;
L_089C4BB0:
    ctx.fpr[14] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[7] + static_cast<std::uint32_t>(0)));
    ctx.fpr[15] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[6] + static_cast<std::uint32_t>(0)));
    ctx.fpr[16] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[11] + static_cast<std::uint32_t>(0)));
    { const float fs = ctx.fpr[14]; const float ft = ctx.fpr[12]; if ((std::isinf(fs) && ft == 0.0f) || (std::isinf(ft) && fs == 0.0f)) ctx.fpr[17] = std::bit_cast<float>(0x7FC00000u); else ctx.fpr[17] = fs * ft; }
    ctx.fpr[18] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[10] + static_cast<std::uint32_t>(0)));
    { const float fs = ctx.fpr[16]; const float ft = ctx.fpr[12]; if ((std::isinf(fs) && ft == 0.0f) || (std::isinf(ft) && fs == 0.0f)) ctx.fpr[16] = std::bit_cast<float>(0x7FC00000u); else ctx.fpr[16] = fs * ft; }
    ctx.fpr[19] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[5] + static_cast<std::uint32_t>(0)));
    ctx.fpr[0] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[2] + static_cast<std::uint32_t>(0)));
    ctx.fpr[17] = ctx.fpr[17] + ctx.fpr[15];
    ctx.fpr[16] = ctx.fpr[16] + ctx.fpr[18];
    { const float fs = ctx.fpr[14]; const float ft = ctx.fpr[13]; if ((std::isinf(fs) && ft == 0.0f) || (std::isinf(ft) && fs == 0.0f)) ctx.fpr[14] = std::bit_cast<float>(0x7FC00000u); else ctx.fpr[14] = fs * ft; }
    { const float fs = ctx.fpr[15]; const float ft = ctx.fpr[12]; if ((std::isinf(fs) && ft == 0.0f) || (std::isinf(ft) && fs == 0.0f)) ctx.fpr[15] = std::bit_cast<float>(0x7FC00000u); else ctx.fpr[15] = fs * ft; }
    ctx.fpr[16] = ctx.fpr[17] - ctx.fpr[16];
    ctx.fpr[14] = ctx.fpr[14] + ctx.fpr[15];
    ctx.fpr[16] = ctx.fpr[0] + ctx.fpr[16];
    aot_mem.aot_store32(ctx.gpr[6] + static_cast<std::uint32_t>(0), std::bit_cast<std::uint32_t>(ctx.fpr[16]));
    ctx.fpr[16] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[7] + static_cast<std::uint32_t>(0)));
    ctx.fpr[18] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[11] + static_cast<std::uint32_t>(0)));
    ctx.fpr[2] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[3] + static_cast<std::uint32_t>(0)));
    ctx.fpr[16] = ctx.fpr[16] - ctx.fpr[18];
    ctx.fpr[14] = ctx.fpr[14] + ctx.fpr[19];
    ctx.gpr[12] = (ctx.gpr[12] + static_cast<std::uint32_t>(1));
    ctx.fpr[15] = ctx.fpr[2] + ctx.fpr[16];
    ctx.gpr[10] = (ctx.gpr[10] + static_cast<std::uint32_t>(4));
    ctx.gpr[11] = (ctx.gpr[11] + static_cast<std::uint32_t>(4));
    aot_mem.aot_store32(ctx.gpr[7] + static_cast<std::uint32_t>(0), std::bit_cast<std::uint32_t>(ctx.fpr[15]));
    ctx.fpr[17] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[6] + static_cast<std::uint32_t>(0)));
    { const float fs = ctx.fpr[15]; const float ft = ctx.fpr[22]; if ((std::isinf(fs) && ft == 0.0f) || (std::isinf(ft) && fs == 0.0f)) ctx.fpr[15] = std::bit_cast<float>(0x7FC00000u); else ctx.fpr[15] = fs * ft; }
    { const float fs = ctx.fpr[17]; const float ft = ctx.fpr[20]; if ((std::isinf(fs) && ft == 0.0f) || (std::isinf(ft) && fs == 0.0f)) ctx.fpr[17] = std::bit_cast<float>(0x7FC00000u); else ctx.fpr[17] = fs * ft; }
    ctx.gpr[6] = (ctx.gpr[6] + static_cast<std::uint32_t>(4));
    ctx.gpr[7] = (ctx.gpr[7] + static_cast<std::uint32_t>(4));
    ctx.gpr[2] = (ctx.gpr[2] + static_cast<std::uint32_t>(4));
    ctx.fpr[15] = ctx.fpr[15] + ctx.fpr[17];
    ctx.gpr[3] = (ctx.gpr[3] + static_cast<std::uint32_t>(4));
    ctx.gpr[13] = (ctx.gpr[12] < static_cast<std::uint32_t>(1) ? 1u : 0u);
    ctx.fpr[14] = ctx.fpr[14] - ctx.fpr[15];
    aot_mem.aot_store32(ctx.gpr[5] + static_cast<std::uint32_t>(0), std::bit_cast<std::uint32_t>(ctx.fpr[14]));
    { const bool branch_taken = ctx.gpr[13] != 0u;
    ctx.gpr[5] = (ctx.gpr[5] + static_cast<std::uint32_t>(4));
      if (branch_taken) {
          goto L_089C4BB0;
      }
      goto L_089C4C4C;
    }
L_089C4C4C:
    ctx.gpr[5] = (0u | 0u);
    ctx.gpr[6] = (ctx.gpr[16] | 0u);
    goto L_089C4C54;
L_089C4C54:
    ctx.fpr[13] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[9] + static_cast<std::uint32_t>(0)));
    ctx.fpr[14] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[8] + static_cast<std::uint32_t>(0)));
    { const float fs = ctx.fpr[13]; const float ft = ctx.fpr[22]; if ((std::isinf(fs) && ft == 0.0f) || (std::isinf(ft) && fs == 0.0f)) ctx.fpr[13] = std::bit_cast<float>(0x7FC00000u); else ctx.fpr[13] = fs * ft; }
    ctx.fpr[15] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[6] + static_cast<std::uint32_t>(20)));
    { const float fs = ctx.fpr[14]; const float ft = ctx.fpr[20]; if ((std::isinf(fs) && ft == 0.0f) || (std::isinf(ft) && fs == 0.0f)) ctx.fpr[14] = std::bit_cast<float>(0x7FC00000u); else ctx.fpr[14] = fs * ft; }
    ctx.gpr[5] = (ctx.gpr[5] + static_cast<std::uint32_t>(1));
    ctx.gpr[9] = (ctx.gpr[9] + static_cast<std::uint32_t>(4));
    ctx.gpr[8] = (ctx.gpr[8] + static_cast<std::uint32_t>(4));
    ctx.fpr[13] = ctx.fpr[13] + ctx.fpr[14];
    ctx.gpr[7] = (ctx.gpr[5] < static_cast<std::uint32_t>(1) ? 1u : 0u);
    ctx.fpr[15] = ctx.fpr[13] + ctx.fpr[15];
    aot_mem.aot_store32(ctx.gpr[6] + static_cast<std::uint32_t>(16), std::bit_cast<std::uint32_t>(ctx.fpr[15]));
    { const bool branch_taken = ctx.gpr[7] != 0u;
    ctx.gpr[6] = (ctx.gpr[6] + static_cast<std::uint32_t>(4));
      if (branch_taken) {
          goto L_089C4C54;
      }
      goto L_089C4C8C;
    }
L_089C4C8C:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(8), ctx.gpr[17]);
    ctx.fpr[13] = std::bit_cast<float>(std::bit_cast<std::uint32_t>(ctx.fpr[12]));
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(12), ctx.gpr[16]);
    ctx.fpr[12] = std::bit_cast<float>(std::bit_cast<std::uint32_t>(ctx.fpr[20]));
    ctx.gpr[7] = (ctx.gpr[16] + static_cast<std::uint32_t>(32));
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(24), ctx.gpr[4]);
    ctx.gpr[5] = (ctx.gpr[29] + static_cast<std::uint32_t>(8));
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(28), ctx.gpr[16]);
    ctx.gpr[6] = (ctx.gpr[29] + static_cast<std::uint32_t>(24));
    ctx.gpr[31] = (0x089C4CB8u);
    ctx.gpr[4] = (ctx.gpr[7] | 0u);
    goto L_089C48D0;
L_089C4CB8:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(40), ctx.gpr[17]);
    ctx.gpr[4] = (ctx.gpr[17] + static_cast<std::uint32_t>(100));
    ctx.gpr[5] = (ctx.gpr[17] + static_cast<std::uint32_t>(96));
    ctx.gpr[6] = (0u | 0u);
    ctx.gpr[7] = (ctx.gpr[16] | 0u);
    goto L_089C4CCC;
L_089C4CCC:
    ctx.fpr[12] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(0)));
    ctx.fpr[13] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[5] + static_cast<std::uint32_t>(0)));
    { const float fs = ctx.fpr[12]; const float ft = ctx.fpr[22]; if ((std::isinf(fs) && ft == 0.0f) || (std::isinf(ft) && fs == 0.0f)) ctx.fpr[12] = std::bit_cast<float>(0x7FC00000u); else ctx.fpr[12] = fs * ft; }
    ctx.fpr[14] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[7] + static_cast<std::uint32_t>(20)));
    { const float fs = ctx.fpr[13]; const float ft = ctx.fpr[20]; if ((std::isinf(fs) && ft == 0.0f) || (std::isinf(ft) && fs == 0.0f)) ctx.fpr[13] = std::bit_cast<float>(0x7FC00000u); else ctx.fpr[13] = fs * ft; }
    ctx.gpr[6] = (ctx.gpr[6] + static_cast<std::uint32_t>(1));
    ctx.gpr[4] = (ctx.gpr[4] + static_cast<std::uint32_t>(4));
    ctx.gpr[5] = (ctx.gpr[5] + static_cast<std::uint32_t>(4));
    ctx.fpr[12] = ctx.fpr[12] + ctx.fpr[13];
    ctx.gpr[8] = (ctx.gpr[6] < static_cast<std::uint32_t>(1) ? 1u : 0u);
    ctx.fpr[14] = ctx.fpr[12] + ctx.fpr[14];
    aot_mem.aot_store32(ctx.gpr[7] + static_cast<std::uint32_t>(16), std::bit_cast<std::uint32_t>(ctx.fpr[14]));
    { const bool branch_taken = ctx.gpr[8] != 0u;
    ctx.gpr[7] = (ctx.gpr[7] + static_cast<std::uint32_t>(4));
      if (branch_taken) {
          goto L_089C4CCC;
      }
      goto L_089C4D04;
    }
L_089C4D04:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(44), ctx.gpr[17]);
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(48), ctx.gpr[16]);
    ctx.gpr[4] = (ctx.gpr[16] + static_cast<std::uint32_t>(8));
    ctx.gpr[6] = (ctx.gpr[17] + static_cast<std::uint32_t>(56));
    ctx.fpr[12] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(0)));
    ctx.fpr[13] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[6] + static_cast<std::uint32_t>(0)));
    ctx.gpr[7] = (ctx.gpr[16] + static_cast<std::uint32_t>(8));
    ctx.fpr[12] = ctx.fpr[13] + ctx.fpr[12];
    ctx.gpr[17] = (ctx.gpr[17] + static_cast<std::uint32_t>(64));
    ctx.gpr[4] = (ctx.gpr[29] + static_cast<std::uint32_t>(52));
    ctx.gpr[5] = (0u | 0u);
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(52), std::bit_cast<std::uint32_t>(ctx.fpr[12]));
    ctx.fpr[12] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[7] + static_cast<std::uint32_t>(4)));
    ctx.fpr[14] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[6] + static_cast<std::uint32_t>(4)));
    ctx.fpr[12] = ctx.fpr[14] + ctx.fpr[12];
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(56), std::bit_cast<std::uint32_t>(ctx.fpr[12]));
    goto L_089C4D44;
L_089C4D44:
    ctx.fpr[12] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[17] + static_cast<std::uint32_t>(0)));
    ctx.fpr[13] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(0)));
    { const float fs = ctx.fpr[12]; const float ft = ctx.fpr[22]; if ((std::isinf(fs) && ft == 0.0f) || (std::isinf(ft) && fs == 0.0f)) ctx.fpr[12] = std::bit_cast<float>(0x7FC00000u); else ctx.fpr[12] = fs * ft; }
    ctx.fpr[14] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[16] + static_cast<std::uint32_t>(40)));
    { const float fs = ctx.fpr[13]; const float ft = ctx.fpr[20]; if ((std::isinf(fs) && ft == 0.0f) || (std::isinf(ft) && fs == 0.0f)) ctx.fpr[13] = std::bit_cast<float>(0x7FC00000u); else ctx.fpr[13] = fs * ft; }
    ctx.gpr[5] = (ctx.gpr[5] + static_cast<std::uint32_t>(1));
    ctx.gpr[17] = (ctx.gpr[17] + static_cast<std::uint32_t>(4));
    ctx.gpr[4] = (ctx.gpr[4] + static_cast<std::uint32_t>(4));
    ctx.fpr[12] = ctx.fpr[12] + ctx.fpr[13];
    ctx.gpr[6] = (ctx.gpr[5] < static_cast<std::uint32_t>(2) ? 1u : 0u);
    ctx.fpr[14] = ctx.fpr[12] + ctx.fpr[14];
    aot_mem.aot_store32(ctx.gpr[16] + static_cast<std::uint32_t>(32), std::bit_cast<std::uint32_t>(ctx.fpr[14]));
    { const bool branch_taken = ctx.gpr[6] != 0u;
    ctx.gpr[16] = (ctx.gpr[16] + static_cast<std::uint32_t>(4));
      if (branch_taken) {
          goto L_089C4D44;
      }
      goto L_089C4D7C;
    }
L_089C4D7C:
    ctx.fpr[20] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(60)));
    ctx.fpr[22] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(64)));
    ctx.gpr[16] = (aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(68)));
    ctx.gpr[17] = (aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(72)));
    ctx.gpr[31] = (aot_mem.aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(76)));
    jump_target = ctx.gpr[31];
    ctx.gpr[29] = (ctx.gpr[29] + static_cast<std::uint32_t>(80));
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5468:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x027097D0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089C54A0:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x02709B90u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089C54D8:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x02709CC0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089C5508:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x02709E60u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089C5528:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x0270A060u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089C5540:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x0270ABC0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089C5550:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x0270AD70u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089C5560:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x0270AFA0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089C5570:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x0270B580u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089C55A8:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x0270B710u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089C55E0:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x02711F10u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089C55F8:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x02713940u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089C5630:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x02713A20u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089C5650:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x02713D70u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089C5688:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x02713EF0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089C56C0:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x02714010u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089C56E0:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x02714130u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089C5700:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x02714250u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089C5718:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x02714320u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089C5730:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x02714460u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089C5770:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5778:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5780:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5788:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5790:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5798:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C57A0:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C57A8:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C57B0:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C57B8:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C57C0:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C57C8:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C57D0:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C57D8:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C57E0:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C57E8:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C57F0:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C57F8:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5800:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5808:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5810:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5818:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5820:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5828:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5830:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5838:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5858:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5860:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5868:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5870:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5878:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5880:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5888:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5890:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5898:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C58A0:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C58A8:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C58C0:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C58C8:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C58D0: // sceFontGetNumFontList - return 0 (no fonts on PC)
    ctx.gpr[2] = 0u;
    jump_target = ctx.gpr[31];
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C58E0:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C58E8:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C58F0:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C58F8:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5900:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5908:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5910:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5918:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5928:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5930:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5938:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5940:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5948:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5950:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5958:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5960:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5968:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5970:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5978:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5980:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5988:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5990:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5998:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C59A0:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C59A8:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C59B0:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C59B8:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C59C0:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C59C8:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C59D0:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C59D8:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C59E0:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C59E8:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C59F0:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C59F8:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5A08:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5A10:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5A18:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5A20:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5A28:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5A30:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5A38:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5A40:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5A48: // sceGeListSync(listid, syncType) -> 0
    g_ge_list_start  = 0u;
    g_ge_exec_cursor = 0u;
      g_ge_stall_updates = 0u;
    ctx.gpr[2] = 0u;
    jump_target = ctx.gpr[31];
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5A50: // sceGeUnsetCallback(id) -> 0
    ctx.gpr[2] = 0u;
    jump_target = ctx.gpr[31];
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5A58: // sceGeListEnQueueHead(list, stall, cbid, arg) -> list_id
    { static std::uint32_t s_geqh = 0x80u;
      ctx.gpr[2] = s_geqh++;
    }
    jump_target = ctx.gpr[31];
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5A60: // sceGeEdramGetSize() -> 0x200000
    ctx.gpr[2] = 0x00200000u;
    jump_target = ctx.gpr[31];
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5A68: // sceGeContinue() -> 0
    ctx.gpr[2] = 0u;
    jump_target = ctx.gpr[31];
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5A70: // sceGeSetCallback(cb) -> 1
    ctx.gpr[2] = 1u;
    jump_target = ctx.gpr[31];
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5A78: // sceGeListEnQueue(list, stall, cbid, arg) -> list_id
    // Just record list start; execution happens at VCB/ListSync time
    { static std::uint32_t s_geq = 1u;
      const std::uint32_t list_phys  = ctx.gpr[4] & 0x1FFFFFFFu;
      const std::uint32_t stall_phys = ctx.gpr[5] & 0x1FFFFFFFu;
      g_ge_list_start    = list_phys;
      g_ge_exec_cursor   = list_phys;
      g_ge_stall_updates = 0u;
      g_ge_list_executed = false;
      ctx.gpr[2] = s_geq++;
    }
    jump_target = ctx.gpr[31];
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5A80: // sceGeDrawSync(syncType) -> 0
    ctx.gpr[2] = 0u;
    jump_target = ctx.gpr[31];
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5A88: // sceGeBreak(mode, pbresult) -> 0
    ctx.gpr[2] = 0u;
    jump_target = ctx.gpr[31];
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5A90: // sceGeListUpdateStallAddr(listid, stall) -> 0
    // Advance stall pointer and execute newly available DL commands
    { const std::uint32_t new_stall = ctx.gpr[5] & 0x1FFFFFFFu;
      extern std::uint32_t g_ge_list_start;
      extern std::uint32_t g_ge_exec_cursor;
      if (new_stall > g_ge_exec_cursor
          && (!kBackupRejectUnboundedGeLists || g_ge_stall_updates < 8u)
          && (!kBackupRejectUnboundedGeLists || new_stall - g_ge_exec_cursor <= 0x1000u)
          && g_ge_exec_cursor >= g_ge_list_start
          && rt.memory().contains(g_ge_exec_cursor, 4u)
          && rt.memory().contains(new_stall - 4u, 4u)) {
          const auto *dl_ptr = reinterpret_cast<const std::uint32_t *>(rt.memory().raw_pointer(g_ge_exec_cursor, 4u));
          const auto *dl_end = reinterpret_cast<const std::uint32_t *>(rt.memory().raw_pointer(new_stall, 4u));
          void *vram_ptr = rt.memory().raw_pointer(0x04000000u, 0x200000u);
          const auto &mem_vec = rt.memory().bytes();
          if (vram_ptr)
              d012::ge_exec(dl_ptr, dl_end, vram_ptr, 0x200000u, mem_vec.data(), mem_vec.size(), 0x08000000u);
          g_ge_exec_cursor = new_stall;
          ++g_ge_stall_updates;
      }
    }
    ctx.gpr[2] = 0u;
    jump_target = ctx.gpr[31];
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5A98: // sceGeEdramGetAddr() -> 0x04000000
    ctx.gpr[2] = 0x04000000u;
    jump_target = ctx.gpr[31];
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5AA0:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5AA8:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5AB0:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5AB8:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5AC0: // sceDisplaySetFrameBuf(buf, bufWidth, pixelFormat, sync)
    { const std::uint32_t buf_va   = ctx.gpr[4];
      const std::uint32_t buf_w    = ctx.gpr[5];
      const std::uint32_t fmt      = ctx.gpr[6];
      // Dump display list from the GE slot. DAT_09af6830 = current slot ptr (set by FUN_0899f5a4).
      // slot[2] = write cursor (advances as commands are emitted). slot[1] = start address.
      // The DL buffer address comes from DAT_089D5EC0[DAT_089D5EC0[0x8C0/4]].
      // Execute the current display list into VRAM before presenting.
      // Read the active DL slot from the GE queue (slot pointer at 0x09AF6830).
      // slot[+4] = DL start address, slot[+8] = current stall/end address.
      { static std::uint32_t s_frame = 0u;
        ++s_frame;
        const std::uint32_t slot_ptr_va = 0x09AF6830u;
        std::uint32_t dl_start = 0u, dl_end_addr = 0u;
        if (rt.memory().contains(slot_ptr_va, 4u)) {
            const std::uint32_t slot_ptr = rt.memory().load32(slot_ptr_va);
            if (slot_ptr && rt.memory().contains(slot_ptr, 12u)) {
                dl_start    = rt.memory().load32(slot_ptr + 4u) & 0x1FFFFFFFu;
                dl_end_addr = rt.memory().load32(slot_ptr + 8u) & 0x1FFFFFFFu;
            }
        }
        if (s_frame <= 5u || s_frame == 64u || (s_frame & 0x3Fu) == 0u) {
            const std::uint32_t len = dl_end_addr > dl_start ? (dl_end_addr - dl_start) / 4u : 0u;
            std::printf("[DL#%u] start=0x%08X end=0x%08X len=%u\n", s_frame, dl_start, dl_end_addr, len);
            // Dump ALL words (including bone) for first frames, skip bone for later
            if (dl_start && dl_end_addr > dl_start &&
                (!kBackupRejectUnboundedGeLists || dl_end_addr - dl_start <= 0x1000u)) {
                std::uint32_t shown = 0u;
                for (std::uint32_t _p = dl_start; _p < dl_end_addr && shown < 64u; _p += 4u) {
                    if (!rt.memory().contains(_p, 4u)) break;
                    const std::uint32_t _cmd = rt.memory().load32(_p);
                    const std::uint8_t _op = static_cast<std::uint8_t>(_cmd >> 24);
                    std::printf("  [+%04u] op=0x%02X arg=0x%06X\n", (_p-dl_start)/4u, _op, _cmd & 0xFFFFFFu);
                    ++shown;
                }
            }
        }
        // Execute the bone DL (slot-based)
        if (kBackupExecuteSlotLists && dl_start && dl_end_addr > dl_start
            && (!kBackupRejectUnboundedGeLists || dl_end_addr - dl_start <= 0x1000u)
            && rt.memory().contains(dl_start, 4u)
            && rt.memory().contains(dl_end_addr - 4u, 4u)) {
            const auto *dl_ptr = reinterpret_cast<const std::uint32_t *>(rt.memory().raw_pointer(dl_start, 4u));
            const auto *dl_end = reinterpret_cast<const std::uint32_t *>(rt.memory().raw_pointer(dl_end_addr, 4u));
            void *vram_ptr = rt.memory().raw_pointer(0x04000000u, 0x200000u);
            const auto &mem_vec = rt.memory().bytes();
            if (vram_ptr)
                d012::ge_exec(dl_ptr, dl_end, vram_ptr, 0x200000u, mem_vec.data(), mem_vec.size(), 0x08000000u);
        }
        // Diagnostic: check rendering gate flags
        if (s_frame <= 5u || s_frame == 64u) {
            auto read8 = [&](std::uint32_t va) -> std::uint8_t {
                return rt.memory().contains(va, 1u) ? static_cast<std::uint8_t>(rt.memory().load32(va & ~3u) >> (8*(va&3u))) : 0xFFu;
            };
            auto read32 = [&](std::uint32_t va) -> std::uint32_t {
                return rt.memory().contains(va, 4u) ? rt.memory().load32(va) : 0xDEADu;
            };
            std::printf("[GATE] frame=%u dc=%02X df=%02X dd=%02X d4=0x%08X cc=0x%08X 7f9c=%02X b49128=0x%08X\n",
                s_frame,
                read8(0x089D69DCu), read8(0x089D69DFu), read8(0x089D69DDu),
                read32(0x089D69D4u), read32(0x089D69CCu),
                read8(0x089D7F9Cu), read32(0x09B49128u));
        }
        // Also execute the rendering DL chain rooted at DAT_09af719c (0x09AF719C)
        // This is the JUMP-chained DL assembled by FUN_089ad370 that contains the actual PRIMs
        { const std::uint32_t render_chain_root_va = 0x09AF719Cu;
          if (rt.memory().contains(render_chain_root_va, 4u)) {
              const std::uint32_t node_ptr = rt.memory().load32(render_chain_root_va) & 0x1FFFFFFFu;
              const std::uint32_t raw_val  = rt.memory().load32(render_chain_root_va);
              if (s_frame <= 5u || s_frame == 64u) {
                  std::printf("[RENDER-CHAIN] raw=0x%08X node_ptr=0x%08X (from DAT_09af719c)\n", raw_val, node_ptr);
                  if (node_ptr && rt.memory().contains(node_ptr, 32u)) {
                      for (int _i = 0; _i < 8; ++_i)
                          std::printf("  node[%d]=0x%08X\n", _i, rt.memory().load32(node_ptr + _i*4u));
                  }
              }
              // Walk the node chain and execute each DL segment
              if (kBackupExecuteRenderChain && node_ptr && rt.memory().contains(node_ptr, 4u)) {
                  void *vram_ptr = rt.memory().raw_pointer(0x04000000u, 0x200000u);
                  const auto &mem_vec = rt.memory().bytes();
                  const std::uint32_t *node_dl = reinterpret_cast<const std::uint32_t *>(rt.memory().raw_pointer(node_ptr, 4u));
                  if (vram_ptr)
                      d012::ge_exec(node_dl, node_dl + 65536u, vram_ptr, 0x200000u, mem_vec.data(), mem_vec.size(), 0x08000000u);
              }
          }
        }
      }
      { // Present the framebuffer selected by the guest, as PPSSPP does.
          const auto &vram = rt.memory().vram_bytes();
          const d012::DisplayFbInfo &fb = d012::g_display_fb;
          const std::uint32_t vram_off = fb.vaddr & 0x1FFFFFu;
          const std::size_t stride = fb.stride > 0 ? fb.stride : buf_w;
          const std::size_t bpp = fb.fmt == 3 ? 4u : 2u;
          const std::size_t fb_bytes = stride * 272u * bpp;
          const std::uint8_t *fb_ptr = (vram_off + fb_bytes <= vram.size())
              ? vram.data() + vram_off : vram.data();
          std::printf("[display] guest framebuffer vaddr=0x%08X off=0x%X stride=%zu fmt=%d\n",
                      fb.vaddr, vram_off, stride, fb.fmt);
          d012::display_present(fb_ptr, static_cast<int>(stride), fb.fmt);
          d012::display_pump();
      }
    }
    ctx.gpr[2] = 0u;
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5AC8: // sceDisplayWaitVblankStartCB() — execute pending DL, present, wait 16ms
    { static std::uint32_t s_vcb_frame = 0u;
      ++s_vcb_frame;
      // Execute any pending (unexecuted) DL — game fills it between EnQueue and here
      if (kBackupExecuteSyntheticPendingList && !g_ge_list_executed && g_ge_list_start != 0u
          && rt.memory().contains(g_ge_list_start, 4u)) {
          const auto *dl_ptr = reinterpret_cast<const std::uint32_t *>(rt.memory().raw_pointer(g_ge_list_start, 4u));
          const std::uint32_t *dl_end = dl_ptr + 0x10000u;
          void *vram_ptr = rt.memory().raw_pointer(0x04000000u, 0x200000u);
          const auto &mem_vec = rt.memory().bytes();
          if (vram_ptr) {
              if (s_vcb_frame <= 5u) std::printf("[VCB-GE] frame=%u executing list=0x%08X\n", s_vcb_frame, g_ge_list_start);
              d012::ge_exec(dl_ptr, dl_end, vram_ptr, 0x200000u, mem_vec.data(), mem_vec.size(), 0x08000000u);
              g_ge_list_executed = true;
          }
      }
      // Also execute render chain from DAT_09AF719C (built each frame by FUN_089AD370)
      { const std::uint32_t render_chain_root_va = 0x09AF719Cu;
        if (rt.memory().contains(render_chain_root_va, 4u)) {
            const std::uint32_t node_ptr = rt.memory().load32(render_chain_root_va) & 0x1FFFFFFFu;
            if (s_vcb_frame <= 5u) std::printf("[VCB-CHAIN] frame=%u node_ptr=0x%08X\n", s_vcb_frame, node_ptr);
            if (kBackupExecuteRenderChain && node_ptr && rt.memory().contains(node_ptr, 4u)) {
                void *vram_ptr = rt.memory().raw_pointer(0x04000000u, 0x200000u);
                const auto &mem_vec = rt.memory().bytes();
                if (vram_ptr) {
                    const std::uint32_t *node_dl = reinterpret_cast<const std::uint32_t *>(rt.memory().raw_pointer(node_ptr, 4u));
                    d012::ge_exec(node_dl, node_dl + 0x10000u, vram_ptr, 0x200000u, mem_vec.data(), mem_vec.size(), 0x08000000u);
                }
            }
        }
      }
      // Also execute the GE slot DL (ring buffer)
      { const std::uint32_t slot_ptr_va = 0x09AF6830u;
        if (rt.memory().contains(slot_ptr_va, 4u)) {
            const std::uint32_t slot_ptr = rt.memory().load32(slot_ptr_va);
            if (slot_ptr && rt.memory().contains(slot_ptr, 12u)) {
                const std::uint32_t dl_start    = rt.memory().load32(slot_ptr + 4u) & 0x1FFFFFFFu;
                const std::uint32_t dl_end_addr = rt.memory().load32(slot_ptr + 8u) & 0x1FFFFFFFu;
                if (kBackupExecuteSlotLists && dl_start && dl_end_addr > dl_start
                    && (!kBackupRejectUnboundedGeLists || dl_end_addr - dl_start <= 0x1000u)
                    && rt.memory().contains(dl_start, 4u) && rt.memory().contains(dl_end_addr - 4u, 4u)) {
                    void *vram_ptr = rt.memory().raw_pointer(0x04000000u, 0x200000u);
                    const auto &mem_vec = rt.memory().bytes();
                    if (vram_ptr) {
                        if (s_vcb_frame <= 5u) std::printf("[VCB-SLOT] frame=%u slot_dl=0x%08X..0x%08X\n", s_vcb_frame, dl_start, dl_end_addr);
                        const auto *dl_ptr = reinterpret_cast<const std::uint32_t *>(rt.memory().raw_pointer(dl_start, 4u));
                        const auto *dl_end = reinterpret_cast<const std::uint32_t *>(rt.memory().raw_pointer(dl_end_addr, 4u));
                        d012::ge_exec(dl_ptr, dl_end, vram_ptr, 0x200000u, mem_vec.data(), mem_vec.size(), 0x08000000u);
                    }
                }
            }
        }
      }
      g_ge_list_start = 0u; // consumed
      // ARCH-SYNTH: once scene 0x2713 (Square Enix logo) is in pending list but not yet active,
      // restore the runtime-corrupted vtable at 0x089CAC90 and call FUN_088A2664(0.0f, 0x2713).
      // The vtable at 0x089CAC90 gets overwritten by pool/BSS data at runtime; we restore it
      // from the ELF (verified at file offset 0x1C7C68) before dispatching.
      { constexpr bool kBackupSceneActivation = true;
        // Keep disabled until the scene manager's render callback chain is
        // reconstructed; enabling it promotes an incomplete node and causes
        // unbounded malformed GE lists.
        constexpr bool kBackupScenePromotion = false;
        static bool s_scene_done=false;
        if (kBackupSceneActivation && !s_scene_done) {
            const std::uint32_t pending = aot_mem.aot_load32(0x09B4CF98u);
            if (pending != 0u && aot_mem.aot_load32(0x09B48358u) == 0u) {
                // Restore vtable at 0x089CAC90 from ELF values
                constexpr std::uint32_t vt = 0x089CAC90u;
                aot_mem.aot_store32(vt+0x00u, 0x00000000u);
                aot_mem.aot_store32(vt+0x04u, 0x00000000u);
                aot_mem.aot_store32(vt+0x08u, 0x00000000u);
                aot_mem.aot_store32(vt+0x0Cu, 0x088A1C74u);
                aot_mem.aot_store32(vt+0x10u, 0x00000000u);
                aot_mem.aot_store32(vt+0x14u, 0x088A310Cu);
                aot_mem.aot_store32(vt+0x18u, 0x00000000u);
                aot_mem.aot_store32(vt+0x1Cu, 0x088A3188u);
                aot_mem.aot_store32(vt+0x20u, 0x00000000u);
                aot_mem.aot_store32(vt+0x24u, 0x088A31ACu);
                aot_mem.aot_store32(vt+0x28u, 0x00000000u);
                aot_mem.aot_store32(vt+0x2Cu, 0x088A31D4u);
                aot_mem.aot_store32(vt+0x30u, 0x00000000u);
                aot_mem.aot_store32(vt+0x34u, 0x088A31FCu);
                aot_mem.aot_store32(vt+0x38u, 0x00000000u);
                aot_mem.aot_store32(vt+0x3Cu, 0x088A3224u);
                aot_mem.aot_store32(vt+0x40u, 0x00000000u);
                aot_mem.aot_store32(vt+0x44u, 0x088A3248u);
                aot_mem.aot_store32(vt+0x48u, 0x00000000u);
                aot_mem.aot_store32(vt+0x4Cu, 0x088A3254u);
                std::printf("[SCENE-ACT] pending=0x%08X vtable restored, calling FUN_088A2664\n",
                            pending); fflush(stdout);
                // Repair scene node fields in case FUN_088A2024 didn't run (cross-unit chain miss).
                // These are the exact values FUN_088A2024 writes for a fresh node.
                // The animation dispatcher indexes a two-entry callback
                // table with this field; although FUN_088A2024 initializes
                // it as a float in the original object, the reconstructed
                // scene must use a valid table index here.
                aot_mem.aot_store32(pending + 0x18u, 0u);
                aot_mem.aot_store32(pending + 0x1Cu, 0x41A00000u); // float 20.0
                aot_mem.aot_store32(pending + 0x20u, 0x3F800000u); // float 1.0
                aot_mem.aot_store32(pending + 0x24u, 0x3F800000u); // float 1.0
                aot_mem.aot_store32(pending + 0x28u, 0x00000000u);
                // Backup activation enters FUN_088A1E44 in its transition
                // state. State 0 only advances to 2 and deliberately does
                // not invoke the scene vtable.
                aot_mem.aot_store32(pending + 0x30u, 0x00000001u); // state = 1
                aot_mem.aot_store32(pending + 0x34u, 0x000002F0u);
                aot_mem.aot_store32(pending + 0x38u, 0xBF800000u); // float -1.0
                aot_mem.aot_store32(pending + 0x3Cu, 0x00000000u);
                aot_mem.aot_store32(pending + 0x40u, 0x00000000u);
                aot_mem.aot_store32(pending + 0x44u, 0x00000000u);
                aot_mem.aot_store32(pending + 0x48u, 0x00000000u);
                aot_mem.aot_store32(pending + 0x54u, 0x00000000u);
                // FUN_088A1E44 obtains the scene callback object from node+0x50,
                // then reads its vtable pointer.  The partial archive path left
                // this descriptor unset, so the state machine could never reach
                // the ELF scene callbacks even though the node was promoted.
                constexpr std::uint32_t scene_desc = 0x09FE0200u;
                aot_mem.aot_store32(scene_desc + 0x00u, 0x089CAC90u);
                aot_mem.aot_store32(scene_desc + 0x04u, 0x00002713u);
                aot_mem.aot_store32(scene_desc + 0x08u, 0xFFFFFFFFu);
                aot_mem.aot_store32(scene_desc + 0x0Cu, 0x00000001u);
                aot_mem.aot_store32(scene_desc + 0x10u, 0x00000000u);
                aot_mem.aot_store16(scene_desc + 0x18u, 0u);
                aot_mem.aot_store32(pending + 0x50u, scene_desc);
                std::printf("[SCENE-DESC] desc=0x%08X vt=0x%08X type=0x%08X res=0x%08X\n",
                    scene_desc, aot_mem.aot_load32(scene_desc), aot_mem.aot_load32(scene_desc+4u),
                    aot_mem.aot_load32(scene_desc+8u)); fflush(stdout);
                std::printf("[SCENE-ACT] node fields repaired, calling FUN_088A2664\n"); fflush(stdout);
                const std::uint32_t save_ra  = ctx.gpr[31];
                const std::uint32_t save_a0  = ctx.gpr[4];
                const float         save_f12 = ctx.fpr[12];
                ctx.fpr[12] = 0.0f;
                // FUN_088A2664(0, 0x2713): $a0 is the float/transition
                // parameter and must be zero; do not inherit the caller's
                // stale value (which can dispatch an invalid scene path).
                ctx.gpr[4]  = 0u;
                ctx.gpr[5]  = 0x2713u;
                ctx.gpr[31] = 0x089C5B00u;
                ctx.pc      = 0x088A2664u;
                (void)rt.invoke_chained_direct<&recomp_unit_0004_entry, 4u, 5051u, 0x088A2664u>(ctx, &aot_mem);
                ctx.gpr[31] = save_ra;
                ctx.gpr[4]  = save_a0;
                ctx.fpr[12] = save_f12;
                // The generated FUN_088A2664 currently exits before its
                // indirect vtable dispatch. Continue through the original
                // guest callback so the scene can perform its real resource
                // setup; this is not a renderer or host-side image path.
                if (aot_mem.aot_load32(0x09B48358u) == 0u) {
                    std::printf("[SCENE-FALLBACK] dispatching original 0x088A3188 guest callback\n"); fflush(stdout);
                    ctx.gpr[4] = scene_desc;
                    ctx.gpr[5] = 0u;
                    ctx.gpr[31] = 0x089C5B00u;
                    ctx.pc = 0x088A3188u;
                    (void)rt.invoke_chained_call(ctx, &aot_mem);
                    ctx.gpr[31] = save_ra;
                    ctx.gpr[4] = save_a0;
                }
                std::printf("[SCENE-ACT] done, active=0x%08X\n",
                            aot_mem.aot_load32(0x09B48358u)); fflush(stdout);
                // The generated scene-manager path can complete without
                // updating the active-root global in this partial port. Keep
                // this promotion independently switchable for rollback.
                if (kBackupScenePromotion &&
                    aot_mem.aot_load32(0x09B48358u) == 0u &&
                    aot_mem.aot_load32(pending + 0x58u) == 0u) {
                    aot_mem.aot_store32(0x09B48358u, pending);
                    aot_mem.aot_store32(0x09B4835Cu, pending);
                    aot_mem.aot_store32(0x09B4CF98u, 0u);
                    aot_mem.aot_store32(0x09B4CF9Cu, 0u);
                    std::printf("[SCENE-ACT] backup promotion active=0x%08X\n",
                                pending); fflush(stdout);
                }
                s_scene_done = true;
            }
        }
      }
      // Present: use the framebuffer address set by sceDisplaySetFrameBuf.
      { const auto &vram = rt.memory().vram_bytes();
        const d012::DisplayFbInfo &fb = d012::g_display_fb;
        // fb.vaddr is a PSP virtual address (0x04000000 base for VRAM).
        const std::uint32_t vram_off = fb.vaddr & 0x1FFFFFu; // VRAM-relative offset
        const std::size_t stride = (fb.stride > 0) ? fb.stride : 512u;
        const std::size_t bpp    = (fb.fmt == 3) ? 4u : 2u;
        const std::size_t fb_bytes = stride * 272u * bpp;
        if (s_vcb_frame <= 5u)
            std::printf("[VCB-PRESENT] frame=%u vaddr=0x%08X off=0x%X stride=%zu fmt=%d\n",
                        s_vcb_frame, fb.vaddr, vram_off, stride, fb.fmt);
        const std::uint8_t *fb_ptr = (vram_off + fb_bytes <= vram.size())
            ? vram.data() + vram_off : vram.data();
        d012::display_present(fb_ptr, static_cast<int>(stride), fb.fmt);
      }
      static auto s_vblank_cb_start = std::chrono::steady_clock::now();
      const auto now = std::chrono::steady_clock::now();
      const auto us_elapsed = std::chrono::duration_cast<std::chrono::microseconds>(now - s_vblank_cb_start).count();
      const std::int64_t us_per_frame = 16667;
      const std::int64_t frames_passed = us_elapsed / us_per_frame;
      const auto next_vblank = s_vblank_cb_start + std::chrono::microseconds((frames_passed + 1) * us_per_frame);
      while (std::chrono::steady_clock::now() < next_vblank) { /* spin */ }
      d012::display_pump();
    }
    ctx.gpr[2] = 0u;
    jump_target = ctx.gpr[31];
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5AD0: // sceDisplayWaitVblankStart() — wait until next 16ms boundary, execute DL, present
    { static auto s_vblank_start = std::chrono::steady_clock::now();
      static std::uint32_t s_vblank_frame = 0u;
      ++s_vblank_frame;
      // Execute the render-chain DL rooted at DAT_09AF719C (built each frame by FUN_089AD370).
      // This must happen at vsync time, AFTER the game has finished filling the DL.
      { const std::uint32_t render_chain_root_va = 0x09AF719Cu;
        if (rt.memory().contains(render_chain_root_va, 4u)) {
            const std::uint32_t node_ptr = rt.memory().load32(render_chain_root_va) & 0x1FFFFFFFu;
            if (s_vblank_frame <= 5u)
                std::printf("[VSYNC-DL] frame=%u node_ptr=0x%08X\n", s_vblank_frame, node_ptr);
            if (kBackupExecuteRenderChain && node_ptr && rt.memory().contains(node_ptr, 4u)) {
                void *vram_ptr = rt.memory().raw_pointer(0x04000000u, 0x200000u);
                const auto &mem_vec = rt.memory().bytes();
                if (vram_ptr) {
                    const std::uint32_t *node_dl = reinterpret_cast<const std::uint32_t *>(
                        rt.memory().raw_pointer(node_ptr, 4u));
                    d012::ge_exec(node_dl, node_dl + 65536u, vram_ptr, 0x200000u,
                                  mem_vec.data(), mem_vec.size(), 0x04000000u);
                }
            }
        }
      }
      // Also run the GE slot DL (ring buffer cursor-based).
      { extern std::uint32_t g_ge_list_start;
        extern std::uint32_t g_ge_exec_cursor;
        const std::uint32_t slot_ptr_va = 0x09AF6830u;
        if (rt.memory().contains(slot_ptr_va, 4u)) {
            const std::uint32_t slot_ptr = rt.memory().load32(slot_ptr_va);
            if (slot_ptr && rt.memory().contains(slot_ptr, 12u)) {
                const std::uint32_t dl_start    = rt.memory().load32(slot_ptr + 4u) & 0x1FFFFFFFu;
                const std::uint32_t dl_end_addr = rt.memory().load32(slot_ptr + 8u) & 0x1FFFFFFFu;
                if (dl_start && dl_end_addr > dl_start
                    && (!kBackupRejectUnboundedGeLists || dl_end_addr - dl_start <= 0x1000u)
                    && rt.memory().contains(dl_start, 4u)
                    && rt.memory().contains(dl_end_addr - 4u, 4u)) {
                    void *vram_ptr = rt.memory().raw_pointer(0x04000000u, 0x200000u);
                    const auto &mem_vec = rt.memory().bytes();
                    if (vram_ptr) {
                        const auto *dl_ptr = reinterpret_cast<const std::uint32_t *>(
                            rt.memory().raw_pointer(dl_start, 4u));
                        const auto *dl_end = reinterpret_cast<const std::uint32_t *>(
                            rt.memory().raw_pointer(dl_end_addr, 4u));
                        d012::ge_exec(dl_ptr, dl_end, vram_ptr, 0x200000u,
                                      mem_vec.data(), mem_vec.size(), 0x04000000u);
                    }
                }
            }
        }
      }
      // Present using the framebuffer set by sceDisplaySetFrameBuf.
      { const auto &vram = rt.memory().vram_bytes();
        const d012::DisplayFbInfo &fb = d012::g_display_fb;
        const std::uint32_t vram_off = fb.vaddr & 0x1FFFFFu;
        const std::size_t stride = (fb.stride > 0) ? fb.stride : 512u;
        const std::size_t bpp    = (fb.fmt == 3) ? 4u : 2u;
        const std::size_t fb_bytes = stride * 272u * bpp;
        if (s_vblank_frame <= 5u)
            std::printf("[VSYNC-PRESENT] frame=%u vaddr=0x%08X off=0x%X stride=%zu fmt=%d\n",
                        s_vblank_frame, fb.vaddr, vram_off, stride, fb.fmt);
        const std::uint8_t *fb_ptr = (vram_off + fb_bytes <= vram.size())
            ? vram.data() + vram_off : vram.data();
        d012::display_present(fb_ptr, static_cast<int>(stride), fb.fmt);
      }
      // Wait for the next 16ms boundary.
      const auto now = std::chrono::steady_clock::now();
      const auto us_elapsed = std::chrono::duration_cast<std::chrono::microseconds>(now - s_vblank_start).count();
      const std::int64_t us_per_frame = 16667;
      const std::int64_t frames_passed = us_elapsed / us_per_frame;
      const auto next_vblank = s_vblank_start + std::chrono::microseconds((frames_passed + 1) * us_per_frame);
      while (std::chrono::steady_clock::now() < next_vblank) { /* spin */ }
      d012::display_pump();
    }
    ctx.gpr[2] = 0u;
    jump_target = ctx.gpr[31];
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5AD8: // sceDisplayGetVcount() -> vblank count since program start
    { static auto s_vc_start = std::chrono::steady_clock::now();
      const auto now = std::chrono::steady_clock::now();
      const auto us = std::chrono::duration_cast<std::chrono::microseconds>(now - s_vc_start).count();
      ctx.gpr[2] = static_cast<std::uint32_t>(us / 16667u);
    }
    jump_target = ctx.gpr[31];
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5AE0: // sceDisplaySetMode(mode, width, height)
    { static bool s_once = false; if (!s_once) { s_once = true;
          std::printf("[DISPLAY] sceDisplaySetMode mode=%u w=%u h=%u\n",
                      ctx.gpr[4], ctx.gpr[5], ctx.gpr[6]); } }
    ctx.gpr[2] = 0u;
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5AE8:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5AF0:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5AF8:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5B00:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5B08:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5B10:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5B18:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5B20:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5B28:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5B30:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5B38:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5B40:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5B48:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5B50:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5B58:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5B60:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5B68:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5B70:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5B78:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5B80:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5B88:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5B90:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5B98:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5BA0:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5BA8:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5BB0:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5BB8:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5BC0: // sceUmdGetDriveStat() -> PSP_UMD_PRESENT(0x20) | PSP_UMD_READY(0x40) | PSP_UMD_READABLE(0x01)
    ctx.gpr[2] = 0x61u; // PSP_UMD_PRESENT|PSP_UMD_READY|PSP_UMD_READABLE (disc always present)
    jump_target = ctx.gpr[31];
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5BC8:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5BD0:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5BD8:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5BE0:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5C00:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5C08:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5C10:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5C18:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5C20:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5C30:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5C38:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5C40:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5C48:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5C50:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5C60:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5C70:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5C88:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5C98:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5CA0:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5CB8:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5CC0:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5CC8:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5CD0:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5CD8:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5CE0:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5CE8:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5CF0:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5CF8:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5D00:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5D08:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5D18: // scesupPreAcc_NID_13AE25B3 - stub returns 0 (accessibility PRX not loaded)
    { static bool once=false; if(!once){once=true; std::printf("[HLE] scesupPreAcc NID_13AE25B3 -> 0\n"); fflush(stdout);} }
    ctx.gpr[2] = 0u;
    jump_target = ctx.gpr[31];
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5D20:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5D30: // scesupPreAcc_NID_348BA3E2 - stub returns 0
    { static bool once=false; if(!once){once=true; std::printf("[HLE] scesupPreAcc NID_348BA3E2 -> 0\n"); fflush(stdout);} }
    ctx.gpr[2] = 0u;
    jump_target = ctx.gpr[31];
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5D38: // scesupPreAcc_NID_86DEBD66 - stub returns 0
    { static bool once=false; if(!once){once=true; std::printf("[HLE] scesupPreAcc NID_86DEBD66 -> 0\n"); fflush(stdout);} }
    ctx.gpr[2] = 0u;
    jump_target = ctx.gpr[31];
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5D48:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5D50:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5D58:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5D60:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5D68:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5D70:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5D78:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5D80:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5D88:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5D90:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5D98:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5DA0:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5DA8:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5DB0:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5DB8:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5DC0:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5DC8:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5DD0:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5DD8:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5DE0:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5E00:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5E10:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5E18:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5E20:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5E30: // sceIoRead(fd, buf_va, size) -> bytes read
    std::printf("[SCE-IO-READ] fd=0x%08X buf=0x%08X size=0x%08X\n", ctx.gpr[4], ctx.gpr[5], ctx.gpr[6]);
    std::fflush(stdout);
    { const std::uint32_t fd   = ctx.gpr[4];
      const std::uint32_t buf_va = ctx.gpr[5];
      const std::uint32_t size = ctx.gpr[6];
      std::vector<std::uint8_t> tmp(size);
      const std::int32_t n = d012::io_read(fd, tmp.data(), size);
      if (n > 0) rt.memory().copy_in(buf_va, std::span<const std::uint8_t>(tmp.data(), static_cast<std::size_t>(n)));
      ctx.gpr[2] = static_cast<std::uint32_t>(n);
    }
    jump_target = ctx.gpr[31];
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5E38:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5E40:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5E48: // sceIoClose(fd) -> 0
    ctx.gpr[2] = static_cast<std::uint32_t>(d012::io_close(ctx.gpr[4]));
    jump_target = ctx.gpr[31];
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5E50:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5E58:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5E60:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5E68:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5E70:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5E78:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5E80:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5E88:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5E90: // sceIoWaitAsync(fd, res_ptr) -> 0
    { const std::uint32_t res_ptr = ctx.gpr[5];
      if (res_ptr && rt.memory().contains(res_ptr, 8u)) {
          rt.memory().store32(res_ptr,      0u);
          rt.memory().store32(res_ptr + 4u, 0u);
      }
    }
    ctx.gpr[2] = 0u;
    jump_target = ctx.gpr[31];
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5E98:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5EA0:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5EA8: // sceIoOpen(path, flags, mode) -> fd or error
    {
        static std::uint32_t trace_open = 0u;
        if (++trace_open <= 4u) {
            std::printf("[IO-OPEN-GUEST] path=0x%08X flags=0x%08X mode=0x%08X ra=0x%08X\n",
                        ctx.gpr[4], ctx.gpr[5], ctx.gpr[6], ctx.gpr[31]);
            std::fflush(stdout);
        }
    }
    ctx.gpr[2] = d012::io_open(rt.memory().read_c_string(ctx.gpr[4]), ctx.gpr[5]);
    {
        static std::uint32_t trace_open_ret = 0u;
        if (++trace_open_ret <= 4u) {
            std::printf("[IO-OPEN-GUEST-RET] fd=%u ra=0x%08X\n", ctx.gpr[2], ctx.gpr[31]);
            std::fflush(stdout);
        }
    }
    jump_target = ctx.gpr[31];
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5EB0:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5EB8: // sceIoLseek(fd, offset_hi, offset_lo, whence) -> new pos (64-bit in v1:v0)
    { const std::int64_t offset = (static_cast<std::int64_t>(ctx.gpr[5]) << 32) | ctx.gpr[6];
      const std::int64_t pos = d012::io_lseek(ctx.gpr[4], offset, ctx.gpr[7]);
      ctx.gpr[2] = static_cast<std::uint32_t>(pos & 0xFFFFFFFFu);
      ctx.gpr[3] = static_cast<std::uint32_t>((static_cast<std::uint64_t>(pos) >> 32) & 0xFFFFFFFFu);
    }
    jump_target = ctx.gpr[31];
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5EC8: // sceIoPollAsync(fd, res_ptr) -> 0
    { const std::uint32_t res_ptr = ctx.gpr[5];
      if (res_ptr && rt.memory().contains(res_ptr, 8u)) {
          rt.memory().store32(res_ptr,      0u);
          rt.memory().store32(res_ptr + 4u, 0u);
      }
    }
    ctx.gpr[2] = 0u;
    jump_target = ctx.gpr[31];
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5ED0:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5ED8:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5EE0:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5EE8:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5EF0: // sceKernelExitGame() -> noreturn
    std::printf("[HLE] sceKernelExitGame\n");
    rt.stop("sceKernelExitGame");
    return;
L_089C5EF8: // sceKernelRegisterExitCallback(uid) -> 0
    ctx.gpr[2] = 0u;
    jump_target = ctx.gpr[31];
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5F00:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5F08:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5F10:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5F18:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5F20:
    // sceKernelGetMemoryBlockAddr(uid, addr_out): resolve the guest heap
    // block created by sceKernelAllocMemoryBlock and write its address.
    if (ctx.gpr[5] != 0u) {
        aot_mem.aot_store32(ctx.gpr[5], d012::hle_get_addr(ctx.gpr[4]));
    }
    ctx.gpr[2] = 0u;
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5F28:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5F30:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5F38:
    // sceKernelAllocMemoryBlock(name, type, size, params).
    ctx.gpr[2] = d012::hle_alloc(ctx.gpr[6]);
    if (ctx.gpr[2] == 0u) ctx.gpr[2] = 0xFFFFFFFFu;
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5F40:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5F48: {
    const std::uint32_t _uid = d012::hle_alloc(ctx.gpr[7]);
    ctx.gpr[2] = _uid ? _uid : ~0u;
    jump_target = ctx.gpr[31];
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
}
L_089C5F50:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5F58: {
    const std::uint32_t _uid58 = ctx.gpr[4];
    ctx.gpr[2]  = d012::hle_get_addr(_uid58);
    ctx.gpr[17] = d012::hle_alloc_size();
    jump_target = ctx.gpr[31];
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
}
L_089C5F60:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5F68:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5F70: // sceKernelCreateSema(name, attr, initVal, maxVal, opt) -> uid
    ctx.gpr[2] = d012::hle_create_sema(ctx.gpr[6]);
    jump_target = ctx.gpr[31];
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5F78:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5F80: // sceKernelCreateCallback(name, func, arg) -> uid
    ctx.gpr[2] = d012::hle_create_callback(ctx.gpr[5]);
    jump_target = ctx.gpr[31];
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5F88:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5F90:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5F98:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5FA0: // sceKernelStartThread(uid, arglen, argp) -> 0
    d012::hle_start_thread(ctx.gpr[4], ctx.gpr[5], ctx.gpr[6]);
    ctx.gpr[2] = 0u;
    jump_target = ctx.gpr[31];
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5FA8:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5FB0:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5FB8: // sceKernelGetSystemTimeLow() -> microseconds since start (32-bit)
    { static const auto s_ktsl_start = std::chrono::steady_clock::now();
      const auto now = std::chrono::steady_clock::now();
      const auto us  = std::chrono::duration_cast<std::chrono::microseconds>(now - s_ktsl_start).count();
      ctx.gpr[2] = static_cast<std::uint32_t>(us & 0xFFFFFFFFu);
    }
    jump_target = ctx.gpr[31];
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5FC0: // sceKernelSignalSema(uid, signal) -> 0
    d012::hle_signal_sema(ctx.gpr[4], ctx.gpr[5]);
    ctx.gpr[2] = 0u;
    jump_target = ctx.gpr[31];
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5FC8:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5FD0: // sceKernelCreateThread(name, entry, priority, stackSize, attr, opt) -> uid
    ctx.gpr[2] = d012::hle_create_thread(ctx.gpr[5], ctx.gpr[6], ctx.gpr[7]);
    jump_target = ctx.gpr[31];
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5FD8:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5FE0: // sceKernelCreateEventFlag(name, attr, bits, opt) -> uid
    ctx.gpr[2] = d012::hle_create_event_flag();
    jump_target = ctx.gpr[31];
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5FE8:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5FF0:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C5FF8:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C6000: // sceKernelExitDeleteThread(status) -> noreturn
    { static std::uint32_t s_exit_count = 0u;
      if (++s_exit_count <= 2u)
          std::printf("[HLE] sceKernelExitDeleteThread(%d) — yielding to main loop\n",
                      static_cast<std::int32_t>(ctx.gpr[4]));
      // The PSP game calls this to end the current "phase" and yield back to the OS.
      // On our host, the main loop at L_08804278 -> L_08804280 -> L_08804270 drives frames.
      // Return normally so invoke_chained_direct succeeds and the loop continues.
      ctx.gpr[2] = 0u; // return value = 0 (success)
      jump_target = ctx.gpr[31]; // return to caller (L_08804280)
      ctx.pc = jump_target;
      local_pc = jump_target;
      if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    }
    return;
L_089C6010:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C6018:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C6020:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C6028:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C6030: // sceKernelExitThread(status) -> noreturn
    std::printf("[HLE] sceKernelExitThread(%d)\n", static_cast<std::int32_t>(ctx.gpr[4]));
    rt.stop("sceKernelExitThread");
    return;
L_089C6040:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C6050:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C6058:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C6060:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C6070:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C6078:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C6080:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C6088:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C6090:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C6098: // sceKernelVolatileMemLock(mode, paddr_out, psize_out) -> 0
    { // PSP volatile memory (ME SRAM): expose a 32KB block in low RAM.
      // Write address and size into the caller's out-pointers.
      const std::uint32_t vol_addr = 0x00010000u; // safe low-RAM region
      const std::uint32_t vol_size = 0x00008000u; // 32 KB
      const std::uint32_t p_addr_out = ctx.gpr[5]; // pointer to store address
      const std::uint32_t p_size_out = ctx.gpr[6]; // pointer to store size
      std::printf("[VMEM] VolatileMemLock: mode=%u p_addr=0x%08X p_size=0x%08X\n",
                  ctx.gpr[4], p_addr_out, p_size_out);
      if (p_addr_out && rt.memory().contains(p_addr_out, 4u))
          rt.memory().store32(p_addr_out, vol_addr);
      if (p_size_out && rt.memory().contains(p_size_out, 4u))
          rt.memory().store32(p_size_out, vol_size);
      ctx.gpr[2] = 0u; // success
    }
    jump_target = ctx.gpr[31];
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C60A0:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C60A8:
    jump_target = ctx.gpr[31];
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C60B0:
    // nop
    ctx.pc = 0x0202A680u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089C63F8:
    rt.unsupported(0x089C63F8u, 0x736F706Du, "unknown not lowered yet"); return;
L_089C640C:
    rt.unsupported(0x089C640Cu, 0x00000036u, "special? not lowered yet"); return;
L_089C645C:
    rt.unsupported(0x089C645Cu, 0x00000036u, "special? not lowered yet"); return;
L_089C64C0:
    ctx.execute_vfpu_compare3(110u, 100u, 70u, 1u, 6u);
    ctx.execute_vfpu_vscl_ct<114u, 85u, 115u, 1u>();
    rt.unsupported(0x089C64C8u, 0x00000072u, "special? not lowered yet"); return;
L_089C64DC:
    ctx.gpr[15] = (aot_mem.aot_load8(ctx.gpr[31] + static_cast<std::uint32_t>(14403)));
    rt.unsupported(0x089C64E0u, 0xB58E61B7u, "unknown not lowered yet"); return;
L_089C6500:
    ctx.gpr[29] = (aot_mem.aot_load16(ctx.gpr[27] + static_cast<std::uint32_t>(-7290)));
    rt.unsupported(0x089C6504u, 0xD1FF982Au, "vfpu4 not lowered yet"); return;
L_089C6548:
    ctx.gpr[20] = (rt.memory().aot_load_word_left(ctx.gpr[3] + static_cast<std::uint32_t>(-9248), ctx.gpr[20]));
    ctx.gpr[28] = (aot_mem.aot_load16(ctx.gpr[15] + static_cast<std::uint32_t>(9531)));
    ctx.gpr[16] = (aot_mem.aot_load16(ctx.gpr[28] + static_cast<std::uint32_t>(-19652)));
    ctx.gpr[28] = (rt.memory().aot_load_word_right(ctx.gpr[16] + static_cast<std::uint32_t>(-28201), ctx.gpr[28]));
    aot_mem.aot_store16(ctx.gpr[14] + static_cast<std::uint32_t>(9222), static_cast<std::uint16_t>(ctx.gpr[26]));
    rt.memory().aot_store_word_left(ctx.gpr[24] + static_cast<std::uint32_t>(16041), ctx.gpr[8]);
    rt.unsupported(0x089C6560u, 0xD4B95FFBu, "vfpu not lowered yet"); return;
L_089C6580:
    ctx.gpr[10] = (ctx.gpr[23] ^ 36022u);
    rt.unsupported(0x089C6584u, 0x67F17ED7u, "vfpu1 not lowered yet"); return;
L_089C65A8:
    if (ctx.gpr[22] == ctx.gpr[30]) {
    ctx.gpr[27] = (aot_mem.aot_load16(0u + static_cast<std::uint32_t>(14455)));
        goto L_089CD408;
    }
    goto L_089C65B0;
L_089C65B0:
    ctx.gpr[13] = (aot_mem.aot_load16(ctx.gpr[2] + static_cast<std::uint32_t>(-9274)));
    aot_mem.aot_store8(ctx.gpr[17] + static_cast<std::uint32_t>(26132), static_cast<std::uint8_t>(ctx.gpr[4]));
    rt.unsupported(0x089C65BCu, 0x0AD043EDu, "control flow in delay slot"); return;
L_089C69A8:
    rt.unsupported(0x089C69A8u, 0x72657375u, "unknown not lowered yet"); return;
L_089C69B4:
    (void)(static_cast<std::uint32_t>(static_cast<std::int32_t>(0u) >> 1u));
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x02011610u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089C6A20:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x02017E90u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089C6C40:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x0201DE20u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089C6C7C:
    rt.unsupported(0x089C6C7Cu, 0x41545441u, "unknown not lowered yet"); return;
L_089C6CA8:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x0202C4E0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089C6CE0:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x0202E000u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089C6D18:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x0202E580u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089C6D60:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x02041480u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089C6D70:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x020412E0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089C6D80:
    // nop
    // nop
    // nop
    rt.unsupported(0x089C6D90u, 0x61747461u, "vfpu0 not lowered yet"); return;
    ctx.pc = 0x020413B0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089C6DA0:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x02042670u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089C6DB0:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x020432B0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089C6DC0:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x02042EA0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089C6DD0:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x02042F70u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089C6DE0:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x02043040u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089C6DF0:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x02043110u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089C6E00:
    // nop
    // nop
    // nop
    rt.unsupported(0x089C6E10u, 0x7F7FFFFFu, "special3? not lowered yet"); return;
    ctx.pc = 0x020431E0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089C6ED4:
    rt.unsupported(0x089C6ED4u, 0x706B7461u, "unknown not lowered yet"); return;
L_089C6EDC:
    rt.unsupported(0x089C6EDCu, 0x63657073u, "vfpu0 not lowered yet"); return;
L_089C6EE4:
    rt.unsupported(0x089C6EE4u, 0x706B656Eu, "unknown not lowered yet"); return;
L_089C6EEC:
    rt.unsupported(0x089C6EECu, 0x62726373u, "vfpu0 not lowered yet"); return;
L_089C6EF4:
    rt.unsupported(0x089C6EF4u, 0x726D6163u, "unknown not lowered yet"); return;
L_089C6EFC:
    rt.unsupported(0x089C6EFCu, 0x67726863u, "vfpu1 not lowered yet"); return;
L_089C6F04:
    rt.unsupported(0x089C6F04u, 0x61726373u, "vfpu0 not lowered yet"); return;
L_089C6F0C:
    rt.unsupported(0x089C6F0Cu, 0x706E7077u, "unknown not lowered yet"); return;
L_089C6F14:
    rt.unsupported(0x089C6F14u, 0x6E756F63u, "vfpu3 not lowered yet"); return;
L_089C6F1C:
    rt.unsupported(0x089C6F1Cu, 0x74697263u, "unknown not lowered yet"); return;
L_089C6F24:
    rt.unsupported(0x089C6F24u, 0x72617567u, "unknown not lowered yet"); return;
L_089C6F2C:
    rt.unsupported(0x089C6F2Cu, 0x67646F64u, "vfpu1 not lowered yet"); return;
L_089C6F34:
    rt.unsupported(0x089C6F34u, 0x69617262u, "unknown not lowered yet"); return;
L_089C6F3C:
    rt.unsupported(0x089C6F3Cu, 0x72617073u, "unknown not lowered yet"); return;
L_089C6F44:
    rt.unsupported(0x089C6F44u, 0x675F6F6Au, "vfpu1 not lowered yet"); return;
L_089C6F4C:
    rt.unsupported(0x089C6F4Cu, 0x61727561u, "vfpu0 not lowered yet"); return;
L_089C6F54:
    rt.unsupported(0x089C6F54u, 0x6E756874u, "vfpu3 not lowered yet"); return;
L_089C6F5C:
    rt.unsupported(0x089C6F5Cu, 0x626D756Eu, "vfpu0 not lowered yet"); return;
L_089C6F64:
    rt.unsupported(0x089C6F64u, 0x7570616Du, "unknown not lowered yet"); return;
L_089C6F6C:
    rt.unsupported(0x089C6F6Cu, 0x726F5F63u, "unknown not lowered yet"); return;
L_089C6F74:
    rt.unsupported(0x089C6F74u, 0x73797263u, "unknown not lowered yet"); return;
L_089C6F7C:
    ctx.execute_vfpu_vcmp_ct<95u, 101u, 1u, 4u>();
    // nop
    // nop
    goto L_089C6F88;
L_089C6F88:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x02050EE0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089C6FB8:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x02051590u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089C6FE8:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x02051C10u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089C7030:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x02052900u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089C7248:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x02053030u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089C74B0:
    // nop
    // nop
    // nop
    rt.unsupported(0x089C74C0u, 0x42700000u, "unknown not lowered yet"); return;
    ctx.pc = 0x02059E10u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089C74C8:
    // nop
    // nop
    // nop
    rt.unsupported(0x089C74D8u, 0x7F7FFFFFu, "special3? not lowered yet"); return;
    ctx.pc = 0x0205F1F0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089C74E8:
    // nop
    goto L_089C74EC;
L_089C74EC:
    // nop
    // nop
    // nop
    ctx.pc = 0x02066F10u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089C74F8:
    // nop
    // nop
    // nop
    rt.unsupported(0x089C7508u, 0x41F00000u, "unknown not lowered yet"); return;
    ctx.pc = 0x020679E0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089C7510:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x02068810u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089C7520:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x0206BE10u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089C7530:
    // nop
    // nop
    // nop
    ctx.gpr[25] = (39322u << 16u);
    ctx.pc = 0x0206D090u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089C7548:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x02077FA0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089C7558:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x02077510u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089C7568:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x020775E0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089C7578:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x020776B0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089C7588:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x02077780u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089C7598:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x02077850u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089C75A8:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x02077920u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089C75B8:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x020779F0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089C75C8:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x02077AC0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089C75D8:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x02077B90u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089C75E8:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x02077C60u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089C75F8:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x02077D30u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089C7608:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x02077E00u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089C7618:
    // nop
    // nop
    // nop
    rt.unsupported(0x089C7628u, 0x6A626F66u, "unknown not lowered yet"); return;
    ctx.pc = 0x02077ED0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089C7638:
    // nop
    // nop
    // nop
    (void)(0u >> 0u);
    ctx.pc = 0x0207BFB0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089C7650:
    // nop
    // nop
    // nop
    rt.unsupported(0x089C7660u, 0x40490FDBu, "unknown not lowered yet"); return;
    ctx.pc = 0x0207D090u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089C7668:
    // nop
    // nop
    // nop
    rt.unsupported(0x089C7678u, 0x40490FDBu, "unknown not lowered yet"); return;
    ctx.pc = 0x020807A0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089C7680:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x02084440u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089C7690:
    // nop
    // nop
    // nop
    rt.unsupported(0x089C76A0u, 0x7F7FFFFFu, "special3? not lowered yet"); return;
    ctx.pc = 0x02088B30u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089C76A8:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x0209E7C0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089C78C0:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x020A2F40u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089C78D0:
    // nop
    // nop
    // nop
    rt.unsupported(0x089C78E0u, 0x74697773u, "unknown not lowered yet"); return;
    ctx.pc = 0x020A2E70u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089C7C48:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x02050EE0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089C7C78:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x020C42F0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089C7FEC:
    // nop
    (void)(0u << (0u & 31u));
    ctx.gpr[25] = (39322u << 16u);
    ctx.gpr[25] = (39322u << 16u);
    // nop
    rt.unsupported(0x089C8000u, 0x00000001u, "special? not lowered yet"); return;
L_089C8148:
    if (static_cast<std::int32_t>(ctx.gpr[26]) > 0) {
    rt.unsupported(0x089C814Cu, 0x41504546u, "unknown not lowered yet"); return;
        goto L_089D8A88;
    }
    goto L_089C8150;
L_089C8150:
    rt.unsupported(0x089C8150u, 0x73253A58u, "unknown not lowered yet"); return;
L_089C86A0:
    rt.unsupported(0x089C86A0u, 0x4D6A624Fu, "unknown not lowered yet"); return;
L_089C86A8:
    if (static_cast<std::int32_t>(ctx.gpr[26]) > 0) {
    rt.unsupported(0x089C86ACu, 0x414E414Du, "unknown not lowered yet"); return;
        goto L_089D8FE8;
    }
    goto L_089C86B0;
L_089C86B0:
    ctx.gpr[18] = (ctx.gpr[18] ^ 17735u);
    ctx.execute_vfpu_vscl_ct<58u, 69u, 120u, 1u>();
    rt.unsupported(0x089C86B8u, 0x73615463u, "unknown not lowered yet"); return;
L_089C86C0:
    if (static_cast<std::int32_t>(ctx.gpr[26]) > 0) {
    rt.unsupported(0x089C86C4u, 0x414E414Du, "unknown not lowered yet"); return;
        goto L_089D9000;
    }
    goto L_089C86C8;
L_089C86C8:
    ctx.gpr[18] = (ctx.gpr[18] ^ 17735u);
    ctx.execute_vfpu_vscl_ct<58u, 69u, 120u, 1u>();
    ctx.execute_vfpu_vcmp_ct<65u, 108u, 1u, 3u>();
    rt.unsupported(0x089C86D4u, 0x6B736154u, "unknown not lowered yet"); return;
L_089C86DC:
    if (static_cast<std::int32_t>(ctx.gpr[26]) > 0) {
    rt.unsupported(0x089C86E0u, 0x414E414Du, "unknown not lowered yet"); return;
        goto L_089D901C;
    }
    goto L_089C86E4;
L_089C86E4:
    ctx.gpr[18] = (ctx.gpr[18] ^ 17735u);
    rt.unsupported(0x089C86E8u, 0x7365443Au, "unknown not lowered yet"); return;
L_089C86F8:
    if (static_cast<std::int32_t>(ctx.gpr[26]) > 0) {
    rt.unsupported(0x089C86FCu, 0x414E414Du, "unknown not lowered yet"); return;
        goto L_089D9038;
    }
    goto L_089C8700;
L_089C8700:
    ctx.gpr[18] = (ctx.gpr[18] ^ 17735u);
    rt.unsupported(0x089C8704u, 0x6172443Au, "vfpu0 not lowered yet"); return;
L_089C8710:
    if (static_cast<std::int32_t>(ctx.gpr[26]) > 0) {
    rt.unsupported(0x089C8714u, 0x414E414Du, "unknown not lowered yet"); return;
        goto L_089D9050;
    }
    goto L_089C8718;
L_089C8718:
    ctx.gpr[18] = (ctx.gpr[18] ^ 17735u);
    rt.unsupported(0x089C871Cu, 0x6172443Au, "vfpu0 not lowered yet"); return;
L_089C872C:
    if (static_cast<std::int32_t>(ctx.gpr[26]) > 0) {
    rt.unsupported(0x089C8730u, 0x414E414Du, "unknown not lowered yet"); return;
        goto L_089D906C;
    }
    goto L_089C8734;
L_089C8734:
    ctx.gpr[18] = (ctx.gpr[18] ^ 17735u);
    rt.unsupported(0x089C8738u, 0x6172443Au, "vfpu0 not lowered yet"); return;
L_089C8750:
    if (static_cast<std::int32_t>(ctx.gpr[26]) > 0) {
    rt.unsupported(0x089C8754u, 0x414E414Du, "unknown not lowered yet"); return;
        goto L_089D9090;
    }
    goto L_089C8758;
L_089C8758:
    ctx.gpr[18] = (ctx.gpr[18] ^ 17735u);
    rt.unsupported(0x089C875Cu, 0x7466413Au, "unknown not lowered yet"); return;
L_089C876C:
    if (static_cast<std::int32_t>(ctx.gpr[26]) > 0) {
    rt.unsupported(0x089C8770u, 0x414E414Du, "unknown not lowered yet"); return;
        goto L_089D90AC;
    }
    goto L_089C8774;
L_089C8774:
    ctx.gpr[18] = (ctx.gpr[18] ^ 17735u);
    { float vfpu_s[4]{}, vfpu_t[4]{}, vfpu_d[4]{};
      ctx.read_vfpu_vector_with_source_prefix_ct<65u, 1u, 0u>(vfpu_s);
      ctx.read_vfpu_vector_with_source_prefix_ct<100u, 1u, 1u>(vfpu_t);
      for (std::uint32_t i = 0; i < 1u; ++i) vfpu_d[i] = vfpu_s[i] * vfpu_t[i];
      ctx.write_vfpu_vector_with_destination_prefix_ct<58u, 1u>(vfpu_d); }
    rt.unsupported(0x089C877Cu, 0x77617244u, "unknown not lowered yet"); return;
L_089C8788:
    if (static_cast<std::int32_t>(ctx.gpr[26]) > 0) {
    rt.unsupported(0x089C878Cu, 0x414E414Du, "unknown not lowered yet"); return;
        goto L_089D90C8;
    }
    goto L_089C8790;
L_089C8790:
    ctx.gpr[18] = (ctx.gpr[18] ^ 17735u);
    rt.unsupported(0x089C8794u, 0x6172443Au, "vfpu0 not lowered yet"); return;
L_089C87B0:
    if (static_cast<std::int32_t>(ctx.gpr[26]) > 0) {
    rt.unsupported(0x089C87B4u, 0x4E554F53u, "unknown not lowered yet"); return;
        goto L_089D90F0;
    }
    goto L_089C87B8;
L_089C87B8:
    rt.unsupported(0x089C87B8u, 0x73253A44u, "unknown not lowered yet"); return;
L_089C87C8:
    if (static_cast<std::int32_t>(ctx.gpr[26]) > 0) {
    rt.unsupported(0x089C87CCu, 0x4E554F53u, "unknown not lowered yet"); return;
        goto L_089D9108;
    }
    goto L_089C87D0;
L_089C87D0:
    rt.unsupported(0x089C87D0u, 0x73253A44u, "unknown not lowered yet"); return;
L_089C87E0:
    if (static_cast<std::int32_t>(ctx.gpr[26]) > 0) {
    rt.unsupported(0x089C87E4u, 0x4E554F53u, "unknown not lowered yet"); return;
        goto L_089D9120;
    }
    goto L_089C87E8;
L_089C87E8:
    rt.unsupported(0x089C87E8u, 0x73253A44u, "unknown not lowered yet"); return;
L_089C87FC:
    rt.unsupported(0x089C87FCu, 0x73257325u, "unknown not lowered yet"); return;
L_089C8808:
    rt.unsupported(0x089C8808u, 0x73257325u, "unknown not lowered yet"); return;
L_089C8814:
    rt.unsupported(0x089C8814u, 0x73257325u, "unknown not lowered yet"); return;
L_089C8820:
    rt.unsupported(0x089C8820u, 0x6B617A5Fu, "unknown not lowered yet"); return;
L_089C8828:
    // nop
    goto L_089C882C;
L_089C882C:
    rt.unsupported(0x089C882Cu, 0x72617228u, "unknown not lowered yet"); return;
L_089C8838:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x0210A2C0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089C8850:
    rt.unsupported(0x089C8850u, 0x786A626Fu, "unknown not lowered yet"); return;
L_089C8858:
    rt.unsupported(0x089C8858u, 0x63696F76u, "vfpu0 not lowered yet"); return;
L_089C8878:
    rt.unsupported(0x089C8878u, 0x63696F76u, "vfpu0 not lowered yet"); return;
L_089C8898:
    rt.unsupported(0x089C8898u, 0x78736F63u, "unknown not lowered yet"); return;
L_089C88A0:
    rt.unsupported(0x089C88A0u, 0x78657865u, "unknown not lowered yet"); return;
L_089C88A8:
    ctx.gpr[13] = (~(ctx.gpr[3] | ctx.gpr[15]));
    goto L_089C88AC;
L_089C88AC:
    rt.unsupported(0x089C88ACu, 0x63657845u, "vfpu0 not lowered yet"); return;
L_089C88B8:
    rt.unsupported(0x089C88B8u, 0x444A424Fu, "unsupported CFC1 control register"); return;
    rt.unsupported(0x089C88BCu, 0x00415441u, "special? not lowered yet"); return;
L_089C88C0:
    rt.unsupported(0x089C88C0u, 0x444A424Fu, "unsupported CFC1 control register"); return;
    if (static_cast<std::int32_t>(ctx.gpr[26]) > 0) {
    ctx.gpr[8] = (static_cast<std::uint32_t>(static_cast<std::int32_t>(0u) >> (0u & 31u)));
        (void)rt.invoke_chained_direct<&recomp_unit_0014, 14u>(ctx, &aot_mem); return;
    }
    goto L_089C88CC;
L_089C88CC:
    rt.unsupported(0x089C88CCu, 0x4D5F5053u, "unknown not lowered yet"); return;
L_089C88D8:
    ctx.gpr[10] = (ctx.gpr[27] < static_cast<std::uint32_t>(25199) ? 1u : 0u);
    ctx.gpr[14] = (ctx.gpr[9] + static_cast<std::uint32_t>(29477));
    rt.unsupported(0x089C88E0u, 0x00000073u, "special? not lowered yet"); return;
L_089C88E4:
    rt.unsupported(0x089C88E4u, 0x63696F76u, "vfpu0 not lowered yet"); return;
L_089C8908:
    rt.unsupported(0x089C8908u, 0x63696F76u, "vfpu0 not lowered yet"); return;
L_089C8924:
    ctx.gpr[19] = (ctx.gpr[19] < static_cast<std::uint32_t>(9567) ? 1u : 0u);
    { const bool signed_ok = ctx.execute_signed_sub(13u, 3u, 14u);
      if (!signed_ok) { rt.arithmetic_overflow(0x089C8928u, 0x006E6962u); return; } }
    goto L_089C892C;
L_089C892C:
    rt.unsupported(0x089C892Cu, 0x63696F76u, "vfpu0 not lowered yet"); return;
L_089C8944:
    rt.unsupported(0x089C8944u, 0x00006E69u, "special? not lowered yet"); return;
L_089C8948:
    ctx.execute_vfpu_vscl_ct<101u, 102u, 102u, 1u>();
    // nop
    goto L_089C8950;
L_089C8950:
    if (static_cast<std::int32_t>(ctx.gpr[27]) > 0) {
    // nop
        (void)rt.invoke_chained_direct<&recomp_unit_0015, 15u>(ctx, &aot_mem); return;
    }
    goto L_089C8958;
L_089C8958:
    rt.unsupported(0x089C8958u, 0x61796C70u, "vfpu0 not lowered yet"); return;
L_089C8960:
    rt.unsupported(0x089C8960u, 0x626D6F63u, "vfpu0 not lowered yet"); return;
L_089C8968:
    rt.unsupported(0x089C8968u, 0x706B7461u, "unknown not lowered yet"); return;
L_089C8970:
    rt.unsupported(0x089C8970u, 0x6967616Du, "unknown not lowered yet"); return;
L_089C8978:
    rt.unsupported(0x089C8978u, 0x74617262u, "unknown not lowered yet"); return;
L_089C8980:
    rt.unsupported(0x089C8980u, 0x74786574u, "unknown not lowered yet"); return;
L_089C8988:
    rt.unsupported(0x089C8988u, 0x63657073u, "vfpu0 not lowered yet"); return;
L_089C8990:
    rt.unsupported(0x089C8990u, 0x74616566u, "unknown not lowered yet"); return;
L_089C8998:
    rt.unsupported(0x089C8998u, 0x73697270u, "unknown not lowered yet"); return;
L_089C89A0:
    rt.unsupported(0x089C89A0u, 0x62627562u, "vfpu0 not lowered yet"); return;
L_089C89A8:
    rt.unsupported(0x089C89A8u, 0x74726163u, "unknown not lowered yet"); return;
L_089C89B0:
    ctx.execute_vfpu_vscl_ct<109u, 105u, 110u, 1u>();
    // nop
    goto L_089C89B8;
L_089C89B8:
    { float vfpu_s[4]{}, vfpu_t[4]{}, vfpu_d[4]{};
      ctx.read_vfpu_vector_with_source_prefix_ct<105u, 1u, 0u>(vfpu_s);
      ctx.read_vfpu_vector_with_source_prefix_ct<110u, 1u, 1u>(vfpu_t);
      for (std::uint32_t i = 0; i < 1u; ++i) vfpu_d[i] = vfpu_s[i] * vfpu_t[i];
      ctx.write_vfpu_vector_with_destination_prefix_ct<119u, 1u>(vfpu_d); }
    // nop
    rt.unsupported(0x089C89C4u, 0x08846A78u, "control flow in delay slot"); return;
L_089C8A00:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x0211ED20u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089C8A74:
    rt.unsupported(0x089C8A74u, 0x494D494Cu, "cop2/vfpu not lowered yet"); return;
L_089C8A80:
    rt.unsupported(0x089C8A80u, 0x40490FDBu, "unknown not lowered yet"); return;
L_089C8AD8:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x021434C0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089C8D3C:
    ctx.gpr[13] = (ctx.gpr[3] ^ ctx.gpr[18]);
    goto L_089C8D40;
L_089C8D40:
    ctx.gpr[13] = (ctx.gpr[3] | ctx.gpr[5]);
    goto L_089C8D44;
L_089C8D44:
    rt.unsupported(0x089C8D44u, 0x00656E6Fu, "special? not lowered yet"); return;
L_089C8D8C:
    ctx.execute_vfpu_vscl_ct<109u, 105u, 110u, 1u>();
    // nop
    goto L_089C8D94;
L_089C8D94:
    rt.unsupported(0x089C8D94u, 0x675F6D74u, "vfpu1 not lowered yet"); return;
L_089C8DC4:
    (void)(0u >> (0u & 31u));
    ctx.lo = 0u;
    rt.unsupported(0x089C8DCCu, 0x0000000Cu, "syscall not lowered yet"); return;
L_089C8E10:
    rt.unsupported(0x089C8E10u, 0x45544641u, "cop1? not lowered yet"); return;
L_089C8E28:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x02171350u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089C8E60:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x02183CA0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089C8ED8:
    rt.unsupported(0x089C8ED8u, 0x78383025u, "unknown not lowered yet"); return;
L_089C8EE0:
    if (static_cast<std::int32_t>(ctx.gpr[27]) > 0) {
    { float vfpu_s[4]{}, vfpu_t[4]{}, vfpu_d[4]{};
      ctx.read_vfpu_vector_with_source_prefix_ct<48u, 1u, 0u>(vfpu_s);
      ctx.read_vfpu_vector_with_source_prefix_ct<51u, 1u, 1u>(vfpu_t);
      for (std::uint32_t i = 0; i < 1u; ++i) vfpu_d[i] = vfpu_s[i] * vfpu_t[i];
      ctx.write_vfpu_vector_with_destination_prefix_ct<37u, 1u>(vfpu_d); }
        (void)rt.invoke_chained_direct<&recomp_unit_0015, 15u>(ctx, &aot_mem); return;
    }
    goto L_089C8EE8;
L_089C8EE8:
    rt.unsupported(0x089C8EE8u, 0x6E69622Eu, "vfpu3 not lowered yet"); return;
L_089C8EF0:
    ctx.gpr[13] = (ctx.gpr[27] < static_cast<std::uint32_t>(26466) ? 1u : 0u);
    // nop
    goto L_089C8EF8;
L_089C8EF8:
    ctx.gpr[3] = (ctx.gpr[27] < static_cast<std::uint32_t>(27748) ? 1u : 0u);
    ctx.gpr[13] = (ctx.gpr[27] < static_cast<std::uint32_t>(26466) ? 1u : 0u);
    if (static_cast<std::int32_t>(ctx.gpr[27]) > 0) {
    { float vfpu_s[4]{}, vfpu_t[4]{}, vfpu_d[4]{};
      ctx.read_vfpu_vector_with_source_prefix_ct<48u, 1u, 0u>(vfpu_s);
      ctx.read_vfpu_vector_with_source_prefix_ct<51u, 1u, 1u>(vfpu_t);
      for (std::uint32_t i = 0; i < 1u; ++i) vfpu_d[i] = vfpu_s[i] * vfpu_t[i];
      ctx.write_vfpu_vector_with_destination_prefix_ct<37u, 1u>(vfpu_d); }
        (void)rt.invoke_chained_direct<&recomp_unit_0015, 15u>(ctx, &aot_mem); return;
    }
    goto L_089C8F08;
L_089C8F08:
    rt.unsupported(0x089C8F08u, 0x6E69622Eu, "vfpu3 not lowered yet"); return;
L_089C8F10:
    ctx.gpr[15] = (ctx.gpr[9] + static_cast<std::uint32_t>(29477));
    { float vfpu_s[4]{}, vfpu_t[4]{}, vfpu_d[4]{};
      ctx.read_vfpu_vector_with_source_prefix_ct<46u, 1u, 0u>(vfpu_s);
      ctx.read_vfpu_vector_with_source_prefix_ct<101u, 1u, 1u>(vfpu_t);
      for (std::uint32_t i = 0; i < 1u; ++i) vfpu_d[i] = vfpu_s[i] * vfpu_t[i];
      ctx.write_vfpu_vector_with_destination_prefix_ct<115u, 1u>(vfpu_d); }
    ctx.gpr[14] = (0u + 0u);
    goto L_089C8F1C;
L_089C8F1C:
    ctx.gpr[13] = (ctx.gpr[27] < static_cast<std::uint32_t>(26466) ? 1u : 0u);
    ctx.gpr[14] = (0u | 0u);
    goto L_089C8F24;
L_089C8F24:
    if (static_cast<std::int32_t>(ctx.gpr[27]) > 0) {
    { float vfpu_s[4]{}, vfpu_t[4]{}, vfpu_d[4]{};
      ctx.read_vfpu_vector_with_source_prefix_ct<48u, 1u, 0u>(vfpu_s);
      ctx.read_vfpu_vector_with_source_prefix_ct<51u, 1u, 1u>(vfpu_t);
      for (std::uint32_t i = 0; i < 1u; ++i) vfpu_d[i] = vfpu_s[i] * vfpu_t[i];
      ctx.write_vfpu_vector_with_destination_prefix_ct<37u, 1u>(vfpu_d); }
        (void)rt.invoke_chained_direct<&recomp_unit_0014, 14u>(ctx, &aot_mem); return;
    }
    goto L_089C8F2C;
L_089C8F2C:
    rt.unsupported(0x089C8F2Cu, 0x69622E74u, "unknown not lowered yet"); return;
L_089C8F34:
    rt.unsupported(0x089C8F34u, 0x74786574u, "unknown not lowered yet"); return;
L_089C8F48:
    rt.unsupported(0x089C8F48u, 0x69622E74u, "unknown not lowered yet"); return;
L_089C8F54:
    ctx.gpr[15] = (ctx.gpr[9] + static_cast<std::uint32_t>(29477));
    rt.unsupported(0x089C8F58u, 0x00000073u, "special? not lowered yet"); return;
L_089C8F5C:
    if (static_cast<std::int32_t>(ctx.gpr[27]) > 0) {
    { float vfpu_s[4]{}, vfpu_t[4]{}, vfpu_d[4]{};
      ctx.read_vfpu_vector_with_source_prefix_ct<48u, 1u, 0u>(vfpu_s);
      ctx.read_vfpu_vector_with_source_prefix_ct<51u, 1u, 1u>(vfpu_t);
      for (std::uint32_t i = 0; i < 1u; ++i) vfpu_d[i] = vfpu_s[i] * vfpu_t[i];
      ctx.write_vfpu_vector_with_destination_prefix_ct<37u, 1u>(vfpu_d); }
        (void)rt.invoke_chained_direct<&recomp_unit_0015, 15u>(ctx, &aot_mem); return;
    }
    goto L_089C8F64;
L_089C8F64:
    rt.unsupported(0x089C8F64u, 0x622E656Fu, "vfpu0 not lowered yet"); return;
L_089C8F6C:
    ctx.gpr[3] = (ctx.gpr[27] < static_cast<std::uint32_t>(27748) ? 1u : 0u);
    ctx.gpr[10] = (ctx.gpr[27] < static_cast<std::uint32_t>(25199) ? 1u : 0u);
    // nop
    goto L_089C8F78;
L_089C8F78:
    ctx.gpr[3] = (ctx.gpr[27] < static_cast<std::uint32_t>(27748) ? 1u : 0u);
    ctx.gpr[10] = (ctx.gpr[27] < static_cast<std::uint32_t>(25199) ? 1u : 0u);
    if (static_cast<std::int32_t>(ctx.gpr[27]) > 0) {
    { float vfpu_s[4]{}, vfpu_t[4]{}, vfpu_d[4]{};
      ctx.read_vfpu_vector_with_source_prefix_ct<48u, 1u, 0u>(vfpu_s);
      ctx.read_vfpu_vector_with_source_prefix_ct<51u, 1u, 1u>(vfpu_t);
      for (std::uint32_t i = 0; i < 1u; ++i) vfpu_d[i] = vfpu_s[i] * vfpu_t[i];
      ctx.write_vfpu_vector_with_destination_prefix_ct<37u, 1u>(vfpu_d); }
        (void)rt.invoke_chained_direct<&recomp_unit_0015, 15u>(ctx, &aot_mem); return;
    }
    goto L_089C8F88;
L_089C8F88:
    rt.unsupported(0x089C8F88u, 0x622E656Fu, "vfpu0 not lowered yet"); return;
L_089C8F94:
    ctx.gpr[3] = (ctx.gpr[27] < static_cast<std::uint32_t>(27748) ? 1u : 0u);
    // nop
    goto L_089C8F9C;
L_089C8F9C:
    rt.unsupported(0x089C8F9Cu, 0x69726561u, "unknown not lowered yet"); return;
L_089C8FA8:
    ctx.gpr[3] = (ctx.gpr[27] < static_cast<std::uint32_t>(27748) ? 1u : 0u);
    rt.unsupported(0x089C8FACu, 0x69726561u, "unknown not lowered yet"); return;
L_089C8FC0:
    // nop
    // nop
    goto L_089C8FC8;
L_089C8FC8:
    rt.unsupported(0x089C8FC8u, 0x4C435845u, "unknown not lowered yet"); return;
L_089C8FD4:
    if (static_cast<std::int32_t>(ctx.gpr[10]) <= 0) {
    // nop
        goto L_089DCD0C;
    }
    goto L_089C8FDC;
L_089C8FDC:
    // nop
    goto L_089C8FE0;
L_089C8FE0:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x0218C820u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089C90F0:
    rt.unsupported(0x089C90F0u, 0x454C4946u, "cop1? not lowered yet"); return;
L_089C9100:
    { float vfpu_s[4]{}, vfpu_t[4]{}, vfpu_d[4]{};
      ctx.read_vfpu_vector_with_source_prefix_ct<68u, 1u, 0u>(vfpu_s);
      ctx.read_vfpu_vector_with_source_prefix_ct<118u, 1u, 1u>(vfpu_t);
      for (std::uint32_t i = 0; i < 1u; ++i) vfpu_d[i] = vfpu_s[i] * vfpu_t[i];
      ctx.write_vfpu_vector_with_destination_prefix_ct<95u, 1u>(vfpu_d); }
    rt.unsupported(0x089C9104u, 0x43646D55u, "unknown not lowered yet"); return;
L_089C9110:
    rt.unsupported(0x089C9110u, 0x63736964u, "vfpu0 not lowered yet"); return;
L_089C9118:
    rt.unsupported(0x089C9118u, 0x61746164u, "vfpu0 not lowered yet"); return;
L_089C9120:
    rt.unsupported(0x089C9120u, 0x63736964u, "vfpu0 not lowered yet"); return;
L_089C912C:
    ctx.gpr[5] = (ctx.gpr[26] < static_cast<std::uint32_t>(19777) ? 1u : 0u);
    rt.unsupported(0x089C9130u, 0x44525355u, "unsupported CFC1 control register"); return;
    { float vfpu_s[4]{}, vfpu_t[4]{}, vfpu_d[4]{};
      ctx.read_vfpu_vector_with_source_prefix_ct<82u, 1u, 0u>(vfpu_s);
      ctx.read_vfpu_vector_with_source_prefix_ct<47u, 1u, 1u>(vfpu_t);
      for (std::uint32_t i = 0; i < 1u; ++i) vfpu_d[i] = vfpu_s[i] * vfpu_t[i];
      ctx.write_vfpu_vector_with_destination_prefix_ct<73u, 1u>(vfpu_d); }
    ctx.gpr[1] = (ctx.gpr[27] < static_cast<std::uint32_t>(29793) ? 1u : 0u);
    rt.unsupported(0x089C913Cu, 0x75646F6Du, "unknown not lowered yet"); return;
L_089C9148:
    rt.unsupported(0x089C9148u, 0x63736964u, "vfpu0 not lowered yet"); return;
L_089C9154:
    ctx.gpr[5] = (ctx.gpr[26] < static_cast<std::uint32_t>(19777) ? 1u : 0u);
    rt.unsupported(0x089C9158u, 0x44525355u, "unsupported CFC1 control register"); return;
    { float vfpu_s[4]{}, vfpu_t[4]{}, vfpu_d[4]{};
      ctx.read_vfpu_vector_with_source_prefix_ct<82u, 1u, 0u>(vfpu_s);
      ctx.read_vfpu_vector_with_source_prefix_ct<47u, 1u, 1u>(vfpu_t);
      for (std::uint32_t i = 0; i < 1u; ++i) vfpu_d[i] = vfpu_s[i] * vfpu_t[i];
      ctx.write_vfpu_vector_with_destination_prefix_ct<73u, 1u>(vfpu_d); }
    ctx.gpr[1] = (ctx.gpr[27] < static_cast<std::uint32_t>(29793) ? 1u : 0u);
    ctx.gpr[14] = (0u | 0u);
    goto L_089C9168;
L_089C9168:
    rt.unsupported(0x089C9168u, 0x63736964u, "vfpu0 not lowered yet"); return;
L_089C9174:
    ctx.gpr[5] = (ctx.gpr[26] < static_cast<std::uint32_t>(19777) ? 1u : 0u);
    rt.unsupported(0x089C9178u, 0x44525355u, "unsupported CFC1 control register"); return;
    ctx.gpr[15] = (ctx.gpr[9] + static_cast<std::uint32_t>(21065));
    rt.unsupported(0x089C9180u, 0x00000073u, "special? not lowered yet"); return;
L_089C9188:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x0218F530u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089C9298:
    ctx.gpr[8] = (ctx.hi);
    goto L_089C929C;
L_089C929C:
    ctx.gpr[10] = (ctx.gpr[4] << (ctx.gpr[2] & 31u));
    goto L_089C92A0;
L_089C92A0:
    rt.unsupported(0x089C92A0u, 0x00444D55u, "special? not lowered yet"); return;
L_089C92B0:
    if (static_cast<std::int32_t>(ctx.gpr[26]) > 0) {
    rt.unsupported(0x089C92B4u, 0x6E65704Fu, "vfpu3 not lowered yet"); return;
        goto L_089DC7CC;
    }
    goto L_089C92B8;
L_089C92B8:
    rt.unsupported(0x089C92B8u, 0x6E797341u, "vfpu3 not lowered yet"); return;
L_089C92C8:
    if (static_cast<std::int32_t>(ctx.gpr[26]) > 0) {
    { float vfpu_s[4]{}, vfpu_t[4]{}, vfpu_d[4]{};
      ctx.read_vfpu_vector_with_source_prefix_ct<101u, 1u, 0u>(vfpu_s);
      ctx.read_vfpu_vector_with_source_prefix_ct<97u, 1u, 1u>(vfpu_t);
      for (std::uint32_t i = 0; i < 1u; ++i) vfpu_d[i] = vfpu_s[i] * vfpu_t[i];
      ctx.write_vfpu_vector_with_destination_prefix_ct<82u, 1u>(vfpu_d); }
        goto L_089DC7E4;
    }
    goto L_089C92D0;
L_089C92D0:
    rt.unsupported(0x089C92D0u, 0x6E797341u, "vfpu3 not lowered yet"); return;
L_089C92E0:
    if (static_cast<std::int32_t>(ctx.gpr[26]) > 0) {
    ctx.execute_vfpu_vscl_ct<83u, 105u, 122u, 1u>();
        goto L_089DC7FC;
    }
    goto L_089C92E8;
L_089C92E8:
    rt.unsupported(0x089C92E8u, 0x6E797341u, "vfpu3 not lowered yet"); return;
L_089C92F8:
    if (static_cast<std::int32_t>(ctx.gpr[26]) > 0) {
    rt.unsupported(0x089C92FCu, 0x6B656553u, "unknown not lowered yet"); return;
        goto L_089DC814;
    }
    goto L_089C9300;
L_089C9300:
    rt.unsupported(0x089C9300u, 0x6E797341u, "vfpu3 not lowered yet"); return;
L_089C9310:
    if (static_cast<std::int32_t>(ctx.gpr[26]) > 0) {
    ctx.execute_vfpu_vscl_ct<80u, 111u, 119u, 1u>();
        goto L_089DC82C;
    }
    goto L_089C9318;
L_089C9318:
    ctx.execute_vfpu_vcmp_ct<67u, 97u, 1u, 2u>();
    rt.unsupported(0x089C931Cu, 0x6361626Cu, "vfpu0 not lowered yet"); return;
L_089C9330:
    rt.unsupported(0x089C9330u, 0x4D415246u, "unknown not lowered yet"); return;
L_089C9344:
    // nop
    goto L_089C9348;
L_089C9348:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x02193DE0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089C9370:
    ctx.execute_vfpu_vscl_ct<71u, 97u, 109u, 1u>();
    ctx.execute_vfpu_vscl_ct<77u, 111u, 100u, 1u>();
    // nop
    goto L_089C937C;
L_089C937C:
    rt.unsupported(0x089C937Cu, 0x454D4147u, "cop1? not lowered yet"); return;
L_089C9390:
    // nop
    // nop
    goto L_089C9398;
L_089C9398:
    rt.unsupported(0x089C939Cu, 0x53434948u, "control flow in delay slot"); return;
L_089C93A0:
    ctx.execute_vfpu_vcmp_ct<58u, 68u, 1u, 10u>();
    rt.unsupported(0x089C93A4u, 0x72617453u, "unknown not lowered yet"); return;
L_089C93B0:
    rt.unsupported(0x089C93B4u, 0x53434948u, "control flow in delay slot"); return;
L_089C93B8:
    ctx.execute_vfpu_vcmp_ct<58u, 68u, 1u, 10u>();
    rt.unsupported(0x089C93BCu, 0x696E6946u, "unknown not lowered yet"); return;
L_089C93C8:
    rt.unsupported(0x089C93CCu, 0x53434948u, "control flow in delay slot"); return;
L_089C93D0:
    ctx.execute_vfpu_vcmp_ct<58u, 68u, 1u, 10u>();
    { float vfpu_s[4]{}, vfpu_t[4]{}, vfpu_d[4]{};
      ctx.read_vfpu_vector_with_source_prefix_ct<101u, 1u, 0u>(vfpu_s);
      ctx.read_vfpu_vector_with_source_prefix_ct<110u, 1u, 1u>(vfpu_t);
      for (std::uint32_t i = 0; i < 1u; ++i) vfpu_d[i] = vfpu_s[i] * vfpu_t[i];
      ctx.write_vfpu_vector_with_destination_prefix_ct<83u, 1u>(vfpu_d); }
    rt.unsupported(0x089C93D8u, 0x6B736154u, "unknown not lowered yet"); return;
L_089C93E0:
    rt.unsupported(0x089C93E4u, 0x53434948u, "control flow in delay slot"); return;
L_089C93E8:
    if (ctx.gpr[18] == ctx.gpr[7]) {
    rt.unsupported(0x089C93ECu, 0x49485041u, "cop2/vfpu not lowered yet"); return;
        goto L_089D7CD4;
    }
    goto L_089C93F0;
L_089C93F0:
    ctx.gpr[10] = (static_cast<std::uint32_t>(static_cast<std::int32_t>(0u) >> 13u));
    goto L_089C93F4;
L_089C93F4:
    rt.unsupported(0x089C93F8u, 0x53434948u, "control flow in delay slot"); return;
L_089C93FC:
    rt.unsupported(0x089C93FCu, 0x44453A3Au, "unsupported CFC1 control register"); return;
    ctx.gpr[8] = (ctx.lo);
    // nop
    rt.unsupported(0x089C9408u, 0x00005F4Du, "special? not lowered yet"); return;
L_089C9424:
    ctx.gpr[10] = (ctx.lo);
    { const std::int32_t dividend = static_cast<std::int32_t>(0u); ctx.lo = dividend >= 0 ? 0xFFFFFFFFu : 1u; ctx.hi = static_cast<std::uint32_t>(dividend); }
    goto L_089C942C;
L_089C942C:
    rt.unsupported(0x089C942Cu, 0x00000001u, "special? not lowered yet"); return;
L_089C955C:
    // nop
    goto L_089C9560;
L_089C9560:
    rt.unsupported(0x089C9560u, 0x0000002Eu, "special? not lowered yet"); return;
L_089C9564:
    rt.unsupported(0x089C9564u, 0x45444F4Du, "cop1? not lowered yet"); return;
L_089C9574:
    rt.unsupported(0x089C9574u, 0x45444F4Du, "cop1? not lowered yet"); return;
L_089C9584:
    rt.unsupported(0x089C9584u, 0x45444F4Du, "cop1? not lowered yet"); return;
L_089C9594:
    // nop
    goto L_089C9598;
L_089C9598:
    rt.unsupported(0x089C9598u, 0x0000005Fu, "special? not lowered yet"); return;
L_089C959C:
    rt.unsupported(0x089C959Cu, 0x67726174u, "vfpu1 not lowered yet"); return;
L_089C95A4:
    rt.unsupported(0x089C95A4u, 0x72756F73u, "unknown not lowered yet"); return;
L_089C95AC:
    rt.unsupported(0x089C95ACu, 0x61666564u, "vfpu0 not lowered yet"); return;
L_089C95B8:
    rt.unsupported(0x089C95B8u, 0x41786554u, "unknown not lowered yet"); return;
L_089C95C0:
    if (ctx.gpr[2] != ctx.gpr[19]) {
    rt.unsupported(0x089C95C4u, 0x45434E41u, "cop1? not lowered yet"); return;
        goto L_089DBAD4;
    }
    goto L_089C95C8;
L_089C95C8:
    // nop
    goto L_089C95CC;
L_089C95CC:
    if (0u == 0u) (void)(0u);
    rt.unsupported(0x089C95D0u, 0x61746144u, "vfpu0 not lowered yet"); return;
L_089C95E0:
    if (ctx.gpr[2] != ctx.gpr[1]) {
    // nop
        goto L_089DA69C;
    }
    goto L_089C95E8;
L_089C95E8:
    ctx.execute_vfpu_vscl_ct<115u, 97u, 118u, 1u>();
    ctx.gpr[16] = (ctx.gpr[26] < static_cast<std::uint32_t>(18991) ? 1u : 0u);
    rt.unsupported(0x089C95F0u, 0x41524150u, "unknown not lowered yet"); return;
L_089C9600:
    ctx.gpr[29] = (ctx.gpr[12] < static_cast<std::uint32_t>(-30956) ? 1u : 0u);
    rt.unsupported(0x089C9604u, 0xB342F18Eu, "unknown not lowered yet"); return;
L_089C9614:
    rt.unsupported(0x089C9614u, 0x7362696Cu, "unknown not lowered yet"); return;
L_089C9628:
    ctx.gpr[16] = (ctx.gpr[17] ^ 29549u);
    rt.unsupported(0x089C9630u, 0x5641532Fu, "control flow in delay slot"); return;
L_089C9634:
    if (ctx.gpr[2] != ctx.gpr[1]) {
    rt.unsupported(0x089C9638u, 0x73252F41u, "unknown not lowered yet"); return;
        goto L_089DA74C;
    }
    goto L_089C963C;
L_089C963C:
    ctx.gpr[14] = (0u | 0u);
    // nop
    // nop
    // nop
    // nop
    goto L_089C9650;
L_089C9650:
    ctx.gpr[16] = (ctx.gpr[17] ^ 29549u);
    rt.unsupported(0x089C9658u, 0x5641532Fu, "control flow in delay slot"); return;
L_089C965C:
    if (ctx.gpr[2] != ctx.gpr[1]) {
    rt.unsupported(0x089C9660u, 0x73252F41u, "unknown not lowered yet"); return;
        goto L_089DA774;
    }
    goto L_089C9664;
L_089C9664:
    if (ctx.gpr[1] == ctx.gpr[15]) {
    rt.unsupported(0x089C9668u, 0x4D415241u, "unknown not lowered yet"); return;
        (void)rt.invoke_chained_direct<&recomp_unit_0015, 15u>(ctx, &aot_mem); return;
    }
    goto L_089C966C;
L_089C966C:
    rt.unsupported(0x089C966Cu, 0x4F46532Eu, "unknown not lowered yet"); return;
L_089C9674:
    if (ctx.gpr[25] != 0u) {
    ctx.execute_vfpu_vscl_ct<114u, 105u, 116u, 1u>();
        (void)rt.invoke_chained_direct<&recomp_unit_0014, 14u>(ctx, &aot_mem); return;
    }
    goto L_089C967C;
L_089C967C:
    // nop
    goto L_089C9680;
L_089C9680:
    // nop
    // nop
    // nop
    rt.unsupported(0x089C9690u, 0x6B636170u, "unknown not lowered yet"); return;
    ctx.pc = 0x021C4CF0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089C96B0:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x021C73F0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089C96E8:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x021C9D00u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089C9738:
    jump_target = 0u;
    ctx.gpr[31] = (0x089C9740u);
    // nop
    ctx.pc = jump_target;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x089C9740u) goto L_089C9740;
    return;
L_089C9740:
    rt.unsupported(0x089C9740u, 0x00000001u, "special? not lowered yet"); return;
L_089C9888:
    ctx.gpr[8] = (0u << 0u);
    // nop
    (void)(ctx.gpr[16] << 0u);
    // nop
    ctx.gpr[4] = (0u << 0u);
    // nop
    (void)(0u << 0u);
    // nop
    ctx.gpr[16] = (0u << 0u);
    // nop
    (void)(0u << 0u);
    // nop
    ctx.gpr[2] = (0u << 0u);
    // nop
    (void)(0u << 0u);
    // nop
    (void)(0u << 1u);
    // nop
    (void)(0u << 0u);
    // nop
    (void)(ctx.hi);
    // nop
    { const bool branch_taken = static_cast<std::int32_t>(0u) < 0;
    // nop
      if (branch_taken) {
          goto L_089C98E4;
      }
      goto L_089C98E8;
    }
L_089C98E4:
    // nop
    goto L_089C98E8;
L_089C98E8:
    (void)(0u << 2u);
    // nop
    // nop
    ctx.pc = 0x00000000u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089C9AC8:
    if (static_cast<std::int32_t>(ctx.gpr[26]) > 0) {
    rt.unsupported(0x089C9ACCu, 0x414E414Du, "unknown not lowered yet"); return;
        goto L_089DA00C;
    }
    goto L_089C9AD0;
L_089C9AD0:
    ctx.gpr[18] = (ctx.gpr[18] ^ 17735u);
    rt.unsupported(0x089C9AD4u, 0x6165523Au, "vfpu0 not lowered yet"); return;
L_089C9AFC:
    // nop
    goto L_089C9B00;
L_089C9B00:
    // nop
    ctx.pc = 0x00000000u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089C9B50:
    rt.unsupported(0x089C9B50u, 0x45524353u, "cop1? not lowered yet"); return;
L_089C9B6C:
    rt.unsupported(0x089C9B6Cu, 0x45524353u, "cop1? not lowered yet"); return;
L_089C9B88:
    rt.unsupported(0x089C9B88u, 0x45524353u, "cop1? not lowered yet"); return;
L_089C9BAC:
    rt.unsupported(0x089C9BACu, 0x45524353u, "cop1? not lowered yet"); return;
L_089C9BB8:
    rt.unsupported(0x089C9BB8u, 0x78453A3Au, "unknown not lowered yet"); return;
L_089C9BC8:
    rt.unsupported(0x089C9BC8u, 0x45524353u, "cop1? not lowered yet"); return;
L_089C9BD4:
    ctx.gpr[26] = (ctx.gpr[17] ^ 21061u);
    rt.unsupported(0x089C9BD8u, 0x6E69614Du, "vfpu3 not lowered yet"); return;
L_089C9BE0:
    if (ctx.gpr[26] == ctx.gpr[19]) {
    rt.unsupported(0x089C9BE4u, 0x41494449u, "unknown not lowered yet"); return;
        goto L_089DC0F4;
    }
    goto L_089C9BE8;
L_089C9BE8:
    ctx.gpr[17] = (ctx.gpr[17] & 12383u);
    rt.unsupported(0x089C9BECu, 0x0046465Fu, "special? not lowered yet"); return;
L_089C9BF0:
    rt.unsupported(0x089C9BF0u, 0x63657845u, "vfpu0 not lowered yet"); return;
L_089C9BF8:
    rt.unsupported(0x089C9BF8u, 0x63657845u, "vfpu0 not lowered yet"); return;
L_089C9C04:
    rt.unsupported(0x089C9C04u, 0x20303032u, "unknown not lowered yet"); return;
L_089C9C38:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x021D6220u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089C9C48:
    // nop
    rt.unsupported(0x089C9C4Cu, 0x00000014u, "special? not lowered yet"); return;
L_089C9C50:
    rt.unsupported(0x089C9C50u, 0x00000038u, "special? not lowered yet"); return;
L_089C9C54:
    rt.unsupported(0x089C9C54u, 0x00000014u, "special? not lowered yet"); return;
L_089C9C5C:
    rt.unsupported(0x089C9C5Cu, 0x00000034u, "special? not lowered yet"); return;
L_089C9C70:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x02D87170u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089C9D30:
    // nop
    // nop
    // nop
    { const bool signed_ok = ctx.execute_signed_add(0u, 0u, 0u);
      if (!signed_ok) { rt.arithmetic_overflow(0x089C9D40u, 0x00000020u); return; } }
    ctx.pc = 0x021E8BB0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089C9D40:
    { const bool signed_ok = ctx.execute_signed_add(0u, 0u, 0u);
      if (!signed_ok) { rt.arithmetic_overflow(0x089C9D40u, 0x00000020u); return; } }
    // nop
    goto L_089C9D48;
L_089C9D48:
    // nop
    // nop
    // nop
    (void)(0u << 8u);
    ctx.pc = 0x021F3BA0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089C9D58:
    (void)(0u << 8u);
    (void)(0u << 2u);
    { const bool signed_ok = ctx.execute_signed_add(0u, 0u, 16u);
      if (!signed_ok) { rt.arithmetic_overflow(0x089C9D60u, 0x00100020u); return; } }
    jump_target = 0u;
    (void)(ctx.gpr[1] >> 0u);
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089C9D6C:
    (void)(0u << (0u & 31u));
    (void)(0u >> 0u);
    // nop
    // nop
    (void)(0u << (0u & 31u));
    (void)(0u >> 0u);
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    (void)(0u >> 0u);
    (void)(0u >> 0u);
    goto L_089C9DAC;
L_089C9DAC:
    if (ctx.gpr[2] != ctx.gpr[19]) {
    rt.unsupported(0x089C9DB0u, 0x46204D45u, "cop1? not lowered yet"); return;
        (void)rt.invoke_chained_direct<&recomp_unit_0014, 14u>(ctx, &aot_mem); return;
    }
    goto L_089C9DB4;
L_089C9DB4:
    rt.unsupported(0x089C9DB4u, 0x20544E4Fu, "unknown not lowered yet"); return;
L_089C9DBC:
    if (ctx.gpr[2] != ctx.gpr[19]) {
    rt.unsupported(0x089C9DC0u, 0x46204D45u, "cop1? not lowered yet"); return;
        (void)rt.invoke_chained_direct<&recomp_unit_0014, 14u>(ctx, &aot_mem); return;
    }
    goto L_089C9DC4;
L_089C9DC4:
    rt.unsupported(0x089C9DC4u, 0x20544E4Fu, "unknown not lowered yet"); return;
L_089C9DCC:
    if (ctx.gpr[2] != ctx.gpr[19]) {
    rt.unsupported(0x089C9DD0u, 0x46204D45u, "cop1? not lowered yet"); return;
        (void)rt.invoke_chained_direct<&recomp_unit_0014, 14u>(ctx, &aot_mem); return;
    }
    goto L_089C9DD4;
L_089C9DD4:
    rt.memory().memory_barrier();
    goto L_089C9DD8;
L_089C9DD8:
    if (ctx.gpr[2] != ctx.gpr[19]) {
    rt.unsupported(0x089C9DDCu, 0x46204D45u, "cop1? not lowered yet"); return;
        (void)rt.invoke_chained_direct<&recomp_unit_0014, 14u>(ctx, &aot_mem); return;
    }
    goto L_089C9DE0;
L_089C9DE0:
    rt.unsupported(0x089C9DE0u, 0x20544E4Fu, "unknown not lowered yet"); return;
L_089C9DE8:
    ctx.execute_vfpu_vhdp(108u, 105u, 98u, 1u);
    ctx.gpr[20] = (ctx.gpr[19] < static_cast<std::uint32_t>(28271) ? 1u : 0u);
    rt.unsupported(0x089C9DF0u, 0x00787270u, "special? not lowered yet"); return;
L_089C9DF4:
    if (ctx.gpr[2] != ctx.gpr[19]) {
    rt.unsupported(0x089C9DF8u, 0x465F4D45u, "cop1? not lowered yet"); return;
        (void)rt.invoke_chained_direct<&recomp_unit_0014, 14u>(ctx, &aot_mem); return;
    }
    goto L_089C9DFC;
L_089C9DFC:
    ctx.gpr[20] = (ctx.gpr[18] ^ 20047u);
    { float vfpu_s[4]{}, vfpu_t[4]{}, vfpu_d[4]{};
      ctx.read_vfpu_vector_with_source_prefix_ct<85u, 1u, 0u>(vfpu_s);
      ctx.read_vfpu_vector_with_source_prefix_ct<112u, 1u, 1u>(vfpu_t);
      for (std::uint32_t i = 0; i < 1u; ++i) vfpu_d[i] = vfpu_s[i] * vfpu_t[i];
      ctx.write_vfpu_vector_with_destination_prefix_ct<58u, 1u>(vfpu_d); }
    ctx.gpr[14] = (ctx.gpr[3] + ctx.gpr[5]);
    goto L_089C9E08;
L_089C9E08:
    if (ctx.gpr[2] != ctx.gpr[19]) {
    rt.unsupported(0x089C9E0Cu, 0x465F4D45u, "cop1? not lowered yet"); return;
        (void)rt.invoke_chained_direct<&recomp_unit_0014, 14u>(ctx, &aot_mem); return;
    }
    goto L_089C9E10;
L_089C9E10:
    ctx.gpr[20] = (ctx.gpr[18] ^ 20047u);
    rt.unsupported(0x089C9E14u, 0x6172443Au, "vfpu0 not lowered yet"); return;
L_089C9EC0:
    if (ctx.gpr[2] != ctx.gpr[19]) {
    rt.unsupported(0x089C9EC4u, 0x4D204D45u, "unknown not lowered yet"); return;
        (void)rt.invoke_chained_direct<&recomp_unit_0014, 14u>(ctx, &aot_mem); return;
    }
    goto L_089C9EC8;
L_089C9EC8:
    if (ctx.gpr[18] == ctx.gpr[15]) {
    { const std::uint64_t product = static_cast<std::uint64_t>(0u) * static_cast<std::uint64_t>(0u); ctx.lo = static_cast<std::uint32_t>(product); ctx.hi = static_cast<std::uint32_t>(product >> 32u); }
        (void)rt.invoke_chained_direct<&recomp_unit_0014, 14u>(ctx, &aot_mem); return;
    }
    goto L_089C9ED0;
L_089C9ED0:
    if (ctx.gpr[2] != ctx.gpr[19]) {
    rt.unsupported(0x089C9ED4u, 0x4D204D45u, "unknown not lowered yet"); return;
        (void)rt.invoke_chained_direct<&recomp_unit_0014, 14u>(ctx, &aot_mem); return;
    }
    goto L_089C9ED8;
L_089C9ED8:
    if (ctx.gpr[18] == ctx.gpr[15]) {
    rt.unsupported(0x089C9EDCu, 0x4D532059u, "unknown not lowered yet"); return;
        (void)rt.invoke_chained_direct<&recomp_unit_0014, 14u>(ctx, &aot_mem); return;
    }
    goto L_089C9EE0;
L_089C9EE0:
    rt.unsupported(0x089C9EE0u, 0x004C4C41u, "special? not lowered yet"); return;
L_089C9EE8:
    rt.unsupported(0x089C9EE8u, 0x74737953u, "unknown not lowered yet"); return;
L_089C9F00:
    rt.unsupported(0x089C9F00u, 0x414C4F56u, "unknown not lowered yet"); return;
L_089C9F14:
    ctx.gpr[26] = (ctx.gpr[17] ^ 21061u);
    rt.unsupported(0x089C9F18u, 0x61647055u, "vfpu0 not lowered yet"); return;
L_089C9F20:
    rt.unsupported(0x089C9F20u, 0x414C4F56u, "unknown not lowered yet"); return;
L_089C9F34:
    rt.unsupported(0x089C9F34u, 0x00005245u, "special? not lowered yet"); return;
L_089C9F38:
    rt.unsupported(0x089C9F38u, 0x414C4F56u, "unknown not lowered yet"); return;
L_089C9F58:
    rt.unsupported(0x089C9F58u, 0x4E595356u, "unknown not lowered yet"); return;
L_089C9F64:
    rt.unsupported(0x089C9F64u, 0x6B736154u, "unknown not lowered yet"); return;
L_089C9F70:
    rt.unsupported(0x089C9F70u, 0x00030001u, "special? not lowered yet"); return;
L_089C9F88:
    (void)(ctx.gpr[2] << 0u);
    (void)(ctx.gpr[1] << (0u & 31u));
    (void)(ctx.gpr[1] << 0u);
    (void)(static_cast<std::uint32_t>(static_cast<std::int32_t>(ctx.gpr[5]) >> 0u));
    rt.unsupported(0x089C9F98u, 0x00000001u, "special? not lowered yet"); return;
L_089C9FA0:
    rt.unsupported(0x089C9FA0u, 0x4D4D4F43u, "unknown not lowered yet"); return;
L_089C9FB8:
    ctx.execute_vfpu_vminmax(99u, 111u, 109u, 1u, false);
    rt.unsupported(0x089C9FBCu, 0x622E6E6Fu, "vfpu0 not lowered yet"); return;
L_089C9FC4:
    rt.unsupported(0x089C9FC4u, 0x73756170u, "unknown not lowered yet"); return;
L_089C9FD8:
    (void)(ctx.gpr[2] << 0u);
    rt.unsupported(0x089C9FDCu, 0x00010005u, "special? not lowered yet"); return;
L_089C9FE8:
    rt.unsupported(0x089C9FE8u, 0x63696F76u, "vfpu0 not lowered yet"); return;
L_089CA004:
    rt.unsupported(0x089CA004u, 0x735F3030u, "unknown not lowered yet"); return;
L_089CA0C0:
    rt.unsupported(0x089CA0C0u, 0x006E696Eu, "special? not lowered yet"); return;
L_089CA0C4:
    rt.unsupported(0x089CA0C4u, 0x006E6874u, "special? not lowered yet"); return;
L_089CA0C8:
    rt.unsupported(0x089CA0C8u, 0x4C454946u, "unknown not lowered yet"); return;
L_089CA0E0:
    ctx.execute_vfpu_vscl_ct<103u, 101u, 110u, 1u>();
    if (static_cast<std::int32_t>(ctx.gpr[27]) > 0) {
    rt.unsupported(0x089CA0E8u, 0x68637261u, "unknown not lowered yet"); return;
        (void)rt.invoke_chained_direct<&recomp_unit_0014, 14u>(ctx, &aot_mem); return;
    }
    goto L_089CA0EC;
L_089CA0EC:
    ctx.gpr[5] = (ctx.gpr[27] < static_cast<std::uint32_t>(30313) ? 1u : 0u);
    ctx.execute_vfpu_vcmp_ct<105u, 101u, 1u, 6u>();
    ctx.execute_vfpu_vscl_ct<100u, 47u, 109u, 1u>();
    rt.unsupported(0x089CA0F8u, 0x622E756Eu, "vfpu0 not lowered yet"); return;
L_089CA100:
    ctx.execute_vfpu_vscl_ct<103u, 101u, 110u, 1u>();
    if (static_cast<std::int32_t>(ctx.gpr[27]) > 0) {
    rt.unsupported(0x089CA108u, 0x68637261u, "unknown not lowered yet"); return;
        (void)rt.invoke_chained_direct<&recomp_unit_0014, 14u>(ctx, &aot_mem); return;
    }
    goto L_089CA10C;
L_089CA10C:
    ctx.gpr[5] = (ctx.gpr[27] < static_cast<std::uint32_t>(30313) ? 1u : 0u);
    ctx.execute_vfpu_vcmp_ct<105u, 101u, 1u, 6u>();
    if (ctx.gpr[2] == ctx.gpr[10]) {
    rt.unsupported(0x089CA118u, 0x6E656D2Fu, "vfpu3 not lowered yet"); return;
        goto L_089D5EA8;
    }
    goto L_089CA11C;
L_089CA11C:
    rt.unsupported(0x089CA11Cu, 0x616C5F75u, "vfpu0 not lowered yet"); return;
L_089CA128:
    ctx.gpr[10] = (ctx.gpr[19] ^ 25199u);
    if (static_cast<std::int32_t>(ctx.gpr[26]) > 0) {
    rt.unsupported(0x089CA130u, 0x45564552u, "cop1? not lowered yet"); return;
        goto L_089DB618;
    }
    goto L_089CA134;
L_089CA134:
    if (static_cast<std::int32_t>(ctx.gpr[26]) > 0) {
    rt.unsupported(0x089CA138u, 0x414E414Du, "unknown not lowered yet"); return;
        goto L_089DBE70;
    }
    goto L_089CA13C;
L_089CA13C:
    ctx.gpr[18] = (ctx.gpr[18] ^ 17735u);
    { float vfpu_s[4]{}, vfpu_t[4]{}, vfpu_d[4]{};
      ctx.read_vfpu_vector_with_source_prefix_ct<85u, 1u, 0u>(vfpu_s);
      ctx.read_vfpu_vector_with_source_prefix_ct<112u, 1u, 1u>(vfpu_t);
      for (std::uint32_t i = 0; i < 1u; ++i) vfpu_d[i] = vfpu_s[i] * vfpu_t[i];
      ctx.write_vfpu_vector_with_destination_prefix_ct<58u, 1u>(vfpu_d); }
    ctx.gpr[14] = (ctx.gpr[3] + ctx.gpr[5]);
    goto L_089CA148;
L_089CA148:
    ctx.gpr[10] = (ctx.gpr[19] ^ 25199u);
    if (ctx.gpr[2] != ctx.gpr[9]) {
    rt.unsupported(0x089CA150u, 0x4F54535Fu, "unknown not lowered yet"); return;
        goto L_089DC238;
    }
    goto L_089CA154;
L_089CA154:
    if (ctx.gpr[9] != ctx.gpr[26]) {
    rt.unsupported(0x089CA158u, 0x74616470u, "unknown not lowered yet"); return;
        goto L_089D8A98;
    }
    goto L_089CA15C;
L_089CA15C:
    (void)(0u | 0u);
    goto L_089CA160;
L_089CA160:
    rt.unsupported(0x089CA160u, 0x69706553u, "unknown not lowered yet"); return;
L_089CA16C:
    rt.unsupported(0x089CA16Cu, 0x69706553u, "unknown not lowered yet"); return;
L_089CA17C:
    rt.unsupported(0x089CA17Cu, 0x45485055u, "cop1? not lowered yet"); return;
L_089CA188:
    ctx.gpr[18] = (ctx.gpr[18] ^ 17735u);
    { float vfpu_s[4]{}, vfpu_t[4]{}, vfpu_d[4]{};
      ctx.read_vfpu_vector_with_source_prefix_ct<85u, 1u, 0u>(vfpu_s);
      ctx.read_vfpu_vector_with_source_prefix_ct<112u, 1u, 1u>(vfpu_t);
      for (std::uint32_t i = 0; i < 1u; ++i) vfpu_d[i] = vfpu_s[i] * vfpu_t[i];
      ctx.write_vfpu_vector_with_destination_prefix_ct<58u, 1u>(vfpu_d); }
    ctx.gpr[14] = (ctx.gpr[3] + ctx.gpr[5]);
    goto L_089CA194;
L_089CA194:
    rt.unsupported(0x089CA198u, 0x51494E55u, "control flow in delay slot"); return;
L_089CA19C:
    rt.unsupported(0x089CA19Cu, 0x4D5F4555u, "unknown not lowered yet"); return;
L_089CA1B0:
    rt.unsupported(0x089CA1B4u, 0x51494E55u, "control flow in delay slot"); return;
L_089CA1B8:
    rt.unsupported(0x089CA1B8u, 0x4D5F4555u, "unknown not lowered yet"); return;
L_089CA1D0:
    rt.unsupported(0x089CA1D4u, 0x51494E55u, "control flow in delay slot"); return;
L_089CA1D8:
    rt.unsupported(0x089CA1D8u, 0x4D5F4555u, "unknown not lowered yet"); return;
L_089CA1F0:
    rt.unsupported(0x089CA1F4u, 0x51494E55u, "control flow in delay slot"); return;
L_089CA1F8:
    rt.unsupported(0x089CA1F8u, 0x4D5F4555u, "unknown not lowered yet"); return;
L_089CA20C:
    rt.unsupported(0x089CA20Cu, 0x41524353u, "unknown not lowered yet"); return;
L_089CA224:
    rt.unsupported(0x089CA224u, 0x41524353u, "unknown not lowered yet"); return;
L_089CA23C:
    rt.unsupported(0x089CA23Cu, 0x41524353u, "unknown not lowered yet"); return;
L_089CA258:
    rt.unsupported(0x089CA25Cu, 0x52435F53u, "control flow in delay slot"); return;
L_089CA260:
    ctx.gpr[11] = (ctx.gpr[18] ^ 17217u);
    { float vfpu_s[4]{}, vfpu_t[4]{}, vfpu_d[4]{};
      ctx.read_vfpu_vector_with_source_prefix_ct<85u, 1u, 0u>(vfpu_s);
      ctx.read_vfpu_vector_with_source_prefix_ct<112u, 1u, 1u>(vfpu_t);
      for (std::uint32_t i = 0; i < 1u; ++i) vfpu_d[i] = vfpu_s[i] * vfpu_t[i];
      ctx.write_vfpu_vector_with_destination_prefix_ct<58u, 1u>(vfpu_d); }
    ctx.gpr[14] = (ctx.gpr[3] + ctx.gpr[5]);
    goto L_089CA26C;
L_089CA26C:
    rt.unsupported(0x089CA270u, 0x52435F53u, "control flow in delay slot"); return;
L_089CA274:
    ctx.gpr[11] = (ctx.gpr[18] ^ 17217u);
    rt.unsupported(0x089CA278u, 0x6172443Au, "vfpu0 not lowered yet"); return;
L_089CA280:
    rt.unsupported(0x089CA280u, 0x45505553u, "cop1? not lowered yet"); return;
L_089CA298:
    rt.unsupported(0x089CA298u, 0x45524353u, "cop1? not lowered yet"); return;
L_089CA2B8:
    rt.unsupported(0x089CA2B8u, 0x45524353u, "cop1? not lowered yet"); return;
L_089CA2D8:
    rt.unsupported(0x089CA2D8u, 0x45524353u, "cop1? not lowered yet"); return;
L_089CA2F4:
    rt.unsupported(0x089CA2F4u, 0x474F5250u, "cop1? not lowered yet"); return;
L_089CA304:
    ctx.gpr[18] = (ctx.gpr[18] ^ 17735u);
    { float vfpu_s[4]{}, vfpu_t[4]{}, vfpu_d[4]{};
      ctx.read_vfpu_vector_with_source_prefix_ct<85u, 1u, 0u>(vfpu_s);
      ctx.read_vfpu_vector_with_source_prefix_ct<112u, 1u, 1u>(vfpu_t);
      for (std::uint32_t i = 0; i < 1u; ++i) vfpu_d[i] = vfpu_s[i] * vfpu_t[i];
      ctx.write_vfpu_vector_with_destination_prefix_ct<58u, 1u>(vfpu_d); }
    ctx.gpr[14] = (ctx.gpr[3] + ctx.gpr[5]);
    goto L_089CA310;
L_089CA310:
    rt.unsupported(0x089CA310u, 0x474F5250u, "cop1? not lowered yet"); return;
L_089CA320:
    ctx.gpr[18] = (ctx.gpr[18] ^ 17735u);
    rt.unsupported(0x089CA324u, 0x6172443Au, "vfpu0 not lowered yet"); return;
L_089CA32C:
    rt.unsupported(0x089CA330u, 0x5F4C4154u, "control flow in delay slot"); return;
L_089CA334:
    rt.unsupported(0x089CA334u, 0x414E414Du, "unknown not lowered yet"); return;
L_089CA34C:
    rt.unsupported(0x089CA350u, 0x5F4C4154u, "control flow in delay slot"); return;
L_089CA354:
    rt.unsupported(0x089CA354u, 0x414E414Du, "unknown not lowered yet"); return;
L_089CA364:
    rt.unsupported(0x089CA368u, 0x5F4C4154u, "control flow in delay slot"); return;
L_089CA36C:
    rt.unsupported(0x089CA36Cu, 0x414E414Du, "unknown not lowered yet"); return;
L_089CA380:
    rt.unsupported(0x089CA384u, 0x5F4C4154u, "control flow in delay slot"); return;
L_089CA388:
    rt.unsupported(0x089CA388u, 0x414E414Du, "unknown not lowered yet"); return;
L_089CA398:
    rt.unsupported(0x089CA39Cu, 0x5F4C4154u, "control flow in delay slot"); return;
L_089CA3A0:
    rt.unsupported(0x089CA3A0u, 0x414E414Du, "unknown not lowered yet"); return;
L_089CA3B4:
    rt.unsupported(0x089CA3B4u, 0x4C454946u, "unknown not lowered yet"); return;
L_089CA3C4:
    rt.unsupported(0x089CA3C4u, 0x77617244u, "unknown not lowered yet"); return;
L_089CA3D0:
    rt.unsupported(0x089CA3D0u, 0x7774654Eu, "unknown not lowered yet"); return;
L_089CA3E0:
    rt.unsupported(0x089CA3E4u, 0x52425F45u, "control flow in delay slot"); return;
L_089CA3E8:
    if (static_cast<std::int32_t>(ctx.gpr[26]) > 0) {
    rt.unsupported(0x089CA3ECu, 0x45464645u, "cop1? not lowered yet"); return;
        goto L_089DA900;
    }
    goto L_089CA3F0;
L_089CA3F0:
    ctx.gpr[26] = (ctx.gpr[17] ^ 21571u);
    rt.unsupported(0x089CA3F4u, 0x77617244u, "unknown not lowered yet"); return;
L_089CA3FC:
    rt.unsupported(0x089CA3FCu, 0x47495242u, "cop1? not lowered yet"); return;
L_089CA418:
    rt.unsupported(0x089CA418u, 0x4F435450u, "unknown not lowered yet"); return;
L_089CA430:
    (void)(0u | 0u);
    goto L_089CA434;
L_089CA434:
    rt.unsupported(0x089CA434u, 0x4F435450u, "unknown not lowered yet"); return;
L_089CA44C:
    rt.unsupported(0x089CA44Cu, 0x4F435450u, "unknown not lowered yet"); return;
L_089CA464:
    ctx.execute_vfpu_compare3(97u, 103u, 84u, 1u, 6u);
    rt.unsupported(0x089CA468u, 0x79616C50u, "unknown not lowered yet"); return;
L_089CA470:
    rt.unsupported(0x089CA470u, 0x49535341u, "cop2/vfpu not lowered yet"); return;
L_089CA488:
    rt.unsupported(0x089CA488u, 0x49535341u, "cop2/vfpu not lowered yet"); return;
L_089CA4A4:
    rt.unsupported(0x089CA4A4u, 0x00726579u, "special? not lowered yet"); return;
L_089CA4A8:
    rt.unsupported(0x089CA4ACu, 0x52435F53u, "control flow in delay slot"); return;
L_089CA4B0:
    rt.unsupported(0x089CA4B4u, 0x54504143u, "control flow in delay slot"); return;
L_089CA4B8:
    ctx.gpr[5] = (ctx.gpr[18] ^ 21077u);
    { float vfpu_s[4]{}, vfpu_t[4]{}, vfpu_d[4]{};
      ctx.read_vfpu_vector_with_source_prefix_ct<85u, 1u, 0u>(vfpu_s);
      ctx.read_vfpu_vector_with_source_prefix_ct<112u, 1u, 1u>(vfpu_t);
      for (std::uint32_t i = 0; i < 1u; ++i) vfpu_d[i] = vfpu_s[i] * vfpu_t[i];
      ctx.write_vfpu_vector_with_destination_prefix_ct<58u, 1u>(vfpu_d); }
    ctx.gpr[14] = (ctx.gpr[3] + ctx.gpr[5]);
    goto L_089CA4C4;
L_089CA4C4:
    rt.unsupported(0x089CA4C4u, 0x63657845u, "vfpu0 not lowered yet"); return;
L_089CA4DC:
    rt.unsupported(0x089CA4DCu, 0x4C454946u, "unknown not lowered yet"); return;
L_089CA4E8:
    rt.unsupported(0x089CA4E8u, 0x63655279u, "vfpu0 not lowered yet"); return;
L_089CA580:
    rt.unsupported(0x089CA580u, 0x6E756F73u, "vfpu3 not lowered yet"); return;
L_089CA59C:
    if (static_cast<std::int32_t>(ctx.gpr[27]) > 0) {
    rt.unsupported(0x089CA5A0u, 0x74746162u, "unknown not lowered yet"); return;
        (void)rt.invoke_chained_direct<&recomp_unit_0015, 15u>(ctx, &aot_mem); return;
    }
    goto L_089CA5A4;
L_089CA5A4:
    rt.unsupported(0x089CA5A4u, 0x732E656Cu, "unknown not lowered yet"); return;
L_089CA5B0:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x0223A880u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089CA5F8:
    rt.unsupported(0x089CA5F8u, 0x61647055u, "vfpu0 not lowered yet"); return;
L_089CA600:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x0223AAF0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089CA638:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x0223B670u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089CA670:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x0223C0D0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089CA6A8:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x0223CF10u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089CA6E0:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x0223DA80u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089CA720:
    rt.unsupported(0x089CA720u, 0x4C454946u, "unknown not lowered yet"); return;
L_089CA730:
    rt.unsupported(0x089CA730u, 0x4C454946u, "unknown not lowered yet"); return;
L_089CA740:
    (void)(ctx.hi);
    // nop
    goto L_089CA748;
L_089CA748:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x02242C10u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089CA758:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x0224F590u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089CA768:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x0224F590u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089CA778:
    // nop
    goto L_089CA77C;
L_089CA77C:
    rt.unsupported(0x089CA77Cu, 0x45505553u, "cop1? not lowered yet"); return;
L_089CA788:
    if (static_cast<std::int32_t>(ctx.gpr[26]) > 0) {
    // nop
        (void)rt.invoke_chained_direct<&recomp_unit_0014, 14u>(ctx, &aot_mem); return;
    }
    goto L_089CA790;
L_089CA78C:
    // nop
    goto L_089CA790;
L_089CA790:
    if (static_cast<std::int32_t>(ctx.gpr[26]) > 0) {
    // nop
        goto L_089DBCA4;
    }
    goto L_089CA798;
L_089CA798:
    ctx.gpr[16] = (ctx.gpr[27] < static_cast<std::uint32_t>(24941) ? 1u : 0u);
    rt.unsupported(0x089CA79Cu, 0x672E7325u, "vfpu1 not lowered yet"); return;
L_089CA7A8:
    ctx.lo = ctx.gpr[2];
    goto L_089CA7AC;
L_089CA7AC:
    rt.unsupported(0x089CA7ACu, 0x0000002Eu, "special? not lowered yet"); return;
L_089CA7B0:
    ctx.execute_vfpu_compare3(46u, 103u, 109u, 1u, 6u);
    // nop
    goto L_089CA7B8;
L_089CA7B8:
    ctx.gpr[16] = (ctx.gpr[18] ^ 16717u);
    ctx.execute_vfpu_vscl_ct<58u, 69u, 120u, 1u>();
    rt.unsupported(0x089CA7C0u, 0x73615463u, "unknown not lowered yet"); return;
L_089CA7C8:
    ctx.gpr[16] = (ctx.gpr[18] ^ 16717u);
    rt.unsupported(0x089CA7CCu, 0x6172443Au, "vfpu0 not lowered yet"); return;
L_089CA7D8:
    ctx.gpr[16] = (ctx.gpr[18] ^ 16717u);
    rt.unsupported(0x089CA7DCu, 0x6172443Au, "vfpu0 not lowered yet"); return;
L_089CA7F0:
    ctx.gpr[16] = (ctx.gpr[18] ^ 16717u);
    ctx.execute_vfpu_vcmp_ct<67u, 117u, 1u, 10u>();
    rt.unsupported(0x089CA7F8u, 0x676E696Cu, "vfpu1 not lowered yet"); return;
L_089CA804:
    ctx.gpr[16] = (ctx.gpr[18] ^ 16717u);
    rt.unsupported(0x089CA808u, 0x616F4C3Au, "vfpu0 not lowered yet"); return;
L_089CA814:
    rt.unsupported(0x089CA814u, 0x45544641u, "cop1? not lowered yet"); return;
L_089CA820:
    rt.unsupported(0x089CA820u, 0x41534944u, "unknown not lowered yet"); return;
L_089CA82C:
    rt.unsupported(0x089CA82Cu, 0x4E415254u, "unknown not lowered yet"); return;
L_089CA868:
    // nop
    // nop
    // nop
    rt.unsupported(0x089CA878u, 0x41454C43u, "unknown not lowered yet"); return;
    ctx.pc = 0x02254EF0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089CA878:
    rt.unsupported(0x089CA878u, 0x41454C43u, "unknown not lowered yet"); return;
L_089CA884:
    ctx.gpr[9] = (ctx.gpr[7] >> (ctx.gpr[2] & 31u));
    goto L_089CA888;
L_089CA888:
    if (ctx.gpr[18] == ctx.gpr[21]) {
    // nop
        (void)rt.invoke_chained_direct<&recomp_unit_0014, 14u>(ctx, &aot_mem); return;
    }
    goto L_089CA890;
L_089CA890:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x02255120u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089CA8B0:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x02255BF0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089CA8D0:
    rt.unsupported(0x089CA8D4u, 0x54534944u, "control flow in delay slot"); return;
L_089CA8D8:
    rt.unsupported(0x089CA8D8u, 0x4954524Fu, "cop2/vfpu not lowered yet"); return;
L_089CA8F0:
    rt.unsupported(0x089CA8F4u, 0x54534944u, "control flow in delay slot"); return;
L_089CA8F8:
    rt.unsupported(0x089CA8F8u, 0x4954524Fu, "cop2/vfpu not lowered yet"); return;
L_089CA910:
    if (static_cast<std::int32_t>(ctx.gpr[26]) > 0) {
    rt.unsupported(0x089CA914u, 0x45464645u, "cop1? not lowered yet"); return;
        goto L_089DAE48;
    }
    goto L_089CA918;
L_089CA918:
    ctx.gpr[26] = (ctx.gpr[9] + static_cast<std::uint32_t>(21571));
    rt.unsupported(0x089CA91Cu, 0x00000073u, "special? not lowered yet"); return;
L_089CA920:
    if (static_cast<std::int32_t>(ctx.gpr[26]) > 0) {
    rt.unsupported(0x089CA924u, 0x45464645u, "cop1? not lowered yet"); return;
        goto L_089DAE58;
    }
    goto L_089CA928;
L_089CA928:
    ctx.gpr[26] = (ctx.gpr[17] ^ 21571u);
    rt.unsupported(0x089CA92Cu, 0x6E69614Du, "vfpu3 not lowered yet"); return;
L_089CA938:
    ctx.execute_vfpu_vminmax(37u, 115u, 46u, 1u, false);
    ctx.gpr[14] = (0u | 0u);
    goto L_089CA940;
L_089CA940:
    if (static_cast<std::int32_t>(ctx.gpr[27]) > 0) {
    rt.unsupported(0x089CA944u, 0x61626573u, "vfpu0 not lowered yet"); return;
        (void)rt.invoke_chained_direct<&recomp_unit_0015, 15u>(ctx, &aot_mem); return;
    }
    goto L_089CA948;
L_089CA948:
    ctx.execute_vfpu_vscl_ct<116u, 116u, 108u, 1u>();
    ctx.gpr[24] = (ctx.gpr[19] < static_cast<std::uint32_t>(25951) ? 1u : 0u);
    ctx.gpr[14] = (ctx.gpr[1] + ctx.gpr[19]);
    goto L_089CA954;
L_089CA954:
    if (static_cast<std::int32_t>(ctx.gpr[27]) > 0) {
    rt.unsupported(0x089CA958u, 0x61626573u, "vfpu0 not lowered yet"); return;
        (void)rt.invoke_chained_direct<&recomp_unit_0015, 15u>(ctx, &aot_mem); return;
    }
    goto L_089CA95C;
L_089CA95C:
    ctx.execute_vfpu_vscl_ct<116u, 116u, 108u, 1u>();
    rt.unsupported(0x089CA960u, 0x6E69665Fu, "vfpu3 not lowered yet"); return;
L_089CAA10:
    // nop
    ctx.pc = 0x0272A5C0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089CAAB0:
    if (static_cast<std::int32_t>(ctx.gpr[27]) > 0) {
    rt.unsupported(0x089CAAB4u, 0x6E756F73u, "vfpu3 not lowered yet"); return;
        (void)rt.invoke_chained_direct<&recomp_unit_0014, 14u>(ctx, &aot_mem); return;
    }
    goto L_089CAAB8;
L_089CAAB8:
    rt.unsupported(0x089CAAB8u, 0x61705F64u, "vfpu0 not lowered yet"); return;
L_089CAAC4:
    if (static_cast<std::int32_t>(ctx.gpr[27]) > 0) {
    rt.unsupported(0x089CAAC8u, 0x732E7325u, "unknown not lowered yet"); return;
        (void)rt.invoke_chained_direct<&recomp_unit_0015, 15u>(ctx, &aot_mem); return;
    }
    goto L_089CAACC;
L_089CAACC:
    ctx.gpr[12] = (0u - 0u);
    goto L_089CAAD0;
L_089CAAD0:
    rt.unsupported(0x089CAAD0u, 0x732E7325u, "unknown not lowered yet"); return;
L_089CAB04:
    ctx.gpr[16] = (ctx.gpr[27] < static_cast<std::uint32_t>(24941) ? 1u : 0u);
    rt.unsupported(0x089CAB08u, 0x692E7325u, "unknown not lowered yet"); return;
L_089CAB10:
    rt.unsupported(0x089CAB10u, 0x0000002Eu, "special? not lowered yet"); return;
L_089CAB14:
    rt.unsupported(0x089CAB14u, 0x0064692Eu, "special? not lowered yet"); return;
L_089CAB18:
    rt.unsupported(0x089CAB18u, 0x4950414Du, "cop2/vfpu not lowered yet"); return;
L_089CAB28:
    ctx.gpr[8] = (ctx.gpr[19] << (ctx.gpr[2] & 31u));
    rt.unsupported(0x089CAB2Cu, 0x00000005u, "special? not lowered yet"); return;
L_089CAB38:
    ctx.execute_vfpu_vcmp_ct<114u, 111u, 1u, 0u>();
    rt.unsupported(0x089CAB3Cu, 0x7375676Fu, "unknown not lowered yet"); return;
L_089CAB50:
    if (static_cast<std::int32_t>(ctx.gpr[27]) > 0) {
    rt.unsupported(0x089CAB54u, 0x72746E65u, "unknown not lowered yet"); return;
        (void)rt.invoke_chained_direct<&recomp_unit_0015, 15u>(ctx, &aot_mem); return;
    }
    goto L_089CAB58;
L_089CAB58:
    rt.unsupported(0x089CAB58u, 0x69622E79u, "unknown not lowered yet"); return;
L_089CAB60:
    if (static_cast<std::int32_t>(ctx.gpr[27]) > 0) {
    ctx.execute_vfpu_vscl_ct<110u, 97u, 109u, 1u>();
        (void)rt.invoke_chained_direct<&recomp_unit_0015, 15u>(ctx, &aot_mem); return;
    }
    goto L_089CAB68;
L_089CAB68:
    rt.unsupported(0x089CAB68u, 0x6E69622Eu, "vfpu3 not lowered yet"); return;
L_089CAB70:
    { float vfpu_s[4]{}, vfpu_t[4]{}, vfpu_d[4]{};
      ctx.read_vfpu_vector_with_source_prefix_ct<48u, 1u, 0u>(vfpu_s);
      ctx.read_vfpu_vector_with_source_prefix_ct<51u, 1u, 1u>(vfpu_t);
      for (std::uint32_t i = 0; i < 1u; ++i) vfpu_d[i] = vfpu_s[i] * vfpu_t[i];
      ctx.write_vfpu_vector_with_destination_prefix_ct<37u, 1u>(vfpu_d); }
    ctx.gpr[16] = (ctx.gpr[25] & 9567u);
    (void)(0u & 0u);
    // nop
    goto L_089CAB80;
L_089CAB80:
    if (static_cast<std::int32_t>(ctx.gpr[26]) > 0) {
    ctx.execute_vfpu_vscl_ct<80u, 111u, 119u, 1u>();
        goto L_089DB0D0;
    }
    goto L_089CAB88;
L_089CAB88:
    ctx.execute_vfpu_vcmp_ct<67u, 97u, 1u, 2u>();
    rt.unsupported(0x089CAB8Cu, 0x6361626Cu, "vfpu0 not lowered yet"); return;
L_089CAB94:
    rt.unsupported(0x089CAB94u, 0x43534944u, "unknown not lowered yet"); return;
L_089CABA0:
    ctx.gpr[5] = (ctx.gpr[26] < static_cast<std::uint32_t>(19777) ? 1u : 0u);
    rt.unsupported(0x089CABA4u, 0x44525355u, "unsupported CFC1 control register"); return;
    rt.unsupported(0x089CABA8u, 0x442F5249u, "cop1? not lowered yet"); return;
L_089CABB8:
    rt.unsupported(0x089CABB8u, 0x6E756F73u, "vfpu3 not lowered yet"); return;
L_089CABD0:
    ctx.execute_vfpu_compare3(115u, 101u, 95u, 1u, 6u);
    rt.unsupported(0x089CABD4u, 0x72726576u, "unknown not lowered yet"); return;
L_089CABE0:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x02284090u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089CABF8:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x02284510u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089CAC10:
    rt.unsupported(0x089CAC10u, 0x4E554F53u, "unknown not lowered yet"); return;
L_089CAC20:
    rt.unsupported(0x089CAC20u, 0x4E554F53u, "unknown not lowered yet"); return;
L_089CAC38:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x0264C3D0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089CAC90:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x022871D0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089CACE8:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x022874B0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089CAE48:
    rt.unsupported(0x089CAE48u, 0x63696F76u, "vfpu0 not lowered yet"); return;
L_089CAE58:
    rt.unsupported(0x089CAE58u, 0x63696F76u, "vfpu0 not lowered yet"); return;
L_089CAE70:
    ctx.execute_vfpu_vscl_ct<109u, 101u, 116u, 1u>();
    rt.unsupported(0x089CAE74u, 0x706D2E72u, "unknown not lowered yet"); return;
L_089CAE7C:
    rt.unsupported(0x089CAE7Cu, 0x63696F76u, "vfpu0 not lowered yet"); return;
L_089CAE8C:
    rt.unsupported(0x089CAE8Cu, 0x63696F76u, "vfpu0 not lowered yet"); return;
L_089CAEA8:
    rt.unsupported(0x089CAEA8u, 0x63696F76u, "vfpu0 not lowered yet"); return;
L_089CAEB8:
    rt.unsupported(0x089CAEB8u, 0x79746972u, "unknown not lowered yet"); return;
L_089CAECC:
    rt.unsupported(0x089CAECCu, 0x63696F76u, "vfpu0 not lowered yet"); return;
L_089CAEF8:
    rt.unsupported(0x089CAEF8u, 0x45464645u, "cop1? not lowered yet"); return;
L_089CAF0C:
    rt.unsupported(0x089CAF0Cu, 0x45464645u, "cop1? not lowered yet"); return;
L_089CAF18:
    rt.unsupported(0x089CAF18u, 0x454D204Du, "cop1? not lowered yet"); return;
L_089CAF24:
    // nop
    goto L_089CAF28;
L_089CAF28:
    rt.unsupported(0x089CAF28u, 0x69736572u, "unknown not lowered yet"); return;
L_089CAF38:
    ctx.execute_vfpu_vscl_ct<101u, 102u, 102u, 1u>();
    rt.unsupported(0x089CAF3Cu, 0x722F7463u, "unknown not lowered yet"); return;
L_089CAF58:
    ctx.execute_vfpu_vscl_ct<101u, 102u, 102u, 1u>();
    ctx.gpr[15] = (ctx.gpr[9] + static_cast<std::uint32_t>(29795));
    rt.unsupported(0x089CAF60u, 0x706D2E73u, "unknown not lowered yet"); return;
L_089CAF68:
    // nop
    // nop
    // nop
    rt.unsupported(0x089CAF78u, 0x45464645u, "cop1? not lowered yet"); return;
    ctx.pc = 0x022993D0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089CAF78:
    rt.unsupported(0x089CAF78u, 0x45464645u, "cop1? not lowered yet"); return;
L_089CAF94:
    rt.unsupported(0x089CAF94u, 0x45464645u, "cop1? not lowered yet"); return;
L_089CAFB0:
    rt.unsupported(0x089CAFB0u, 0x45464645u, "cop1? not lowered yet"); return;
L_089CAFCC:
    rt.unsupported(0x089CAFCCu, 0x45464645u, "cop1? not lowered yet"); return;
L_089CAFE8:
    rt.unsupported(0x089CAFE8u, 0x45464645u, "cop1? not lowered yet"); return;
L_089CB004:
    rt.unsupported(0x089CB004u, 0x45464645u, "cop1? not lowered yet"); return;
L_089CB020:
    rt.unsupported(0x089CB020u, 0x45464645u, "cop1? not lowered yet"); return;
L_089CB03C:
    rt.unsupported(0x089CB03Cu, 0x45464645u, "cop1? not lowered yet"); return;
L_089CB05C:
    rt.unsupported(0x089CB05Cu, 0x45464645u, "cop1? not lowered yet"); return;
L_089CB104:
    // nop
    if (0u == 0u) (void)(0u);
    rt.unsupported(0x089CB10Cu, 0x00000001u, "special? not lowered yet"); return;
L_089CB188:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x022A01F0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089CB1B0:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x022A0530u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089CB1F8:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x022A06A0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089CB228:
    rt.unsupported(0x089CB228u, 0x41504546u, "unknown not lowered yet"); return;
L_089CB238:
    ctx.gpr[18] = (ctx.gpr[18] ^ 17735u);
    rt.unsupported(0x089CB23Cu, 0x69614D3Au, "unknown not lowered yet"); return;
L_089CB248:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x0264C3D0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089CB290:
    (void)(ctx.hi);
    // nop
    goto L_089CB298;
L_089CB298:
    rt.unsupported(0x089CB298u, 0x74737973u, "unknown not lowered yet"); return;
L_089CB2AC:
    rt.unsupported(0x089CB2ACu, 0x74746162u, "unknown not lowered yet"); return;
L_089CB2C4:
    ctx.execute_vfpu_compare3(97u, 114u, 114u, 1u, 6u);
    ctx.execute_vfpu_vhdp(119u, 45u, 101u, 1u);
    ctx.execute_vfpu_vminmax(102u, 101u, 46u, 1u, false);
    rt.unsupported(0x089CB2D0u, 0x00006B70u, "special? not lowered yet"); return;
L_089CB2D4:
    rt.unsupported(0x089CB2D4u, 0x73797263u, "unknown not lowered yet"); return;
L_089CB2E8:
    rt.unsupported(0x089CB2E8u, 0x69736564u, "unknown not lowered yet"); return;
L_089CB2F8:
    rt.unsupported(0x089CB2F8u, 0x74746162u, "unknown not lowered yet"); return;
L_089CB314:
    ctx.execute_vfpu_vscl_ct<101u, 102u, 102u, 1u>();
    rt.unsupported(0x089CB318u, 0x732F7463u, "unknown not lowered yet"); return;
L_089CB334:
    ctx.execute_vfpu_vscl_ct<101u, 102u, 102u, 1u>();
    rt.unsupported(0x089CB338u, 0x732F7463u, "unknown not lowered yet"); return;
L_089CB354:
    (void)(0u < 0u ? 1u : 0u);
    goto L_089CB358;
L_089CB358:
    rt.unsupported(0x089CB35Cu, 0x5C45F890u, "control flow in delay slot"); return;
L_089CB360:
    ctx.gpr[25] = (ctx.gpr[14] ^ 12206u);
    { const bool branch_taken = static_cast<std::int32_t>(0u) <= 0;
    { float vfpu_s[4]{}, vfpu_t[4]{}, vfpu_d[4]{};
      ctx.read_vfpu_vector_with_source_prefix_ct<48u, 1u, 0u>(vfpu_s);
      ctx.read_vfpu_vector_with_source_prefix_ct<52u, 1u, 1u>(vfpu_t);
      for (std::uint32_t i = 0; i < 1u; ++i) vfpu_d[i] = vfpu_s[i] * vfpu_t[i];
      ctx.write_vfpu_vector_with_destination_prefix_ct<37u, 1u>(vfpu_d); }
      if (branch_taken) {
          (void)rt.invoke_chained_direct<&recomp_unit_0014, 14u>(ctx, &aot_mem); return;
      }
      goto L_089CB36C;
    }
L_089CB36C:
    ctx.gpr[16] = (ctx.gpr[17] & 9519u);
    ctx.gpr[5] = (ctx.gpr[1] & 12132u);
    (void)(ctx.gpr[9] + static_cast<std::uint32_t>(25650));
    ctx.gpr[5] = (ctx.gpr[1] & 14948u);
    ctx.gpr[26] = (ctx.gpr[9] + static_cast<std::uint32_t>(25650));
    rt.unsupported(0x089CB380u, 0x00643230u, "special? not lowered yet"); return;
L_089CB3BC:
    ctx.execute_vfpu_vminmax(102u, 97u, 116u, 1u, false);
    rt.unsupported(0x089CB3C0u, 0x003A3073u, "special? not lowered yet"); return;
L_089CB3D8:
    rt.unsupported(0x089CB3D8u, 0x46816425u, "cop1? not lowered yet"); return;
L_089CB3E8:
    ctx.gpr[5] = (ctx.gpr[1] & 29477u);
    rt.unsupported(0x089CB3ECu, 0x00006432u, "special? not lowered yet"); return;
L_089CB3F0:
    ctx.execute_vfpu_vscl_ct<71u, 97u, 109u, 1u>();
    rt.unsupported(0x089CB3F4u, 0x61746144u, "vfpu0 not lowered yet"); return;
L_089CB3FC:
    ctx.execute_vfpu_vscl_ct<71u, 97u, 109u, 1u>();
    rt.unsupported(0x089CB400u, 0x61746144u, "vfpu0 not lowered yet"); return;
L_089CB408:
    rt.unsupported(0x089CB408u, 0x61647055u, "vfpu0 not lowered yet"); return;
L_089CB410:
    rt.unsupported(0x089CB410u, 0x63657053u, "vfpu0 not lowered yet"); return;
L_089CB428:
    rt.unsupported(0x089CB428u, 0x2077656Eu, "unknown not lowered yet"); return;
L_089CB434:
    if (0u == 0u) (void)(0u);
    { float vfpu_s[4]{}, vfpu_t[4]{}, vfpu_d[4]{};
      ctx.read_vfpu_vector_with_source_prefix_ct<48u, 1u, 0u>(vfpu_s);
      ctx.read_vfpu_vector_with_source_prefix_ct<52u, 1u, 1u>(vfpu_t);
      for (std::uint32_t i = 0; i < 1u; ++i) vfpu_d[i] = vfpu_s[i] * vfpu_t[i];
      ctx.write_vfpu_vector_with_destination_prefix_ct<37u, 1u>(vfpu_d); }
    ctx.gpr[16] = (ctx.gpr[17] & 9519u);
    ctx.gpr[5] = (ctx.gpr[1] & 12132u);
    (void)(ctx.gpr[9] + static_cast<std::uint32_t>(25650));
    ctx.gpr[5] = (ctx.gpr[1] & 14948u);
    rt.unsupported(0x089CB44Cu, 0x00006432u, "special? not lowered yet"); return;
L_089CB480:
    rt.unsupported(0x089CB480u, 0x4B206425u, "cop2/vfpu not lowered yet"); return;
L_089CB488:
    rt.unsupported(0x089CB488u, 0x4E4F4349u, "unknown not lowered yet"); return;
L_089CB494:
    rt.unsupported(0x089CB494u, 0x4E4F4349u, "unknown not lowered yet"); return;
L_089CB4A4:
    ctx.execute_vfpu_compare3(97u, 117u, 116u, 1u, 6u);
    rt.unsupported(0x089CB4A8u, 0x7661735Fu, "unknown not lowered yet"); return;
L_089CB4B4:
    ctx.execute_vfpu_vscl_ct<115u, 97u, 118u, 1u>();
    rt.unsupported(0x089CB4B8u, 0x7461645Fu, "unknown not lowered yet"); return;
L_089CB4C4:
    if (ctx.gpr[26] == ctx.gpr[19]) {
    rt.unsupported(0x089CB4C8u, 0x41494449u, "unknown not lowered yet"); return;
        (void)rt.invoke_chained_direct<&recomp_unit_0014, 14u>(ctx, &aot_mem); return;
    }
    goto L_089CB4CC;
L_089CB4CC:
    rt.unsupported(0x089CB4CCu, 0x4E49422Eu, "unknown not lowered yet"); return;
L_089CB4D4:
    ctx.execute_vfpu_compare3(109u, 101u, 109u, 1u, 6u);
    rt.unsupported(0x089CB4D8u, 0x73207972u, "unknown not lowered yet"); return;
L_089CB538:
    // vflush: architectural no-op that retains VFPU prefixes
    // vflush: architectural no-op that retains VFPU prefixes
    (void)(~(0u | 0u));
    (void)(static_cast<std::uint32_t>(std::countl_zero(0u)));
    rt.unsupported(0x089CB548u, 0x00000028u, "special? not lowered yet"); return;
L_089CB650:
    rt.unsupported(0x089CB650u, 0x0000003Eu, "special? not lowered yet"); return;
L_089CB680:
    rt.unsupported(0x089CB680u, 0x00000074u, "special? not lowered yet"); return;
L_089CB6E8:
    rt.unsupported(0x089CB6E8u, 0x61647055u, "vfpu0 not lowered yet"); return;
L_089CB6F8:
    rt.unsupported(0x089CB6F8u, 0x4B206425u, "cop2/vfpu not lowered yet"); return;
L_089CB700:
    { float vfpu_s[4]{}, vfpu_t[4]{}, vfpu_d[4]{};
      ctx.read_vfpu_vector_with_source_prefix_ct<48u, 1u, 0u>(vfpu_s);
      ctx.read_vfpu_vector_with_source_prefix_ct<50u, 1u, 1u>(vfpu_t);
      for (std::uint32_t i = 0; i < 1u; ++i) vfpu_d[i] = vfpu_s[i] * vfpu_t[i];
      ctx.write_vfpu_vector_with_destination_prefix_ct<37u, 1u>(vfpu_d); }
    // nop
    goto L_089CB708;
L_089CB708:
    aot_mem.aot_store32(ctx.gpr[27] + static_cast<std::uint32_t>(6016), std::bit_cast<std::uint32_t>(ctx.fpr[11]));
    aot_mem.aot_store32(ctx.gpr[18] + static_cast<std::uint32_t>(-23569), std::bit_cast<std::uint32_t>(ctx.fpr[26]));
    ctx.execute_vfpu_vscl_ct<12u, 29u, 13u, 4u>();
    ctx.gpr[8] = (aot_mem.aot_load8(ctx.gpr[11] + static_cast<std::uint32_t>(7511)));
    goto L_089CB718;
L_089CB718:
    rt.unsupported(0x089CB718u, 0x4C504552u, "unknown not lowered yet"); return;
L_089CB724:
    ctx.execute_vfpu_vcmp_ct<101u, 112u, 1u, 2u>();
    goto L_089CB728;
L_089CB728:
    ctx.gpr[15] = (0u + 0u);
    goto L_089CB72C;
L_089CB72C:
    ctx.execute_vfpu_vscl_ct<115u, 97u, 118u, 1u>();
    ctx.gpr[16] = (ctx.gpr[26] < static_cast<std::uint32_t>(18991) ? 1u : 0u);
    rt.unsupported(0x089CB734u, 0x4E4F4349u, "unknown not lowered yet"); return;
L_089CB740:
    ctx.execute_vfpu_vscl_ct<115u, 97u, 118u, 1u>();
    ctx.gpr[16] = (ctx.gpr[26] < static_cast<std::uint32_t>(18991) ? 1u : 0u);
    rt.unsupported(0x089CB748u, 0x4E4F4349u, "unknown not lowered yet"); return;
L_089CB758:
    if (0u == 0u) (void)(0u);
    // nop
    goto L_089CB760;
L_089CB760:
    rt.unsupported(0x089CB760u, 0x61647055u, "vfpu0 not lowered yet"); return;
L_089CB768:
    rt.unsupported(0x089CB768u, 0x4C495455u, "unknown not lowered yet"); return;
L_089CB770:
    rt.unsupported(0x089CB770u, 0x61647055u, "vfpu0 not lowered yet"); return;
L_089CB774:
    rt.unsupported(0x089CB774u, 0x00006574u, "special? not lowered yet"); return;
L_089CB778:
    ctx.execute_vfpu_vcmp_ct<98u, 105u, 1u, 1u>();
    ctx.gpr[25] = (ctx.gpr[19] < static_cast<std::uint32_t>(29801) ? 1u : 0u);
    { const bool signed_ok = ctx.execute_signed_sub(13u, 3u, 14u);
      if (!signed_ok) { rt.arithmetic_overflow(0x089CB780u, 0x006E6962u); return; } }
    // nop
    goto L_089CB788;
L_089CB788:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x022C7DF0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089CB7A0:
    ctx.execute_vfpu_vscl_ct<97u, 99u, 99u, 1u>();
    rt.unsupported(0x089CB7A4u, 0x726F7373u, "unknown not lowered yet"); return;
L_089CB7B0:
    ctx.execute_vfpu_vscl_ct<97u, 99u, 99u, 1u>();
    rt.unsupported(0x089CB7B4u, 0x726F7373u, "unknown not lowered yet"); return;
L_089CB7C8:
    // nop
    // nop
    // nop
    rt.unsupported(0x089CB7D8u, 0x69737361u, "unknown not lowered yet"); return;
    ctx.pc = 0x022CE1A0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089CB7E8:
    // vflush: architectural no-op that retains VFPU prefixes
    rt.unsupported(0x089CB7ECu, 0x00000001u, "special? not lowered yet"); return;
L_089CB898:
    rt.unsupported(0x089CB898u, 0x70726863u, "unknown not lowered yet"); return;
L_089CB8A0:
    rt.unsupported(0x089CB8A0u, 0x706D6E65u, "unknown not lowered yet"); return;
L_089CB8A8:
    rt.unsupported(0x089CB8A8u, 0x70777267u, "unknown not lowered yet"); return;
L_089CB8B0:
    ctx.execute_vfpu_vminmax(101u, 113u, 112u, 1u, false);
    // nop
    goto L_089CB8B8;
L_089CB8B8:
    rt.unsupported(0x089CB8B8u, 0x61617165u, "vfpu0 not lowered yet"); return;
L_089CB8C0:
    ctx.execute_vfpu_compare3(101u, 113u, 97u, 1u, 6u);
    // nop
    goto L_089CB8C8;
L_089CB8C8:
    rt.unsupported(0x089CB8C8u, 0x74697165u, "unknown not lowered yet"); return;
L_089CB8D0:
    rt.unsupported(0x089CB8D0u, 0x63617165u, "vfpu0 not lowered yet"); return;
L_089CB8D8:
    rt.unsupported(0x089CB8D8u, 0x74636E66u, "unknown not lowered yet"); return;
L_089CB8E0:
    rt.unsupported(0x089CB8E0u, 0x73636E66u, "unknown not lowered yet"); return;
L_089CB8E8:
    rt.unsupported(0x089CB8E8u, 0x746C6261u, "unknown not lowered yet"); return;
L_089CB8F0:
    rt.unsupported(0x089CB8F0u, 0x72736361u, "unknown not lowered yet"); return;
L_089CB8F8:
    ctx.execute_vfpu_vminmax(105u, 116u, 101u, 1u, false);
    // nop
    goto L_089CB900;
L_089CB900:
    ctx.execute_vfpu_vcmp_ct<104u, 114u, 1u, 3u>();
    // nop
    goto L_089CB908;
L_089CB908:
    rt.unsupported(0x089CB908u, 0x73616D61u, "unknown not lowered yet"); return;
L_089CB910:
    { float vfpu_s[4]{}, vfpu_t[4]{}, vfpu_d[4]{};
      ctx.read_vfpu_vector_with_source_prefix_ct<114u, 1u, 0u>(vfpu_s);
      ctx.read_vfpu_vector_with_source_prefix_ct<119u, 1u, 1u>(vfpu_t);
      for (std::uint32_t i = 0; i < 1u; ++i) vfpu_d[i] = vfpu_s[i] * vfpu_t[i];
      ctx.write_vfpu_vector_with_destination_prefix_ct<98u, 1u>(vfpu_d); }
    // nop
    goto L_089CB918;
L_089CB918:
    rt.unsupported(0x089CB918u, 0x70626F6Au, "unknown not lowered yet"); return;
L_089CB920:
    rt.unsupported(0x089CB920u, 0x6E656761u, "vfpu3 not lowered yet"); return;
L_089CB928:
    ctx.execute_vfpu_compare3(97u, 99u, 99u, 1u, 6u);
    // nop
    goto L_089CB930;
L_089CB930:
    rt.unsupported(0x089CB930u, 0x62616361u, "vfpu0 not lowered yet"); return;
L_089CB938:
    rt.unsupported(0x089CB938u, 0x74696361u, "unknown not lowered yet"); return;
L_089CB940:
    rt.unsupported(0x089CB940u, 0x63616361u, "vfpu0 not lowered yet"); return;
L_089CB948:
    rt.unsupported(0x089CB948u, 0x73616361u, "unknown not lowered yet"); return;
L_089CB950:
    ctx.execute_vfpu_compare3(100u, 112u, 98u, 1u, 6u);
    // nop
    goto L_089CB958;
L_089CB958:
    rt.unsupported(0x089CB958u, 0x706C6163u, "unknown not lowered yet"); return;
L_089CB960:
    rt.unsupported(0x089CB960u, 0x7373696Du, "unknown not lowered yet"); return;
L_089CB968:
    rt.unsupported(0x089CB968u, 0x70796C70u, "unknown not lowered yet"); return;
L_089CB970:
    rt.unsupported(0x089CB970u, 0x70676F6Du, "unknown not lowered yet"); return;
L_089CB978:
    rt.unsupported(0x089CB978u, 0x63746573u, "vfpu0 not lowered yet"); return;
L_089CB980:
    rt.unsupported(0x089CB980u, 0x7074706Fu, "unknown not lowered yet"); return;
L_089CB988:
    rt.unsupported(0x089CB988u, 0x70666E69u, "unknown not lowered yet"); return;
L_089CB990:
    ctx.execute_vfpu_compare3(116u, 117u, 116u, 1u, 6u);
    // nop
    goto L_089CB998;
L_089CB998:
    rt.unsupported(0x089CB998u, 0x696C6572u, "unknown not lowered yet"); return;
L_089CB9A0:
    { float vfpu_s[4]{}, vfpu_t[4]{}, vfpu_d[4]{};
      ctx.read_vfpu_vector_with_source_prefix_ct<99u, 1u, 0u>(vfpu_s);
      ctx.read_vfpu_vector_with_source_prefix_ct<114u, 1u, 1u>(vfpu_t);
      for (std::uint32_t i = 0; i < 1u; ++i) vfpu_d[i] = vfpu_s[i] * vfpu_t[i];
      ctx.write_vfpu_vector_with_destination_prefix_ct<102u, 1u>(vfpu_d); }
    // nop
    goto L_089CB9A8;
L_089CB9A8:
    rt.unsupported(0x089CB9A8u, 0x6E636975u, "vfpu3 not lowered yet"); return;
L_089CB9B0:
    rt.unsupported(0x089CB9B0u, 0x756F6361u, "unknown not lowered yet"); return;
L_089CB9B8:
    ctx.execute_vfpu_vscl_ct<97u, 112u, 114u, 1u>();
    // nop
    goto L_089CB9C0;
L_089CB9C0:
    { float vfpu_s[4]{}, vfpu_t[4]{}, vfpu_d[4]{};
      ctx.read_vfpu_vector_with_source_prefix_ct<109u, 1u, 0u>(vfpu_s);
      ctx.read_vfpu_vector_with_source_prefix_ct<111u, 1u, 1u>(vfpu_t);
      for (std::uint32_t i = 0; i < 1u; ++i) vfpu_d[i] = vfpu_s[i] * vfpu_t[i];
      ctx.write_vfpu_vector_with_destination_prefix_ct<97u, 1u>(vfpu_d); }
    // nop
    goto L_089CB9C8;
L_089CB9C8:
    ctx.execute_vfpu_compare3(99u, 104u, 97u, 1u, 6u);
    // nop
    goto L_089CB9D0;
L_089CB9D0:
    rt.unsupported(0x089CB9D0u, 0x626F6A70u, "vfpu0 not lowered yet"); return;
L_089CB9D8:
    ctx.execute_vfpu_vcmp_ct<115u, 107u, 1u, 4u>();
    // nop
    goto L_089CB9E0;
L_089CB9E0:
    rt.unsupported(0x089CB9E0u, 0x7572726Fu, "unknown not lowered yet"); return;
L_089CB9E8:
    rt.unsupported(0x089CB9E8u, 0x006C6B73u, "special? not lowered yet"); return;
L_089CB9EC:
    rt.unsupported(0x089CB9ECu, 0x676E7564u, "vfpu1 not lowered yet"); return;
L_089CB9F8:
    rt.unsupported(0x089CB9F8u, 0x69622E6Cu, "unknown not lowered yet"); return;
L_089CBA00:
    rt.unsupported(0x089CBA00u, 0x676E7564u, "vfpu1 not lowered yet"); return;
L_089CBA0C:
    ctx.execute_vfpu_vscl_ct<108u, 95u, 104u, 1u>();
    rt.unsupported(0x089CBA10u, 0x622E706Cu, "vfpu0 not lowered yet"); return;
L_089CBA18:
    ctx.execute_vfpu_vscl_ct<102u, 114u, 105u, 1u>();
    rt.unsupported(0x089CBA1Cu, 0x635F646Eu, "vfpu0 not lowered yet"); return;
L_089CBA28:
    rt.unsupported(0x089CBA28u, 0x434E5546u, "unknown not lowered yet"); return;
L_089CBA38:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x022FDB20u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089CBA50:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x022FD700u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089CBA68:
    rt.unsupported(0x089CBA6Cu, 0x08070605u, "control flow in delay slot"); return;
L_089CBA70:
    rt.unsupported(0x089CBA74u, 0x100F0E0Du, "control flow in delay slot"); return;
L_089CBA78:
    rt.unsupported(0x089CBA7Cu, 0x19181615u, "control flow in delay slot"); return;
L_089CBA80:
    { const bool branch_taken = static_cast<std::int32_t>(ctx.gpr[8]) > 0;
    rt.unsupported(0x089CBA84u, 0x00201F1Eu, "special? not lowered yet"); return;
      if (branch_taken) {
          goto L_089D26EC;
      }
      goto L_089CBA88;
    }
L_089CBA88:
    ctx.execute_vfpu_vminmax(105u, 116u, 101u, 1u, false);
    rt.unsupported(0x089CBA8Cu, 0x6E69622Eu, "vfpu3 not lowered yet"); return;
L_089CBA94:
    ctx.execute_vfpu_vminmax(105u, 116u, 101u, 1u, false);
    ctx.execute_vfpu_vcmp_ct<104u, 101u, 1u, 15u>();
    rt.unsupported(0x089CBA9Cu, 0x69622E70u, "unknown not lowered yet"); return;
L_089CBAB0:
    rt.unsupported(0x089CBAB0u, 0x02DF02BCu, "special? not lowered yet"); return;
L_089CBB70:
    rt.unsupported(0x089CBB70u, 0x07050301u, "regimm? not lowered yet"); return;
L_089CBB7C:
    rt.unsupported(0x089CBB80u, 0x13110F0Du, "control flow in delay slot"); return;
L_089CBB9C:
    rt.unsupported(0x089CBB9Cu, 0x0000021Du, "special? not lowered yet"); return;
L_089CBBEC:
    (void)(ctx.gpr[15] + ctx.gpr[2]);
    (void)(ctx.gpr[15] & ctx.gpr[5]);
    (void)(ctx.gpr[15] ^ ctx.gpr[7]);
    rt.unsupported(0x089CBBF8u, 0x01E901E8u, "special? not lowered yet"); return;
L_089CBC38:
    // nop
    // nop
    // nop
    ctx.execute_vfpu_compare3(112u, 116u, 99u, 1u, 6u);
    ctx.pc = 0x0231AE90u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089CBC58:
    rt.unsupported(0x089CBC58u, 0x74726170u, "unknown not lowered yet"); return;
L_089CBC98:
    rt.unsupported(0x089CBC9Cu, 0x08070605u, "control flow in delay slot"); return;
L_089CBCA0:
    rt.unsupported(0x089CBCA4u, 0x100F0E0Du, "control flow in delay slot"); return;
L_089CBCA8:
    rt.unsupported(0x089CBCACu, 0x19181615u, "control flow in delay slot"); return;
L_089CBCB0:
    { const bool branch_taken = static_cast<std::int32_t>(ctx.gpr[8]) > 0;
    rt.unsupported(0x089CBCB4u, 0x00201F1Eu, "special? not lowered yet"); return;
      if (branch_taken) {
          goto L_089D291C;
      }
      goto L_089CBCB8;
    }
L_089CBCB8:
    rt.unsupported(0x089CBCB8u, 0x61657073u, "vfpu0 not lowered yet"); return;
L_089CBCC8:
    (void)(ctx.gpr[2] & ctx.gpr[26]);
    (void)(ctx.hi);
    rt.unsupported(0x089CBCD0u, 0x0032003Cu, "special? not lowered yet"); return;
L_089CBCE0:
    // nop
    // nop
    // nop
    rt.unsupported(0x089CBCF0u, 0x40A00000u, "unknown not lowered yet"); return;
    ctx.pc = 0x02332230u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089CBCF4:
    rt.unsupported(0x089CBCF4u, 0x61647055u, "vfpu0 not lowered yet"); return;
L_089CBD04:
    (void)(ctx.gpr[3] | ctx.gpr[4]);
    // nop
    // nop
    goto L_089CBD10;
L_089CBD10:
    // nop
    // nop
    // nop
    rt.unsupported(0x089CBD20u, 0x40A00000u, "unknown not lowered yet"); return;
    ctx.pc = 0x02335090u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089CBD24:
    rt.unsupported(0x089CBD24u, 0x61647055u, "vfpu0 not lowered yet"); return;
L_089CBD2C:
    rt.unsupported(0x089CBD2Cu, 0x74786574u, "unknown not lowered yet"); return;
L_089CBD50:
    // nop
    // nop
    // nop
    rt.unsupported(0x089CBD60u, 0x43F00000u, "unknown not lowered yet"); return;
    ctx.pc = 0x02337C60u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089CBD74:
    ctx.execute_vfpu_vcmp_ct<101u, 112u, 1u, 2u>();
    rt.unsupported(0x089CBD78u, 0x435F7961u, "unknown not lowered yet"); return;
L_089CBD84:
    rt.unsupported(0x089CBD84u, 0x77617244u, "unknown not lowered yet"); return;
L_089CBD90:
    // nop
    // nop
    // nop
    rt.unsupported(0x089CBDA0u, 0x40A00000u, "unknown not lowered yet"); return;
    ctx.pc = 0x02338DB0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089CBDA4:
    rt.unsupported(0x089CBDA4u, 0x61647055u, "vfpu0 not lowered yet"); return;
L_089CBDB0:
    // nop
    // nop
    (void)(0u >> 0u);
    goto L_089CBDBC;
L_089CBDBC:
    (void)(static_cast<std::uint32_t>(static_cast<std::int32_t>(0u) >> 0u));
    if (0u == 0u) (void)(0u);
    if (0u == 0u) (void)(0u);
    goto L_089CBDC8;
L_089CBDC8:
    // nop
    // vflush: architectural no-op that retains VFPU prefixes
    // vflush: architectural no-op that retains VFPU prefixes
    goto L_089CBDD4;
L_089CBDD4:
    if (ctx.gpr[10] != ctx.gpr[14]) {
    rt.unsupported(0x089CBDD8u, 0x4E414D20u, "unknown not lowered yet"); return;
        goto L_089DD30C;
    }
    goto L_089CBDDC;
L_089CBDDC:
    if (ctx.gpr[18] == ctx.gpr[5]) {
    // nop
        (void)rt.invoke_chained_direct<&recomp_unit_0014, 14u>(ctx, &aot_mem); return;
    }
    goto L_089CBDE4;
L_089CBDE4:
    if (ctx.gpr[10] != ctx.gpr[14]) {
    rt.unsupported(0x089CBDE8u, 0x4E414D5Fu, "unknown not lowered yet"); return;
        goto L_089DD31C;
    }
    goto L_089CBDEC;
L_089CBDEC:
    if (ctx.gpr[18] == ctx.gpr[5]) {
    rt.unsupported(0x089CBDF0u, 0x78453A3Au, "unknown not lowered yet"); return;
        (void)rt.invoke_chained_direct<&recomp_unit_0014, 14u>(ctx, &aot_mem); return;
    }
    goto L_089CBDF4;
L_089CBDF4:
    rt.unsupported(0x089CBDF4u, 0x74756365u, "unknown not lowered yet"); return;
L_089CBE00:
    if (ctx.gpr[10] != ctx.gpr[14]) {
    rt.unsupported(0x089CBE04u, 0x4E414D5Fu, "unknown not lowered yet"); return;
        goto L_089DD338;
    }
    goto L_089CBE08;
L_089CBE08:
    if (ctx.gpr[18] == ctx.gpr[5]) {
    rt.unsupported(0x089CBE0Cu, 0x72443A3Au, "unknown not lowered yet"); return;
        (void)rt.invoke_chained_direct<&recomp_unit_0014, 14u>(ctx, &aot_mem); return;
    }
    goto L_089CBE10;
L_089CBE10:
    ctx.gpr[14] = (0u + 0u);
    goto L_089CBE14;
L_089CBE14:
    if (ctx.gpr[10] != ctx.gpr[14]) {
    rt.unsupported(0x089CBE18u, 0x4E414D5Fu, "unknown not lowered yet"); return;
        goto L_089DD34C;
    }
    goto L_089CBE1C;
L_089CBE1C:
    if (ctx.gpr[18] == ctx.gpr[5]) {
    rt.unsupported(0x089CBE20u, 0x72443A3Au, "unknown not lowered yet"); return;
        (void)rt.invoke_chained_direct<&recomp_unit_0014, 14u>(ctx, &aot_mem); return;
    }
    goto L_089CBE24;
L_089CBE24:
    ctx.execute_vfpu_vhdp(97u, 119u, 65u, 1u);
    rt.unsupported(0x089CBE28u, 0x00726574u, "special? not lowered yet"); return;
L_089CBE2C:
    rt.unsupported(0x089CBE2Cu, 0x6E756F73u, "vfpu3 not lowered yet"); return;
L_089CBE40:
    if (static_cast<std::int32_t>(ctx.gpr[27]) > 0) {
    rt.unsupported(0x089CBE44u, 0x756E656Du, "unknown not lowered yet"); return;
        (void)rt.invoke_chained_direct<&recomp_unit_0015, 15u>(ctx, &aot_mem); return;
    }
    goto L_089CBE48;
L_089CBE48:
    { float vfpu_s[4]{}, vfpu_t[4]{}, vfpu_d[4]{};
      ctx.read_vfpu_vector_with_source_prefix_ct<115u, 1u, 0u>(vfpu_s);
      ctx.read_vfpu_vector_with_source_prefix_ct<99u, 1u, 1u>(vfpu_t);
      for (std::uint32_t i = 0; i < 1u; ++i) vfpu_d[i] = vfpu_s[i] * vfpu_t[i];
      ctx.write_vfpu_vector_with_destination_prefix_ct<46u, 1u>(vfpu_d); }
    // nop
    goto L_089CBE50;
L_089CBE50:
    ctx.gpr[4] = (ctx.hi);
    ctx.hi = 0u;
    ctx.gpr[4] = (ctx.lo);
    // nop
    goto L_089CBE60;
L_089CBE60:
    ctx.gpr[4] = (ctx.hi);
    ctx.hi = 0u;
    ctx.gpr[4] = (ctx.lo);
    rt.unsupported(0x089CBE6Cu, 0x00061A81u, "special? not lowered yet"); return;
L_089CBF04:
    rt.unsupported(0x089CBF04u, 0x00000001u, "special? not lowered yet"); return;
L_089CC00C:
    (void)(static_cast<std::uint32_t>(static_cast<std::int32_t>(ctx.gpr[4]) >> 0u));
    rt.unsupported(0x089CC010u, 0x00060005u, "special? not lowered yet"); return;
L_089CC020:
    // vflush: architectural no-op that retains VFPU prefixes
    // nop
    rt.unsupported(0x089CC028u, 0x00000001u, "special? not lowered yet"); return;
L_089CC0A4:
    ctx.gpr[13] = (ctx.gpr[27] < static_cast<std::uint32_t>(26466) ? 1u : 0u);
    ctx.gpr[14] = (0u | 0u);
    // nop
    goto L_089CC0B0;
L_089CC0B0:
    // nop
    // nop
    // nop
    rt.unsupported(0x089CC0C0u, 0x61647055u, "vfpu0 not lowered yet"); return;
    ctx.pc = 0x0235B3F0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089CC0C0:
    rt.unsupported(0x089CC0C0u, 0x61647055u, "vfpu0 not lowered yet"); return;
L_089CC0C8:
    // nop
    // nop
    // nop
    rt.unsupported(0x089CC0D8u, 0x0000000Du, "special? not lowered yet"); return;
    ctx.pc = 0x0235EDD0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089CC0D8:
    rt.unsupported(0x089CC0D8u, 0x0000000Du, "special? not lowered yet"); return;
L_089CC0F0:
    (void)(static_cast<std::uint32_t>(static_cast<std::int32_t>(0u) >> (0u & 31u)));
    (void)(0u >> (0u & 31u));
    rt.unsupported(0x089CC0F8u, 0x00000005u, "special? not lowered yet"); return;
L_089CC110:
    rt.unsupported(0x089CC110u, 0x0000000Du, "special? not lowered yet"); return;
L_089CC128:
    (void)(static_cast<std::uint32_t>(static_cast<std::int32_t>(0u) >> (0u & 31u)));
    (void)(0u >> (0u & 31u));
    rt.unsupported(0x089CC130u, 0x00000005u, "special? not lowered yet"); return;
L_089CC148:
    rt.unsupported(0x089CC148u, 0x0000000Du, "special? not lowered yet"); return;
L_089CC160:
    (void)(static_cast<std::uint32_t>(static_cast<std::int32_t>(0u) >> (0u & 31u)));
    (void)(0u >> (0u & 31u));
    rt.unsupported(0x089CC168u, 0x00000005u, "special? not lowered yet"); return;
L_089CC180:
    rt.unsupported(0x089CC180u, 0x0000000Du, "special? not lowered yet"); return;
L_089CC188:
    // nop
    // nop
    // nop
    (void)(ctx.hi);
    ctx.pc = 0x0235FEA0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089CC1C0:
    // nop
    // nop
    // nop
    rt.unsupported(0x089CC1D0u, 0x40A00000u, "unknown not lowered yet"); return;
    ctx.pc = 0x023614F0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089CC1D8:
    // nop
    // nop
    // nop
    rt.unsupported(0x089CC1E8u, 0x0000000Du, "special? not lowered yet"); return;
    ctx.pc = 0x023626E0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089CC1E8:
    rt.unsupported(0x089CC1E8u, 0x0000000Du, "special? not lowered yet"); return;
L_089CC200:
    (void)(static_cast<std::uint32_t>(static_cast<std::int32_t>(0u) >> (0u & 31u)));
    goto L_089CC204;
L_089CC204:
    rt.unsupported(0x089CC204u, 0x0000000Du, "special? not lowered yet"); return;
L_089CC21C:
    (void)(static_cast<std::uint32_t>(static_cast<std::int32_t>(0u) >> (0u & 31u)));
    goto L_089CC220;
L_089CC220:
    rt.unsupported(0x089CC220u, 0x0000000Du, "special? not lowered yet"); return;
L_089CC238:
    (void)(static_cast<std::uint32_t>(static_cast<std::int32_t>(0u) >> (0u & 31u)));
    // nop
    goto L_089CC240;
L_089CC240:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x02364740u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089CC250:
    // nop
    // nop
    // nop
    rt.unsupported(0x089CC260u, 0x40490FDBu, "unknown not lowered yet"); return;
    ctx.pc = 0x02365B90u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089CC268:
    (void)(0u << 1u);
    rt.unsupported(0x089CC26Cu, 0x0000005Cu, "special? not lowered yet"); return;
L_089CC270:
    (void)(ctx.hi);
    (void)(static_cast<std::int32_t>(0u) > static_cast<std::int32_t>(0u) ? 0u : 0u);
    rt.unsupported(0x089CC278u, 0x0000001Cu, "special? not lowered yet"); return;
L_089CC290:
    // nop
    // nop
    // nop
    rt.unsupported(0x089CC2A0u, 0x61647055u, "vfpu0 not lowered yet"); return;
    ctx.pc = 0x02378B10u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089CC2A0:
    rt.unsupported(0x089CC2A0u, 0x61647055u, "vfpu0 not lowered yet"); return;
L_089CC2A8:
    // nop
    // nop
    // nop
    rt.unsupported(0x089CC2B8u, 0x00000001u, "special? not lowered yet"); return;
    ctx.pc = 0x0237A5A0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089CC2B8:
    rt.unsupported(0x089CC2B8u, 0x00000001u, "special? not lowered yet"); return;
L_089CC2C0:
    rt.unsupported(0x089CC2C0u, 0x00000001u, "special? not lowered yet"); return;
L_089CC2C8:
    rt.unsupported(0x089CC2C8u, 0x00000001u, "special? not lowered yet"); return;
L_089CC2D0:
    // nop
    // nop
    // nop
    rt.unsupported(0x089CC2E0u, 0x00000001u, "special? not lowered yet"); return;
    ctx.pc = 0x0237B2C0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089CC2E0:
    rt.unsupported(0x089CC2E0u, 0x00000001u, "special? not lowered yet"); return;
L_089CC2E8:
    rt.unsupported(0x089CC2E8u, 0x00000001u, "special? not lowered yet"); return;
L_089CC2F0:
    rt.unsupported(0x089CC2F0u, 0x00000001u, "special? not lowered yet"); return;
L_089CC2F8:
    (void)(static_cast<std::uint32_t>(static_cast<std::int32_t>(0u) >> (0u & 31u)));
    (void)(0u >> (0u & 31u));
    (void)(0u << (0u & 31u));
    rt.unsupported(0x089CC304u, 0x00000005u, "special? not lowered yet"); return;
L_089CC308:
    // nop
    // nop
    // nop
    (void)(0u << 1u);
    ctx.pc = 0x0237C210u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089CC330:
    // nop
    // nop
    // nop
    rt.unsupported(0x089CC340u, 0x40A00000u, "unknown not lowered yet"); return;
    ctx.pc = 0x0237D360u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089CC348:
    ctx.gpr[13] = (ctx.gpr[18] ^ 17748u);
    rt.unsupported(0x089CC34Cu, 0x4D454D3Au, "unknown not lowered yet"); return;
L_089CC358:
    // nop
    // nop
    // nop
    rt.unsupported(0x089CC368u, 0x6E756F73u, "vfpu3 not lowered yet"); return;
    ctx.pc = 0x0237F650u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089CC37C:
    rt.unsupported(0x089CC37Cu, 0x74786574u, "unknown not lowered yet"); return;
L_089CC384:
    rt.unsupported(0x089CC384u, 0x6B6C6174u, "unknown not lowered yet"); return;
L_089CC4A0:
    rt.unsupported(0x089CC4A4u, 0x088E2980u, "control flow in delay slot"); return;
L_089CC538:
    // nop
    // nop
    // nop
    rt.unsupported(0x089CC548u, 0x756E656Du, "unknown not lowered yet"); return;
    ctx.pc = 0x0238AB20u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089CC548:
    rt.unsupported(0x089CC548u, 0x756E656Du, "unknown not lowered yet"); return;
L_089CC568:
    rt.unsupported(0x089CC568u, 0x756E656Du, "unknown not lowered yet"); return;
L_089CC58C:
    rt.unsupported(0x089CC58Cu, 0x74786574u, "unknown not lowered yet"); return;
L_089CC59C:
    rt.unsupported(0x089CC59Cu, 0x7165732Eu, "unknown not lowered yet"); return;
L_089CC5A8:
    rt.unsupported(0x089CC5A8u, 0x0065732Eu, "special? not lowered yet"); return;
L_089CC5AC:
    ctx.execute_vfpu_vminmax(46u, 103u, 105u, 1u, false);
    // nop
    goto L_089CC5B4;
L_089CC5B4:
    rt.unsupported(0x089CC5B4u, 0x6E69622Eu, "vfpu3 not lowered yet"); return;
L_089CC610:
    // nop
    // nop
    // nop
    rt.unsupported(0x089CC620u, 0x40490FDBu, "unknown not lowered yet"); return;
    ctx.pc = 0x02396C10u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089CC710:
    // nop
    // nop
    // nop
    rt.unsupported(0x089CC720u, 0x40400000u, "unknown not lowered yet"); return;
    ctx.pc = 0x02399AD0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089CC72C:
    ctx.gpr[13] = (ctx.gpr[27] < static_cast<std::uint32_t>(26466) ? 1u : 0u);
    ctx.gpr[14] = (0u | 0u);
    // nop
    goto L_089CC738;
L_089CC738:
    // nop
    // nop
    // nop
    rt.unsupported(0x089CC748u, 0x40490FDBu, "unknown not lowered yet"); return;
    ctx.pc = 0x0239B860u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089CC7A0:
    // nop
    // nop
    // nop
    rt.unsupported(0x089CC7B0u, 0x7773616Du, "unknown not lowered yet"); return;
    ctx.pc = 0x023A07F0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089CC7B0:
    rt.unsupported(0x089CC7B0u, 0x7773616Du, "unknown not lowered yet"); return;
L_089CC7B8:
    ctx.gpr[16] = (ctx.gpr[27] < static_cast<std::uint32_t>(24941) ? 1u : 0u);
    rt.unsupported(0x089CC7BCu, 0x6170616Du, "vfpu0 not lowered yet"); return;
L_089CC7CC:
    if (static_cast<std::int32_t>(ctx.gpr[27]) > 0) {
    ctx.gpr[31] = (ctx.gpr[10] + static_cast<std::uint32_t>(25971));
        (void)rt.invoke_chained_direct<&recomp_unit_0015, 15u>(ctx, &aot_mem); return;
    }
    goto L_089CC7D4;
L_089CC7D4:
    rt.unsupported(0x089CC7D4u, 0x74725F73u, "unknown not lowered yet"); return;
L_089CC7E0:
    rt.unsupported(0x089CC7E0u, 0x72616373u, "unknown not lowered yet"); return;
L_089CC7F0:
    rt.unsupported(0x089CC7F0u, 0x63656970u, "vfpu0 not lowered yet"); return;
L_089CC800:
    rt.unsupported(0x089CC800u, 0x626F662Eu, "vfpu0 not lowered yet"); return;
L_089CC808:
    rt.unsupported(0x089CC808u, 0x672E7325u, "vfpu1 not lowered yet"); return;
L_089CC810:
    ctx.execute_vfpu_compare3(37u, 115u, 46u, 1u, 6u);
    { const bool signed_ok = ctx.execute_signed_sub(13u, 3u, 24u);
      if (!signed_ok) { rt.arithmetic_overflow(0x089CC814u, 0x00786A62u); return; } }
    ctx.execute_vfpu_vminmax(114u, 116u, 46u, 1u, false);
    rt.unsupported(0x089CC81Cu, 0x00006B70u, "special? not lowered yet"); return;
L_089CC820:
    rt.unsupported(0x089CC820u, 0x6B6C6174u, "unknown not lowered yet"); return;
L_089CC834:
    rt.unsupported(0x089CC834u, 0x6E69614Du, "vfpu3 not lowered yet"); return;
L_089CC840:
    rt.unsupported(0x089CC840u, 0x77617244u, "unknown not lowered yet"); return;
L_089CC84C:
    rt.unsupported(0x089CC84Cu, 0x77617244u, "unknown not lowered yet"); return;
L_089CC85C:
    rt.unsupported(0x089CC85Cu, 0x77617244u, "unknown not lowered yet"); return;
L_089CC870:
    if (static_cast<std::int32_t>(ctx.gpr[27]) > 0) {
    rt.unsupported(0x089CC874u, 0x71696E75u, "unknown not lowered yet"); return;
        (void)rt.invoke_chained_direct<&recomp_unit_0015, 15u>(ctx, &aot_mem); return;
    }
    goto L_089CC878;
L_089CC878:
    ctx.gpr[26] = (ctx.gpr[17] ^ 25973u);
    rt.unsupported(0x089CC880u, 0x51494E55u, "control flow in delay slot"); return;
L_089CC884:
    rt.unsupported(0x089CC884u, 0x4D5F4555u, "unknown not lowered yet"); return;
L_089CC898:
    if (static_cast<std::int32_t>(ctx.gpr[27]) > 0) {
    rt.unsupported(0x089CC89Cu, 0x71696E75u, "unknown not lowered yet"); return;
        (void)rt.invoke_chained_direct<&recomp_unit_0015, 15u>(ctx, &aot_mem); return;
    }
    goto L_089CC8A0;
L_089CC8A0:
    ctx.gpr[26] = (ctx.gpr[17] ^ 25973u);
    rt.unsupported(0x089CC8A8u, 0x51494E55u, "control flow in delay slot"); return;
L_089CC8AC:
    rt.unsupported(0x089CC8ACu, 0x4D5F4555u, "unknown not lowered yet"); return;
L_089CC8C4:
    if (static_cast<std::int32_t>(ctx.gpr[27]) > 0) {
    rt.unsupported(0x089CC8C8u, 0x71696E75u, "unknown not lowered yet"); return;
        (void)rt.invoke_chained_direct<&recomp_unit_0015, 15u>(ctx, &aot_mem); return;
    }
    goto L_089CC8CC;
L_089CC8CC:
    ctx.gpr[26] = (ctx.gpr[17] ^ 25973u);
    rt.unsupported(0x089CC8D4u, 0x51494E55u, "control flow in delay slot"); return;
L_089CC8D8:
    rt.unsupported(0x089CC8D8u, 0x4D5F4555u, "unknown not lowered yet"); return;
L_089CC8F0:
    if (static_cast<std::int32_t>(ctx.gpr[27]) > 0) {
    rt.unsupported(0x089CC8F4u, 0x71696E75u, "unknown not lowered yet"); return;
        (void)rt.invoke_chained_direct<&recomp_unit_0015, 15u>(ctx, &aot_mem); return;
    }
    goto L_089CC8F8;
L_089CC8F8:
    ctx.gpr[26] = (ctx.gpr[17] ^ 25973u);
    rt.unsupported(0x089CC900u, 0x51494E55u, "control flow in delay slot"); return;
L_089CC904:
    rt.unsupported(0x089CC904u, 0x4D5F4555u, "unknown not lowered yet"); return;
L_089CC918:
    ctx.gpr[10] = (ctx.gpr[19] ^ 25199u);
    rt.unsupported(0x089CC91Cu, 0x4F52503Au, "unknown not lowered yet"); return;
L_089CC92C:
    if (ctx.gpr[18] == ctx.gpr[5]) {
    rt.unsupported(0x089CC930u, 0x70553A3Au, "unknown not lowered yet"); return;
        (void)rt.invoke_chained_direct<&recomp_unit_0014, 14u>(ctx, &aot_mem); return;
    }
    goto L_089CC934;
L_089CC934:
    ctx.execute_vfpu_vscl_ct<100u, 97u, 116u, 1u>();
    // nop
    goto L_089CC93C;
L_089CC93C:
    ctx.gpr[10] = (ctx.gpr[19] ^ 25199u);
    rt.unsupported(0x089CC940u, 0x4F52503Au, "unknown not lowered yet"); return;
L_089CC950:
    if (ctx.gpr[18] == ctx.gpr[5]) {
    rt.unsupported(0x089CC954u, 0x72443A3Au, "unknown not lowered yet"); return;
        (void)rt.invoke_chained_direct<&recomp_unit_0014, 14u>(ctx, &aot_mem); return;
    }
    goto L_089CC958;
L_089CC958:
    ctx.gpr[14] = (0u + 0u);
    goto L_089CC95C;
L_089CC95C:
    if (ctx.gpr[2] != ctx.gpr[16]) {
    rt.unsupported(0x089CC960u, 0x4C425F48u, "unknown not lowered yet"); return;
        (void)rt.invoke_chained_direct<&recomp_unit_0014, 14u>(ctx, &aot_mem); return;
    }
    goto L_089CC964;
L_089CC964:
    ctx.gpr[26] = (ctx.gpr[17] ^ 21077u);
    rt.unsupported(0x089CC968u, 0x77617244u, "unknown not lowered yet"); return;
L_089CC970:
    rt.unsupported(0x089CC970u, 0x49504553u, "cop2/vfpu not lowered yet"); return;
L_089CC97C:
    rt.unsupported(0x089CC97Cu, 0x63657845u, "vfpu0 not lowered yet"); return;
L_089CC9A8:
    // nop
    // nop
    // nop
    rt.unsupported(0x089CC9B8u, 0x61746164u, "vfpu0 not lowered yet"); return;
    ctx.pc = 0x023A8B70u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089CC9B8:
    rt.unsupported(0x089CC9B8u, 0x61746164u, "vfpu0 not lowered yet"); return;
L_089CC9C8:
    // nop
    // nop
    // nop
    ctx.execute_vfpu_vscl_ct<114u, 116u, 95u, 1u>();
    ctx.pc = 0x023A9D80u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089CC9D8:
    ctx.execute_vfpu_vscl_ct<114u, 116u, 95u, 1u>();
    rt.unsupported(0x089CC9DCu, 0x746E6576u, "unknown not lowered yet"); return;
L_089CC9E8:
    // nop
    // nop
    // nop
    rt.unsupported(0x089CC9F8u, 0x4B4C4154u, "cop2/vfpu not lowered yet"); return;
    ctx.pc = 0x023AA890u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089CC9F8:
    rt.unsupported(0x089CC9F8u, 0x4B4C4154u, "cop2/vfpu not lowered yet"); return;
L_089CCA0C:
    rt.unsupported(0x089CCA0Cu, 0x6E756F73u, "vfpu3 not lowered yet"); return;
L_089CCA28:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x0264C3D0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089CCA60:
    rt.unsupported(0x089CCA60u, 0x756E656Du, "unknown not lowered yet"); return;
L_089CCA6C:
    rt.unsupported(0x089CCA70u, 0x5F716573u, "control flow in delay slot"); return;
L_089CCA74:
    rt.unsupported(0x089CCA74u, 0x69622E30u, "unknown not lowered yet"); return;
L_089CCA7C:
    rt.unsupported(0x089CCA7Cu, 0x756E656Du, "unknown not lowered yet"); return;
L_089CCA98:
    rt.unsupported(0x089CCA98u, 0x756E656Du, "unknown not lowered yet"); return;
L_089CCAA4:
    rt.unsupported(0x089CCAA8u, 0x5F6D6967u, "control flow in delay slot"); return;
L_089CCAAC:
    rt.unsupported(0x089CCAACu, 0x69622E30u, "unknown not lowered yet"); return;
L_089CCAB4:
    rt.unsupported(0x089CCAB4u, 0x756E656Du, "unknown not lowered yet"); return;
L_089CCAD0:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x023B23A0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089CCB08:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x023B36D0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089CCB48:
    // nop
    // nop
    // nop
    goto L_089CCB54;
L_089CCB54:
    // nop
    ctx.pc = 0x023B3950u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089CCB80:
    (void)(static_cast<std::uint32_t>(static_cast<std::int32_t>(0u) >> 0u));
    // nop
    rt.unsupported(0x089CCB88u, 0x00000001u, "special? not lowered yet"); return;
L_089CCB90:
    ctx.execute_vfpu_vminmax(102u, 97u, 116u, 1u, false);
    rt.unsupported(0x089CCB94u, 0x003A3073u, "special? not lowered yet"); return;
L_089CCBB8:
    if (static_cast<std::int32_t>(ctx.gpr[2]) <= 0) {
    rt.unsupported(0x089CCBBCu, 0x20434554u, "unknown not lowered yet"); return;
        (void)rt.invoke_chained_direct<&recomp_unit_0014, 14u>(ctx, &aot_mem); return;
    }
    goto L_089CCBC0;
L_089CCBC0:
    rt.unsupported(0x089CCBC0u, 0x69766F4Du, "unknown not lowered yet"); return;
L_089CCBDC:
    if (static_cast<std::int32_t>(ctx.gpr[2]) <= 0) {
    rt.unsupported(0x089CCBE0u, 0x20434554u, "unknown not lowered yet"); return;
        (void)rt.invoke_chained_direct<&recomp_unit_0014, 14u>(ctx, &aot_mem); return;
    }
    goto L_089CCBE4;
L_089CCBE4:
    rt.unsupported(0x089CCBE4u, 0x69766F4Du, "unknown not lowered yet"); return;
L_089CCBFC:
    rt.unsupported(0x089CCBFCu, 0x74736F68u, "unknown not lowered yet"); return;
L_089CCC04:
    ctx.gpr[16] = (ctx.gpr[17] ^ 29549u);
    // nop
    goto L_089CCC0C;
L_089CCC0C:
    rt.unsupported(0x089CCC0Cu, 0x63736964u, "vfpu0 not lowered yet"); return;
L_089CCC14:
    if (static_cast<std::int32_t>(ctx.gpr[2]) <= 0) {
    rt.unsupported(0x089CCC18u, 0x20434554u, "unknown not lowered yet"); return;
        (void)rt.invoke_chained_direct<&recomp_unit_0014, 14u>(ctx, &aot_mem); return;
    }
    goto L_089CCC1C;
L_089CCC1C:
    rt.unsupported(0x089CCC1Cu, 0x69766F4Du, "unknown not lowered yet"); return;
L_089CCC2C:
    if (static_cast<std::int32_t>(ctx.gpr[2]) <= 0) {
    rt.unsupported(0x089CCC30u, 0x20434554u, "unknown not lowered yet"); return;
        (void)rt.invoke_chained_direct<&recomp_unit_0014, 14u>(ctx, &aot_mem); return;
    }
    goto L_089CCC34;
L_089CCC34:
    rt.unsupported(0x089CCC34u, 0x69766F4Du, "unknown not lowered yet"); return;
L_089CCC44:
    if (static_cast<std::int32_t>(ctx.gpr[2]) <= 0) {
    rt.unsupported(0x089CCC48u, 0x20434554u, "unknown not lowered yet"); return;
        (void)rt.invoke_chained_direct<&recomp_unit_0014, 14u>(ctx, &aot_mem); return;
    }
    goto L_089CCC4C;
L_089CCC4C:
    rt.unsupported(0x089CCC4Cu, 0x69766F4Du, "unknown not lowered yet"); return;
L_089CCC70:
    // nop
    // nop
    // nop
    rt.unsupported(0x089CCC7Cu, 0x00000001u, "special? not lowered yet"); return;
L_089CCC88:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x023CA8C0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089CCCF8:
    // nop
    rt.unsupported(0x089CCCFCu, 0x00000001u, "special? not lowered yet"); return;
L_089CCD20:
    rt.unsupported(0x089CCD20u, 0x444E5246u, "unsupported CFC1 control register"); return;
    rt.unsupported(0x089CCD24u, 0x44524143u, "unsupported CFC1 control register"); return;
    // nop
    // nop
    goto L_089CCD30;
L_089CCD30:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x023DD420u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089CCD70:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x023DD730u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089CCDB8:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x023DD7F0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089CCDC8:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x023E1230u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089CCE20:
    { const std::int64_t product = static_cast<std::int64_t>(static_cast<std::int32_t>(0u)) * static_cast<std::int64_t>(static_cast<std::int32_t>(ctx.gpr[4])); ctx.lo = static_cast<std::uint32_t>(product); ctx.hi = static_cast<std::uint32_t>(static_cast<std::uint64_t>(product) >> 32u); }
    // vflush: architectural no-op that retains VFPU prefixes
    goto L_089CCE28;
L_089CCE28:
    { const std::int64_t product = static_cast<std::int64_t>(static_cast<std::int32_t>(0u)) * static_cast<std::int64_t>(static_cast<std::int32_t>(ctx.gpr[2])); ctx.lo = static_cast<std::uint32_t>(product); ctx.hi = static_cast<std::uint32_t>(static_cast<std::uint64_t>(product) >> 32u); }
    // vflush: architectural no-op that retains VFPU prefixes
    // vflush: architectural no-op that retains VFPU prefixes
    rt.unsupported(0x089CCE34u, 0x0000FFFFu, "special? not lowered yet"); return;
L_089CCE38:
    if (ctx.gpr[2] != 0u) (void)(0u);
    rt.unsupported(0x089CCE3Cu, 0x0002000Cu, "syscall not lowered yet"); return;
L_089CCE68:
    (void)(static_cast<std::uint32_t>(static_cast<std::int32_t>(ctx.gpr[1]) >> (0u & 31u)));
    jump_target = 0u;
    (void)(ctx.gpr[1] >> (0u & 31u));
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089CCE9C:
    (void)(ctx.gpr[4] << 0u);
    // vflush: architectural no-op that retains VFPU prefixes
    rt.unsupported(0x089CCEA4u, 0x00010001u, "special? not lowered yet"); return;
L_089CCEBC:
    (void)(static_cast<std::uint32_t>(static_cast<std::int32_t>(ctx.gpr[9]) >> 0u));
    (void)(ctx.gpr[1] << 0u);
    rt.unsupported(0x089CCEC4u, 0x00020005u, "special? not lowered yet"); return;
L_089CCF44:
    (void)(ctx.gpr[20] << 0u);
    (void)(static_cast<std::uint32_t>(static_cast<std::int32_t>(ctx.gpr[27]) >> 0u));
    (void)(ctx.gpr[18] >> 0u);
    (void)(static_cast<std::uint32_t>(static_cast<std::int32_t>(ctx.gpr[25]) >> 0u));
    rt.unsupported(0x089CCF54u, 0x00120001u, "special? not lowered yet"); return;
L_089CCFAC:
    rt.unsupported(0x089CCFACu, 0x00030014u, "special? not lowered yet"); return;
L_089CCFD4:
    rt.unsupported(0x089CCFD4u, 0x0014000Du, "special? not lowered yet"); return;
L_089CD03C:
    rt.unsupported(0x089CD03Cu, 0x69622E6Du, "unknown not lowered yet"); return;
L_089CD048:
    rt.unsupported(0x089CD04Cu, 0x122A1029u, "control flow in delay slot"); return;
L_089CD050:
    // vflush: architectural no-op that retains VFPU prefixes
    ctx.gpr[10] = (rt.memory().aot_load_word_left(ctx.gpr[17] + static_cast<std::uint32_t>(-1), ctx.gpr[10]));
    ctx.gpr[12] = (rt.memory().aot_load_word_left(ctx.gpr[17] + static_cast<std::uint32_t>(-30679), ctx.gpr[12]));
    ctx.gpr[18] = (rt.memory().aot_load_word_left(ctx.gpr[17] + static_cast<std::uint32_t>(-30718), ctx.gpr[18]));
    ctx.gpr[16] = (rt.memory().aot_load_word_left(ctx.gpr[17] + static_cast<std::uint32_t>(-30677), ctx.gpr[16]));
    // vflush: architectural no-op that retains VFPU prefixes
    rt.unsupported(0x089CD068u, 0x0000FFFFu, "special? not lowered yet"); return;
L_089CD06C:
    ctx.gpr[12] = (0u | 0u);
    goto L_089CD070;
L_089CD070:
    ctx.gpr[14] = (ctx.gpr[18] ^ 16717u);
    rt.unsupported(0x089CD074u, 0x4655423Au, "cop1? not lowered yet"); return;
L_089CD1FC:
    rt.unsupported(0x089CD1FCu, 0x72617765u, "unknown not lowered yet"); return;
L_089CD220:
    { float vfpu_s[4]{}, vfpu_t[4]{}, vfpu_d[4]{};
      ctx.read_vfpu_vector_with_source_prefix_ct<109u, 1u, 0u>(vfpu_s);
      ctx.read_vfpu_vector_with_source_prefix_ct<46u, 1u, 1u>(vfpu_t);
      for (std::uint32_t i = 0; i < 1u; ++i) vfpu_d[i] = vfpu_s[i] * vfpu_t[i];
      ctx.write_vfpu_vector_with_destination_prefix_ct<111u, 1u>(vfpu_d); }
    rt.unsupported(0x089CD224u, 0x00007270u, "special? not lowered yet"); return;
L_089CD258:
    ctx.execute_vfpu_vscl_ct<101u, 109u, 45u, 1u>();
    ctx.gpr[5] = (ctx.gpr[19] < static_cast<std::uint32_t>(26214) ? 1u : 0u);
    ctx.gpr[14] = (static_cast<std::int32_t>(ctx.gpr[3]) < static_cast<std::int32_t>(ctx.gpr[11]) ? ctx.gpr[3] : ctx.gpr[11]);
    rt.unsupported(0x089CD264u, 0x676E7564u, "vfpu1 not lowered yet"); return;
L_089CD2B0:
    rt.unsupported(0x089CD2B0u, 0x68635F6Bu, "unknown not lowered yet"); return;
L_089CD2D4:
    rt.unsupported(0x089CD2D4u, 0x68635F74u, "unknown not lowered yet"); return;
L_089CD314:
    rt.unsupported(0x089CD314u, 0x746E6564u, "unknown not lowered yet"); return;
L_089CD328:
    ctx.execute_vfpu_compare3(121u, 95u, 109u, 1u, 6u);
    rt.unsupported(0x089CD32Cu, 0x622E6564u, "vfpu0 not lowered yet"); return;
L_089CD408:
    if (static_cast<std::int32_t>(ctx.gpr[27]) > 0) {
    rt.unsupported(0x089CD40Cu, 0x69622E30u, "unknown not lowered yet"); return;
        (void)rt.invoke_chained_direct<&recomp_unit_0015, 15u>(ctx, &aot_mem); return;
    }
    goto L_089CD410;
L_089CD410:
    rt.unsupported(0x089CD410u, 0x0000006Eu, "special? not lowered yet"); return;
L_089CD420:
    ctx.execute_vfpu_compare3(46u, 103u, 109u, 1u, 6u);
    // nop
    ctx.gpr[10] = (ctx.gpr[27] < static_cast<std::uint32_t>(25199) ? 1u : 0u);
    if (static_cast<std::int32_t>(ctx.gpr[10]) <= 0) {
    ctx.gpr[16] = (ctx.gpr[9] & 12621u);
        (void)rt.invoke_chained_direct<&recomp_unit_0015, 15u>(ctx, &aot_mem); return;
    }
    goto L_089CD434;
L_089CD434:
    ctx.execute_vfpu_compare3(46u, 103u, 109u, 1u, 6u);
    // nop
    ctx.gpr[10] = (ctx.gpr[27] < static_cast<std::uint32_t>(25199) ? 1u : 0u);
    if (static_cast<std::int32_t>(ctx.gpr[10]) <= 0) {
    ctx.gpr[16] = (ctx.gpr[17] & 12621u);
        (void)rt.invoke_chained_direct<&recomp_unit_0015, 15u>(ctx, &aot_mem); return;
    }
    goto L_089CD448;
L_089CD448:
    ctx.execute_vfpu_compare3(46u, 103u, 109u, 1u, 6u);
    // nop
    ctx.gpr[10] = (ctx.gpr[27] < static_cast<std::uint32_t>(25199) ? 1u : 0u);
    if (static_cast<std::int32_t>(ctx.gpr[10]) <= 0) {
    ctx.gpr[16] = (ctx.gpr[9] ^ 12621u);
        (void)rt.invoke_chained_direct<&recomp_unit_0015, 15u>(ctx, &aot_mem); return;
    }
    goto L_089CD45C;
L_089CD45C:
    ctx.execute_vfpu_compare3(46u, 103u, 109u, 1u, 6u);
    // nop
    ctx.gpr[10] = (ctx.gpr[27] < static_cast<std::uint32_t>(25199) ? 1u : 0u);
    if (static_cast<std::int32_t>(ctx.gpr[10]) <= 0) {
    ctx.gpr[17] = (ctx.gpr[1] & 12621u);
        (void)rt.invoke_chained_direct<&recomp_unit_0015, 15u>(ctx, &aot_mem); return;
    }
    goto L_089CD470;
L_089CD470:
    ctx.execute_vfpu_compare3(46u, 103u, 109u, 1u, 6u);
    // nop
    ctx.gpr[10] = (ctx.gpr[27] < static_cast<std::uint32_t>(25199) ? 1u : 0u);
    if (static_cast<std::int32_t>(ctx.gpr[10]) <= 0) {
    ctx.gpr[18] = (ctx.gpr[1] & 12621u);
        (void)rt.invoke_chained_direct<&recomp_unit_0015, 15u>(ctx, &aot_mem); return;
    }
    goto L_089CD484;
L_089CD484:
    ctx.execute_vfpu_compare3(46u, 103u, 109u, 1u, 6u);
    // nop
    ctx.gpr[10] = (ctx.gpr[27] < static_cast<std::uint32_t>(25199) ? 1u : 0u);
    if (static_cast<std::int32_t>(ctx.gpr[10]) <= 0) {
    ctx.gpr[20] = (ctx.gpr[1] & 12621u);
        (void)rt.invoke_chained_direct<&recomp_unit_0015, 15u>(ctx, &aot_mem); return;
    }
    goto L_089CD498;
L_089CD498:
    ctx.execute_vfpu_compare3(46u, 103u, 109u, 1u, 6u);
    // nop
    ctx.gpr[10] = (ctx.gpr[27] < static_cast<std::uint32_t>(25199) ? 1u : 0u);
    if (static_cast<std::int32_t>(ctx.gpr[10]) <= 0) {
    ctx.gpr[21] = (ctx.gpr[1] & 12621u);
        (void)rt.invoke_chained_direct<&recomp_unit_0015, 15u>(ctx, &aot_mem); return;
    }
    goto L_089CD4AC;
L_089CD4AC:
    ctx.execute_vfpu_compare3(46u, 103u, 109u, 1u, 6u);
    // nop
    ctx.gpr[10] = (ctx.gpr[27] < static_cast<std::uint32_t>(25199) ? 1u : 0u);
    if (static_cast<std::int32_t>(ctx.gpr[10]) <= 0) {
    ctx.gpr[22] = (ctx.gpr[1] & 12621u);
        (void)rt.invoke_chained_direct<&recomp_unit_0015, 15u>(ctx, &aot_mem); return;
    }
    goto L_089CD4C0;
L_089CD4C0:
    ctx.execute_vfpu_compare3(46u, 103u, 109u, 1u, 6u);
    // nop
    ctx.gpr[10] = (ctx.gpr[27] < static_cast<std::uint32_t>(25199) ? 1u : 0u);
    if (static_cast<std::int32_t>(ctx.gpr[10]) <= 0) {
    ctx.gpr[22] = (ctx.gpr[1] & 12621u);
        (void)rt.invoke_chained_direct<&recomp_unit_0015, 15u>(ctx, &aot_mem); return;
    }
    goto L_089CD4D4;
L_089CD4D4:
    rt.unsupported(0x089CD4D4u, 0x6A626F2Eu, "unknown not lowered yet"); return;
L_089CD4E8:
    ctx.execute_vfpu_compare3(46u, 103u, 109u, 1u, 6u);
    // nop
    ctx.gpr[10] = (ctx.gpr[27] < static_cast<std::uint32_t>(25199) ? 1u : 0u);
    if (static_cast<std::int32_t>(ctx.gpr[10]) <= 0) {
    ctx.gpr[25] = (ctx.gpr[1] & 12621u);
        (void)rt.invoke_chained_direct<&recomp_unit_0015, 15u>(ctx, &aot_mem); return;
    }
    goto L_089CD4FC;
L_089CD4FC:
    ctx.execute_vfpu_compare3(46u, 103u, 109u, 1u, 6u);
    // nop
    ctx.gpr[10] = (ctx.gpr[27] < static_cast<std::uint32_t>(25199) ? 1u : 0u);
    if (static_cast<std::int32_t>(ctx.gpr[10]) <= 0) {
    ctx.gpr[16] = (ctx.gpr[1] & 12877u);
        (void)rt.invoke_chained_direct<&recomp_unit_0015, 15u>(ctx, &aot_mem); return;
    }
    goto L_089CD510;
L_089CD510:
    ctx.execute_vfpu_compare3(46u, 103u, 109u, 1u, 6u);
    // nop
    ctx.gpr[10] = (ctx.gpr[27] < static_cast<std::uint32_t>(25199) ? 1u : 0u);
    if (static_cast<std::int32_t>(ctx.gpr[10]) <= 0) {
    ctx.gpr[16] = (ctx.gpr[1] & 12877u);
        (void)rt.invoke_chained_direct<&recomp_unit_0015, 15u>(ctx, &aot_mem); return;
    }
    goto L_089CD524;
L_089CD524:
    rt.unsupported(0x089CD524u, 0x6A626F2Eu, "unknown not lowered yet"); return;
L_089CD538:
    ctx.execute_vfpu_compare3(46u, 103u, 109u, 1u, 6u);
    // nop
    ctx.gpr[10] = (ctx.gpr[27] < static_cast<std::uint32_t>(25199) ? 1u : 0u);
    if (static_cast<std::int32_t>(ctx.gpr[10]) <= 0) {
    ctx.gpr[18] = (ctx.gpr[1] & 12877u);
        (void)rt.invoke_chained_direct<&recomp_unit_0015, 15u>(ctx, &aot_mem); return;
    }
    goto L_089CD54C;
L_089CD54C:
    ctx.execute_vfpu_compare3(46u, 103u, 109u, 1u, 6u);
    // nop
    ctx.gpr[10] = (ctx.gpr[27] < static_cast<std::uint32_t>(25199) ? 1u : 0u);
    if (static_cast<std::int32_t>(ctx.gpr[10]) <= 0) {
    ctx.gpr[20] = (ctx.gpr[1] & 12877u);
        (void)rt.invoke_chained_direct<&recomp_unit_0015, 15u>(ctx, &aot_mem); return;
    }
    goto L_089CD560;
L_089CD560:
    ctx.execute_vfpu_compare3(46u, 103u, 109u, 1u, 6u);
    // nop
    ctx.gpr[10] = (ctx.gpr[27] < static_cast<std::uint32_t>(25199) ? 1u : 0u);
    if (static_cast<std::int32_t>(ctx.gpr[10]) <= 0) {
    ctx.gpr[20] = (ctx.gpr[1] & 12877u);
        (void)rt.invoke_chained_direct<&recomp_unit_0015, 15u>(ctx, &aot_mem); return;
    }
    goto L_089CD574;
L_089CD574:
    rt.unsupported(0x089CD574u, 0x6A626F2Eu, "unknown not lowered yet"); return;
L_089CD588:
    ctx.execute_vfpu_compare3(46u, 103u, 109u, 1u, 6u);
    // nop
    ctx.gpr[10] = (ctx.gpr[27] < static_cast<std::uint32_t>(25199) ? 1u : 0u);
    if (static_cast<std::int32_t>(ctx.gpr[10]) <= 0) {
    ctx.gpr[21] = (ctx.gpr[1] & 12877u);
        (void)rt.invoke_chained_direct<&recomp_unit_0015, 15u>(ctx, &aot_mem); return;
    }
    goto L_089CD59C;
L_089CD59C:
    rt.unsupported(0x089CD59Cu, 0x6A626F2Eu, "unknown not lowered yet"); return;
L_089CD5B0:
    ctx.execute_vfpu_compare3(46u, 103u, 109u, 1u, 6u);
    // nop
    ctx.gpr[10] = (ctx.gpr[27] < static_cast<std::uint32_t>(25199) ? 1u : 0u);
    if (static_cast<std::int32_t>(ctx.gpr[10]) <= 0) {
    ctx.gpr[21] = (ctx.gpr[17] & 12877u);
        (void)rt.invoke_chained_direct<&recomp_unit_0015, 15u>(ctx, &aot_mem); return;
    }
    goto L_089CD5C4;
L_089CD5C4:
    ctx.execute_vfpu_compare3(46u, 103u, 109u, 1u, 6u);
    // nop
    ctx.gpr[10] = (ctx.gpr[27] < static_cast<std::uint32_t>(25199) ? 1u : 0u);
    if (static_cast<std::int32_t>(ctx.gpr[10]) <= 0) {
    ctx.gpr[21] = (ctx.gpr[25] & 12877u);
        (void)rt.invoke_chained_direct<&recomp_unit_0015, 15u>(ctx, &aot_mem); return;
    }
    goto L_089CD5D8;
L_089CD5D8:
    ctx.execute_vfpu_compare3(46u, 103u, 109u, 1u, 6u);
    // nop
    ctx.gpr[10] = (ctx.gpr[27] < static_cast<std::uint32_t>(25199) ? 1u : 0u);
    if (static_cast<std::int32_t>(ctx.gpr[10]) <= 0) {
    ctx.gpr[21] = (ctx.gpr[1] | 12877u);
        (void)rt.invoke_chained_direct<&recomp_unit_0015, 15u>(ctx, &aot_mem); return;
    }
    goto L_089CD5EC;
L_089CD5EC:
    ctx.execute_vfpu_compare3(46u, 103u, 109u, 1u, 6u);
    // nop
    ctx.gpr[10] = (ctx.gpr[27] < static_cast<std::uint32_t>(25199) ? 1u : 0u);
    if (static_cast<std::int32_t>(ctx.gpr[10]) <= 0) {
    ctx.gpr[21] = (ctx.gpr[9] | 12877u);
        (void)rt.invoke_chained_direct<&recomp_unit_0015, 15u>(ctx, &aot_mem); return;
    }
    goto L_089CD600;
L_089CD600:
    ctx.execute_vfpu_compare3(46u, 103u, 109u, 1u, 6u);
    // nop
    ctx.gpr[10] = (ctx.gpr[27] < static_cast<std::uint32_t>(25199) ? 1u : 0u);
    if (static_cast<std::int32_t>(ctx.gpr[10]) <= 0) {
    ctx.gpr[21] = (ctx.gpr[17] | 12877u);
        (void)rt.invoke_chained_direct<&recomp_unit_0015, 15u>(ctx, &aot_mem); return;
    }
    goto L_089CD614;
L_089CD614:
    ctx.execute_vfpu_compare3(46u, 103u, 109u, 1u, 6u);
    // nop
    ctx.gpr[10] = (ctx.gpr[27] < static_cast<std::uint32_t>(25199) ? 1u : 0u);
    if (static_cast<std::int32_t>(ctx.gpr[10]) <= 0) {
    ctx.gpr[21] = (ctx.gpr[17] | 12877u);
        (void)rt.invoke_chained_direct<&recomp_unit_0015, 15u>(ctx, &aot_mem); return;
    }
    goto L_089CD628;
L_089CD628:
    rt.unsupported(0x089CD628u, 0x6A626F2Eu, "unknown not lowered yet"); return;
L_089CD63C:
    ctx.gpr[5] = (ctx.gpr[27] < static_cast<std::uint32_t>(30313) ? 1u : 0u);
    ctx.execute_vfpu_vcmp_ct<105u, 101u, 1u, 6u>();
    ctx.execute_vfpu_vscl_ct<100u, 47u, 109u, 1u>();
    rt.unsupported(0x089CD648u, 0x622E756Eu, "vfpu0 not lowered yet"); return;
L_089CD65C:
    ctx.gpr[5] = (ctx.gpr[27] < static_cast<std::uint32_t>(30313) ? 1u : 0u);
    ctx.execute_vfpu_vcmp_ct<105u, 101u, 1u, 6u>();
    if (ctx.gpr[2] == ctx.gpr[10]) {
    rt.unsupported(0x089CD668u, 0x6E656D2Fu, "vfpu3 not lowered yet"); return;
        goto L_089D93F8;
    }
    goto L_089CD66C;
L_089CD66C:
    rt.unsupported(0x089CD66Cu, 0x616C5F75u, "vfpu0 not lowered yet"); return;
L_089CD68C:
    if (static_cast<std::int32_t>(ctx.gpr[27]) > 0) {
    rt.unsupported(0x089CD690u, 0x69622E30u, "unknown not lowered yet"); return;
        (void)rt.invoke_chained_direct<&recomp_unit_0015, 15u>(ctx, &aot_mem); return;
    }
    goto L_089CD694;
L_089CD694:
    rt.unsupported(0x089CD694u, 0x0000006Eu, "special? not lowered yet"); return;
L_089CD72C:
    ctx.gpr[5] = (ctx.gpr[27] < static_cast<std::uint32_t>(30313) ? 1u : 0u);
    ctx.execute_vfpu_vcmp_ct<105u, 101u, 1u, 6u>();
    rt.unsupported(0x089CD734u, 0x69662F64u, "unknown not lowered yet"); return;
L_089CD74C:
    ctx.gpr[5] = (ctx.gpr[27] < static_cast<std::uint32_t>(30313) ? 1u : 0u);
    ctx.execute_vfpu_vcmp_ct<105u, 101u, 1u, 6u>();
    if (ctx.gpr[10] == ctx.gpr[26]) {
    ctx.execute_vfpu_vscl_ct<47u, 102u, 105u, 1u>();
        goto L_089D94E8;
    }
    goto L_089CD75C;
L_089CD75C:
    ctx.execute_vfpu_vcmp_ct<100u, 95u, 1u, 12u>();
    ctx.gpr[7] = (ctx.gpr[19] < static_cast<std::uint32_t>(28257) ? 1u : 0u);
    { const bool signed_ok = ctx.execute_signed_sub(13u, 3u, 14u);
      if (!signed_ok) { rt.arithmetic_overflow(0x089CD764u, 0x006E6962u); return; } }
    rt.unsupported(0x089CD768u, 0x74746162u, "unknown not lowered yet"); return;
L_089CD790:
    rt.unsupported(0x089CD790u, 0x745F646Eu, "unknown not lowered yet"); return;
L_089CD858:
    ctx.execute_vfpu_compare3(46u, 103u, 109u, 1u, 6u);
    // nop
    ctx.gpr[10] = (ctx.gpr[27] < static_cast<std::uint32_t>(25199) ? 1u : 0u);
    rt.unsupported(0x089CD864u, 0x79735F72u, "unknown not lowered yet"); return;
L_089CD880:
    ctx.execute_vfpu_compare3(46u, 103u, 109u, 1u, 6u);
    // nop
    ctx.gpr[10] = (ctx.gpr[27] < static_cast<std::uint32_t>(25199) ? 1u : 0u);
    rt.unsupported(0x089CD88Cu, 0x79735F72u, "unknown not lowered yet"); return;
L_089CD8D0:
    ctx.execute_vfpu_compare3(46u, 103u, 109u, 1u, 6u);
    // nop
    ctx.gpr[10] = (ctx.gpr[27] < static_cast<std::uint32_t>(25199) ? 1u : 0u);
    rt.unsupported(0x089CD8DCu, 0x79735F72u, "unknown not lowered yet"); return;
L_089CD90C:
    (void)(0u < 0u ? 1u : 0u);
    rt.unsupported(0x089CD910u, 0x6E756F73u, "vfpu3 not lowered yet"); return;
L_089CD9D8:
    rt.unsupported(0x089CD9D8u, 0x70616D64u, "unknown not lowered yet"); return;
L_089CD9F8:
    rt.unsupported(0x089CD9F8u, 0x75642E79u, "unknown not lowered yet"); return;
L_089CDA18:
    if (ctx.gpr[26] == ctx.gpr[19]) {
    rt.unsupported(0x089CDA1Cu, 0x41494449u, "unknown not lowered yet"); return;
        (void)rt.invoke_chained_direct<&recomp_unit_0014, 14u>(ctx, &aot_mem); return;
    }
    goto L_089CDA20;
L_089CDA20:
    ctx.gpr[17] = (ctx.gpr[17] & 12320u);
    { const bool signed_ok = ctx.execute_signed_add(8u, 2u, 6u);
      if (!signed_ok) { rt.arithmetic_overflow(0x089CDA24u, 0x00464620u); return; } }
    goto L_089CDA28;
L_089CDA28:
    ctx.gpr[16] = (ctx.gpr[1] | 9567u);
    (void)(0u & 0u);
    // nop
    // nop
    rt.unsupported(0x089CDA38u, 0x0000003Fu, "special? not lowered yet"); return;
L_089CDA50:
    rt.unsupported(0x089CDA50u, 0x63657845u, "vfpu0 not lowered yet"); return;
L_089CDA60:
    rt.unsupported(0x089CDA60u, 0x69647541u, "unknown not lowered yet"); return;
L_089CDA70:
    rt.unsupported(0x089CDA70u, 0x69647541u, "unknown not lowered yet"); return;
L_089CDA80:
    rt.unsupported(0x089CDA80u, 0x69647541u, "unknown not lowered yet"); return;
L_089CDA98:
    rt.unsupported(0x089CDA98u, 0x00020001u, "special? not lowered yet"); return;
L_089CDAA8:
    rt.unsupported(0x089CDAACu, 0x0BE60BE2u, "control flow in delay slot"); return;
L_089CDB18:
    rt.unsupported(0x089CDB18u, 0x00000005u, "special? not lowered yet"); return;
L_089CDB28:
    rt.unsupported(0x089CDB28u, 0x00000005u, "special? not lowered yet"); return;
L_089CDB70:
    ctx.execute_vfpu_vhdp(99u, 111u, 109u, 1u);
    rt.unsupported(0x089CDB74u, 0x2067616Cu, "unknown not lowered yet"); return;
L_089CDBC0:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x02415550u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089CDBE0:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x02417520u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089CDC40:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x02418E80u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089CDCA0:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x0241FA50u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089CDCC0:
    // nop
    // nop
    // nop
    ctx.gpr[16] = (ctx.gpr[19] << 28u);
    ctx.pc = 0x0241FBE0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089CDD18:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x024290E0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089CDD30:
    rt.unsupported(0x089CDD30u, 0x42424F4Cu, "unknown not lowered yet"); return;
L_089CDD60:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x0242DBB0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089CDD78:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x0242DC90u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089CDD88:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x0264C3D0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089CDE50:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x0242E470u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089CDF18:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x02430170u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089CE038:
    rt.unsupported(0x089CE03Cu, 0x5F4B524Fu, "control flow in delay slot"); return;
L_089CE040:
    rt.unsupported(0x089CE040u, 0x414E414Du, "unknown not lowered yet"); return;
L_089CE060:
    ctx.execute_vfpu_compare3(115u, 110u, 114u, 1u, 6u);
    // nop
    goto L_089CE068;
L_089CE068:
    rt.unsupported(0x089CE068u, 0x6E656D77u, "vfpu3 not lowered yet"); return;
L_089CE070:
    rt.unsupported(0x089CE070u, 0x73756170u, "unknown not lowered yet"); return;
L_089CE078:
    ctx.execute_vfpu_vcmp_ct<111u, 114u, 1u, 7u>();
    rt.unsupported(0x089CE07Cu, 0x70616D64u, "unknown not lowered yet"); return;
L_089CE084:
    rt.unsupported(0x089CE084u, 0x622E7325u, "vfpu0 not lowered yet"); return;
L_089CE08C:
    ctx.execute_vfpu_vscl_ct<103u, 97u, 116u, 1u>();
    // nop
    goto L_089CE094;
L_089CE094:
    rt.unsupported(0x089CE094u, 0x67627467u, "vfpu1 not lowered yet"); return;
L_089CE09C:
    rt.unsupported(0x089CE09Cu, 0x746E6970u, "unknown not lowered yet"); return;
L_089CE0A4:
    rt.unsupported(0x089CE0A4u, 0x6B747266u, "unknown not lowered yet"); return;
L_089CE0AC:
    ctx.execute_vfpu_vscl_ct<119u, 101u, 110u, 1u>();
    // nop
    goto L_089CE0B4;
L_089CE0B4:
    rt.unsupported(0x089CE0B4u, 0x69726677u, "unknown not lowered yet"); return;
L_089CE0BC:
    { float vfpu_s[4]{}, vfpu_t[4]{}, vfpu_d[4]{};
      ctx.read_vfpu_vector_with_source_prefix_ct<114u, 1u, 0u>(vfpu_s);
      ctx.read_vfpu_vector_with_source_prefix_ct<110u, 1u, 1u>(vfpu_t);
      for (std::uint32_t i = 0; i < 1u; ++i) vfpu_d[i] = vfpu_s[i] * vfpu_t[i];
      ctx.write_vfpu_vector_with_destination_prefix_ct<102u, 1u>(vfpu_d); }
    // nop
    goto L_089CE0C4;
L_089CE0C4:
    rt.unsupported(0x089CE0C4u, 0x706C7477u, "unknown not lowered yet"); return;
L_089CE0CC:
    if (static_cast<std::int32_t>(ctx.gpr[27]) > 0) {
    // nop
        (void)rt.invoke_chained_direct<&recomp_unit_0015, 15u>(ctx, &aot_mem); return;
    }
    goto L_089CE0D4;
L_089CE0D4:
    // nop
    rt.unsupported(0x089CE0D8u, 0x79735F77u, "unknown not lowered yet"); return;
L_089CE0F8:
    rt.unsupported(0x089CE0F8u, 0x6B6C6174u, "unknown not lowered yet"); return;
L_089CE138:
    ctx.execute_vfpu_vscl_ct<37u, 115u, 46u, 1u>();
    rt.unsupported(0x089CE13Cu, 0x00786576u, "special? not lowered yet"); return;
L_089CE140:
    ctx.gpr[16] = (ctx.gpr[27] < static_cast<std::uint32_t>(24941) ? 1u : 0u);
    rt.unsupported(0x089CE144u, 0x6170616Du, "vfpu0 not lowered yet"); return;
L_089CE154:
    if (static_cast<std::int32_t>(ctx.gpr[27]) > 0) {
    ctx.gpr[31] = (ctx.gpr[10] + static_cast<std::uint32_t>(25971));
        (void)rt.invoke_chained_direct<&recomp_unit_0015, 15u>(ctx, &aot_mem); return;
    }
    goto L_089CE15C;
L_089CE15C:
    rt.unsupported(0x089CE15Cu, 0x736D2D73u, "unknown not lowered yet"); return;
L_089CE168:
    rt.unsupported(0x089CE168u, 0x72616373u, "unknown not lowered yet"); return;
L_089CE178:
    rt.unsupported(0x089CE178u, 0x63656970u, "vfpu0 not lowered yet"); return;
L_089CE188:
    rt.unsupported(0x089CE188u, 0x626F662Eu, "vfpu0 not lowered yet"); return;
L_089CE190:
    rt.unsupported(0x089CE190u, 0x672E7325u, "vfpu1 not lowered yet"); return;
L_089CE198:
    ctx.execute_vfpu_compare3(37u, 115u, 46u, 1u, 6u);
    { const bool signed_ok = ctx.execute_signed_sub(13u, 3u, 24u);
      if (!signed_ok) { rt.arithmetic_overflow(0x089CE19Cu, 0x00786A62u); return; } }
    goto L_089CE1A0;
L_089CE1A0:
    rt.unsupported(0x089CE1A0u, 0x6E69622Eu, "vfpu3 not lowered yet"); return;
L_089CE1A8:
    ctx.execute_vfpu_vscl_ct<37u, 115u, 45u, 1u>();
    ctx.gpr[5] = (ctx.gpr[19] < static_cast<std::uint32_t>(26214) ? 1u : 0u);
    ctx.gpr[14] = (static_cast<std::int32_t>(ctx.gpr[3]) < static_cast<std::int32_t>(ctx.gpr[11]) ? ctx.gpr[3] : ctx.gpr[11]);
    goto L_089CE1B4;
L_089CE1B4:
    rt.unsupported(0x089CE1B4u, 0x672E7325u, "vfpu1 not lowered yet"); return;
L_089CE1C0:
    ctx.gpr[26] = (ctx.gpr[17] ^ 19799u);
    rt.unsupported(0x089CE1C4u, 0x4F4D454Du, "unknown not lowered yet"); return;
L_089CE1D0:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x02446470u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089CE1E8:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x02447170u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089CE200:
    rt.unsupported(0x089CE200u, 0x00120001u, "special? not lowered yet"); return;
L_089CE230:
    rt.unsupported(0x089CE230u, 0x74786574u, "unknown not lowered yet"); return;
L_089CE244:
    rt.unsupported(0x089CE244u, 0x70616D64u, "unknown not lowered yet"); return;
L_089CE250:
    (void)(ctx.gpr[3] | ctx.gpr[19]);
    { const bool signed_ok = ctx.execute_signed_add(0u, 2u, 12u);
      if (!signed_ok) { rt.arithmetic_overflow(0x089CE254u, 0x004C0020u); return; } }
    rt.unsupported(0x089CE258u, 0x00250076u, "special? not lowered yet"); return;
L_089CE3B0:
    rt.unsupported(0x089CE3B0u, 0x6B6C6174u, "unknown not lowered yet"); return;
L_089CE3C4:
    ctx.gpr[26] = (ctx.gpr[17] ^ 19799u);
    if (static_cast<std::int32_t>(ctx.gpr[26]) > 0) {
    rt.unsupported(0x089CE3CCu, 0x4F4D454Du, "unknown not lowered yet"); return;
        (void)rt.invoke_chained_direct<&recomp_unit_0014, 14u>(ctx, &aot_mem); return;
    }
    goto L_089CE3D0;
L_089CE3D0:
    ctx.gpr[11] = (ctx.lo);
    goto L_089CE3D4;
L_089CE3D4:
    rt.unsupported(0x089CE3D4u, 0x6B636F43u, "unknown not lowered yet"); return;
L_089CE3E4:
    (void)(0u | 0u);
    goto L_089CE3E8;
L_089CE3E8:
    ctx.execute_vfpu_vcmp_ct<111u, 114u, 1u, 7u>();
    rt.unsupported(0x089CE3ECu, 0x70616D64u, "unknown not lowered yet"); return;
L_089CE3F8:
    ctx.gpr[13] = (ctx.gpr[27] < static_cast<std::uint32_t>(26466) ? 1u : 0u);
    ctx.gpr[14] = (0u | 0u);
    goto L_089CE400;
L_089CE400:
    rt.unsupported(0x089CE400u, 0x6E69614Du, "vfpu3 not lowered yet"); return;
L_089CE40C:
    rt.unsupported(0x089CE40Cu, 0x77617244u, "unknown not lowered yet"); return;
L_089CE418:
    rt.unsupported(0x089CE418u, 0x4C524F57u, "unknown not lowered yet"); return;
L_089CE424:
    ctx.gpr[26] = (ctx.gpr[17] ^ 20041u);
    rt.unsupported(0x089CE428u, 0x6E69614Du, "vfpu3 not lowered yet"); return;
L_089CE460:
    if (static_cast<std::int32_t>(ctx.gpr[27]) > 0) {
    rt.unsupported(0x089CE464u, 0x71696E75u, "unknown not lowered yet"); return;
        (void)rt.invoke_chained_direct<&recomp_unit_0015, 15u>(ctx, &aot_mem); return;
    }
    goto L_089CE468;
L_089CE468:
    ctx.gpr[26] = (ctx.gpr[17] ^ 25973u);
    rt.unsupported(0x089CE470u, 0x51494E55u, "control flow in delay slot"); return;
L_089CE474:
    rt.unsupported(0x089CE474u, 0x4D5F4555u, "unknown not lowered yet"); return;
L_089CE488:
    if (static_cast<std::int32_t>(ctx.gpr[27]) > 0) {
    rt.unsupported(0x089CE48Cu, 0x71696E75u, "unknown not lowered yet"); return;
        (void)rt.invoke_chained_direct<&recomp_unit_0015, 15u>(ctx, &aot_mem); return;
    }
    goto L_089CE490;
L_089CE490:
    ctx.gpr[26] = (ctx.gpr[17] ^ 25973u);
    rt.unsupported(0x089CE498u, 0x51494E55u, "control flow in delay slot"); return;
L_089CE49C:
    rt.unsupported(0x089CE49Cu, 0x4D5F4555u, "unknown not lowered yet"); return;
L_089CE4B4:
    if (static_cast<std::int32_t>(ctx.gpr[27]) > 0) {
    rt.unsupported(0x089CE4B8u, 0x71696E75u, "unknown not lowered yet"); return;
        (void)rt.invoke_chained_direct<&recomp_unit_0015, 15u>(ctx, &aot_mem); return;
    }
    goto L_089CE4BC;
L_089CE4BC:
    ctx.gpr[26] = (ctx.gpr[17] ^ 25973u);
    rt.unsupported(0x089CE4C4u, 0x51494E55u, "control flow in delay slot"); return;
L_089CE4C8:
    rt.unsupported(0x089CE4C8u, 0x4D5F4555u, "unknown not lowered yet"); return;
L_089CE4E0:
    if (static_cast<std::int32_t>(ctx.gpr[27]) > 0) {
    rt.unsupported(0x089CE4E4u, 0x71696E75u, "unknown not lowered yet"); return;
        (void)rt.invoke_chained_direct<&recomp_unit_0015, 15u>(ctx, &aot_mem); return;
    }
    goto L_089CE4E8;
L_089CE4E8:
    ctx.gpr[26] = (ctx.gpr[17] ^ 25973u);
    rt.unsupported(0x089CE4F0u, 0x51494E55u, "control flow in delay slot"); return;
L_089CE4F4:
    rt.unsupported(0x089CE4F4u, 0x4D5F4555u, "unknown not lowered yet"); return;
L_089CE508:
    ctx.gpr[10] = (ctx.gpr[19] ^ 25199u);
    rt.unsupported(0x089CE50Cu, 0x4F52503Au, "unknown not lowered yet"); return;
L_089CE51C:
    if (ctx.gpr[18] == ctx.gpr[5]) {
    rt.unsupported(0x089CE520u, 0x70553A3Au, "unknown not lowered yet"); return;
        (void)rt.invoke_chained_direct<&recomp_unit_0014, 14u>(ctx, &aot_mem); return;
    }
    goto L_089CE524;
L_089CE524:
    ctx.execute_vfpu_vscl_ct<100u, 97u, 116u, 1u>();
    // nop
    goto L_089CE52C;
L_089CE52C:
    ctx.gpr[10] = (ctx.gpr[19] ^ 25199u);
    rt.unsupported(0x089CE530u, 0x4F52503Au, "unknown not lowered yet"); return;
L_089CE540:
    if (ctx.gpr[18] == ctx.gpr[5]) {
    rt.unsupported(0x089CE544u, 0x72443A3Au, "unknown not lowered yet"); return;
        (void)rt.invoke_chained_direct<&recomp_unit_0014, 14u>(ctx, &aot_mem); return;
    }
    goto L_089CE548;
L_089CE548:
    ctx.gpr[14] = (0u + 0u);
    goto L_089CE54C;
L_089CE54C:
    if (ctx.gpr[2] != ctx.gpr[16]) {
    rt.unsupported(0x089CE550u, 0x4C425F48u, "unknown not lowered yet"); return;
        (void)rt.invoke_chained_direct<&recomp_unit_0014, 14u>(ctx, &aot_mem); return;
    }
    goto L_089CE554;
L_089CE554:
    ctx.gpr[26] = (ctx.gpr[17] ^ 21077u);
    rt.unsupported(0x089CE558u, 0x77617244u, "unknown not lowered yet"); return;
L_089CE560:
    rt.unsupported(0x089CE560u, 0x49504553u, "cop2/vfpu not lowered yet"); return;
L_089CE56C:
    rt.unsupported(0x089CE56Cu, 0x63657845u, "vfpu0 not lowered yet"); return;
L_089CE580:
    rt.unsupported(0x089CE580u, 0x77617244u, "unknown not lowered yet"); return;
L_089CE594:
    rt.unsupported(0x089CE594u, 0x74746162u, "unknown not lowered yet"); return;
L_089CE5AC:
    rt.unsupported(0x089CE5ACu, 0x74737543u, "unknown not lowered yet"); return;
L_089CE5BC:
    rt.unsupported(0x089CE5BCu, 0x706F6853u, "unknown not lowered yet"); return;
L_089CE620:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x0246B0A0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089CE630:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x0246B420u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089CE640:
    // nop
    // nop
    // nop
    rt.unsupported(0x089CE650u, 0x6B6C6174u, "unknown not lowered yet"); return;
    ctx.pc = 0x0246D080u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089CE650:
    rt.unsupported(0x089CE650u, 0x6B6C6174u, "unknown not lowered yet"); return;
L_089CE690:
    rt.unsupported(0x089CE690u, 0x61647055u, "vfpu0 not lowered yet"); return;
L_089CE698:
    if (ctx.gpr[2] != ctx.gpr[18]) {
    rt.unsupported(0x089CE69Cu, 0x41422059u, "unknown not lowered yet"); return;
        (void)rt.invoke_chained_direct<&recomp_unit_0014, 14u>(ctx, &aot_mem); return;
    }
    goto L_089CE6A0;
L_089CE6A0:
    rt.unsupported(0x089CE6A0u, 0x454C5454u, "cop1? not lowered yet"); return;
L_089CE6AC:
    // nop
    goto L_089CE6B0;
L_089CE6B0:
    rt.unsupported(0x089CE6B0u, 0x756E656Du, "unknown not lowered yet"); return;
L_089CE6D4:
    rt.unsupported(0x089CE6D4u, 0x69622E30u, "unknown not lowered yet"); return;
L_089CE6DC:
    rt.unsupported(0x089CE6DCu, 0x756E656Du, "unknown not lowered yet"); return;
L_089CE700:
    rt.unsupported(0x089CE700u, 0x69622E30u, "unknown not lowered yet"); return;
L_089CE708:
    rt.unsupported(0x089CE708u, 0x756E656Du, "unknown not lowered yet"); return;
L_089CE730:
    rt.unsupported(0x089CE730u, 0x69622E30u, "unknown not lowered yet"); return;
L_089CE738:
    rt.unsupported(0x089CE738u, 0x74786574u, "unknown not lowered yet"); return;
L_089CE74C:
    rt.unsupported(0x089CE74Cu, 0x61625F79u, "vfpu0 not lowered yet"); return;
L_089CE768:
    rt.unsupported(0x089CE768u, 0x0000006Eu, "special? not lowered yet"); return;
L_089CE76C:
    rt.unsupported(0x089CE76Cu, 0x74786574u, "unknown not lowered yet"); return;
L_089CE780:
    rt.unsupported(0x089CE780u, 0x61625F79u, "vfpu0 not lowered yet"); return;
L_089CE7C0:
    rt.unsupported(0x089CE7C0u, 0x676E7564u, "vfpu1 not lowered yet"); return;
L_089CE7D4:
    rt.unsupported(0x089CE7D4u, 0x75642E79u, "unknown not lowered yet"); return;
L_089CE7DC:
    ctx.gpr[14] = (ctx.gpr[3] & ctx.gpr[5]);
    goto L_089CE7E0;
L_089CE7E0:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x0247FD80u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089CE878:
    // nop
    rt.unsupported(0x089CE87Cu, 0x00020001u, "special? not lowered yet"); return;
L_089CE894:
    rt.unsupported(0x089CE894u, 0x000E000Du, "special? not lowered yet"); return;
L_089CEA88:
    rt.unsupported(0x089CEA88u, 0x7773616Du, "unknown not lowered yet"); return;
L_089CEA90:
    rt.unsupported(0x089CEA90u, 0x7165732Eu, "unknown not lowered yet"); return;
L_089CEA9C:
    ctx.execute_vfpu_vminmax(46u, 103u, 105u, 1u, false);
    // nop
    goto L_089CEAA4;
L_089CEAA4:
    rt.unsupported(0x089CEAA4u, 0x6769726Fu, "vfpu1 not lowered yet"); return;
L_089CEAC0:
    if (static_cast<std::int32_t>(ctx.gpr[27]) > 0) {
    ctx.execute_vfpu_vscl_ct<108u, 111u, 115u, 1u>();
        (void)rt.invoke_chained_direct<&recomp_unit_0015, 15u>(ctx, &aot_mem); return;
    }
    goto L_089CEAC8;
L_089CEAC8:
    rt.unsupported(0x089CEAC8u, 0x6E6F635Fu, "vfpu3 not lowered yet"); return;
L_089CEAE0:
    rt.unsupported(0x089CEAE0u, 0x454B414Du, "cop1? not lowered yet"); return;
L_089CEAEC:
    rt.unsupported(0x089CEAECu, 0x74786574u, "unknown not lowered yet"); return;
L_089CEB58:
    rt.unsupported(0x089CEB5Cu, 0x54534555u, "control flow in delay slot"); return;
L_089CEB60:
    // nop
    goto L_089CEB64;
L_089CEB64:
    // nop
    rt.unsupported(0x089CEB68u, 0x00000001u, "special? not lowered yet"); return;
L_089CEB78:
    rt.unsupported(0x089CEB7Cu, 0x54534555u, "control flow in delay slot"); return;
L_089CEB80:
    // nop
    // nop
    goto L_089CEB88;
L_089CEB88:
    (void)(0u & 0u);
    (void)(0u & 0u);
    (void)(0u & 0u);
    (void)(0u & 0u);
    (void)(0u & 0u);
    (void)(0u & 0u);
    (void)(0u >> 0u);
    (void)(0u & 0u);
    (void)(0u & 0u);
    rt.unsupported(0x089CEBACu, 0x00000014u, "special? not lowered yet"); return;
L_089CEBE0:
    rt.unsupported(0x089CEBE0u, 0x61647055u, "vfpu0 not lowered yet"); return;
L_089CEBE8:
    if (ctx.gpr[2] != ctx.gpr[12]) {
    rt.unsupported(0x089CEBECu, 0x4F4C2049u, "unknown not lowered yet"); return;
        (void)rt.invoke_chained_direct<&recomp_unit_0015, 15u>(ctx, &aot_mem); return;
    }
    goto L_089CEBF0;
L_089CEBF0:
    rt.unsupported(0x089CEBF0u, 0x20594242u, "unknown not lowered yet"); return;
L_089CEBFC:
    // nop
    goto L_089CEC00;
L_089CEC00:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x024AB0B0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089CEC50:
    rt.unsupported(0x089CEC50u, 0x61647055u, "vfpu0 not lowered yet"); return;
L_089CEC58:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x024AE720u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089CECA0:
    rt.unsupported(0x089CECA0u, 0x00110001u, "special? not lowered yet"); return;
L_089CECC8:
    (void)(ctx.gpr[7] << 0u);
    // vflush: architectural no-op that retains VFPU prefixes
    rt.unsupported(0x089CECD0u, 0x00000001u, "special? not lowered yet"); return;
L_089CECE0:
    rt.unsupported(0x089CECE0u, 0x00190014u, "special? not lowered yet"); return;
L_089CECF8:
    (void)(ctx.lo);
    jump_target = 0u;
    (void)(0u >> 0u);
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089CED1C:
    (void)(ctx.gpr[3] | ctx.gpr[4]);
    // nop
    // nop
    jump_target = 0u;
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089CED38:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x024B31E0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089CED80:
    rt.unsupported(0x089CED80u, 0x00110001u, "special? not lowered yet"); return;
L_089CED98:
    (void)(ctx.gpr[13] << 0u);
    // vflush: architectural no-op that retains VFPU prefixes
    // vflush: architectural no-op that retains VFPU prefixes
    // vflush: architectural no-op that retains VFPU prefixes
    goto L_089CEDA8;
L_089CEDA8:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x024B4580u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089CEDF0:
    (void)(ctx.gpr[3] << 0u);
    // vflush: architectural no-op that retains VFPU prefixes
    rt.unsupported(0x089CEDF8u, 0x00020001u, "special? not lowered yet"); return;
L_089CEE20:
    rt.unsupported(0x089CEE20u, 0x00110001u, "special? not lowered yet"); return;
L_089CEE68:
    jump_target = 0u;
    (void)(static_cast<std::uint32_t>(static_cast<std::int32_t>(ctx.gpr[1]) >> 0u));
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089CEE88:
    (void)(ctx.gpr[3] | ctx.gpr[4]);
    // nop
    goto L_089CEE90;
L_089CEE90:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x024B6DA0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089CEEE0:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x024B8910u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089CEF30:
    rt.unsupported(0x089CEF30u, 0x00000001u, "special? not lowered yet"); return;
L_089CEF48:
    (void)(ctx.gpr[18] << 0u);
    // nop
    // vflush: architectural no-op that retains VFPU prefixes
    // vflush: architectural no-op that retains VFPU prefixes
    (void)(0u << (0u & 31u));
    // nop
    goto L_089CEF60;
L_089CEF60:
    (void)(ctx.gpr[3] | ctx.gpr[4]);
    // nop
    goto L_089CEF68;
L_089CEF68:
    (void)(ctx.gpr[3] | ctx.gpr[19]);
    // nop
    rt.unsupported(0x089CEF74u, 0x0892E4F4u, "control flow in delay slot"); return;
L_089CEFF0:
    // nop
    // vflush: architectural no-op that retains VFPU prefixes
    // vflush: architectural no-op that retains VFPU prefixes
    // vflush: architectural no-op that retains VFPU prefixes
    goto L_089CF000;
L_089CF000:
    (void)(ctx.gpr[18] << 0u);
    // nop
    // vflush: architectural no-op that retains VFPU prefixes
    // vflush: architectural no-op that retains VFPU prefixes
    goto L_089CF010;
L_089CF010:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x024BD0D0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089CF058:
    rt.unsupported(0x089CF058u, 0x00120001u, "special? not lowered yet"); return;
L_089CF080:
    (void)(ctx.gpr[5] << 0u);
    // vflush: architectural no-op that retains VFPU prefixes
    // vflush: architectural no-op that retains VFPU prefixes
    // vflush: architectural no-op that retains VFPU prefixes
    goto L_089CF090;
L_089CF090:
    (void)(ctx.gpr[18] << 0u);
    (void)(ctx.gpr[1] << 0u);
    // vflush: architectural no-op that retains VFPU prefixes
    // vflush: architectural no-op that retains VFPU prefixes
    goto L_089CF0A0;
L_089CF0A0:
    (void)(ctx.gpr[4] << 0u);
    rt.unsupported(0x089CF0A4u, 0x00000005u, "special? not lowered yet"); return;
L_089CF0D0:
    (void)(ctx.gpr[3] | ctx.gpr[4]);
    rt.unsupported(0x089CF0D4u, 0x0025002Fu, "special? not lowered yet"); return;
L_089CF0F0:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x024BFA50u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089CF138:
    // nop
    // vflush: architectural no-op that retains VFPU prefixes
    // vflush: architectural no-op that retains VFPU prefixes
    // vflush: architectural no-op that retains VFPU prefixes
    goto L_089CF148;
L_089CF148:
    (void)(ctx.gpr[18] << 0u);
    // nop
    // vflush: architectural no-op that retains VFPU prefixes
    // vflush: architectural no-op that retains VFPU prefixes
    goto L_089CF158;
L_089CF158:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x024C2F90u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089CF1A0:
    rt.unsupported(0x089CF1A0u, 0x00140001u, "special? not lowered yet"); return;
L_089CF1B8:
    rt.unsupported(0x089CF1B8u, 0x000B0001u, "special? not lowered yet"); return;
L_089CF1CC:
    (void)(ctx.gpr[19] << 0u);
    // vflush: architectural no-op that retains VFPU prefixes
    // vflush: architectural no-op that retains VFPU prefixes
    // vflush: architectural no-op that retains VFPU prefixes
    goto L_089CF1DC;
L_089CF1DC:
    rt.unsupported(0x089CF1DCu, 0x00040005u, "special? not lowered yet"); return;
L_089CF200:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x024C7680u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089CF230:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x024C7AE0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089CF260:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x024C8FB0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089CF290:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x024CABD0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089CF2D8:
    // vflush: architectural no-op that retains VFPU prefixes
    // nop
    // vflush: architectural no-op that retains VFPU prefixes
    // vflush: architectural no-op that retains VFPU prefixes
    goto L_089CF2E8;
L_089CF2E8:
    (void)(ctx.gpr[17] << 0u);
    (void)(ctx.gpr[1] << 0u);
    rt.unsupported(0x089CF2F0u, 0x00090001u, "special? not lowered yet"); return;
L_089CF308:
    (void)(ctx.gpr[17] << 0u);
    (void)(static_cast<std::uint32_t>(static_cast<std::int32_t>(0u) >> 0u));
    rt.unsupported(0x089CF310u, 0x00110001u, "special? not lowered yet"); return;
L_089CF340:
    (void)(ctx.gpr[3] << 0u);
    // vflush: architectural no-op that retains VFPU prefixes
    // vflush: architectural no-op that retains VFPU prefixes
    // vflush: architectural no-op that retains VFPU prefixes
    goto L_089CF350;
L_089CF350:
    // nop
    (void)(ctx.gpr[23] << 0u);
    rt.unsupported(0x089CF358u, 0x00220001u, "special? not lowered yet"); return;
L_089CF3DC:
    (void)(ctx.gpr[1] << 0u);
    (void)(ctx.gpr[3] >> 0u);
    (void)(0u << (0u & 31u));
    goto L_089CF3E8;
L_089CF3E8:
    (void)(ctx.gpr[3] | ctx.gpr[4]);
    // nop
    if (static_cast<std::int32_t>(ctx.gpr[16]) >= 0) {
    ctx.execute_vfpu_vscl_ct<103u, 101u, 110u, 1u>();
        goto L_089CF434;
    }
    goto L_089CF3F8;
L_089CF3F8:
    if (static_cast<std::int32_t>(ctx.gpr[27]) > 0) {
    rt.unsupported(0x089CF3FCu, 0x68637261u, "unknown not lowered yet"); return;
        (void)rt.invoke_chained_direct<&recomp_unit_0015, 15u>(ctx, &aot_mem); return;
    }
    goto L_089CF400;
L_089CF400:
    ctx.gpr[5] = (ctx.gpr[27] < static_cast<std::uint32_t>(30313) ? 1u : 0u);
    rt.unsupported(0x089CF404u, 0x6E69616Du, "vfpu3 not lowered yet"); return;
L_089CF420:
    ctx.gpr[5] = (ctx.gpr[27] < static_cast<std::uint32_t>(30313) ? 1u : 0u);
    rt.unsupported(0x089CF424u, 0x6E69616Du, "vfpu3 not lowered yet"); return;
L_089CF434:
    rt.unsupported(0x089CF434u, 0x69622E67u, "unknown not lowered yet"); return;
L_089CF448:
    ctx.gpr[5] = (ctx.gpr[27] < static_cast<std::uint32_t>(30313) ? 1u : 0u);
    rt.unsupported(0x089CF44Cu, 0x6E69616Du, "vfpu3 not lowered yet"); return;
L_089CF470:
    ctx.gpr[5] = (ctx.gpr[27] < static_cast<std::uint32_t>(30313) ? 1u : 0u);
    rt.unsupported(0x089CF474u, 0x6E69616Du, "vfpu3 not lowered yet"); return;
L_089CF494:
    rt.unsupported(0x089CF494u, 0x74697865u, "unknown not lowered yet"); return;
L_089CF49C:
    ctx.gpr[10] = (ctx.gpr[4] << (ctx.gpr[2] & 31u));
    goto L_089CF4A0;
L_089CF4A0:
    rt.unsupported(0x089CF4A0u, 0x6E756F73u, "vfpu3 not lowered yet"); return;
L_089CF4B8:
    if (static_cast<std::int32_t>(ctx.gpr[27]) > 0) {
    ctx.execute_vfpu_vminmax(99u, 111u, 109u, 1u, false);
        (void)rt.invoke_chained_direct<&recomp_unit_0015, 15u>(ctx, &aot_mem); return;
    }
    goto L_089CF4C0;
L_089CF4C0:
    rt.unsupported(0x089CF4C0u, 0x732E6E6Fu, "unknown not lowered yet"); return;
L_089CF4D4:
    rt.unsupported(0x089CF4D4u, 0x7070615Fu, "unknown not lowered yet"); return;
L_089CF4E8:
    rt.unsupported(0x089CF4E8u, 0x615F656Cu, "vfpu0 not lowered yet"); return;
L_089CF4FC:
    rt.unsupported(0x089CF4FCu, 0x70615F61u, "unknown not lowered yet"); return;
L_089CF508:
    rt.unsupported(0x089CF508u, 0x73257325u, "unknown not lowered yet"); return;
L_089CF510:
    rt.unsupported(0x089CF514u, 0x5F59414Cu, "control flow in delay slot"); return;
L_089CF518:
    rt.unsupported(0x089CF518u, 0x45444F4Du, "cop1? not lowered yet"); return;
L_089CF530:
    rt.unsupported(0x089CF530u, 0x6362696Cu, "vfpu0 not lowered yet"); return;
L_089CF55C:
    rt.unsupported(0x089CF55Cu, 0x6362696Cu, "vfpu0 not lowered yet"); return;
L_089CF580:
    rt.unsupported(0x089CF584u, 0x72657355u, "unknown not lowered yet"); return;
    ctx.pc = 0x024D12C0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089CF584:
    rt.unsupported(0x089CF584u, 0x72657355u, "unknown not lowered yet"); return;
L_089CF590:
    rt.unsupported(0x089CF590u, 0x20202000u, "unknown not lowered yet"); return;
L_089CF5B8:
    rt.unsupported(0x089CF5BCu, 0x10101010u, "control flow in delay slot"); return;
L_089CF5C0:
    rt.unsupported(0x089CF5C0u, 0x04040410u, "regimm? not lowered yet"); return;
L_089CF5D0:
    rt.unsupported(0x089CF5D0u, 0x41411010u, "unknown not lowered yet"); return;
L_089CF5F4:
    rt.unsupported(0x089CF5F4u, 0x42424242u, "unknown not lowered yet"); return;
L_089CF614:
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    (void)(static_cast<std::uint32_t>(static_cast<std::int32_t>(0u) >> 1u));
    // nop
    goto L_089CF6A0;
L_089CF6A0:
    ctx.execute_vfpu_vhdp(45u, 73u, 110u, 1u);
    // nop
    jump_target = ctx.gpr[3];
    ctx.gpr[13] = (0x089CF6B0u);
    rt.unsupported(0x089CF6ACu, 0x004E614Eu, "special? not lowered yet"); return;
    ctx.pc = jump_target;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x089CF6B0u) goto L_089CF6B0;
    return;
L_089CF6B0:
    // nop
    // nop
    // nop
    ctx.gpr[16] = (0u << 16u);
    // nop
    rt.unsupported(0x089CF6C4u, 0x40240000u, "unknown not lowered yet"); return;
L_089CF6D8:
    rt.unsupported(0x089CF6D8u, 0x20202020u, "unknown not lowered yet"); return;
L_089CF6E8:
    ctx.gpr[16] = (ctx.gpr[1] & 12336u);
    ctx.gpr[16] = (ctx.gpr[1] & 12336u);
    ctx.gpr[16] = (ctx.gpr[1] & 12336u);
    ctx.gpr[16] = (ctx.gpr[1] & 12336u);
    goto L_089CF6F8;
L_089CF6F8:
    ctx.gpr[18] = (ctx.gpr[25] & 12592u);
    ctx.gpr[22] = (ctx.gpr[25] | 13620u);
    rt.unsupported(0x089CF700u, 0x62613938u, "vfpu0 not lowered yet"); return;
L_089CF70C:
    ctx.execute_vfpu_vcmp_ct<110u, 117u, 1u, 8u>();
    ctx.gpr[5] = (static_cast<std::int32_t>(0u) > static_cast<std::int32_t>(0u) ? 0u : 0u);
    goto L_089CF714;
L_089CF714:
    ctx.gpr[18] = (ctx.gpr[25] & 12592u);
    ctx.gpr[22] = (ctx.gpr[25] | 13620u);
    rt.unsupported(0x089CF71Cu, 0x42413938u, "unknown not lowered yet"); return;
L_089CF728:
    rt.unsupported(0x089CF728u, 0x20677562u, "unknown not lowered yet"); return;
L_089CF970:
    rt.unsupported(0x089CF970u, 0x20202020u, "unknown not lowered yet"); return;
L_089CF980:
    ctx.gpr[16] = (ctx.gpr[1] & 12336u);
    ctx.gpr[16] = (ctx.gpr[1] & 12336u);
    ctx.gpr[16] = (ctx.gpr[1] & 12336u);
    ctx.gpr[16] = (ctx.gpr[1] & 12336u);
    goto L_089CF990;
L_089CF990:
    ctx.gpr[18] = (ctx.gpr[25] & 12592u);
    ctx.gpr[22] = (ctx.gpr[25] | 13620u);
    rt.unsupported(0x089CF998u, 0x62613938u, "vfpu0 not lowered yet"); return;
L_089CF9A4:
    ctx.execute_vfpu_vcmp_ct<110u, 117u, 1u, 8u>();
    ctx.gpr[5] = (static_cast<std::int32_t>(0u) > static_cast<std::int32_t>(0u) ? 0u : 0u);
    goto L_089CF9AC;
L_089CF9AC:
    ctx.gpr[18] = (ctx.gpr[25] & 12592u);
    ctx.gpr[22] = (ctx.gpr[25] | 13620u);
    rt.unsupported(0x089CF9B4u, 0x42413938u, "unknown not lowered yet"); return;
L_089CF9C0:
    rt.unsupported(0x089CF9C0u, 0x20677562u, "unknown not lowered yet"); return;
L_089CFB70:
    (void)(static_cast<std::int32_t>(ctx.gpr[2]) < static_cast<std::int32_t>(ctx.gpr[9]) ? ctx.gpr[2] : ctx.gpr[9]);
    rt.unsupported(0x089CFB74u, 0x0066006Eu, "special? not lowered yet"); return;
L_089CFB84:
    rt.unsupported(0x089CFB84u, 0x0061004Eu, "special? not lowered yet"); return;
L_089CFBC0:
    { const bool signed_ok = ctx.execute_signed_add(0u, 1u, 0u);
      if (!signed_ok) { rt.arithmetic_overflow(0x089CFBC0u, 0x00200020u); return; } }
    { const bool signed_ok = ctx.execute_signed_add(0u, 1u, 0u);
      if (!signed_ok) { rt.arithmetic_overflow(0x089CFBC4u, 0x00200020u); return; } }
    { const bool signed_ok = ctx.execute_signed_add(0u, 1u, 0u);
      if (!signed_ok) { rt.arithmetic_overflow(0x089CFBC8u, 0x00200020u); return; } }
    { const bool signed_ok = ctx.execute_signed_add(0u, 1u, 0u);
      if (!signed_ok) { rt.arithmetic_overflow(0x089CFBCCu, 0x00200020u); return; } }
    { const bool signed_ok = ctx.execute_signed_add(0u, 1u, 0u);
      if (!signed_ok) { rt.arithmetic_overflow(0x089CFBD0u, 0x00200020u); return; } }
    { const bool signed_ok = ctx.execute_signed_add(0u, 1u, 0u);
      if (!signed_ok) { rt.arithmetic_overflow(0x089CFBD4u, 0x00200020u); return; } }
    { const bool signed_ok = ctx.execute_signed_add(0u, 1u, 0u);
      if (!signed_ok) { rt.arithmetic_overflow(0x089CFBD8u, 0x00200020u); return; } }
    { const bool signed_ok = ctx.execute_signed_add(0u, 1u, 0u);
      if (!signed_ok) { rt.arithmetic_overflow(0x089CFBDCu, 0x00200020u); return; } }
    goto L_089CFBE0;
L_089CFBE0:
    rt.unsupported(0x089CFBE0u, 0x00300030u, "special? not lowered yet"); return;
L_089CFC00:
    rt.unsupported(0x089CFC00u, 0x00310030u, "special? not lowered yet"); return;
L_089CFC24:
    rt.unsupported(0x089CFC24u, 0x006E0028u, "special? not lowered yet"); return;
L_089CFC34:
    rt.unsupported(0x089CFC34u, 0x00310030u, "special? not lowered yet"); return;
L_089CFC58:
    { const bool signed_ok = ctx.execute_signed_sub(0u, 3u, 21u);
      if (!signed_ok) { rt.arithmetic_overflow(0x089CFC58u, 0x00750062u); return; } }
    (void)(~(ctx.gpr[1] | 0u));
    rt.unsupported(0x089CFC60u, 0x006E0069u, "special? not lowered yet"); return;
L_089CFE90:
    { const bool signed_ok = ctx.execute_signed_add(0u, 1u, 0u);
      if (!signed_ok) { rt.arithmetic_overflow(0x089CFE90u, 0x00200020u); return; } }
    { const bool signed_ok = ctx.execute_signed_add(0u, 1u, 0u);
      if (!signed_ok) { rt.arithmetic_overflow(0x089CFE94u, 0x00200020u); return; } }
    { const bool signed_ok = ctx.execute_signed_add(0u, 1u, 0u);
      if (!signed_ok) { rt.arithmetic_overflow(0x089CFE98u, 0x00200020u); return; } }
    { const bool signed_ok = ctx.execute_signed_add(0u, 1u, 0u);
      if (!signed_ok) { rt.arithmetic_overflow(0x089CFE9Cu, 0x00200020u); return; } }
    { const bool signed_ok = ctx.execute_signed_add(0u, 1u, 0u);
      if (!signed_ok) { rt.arithmetic_overflow(0x089CFEA0u, 0x00200020u); return; } }
    { const bool signed_ok = ctx.execute_signed_add(0u, 1u, 0u);
      if (!signed_ok) { rt.arithmetic_overflow(0x089CFEA4u, 0x00200020u); return; } }
    { const bool signed_ok = ctx.execute_signed_add(0u, 1u, 0u);
      if (!signed_ok) { rt.arithmetic_overflow(0x089CFEA8u, 0x00200020u); return; } }
    { const bool signed_ok = ctx.execute_signed_add(0u, 1u, 0u);
      if (!signed_ok) { rt.arithmetic_overflow(0x089CFEACu, 0x00200020u); return; } }
    goto L_089CFEB0;
L_089CFEB0:
    rt.unsupported(0x089CFEB0u, 0x00300030u, "special? not lowered yet"); return;
L_089CFED0:
    rt.unsupported(0x089CFED0u, 0x00310030u, "special? not lowered yet"); return;
L_089CFEF4:
    rt.unsupported(0x089CFEF4u, 0x006E0028u, "special? not lowered yet"); return;
L_089CFF04:
    rt.unsupported(0x089CFF04u, 0x00310030u, "special? not lowered yet"); return;
L_089CFF28:
    { const bool signed_ok = ctx.execute_signed_sub(0u, 3u, 21u);
      if (!signed_ok) { rt.arithmetic_overflow(0x089CFF28u, 0x00750062u); return; } }
    (void)(~(ctx.gpr[1] | 0u));
    rt.unsupported(0x089CFF30u, 0x006E0069u, "special? not lowered yet"); return;
L_089D0000:
    rt.unsupported(0x089D0004u, 0x0893C500u, "control flow in delay slot"); return;
L_089D00D0:
    rt.unsupported(0x089D00D4u, 0x089D00CCu, "control flow in delay slot"); return;
L_089D0128:
    // nop
    // nop
    // nop
    (void)(static_cast<std::uint32_t>(static_cast<std::int32_t>(static_cast<std::int8_t>(aot_mem.aot_load8(0u + static_cast<std::uint32_t>(0))))));
    ctx.eat_vfpu_prefixes(); // VFPU sync/no-op consumes prefixes
    ctx.gpr[6] = (11842u << 16u);
    ctx.gpr[25] = (ctx.gpr[11] | 15478u);
    ctx.gpr[10] = (14831u << 16u);
    // nop
    rt.unsupported(0x089D014Cu, 0x43500000u, "unknown not lowered yet"); return;
L_089D0158:
    ctx.gpr[23] = (rt.memory().aot_load_word_right(ctx.gpr[12] + static_cast<std::uint32_t>(-1532), ctx.gpr[23]));
    ctx.gpr[25] = (39321u << 16u);
    ctx.gpr[2] = (aot_mem.aot_load16(ctx.gpr[1] + static_cast<std::uint32_t>(-27815)));
    ctx.gpr[18] = (18724u << 16u);
    { const bool branch_taken = static_cast<std::int32_t>(ctx.gpr[12]) > 0;
    ctx.gpr[12] = (29125u << 16u);
      if (branch_taken) {
          (void)rt.invoke_chained_direct<&recomp_unit_0015, 15u>(ctx, &aot_mem); return;
      }
      goto L_089D0170;
    }
L_089D0170:
    ctx.gpr[11] = (aot_mem.aot_load16(ctx.gpr[22] + static_cast<std::uint32_t>(990)));
    ctx.gpr[7] = (18020u << 16u);
    { const float vfpu_constant = std::bit_cast<float>(0x00000000u);
      const float vfpu_value[4]{vfpu_constant, vfpu_constant, vfpu_constant, vfpu_constant};
      ctx.write_vfpu_vector_with_destination_prefix_ct<31u, 4u>(vfpu_value); }
    ctx.gpr[3] = (39433u << 16u);
    { const float vfpu_value[1]{static_cast<float>(21060)};
      ctx.write_vfpu_vector_with_destination_prefix_ct<62u, 1u>(vfpu_value); }
    ctx.gpr[2] = (61714u << 16u);
    // nop
    // nop
    { const bool branch_taken = ctx.gpr[9] != ctx.gpr[6];
    ctx.gpr[27] = (52091u << 16u);
      if (branch_taken) {
          goto L_089C95CC;
      }
      goto L_089D0198;
    }
L_089D0198:
    if (ctx.gpr[4] == ctx.gpr[31]) {
    ctx.gpr[19] = (17427u << 16u);
        (void)rt.invoke_chained_direct<&recomp_unit_0015, 15u>(ctx, &aot_mem); return;
    }
    goto L_089D01A0;
L_089D01A0:
    { const bool branch_taken = ctx.gpr[15] == ctx.gpr[17];
    ctx.gpr[25] = (65267u << 16u);
      if (branch_taken) {
          goto L_089DAE7C;
      }
      goto L_089D01A8;
    }
L_089D01A8:
    // nop
    rt.unsupported(0x089D01ACu, 0xC3500000u, "unknown not lowered yet"); return;
L_089D01B8:
    // nop
    (void)(0u << 16u);
    // nop
    rt.unsupported(0x089D01C4u, 0x40000000u, "unknown not lowered yet"); return;
L_089D01C8:
    rt.unsupported(0x089D01C8u, 0x4A532D43u, "cop2/vfpu not lowered yet"); return;
L_089D01D4:
    ctx.gpr[9] = (static_cast<std::uint32_t>(static_cast<std::int32_t>(ctx.gpr[16]) >> 9u));
    rt.unsupported(0x089D01D8u, 0x494A2D43u, "cop2/vfpu not lowered yet"); return;
L_089D0200:
    rt.unsupported(0x089D0200u, 0x67452301u, "vfpu1 not lowered yet"); return;
L_089D0214:
    ctx.gpr[18] = (31068u << 16u);
    (void)(ctx.gpr[3] & 25440u);
    rt.unsupported(0x089D021Cu, 0x79747B7Eu, "unknown not lowered yet"); return;
L_089D022C:
    rt.unsupported(0x089D022Cu, 0x47656353u, "cop1? not lowered yet"); return;
L_089D02C0:
    if (0u == 0u) (void)(0u);
    { float vfpu_s[4]{}, vfpu_t[4]{}, vfpu_d[4]{};
      ctx.read_vfpu_vector_with_source_prefix_ct<32u, 1u, 0u>(vfpu_s);
      ctx.read_vfpu_vector_with_source_prefix_ct<37u, 1u, 1u>(vfpu_t);
      for (std::uint32_t i = 0; i < 1u; ++i) vfpu_d[i] = vfpu_s[i] * vfpu_t[i];
      ctx.write_vfpu_vector_with_destination_prefix_ct<61u, 1u>(vfpu_d); }
    if (0u == 0u) (void)(0u);
    // nop
    if (0u == 0u) (void)(0u);
    // nop
    (void)rt.invoke_chained_direct<&recomp_unit_0136, 136u>(ctx, &aot_mem); return;
L_089D04F0:
    rt.unsupported(0x089D04F4u, 0x0895181Cu, "control flow in delay slot"); return;
L_089D05DC:
    rt.unsupported(0x089D05E0u, 0x0897098Cu, "control flow in delay slot"); return;
L_089D0628:
    (void)(static_cast<std::uint32_t>(static_cast<std::int32_t>(0u) >> 0u));
    // nop
    rt.unsupported(0x089D0630u, 0x00000001u, "special? not lowered yet"); return;
L_089D0648:
    // nop
    rt.unsupported(0x089D064Cu, 0x00000001u, "special? not lowered yet"); return;
L_089D0660:
    // nop
    rt.unsupported(0x089D0664u, 0x00000001u, "special? not lowered yet"); return;
L_089D066C:
    (void)(static_cast<std::uint32_t>(static_cast<std::int32_t>(0u) >> 0u));
    // nop
    rt.unsupported(0x089D0674u, 0x00000001u, "special? not lowered yet"); return;
L_089D067C:
    jump_target = 0u;
    (void)(ctx.hi);
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089D0908:
    rt.unsupported(0x089D0908u, 0x49445541u, "cop2/vfpu not lowered yet"); return;
L_089D091C:
    rt.unsupported(0x089D091Cu, 0x43494F56u, "unknown not lowered yet"); return;
L_089D0928:
    rt.unsupported(0x089D0928u, 0x45525453u, "cop1? not lowered yet"); return;
L_089D0988:
    ctx.execute_vfpu_vminmax(102u, 97u, 116u, 1u, false);
    rt.unsupported(0x089D098Cu, 0x003A3073u, "special? not lowered yet"); return;
L_089D0990:
    ctx.gpr[16] = (ctx.gpr[17] ^ 29549u);
    // nop
    goto L_089D0998;
L_089D0998:
    rt.unsupported(0x089D0998u, 0x0000002Fu, "special? not lowered yet"); return;
L_089D09B4:
    rt.unsupported(0x089D09B4u, 0x4C4C5353u, "unknown not lowered yet"); return;
L_089D09BC:
    rt.unsupported(0x089D09BCu, 0x4C4C4C4Cu, "unknown not lowered yet"); return;
L_089D09D0:
    rt.unsupported(0x089D09D0u, 0x4C4C5353u, "unknown not lowered yet"); return;
L_089D09D8:
    if (ctx.gpr[26] == ctx.gpr[12]) {
    rt.unsupported(0x089D09DCu, 0x4C4C4C53u, "unknown not lowered yet"); return;
        (void)rt.invoke_chained_direct<&recomp_unit_0014, 14u>(ctx, &aot_mem); return;
    }
    goto L_089D09E0;
L_089D09E0:
    rt.unsupported(0x089D09E0u, 0x004C4C4Cu, "syscall not lowered yet"); return;
L_089D09E4:
    rt.unsupported(0x089D09E4u, 0x4C4C5353u, "unknown not lowered yet"); return;
L_089D0A04:
    rt.unsupported(0x089D0A04u, 0x0000002Fu, "special? not lowered yet"); return;
L_089D0A08:
    rt.unsupported(0x089D0A08u, 0x4D4D5544u, "unknown not lowered yet"); return;
L_089D0A18:
    rt.unsupported(0x089D0A18u, 0x0000002Eu, "special? not lowered yet"); return;
L_089D0A1C:
    ctx.gpr[16] = (ctx.gpr[17] ^ 29549u);
    // nop
    goto L_089D0A24;
L_089D0A24:
    rt.unsupported(0x089D0A24u, 0x4E4F4349u, "unknown not lowered yet"); return;
L_089D0A2C:
    ctx.gpr[9] = (ctx.hi);
    ctx.lo = ctx.gpr[2];
    goto L_089D0A34;
L_089D0A34:
    rt.unsupported(0x089D0A34u, 0x4F46532Eu, "unknown not lowered yet"); return;
L_089D0A3C:
    ctx.gpr[16] = (ctx.gpr[25] & 9517u);
    (void)(0u & 0u);
    goto L_089D0A44;
L_089D0A44:
    ctx.gpr[16] = (ctx.gpr[17] ^ 29549u);
    rt.unsupported(0x089D0A48u, 0x4349502Fu, "unknown not lowered yet"); return;
L_089D0A54:
    ctx.gpr[16] = (ctx.gpr[17] ^ 29549u);
    rt.unsupported(0x089D0A58u, 0x4449562Fu, "unsupported CFC1 control register"); return;
    rt.unsupported(0x089D0A5Cu, 0x00004F45u, "special? not lowered yet"); return;
L_089D0A60:
    ctx.gpr[16] = (ctx.gpr[17] ^ 29549u);
    rt.unsupported(0x089D0A68u, 0x00004349u, "control flow in delay slot"); return;
L_089D0A6C:
    ctx.gpr[16] = (ctx.gpr[17] ^ 29549u);
    if (ctx.gpr[2] == ctx.gpr[19]) {
    // nop
        (void)rt.invoke_chained_direct<&recomp_unit_0015, 15u>(ctx, &aot_mem); return;
    }
    goto L_089D0A78;
L_089D0A78:
    rt.unsupported(0x089D0A7Cu, 0x54414445u, "control flow in delay slot"); return;
L_089D0A80:
    rt.unsupported(0x089D0A80u, 0x00000041u, "special? not lowered yet"); return;
L_089D0A84:
    ctx.gpr[16] = (ctx.gpr[17] ^ 29549u);
    rt.unsupported(0x089D0A88u, 0x4943442Fu, "cop2/vfpu not lowered yet"); return;
L_089D0A90:
    rt.unsupported(0x089D0A90u, 0x4F48502Fu, "unknown not lowered yet"); return;
L_089D0A98:
    rt.unsupported(0x089D0A9Cu, 0x00004349u, "control flow in delay slot"); return;
L_089D0AA0:
    rt.unsupported(0x089D0AA0u, 0x4D41472Fu, "unknown not lowered yet"); return;
L_089D0AA8:
    ctx.gpr[16] = (ctx.gpr[17] ^ 29549u);
    if (ctx.gpr[26] == ctx.gpr[19]) {
    ctx.lo = 0u;
        (void)rt.invoke_chained_direct<&recomp_unit_0014, 14u>(ctx, &aot_mem); return;
    }
    goto L_089D0AB4;
L_089D0AB4:
    rt.unsupported(0x089D0AB4u, 0x4D4F432Fu, "unknown not lowered yet"); return;
L_089D0ABC:
    rt.unsupported(0x089D0AC0u, 0x089AA854u, "control flow in delay slot"); return;
L_089D0AE8:
    rt.unsupported(0x089D0AE8u, 0x00002E2Eu, "special? not lowered yet"); return;
L_089D0B0C:
    rt.unsupported(0x089D0B0Cu, 0x456E6961u, "cop1? not lowered yet"); return;
L_089D0B1C:
    ctx.gpr[13] = (ctx.gpr[3] + ctx.gpr[14]);
    goto L_089D0B20;
L_089D0B20:
    ctx.gpr[11] = (static_cast<std::int32_t>(ctx.gpr[25]) < 17162 ? 1u : 0u);
    rt.unsupported(0x089D0B24u, 0x6E757220u, "vfpu3 not lowered yet"); return;
L_089D0B34:
    ctx.execute_vfpu_vminmax(116u, 101u, 114u, 1u, false);
    rt.unsupported(0x089D0B38u, 0x74616E69u, "unknown not lowered yet"); return;
L_089D0B6C:
    rt.unsupported(0x089D0B6Cu, 0x75746572u, "unknown not lowered yet"); return;
L_089D0BA0:
    ctx.execute_vfpu_vscl_ct<105u, 110u, 116u, 1u>();
    ctx.execute_vfpu_vcmp_ct<110u, 97u, 1u, 2u>();
    rt.unsupported(0x089D0BA8u, 0x72726520u, "unknown not lowered yet"); return;
L_089D0BE4:
    rt.unsupported(0x089D0BE4u, 0x6E69616Du, "vfpu3 not lowered yet"); return;
L_089D0C04:
    rt.unsupported(0x089D0C04u, 0x75702061u, "unknown not lowered yet"); return;
L_089D0C28:
    rt.unsupported(0x089D0C28u, 0x61766E69u, "vfpu0 not lowered yet"); return;
L_089D0C40:
    rt.unsupported(0x089D0C40u, 0x61766E69u, "vfpu0 not lowered yet"); return;
L_089D0C5C:
    ctx.execute_vfpu_vscl_ct<102u, 114u, 101u, 1u>();
    rt.unsupported(0x089D0C60u, 0x20676E69u, "unknown not lowered yet"); return;
L_089D0C94:
    rt.unsupported(0x089D0C94u, 0x203A7325u, "unknown not lowered yet"); return;
L_089D0CF8:
    rt.unsupported(0x089D0CF8u, 0x00776F70u, "special? not lowered yet"); return;
L_089D0D28:
    rt.unsupported(0x089D0D28u, 0x74727173u, "unknown not lowered yet"); return;
L_089D0D38:
    { float vfpu_s[4]{}, vfpu_t[4]{}, vfpu_d[4]{};
      ctx.read_vfpu_vector_with_source_prefix_ct<109u, 1u, 0u>(vfpu_s);
      ctx.read_vfpu_vector_with_source_prefix_ct<111u, 1u, 1u>(vfpu_t);
      for (std::uint32_t i = 0; i < 1u; ++i) vfpu_d[i] = vfpu_s[i] * vfpu_t[i];
      ctx.write_vfpu_vector_with_destination_prefix_ct<102u, 1u>(vfpu_d); }
    (void)(0u ^ 0u);
    // nop
    // nop
    rt.unsupported(0x089D0D48u, 0x00000001u, "special? not lowered yet"); return;
L_089D0D50:
    // nop
    rt.unsupported(0x089D0D54u, 0x43300000u, "unknown not lowered yet"); return;
L_089D0D60:
    // nop
    ctx.gpr[16] = (0u << 16u);
    // nop
    ctx.gpr[24] = (0u << 16u);
    goto L_089D0D70;
L_089D0D70:
    // nop
    // nop
    rt.unsupported(0x089D0D78u, 0x40000000u, "unknown not lowered yet"); return;
L_089D0D80:
    // nop
    // nop
    rt.unsupported(0x089D0D88u, 0x43CFD006u, "unknown not lowered yet"); return;
L_089D0DD8:
    rt.memory().aot_store_word_left(ctx.gpr[8] + static_cast<std::uint32_t>(16641), ctx.gpr[29]);
    ctx.gpr[17] = (29792u << 16u);
    ctx.gpr[9] = (aot_mem.aot_load8(ctx.gpr[30] + static_cast<std::uint32_t>(-9371)));
    ctx.gpr[13] = (34378u << 16u);
    rt.unsupported(0x089D0DE8u, 0x4A454EEFu, "cop2/vfpu not lowered yet"); return;
L_089D0DF8:
    { const bool branch_taken = ctx.gpr[21] != ctx.gpr[30];
    // PSP CACHE is a no-op in coherent host memory.
      if (branch_taken) {
          (void)rt.invoke_chained_direct<&recomp_unit_0013_entry, 13u, 5928u, 0x089C0448u>(ctx, &aot_mem); return;
      }
      goto L_089D0E00;
    }
L_089D0E00:
    aot_mem.aot_store32(ctx.gpr[25] + static_cast<std::uint32_t>(-8660), ctx.gpr[5]);
    ctx.gpr[17] = (22122u << 16u);
    ctx.fpr[18] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[14] + static_cast<std::uint32_t>(27633)));
    // PSP CACHE is a no-op in coherent host memory.
    rt.unsupported(0x089D0E10u, 0x72BEA4D0u, "unknown not lowered yet"); return;
L_089D0E30:
    ctx.execute_vfpu_vscl_ct<126u, 2u, 43u, 4u>();
    ctx.gpr[23] = (5447u << 16u);
    ctx.vfpu_ctrl[0u] = 0x000A03FDu;
    ctx.gpr[14] = (50953u << 16u);
    rt.unsupported(0x089D0E40u, 0xE0000000u, "unknown not lowered yet"); return;
L_089D0E50:
    ctx.execute_vfpu_vscl_ct<126u, 2u, 43u, 4u>();
    ctx.gpr[23] = (5447u << 16u);
    { float vfpu_s[4]{}, vfpu_t[4]{}, vfpu_d[4]{};
      ctx.read_vfpu_vector_with_source_prefix_ct<0u, 1u, 0u>(vfpu_s);
      ctx.read_vfpu_vector_with_source_prefix_ct<0u, 1u, 1u>(vfpu_t);
      for (std::uint32_t i = 0; i < 1u; ++i) vfpu_d[i] = vfpu_s[i] + vfpu_t[i];
      ctx.write_vfpu_vector_with_destination_prefix_ct<0u, 1u>(vfpu_d); }
    ctx.gpr[23] = (5447u << 16u);
    { float vfpu_value[4]{}; ctx.read_vfpu_vector_ct<29u, 4u>(vfpu_value);
      const std::uint32_t vfpu_address = ctx.gpr[2] + static_cast<std::uint32_t>(-8380);
      aot_mem.aot_store32(vfpu_address + 0u, std::bit_cast<std::uint32_t>(vfpu_value[0]));
      aot_mem.aot_store32(vfpu_address + 4u, std::bit_cast<std::uint32_t>(vfpu_value[1]));
      aot_mem.aot_store32(vfpu_address + 8u, std::bit_cast<std::uint32_t>(vfpu_value[2]));
      aot_mem.aot_store32(vfpu_address + 12u, std::bit_cast<std::uint32_t>(vfpu_value[3])); }
    ctx.gpr[20] = (44555u << 16u);
    // nop
    ctx.gpr[16] = ((ctx.gpr[31] >> 0u) & 0x00000001u);
    // nop
    ctx.gpr[16] = (0u << 16u);
    if (ctx.gpr[10] != ctx.gpr[21]) {
    ctx.gpr[21] = (21845u << 16u);
        (void)rt.invoke_chained_direct<&recomp_unit_0015, 15u>(ctx, &aot_mem); return;
    }
    goto L_089D0E80;
L_089D0E80:
    // nop
    (void)(0u << 16u);
    // nop
    rt.unsupported(0x089D0E8Cu, 0x40080000u, "unknown not lowered yet"); return;
L_089D0E98:
    ctx.gpr[31] = (static_cast<std::uint32_t>(static_cast<std::int32_t>(ctx.gpr[2]) >> 6u));
    ctx.gpr[9] = (ctx.gpr[14] << (ctx.gpr[3] & 31u));
    rt.unsupported(0x089D0EA0u, 0x001529FCu, "special? not lowered yet"); return;
L_089D0ED4:
    rt.unsupported(0x089D0ED4u, 0x00D1921Cu, "special? not lowered yet"); return;
L_089D0F30:
    rt.unsupported(0x089D0F30u, 0x003F669Eu, "special? not lowered yet"); return;
L_089D0FA0:
    ctx.gpr[25] = (8699u << 16u);
    rt.unsupported(0x089D0FA4u, 0x400921FBu, "unknown not lowered yet"); return;
L_089D1044:
    ctx.gpr[25] = (8699u << 16u);
    goto L_089D1048;
L_089D1048:
    { const bool branch_taken = static_cast<std::int32_t>(ctx.gpr[19]) <= 0;
    ctx.gpr[16] = (46177u << 16u);
      if (branch_taken) {
          (void)rt.invoke_chained_direct<&recomp_unit_0015, 15u>(ctx, &aot_mem); return;
      }
      goto L_089D1050;
    }
L_089D104C:
    ctx.gpr[16] = (46177u << 16u);
    goto L_089D1050;
L_089D1050:
    { const bool branch_taken = static_cast<std::int32_t>(ctx.gpr[19]) <= 0;
    ctx.gpr[16] = (46177u << 16u);
      if (branch_taken) {
          goto L_089D1054;
      }
      goto L_089D1058;
    }
L_089D1054:
    ctx.gpr[16] = (46177u << 16u);
    goto L_089D1058;
L_089D1058:
    ctx.gpr[3] = (ctx.gpr[16] < static_cast<std::uint32_t>(28787) ? 1u : 0u);
    ctx.gpr[3] = (ctx.gpr[29] ^ 6538u);
    (void)(ctx.gpr[16] < static_cast<std::uint32_t>(0) ? 1u : 0u);
    ctx.gpr[3] = (ctx.gpr[29] ^ 6538u);
    (void)(ctx.gpr[9] + static_cast<std::uint32_t>(18881));
    ctx.gpr[27] = (ctx.gpr[11] ^ 33690u);
    // nop
    // nop
    (void)(0u << 16u);
    goto L_089D107C;
L_089D107C:
    // nop
    (void)(static_cast<std::uint32_t>(static_cast<std::int32_t>(static_cast<std::int8_t>(aot_mem.aot_load8(0u + static_cast<std::uint32_t>(0))))));
    // nop
    goto L_089D1088;
L_089D1088:
    (void)(0u >> 0u);
    (void)(static_cast<std::uint32_t>(static_cast<std::int32_t>(0u) >> 0u));
    (void)(0u << (0u & 31u));
    (void)(0u >> (0u & 31u));
    goto L_089D1098;
L_089D1098:
    rt.unsupported(0x089D1098u, 0x40000000u, "unknown not lowered yet"); return;
L_089D1120:
    ctx.gpr[20] = (ctx.gpr[24] & 23559u);
    ctx.gpr[1] = (42534u << 16u);
    goto L_089D1128;
L_089D1128:
    if (ctx.gpr[10] != ctx.gpr[21]) {
    ctx.gpr[21] = (21845u << 16u);
        (void)rt.invoke_chained_direct<&recomp_unit_0015, 15u>(ctx, &aot_mem); return;
    }
    goto L_089D1130;
L_089D1130:
    { const bool branch_taken = ctx.gpr[8] == ctx.gpr[16];
    ctx.gpr[1] = (4369u << 16u);
      if (branch_taken) {
          goto L_089D0B1C;
      }
      goto L_089D1138;
    }
L_089D1138:
    { const bool branch_taken = static_cast<std::int32_t>(ctx.gpr[29]) <= 0;
    ctx.gpr[11] = (41402u << 16u);
      if (branch_taken) {
          (void)rt.invoke_chained_direct<&recomp_unit_0014, 14u>(ctx, &aot_mem); return;
      }
      goto L_089D1140;
    }
L_089D1140:
    ctx.gpr[6] = (static_cast<std::uint32_t>(static_cast<std::int32_t>(static_cast<std::int16_t>(aot_mem.aot_load16(0u + static_cast<std::uint32_t>(-10697))))));
    ctx.gpr[22] = (25844u << 16u);
    aot_mem.aot_store32(ctx.gpr[11] + static_cast<std::uint32_t>(-31600), ctx.vfpu_scalar_bits_ct<110u>());
    ctx.gpr[2] = (9955u << 16u);
    ctx.set_vfpu_scalar_bits_ct<22u>(aot_mem.aot_load32(ctx.gpr[10] + static_cast<std::uint32_t>(808)));
    ctx.gpr[13] = (27938u << 16u);
    ctx.eat_vfpu_prefixes(); // VFPU sync/no-op consumes prefixes
    ctx.gpr[23] = (56264u << 16u);
    ctx.execute_vfpu_cross_quat(1u, 101u, 114u, 1u);
    ctx.gpr[3] = (17624u << 16u);
    { const bool branch_taken = static_cast<std::int32_t>(ctx.gpr[20]) <= 0;
    ctx.gpr[16] = (9975u << 16u);
      if (branch_taken) {
          goto L_089D530C;
      }
      goto L_089D1170;
    }
L_089D1170:
    aot_mem.aot_store8(ctx.gpr[1] + static_cast<std::uint32_t>(-27994), static_cast<std::uint8_t>(ctx.gpr[23]));
    ctx.gpr[20] = (32392u << 16u);
    ctx.gpr[16] = (ctx.gpr[23] & 42985u);
    ctx.gpr[18] = (47119u << 16u);
    { const std::uint32_t vfpu_address = ctx.gpr[27] + static_cast<std::uint32_t>(21360);
      float vfpu_value[4]{
        std::bit_cast<float>(aot_mem.aot_load32(vfpu_address + 0u)),
        std::bit_cast<float>(aot_mem.aot_load32(vfpu_address + 4u)),
        std::bit_cast<float>(aot_mem.aot_load32(vfpu_address + 8u)),
        std::bit_cast<float>(aot_mem.aot_load32(vfpu_address + 12u))};
      ctx.write_vfpu_vector_ct<32u, 4u>(vfpu_value); }
    // PSP CACHE is a no-op in coherent host memory.
    rt.unsupported(0x089D1188u, 0x74BF7AD4u, "unknown not lowered yet"); return;
L_089D11E0:
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    goto L_089D11F8;
L_089D11F8:
    (void)(ctx.gpr[2] << 4u);
    (void)(static_cast<std::uint32_t>(static_cast<std::int32_t>(ctx.gpr[3]) >> 12u));
    rt.unsupported(0x089D1200u, 0x04040404u, "regimm? not lowered yet"); return;
L_089D131C:
    rt.unsupported(0x089D1320u, 0x0899C3F8u, "control flow in delay slot"); return;
L_089D13C0:
    // vflush: architectural no-op that retains VFPU prefixes
    // vflush: architectural no-op that retains VFPU prefixes
    // vflush: architectural no-op that retains VFPU prefixes
    // vflush: architectural no-op that retains VFPU prefixes
    goto L_089D13D0;
L_089D13D0:
    // nop
    // nop
    (void)(0u << 16u);
    (void)(0u << 16u);
    goto L_089D13E0;
L_089D13E0:
    // nop
    if (0u == 0u) (void)(0u);
    if (0u == 0u) (void)(0u);
    // nop
    // nop
    (void)(0u >> 0u);
    (void)(static_cast<std::uint32_t>(static_cast<std::int32_t>(0u) >> 0u));
    // vflush: architectural no-op that retains VFPU prefixes
    // nop
    (void)(0u >> 0u);
    if (0u == 0u) (void)(0u);
    // vflush: architectural no-op that retains VFPU prefixes
    (void)(0u >> 0u);
    (void)(0u >> 0u);
    if (0u == 0u) (void)(0u);
    // vflush: architectural no-op that retains VFPU prefixes
    (void)(static_cast<std::uint32_t>(static_cast<std::int32_t>(0u) >> 0u));
    (void)(0u >> 0u);
    if (0u == 0u) (void)(0u);
    // vflush: architectural no-op that retains VFPU prefixes
    (void)(0u << (0u & 31u));
    (void)(0u >> 0u);
    if (0u == 0u) (void)(0u);
    // vflush: architectural no-op that retains VFPU prefixes
    rt.unsupported(0x089D1440u, 0x00000005u, "special? not lowered yet"); return;
L_089D1454:
    rt.unsupported(0x089D1458u, 0x0899D618u, "control flow in delay slot"); return;
L_089D14C8:
    // vflush: architectural no-op that retains VFPU prefixes
    rt.unsupported(0x089D14CCu, 0x00000001u, "special? not lowered yet"); return;
L_089D14E0:
    rt.unsupported(0x089D14E4u, 0x0899E71Cu, "control flow in delay slot"); return;
L_089D14F8:
    rt.unsupported(0x089D14F8u, 0x20101010u, "unknown not lowered yet"); return;
L_089D1508:
    rt.unsupported(0x089D1508u, 0x20101010u, "unknown not lowered yet"); return;
L_089D1510:
    // nop
    (void)(0u << 0u);
    (void)(0u << 0u);
    rt.unsupported(0x089D1520u, 0x12000000u, "control flow in delay slot"); return;
L_089D1520:
    rt.unsupported(0x089D1524u, 0x13000000u, "control flow in delay slot"); return;
L_089D1524:
    rt.unsupported(0x089D1528u, 0x15000000u, "control flow in delay slot"); return;
L_089D1528:
    rt.unsupported(0x089D152Cu, 0x16000000u, "control flow in delay slot"); return;
L_089D152C:
    rt.unsupported(0x089D1530u, 0x17000000u, "control flow in delay slot"); return;
L_089D1530:
    rt.unsupported(0x089D1534u, 0x18000000u, "control flow in delay slot"); return;
L_089D1534:
    rt.unsupported(0x089D1538u, 0x19000000u, "control flow in delay slot"); return;
L_089D1538:
    rt.unsupported(0x089D153Cu, 0x1A000000u, "control flow in delay slot"); return;
L_089D153C:
    rt.unsupported(0x089D1540u, 0x1B000000u, "control flow in delay slot"); return;
L_089D1540:
    rt.unsupported(0x089D1544u, 0x1C000000u, "control flow in delay slot"); return;
L_089D1544:
    rt.unsupported(0x089D1548u, 0x1D000000u, "control flow in delay slot"); return;
L_089D1548:
    rt.unsupported(0x089D154Cu, 0x1E000000u, "control flow in delay slot"); return;
L_089D154C:
    rt.unsupported(0x089D1550u, 0x1F000000u, "control flow in delay slot"); return;
L_089D1550:
    { const bool branch_taken = static_cast<std::int32_t>(ctx.gpr[24]) > 0;
    rt.unsupported(0x089D1554u, 0x20000000u, "unknown not lowered yet"); return;
      if (branch_taken) {
          goto L_089D1554;
      }
      goto L_089D1558;
    }
L_089D1554:
    rt.unsupported(0x089D1554u, 0x20000000u, "unknown not lowered yet"); return;
L_089D1558:
    rt.unsupported(0x089D1558u, 0x21000000u, "unknown not lowered yet"); return;
L_089D15DC:
    ctx.fpr[0] = ctx.fpr[0] + ctx.fpr[0];
    goto L_089D15E0;
L_089D15E0:
    rt.unsupported(0x089D15E0u, 0x47000000u, "cop1? not lowered yet"); return;
L_089D15EC:
    rt.unsupported(0x089D15ECu, 0x4A000000u, "cop2/vfpu not lowered yet"); return;
L_089D15F0:
    rt.unsupported(0x089D15F0u, 0x4B000000u, "cop2/vfpu not lowered yet"); return;
L_089D1600:
    rt.unsupported(0x089D1604u, 0x53000000u, "control flow in delay slot"); return;
L_089D1604:
    rt.unsupported(0x089D1608u, 0x54000000u, "control flow in delay slot"); return;
L_089D1608:
    rt.unsupported(0x089D160Cu, 0x55000000u, "control flow in delay slot"); return;
L_089D160C:
    rt.unsupported(0x089D1610u, 0x56000000u, "control flow in delay slot"); return;
L_089D1610:
    rt.unsupported(0x089D1614u, 0x57000000u, "control flow in delay slot"); return;
L_089D1614:
    rt.unsupported(0x089D1618u, 0x58000000u, "control flow in delay slot"); return;
L_089D1618:
    rt.unsupported(0x089D161Cu, 0x5B000000u, "control flow in delay slot"); return;
L_089D161C:
    rt.unsupported(0x089D1620u, 0x5C000000u, "control flow in delay slot"); return;
L_089D1620:
    rt.unsupported(0x089D1624u, 0x5D000000u, "control flow in delay slot"); return;
L_089D1624:
    rt.unsupported(0x089D1628u, 0x5E000000u, "control flow in delay slot"); return;
L_089D1628:
    rt.unsupported(0x089D162Cu, 0x5F000000u, "control flow in delay slot"); return;
L_089D162C:
    if (static_cast<std::int32_t>(ctx.gpr[24]) > 0) {
    { float vfpu_s[4]{}, vfpu_t[4]{}, vfpu_d[4]{};
      ctx.read_vfpu_vector_with_source_prefix_ct<0u, 1u, 0u>(vfpu_s);
      ctx.read_vfpu_vector_with_source_prefix_ct<0u, 1u, 1u>(vfpu_t);
      for (std::uint32_t i = 0; i < 1u; ++i) vfpu_d[i] = vfpu_s[i] + vfpu_t[i];
      ctx.write_vfpu_vector_with_destination_prefix_ct<0u, 1u>(vfpu_d); }
        goto L_089D1630;
    }
    goto L_089D1634;
L_089D1630:
    { float vfpu_s[4]{}, vfpu_t[4]{}, vfpu_d[4]{};
      ctx.read_vfpu_vector_with_source_prefix_ct<0u, 1u, 0u>(vfpu_s);
      ctx.read_vfpu_vector_with_source_prefix_ct<0u, 1u, 1u>(vfpu_t);
      for (std::uint32_t i = 0; i < 1u; ++i) vfpu_d[i] = vfpu_s[i] + vfpu_t[i];
      ctx.write_vfpu_vector_with_destination_prefix_ct<0u, 1u>(vfpu_d); }
    goto L_089D1634;
L_089D1634:
    rt.unsupported(0x089D1634u, 0x61000000u, "vfpu0 not lowered yet"); return;
L_089D1830:
    rt.unsupported(0x089D1830u, 0xE3000000u, "unknown not lowered yet"); return;
L_089D1860:
    (void)(ctx.hi);
    // nop
    { const bool signed_ok = ctx.execute_signed_add(0u, 0u, 0u);
      if (!signed_ok) { rt.arithmetic_overflow(0x089D1868u, 0x00000020u); return; } }
    // vflush: architectural no-op that retains VFPU prefixes
    ctx.pc = 0x06BDB4C0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089D18CC:
    rt.unsupported(0x089D18D0u, 0x0899F92Cu, "control flow in delay slot"); return;
L_089D18E0:
    rt.unsupported(0x089D18E4u, 0x089A01D0u, "control flow in delay slot"); return;
L_089D18F4:
    rt.unsupported(0x089D18F8u, 0x089A1340u, "control flow in delay slot"); return;
L_089D18F8: // GE cmd handler slot 1 (no-op)
    jump_target = ctx.gpr[31]; ctx.pc = jump_target; local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; } return;
L_089D18FC: // GE cmd handler slot 2 (no-op)
    jump_target = ctx.gpr[31]; ctx.pc = jump_target; local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; } return;
L_089D1900: // GE cmd handler slot 3 (no-op)
    jump_target = ctx.gpr[31]; ctx.pc = jump_target; local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; } return;
L_089D1904: // GE cmd handler slot 4 (no-op)
    jump_target = ctx.gpr[31]; ctx.pc = jump_target; local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; } return;
L_089D1908: // GE cmd handler slot 5 (no-op)
    jump_target = ctx.gpr[31]; ctx.pc = jump_target; local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; } return;
L_089D190C: // GE cmd handler slot 6 (no-op)
    jump_target = ctx.gpr[31]; ctx.pc = jump_target; local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; } return;
L_089D1910: // GE cmd handler slot 7 (no-op)
    jump_target = ctx.gpr[31]; ctx.pc = jump_target; local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; } return;
L_089D1914: // GE cmd handler slot 8 (no-op)
    jump_target = ctx.gpr[31]; ctx.pc = jump_target; local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; } return;
L_089D1918: // GE cmd handler slot 9 (no-op)
    jump_target = ctx.gpr[31]; ctx.pc = jump_target; local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; } return;
L_089D191C: // GE cmd handler slot 10 (no-op)
    jump_target = ctx.gpr[31]; ctx.pc = jump_target; local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; } return;
L_089D1920: // GE cmd handler slot 11 (no-op)
    jump_target = ctx.gpr[31]; ctx.pc = jump_target; local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; } return;
L_089D1924: // GE cmd handler slot 12 (no-op)
    jump_target = ctx.gpr[31]; ctx.pc = jump_target; local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; } return;
L_089D1928: // GE cmd handler slot 13 (no-op)
    jump_target = ctx.gpr[31]; ctx.pc = jump_target; local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; } return;
L_089D192C: // GE cmd handler slot 14 (no-op)
    jump_target = ctx.gpr[31]; ctx.pc = jump_target; local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; } return;
L_089D1930: // GE cmd handler slot 15 (no-op)
    jump_target = ctx.gpr[31]; ctx.pc = jump_target; local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; } return;
L_089D1934: // GE cmd handler slot 16 (no-op)
    jump_target = ctx.gpr[31]; ctx.pc = jump_target; local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; } return;
L_089D1938: // GE cmd handler slot 17 (no-op)
    jump_target = ctx.gpr[31]; ctx.pc = jump_target; local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; } return;
L_089D193C: // GE cmd handler slot 18 (no-op)
    jump_target = ctx.gpr[31]; ctx.pc = jump_target; local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; } return;
L_089D1940: // GE cmd handler slot 19 (no-op)
    jump_target = ctx.gpr[31]; ctx.pc = jump_target; local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; } return;
L_089D1944: // GE cmd handler slot 20 (no-op)
    jump_target = ctx.gpr[31]; ctx.pc = jump_target; local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; } return;
L_089D1948: // GE cmd handler slot 21 (no-op)
    jump_target = ctx.gpr[31]; ctx.pc = jump_target; local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; } return;
L_089D194C:
    rt.unsupported(0x089D1950u, 0x089A1F2Cu, "control flow in delay slot"); return;
L_089D19CC:
    ctx.eat_vfpu_prefixes(); // VFPU sync/no-op consumes prefixes
    ctx.eat_vfpu_prefixes(); // VFPU sync/no-op consumes prefixes
    ctx.eat_vfpu_prefixes(); // VFPU sync/no-op consumes prefixes
    { float vfpu_value[4]{}; ctx.read_vfpu_vector_ct<26u, 4u>(vfpu_value);
      const std::uint32_t vfpu_address = ctx.gpr[23] + static_cast<std::uint32_t>(-1028);
      aot_mem.aot_store32(vfpu_address + 0u, std::bit_cast<std::uint32_t>(vfpu_value[0]));
      aot_mem.aot_store32(vfpu_address + 4u, std::bit_cast<std::uint32_t>(vfpu_value[1]));
      aot_mem.aot_store32(vfpu_address + 8u, std::bit_cast<std::uint32_t>(vfpu_value[2]));
      aot_mem.aot_store32(vfpu_address + 12u, std::bit_cast<std::uint32_t>(vfpu_value[3])); }
    rt.unsupported(0x089D19DCu, 0xF7F8F9F9u, "vfpu not lowered yet"); return;
L_089D1C80:
    ctx.gpr[12] = (33630u << 16u);
    ctx.gpr[10] = (35796u << 16u);
    ctx.gpr[7] = (15733u << 16u);
    ctx.gpr[21] = (1267u << 16u);
    ctx.gpr[2] = (26125u << 16u);
    ctx.gpr[6] = (56939u << 16u);
    // PSP CACHE is a no-op in coherent host memory.
    // PSP CACHE is a no-op in coherent host memory.
    // PSP CACHE is a no-op in coherent host memory.
    // PSP CACHE is a no-op in coherent host memory.
    goto L_089D1CA8;
L_089D1CA8:
    ctx.gpr[12] = (ctx.gpr[2] & 62672u);
    rt.unsupported(0x089D1CACu, 0xD0B4D040u, "vfpu4 not lowered yet"); return;
L_089D1CF0:
    rt.unsupported(0x089D1CF0u, 0xE0FFD8FFu, "unknown not lowered yet"); return;
L_089D1D00:
    ctx.gpr[16] = (0u << 0u);
    (void)(static_cast<std::uint32_t>(static_cast<std::int32_t>(static_cast<std::int16_t>(aot_mem.aot_load16(0u + static_cast<std::uint32_t>(-9217))))));
    goto L_089D1D08;
L_089D1D08:
    aot_mem.aot_store8(ctx.gpr[16] + static_cast<std::uint32_t>(-15105), static_cast<std::uint8_t>(ctx.gpr[1]));
    { const bool branch_taken = static_cast<std::int32_t>(ctx.gpr[8]) >= 0;
    rt.unsupported(0x089D1D10u, 0x01010101u, "special? not lowered yet"); return;
      if (branch_taken) {
          goto L_089D1D10;
      }
      goto L_089D1D14;
    }
L_089D1D10:
    rt.unsupported(0x089D1D10u, 0x01010101u, "special? not lowered yet"); return;
L_089D1D14:
    rt.unsupported(0x089D1D14u, 0x00000101u, "special? not lowered yet"); return;
L_089D1E00:
    rt.unsupported(0x089D1E00u, 0x05070403u, "regimm? not lowered yet"); return;
L_089D1E14:
    ctx.gpr[31] = (0x089D1E1Cu);
    { const bool branch_taken = static_cast<std::int32_t>(ctx.gpr[26]) >= 0;
    rt.unsupported(0x089D1E18u, 0x22137161u, "unknown not lowered yet"); return;
      if (branch_taken) {
          (void)rt.invoke_chained_direct<&recomp_unit_0014, 14u>(ctx, &aot_mem); return;
      }
      goto L_089D1E1C;
    }
L_089D1E1C:
    { const bool branch_taken = 0u != ctx.gpr[8];
    rt.unsupported(0x089D1E20u, 0xB1A19142u, "unknown not lowered yet"); return;
      if (branch_taken) {
          (void)rt.invoke_chained_direct<&recomp_unit_0013_entry, 13u, 3037u, 0x089B22E8u>(ctx, &aot_mem); return;
      }
      goto L_089D1E24;
    }
L_089D1E24:
    ctx.gpr[3] = (ctx.gpr[25] & 2497u);
    rt.unsupported(0x089D1E28u, 0x6215F052u, "vfpu0 not lowered yet"); return;
L_089D1E34:
    { const bool branch_taken = static_cast<std::int32_t>(ctx.gpr[8]) <= 0;
    ctx.gpr[7] = (static_cast<std::int32_t>(ctx.gpr[1]) < 9754 ? 1u : 0u);
      if (branch_taken) {
          goto L_089D7DFC;
      }
      goto L_089D1E3C;
    }
L_089D1E3C:
    ctx.gpr[21] = (ctx.gpr[17] | 10793u);
    ctx.gpr[25] = (ctx.gpr[17] ^ 14391u);
    rt.unsupported(0x089D1E44u, 0x46454443u, "cop1? not lowered yet"); return;
L_089D1E54:
    ctx.execute_vfpu_vhdp(99u, 100u, 101u, 1u);
    rt.unsupported(0x089D1E58u, 0x6A696867u, "unknown not lowered yet"); return;
L_089D1EAC:
    rt.unsupported(0x089D1EB0u, 0x00000008u, "control flow in delay slot"); return;
L_089D1EB4:
    (void)(static_cast<std::uint32_t>(static_cast<std::int32_t>(ctx.gpr[2]) >> 4u));
    ctx.gpr[2] = (ctx.gpr[1] >> 4u);
    { const std::uint32_t vfpu_address = ctx.gpr[23] + static_cast<std::uint32_t>(272);
      float vfpu_value[4]{
        std::bit_cast<float>(aot_mem.aot_load32(vfpu_address + 0u)),
        std::bit_cast<float>(aot_mem.aot_load32(vfpu_address + 4u)),
        std::bit_cast<float>(aot_mem.aot_load32(vfpu_address + 8u)),
        std::bit_cast<float>(aot_mem.aot_load32(vfpu_address + 12u))};
      ctx.write_vfpu_vector_ct<63u, 4u>(vfpu_value); }
    ctx.gpr[1] = (ctx.gpr[3] << 16u);
    (void)(ctx.gpr[17] << 8u);
    ctx.hi = ctx.gpr[1];
    goto L_089D1ECC;
L_089D1ECC:
    rt.unsupported(0x089D1ED0u, 0x0E100A0Cu, "control flow in delay slot"); return;
L_089D1ED4:
    { const bool branch_taken = ctx.gpr[8] == ctx.gpr[18];
    ctx.gpr[24] = (static_cast<std::int32_t>(0u) < 4880 ? 1u : 0u);
      if (branch_taken) {
          goto L_089D570C;
      }
      goto L_089D1EDC;
    }
L_089D1EDC:
    { const bool branch_taken = ctx.gpr[16] != ctx.gpr[22];
    ctx.gpr[3] = (ctx.gpr[9] + static_cast<std::uint32_t>(12568));
      if (branch_taken) {
          goto L_089D7F48;
      }
      goto L_089D1EE4;
    }
L_089D1EE4:
    ctx.gpr[26] = (ctx.gpr[25] & 10269u);
    ctx.gpr[25] = (ctx.gpr[25] & 15421u);
    rt.unsupported(0x089D1EECu, 0x48403738u, "cop2/vfpu not lowered yet"); return;
L_089D1F00:
    rt.unsupported(0x089D1F00u, 0x714D3E67u, "unknown not lowered yet"); return;
L_089D1F0C:
    rt.unsupported(0x089D1F10u, 0x1A2F1815u, "control flow in delay slot"); return;
L_089D1F14:
    rt.unsupported(0x089D1F14u, 0x42632F1Au, "unknown not lowered yet"); return;
L_089D1F74:
    ctx.gpr[31] = (0x089D1F7Cu);
    ctx.execute_vfpu_cross_quat(14u, 16u, 114u, 1u);
    ctx.pc = 0x08383808u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x089D1F7Cu) goto L_089D1F7C;
    return;
L_089D1F7C:
    rt.unsupported(0x089D1F7Cu, 0x02F2F2F2u, "special? not lowered yet"); return;
L_089D1F88:
    ctx.execute_vfpu_cross_quat(114u, 114u, 114u, 4u);
    rt.unsupported(0x089D1F90u, 0x0E0E0E0Eu, "control flow in delay slot"); return;
L_089D1F94:
    ctx.execute_vfpu_cross_quat(14u, 2u, 114u, 1u);
    rt.unsupported(0x089D1F9Cu, 0x0E0E0E0Eu, "control flow in delay slot"); return;
L_089D1FA0:
    ctx.execute_vfpu_cross_quat(2u, 114u, 114u, 3u);
    ctx.gpr[1] = (ctx.hi);
    rt.unsupported(0x089D1FA8u, 0x000010F2u, "special? not lowered yet"); return;
L_089D1FB4:
    rt.unsupported(0x089D1FB8u, 0x089A8CBCu, "control flow in delay slot"); return;
L_089D2084:
    rt.unsupported(0x089D2088u, 0x089A90F4u, "control flow in delay slot"); return;
L_089D2130:
    rt.unsupported(0x089D2134u, 0x089A90F4u, "control flow in delay slot"); return;
L_089D2144:
    // nop
    // PSP CACHE is a no-op in coherent host memory.
    (void)(0u << 16u);
    (void)(0u << 16u);
    ctx.set_vfpu_scalar_bits_ct<20u>(aot_mem.aot_load32(ctx.gpr[11] + static_cast<std::uint32_t>(9216)));
    rt.unsupported(0x089D2158u, 0x49742400u, "cop2/vfpu not lowered yet"); return;
L_089D216C:
    // nop
    (void)(0u << 0u);
    rt.unsupported(0x089D2174u, 0x00200001u, "special? not lowered yet"); return;
L_089D21B8:
    // nop
    goto L_089D21BC;
L_089D21BC:
    rt.unsupported(0x089D21BCu, 0x00000201u, "special? not lowered yet"); return;
L_089D21C0:
    if (0u == 0u) ctx.gpr[1] = (ctx.gpr[8]);
    (void)(ctx.gpr[2] << 4u);
    (void)(0u << (0u & 31u));
    (void)(0u << 16u);
    rt.unsupported(0x089D21D0u, 0x41800000u, "unknown not lowered yet"); return;
L_089D21E0:
    rt.unsupported(0x089D21E0u, 0xC1200000u, "unknown not lowered yet"); return;
L_089D21EC:
    rt.unsupported(0x089D21ECu, 0x43535655u, "unknown not lowered yet"); return;
L_089D21F8:
    rt.unsupported(0x089D21F8u, 0x48504C41u, "cop2/vfpu not lowered yet"); return;
L_089D2204:
    rt.unsupported(0x089D2204u, 0x44414853u, "unsupported CFC1 control register"); return;
    rt.unsupported(0x089D2208u, 0x464F574Fu, "cop1? not lowered yet"); return;
L_089D2210:
    rt.unsupported(0x089D2210u, 0x41505655u, "unknown not lowered yet"); return;
L_089D221C:
    rt.unsupported(0x089D221Cu, 0x41505655u, "unknown not lowered yet"); return;
L_089D2228:
    rt.unsupported(0x089D222Cu, 0x089B6970u, "control flow in delay slot"); return;
L_089D2250:
    rt.unsupported(0x089D2254u, 0x089B7000u, "control flow in delay slot"); return;
L_089D2264:
    rt.unsupported(0x089D2268u, 0x089B7570u, "control flow in delay slot"); return;
L_089D22E4:
    (void)(static_cast<std::int32_t>(ctx.gpr[9]) > static_cast<std::int32_t>(ctx.gpr[16]) ? ctx.gpr[9] : ctx.gpr[16]);
    rt.unsupported(0x089D22E8u, 0x01380038u, "special? not lowered yet"); return;
L_089D22F4:
    (void)(0u << 16u);
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    (void)(ctx.hi);
    rt.unsupported(0x089D2318u, 0x00006001u, "special? not lowered yet"); return;
L_089D2330:
    { float vfpu_s[4]{}, vfpu_t[4]{}, vfpu_d[4]{};
      ctx.read_vfpu_vector_with_source_prefix_ct<8u, 1u, 0u>(vfpu_s);
      ctx.read_vfpu_vector_with_source_prefix_ct<112u, 1u, 1u>(vfpu_t);
      for (std::uint32_t i = 0; i < 1u; ++i) vfpu_d[i] = vfpu_s[i] + vfpu_t[i];
      ctx.write_vfpu_vector_with_destination_prefix_ct<28u, 1u>(vfpu_d); }
    ctx.gpr[3] = (ctx.gpr[16] << 17u);
    goto L_089D2338;
L_089D2338:
    (void)(0u << 16u);
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    (void)(0u << 16u);
    goto L_089D235C;
L_089D235C:
    rt.unsupported(0x089D2360u, 0x089B9A44u, "control flow in delay slot"); return;
L_089D2640:
    // nop
    // nop
    (void)(0u << 16u);
    (void)(0u << 16u);
    goto L_089D2650;
L_089D2650:
    (void)(0u << 16u);
    // nop
    // nop
    // nop
    goto L_089D2660;
L_089D2660:
    // nop
    (void)(0u << 16u);
    // nop
    // nop
    // nop
    // nop
    (void)(0u << 16u);
    // nop
    // nop
    // nop
    // nop
    (void)(0u << 16u);
    goto L_089D2690;
L_089D2690:
    (void)(0u << 16u);
    (void)(0u << 16u);
    (void)(0u << 16u);
    ctx.set_vfpu_scalar_bits_ct<20u>(aot_mem.aot_load32(ctx.gpr[11] + static_cast<std::uint32_t>(9216)));
    rt.unsupported(0x089D26A0u, 0x49742400u, "cop2/vfpu not lowered yet"); return;
L_089D26A8:
    rt.unsupported(0x089D26ACu, 0x089BD3DCu, "control flow in delay slot"); return;
L_089D26EC:
    rt.unsupported(0x089D26F0u, 0x089BD484u, "control flow in delay slot"); return;
L_089D26F4:
    rt.unsupported(0x089D26F8u, 0x089BD3D4u, "control flow in delay slot"); return;
L_089D2748:
    ctx.gpr[1] = (ctx.gpr[10] << 8u);
    ctx.eat_vfpu_prefixes(); // VFPU sync/no-op consumes prefixes
    ctx.eat_vfpu_prefixes(); // VFPU sync/no-op consumes prefixes
    ctx.eat_vfpu_prefixes(); // VFPU sync/no-op consumes prefixes
    ctx.eat_vfpu_prefixes(); // VFPU sync/no-op consumes prefixes
    ctx.eat_vfpu_prefixes(); // VFPU sync/no-op consumes prefixes
    ctx.eat_vfpu_prefixes(); // VFPU sync/no-op consumes prefixes
    // nop
    // nop
    // nop
    goto L_089D2770;
L_089D2770:
    // nop
    // nop
    (void)(0u << 16u);
    (void)(0u << 16u);
    rt.unsupported(0x089D2780u, 0x41800000u, "unknown not lowered yet"); return;
L_089D2784:
    rt.unsupported(0x089D2784u, 0x20101010u, "unknown not lowered yet"); return;
L_089D2794:
    // vflush: architectural no-op that retains VFPU prefixes
    rt.unsupported(0x089D2798u, 0x00000001u, "special? not lowered yet"); return;
L_089D27AC:
    rt.unsupported(0x089D27B0u, 0x089BFAECu, "control flow in delay slot"); return;
L_089D27C4:
    rt.unsupported(0x089D27C4u, 0x62733C00u, "vfpu0 not lowered yet"); return;
L_089D27D4:
    rt.unsupported(0x089D27D4u, 0xC1E00000u, "unknown not lowered yet"); return;
L_089D2800:
    // nop
    // nop
    goto L_089D2808;
L_089D2808:
    // nop
    goto L_089D280C;
L_089D280C:
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    goto L_089D291C;
L_089D291C:
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    goto L_089D2A18;
L_089D2A18:
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    goto L_089D35FC;
L_089D35FC:
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    goto L_089D3630;
L_089D3630:
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    goto L_089D3650;
L_089D3650:
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    goto L_089D4320;
L_089D4320:
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    goto L_089D4750;
L_089D4750:
    // nop
    goto L_089D4754;
L_089D4754:
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    goto L_089D4770;
L_089D4770:
    // nop
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x0271B640u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089D47B0:
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    goto L_089D48C0;
L_089D48C0:
    // nop
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x0271BB20u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089D4900:
    // nop
    rt.unsupported(0x089D4908u, 0x0881B424u, "control flow in delay slot"); return;
L_089D4948:
    // nop
    rt.unsupported(0x089D4950u, 0x0883106Cu, "control flow in delay slot"); return;
L_089D4978:
    rt.unsupported(0x089D4978u, 0x00000001u, "special? not lowered yet"); return;
L_089D4D84:
    (void)(static_cast<std::uint32_t>(static_cast<std::int32_t>(static_cast<std::int8_t>(aot_mem.aot_load8(ctx.gpr[2] + static_cast<std::uint32_t>(0))))));
    (void)(static_cast<std::uint32_t>(static_cast<std::int32_t>(static_cast<std::int8_t>(aot_mem.aot_load8(0u + static_cast<std::uint32_t>(64))))));
    ctx.gpr[16] = (0u << 1u);
    ctx.gpr[16] = (0u << 0u);
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    ctx.gpr[24] = (20972u << 16u);
    ctx.gpr[12] = (52429u << 16u);
    (void)(0u << 16u);
    ctx.gpr[25] = (39322u << 16u);
    rt.unsupported(0x089D4DC0u, 0x41800000u, "unknown not lowered yet"); return;
L_089D4DD0:
    // nop
    // nop
    (void)(0u << 16u);
    (void)(0u << 16u);
    (void)(0u << 16u);
    // nop
    // nop
    (void)(0u << 16u);
    (void)(0u << 16u);
    (void)(0u << 16u);
    // nop
    // nop
    // nop
    (void)(0u << 16u);
    (void)(0u << 16u);
    // nop
    // nop
    ctx.pc = 0x02723800u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089D4E38:
    ctx.gpr[31] = (ctx.gpr[1] + static_cast<std::uint32_t>(27272));
    goto L_089D4E3C;
L_089D4E3C:
    ctx.gpr[3] = (static_cast<std::uint32_t>(static_cast<std::int32_t>(static_cast<std::int16_t>(aot_mem.aot_load16(ctx.gpr[13] + static_cast<std::uint32_t>(2259))))));
    { const bool branch_taken = ctx.gpr[24] == ctx.gpr[25];
    ctx.gpr[14] = (ctx.gpr[16] << (ctx.gpr[27] & 31u));
      if (branch_taken) {
          (void)rt.invoke_chained_direct<&recomp_unit_0013_entry, 13u, 4097u, 0x089B76FCu>(ctx, &aot_mem); return;
      }
      goto L_089D4E48;
    }
L_089D4E48:
    aot_mem.aot_store16(0u + static_cast<std::uint32_t>(14370), static_cast<std::uint16_t>(ctx.gpr[9]));
    ctx.gpr[31] = (static_cast<std::int32_t>(ctx.gpr[12]) < 12752 ? 1u : 0u);
    rt.unsupported(0x089D4E54u, 0xEC4E6C89u, "unknown not lowered yet"); return;
    ctx.pc = 0x00BBEA60u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089D4E80:
    rt.unsupported(0x089D4E80u, 0xD1310BA6u, "vfpu4 not lowered yet"); return;
L_089D4E84:
    ctx.gpr[31] = (rt.memory().aot_load_word_right(ctx.gpr[6] + static_cast<std::uint32_t>(-19028), ctx.gpr[31]));
    ctx.gpr[29] = (ctx.gpr[31] < static_cast<std::uint32_t>(29403) ? 1u : 0u);
    { float vfpu_s[4]{}, vfpu_d[4]{};
      ctx.read_vfpu_vector_with_source_prefix_ct<95u, 4u, 0u>(vfpu_s);
      for (std::uint32_t i = 0; i < 4u; ++i) vfpu_d[i] = -std::sin(vfpu_s[i] * 1.57079632679489661923f);
      ctx.write_vfpu_vector_with_destination_prefix_ct<55u, 4u>(vfpu_d); }
    rt.memory().aot_store_word_right(ctx.gpr[7] + static_cast<std::uint32_t>(-20499), ctx.gpr[1]);
    rt.unsupported(0x089D4E94u, 0x6A267E96u, "unknown not lowered yet"); return;
L_089D530C:
    rt.memory().aot_store_word_left(ctx.gpr[18] + static_cast<std::uint32_t>(1847), ctx.gpr[16]);
    ctx.gpr[7] = (33820u << 16u);
    rt.unsupported(0x089D5314u, 0x7FDEAE5Cu, "special3? not lowered yet"); return;
L_089D5324:
    { float vfpu_s[16]{}, vfpu_t[16]{}, vfpu_d[16]{};
      ctx.read_vfpu_matrix(vfpu_s, 12u, 1u);
      ctx.read_vfpu_matrix(vfpu_t, 80u, 1u);
      for (std::uint32_t a = 0; a < 1u; ++a) {
        for (std::uint32_t b = 0; b < 1u; ++b) {
          float sum = 0.0f;
          for (std::uint32_t c = 0; c < 1u; ++c) sum += vfpu_s[b * 4u + c] * vfpu_t[a * 4u + c];
          vfpu_d[a * 4u + b] = sum;
        }
      }
      ctx.write_vfpu_matrix(vfpu_d, 13u, 1u);
      ctx.eat_vfpu_prefixes(); }
    { float vfpu_s[16]{}, vfpu_t[16]{}, vfpu_d[16]{};
      ctx.read_vfpu_matrix(vfpu_s, 31u, 1u);
      ctx.read_vfpu_matrix(vfpu_t, 28u, 1u);
      for (std::uint32_t a = 0; a < 1u; ++a) {
        for (std::uint32_t b = 0; b < 1u; ++b) {
          float sum = 0.0f;
          for (std::uint32_t c = 0; c < 1u; ++c) sum += vfpu_s[b * 4u + c] * vfpu_t[a * 4u + c];
          vfpu_d[a * 4u + b] = sum;
        }
      }
      ctx.write_vfpu_matrix(vfpu_d, 4u, 1u);
      ctx.eat_vfpu_prefixes(); }
    rt.unsupported(0x089D532Cu, 0x0200B3FFu, "special? not lowered yet"); return;
L_089D536C:
    aot_mem.aot_store16(ctx.gpr[3] + static_cast<std::uint32_t>(7745), static_cast<std::uint16_t>(ctx.gpr[21]));
    rt.unsupported(0x089D5370u, 0xE238CD99u, "unknown not lowered yet"); return;
L_089D5384:
    rt.unsupported(0x089D5384u, 0x4F6DB908u, "unknown not lowered yet"); return;
L_089D53A0:
    ctx.vfpu_ctrl[2u] = 0x0000071Fu;
    { const std::uint32_t vfpu_address = ctx.gpr[12] + static_cast<std::uint32_t>(2064);
      float vfpu_value[4]{
        std::bit_cast<float>(aot_mem.aot_load32(vfpu_address + 0u)),
        std::bit_cast<float>(aot_mem.aot_load32(vfpu_address + 4u)),
        std::bit_cast<float>(aot_mem.aot_load32(vfpu_address + 8u)),
        std::bit_cast<float>(aot_mem.aot_load32(vfpu_address + 12u))};
      ctx.write_vfpu_vector_ct<19u, 4u>(vfpu_value); }
    rt.unsupported(0x089D53A8u, 0xB38BAE12u, "unknown not lowered yet"); return;
L_089D53B8:
    if (0u == ctx.gpr[26]) {
    rt.unsupported(0x089D53BCu, 0x9F84CD87u, "unknown not lowered yet"); return;
        goto L_089CCB54;
    }
    goto L_089D53C0;
L_089D53C0:
    rt.unsupported(0x089D53C0u, 0x7A584718u, "unknown not lowered yet"); return;
L_089D53F8:
    rt.unsupported(0x089D53FCu, 0x133AE4DDu, "control flow in delay slot"); return;
L_089D5400:
    rt.unsupported(0x089D5400u, 0x71DFF89Eu, "unknown not lowered yet"); return;
L_089D5404:
    { const bool branch_taken = ctx.gpr[1] == ctx.gpr[17];
    ctx.gpr[12] = (static_cast<std::uint32_t>(static_cast<std::int32_t>(static_cast<std::int8_t>(aot_mem.aot_load8(ctx.gpr[13] + static_cast<std::uint32_t>(30678))))));
      if (branch_taken) {
          (void)rt.invoke_chained_direct<&recomp_unit_0015, 15u>(ctx, &aot_mem); return;
      }
      goto L_089D540C;
    }
L_089D540C:
    if (static_cast<std::int32_t>(ctx.gpr[24]) > 0) {
    rt.unsupported(0x089D5410u, 0x043556F1u, "regimm? not lowered yet"); return;
        goto L_089DBA7C;
    }
    goto L_089D5414;
L_089D5414:
    rt.unsupported(0x089D5414u, 0xD7A3C76Bu, "vfpu not lowered yet"); return;
L_089D5424:
    ctx.gpr[17] = (aot_mem.aot_load16(ctx.gpr[31] + static_cast<std::uint32_t>(-1030)));
    rt.unsupported(0x089D5428u, 0x9EBABF2Cu, "unknown not lowered yet"); return;
L_089D5434:
    aot_mem.aot_store32(ctx.gpr[23] + static_cast<std::uint32_t>(28592), ctx.vfpu_scalar_bits_ct<41u>());
    ctx.gpr[14] = (static_cast<std::uint32_t>(static_cast<std::int32_t>(static_cast<std::int16_t>(aot_mem.aot_load16(ctx.gpr[16] + static_cast<std::uint32_t>(24074))))));
    if (static_cast<std::int32_t>(ctx.gpr[17]) <= 0) {
    rt.unsupported(0x089D5440u, 0x771FE71Cu, "unknown not lowered yet"); return;
        (void)rt.invoke_chained_direct<&recomp_unit_0014, 14u>(ctx, &aot_mem); return;
    }
    goto L_089D5444;
L_089D5444:
    rt.unsupported(0x089D5444u, 0x4E3D06FAu, "unknown not lowered yet"); return;
L_089D545C:
    rt.unsupported(0x089D545Cu, 0x9C10B36Au, "unknown not lowered yet"); return;
L_089D5474:
    ctx.gpr[29] = (ctx.gpr[16] | 11069u);
    rt.unsupported(0x089D547Cu, 0x19C27960u, "control flow in delay slot"); return;
L_089D5480:
    if (ctx.gpr[17] == ctx.gpr[3]) {
    rt.unsupported(0x089D5484u, 0xF71312B6u, "vfpu not lowered yet"); return;
        (void)rt.invoke_chained_direct<&recomp_unit_0013_entry, 13u, 5700u, 0x089BF0A4u>(ctx, &aot_mem); return;
    }
    goto L_089D5488;
L_089D5488:
    aot_mem.aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(-404), ctx.vfpu_scalar_bits_ct<77u>());
    aot_mem.aot_store32(ctx.gpr[22] + static_cast<std::uint32_t>(8036), ctx.vfpu_scalar_bits_ct<67u>());
    rt.unsupported(0x089D5490u, 0xE3BC4595u, "unknown not lowered yet"); return;
L_089D54C4:
    ctx.gpr[7] = (static_cast<std::int32_t>(ctx.gpr[8]) < 24944 ? 1u : 0u);
    rt.unsupported(0x089D54C8u, 0xECDD4775u, "unknown not lowered yet"); return;
L_089D54D8:
    rt.unsupported(0x089D54D8u, 0x0334FE1Eu, "special? not lowered yet"); return;
L_089D550C:
    ctx.execute_vfpu_vscl_ct<80u, 59u, 90u, 3u>();
    rt.unsupported(0x089D5510u, 0x40685A32u, "unknown not lowered yet"); return;
L_089D5540:
    ctx.gpr[31] = (0x089D5548u);
    ctx.fpr[6] = std::bit_cast<float>(aot_mem.aot_load32(ctx.gpr[31] + static_cast<std::uint32_t>(8150)));
    if (rt.invoke_chained_direct<&recomp_unit_0042, 42u>(ctx, &aot_mem) && ctx.pc == 0x089D5548u) goto L_089D5548;
    return;
L_089D5548:
    ctx.gpr[30] = (aot_mem.aot_load16(ctx.gpr[22] + static_cast<std::uint32_t>(-8287)));
    rt.unsupported(0x089D554Cu, 0x7858BA99u, "unknown not lowered yet"); return;
L_089D5558:
    ctx.gpr[3] = (rt.memory().aot_load_word_right(ctx.gpr[28] + static_cast<std::uint32_t>(-15361), ctx.gpr[3]));
    { const bool branch_taken = static_cast<std::int32_t>(ctx.gpr[22]) <= 0;
    rt.unsupported(0x089D5560u, 0xCDB30AEBu, "unknown not lowered yet"); return;
      if (branch_taken) {
          (void)rt.invoke_chained_direct<&recomp_unit_0015, 15u>(ctx, &aot_mem); return;
      }
      goto L_089D5564;
    }
L_089D5564:
    if (ctx.gpr[25] == ctx.gpr[14]) {
    ctx.gpr[25] = (aot_mem.aot_load32(ctx.gpr[30] + static_cast<std::uint32_t>(18660)));
        (void)rt.invoke_chained_direct<&recomp_unit_0014, 14u>(ctx, &aot_mem); return;
    }
    goto L_089D556C;
L_089D556C:
    ctx.execute_vfpu_vminmax(40u, 49u, 60u, 1u, true);
    if (static_cast<std::int32_t>(ctx.gpr[7]) <= 0) {
    ctx.gpr[6] = (ctx.gpr[6] | 65514u);
        goto L_089D2130;
    }
    goto L_089D5578;
L_089D5578:
    ctx.eat_vfpu_prefixes(); // VFPU sync/no-op consumes prefixes
    rt.unsupported(0x089D557Cu, 0xEE7C3C73u, "unknown not lowered yet"); return;
L_089D5588:
    rt.unsupported(0x089D5588u, 0x42105D14u, "unknown not lowered yet"); return;
L_089D55CC:
    rt.unsupported(0x089D55CCu, 0xC1C7B6A3u, "unknown not lowered yet"); return;
L_089D55E4:
    aot_mem.aot_store32(ctx.gpr[8] + static_cast<std::uint32_t>(18589), ctx.gpr[25]);
    { const bool branch_taken = ctx.gpr[3] != ctx.gpr[2];
    rt.unsupported(0x089D55ECu, 0x23820E00u, "unknown not lowered yet"); return;
      if (branch_taken) {
          (void)rt.invoke_chained_direct<&recomp_unit_0013_entry, 13u, 6243u, 0x089C1BBCu>(ctx, &aot_mem); return;
      }
      goto L_089D55F0;
    }
L_089D55F0:
    rt.unsupported(0x089D55F4u, 0x0C55F5EAu, "control flow in delay slot"); return;
L_089D55F8:
    { const bool branch_taken = static_cast<std::int32_t>(ctx.gpr[13]) > 0;
    rt.unsupported(0x089D55FCu, 0x233F7061u, "unknown not lowered yet"); return;
      if (branch_taken) {
          goto L_089D26F4;
      }
      goto L_089D5600;
    }
L_089D5600:
    ctx.gpr[18] = (ctx.gpr[27] & 61586u);
    ctx.gpr[19] = (aot_mem.aot_load32(ctx.gpr[12] + static_cast<std::uint32_t>(32321)));
    rt.unsupported(0x089D5608u, 0xD65FECF1u, "vfpu not lowered yet"); return;
L_089D562C:
    rt.unsupported(0x089D562Cu, 0x61D99735u, "vfpu0 not lowered yet"); return;
L_089D5640:
    rt.unsupported(0x089D5640u, 0x9E447A2Eu, "unknown not lowered yet"); return;
L_089D5654:
    { const bool branch_taken = ctx.gpr[2] == ctx.gpr[21];
    rt.unsupported(0x089D5658u, 0x675FDA79u, "vfpu1 not lowered yet"); return;
      if (branch_taken) {
          (void)rt.invoke_chained_direct<&recomp_unit_0013_entry, 13u, 4114u, 0x089B798Cu>(ctx, &aot_mem); return;
      }
      goto L_089D565C;
    }
L_089D565C:
    rt.unsupported(0x089D565Cu, 0xE3674340u, "unknown not lowered yet"); return;
L_089D5678:
    aot_mem.aot_store32(ctx.gpr[23] + static_cast<std::uint32_t>(-24789), std::bit_cast<std::uint32_t>(ctx.fpr[3]));
    { const std::uint32_t vfpu_address = ctx.gpr[28] + static_cast<std::uint32_t>(-21004);
      float vfpu_value[4]{
        std::bit_cast<float>(aot_mem.aot_load32(vfpu_address + 0u)),
        std::bit_cast<float>(aot_mem.aot_load32(vfpu_address + 4u)),
        std::bit_cast<float>(aot_mem.aot_load32(vfpu_address + 8u)),
        std::bit_cast<float>(aot_mem.aot_load32(vfpu_address + 12u))};
      ctx.write_vfpu_vector_ct<35u, 4u>(vfpu_value); }
    aot_mem.aot_store32(ctx.gpr[9] + static_cast<std::uint32_t>(23144), ctx.vfpu_scalar_bits_ct<29u>());
    ctx.gpr[1] = (aot_mem.aot_load16(ctx.gpr[4] + static_cast<std::uint32_t>(16631)));
    rt.unsupported(0x089D5688u, 0xF64C261Cu, "vfpu not lowered yet"); return;
L_089D56B4:
    ctx.gpr[4] = (aot_mem.aot_load16(ctx.gpr[25] + static_cast<std::uint32_t>(17734)));
    { const bool branch_taken = ctx.gpr[1] != ctx.gpr[1];
    // PSP CACHE is a no-op in coherent host memory.
      if (branch_taken) {
          (void)rt.invoke_chained_direct<&recomp_unit_0015, 15u>(ctx, &aot_mem); return;
      }
      goto L_089D56C0;
    }
L_089D56C0:
    rt.unsupported(0x089D56C0u, 0x4D95FC1Du, "unknown not lowered yet"); return;
L_089D56EC:
    rt.memory().aot_store_word_left(ctx.gpr[30] + static_cast<std::uint32_t>(2714), ctx.gpr[10]);
    ctx.gpr[16] = (static_cast<std::int32_t>(ctx.gpr[2]) < 30757 ? 1u : 0u);
    rt.unsupported(0x089D56F8u, 0x0A2C86DAu, "control flow in delay slot"); return;
L_089D56FC:
    aot_mem.aot_store32(ctx.gpr[13] + static_cast<std::uint32_t>(28152), ctx.vfpu_scalar_bits_ct<118u>());
    rt.unsupported(0x089D5700u, 0x68DC1462u, "unknown not lowered yet"); return;
L_089D570C:
    ctx.gpr[1] = (ctx.gpr[29] + static_cast<std::uint32_t>(-29202));
    rt.unsupported(0x089D5710u, 0x4F3FFEA2u, "unknown not lowered yet"); return;
L_089D5748:
    ctx.gpr[3] = (ctx.gpr[21] + static_cast<std::uint32_t>(26161));
    aot_mem.aot_store32(ctx.gpr[23] + static_cast<std::uint32_t>(-26704), ctx.vfpu_scalar_bits_ct<67u>());
    ctx.gpr[14] = (ctx.gpr[19] ^ 64116u);
    ctx.vfpu_ctrl[1u] = 0x000B4332u;
    rt.unsupported(0x089D5758u, 0x6841E7F7u, "unknown not lowered yet"); return;
L_089D5778:
    ctx.eat_vfpu_prefixes(); // VFPU sync/no-op consumes prefixes
    rt.unsupported(0x089D577Cu, 0xD096954Bu, "vfpu4 not lowered yet"); return;
L_089D5788:
    rt.unsupported(0x089D5788u, 0xCCA92963u, "unknown not lowered yet"); return;
L_089D57A0:
    ctx.eat_vfpu_prefixes(); // VFPU sync/no-op consumes prefixes
    rt.unsupported(0x089D57A4u, 0x04272F70u, "regimm? not lowered yet"); return;
L_089D57D4:
    rt.unsupported(0x089D57D4u, 0xD59BC0D1u, "vfpu not lowered yet"); return;
L_089D57F4:
    rt.unsupported(0x089D57F4u, 0x02E1329Eu, "special? not lowered yet"); return;
L_089D5838:
    rt.unsupported(0x089D5838u, 0xC39DFD27u, "unknown not lowered yet"); return;
L_089D5EA8:
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x02725020u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089D5ED0:
    rt.unsupported(0x089D5ED4u, 0x089C9410u, "control flow in delay slot"); return;
L_089D5EF4:
    rt.unsupported(0x089D5EF8u, 0x089C9410u, "control flow in delay slot"); return;
L_089D5F30:
    rt.unsupported(0x089D5F34u, 0x089C9478u, "control flow in delay slot"); return;
L_089D5FF8:
    // nop
    // nop
    rt.unsupported(0x089D6004u, 0x08B7F560u, "control flow in delay slot"); return;
L_089D6018:
    // nop
    // nop
    // nop
    ctx.pc = 0x021D1400u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089D6050:
    ctx.gpr[1] = (static_cast<std::uint32_t>(static_cast<std::int32_t>(static_cast<std::int8_t>(aot_mem.aot_load8(0u + static_cast<std::uint32_t>(-32768))))));
    ctx.gpr[3] = (static_cast<std::uint32_t>(static_cast<std::int32_t>(static_cast<std::int8_t>(aot_mem.aot_load8(0u + static_cast<std::uint32_t>(-32766))))));
    ctx.gpr[5] = (static_cast<std::uint32_t>(static_cast<std::int32_t>(static_cast<std::int8_t>(aot_mem.aot_load8(0u + static_cast<std::uint32_t>(-32764))))));
    ctx.gpr[7] = (static_cast<std::uint32_t>(static_cast<std::int32_t>(static_cast<std::int8_t>(aot_mem.aot_load8(0u + static_cast<std::uint32_t>(-32762))))));
    ctx.gpr[9] = (static_cast<std::uint32_t>(static_cast<std::int32_t>(static_cast<std::int8_t>(aot_mem.aot_load8(0u + static_cast<std::uint32_t>(-32760))))));
    ctx.gpr[11] = (static_cast<std::uint32_t>(static_cast<std::int32_t>(static_cast<std::int8_t>(aot_mem.aot_load8(0u + static_cast<std::uint32_t>(-32758))))));
    ctx.gpr[13] = (static_cast<std::uint32_t>(static_cast<std::int32_t>(static_cast<std::int8_t>(aot_mem.aot_load8(0u + static_cast<std::uint32_t>(-32756))))));
    ctx.gpr[15] = (static_cast<std::uint32_t>(static_cast<std::int32_t>(static_cast<std::int8_t>(aot_mem.aot_load8(0u + static_cast<std::uint32_t>(-32754))))));
    ctx.gpr[17] = (static_cast<std::uint32_t>(static_cast<std::int32_t>(static_cast<std::int8_t>(aot_mem.aot_load8(0u + static_cast<std::uint32_t>(-32752))))));
    ctx.gpr[19] = (static_cast<std::uint32_t>(static_cast<std::int32_t>(static_cast<std::int8_t>(aot_mem.aot_load8(0u + static_cast<std::uint32_t>(-32750))))));
    ctx.gpr[21] = (static_cast<std::uint32_t>(static_cast<std::int32_t>(static_cast<std::int8_t>(aot_mem.aot_load8(0u + static_cast<std::uint32_t>(-32748))))));
    ctx.gpr[23] = (static_cast<std::uint32_t>(static_cast<std::int32_t>(static_cast<std::int8_t>(aot_mem.aot_load8(0u + static_cast<std::uint32_t>(-32746))))));
    ctx.gpr[25] = (static_cast<std::uint32_t>(static_cast<std::int32_t>(static_cast<std::int8_t>(aot_mem.aot_load8(0u + static_cast<std::uint32_t>(-32744))))));
    ctx.gpr[27] = (static_cast<std::uint32_t>(static_cast<std::int32_t>(static_cast<std::int8_t>(aot_mem.aot_load8(0u + static_cast<std::uint32_t>(-32742))))));
    ctx.gpr[29] = (static_cast<std::uint32_t>(static_cast<std::int32_t>(static_cast<std::int8_t>(aot_mem.aot_load8(0u + static_cast<std::uint32_t>(-32740))))));
    ctx.gpr[31] = (static_cast<std::uint32_t>(static_cast<std::int32_t>(static_cast<std::int8_t>(aot_mem.aot_load8(0u + static_cast<std::uint32_t>(-32738))))));
    goto L_089D6090;
L_089D6090:
    ctx.gpr[1] = (static_cast<std::uint32_t>(static_cast<std::int32_t>(static_cast<std::int16_t>(aot_mem.aot_load16(ctx.gpr[1] + static_cast<std::uint32_t>(-32768))))));
    ctx.gpr[3] = (aot_mem.aot_load32(ctx.gpr[3] + static_cast<std::uint32_t>(-30654)));
    ctx.gpr[5] = (aot_mem.aot_load16(ctx.gpr[5] + static_cast<std::uint32_t>(-28540)));
    rt.unsupported(0x089D609Cu, 0x9CE798C6u, "unknown not lowered yet"); return;
L_089D60D0:
    { float vfpu_value[4]{}; ctx.read_vfpu_vector_ct<62u, 4u>(vfpu_value);
      const std::uint32_t vfpu_address = ctx.gpr[30] + static_cast<std::uint32_t>(-4);
      aot_mem.aot_store32(vfpu_address + 0u, std::bit_cast<std::uint32_t>(vfpu_value[0]));
      aot_mem.aot_store32(vfpu_address + 4u, std::bit_cast<std::uint32_t>(vfpu_value[1]));
      aot_mem.aot_store32(vfpu_address + 8u, std::bit_cast<std::uint32_t>(vfpu_value[2]));
      aot_mem.aot_store32(vfpu_address + 12u, std::bit_cast<std::uint32_t>(vfpu_value[3])); }
    rt.unsupported(0x089D60D4u, 0xF39CF7BDu, "vfpu-matrix1 not lowered yet"); return;
L_089D6110:
    { const bool branch_taken = 0u == 0u;
    // nop
      if (branch_taken) {
          goto L_089D6114;
      }
      goto L_089D6118;
    }
L_089D6114:
    // nop
    goto L_089D6118;
L_089D6118:
    rt.unsupported(0x089D6118u, 0x40000000u, "unknown not lowered yet"); return;
L_089D618C:
    // nop
    goto L_089D6190;
L_089D6190:
    rt.unsupported(0x089D6190u, 0x40000000u, "unknown not lowered yet"); return;
L_089D6264:
    // nop
    goto L_089D6268;
L_089D6268:
    rt.unsupported(0x089D6268u, 0x40000000u, "unknown not lowered yet"); return;
L_089D63A0:
    // nop
    rt.unsupported(0x089D63A8u, 0x0892742Cu, "control flow in delay slot"); return;
L_089D63AC:
    // nop
    rt.unsupported(0x089D63B4u, 0x0891F7B4u, "control flow in delay slot"); return;
L_089D63B8:
    // nop
    rt.unsupported(0x089D63C0u, 0x0891FB38u, "control flow in delay slot"); return;
L_089D63C4:
    // nop
    rt.unsupported(0x089D63CCu, 0x08879DB0u, "control flow in delay slot"); return;
L_089D63D0:
    // nop
    rt.unsupported(0x089D63D8u, 0x08879BBCu, "control flow in delay slot"); return;
L_089D63DC:
    // nop
    rt.unsupported(0x089D63E4u, 0x08810CACu, "control flow in delay slot"); return;
L_089D63E8:
    // nop
    rt.unsupported(0x089D63F0u, 0x08879B28u, "control flow in delay slot"); return;
L_089D63F4:
    // nop
    rt.unsupported(0x089D63FCu, 0x08860F28u, "control flow in delay slot"); return;
L_089D6400:
    // nop
    rt.unsupported(0x089D6408u, 0x08875888u, "control flow in delay slot"); return;
L_089D640C:
    // nop
    rt.unsupported(0x089D6414u, 0x088FC90Cu, "control flow in delay slot"); return;
L_089D6418:
    // nop
    rt.unsupported(0x089D6420u, 0x088B15D8u, "control flow in delay slot"); return;
L_089D6424:
    // nop
    rt.unsupported(0x089D642Cu, 0x088F43B0u, "control flow in delay slot"); return;
L_089D6430:
    // nop
    rt.unsupported(0x089D6438u, 0x0887A19Cu, "control flow in delay slot"); return;
L_089D643C:
    // nop
    rt.unsupported(0x089D6444u, 0x08885A4Cu, "control flow in delay slot"); return;
L_089D6448:
    // nop
    rt.unsupported(0x089D6450u, 0x08879FE0u, "control flow in delay slot"); return;
L_089D6454:
    // nop
    rt.unsupported(0x089D645Cu, 0x088D14B8u, "control flow in delay slot"); return;
L_089D6460:
    // nop
    rt.unsupported(0x089D6468u, 0x08879D04u, "control flow in delay slot"); return;
L_089D646C:
    // nop
    rt.unsupported(0x089D6474u, 0x08892234u, "control flow in delay slot"); return;
L_089D6478:
    // nop
    rt.unsupported(0x089D6480u, 0x088B3868u, "control flow in delay slot"); return;
L_089D6484:
    // nop
    rt.unsupported(0x089D648Cu, 0x088C6BA4u, "control flow in delay slot"); return;
L_089D6490:
    // nop
    rt.unsupported(0x089D6498u, 0x08828BD0u, "control flow in delay slot"); return;
L_089D649C:
    // nop
    rt.unsupported(0x089D64A4u, 0x0881DFE8u, "control flow in delay slot"); return;
L_089D64A8:
    // nop
    rt.unsupported(0x089D64B0u, 0x08879F28u, "control flow in delay slot"); return;
L_089D64B4:
    // nop
    rt.unsupported(0x089D64BCu, 0x0885BF8Cu, "control flow in delay slot"); return;
L_089D64C0:
    // nop
    rt.unsupported(0x089D64C8u, 0x08933EE4u, "control flow in delay slot"); return;
L_089D64CC:
    // nop
    rt.unsupported(0x089D64D4u, 0x08933BC4u, "control flow in delay slot"); return;
L_089D64D8:
    // nop
    rt.unsupported(0x089D64E0u, 0x088AFAD4u, "control flow in delay slot"); return;
L_089D64E4:
    // nop
    rt.unsupported(0x089D64ECu, 0x088B075Cu, "control flow in delay slot"); return;
L_089D64F0:
    // nop
    rt.unsupported(0x089D64F8u, 0x088ADAE4u, "control flow in delay slot"); return;
L_089D64FC:
    // nop
    rt.unsupported(0x089D6504u, 0x088B19B4u, "control flow in delay slot"); return;
L_089D6508:
    // nop
    rt.unsupported(0x089D6510u, 0x08885BA8u, "control flow in delay slot"); return;
L_089D6514:
    // nop
    rt.unsupported(0x089D651Cu, 0x0887E4C4u, "control flow in delay slot"); return;
L_089D6520:
    // nop
    rt.unsupported(0x089D6528u, 0x08879EC4u, "control flow in delay slot"); return;
L_089D652C:
    // nop
    rt.unsupported(0x089D6534u, 0x08879D54u, "control flow in delay slot"); return;
L_089D6538:
    // nop
    rt.unsupported(0x089D6540u, 0x088799F0u, "control flow in delay slot"); return;
L_089D6544:
    // nop
    rt.unsupported(0x089D654Cu, 0x088707C4u, "control flow in delay slot"); return;
L_089D6550:
    // nop
    rt.unsupported(0x089D6558u, 0x0886EFDCu, "control flow in delay slot"); return;
L_089D655C:
    // nop
    rt.unsupported(0x089D6564u, 0x0887133Cu, "control flow in delay slot"); return;
L_089D6568:
    // nop
    rt.unsupported(0x089D6570u, 0x088658B0u, "control flow in delay slot"); return;
L_089D6574:
    // nop
    rt.unsupported(0x089D657Cu, 0x08883EBCu, "control flow in delay slot"); return;
L_089D6580:
    // nop
    rt.unsupported(0x089D6588u, 0x088821F0u, "control flow in delay slot"); return;
L_089D658C:
    // nop
    rt.unsupported(0x089D6594u, 0x08872C38u, "control flow in delay slot"); return;
L_089D6598:
    // nop
    rt.unsupported(0x089D65A0u, 0x08881F4Cu, "control flow in delay slot"); return;
L_089D65A4:
    // nop
    rt.unsupported(0x089D65ACu, 0x0893342Cu, "control flow in delay slot"); return;
L_089D65B0:
    // nop
    rt.unsupported(0x089D65B8u, 0x08B58B38u, "control flow in delay slot"); return;
L_089D65BC:
    // nop
    rt.unsupported(0x089D65C4u, 0x08B42A2Cu, "control flow in delay slot"); return;
L_089D65C8:
    // nop
    rt.unsupported(0x089D65D0u, 0x08B42390u, "control flow in delay slot"); return;
L_089D65D4:
    // nop
    rt.unsupported(0x089D65DCu, 0x08B43648u, "control flow in delay slot"); return;
L_089D65E0:
    // nop
    rt.unsupported(0x089D65E8u, 0x08B45454u, "control flow in delay slot"); return;
L_089D65EC:
    // nop
    rt.unsupported(0x089D65F4u, 0x08B44768u, "control flow in delay slot"); return;
L_089D65F8:
    // nop
    rt.unsupported(0x089D6600u, 0x08B42240u, "control flow in delay slot"); return;
L_089D6604:
    // nop
    rt.unsupported(0x089D660Cu, 0x08A87464u, "control flow in delay slot"); return;
L_089D6610:
    // nop
    rt.unsupported(0x089D6618u, 0x08A8A1D0u, "control flow in delay slot"); return;
L_089D661C:
    // nop
    rt.unsupported(0x089D6624u, 0x08879A78u, "control flow in delay slot"); return;
L_089D6628:
    // nop
    rt.unsupported(0x089D6630u, 0x08A9CC28u, "control flow in delay slot"); return;
L_089D6634:
    // nop
    rt.unsupported(0x089D663Cu, 0x08A500ECu, "control flow in delay slot"); return;
L_089D6640:
    // nop
    rt.unsupported(0x089D6648u, 0x08A4D550u, "control flow in delay slot"); return;
L_089D664C:
    // nop
    rt.unsupported(0x089D6654u, 0x08A4AC38u, "control flow in delay slot"); return;
L_089D6658:
    // nop
    rt.unsupported(0x089D6660u, 0x08A1D400u, "control flow in delay slot"); return;
L_089D6664:
    // nop
    rt.unsupported(0x089D666Cu, 0x08A2BD20u, "control flow in delay slot"); return;
L_089D6670:
    // nop
    rt.unsupported(0x089D6678u, 0x089FE560u, "control flow in delay slot"); return;
L_089D667C:
    // nop
    rt.unsupported(0x089D6684u, 0x08A32420u, "control flow in delay slot"); return;
L_089D6688:
    // nop
    rt.unsupported(0x089D6690u, 0x08A436FCu, "control flow in delay slot"); return;
L_089D6694:
    // nop
    rt.unsupported(0x089D669Cu, 0x08A42C58u, "control flow in delay slot"); return;
L_089D66A0:
    // nop
    rt.unsupported(0x089D66A8u, 0x08B32734u, "control flow in delay slot"); return;
L_089D66AC:
    // nop
    rt.unsupported(0x089D66B4u, 0x08B29724u, "control flow in delay slot"); return;
L_089D66B8:
    // nop
    rt.unsupported(0x089D66C0u, 0x08B24A48u, "control flow in delay slot"); return;
L_089D66C4:
    // nop
    rt.unsupported(0x089D66CCu, 0x08AB9C54u, "control flow in delay slot"); return;
L_089D66D0:
    // nop
    rt.unsupported(0x089D66D8u, 0x08B0C048u, "control flow in delay slot"); return;
L_089D66DC:
    // nop
    rt.unsupported(0x089D66E4u, 0x08B1F0F8u, "control flow in delay slot"); return;
L_089D66E8:
    // nop
    rt.unsupported(0x089D66F0u, 0x08ABF734u, "control flow in delay slot"); return;
L_089D66F4:
    // nop
    rt.unsupported(0x089D66FCu, 0x08B23934u, "control flow in delay slot"); return;
L_089D6700:
    // nop
    rt.unsupported(0x089D6708u, 0x08AF2C84u, "control flow in delay slot"); return;
L_089D670C:
    // nop
    rt.unsupported(0x089D6714u, 0x08AC65DCu, "control flow in delay slot"); return;
L_089D6718:
    // nop
    rt.unsupported(0x089D6720u, 0x088F0708u, "control flow in delay slot"); return;
L_089D6724:
    // nop
    rt.unsupported(0x089D672Cu, 0x088F2228u, "control flow in delay slot"); return;
L_089D6730:
    // nop
    rt.unsupported(0x089D6738u, 0x089E0B50u, "control flow in delay slot"); return;
L_089D673C:
    // nop
    rt.unsupported(0x089D6744u, 0x089DD568u, "control flow in delay slot"); return;
L_089D6748:
    // nop
    rt.unsupported(0x089D6750u, 0x0887A0ECu, "control flow in delay slot"); return;
L_089D6754:
    // nop
    rt.unsupported(0x089D675Cu, 0x08879C20u, "control flow in delay slot"); return;
L_089D6760:
    // nop
    rt.unsupported(0x089D6768u, 0x08B488BCu, "control flow in delay slot"); return;
L_089D676C:
    // nop
    rt.unsupported(0x089D6774u, 0x08ACCDF4u, "control flow in delay slot"); return;
L_089D6778:
    // nop
    rt.unsupported(0x089D6780u, 0x08ACEE50u, "control flow in delay slot"); return;
L_089D6784:
    // nop
    rt.unsupported(0x089D678Cu, 0x08A61F38u, "control flow in delay slot"); return;
L_089D6790:
    // nop
    rt.unsupported(0x089D6798u, 0x08AC8F30u, "control flow in delay slot"); return;
L_089D679C:
    // nop
    rt.unsupported(0x089D67A4u, 0x08AA77D0u, "control flow in delay slot"); return;
L_089D67A8:
    // nop
    rt.unsupported(0x089D67B0u, 0x08AA5668u, "control flow in delay slot"); return;
L_089D67B4:
    // nop
    rt.unsupported(0x089D67BCu, 0x08A800E0u, "control flow in delay slot"); return;
L_089D67C0:
    // nop
    rt.unsupported(0x089D67C8u, 0x08ABAD30u, "control flow in delay slot"); return;
L_089D67CC:
    // nop
    rt.unsupported(0x089D67D4u, 0x08B18528u, "control flow in delay slot"); return;
L_089D67D8:
    // nop
    rt.unsupported(0x089D67E0u, 0x08B0DA58u, "control flow in delay slot"); return;
L_089D67E4:
    // nop
    rt.unsupported(0x089D67ECu, 0x08B04C00u, "control flow in delay slot"); return;
L_089D67F0:
    // nop
    rt.unsupported(0x089D67F8u, 0x08B0150Cu, "control flow in delay slot"); return;
L_089D67FC:
    // nop
    rt.unsupported(0x089D6804u, 0x08B2CD08u, "control flow in delay slot"); return;
L_089D6808:
    // nop
    rt.unsupported(0x089D6810u, 0x08B279F0u, "control flow in delay slot"); return;
L_089D6814:
    // nop
    rt.unsupported(0x089D681Cu, 0x08879F84u, "control flow in delay slot"); return;
L_089D6820:
    // nop
    rt.unsupported(0x089D6828u, 0x08B21340u, "control flow in delay slot"); return;
L_089D682C:
    // nop
    rt.unsupported(0x089D6834u, 0x08B20AD8u, "control flow in delay slot"); return;
L_089D6838:
    // nop
    rt.unsupported(0x089D6840u, 0x08B1D8E0u, "control flow in delay slot"); return;
L_089D6844:
    // nop
    rt.unsupported(0x089D684Cu, 0x08A21F90u, "control flow in delay slot"); return;
L_089D6850:
    // nop
    rt.unsupported(0x089D6858u, 0x08B1CDC0u, "control flow in delay slot"); return;
L_089D685C:
    // nop
    rt.unsupported(0x089D6864u, 0x08A22AF8u, "control flow in delay slot"); return;
L_089D6868:
    // nop
    rt.unsupported(0x089D6870u, 0x08B12CFCu, "control flow in delay slot"); return;
L_089D6874:
    // nop
    rt.unsupported(0x089D687Cu, 0x08AB3CF0u, "control flow in delay slot"); return;
L_089D6880:
    // nop
    rt.unsupported(0x089D6888u, 0x08879CB4u, "control flow in delay slot"); return;
L_089D688C:
    // nop
    rt.unsupported(0x089D6894u, 0x089E0DD0u, "control flow in delay slot"); return;
L_089D6898:
    // nop
    rt.unsupported(0x089D68A0u, 0x089DE670u, "control flow in delay slot"); return;
L_089D68D0:
    { const bool branch_taken = static_cast<std::int32_t>(ctx.gpr[31]) > 0;
    ctx.gpr[31] = (12287u << 16u);
      if (branch_taken) {
          goto L_089DA8D0;
      }
      goto L_089D68D8;
    }
L_089D68D8:
    if (static_cast<std::int32_t>(ctx.gpr[31]) > 0) {
    rt.unsupported(0x089D68DCu, 0x7FFF6FFFu, "special3? not lowered yet"); return;
        (void)rt.invoke_chained_direct<&recomp_unit_0015, 15u>(ctx, &aot_mem); return;
    }
    goto L_089D68E0;
L_089D68E0:
    rt.unsupported(0x089D68E0u, 0x9FFF8FFFu, "unknown not lowered yet"); return;
L_089D68F0:
    // nop
    rt.unsupported(0x089D68F8u, 0x0887CEE8u, "control flow in delay slot"); return;
L_089D6904:
    (void)(static_cast<std::uint32_t>(std::countl_zero(0u)));
    (void)(static_cast<std::uint32_t>(std::countl_one(0u)));
    { const std::int64_t product = static_cast<std::int64_t>(static_cast<std::int32_t>(0u)) * static_cast<std::int64_t>(static_cast<std::int32_t>(0u)); ctx.lo = static_cast<std::uint32_t>(product); ctx.hi = static_cast<std::uint32_t>(static_cast<std::uint64_t>(product) >> 32u); }
    { const std::uint64_t product = static_cast<std::uint64_t>(0u) * static_cast<std::uint64_t>(0u); ctx.lo = static_cast<std::uint32_t>(product); ctx.hi = static_cast<std::uint32_t>(product >> 32u); }
    goto L_089D6914;
L_089D6914:
    rt.unsupported(0x089D6914u, 0x0000000Cu, "syscall not lowered yet"); return;
L_089D6924:
    rt.unsupported(0x089D6924u, 0x0000000Du, "special? not lowered yet"); return;
L_089D6960:
    { const bool signed_ok = ctx.execute_signed_sub(4u, 0u, 0u);
      if (!signed_ok) { rt.arithmetic_overflow(0x089D6960u, 0x00002122u); return; } }
    goto L_089D6964;
L_089D6964:
    rt.unsupported(0x089D6964u, 0x00004681u, "special? not lowered yet"); return;
L_089D6970:
    rt.unsupported(0x089D6970u, 0x00007C81u, "special? not lowered yet"); return;
L_089D6988:
    ctx.eat_vfpu_prefixes(); // VFPU sync/no-op consumes prefixes
    ctx.eat_vfpu_prefixes(); // VFPU sync/no-op consumes prefixes
    ctx.eat_vfpu_prefixes(); // VFPU sync/no-op consumes prefixes
    // vflush: architectural no-op that retains VFPU prefixes
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    goto L_089D6A18;
L_089D6A18:
    // nop
    rt.unsupported(0x089D6A20u, 0x00000001u, "special? not lowered yet"); return;
    ctx.pc = 0x02728100u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089D6A48:
    // nop
    // nop
    ctx.pc = 0x02221E90u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089D6A98:
    // nop
    rt.unsupported(0x089D6AA0u, 0x08869908u, "control flow in delay slot"); return;
L_089D6AB0:
    // nop
    rt.unsupported(0x089D6AB8u, 0x0887A644u, "control flow in delay slot"); return;
L_089D6AF8:
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    goto L_089D6BF8;
L_089D6BF8:
    (void)(0u << 16u);
    goto L_089D6BFC;
L_089D6BFC:
    (void)(0u << 16u);
    (void)(0u << 16u);
    ctx.gpr[12] = (52429u << 16u);
    (void)(0u << 16u);
    (void)(0u << 16u);
    // nop
    rt.unsupported(0x089D6C18u, 0x089CAAECu, "control flow in delay slot"); return;
L_089D6C18:
    rt.unsupported(0x089D6C1Cu, 0x089CAAF4u, "control flow in delay slot"); return;
L_089D6C20:
    // nop
    rt.unsupported(0x089D6C28u, 0x08899240u, "control flow in delay slot"); return;
L_089D6CA8:
    // nop
    rt.unsupported(0x089D6CB0u, 0x089CAD48u, "control flow in delay slot"); return;
L_089D6D3C:
    // nop
    // nop
    // nop
    ctx.pc = 0x022904C0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089D6D98:
    // nop
    // nop
    ctx.pc = 0x022A2040u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089D6DB8:
    // nop
    rt.unsupported(0x089D6DC0u, 0x088A814Cu, "control flow in delay slot"); return;
L_089D6DDC:
    rt.unsupported(0x089D6DE0u, 0x089CB384u, "control flow in delay slot"); return;
L_089D6DE8:
    rt.unsupported(0x089D6DE8u, 0x0000FFFFu, "special? not lowered yet"); return;
L_089D6F58:
    // nop
    // vflush: architectural no-op that retains VFPU prefixes
    rt.unsupported(0x089D6F60u, 0x00000015u, "special? not lowered yet"); return;
L_089D70FC:
    // nop
    { const std::uint64_t product = static_cast<std::uint64_t>(0u) * static_cast<std::uint64_t>(0u); ctx.lo = static_cast<std::uint32_t>(product); ctx.hi = static_cast<std::uint32_t>(product >> 32u); }
    rt.unsupported(0x089D7104u, 0x00000001u, "special? not lowered yet"); return;
L_089D7130:
    rt.unsupported(0x089D7134u, 0x089CB450u, "control flow in delay slot"); return;
L_089D7140:
    // nop
    { const bool signed_ok = ctx.execute_signed_add(0u, 0u, 0u);
      if (!signed_ok) { rt.arithmetic_overflow(0x089D7144u, 0x000000A0u); return; } }
    // vflush: architectural no-op that retains VFPU prefixes
    // vflush: architectural no-op that retains VFPU prefixes
    // nop
    { const bool signed_ok = ctx.execute_signed_add(0u, 0u, 0u);
      if (!signed_ok) { rt.arithmetic_overflow(0x089D7154u, 0x000000A0u); return; } }
    // vflush: architectural no-op that retains VFPU prefixes
    // vflush: architectural no-op that retains VFPU prefixes
    rt.unsupported(0x089D7160u, 0x00000014u, "special? not lowered yet"); return;
L_089D7270:
    (void)(0u + 0u);
    { const bool signed_ok = ctx.execute_signed_sub(0u, 0u, 0u);
      if (!signed_ok) { rt.arithmetic_overflow(0x089D7274u, 0x00000022u); return; } }
    (void)(0u - 0u);
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    goto L_089D7298;
L_089D7298:
    // nop
    rt.unsupported(0x089D72A0u, 0x0887A644u, "control flow in delay slot"); return;
L_089D72C4:
    // nop
    rt.unsupported(0x089D72CCu, 0x0887A644u, "control flow in delay slot"); return;
L_089D72D0:
    // nop
    rt.unsupported(0x089D72D8u, 0x0887A644u, "control flow in delay slot"); return;
L_089D7390:
    // nop
    rt.unsupported(0x089D7398u, 0x0887A644u, "control flow in delay slot"); return;
L_089D739C:
    // nop
    rt.unsupported(0x089D73A4u, 0x0887A644u, "control flow in delay slot"); return;
L_089D73C0:
    // nop
    rt.unsupported(0x089D73C8u, 0x0887A644u, "control flow in delay slot"); return;
L_089D7418:
    // nop
    rt.unsupported(0x089D7420u, 0x0887A644u, "control flow in delay slot"); return;
L_089D7424:
    // nop
    rt.unsupported(0x089D742Cu, 0x0887A644u, "control flow in delay slot"); return;
L_089D7440:
    // nop
    // nop
    ctx.pc = 0x023081E0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089D7490:
    // nop
    // nop
    ctx.pc = 0x023087C0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089D74E0:
    rt.unsupported(0x089D74E4u, 0x088C2A48u, "control flow in delay slot"); return;
L_089D7758:
    (void)(ctx.hi);
    // nop
    (void)(0u << 1u);
    // nop
    (void)(0u << 2u);
    // nop
    { const bool signed_ok = ctx.execute_signed_add(0u, 0u, 0u);
      if (!signed_ok) { rt.arithmetic_overflow(0x089D7770u, 0x00000020u); return; } }
    // nop
    // nop
    (void)(0u << (0u & 31u));
    // nop
    (void)(ctx.hi);
    // nop
    { const bool signed_ok = ctx.execute_signed_add(0u, 0u, 0u);
      if (!signed_ok) { rt.arithmetic_overflow(0x089D778Cu, 0x00000020u); return; } }
    // nop
    jump_target = 0u;
    ctx.gpr[4] = (0u << 0u);
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089D7820:
    // nop
    rt.unsupported(0x089D7828u, 0x088CDF18u, "control flow in delay slot"); return;
L_089D7838:
    ctx.gpr[5] = (ctx.gpr[3] & 28271u);
    rt.unsupported(0x089D783Cu, 0x00000030u, "special? not lowered yet"); return;
L_089D79E8:
    ctx.gpr[18] = (ctx.gpr[3] & 28518u);
    rt.unsupported(0x089D79ECu, 0x61655F31u, "vfpu0 not lowered yet"); return;
L_089D7A10:
    // nop
    (void)(ctx.hi);
    ctx.gpr[24] = (ctx.gpr[3] & 26995u);
    rt.unsupported(0x089D7A1Cu, 0x61655F31u, "vfpu0 not lowered yet"); return;
L_089D7A30:
    ctx.gpr[22] = (ctx.gpr[3] & 25971u);
    rt.unsupported(0x089D7A34u, 0x61655F31u, "vfpu0 not lowered yet"); return;
L_089D7BE0:
    rt.unsupported(0x089D7BE0u, 0x00000001u, "special? not lowered yet"); return;
L_089D7CD4:
    jump_target = 0u;
    (void)(0u < 0u ? 1u : 0u);
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089D7DFC:
    rt.unsupported(0x089D7DFCu, 0x0000001Cu, "special? not lowered yet"); return;
L_089D7E8C:
    // nop
    // nop
    ctx.pc = 0x023A4920u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089D7ED8:
    // nop
    // nop
    ctx.pc = 0x023B3020u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089D7F00:
    // nop
    // vflush: architectural no-op that retains VFPU prefixes
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // vflush: architectural no-op that retains VFPU prefixes
    // nop
    // nop
    // nop
    // vflush: architectural no-op that retains VFPU prefixes
    goto L_089D7F48;
L_089D7F48:
    // nop
    // nop
    rt.unsupported(0x089D7F54u, 0x089CD028u, "control flow in delay slot"); return;
L_089D7F58:
    (void)(static_cast<std::uint32_t>(std::countl_one(0u)));
    rt.unsupported(0x089D7F5Cu, 0x00140015u, "special? not lowered yet"); return;
L_089D7F6C:
    (void)(static_cast<std::uint32_t>(static_cast<std::int32_t>(0u) >> 0u));
    (void)(ctx.lo);
    rt.unsupported(0x089D7F74u, 0x00000001u, "special? not lowered yet"); return;
L_089D7FA0:
    rt.unsupported(0x089D7FA4u, 0x089CD0A0u, "control flow in delay slot"); return;
L_089D7FC8:
    rt.unsupported(0x089D7FCCu, 0x089CD1C4u, "control flow in delay slot"); return;
L_089D8018:
    rt.unsupported(0x089D801Cu, 0x089CD428u, "control flow in delay slot"); return;
L_089D8088:
    rt.unsupported(0x089D808Cu, 0x089CD650u, "control flow in delay slot"); return;
L_089D80B8:
    rt.unsupported(0x089D80BCu, 0x089CD7E8u, "control flow in delay slot"); return;
L_089D80D0:
    rt.unsupported(0x089D80D4u, 0x089CD83Cu, "control flow in delay slot"); return;
L_089D8150:
    // nop
    // nop
    ctx.pc = 0x0241D330u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089D81B8:
    // nop
    // nop
    ctx.pc = 0x0241E310u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089D8220:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x02423880u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089D8250:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x024235B0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089D8280:
    // nop
    // nop
    ctx.pc = 0x02426EB0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089D82B0:
    // nop
    // nop
    ctx.pc = 0x02427020u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089D82E0:
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    goto L_089D8320;
L_089D8320:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x0242B460u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089D83E0:
    // nop
    // nop
    ctx.pc = 0x02738AB0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089D8408:
    // nop
    // nop
    ctx.pc = 0x0244F090u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089D84B8:
    // nop
    // nop
    ctx.gpr[12] = (52429u << 16u);
    ctx.gpr[12] = (52429u << 16u);
    (void)(0u << 16u);
    ctx.gpr[12] = (52429u << 16u);
    (void)(0u << 16u);
    ctx.gpr[12] = (52429u << 16u);
    goto L_089D84D8;
L_089D84D8:
    // nop
    // nop
    ctx.gpr[12] = (52429u << 16u);
    ctx.gpr[6] = (26214u << 16u);
    (void)(0u << 16u);
    goto L_089D84EC;
L_089D84EC:
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    goto L_089D8540;
L_089D8540:
    (void)(ctx.gpr[25] << 0u);
    // vflush: architectural no-op that retains VFPU prefixes
    rt.unsupported(0x089D8548u, 0x00000001u, "special? not lowered yet"); return;
L_089D8568:
    // nop
    (void)(static_cast<std::uint32_t>(static_cast<std::int32_t>(ctx.gpr[2]) >> 0u));
    (void)(ctx.gpr[9] >> 0u);
    (void)(static_cast<std::uint32_t>(static_cast<std::int32_t>(0u) >> 0u));
    rt.unsupported(0x089D8578u, 0x000C0001u, "special? not lowered yet"); return;
L_089D8598:
    rt.unsupported(0x089D8598u, 0x74736666u, "unknown not lowered yet"); return;
L_089D85A4:
    (void)(0u << 1u);
    goto L_089D85A8;
L_089D85A8:
    rt.unsupported(0x089D85A8u, 0x00000030u, "special? not lowered yet"); return;
L_089D85C4:
    rt.unsupported(0x089D85C8u, 0x089CF4E0u, "control flow in delay slot"); return;
L_089D85D0:
    rt.unsupported(0x089D85D4u, 0x08878DE0u, "control flow in delay slot"); return;
L_089D85DC:
    rt.unsupported(0x089D85E0u, 0x088798A0u, "control flow in delay slot"); return;
L_089D886C:
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    ctx.gpr[18] = (ctx.gpr[25] & 12592u);
    ctx.pc = 0x027617E0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089D88E8:
    ctx.gpr[18] = (ctx.gpr[25] & 12592u);
    ctx.gpr[22] = (ctx.gpr[25] | 13620u);
    rt.unsupported(0x089D88F0u, 0x62613938u, "vfpu0 not lowered yet"); return;
L_089D8920:
    rt.unsupported(0x089D8920u, 0x00310030u, "special? not lowered yet"); return;
L_089D8978:
    // nop
    // nop
    rt.unsupported(0x089D8984u, 0x089D8978u, "control flow in delay slot"); return;
L_089D8A88:
    rt.unsupported(0x089D8A8Cu, 0x089D8A80u, "control flow in delay slot"); return;
L_089D8A98:
    rt.unsupported(0x089D8A9Cu, 0x089D8A90u, "control flow in delay slot"); return;
L_089D8D74:
    rt.unsupported(0x089D8D78u, 0x089D8D70u, "control flow in delay slot"); return;
L_089D8DA8:
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    rt.unsupported(0x089D8DC0u, 0x00000001u, "special? not lowered yet"); return;
L_089D8DC8:
    rt.unsupported(0x089D8DC8u, 0x00000001u, "special? not lowered yet"); return;
L_089D8DF4:
    if (0u == 0u) (void)(0u);
    if (0u == 0u) (void)(0u);
    if (0u == 0u) (void)(0u);
    if (0u == 0u) (void)(0u);
    if (0u == 0u) (void)(0u);
    if (0u == 0u) (void)(0u);
    if (0u == 0u) (void)(0u);
    if (0u == 0u) (void)(0u);
    if (0u == 0u) (void)(0u);
    if (0u == 0u) (void)(0u);
    (void)(static_cast<std::uint32_t>(static_cast<std::int32_t>(0u) >> 0u));
    (void)(static_cast<std::uint32_t>(static_cast<std::int32_t>(0u) >> 0u));
    if (0u == 0u) (void)(0u);
    if (0u == 0u) (void)(0u);
    if (0u == 0u) (void)(0u);
    if (0u == 0u) (void)(0u);
    (void)(0u >> (0u & 31u));
    (void)(0u << (0u & 31u));
    (void)(0u << (0u & 31u));
    (void)(0u << (0u & 31u));
    (void)(0u << (0u & 31u));
    (void)(0u << (0u & 31u));
    if (0u != 0u) (void)(0u);
    (void)(0u << (0u & 31u));
    if (0u != 0u) (void)(0u);
    if (0u != 0u) (void)(0u);
    rt.unsupported(0x089D8E5Cu, 0x00000005u, "special? not lowered yet"); return;
L_089D8F78:
    rt.unsupported(0x089D8F78u, 0x00000005u, "special? not lowered yet"); return;
L_089D8FE8:
    rt.unsupported(0x089D8FE8u, 0x00000005u, "special? not lowered yet"); return;
L_089D9000:
    rt.unsupported(0x089D9000u, 0x00000005u, "special? not lowered yet"); return;
L_089D900C:
    rt.unsupported(0x089D900Cu, 0x00000005u, "special? not lowered yet"); return;
L_089D901C:
    rt.unsupported(0x089D901Cu, 0x00000005u, "special? not lowered yet"); return;
L_089D9038:
    (void)(0u >> 0u);
    (void)(0u >> 0u);
    goto L_089D9040;
L_089D9040:
    (void)(0u >> 0u);
    (void)(static_cast<std::uint32_t>(static_cast<std::int32_t>(0u) >> (0u & 31u)));
    (void)(0u >> 0u);
    (void)(0u >> 0u);
    goto L_089D9050;
L_089D9050:
    (void)(static_cast<std::uint32_t>(static_cast<std::int32_t>(0u) >> (0u & 31u)));
    (void)(static_cast<std::uint32_t>(static_cast<std::int32_t>(0u) >> (0u & 31u)));
    rt.unsupported(0x089D9058u, 0x00000005u, "special? not lowered yet"); return;
L_089D906C:
    (void)(static_cast<std::uint32_t>(static_cast<std::int32_t>(0u) >> (0u & 31u)));
    (void)(static_cast<std::uint32_t>(static_cast<std::int32_t>(0u) >> (0u & 31u)));
    (void)(static_cast<std::uint32_t>(static_cast<std::int32_t>(0u) >> (0u & 31u)));
    (void)(static_cast<std::uint32_t>(static_cast<std::int32_t>(0u) >> (0u & 31u)));
    (void)(static_cast<std::uint32_t>(static_cast<std::int32_t>(0u) >> (0u & 31u)));
    (void)(static_cast<std::uint32_t>(static_cast<std::int32_t>(0u) >> (0u & 31u)));
    rt.unsupported(0x089D9084u, 0x00000005u, "special? not lowered yet"); return;
L_089D9090:
    (void)(static_cast<std::uint32_t>(static_cast<std::int32_t>(0u) >> (0u & 31u)));
    (void)(static_cast<std::uint32_t>(static_cast<std::int32_t>(0u) >> (0u & 31u)));
    (void)(static_cast<std::uint32_t>(static_cast<std::int32_t>(0u) >> (0u & 31u)));
    (void)(static_cast<std::uint32_t>(static_cast<std::int32_t>(0u) >> (0u & 31u)));
    rt.unsupported(0x089D90A0u, 0x00000005u, "special? not lowered yet"); return;
L_089D90AC:
    (void)(static_cast<std::uint32_t>(static_cast<std::int32_t>(0u) >> (0u & 31u)));
    (void)(static_cast<std::uint32_t>(static_cast<std::int32_t>(0u) >> (0u & 31u)));
    (void)(static_cast<std::uint32_t>(static_cast<std::int32_t>(0u) >> (0u & 31u)));
    (void)(static_cast<std::uint32_t>(static_cast<std::int32_t>(0u) >> (0u & 31u)));
    (void)(static_cast<std::uint32_t>(static_cast<std::int32_t>(0u) >> (0u & 31u)));
    (void)(static_cast<std::uint32_t>(static_cast<std::int32_t>(0u) >> (0u & 31u)));
    (void)(static_cast<std::uint32_t>(static_cast<std::int32_t>(0u) >> (0u & 31u)));
    goto L_089D90C8;
L_089D90C8:
    (void)(static_cast<std::uint32_t>(static_cast<std::int32_t>(0u) >> (0u & 31u)));
    rt.unsupported(0x089D90CCu, 0x00000001u, "special? not lowered yet"); return;
L_089D90F0:
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    goto L_089D9108;
L_089D9108:
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    goto L_089D9120;
L_089D9120:
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    goto L_089D9140;
L_089D9140:
    rt.unsupported(0x089D9144u, 0x08934AF4u, "control flow in delay slot"); return;
L_089D914C:
    rt.unsupported(0x089D9150u, 0x08934B18u, "control flow in delay slot"); return;
L_089D9180:
    // nop
    // nop
    // nop
    // nop
    goto L_089D9190;
L_089D9190:
    (void)(0u << 16u);
    // nop
    // nop
    // nop
    // nop
    (void)(0u << 16u);
    // nop
    // nop
    // nop
    // nop
    (void)(0u << 16u);
    // nop
    // nop
    // nop
    // nop
    (void)(0u << 16u);
    goto L_089D91D0;
L_089D91D0:
    rt.unsupported(0x089D91D0u, 0x42C80000u, "unknown not lowered yet"); return;
L_089D91E0:
    rt.unsupported(0x089D91E0u, 0x41200000u, "unknown not lowered yet"); return;
L_089D91F0:
    rt.unsupported(0x089D91F0u, 0x43700000u, "unknown not lowered yet"); return;
L_089D9204:
    rt.unsupported(0x089D9204u, 0x42F80000u, "unknown not lowered yet"); return;
L_089D9218:
    // PSP CACHE is a no-op in coherent host memory.
    (void)(0u << 16u);
    (void)(0u << 16u);
    (void)(0u << 16u);
    (void)(0u << 16u);
    (void)(0u << 16u);
    // PSP CACHE is a no-op in coherent host memory.
    // PSP CACHE is a no-op in coherent host memory.
    (void)(0u << 16u);
    (void)(0u << 16u);
    // PSP CACHE is a no-op in coherent host memory.
    (void)(0u << 16u);
    // PSP CACHE is a no-op in coherent host memory.
    (void)(0u << 16u);
    // PSP CACHE is a no-op in coherent host memory.
    (void)(0u << 16u);
    (void)(0u << 16u);
    // PSP CACHE is a no-op in coherent host memory.
    // PSP CACHE is a no-op in coherent host memory.
    // PSP CACHE is a no-op in coherent host memory.
    // PSP CACHE is a no-op in coherent host memory.
    (void)(0u << 16u);
    // PSP CACHE is a no-op in coherent host memory.
    // PSP CACHE is a no-op in coherent host memory.
    goto L_089D9278;
L_089D9278:
    (void)(0u << 4u);
    (void)(ctx.gpr[3] >> 12u);
    rt.unsupported(0x089D9280u, 0x06040504u, "regimm? not lowered yet"); return;
L_089D9290:
    ctx.eat_vfpu_prefixes(); // VFPU sync/no-op consumes prefixes
    // nop
    // nop
    // nop
    ctx.eat_vfpu_prefixes(); // VFPU sync/no-op consumes prefixes
    rt.unsupported(0x089D92A4u, 0x42C80000u, "unknown not lowered yet"); return;
L_089D92BC:
    // nop
    ctx.eat_vfpu_prefixes(); // VFPU sync/no-op consumes prefixes
    // nop
    rt.unsupported(0x089D92C8u, 0x42C80000u, "unknown not lowered yet"); return;
L_089D92F0:
    // nop
    // nop
    // nop
    // nop
    goto L_089D9300;
L_089D9300:
    rt.unsupported(0x089D9300u, 0x42C80000u, "unknown not lowered yet"); return;
L_089D9310:
    rt.unsupported(0x089D9310u, 0x43700000u, "unknown not lowered yet"); return;
L_089D9324:
    rt.unsupported(0x089D9324u, 0x42F80000u, "unknown not lowered yet"); return;
L_089D9340:
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    (void)(0u >> 0u);
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    goto L_089D93F8;
L_089D93F8:
    // nop
    (void)(0u << (0u & 31u));
    // nop
    (void)(0u << (0u & 31u));
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    jump_target = 0u;
    // nop
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089D945C:
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    goto L_089D94E8;
L_089D94E8:
    (void)(0u >> 0u);
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    goto L_089D9544;
L_089D9544:
    // nop
    // nop
    // nop
    // nop
    // nop
    (void)(0u << (0u & 31u));
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    goto L_089D95D0;
L_089D95D0:
    // nop
    rt.unsupported(0x089D95D8u, 0x089D9860u, "control flow in delay slot"); return;
L_089D99E0:
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    (void)(ctx.gpr[1] << 0u);
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    goto L_089D9A88;
L_089D9A88:
    { const bool signed_ok = ctx.execute_signed_sub(0u, 0u, 0u);
      if (!signed_ok) { rt.arithmetic_overflow(0x089D9A88u, 0x000000A2u); return; } }
    // nop
    // nop
    // nop
    goto L_089D9A98;
L_089D9A98:
    // nop
    // nop
    rt.unsupported(0x089D9AA0u, 0x00000201u, "special? not lowered yet"); return;
L_089D9AF8:
    rt.unsupported(0x089D9AF8u, 0x00010001u, "special? not lowered yet"); return;
L_089D9B30:
    rt.unsupported(0x089D9B30u, 0x00010001u, "special? not lowered yet"); return;
L_089D9B50:
    jump_target = 0u;
    ctx.gpr[31] = (0x089D9B58u);
    (void)(static_cast<std::int32_t>(0u) > static_cast<std::int32_t>(0u) ? 0u : 0u);
    ctx.pc = jump_target;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x089D9B58u) goto L_089D9B58;
    return;
L_089D9B58:
    if (ctx.gpr[1] == 0u) (void)(0u);
    (void)(static_cast<std::int32_t>(0u) > static_cast<std::int32_t>(0u) ? 0u : 0u);
    jump_target = 0u;
    ctx.gpr[31] = (0x089D9B68u);
    rt.unsupported(0x089D9B64u, 0x00000036u, "special? not lowered yet"); return;
    ctx.pc = jump_target;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x089D9B68u) goto L_089D9B68;
    return;
L_089D9B68:
    jump_target = 0u;
    ctx.gpr[31] = (0x089D9B70u);
    { const std::int32_t dividend = static_cast<std::int32_t>(0u); const std::int32_t divisor = static_cast<std::int32_t>(ctx.gpr[6]); if (divisor == 0) { ctx.lo = dividend >= 0 ? 0xFFFFFFFFu : 1u; ctx.hi = static_cast<std::uint32_t>(dividend); } else if (dividend == static_cast<std::int32_t>(0x80000000u) && divisor == -1) { ctx.lo = 0x80000000u; ctx.hi = 0u; } else { ctx.lo = static_cast<std::uint32_t>(dividend / divisor); ctx.hi = static_cast<std::uint32_t>(dividend % divisor); } }
    ctx.pc = jump_target;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x089D9B70u) goto L_089D9B70;
    return;
L_089D9B70:
    (void)(static_cast<std::uint32_t>(static_cast<std::int32_t>(ctx.gpr[2]) >> (0u & 31u)));
    ctx.hi = 0u;
    (void)(0u << (0u & 31u));
    if (0u == 0u) (void)(0u);
    (void)(ctx.gpr[2] << 16u);
    (void)(ctx.gpr[16] << 0u);
    if (ctx.gpr[1] == 0u) (void)(0u);
    rt.unsupported(0x089D9B8Cu, 0x0006001Cu, "special? not lowered yet"); return;
L_089D9BB8:
    rt.unsupported(0x089D9BB8u, 0x00010005u, "special? not lowered yet"); return;
L_089D9FB0:
    // nop
    (void)(0u << 16u);
    // nop
    (void)(0u << 16u);
    goto L_089D9FC0;
L_089D9FC0:
    // nop
    // nop
    (void)(0u << 16u);
    (void)(0u << 16u);
    goto L_089D9FD0;
L_089D9FD0:
    // nop
    // nop
    // nop
    // nop
    goto L_089D9FE0;
L_089D9FE0:
    // nop
    // nop
    // nop
    // nop
    goto L_089D9FF0;
L_089D9FF0:
    // nop
    (void)(0u << 16u);
    // nop
    (void)(0u << 16u);
    goto L_089DA000;
L_089DA000:
    // nop
    // nop
    (void)(0u << 16u);
    goto L_089DA00C;
L_089DA00C:
    (void)(0u << 16u);
    goto L_089DA010;
L_089DA010:
    // nop
    // nop
    // nop
    // nop
    goto L_089DA020;
L_089DA020:
    (void)(0u << 16u);
    // nop
    // nop
    // nop
    // nop
    (void)(0u << 16u);
    // nop
    // nop
    // nop
    // nop
    (void)(0u << 16u);
    // nop
    // nop
    // nop
    // nop
    (void)(0u << 16u);
    goto L_089DA060;
L_089DA060:
    // nop
    // nop
    // nop
    // nop
    goto L_089DA070;
L_089DA070:
    // nop
    // nop
    // nop
    // nop
    goto L_089DA080;
L_089DA080:
    // nop
    // nop
    // nop
    // nop
    goto L_089DA090;
L_089DA090:
    // nop
    // nop
    // nop
    // nop
    goto L_089DA0A0;
L_089DA0A0:
    // nop
    // nop
    // nop
    // nop
    goto L_089DA0B0;
L_089DA0B0:
    // nop
    // nop
    // nop
    // nop
    goto L_089DA0C0;
L_089DA0C0:
    { const bool branch_taken = 0u != ctx.gpr[19];
    // nop
      if (branch_taken) {
          (void)rt.invoke_chained_direct<&recomp_unit_0014, 14u>(ctx, &aot_mem); return;
      }
      goto L_089DA0C8;
    }
L_089DA0C8:
    ctx.gpr[20] = (ctx.gpr[9] & 12848u);
    { const bool branch_taken = 0u == 0u;
    { const bool signed_ok = ctx.execute_signed_add(0u, 0u, 0u);
      if (!signed_ok) { rt.arithmetic_overflow(0x089DA0D0u, 0x00000020u); return; } }
      if (branch_taken) {
          (void)rt.invoke_chained_direct<&recomp_unit_0015, 15u>(ctx, &aot_mem); return;
      }
      goto L_089DA0D4;
    }
L_089DA0D4:
    // nop
    goto L_089DA0D8;
L_089DA0D8:
    rt.unsupported(0x089DA0D8u, 0x000F0E0Du, "special? not lowered yet"); return;
L_089DA0E0:
    rt.unsupported(0x089DA0E4u, 0x10001D0Fu, "control flow in delay slot"); return;
L_089DA0E8:
    { const bool signed_ok = ctx.execute_signed_add(0u, 0u, 0u);
      if (!signed_ok) { rt.arithmetic_overflow(0x089DA0E8u, 0x00000020u); return; } }
    // nop
    goto L_089DA0F0;
L_089DA0F0:
    rt.unsupported(0x089DA0F0u, 0x000F0E0Du, "special? not lowered yet"); return;
L_089DA0F8:
    rt.unsupported(0x089DA0FCu, 0x10001D0Fu, "control flow in delay slot"); return;
L_089DA100:
    { const bool signed_ok = ctx.execute_signed_add(0u, 0u, 0u);
      if (!signed_ok) { rt.arithmetic_overflow(0x089DA100u, 0x00000020u); return; } }
    // nop
    goto L_089DA108;
L_089DA108:
    rt.unsupported(0x089DA108u, 0x000F0E0Du, "special? not lowered yet"); return;
L_089DA110:
    rt.unsupported(0x089DA114u, 0x10001E1Cu, "control flow in delay slot"); return;
L_089DA118:
    { const bool signed_ok = ctx.execute_signed_add(0u, 0u, 0u);
      if (!signed_ok) { rt.arithmetic_overflow(0x089DA118u, 0x00000020u); return; } }
    // nop
    rt.unsupported(0x089DA120u, 0x00000001u, "special? not lowered yet"); return;
L_089DA130:
    (void)(0u << 16u);
    // nop
    // nop
    // nop
    // nop
    (void)(0u << 16u);
    // nop
    // nop
    // nop
    // nop
    (void)(0u << 16u);
    // nop
    // nop
    // nop
    // nop
    (void)(0u << 16u);
    goto L_089DA170;
L_089DA170:
    // PSP CACHE is a no-op in coherent host memory.
    // PSP CACHE is a no-op in coherent host memory.
    // PSP CACHE is a no-op in coherent host memory.
    (void)(0u << 16u);
    // PSP CACHE is a no-op in coherent host memory.
    // PSP CACHE is a no-op in coherent host memory.
    (void)(0u << 16u);
    (void)(0u << 16u);
    (void)(0u << 16u);
    // PSP CACHE is a no-op in coherent host memory.
    (void)(0u << 16u);
    (void)(0u << 16u);
    (void)(0u << 16u);
    // PSP CACHE is a no-op in coherent host memory.
    // PSP CACHE is a no-op in coherent host memory.
    (void)(0u << 16u);
    // PSP CACHE is a no-op in coherent host memory.
    (void)(0u << 16u);
    // PSP CACHE is a no-op in coherent host memory.
    (void)(0u << 16u);
    // PSP CACHE is a no-op in coherent host memory.
    (void)(0u << 16u);
    (void)(0u << 16u);
    (void)(0u << 16u);
    (void)(0u << 16u);
    (void)(0u << 16u);
    (void)(0u << 16u);
    (void)(0u << 16u);
    (void)(0u << 16u);
    (void)(0u << 16u);
    // PSP CACHE is a no-op in coherent host memory.
    (void)(0u << 16u);
    goto L_089DA1F0;
L_089DA1F0:
    // PSP CACHE is a no-op in coherent host memory.
    // PSP CACHE is a no-op in coherent host memory.
    // PSP CACHE is a no-op in coherent host memory.
    (void)(0u << 16u);
    // PSP CACHE is a no-op in coherent host memory.
    // PSP CACHE is a no-op in coherent host memory.
    (void)(0u << 16u);
    (void)(0u << 16u);
    (void)(0u << 16u);
    // PSP CACHE is a no-op in coherent host memory.
    (void)(0u << 16u);
    (void)(0u << 16u);
    (void)(0u << 16u);
    // PSP CACHE is a no-op in coherent host memory.
    // PSP CACHE is a no-op in coherent host memory.
    (void)(0u << 16u);
    // PSP CACHE is a no-op in coherent host memory.
    (void)(0u << 16u);
    // PSP CACHE is a no-op in coherent host memory.
    (void)(0u << 16u);
    // PSP CACHE is a no-op in coherent host memory.
    (void)(0u << 16u);
    (void)(0u << 16u);
    (void)(0u << 16u);
    (void)(0u << 16u);
    (void)(0u << 16u);
    (void)(0u << 16u);
    (void)(0u << 16u);
    (void)(0u << 16u);
    (void)(0u << 16u);
    // PSP CACHE is a no-op in coherent host memory.
    (void)(0u << 16u);
    ctx.gpr[29] = (28836u << 16u);
    ctx.gpr[31] = (48759u << 16u);
    // nop
    // nop
    // nop
    // nop
    // vflush: architectural no-op that retains VFPU prefixes
    goto L_089DA28C;
L_089DA28C:
    (void)(ctx.gpr[1] << 0u);
    jump_target = ctx.gpr[8];
    ctx.gpr[31] = (0x089DA298u);
    if (ctx.gpr[18] == 0u) (void)(ctx.gpr[8]);
    ctx.pc = jump_target;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x089DA298u) goto L_089DA298;
    return;
L_089DA298:
    { const std::int32_t dividend = static_cast<std::int32_t>(ctx.gpr[9]); const std::int32_t divisor = static_cast<std::int32_t>(ctx.gpr[2]); if (divisor == 0) { ctx.lo = dividend >= 0 ? 0xFFFFFFFFu : 1u; ctx.hi = static_cast<std::uint32_t>(dividend); } else if (dividend == static_cast<std::int32_t>(0x80000000u) && divisor == -1) { ctx.lo = 0x80000000u; ctx.hi = 0u; } else { ctx.lo = static_cast<std::uint32_t>(dividend / divisor); ctx.hi = static_cast<std::uint32_t>(dividend % divisor); } }
    (void)(static_cast<std::int32_t>(ctx.gpr[9]) < static_cast<std::int32_t>(ctx.gpr[18]) ? 1u : 0u);
    rt.unsupported(0x089DA2A0u, 0x01370136u, "special? not lowered yet"); return;
L_089DA2C0:
    (void)(ctx.gpr[9] << 0u);
    if (ctx.gpr[18] == 0u) (void)(ctx.gpr[8]);
    { const std::int32_t dividend = static_cast<std::int32_t>(ctx.gpr[9]); const std::int32_t divisor = static_cast<std::int32_t>(ctx.gpr[2]); if (divisor == 0) { ctx.lo = dividend >= 0 ? 0xFFFFFFFFu : 1u; ctx.hi = static_cast<std::uint32_t>(dividend); } else if (dividend == static_cast<std::int32_t>(0x80000000u) && divisor == -1) { ctx.lo = 0x80000000u; ctx.hi = 0u; } else { ctx.lo = static_cast<std::uint32_t>(dividend / divisor); ctx.hi = static_cast<std::uint32_t>(dividend % divisor); } }
    (void)(static_cast<std::int32_t>(ctx.gpr[9]) < static_cast<std::int32_t>(ctx.gpr[18]) ? 1u : 0u);
    rt.unsupported(0x089DA2D0u, 0x01090136u, "special? not lowered yet"); return;
L_089DA2E4:
    rt.unsupported(0x089DA2E4u, 0x02010101u, "special? not lowered yet"); return;
L_089DA2F0:
    (void)(ctx.gpr[7] << 8u);
    (void)(0u >> 8u);
    ctx.gpr[31] = (0u >> 28u);
    goto L_089DA2FC;
L_089DA2FC:
    (void)(0u << 16u);
    rt.unsupported(0x089DA304u, 0x04000000u, "control flow in delay slot"); return;
L_089DA308:
    rt.unsupported(0x089DA30Cu, 0x0B050004u, "control flow in delay slot"); return;
L_089DA340:
    // nop
    // nop
    // nop
    // nop
    goto L_089DA350;
L_089DA350:
    // nop
    // nop
    // nop
    (void)(0u << 16u);
    goto L_089DA360;
L_089DA360:
    // nop
    // nop
    // nop
    // nop
    goto L_089DA370;
L_089DA370:
    (void)(0u << 16u);
    // nop
    // nop
    // nop
    // nop
    (void)(0u << 16u);
    // nop
    // nop
    // nop
    // nop
    (void)(0u << 16u);
    // nop
    // nop
    // nop
    // nop
    (void)(0u << 16u);
    goto L_089DA3B0;
L_089DA3B0:
    // nop
    // nop
    // nop
    // nop
    goto L_089DA3C0;
L_089DA3C0:
    // nop
    (void)(0u >> 0u);
    (void)(0u << (0u & 31u));
    jump_target = 0u;
    (void)(ctx.hi);
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
L_089DA400:
    // nop
    // nop
    // nop
    // nop
    goto L_089DA410;
L_089DA410:
    (void)(ctx.gpr[28] ^ 32897u);
    (void)(ctx.gpr[28] ^ 32897u);
    (void)(ctx.gpr[28] ^ 32897u);
    (void)(ctx.gpr[28] ^ 32897u);
    // nop
    // nop
    // nop
    rt.unsupported(0x089DA42Cu, 0x00000001u, "special? not lowered yet"); return;
L_089DA4C0:
    rt.unsupported(0x089DA4C4u, 0x08934AF4u, "control flow in delay slot"); return;
L_089DA4CC:
    rt.unsupported(0x089DA4D0u, 0x08934B18u, "control flow in delay slot"); return;
L_089DA4D8:
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    goto L_089DA69C;
L_089DA69C:
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    goto L_089DA6CC;
L_089DA6CC:
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    goto L_089DA6E8;
L_089DA6E8:
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    goto L_089DA708;
L_089DA708:
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    goto L_089DA728;
L_089DA728:
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    goto L_089DA74C;
L_089DA74C:
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    goto L_089DA774;
L_089DA774:
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    goto L_089DA8D0;
L_089DA8D0:
    // nop
    // nop
    goto L_089DA8D8;
L_089DA8D8:
    // nop
    // nop
    // nop
    // nop
    goto L_089DA8E8;
L_089DA8E8:
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    goto L_089DA900;
L_089DA900:
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    goto L_089DA930;
L_089DA930:
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    goto L_089DAA38;
L_089DAA38:
    ctx.gpr[16] = (ctx.gpr[25] & 9517u);
    (void)(0u & 0u);
    // nop
    // nop
    // vflush: architectural no-op that retains VFPU prefixes
    (void)(~(0u | 0u));
    // nop
    rt.unsupported(0x089DAA54u, 0x00000001u, "special? not lowered yet"); return;
L_089DAA58:
    // nop
    // nop
    // nop
    // nop
    goto L_089DAA68;
L_089DAA68:
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    goto L_089DAAC4;
L_089DAAC4:
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    goto L_089DAE00;
L_089DAE00:
    // nop
    // nop
    goto L_089DAE08;
L_089DAE08:
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    goto L_089DAE28;
L_089DAE28:
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    goto L_089DAE48;
L_089DAE48:
    // nop
    // nop
    // nop
    // nop
    goto L_089DAE58;
L_089DAE58:
    // nop
    // nop
    // nop
    // nop
    goto L_089DAE68;
L_089DAE68:
    // nop
    // nop
    // nop
    // nop
    // nop
    goto L_089DAE7C;
L_089DAE7C:
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    // nop
    goto L_089DAEE8;
L_089DAEE8:
    rt.unsupported(0x089DAEECu, 0x08934B18u, "control flow in delay slot"); return;
L_089DAF30:
    rt.unsupported(0x089DAF34u, 0x08934B18u, "control flow in delay slot"); return;
L_089DAF84:
    rt.unsupported(0x089DAF84u, 0xC2000001u, "unknown not lowered yet"); return;
L_089DAFC0:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x02507450u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DB014:
    // nop
    ctx.pc = 0x02509000u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DB028:
    // nop
    // nop
    goto L_089DB030;
L_089DB030:
    // nop
    // nop
    ctx.pc = 0x02507450u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DB090:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x02538F00u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DB0D0:
    // nop
    // nop
    ctx.pc = 0x02538EC0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DB0E0:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x025396C0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DB130:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x0253A390u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DB180:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x0253B3C0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DB1B8:
    // nop
    // nop
    ctx.pc = 0x02538EA0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DB1D0:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x0253B400u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DB220:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x0253B520u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DB270:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x0253CDE0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DB2C0:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x0253E470u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DB310:
    // nop
    goto L_089DB314;
L_089DB314:
    // nop
    // nop
    // nop
    ctx.pc = 0x0253FD80u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DB360:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x025418A0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DB3B0:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x02543D70u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DB400:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x02545F30u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DB450:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x02546180u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DB4A0:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x02546A60u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DB4F0:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x02547A60u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DB540:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x025489D0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DB590:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x02548FD0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DB5E0:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x02549C30u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DB618:
    // nop
    // nop
    ctx.pc = 0x02538EA0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DB630:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x0254A910u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DB680:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x0254AEB0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DB6D0:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x0254BB60u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DB720:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x0254C860u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DB770:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x0254D4F0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DB7C0:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x0254E0E0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DB810:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x0254E610u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DB860:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x02550770u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DB8B0:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x02550900u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DB900:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x02550A40u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DB950:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x02551470u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DB9A0:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x025516E0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DB9F0:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x02553740u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DBA40:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x02555BB0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DBA7C:
    // nop
    ctx.pc = 0x02538EA0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DBA90:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x02557A10u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DBAD4:
    // nop
    ctx.pc = 0x02538EC0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DBAE0:
    // nop
    // nop
    // nop
    goto L_089DBAEC;
L_089DBAEC:
    // nop
    ctx.pc = 0x02558410u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DBB30:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x025584D0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DBB80:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x02558590u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DBBD0:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x0255A700u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DBC20:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x025655B0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DBC70:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x02565A20u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DBCA4:
    // nop
    ctx.pc = 0x02566050u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DBCC0:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x02566070u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DBD10:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x02567910u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DBD60:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x02567DC0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DBDB0:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x02569220u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DBE00:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x02569A60u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DBE50:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x02569B20u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DBE70:
    // nop
    // nop
    ctx.pc = 0x02569EC0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DBEA0:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x0256A170u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DBEF0:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x0256A730u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DBF40:
    // nop
    // nop
    goto L_089DBF48;
L_089DBF48:
    // nop
    // nop
    ctx.pc = 0x0256C790u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DBF50:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x0256E1C0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DBF60:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x02570690u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DBF70:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x02709F30u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DBF90:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x0270A250u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DBFC0:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x0270A130u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DBFD8:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x0270A550u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DC008:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x0270A430u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DC020:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x0270A850u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DC050:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x0270A730u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DC068:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x02585E30u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DC0B8:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x025872E0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DC0F4:
    // nop
    ctx.pc = 0x02538EA0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DC108:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x0258A360u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DC158:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x0258C830u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DC1A8:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x0258EF90u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DC1E8:
    // nop
    // nop
    ctx.pc = 0x02538EC0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DC1F8:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x02538DE0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DC238:
    // nop
    // nop
    ctx.pc = 0x02538EC0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DC248:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x02592970u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DC28C:
    // nop
    ctx.pc = 0x02538EC0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DC298:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x02596AD0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DC2E8:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x02597110u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DC338:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x02597750u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DC388:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x02597D90u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DC3D8:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x02598340u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DC428:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x0259C8B0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DC478:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x0259CE20u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DC4C8:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x025A1670u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DC4E8:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x025A4790u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DC508:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x025A7EB0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DC528:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x025AABF0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DC548:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x025AF700u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DC568:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x025B3480u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DC57C:
    // nop
    ctx.pc = 0x025B34A0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DC5B8:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x025B4200u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DC608:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x025B4470u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DC658:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x025B5910u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DC6A8:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x025B6630u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DC6F8:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x025B68A0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DC748:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x025B7910u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DC798:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x025B8660u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DC7CC:
    // nop
    ctx.pc = 0x025B87A0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DC7E4:
    // nop
    ctx.pc = 0x02538EE0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DC7E8:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x025B88D0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DC7FC:
    // nop
    ctx.pc = 0x025B88F0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DC814:
    // nop
    ctx.pc = 0x02538E60u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DC82C:
    // nop
    ctx.pc = 0x02538EC0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DC838:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x025B9700u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DC888:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x025BA430u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DC8D8:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x025BA6A0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DC928:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x0270AA90u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DC960:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x02507450u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DC9C8:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x02507450u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DCA30:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x02507450u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DCA98:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x025D2B00u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DCAE8:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x025D4F50u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DCB38:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x025D7770u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DCB88:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x025D9D60u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DCBD8:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x025DC4B0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DCC28:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x025DF2D0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DCC78:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x025E2880u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DCCC8:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x025E60E0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DCD0C:
    // nop
    ctx.pc = 0x02538EC0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DCD18:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x025E91C0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DCD68:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x025ECAC0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DCDB4:
    // nop
    ctx.pc = 0x02538EE0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DCDB8:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x025F1490u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DCDDC:
    // nop
    ctx.pc = 0x025F1E60u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DCE08:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x025F3410u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DCE34:
    // nop
    ctx.pc = 0x025F39A0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DCE58:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x025F3AA0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DCEA8:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x025F4A50u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DCEF8:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x025F7010u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DCF48:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x025F7D80u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DCF98:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x025FA3C0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DCFE8:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x025FB110u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DD038:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x025FBD70u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DD088:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x025FF2E0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DD0D8:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x02711FE0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DD0F0:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x02712100u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DD108:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x02712220u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DD120:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x02600B10u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DD170:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x0260DC80u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DD1C0:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x0260E890u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DD210:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x02610FB0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DD230:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x02713660u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DD250:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x027137D0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DD270:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x02622290u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DD2A8:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x02626D10u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DD2C8:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x02713AF0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DD2E8:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x02713C10u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DD308:
    // nop
    goto L_089DD30C;
L_089DD30C:
    // nop
    // nop
    // nop
    ctx.pc = 0x02714650u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DD31C:
    // nop
    ctx.pc = 0x0263E390u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DD320:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x02714530u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DD338:
    // nop
    // nop
    // nop
    // nop
    ctx.pc = 0x0263E720u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DD34C:
    // nop
    ctx.pc = 0x0263EBD0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DD370:
    // nop
    // nop
    goto L_089DD378;
L_089DD378:
    // nop
    // nop
    ctx.pc = 0x02643BB0u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
L_089DD380:
    // nop
    // nop
    // nop
    goto L_089DD38C;
L_089DD38C:
    // nop
    ctx.pc = 0x02648500u; (void)rt.invoke_chained_call(ctx, &aot_mem); return;
}

void recomp_unit_0014(Runtime &rt, AllegrexContext &ctx) {
    auto aot_mem = rt.memory().aot_fast_view();
    recomp_unit_0014_entry(rt, ctx, 0u, aot_mem);
}

void register_generated_unit_14(Runtime &runtime) {
    runtime.register_generated_unit(14u, 0x089C4040u, 131072u, &recomp_unit_0014, &recomp_unit_0014_entry);
    runtime.register_function(0x089C4044u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C4050u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C408Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C4094u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C409Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C40FCu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C4104u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C410Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C4114u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C411Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C4124u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C412Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C4130u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C4148u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C4158u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C4168u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C4174u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C419Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C41C4u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C41D4u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C41E0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C4208u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C422Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C4240u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C4248u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C4258u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C426Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C4298u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C42B4u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C43D8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C43ECu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C4400u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C4420u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C442Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C4448u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C4454u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C4470u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C44B0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C44D0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C4504u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C4520u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C452Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C4548u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C4578u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C4580u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C4588u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C4590u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C4598u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C45A0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C45A8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C45C8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C46FCu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C47BCu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C48D0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C4A08u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C4AA4u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C4AFCu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C4B34u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C4B3Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C4BB0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C4C4Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C4C54u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C4C8Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C4CB8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C4CCCu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C4D04u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C4D44u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C4D7Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5468u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C54A0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C54D8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5508u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5528u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5540u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5550u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5560u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5570u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C55A8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C55E0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C55F8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5630u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5650u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5688u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C56C0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C56E0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5700u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5718u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5730u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5770u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5778u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5780u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5788u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5790u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5798u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C57A0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C57A8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C57B0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C57B8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C57C0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C57C8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C57D0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C57D8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C57E0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C57E8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C57F0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C57F8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5800u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5808u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5810u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5818u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5820u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5828u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5830u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5838u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5858u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5860u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5868u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5870u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5878u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5880u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5888u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5890u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5898u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C58A0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C58A8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C58C0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C58C8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C58D0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C58E0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C58E8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C58F0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C58F8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5900u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5908u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5910u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5918u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5928u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5930u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5938u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5940u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5948u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5950u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5958u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5960u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5968u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5970u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5978u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5980u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5988u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5990u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5998u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C59A0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C59A8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C59B0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C59B8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C59C0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C59C8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C59D0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C59D8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C59E0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C59E8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C59F0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C59F8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5A08u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5A10u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5A18u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5A20u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5A28u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5A30u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5A38u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5A40u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5A48u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5A50u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5A58u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5A60u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5A70u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5A78u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5A80u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5A90u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5A98u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5AA0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5AA8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5AB0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5AB8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5AC0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5AC8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5AD0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5AD8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5AE0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5AE8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5AF0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5AF8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5B00u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5B08u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5B10u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5B18u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5B20u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5B28u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5B30u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5B38u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5B40u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5B48u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5B50u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5B58u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5B60u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5B68u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5B70u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5B78u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5B80u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5B88u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5B90u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5B98u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5BA0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5BA8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5BB0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5BB8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5BC0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5BC8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5BD0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5BD8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5BE0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5C00u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5C08u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5C10u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5C18u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5C20u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5C30u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5C38u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5C40u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5C48u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5C50u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5C60u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5C70u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5C88u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5C98u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5CA0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5CB8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5CC0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5CC8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5CD0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5CD8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5CE0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5CE8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5CF0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5CF8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5D00u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5D08u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5D18u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5D20u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5D30u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5D38u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5D48u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5D50u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5D58u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5D60u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5D68u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5D70u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5D78u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5D80u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5D88u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5D90u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5D98u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5DA0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5DA8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5DB0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5DB8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5DC0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5DC8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5DD0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5DD8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5DE0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5E00u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5E10u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5E18u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5E20u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5E30u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5E38u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5E40u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5E48u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5E50u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5E58u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5E60u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5E68u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5E70u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5E78u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5E80u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5E88u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5E90u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5E98u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5EA0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5EA8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5EB0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5EB8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5EC8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5ED0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5ED8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5EE0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5EE8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5EF0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5EF8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5F00u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5F08u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5F10u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5F18u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5F20u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5F28u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5F30u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5F38u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5F40u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5F48u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5F50u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5F58u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5F60u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5F68u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5F70u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5F78u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5F80u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5F88u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5F90u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5F98u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5FA0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5FA8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5FB0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5FB8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5FC0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5FC8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5FD0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5FD8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5FE0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5FE8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5FF0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C5FF8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C6000u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C6010u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C6018u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C6020u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C6028u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C6030u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C6040u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C6050u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C6058u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C6060u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C6070u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C6078u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C6080u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C6088u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C6090u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C6098u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C60A0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C60A8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C60B0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C63F8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C640Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C645Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C64C0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C64DCu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C6500u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C6548u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C6580u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C65A8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C65B0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C69A8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C69B4u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C6A20u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C6C40u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C6C7Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C6CA8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C6CE0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C6D18u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C6D60u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C6D70u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C6D80u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C6DA0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C6DB0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C6DC0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C6DD0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C6DE0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C6DF0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C6E00u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C6ED4u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C6EDCu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C6EE4u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C6EECu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C6EF4u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C6EFCu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C6F04u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C6F0Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C6F14u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C6F1Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C6F24u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C6F2Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C6F34u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C6F3Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C6F44u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C6F4Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C6F54u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C6F5Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C6F64u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C6F6Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C6F74u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C6F7Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C6F88u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C6FB8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C6FE8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C7030u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C7248u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C74B0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C74C8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C74E8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C74ECu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C74F8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C7510u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C7520u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C7530u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C7548u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C7558u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C7568u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C7578u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C7588u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C7598u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C75A8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C75B8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C75C8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C75D8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C75E8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C75F8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C7608u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C7618u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C7638u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C7650u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C7668u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C7680u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C7690u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C76A8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C78C0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C78D0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C7C48u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C7C78u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C7FECu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C8148u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C8150u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C86A0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C86A8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C86B0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C86C0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C86C8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C86DCu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C86E4u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C86F8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C8700u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C8710u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C8718u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C872Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C8734u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C8750u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C8758u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C876Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C8774u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C8788u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C8790u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C87B0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C87B8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C87C8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C87D0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C87E0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C87E8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C87FCu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C8808u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C8814u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C8820u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C8828u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C882Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C8838u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C8850u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C8858u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C8878u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C8898u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C88A0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C88A8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C88ACu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C88B8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C88C0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C88CCu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C88D8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C88E4u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C8908u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C8924u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C892Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C8944u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C8948u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C8950u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C8958u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C8960u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C8968u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C8970u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C8978u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C8980u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C8988u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C8990u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C8998u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C89A0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C89A8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C89B0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C89B8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C8A00u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C8A74u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C8A80u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C8AD8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C8D3Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C8D40u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C8D44u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C8D8Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C8D94u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C8DC4u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C8E10u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C8E28u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C8E60u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C8ED8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C8EE0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C8EE8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C8EF0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C8EF8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C8F08u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C8F10u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C8F1Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C8F24u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C8F2Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C8F34u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C8F48u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C8F54u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C8F5Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C8F64u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C8F6Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C8F78u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C8F88u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C8F94u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C8F9Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C8FA8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C8FC0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C8FC8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C8FD4u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C8FDCu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C8FE0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C90F0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C9100u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C9110u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C9118u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C9120u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C912Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C9148u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C9154u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C9168u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C9174u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C9188u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C9298u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C929Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C92A0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C92B0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C92B8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C92C8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C92D0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C92E0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C92E8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C92F8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C9300u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C9310u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C9318u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C9330u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C9344u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C9348u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C9370u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C937Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C9390u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C9398u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C93A0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C93B0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C93B8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C93C8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C93D0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C93E0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C93E8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C93F0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C93F4u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C93FCu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C9424u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C942Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C955Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C9560u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C9564u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C9574u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C9584u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C9594u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C9598u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C959Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C95A4u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C95ACu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C95B8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C95C0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C95C8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C95CCu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C95E0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C95E8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C9600u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C9614u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C9628u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C9634u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C963Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C9650u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C965Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C9664u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C966Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C9674u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C967Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C9680u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C96B0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C96E8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C9738u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C9740u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C9888u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C98E4u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C98E8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C9AC8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C9AD0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C9AFCu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C9B00u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C9B50u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C9B6Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C9B88u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C9BACu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C9BB8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C9BC8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C9BD4u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C9BE0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C9BE8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C9BF0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C9BF8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C9C04u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C9C38u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C9C48u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C9C50u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C9C54u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C9C5Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C9C70u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C9D30u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C9D40u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C9D48u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C9D58u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C9D6Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C9DACu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C9DB4u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C9DBCu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C9DC4u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C9DCCu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C9DD4u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C9DD8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C9DE0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C9DE8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C9DF4u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C9DFCu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C9E08u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C9E10u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C9EC0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C9EC8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C9ED0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C9ED8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C9EE0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C9EE8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C9F00u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C9F14u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C9F20u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C9F34u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C9F38u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C9F58u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C9F64u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C9F70u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C9F88u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C9FA0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C9FB8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C9FC4u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C9FD8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089C9FE8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CA004u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CA0C0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CA0C4u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CA0C8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CA0E0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CA0ECu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CA100u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CA10Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CA11Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CA128u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CA134u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CA13Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CA148u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CA154u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CA15Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CA160u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CA16Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CA17Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CA188u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CA194u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CA19Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CA1B0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CA1B8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CA1D0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CA1D8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CA1F0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CA1F8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CA20Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CA224u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CA23Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CA258u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CA260u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CA26Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CA274u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CA280u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CA298u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CA2B8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CA2D8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CA2F4u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CA304u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CA310u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CA320u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CA32Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CA334u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CA34Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CA354u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CA364u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CA36Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CA380u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CA388u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CA398u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CA3A0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CA3B4u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CA3C4u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CA3D0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CA3E0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CA3E8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CA3F0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CA3FCu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CA418u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CA430u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CA434u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CA44Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CA464u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CA470u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CA488u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CA4A4u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CA4A8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CA4B0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CA4B8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CA4C4u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CA4DCu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CA4E8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CA580u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CA59Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CA5A4u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CA5B0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CA5F8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CA600u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CA638u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CA670u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CA6A8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CA6E0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CA720u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CA730u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CA740u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CA748u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CA758u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CA768u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CA778u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CA77Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CA788u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CA78Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CA790u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CA798u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CA7A8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CA7ACu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CA7B0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CA7B8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CA7C8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CA7D8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CA7F0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CA804u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CA814u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CA820u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CA82Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CA868u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CA878u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CA884u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CA888u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CA890u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CA8B0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CA8D0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CA8D8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CA8F0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CA8F8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CA910u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CA918u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CA920u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CA928u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CA938u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CA940u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CA948u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CA954u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CA95Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CAA10u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CAAB0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CAAB8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CAAC4u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CAACCu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CAAD0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CAB04u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CAB10u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CAB14u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CAB18u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CAB28u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CAB38u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CAB50u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CAB58u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CAB60u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CAB68u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CAB70u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CAB80u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CAB88u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CAB94u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CABA0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CABB8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CABD0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CABE0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CABF8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CAC10u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CAC20u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CAC38u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CAC90u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CACE8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CAE48u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CAE58u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CAE70u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CAE7Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CAE8Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CAEA8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CAEB8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CAECCu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CAEF8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CAF0Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CAF18u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CAF24u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CAF28u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CAF38u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CAF58u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CAF68u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CAF78u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CAF94u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CAFB0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CAFCCu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CAFE8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CB004u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CB020u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CB03Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CB05Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CB104u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CB188u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CB1B0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CB1F8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CB228u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CB238u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CB248u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CB290u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CB298u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CB2ACu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CB2C4u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CB2D4u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CB2E8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CB2F8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CB314u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CB334u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CB354u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CB358u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CB360u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CB36Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CB3BCu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CB3D8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CB3E8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CB3F0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CB3FCu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CB408u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CB410u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CB428u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CB434u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CB480u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CB488u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CB494u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CB4A4u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CB4B4u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CB4C4u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CB4CCu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CB4D4u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CB538u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CB650u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CB680u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CB6E8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CB6F8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CB700u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CB708u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CB718u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CB724u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CB728u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CB72Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CB740u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CB758u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CB760u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CB768u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CB770u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CB774u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CB778u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CB788u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CB7A0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CB7B0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CB7C8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CB7E8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CB898u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CB8A0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CB8A8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CB8B0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CB8B8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CB8C0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CB8C8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CB8D0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CB8D8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CB8E0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CB8E8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CB8F0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CB8F8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CB900u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CB908u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CB910u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CB918u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CB920u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CB928u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CB930u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CB938u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CB940u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CB948u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CB950u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CB958u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CB960u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CB968u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CB970u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CB978u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CB980u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CB988u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CB990u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CB998u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CB9A0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CB9A8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CB9B0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CB9B8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CB9C0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CB9C8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CB9D0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CB9D8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CB9E0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CB9E8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CB9ECu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CB9F8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CBA00u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CBA0Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CBA18u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CBA28u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CBA38u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CBA50u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CBA68u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CBA70u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CBA78u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CBA80u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CBA88u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CBA94u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CBAB0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CBB70u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CBB7Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CBB9Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CBBECu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CBC38u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CBC58u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CBC98u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CBCA0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CBCA8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CBCB0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CBCB8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CBCC8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CBCE0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CBCF4u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CBD04u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CBD10u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CBD24u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CBD2Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CBD50u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CBD74u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CBD84u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CBD90u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CBDA4u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CBDB0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CBDBCu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CBDC8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CBDD4u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CBDDCu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CBDE4u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CBDECu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CBDF4u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CBE00u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CBE08u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CBE10u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CBE14u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CBE1Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CBE24u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CBE2Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CBE40u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CBE48u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CBE50u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CBE60u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CBF04u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CC00Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CC020u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CC0A4u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CC0B0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CC0C0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CC0C8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CC0D8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CC0F0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CC110u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CC128u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CC148u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CC160u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CC180u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CC188u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CC1C0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CC1D8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CC1E8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CC200u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CC204u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CC21Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CC220u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CC238u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CC240u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CC250u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CC268u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CC270u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CC290u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CC2A0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CC2A8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CC2B8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CC2C0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CC2C8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CC2D0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CC2E0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CC2E8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CC2F0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CC2F8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CC308u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CC330u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CC348u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CC358u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CC37Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CC384u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CC4A0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CC538u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CC548u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CC568u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CC58Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CC59Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CC5A8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CC5ACu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CC5B4u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CC610u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CC710u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CC72Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CC738u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CC7A0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CC7B0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CC7B8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CC7CCu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CC7D4u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CC7E0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CC7F0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CC800u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CC808u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CC810u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CC820u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CC834u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CC840u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CC84Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CC85Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CC870u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CC878u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CC884u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CC898u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CC8A0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CC8ACu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CC8C4u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CC8CCu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CC8D8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CC8F0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CC8F8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CC904u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CC918u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CC92Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CC934u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CC93Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CC950u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CC958u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CC95Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CC964u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CC970u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CC97Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CC9A8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CC9B8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CC9C8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CC9D8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CC9E8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CC9F8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CCA0Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CCA28u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CCA60u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CCA6Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CCA74u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CCA7Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CCA98u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CCAA4u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CCAACu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CCAB4u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CCAD0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CCB08u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CCB48u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CCB54u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CCB80u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CCB90u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CCBB8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CCBC0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CCBDCu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CCBE4u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CCBFCu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CCC04u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CCC0Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CCC14u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CCC1Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CCC2Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CCC34u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CCC44u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CCC4Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CCC70u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CCC88u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CCCF8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CCD20u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CCD30u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CCD70u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CCDB8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CCDC8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CCE20u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CCE28u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CCE38u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CCE68u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CCE9Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CCEBCu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CCF44u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CCFACu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CCFD4u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CD03Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CD048u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CD050u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CD06Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CD070u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CD1FCu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CD220u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CD258u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CD2B0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CD2D4u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CD314u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CD328u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CD408u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CD410u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CD420u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CD434u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CD448u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CD45Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CD470u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CD484u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CD498u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CD4ACu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CD4C0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CD4D4u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CD4E8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CD4FCu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CD510u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CD524u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CD538u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CD54Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CD560u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CD574u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CD588u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CD59Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CD5B0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CD5C4u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CD5D8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CD5ECu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CD600u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CD614u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CD628u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CD63Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CD65Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CD66Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CD68Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CD694u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CD72Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CD74Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CD75Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CD790u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CD858u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CD880u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CD8D0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CD90Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CD9D8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CD9F8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CDA18u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CDA20u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CDA28u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CDA50u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CDA60u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CDA70u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CDA80u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CDA98u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CDAA8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CDB18u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CDB28u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CDB70u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CDBC0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CDBE0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CDC40u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CDCA0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CDCC0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CDD18u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CDD30u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CDD60u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CDD78u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CDD88u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CDE50u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CDF18u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CE038u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CE040u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CE060u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CE068u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CE070u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CE078u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CE084u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CE08Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CE094u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CE09Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CE0A4u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CE0ACu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CE0B4u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CE0BCu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CE0C4u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CE0CCu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CE0D4u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CE0F8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CE138u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CE140u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CE154u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CE15Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CE168u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CE178u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CE188u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CE190u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CE198u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CE1A0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CE1A8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CE1B4u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CE1C0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CE1D0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CE1E8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CE200u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CE230u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CE244u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CE250u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CE3B0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CE3C4u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CE3D0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CE3D4u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CE3E4u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CE3E8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CE3F8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CE400u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CE40Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CE418u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CE424u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CE460u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CE468u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CE474u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CE488u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CE490u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CE49Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CE4B4u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CE4BCu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CE4C8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CE4E0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CE4E8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CE4F4u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CE508u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CE51Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CE524u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CE52Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CE540u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CE548u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CE54Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CE554u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CE560u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CE56Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CE580u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CE594u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CE5ACu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CE5BCu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CE620u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CE630u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CE640u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CE650u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CE690u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CE698u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CE6A0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CE6ACu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CE6B0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CE6D4u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CE6DCu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CE700u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CE708u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CE730u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CE738u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CE74Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CE768u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CE76Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CE780u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CE7C0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CE7D4u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CE7DCu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CE7E0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CE878u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CE894u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CEA88u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CEA90u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CEA9Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CEAA4u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CEAC0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CEAC8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CEAE0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CEAECu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CEB58u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CEB60u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CEB64u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CEB78u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CEB80u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CEB88u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CEBE0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CEBE8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CEBF0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CEBFCu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CEC00u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CEC50u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CEC58u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CECA0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CECC8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CECE0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CECF8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CED1Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CED38u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CED80u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CED98u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CEDA8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CEDF0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CEE20u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CEE68u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CEE88u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CEE90u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CEEE0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CEF30u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CEF48u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CEF60u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CEF68u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CEFF0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CF000u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CF010u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CF058u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CF080u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CF090u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CF0A0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CF0D0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CF0F0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CF138u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CF148u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CF158u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CF1A0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CF1B8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CF1CCu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CF1DCu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CF200u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CF230u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CF260u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CF290u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CF2D8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CF2E8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CF308u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CF340u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CF350u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CF3DCu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CF3E8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CF3F8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CF400u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CF420u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CF434u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CF448u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CF470u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CF494u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CF49Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CF4A0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CF4B8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CF4C0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CF4D4u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CF4E8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CF4FCu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CF508u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CF510u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CF518u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CF530u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CF55Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CF580u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CF584u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CF590u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CF5B8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CF5C0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CF5D0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CF5F4u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CF614u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CF6A0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CF6B0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CF6D8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CF6E8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CF6F8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CF70Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CF714u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CF728u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CF970u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CF980u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CF990u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CF9A4u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CF9ACu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CF9C0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CFB70u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CFB84u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CFBC0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CFBE0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CFC00u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CFC24u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CFC34u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CFC58u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CFE90u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CFEB0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CFED0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CFEF4u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CFF04u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089CFF28u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D0000u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D00D0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D0128u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D0158u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D0170u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D0198u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D01A0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D01A8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D01B8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D01C8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D01D4u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D0200u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D0214u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D022Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D02C0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D04F0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D05DCu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D0628u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D0648u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D0660u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D066Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D067Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D0908u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D091Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D0928u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D0988u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D0990u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D0998u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D09B4u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D09BCu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D09D0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D09D8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D09E0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D09E4u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D0A04u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D0A08u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D0A18u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D0A1Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D0A24u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D0A2Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D0A34u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D0A3Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D0A44u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D0A54u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D0A60u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D0A6Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D0A78u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D0A80u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D0A84u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D0A90u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D0A98u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D0AA0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D0AA8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D0AB4u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D0ABCu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D0AE8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D0B0Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D0B1Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D0B20u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D0B34u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D0B6Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D0BA0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D0BE4u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D0C04u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D0C28u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D0C40u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D0C5Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D0C94u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D0CF8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D0D28u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D0D38u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D0D50u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D0D60u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D0D70u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D0D80u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D0DD8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D0DF8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D0E00u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D0E30u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D0E50u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D0E80u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D0E98u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D0ED4u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D0F30u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D0FA0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D1044u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D1048u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D104Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D1050u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D1054u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D1058u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D107Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D1088u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D1098u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D1120u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D1128u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D1130u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D1138u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D1140u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D1170u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D11E0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D11F8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D131Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D13C0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D13D0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D13E0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D1454u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D14C8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D14E0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D14F8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D1508u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D1510u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D1520u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D1524u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D1528u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D152Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D1530u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D1534u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D1538u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D153Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D1540u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D1544u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D1548u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D154Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D1550u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D1554u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D1558u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D15DCu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D15E0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D15ECu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D15F0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D1600u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D1604u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D1608u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D160Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D1610u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D1614u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D1618u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D161Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D1620u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D1624u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D1628u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D162Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D1630u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D1634u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D1830u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D1860u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D18CCu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D18E0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D18F4u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D18F8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D18FCu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D1900u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D1904u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D1908u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D190Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D1910u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D1914u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D1918u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D191Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D1920u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D1924u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D1928u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D192Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D1930u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D1934u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D1938u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D193Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D1940u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D1944u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D1948u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D194Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D19CCu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D1C80u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D1CA8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D1CF0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D1D00u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D1D08u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D1D10u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D1D14u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D1E00u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D1E14u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D1E1Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D1E24u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D1E34u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D1E3Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D1E54u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D1EACu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D1EB4u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D1ECCu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D1ED4u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D1EDCu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D1EE4u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D1F00u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D1F0Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D1F14u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D1F74u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D1F7Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D1F88u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D1F94u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D1FA0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D1FB4u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D2084u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D2130u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D2144u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D216Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D21B8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D21BCu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D21C0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D21E0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D21ECu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D21F8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D2204u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D2210u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D221Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D2228u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D2250u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D2264u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D22E4u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D22F4u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D2330u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D2338u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D235Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D2640u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D2650u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D2660u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D2690u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D26A8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D26ECu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D26F4u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D2748u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D2770u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D2784u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D2794u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D27ACu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D27C4u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D27D4u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D2800u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D2808u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D280Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D291Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D2A18u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D35FCu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D3630u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D3650u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D4320u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D4750u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D4754u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D4770u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D47B0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D48C0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D4900u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D4948u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D4978u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D4D84u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D4DD0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D4E38u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D4E3Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D4E48u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D4E80u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D4E84u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D530Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D5324u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D536Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D5384u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D53A0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D53B8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D53C0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D53F8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D5400u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D5404u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D540Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D5414u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D5424u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D5434u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D5444u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D545Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D5474u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D5480u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D5488u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D54C4u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D54D8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D550Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D5540u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D5548u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D5558u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D5564u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D556Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D5578u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D5588u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D55CCu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D55E4u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D55F0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D55F8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D5600u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D562Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D5640u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D5654u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D565Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D5678u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D56B4u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D56C0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D56ECu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D56FCu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D570Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D5748u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D5778u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D5788u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D57A0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D57D4u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D57F4u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D5838u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D5EA8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D5ED0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D5EF4u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D5F30u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D5FF8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D6018u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D6050u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D6090u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D60D0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D6110u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D6114u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D6118u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D618Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D6190u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D6264u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D6268u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D63A0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D63ACu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D63B8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D63C4u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D63D0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D63DCu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D63E8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D63F4u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D6400u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D640Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D6418u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D6424u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D6430u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D643Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D6448u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D6454u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D6460u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D646Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D6478u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D6484u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D6490u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D649Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D64A8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D64B4u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D64C0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D64CCu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D64D8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D64E4u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D64F0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D64FCu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D6508u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D6514u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D6520u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D652Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D6538u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D6544u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D6550u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D655Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D6568u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D6574u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D6580u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D658Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D6598u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D65A4u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D65B0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D65BCu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D65C8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D65D4u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D65E0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D65ECu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D65F8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D6604u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D6610u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D661Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D6628u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D6634u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D6640u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D664Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D6658u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D6664u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D6670u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D667Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D6688u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D6694u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D66A0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D66ACu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D66B8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D66C4u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D66D0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D66DCu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D66E8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D66F4u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D6700u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D670Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D6718u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D6724u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D6730u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D673Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D6748u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D6754u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D6760u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D676Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D6778u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D6784u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D6790u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D679Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D67A8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D67B4u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D67C0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D67CCu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D67D8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D67E4u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D67F0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D67FCu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D6808u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D6814u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D6820u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D682Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D6838u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D6844u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D6850u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D685Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D6868u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D6874u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D6880u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D688Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D6898u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D68D0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D68D8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D68E0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D68F0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D6904u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D6914u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D6924u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D6960u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D6964u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D6970u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D6988u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D6A18u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D6A48u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D6A98u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D6AB0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D6AF8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D6BF8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D6BFCu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D6C18u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D6C20u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D6CA8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D6D3Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D6D98u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D6DB8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D6DDCu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D6DE8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D6F58u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D70FCu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D7130u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D7140u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D7270u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D7298u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D72C4u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D72D0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D7390u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D739Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D73C0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D7418u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D7424u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D7440u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D7490u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D74E0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D7758u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D7820u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D7838u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D79E8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D7A10u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D7A30u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D7BE0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D7CD4u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D7DFCu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D7E8Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D7ED8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D7F00u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D7F48u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D7F58u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D7F6Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D7FA0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D7FC8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D8018u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D8088u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D80B8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D80D0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D8150u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D81B8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D8220u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D8250u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D8280u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D82B0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D82E0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D8320u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D83E0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D8408u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D84B8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D84D8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D84ECu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D8540u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D8568u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D8598u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D85A4u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D85A8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D85C4u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D85D0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D85DCu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D886Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D88E8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D8920u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D8978u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D8A88u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D8A98u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D8D74u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D8DA8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D8DC8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D8DF4u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D8F78u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D8FE8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D9000u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D900Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D901Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D9038u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D9040u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D9050u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D906Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D9090u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D90ACu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D90C8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D90F0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D9108u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D9120u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D9140u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D914Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D9180u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D9190u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D91D0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D91E0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D91F0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D9204u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D9218u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D9278u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D9290u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D92BCu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D92F0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D9300u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D9310u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D9324u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D9340u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D93F8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D945Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D94E8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D9544u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D95D0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D99E0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D9A88u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D9A98u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D9AF8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D9B30u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D9B50u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D9B58u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D9B68u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D9B70u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D9BB8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D9FB0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D9FC0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D9FD0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D9FE0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089D9FF0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DA000u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DA00Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DA010u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DA020u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DA060u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DA070u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DA080u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DA090u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DA0A0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DA0B0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DA0C0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DA0C8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DA0D4u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DA0D8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DA0E0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DA0E8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DA0F0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DA0F8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DA100u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DA108u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DA110u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DA118u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DA130u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DA170u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DA1F0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DA28Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DA298u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DA2C0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DA2E4u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DA2F0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DA2FCu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DA308u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DA340u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DA350u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DA360u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DA370u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DA3B0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DA3C0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DA400u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DA410u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DA4C0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DA4CCu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DA4D8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DA69Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DA6CCu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DA6E8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DA708u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DA728u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DA74Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DA774u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DA8D0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DA8D8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DA8E8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DA900u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DA930u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DAA38u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DAA58u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DAA68u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DAAC4u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DAE00u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DAE08u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DAE28u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DAE48u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DAE58u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DAE68u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DAE7Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DAEE8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DAF30u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DAF84u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DAFC0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DB014u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DB028u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DB030u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DB090u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DB0D0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DB0E0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DB130u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DB180u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DB1B8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DB1D0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DB220u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DB270u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DB2C0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DB310u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DB314u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DB360u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DB3B0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DB400u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DB450u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DB4A0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DB4F0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DB540u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DB590u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DB5E0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DB618u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DB630u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DB680u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DB6D0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DB720u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DB770u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DB7C0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DB810u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DB860u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DB8B0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DB900u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DB950u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DB9A0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DB9F0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DBA40u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DBA7Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DBA90u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DBAD4u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DBAE0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DBAECu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DBB30u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DBB80u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DBBD0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DBC20u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DBC70u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DBCA4u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DBCC0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DBD10u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DBD60u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DBDB0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DBE00u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DBE50u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DBE70u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DBEA0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DBEF0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DBF40u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DBF48u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DBF50u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DBF60u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DBF70u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DBF90u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DBFC0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DBFD8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DC008u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DC020u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DC050u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DC068u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DC0B8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DC0F4u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DC108u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DC158u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DC1A8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DC1E8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DC1F8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DC238u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DC248u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DC28Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DC298u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DC2E8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DC338u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DC388u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DC3D8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DC428u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DC478u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DC4C8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DC4E8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DC508u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DC528u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DC548u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DC568u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DC57Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DC5B8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DC608u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DC658u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DC6A8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DC6F8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DC748u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DC798u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DC7CCu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DC7E4u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DC7E8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DC7FCu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DC814u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DC82Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DC838u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DC888u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DC8D8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DC928u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DC960u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DC9C8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DCA30u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DCA98u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DCAE8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DCB38u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DCB88u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DCBD8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DCC28u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DCC78u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DCCC8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DCD0Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DCD18u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DCD68u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DCDB4u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DCDB8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DCDDCu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DCE08u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DCE34u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DCE58u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DCEA8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DCEF8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DCF48u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DCF98u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DCFE8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DD038u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DD088u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DD0D8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DD0F0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DD108u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DD120u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DD170u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DD1C0u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DD210u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DD230u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DD250u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DD270u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DD2A8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DD2C8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DD2E8u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DD308u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DD30Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DD31Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DD320u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DD338u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DD34Cu, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DD370u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DD378u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DD380u, &recomp_unit_0014, "recomp_unit_0014");
    runtime.register_function(0x089DD38Cu, &recomp_unit_0014, "recomp_unit_0014");
}
} // namespace psprecomp
