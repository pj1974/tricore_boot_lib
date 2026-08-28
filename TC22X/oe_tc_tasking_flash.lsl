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
#if defined(__PROC_TC22X__)
#include "tc22x.lsl"

#else
#include <cpu.lsl>
#endif
