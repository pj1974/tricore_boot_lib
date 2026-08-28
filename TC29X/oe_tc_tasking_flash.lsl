/**
 *
 * This file derives from a modification of the TASKING linker scripts,
 * distributed under the following license:
 *
 * TASKING VX-toolset for TriCore
 * Eclipse project linker script file
 *
 */

/** \file   oe_tc_tasking_flash.lsl
 *  \brief  Linker script file for TASKING compiler (no iLLD integration)
 *  \author Errico Guidieri
 *  \date   2019
 */
#if (!defined(USTACK_TC0))
#define USTACK_TC0 4k
#endif /* !USTACK_TC0 */
#if defined(__PROC_TC29X__)
#include "tc29x.lsl"

section_layout mpe:vtc:abs18
{
  /* map .zbss and .zdata in not cached address space otherwise all sort of
    troubles happen */
  group abs18_not_cached (ordered, run_addr=mem:mpe:lmuram/not_cached) {
    select "*(.zbss|.zbss*)" (attributes=-x+r+w); 
    select "*(.zdata|.zdata*)" (attributes=-x+r+w);
  }
/*
  group abs18_not_cached ( run_addr=mem:mpe:lmuram/not_cached ) {
    select ".zbss.oe_gbl_kernel_bss";
    select ".zdata.oe_gbl_kernel_data";
    select ".zdata.oe_kernel_data";
  }

  group api_abs18_not_cached ( run_addr=mem:mpe:lmuram/not_cached ) {
    select ".zbss.oe_api_bss";
    select ".zdata.oe_api_data";
  }
*/
}

section_layout mpe:vtc:linear
{
  /* map .bss and .data in not cached address space otherwise all sort of
    troubles happen */
  group liner_not_cached (ordered, run_addr=mem:mpe:lmuram/not_cached) {
    select "*(.bss|.bss*)" (attributes=-x+r+w); 
    select "*(.data|.data*)" (attributes=-x+r+w);
  }
/*
  group kernel_linear_not_cached (ordered, run_addr=mem:mpe:lmuram/not_cached)
  {
    select ".bss.oe_gbl_kernel_bss";
    select ".data.oe_gbl_kernel_data";
    select ".data.oe_kernel_data";
  }

  group api_linear_not_cached (ordered, run_addr=mem:mpe:lmuram/not_cached) {
    select ".bss.oe_api_bss";
    select ".data.oe_api_data";
  }
*/
}
#else
#include <cpu.lsl>
#endif
