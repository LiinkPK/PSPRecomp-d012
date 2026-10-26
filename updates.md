# PSPRecomp â€“ Dissidia 012 (ULES01505.BIN) â€“ Current State

**Last updated:** 22/10/2026 (Session 13)

**Goal:** Genuinely boot Dissidia 012â€™s original startup path and visibly render the authentic Square Enix logo through guest asset I/O â†’ guest VRAM â†’ GE â†’ the native window. A blank window, hard-coded logo, placeholder, or host overlay does not count.

### Consolidated Sessions 9â€“11

- **Session 9 â€” Scene discovery:** Init completed and the guest created the Square Enix scene (`0x2713`) in the pending-scene list. Activation and drawable GE commands were still absent.
- **Session 10 â€” Real startup I/O:** A visible native run loaded the real archive data into guest memory and presented guest VRAM without a host-side logo. GE execution remained state-only (`GE-PRIM=0`, `GE-CLEAR=0`, `GE-VDATA=0`).
- **Session 11 â€” Dispatch and GE stability:** Cross-unit dispatch and several GE crashes were corrected. The executable reaches real MPK loading and presents a native window, but malformed archive state still prevents scene geometry. The authentic logo remained unverified.
- **Session 12 â€” MPK corruption traced and allocator fixed:** Real embedded assets load and the framebuffer path is active. The root cause was empty `sceKernelAllocMemoryBlock`/`sceKernelGetMemoryBlockAddr` stubs at `0x089C5F38`/`0x089C5F20`; they left the effect allocator with a stale address, causing the `0x38AAF` copy to overlap MPK table `0x089CC268`. Both syscall bodies now use the existing guest heap allocator. The fix compiles, but has not yet been run; the logo remains unverified.

**Project:** `C:\path\to\your\folder\PSPRecomp`  
**Build:** `cmake --build out\d012 --config Release` â†’ binary at `out\d012\profiles\d012\Release\d012_native.exe`  
**Run:** `.\d012_native.exe "C:\path\to\original\ULES01505_FFSTJP.BIN"`

---

## How the runtime works

- PSP RAM is a flat host buffer. Guest addresses like `0x08804040` map directly into it.
- Functions are split into **units** of `0x20000` bytes. Unit N covers `0x08804040 + N*0x20000`.
- Each unit is one giant C++ function (`recomp_unit_000N`) with a `LOCAL_DISPATCH` switch on `ctx.pc`.
- Calling between units uses `invoke_chained_direct<&unit_entry, UnitIdx, EntryID, TargetPC>` or `invoke_chained_call` (dynamic).
- **Poisoning rule:** Registering a stub with a name NOT starting with `"recomp_unit_"` disables ALL generated code in that unit. Never register HLE stubs at addresses inside a unit you need working. Add the stub body directly as a label inside the generated unit file instead.
- `lookup_function_override(addr)` only returns a stub if `direct_chainable_[idx] == nullptr` (i.e. the name does NOT start with `"recomp_unit_"`).
- **All PSP syscall stubs live in unit 14** (`generated_unit_0014.cpp`). HLE implementations go there as label bodies, NOT in `d012_profile.cpp` via `s_handlers[]`.

---

## How to add a missing function

When `invoke_chained_call` hits an unregistered address â†’ null-PC crash. Fix:

1. Find which unit: `unit = (addr - 0x08804040) / 0x20000`
2. Open `profiles/d012/generated/generated_unit_000N.cpp`
3. Add `case 0xADDRu: goto L_ADDR;` in the `LOCAL_DISPATCH` switch (keep sorted)
4. Add the label + body before the next label (real logic or no-op return)
5. Add `runtime.register_function(0xADDRu, &recomp_unit_000N, "recomp_unit_000N");` in the bottom init function
6. Do **NOT** add it to `d012_profile.cpp` unless the address is outside all unit ranges

**No-op stub pattern:**
```cpp
L_0XXXXXXX: // brief description
    { static bool once=false; if(!once){once=true; std::printf("[HLE] 0XXXXXXX skipped\n");} }
    ctx.gpr[2] = 0u;
    jump_target = ctx.gpr[31];
    ctx.pc = jump_target;
    local_pc = jump_target;
    if (++local_transfers < 2048u) { entry_id = 0u; goto LOCAL_DISPATCH; }
    return;
```

**Build and run:**
```
cmake --build C:\path\to\your\folder\PSPRecomp\out\d012 --config Release
cd C:\path\to\your\folder\PSPRecomp\out\d012\profiles\d012\Release
.\d012_native.exe "C:\path\to\your\folder\PSPRecomp\original\ULES01505_FFSTJP.BIN"
```

**Pseudocode** for any address: `pseudocode/XXXXXXXX.c` (root of the repo)

---

## GE (Graphics Engine) subsystem â€” what was done

The game has its own internal GE manager (does **not** import `sceGeListEnQueue`/`sceGeDrawSync`). Only imports: `sceGeListSync`, `sceGeUnsetCallback`, `sceGeListEnQueueHead`, `sceGeEdramGetSize`, `sceGeContinue`.

**Key addresses in unit 12 (`generated_unit_0012.cpp`):**

- `L_0899F5A4`: internal GE list enqueue. `gpr[4]` = list base (DL buffer), `gpr[5]` = stall address.
- `L_0899F630` (line ~49711). Writes slot fields. `slot+8` = display list write pointer.
- `GE_struct` = `0x09AF67A8`. `GE_struct+72` = active slot pointer.
- `DAT_09af6830` = `base+26672` = slot pointer used by all GE command writers.
- Ring buffer: 5 slots at stride 252 bytes, base at `GE_struct+76 = 0x09AF67F4`.

**Crashes fixed:**

| Crash addr | Root cause | Fix |
|---|---|---|
| `0x00000008` | `GE_struct+72` null-deref | Null guard at `L_089A0330`; commented-out zero-store in `L_089A00A4` |
| `0x000000A8` | `DAT_09af6830` null | 52 null+range guards at all `base+26672` load sites |
| `0x00000010` | `GE_struct+72` zeroed via error path `L_0899F7F8` | Commented-out zero-store in `L_0899F7F8` |
| `0x50000009` | `dlptr = 0x9F000200` passes null check but fails range | Upgraded all 52 guards to range-check: `< 0x08800000 \|\| >= 0x09F00000` |
| `0x9F000208` | `slot+8` stored `stall & 0x1FFFFFFF = 0x1F000200` instead of list base | `L_0899F630` line ~49715: store `gpr[16] & 0x0FFFFFFF` (list base). Follows PPSSPP: `slot.pc = startpc = list & 0x0FFFFFFF` |
| Infinite loop / null-PC on cmds 0â€“21 | `L_089A1308` emitted as indirect jump through `RAM[table+cmd*4]`, recompiler mis-decoded MIPS switch table as a jump-through-pointer. Actual function `FUN_089a12fc` is a switch that writes one GE DL word per cmd. | Replaced `L_089A1308` with full switch implementation from pseudocode. Also added unit-14 no-op stubs + `register_function` for `0x089D18F8`â€“`0x089D1948`. |

---

## Display subsystem â€” current state

`sceDisplaySetFrameBuf` is called every frame (confirmed). Double-buffered:
- Front buffer: `0x04000000` (PSP VRAM offset 0)
- Back buffer: `0x04044000` (PSP VRAM offset 0x44000)
- Format: RGB565 (`fmt=1`), width 512, height 272

VRAM is accessible via `rt.memory().vram_bytes()`. A host window (SDL2/Win32) is needed to blit it.

**Display state machine** (`FUN_08865ED0`, task fn=`0x08865ED0`):
- State 0 = idle, calls `FUN_0886598c` (GE render list writer) each frame
- State 1â†’2â†’3 = triggered by `FUN_08866178` on stereo mode change; runs display setup chain
- The state machine is registered as a task and dispatched by the task scheduler every frame

**Task scheduler** (`FUN_0888245C`, unit 3): confirmed working. Tasks dispatched each frame:

| fn VA | Name | Purpose |
|---|---|---|
| `0x08865E98` | GRAPHICS::DlSendTask | calls `FUN_08865918` if state==0 |
| `0x08865ED0` | GRAPHICS::DlStartTask | display state machine |
| `0x08865FD8` | GRAPHICS::DlFinishTask | calls `FUN_08865E50` if state==0 |
| `0x088838F8` | (unknown) | fires every frame |
| `0x08883EE8` | (unknown) | fires every frame |

---

## HLE stub placement rule (learned the hard way)

All PSP import stubs cluster in unit 14 (`0x089C4040`â€“`0x089C6040`). The generated unit already has `jr $ra / nop` for each stub VA and registers them as `"recomp_unit_0014"`. This means:

- `s_handlers[VA]` in `d012_profile.cpp` is **never reached**. The generated unit intercepts first
- `register_hle(library, nid, fn)` is also dead for these â€” `invoke_import` is never called from AOT units

**Fix:** Implement all HLE logic directly as label bodies in `generated_unit_0014.cpp`.

---

## Files modified (beyond original recompiler output)

| File | What changed |
|---|---|
| `profiles/d012/generated/generated_unit_0012.cpp` | GE ring buffer fixes (see table above). `L_0899F630`: `slot+8` now stores list base. `L_089A00A4` + `L_0899F7F8`: zeroing of `GE_struct+72` / slot pointer commented out. 52 null+range guards on all `base+26672` load sites. `L_089A22A4` GE init: sets `DAT_09af6830` to slot-0 address on startup. |
| `profiles/d012/generated/generated_unit_0003.cpp` | Debug trace at `L_0888251C` (task dispatcher): logs first 5 dispatches + every 4096th. Temporary debug prints at other labels. |
| `profiles/d012/generated/generated_unit_0014.cpp` | `L_089C5AC0` (`sceDisplaySetFrameBuf`): logs call + returns 0. `L_089C5AE0` (`sceDisplaySetMode`): logs once + returns 0. `L_089C5EA8` (`sceIoOpen`): logs path + returns -2 (ENOENT). |
| `profiles/d012/generated/generated_unit_0002.cpp` | `L_08863208` (UMD init stub), `L_0886330C` (resource loader no-op), dispatch cases + `register_function` entries. |
| `profiles/d012/host/d012_profile.cpp` | Renamed `cpususpendintr`/`cpuresumeintr` stubs to `"recomp_unit_..."` (chainable). Dead `s_handlers[]` entries for sceDisplay/sceIo (these are overridden by unit 14). |
| `profiles/d012/host/main.cpp` | Sets game root to BIN's parent directory before running. |

---

## Current status (as of 15/10/2026, session 8)

### Session 10 - native rebuild and real startup trace (16/10/2026)

- Fresh `Release` build succeeds.
- Foreground launch reaches scene activation: pending scene `0x09999794` is promoted to the active scene root and the native window presents frames.
- The temporary host-side title-card experiment was reverted; no hard-coded title pixels remain in the presentation path.
- Backup flags remain in place for the malformed GE lists, synthetic pending lists, slot lists, render-chain replay, and scheduler maintenance path.
- Foreground watchdog result: the guest later enters the known unbounded scheduler/task pattern (dispatches `0x088A1AE4`/`0x088D15E0` repeatedly); the run was terminated deliberately rather than left spinning.

**Rendering gate `DAT_089D69DC` is now open (dc=01) from frame 2 onward.** âœ…
**`DAT_089D69E0` (render object ptr) is now set to `0x08C13A94` by `FUN_088769CC`.** âœ…
**`FUN_08883EE8` (DL builder) runs every frame with the correct render object pointer.** âœ…
**`FUN_0893354C` boot gate check passes; all 47+ subsystem inits fire.** âœ…
**`FUN_08869954` returns 1 (MPK magic check passes). `main.bin` loaded correctly.** âœ…
**Audio channel search infinite loop bypassed (`FUN_088A0EEC` stub â†’ -1).** âœ…
**`FUN_08869AB4` null deref fixed (not-found path instead of self-loop).** âœ…
**Menu MPK files extracted from PACKAGE.BIN, game proceeds past archive init.** âœ…
**Init sequence completes. Task scheduler runs 8+ tasks per frame.** âœ…
**Render chain (`DAT_09AF719C`) confirmed written with `0x08C15FD0` by `FUN_089AD204` (RCHAIN-INSERT).** âœ…
**VCB display list executor picks up the correct render chain pointer.** âœ…
**GE vertex address lookup extended to cover PSP RAM range `0x08000000â€“0x0A000000`.** âœ…
**`general_archive/main/main.bin` (1.2 MB) confirmed loaded into guest RAM at `0x09644A80`.** âœ…
**Root cause of zero pixels identified: ARCH-SYNTH fake entries set sub-chunk count = 0, blocking all geometry loads.** âŒ
**Current blocker: archive object not populated from `main.bin` â†’ ARCH-SYNTH fires â†’ sub-chunks=0 â†’ no vertex data written.** âŒ

### What was done this session (session 4)

#### main.bin extraction
- Wrote C# scanner (`FindMainBin.cs`, `FindLargeMPK.cs`) to scan `PACKAGE.BIN` for MPK blocks
- Identified `PACKAGE.BIN offset 0x2000`, size `0x129800` (1,218,560 bytes) as `general_archive/main/main.bin`
- Extracted to `original/general_archive/main/main.bin` â€” starts with `MPK ` magic âœ…
- Created minimal 16-byte MPK stub for `original/general_archive/main/JP/main_lang.bin` (0 entries)
- Created 84-byte zero stub for `original/language.bin`
- Created 900-byte PSF stub for `original/save/JP/PARAM.SFO`

#### Crash fixes
- **Null vtable audio loop** (`FUN_088A0EEC`, `generated_unit_0004.cpp`): stubbed to return -1 immediately, bypassing 32-slot null-function-pointer spin
- **`FUN_08869AB4` null deref** (`L_088D2A8C`, `generated_unit_0006.cpp`): null guard jumps to `L_088D2AA0` (not-found path) instead of returning to self (ra = same address)

#### Menu MPK extraction
- Found `menu_pk_loading_seq_0.bin` at `PACKAGE.BIN offset 0x12B800` via C# scanner
- MPK at that offset has 21 entries; extracted all to `original/`:
  - `common.bin`, `pause_menu.bin`, `save_data.bin`, `bgm_name.bin`, `friend_card.bin`
  - `ability.bin`, `accessory.bin`, `accessory_help.bin`, `item.bin`, `item_help.bin`
  - `party_command.bin`, `menu_pk_loading_seq_0.bin`, `menu_pk_loading_gim_0.bin`
  - `auto_save.gim`, `replay_CO.gim`, `ICON0.PNG`, `ICON0_NEW.PNG`
  - `menu_lpk_loading_seq_0.bin`, `menu_lpk_loading_gim_0.bin`
  - `dungeon_skill.bin`, `dungeon_skill_help.bin`
- Saved full `menu.bin` MPK block to `original/general_archive/field/menu.bin`

#### main.bin MPK contents (13 entries)
`battle.bin`, `objentry.bin`, `system.bin`, `mapentry.bin`, `manual_param.bin`, `ptcommand.bin`, `voice_priority_parameter.bin`, `resident.frr`, `snd_menu.scd`, `snd_common.scd`, `bgm_entry.bin`, `se_override.bin`, `assist.bin`

### Session 5 crash fixes

| Crash | Fix | File |
|---|---|---|
| `L_088D2B40` null buf crash | Skip to `L_088D2E2C` when gpr[17]=0 | `generated_unit_0006.cpp` |
| `L_088AECBC/CF0/ED24/ED98` FUN_08869AB4 null | Null guards store 0 and skip to next label | `generated_unit_0005.cpp` |
| `L_08813604` sub-pointer null | Skip call if gpr[16]+4 = 0 | `generated_unit_0000.cpp` |
| `0x089389E0` unregistered jump-table target | Added stub + dispatch case in unit 9 | `generated_unit_0009.cpp` |
| `0x001ECF3B` unregistered (bad fn ptr) | Guard at `L_0886313C` skips call if outside RAM | `generated_unit_0002.cpp` |
| `FUN_08872F08` VRAM read crash | Stubbed â€” reads `0x0A000000` (VRAM mirror), unsupported | `generated_unit_0003.cpp` |

### Session 9 findings (15/10/2026)

#### Init sequence now fully complete
- All INIT cross-unit call failures resolved. Two new HLE stubs added: `0x08890780` (clears `09B491F8[0,4,12]`, pushes `089D6AB0` to list) and `0x088A4168` (pushes `089D6D3C` to list).
- INIT completes; task scheduler runs 8 tasks per frame: `0x08865E98`, `0x08865ED0`, `0x08872F08`, `0x08875364`, `0x08874DFC`, `0x088D1598`, `0x08873E6C`, `0x088751B8`.

#### GE JUMP cycle detection
- Node `0x08C15FD0` JUMP pointed back to itself (JUMP at word[8], target = word[0]). Old self-jump guard `new_p == p` failed.
- Fixed: 16-entry history array in `ge_render.cpp`. If a JUMP target was seen before in the same exec call, abort.

#### Scene creation (Square Enix logo â€” type 0x2713)
- `DAT_089D603A` = 1 was blocking scene creation. When 603Aâ‰ 0, `FUN_08875364` (state=0) increments state rather than calling `FUN_088A24D4(0, 0x2713, 1, 0)`.
- ARCH-SYNTH in `generated_unit_0003.cpp`: forces `603A=0` when `6039=1` and state=0.
- Result: `FUN_088A24D4(0, 0x2713, 1, 0)` called. Scene object created at `0x08C10DA0`. Pool count 64â†’63. Scene added to pending list `DAT_09B4CF98`.

#### Current blocker: scene not activating
- Scene `0x08C10DA0` (type `0x2713`, vtable `0x089CAC90`) is in **pending list** `DAT_09B4CF98`.
- Activation requires: `FUN_0888B21C` â†’ `FUN_08895FE4` â†’ `FUN_088A2664` (iterates pending list) â†’ `FUN_088A1E44` (activates scene, moves to `DAT_09B48358`).
- None of the 8 running tasks call this chain. The render chain stays at gray node `0x08C15FD0` every frame.
- **Next step**: identify which task/caller invokes `FUN_0888B21C`, ensure it runs, OR add ARCH-SYNTH to directly call `FUN_088A2664` once per frame.

---

### Session 8 findings

#### Render pipeline trace
- Confirmed render chain at `DAT_09AF719C` is written with node `0x08C15FD0` by `FUN_089AD204` (RCHAIN-INSERT)
- Frame ordering: `sceDisplaySetFrameBuf` GE exec fires BEFORE RCHAIN-INSERT (chain empty), VCB exec fires AFTER (chain populated â€” correct path)
- GE DL at node `0x08C15FD0`: first word `0x5C808080` = JUMP opcode targeting `0x08808080` (inside guest RAM)
- `0x08808080` is all zeros â€” vertex data never written there
- Fixed GE vertex address lookup to also cover PSP RAM range `0x08000000â€“0x0A000000` (was only checking VRAM)

#### Root cause of zero pixels (ARCH-SYNTH sub-chunk count)
- Traced full code path: `FUN_088D2980` â†’ ARCH-SYNTH intercept â†’ returns fake entry with `sub_data+10 = 0`
- `sub_data+10` is the sub-chunk count; geometry load loop exits immediately when count=0
- `main.bin` IS loaded to `0x09644A80` via `FUN_08862854`, but the archive *object* (struct pointed to by `gpr[4]`) has `hdr+8 = 0` (empty entry table)
- The archive object's index table is not populated â€” the parsing/init function that should scan `main.bin` and build the object table hasn't run, or ran before `main.bin` was loaded
- **Next step**: trace why archive object at `gpr[4]` remains empty despite `main.bin` being loaded; find and trigger the init function that builds the entry table

### Session 6 crash fixes / investigation

| Crash | Root cause | Status |
|---|---|---|
| `0x0A000004` in task 3 `FUN_08872F08` | Traced through unit 9 â†’ unit 3 `L_0887263C`, `gpr[8]+4` where `gpr[8]=0x0A000000`. Defensive guards added at `L_088726B0`, `L_088726F4`, `L_0887263C` in unit 3 | Guards left in; crash source is `gpr[16]+64` storing the VRAM ptr `0x0A000000` |
| `0x0C000004` (after investigation) | `gpr[8]=0x0C000000` loaded from `gpr[8]+4` where `gpr[8]=0x0A000000`. `0x0C000000` = PSP write-combine VRAM alias (`0x4C000000 & 0x1FFFFFFF`) â€” not handled by `is_vram_window` which only covers `0x04000000â€“0x04800000` | **Next session**: add `0x0C000000` VRAM mirror to `is_vram_window` in `guest_memory.cpp` |

**Root fix needed**: `GuestMemory::is_vram_window()` must also accept `0x0C000000â€“0x0C800000` (write-combine VRAM aperture). Then `0x0C000000+4` will resolve to VRAM offset 4 instead of throwing.

### Current blocker: task loop â€” CHAIN-BAD / unregistered 0x08C13B40

After init, the task scheduler fires. Several tasks return to `ra=0x8888505B` (corrupt â€” float data misread as return address). One task tries to jump to `0x08C13B40` (heap-allocated, not a recompiled function â€” may be a dynamically-created callback).

### Watchdog finding

- Foreground runs are limited to 30 seconds; stalled runs are terminated.
- Current loop signature: repeated `ge_exec` calls on three host display-list buffers with spans of `65536`, interleaved with a growing partial-list span; approximately 5,000 executions occur within 30 seconds.
- `kBackupScenePromotion` is disabled because promoting the incomplete scene object causes this malformed-list loop. The `$a0=0` activation correction remains enabled.

### Known archive paths in ELF binary (baked in at compile time)
```
general_archive/main/main.bin          â† loaded âœ…
general_archive/main/JP/main_lang.bin  â† stub (0 entries)
general_archive/main/main_prologus.bin â† not yet loaded
general_archive/main/JP/main_lang_prologus.bin â† not yet loaded
general_archive/field/menu.bin         â† extracted but not yet registered
general_archive/field/JP/menu_lang.bin â† not yet loaded
general_archive/field/field.bin        â† not yet loaded
general_archive/field/ZQ/field_lang.bin â† not yet loaded
```

### Session 7 wrap-up (15/10/2026)

- No completion: the authentic Square Enix logo was not verified in the native window.
- Preserved the real 397,392-byte MPK as `original/general_archive/main/JP/main_lang.real.mpk` and tested it through the guest archive path.
- Corrected MPK-relative pointer experiments to use the loaded guest buffer at `0x097C4A80`; execution advanced through real archive data but still faults in the generated language-object routine around `0x088DCC24`/`0x088DD21C`.
- The visible foreground window was verified for the empty-stub path; the real-MPK path still exits before authentic logo GE submission.
- Remaining blocker: reconstruct the MPK object layout and generated cross-unit register/return behavior without synthetic entries or host-side logo injection.

### Session 10 - native rebuild and real startup trace (16/10/2026)

- Rebuilt `d012_native.exe` after clearing only stale/corrupt Release `.obj` artifacts. The executable is restored at `out/d012/profiles/d012/Release/d012_native.exe`.
- Visible bounded run confirmed the native program reads the real `main.bin` and `JP/main_lang.bin`, parses the 21-entry MPK, submits real GE lists, and presents the VRAM framebuffer.
- Authentic logo is **not yet verified**. Execution still faults while processing the third real loading-package record:
  `0x922A01B0` at guest PC `0x088DDDC0`.
- This is now narrowed to the generated language/loading-record path after two valid records, not a missing executable, fake logo, or host overlay.
- No source files or game data were removed; only rebuild artifacts under the native Release object directory were regenerated.

- Root cause of the `0x922A01B0` fault was identified: a malformed third record carried `s4=0x88885633`, which the generated parser interpreted as a small alignment/offset and added to `s3=0x09A1AB78`, producing `0x922A01AC`.
- Added a defensive malformed-record check before that offset arithmetic. The native build succeeds and the visible run no longer faults at `0x922A01B0`.
- The real archive path now reaches later entries, including `menu_pk_loading_gim_0.bin` and `menu_lpk_loading_gim_0.bin`.
- Scene initialization completes; the render chain is inserted; the VCB presents the guest framebuffer at `0x04000000` on five observed frames, with six real GE list submissions.
- A 20-second visible run reported: `Exceptions=0`, `PresentFrames=5`, `GELists=6`, `AuthenticGimEntries=2`.
- The authentic Square Enix pixels have not yet been independently verified on the framebuffer, so the overall goal remains open. Current focus is validating the displayed framebuffer contents and removing the remaining repeated malformed-record skips without replacing the guest asset path.

- Confirmed from the native runtime output that enabling the real render-chain and GE slot paths produces `477` GE executions, `5` framebuffer presentations, and `0` exceptions in a bounded run.
- The GE command trace currently contains no drawable guest commands: `GE-PRIM=0`, `GE-CLEAR=0`, and `GE-VDATA=0`. The executed chain is limited to state/finalization commands and a node pointer; this is why the authentic logo is still absent.
- Tested the existing scene-pending activation backup flag. It stalled in the malformed archive/resource path before the frame loop (`1` GE execution, `0` VCB presents, no scene callback), so it was reverted. No logo pixels or host-side overlay were added.
- Rebuilt the stable executable with the real GE execution flags enabled and synthetic scene-pending activation disabled. Remaining blocker is guest scene/resource activation and emission of the original logo's actual primitive/texture GE list.


### Session 11 - dispatch and GE stability (17/10/2026)

- Cross-unit dispatch and several GE crash paths were corrected.
- The native executable reaches real MPK loading, presents guest VRAM, and runs without the earlier scene-call failure.
- Archive/object state is still malformed, so no drawable scene geometry or authentic Square Enix logo is produced.
- No fake logo or host overlay was added.

### Session 12 - MPK corruption tracing (18/10/2026)

- Real embedded assets load and the native framebuffer path is active.
- Write tracing proved that translated FUN_08935524 overwrites MPK table 0x089CC268 before parsing.
- That corruption creates invalid archive sizes and leaves the GE trace at zero drawable primitives.
- The authentic logo remains unverified; the exact data-flow correction is the next task.

### Session 13 - PortableKit migration (22/10/2026)

**Goal this session:** migrate D012 from the old standalone build to PortableKit's framework so it uses the same Vulkan renderer, window, and cooperative kernel as Tenkawa (DBZ Tenkaichi Tag Team), which already works.

**No roadmap progress.** The session was entirely spent on bootstrapping the PortableKit build. The old MPK/archive/rendering blocker is unchanged.

**What was done:**

- Created `profiles/d012_pk/` — a new CMakeLists that wires D012's generated units into `portablekit_add_game()`.
- Created `profiles/d012/host/d012_portablekit_profile.cpp` — the PortableKit `game()` profile for ULES01505.
- Fixed disc_id to `ULES01505` (European release); installer was rejecting it as unsupported.
- Fixed installer SHA256 check: null/empty hash now bypasses the check, accepting the pre-decrypted ELF.
- Added FetchContent auto-download for SDL3 3.2.14 to `PortableKit.cmake` so the build is self-contained.
- Added entry redirect at address `0x00000000` → `load_base 0x08804040` (ET_EXEC ELF has `e_entry=0`).
- Removed interpreter stubs at `0x089C5F28/40/A0/D0` that were overriding unit_0014's AOT registrations, causing an infinite `sceKernelCreateThread` loop.
- Identified root cause of freeze: unit_0014 intercepts `sceKernelCreateThread` (`0x089C5FD0`) and `sceKernelStartThread` (`0x089C5FA0`) inline, routing them to `d012::hle_create_thread`/`hle_start_thread`. Those functions only queued the thread in `d012::s_thread_queue`, which nothing drained in the PortableKit build (the old `main.cpp`'s `hle_run_cooperative` was never called).
- Fixed `d012::hle_create_thread` and `d012::hle_start_thread` to call `portablekit::kernel().create_thread()` / `.start_thread()` so PortableKit's cooperative scheduler owns the thread.
- Added `d012::set_runtime(rt)` called from `patch_loaded_image` to give `d012_profile.cpp` access to the runtime for kernel calls.

**Current state:** Build is running. The game reached `sceKernelCreateThread uid=1 entry=0x08804160` before this fix — the thread was being created but never started. With this fix PortableKit's kernel owns the thread and should schedule it. Window and rendering not yet verified.

### Session 14 - init sequence traced, interpreter crash at 0x08BEE950 (26/10/2026)

**What was done this session:**

- Init sequence fully traced end-to-end. All 7 XUNIT init entries complete via `invoke_isolated_aot` with register save/restore (gpr[29]/gpr[31]/gpr[16]).
- Scheduler dispatches after init. Archive loading (`general_archive/main/main.bin`) proceeds.
- Game thread reaches the render loop.
- `L_08933458` entry diagnostic confirmed: `ra=0x089333F8` (valid), the `0xFFFFFFFF` ra crash from previous sessions is resolved.
- `[SCHED-TICK]` fires with `gpr4=0x08C10CFC gpr5=0x00000001 ra=0x0886F36C` — calls unit_14 (`sceKernelStopModule` import stub at `0x089C57E0`).
- PortableKit's kernel HLE for `sceKernelStopModule` reads the module's registered stop-function pointer (`0x08BA77D0`) and calls it.
- `0x08BA77D0` is in the un-recompiled range (units 27–31 do not exist as generated .cpp files). The interpreter starts there and runs ~72,801 instructions across the data section.
- Interpreter eventually reaches `0x08BEE950` which contains `0x0000FFFF` (uninitialized memory / data, not code) — crash: `Unsupported Allegrex instruction 0x0000FFFF`.

**Current blocker:** PortableKit's `sceKernelStopModule` HLE calls the module stop-function pointer `0x08BA77D0` (un-recompiled, data section). Interpreter runs 72k instructions through data until it hits `0x0000FFFF` at `0x08BEE950`. Attempted NID override (`ModuleMgrForUser / 0xD1FF982A`) via `rt.register_hle` after `force_import_stub` — import stub address is already bound to PortableKit's internal HLE which calls the stop function directly; NID override does not intercept the internal call.

**Next step:** Override the stop function call path inside PortableKit's kernel HLE, or register `0x08BA77D0` directly as a no-op HLE stub so the interpreter never runs there.
