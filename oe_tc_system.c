/*
 *
 * This file derives from a modification of the Infineon startup scripts,
 * distributed under the following license:
 *
 * \file IfxScuCcu.c
 * \brief SCU  basic functionality
 *
 * \version iLLD_1_0_1_3_0
 * \copyright Copyright (c) 2017 Infineon Technologies AG. All rights reserved.
 *
 *
 *                                 IMPORTANT NOTICE
 *
 *
 * Infineon Technologies AG (Infineon) is supplying this file for use
 * exclusively with Infineon's microcontroller products. This file can be freely
 * distributed within development tools that are supporting such microcontroller
 * products.
 *
 * THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 * INFINEON SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL,
 * OR CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *
 *
 */

/** \file   oe_tc_system.c
 *  \brief  PLL configuration and System Timer Implementation, to be used in
            OpenERIKA standalone configuration (no iLLD integration)
 *  \author Errico Guidieri
 *  \date   2017
 */

#include "oe_internal.h"

/* STM_SR Function Static storage declaration (if needed) */
#if (defined(OE_SINGLECORE))
#if (defined(OE_SYSTEM_TIMER_DEVICE)) &&\
    (OE_SYSTEM_TIMER_DEVICE == OE_TC_STM_SR0)
#define OE_TC_STM_SR0_STORAGE static
static void OE_tc_stm_set_sr0(OE_reg usec, OE_tc_isr_hw_prio intvec);
static void OE_tc_stm_set_sr0_next_match(OE_reg usec);
#else
#define OE_TC_STM_SR0_STORAGE
#endif /* OE_SYSTEM_TIMER_DEVICE == OE_TC_STM_SR0 */

#if (defined(OE_SYSTEM_TIMER_DEVICE)) &&\
    (OE_SYSTEM_TIMER_DEVICE == OE_TC_STM_SR1)
#define OE_TC_STM_SR1_STORAGE static
static void OE_tc_stm_set_sr1(OE_reg usec, OE_tc_isr_hw_prio intvec);
static void OE_tc_stm_set_sr1_next_match(OE_reg usec);
#else
#define OE_TC_STM_SR1_STORAGE
#endif /* OE_SYSTEM_TIMER_DEVICE == OE_TC_STM_SR1 */
#else /* OE_SINGLECORE */

#if ((defined(OE_SYSTEM_TIMER_CORE0_DEVICE)) &&             \
      (OE_SYSTEM_TIMER_CORE0_DEVICE == OE_TC_STM_SR0)) || \
    ((defined(OE_SYSTEM_TIMER_CORE1_DEVICE)) &&             \
      (OE_SYSTEM_TIMER_CORE1_DEVICE == OE_TC_STM_SR0)) || \
    ((defined(OE_SYSTEM_TIMER_CORE2_DEVICE)) &&             \
      (OE_SYSTEM_TIMER_CORE2_DEVICE == OE_TC_STM_SR0)) || \
    ((defined(OE_SYSTEM_TIMER_CORE3_DEVICE)) &&             \
      (OE_SYSTEM_TIMER_CORE3_DEVICE == OE_TC_STM_SR0)) || \
    ((defined(OE_SYSTEM_TIMER_CORE4_DEVICE)) &&             \
      (OE_SYSTEM_TIMER_CORE4_DEVICE == OE_TC_STM_SR0)) || \
    ((defined(OE_SYSTEM_TIMER_CORE6_DEVICE)) &&             \
      (OE_SYSTEM_TIMER_CORE6_DEVICE == OE_TC_STM_SR0))

#define OE_TC_STM_SR0_STORAGE static
static void OE_tc_stm_set_sr0(OE_reg usec, OE_tc_isr_hw_prio intvec);
static void OE_tc_stm_set_sr0_next_match(OE_reg usec);
#else
#define OE_TC_STM_SR0_STORAGE
#endif

#if ((defined(OE_SYSTEM_TIMER_CORE0_DEVICE)) &&             \
      (OE_SYSTEM_TIMER_CORE0_DEVICE == OE_TC_STM_SR1)) || \
    ((defined(OE_SYSTEM_TIMER_CORE1_DEVICE)) &&             \
      (OE_SYSTEM_TIMER_CORE1_DEVICE == OE_TC_STM_SR1)) || \
    ((defined(OE_SYSTEM_TIMER_CORE2_DEVICE)) &&             \
      (OE_SYSTEM_TIMER_CORE2_DEVICE == OE_TC_STM_SR1)) || \
    ((defined(OE_SYSTEM_TIMER_CORE3_DEVICE)) &&             \
      (OE_SYSTEM_TIMER_CORE3_DEVICE == OE_TC_STM_SR1)) || \
    ((defined(OE_SYSTEM_TIMER_CORE4_DEVICE)) &&             \
      (OE_SYSTEM_TIMER_CORE4_DEVICE == OE_TC_STM_SR1)) || \
    ((defined(OE_SYSTEM_TIMER_CORE6_DEVICE)) &&             \
      (OE_SYSTEM_TIMER_CORE6_DEVICE == OE_TC_STM_SR1))

#define OE_TC_STM_SR1_STORAGE static
static void OE_tc_stm_set_sr1(OE_reg usec, OE_tc_isr_hw_prio intvec);
static void OE_tc_stm_set_sr1_next_match(OE_reg usec);
#else
#define OE_TC_STM_SR1_STORAGE
#endif

#endif /* OE_SINGLECORE */

/* This part of the file is needed only if System Timer is defined */
#if (defined(OE_HAS_SYSTEM_TIMER))
/****************************************************************
                    System Timer Support
 ****************************************************************/

/* Map the right device that will be used as system timer
 * Legit Devices for System Timer Defines.
 * N.B:
 * For the system timer we will use STM peripheral. This peripheral
 * is composed by a 64 bit upper counter in free-run, two compare
 * registers (32 bit with offset and mask-length configurable),
 * and two services (read: interrupt sources). Each Compare
 * register can be tied to both service, and that would mean
 * 4 STM meaningful configuration, but only two independent.
 * For simplicity I fix a degree of freedom tying compare register
 * with corresponding service number. So the configuration will be
 * easier, still having two independent services source.
 *
 * (Check the documentation for more information)
 */

#if (defined(OE_SYSTEM_TIMER_DEVICE))
#if (OE_SYSTEM_TIMER_DEVICE != OE_TC_STM_SR0) && \
  (OE_SYSTEM_TIMER_DEVICE != OE_TC_STM_SR1)
#error Unsupported Device as System Timer!
#endif
#endif /* OE_SYSTEM_TIMER_DEVICE */
#if (defined(OE_SYSTEM_TIMER_CORE0_DEVICE))
#if (OE_SYSTEM_TIMER_CORE0_DEVICE != OE_TC_STM_SR0)  && \
  (OE_SYSTEM_TIMER_CORE0_DEVICE != OE_TC_STM_SR1)
#error Unsupported Device for CORE0 as System Timer!
#endif
#endif /* OE_SYSTEM_TIMER_CORE0_DEVICE */
#if (defined(OE_SYSTEM_TIMER_CORE1_DEVICE))
#if (OE_SYSTEM_TIMER_CORE1_DEVICE != OE_TC_STM_SR0)  && \
  (OE_SYSTEM_TIMER_CORE1_DEVICE != OE_TC_STM_SR1)
#error Unsupported Device for CORE1 as System Timer!
#endif
#endif /* OE_SYSTEM_TIMER_CORE1_DEVICE */
#if (defined(OE_SYSTEM_TIMER_CORE2_DEVICE))
#if (OE_SYSTEM_TIMER_CORE2_DEVICE != OE_TC_STM_SR0)  && \
  (OE_SYSTEM_TIMER_CORE2_DEVICE != OE_TC_STM_SR1)
#error Unsupported Device for CORE2 as System Timer!
#endif
#endif /* OE_SYSTEM_TIMER_CORE2_DEVICE */
#if (defined(OE_SYSTEM_TIMER_CORE3_DEVICE))
#if (OE_SYSTEM_TIMER_CORE3_DEVICE != OE_TC_STM_SR0)  && \
  (OE_SYSTEM_TIMER_CORE3_DEVICE != OE_TC_STM_SR1)
#error Unsupported Device for CORE3 as System Timer!
#endif
#endif /* OE_SYSTEM_TIMER_CORE3_DEVICE */
#if (defined(OE_SYSTEM_TIMER_CORE4_DEVICE))
#if (OE_SYSTEM_TIMER_CORE4_DEVICE != OE_TC_STM_SR0)  && \
  (OE_SYSTEM_TIMER_CORE4_DEVICE != OE_TC_STM_SR1)
#error Unsupported Device for CORE4 as System Timer!
#endif
#endif /* OE_SYSTEM_TIMER_CORE4_DEVICE */
#if (defined(OE_SYSTEM_TIMER_CORE6_DEVICE))
#if (OE_SYSTEM_TIMER_CORE6_DEVICE != OE_TC_STM_SR0)  && \
  (OE_SYSTEM_TIMER_CORE6_DEVICE != OE_TC_STM_SR1)
#error Unsupported Device for CORE6 as System Timer!
#endif
#endif /* OE_SYSTEM_TIMER_CORE6_DEVICE */

void OE_tricore_system_timer_handler(void) {
  OE_CDB * p_cdb;
#if (defined(OE_SINGLECORE))
#if (OE_SYSTEM_TIMER_DEVICE == OE_TC_STM_SR0)
  OE_tc_stm_set_sr0_next_match(OSTICKDURATION / 1000U);
#elif (OE_SYSTEM_TIMER_DEVICE == OE_TC_STM_SR1)
  OE_tc_stm_set_sr1_next_match(OSTICKDURATION / 1000U);
#endif /* OE_SYSTEM_TIMER_DEVICE */
#else /* OE_SINGLECORE */
  switch (OE_get_curr_core_id()) {
#if (defined(OE_SYSTEM_TIMER_CORE0_DEVICE))
    case OS_CORE_ID_MASTER:
#if (OE_SYSTEM_TIMER_CORE0_DEVICE == OE_TC_STM_SR0)
      OE_tc_stm_set_sr0_next_match(OSTICKDURATION_CORE0 / 1000U);
#elif (OE_SYSTEM_TIMER_CORE0_DEVICE == OE_TC_STM_SR1)
      OE_tc_stm_set_sr1_next_match(OSTICKDURATION_CORE0 / 1000U);
#endif
    break;
#endif /* OE_SYSTEM_TIMER_CORE0_DEVICE */
#if (defined(OE_SYSTEM_TIMER_CORE1_DEVICE))
    case OS_CORE_ID_1:
#if (OE_SYSTEM_TIMER_CORE1_DEVICE == OE_TC_STM_SR0)
      OE_tc_stm_set_sr0_next_match(OSTICKDURATION_CORE1 / 1000U);
#elif (OE_SYSTEM_TIMER_CORE1_DEVICE == OE_TC_STM_SR1)
      OE_tc_stm_set_sr1_next_match(OSTICKDURATION_CORE1 / 1000U);
#endif
    break;
#endif /* OE_SYSTEM_TIMER_CORE1_DEVICE */
#if (defined(OE_SYSTEM_TIMER_CORE2_DEVICE))
    case OS_CORE_ID_2:
#if (OE_SYSTEM_TIMER_CORE2_DEVICE == OE_TC_STM_SR0)
      OE_tc_stm_set_sr0_next_match(OSTICKDURATION_CORE2 / 1000U);
#elif (OE_SYSTEM_TIMER_CORE2_DEVICE == OE_TC_STM_SR1)
      OE_tc_stm_set_sr1_next_match(OSTICKDURATION_CORE2 / 1000U);
#endif
    break;
#endif /* OE_SYSTEM_TIMER_CORE2_DEVICE */
#if (defined(OE_SYSTEM_TIMER_CORE3_DEVICE))
    case OS_CORE_ID_3:
#if (OE_SYSTEM_TIMER_CORE3_DEVICE == OE_TC_STM_SR0)
      OE_tc_stm_set_sr0_next_match(OSTICKDURATION_CORE3 / 1000U);
#elif (OE_SYSTEM_TIMER_CORE3_DEVICE == OE_TC_STM_SR1)
      OE_tc_stm_set_sr1_next_match(OSTICKDURATION_CORE3 / 1000U);
#endif
    break;
#endif /* OE_SYSTEM_TIMER_CORE3_DEVICE */
#if (defined(OE_SYSTEM_TIMER_CORE4_DEVICE))
    case OS_CORE_ID_4:
#if (OE_SYSTEM_TIMER_CORE4_DEVICE == OE_TC_STM_SR0)
      OE_tc_stm_set_sr0_next_match(OSTICKDURATION_CORE4 / 1000U);
#elif (OE_SYSTEM_TIMER_CORE4_DEVICE == OE_TC_STM_SR1)
      OE_tc_stm_set_sr1_next_match(OSTICKDURATION_CORE4 / 1000U);
#endif
    break;
#endif /* OE_SYSTEM_TIMER_CORE4_DEVICE */
#if (defined(OE_SYSTEM_TIMER_CORE_DEVICE))
    case OS_CORE_ID_6:
#if (OE_SYSTEM_TIMER_CORE6_DEVICE == OE_TC_STM_SR0)
      OE_tc_stm_set_sr0_next_match(OSTICKDURATION_CORE6 / 1000U);
#elif (OE_SYSTEM_TIMER_CORE6_DEVICE == OE_TC_STM_SR1)
      OE_tc_stm_set_sr1_next_match(OSTICKDURATION_CORE6 / 1000U);
#endif
    break;
#endif /* OE_SYSTEM_TIMER_CORE6_DEVICE */
    case OS_CORE_ID_ARR_SIZE:
    default:
      /* All possible timer masks have been handled above */
      break;
  }
#endif /* OE_SINGLECORE */

  p_cdb = OE_get_curr_core();
  OE_counter_increment(p_cdb->p_sys_counter_db);
}

/* System Timer Initialization */
void OE_tc_initialize_system_timer(OE_TDB * p_tdb) {
  TaskPrio const isr2_prio = OE_ISR2_VIRT_TO_HW_PRIO(p_tdb->ready_prio);
#if (defined(OE_SINGLECORE))
#if (defined(OE_DEBUG))
  OE_tc_stm_ocds_suspend_control(0U);
#endif  /* OE_DEBUG */
#if (OE_SYSTEM_TIMER_DEVICE == OE_TC_STM_SR0)
  OE_tc_stm_set_sr0(OSTICKDURATION / 1000U, isr2_prio);
#elif (OE_SYSTEM_TIMER_DEVICE == OE_TC_STM_SR1)
  OE_tc_stm_set_sr1(OSTICKDURATION / 1000U, isr2_prio);
#endif
#else /* OE_SINGLECORE */
  switch (OE_get_curr_core_id()) {
#if (defined(OE_SYSTEM_TIMER_CORE0_DEVICE))
    case OS_CORE_ID_MASTER:
#if (defined(OE_DEBUG))
      OE_tc_stm_ocds_suspend_control(0U);
#endif /* OE_DEBUG */
#if (OE_SYSTEM_TIMER_CORE0_DEVICE == OE_TC_STM_SR0)
      OE_tc_stm_set_sr0(OSTICKDURATION_CORE0 / 1000U, isr2_prio);
#elif (OE_SYSTEM_TIMER_CORE0_DEVICE == OE_TC_STM_SR1)
      OE_tc_stm_set_sr1(OSTICKDURATION_CORE0 / 1000U, isr2_prio);
#endif
    break;
#endif /* OE_SYSTEM_TIMER_CORE0_DEVICE */
#if (defined(OE_SYSTEM_TIMER_CORE1_DEVICE))
    case OS_CORE_ID_1:
#if (defined(OE_DEBUG))
      OE_tc_stm_ocds_suspend_control(1U);
#endif /* OE_DEBUG */
#if (OE_SYSTEM_TIMER_CORE1_DEVICE == OE_TC_STM_SR0)
      OE_tc_stm_set_sr0(OSTICKDURATION_CORE1 / 1000U, isr2_prio);
#elif (OE_SYSTEM_TIMER_CORE1_DEVICE == OE_TC_STM_SR1)
      OE_tc_stm_set_sr1(OSTICKDURATION_CORE1 / 1000U, isr2_prio);
#endif
    break;
#endif /* OE_SYSTEM_TIMER_CORE1_DEVICE */
#if (defined(OE_SYSTEM_TIMER_CORE2_DEVICE))
    case OS_CORE_ID_2:
#if (defined(OE_DEBUG))
      OE_tc_stm_ocds_suspend_control(2U);
#endif /* OE_DEBUG */
#if (OE_SYSTEM_TIMER_CORE2_DEVICE == OE_TC_STM_SR0)
      OE_tc_stm_set_sr0(OSTICKDURATION_CORE2 / 1000U, isr2_prio);
#elif (OE_SYSTEM_TIMER_CORE2_DEVICE == OE_TC_STM_SR1)
      OE_tc_stm_set_sr1(OSTICKDURATION_CORE2 / 1000U, isr2_prio);
#endif
    break;
#endif /* OE_SYSTEM_TIMER_CORE2_DEVICE */
#if (defined(OE_SYSTEM_TIMER_CORE3_DEVICE))
    case OS_CORE_ID_3:
#if (defined(OE_DEBUG))
      OE_tc_stm_ocds_suspend_control(3U);
#endif /* OE_DEBUG */
#if (OE_SYSTEM_TIMER_CORE3_DEVICE == OE_TC_STM_SR0)
      OE_tc_stm_set_sr0(OSTICKDURATION_CORE3 / 1000U, isr2_prio);
#elif (OE_SYSTEM_TIMER_CORE3_DEVICE == OE_TC_STM_SR1)
      OE_tc_stm_set_sr1(OSTICKDURATION_CORE3 / 1000U, isr2_prio);
#endif
    break;
#endif /* OE_SYSTEM_TIMER_CORE3_DEVICE */
#if (defined(OE_SYSTEM_TIMER_CORE4_DEVICE))
    case OS_CORE_ID_4:
#if (defined(OE_DEBUG))
      OE_tc_stm_ocds_suspend_control(4U);
#endif /* OE_DEBUG */
#if (OE_SYSTEM_TIMER_CORE4_DEVICE == OE_TC_STM_SR0)
      OE_tc_stm_set_sr0(OSTICKDURATION_CORE4 / 1000U, isr2_prio);
#elif (OE_SYSTEM_TIMER_CORE4_DEVICE == OE_TC_STM_SR1)
      OE_tc_stm_set_sr1(OSTICKDURATION_CORE4 / 1000U, isr2_prio);
#endif
    break;
#endif /* OE_SYSTEM_TIMER_CORE4_DEVICE */
#if (defined(OE_SYSTEM_TIMER_CORE6_DEVICE))
    case OS_CORE_ID_6:
#if (defined(OE_DEBUG))
      OE_tc_stm_ocds_suspend_control(5U);
#endif /* OE_DEBUG */
#if (OE_SYSTEM_TIMER_CORE6_DEVICE == OE_TC_STM_SR0)
      OE_tc_stm_set_sr0(OSTICKDURATION_CORE6 / 1000U, isr2_prio);
#elif (OE_SYSTEM_TIMER_CORE6_DEVICE == OE_TC_STM_SR1)
      OE_tc_stm_set_sr1(OSTICKDURATION_CORE6 / 1000U, isr2_prio);
#endif
    break;
#endif /* OE_SYSTEM_TIMER_CORE6_DEVICE */
    case OS_CORE_ID_ARR_SIZE:
    default:
      /* All possible SRC masks have been handled above */
      break;

  }
#endif /* OE_SINGLECORE */
}

#endif /* OE_HAS_SYSTEM_TIMER */

#if (!defined(OE_TC_2G))
/******************************************************************************
                          SCU Clock Support
 *****************************************************************************/
#define OE_TC_FPLL_KSTEP  (240000000U)
#define OE_TC_FREF_MAX    (24000000U)
#define OE_TC_FREF_MIN    (8000000U)
#define OE_TC_FVCO_MAX    (800000000U)
#define OE_TC_FVCO_MIN    (400000000U)
#define OE_TC_P_MAX       (16U)  /* '4 bits */
#define OE_TC_P_MIN       (1U)
#define OE_TC_K2_MAX      (28U)  /* '7 bits */
#define OE_TC_K2_MIN      (1U)
#define OE_TC_N_MAX       (128U)  /* '7 bits */
#define OE_TC_N_MIN       (1U)
#define OE_TC_DEV_ALLOWED (2U)

void OE_tc_set_pll_fsource(OE_reg fpll) {
  /*
   * Dynamic PLL calculation Alg:
   *
   * fPLL = (N /( P * K2))  * fOSC
   *
   */
  OE_reg  p, n, k2, k2Steps, bestK2, bestN, bestP;
  uint64_t fRef, fVco, fPllLeastError, fPllError;
  OE_reg fpll_maxerrorallowed;

  bestK2 = 0U;
  bestN  = 0U;
  bestP  = 0U;
  /* K2+1 div should be even for 50% duty cycle */
  k2Steps = 2;

  fPllLeastError  = OE_TC_CLOCK_MAX;
  fPllError       = OE_TC_CLOCK_MAX;

  if (fpll > OE_TC_FPLL_KSTEP)
  {
    k2Steps = 1;
  }

  for (
    p = OE_TC_P_MAX;
    ((p >= OE_TC_P_MIN ) && (fPllError != 0ULL));
    --p
  )
  {
    fRef = ((uint64_t)OE_TC_BOARD_FOSC / p);

    if ((fRef >= OE_TC_FREF_MIN) && (fRef <= OE_TC_FREF_MAX))
    {
      for (
          k2 = OE_TC_K2_MIN;
          ((k2 <= OE_TC_K2_MAX) && (fPllError != 0U));
          k2 += k2Steps
        )
      {
        fVco = ((uint64_t)fpll) * k2;

        if ((fVco >= OE_TC_FVCO_MIN) && (fVco <= OE_TC_FVCO_MAX))
        {
          for (
              n = OE_TC_N_MIN;
              ((n <= OE_TC_N_MAX) && (fPllError != 0U));
              ++n
            )
          {
            fPllError = (
              (((n) / (p * k2)) * OE_TC_BOARD_FOSC) - fpll
            );

            if (fPllError == ((uint64_t)0U) )
            {
              fPllLeastError = fPllError;
              bestK2         = k2;
              bestN          = n;
              bestP          = p;
            }

            if (fPllLeastError > fPllError)
            {
              fPllLeastError = fPllError;
              bestK2         = k2;
              bestN          = n;
              bestP          = p;
            }
          }
        }
      }
    }
  }

  /* Percent ALLOWED_DEVIATION error allowed */
  fpll_maxerrorallowed = (fpll * OE_TC_DEV_ALLOWED) / ((OE_reg)100U);
  if (fPllLeastError < (uint64_t)fpll_maxerrorallowed)
  {
    /* Divide by K2DIV + 1 */
    OE_TC_SCU_PLLCON1.bits.k2div = (uint8_t)(bestK2 - 1U);

    while (OE_TC_SCU_PLLSTAT.bits.k2rdy == 0U) {
      ; /* Wait until K2-Divider is ready to operate */
    }

    /* K1 divider default value */

    /* Enabled the VCO Bypass Mode */
    OE_TC_SCU_PLLCON0.bits.vcobyp = 1U;

    while (OE_TC_SCU_PLLSTAT.bits.vcobyst == 0U) {
      ; /* Wait until prescaler mode is entered */
    }

    /* I will use n=80 and p=2. Because I can get al the
       needed values */
    OE_TC_SCU_PLLCON0.bits.pdiv = (uint8_t)(bestP - 1U);
    OE_TC_SCU_PLLCON0.bits.ndiv = (uint8_t)(bestN - 1U);

    /* Power down VCO Normal Behavior */
    OE_TC_SCU_PLLCON0.bits.vcopwd = 0U;

    /***** Configure PLL normal mode. *****/

    /* Automatic oscillator disconnect disabled */
    OE_TC_SCU_PLLCON0.bits.oscdisdis = 1U;
    /* Connect VCO to the oscillator */
    OE_TC_SCU_PLLCON0.bits.clrfindis = 1U;

    while (OE_TC_SCU_PLLSTAT.bits.findis == 1U) {
      ; /* Wait until oscillator is connected to the VCO */
    }

    /* Restart VCO lock detection */
    OE_TC_SCU_PLLCON0.bits.resld = 1U;

    while (OE_TC_SCU_PLLSTAT.bits.vcolock == 0U) {
      ; /* Wait until the VCO becomes locked */
    }

    /* Disable the VCO Bypass Mode */
    OE_TC_SCU_PLLCON0.bits.vcobyp = 0U;

    while (OE_TC_SCU_PLLSTAT.bits.vcobyst == 1U) {
      ; /* Wait until normal mode is entered */
    }

    /* Automatic oscillator disconnect enabled */
    OE_TC_SCU_PLLCON0.bits.oscdisdis = 0U;
  }

}

OE_reg OE_tc_get_fsource(void) {
  /*  fSOURCE Frequency */
  OE_reg fsource;

  if (OE_TC_SCU_CCUCON0.bits.clksel != 0U) {
    /* PLL */
    /* PLL dividers */
    OE_reg k1, k2, p, n;
    /* Prescaler mode */
    if (OE_TC_SCU_PLLSTAT.bits.vcobyst != 0U)
    {
      k1 = (OE_reg)OE_TC_SCU_PLLCON1.bits.k1div + 1U;
      fsource = OE_TC_BOARD_FOSC / k1;
    } else {
      /* Free running mode */
      if (OE_TC_SCU_PLLSTAT.bits.findis != 0U)
      {
        k2 = (OE_reg)OE_TC_SCU_PLLCON1.bits.k2div + 1U;
        fsource = OE_TC_BOARD_FOSC / k2;
      } else {
        /* PLL Normal mode */
        k2 = (OE_reg)OE_TC_SCU_PLLCON1.bits.k2div + 1U;
        p = (OE_reg)OE_TC_SCU_PLLCON0.bits.pdiv + 1U;
        n = (OE_reg)OE_TC_SCU_PLLCON0.bits.ndiv + 1U;

        /* cpu clock value fclk = (fosc * n)/(P * k2) */
        fsource = n * (OE_TC_BOARD_FOSC / (p * k2));
      }
    }
  } else {
    /* Backup Oscillator (EVR) */
    fsource = OE_TC_EVR_OSC_FREQUENCY;
  }
  return fsource;
}
#else

static OE_reg OE_tc_get_osc_freq(void) {
  OE_reg fosc;
  OE_reg syspllcon0_insel = OE_TC_SCU_SYSPLLCON0.bits.insel;

  switch (syspllcon0_insel) {
    case OE_TC_SCU_SYSPLLCON_INSEL_BACKUP:
      fosc = OE_TC_EVR_OSC_FREQUENCY;
    break;
    case OE_TC_SCU_SYSPLLCON_INSEL_FOSC0:
      fosc = OE_TC_BOARD_FOSC;
    break;
    case OE_TC_SCU_SYSPLLCON_INSEL_SYSCLK:
      /* TODO: Find real value of SYSCLK pin frequency */
      fosc = OE_TC_BOARD_FOSC;
    break;
    default:
      /* Reserved value, return an invalid value */
      fosc = 0U;
    break;
  }
  return fosc;
}

static OE_reg OE_tc_get_pll_freq(void) {
  OE_reg            const fosc          = OE_tc_get_osc_freq();
  OE_tc_SYSPLLCON0  const sys_pll_con0  = OE_TC_SCU_SYSPLLCON0;
  OE_tc_SYSPLLCON1  const sys_pll_con1  = OE_TC_SCU_SYSPLLCON1;

  OE_reg  const fpll =
    (fosc * ((OE_reg)sys_pll_con0.bits.ndiv + 1U)) /
      (((OE_reg)sys_pll_con1.bits.k2div + 1U) *
        ((OE_reg)sys_pll_con0.bits.pdiv + 1U));

  return fpll;
}

OE_reg OE_tc_get_fsource(void) {
  /*  fSOURCE Frequency */
  OE_reg fsource;
  if (OE_TC_SCU_CCUCON0.bits.clksel != 0U) {
    fsource = OE_tc_get_pll_freq();
  } else {
    /* Backup Oscillator (EVR) */
    fsource = OE_TC_EVR_OSC_FREQUENCY;
  }

  return fsource;
}
#endif /* !OE_TC_2G */

/******************************************************************************
                        STM Support
 *****************************************************************************/
/* Global variable with freq in Khz value */
#if (defined(__TASKING__))
#define OS_START_SEC_GLOBAL_VAR_CLEARED
#include "Os_MemMap.h"
#endif /* __TASKING__ */

static OE_reg OE_tc_stm_freq_khz;

#if (defined(__TASKING__))
#define OS_STOP_SEC_GLOBAL_VAR_CLEARED
#include "Os_MemMap.h"
#endif /* __TASKING__ */

static OE_reg OE_tc_stm_us_ticks(OE_reg usec) {
  OE_reg ticks;
  if (OE_tc_stm_freq_khz >= OE_KILO) {
    ticks = usec * (OE_tc_stm_freq_khz / OE_KILO);
  } else if (usec >= OE_KILO) {
    ticks = (usec / OE_KILO) * OE_tc_stm_freq_khz;
  } else {
    ticks = (usec * OE_tc_stm_freq_khz) / OE_KILO;
  }
  return ticks;
}

/* Set inside std time reference  */
void OE_tc_stm_set_clockpersec(void)
{
#if (defined(__TASKING__))
  /* I don't know where is declared */
  extern unsigned long long setfoschz ( unsigned long long );
#endif /* __TASKING__ */
  /* fSOURCE Frequency */
  OE_reg const fsource  = OE_tc_get_fsource();
  /* Standard Timer Module period rounded */
  OE_reg const fstm     = (fsource + 1U) / OE_SCU_HW_FSTM_DIV;

  /* Set Global variable with freq in Khz value */
  OE_tc_stm_freq_khz = fstm / OE_KILO;

#if (defined(__TASKING__))
  setfoschz(fstm);
  OE_tc_dsync();
#endif /* __TASKING__ */
}

/*
    STM set_sr function implementation. It will use SFR
    Types. These types are already volatile so I don't need to put
    that qualifier on pointers.
 */

OE_TC_STM_SR0_STORAGE void OE_tc_stm_set_sr0(OE_reg usec,
    OE_tc_isr_hw_prio intvec)
{
  OE_reg          us_in_ticks;
  uint8_t           size_of_compare;
  CoreIdType const  core_id = OE_get_curr_core_id();
#if (defined(OE_CORE_ID_VALID_MASK)) && (OE_CORE_ID_VALID_MASK & 0x40U)
  OE_reg   const  stm_id  = (core_id != OS_CORE_ID_6)? (OE_reg)core_id:
    5U;
#else
  OE_reg   const  stm_id  = (OE_reg)core_id;
#endif /* OE_CORE_ID_VALID_MASK & 0x40U */
/* Get Interrupt period in ticks */
  us_in_ticks = OE_tc_stm_us_ticks(usec);
/* Adjust the size of the mask */
  size_of_compare = 31U - ((uint8_t)OE_tc_clz(us_in_ticks));

/*  Set Compare Value Register (actual value + increment,
    I don't need to handle wrap around) */
  OE_TC_STM_REG(stm_id, OE_TC_STM_CMP0_OFF) =
    us_in_ticks + OE_tc_stm_get_time_lower_word(stm_id);

  if (intvec != 0U) {
    OE_TC_STM_CMCON(stm_id).bits.mstart0  = 0U;
    OE_TC_STM_CMCON(stm_id).bits.msize0   = size_of_compare;
/* Tie STM Service Request 0 with Compare Register 0 */
    OE_TC_STM_ICR(stm_id).bits.cmp0os     = 0U;
/* Enable STM Service Request Source */
    OE_TC_STM_ICR(stm_id).bits.cmp0en     = 1U;

/*
 *  STM service Request configuration
 */
    OE_tc_conf_src(core_id, OE_TC_STM_SRC_OFFSET(stm_id, 0U), intvec);
  } else {
/* Disable STM Service Request Source */
    OE_TC_STM_ICR(stm_id).bits.cmp0en                 = 0U;
    OE_TC_SRC_REG(OE_TC_STM_SRC_OFFSET(stm_id, 0U)) = 0U;
  }
}

OE_TC_STM_SR0_STORAGE void OE_tc_stm_set_sr0_next_match(OE_reg usec)
{
/* Evaluate next compare value (previous one + increment,
   I don't need to handle wrap around) */
  CoreIdType const  core_id = OE_get_curr_core_id();
#if (defined(OE_CORE_ID_VALID_MASK)) && (OE_CORE_ID_VALID_MASK & 0x40U)
  OE_reg   const  stm_id  = (core_id != OS_CORE_ID_6)? (OE_reg)core_id:
    5U;
#else
  OE_reg   const  stm_id  = (OE_reg)core_id;
#endif /* OE_CORE_ID_VALID_MASK & 0x40U */
/* CMP0IRR bit 0 => 0x1 | CMP0IRS bit 1 => 0x2 */
#if 0
  OE_TC_STM_REG(stm_id, OE_TC_STM_ISCR_OFF) = 0x1U;
#endif
  OE_TC_STM_REG(stm_id, OE_TC_STM_CMP0_OFF) += OE_tc_stm_us_ticks(usec);
}

OE_TC_STM_SR1_STORAGE void OE_tc_stm_set_sr1(OE_reg usec,
  OE_tc_isr_hw_prio intvec)
{
  OE_reg          us_in_ticks;
  uint8_t           size_of_compare;
  CoreIdType const  core_id = OE_get_curr_core_id();
#if (defined(OE_CORE_ID_VALID_MASK)) && (OE_CORE_ID_VALID_MASK & 0x40U)
  OE_reg   const  stm_id  = (core_id != OS_CORE_ID_6)? (OE_reg)core_id:
    5U;
#else
  OE_reg   const  stm_id  = (OE_reg)core_id;
#endif /* OE_CORE_ID_VALID_MASK & 0x40U */

/* Get Interrupt period in ticks */
  us_in_ticks = OE_tc_stm_us_ticks(usec);
/* Adjust the size of the mask */
  size_of_compare = 31U - ((uint8_t)OE_tc_clz(us_in_ticks));

/*  Set Compare Value Register (actual value + increment,
    I don't need to handle wrap around) */
  OE_TC_STM_REG(stm_id, OE_TC_STM_CMP1_OFF) =
    us_in_ticks + OE_tc_stm_get_time_lower_word(stm_id);

  if (intvec != 0U) {
    OE_TC_STM_CMCON(stm_id).bits.mstart1  = 0U;
    OE_TC_STM_CMCON(stm_id).bits.msize1   = size_of_compare;
/* Tie STM Service Request 1 with Compare Register 1 */
    OE_TC_STM_ICR(stm_id).bits.cmp1os     = 1U;
/* Enable STM Service Request Source */
    OE_TC_STM_ICR(stm_id).bits.cmp1en     = 1U;
/*
 *  STM service Request configuration
 */
    OE_tc_conf_src(core_id, OE_TC_STM_SRC_OFFSET(stm_id, 1U), intvec);
  } else {
/* Disable STM Service Request Source */
    OE_TC_STM_ICR(stm_id).bits.cmp1en                 = 0U;
    OE_TC_SRC_REG(OE_TC_STM_SRC_OFFSET(stm_id, 1U)) = 0U;
  }
}

OE_TC_STM_SR1_STORAGE void OE_tc_stm_set_sr1_next_match(OE_reg usec)
{
  CoreIdType const  core_id = OE_get_curr_core_id();
#if (defined(OE_CORE_ID_VALID_MASK)) && (OE_CORE_ID_VALID_MASK & 0x40U)
  OE_reg   const  stm_id  = (core_id != OS_CORE_ID_6)? (OE_reg)core_id:
    5U;
#else
  OE_reg   const  stm_id  = (OE_reg)core_id;
#endif /* OE_CORE_ID_VALID_MASK & 0x40U */
/* CMP1IRR bit 2 => 0x4 | CMP1IRS bit 3 => 0x8 */
#if 0
  OE_TC_STM_REG(stm_id, OE_TC_STM_ISCR_OFF) = 0x4U;
#endif
  OE_TC_STM_REG(stm_id, OE_TC_STM_CMP1_OFF) += OE_tc_stm_us_ticks(usec);
}

void OE_tc_delay(OE_reg usec)
{
  CoreIdType  const core_id = OE_get_curr_core_id();
#if (defined(OE_CORE_ID_VALID_MASK)) && (OE_CORE_ID_VALID_MASK & 0x40U)
  OE_reg   const  stm_id  = (core_id != OS_CORE_ID_6)? (OE_reg)core_id:
    5U;
#else
  OE_reg   const  stm_id  = (OE_reg)core_id;
#endif /* OE_CORE_ID_VALID_MASK & 0x40U */
  /* Read Start Point */
  OE_reg    const start = OE_tc_stm_get_time_lower_word(stm_id);
  /* Evaluate End Point */
  OE_reg    const ticks = OE_tc_stm_us_ticks(usec);

  while (ticks > (OE_tc_stm_get_time_lower_word(stm_id) - start)) {
    ; /* Wait */
  }
}

