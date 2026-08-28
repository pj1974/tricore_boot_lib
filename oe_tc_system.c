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
            Erika's standalone configuration (no iLLD integration)
 *  \author Errico Guidieri
 *  \date   2017
 */

#include "oe_internal.h"

/* STM_SR Function Static storage declaration (if needed) */
#if (defined(OSEE_SINGLECORE))
#if (defined(OSEE_SYSTEM_TIMER_DEVICE)) &&\
    (OSEE_SYSTEM_TIMER_DEVICE == OSEE_TC_STM_SR0)
#define OSEE_TC_STM_SR0_STORAGE static
static void OSEE_tc_stm_set_sr0(OSEE_reg usec, OSEE_tc_isr_hw_prio intvec);
static void OSEE_tc_stm_set_sr0_next_match(OSEE_reg usec);
#else
#define OSEE_TC_STM_SR0_STORAGE
#endif /* OSEE_SYSTEM_TIMER_DEVICE == OSEE_TC_STM_SR0 */

#if (defined(OSEE_SYSTEM_TIMER_DEVICE)) &&\
    (OSEE_SYSTEM_TIMER_DEVICE == OSEE_TC_STM_SR1)
#define OSEE_TC_STM_SR1_STORAGE static
static void OSEE_tc_stm_set_sr1(OSEE_reg usec, OSEE_tc_isr_hw_prio intvec);
static void OSEE_tc_stm_set_sr1_next_match(OSEE_reg usec);
#else
#define OSEE_TC_STM_SR1_STORAGE
#endif /* OSEE_SYSTEM_TIMER_DEVICE == OSEE_TC_STM_SR1 */
#else /* OSEE_SINGLECORE */

#if ((defined(OSEE_SYSTEM_TIMER_CORE0_DEVICE)) &&             \
      (OSEE_SYSTEM_TIMER_CORE0_DEVICE == OSEE_TC_STM_SR0)) || \
    ((defined(OSEE_SYSTEM_TIMER_CORE1_DEVICE)) &&             \
      (OSEE_SYSTEM_TIMER_CORE1_DEVICE == OSEE_TC_STM_SR0)) || \
    ((defined(OSEE_SYSTEM_TIMER_CORE2_DEVICE)) &&             \
      (OSEE_SYSTEM_TIMER_CORE2_DEVICE == OSEE_TC_STM_SR0)) || \
    ((defined(OSEE_SYSTEM_TIMER_CORE3_DEVICE)) &&             \
      (OSEE_SYSTEM_TIMER_CORE3_DEVICE == OSEE_TC_STM_SR0)) || \
    ((defined(OSEE_SYSTEM_TIMER_CORE4_DEVICE)) &&             \
      (OSEE_SYSTEM_TIMER_CORE4_DEVICE == OSEE_TC_STM_SR0)) || \
    ((defined(OSEE_SYSTEM_TIMER_CORE6_DEVICE)) &&             \
      (OSEE_SYSTEM_TIMER_CORE6_DEVICE == OSEE_TC_STM_SR0))

#define OSEE_TC_STM_SR0_STORAGE static
static void OSEE_tc_stm_set_sr0(OSEE_reg usec, OSEE_tc_isr_hw_prio intvec);
static void OSEE_tc_stm_set_sr0_next_match(OSEE_reg usec);
#else
#define OSEE_TC_STM_SR0_STORAGE
#endif

#if ((defined(OSEE_SYSTEM_TIMER_CORE0_DEVICE)) &&             \
      (OSEE_SYSTEM_TIMER_CORE0_DEVICE == OSEE_TC_STM_SR1)) || \
    ((defined(OSEE_SYSTEM_TIMER_CORE1_DEVICE)) &&             \
      (OSEE_SYSTEM_TIMER_CORE1_DEVICE == OSEE_TC_STM_SR1)) || \
    ((defined(OSEE_SYSTEM_TIMER_CORE2_DEVICE)) &&             \
      (OSEE_SYSTEM_TIMER_CORE2_DEVICE == OSEE_TC_STM_SR1)) || \
    ((defined(OSEE_SYSTEM_TIMER_CORE3_DEVICE)) &&             \
      (OSEE_SYSTEM_TIMER_CORE3_DEVICE == OSEE_TC_STM_SR1)) || \
    ((defined(OSEE_SYSTEM_TIMER_CORE4_DEVICE)) &&             \
      (OSEE_SYSTEM_TIMER_CORE4_DEVICE == OSEE_TC_STM_SR1)) || \
    ((defined(OSEE_SYSTEM_TIMER_CORE6_DEVICE)) &&             \
      (OSEE_SYSTEM_TIMER_CORE6_DEVICE == OSEE_TC_STM_SR1))

#define OSEE_TC_STM_SR1_STORAGE static
static void OSEE_tc_stm_set_sr1(OSEE_reg usec, OSEE_tc_isr_hw_prio intvec);
static void OSEE_tc_stm_set_sr1_next_match(OSEE_reg usec);
#else
#define OSEE_TC_STM_SR1_STORAGE
#endif

#endif /* OSEE_SINGLECORE */

/* This part of the file is needed only if System Timer is defined */
#if (defined(OSEE_HAS_SYSTEM_TIMER))
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

#if (defined(OSEE_SYSTEM_TIMER_DEVICE))
#if (OSEE_SYSTEM_TIMER_DEVICE != OSEE_TC_STM_SR0) && \
  (OSEE_SYSTEM_TIMER_DEVICE != OSEE_TC_STM_SR1)
#error Unsupported Device as System Timer!
#endif
#endif /* OSEE_SYSTEM_TIMER_DEVICE */
#if (defined(OSEE_SYSTEM_TIMER_CORE0_DEVICE))
#if (OSEE_SYSTEM_TIMER_CORE0_DEVICE != OSEE_TC_STM_SR0)  && \
  (OSEE_SYSTEM_TIMER_CORE0_DEVICE != OSEE_TC_STM_SR1)
#error Unsupported Device for CORE0 as System Timer!
#endif
#endif /* OSEE_SYSTEM_TIMER_CORE0_DEVICE */
#if (defined(OSEE_SYSTEM_TIMER_CORE1_DEVICE))
#if (OSEE_SYSTEM_TIMER_CORE1_DEVICE != OSEE_TC_STM_SR0)  && \
  (OSEE_SYSTEM_TIMER_CORE1_DEVICE != OSEE_TC_STM_SR1)
#error Unsupported Device for CORE1 as System Timer!
#endif
#endif /* OSEE_SYSTEM_TIMER_CORE1_DEVICE */
#if (defined(OSEE_SYSTEM_TIMER_CORE2_DEVICE))
#if (OSEE_SYSTEM_TIMER_CORE2_DEVICE != OSEE_TC_STM_SR0)  && \
  (OSEE_SYSTEM_TIMER_CORE2_DEVICE != OSEE_TC_STM_SR1)
#error Unsupported Device for CORE2 as System Timer!
#endif
#endif /* OSEE_SYSTEM_TIMER_CORE2_DEVICE */
#if (defined(OSEE_SYSTEM_TIMER_CORE3_DEVICE))
#if (OSEE_SYSTEM_TIMER_CORE3_DEVICE != OSEE_TC_STM_SR0)  && \
  (OSEE_SYSTEM_TIMER_CORE3_DEVICE != OSEE_TC_STM_SR1)
#error Unsupported Device for CORE3 as System Timer!
#endif
#endif /* OSEE_SYSTEM_TIMER_CORE3_DEVICE */
#if (defined(OSEE_SYSTEM_TIMER_CORE4_DEVICE))
#if (OSEE_SYSTEM_TIMER_CORE4_DEVICE != OSEE_TC_STM_SR0)  && \
  (OSEE_SYSTEM_TIMER_CORE4_DEVICE != OSEE_TC_STM_SR1)
#error Unsupported Device for CORE4 as System Timer!
#endif
#endif /* OSEE_SYSTEM_TIMER_CORE4_DEVICE */
#if (defined(OSEE_SYSTEM_TIMER_CORE6_DEVICE))
#if (OSEE_SYSTEM_TIMER_CORE6_DEVICE != OSEE_TC_STM_SR0)  && \
  (OSEE_SYSTEM_TIMER_CORE6_DEVICE != OSEE_TC_STM_SR1)
#error Unsupported Device for CORE6 as System Timer!
#endif
#endif /* OSEE_SYSTEM_TIMER_CORE6_DEVICE */

void OSEE_tricore_system_timer_handler(void) {
  OSEE_CDB * p_cdb;
#if (defined(OSEE_SINGLECORE))
#if (OSEE_SYSTEM_TIMER_DEVICE == OSEE_TC_STM_SR0)
  OSEE_tc_stm_set_sr0_next_match(OSTICKDURATION / 1000U);
#elif (OSEE_SYSTEM_TIMER_DEVICE == OSEE_TC_STM_SR1)
  OSEE_tc_stm_set_sr1_next_match(OSTICKDURATION / 1000U);
#endif /* OSEE_SYSTEM_TIMER_DEVICE */
#else /* OSEE_SINGLECORE */
  switch (OSEE_get_curr_core_id()) {
#if (defined(OSEE_SYSTEM_TIMER_CORE0_DEVICE))
    case OS_CORE_ID_MASTER:
#if (OSEE_SYSTEM_TIMER_CORE0_DEVICE == OSEE_TC_STM_SR0)
      OSEE_tc_stm_set_sr0_next_match(OSTICKDURATION_CORE0 / 1000U);
#elif (OSEE_SYSTEM_TIMER_CORE0_DEVICE == OSEE_TC_STM_SR1)
      OSEE_tc_stm_set_sr1_next_match(OSTICKDURATION_CORE0 / 1000U);
#endif
    break;
#endif /* OSEE_SYSTEM_TIMER_CORE0_DEVICE */
#if (defined(OSEE_SYSTEM_TIMER_CORE1_DEVICE))
    case OS_CORE_ID_1:
#if (OSEE_SYSTEM_TIMER_CORE1_DEVICE == OSEE_TC_STM_SR0)
      OSEE_tc_stm_set_sr0_next_match(OSTICKDURATION_CORE1 / 1000U);
#elif (OSEE_SYSTEM_TIMER_CORE1_DEVICE == OSEE_TC_STM_SR1)
      OSEE_tc_stm_set_sr1_next_match(OSTICKDURATION_CORE1 / 1000U);
#endif
    break;
#endif /* OSEE_SYSTEM_TIMER_CORE1_DEVICE */
#if (defined(OSEE_SYSTEM_TIMER_CORE2_DEVICE))
    case OS_CORE_ID_2:
#if (OSEE_SYSTEM_TIMER_CORE2_DEVICE == OSEE_TC_STM_SR0)
      OSEE_tc_stm_set_sr0_next_match(OSTICKDURATION_CORE2 / 1000U);
#elif (OSEE_SYSTEM_TIMER_CORE2_DEVICE == OSEE_TC_STM_SR1)
      OSEE_tc_stm_set_sr1_next_match(OSTICKDURATION_CORE2 / 1000U);
#endif
    break;
#endif /* OSEE_SYSTEM_TIMER_CORE2_DEVICE */
#if (defined(OSEE_SYSTEM_TIMER_CORE3_DEVICE))
    case OS_CORE_ID_3:
#if (OSEE_SYSTEM_TIMER_CORE3_DEVICE == OSEE_TC_STM_SR0)
      OSEE_tc_stm_set_sr0_next_match(OSTICKDURATION_CORE3 / 1000U);
#elif (OSEE_SYSTEM_TIMER_CORE3_DEVICE == OSEE_TC_STM_SR1)
      OSEE_tc_stm_set_sr1_next_match(OSTICKDURATION_CORE3 / 1000U);
#endif
    break;
#endif /* OSEE_SYSTEM_TIMER_CORE3_DEVICE */
#if (defined(OSEE_SYSTEM_TIMER_CORE4_DEVICE))
    case OS_CORE_ID_4:
#if (OSEE_SYSTEM_TIMER_CORE4_DEVICE == OSEE_TC_STM_SR0)
      OSEE_tc_stm_set_sr0_next_match(OSTICKDURATION_CORE4 / 1000U);
#elif (OSEE_SYSTEM_TIMER_CORE4_DEVICE == OSEE_TC_STM_SR1)
      OSEE_tc_stm_set_sr1_next_match(OSTICKDURATION_CORE4 / 1000U);
#endif
    break;
#endif /* OSEE_SYSTEM_TIMER_CORE4_DEVICE */
#if (defined(OSEE_SYSTEM_TIMER_CORE_DEVICE))
    case OS_CORE_ID_6:
#if (OSEE_SYSTEM_TIMER_CORE6_DEVICE == OSEE_TC_STM_SR0)
      OSEE_tc_stm_set_sr0_next_match(OSTICKDURATION_CORE6 / 1000U);
#elif (OSEE_SYSTEM_TIMER_CORE6_DEVICE == OSEE_TC_STM_SR1)
      OSEE_tc_stm_set_sr1_next_match(OSTICKDURATION_CORE6 / 1000U);
#endif
    break;
#endif /* OSEE_SYSTEM_TIMER_CORE6_DEVICE */
    case OS_CORE_ID_ARR_SIZE:
    default:
      /* All possible timer masks have been handled above */
      break;
  }
#endif /* OSEE_SINGLECORE */

  p_cdb = OSEE_get_curr_core();
  OSEE_counter_increment(p_cdb->p_sys_counter_db);
}

/* System Timer Initialization */
void OSEE_tc_initialize_system_timer(OSEE_TDB * p_tdb) {
  TaskPrio const isr2_prio = OSEE_ISR2_VIRT_TO_HW_PRIO(p_tdb->ready_prio);
#if (defined(OSEE_SINGLECORE))
#if (defined(OSEE_DEBUG))
  OSEE_tc_stm_ocds_suspend_control(0U);
#endif  /* OSEE_DEBUG */
#if (OSEE_SYSTEM_TIMER_DEVICE == OSEE_TC_STM_SR0)
  OSEE_tc_stm_set_sr0(OSTICKDURATION / 1000U, isr2_prio);
#elif (OSEE_SYSTEM_TIMER_DEVICE == OSEE_TC_STM_SR1)
  OSEE_tc_stm_set_sr1(OSTICKDURATION / 1000U, isr2_prio);
#endif
#else /* OSEE_SINGLECORE */
  switch (OSEE_get_curr_core_id()) {
#if (defined(OSEE_SYSTEM_TIMER_CORE0_DEVICE))
    case OS_CORE_ID_MASTER:
#if (defined(OSEE_DEBUG))
      OSEE_tc_stm_ocds_suspend_control(0U);
#endif /* OSEE_DEBUG */
#if (OSEE_SYSTEM_TIMER_CORE0_DEVICE == OSEE_TC_STM_SR0)
      OSEE_tc_stm_set_sr0(OSTICKDURATION_CORE0 / 1000U, isr2_prio);
#elif (OSEE_SYSTEM_TIMER_CORE0_DEVICE == OSEE_TC_STM_SR1)
      OSEE_tc_stm_set_sr1(OSTICKDURATION_CORE0 / 1000U, isr2_prio);
#endif
    break;
#endif /* OSEE_SYSTEM_TIMER_CORE0_DEVICE */
#if (defined(OSEE_SYSTEM_TIMER_CORE1_DEVICE))
    case OS_CORE_ID_1:
#if (defined(OSEE_DEBUG))
      OSEE_tc_stm_ocds_suspend_control(1U);
#endif /* OSEE_DEBUG */
#if (OSEE_SYSTEM_TIMER_CORE1_DEVICE == OSEE_TC_STM_SR0)
      OSEE_tc_stm_set_sr0(OSTICKDURATION_CORE1 / 1000U, isr2_prio);
#elif (OSEE_SYSTEM_TIMER_CORE1_DEVICE == OSEE_TC_STM_SR1)
      OSEE_tc_stm_set_sr1(OSTICKDURATION_CORE1 / 1000U, isr2_prio);
#endif
    break;
#endif /* OSEE_SYSTEM_TIMER_CORE1_DEVICE */
#if (defined(OSEE_SYSTEM_TIMER_CORE2_DEVICE))
    case OS_CORE_ID_2:
#if (defined(OSEE_DEBUG))
      OSEE_tc_stm_ocds_suspend_control(2U);
#endif /* OSEE_DEBUG */
#if (OSEE_SYSTEM_TIMER_CORE2_DEVICE == OSEE_TC_STM_SR0)
      OSEE_tc_stm_set_sr0(OSTICKDURATION_CORE2 / 1000U, isr2_prio);
#elif (OSEE_SYSTEM_TIMER_CORE2_DEVICE == OSEE_TC_STM_SR1)
      OSEE_tc_stm_set_sr1(OSTICKDURATION_CORE2 / 1000U, isr2_prio);
#endif
    break;
#endif /* OSEE_SYSTEM_TIMER_CORE2_DEVICE */
#if (defined(OSEE_SYSTEM_TIMER_CORE3_DEVICE))
    case OS_CORE_ID_3:
#if (defined(OSEE_DEBUG))
      OSEE_tc_stm_ocds_suspend_control(3U);
#endif /* OSEE_DEBUG */
#if (OSEE_SYSTEM_TIMER_CORE3_DEVICE == OSEE_TC_STM_SR0)
      OSEE_tc_stm_set_sr0(OSTICKDURATION_CORE3 / 1000U, isr2_prio);
#elif (OSEE_SYSTEM_TIMER_CORE3_DEVICE == OSEE_TC_STM_SR1)
      OSEE_tc_stm_set_sr1(OSTICKDURATION_CORE3 / 1000U, isr2_prio);
#endif
    break;
#endif /* OSEE_SYSTEM_TIMER_CORE3_DEVICE */
#if (defined(OSEE_SYSTEM_TIMER_CORE4_DEVICE))
    case OS_CORE_ID_4:
#if (defined(OSEE_DEBUG))
      OSEE_tc_stm_ocds_suspend_control(4U);
#endif /* OSEE_DEBUG */
#if (OSEE_SYSTEM_TIMER_CORE4_DEVICE == OSEE_TC_STM_SR0)
      OSEE_tc_stm_set_sr0(OSTICKDURATION_CORE4 / 1000U, isr2_prio);
#elif (OSEE_SYSTEM_TIMER_CORE4_DEVICE == OSEE_TC_STM_SR1)
      OSEE_tc_stm_set_sr1(OSTICKDURATION_CORE4 / 1000U, isr2_prio);
#endif
    break;
#endif /* OSEE_SYSTEM_TIMER_CORE4_DEVICE */
#if (defined(OSEE_SYSTEM_TIMER_CORE6_DEVICE))
    case OS_CORE_ID_6:
#if (defined(OSEE_DEBUG))
      OSEE_tc_stm_ocds_suspend_control(5U);
#endif /* OSEE_DEBUG */
#if (OSEE_SYSTEM_TIMER_CORE6_DEVICE == OSEE_TC_STM_SR0)
      OSEE_tc_stm_set_sr0(OSTICKDURATION_CORE6 / 1000U, isr2_prio);
#elif (OSEE_SYSTEM_TIMER_CORE6_DEVICE == OSEE_TC_STM_SR1)
      OSEE_tc_stm_set_sr1(OSTICKDURATION_CORE6 / 1000U, isr2_prio);
#endif
    break;
#endif /* OSEE_SYSTEM_TIMER_CORE6_DEVICE */
    case OS_CORE_ID_ARR_SIZE:
    default:
      /* All possible SRC masks have been handled above */
      break;

  }
#endif /* OSEE_SINGLECORE */
}

#endif /* OSEE_HAS_SYSTEM_TIMER */

#if (!defined(OSEE_TC_2G))
/******************************************************************************
                          SCU Clock Support
 *****************************************************************************/
#define OSEE_TC_FPLL_KSTEP  (240000000U)
#define OSEE_TC_FREF_MAX    (24000000U)
#define OSEE_TC_FREF_MIN    (8000000U)
#define OSEE_TC_FVCO_MAX    (800000000U)
#define OSEE_TC_FVCO_MIN    (400000000U)
#define OSEE_TC_P_MAX       (16U)  /* '4 bits */
#define OSEE_TC_P_MIN       (1U)
#define OSEE_TC_K2_MAX      (28U)  /* '7 bits */
#define OSEE_TC_K2_MIN      (1U)
#define OSEE_TC_N_MAX       (128U)  /* '7 bits */
#define OSEE_TC_N_MIN       (1U)
#define OSEE_TC_DEV_ALLOWED (2U)

void OSEE_tc_set_pll_fsource(OSEE_reg fpll) {
  /*
   * Dynamic PLL calculation Alg:
   *
   * fPLL = (N /( P * K2))  * fOSC
   *
   */
  OSEE_reg  p, n, k2, k2Steps, bestK2, bestN, bestP;
  uint64_t fRef, fVco, fPllLeastError, fPllError;
  OSEE_reg fpll_maxerrorallowed;

  bestK2 = 0U;
  bestN  = 0U;
  bestP  = 0U;
  /* K2+1 div should be even for 50% duty cycle */
  k2Steps = 2;

  fPllLeastError  = OSEE_TC_CLOCK_MAX;
  fPllError       = OSEE_TC_CLOCK_MAX;

  if (fpll > OSEE_TC_FPLL_KSTEP)
  {
    k2Steps = 1;
  }

  for (
    p = OSEE_TC_P_MAX;
    ((p >= OSEE_TC_P_MIN ) && (fPllError != 0ULL));
    --p
  )
  {
    fRef = ((uint64_t)OSEE_TC_BOARD_FOSC / p);

    if ((fRef >= OSEE_TC_FREF_MIN) && (fRef <= OSEE_TC_FREF_MAX))
    {
      for (
          k2 = OSEE_TC_K2_MIN;
          ((k2 <= OSEE_TC_K2_MAX) && (fPllError != 0U));
          k2 += k2Steps
        )
      {
        fVco = ((uint64_t)fpll) * k2;

        if ((fVco >= OSEE_TC_FVCO_MIN) && (fVco <= OSEE_TC_FVCO_MAX))
        {
          for (
              n = OSEE_TC_N_MIN;
              ((n <= OSEE_TC_N_MAX) && (fPllError != 0U));
              ++n
            )
          {
            fPllError = (
              (((n) / (p * k2)) * OSEE_TC_BOARD_FOSC) - fpll
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
  fpll_maxerrorallowed = (fpll * OSEE_TC_DEV_ALLOWED) / ((OSEE_reg)100U);
  if (fPllLeastError < (uint64_t)fpll_maxerrorallowed)
  {
    /* Divide by K2DIV + 1 */
    OSEE_TC_SCU_PLLCON1.bits.k2div = (uint8_t)(bestK2 - 1U);

    while (OSEE_TC_SCU_PLLSTAT.bits.k2rdy == 0U) {
      ; /* Wait until K2-Divider is ready to operate */
    }

    /* K1 divider default value */

    /* Enabled the VCO Bypass Mode */
    OSEE_TC_SCU_PLLCON0.bits.vcobyp = 1U;

    while (OSEE_TC_SCU_PLLSTAT.bits.vcobyst == 0U) {
      ; /* Wait until prescaler mode is entered */
    }

    /* I will use n=80 and p=2. Because I can get al the
       needed values */
    OSEE_TC_SCU_PLLCON0.bits.pdiv = (uint8_t)(bestP - 1U);
    OSEE_TC_SCU_PLLCON0.bits.ndiv = (uint8_t)(bestN - 1U);

    /* Power down VCO Normal Behavior */
    OSEE_TC_SCU_PLLCON0.bits.vcopwd = 0U;

    /***** Configure PLL normal mode. *****/

    /* Automatic oscillator disconnect disabled */
    OSEE_TC_SCU_PLLCON0.bits.oscdisdis = 1U;
    /* Connect VCO to the oscillator */
    OSEE_TC_SCU_PLLCON0.bits.clrfindis = 1U;

    while (OSEE_TC_SCU_PLLSTAT.bits.findis == 1U) {
      ; /* Wait until oscillator is connected to the VCO */
    }

    /* Restart VCO lock detection */
    OSEE_TC_SCU_PLLCON0.bits.resld = 1U;

    while (OSEE_TC_SCU_PLLSTAT.bits.vcolock == 0U) {
      ; /* Wait until the VCO becomes locked */
    }

    /* Disable the VCO Bypass Mode */
    OSEE_TC_SCU_PLLCON0.bits.vcobyp = 0U;

    while (OSEE_TC_SCU_PLLSTAT.bits.vcobyst == 1U) {
      ; /* Wait until normal mode is entered */
    }

    /* Automatic oscillator disconnect enabled */
    OSEE_TC_SCU_PLLCON0.bits.oscdisdis = 0U;
  }

}

OSEE_reg OSEE_tc_get_fsource(void) {
  /*  fSOURCE Frequency */
  OSEE_reg fsource;

  if (OSEE_TC_SCU_CCUCON0.bits.clksel != 0U) {
    /* PLL */
    /* PLL dividers */
    OSEE_reg k1, k2, p, n;
    /* Prescaler mode */
    if (OSEE_TC_SCU_PLLSTAT.bits.vcobyst != 0U)
    {
      k1 = (OSEE_reg)OSEE_TC_SCU_PLLCON1.bits.k1div + 1U;
      fsource = OSEE_TC_BOARD_FOSC / k1;
    } else {
      /* Free running mode */
      if (OSEE_TC_SCU_PLLSTAT.bits.findis != 0U)
      {
        k2 = (OSEE_reg)OSEE_TC_SCU_PLLCON1.bits.k2div + 1U;
        fsource = OSEE_TC_BOARD_FOSC / k2;
      } else {
        /* PLL Normal mode */
        k2 = (OSEE_reg)OSEE_TC_SCU_PLLCON1.bits.k2div + 1U;
        p = (OSEE_reg)OSEE_TC_SCU_PLLCON0.bits.pdiv + 1U;
        n = (OSEE_reg)OSEE_TC_SCU_PLLCON0.bits.ndiv + 1U;

        /* cpu clock value fclk = (fosc * n)/(P * k2) */
        fsource = n * (OSEE_TC_BOARD_FOSC / (p * k2));
      }
    }
  } else {
    /* Backup Oscillator (EVR) */
    fsource = OSEE_TC_EVR_OSC_FREQUENCY;
  }
  return fsource;
}
#else

static OSEE_reg OSEE_tc_get_osc_freq(void) {
  OSEE_reg fosc;
  OSEE_reg syspllcon0_insel = OSEE_TC_SCU_SYSPLLCON0.bits.insel;

  switch (syspllcon0_insel) {
    case OSEE_TC_SCU_SYSPLLCON_INSEL_BACKUP:
      fosc = OSEE_TC_EVR_OSC_FREQUENCY;
    break;
    case OSEE_TC_SCU_SYSPLLCON_INSEL_FOSC0:
      fosc = OSEE_TC_BOARD_FOSC;
    break;
    case OSEE_TC_SCU_SYSPLLCON_INSEL_SYSCLK:
      /* TODO: Find real value of SYSCLK pin frequency */
      fosc = OSEE_TC_BOARD_FOSC;
    break;
    default:
      /* Reserved value, return an invalid value */
      fosc = 0U;
    break;
  }
  return fosc;
}

static OSEE_reg OSEE_tc_get_pll_freq(void) {
  OSEE_reg            const fosc          = OSEE_tc_get_osc_freq();
  OSEE_tc_SYSPLLCON0  const sys_pll_con0  = OSEE_TC_SCU_SYSPLLCON0;
  OSEE_tc_SYSPLLCON1  const sys_pll_con1  = OSEE_TC_SCU_SYSPLLCON1;

  OSEE_reg  const fpll =
    (fosc * ((OSEE_reg)sys_pll_con0.bits.ndiv + 1U)) /
      (((OSEE_reg)sys_pll_con1.bits.k2div + 1U) *
        ((OSEE_reg)sys_pll_con0.bits.pdiv + 1U));

  return fpll;
}

OSEE_reg OSEE_tc_get_fsource(void) {
  /*  fSOURCE Frequency */
  OSEE_reg fsource;
  if (OSEE_TC_SCU_CCUCON0.bits.clksel != 0U) {
    fsource = OSEE_tc_get_pll_freq();
  } else {
    /* Backup Oscillator (EVR) */
    fsource = OSEE_TC_EVR_OSC_FREQUENCY;
  }

  return fsource;
}
#endif /* !OSEE_TC_2G */

/******************************************************************************
                        STM Support
 *****************************************************************************/
/* Global variable with freq in Khz value */
#if (defined(__TASKING__))
#define OS_START_SEC_GLOBAL_VAR_CLEARED
#include "Os_MemMap.h"
#endif /* __TASKING__ */

static OSEE_reg OSEE_tc_stm_freq_khz;

#if (defined(__TASKING__))
#define OS_STOP_SEC_GLOBAL_VAR_CLEARED
#include "Os_MemMap.h"
#endif /* __TASKING__ */

static OSEE_reg OSEE_tc_stm_us_ticks(OSEE_reg usec) {
  OSEE_reg ticks;
  if (OSEE_tc_stm_freq_khz >= OSEE_KILO) {
    ticks = usec * (OSEE_tc_stm_freq_khz / OSEE_KILO);
  } else if (usec >= OSEE_KILO) {
    ticks = (usec / OSEE_KILO) * OSEE_tc_stm_freq_khz;
  } else {
    ticks = (usec * OSEE_tc_stm_freq_khz) / OSEE_KILO;
  }
  return ticks;
}

/* Set inside std time reference  */
void OSEE_tc_stm_set_clockpersec(void)
{
#if (defined(__TASKING__))
  /* I don't know where is declared */
  extern unsigned long long setfoschz ( unsigned long long );
#endif /* __TASKING__ */
  /* fSOURCE Frequency */
  OSEE_reg const fsource  = OSEE_tc_get_fsource();
  /* Standard Timer Module period rounded */
  OSEE_reg const fstm     = (fsource + 1U) / OSEE_SCU_HW_FSTM_DIV;

  /* Set Global variable with freq in Khz value */
  OSEE_tc_stm_freq_khz = fstm / OSEE_KILO;

#if (defined(__TASKING__))
  setfoschz(fstm);
  OSEE_tc_dsync();
#endif /* __TASKING__ */
}

/*
    STM set_sr function implementation. It will use SFR
    Types. These types are already volatile so I don't need to put
    that qualifier on pointers.
 */

OSEE_TC_STM_SR0_STORAGE void OSEE_tc_stm_set_sr0(OSEE_reg usec,
    OSEE_tc_isr_hw_prio intvec)
{
  OSEE_reg          us_in_ticks;
  uint8_t           size_of_compare;
  CoreIdType const  core_id = OSEE_get_curr_core_id();
#if (defined(OSEE_CORE_ID_VALID_MASK)) && (OSEE_CORE_ID_VALID_MASK & 0x40U)
  OSEE_reg   const  stm_id  = (core_id != OS_CORE_ID_6)? (OSEE_reg)core_id:
    5U;
#else
  OSEE_reg   const  stm_id  = (OSEE_reg)core_id;
#endif /* OSEE_CORE_ID_VALID_MASK & 0x40U */
/* Get Interrupt period in ticks */
  us_in_ticks = OSEE_tc_stm_us_ticks(usec);
/* Adjust the size of the mask */
  size_of_compare = 31U - ((uint8_t)OSEE_tc_clz(us_in_ticks));

/*  Set Compare Value Register (actual value + increment,
    I don't need to handle wrap around) */
  OSEE_TC_STM_REG(stm_id, OSEE_TC_STM_CMP0_OFF) =
    us_in_ticks + OSEE_tc_stm_get_time_lower_word(stm_id);

  if (intvec != 0U) {
    OSEE_TC_STM_CMCON(stm_id).bits.mstart0  = 0U;
    OSEE_TC_STM_CMCON(stm_id).bits.msize0   = size_of_compare;
/* Tie STM Service Request 0 with Compare Register 0 */
    OSEE_TC_STM_ICR(stm_id).bits.cmp0os     = 0U;
/* Enable STM Service Request Source */
    OSEE_TC_STM_ICR(stm_id).bits.cmp0en     = 1U;

/*
 *  STM service Request configuration
 */
    OSEE_tc_conf_src(core_id, OSEE_TC_STM_SRC_OFFSET(stm_id, 0U), intvec);
  } else {
/* Disable STM Service Request Source */
    OSEE_TC_STM_ICR(stm_id).bits.cmp0en                 = 0U;
    OSEE_TC_SRC_REG(OSEE_TC_STM_SRC_OFFSET(stm_id, 0U)) = 0U;
  }
}

OSEE_TC_STM_SR0_STORAGE void OSEE_tc_stm_set_sr0_next_match(OSEE_reg usec)
{
/* Evaluate next compare value (previous one + increment,
   I don't need to handle wrap around) */
  CoreIdType const  core_id = OSEE_get_curr_core_id();
#if (defined(OSEE_CORE_ID_VALID_MASK)) && (OSEE_CORE_ID_VALID_MASK & 0x40U)
  OSEE_reg   const  stm_id  = (core_id != OS_CORE_ID_6)? (OSEE_reg)core_id:
    5U;
#else
  OSEE_reg   const  stm_id  = (OSEE_reg)core_id;
#endif /* OSEE_CORE_ID_VALID_MASK & 0x40U */
/* CMP0IRR bit 0 => 0x1 | CMP0IRS bit 1 => 0x2 */
#if 0
  OSEE_TC_STM_REG(stm_id, OSEE_TC_STM_ISCR_OFF) = 0x1U;
#endif
  OSEE_TC_STM_REG(stm_id, OSEE_TC_STM_CMP0_OFF) += OSEE_tc_stm_us_ticks(usec);
}

OSEE_TC_STM_SR1_STORAGE void OSEE_tc_stm_set_sr1(OSEE_reg usec,
  OSEE_tc_isr_hw_prio intvec)
{
  OSEE_reg          us_in_ticks;
  uint8_t           size_of_compare;
  CoreIdType const  core_id = OSEE_get_curr_core_id();
#if (defined(OSEE_CORE_ID_VALID_MASK)) && (OSEE_CORE_ID_VALID_MASK & 0x40U)
  OSEE_reg   const  stm_id  = (core_id != OS_CORE_ID_6)? (OSEE_reg)core_id:
    5U;
#else
  OSEE_reg   const  stm_id  = (OSEE_reg)core_id;
#endif /* OSEE_CORE_ID_VALID_MASK & 0x40U */

/* Get Interrupt period in ticks */
  us_in_ticks = OSEE_tc_stm_us_ticks(usec);
/* Adjust the size of the mask */
  size_of_compare = 31U - ((uint8_t)OSEE_tc_clz(us_in_ticks));

/*  Set Compare Value Register (actual value + increment,
    I don't need to handle wrap around) */
  OSEE_TC_STM_REG(stm_id, OSEE_TC_STM_CMP1_OFF) =
    us_in_ticks + OSEE_tc_stm_get_time_lower_word(stm_id);

  if (intvec != 0U) {
    OSEE_TC_STM_CMCON(stm_id).bits.mstart1  = 0U;
    OSEE_TC_STM_CMCON(stm_id).bits.msize1   = size_of_compare;
/* Tie STM Service Request 1 with Compare Register 1 */
    OSEE_TC_STM_ICR(stm_id).bits.cmp1os     = 1U;
/* Enable STM Service Request Source */
    OSEE_TC_STM_ICR(stm_id).bits.cmp1en     = 1U;
/*
 *  STM service Request configuration
 */
    OSEE_tc_conf_src(core_id, OSEE_TC_STM_SRC_OFFSET(stm_id, 1U), intvec);
  } else {
/* Disable STM Service Request Source */
    OSEE_TC_STM_ICR(stm_id).bits.cmp1en                 = 0U;
    OSEE_TC_SRC_REG(OSEE_TC_STM_SRC_OFFSET(stm_id, 1U)) = 0U;
  }
}

OSEE_TC_STM_SR1_STORAGE void OSEE_tc_stm_set_sr1_next_match(OSEE_reg usec)
{
  CoreIdType const  core_id = OSEE_get_curr_core_id();
#if (defined(OSEE_CORE_ID_VALID_MASK)) && (OSEE_CORE_ID_VALID_MASK & 0x40U)
  OSEE_reg   const  stm_id  = (core_id != OS_CORE_ID_6)? (OSEE_reg)core_id:
    5U;
#else
  OSEE_reg   const  stm_id  = (OSEE_reg)core_id;
#endif /* OSEE_CORE_ID_VALID_MASK & 0x40U */
/* CMP1IRR bit 2 => 0x4 | CMP1IRS bit 3 => 0x8 */
#if 0
  OSEE_TC_STM_REG(stm_id, OSEE_TC_STM_ISCR_OFF) = 0x4U;
#endif
  OSEE_TC_STM_REG(stm_id, OSEE_TC_STM_CMP1_OFF) += OSEE_tc_stm_us_ticks(usec);
}

void OSEE_tc_delay(OSEE_reg usec)
{
  CoreIdType  const core_id = OSEE_get_curr_core_id();
#if (defined(OSEE_CORE_ID_VALID_MASK)) && (OSEE_CORE_ID_VALID_MASK & 0x40U)
  OSEE_reg   const  stm_id  = (core_id != OS_CORE_ID_6)? (OSEE_reg)core_id:
    5U;
#else
  OSEE_reg   const  stm_id  = (OSEE_reg)core_id;
#endif /* OSEE_CORE_ID_VALID_MASK & 0x40U */
  /* Read Start Point */
  OSEE_reg    const start = OSEE_tc_stm_get_time_lower_word(stm_id);
  /* Evaluate End Point */
  OSEE_reg    const ticks = OSEE_tc_stm_us_ticks(usec);

  while (ticks > (OSEE_tc_stm_get_time_lower_word(stm_id) - start)) {
    ; /* Wait */
  }
}

