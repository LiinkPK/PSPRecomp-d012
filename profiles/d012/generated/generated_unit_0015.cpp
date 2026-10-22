#include "psprecomp/runtime.hpp"
#include <bit>
#include <cmath>
#include <cstdint>
#include <limits>

namespace psprecomp {
static const std::uint16_t kEntryIds_recomp_unit_0015[660] = {
    1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32,
    33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64,
    65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96,
    97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128,
    129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 0, 139, 140, 141, 0, 142, 143, 0, 144, 145, 146, 147, 0, 148, 149, 0, 150, 151, 0, 152, 153, 154,
    155, 156, 0, 157, 158, 159, 0, 160, 161, 0, 162, 163, 164, 165, 166, 0, 167, 168, 169, 0, 170, 171, 0, 172, 173, 174, 175, 176, 0, 177, 178, 179,
    0, 180, 181, 0, 182, 183, 184, 185, 186, 187, 0, 188, 189, 190, 0, 191, 192, 0, 193, 194, 195, 196, 197, 0, 198, 199, 200, 0, 201, 202, 0, 203,
    204, 205, 206, 207, 0, 208, 209, 210, 0, 211, 212, 0, 213, 214, 215, 216, 217, 0, 218, 219, 220, 0, 221, 222, 0, 223, 224, 225, 226, 227, 0, 228,
    229, 230, 0, 231, 232, 0, 233, 234, 235, 236, 237, 0, 238, 239, 240, 0, 241, 242, 0, 243, 244, 245, 246, 247, 0, 248, 249, 250, 0, 251, 252, 0,
    253, 254, 255, 256, 257, 0, 258, 259, 260, 0, 261, 262, 0, 263, 264, 265, 266, 267, 0, 268, 269, 270, 0, 271, 272, 0, 273, 274, 275, 276, 277, 0,
    278, 279, 280, 0, 281, 282, 0, 283, 284, 285, 286, 287, 0, 288, 289, 290, 0, 291, 292, 0, 293, 294, 295, 296, 297, 0, 298, 299, 300, 0, 301, 302,
    0, 303, 304, 305, 306, 307, 0, 308, 309, 310, 0, 311, 312, 0, 313, 314, 315, 316, 317, 0, 318, 319, 320, 0, 321, 322, 0, 323, 324, 325, 326, 327,
    0, 328, 329, 330, 0, 331, 332, 0, 333, 334, 335, 336, 337, 0, 338, 339, 340, 0, 341, 342, 343, 344, 345, 0, 346, 347, 348, 0, 349, 350, 0, 351,
    352, 353, 354, 355, 0, 356, 357, 358, 0, 359, 360, 0, 361, 362, 363, 364, 365, 0, 366, 367, 368, 0, 369, 370, 0, 371, 372, 373, 374, 375, 0, 376,
    377, 378, 0, 379, 380, 0, 381, 382, 383, 384, 385, 0, 386, 387, 388, 0, 389, 390, 0, 391, 392, 393, 394, 395, 0, 396, 397, 398, 0, 399, 400, 401,
    402, 403, 0, 404, 405, 406, 0, 407, 408, 0, 409, 410, 411, 412, 413, 0, 414, 415, 416, 0, 417, 418, 0, 419, 420, 421, 422, 423, 0, 424, 425, 426,
    0, 427, 428, 429, 430, 431, 0, 432, 433, 434, 0, 435, 436, 437, 438, 439, 0, 440, 441, 442, 0, 443, 444, 445, 446, 447, 0, 448, 449, 450, 0, 451,
    452, 453, 454, 455, 0, 456, 457, 458, 0, 459, 460, 461, 462, 463, 0, 464, 465, 466, 0, 467, 468, 0, 469, 470, 471, 472, 473, 0, 474, 475, 0, 476,
    477, 0, 478, 479, 480, 481, 482, 0, 483, 484, 0, 485, 486, 0, 487, 488, 489, 490, 491, 0, 492, 493, 0, 494, 495, 0, 496, 497, 498, 499, 500, 0,
    501, 502, 0, 503, 504, 0, 505, 506, 507, 508, 509, 0, 510, 511, 0, 512, 513, 0, 514, 515, 516, 517, 518, 0, 519, 520, 0, 521, 522, 523, 524, 525,
    0, 526, 527, 0, 528, 529, 0, 530, 531, 532, 533, 534, 535, 536, 537, 538, 539, 540, 541, 542,
};
void recomp_unit_0015_entry(Runtime &rt, AllegrexContext &ctx, std::uint16_t direct_entry_id, GuestMemory::AotFastView &aot_mem) {
    std::uint32_t jump_target = 0u;
    std::uint32_t local_transfers = 0u;
    std::uint32_t local_pc = ctx.pc;
    std::uint32_t entry_id = direct_entry_id;
LOCAL_DISPATCH:
    {
    if (entry_id == 0u) {
        const std::uint32_t entry_delta = local_pc - 0x0887801Cu;
        entry_id = (entry_delta < 2640u && (entry_delta & 3u) == 0u) ? kEntryIds_recomp_unit_0015[entry_delta >> 2u] : 0u;
    }
    switch (entry_id) {
    case 1u: goto L_0887801C;
    case 2u: goto L_08878020;
    case 3u: goto L_08878024;
    case 4u: goto L_08878028;
    case 5u: goto L_0887802C;
    case 6u: goto L_08878030;
    case 7u: goto L_08878034;
    case 8u: goto L_08878038;
    case 9u: goto L_0887803C;
    case 10u: goto L_08878040;
    case 11u: goto L_08878044;
    case 12u: goto L_08878048;
    case 13u: goto L_0887804C;
    case 14u: goto L_08878050;
    case 15u: goto L_08878054;
    case 16u: goto L_08878058;
    case 17u: goto L_0887805C;
    case 18u: goto L_08878060;
    case 19u: goto L_08878064;
    case 20u: goto L_08878068;
    case 21u: goto L_0887806C;
    case 22u: goto L_08878070;
    case 23u: goto L_08878074;
    case 24u: goto L_08878078;
    case 25u: goto L_0887807C;
    case 26u: goto L_08878080;
    case 27u: goto L_08878084;
    case 28u: goto L_08878088;
    case 29u: goto L_0887808C;
    case 30u: goto L_08878090;
    case 31u: goto L_08878094;
    case 32u: goto L_08878098;
    case 33u: goto L_0887809C;
    case 34u: goto L_088780A0;
    case 35u: goto L_088780A4;
    case 36u: goto L_088780A8;
    case 37u: goto L_088780AC;
    case 38u: goto L_088780B0;
    case 39u: goto L_088780B4;
    case 40u: goto L_088780B8;
    case 41u: goto L_088780BC;
    case 42u: goto L_088780C0;
    case 43u: goto L_088780C4;
    case 44u: goto L_088780C8;
    case 45u: goto L_088780CC;
    case 46u: goto L_088780D0;
    case 47u: goto L_088780D4;
    case 48u: goto L_088780D8;
    case 49u: goto L_088780DC;
    case 50u: goto L_088780E0;
    case 51u: goto L_088780E4;
    case 52u: goto L_088780E8;
    case 53u: goto L_088780EC;
    case 54u: goto L_088780F0;
    case 55u: goto L_088780F4;
    case 56u: goto L_088780F8;
    case 57u: goto L_088780FC;
    case 58u: goto L_08878100;
    case 59u: goto L_08878104;
    case 60u: goto L_08878108;
    case 61u: goto L_0887810C;
    case 62u: goto L_08878110;
    case 63u: goto L_08878114;
    case 64u: goto L_08878118;
    case 65u: goto L_0887811C;
    case 66u: goto L_08878120;
    case 67u: goto L_08878124;
    case 68u: goto L_08878128;
    case 69u: goto L_0887812C;
    case 70u: goto L_08878130;
    case 71u: goto L_08878134;
    case 72u: goto L_08878138;
    case 73u: goto L_0887813C;
    case 74u: goto L_08878140;
    case 75u: goto L_08878144;
    case 76u: goto L_08878148;
    case 77u: goto L_0887814C;
    case 78u: goto L_08878150;
    case 79u: goto L_08878154;
    case 80u: goto L_08878158;
    case 81u: goto L_0887815C;
    case 82u: goto L_08878160;
    case 83u: goto L_08878164;
    case 84u: goto L_08878168;
    case 85u: goto L_0887816C;
    case 86u: goto L_08878170;
    case 87u: goto L_08878174;
    case 88u: goto L_08878178;
    case 89u: goto L_0887817C;
    case 90u: goto L_08878180;
    case 91u: goto L_08878184;
    case 92u: goto L_08878188;
    case 93u: goto L_0887818C;
    case 94u: goto L_08878190;
    case 95u: goto L_08878194;
    case 96u: goto L_08878198;
    case 97u: goto L_0887819C;
    case 98u: goto L_088781A0;
    case 99u: goto L_088781A4;
    case 100u: goto L_088781A8;
    case 101u: goto L_088781AC;
    case 102u: goto L_088781B0;
    case 103u: goto L_088781B4;
    case 104u: goto L_088781B8;
    case 105u: goto L_088781BC;
    case 106u: goto L_088781C0;
    case 107u: goto L_088781C4;
    case 108u: goto L_088781C8;
    case 109u: goto L_088781CC;
    case 110u: goto L_088781D0;
    case 111u: goto L_088781D4;
    case 112u: goto L_088781D8;
    case 113u: goto L_088781DC;
    case 114u: goto L_088781E0;
    case 115u: goto L_088781E4;
    case 116u: goto L_088781E8;
    case 117u: goto L_088781EC;
    case 118u: goto L_088781F0;
    case 119u: goto L_088781F4;
    case 120u: goto L_088781F8;
    case 121u: goto L_088781FC;
    case 122u: goto L_08878200;
    case 123u: goto L_08878204;
    case 124u: goto L_08878208;
    case 125u: goto L_0887820C;
    case 126u: goto L_08878210;
    case 127u: goto L_08878214;
    case 128u: goto L_08878218;
    case 129u: goto L_0887821C;
    case 130u: goto L_08878220;
    case 131u: goto L_08878224;
    case 132u: goto L_08878228;
    case 133u: goto L_0887822C;
    case 134u: goto L_08878230;
    case 135u: goto L_08878234;
    case 136u: goto L_08878238;
    case 137u: goto L_0887823C;
    case 138u: goto L_08878240;
    case 139u: goto L_08878248;
    case 140u: goto L_0887824C;
    case 141u: goto L_08878250;
    case 142u: goto L_08878258;
    case 143u: goto L_0887825C;
    case 144u: goto L_08878264;
    case 145u: goto L_08878268;
    case 146u: goto L_0887826C;
    case 147u: goto L_08878270;
    case 148u: goto L_08878278;
    case 149u: goto L_0887827C;
    case 150u: goto L_08878284;
    case 151u: goto L_08878288;
    case 152u: goto L_08878290;
    case 153u: goto L_08878294;
    case 154u: goto L_08878298;
    case 155u: goto L_0887829C;
    case 156u: goto L_088782A0;
    case 157u: goto L_088782A8;
    case 158u: goto L_088782AC;
    case 159u: goto L_088782B0;
    case 160u: goto L_088782B8;
    case 161u: goto L_088782BC;
    case 162u: goto L_088782C4;
    case 163u: goto L_088782C8;
    case 164u: goto L_088782CC;
    case 165u: goto L_088782D0;
    case 166u: goto L_088782D4;
    case 167u: goto L_088782DC;
    case 168u: goto L_088782E0;
    case 169u: goto L_088782E4;
    case 170u: goto L_088782EC;
    case 171u: goto L_088782F0;
    case 172u: goto L_088782F8;
    case 173u: goto L_088782FC;
    case 174u: goto L_08878300;
    case 175u: goto L_08878304;
    case 176u: goto L_08878308;
    case 177u: goto L_08878310;
    case 178u: goto L_08878314;
    case 179u: goto L_08878318;
    case 180u: goto L_08878320;
    case 181u: goto L_08878324;
    case 182u: goto L_0887832C;
    case 183u: goto L_08878330;
    case 184u: goto L_08878334;
    case 185u: goto L_08878338;
    case 186u: goto L_0887833C;
    case 187u: goto L_08878340;
    case 188u: goto L_08878348;
    case 189u: goto L_0887834C;
    case 190u: goto L_08878350;
    case 191u: goto L_08878358;
    case 192u: goto L_0887835C;
    case 193u: goto L_08878364;
    case 194u: goto L_08878368;
    case 195u: goto L_0887836C;
    case 196u: goto L_08878370;
    case 197u: goto L_08878374;
    case 198u: goto L_0887837C;
    case 199u: goto L_08878380;
    case 200u: goto L_08878384;
    case 201u: goto L_0887838C;
    case 202u: goto L_08878390;
    case 203u: goto L_08878398;
    case 204u: goto L_0887839C;
    case 205u: goto L_088783A0;
    case 206u: goto L_088783A4;
    case 207u: goto L_088783A8;
    case 208u: goto L_088783B0;
    case 209u: goto L_088783B4;
    case 210u: goto L_088783B8;
    case 211u: goto L_088783C0;
    case 212u: goto L_088783C4;
    case 213u: goto L_088783CC;
    case 214u: goto L_088783D0;
    case 215u: goto L_088783D4;
    case 216u: goto L_088783D8;
    case 217u: goto L_088783DC;
    case 218u: goto L_088783E4;
    case 219u: goto L_088783E8;
    case 220u: goto L_088783EC;
    case 221u: goto L_088783F4;
    case 222u: goto L_088783F8;
    case 223u: goto L_08878400;
    case 224u: goto L_08878404;
    case 225u: goto L_08878408;
    case 226u: goto L_0887840C;
    case 227u: goto L_08878410;
    case 228u: goto L_08878418;
    case 229u: goto L_0887841C;
    case 230u: goto L_08878420;
    case 231u: goto L_08878428;
    case 232u: goto L_0887842C;
    case 233u: goto L_08878434;
    case 234u: goto L_08878438;
    case 235u: goto L_0887843C;
    case 236u: goto L_08878440;
    case 237u: goto L_08878444;
    case 238u: goto L_0887844C;
    case 239u: goto L_08878450;
    case 240u: goto L_08878454;
    case 241u: goto L_0887845C;
    case 242u: goto L_08878460;
    case 243u: goto L_08878468;
    case 244u: goto L_0887846C;
    case 245u: goto L_08878470;
    case 246u: goto L_08878474;
    case 247u: goto L_08878478;
    case 248u: goto L_08878480;
    case 249u: goto L_08878484;
    case 250u: goto L_08878488;
    case 251u: goto L_08878490;
    case 252u: goto L_08878494;
    case 253u: goto L_0887849C;
    case 254u: goto L_088784A0;
    case 255u: goto L_088784A4;
    case 256u: goto L_088784A8;
    case 257u: goto L_088784AC;
    case 258u: goto L_088784B4;
    case 259u: goto L_088784B8;
    case 260u: goto L_088784BC;
    case 261u: goto L_088784C4;
    case 262u: goto L_088784C8;
    case 263u: goto L_088784D0;
    case 264u: goto L_088784D4;
    case 265u: goto L_088784D8;
    case 266u: goto L_088784DC;
    case 267u: goto L_088784E0;
    case 268u: goto L_088784E8;
    case 269u: goto L_088784EC;
    case 270u: goto L_088784F0;
    case 271u: goto L_088784F8;
    case 272u: goto L_088784FC;
    case 273u: goto L_08878504;
    case 274u: goto L_08878508;
    case 275u: goto L_0887850C;
    case 276u: goto L_08878510;
    case 277u: goto L_08878514;
    case 278u: goto L_0887851C;
    case 279u: goto L_08878520;
    case 280u: goto L_08878524;
    case 281u: goto L_0887852C;
    case 282u: goto L_08878530;
    case 283u: goto L_08878538;
    case 284u: goto L_0887853C;
    case 285u: goto L_08878540;
    case 286u: goto L_08878544;
    case 287u: goto L_08878548;
    case 288u: goto L_08878550;
    case 289u: goto L_08878554;
    case 290u: goto L_08878558;
    case 291u: goto L_08878560;
    case 292u: goto L_08878564;
    case 293u: goto L_0887856C;
    case 294u: goto L_08878570;
    case 295u: goto L_08878574;
    case 296u: goto L_08878578;
    case 297u: goto L_0887857C;
    case 298u: goto L_08878584;
    case 299u: goto L_08878588;
    case 300u: goto L_0887858C;
    case 301u: goto L_08878594;
    case 302u: goto L_08878598;
    case 303u: goto L_088785A0;
    case 304u: goto L_088785A4;
    case 305u: goto L_088785A8;
    case 306u: goto L_088785AC;
    case 307u: goto L_088785B0;
    case 308u: goto L_088785B8;
    case 309u: goto L_088785BC;
    case 310u: goto L_088785C0;
    case 311u: goto L_088785C8;
    case 312u: goto L_088785CC;
    case 313u: goto L_088785D4;
    case 314u: goto L_088785D8;
    case 315u: goto L_088785DC;
    case 316u: goto L_088785E0;
    case 317u: goto L_088785E4;
    case 318u: goto L_088785EC;
    case 319u: goto L_088785F0;
    case 320u: goto L_088785F4;
    case 321u: goto L_088785FC;
    case 322u: goto L_08878600;
    case 323u: goto L_08878608;
    case 324u: goto L_0887860C;
    case 325u: goto L_08878610;
    case 326u: goto L_08878614;
    case 327u: goto L_08878618;
    case 328u: goto L_08878620;
    case 329u: goto L_08878624;
    case 330u: goto L_08878628;
    case 331u: goto L_08878630;
    case 332u: goto L_08878634;
    case 333u: goto L_0887863C;
    case 334u: goto L_08878640;
    case 335u: goto L_08878644;
    case 336u: goto L_08878648;
    case 337u: goto L_0887864C;
    case 338u: goto L_08878654;
    case 339u: goto L_08878658;
    case 340u: goto L_0887865C;
    case 341u: goto L_08878664;
    case 342u: goto L_08878668;
    case 343u: goto L_0887866C;
    case 344u: goto L_08878670;
    case 345u: goto L_08878674;
    case 346u: goto L_0887867C;
    case 347u: goto L_08878680;
    case 348u: goto L_08878684;
    case 349u: goto L_0887868C;
    case 350u: goto L_08878690;
    case 351u: goto L_08878698;
    case 352u: goto L_0887869C;
    case 353u: goto L_088786A0;
    case 354u: goto L_088786A4;
    case 355u: goto L_088786A8;
    case 356u: goto L_088786B0;
    case 357u: goto L_088786B4;
    case 358u: goto L_088786B8;
    case 359u: goto L_088786C0;
    case 360u: goto L_088786C4;
    case 361u: goto L_088786CC;
    case 362u: goto L_088786D0;
    case 363u: goto L_088786D4;
    case 364u: goto L_088786D8;
    case 365u: goto L_088786DC;
    case 366u: goto L_088786E4;
    case 367u: goto L_088786E8;
    case 368u: goto L_088786EC;
    case 369u: goto L_088786F4;
    case 370u: goto L_088786F8;
    case 371u: goto L_08878700;
    case 372u: goto L_08878704;
    case 373u: goto L_08878708;
    case 374u: goto L_0887870C;
    case 375u: goto L_08878710;
    case 376u: goto L_08878718;
    case 377u: goto L_0887871C;
    case 378u: goto L_08878720;
    case 379u: goto L_08878728;
    case 380u: goto L_0887872C;
    case 381u: goto L_08878734;
    case 382u: goto L_08878738;
    case 383u: goto L_0887873C;
    case 384u: goto L_08878740;
    case 385u: goto L_08878744;
    case 386u: goto L_0887874C;
    case 387u: goto L_08878750;
    case 388u: goto L_08878754;
    case 389u: goto L_0887875C;
    case 390u: goto L_08878760;
    case 391u: goto L_08878768;
    case 392u: goto L_0887876C;
    case 393u: goto L_08878770;
    case 394u: goto L_08878774;
    case 395u: goto L_08878778;
    case 396u: goto L_08878780;
    case 397u: goto L_08878784;
    case 398u: goto L_08878788;
    case 399u: goto L_08878790;
    case 400u: goto L_08878794;
    case 401u: goto L_08878798;
    case 402u: goto L_0887879C;
    case 403u: goto L_088787A0;
    case 404u: goto L_088787A8;
    case 405u: goto L_088787AC;
    case 406u: goto L_088787B0;
    case 407u: goto L_088787B8;
    case 408u: goto L_088787BC;
    case 409u: goto L_088787C4;
    case 410u: goto L_088787C8;
    case 411u: goto L_088787CC;
    case 412u: goto L_088787D0;
    case 413u: goto L_088787D4;
    case 414u: goto L_088787DC;
    case 415u: goto L_088787E0;
    case 416u: goto L_088787E4;
    case 417u: goto L_088787EC;
    case 418u: goto L_088787F0;
    case 419u: goto L_088787F8;
    case 420u: goto L_088787FC;
    case 421u: goto L_08878800;
    case 422u: goto L_08878804;
    case 423u: goto L_08878808;
    case 424u: goto L_08878810;
    case 425u: goto L_08878814;
    case 426u: goto L_08878818;
    case 427u: goto L_08878820;
    case 428u: goto L_08878824;
    case 429u: goto L_08878828;
    case 430u: goto L_0887882C;
    case 431u: goto L_08878830;
    case 432u: goto L_08878838;
    case 433u: goto L_0887883C;
    case 434u: goto L_08878840;
    case 435u: goto L_08878848;
    case 436u: goto L_0887884C;
    case 437u: goto L_08878850;
    case 438u: goto L_08878854;
    case 439u: goto L_08878858;
    case 440u: goto L_08878860;
    case 441u: goto L_08878864;
    case 442u: goto L_08878868;
    case 443u: goto L_08878870;
    case 444u: goto L_08878874;
    case 445u: goto L_08878878;
    case 446u: goto L_0887887C;
    case 447u: goto L_08878880;
    case 448u: goto L_08878888;
    case 449u: goto L_0887888C;
    case 450u: goto L_08878890;
    case 451u: goto L_08878898;
    case 452u: goto L_0887889C;
    case 453u: goto L_088788A0;
    case 454u: goto L_088788A4;
    case 455u: goto L_088788A8;
    case 456u: goto L_088788B0;
    case 457u: goto L_088788B4;
    case 458u: goto L_088788B8;
    case 459u: goto L_088788C0;
    case 460u: goto L_088788C4;
    case 461u: goto L_088788C8;
    case 462u: goto L_088788CC;
    case 463u: goto L_088788D0;
    case 464u: goto L_088788D8;
    case 465u: goto L_088788DC;
    case 466u: goto L_088788E0;
    case 467u: goto L_088788E8;
    case 468u: goto L_088788EC;
    case 469u: goto L_088788F4;
    case 470u: goto L_088788F8;
    case 471u: goto L_088788FC;
    case 472u: goto L_08878900;
    case 473u: goto L_08878904;
    case 474u: goto L_0887890C;
    case 475u: goto L_08878910;
    case 476u: goto L_08878918;
    case 477u: goto L_0887891C;
    case 478u: goto L_08878924;
    case 479u: goto L_08878928;
    case 480u: goto L_0887892C;
    case 481u: goto L_08878930;
    case 482u: goto L_08878934;
    case 483u: goto L_0887893C;
    case 484u: goto L_08878940;
    case 485u: goto L_08878948;
    case 486u: goto L_0887894C;
    case 487u: goto L_08878954;
    case 488u: goto L_08878958;
    case 489u: goto L_0887895C;
    case 490u: goto L_08878960;
    case 491u: goto L_08878964;
    case 492u: goto L_0887896C;
    case 493u: goto L_08878970;
    case 494u: goto L_08878978;
    case 495u: goto L_0887897C;
    case 496u: goto L_08878984;
    case 497u: goto L_08878988;
    case 498u: goto L_0887898C;
    case 499u: goto L_08878990;
    case 500u: goto L_08878994;
    case 501u: goto L_0887899C;
    case 502u: goto L_088789A0;
    case 503u: goto L_088789A8;
    case 504u: goto L_088789AC;
    case 505u: goto L_088789B4;
    case 506u: goto L_088789B8;
    case 507u: goto L_088789BC;
    case 508u: goto L_088789C0;
    case 509u: goto L_088789C4;
    case 510u: goto L_088789CC;
    case 511u: goto L_088789D0;
    case 512u: goto L_088789D8;
    case 513u: goto L_088789DC;
    case 514u: goto L_088789E4;
    case 515u: goto L_088789E8;
    case 516u: goto L_088789EC;
    case 517u: goto L_088789F0;
    case 518u: goto L_088789F4;
    case 519u: goto L_088789FC;
    case 520u: goto L_08878A00;
    case 521u: goto L_08878A08;
    case 522u: goto L_08878A0C;
    case 523u: goto L_08878A10;
    case 524u: goto L_08878A14;
    case 525u: goto L_08878A18;
    case 526u: goto L_08878A20;
    case 527u: goto L_08878A24;
    case 528u: goto L_08878A2C;
    case 529u: goto L_08878A30;
    case 530u: goto L_08878A38;
    case 531u: goto L_08878A3C;
    case 532u: goto L_08878A40;
    case 533u: goto L_08878A44;
    case 534u: goto L_08878A48;
    case 535u: goto L_08878A4C;
    case 536u: goto L_08878A50;
    case 537u: goto L_08878A54;
    case 538u: goto L_08878A58;
    case 539u: goto L_08878A5C;
    case 540u: goto L_08878A60;
    case 541u: goto L_08878A64;
    case 542u: goto L_08878A68;
    default:
        if (local_transfers == 0u) rt.unsupported(ctx.pc, 0u, "invalid internal function entry");
        else ctx.pc = local_pc;
        return;
    }
    }
L_0887801C:
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(-192));
    goto L_08878020;
L_08878020:
    ctx.set_gpr(4, 2478u << 16u);
    goto L_08878024;
L_08878024:
    ctx.set_gpr(4, ctx.gpr[4] + static_cast<std::uint32_t>(27712));
    goto L_08878028;
L_08878028:
    ctx.set_gpr(5, 2478u << 16u);
    goto L_0887802C;
L_0887802C:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(0), ctx.gpr[4]);
    goto L_08878030;
L_08878030:
    ctx.set_gpr(5, ctx.gpr[5] + static_cast<std::uint32_t>(27376));
    goto L_08878034;
L_08878034:
    ctx.set_gpr(4, 2478u << 16u);
    goto L_08878038;
L_08878038:
    ctx.set_gpr(4, ctx.gpr[4] + static_cast<std::uint32_t>(27024));
    goto L_0887803C;
L_0887803C:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(4), ctx.gpr[5]);
    goto L_08878040;
L_08878040:
    ctx.set_gpr(5, 2478u << 16u);
    goto L_08878044;
L_08878044:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(8), ctx.gpr[4]);
    goto L_08878048;
L_08878048:
    ctx.set_gpr(5, ctx.gpr[5] + static_cast<std::uint32_t>(26688));
    goto L_0887804C;
L_0887804C:
    ctx.set_gpr(4, 2478u << 16u);
    goto L_08878050;
L_08878050:
    ctx.set_gpr(4, ctx.gpr[4] + static_cast<std::uint32_t>(26352));
    goto L_08878054;
L_08878054:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(12), ctx.gpr[5]);
    goto L_08878058;
L_08878058:
    ctx.set_gpr(5, 2478u << 16u);
    goto L_0887805C;
L_0887805C:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(16), ctx.gpr[4]);
    goto L_08878060;
L_08878060:
    ctx.set_gpr(5, ctx.gpr[5] + static_cast<std::uint32_t>(26016));
    goto L_08878064;
L_08878064:
    ctx.set_gpr(4, 2478u << 16u);
    goto L_08878068;
L_08878068:
    ctx.set_gpr(4, ctx.gpr[4] + static_cast<std::uint32_t>(25680));
    goto L_0887806C;
L_0887806C:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(20), ctx.gpr[5]);
    goto L_08878070;
L_08878070:
    ctx.set_gpr(5, 2478u << 16u);
    goto L_08878074;
L_08878074:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(24), ctx.gpr[4]);
    goto L_08878078;
L_08878078:
    ctx.set_gpr(5, ctx.gpr[5] + static_cast<std::uint32_t>(25328));
    goto L_0887807C;
L_0887807C:
    ctx.set_gpr(4, 2478u << 16u);
    goto L_08878080;
L_08878080:
    ctx.set_gpr(4, ctx.gpr[4] + static_cast<std::uint32_t>(24992));
    goto L_08878084;
L_08878084:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(28), ctx.gpr[5]);
    goto L_08878088;
L_08878088:
    ctx.set_gpr(5, 2478u << 16u);
    goto L_0887808C;
L_0887808C:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(32), ctx.gpr[4]);
    goto L_08878090;
L_08878090:
    ctx.set_gpr(5, ctx.gpr[5] + static_cast<std::uint32_t>(24624));
    goto L_08878094;
L_08878094:
    ctx.set_gpr(4, 2478u << 16u);
    goto L_08878098;
L_08878098:
    ctx.set_gpr(4, ctx.gpr[4] + static_cast<std::uint32_t>(24288));
    goto L_0887809C;
L_0887809C:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(36), ctx.gpr[5]);
    goto L_088780A0;
L_088780A0:
    ctx.set_gpr(5, 2478u << 16u);
    goto L_088780A4;
L_088780A4:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(40), ctx.gpr[4]);
    goto L_088780A8;
L_088780A8:
    ctx.set_gpr(5, ctx.gpr[5] + static_cast<std::uint32_t>(24196));
    goto L_088780AC;
L_088780AC:
    ctx.set_gpr(4, 2478u << 16u);
    goto L_088780B0;
L_088780B0:
    ctx.set_gpr(4, ctx.gpr[4] + static_cast<std::uint32_t>(23856));
    goto L_088780B4;
L_088780B4:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(44), ctx.gpr[5]);
    goto L_088780B8;
L_088780B8:
    ctx.set_gpr(5, 2478u << 16u);
    goto L_088780BC;
L_088780BC:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(48), ctx.gpr[4]);
    goto L_088780C0;
L_088780C0:
    ctx.set_gpr(5, ctx.gpr[5] + static_cast<std::uint32_t>(23520));
    goto L_088780C4;
L_088780C4:
    ctx.set_gpr(4, 2478u << 16u);
    goto L_088780C8;
L_088780C8:
    ctx.set_gpr(4, ctx.gpr[4] + static_cast<std::uint32_t>(23120));
    goto L_088780CC;
L_088780CC:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(52), ctx.gpr[5]);
    goto L_088780D0;
L_088780D0:
    ctx.set_gpr(5, 2478u << 16u);
    goto L_088780D4;
L_088780D4:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(56), ctx.gpr[4]);
    goto L_088780D8;
L_088780D8:
    ctx.set_gpr(5, ctx.gpr[5] + static_cast<std::uint32_t>(22688));
    goto L_088780DC;
L_088780DC:
    ctx.set_gpr(4, 2478u << 16u);
    goto L_088780E0;
L_088780E0:
    ctx.set_gpr(4, ctx.gpr[4] + static_cast<std::uint32_t>(22336));
    goto L_088780E4;
L_088780E4:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(60), ctx.gpr[5]);
    goto L_088780E8;
L_088780E8:
    ctx.set_gpr(5, 2478u << 16u);
    goto L_088780EC;
L_088780EC:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(64), ctx.gpr[4]);
    goto L_088780F0;
L_088780F0:
    ctx.set_gpr(5, ctx.gpr[5] + static_cast<std::uint32_t>(22228));
    goto L_088780F4;
L_088780F4:
    ctx.set_gpr(4, 2478u << 16u);
    goto L_088780F8;
L_088780F8:
    ctx.set_gpr(4, ctx.gpr[4] + static_cast<std::uint32_t>(22132));
    goto L_088780FC;
L_088780FC:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(68), ctx.gpr[5]);
    goto L_08878100;
L_08878100:
    ctx.set_gpr(5, 2478u << 16u);
    goto L_08878104;
L_08878104:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(72), ctx.gpr[4]);
    goto L_08878108;
L_08878108:
    ctx.set_gpr(5, ctx.gpr[5] + static_cast<std::uint32_t>(18048));
    goto L_0887810C;
L_0887810C:
    ctx.set_gpr(4, 2478u << 16u);
    goto L_08878110;
L_08878110:
    ctx.set_gpr(4, ctx.gpr[4] + static_cast<std::uint32_t>(17392));
    goto L_08878114;
L_08878114:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(76), ctx.gpr[5]);
    goto L_08878118;
L_08878118:
    ctx.set_gpr(5, 2478u << 16u);
    goto L_0887811C;
L_0887811C:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(80), ctx.gpr[4]);
    goto L_08878120;
L_08878120:
    ctx.set_gpr(5, ctx.gpr[5] + static_cast<std::uint32_t>(17380));
    goto L_08878124;
L_08878124:
    ctx.set_gpr(4, 2478u << 16u);
    goto L_08878128;
L_08878128:
    ctx.set_gpr(4, ctx.gpr[4] + static_cast<std::uint32_t>(16592));
    goto L_0887812C;
L_0887812C:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(84), ctx.gpr[5]);
    goto L_08878130;
L_08878130:
    ctx.set_gpr(5, 2478u << 16u);
    goto L_08878134;
L_08878134:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(88), ctx.gpr[4]);
    goto L_08878138;
L_08878138:
    ctx.set_gpr(5, ctx.gpr[5] + static_cast<std::uint32_t>(16240));
    goto L_0887813C;
L_0887813C:
    ctx.set_gpr(4, 2478u << 16u);
    goto L_08878140;
L_08878140:
    ctx.set_gpr(4, ctx.gpr[4] + static_cast<std::uint32_t>(15888));
    goto L_08878144;
L_08878144:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(92), ctx.gpr[5]);
    goto L_08878148;
L_08878148:
    ctx.set_gpr(5, 2478u << 16u);
    goto L_0887814C;
L_0887814C:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(96), ctx.gpr[4]);
    goto L_08878150;
L_08878150:
    ctx.set_gpr(5, ctx.gpr[5] + static_cast<std::uint32_t>(15876));
    goto L_08878154;
L_08878154:
    ctx.set_gpr(4, 2478u << 16u);
    goto L_08878158;
L_08878158:
    ctx.set_gpr(4, ctx.gpr[4] + static_cast<std::uint32_t>(15660));
    goto L_0887815C;
L_0887815C:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(100), ctx.gpr[5]);
    goto L_08878160;
L_08878160:
    ctx.set_gpr(5, 2478u << 16u);
    goto L_08878164;
L_08878164:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(104), ctx.gpr[4]);
    goto L_08878168;
L_08878168:
    ctx.set_gpr(5, ctx.gpr[5] + static_cast<std::uint32_t>(15596));
    goto L_0887816C;
L_0887816C:
    ctx.set_gpr(4, 2478u << 16u);
    goto L_08878170;
L_08878170:
    ctx.set_gpr(4, ctx.gpr[4] + static_cast<std::uint32_t>(15584));
    goto L_08878174;
L_08878174:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(108), ctx.gpr[5]);
    goto L_08878178;
L_08878178:
    ctx.set_gpr(5, 2478u << 16u);
    goto L_0887817C;
L_0887817C:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(112), ctx.gpr[4]);
    goto L_08878180;
L_08878180:
    ctx.set_gpr(5, ctx.gpr[5] + static_cast<std::uint32_t>(15572));
    goto L_08878184;
L_08878184:
    ctx.set_gpr(4, 2478u << 16u);
    goto L_08878188;
L_08878188:
    ctx.set_gpr(4, ctx.gpr[4] + static_cast<std::uint32_t>(15548));
    goto L_0887818C;
L_0887818C:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(116), ctx.gpr[5]);
    goto L_08878190;
L_08878190:
    ctx.set_gpr(5, 2478u << 16u);
    goto L_08878194;
L_08878194:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(120), ctx.gpr[4]);
    goto L_08878198;
L_08878198:
    ctx.set_gpr(5, ctx.gpr[5] + static_cast<std::uint32_t>(15536));
    goto L_0887819C;
L_0887819C:
    ctx.set_gpr(4, 2478u << 16u);
    goto L_088781A0;
L_088781A0:
    ctx.set_gpr(4, ctx.gpr[4] + static_cast<std::uint32_t>(15524));
    goto L_088781A4;
L_088781A4:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(124), ctx.gpr[5]);
    goto L_088781A8;
L_088781A8:
    ctx.set_gpr(5, 2478u << 16u);
    goto L_088781AC;
L_088781AC:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(128), ctx.gpr[4]);
    goto L_088781B0;
L_088781B0:
    ctx.set_gpr(5, ctx.gpr[5] + static_cast<std::uint32_t>(15504));
    goto L_088781B4;
L_088781B4:
    ctx.set_gpr(4, 2478u << 16u);
    goto L_088781B8;
L_088781B8:
    ctx.set_gpr(4, ctx.gpr[4] + static_cast<std::uint32_t>(15492));
    goto L_088781BC;
L_088781BC:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(132), ctx.gpr[5]);
    goto L_088781C0;
L_088781C0:
    ctx.set_gpr(5, 2478u << 16u);
    goto L_088781C4;
L_088781C4:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(136), ctx.gpr[4]);
    goto L_088781C8;
L_088781C8:
    ctx.set_gpr(6, 2478u << 16u);
    goto L_088781CC;
L_088781CC:
    ctx.set_gpr(5, ctx.gpr[5] + static_cast<std::uint32_t>(15136));
    goto L_088781D0;
L_088781D0:
    ctx.set_gpr(4, 2478u << 16u);
    goto L_088781D4;
L_088781D4:
    ctx.set_gpr(7, rt.memory().aot_load32(ctx.gpr[6] + static_cast<std::uint32_t>(28768)));
    goto L_088781D8;
L_088781D8:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(148), ctx.gpr[16]);
    goto L_088781DC;
L_088781DC:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(156), ctx.gpr[18]);
    goto L_088781E0;
L_088781E0:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(164), ctx.gpr[20]);
    goto L_088781E4;
L_088781E4:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(172), ctx.gpr[22]);
    goto L_088781E8;
L_088781E8:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(180), ctx.gpr[30]);
    goto L_088781EC;
L_088781EC:
    ctx.set_gpr(4, ctx.gpr[4] + static_cast<std::uint32_t>(15116));
    goto L_088781F0;
L_088781F0:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(140), ctx.gpr[5]);
    goto L_088781F4;
L_088781F4:
    ctx.set_gpr(16, 2478u << 16u);
    goto L_088781F8;
L_088781F8:
    ctx.set_gpr(18, 2478u << 16u);
    goto L_088781FC;
L_088781FC:
    ctx.set_gpr(20, 2478u << 16u);
    goto L_08878200;
L_08878200:
    ctx.set_gpr(22, 2478u << 16u);
    goto L_08878204;
L_08878204:
    ctx.set_gpr(30, 2478u << 16u);
    goto L_08878208;
L_08878208:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(152), ctx.gpr[17]);
    goto L_0887820C;
L_0887820C:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(160), ctx.gpr[19]);
    goto L_08878210;
L_08878210:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(168), ctx.gpr[21]);
    goto L_08878214;
L_08878214:
    ctx.set_gpr(16, ctx.gpr[16] + static_cast<std::uint32_t>(28784));
    goto L_08878218;
L_08878218:
    ctx.set_gpr(18, ctx.gpr[18] + static_cast<std::uint32_t>(28416));
    goto L_0887821C;
L_0887821C:
    ctx.set_gpr(20, ctx.gpr[20] + static_cast<std::uint32_t>(28396));
    goto L_08878220;
L_08878220:
    ctx.set_gpr(22, ctx.gpr[22] + static_cast<std::uint32_t>(28388));
    goto L_08878224;
L_08878224:
    ctx.set_gpr(30, ctx.gpr[30] + static_cast<std::uint32_t>(28064));
    goto L_08878228;
L_08878228:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(144), ctx.gpr[4]);
    goto L_0887822C;
L_0887822C:
    ctx.set_gpr(17, 2478u << 16u);
    goto L_08878230;
L_08878230:
    ctx.set_gpr(19, 2478u << 16u);
    goto L_08878234;
L_08878234:
    ctx.set_gpr(21, 2478u << 16u);
    goto L_08878238;
L_08878238:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(176), ctx.gpr[23]);
    goto L_0887823C;
L_0887823C:
    rt.memory().aot_store32(ctx.gpr[29] + static_cast<std::uint32_t>(184), ctx.gpr[31]);
    goto L_08878240;
L_08878240:
    { const bool branch_taken = ctx.gpr[7] != 0u;
    ctx.set_gpr(23, 2478u << 16u);
      if (branch_taken) {
          goto L_08878264;
      }
      goto L_08878248;
    }
L_08878248:
    ctx.set_gpr(4, 0u | 1u);
    goto L_0887824C;
L_0887824C:
    rt.memory().aot_store32(ctx.gpr[6] + static_cast<std::uint32_t>(28768), ctx.gpr[4]);
    goto L_08878250;
L_08878250:
    ctx.set_gpr(31, 0x08878258u);
    ctx.set_gpr(4, ctx.gpr[16] | 0u);
    ctx.pc = 0x089DD4D0u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08878258u) goto L_08878258;
    return;
L_08878258:
    ctx.set_gpr(4, 2205u << 16u);
    goto L_0887825C;
L_0887825C:
    ctx.set_gpr(31, 0x08878264u);
    ctx.set_gpr(4, ctx.gpr[4] + static_cast<std::uint32_t>(26428));
    ctx.pc = 0x08992F6Cu;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08878264u) goto L_08878264;
    return;
L_08878264:
    { static std::uint32_t s_trace=0; if (++s_trace <= 8u) { std::printf("[SCHED-CB-WRITE] 08878264 gpr16=0x%08X gpr17=0x%08X gpr18=0x%08X cbslot=0x%08X\n", ctx.gpr[16], ctx.gpr[17], ctx.gpr[18], rt.memory().aot_load32(0x089E09C0u)); fflush(stdout); } }
    // ARCH-SYNTH: signal scene manager that loading is complete.
    // On real PSP the loading thread signals a semaphore here; the scene manager
    // then calls sceKernelCreateScene(0x2713) which sets 6039=1 and 603B=1.
    // We inject that signal directly so FUN_08875364 (task[3]) sees it and fires.
    { static bool s_load_done = false;
      if (!s_load_done) {
          s_load_done = true;
          rt.memory().aot_store8(0x089D6039u, 1u);
          rt.memory().aot_store8(0x089D603Bu, 1u);
          rt.memory().aot_store8(0x089D603Au, 0u); // clear "skip first scene" flag
          std::printf("[LOAD-DONE] injected 6039=1 603B=1 603A=0 — loading complete, scene transition armed\n"); fflush(stdout);
      }
    }
    ctx.set_gpr(4, 2206u << 16u);
    goto L_08878268;
L_08878268:
    rt.memory().aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(2496), ctx.gpr[16]);
    goto L_0887826C;
L_0887826C:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[17] + static_cast<std::uint32_t>(28400)));
    goto L_08878270;
L_08878270:
    { const bool branch_taken = ctx.gpr[4] != 0u;
    ctx.set_gpr(4, 0u | 1u);
      if (branch_taken) {
          goto L_08878290;
      }
      goto L_08878278;
    }
L_08878278:
    rt.memory().aot_store32(ctx.gpr[17] + static_cast<std::uint32_t>(28400), ctx.gpr[4]);
    goto L_0887827C;
L_0887827C:
    ctx.set_gpr(31, 0x08878284u);
    ctx.set_gpr(4, ctx.gpr[18] | 0u);
    ctx.pc = 0x089E0B0Cu;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08878284u) goto L_08878284;
    return;
L_08878284:
    ctx.set_gpr(4, 2205u << 16u);
    goto L_08878288;
L_08878288:
    ctx.set_gpr(31, 0x08878290u);
    ctx.set_gpr(4, ctx.gpr[4] + static_cast<std::uint32_t>(26416));
    ctx.pc = 0x08992F6Cu;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08878290u) goto L_08878290;
    return;
L_08878290:
    ctx.set_gpr(4, 2206u << 16u);
    goto L_08878294;
L_08878294:
    rt.memory().aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(30148), ctx.gpr[18]);
    goto L_08878298;
L_08878298:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[19] + static_cast<std::uint32_t>(28392)));
    goto L_0887829C;
L_0887829C:
    ctx.set_gpr(16, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(0)));
    goto L_088782A0;
L_088782A0:
    { const bool branch_taken = ctx.gpr[4] != 0u;
    ctx.set_gpr(17, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(4)));
      if (branch_taken) {
          goto L_088782C4;
      }
      goto L_088782A8;
    }
L_088782A8:
    ctx.set_gpr(4, 0u | 1u);
    goto L_088782AC;
L_088782AC:
    rt.memory().aot_store32(ctx.gpr[19] + static_cast<std::uint32_t>(28392), ctx.gpr[4]);
    goto L_088782B0;
L_088782B0:
    ctx.set_gpr(31, 0x088782B8u);
    ctx.set_gpr(4, ctx.gpr[20] | 0u);
    ctx.pc = 0x088F2220u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x088782B8u) goto L_088782B8;
    return;
L_088782B8:
    ctx.set_gpr(4, 2205u << 16u);
    goto L_088782BC;
L_088782BC:
    ctx.set_gpr(31, 0x088782C4u);
    ctx.set_gpr(4, ctx.gpr[4] + static_cast<std::uint32_t>(26404));
    ctx.pc = 0x08992F6Cu;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x088782C4u) goto L_088782C4;
    return;
L_088782C4:
    ctx.set_gpr(4, 2205u << 16u);
    goto L_088782C8;
L_088782C8:
    rt.memory().aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(32544), ctx.gpr[20]);
    goto L_088782CC;
L_088782CC:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[21] + static_cast<std::uint32_t>(28384)));
    goto L_088782D0;
L_088782D0:
    ctx.set_gpr(18, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(8)));
    goto L_088782D4;
L_088782D4:
    { const bool branch_taken = ctx.gpr[4] != 0u;
    ctx.set_gpr(19, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(12)));
      if (branch_taken) {
          goto L_088782F8;
      }
      goto L_088782DC;
    }
L_088782DC:
    ctx.set_gpr(4, 0u | 1u);
    goto L_088782E0;
L_088782E0:
    rt.memory().aot_store32(ctx.gpr[21] + static_cast<std::uint32_t>(28384), ctx.gpr[4]);
    goto L_088782E4;
L_088782E4:
    ctx.set_gpr(31, 0x088782ECu);
    ctx.set_gpr(4, ctx.gpr[22] | 0u);
    ctx.pc = 0x088F0700u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x088782ECu) goto L_088782EC;
    return;
L_088782EC:
    ctx.set_gpr(4, 2205u << 16u);
    goto L_088782F0;
L_088782F0:
    ctx.set_gpr(31, 0x088782F8u);
    ctx.set_gpr(4, ctx.gpr[4] + static_cast<std::uint32_t>(26392));
    ctx.pc = 0x08992F6Cu;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x088782F8u) goto L_088782F8;
    return;
L_088782F8:
    ctx.set_gpr(4, 2205u << 16u);
    goto L_088782FC;
L_088782FC:
    rt.memory().aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(32528), ctx.gpr[22]);
    goto L_08878300;
L_08878300:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[23] + static_cast<std::uint32_t>(28048)));
    goto L_08878304;
L_08878304:
    ctx.set_gpr(20, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(16)));
    goto L_08878308;
L_08878308:
    { const bool branch_taken = ctx.gpr[4] != 0u;
    ctx.set_gpr(21, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(20)));
      if (branch_taken) {
          goto L_0887832C;
      }
      goto L_08878310;
    }
L_08878310:
    ctx.set_gpr(4, 0u | 1u);
    goto L_08878314;
L_08878314:
    rt.memory().aot_store32(ctx.gpr[23] + static_cast<std::uint32_t>(28048), ctx.gpr[4]);
    goto L_08878318;
L_08878318:
    ctx.set_gpr(31, 0x08878320u);
    ctx.set_gpr(4, ctx.gpr[30] | 0u);
    ctx.pc = 0x08AC65A0u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08878320u) goto L_08878320;
    return;
L_08878320:
    ctx.set_gpr(4, 2205u << 16u);
    goto L_08878324;
L_08878324:
    ctx.set_gpr(31, 0x0887832Cu);
    ctx.set_gpr(4, ctx.gpr[4] + static_cast<std::uint32_t>(26380));
    ctx.pc = 0x08992F6Cu;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x0887832Cu) goto L_0887832C;
    return;
L_0887832C:
    ctx.set_gpr(4, 2220u << 16u);
    goto L_08878330;
L_08878330:
    rt.memory().aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(29952), ctx.gpr[30]);
    goto L_08878334;
L_08878334:
    ctx.set_gpr(6, 2478u << 16u);
    goto L_08878338;
L_08878338:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[6] + static_cast<std::uint32_t>(27696)));
    goto L_0887833C;
L_0887833C:
    ctx.set_gpr(22, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(24)));
    goto L_08878340;
L_08878340:
    { const bool branch_taken = ctx.gpr[4] != 0u;
    ctx.set_gpr(23, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(28)));
      if (branch_taken) {
          goto L_08878364;
      }
      goto L_08878348;
    }
L_08878348:
    ctx.set_gpr(4, 0u | 1u);
    goto L_0887834C;
L_0887834C:
    rt.memory().aot_store32(ctx.gpr[6] + static_cast<std::uint32_t>(27696), ctx.gpr[4]);
    goto L_08878350;
L_08878350:
    ctx.set_gpr(31, 0x08878358u);
    ctx.set_gpr(4, ctx.gpr[16] | 0u);
    ctx.pc = 0x08AF2C30u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08878358u) goto L_08878358;
    return;
L_08878358:
    ctx.set_gpr(4, 2205u << 16u);
    goto L_0887835C;
L_0887835C:
    ctx.set_gpr(31, 0x08878364u);
    ctx.set_gpr(4, ctx.gpr[4] + static_cast<std::uint32_t>(26368));
    ctx.pc = 0x08992F6Cu;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08878364u) goto L_08878364;
    return;
L_08878364:
    ctx.set_gpr(4, 2224u << 16u);
    goto L_08878368;
L_08878368:
    rt.memory().aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(7416), ctx.gpr[16]);
    goto L_0887836C;
L_0887836C:
    ctx.set_gpr(6, 2478u << 16u);
    goto L_08878370;
L_08878370:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[6] + static_cast<std::uint32_t>(27360)));
    goto L_08878374;
L_08878374:
    { const bool branch_taken = ctx.gpr[4] != 0u;
    ctx.set_gpr(30, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(32)));
      if (branch_taken) {
          goto L_08878398;
      }
      goto L_0887837C;
    }
L_0887837C:
    ctx.set_gpr(4, 0u | 1u);
    goto L_08878380;
L_08878380:
    rt.memory().aot_store32(ctx.gpr[6] + static_cast<std::uint32_t>(27360), ctx.gpr[4]);
    goto L_08878384;
L_08878384:
    ctx.set_gpr(31, 0x0887838Cu);
    ctx.set_gpr(4, ctx.gpr[17] | 0u);
    ctx.pc = 0x08B238F8u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x0887838Cu) goto L_0887838C;
    return;
L_0887838C:
    ctx.set_gpr(4, 2205u << 16u);
    goto L_08878390;
L_08878390:
    ctx.set_gpr(31, 0x08878398u);
    ctx.set_gpr(4, ctx.gpr[4] + static_cast<std::uint32_t>(26356));
    ctx.pc = 0x08992F6Cu;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08878398u) goto L_08878398;
    return;
L_08878398:
    ctx.set_gpr(4, 2226u << 16u);
    goto L_0887839C;
L_0887839C:
    rt.memory().aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(17344), ctx.gpr[17]);
    goto L_088783A0;
L_088783A0:
    ctx.set_gpr(6, 2478u << 16u);
    goto L_088783A4;
L_088783A4:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[6] + static_cast<std::uint32_t>(27008)));
    goto L_088783A8;
L_088783A8:
    { const bool branch_taken = ctx.gpr[4] != 0u;
    ctx.set_gpr(16, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(36)));
      if (branch_taken) {
          goto L_088783CC;
      }
      goto L_088783B0;
    }
L_088783B0:
    ctx.set_gpr(4, 0u | 1u);
    goto L_088783B4;
L_088783B4:
    rt.memory().aot_store32(ctx.gpr[6] + static_cast<std::uint32_t>(27008), ctx.gpr[4]);
    goto L_088783B8;
L_088783B8:
    ctx.set_gpr(31, 0x088783C0u);
    ctx.set_gpr(4, ctx.gpr[18] | 0u);
    ctx.pc = 0x08ABF6F8u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x088783C0u) goto L_088783C0;
    return;
L_088783C0:
    ctx.set_gpr(4, 2205u << 16u);
    goto L_088783C4;
L_088783C4:
    ctx.set_gpr(31, 0x088783CCu);
    ctx.set_gpr(4, ctx.gpr[4] + static_cast<std::uint32_t>(26344));
    ctx.pc = 0x08992F6Cu;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x088783CCu) goto L_088783CC;
    return;
L_088783CC:
    ctx.set_gpr(4, 2220u << 16u);
    goto L_088783D0;
L_088783D0:
    rt.memory().aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(17760), ctx.gpr[18]);
    goto L_088783D4;
L_088783D4:
    ctx.set_gpr(6, 2478u << 16u);
    goto L_088783D8;
L_088783D8:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[6] + static_cast<std::uint32_t>(26672)));
    goto L_088783DC;
L_088783DC:
    { const bool branch_taken = ctx.gpr[4] != 0u;
    ctx.set_gpr(17, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(40)));
      if (branch_taken) {
          goto L_08878400;
      }
      goto L_088783E4;
    }
L_088783E4:
    ctx.set_gpr(4, 0u | 1u);
    goto L_088783E8;
L_088783E8:
    rt.memory().aot_store32(ctx.gpr[6] + static_cast<std::uint32_t>(26672), ctx.gpr[4]);
    goto L_088783EC;
L_088783EC:
    ctx.set_gpr(31, 0x088783F4u);
    ctx.set_gpr(4, ctx.gpr[19] | 0u);
    ctx.pc = 0x08B1F0BCu;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x088783F4u) goto L_088783F4;
    return;
L_088783F4:
    ctx.set_gpr(4, 2205u << 16u);
    goto L_088783F8;
L_088783F8:
    ctx.set_gpr(31, 0x08878400u);
    ctx.set_gpr(4, ctx.gpr[4] + static_cast<std::uint32_t>(26332));
    ctx.pc = 0x08992F6Cu;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08878400u) goto L_08878400;
    return;
L_08878400:
    ctx.set_gpr(4, 2226u << 16u);
    goto L_08878404;
L_08878404:
    rt.memory().aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(11928), ctx.gpr[19]);
    goto L_08878408;
L_08878408:
    ctx.set_gpr(6, 2478u << 16u);
    goto L_0887840C;
L_0887840C:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[6] + static_cast<std::uint32_t>(26336)));
    goto L_08878410;
L_08878410:
    { const bool branch_taken = ctx.gpr[4] != 0u;
    ctx.set_gpr(18, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(44)));
      if (branch_taken) {
          goto L_08878434;
      }
      goto L_08878418;
    }
L_08878418:
    ctx.set_gpr(4, 0u | 1u);
    goto L_0887841C;
L_0887841C:
    rt.memory().aot_store32(ctx.gpr[6] + static_cast<std::uint32_t>(26336), ctx.gpr[4]);
    goto L_08878420;
L_08878420:
    ctx.set_gpr(31, 0x08878428u);
    ctx.set_gpr(4, ctx.gpr[20] | 0u);
    ctx.pc = 0x08B0C00Cu;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08878428u) goto L_08878428;
    return;
L_08878428:
    ctx.set_gpr(4, 2205u << 16u);
    goto L_0887842C;
L_0887842C:
    ctx.set_gpr(31, 0x08878434u);
    ctx.set_gpr(4, ctx.gpr[4] + static_cast<std::uint32_t>(26320));
    ctx.pc = 0x08992F6Cu;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08878434u) goto L_08878434;
    return;
L_08878434:
    ctx.set_gpr(4, 2226u << 16u);
    goto L_08878438;
L_08878438:
    rt.memory().aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(-13568), ctx.gpr[20]);
    goto L_0887843C;
L_0887843C:
    ctx.set_gpr(6, 2478u << 16u);
    goto L_08878440;
L_08878440:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[6] + static_cast<std::uint32_t>(26000)));
    goto L_08878444;
L_08878444:
    { const bool branch_taken = ctx.gpr[4] != 0u;
    ctx.set_gpr(19, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(48)));
      if (branch_taken) {
          goto L_08878468;
      }
      goto L_0887844C;
    }
L_0887844C:
    ctx.set_gpr(4, 0u | 1u);
    goto L_08878450;
L_08878450:
    rt.memory().aot_store32(ctx.gpr[6] + static_cast<std::uint32_t>(26000), ctx.gpr[4]);
    goto L_08878454;
L_08878454:
    ctx.set_gpr(31, 0x0887845Cu);
    ctx.set_gpr(4, ctx.gpr[21] | 0u);
    ctx.pc = 0x08AB9C18u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x0887845Cu) goto L_0887845C;
    return;
L_0887845C:
    ctx.set_gpr(4, 2205u << 16u);
    goto L_08878460;
L_08878460:
    ctx.set_gpr(31, 0x08878468u);
    ctx.set_gpr(4, ctx.gpr[4] + static_cast<std::uint32_t>(26308));
    ctx.pc = 0x08992F6Cu;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08878468u) goto L_08878468;
    return;
L_08878468:
    ctx.set_gpr(4, 2220u << 16u);
    goto L_0887846C;
L_0887846C:
    rt.memory().aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(-17948), ctx.gpr[21]);
    goto L_08878470;
L_08878470:
    ctx.set_gpr(6, 2478u << 16u);
    goto L_08878474;
L_08878474:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[6] + static_cast<std::uint32_t>(25664)));
    goto L_08878478;
L_08878478:
    { const bool branch_taken = ctx.gpr[4] != 0u;
    ctx.set_gpr(20, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(52)));
      if (branch_taken) {
          goto L_0887849C;
      }
      goto L_08878480;
    }
L_08878480:
    ctx.set_gpr(4, 0u | 1u);
    goto L_08878484;
L_08878484:
    rt.memory().aot_store32(ctx.gpr[6] + static_cast<std::uint32_t>(25664), ctx.gpr[4]);
    goto L_08878488;
L_08878488:
    ctx.set_gpr(31, 0x08878490u);
    ctx.set_gpr(4, ctx.gpr[22] | 0u);
    ctx.pc = 0x08B24A0Cu;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08878490u) goto L_08878490;
    return;
L_08878490:
    ctx.set_gpr(4, 2205u << 16u);
    goto L_08878494;
L_08878494:
    ctx.set_gpr(31, 0x0887849Cu);
    ctx.set_gpr(4, ctx.gpr[4] + static_cast<std::uint32_t>(26296));
    ctx.pc = 0x08992F6Cu;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x0887849Cu) goto L_0887849C;
    return;
L_0887849C:
    ctx.set_gpr(4, 2226u << 16u);
    goto L_088784A0;
L_088784A0:
    rt.memory().aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(20548), ctx.gpr[22]);
    goto L_088784A4;
L_088784A4:
    ctx.set_gpr(6, 2478u << 16u);
    goto L_088784A8;
L_088784A8:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[6] + static_cast<std::uint32_t>(25312)));
    goto L_088784AC;
L_088784AC:
    { const bool branch_taken = ctx.gpr[4] != 0u;
    ctx.set_gpr(21, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(56)));
      if (branch_taken) {
          goto L_088784D0;
      }
      goto L_088784B4;
    }
L_088784B4:
    ctx.set_gpr(4, 0u | 1u);
    goto L_088784B8;
L_088784B8:
    rt.memory().aot_store32(ctx.gpr[6] + static_cast<std::uint32_t>(25312), ctx.gpr[4]);
    goto L_088784BC;
L_088784BC:
    ctx.set_gpr(31, 0x088784C4u);
    ctx.set_gpr(4, ctx.gpr[23] | 0u);
    ctx.pc = 0x08B296E8u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x088784C4u) goto L_088784C4;
    return;
L_088784C4:
    ctx.set_gpr(4, 2205u << 16u);
    goto L_088784C8;
L_088784C8:
    ctx.set_gpr(31, 0x088784D0u);
    ctx.set_gpr(4, ctx.gpr[4] + static_cast<std::uint32_t>(26284));
    ctx.pc = 0x08992F6Cu;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x088784D0u) goto L_088784D0;
    return;
L_088784D0:
    ctx.set_gpr(4, 2227u << 16u);
    goto L_088784D4;
L_088784D4:
    rt.memory().aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(-25352), ctx.gpr[23]);
    goto L_088784D8;
L_088784D8:
    ctx.set_gpr(6, 2478u << 16u);
    goto L_088784DC;
L_088784DC:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[6] + static_cast<std::uint32_t>(24976)));
    goto L_088784E0;
L_088784E0:
    { const bool branch_taken = ctx.gpr[4] != 0u;
    ctx.set_gpr(22, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(60)));
      if (branch_taken) {
          goto L_08878504;
      }
      goto L_088784E8;
    }
L_088784E8:
    ctx.set_gpr(4, 0u | 1u);
    goto L_088784EC;
L_088784EC:
    rt.memory().aot_store32(ctx.gpr[6] + static_cast<std::uint32_t>(24976), ctx.gpr[4]);
    goto L_088784F0;
L_088784F0:
    ctx.set_gpr(31, 0x088784F8u);
    ctx.set_gpr(4, ctx.gpr[30] | 0u);
    ctx.pc = 0x08B326F8u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x088784F8u) goto L_088784F8;
    return;
L_088784F8:
    ctx.set_gpr(4, 2205u << 16u);
    goto L_088784FC;
L_088784FC:
    ctx.set_gpr(31, 0x08878504u);
    ctx.set_gpr(4, ctx.gpr[4] + static_cast<std::uint32_t>(26272));
    ctx.pc = 0x08992F6Cu;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08878504u) goto L_08878504;
    return;
L_08878504:
    ctx.set_gpr(4, 2227u << 16u);
    goto L_08878508;
L_08878508:
    rt.memory().aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(11664), ctx.gpr[30]);
    goto L_0887850C;
L_0887850C:
    ctx.set_gpr(6, 2478u << 16u);
    goto L_08878510;
L_08878510:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[6] + static_cast<std::uint32_t>(24608)));
    goto L_08878514;
L_08878514:
    { const bool branch_taken = ctx.gpr[4] != 0u;
    ctx.set_gpr(23, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(64)));
      if (branch_taken) {
          goto L_08878538;
      }
      goto L_0887851C;
    }
L_0887851C:
    ctx.set_gpr(4, 0u | 1u);
    goto L_08878520;
L_08878520:
    rt.memory().aot_store32(ctx.gpr[6] + static_cast<std::uint32_t>(24608), ctx.gpr[4]);
    goto L_08878524;
L_08878524:
    ctx.set_gpr(31, 0x0887852Cu);
    ctx.set_gpr(4, ctx.gpr[16] | 0u);
    ctx.pc = 0x08A42C1Cu;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x0887852Cu) goto L_0887852C;
    return;
L_0887852C:
    ctx.set_gpr(4, 2205u << 16u);
    goto L_08878530;
L_08878530:
    ctx.set_gpr(31, 0x08878538u);
    ctx.set_gpr(4, ctx.gpr[4] + static_cast<std::uint32_t>(26260));
    ctx.pc = 0x08992F6Cu;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08878538u) goto L_08878538;
    return;
L_08878538:
    ctx.set_gpr(4, 2212u << 16u);
    goto L_0887853C;
L_0887853C:
    rt.memory().aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(22508), ctx.gpr[16]);
    goto L_08878540;
L_08878540:
    ctx.set_gpr(6, 2478u << 16u);
    goto L_08878544;
L_08878544:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[6] + static_cast<std::uint32_t>(24272)));
    goto L_08878548;
L_08878548:
    { const bool branch_taken = ctx.gpr[4] != 0u;
    ctx.set_gpr(30, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(68)));
      if (branch_taken) {
          goto L_0887856C;
      }
      goto L_08878550;
    }
L_08878550:
    ctx.set_gpr(4, 0u | 1u);
    goto L_08878554;
L_08878554:
    rt.memory().aot_store32(ctx.gpr[6] + static_cast<std::uint32_t>(24272), ctx.gpr[4]);
    goto L_08878558;
L_08878558:
    ctx.set_gpr(31, 0x08878560u);
    ctx.set_gpr(4, ctx.gpr[17] | 0u);
    ctx.pc = 0x08A436C0u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08878560u) goto L_08878560;
    return;
L_08878560:
    ctx.set_gpr(4, 2205u << 16u);
    goto L_08878564;
L_08878564:
    ctx.set_gpr(31, 0x0887856Cu);
    ctx.set_gpr(4, ctx.gpr[4] + static_cast<std::uint32_t>(26248));
    ctx.pc = 0x08992F6Cu;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x0887856Cu) goto L_0887856C;
    return;
L_0887856C:
    ctx.set_gpr(4, 2212u << 16u);
    goto L_08878570;
L_08878570:
    rt.memory().aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(22512), ctx.gpr[17]);
    goto L_08878574;
L_08878574:
    ctx.set_gpr(6, 2478u << 16u);
    goto L_08878578;
L_08878578:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[6] + static_cast<std::uint32_t>(24192)));
    goto L_0887857C;
L_0887857C:
    { const bool branch_taken = ctx.gpr[4] != 0u;
    ctx.set_gpr(16, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(72)));
      if (branch_taken) {
          goto L_088785A0;
      }
      goto L_08878584;
    }
L_08878584:
    ctx.set_gpr(4, 0u | 1u);
    goto L_08878588;
L_08878588:
    rt.memory().aot_store32(ctx.gpr[6] + static_cast<std::uint32_t>(24192), ctx.gpr[4]);
    goto L_0887858C;
L_0887858C:
    ctx.set_gpr(31, 0x08878594u);
    ctx.set_gpr(4, ctx.gpr[18] | 0u);
    ctx.pc = 0x08A323E4u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08878594u) goto L_08878594;
    return;
L_08878594:
    ctx.set_gpr(4, 2205u << 16u);
    goto L_08878598;
L_08878598:
    ctx.set_gpr(31, 0x088785A0u);
    ctx.set_gpr(4, ctx.gpr[4] + static_cast<std::uint32_t>(26236));
    ctx.pc = 0x08992F6Cu;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x088785A0u) goto L_088785A0;
    return;
L_088785A0:
    ctx.set_gpr(4, 2211u << 16u);
    goto L_088785A4;
L_088785A4:
    rt.memory().aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(23040), ctx.gpr[18]);
    goto L_088785A8;
L_088785A8:
    ctx.set_gpr(6, 2478u << 16u);
    goto L_088785AC;
L_088785AC:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[6] + static_cast<std::uint32_t>(23840)));
    goto L_088785B0;
L_088785B0:
    { const bool branch_taken = ctx.gpr[4] != 0u;
    ctx.set_gpr(17, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(76)));
      if (branch_taken) {
          goto L_088785D4;
      }
      goto L_088785B8;
    }
L_088785B8:
    ctx.set_gpr(4, 0u | 1u);
    goto L_088785BC;
L_088785BC:
    rt.memory().aot_store32(ctx.gpr[6] + static_cast<std::uint32_t>(23840), ctx.gpr[4]);
    goto L_088785C0;
L_088785C0:
    ctx.set_gpr(31, 0x088785C8u);
    ctx.set_gpr(4, ctx.gpr[19] | 0u);
    ctx.pc = 0x089FE524u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x088785C8u) goto L_088785C8;
    return;
L_088785C8:
    ctx.set_gpr(4, 2205u << 16u);
    goto L_088785CC;
L_088785CC:
    ctx.set_gpr(31, 0x088785D4u);
    ctx.set_gpr(4, ctx.gpr[4] + static_cast<std::uint32_t>(26224));
    ctx.pc = 0x08992F6Cu;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x088785D4u) goto L_088785D4;
    return;
L_088785D4:
    ctx.set_gpr(4, 2209u << 16u);
    goto L_088785D8;
L_088785D8:
    rt.memory().aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(-18784), ctx.gpr[19]);
    goto L_088785DC;
L_088785DC:
    ctx.set_gpr(6, 2478u << 16u);
    goto L_088785E0;
L_088785E0:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[6] + static_cast<std::uint32_t>(23504)));
    goto L_088785E4;
L_088785E4:
    { const bool branch_taken = ctx.gpr[4] != 0u;
    ctx.set_gpr(18, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(80)));
      if (branch_taken) {
          goto L_08878608;
      }
      goto L_088785EC;
    }
L_088785EC:
    ctx.set_gpr(4, 0u | 1u);
    goto L_088785F0;
L_088785F0:
    rt.memory().aot_store32(ctx.gpr[6] + static_cast<std::uint32_t>(23504), ctx.gpr[4]);
    goto L_088785F4;
L_088785F4:
    ctx.set_gpr(31, 0x088785FCu);
    ctx.set_gpr(4, ctx.gpr[20] | 0u);
    ctx.pc = 0x08A2BCE4u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x088785FCu) goto L_088785FC;
    return;
L_088785FC:
    ctx.set_gpr(4, 2205u << 16u);
    goto L_08878600;
L_08878600:
    ctx.set_gpr(31, 0x08878608u);
    ctx.set_gpr(4, ctx.gpr[4] + static_cast<std::uint32_t>(26212));
    ctx.pc = 0x08992F6Cu;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08878608u) goto L_08878608;
    return;
L_08878608:
    ctx.set_gpr(4, 2206u << 16u);
    goto L_0887860C;
L_0887860C:
    rt.memory().aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(30152), ctx.gpr[20]);
    goto L_08878610;
L_08878610:
    ctx.set_gpr(6, 2478u << 16u);
    goto L_08878614;
L_08878614:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[6] + static_cast<std::uint32_t>(23104)));
    goto L_08878618;
L_08878618:
    { const bool branch_taken = ctx.gpr[4] != 0u;
    ctx.set_gpr(19, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(84)));
      if (branch_taken) {
          goto L_0887863C;
      }
      goto L_08878620;
    }
L_08878620:
    ctx.set_gpr(4, 0u | 1u);
    goto L_08878624;
L_08878624:
    rt.memory().aot_store32(ctx.gpr[6] + static_cast<std::uint32_t>(23104), ctx.gpr[4]);
    goto L_08878628;
L_08878628:
    ctx.set_gpr(31, 0x08878630u);
    ctx.set_gpr(4, ctx.gpr[21] | 0u);
    ctx.pc = 0x08A1D364u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08878630u) goto L_08878630;
    return;
L_08878630:
    ctx.set_gpr(4, 2205u << 16u);
    goto L_08878634;
L_08878634:
    ctx.set_gpr(31, 0x0887863Cu);
    ctx.set_gpr(4, ctx.gpr[4] + static_cast<std::uint32_t>(26200));
    ctx.pc = 0x08992F6Cu;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x0887863Cu) goto L_0887863C;
    return;
L_0887863C:
    ctx.set_gpr(4, 2210u << 16u);
    goto L_08878640;
L_08878640:
    rt.memory().aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(16368), ctx.gpr[21]);
    goto L_08878644;
L_08878644:
    ctx.set_gpr(6, 2478u << 16u);
    goto L_08878648;
L_08878648:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[6] + static_cast<std::uint32_t>(22672)));
    goto L_0887864C;
L_0887864C:
    { const bool branch_taken = ctx.gpr[4] != 0u;
    ctx.set_gpr(20, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(88)));
      if (branch_taken) {
          goto L_08878664;
      }
      goto L_08878654;
    }
L_08878654:
    ctx.set_gpr(4, 0u | 1u);
    goto L_08878658;
L_08878658:
    rt.memory().aot_store32(ctx.gpr[6] + static_cast<std::uint32_t>(22672), ctx.gpr[4]);
    goto L_0887865C;
L_0887865C:
    ctx.set_gpr(31, 0x08878664u);
    ctx.set_gpr(4, ctx.gpr[22] | 0u);
    ctx.pc = 0x089E7678u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08878664u) goto L_08878664;
    return;
L_08878664:
    ctx.set_gpr(4, 2207u << 16u);
    goto L_08878668;
L_08878668:
    rt.memory().aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(-25288), ctx.gpr[22]);
    goto L_0887866C;
L_0887866C:
    ctx.set_gpr(6, 2478u << 16u);
    goto L_08878670;
L_08878670:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[6] + static_cast<std::uint32_t>(22324)));
    goto L_08878674;
L_08878674:
    { const bool branch_taken = ctx.gpr[4] != 0u;
    ctx.set_gpr(21, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(92)));
      if (branch_taken) {
          goto L_08878698;
      }
      goto L_0887867C;
    }
L_0887867C:
    ctx.set_gpr(4, 0u | 1u);
    goto L_08878680;
L_08878680:
    rt.memory().aot_store32(ctx.gpr[6] + static_cast<std::uint32_t>(22324), ctx.gpr[4]);
    goto L_08878684;
L_08878684:
    ctx.set_gpr(31, 0x0887868Cu);
    ctx.set_gpr(4, ctx.gpr[23] | 0u);
    ctx.pc = 0x08A4ABFCu;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x0887868Cu) goto L_0887868C;
    return;
L_0887868C:
    ctx.set_gpr(4, 2205u << 16u);
    goto L_08878690;
L_08878690:
    ctx.set_gpr(31, 0x08878698u);
    ctx.set_gpr(4, ctx.gpr[4] + static_cast<std::uint32_t>(26188));
    ctx.pc = 0x08992F6Cu;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08878698u) goto L_08878698;
    return;
L_08878698:
    ctx.set_gpr(4, 2213u << 16u);
    goto L_0887869C;
L_0887869C:
    rt.memory().aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(-16132), ctx.gpr[23]);
    goto L_088786A0;
L_088786A0:
    ctx.set_gpr(6, 2478u << 16u);
    goto L_088786A4;
L_088786A4:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[6] + static_cast<std::uint32_t>(22224)));
    goto L_088786A8;
L_088786A8:
    { const bool branch_taken = ctx.gpr[4] != 0u;
    ctx.set_gpr(22, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(96)));
      if (branch_taken) {
          goto L_088786CC;
      }
      goto L_088786B0;
    }
L_088786B0:
    ctx.set_gpr(4, 0u | 1u);
    goto L_088786B4;
L_088786B4:
    rt.memory().aot_store32(ctx.gpr[6] + static_cast<std::uint32_t>(22224), ctx.gpr[4]);
    goto L_088786B8;
L_088786B8:
    ctx.set_gpr(31, 0x088786C0u);
    ctx.set_gpr(4, ctx.gpr[30] | 0u);
    ctx.pc = 0x08A4D4DCu;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x088786C0u) goto L_088786C0;
    return;
L_088786C0:
    ctx.set_gpr(4, 2205u << 16u);
    goto L_088786C4;
L_088786C4:
    ctx.set_gpr(31, 0x088786CCu);
    ctx.set_gpr(4, ctx.gpr[4] + static_cast<std::uint32_t>(26176));
    ctx.pc = 0x08992F6Cu;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x088786CCu) goto L_088786CC;
    return;
L_088786CC:
    ctx.set_gpr(4, 2213u << 16u);
    goto L_088786D0;
L_088786D0:
    rt.memory().aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(-12), ctx.gpr[30]);
    goto L_088786D4;
L_088786D4:
    ctx.set_gpr(6, 2478u << 16u);
    goto L_088786D8;
L_088786D8:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[6] + static_cast<std::uint32_t>(22128)));
    goto L_088786DC;
L_088786DC:
    { const bool branch_taken = ctx.gpr[4] != 0u;
    ctx.set_gpr(23, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(100)));
      if (branch_taken) {
          goto L_08878700;
      }
      goto L_088786E4;
    }
L_088786E4:
    ctx.set_gpr(4, 0u | 1u);
    goto L_088786E8;
L_088786E8:
    rt.memory().aot_store32(ctx.gpr[6] + static_cast<std::uint32_t>(22128), ctx.gpr[4]);
    goto L_088786EC;
L_088786EC:
    ctx.set_gpr(31, 0x088786F4u);
    ctx.set_gpr(4, ctx.gpr[16] | 0u);
    ctx.pc = 0x08A500A8u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x088786F4u) goto L_088786F4;
    return;
L_088786F4:
    ctx.set_gpr(4, 2205u << 16u);
    goto L_088786F8;
L_088786F8:
    ctx.set_gpr(31, 0x08878700u);
    ctx.set_gpr(4, ctx.gpr[4] + static_cast<std::uint32_t>(26164));
    ctx.pc = 0x08992F6Cu;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08878700u) goto L_08878700;
    return;
L_08878700:
    ctx.set_gpr(4, 2213u << 16u);
    goto L_08878704;
L_08878704:
    rt.memory().aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(7356), ctx.gpr[16]);
    goto L_08878708;
L_08878708:
    ctx.set_gpr(6, 2478u << 16u);
    goto L_0887870C;
L_0887870C:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[6] + static_cast<std::uint32_t>(18032)));
    goto L_08878710;
L_08878710:
    { const bool branch_taken = ctx.gpr[4] != 0u;
    ctx.set_gpr(30, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(104)));
      if (branch_taken) {
          goto L_08878734;
      }
      goto L_08878718;
    }
L_08878718:
    ctx.set_gpr(4, 0u | 1u);
    goto L_0887871C;
L_0887871C:
    rt.memory().aot_store32(ctx.gpr[6] + static_cast<std::uint32_t>(18032), ctx.gpr[4]);
    goto L_08878720;
L_08878720:
    ctx.set_gpr(31, 0x08878728u);
    ctx.set_gpr(4, ctx.gpr[17] | 0u);
    ctx.pc = 0x08A9CBDCu;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08878728u) goto L_08878728;
    return;
L_08878728:
    ctx.set_gpr(4, 2205u << 16u);
    goto L_0887872C;
L_0887872C:
    ctx.set_gpr(31, 0x08878734u);
    ctx.set_gpr(4, ctx.gpr[4] + static_cast<std::uint32_t>(26152));
    ctx.pc = 0x08992F6Cu;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08878734u) goto L_08878734;
    return;
L_08878734:
    ctx.set_gpr(4, 2218u << 16u);
    goto L_08878738;
L_08878738:
    rt.memory().aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(16196), ctx.gpr[17]);
    goto L_0887873C;
L_0887873C:
    ctx.set_gpr(6, 2478u << 16u);
    goto L_08878740;
L_08878740:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[6] + static_cast<std::uint32_t>(17388)));
    goto L_08878744;
L_08878744:
    { const bool branch_taken = ctx.gpr[4] != 0u;
    ctx.set_gpr(16, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(108)));
      if (branch_taken) {
          goto L_08878768;
      }
      goto L_0887874C;
    }
L_0887874C:
    ctx.set_gpr(4, 0u | 1u);
    goto L_08878750;
L_08878750:
    rt.memory().aot_store32(ctx.gpr[6] + static_cast<std::uint32_t>(17388), ctx.gpr[4]);
    goto L_08878754;
L_08878754:
    ctx.set_gpr(31, 0x0887875Cu);
    ctx.set_gpr(4, ctx.gpr[18] | 0u);
    ctx.pc = 0x08A6CBFCu;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x0887875Cu) goto L_0887875C;
    return;
L_0887875C:
    ctx.set_gpr(4, 2205u << 16u);
    goto L_08878760;
L_08878760:
    ctx.set_gpr(31, 0x08878768u);
    ctx.set_gpr(4, ctx.gpr[4] + static_cast<std::uint32_t>(26140));
    ctx.pc = 0x08992F6Cu;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08878768u) goto L_08878768;
    return;
L_08878768:
    ctx.set_gpr(4, 2215u << 16u);
    goto L_0887876C;
L_0887876C:
    rt.memory().aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(-10480), ctx.gpr[18]);
    goto L_08878770;
L_08878770:
    ctx.set_gpr(6, 2478u << 16u);
    goto L_08878774;
L_08878774:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[6] + static_cast<std::uint32_t>(17376)));
    goto L_08878778;
L_08878778:
    { const bool branch_taken = ctx.gpr[4] != 0u;
    ctx.set_gpr(17, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(112)));
      if (branch_taken) {
          goto L_08878790;
      }
      goto L_08878780;
    }
L_08878780:
    ctx.set_gpr(4, 0u | 1u);
    goto L_08878784;
L_08878784:
    rt.memory().aot_store32(ctx.gpr[6] + static_cast<std::uint32_t>(17376), ctx.gpr[4]);
    goto L_08878788;
L_08878788:
    ctx.set_gpr(31, 0x08878790u);
    ctx.set_gpr(4, ctx.gpr[19] | 0u);
    ctx.pc = 0x08A6D7CCu;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08878790u) goto L_08878790;
    return;
L_08878790:
    ctx.set_gpr(4, 2215u << 16u);
    goto L_08878794;
L_08878794:
    rt.memory().aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(-10272), ctx.gpr[19]);
    goto L_08878798;
L_08878798:
    ctx.set_gpr(6, 2478u << 16u);
    goto L_0887879C;
L_0887879C:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[6] + static_cast<std::uint32_t>(16576)));
    goto L_088787A0;
L_088787A0:
    { const bool branch_taken = ctx.gpr[4] != 0u;
    ctx.set_gpr(18, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(116)));
      if (branch_taken) {
          goto L_088787C4;
      }
      goto L_088787A8;
    }
L_088787A8:
    ctx.set_gpr(4, 0u | 1u);
    goto L_088787AC;
L_088787AC:
    rt.memory().aot_store32(ctx.gpr[6] + static_cast<std::uint32_t>(16576), ctx.gpr[4]);
    goto L_088787B0;
L_088787B0:
    ctx.set_gpr(31, 0x088787B8u);
    ctx.set_gpr(4, ctx.gpr[20] | 0u);
    ctx.pc = 0x08A8A194u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x088787B8u) goto L_088787B8;
    return;
L_088787B8:
    ctx.set_gpr(4, 2205u << 16u);
    goto L_088787BC;
L_088787BC:
    ctx.set_gpr(31, 0x088787C4u);
    ctx.set_gpr(4, ctx.gpr[4] + static_cast<std::uint32_t>(26128));
    ctx.pc = 0x08992F6Cu;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x088787C4u) goto L_088787C4;
    return;
L_088787C4:
    ctx.set_gpr(4, 2217u << 16u);
    goto L_088787C8;
L_088787C8:
    rt.memory().aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(-18520), ctx.gpr[20]);
    goto L_088787CC;
L_088787CC:
    ctx.set_gpr(6, 2478u << 16u);
    goto L_088787D0;
L_088787D0:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[6] + static_cast<std::uint32_t>(16224)));
    goto L_088787D4;
L_088787D4:
    { const bool branch_taken = ctx.gpr[4] != 0u;
    ctx.set_gpr(19, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(120)));
      if (branch_taken) {
          goto L_088787F8;
      }
      goto L_088787DC;
    }
L_088787DC:
    ctx.set_gpr(4, 0u | 1u);
    goto L_088787E0;
L_088787E0:
    rt.memory().aot_store32(ctx.gpr[6] + static_cast<std::uint32_t>(16224), ctx.gpr[4]);
    goto L_088787E4;
L_088787E4:
    ctx.set_gpr(31, 0x088787ECu);
    ctx.set_gpr(4, ctx.gpr[21] | 0u);
    ctx.pc = 0x08A87428u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x088787ECu) goto L_088787EC;
    return;
L_088787EC:
    ctx.set_gpr(4, 2205u << 16u);
    goto L_088787F0;
L_088787F0:
    ctx.set_gpr(31, 0x088787F8u);
    ctx.set_gpr(4, ctx.gpr[4] + static_cast<std::uint32_t>(26116));
    ctx.pc = 0x08992F6Cu;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x088787F8u) goto L_088787F8;
    return;
L_088787F8:
    ctx.set_gpr(4, 2216u << 16u);
    goto L_088787FC;
L_088787FC:
    rt.memory().aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(32428), ctx.gpr[21]);
    goto L_08878800;
L_08878800:
    ctx.set_gpr(6, 2478u << 16u);
    goto L_08878804;
L_08878804:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[6] + static_cast<std::uint32_t>(15880)));
    goto L_08878808;
L_08878808:
    { const bool branch_taken = ctx.gpr[4] != 0u;
    ctx.set_gpr(20, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(124)));
      if (branch_taken) {
          goto L_08878820;
      }
      goto L_08878810;
    }
L_08878810:
    ctx.set_gpr(4, 0u | 1u);
    goto L_08878814;
L_08878814:
    rt.memory().aot_store32(ctx.gpr[6] + static_cast<std::uint32_t>(15880), ctx.gpr[4]);
    goto L_08878818;
L_08878818:
    ctx.set_gpr(31, 0x08878820u);
    ctx.set_gpr(4, ctx.gpr[22] | 0u);
    ctx.pc = 0x08B53B88u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08878820u) goto L_08878820;
    return;
L_08878820:
    ctx.set_gpr(4, 2229u << 16u);
    goto L_08878824;
L_08878824:
    rt.memory().aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(16472), ctx.gpr[22]);
    goto L_08878828;
L_08878828:
    ctx.set_gpr(6, 2478u << 16u);
    goto L_0887882C;
L_0887882C:
    ctx.set_gpr(4, rt.memory().aot_load32(ctx.gpr[6] + static_cast<std::uint32_t>(15872)));
    goto L_08878830;
L_08878830:
    { const bool branch_taken = ctx.gpr[4] != 0u;
    ctx.set_gpr(21, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(128)));
      if (branch_taken) {
          goto L_08878848;
      }
      goto L_08878838;
    }
L_08878838:
    ctx.set_gpr(4, 0u | 1u);
    goto L_0887883C;
L_0887883C:
    rt.memory().aot_store32(ctx.gpr[6] + static_cast<std::uint32_t>(15872), ctx.gpr[4]);
    goto L_08878840;
L_08878840:
    ctx.set_gpr(31, 0x08878848u);
    ctx.set_gpr(4, ctx.gpr[23] | 0u);
    ctx.pc = 0x08A969CCu;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08878848u) goto L_08878848;
    return;
L_08878848:
    ctx.set_gpr(4, 2217u << 16u);
    goto L_0887884C;
L_0887884C:
    rt.memory().aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(27176), ctx.gpr[23]);
    goto L_08878850;
L_08878850:
    ctx.set_gpr(4, 2478u << 16u);
    goto L_08878854;
L_08878854:
    ctx.set_gpr(5, rt.memory().aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(15656)));
    goto L_08878858;
L_08878858:
    { const bool branch_taken = ctx.gpr[5] != 0u;
    ctx.set_gpr(22, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(132)));
      if (branch_taken) {
          goto L_08878870;
      }
      goto L_08878860;
    }
L_08878860:
    ctx.set_gpr(5, 0u | 1u);
    goto L_08878864;
L_08878864:
    rt.memory().aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(15656), ctx.gpr[5]);
    goto L_08878868;
L_08878868:
    ctx.set_gpr(31, 0x08878870u);
    ctx.set_gpr(4, ctx.gpr[30] | 0u);
    ctx.pc = 0x08B34C18u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08878870u) goto L_08878870;
    return;
L_08878870:
    ctx.set_gpr(4, 2228u << 16u);
    goto L_08878874;
L_08878874:
    rt.memory().aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(7360), ctx.gpr[30]);
    goto L_08878878;
L_08878878:
    ctx.set_gpr(4, 2478u << 16u);
    goto L_0887887C;
L_0887887C:
    ctx.set_gpr(5, rt.memory().aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(15592)));
    goto L_08878880;
L_08878880:
    { const bool branch_taken = ctx.gpr[5] != 0u;
    ctx.set_gpr(23, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(136)));
      if (branch_taken) {
          goto L_08878898;
      }
      goto L_08878888;
    }
L_08878888:
    ctx.set_gpr(5, 0u | 1u);
    goto L_0887888C;
L_0887888C:
    rt.memory().aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(15592), ctx.gpr[5]);
    goto L_08878890;
L_08878890:
    ctx.set_gpr(31, 0x08878898u);
    ctx.set_gpr(4, ctx.gpr[16] | 0u);
    ctx.pc = 0x08B41F00u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08878898u) goto L_08878898;
    return;
L_08878898:
    ctx.set_gpr(4, 2228u << 16u);
    goto L_0887889C;
L_0887889C:
    rt.memory().aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(8328), ctx.gpr[16]);
    goto L_088788A0;
L_088788A0:
    ctx.set_gpr(4, 2478u << 16u);
    goto L_088788A4;
L_088788A4:
    ctx.set_gpr(5, rt.memory().aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(15580)));
    goto L_088788A8;
L_088788A8:
    { const bool branch_taken = ctx.gpr[5] != 0u;
    ctx.set_gpr(30, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(140)));
      if (branch_taken) {
          goto L_088788C0;
      }
      goto L_088788B0;
    }
L_088788B0:
    ctx.set_gpr(5, 0u | 1u);
    goto L_088788B4;
L_088788B4:
    rt.memory().aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(15580), ctx.gpr[5]);
    goto L_088788B8;
L_088788B8:
    ctx.set_gpr(31, 0x088788C0u);
    ctx.set_gpr(4, ctx.gpr[17] | 0u);
    ctx.pc = 0x08B42AA0u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x088788C0u) goto L_088788C0;
    return;
L_088788C0:
    ctx.set_gpr(4, 2228u << 16u);
    goto L_088788C4;
L_088788C4:
    rt.memory().aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(11304), ctx.gpr[17]);
    goto L_088788C8;
L_088788C8:
    ctx.set_gpr(4, 2478u << 16u);
    goto L_088788CC;
L_088788CC:
    ctx.set_gpr(5, rt.memory().aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(15568)));
    goto L_088788D0;
L_088788D0:
    { const bool branch_taken = ctx.gpr[5] != 0u;
    ctx.set_gpr(16, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(144)));
      if (branch_taken) {
          goto L_088788F4;
      }
      goto L_088788D8;
    }
L_088788D8:
    ctx.set_gpr(5, 0u | 1u);
    goto L_088788DC;
L_088788DC:
    rt.memory().aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(15568), ctx.gpr[5]);
    goto L_088788E0;
L_088788E0:
    ctx.set_gpr(31, 0x088788E8u);
    ctx.set_gpr(4, ctx.gpr[18] | 0u);
    ctx.pc = 0x08B42234u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x088788E8u) goto L_088788E8;
    return;
L_088788E8:
    ctx.set_gpr(4, 2205u << 16u);
    goto L_088788EC;
L_088788EC:
    ctx.set_gpr(31, 0x088788F4u);
    ctx.set_gpr(4, ctx.gpr[4] + static_cast<std::uint32_t>(26104));
    ctx.pc = 0x08992F6Cu;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x088788F4u) goto L_088788F4;
    return;
L_088788F4:
    ctx.set_gpr(5, 2228u << 16u);
    goto L_088788F8;
L_088788F8:
    ctx.set_gpr(4, 2478u << 16u);
    goto L_088788FC;
L_088788FC:
    rt.memory().aot_store32(ctx.gpr[5] + static_cast<std::uint32_t>(8840), ctx.gpr[18]);
    goto L_08878900;
L_08878900:
    ctx.set_gpr(5, rt.memory().aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(15544)));
    goto L_08878904;
L_08878904:
    { const bool branch_taken = ctx.gpr[5] != 0u;
    ctx.set_gpr(5, 0u | 1u);
      if (branch_taken) {
          goto L_08878924;
      }
      goto L_0887890C;
    }
L_0887890C:
    rt.memory().aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(15544), ctx.gpr[5]);
    goto L_08878910;
L_08878910:
    ctx.set_gpr(31, 0x08878918u);
    ctx.set_gpr(4, ctx.gpr[19] | 0u);
    ctx.pc = 0x08B44750u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08878918u) goto L_08878918;
    return;
L_08878918:
    ctx.set_gpr(4, 2205u << 16u);
    goto L_0887891C;
L_0887891C:
    ctx.set_gpr(31, 0x08878924u);
    ctx.set_gpr(4, ctx.gpr[4] + static_cast<std::uint32_t>(26092));
    ctx.pc = 0x08992F6Cu;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08878924u) goto L_08878924;
    return;
L_08878924:
    ctx.set_gpr(5, 2228u << 16u);
    goto L_08878928;
L_08878928:
    ctx.set_gpr(4, 2478u << 16u);
    goto L_0887892C;
L_0887892C:
    rt.memory().aot_store32(ctx.gpr[5] + static_cast<std::uint32_t>(20232), ctx.gpr[19]);
    goto L_08878930;
L_08878930:
    ctx.set_gpr(5, rt.memory().aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(15532)));
    goto L_08878934;
L_08878934:
    { const bool branch_taken = ctx.gpr[5] != 0u;
    ctx.set_gpr(5, 0u | 1u);
      if (branch_taken) {
          goto L_08878954;
      }
      goto L_0887893C;
    }
L_0887893C:
    rt.memory().aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(15532), ctx.gpr[5]);
    goto L_08878940;
L_08878940:
    ctx.set_gpr(31, 0x08878948u);
    ctx.set_gpr(4, ctx.gpr[20] | 0u);
    ctx.pc = 0x08B45444u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08878948u) goto L_08878948;
    return;
L_08878948:
    ctx.set_gpr(4, 2205u << 16u);
    goto L_0887894C;
L_0887894C:
    ctx.set_gpr(31, 0x08878954u);
    ctx.set_gpr(4, ctx.gpr[4] + static_cast<std::uint32_t>(26080));
    ctx.pc = 0x08992F6Cu;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08878954u) goto L_08878954;
    return;
L_08878954:
    ctx.set_gpr(5, 2228u << 16u);
    goto L_08878958;
L_08878958:
    ctx.set_gpr(4, 2478u << 16u);
    goto L_0887895C;
L_0887895C:
    rt.memory().aot_store32(ctx.gpr[5] + static_cast<std::uint32_t>(22648), ctx.gpr[20]);
    goto L_08878960;
L_08878960:
    ctx.set_gpr(5, rt.memory().aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(15520)));
    goto L_08878964;
L_08878964:
    { const bool branch_taken = ctx.gpr[5] != 0u;
    ctx.set_gpr(5, 0u | 1u);
      if (branch_taken) {
          goto L_08878984;
      }
      goto L_0887896C;
    }
L_0887896C:
    rt.memory().aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(15520), ctx.gpr[5]);
    goto L_08878970;
L_08878970:
    ctx.set_gpr(31, 0x08878978u);
    ctx.set_gpr(4, ctx.gpr[21] | 0u);
    ctx.pc = 0x08B43620u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08878978u) goto L_08878978;
    return;
L_08878978:
    ctx.set_gpr(4, 2205u << 16u);
    goto L_0887897C;
L_0887897C:
    ctx.set_gpr(31, 0x08878984u);
    ctx.set_gpr(4, ctx.gpr[4] + static_cast<std::uint32_t>(26068));
    ctx.pc = 0x08992F6Cu;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08878984u) goto L_08878984;
    return;
L_08878984:
    ctx.set_gpr(5, 2228u << 16u);
    goto L_08878988;
L_08878988:
    ctx.set_gpr(4, 2478u << 16u);
    goto L_0887898C;
L_0887898C:
    rt.memory().aot_store32(ctx.gpr[5] + static_cast<std::uint32_t>(14528), ctx.gpr[21]);
    goto L_08878990;
L_08878990:
    ctx.set_gpr(5, rt.memory().aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(15500)));
    goto L_08878994;
L_08878994:
    { const bool branch_taken = ctx.gpr[5] != 0u;
    ctx.set_gpr(5, 0u | 1u);
      if (branch_taken) {
          goto L_088789B4;
      }
      goto L_0887899C;
    }
L_0887899C:
    rt.memory().aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(15500), ctx.gpr[5]);
    goto L_088789A0;
L_088789A0:
    ctx.set_gpr(31, 0x088789A8u);
    ctx.set_gpr(4, ctx.gpr[22] | 0u);
    ctx.pc = 0x08B42368u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x088789A8u) goto L_088789A8;
    return;
L_088789A8:
    ctx.set_gpr(4, 2205u << 16u);
    goto L_088789AC;
L_088789AC:
    ctx.set_gpr(31, 0x088789B4u);
    ctx.set_gpr(4, ctx.gpr[4] + static_cast<std::uint32_t>(26056));
    ctx.pc = 0x08992F6Cu;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x088789B4u) goto L_088789B4;
    return;
L_088789B4:
    ctx.set_gpr(5, 2228u << 16u);
    goto L_088789B8;
L_088789B8:
    ctx.set_gpr(4, 2478u << 16u);
    goto L_088789BC;
L_088789BC:
    rt.memory().aot_store32(ctx.gpr[5] + static_cast<std::uint32_t>(9904), ctx.gpr[22]);
    goto L_088789C0;
L_088789C0:
    ctx.set_gpr(5, rt.memory().aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(15488)));
    goto L_088789C4;
L_088789C4:
    { const bool branch_taken = ctx.gpr[5] != 0u;
    ctx.set_gpr(5, 0u | 1u);
      if (branch_taken) {
          goto L_088789E4;
      }
      goto L_088789CC;
    }
L_088789CC:
    rt.memory().aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(15488), ctx.gpr[5]);
    goto L_088789D0;
L_088789D0:
    ctx.set_gpr(31, 0x088789D8u);
    ctx.set_gpr(4, ctx.gpr[23] | 0u);
    ctx.pc = 0x08B42A04u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x088789D8u) goto L_088789D8;
    return;
L_088789D8:
    ctx.set_gpr(4, 2205u << 16u);
    goto L_088789DC;
L_088789DC:
    ctx.set_gpr(31, 0x088789E4u);
    ctx.set_gpr(4, ctx.gpr[4] + static_cast<std::uint32_t>(26044));
    ctx.pc = 0x08992F6Cu;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x088789E4u) goto L_088789E4;
    return;
L_088789E4:
    ctx.set_gpr(5, 2228u << 16u);
    goto L_088789E8;
L_088789E8:
    ctx.set_gpr(4, 2478u << 16u);
    goto L_088789EC;
L_088789EC:
    rt.memory().aot_store32(ctx.gpr[5] + static_cast<std::uint32_t>(10904), ctx.gpr[23]);
    goto L_088789F0;
L_088789F0:
    ctx.set_gpr(5, rt.memory().aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(15120)));
    goto L_088789F4;
L_088789F4:
    { const bool branch_taken = ctx.gpr[5] != 0u;
    ctx.set_gpr(5, 0u | 1u);
      if (branch_taken) {
          goto L_08878A08;
      }
      goto L_088789FC;
    }
L_088789FC:
    rt.memory().aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(15120), ctx.gpr[5]);
    goto L_08878A00;
L_08878A00:
    ctx.set_gpr(31, 0x08878A08u);
    ctx.set_gpr(4, ctx.gpr[30] | 0u);
    ctx.pc = 0x08B54060u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08878A08u) goto L_08878A08;
    return;
L_08878A08:
    ctx.set_gpr(5, 2229u << 16u);
    goto L_08878A0C;
L_08878A0C:
    ctx.set_gpr(4, 2478u << 16u);
    goto L_08878A10;
L_08878A10:
    rt.memory().aot_store32(ctx.gpr[5] + static_cast<std::uint32_t>(19512), ctx.gpr[30]);
    goto L_08878A14;
L_08878A14:
    ctx.set_gpr(5, rt.memory().aot_load32(ctx.gpr[4] + static_cast<std::uint32_t>(15112)));
    goto L_08878A18;
L_08878A18:
    { const bool branch_taken = ctx.gpr[5] != 0u;
    ctx.set_gpr(5, 0u | 1u);
      if (branch_taken) {
          goto L_08878A38;
      }
      goto L_08878A20;
    }
L_08878A20:
    rt.memory().aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(15112), ctx.gpr[5]);
    goto L_08878A24;
L_08878A24:
    ctx.set_gpr(31, 0x08878A2Cu);
    ctx.set_gpr(4, ctx.gpr[16] | 0u);
    ctx.pc = 0x08B58B30u;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08878A2Cu) goto L_08878A2C;
    return;
L_08878A2C:
    ctx.set_gpr(4, 2205u << 16u);
    goto L_08878A30;
L_08878A30:
    ctx.set_gpr(31, 0x08878A38u);
    ctx.set_gpr(4, ctx.gpr[4] + static_cast<std::uint32_t>(26032));
    ctx.pc = 0x08992F6Cu;
    if (rt.invoke_chained_call(ctx, &aot_mem) && ctx.pc == 0x08878A38u) goto L_08878A38;
    return;
L_08878A38:
    ctx.set_gpr(4, 2230u << 16u);
    goto L_08878A3C;
L_08878A3C:
    rt.memory().aot_store32(ctx.gpr[4] + static_cast<std::uint32_t>(-28112), ctx.gpr[16]);
    goto L_08878A40;
L_08878A40:
    ctx.set_gpr(16, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(148)));
    goto L_08878A44;
L_08878A44:
    ctx.set_gpr(17, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(152)));
    goto L_08878A48;
L_08878A48:
    ctx.set_gpr(18, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(156)));
    goto L_08878A4C;
L_08878A4C:
    ctx.set_gpr(19, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(160)));
    goto L_08878A50;
L_08878A50:
    ctx.set_gpr(20, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(164)));
    goto L_08878A54;
L_08878A54:
    ctx.set_gpr(21, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(168)));
    goto L_08878A58;
L_08878A58:
    ctx.set_gpr(22, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(172)));
    goto L_08878A5C;
L_08878A5C:
    ctx.set_gpr(23, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(176)));
    goto L_08878A60;
L_08878A60:
    ctx.set_gpr(30, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(180)));
    goto L_08878A64;
L_08878A64:
    ctx.set_gpr(31, rt.memory().aot_load32(ctx.gpr[29] + static_cast<std::uint32_t>(184)));
    goto L_08878A68;
L_08878A68:
    jump_target = ctx.gpr[31];
    ctx.set_gpr(29, ctx.gpr[29] + static_cast<std::uint32_t>(192));
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    ctx.pc = jump_target;
    return;
}

void recomp_unit_0015(Runtime &rt, AllegrexContext &ctx) {
    auto aot_mem = rt.memory().aot_fast_view();
    recomp_unit_0015_entry(rt, ctx, 0u, aot_mem);
}

void register_generated_unit_15(Runtime &runtime) {
    runtime.register_generated_unit(15u, 0x089E4040u, 131072u, &recomp_unit_0015, &recomp_unit_0015_entry);
    runtime.register_function(0x0887801Cu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878020u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878024u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878028u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x0887802Cu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878030u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878034u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878038u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x0887803Cu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878040u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878044u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878048u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x0887804Cu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878050u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878054u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878058u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x0887805Cu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878060u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878064u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878068u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x0887806Cu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878070u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878074u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878078u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x0887807Cu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878080u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878084u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878088u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x0887808Cu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878090u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878094u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878098u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x0887809Cu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088780A0u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088780A4u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088780A8u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088780ACu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088780B0u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088780B4u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088780B8u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088780BCu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088780C0u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088780C4u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088780C8u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088780CCu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088780D0u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088780D4u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088780D8u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088780DCu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088780E0u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088780E4u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088780E8u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088780ECu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088780F0u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088780F4u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088780F8u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088780FCu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878100u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878104u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878108u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x0887810Cu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878110u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878114u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878118u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x0887811Cu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878120u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878124u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878128u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x0887812Cu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878130u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878134u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878138u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x0887813Cu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878140u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878144u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878148u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x0887814Cu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878150u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878154u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878158u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x0887815Cu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878160u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878164u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878168u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x0887816Cu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878170u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878174u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878178u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x0887817Cu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878180u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878184u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878188u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x0887818Cu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878190u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878194u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878198u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x0887819Cu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088781A0u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088781A4u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088781A8u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088781ACu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088781B0u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088781B4u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088781B8u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088781BCu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088781C0u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088781C4u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088781C8u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088781CCu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088781D0u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088781D4u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088781D8u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088781DCu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088781E0u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088781E4u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088781E8u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088781ECu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088781F0u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088781F4u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088781F8u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088781FCu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878200u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878204u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878208u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x0887820Cu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878210u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878214u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878218u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x0887821Cu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878220u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878224u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878228u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x0887822Cu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878230u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878234u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878238u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x0887823Cu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878240u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878248u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x0887824Cu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878250u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878258u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x0887825Cu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878264u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878268u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x0887826Cu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878270u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878278u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x0887827Cu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878284u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878288u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878290u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878294u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878298u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x0887829Cu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088782A0u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088782A8u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088782ACu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088782B0u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088782B8u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088782BCu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088782C4u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088782C8u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088782CCu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088782D0u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088782D4u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088782DCu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088782E0u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088782E4u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088782ECu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088782F0u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088782F8u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088782FCu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878300u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878304u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878308u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878310u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878314u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878318u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878320u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878324u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x0887832Cu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878330u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878334u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878338u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x0887833Cu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878340u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878348u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x0887834Cu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878350u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878358u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x0887835Cu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878364u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878368u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x0887836Cu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878370u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878374u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x0887837Cu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878380u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878384u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x0887838Cu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878390u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878398u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x0887839Cu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088783A0u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088783A4u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088783A8u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088783B0u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088783B4u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088783B8u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088783C0u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088783C4u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088783CCu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088783D0u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088783D4u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088783D8u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088783DCu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088783E4u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088783E8u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088783ECu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088783F4u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088783F8u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878400u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878404u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878408u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x0887840Cu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878410u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878418u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x0887841Cu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878420u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878428u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x0887842Cu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878434u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878438u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x0887843Cu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878440u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878444u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x0887844Cu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878450u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878454u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x0887845Cu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878460u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878468u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x0887846Cu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878470u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878474u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878478u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878480u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878484u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878488u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878490u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878494u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x0887849Cu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088784A0u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088784A4u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088784A8u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088784ACu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088784B4u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088784B8u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088784BCu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088784C4u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088784C8u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088784D0u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088784D4u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088784D8u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088784DCu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088784E0u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088784E8u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088784ECu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088784F0u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088784F8u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088784FCu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878504u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878508u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x0887850Cu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878510u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878514u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x0887851Cu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878520u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878524u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x0887852Cu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878530u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878538u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x0887853Cu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878540u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878544u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878548u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878550u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878554u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878558u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878560u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878564u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x0887856Cu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878570u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878574u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878578u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x0887857Cu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878584u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878588u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x0887858Cu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878594u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878598u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088785A0u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088785A4u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088785A8u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088785ACu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088785B0u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088785B8u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088785BCu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088785C0u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088785C8u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088785CCu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088785D4u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088785D8u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088785DCu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088785E0u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088785E4u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088785ECu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088785F0u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088785F4u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088785FCu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878600u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878608u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x0887860Cu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878610u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878614u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878618u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878620u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878624u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878628u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878630u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878634u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x0887863Cu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878640u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878644u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878648u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x0887864Cu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878654u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878658u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x0887865Cu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878664u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878668u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x0887866Cu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878670u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878674u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x0887867Cu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878680u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878684u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x0887868Cu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878690u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878698u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x0887869Cu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088786A0u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088786A4u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088786A8u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088786B0u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088786B4u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088786B8u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088786C0u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088786C4u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088786CCu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088786D0u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088786D4u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088786D8u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088786DCu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088786E4u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088786E8u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088786ECu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088786F4u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088786F8u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878700u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878704u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878708u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x0887870Cu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878710u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878718u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x0887871Cu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878720u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878728u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x0887872Cu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878734u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878738u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x0887873Cu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878740u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878744u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x0887874Cu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878750u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878754u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x0887875Cu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878760u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878768u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x0887876Cu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878770u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878774u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878778u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878780u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878784u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878788u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878790u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878794u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878798u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x0887879Cu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088787A0u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088787A8u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088787ACu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088787B0u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088787B8u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088787BCu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088787C4u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088787C8u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088787CCu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088787D0u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088787D4u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088787DCu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088787E0u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088787E4u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088787ECu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088787F0u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088787F8u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088787FCu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878800u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878804u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878808u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878810u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878814u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878818u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878820u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878824u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878828u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x0887882Cu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878830u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878838u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x0887883Cu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878840u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878848u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x0887884Cu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878850u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878854u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878858u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878860u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878864u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878868u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878870u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878874u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878878u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x0887887Cu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878880u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878888u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x0887888Cu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878890u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878898u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x0887889Cu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088788A0u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088788A4u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088788A8u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088788B0u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088788B4u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088788B8u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088788C0u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088788C4u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088788C8u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088788CCu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088788D0u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088788D8u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088788DCu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088788E0u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088788E8u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088788ECu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088788F4u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088788F8u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088788FCu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878900u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878904u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x0887890Cu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878910u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878918u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x0887891Cu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878924u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878928u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x0887892Cu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878930u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878934u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x0887893Cu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878940u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878948u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x0887894Cu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878954u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878958u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x0887895Cu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878960u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878964u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x0887896Cu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878970u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878978u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x0887897Cu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878984u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878988u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x0887898Cu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878990u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878994u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x0887899Cu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088789A0u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088789A8u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088789ACu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088789B4u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088789B8u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088789BCu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088789C0u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088789C4u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088789CCu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088789D0u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088789D8u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088789DCu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088789E4u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088789E8u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088789ECu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088789F0u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088789F4u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x088789FCu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878A00u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878A08u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878A0Cu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878A10u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878A14u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878A18u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878A20u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878A24u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878A2Cu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878A30u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878A38u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878A3Cu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878A40u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878A44u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878A48u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878A4Cu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878A50u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878A54u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878A58u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878A5Cu, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878A60u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878A64u, &recomp_unit_0015, "recomp_unit_0015");
    runtime.register_function(0x08878A68u, &recomp_unit_0015, "recomp_unit_0015");
}
} // namespace psprecomp

