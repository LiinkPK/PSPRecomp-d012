#pragma once

#include <cstdint>
#include "psprecomp/guest_memory.hpp"

namespace psprecomp {
class Runtime;
struct AllegrexContext;
void recomp_unit_0000(Runtime &, AllegrexContext &);
void recomp_unit_0000_entry(Runtime &, AllegrexContext &, std::uint16_t, GuestMemory::AotFastView &);
void recomp_unit_0001(Runtime &, AllegrexContext &);
void recomp_unit_0001_entry(Runtime &, AllegrexContext &, std::uint16_t, GuestMemory::AotFastView &);
void recomp_unit_0002(Runtime &, AllegrexContext &);
void recomp_unit_0002_entry(Runtime &, AllegrexContext &, std::uint16_t, GuestMemory::AotFastView &);
void recomp_unit_0003(Runtime &, AllegrexContext &);
void recomp_unit_0003_entry(Runtime &, AllegrexContext &, std::uint16_t, GuestMemory::AotFastView &);
void recomp_unit_0004(Runtime &, AllegrexContext &);
void recomp_unit_0004_entry(Runtime &, AllegrexContext &, std::uint16_t, GuestMemory::AotFastView &);
void recomp_unit_0005(Runtime &, AllegrexContext &);
void recomp_unit_0005_entry(Runtime &, AllegrexContext &, std::uint16_t, GuestMemory::AotFastView &);
void recomp_unit_0006(Runtime &, AllegrexContext &);
void recomp_unit_0006_entry(Runtime &, AllegrexContext &, std::uint16_t, GuestMemory::AotFastView &);
void recomp_unit_0007(Runtime &, AllegrexContext &);
void recomp_unit_0007_entry(Runtime &, AllegrexContext &, std::uint16_t, GuestMemory::AotFastView &);
void recomp_unit_0008(Runtime &, AllegrexContext &);
void recomp_unit_0008_entry(Runtime &, AllegrexContext &, std::uint16_t, GuestMemory::AotFastView &);
void recomp_unit_0009(Runtime &, AllegrexContext &);
void recomp_unit_0009_entry(Runtime &, AllegrexContext &, std::uint16_t, GuestMemory::AotFastView &);
void recomp_unit_0010(Runtime &, AllegrexContext &);
void recomp_unit_0010_entry(Runtime &, AllegrexContext &, std::uint16_t, GuestMemory::AotFastView &);
void recomp_unit_0011(Runtime &, AllegrexContext &);
void recomp_unit_0011_entry(Runtime &, AllegrexContext &, std::uint16_t, GuestMemory::AotFastView &);
void recomp_unit_0012(Runtime &, AllegrexContext &);
void recomp_unit_0012_entry(Runtime &, AllegrexContext &, std::uint16_t, GuestMemory::AotFastView &);
void recomp_unit_0013(Runtime &, AllegrexContext &);
void recomp_unit_0013_entry(Runtime &, AllegrexContext &, std::uint16_t, GuestMemory::AotFastView &);
void recomp_unit_0014(Runtime &, AllegrexContext &);
void recomp_unit_0014_entry(Runtime &, AllegrexContext &, std::uint16_t, GuestMemory::AotFastView &);
// Branch targets beyond the recompiled code (data and heap); no body exists for them.
void recomp_unit_0015(Runtime &, AllegrexContext &);
void recomp_unit_0015_entry(Runtime &, AllegrexContext &, std::uint16_t, GuestMemory::AotFastView &);
void recomp_unit_0016(Runtime &, AllegrexContext &);
void recomp_unit_0016_entry(Runtime &, AllegrexContext &, std::uint16_t, GuestMemory::AotFastView &);
void recomp_unit_0017(Runtime &, AllegrexContext &);
void recomp_unit_0017_entry(Runtime &, AllegrexContext &, std::uint16_t, GuestMemory::AotFastView &);
void recomp_unit_0018(Runtime &, AllegrexContext &);
void recomp_unit_0018_entry(Runtime &, AllegrexContext &, std::uint16_t, GuestMemory::AotFastView &);
void recomp_unit_0019(Runtime &, AllegrexContext &);
void recomp_unit_0019_entry(Runtime &, AllegrexContext &, std::uint16_t, GuestMemory::AotFastView &);
void recomp_unit_0020(Runtime &, AllegrexContext &);
void recomp_unit_0020_entry(Runtime &, AllegrexContext &, std::uint16_t, GuestMemory::AotFastView &);
void recomp_unit_0021(Runtime &, AllegrexContext &);
void recomp_unit_0021_entry(Runtime &, AllegrexContext &, std::uint16_t, GuestMemory::AotFastView &);
void recomp_unit_0022(Runtime &, AllegrexContext &);
void recomp_unit_0022_entry(Runtime &, AllegrexContext &, std::uint16_t, GuestMemory::AotFastView &);
void recomp_unit_0023(Runtime &, AllegrexContext &);
void recomp_unit_0023_entry(Runtime &, AllegrexContext &, std::uint16_t, GuestMemory::AotFastView &);
void recomp_unit_0024(Runtime &, AllegrexContext &);
void recomp_unit_0024_entry(Runtime &, AllegrexContext &, std::uint16_t, GuestMemory::AotFastView &);
void recomp_unit_0025(Runtime &, AllegrexContext &);
void recomp_unit_0025_entry(Runtime &, AllegrexContext &, std::uint16_t, GuestMemory::AotFastView &);
void recomp_unit_0026(Runtime &, AllegrexContext &);
void recomp_unit_0026_entry(Runtime &, AllegrexContext &, std::uint16_t, GuestMemory::AotFastView &);
void recomp_unit_0042(Runtime &, AllegrexContext &);
void recomp_unit_0042_entry(Runtime &, AllegrexContext &, std::uint16_t, GuestMemory::AotFastView &);
void recomp_unit_0136(Runtime &, AllegrexContext &);
void recomp_unit_0136_entry(Runtime &, AllegrexContext &, std::uint16_t, GuestMemory::AotFastView &);
} // namespace psprecomp
