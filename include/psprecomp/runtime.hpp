#pragma once

#include "psprecomp/allegrex_context.hpp"
#include "psprecomp/guest_memory.hpp"
#include "psprecomp/nid_registry.hpp"

#include <cstdint>
#include <filesystem>
#include <functional>
#include <string>
#include <string_view>
#include <type_traits>
#include <unordered_map>
#include <vector>

namespace psprecomp {

// generated direct-unit chaining stays on a zero-observer fast path.
// Diagnostics flip this once for the process and transparently fall back to the
// fully instrumented runtime lookup. Keeping this as a plain process-global bool
// makes the common branch one predictable load instead of a hook/table walk.
extern bool g_runtime_chain_observers_active;
// Fast-path copy of the scheduler cadence. It is configured before guest
// execution and lets compile-time direct AOT chains charge ordinary work
// without calling an out-of-line helper on every cross-unit edge.
extern std::uint64_t g_runtime_starvation_interval_fast;
// Same idea for the thread-switch generation used by every compile-time direct
// chain. Keeping it as a public fast-path scalar avoids two out-of-line accessor
// calls per chain when the compiler cannot see through a giant generated unit.
extern std::uint64_t g_runtime_thread_switch_generation_fast;

#if defined(_MSC_VER)
#define PSPRECOMP_RUNTIME_FORCEINLINE __forceinline
#define PSPRECOMP_RESTRICT __restrict
#elif defined(__GNUC__) || defined(__clang__)
#define PSPRECOMP_RUNTIME_FORCEINLINE inline __attribute__((always_inline))
#define PSPRECOMP_RESTRICT __restrict__
#else
#define PSPRECOMP_RUNTIME_FORCEINLINE inline
#define PSPRECOMP_RESTRICT
#endif

// The cross-unit hot-register cache (AotHotRegisterCache) was removed here.  It
// kept seven GPRs and six scalar FPRs live in a second object alongside
// AllegrexContext for the whole duration of a generated unit.  Inside the
// ~10,000-line single functions this corpus emits, that pushed MSVC's optimizer
// past the point where it converges: affected units never finished compiling and
// grew past 2 GB each, which exhausted system memory during a normal build.  The
// last configuration observed booting on hardware (Stage 45.7) does not have it.
struct RuntimeExecutionContextToken {
    std::int32_t thread_uid{-1};
    std::uint64_t switch_generation{};
};

void set_runtime_thread_identity(std::int32_t uid, const std::string &name) noexcept;
[[nodiscard]] std::int32_t runtime_thread_uid() noexcept;
[[nodiscard]] const char *runtime_thread_name() noexcept;
[[nodiscard]] std::uint32_t runtime_dispatch_pc() noexcept;
void set_runtime_dispatch_pc(std::uint32_t pc) noexcept;
[[nodiscard]] RuntimeExecutionContextToken capture_runtime_execution_context() noexcept;
[[nodiscard]] bool runtime_execution_context_matches(RuntimeExecutionContextToken token) noexcept;
// Hot direct-chain guard.  The generation increments on every PSP thread
// identity transition, including switch-away/switch-back, so one 64-bit value
// is sufficient to detect stale native caller frames.  Keep the richer token
// above for diagnostics and generic/indirect paths.
[[nodiscard]] std::uint64_t runtime_thread_switch_generation() noexcept;
[[nodiscard]] bool runtime_thread_switch_generation_matches(std::uint64_t generation) noexcept;

class Runtime {
public:
    using RecompiledFunction = void (*)(Runtime &, AllegrexContext &);
    using RecompiledEntryFunction = void (*)(Runtime &, AllegrexContext &, std::uint16_t,
                                             GuestMemory::AotFastView &);
    using HleFunction = std::function<void(Runtime &, AllegrexContext &)>;
    using NativeFastPath = void (*)(Runtime &, AllegrexContext &);

    explicit Runtime(std::uint32_t ram_size = 32u * 1024u * 1024u);

    GuestMemory &memory() noexcept { return memory_; }
    const GuestMemory &memory() const noexcept { return memory_; }
    AllegrexContext &context() noexcept { return cpu_; }
    NidRegistry &nids() noexcept;
    const NidRegistry &nids() const noexcept;

    void register_function(std::uint32_t address, RecompiledFunction function, std::string name);
    void register_hle(std::string library, std::uint32_t nid, HleFunction function);
    [[nodiscard]] bool has_function(std::uint32_t address) const;
    [[nodiscard]] std::size_t function_count() const noexcept;

    void set_game_root(std::filesystem::path root);
    [[nodiscard]] const std::filesystem::path &game_root() const noexcept;
    [[nodiscard]] std::filesystem::path translate_path(const std::string &psp_path) const;

    void run(std::uint32_t entry, std::uint64_t max_dispatches = 10'000'000u);
    void stop(std::string reason);
    [[nodiscard]] bool stopped() const noexcept;
    [[nodiscard]] const std::string &stop_reason() const noexcept;

    void unsupported(std::uint32_t pc, std::uint32_t instruction, const std::string &reason);
    void arithmetic_overflow(std::uint32_t pc, std::uint32_t instruction);
    void invoke_import(std::string_view library, std::uint32_t nid, AllegrexContext &ctx);
    // Generated import wrappers have a stable numeric slot. Resolve the
    // library/NID hash maps only on the first call, then invoke the bound HLE
    // std::function directly on every subsequent frame.
    void invoke_import_cached(std::uint32_t slot, std::string_view library,
                              std::uint32_t nid, AllegrexContext &ctx);
    // Executes one registered AOT function in a caller-supplied context without
    // charging guest scheduler work. Used by host render integrations that must
    // call a pure guest math helper with an isolated stack/context.
    [[nodiscard]] bool invoke_isolated_aot(std::uint32_t address,
                                           AllegrexContext &ctx);
    // Profiles may register native replacements for selected guest functions.
    // Generated profile code can call this API without putting game-specific
    // addresses or implementations in the reusable runtime.
    void register_native_fast_path(std::uint32_t address, NativeFastPath function);
    void invoke_native_fast_path(std::uint32_t address, AllegrexContext &ctx);

    // Bounded cross-unit call chaining.
    //
    // The hottest guest routines are five-instruction leaves in a different
    // generated unit than their caller, so a plain `jal` costs two full outer
    // dispatches: one to enter the leaf and one to return.  This executes an
    // ordinary translated unit inline instead, leaving ctx.pc wherever the
    // callee stopped so the caller can resume locally only when it matches its
    // own return address.
    //
    // It stays safe because a generated unit never runs an import inline: any
    // `jal` to an import wrapper leaves the unit through the outer loop.  Every
    // thread switch therefore still happens with the runtime in control, and a
    // switched context is rejected by an execution-context token before the
    // generated caller is allowed to resume its local native frame.  Checking
    // only the return PC is insufficient because another PSP thread can resume
    // at the same address.  Depth is bounded so guest recursion cannot exhaust
    // the native stack.  PSPRECOMP_NO_CHAIN=1 disables it for A/B checks.
    [[nodiscard]] bool invoke_chained_call(AllegrexContext &ctx,
                                           GuestMemory::AotFastView *shared_aot_mem = nullptr);
    // Clear the chain-invalidation flag set by a yielded sub-call, allowing the
    // caller to continue as if no context switch occurred.  Use only when the
    // caller has already handled the consequences of the yield (e.g. all
    // globals were pre-initialised and the call result is not needed).
    void clear_chain_invalidation() { chain_context_invalidated_ = false; }
    // Fast path for compile-time-known cross-unit targets.  Automatic AOT knows
    // the 16 KiB unit index and can avoid the large guest-PC dispatch table.
    // Units containing an import/HLE/host override fall back to the exact
    // per-PC chainability path at runtime.
    [[nodiscard]] bool invoke_chained_unit(AllegrexContext &ctx, std::uint32_t unit_index,
                                           GuestMemory::AotFastView *shared_aot_mem = nullptr);

    // compile-time unit chain.  Automatic AOT knows both the target
    // function symbol and bucket, so the normal path becomes a direct native
    // call.  LTCG can optimize across that edge and the CPU no longer pays an
    // indirect function-pointer branch on every fixed cross-unit jump/JAL.
    //
    // The one table equality check is intentional: if install_profile() later
    // overlays an import/HLE/host replacement in that bucket, registration
    // poisons generated_units_[UnitIndex].  We then fall back to the old exact
    // path and unwind to outer dispatch instead of bypassing the replacement.
    template <auto Function, std::uint32_t UnitIndex, std::uint16_t DirectEntryId = 0u,
              std::uint32_t DirectTargetPc = 0u>
    [[nodiscard]] PSPRECOMP_RUNTIME_FORCEINLINE bool invoke_chained_direct(
        AllegrexContext &ctx, GuestMemory::AotFastView *shared_aot_mem = nullptr) {
        const std::uint32_t previous_dispatch_pc = runtime_dispatch_pc();
        struct DispatchPcRestore {
            std::uint32_t previous;
            ~DispatchPcRestore() { set_runtime_dispatch_pc(previous); }
        } dispatch_pc_restore{previous_dispatch_pc};
        if constexpr (DirectTargetPc != 0u) set_runtime_dispatch_pc(DirectTargetPc);
#if defined(PSPRECOMP_AOT_PRODUCTION_FASTPATHS)
        if (UnitIndex >= kGeneratedUnitFastCapacity || !generated_unit_layout_valid_) {
#else
        if (g_runtime_chain_observers_active ||
            UnitIndex >= kGeneratedUnitFastCapacity ||
            !generated_unit_layout_valid_) {
#endif
            if constexpr (UnitIndex == 9u && DirectTargetPc == 0x0893431Cu) {
                std::printf("[RT-FALLBACK] observers=%d layout=%d ctx.pc=0x%08X -> setting 0x0893431C\n",
                    static_cast<int>(g_runtime_chain_observers_active),
                    static_cast<int>(generated_unit_layout_valid_), ctx.pc);
                std::fflush(stdout);
            }
            if constexpr (DirectTargetPc != 0u) ctx.pc = DirectTargetPc;
            return invoke_chained_unit(ctx, UnitIndex, shared_aot_mem);
        }
        if (generated_unit_disabled_[UnitIndex] != 0u) {
            if constexpr (DirectTargetPc == 0x089A01FCu || DirectTargetPc == 0x0899F5A4u ||
                          DirectTargetPc == 0x0899FA64u || DirectTargetPc == 0x089C5AA8u) {
                static std::uint32_t s_disabled_trace = 0u;
                if (++s_disabled_trace <= 16u) {
                    std::printf("[CHAIN-DISABLED#%u] unit=%u target=0x%08X\\n",
                                s_disabled_trace, UnitIndex, DirectTargetPc);
                    std::fflush(stdout);
                }
            }
            // A unit can be poisoned because it contains PSP import stubs while
            // other exact entries in the same 16 KiB bucket remain ordinary AOT.
            // codegen sends known import targets straight to outer
            // dispatch, so for the remaining fixed targets use the exact per-PC
            // chain table rather than pessimistically abandoning all chaining in
            // the mixed bucket. Host/HLE overrides are still non-chainable there.
            if constexpr (DirectTargetPc != 0u) {
                if constexpr (DirectTargetPc != 0u) {
                    if (const RecompiledFunction _ov = lookup_function_override(DirectTargetPc); _ov != nullptr) {
                        ctx.pc = DirectTargetPc;
                        _ov(*this, ctx);
                        return !chain_context_invalidated_;
                    }
                }
                // A mixed unit is disabled only for its import edges; known
                // AOT targets in that same unit remain valid and must execute
                // through the unit entry rather than being rejected wholesale.
                if constexpr (DirectTargetPc != 0u) ctx.pc = DirectTargetPc;
                if constexpr (DirectEntryId != 0u &&
                              std::is_invocable_v<decltype(Function), Runtime &, AllegrexContext &, std::uint16_t,
                                                  GuestMemory::AotFastView &>) {
                    if constexpr (DirectTargetPc == 0x0893431Cu) {
                        std::printf("[RT-DISABLED] about to call unit_9 ctx.pc=0x%08X entry=%u\n",
                            ctx.pc, static_cast<unsigned>(DirectEntryId));
                        std::fflush(stdout);
                    }
                    if constexpr (DirectTargetPc == 0x0899F5A4u || DirectTargetPc == 0x089A01FCu) {
                        std::printf("[CHAIN-DIRECT-AOT] target=0x%08X entry=%u pc_before=0x%08X\n",
                                    DirectTargetPc, static_cast<unsigned>(DirectEntryId), ctx.pc);
                        std::fflush(stdout);
                    }
                    if (shared_aot_mem != nullptr) Function(*this, ctx, DirectEntryId, *shared_aot_mem);
                    else { auto _mem = memory_.aot_fast_view(); Function(*this, ctx, DirectEntryId, _mem); }
                    if constexpr (DirectTargetPc == 0x0899F5A4u || DirectTargetPc == 0x089A01FCu) {
                        std::printf("[CHAIN-DIRECT-AOT-RET] target=0x%08X pc_after=0x%08X\n", DirectTargetPc, ctx.pc);
                        std::fflush(stdout);
                    }
                    return true;
                } else if constexpr (DirectEntryId != 0u &&
                                     std::is_invocable_v<decltype(Function), Runtime &, AllegrexContext &, std::uint16_t>) {
                    Function(*this, ctx, DirectEntryId);
                    return true;
                }
                return invoke_chained_call(ctx, shared_aot_mem);
            } else {
                return false;
            }
        }
        if (chain_depth_ >= chain_depth_limit_) {
            // The caller removed the ordinary ctx.pc=target store from the hot
            // path. Restore it only on the rare depth-limit unwind so the outer
            // dispatcher still enters the exact guest destination.
            if constexpr (DirectTargetPc != 0u) ctx.pc = DirectTargetPc;
            return false;
        }

        // compile-time direct chains also carry their exact target
        // PC/entry id as template constants. The generated caller therefore does
        // not dirty AllegrexContext::pc before every successful native call; the
        // target PC is materialized only if chaining must unwind/fallback.
        //
        // compile-time direct chains no longer load the global PSP
        // thread generation before and after every native unit call.  The only
        // safe point able to switch PSP ownership while generated frames remain
        // nested is run_starvation_boundary(), which raises one Runtime-local
        // invalidation flag.  All active direct ancestors see that same hot
        // byte and unwind. This replaces two process-global 64-bit loads on
        // every fixed cross-unit transfer with one normally-false local load.
        struct DepthGuard {
            std::uint32_t &depth;
            explicit DepthGuard(std::uint32_t &value) : depth(value) { ++depth; }
            ~DepthGuard() { --depth; }
        } guard(chain_depth_);
        // This recovered target is entered through several ABI shapes in the
        // startup path. Use the exact guest-PC dispatcher for it so its entry
        // state is reconstructed from the dispatch table instead of relying on
        // the direct AOT entry shortcut.
        if constexpr (DirectTargetPc == 0x08869AB4u) {
            ctx.pc = DirectTargetPc;
            return invoke_chained_call(ctx, shared_aot_mem);
        }
        if constexpr (DirectTargetPc != 0u) { ctx.pc = DirectTargetPc; _ReadWriteBarrier(); }
        if constexpr (DirectTargetPc != 0u) {
            if (const RecompiledFunction _ov = lookup_function_override(DirectTargetPc); _ov != nullptr) {
                if constexpr (DirectTargetPc == 0x0893431Cu) {
                    std::printf("[RT-OVERRIDE] override found for 0x0893431C ctx.pc=0x%08X\n", ctx.pc);
                    std::fflush(stdout);
                }
                _ov(*this, ctx);
                if (chain_context_invalidated_) return false;
                return true;
            }
        }
        if constexpr (DirectEntryId != 0u &&
                      std::is_invocable_v<decltype(Function), Runtime &, AllegrexContext &, std::uint16_t,
                                          GuestMemory::AotFastView &>) {
            if constexpr (DirectTargetPc == 0x0893431Cu) {
                std::printf("[RT-DIRECT] about to call unit_9 ctx.pc=0x%08X DirectTargetPc=0x%08X entry=%u\n",
                    ctx.pc, static_cast<unsigned>(DirectTargetPc), static_cast<unsigned>(DirectEntryId));
                std::fflush(stdout);
            }
            _ReadWriteBarrier(); // prevent LTCG from eliding ctx.gpr writes (ra, etc.) before the call
            if (shared_aot_mem != nullptr) {
                Function(*this, ctx, DirectEntryId, *shared_aot_mem);
            } else {
                auto local_aot_mem = memory_.aot_fast_view();
                Function(*this, ctx, DirectEntryId, local_aot_mem);
            }
        } else if constexpr (DirectEntryId != 0u &&
                             std::is_invocable_v<decltype(Function), Runtime &, AllegrexContext &, std::uint16_t>) {
            _ReadWriteBarrier();
            Function(*this, ctx, DirectEntryId);
        } else {
            _ReadWriteBarrier();
            Function(*this, ctx);
        }
#if !defined(PSPRECOMP_AOT_PRODUCTION_FASTPATHS)
        if (track_dispatch_counters_) {
            ++chained_dispatches_;
            ++dispatch_work_count_;
        }
#endif

        // A scheduler boundary in any descendant switched PSP ownership.
        // Unwind every still-live native caller without touching another global
        // generation counter or scheduling from stale guest registers.
        if (chain_context_invalidated_) {
            const std::uint64_t interval = g_runtime_starvation_interval_fast;
            if (interval != 0u) ++dispatches_since_import_;
            return false;
        }

        const std::uint64_t starvation_interval = g_runtime_starvation_interval_fast;
        if (starvation_interval == 0u) return true;
        if (++dispatches_since_import_ < starvation_interval) return true;
        return run_starvation_boundary(ctx);
    }

    void register_generated_unit(std::uint32_t unit_index, std::uint32_t unit_address,
                                 std::uint32_t unit_span, RecompiledFunction function,
                                 RecompiledEntryFunction entry_function = nullptr);
    [[nodiscard]] std::uint64_t dispatch_work_count() const noexcept { return dispatch_work_count_; }

    AllegrexContext &cpu() noexcept;
    const AllegrexContext &cpu() const noexcept;

    // Ordered "library:nid -> call count" snapshot, empty unless
    // PSPRECOMP_HLE_HISTOGRAM is set.  Used to tell a synchronous compute phase
    // apart from a wait loop the host never satisfies.
    [[nodiscard]] std::vector<std::pair<std::string, std::uint64_t>> hle_histogram() const;
    void report_hle_histogram(std::size_t limit = 25u) const;

private:
    struct FunctionEntry {
        RecompiledFunction function{};
        std::string name;
    };

    struct TransparentStringHash {
        using is_transparent = void;
        std::size_t operator()(std::string_view value) const noexcept {
            return std::hash<std::string_view>{}(value);
        }
    };
    using HleLibrary = std::unordered_map<std::uint32_t, HleFunction>;

    static std::string hle_key(std::string_view library, std::uint32_t nid);
    [[nodiscard]] RecompiledFunction lookup_function(std::uint32_t address) const noexcept;
    // Dense unit lookup for the production outer dispatcher.  Unlike
    // lookup_function(), this touches a 512-entry table rather than the
    // multi-megabyte per-PC table when the PC belongs to a clean generated
    // unit. Host/import-overlapped units are poisoned and return nullptr.
    [[nodiscard]] RecompiledFunction lookup_generated_unit(std::uint32_t address) const noexcept;
    [[nodiscard]] const FunctionEntry *lookup_entry(std::uint32_t address) const noexcept;
    // Returns false only when the starvation/preemption hook changed the PSP
    // execution context at this safe boundary.
    [[nodiscard]] bool account_dispatch_work(AllegrexContext &ctx, bool allow_preemption);
    // Called only once per configured scheduler interval by the header-inline
    // direct-chain fast path. Keeping hook/context-token work here leaves the
    // other ~4095 boundaries as a counter increment + predictable compare.
    [[nodiscard]] bool run_starvation_boundary(AllegrexContext &ctx);
    [[nodiscard]] RecompiledFunction lookup_function_override(std::uint32_t address) const noexcept {
        if (direct_functions_.empty()) return nullptr;
        const std::uint32_t c = memory_.canonical(address);
        const std::uint32_t delta = c - direct_base_;
        if ((delta & 3u) != 0u) return nullptr;
        const std::size_t index = static_cast<std::size_t>(delta) / 4u;
        if (index >= direct_functions_.size()) return nullptr;
        const RecompiledFunction fn = direct_functions_[index];
        if (fn == nullptr || direct_chainable_[index] != nullptr) return nullptr;
        return fn;
    }

    GuestMemory memory_;
    NidRegistry nids_;
    AllegrexContext cpu_;
    std::unordered_map<std::uint32_t, FunctionEntry> functions_;
    // Direct PC table, covering only the registered code window rather than all
    // of guest RAM.  direct_base_ is its 1 MiB-aligned first canonical address.
    std::vector<RecompiledFunction> direct_functions_;
    // Same indexing, but null for import wrappers and every other non-unit
    // entry, so chaining can reject them with one array probe.
    std::vector<RecompiledFunction> direct_chainable_;
    // Dense fixed table for compile-time direct unit chaining. Keeping this in
    // the Runtime object avoids vector indirections and repeated size loads on
    // hot generated call edges. Larger corpora fall back to exact PC dispatch
    // for indices beyond this conservative capacity.
    static constexpr std::size_t kGeneratedUnitFastCapacity = 512u;
    std::array<RecompiledFunction, kGeneratedUnitFastCapacity> generated_units_{};
    // Entry-form companion used by dynamic JR/JALR chains so they can share the
    // caller's AotFastView instead of rebuilding RAM pointers/limits each unit.
    std::array<RecompiledEntryFunction, kGeneratedUnitFastCapacity> generated_unit_entries_{};
    // Consulted only while registering. An overlapping host/import entry poisons
    // the whole unit for the fast path; calls then unwind to exact PC dispatch.
    std::array<std::uint8_t, kGeneratedUnitFastCapacity> generated_unit_disabled_{};
    std::uint32_t generated_unit_base_{};
    std::uint32_t generated_unit_span_{};
    bool generated_unit_layout_valid_{true};
    std::uint32_t direct_base_{};
    std::uint32_t chain_depth_{};
    std::uint32_t chain_depth_limit_{};
    // Set only when a scheduler safe-point actually changes PSP execution
    // ownership while native AOT frames may still be nested. Cleared at the
    // beginning of each outer Runtime dispatch.
    bool chain_context_invalidated_{};
    std::uint64_t dispatches_since_import_{};
    std::uint64_t chained_dispatches_{};
    std::uint64_t dispatch_work_count_{};
    std::unordered_map<std::string, HleLibrary,
                       TransparentStringHash, std::equal_to<>> hle_;
    std::unordered_map<std::uint32_t, NativeFastPath> native_fast_paths_;
    std::vector<const HleFunction *> import_bindings_;
    std::filesystem::path game_root_;
    bool stopped_{};
    std::string stop_reason_;
    bool hle_histogram_enabled_{};
    // keep high-frequency dispatch counters completely cold unless
    // the user explicitly asks for them. They previously dirtied the Runtime
    // cache line on every native chained call during normal gameplay.
    bool track_dispatch_counters_{};
    std::unordered_map<std::string, std::uint64_t> hle_histogram_;
};

// Identifies the PSP execution context that entered a host import wrapper.
// A kernel HLE call may schedule a different thread while the wrapper is still
// on the native stack.  Checking only ctx.pc is insufficient because the new
// thread can legitimately be waiting at the same import stub.  The switch
// generation makes return-address normalization conditional on still owning
// the original PSP thread context.

// Prints one "[count-pc] pc=... hits=..." line per address armed through
// PSPRECOMP_COUNT_PC (comma-separated, up to eight).  Counts both entry paths,
// the outer dispatch loop and invoke_chained_call, so a routine reached only
// through cross-unit chaining is still seen.  Answers "does this guest routine
// ever run?" without the overhead that makes the chain tracer alter the run.
void report_counted_pcs();

// Replaced by psp_recomp output once a real function map is available.
void register_generated_functions(Runtime &runtime);

// Optional liveness callback for the host.  It is invoked from the production
// dispatch loop roughly every `interval` outer dispatches so a presentation
// layer can stay informative during long synchronous guest phases.  Passing a
// null hook or a zero interval disables it and restores the previous loop.
using RuntimeHeartbeatHook = void (*)(std::uint64_t dispatch, std::uint32_t pc);
void set_runtime_heartbeat_hook(RuntimeHeartbeatHook hook, std::uint64_t interval) noexcept;

// Execution-driven time and preemption.
//
// On real hardware the PSP clock advances with executed cycles and the kernel
// preempts from a timer interrupt.  A cooperative runtime that only advances
// virtual time when a thread sleeps deadlocks against guest busy-waits: the
// world loader polls sceKernelGetSystemTime / sceKernelPollEventFlag /
// sceUmdGetDriveStat without ever blocking, so the clock froze and the UMD
// stream thread it was waiting on never came due.
//
// The hook fires from the outer dispatch loop every `interval` dispatches,
// regardless of how often the guest enters the kernel, and never from inside a
// chained call.  A dispatch boundary is a safe preemption point because ctx.pc
// is precisely the next instruction to run.
using RuntimeStarvationHook = void (*)(Runtime &, AllegrexContext &);
void set_runtime_starvation_hook(RuntimeStarvationHook hook, std::uint64_t interval) noexcept;

// One-shot scheduling barriers and other host services occasionally need to
// observe a completed *outer* dispatch.  This fires after a translated unit or
// import wrapper returns to Runtime::run, never from inside a chained call.
// `dispatch_pc` and `dispatch_thread_uid` identify the unit and PSP thread
// that started the dispatch, even if an HLE call switched `ctx` to another
// thread before the translated wrapper returned.
using RuntimePreDispatchHook = void (*)(Runtime &, AllegrexContext &, std::uint32_t dispatch_pc,
                                        std::int32_t dispatch_thread_uid);
void set_runtime_pre_dispatch_hook(RuntimePreDispatchHook hook) noexcept;
using RuntimePostDispatchHook = void (*)(Runtime &, AllegrexContext &, std::uint32_t dispatch_pc,
                                         std::int32_t dispatch_thread_uid);
void set_runtime_post_dispatch_hook(RuntimePostDispatchHook hook) noexcept;

// Optional diagnostics around native cross-unit calls.  Unlike the outer
// dispatch hooks these fire for calls performed through invoke_chained_call(),
// so a host profile can inspect a nested guest routine without disabling the
// fast chaining path or changing guest timing.  `target_pc` is captured before
// the callee runs and `native_depth` is the zero-based chained-call depth.
using RuntimePreChainedCallHook = void (*)(Runtime &, AllegrexContext &, std::uint32_t target_pc,
                                           std::uint32_t native_depth);
using RuntimePostChainedCallHook = void (*)(Runtime &, AllegrexContext &, std::uint32_t target_pc,
                                            std::uint32_t native_depth);
void set_runtime_pre_chained_call_hook(RuntimePreChainedCallHook hook) noexcept;
void set_runtime_post_chained_call_hook(RuntimePostChainedCallHook hook) noexcept;

#undef PSPRECOMP_RUNTIME_FORCEINLINE

} // namespace psprecomp
