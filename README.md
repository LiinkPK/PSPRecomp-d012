# PSPRecomp — Dissidia 012 PC Port

A fork of the PSPRecomp static recompilation framework, used to port **Dissidia 012 [duodecim] Final Fantasy** (`ULES01505`) to PC as a native executable. The PSP's MIPS code is translated to C++ ahead of time and runs on the PortableKit runtime (cooperative kernel, HLE, Vulkan renderer, audio). No emulator is needed to play.

> **Game files not included.** You need your own copy of the game (the ISO). Nothing copyrighted is in this repository.

---

## Repository layout

```
include/psprecomp/        Public runtime and Allegrex interfaces
src/                      ELF/PRX loading, decoder, memory, runtime, support code
tools/                    Analyzer (psp_analyze), recompiler (psp_recomp), helpers
tests/                    Framework regression tests
configs/                  Generic examples and PSP NID data
docs/                     Architecture and profile guides
pseudocode/               Reverse-engineered pseudocode of the whole executable (one file per function)
profiles/
  d012/
    generated/            AOT-compiled units of the main executable and of the menu overlay
    host/                 Game profile for PortableKit (title, icon, the few game-specific HLE hooks)
  d012_pk/                CMake entry point that builds d012_native with PortableKit
```

---

## Requirements

- CMake 3.20+ and a C++20 compiler (MSVC on Windows)
- A checkout of PortableKit; pass its folder as `-DPORTABLEKIT_ROOT=<path>`
- Your own `ULES01505` ISO

---

## Build and run

```bash
cmake -S profiles/d012_pk -B out/d012_pk -DPORTABLEKIT_ROOT=<path to portablekit>
cmake --build out/d012_pk --config Release --target d012_native
out/d012_pk/bin/Release/d012_native.exe
```

On first run PortableKit asks for the ISO and installs what it needs. The generated units are large; a full compile takes a long time, and afterwards only changed files rebuild.

---

## How it works

The executable is recompiled **unmodified**: the code in `profiles/d012/generated/` comes straight from the decrypted `EBOOT.BIN` and carries no hand patches or forged game state. Regenerate it with:

```bash
psp_recomp <ULES01505 EBOOT.elf> --auto profiles/d012/generated 0x08804040 131072
```

Each unit covers `0x20000` bytes of guest code as one C++ function that dispatches on the guest program counter. Every PSP import is bound to PortableKit's HLE; `profiles/d012/host/d012_portablekit_profile.cpp` holds only what this game needs on top (entry redirect, fake module ids for the font PRXs, language/RTC answers, a guard for the loader's thread arguments).

Inside a unit, jumps and returns update `local_pc`, so the dispatch switches on `local_pc`. An earlier version of the generator switched on a stale `ctx.pc`, which sent every internal return to the wrong address; that is fixed in `tools/codegen_main.cpp` and in the generated units.

---

## Texture replacement

The renderer can replace textures by PPSSPP `hash=quick` ID using a PPSSPP-style pack (`textures.ini` plus PNGs). The pack is appended to the executable at build time, so the game ships as one file; set `<prefix>_TEXTURE_PACK=<folder>` to load a folder instead while developing a pack. The replacement image keeps its own resolution, so HD art works without touching the game's data.

---

## Status

The recompiled game boots through its startup code and its main thread runs. Getting the Square Enix splash on screen end to end (resource loading, GE submission, HLE) is the current goal; see `updates.md` for the session-by-session log.

---

## Source provenance & license

No commercial game executable or asset is included. PPSSPP source is used for **reference only**; no GPL code is copied into this repository.

The PSPRecomp framework is MIT licensed. See [`LICENSE`](LICENSE).
