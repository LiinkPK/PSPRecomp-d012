# PSPRecomp – Dissidia 012 (ULES01505.BIN) – Current State

**Last updated:** 18/10/2026 (Session 12)

**Goal:** Genuinely boot Dissidia 012’s original startup path and visibly render the authentic Square Enix logo through guest asset I/O → guest VRAM → GE → the native window. A blank window, hard-coded logo, placeholder, or host overlay does not count.

### Consolidated Sessions 9–11

- **Session 9 — Scene discovery:** Init completed and the guest created the Square Enix scene (`0x2713`) in the pending-scene list. Activation and drawable GE commands were still absent.
- **Session 10 — Real startup I/O:** A visible native run loaded the real archive data into guest memory and presented guest VRAM without a host-side logo. GE execution remained state-only (`GE-PRIM=0`, `GE-CLEAR=0`, `GE-VDATA=0`).
- **Session 11 — Cross-unit dispatch:** The mixed-unit fallback was corrected so valid AOT targets execute even when their unit also contains imports. The rebuilt executable now reaches real MPK loading without the earlier `CHAIN-BAD` scene-call failure, but malformed archive-record/object state still prevents scene geometry from being emitted. The authentic logo remains unverified.
- **Session 12 — Resource-return tracing:** The rebuilt native window remains stable and presents guest VRAM; `data/package_info.bin` is genuinely opened and read. A register-preservation correction removed the render-chain crash. The remaining startup failure is narrowed to `FUN_0886330C`: the generated formatter/resource handoff still supplies truncated `data/s` instead of the reconstructed `data/package_info.bin`, so later assets and GE primitives are never reached. No logo was faked or verified.

**Project:** `C:\path\to\your\folder\PSPRecomp`  
**Build:** `cmake --build out\d012 --config Release` → binary at `out\d012\profiles\d012\Release\d012_native.exe`  
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

When `invoke_chained_call` hits an unregistered address → null-PC crash. Fix:

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

## GE (Graphics Engine) subsystem — what was done

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
| Infinite loop / null-PC on cmds 0–21 | `L_089A1308` emitted as indirect jump through `RAM[table+cmd*4]`, recompiler mis-decoded MIPS switch table as a jump-through-pointer. Actual function `FUN_089a12fc` is a switch that writes one GE DL word per cmd. | Replaced `L_089A1308` with full switch implementation from pseudocode. Also added unit-14 no-op stubs + `register_function` for `0x089D18F8`–`0x089D1948`. |

---

## Display subsystem — current state

`sceDisplaySetFrameBuf` is called every frame (confirmed). Double-buffered:
- Front buffer: `0x04000000` (PSP VRAM offset 0)
- Back buffer: `0x04044000` (PSP VRAM offset 0x44000)
- Format: RGB565 (`fmt=1`), width 512, height 272

VRAM is accessible via `rt.memory().vram_bytes()`. A host window (SDL2/Win32) is needed to blit it.

**Display state machine** (`FUN_08865ED0`, task fn=`0x08865ED0`):
- State 0 = idle, calls `FUN_0886598c` (GE render list writer) each frame
- State 1→2→3 = triggered by `FUN_08866178` on stereo mode change; runs display setup chain
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

All PSP import stubs cluster in unit 14 (`0x089C4040`–`0x089C6040`). The generated unit already has `jr $ra / nop` for each stub VA and registers them as `"recomp_unit_0014"`. This means:

- `s_handlers[VA]` in `d012_profile.cpp` is **never reached**. The generated unit intercepts first
- `register_hle(library, nid, fn)` is also dead for these — `invoke_import` is never called from AOT units

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

### Session 10 completion checkpoint (15/10/2026)

- Fresh `Release` build succeeds.
- Foreground launch reaches scene activation: pending scene `0x09999794` is promoted to the active scene root and the native window presents frames.
- The temporary host-side title-card experiment was reverted; no hard-coded title pixels remain in the presentation path.
- Backup flags remain in place for the malformed GE lists, synthetic pending lists, slot lists, render-chain replay, and scheduler maintenance path.
- Foreground watchdog result: the guest later enters the known unbounded scheduler/task pattern (dispatches `0x088A1AE4`/`0x088D15E0` repeatedly); the run was terminated deliberately rather than left spinning.

**Rendering gate `DAT_089D69DC` is now open (dc=01) from frame 2 onward.** ✅
**`DAT_089D69E0` (render object ptr) is now set to `0x08C13A94` by `FUN_088769CC`.** ✅
**`FUN_08883EE8` (DL builder) runs every frame with the correct render object pointer.** ✅
**`FUN_0893354C` boot gate check passes; all 47+ subsystem inits fire.** ✅
**`FUN_08869954` returns 1 (MPK magic check passes). `main.bin` loaded correctly.** ✅
**Audio channel search infinite loop bypassed (`FUN_088A0EEC` stub → -1).** ✅
**`FUN_08869AB4` null deref fixed (not-found path instead of self-loop).** ✅
**Menu MPK files extracted from PACKAGE.BIN, game proceeds past archive init.** ✅
**Init sequence completes. Task scheduler runs 8+ tasks per frame.** ✅
**Render chain (`DAT_09AF719C`) confirmed written with `0x08C15FD0` by `FUN_089AD204` (RCHAIN-INSERT).** ✅
**VCB display list executor picks up the correct render chain pointer.** ✅
**GE vertex address lookup extended to cover PSP RAM range `0x08000000–0x0A000000`.** ✅
**`general_archive/main/main.bin` (1.2 MB) confirmed loaded into guest RAM at `0x09644A80`.** ✅
**Root cause of zero pixels identified: ARCH-SYNTH fake entries set sub-chunk count = 0, blocking all geometry loads.** ❌
**Current blocker: archive object not populated from `main.bin` → ARCH-SYNTH fires → sub-chunks=0 → no vertex data written.** ❌

### What was done this session (session 4)

#### main.bin extraction
- Wrote C# scanner (`FindMainBin.cs`, `FindLargeMPK.cs`) to scan `PACKAGE.BIN` for MPK blocks
- Identified `PACKAGE.BIN offset 0x2000`, size `0x129800` (1,218,560 bytes) as `general_archive/main/main.bin`
- Extracted to `original/general_archive/main/main.bin` — starts with `MPK ` magic ✅
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
| `FUN_08872F08` VRAM read crash | Stubbed — reads `0x0A000000` (VRAM mirror), unsupported | `generated_unit_0003.cpp` |

### Session 9 findings (15/10/2026)

#### Init sequence now fully complete
- All INIT cross-unit call failures resolved. Two new HLE stubs added: `0x08890780` (clears `09B491F8[0,4,12]`, pushes `089D6AB0` to list) and `0x088A4168` (pushes `089D6D3C` to list).
- INIT completes; task scheduler runs 8 tasks per frame: `0x08865E98`, `0x08865ED0`, `0x08872F08`, `0x08875364`, `0x08874DFC`, `0x088D1598`, `0x08873E6C`, `0x088751B8`.

#### GE JUMP cycle detection
- Node `0x08C15FD0` JUMP pointed back to itself (JUMP at word[8], target = word[0]). Old self-jump guard `new_p == p` failed.
- Fixed: 16-entry history array in `ge_render.cpp`. If a JUMP target was seen before in the same exec call, abort.

#### Scene creation (Square Enix logo — type 0x2713)
- `DAT_089D603A` = 1 was blocking scene creation. When 603A≠0, `FUN_08875364` (state=0) increments state rather than calling `FUN_088A24D4(0, 0x2713, 1, 0)`.
- ARCH-SYNTH in `generated_unit_0003.cpp`: forces `603A=0` when `6039=1` and state=0.
- Result: `FUN_088A24D4(0, 0x2713, 1, 0)` called. Scene object created at `0x08C10DA0`. Pool count 64→63. Scene added to pending list `DAT_09B4CF98`.

#### Current blocker: scene not activating
- Scene `0x08C10DA0` (type `0x2713`, vtable `0x089CAC90`) is in **pending list** `DAT_09B4CF98`.
- Activation requires: `FUN_0888B21C` → `FUN_08895FE4` → `FUN_088A2664` (iterates pending list) → `FUN_088A1E44` (activates scene, moves to `DAT_09B48358`).
- None of the 8 running tasks call this chain. The render chain stays at gray node `0x08C15FD0` every frame.
- **Next step**: identify which task/caller invokes `FUN_0888B21C`, ensure it runs, OR add ARCH-SYNTH to directly call `FUN_088A2664` once per frame.

---

### Session 8 findings

#### Render pipeline trace
- Confirmed render chain at `DAT_09AF719C` is written with node `0x08C15FD0` by `FUN_089AD204` (RCHAIN-INSERT)
- Frame ordering: `sceDisplaySetFrameBuf` GE exec fires BEFORE RCHAIN-INSERT (chain empty), VCB exec fires AFTER (chain populated — correct path)
- GE DL at node `0x08C15FD0`: first word `0x5C808080` = JUMP opcode targeting `0x08808080` (inside guest RAM)
- `0x08808080` is all zeros — vertex data never written there
- Fixed GE vertex address lookup to also cover PSP RAM range `0x08000000–0x0A000000` (was only checking VRAM)

#### Root cause of zero pixels (ARCH-SYNTH sub-chunk count)
- Traced full code path: `FUN_088D2980` → ARCH-SYNTH intercept → returns fake entry with `sub_data+10 = 0`
- `sub_data+10` is the sub-chunk count; geometry load loop exits immediately when count=0
- `main.bin` IS loaded to `0x09644A80` via `FUN_08862854`, but the archive *object* (struct pointed to by `gpr[4]`) has `hdr+8 = 0` (empty entry table)
- The archive object's index table is not populated — the parsing/init function that should scan `main.bin` and build the object table hasn't run, or ran before `main.bin` was loaded
- **Next step**: trace why archive object at `gpr[4]` remains empty despite `main.bin` being loaded; find and trigger the init function that builds the entry table

### Session 6 crash fixes / investigation

| Crash | Root cause | Status |
|---|---|---|
| `0x0A000004` in task 3 `FUN_08872F08` | Traced through unit 9 → unit 3 `L_0887263C`, `gpr[8]+4` where `gpr[8]=0x0A000000`. Defensive guards added at `L_088726B0`, `L_088726F4`, `L_0887263C` in unit 3 | Guards left in; crash source is `gpr[16]+64` storing the VRAM ptr `0x0A000000` |
| `0x0C000004` (after investigation) | `gpr[8]=0x0C000000` loaded from `gpr[8]+4` where `gpr[8]=0x0A000000`. `0x0C000000` = PSP write-combine VRAM alias (`0x4C000000 & 0x1FFFFFFF`) — not handled by `is_vram_window` which only covers `0x04000000–0x04800000` | **Next session**: add `0x0C000000` VRAM mirror to `is_vram_window` in `guest_memory.cpp` |

**Root fix needed**: `GuestMemory::is_vram_window()` must also accept `0x0C000000–0x0C800000` (write-combine VRAM aperture). Then `0x0C000000+4` will resolve to VRAM offset 4 instead of throwing.

### Current blocker: task loop — CHAIN-BAD / unregistered 0x08C13B40

After init, the task scheduler fires. Several tasks return to `ra=0x8888505B` (corrupt — float data misread as return address). One task tries to jump to `0x08C13B40` (heap-allocated, not a recompiled function — may be a dynamically-created callback).

### Watchdog finding

- Foreground runs are limited to 30 seconds; stalled runs are terminated.
- Current loop signature: repeated `ge_exec` calls on three host display-list buffers with spans of `65536`, interleaved with a growing partial-list span; approximately 5,000 executions occur within 30 seconds.
- `kBackupScenePromotion` is disabled because promoting the incomplete scene object causes this malformed-list loop. The `$a0=0` activation correction remains enabled.

### Known archive paths in ELF binary (baked in at compile time)
```
general_archive/main/main.bin          ← loaded ✅
general_archive/main/JP/main_lang.bin  ← stub (0 entries)
general_archive/main/main_prologus.bin ← not yet loaded
general_archive/main/JP/main_lang_prologus.bin ← not yet loaded
general_archive/field/menu.bin         ← extracted but not yet registered
general_archive/field/JP/menu_lang.bin ← not yet loaded
general_archive/field/field.bin        ← not yet loaded
general_archive/field/ZQ/field_lang.bin ← not yet loaded
```

### Session 7 wrap-up (15/10/2026)

- No completion: the authentic Square Enix logo was not verified in the native window.
- Preserved the real 397,392-byte MPK as `original/general_archive/main/JP/main_lang.real.mpk` and tested it through the guest archive path.
- Corrected MPK-relative pointer experiments to use the loaded guest buffer at `0x097C4A80`; execution advanced through real archive data but still faults in the generated language-object routine around `0x088DCC24`/`0x088DD21C`.
- The visible foreground window was verified for the empty-stub path; the real-MPK path still exits before authentic logo GE submission.
- Remaining blocker: reconstruct the MPK object layout and generated cross-unit register/return behavior without synthetic entries or host-side logo injection.

### Session 10 — native rebuild and real startup trace (16/10/2026)

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

### Session 11 — scene callback reachability trace (17/10/2026)

- A fresh 30-second native run remains stable: `477` GE executions, `5` VCB presentations, and `0` exceptions/out-of-memory accesses.
- Added narrow guest-entry diagnostics around `0x0888B21C`, `0x088A2664`, `0x088EA800`, and `sceGuDrawArray`, then rebuilt and ran the native executable.
- None of those scene-transition or draw entry points are reached. The scheduler reaches `0x089333F0` and invokes its current callback path, but the active scene worker and GE draw API remain absent; the GE stream still has `GE-PRIM=0`, `GE-CLEAR=0`, and `GE-VDATA=0`.
- This isolates the next task to the scheduler/scene-list handoff, before GE command generation. No host-side logo, texture injection, or overlay was added.
- The scheduler trace now identifies the immediate failed handoff: `0x08933A2C` loads callback object `0x09AE7070`, whose first four words are all zero. It is therefore not a callable guest function and the indirect call returns without entering the scene worker.
- The same run still reaches five VCB presentations with no exceptions, but no `0x0888B21C`, `0x088A2664`, `0x088EA800`, `sceGuDrawArray`, or GE primitive commands.
- The next repair target is initialization/population of the callback object at the guest scheduler slot, not the host renderer. Diagnostic tracing remains source-only; no logo or pixels were injected.
- The callback slot trace now shows the runtime actually attempts `invoke_chained_call(0x09AE7070)`, but that address is unregistered guest data; the runtime reports `[UNREGISTERED] pc=0x09AE7070` and returns to the caller.
- The suspected write site `0x08878264` is never reached, confirming `0x09AE7070` is not populated by that initialization path in the current startup sequence. The scene worker and draw API remain unentered.
- This is the current concrete handoff defect: the native runtime must reproduce the original callback/function registration or the guest path must reach the initializer that populates it. No host rendering shortcut was introduced.
- Identified the apparent missing constructor addresses as `OVL_MENU_APP.ELF` overlay code: its load segment begins at `0x089DD4C0`, and the previously pass-through addresses (`0x08A...`/`0x08B...`) fall inside that overlay range rather than the main EBOOT code segment.
- Generated 12 AOT source units for the real `OVL_MENU_APP.ELF`, added them to the D012 build, copied the supplied overlay asset to `original/OVL_MENU_APP.ELF`, and added a loader that maps its ELF segment into guest memory at the correct load address.
- Removed the subsystem constructor pass-through registrations and kept synthetic scene promotion disabled. This preserves the requirement that visible output must come from guest asset I/O → guest memory/VRAM → GE.
- The first overlay compile exposed and was corrected for an AOT entry-dispatch variable omission. The current build was still compiling the large overlay units at session handoff; the old executable remains unchanged until the new build succeeds.
- Authentic Square Enix pixels remain unverified. The next required gate is a successful overlay build followed by a visible run showing overlay-driven I/O, nonzero GE primitive/vertex commands, texture/VRAM activity, and the logo in the presented framebuffer.
- The generated menu-overlay build stalled repeatedly while compiling a large overlay unit; it was stopped without modifying the previously built executable.
- Removed the incomplete overlay source list/loader from the active build configuration so the repository does not remain dependent on an unfinished executable. Generated overlay sources and `original/OVL_MENU_APP.ELF` remain available for future targeted integration.
- Revalidated the intact native executable with a visible bounded run. It reads `language.bin`, `general_archive/main/main.bin`, `main_lang.bin`, and both real loading GIM archives; scene initialization completes and the VCB presents guest VRAM frames 1–4.
- Current evidence still shows GE enqueue/presentation but no verified Square Enix pixels or nonzero primitive/vertex trace. Goal remains open; the next useful approach is targeted overlay integration/codegen rather than compiling the entire overlay at once.
- Added a targeted overlay registry for only menu overlay units 0001–0003, which contain the missing startup addresses, plus the real `OVL_MENU_APP.ELF` guest-memory loader.
- The build system nevertheless scheduled large baseline generated units because interrupted object state made them out of date. Unit 0004 then made no object progress across repeated checks; the stale compiler tree was stopped.
- The previous executable remains preserved and the source tree contains no fake logo or host overlay. The next build must reuse valid baseline objects or use a separate targeted build configuration so overlay code can be tested without recompiling the entire generated EBOOT.
