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

#if (defined(OSEE_TC_LINK_BMHD))
/* We declare that we want generate and link the Boot Mode Headers */
#define __BMHD0_CONFIG  __BMHD_GENERATE
#define __BMHD1_CONFIG  __BMHD_GENERATE
#define __BMHD2_CONFIG  __BMHD_GENERATE
#define __BMHD3_CONFIG  __BMHD_GENERATE
#endif /* OSEE_TC_LINK_BMHD */

#if defined(__PROC_TC39X__)
#include "tc39x.lsl"

/* N.B. abs18 addressing is broken (especially in for AURIX 2G).
        I forced it off. */
section_layout mpe:vtc:linear
{
  /* map .bss and .data in not cached address space otherwise all sort of
    troubles happen */
  group liner_not_cached (ordered, run_addr=mem:mpe:lmuram0/not_cached) {
    select "*(.bss|.bss*)" (attributes=-x+r+w); 
    select "*(.data|.data*)" (attributes=-x+r+w);
  }

  group tc0_liner_const (run_addr=mem:mpe:pflash0) {
    select "*(.CPU0.oe_kernel_const|.CPU0.oe_kernel_const*)";
  }

  group tc0_liner_code (run_addr=mem:mpe:pflash0) {
    select "*(.CPU0.code|.CPU0.code*)";
  }

  group tc1_liner_const (run_addr=mem:mpe:pflash1) {
    select "*(.CPU1.oe_kernel_const|.CPU1.oe_kernel_const*)";
  }

  group tc1_liner_code (run_addr=mem:mpe:pflash1) {
    select "*(.CPU1.code|.CPU1.code*)";
  }

  group tc2_liner_const (run_addr=mem:mpe:pflash2) {
    select "*(.CPU2.oe_kernel_const|.CPU2.oe_kernel_const*)";
  }

  group tc2_liner_code (run_addr=mem:mpe:pflash2) {
    select "*(.CPU2.code|.CPU2.code*)";
  }

  group tc3_liner_const (run_addr=mem:mpe:pflash3) {
    select "*(.CPU3.oe_kernel_const|.CPU3.oe_kernel_const*)";
  }

  group tc3_liner_code (run_addr=mem:mpe:pflash3) {
    select "*(.CPU3.code|.CPU3.code*)";
  }

  group tc4_liner_const (run_addr=mem:mpe:pflash4) {
    select "*(.CPU4.oe_kernel_const|.CPU4.oe_kernel_const*)";
  }

  group tc4_liner_code (run_addr=mem:mpe:pflash4) {
    select "*(.CPU4.code|.CPU4.code*)";
  }

  group tc5_liner_const (run_addr=mem:mpe:pflash5) {
    select "*(.CPU6.oe_kernel_const|.CPU6.oe_kernel_const*)";
  }

  group tc5_liner_code (run_addr=mem:mpe:pflash5) {
    select "*(.CPU6.code|.CPU6.code*)";
  }

}

section_layout mpe:tc0:linear
{
  group tc0_private_code (run_addr = mem:mpe:pflash0, nocopy, attributes=rx) {
    select "*(.text|.text*)";
  }
}

section_layout mpe:tc1:linear
{
  group tc1_private_code (run_addr = mem:mpe:pflash1, nocopy, attributes=rx) {
    select "*(.text|.text*)";
  }
}

section_layout mpe:tc2:linear
{
  group tc2_private_code (run_addr = mem:mpe:pflash2, nocopy, attributes=rx) {
    select "*(.text|.text*)";
  }
}

section_layout mpe:tc3:linear
{
  group tc3_private_code (run_addr = mem:mpe:pflash3, nocopy, attributes=rx) {
    select "*(.text|.text*)";
  }
}

section_layout mpe:tc4:linear
{
  group tc4_private_code (run_addr = mem:mpe:pflash4, nocopy, attributes=rx) {
    select "*(.text|.text*)";
  }
}

section_layout mpe:tc5:linear
{
  group tc6_private_code (run_addr = mem:mpe:pflash5, nocopy, attributes=rx) {
    select "*(.text|.text*)";
  }
}

#else
#include <cpu.lsl>
#endif


memory xram_8_a (tag="on-board")
{
    mau = 8;
    type = ram;
    size = 1M;
    map cached(dest=bus:mpe:sri, dest_offset=0x88000000, size=1M);
    map not_cached(dest=bus:mpe:sri, dest_offset=0xa8000000, size=1M, reserved);
}