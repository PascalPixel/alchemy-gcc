/* Compilation switch flag definitions for GNU CC.
   Copyright (C) 1987, 1988, 1994, 1995, 1996, 1997, 1998, 1999, 2000
   Free Software Foundation, Inc.

This file is part of GNU CC.

GNU CC is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2, or (at your option)
any later version.

GNU CC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with GNU CC; see the file COPYING.  If not, write to
the Free Software Foundation, 59 Temple Place - Suite 330,
Boston, MA 02111-1307, USA.  */

/* Name of the input .c file being compiled.  */
extern const char *main_input_filename;

enum debug_info_type
{
  NO_DEBUG,	    /* Write no debug info.  */
  DBX_DEBUG,	    /* Write BSD .stabs for DBX (using dbxout.c).  */
  SDB_DEBUG,	    /* Write COFF for (old) SDB (using sdbout.c).  */
  DWARF_DEBUG,	    /* Write Dwarf debug info (using dwarfout.c).  */
  DWARF2_DEBUG,	    /* Write Dwarf v2 debug info (using dwarf2out.c).  */
  XCOFF_DEBUG	    /* Write IBM/Xcoff debug info (using dbxout.c).  */
};

/* Specify which kind of debugging info to generate.  */
extern enum debug_info_type write_symbols;

enum debug_info_level
{
  DINFO_LEVEL_NONE,	/* Write no debugging info.  */
  DINFO_LEVEL_TERSE,	/* Write minimal info to support tracebacks only.  */
  DINFO_LEVEL_NORMAL,	/* Write info for all declarations (and line table). */
  DINFO_LEVEL_VERBOSE	/* Write normal info plus #define/#undef info.  */
};

/* Specify how much debugging info to generate.  */
extern enum debug_info_level debug_info_level;

/* Nonzero means use GNU-only extensions in the generated symbolic
   debugging information.  */
extern int use_gnu_debug_info_extensions;

/* Nonzero means do optimizations.  -opt.  */

extern int optimize;

/* Nonzero means optimize for size.  -Os.  */

extern int optimize_size;

/* Don't print functions as they are compiled and don't print
   times taken by the various passes.  -quiet.  */

extern int quiet_flag;

/* Don't print warning messages.  -w.  */

extern int inhibit_warnings;

/* Do print extra warnings (such as for uninitialized variables).  -W.  */

extern int extra_warnings;

/* Nonzero to warn about unused variables, functions et.al.  Use
   set_Wunused() to update the -Wunused-* flags that correspond to the
   -Wunused option. */

extern void set_Wunused PARAMS ((int setting));

extern int warn_unused_function;
extern int warn_unused_label;
extern int warn_unused_parameter;
extern int warn_unused_variable;
extern int warn_unused_value;

/* Nonzero to warn about code which is never reached.  */

extern int warn_notreached;

/* Nonzero means warn if inline function is too large.  */

extern int warn_inline;

/* Nonzero to warn about variables used before they are initialized.  */

extern int warn_uninitialized;

/* Zero if unknown pragmas are ignored
   One if the compiler should warn about an unknown pragma not in
   a system include file.
   Greater than one if the compiler should warn for all unknown
   pragmas.  */

extern int warn_unknown_pragmas;

/* Nonzero means warn about all declarations which shadow others.   */

extern int warn_shadow;

/* Warn if a switch on an enum fails to have a case for every enum value.  */

extern int warn_switch;

/* Nonzero means warn about function definitions that default the return type
   or that use a null return and have a return-type other than void.  */

extern int warn_return_type;

/* Nonzero means warn about pointer casts that increase the required
   alignment of the target type (and might therefore lead to a crash
   due to a misaligned access).  */

extern int warn_cast_align;

/* Nonzero means warn about any identifiers that match in the first N
   characters.  The value N is in `id_clash_len'.  */

extern int warn_id_clash;
extern int id_clash_len;

/* Nonzero means warn about any objects definitions whose size is larger
   than N bytes.  Also want about function definitions whose returned
   values are larger than N bytes. The value N is in `larger_than_size'.  */

extern int warn_larger_than;
extern HOST_WIDE_INT larger_than_size;

/* Warn if a function returns an aggregate,
   since there are often incompatible calling conventions for doing this.  */

extern int warn_aggregate_return;

/* Warn if packed attribute on struct is unnecessary and inefficient.  */

extern int warn_packed;

/* Warn when gcc pads a structure to an alignment boundary.  */

extern int warn_padded;

/* Nonzero if generating code to do profiling.  */

extern int profile_flag;

/* Nonzero if generating code to do profiling on the basis of basic blocks.  */

extern int profile_block_flag;

/* Nonzero if generating code to profile program flow graph arcs. */

extern int profile_arc_flag;

/* Nonzero if generating info for gcov to calculate line test coverage. */

extern int flag_test_coverage;

/* Nonzero indicates that branch taken probabilities should be calculated. */

extern int flag_branch_probabilities;

/* Nonzero for -pedantic switch: warn about anything
   that standard C forbids.  */

extern int pedantic;

/* Temporarily suppress certain warnings.
   This is set while reading code from a system header file.  */

extern int in_system_header;

/* Nonzero for -dp: annotate the assembly with a comment describing the
   pattern and alternative used.  */

extern int flag_print_asm_name;

/* Now the symbols that are set with `-f' switches.  */

/* Nonzero means `char' should be signed.  */

extern int flag_signed_char;

/* Nonzero means give an enum type only as many bytes as it needs.  */

extern int flag_short_enums;

/* Nonzero for -fcaller-saves: allocate values in regs that need to
   be saved across function calls, if that produces overall better code.
   Optional now, so people can test it.  */

extern int flag_caller_saves;

/* Nonzero for -fpcc-struct-return: return values the same way PCC does.  */

extern int flag_pcc_struct_return;

/* Nonzero for -fforce-mem: load memory value into a register
   before arithmetic on it.  This makes better cse but slower compilation.  */

extern int flag_force_mem;

/* Nonzero for -fforce-addr: load memory address into a register before
   reference to memory.  This makes better cse but slower compilation.  */

extern int flag_force_addr;

/* Nonzero for -fdefer-pop: don't pop args after each function call;
   instead save them up to pop many calls' args with one insns.  */

extern int flag_defer_pop;

/* Nonzero for -ffloat-store: don't allocate floats and doubles
   in extended-precision registers.  */

extern int flag_float_store;

/* Nonzero enables strength-reduction in loop.c.  */

extern int flag_strength_reduce;

/* Nonzero enables loop unrolling in unroll.c.  Only loops for which the
   number of iterations can be calculated at compile-time (UNROLL_COMPLETELY,
   UNROLL_MODULO) or at run-time (preconditioned to be UNROLL_MODULO) are
   unrolled.  */

extern int flag_unroll_loops;

/* Nonzero enables loop unrolling in unroll.c.  All loops are unrolled.
   This is generally not a win.  */

extern int flag_unroll_all_loops;

/* Nonzero forces all invariant computations in loops to be moved
   outside the loop. */

extern int flag_move_all_movables;

/* Nonzero forces all general induction variables in loops to be
   strength reduced. */

extern int flag_reduce_all_givs;

/* Nonzero for -fcse-follow-jumps:
   have cse follow jumps to do a more extensive job.  */

extern int flag_cse_follow_jumps;

/* Nonzero for -fcse-skip-blocks:
   have cse follow a branch around a block.  */

extern int flag_cse_skip_blocks;

/* Nonzero for -fexpensive-optimizations:
   perform miscellaneous relatively-expensive optimizations.  */
extern int flag_expensive_optimizations;

/* Nonzero for -fwritable-strings:
   store string constants in data segment and don't uniquize them.  */

extern int flag_writable_strings;

/* Nonzero means don't put addresses of constant functions in registers.
   Used for compiling the Unix kernel, where strange substitutions are
   done on the assembly output.  */

extern int flag_no_function_cse;

/* Nonzero for -fomit-frame-pointer:
   don't make a frame pointer in simple functions that don't require one.  */

extern int flag_omit_frame_pointer;

/* Nonzero to inhibit use of define_optimization peephole opts.  */

extern int flag_no_peephole;

/* Nonzero means all references through pointers are volatile.  */

extern int flag_volatile;

/* Nonzero means treat all global and extern variables as volatile.  */

extern int flag_volatile_global;

/* Nonzero means treat all static variables as volatile.  */

extern int flag_volatile_static;

/* Nonzero allows GCC to violate some IEEE or ANSI rules regarding math
   operations in the interest of optimization.  For example it allows
   GCC to assume arguments to sqrt are nonnegative numbers, allowing
   faster code for sqrt to be generated. */

extern int flag_fast_math;

/* Nonzero allows GCC to optimize sibling and tail recursive calls.  */

extern int flag_optimize_sibling_calls;

/* Nonzero means the front end generally wants `errno' maintained by math
   operations, like built-in SQRT, unless overridden by flag_fast_math.  */

extern int flag_errno_math;

/* 0 means straightforward implementation of complex divide acceptable.
   1 means wide ranges of inputs must work for complex divide.
   2 means C9X-like requirements for complex divide (not yet implemented).  */

extern int flag_complex_divide_method;

/* Nonzero means to run loop optimizations twice.  */

extern int flag_rerun_loop_opt;

/* Nonzero means make functions that look like good inline candidates
   go inline.  */

extern int flag_inline_functions;

/* Nonzero for -fkeep-inline-functions: even if we make a function
   go inline everywhere, keep its definition around for debugging
   purposes.  */

extern int flag_keep_inline_functions;

/* Nonzero means that functions declared `inline' will be treated
   as `static'.  Prevents generation of zillions of copies of unused
   static inline functions; instead, `inlines' are written out
   only when actually used.  Used in conjunction with -g.  Also
   does the right thing with #pragma interface.  */

extern int flag_no_inline;

/* Nonzero if we are only using compiler to check syntax errors.  */

extern int flag_syntax_only;

/* Nonzero means we should save auxiliary info into a .X file.  */

extern int flag_gen_aux_info;

/* Nonzero means make the text shared if supported.  */

extern int flag_shared_data;

/* flag_schedule_insns means schedule insns within basic blocks (before
   local_alloc).
   flag_schedule_insns_after_reload means schedule insns after
   global_alloc.  */

extern int flag_schedule_insns;
extern int flag_schedule_insns_after_reload;

/* flag_schedule_depend_count means rank_for_schedule may break a tie towards
   the insn with more forward dependents.  Clear it to fall through to the
   INSN_LUID (original order) tie-break instead.  */

extern int flag_schedule_depend_count;

/* flag_schedule_low_dest_first means rank_for_schedule may break a tie towards
   the insn whose single SET writes the lower-numbered hard register, for the
   registers the target names in SCHED_DEST_ORDER_REGNO_P.  Off by default; the
   fork's own tie-breaks (forward-dependent count, then INSN_LUID) decide
   instead.  */

extern int flag_schedule_low_dest_first;

/* Nonzero means a matching-constraint (two-address) operand may not tie its
   quantity to the output, so the input keeps its own register and the copy
   the reference emits before a destructive operation survives.  */
extern int flag_match0_keeps_input;

/* flag_schedule_high_dest_first is the same tie-break, in the same direction,
   for the registers the target names in SCHED_HIGH_DEST_ORDER_REGNO_P -- the
   ones that are not a call's argument registers -- and only for an insn with no
   call among its forward dependents, so the two flags never look at the same
   insn.  Off by default; the fork's own tie-breaks decide instead.  */

extern int flag_schedule_high_dest_first;

/* flag_schedule_call_dest_descending is -fsched-low-dest-first's gate with the
   comparison negated: the same call-argument setters, ordered highest register
   first.  Mutually exclusive with that flag, and it wins if both are set.  Off
   by default; the fork's own tie-breaks decide instead.  */

extern int flag_schedule_call_dest_descending;

/* flag_schedule_store_first means rank_for_schedule ranks every store alike and
   above every non-store insn, so a store issues as soon as its address and
   value are ready.  Off by default; INSN_PRIORITY decides instead.  */

extern int flag_schedule_store_first;

/* flag_schedule_alias means the instruction scheduler's dependence analysis may
   use alias analysis to decide that two memory references do not conflict.
   Clear it to assume every load and store conflicts with every other, so
   memory references keep the order they were written in.  Constant-pool
   references and read-after-read are unaffected.  */

extern int flag_schedule_alias;

/* flag_thumb_contiguous_immediate means arm_reorg may pull the two halves of a
   split Thumb constant back together when scheduling put an independent insn
   between them.  Some reference objects want that gap left alone, and there is
   no target_flags bit free to spell it, so it is an -f option like the tie-break
   above.  */
extern int flag_thumb_contiguous_immediate;

/* flag_thumb_next_arg_between_split means arm_reorg may place an immediately
   following call-argument constant between the move and long shift that build
   the preceding argument.  The transform is structural and opt-in.  */
extern int flag_thumb_next_arg_between_split;

/* flag_thumb_call_arg1_before_arg0 means arm_reorg may put an adjacent r1
   setter ahead of a constant r0 setter when the pair feeds the same call.  */
extern int flag_thumb_call_arg1_before_arg0;

/* flag_thumb_call_arg0_pool_load widens that repair to an r0 argument loaded
   from the constant pool -- a function or object address -- rather than only a
   plain integer constant.  The reference objects invert the same pair either
   way; only the shape of the r0 source differs.  Off by default, source-routed.  */
extern int flag_thumb_call_arg0_pool_load;

/* flag_thumb_arg0_after_split means arm_reorg may push an r0 call argument that
   the scheduler parked inside a long split immediate's two halves down past the
   shift, so the split stays contiguous.  This is the inverse of
   flag_thumb_next_arg_between_split, which fills that same slot.  */
extern int flag_thumb_arg0_after_split;

/* flag_thumb_return_value_before_stack_adjust means arm_reorg may put the move
   that materialises the return value ahead of the epilogue's stack-pointer
   increment when the two are independent.  */
extern int flag_thumb_return_value_before_stack_adjust;

/* flag_thumb_sink_group_pool_loads means arm_reorg may move the channel-base
   and control literal loads of a grouped transfer down to the transfer.  */
extern int flag_thumb_sink_group_pool_loads;

/* flag_thumb_sink_stack_adjust means arm_reorg may move the epilogue's
   stack-pointer increment down past tail insns that do not touch sp.  */
extern int flag_thumb_sink_stack_adjust;

/* flag_thumb_sink_dependent_load means arm_reorg may delay a load whose
   address register was materialised by the immediately preceding insn.  */
extern int flag_thumb_sink_dependent_load;
extern int flag_thumb_collapse_dead_scratch;
extern int flag_thumb_sink_block_constant;
extern int flag_thumb_sink_past_pool_load;
extern int flag_thumb_sink_constant_past_memory;

/* flag_thumb_call_arg0_before_store means arm_reorg may put an independent
   register copy into r0 ahead of an adjacent memory store when that copy is
   immediately followed by a call.  */
extern int flag_thumb_call_arg0_before_store;

/* flag_thumb_postcall_byte_increment_r2 retargets one strict post-call
   byte-state increment from r1 to r2 after reload.  */
extern int flag_thumb_postcall_byte_increment_r2;

/* flag_cse_two_insn_immediate means cse_insn may substitute an equivalent
   register for a CONST_INT source that the target would need more than one
   instruction to materialise.  Clear it to keep the constant at each site, so
   the value is re-materialised rather than kept live in a register.  */
extern int flag_cse_two_insn_immediate;

/* flag_cse_shift_immediate is the finer split of the class above: it covers
   only the shifted (`movs/lsls', constraint K) constants, leaving the negated
   (`movs/negs', constraint J) constants shared.  Clear it to re-materialise
   shifted constants at each site.  */
extern int flag_cse_shift_immediate;

/* flag_cse_pool_immediate means cse_insn may substitute an equivalent register
   for a CONST_INT source the target materialises out of the literal pool.
   Clear it to reload the pool word at each site instead.  */
extern int flag_cse_pool_immediate;

/* flag_gcse_insert_load means partial-redundancy elimination may insert a copy
   of an expression that reads memory in order to make a later occurrence of it
   fully redundant.  Clear it to leave such an expression out of the PRE problem
   entirely -- neither inserted nor deleted -- so each load stays at the site it
   was written.  Loads whose redundancy needs no insertion are unaffected.  */

extern int flag_gcse_insert_load;

/* flag_thumb_move_before_alu means arm_reorg may put an independent register
   copy ahead of an adjacent two-address ALU insn, which is the order some
   reference objects always take.  Off by default; there is no target_flags bit
   left to spell it.  */
extern int flag_thumb_move_before_alu;

/* flag_thumb_minipool_tail_first means arm_reorg may rotate the final node of
   an exactly-three-entry Thumb minipool to its head.  Every entry must be a
   live four-byte word and the rotated offsets must satisfy every recorded
   reach constraint.  Off by default; the layout fingerprint is
   source-scoped.  */
extern int flag_thumb_minipool_tail_first;

/* flag_thumb_orr_dead_input_reuse means arm_reorg may keep a strict r2/r3
   two-address OR's result in its dead r3 input, reuse r2 for the following
   volatile halfword-store address, and move one independent r6 constant load
   after that store.  Off by default; the reference fingerprint is
   source-scoped.  */
extern int flag_thumb_orr_dead_input_reuse;

/* flag_thumb_entry_frame_cluster means arm_reorg may reorder one strict
   post-reload entry sequence so a frame allocation and dependent global load
   fill the first literal load's delay slots, while two stack initializers fill
   an index shift's dependency slot.  Off by default; the reference fingerprint
   is source-scoped.  */
extern int flag_thumb_entry_frame_cluster;

/* flag_thumb_literal_before_index_shift means arm_reorg may move one strict
   constant-pool load ahead of an adjacent table-index shift.  The following
   store must consume the literal, table base, and shifted index in exact hard
   registers and kill all three.  Off by default; the reference fingerprint is
   source-scoped.  */
extern int flag_thumb_literal_before_index_shift;

/* flag_thumb_low_constant_before_high_move means arm_reorg may fill the
   dependency slot between a low-register immediate and a move of that value
   into a saved high register with an independent saved-low-register immediate.
   The high move may cross at most two additional independent register SETs on
   its way to that immediate.  Off by default; the reference fingerprint is
   source-scoped.  */
extern int flag_thumb_low_constant_before_high_move;

/* flag_thumb_high_move_before_stack_store means arm_reorg may restore the
   original order of one strict stack-zero initializer whose saved high-register
   copy was transposed after its stack store by sched2.  The complete four-insn
   hard-register and death-note fingerprint is required.  Off by default; the
   reference fingerprint is source-scoped.  */
extern int flag_thumb_high_move_before_stack_store;

/* flag_thumb_split_group_base means arm_pre_reload gives the uses that follow a
   grouped descriptor transfer their own materialisation of the base address
   instead of letting them reach back to the register the transfer left behind.
   The reference objects reload the pool word for a status poll rather than
   copying the surviving base, which is only expressible if the two uses are
   distinct pseudos.  Off by default; there is no target_flags bit left to spell
   it.  */
extern int flag_thumb_split_group_base;

/* flag_thumb_group_control_last means arm_reorg may sink a grouped descriptor
   transfer's control-word load, and the destination move ahead of it, down to
   the transfer itself.  thumb_order_grouped_dma_store already normalises this
   order, but only when the three setup insns are already adjacent; a descriptor
   whose source address needs arithmetic has independent insns interleaved and
   falls out of that pattern.  Separate flag rather than a widening, because the
   adjacent case reorders to a different final order and sources are routed
   against it.  Off by default.  */
extern int flag_thumb_group_control_last;

/* flag_thumb_group_pooled_control_last is the same repair for the shape where
   the control word is too wide for a Thumb immediate and arrives as a
   constant-pool load, and where the value the transfer stores first is a plain
   register copy into r0.  The pooled load has no dependence on the copy, so the
   scheduler is free to issue it first; the reference objects issue the copy
   first and load the control word immediately before the transfer.  Off by
   default.  Witness 0801a4fc.  */
extern int flag_thumb_group_pooled_control_last;

/* flag_thumb_high_move_before_alu is the high-register variant of
   -fthumb-move-before-alu: it also accepts a copy into a high register (which
   writes no flags) and an ALU insn whose second input is an immediate.  Off by
   default.  Witness 0808b868.  */
extern int flag_thumb_high_move_before_alu;

/* flag_thumb_move_before_immediate_alu widens -fthumb-move-before-alu the other
   way: the ALU insn's second input may be an immediate, and the insn issued
   ahead of it may be a load as well as a low-register copy.  Off by default.
   Witness 0801fd34.  */
extern int flag_thumb_move_before_immediate_alu;

/* flag_thumb_late_frame_allocation is the mirror of -mearly-frame-allocation:
   it lowers, rather than raises, the scheduling priority of a Thumb stack
   decrement so the incoming-argument copies issue ahead of it.  Some reference
   objects open with the argument moves and only then allocate the frame.  Off
   by default; there is no target_flags bit left to spell it, which is why this
   is an -f flag while its early twin is an -m one.  */
extern int flag_thumb_late_frame_allocation;

/* flag_thumb_group_zero_any_register widens the stack-zero-before-base repair
   that flag_thumb_group_control_last performs.  That repair only fires when
   register allocation happened to pick r5 for the saved call result and r6 for
   the zero word; other objects with the identical source shape land on a
   different low-register pair and fall out of the pattern.  With this flag the
   two registers are read off the insns instead of being hard-coded, and only
   their relationships are checked.  Off by default and source-routed.  */
extern int flag_thumb_group_zero_any_register;

/* flag_thumb_leaf_no_lr stops THUMB_INITIAL_ELIMINATION_OFFSET from latching a
   permanent "this function contains a far jump" answer for functions with an
   empty frame and no memory arguments.  Branch lengths are still unknown when
   that query runs, so every conditional branch reads as far, and a leaf
   function with any if/else ends up pushing and popping the link register it
   never needed.  With nothing on the stack no elimination offset can move, so
   the answer is deferred to the prologue, where real lengths are known.  Off by
   default.  */
extern int flag_thumb_leaf_no_lr;

/* flag_thumb_no_if_convert disables the if-conversion pass entirely, modelling
   a compiler generation that predates it.  See ifcvt.c for what it changes.
   Off by default.  */
extern int flag_thumb_no_if_convert;

/* flag_thumb_group_value1_before_base restores one strict grouped-DMA setup
   order: an immediate, source-address add, base literal, shift, control
   literal, and transfer.  It is default-off and source-routed.  */
extern int flag_thumb_group_value1_before_base;

/* flag_thumb_group_value2_in_place lets a grouped descriptor transfer's third
   word be materialised straight into r2 when its definition is a constant,
   instead of being defined into a pseudo and copied.  value0 already has an
   equivalent special case; value2 had none, and the surviving copy is the last
   divergence in the descriptor-then-call regions.  Off by default.  */
extern int flag_thumb_group_value2_in_place;

/* flag_thumb_group_control_rematerialize lets a grouped descriptor transfer
   reload its control word from the literal pool at each transfer instead of
   copying it out of a register an earlier group is keeping alive.  The
   reference issues `ldr r2, [pc, #K]' against the same pool word before every
   stmia, which lets the shared value die at its first transfer, frees the low
   register between groups for address arithmetic, and keeps a callee-saved
   register off the prologue.  Only a pool-class constant is duplicated: that
   trade is one insn for one insn, and the minipool machinery coalesces the
   repeated word.  Off by default and source-routed.  */
extern int flag_thumb_group_control_rematerialize;

/* flag_thumb_group_base_in_r3 materialises a grouped descriptor transfer's
   base directly into r3 when its definition is a constant or pool load and
   nothing between the definition and the transfer touches r3.  The reference
   allocates the descriptor base low-first, so control accesses address
   [r3, #K] and the transfer writes through the same register; our allocator
   assigns the longest-lived quantity first while the group's value copies pin
   r0-r2, which pushes the base to r4 and permutes every temporary after it.
   Same def-retargeting shape as flag_thumb_group_value2_in_place.  Off by
   default and source-routed.  */
extern int flag_thumb_group_base_in_r3;

/* flag_thumb_sched_pool_load_late makes the post-reload ready list issue a
   literal-pool load after a ready immediate-construction insn, the order the
   reference produces at descriptor groups and calls.  It decides only a
   comparison between those two classes; every other pair keeps the model's
   ranking.  The target names the classes in SCHED_POOL_LOAD_LATE_CLASS, and
   without that definition the flag does nothing.  Off by default and
   source-routed.  */
extern int flag_thumb_sched_pool_load_late;

/* flag_thumb_hoist_parameter_save lets a `mov <high>, <arg>' parameter save move
   up over insns that touch neither of its registers, stopping at another such
   save so the saves keep parameter order.  thumb_order_high_register_move only
   swaps an adjacent pair with a constant setup; some references put every save
   first, ahead of several body insns.  Off by default.  */
extern int flag_thumb_hoist_parameter_save;

/* flag_thumb_entry_saves_descending emits a pair of adjacent entry parameter
   saves in descending argument-register order -- the later parameter first.
   Some references save r1 before r0; ours always follows parameter order.  Off
   by default.  */
extern int flag_thumb_entry_saves_descending;

/* flag_thumb_0807a664_exact applies the independently verified post-reload
   0807a664 register/lifetime shape.  It is an experimental, source-routed
   compatibility mode and is intentionally off for every other translation
   unit.  */
extern int flag_thumb_0807a664_exact;

/* flag_canonicalize_comparison means simplify_comparison may rewrite a signed
   `x < C` into `x <= C-1` (and `x >= C` into `x > C-1`).  Clear it to leave the
   comparison code and its constant as written.  */

extern int flag_canonicalize_comparison;

/* The following flags have effect only for scheduling before register
   allocation:

   flag_schedule_interblock means schedule insns accross basic blocks.
   flag_schedule_speculative means allow speculative motion of non-load insns.
   flag_schedule_speculative_load means allow speculative motion of some
   load insns.
   flag_schedule_speculative_load_dangerous allows speculative motion of more
   load insns.  */

extern int flag_schedule_interblock;
extern int flag_schedule_speculative;
extern int flag_schedule_speculative_load;
extern int flag_schedule_speculative_load_dangerous;

/* flag_branch_on_count_reg means try to replace add-1,compare,branch tupple
   by a cheaper branch, on a count register. */
extern int flag_branch_on_count_reg;

/* This option is set to 1 on -fsingle-precision-constant option which is
   used to convert the floating point constants to single precision 
   constants. */

extern int flag_single_precision_constant;

/* Nonzero means put things in delayed-branch slots if supported. */

extern int flag_delayed_branch;

/* Nonzero means suppress output of instruction numbers and line number
   notes in debugging dumps.  */

extern int flag_dump_unnumbered;

/* Nonzero means pretend it is OK to examine bits of target floats,
   even if that isn't true.  The resulting code will have incorrect constants,
   but the same series of instructions that the native compiler would make.  */

extern int flag_pretend_float;

/* Nonzero means change certain warnings into errors.
   Usually these are warnings about failure to conform to some standard.  */

extern int flag_pedantic_errors;

/* Nonzero means generate position-independent code.
   This is not fully implemented yet.  */

extern int flag_pic;

/* Nonzero means generate extra code for exception handling and enable
   exception handling.  */

extern int flag_exceptions;

/* Nonzero means use the new model for exception handling. Replaces 
   -DNEW_EH_MODEL as a compile option. */

extern int flag_new_exceptions;

/* Nonzero means generate frame unwind info table when supported */

extern int flag_unwind_tables;

/* Nonzero means don't place uninitialized global data in common storage
   by default.  */

extern int flag_no_common;

/* -finhibit-size-directive inhibits output of .size for ELF.
   This is used only for compiling crtstuff.c,
   and it may be extended to other effects
   needed for crtstuff.c on other systems.  */
extern int flag_inhibit_size_directive;

/* Nonzero means place each function into its own section on those platforms
   which support arbitrary section names and unlimited numbers of sections.  */

extern int flag_function_sections;

/* ... and similar for data.  */
 
extern int flag_data_sections;

/* -fverbose-asm causes extra commentary information to be produced in
   the generated assembly code (to make it more readable).  This option
   is generally only of use to those who actually need to read the
   generated assembly code (perhaps while debugging the compiler itself).
   -fno-verbose-asm, the default, causes the extra information
   to not be added and is useful when comparing two assembler files.  */

extern int flag_verbose_asm;

/* -dA causes debug information to be produced in
   the generated assembly code (to make it more readable).  This option
   is generally only of use to those who actually need to read the
   generated assembly code (perhaps while debugging the compiler itself).
   Currently, this switch is only used by dwarfout.c; however, it is intended
   to be a catchall for printing debug information in the assembler file.  */

extern int flag_debug_asm;

/* -fgnu-linker specifies use of the GNU linker for initializations.
   -fno-gnu-linker says that collect will be used.  */
extern int flag_gnu_linker;

/* Tag all structures with __attribute__(packed) */
extern int flag_pack_struct;

/* This flag is only tested if alias checking is enabled.
   0 if pointer arguments may alias each other.  True in C.
   1 if pointer arguments may not alias each other but may alias
   global variables.
   2 if pointer arguments may not alias each other and may not
   alias global variables.  True in Fortran.
   The value is ignored if flag_alias_check is 0.  */
extern int flag_argument_noalias;

/* Nonzero if we should do (language-dependent) alias analysis.
   Typically, this analysis will assume that expressions of certain
   types do not alias expressions of certain other types.  Only used
   if alias analysis (in general) is enabled.  */
extern int flag_strict_aliasing;

/* Emit code to probe the stack, to help detect stack overflow; also
   may cause large objects to be allocated dynamically.  */
extern int flag_stack_check;

/* Do the full regmove optimization pass.  */
extern int flag_regmove;

/* Instrument functions with calls at entry and exit, for profiling.  */
extern int flag_instrument_function_entry_exit;

/* Perform a peephole pass before sched2. */
extern int flag_peephole2;

/* -fbounded-pointers causes gcc to compile pointers as composite
   objects occupying three words: the pointer value, the base address
   of the referent object, and the address immediately beyond the end
   of the referent object.  The base and extent allow us to perform
   runtime bounds checking.  -fbounded-pointers implies -fcheck-bounds.  */
extern int flag_bounded_pointers;

/* -fcheck-bounds causes gcc to generate array bounds checks.
   For C, C++: defaults to value of flag_bounded_pointers.
   For ObjC: defaults to off.
   For Java: defaults to on.
   For Fortran: defaults to off.
   For CHILL: defaults to off.  */
extern int flag_bounds_check;

/* If one, renumber instruction UIDs to reduce the number of
   unused UIDs if there are a lot of instructions.  If greater than
   one, unconditionally renumber instruction UIDs.  */
extern int flag_renumber_insns;

/* Other basic status info about current function.  */

/* Nonzero means current function must be given a frame pointer.
   Set in stmt.c if anything is allocated on the stack there.
   Set in reload1.c if anything is allocated on the stack there.  */

extern int frame_pointer_needed;

/* Set nonzero if jump_optimize finds that control falls through
   at the end of the function.  */

extern int can_reach_end;

/* Nonzero if GCC must add code to check memory access (used by Checker).  */

extern int flag_check_memory_usage;

/* Nonzero if GCC must prefix function names (used with
   flag_check_memory_usage).  */

extern int flag_prefix_function_name;

/* Value of the -G xx switch, and whether it was passed or not.  */
extern int g_switch_value;
extern int g_switch_set;

/* Value of the -finline-limit flag.  */

extern int inline_max_insns;

/* Values of the -falign-* flags: how much to align labels in code. 
   0 means `use default', 1 means `don't align'.  
   For each variable, there is an _log variant which is the power
   of two not less than the variable, for .align output.  */

extern int align_loops;
extern int align_loops_log;
extern int align_jumps;
extern int align_jumps_log;
extern int align_labels;
extern int align_labels_log;
extern int align_functions;
extern int align_functions_log;

/* Nonzero if we dump in VCG format, not plain text.  */
extern int dump_for_graph;

/* Selection of the graph form.  */
enum graph_dump_types
{
  no_graph = 0,
  vcg
};
extern enum graph_dump_types graph_dump_format;

/* Nonzero means ignore `#ident' directives.  0 means handle them.
   On SVR4 targets, it also controls whether or not to emit a
   string identifying the compiler.  */

extern int flag_no_ident;
