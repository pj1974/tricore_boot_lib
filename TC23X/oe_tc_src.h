/**
 *
 * This file derives from a modification of the Infineon startup scripts,
 * distributed under the following license:
 *
 * \file ./Src/BaseSw/Infra/Sfr/TC23A/_Reg/IfxSrc_reg.h
 * \brief
 * \copyright Copyright (c) 2015 Infineon Technologies AG. All rights reserved.
 *
 * Version: TC23XADAS_UM_V1.1.R0
 * Specification: tc23xadas_um_sfrs_MCSFR.xml (Revision: UM_V1.1)
 * MAY BE CHANGED BY USER [yes/no]: No
 *
 *                                 IMPORTANT NOTICE
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
 */


/** \file   oe_tc_srch.h
 *  \brief  Contains the OE_TC_SRC registers offset definition for tc23x.
 *  \author Errico Guidieri
 *  \date   2017
 */
#ifndef OE_TC_SRC_H
#define OE_TC_SRC_H

/** \brief  88, ASCLIN Error Service Request */
#define OE_TC_SRC_ASCLIN_ASCLIN0_ERR    (0x0088U)

/** Alias (User Manual Name) for OE_TC_SRC_ASCLIN_ASCLIN0_ERR.
 * To use register names with standard convention, please use OE_TC_SRC_ASCLIN_ASCLIN0_ERR.
 */
#define OE_TC_SRC_ASCLIN0ERR            (OE_TC_SRC_ASCLIN_ASCLIN0_ERR)

/** \brief  84, ASCLIN Receive Service Request */
#define OE_TC_SRC_ASCLIN_ASCLIN0_RX     (0x0084U)

/** Alias (User Manual Name) for OE_TC_SRC_ASCLIN_ASCLIN0_RX.
 * To use register names with standard convention, please use OE_TC_SRC_ASCLIN_ASCLIN0_RX.
 */
#define OE_TC_SRC_ASCLIN0RX             (OE_TC_SRC_ASCLIN_ASCLIN0_RX)

/** \brief  80, ASCLIN Transmit Service Request */
#define OE_TC_SRC_ASCLIN_ASCLIN0_TX     (0x0080U)

/** Alias (User Manual Name) for OE_TC_SRC_ASCLIN_ASCLIN0_TX.
 * To use register names with standard convention, please use OE_TC_SRC_ASCLIN_ASCLIN0_TX.
 */
#define OE_TC_SRC_ASCLIN0TX             (OE_TC_SRC_ASCLIN_ASCLIN0_TX)

/** \brief  94, ASCLIN Error Service Request */
#define OE_TC_SRC_ASCLIN_ASCLIN1_ERR    (0x0094U)

/** Alias (User Manual Name) for OE_TC_SRC_ASCLIN_ASCLIN1_ERR.
 * To use register names with standard convention, please use OE_TC_SRC_ASCLIN_ASCLIN1_ERR.
 */
#define OE_TC_SRC_ASCLIN1ERR            (OE_TC_SRC_ASCLIN_ASCLIN1_ERR)

/** \brief  90, ASCLIN Receive Service Request */
#define OE_TC_SRC_ASCLIN_ASCLIN1_RX     (0x0090U)

/** Alias (User Manual Name) for OE_TC_SRC_ASCLIN_ASCLIN1_RX.
 * To use register names with standard convention, please use OE_TC_SRC_ASCLIN_ASCLIN1_RX.
 */
#define OE_TC_SRC_ASCLIN1RX             (OE_TC_SRC_ASCLIN_ASCLIN1_RX)

/** \brief  8C, ASCLIN Transmit Service Request */
#define OE_TC_SRC_ASCLIN_ASCLIN1_TX     (0x008CU)

/** Alias (User Manual Name) for OE_TC_SRC_ASCLIN_ASCLIN1_TX.
 * To use register names with standard convention, please use OE_TC_SRC_ASCLIN_ASCLIN1_TX.
 */
#define OE_TC_SRC_ASCLIN1TX             (OE_TC_SRC_ASCLIN_ASCLIN1_TX)

/** \brief  40, Bus Control Unit SPB Service Request */
#define OE_TC_SRC_BCU_SPB_SBSRC         (0x0040U)

/** Alias (User Manual Name) for OE_TC_SRC_BCU_SPB_SBSRC.
 * To use register names with standard convention, please use OE_TC_SRC_BCU_SPB_SBSRC.
 */
#define OE_TC_SRC_BCUSPBSBSRC           (OE_TC_SRC_BCU_SPB_SBSRC)

/** \brief  900, MULTICAN Service Request */
#define OE_TC_SRC_CAN_CAN0_INT0         (0x0900U)

/** Alias (User Manual Name) for OE_TC_SRC_CAN_CAN0_INT0.
 * To use register names with standard convention, please use OE_TC_SRC_CAN_CAN0_INT0.
 */
#define OE_TC_SRC_CANINT0               (OE_TC_SRC_CAN_CAN0_INT0)

/** \brief  904, MULTICAN Service Request */
#define OE_TC_SRC_CAN_CAN0_INT1         (0x0904U)

/** Alias (User Manual Name) for OE_TC_SRC_CAN_CAN0_INT1.
 * To use register names with standard convention, please use OE_TC_SRC_CAN_CAN0_INT1.
 */
#define OE_TC_SRC_CANINT1               (OE_TC_SRC_CAN_CAN0_INT1)

/** \brief  928, MULTICAN Service Request */
#define OE_TC_SRC_CAN_CAN0_INT10        (0x0928U)

/** Alias (User Manual Name) for OE_TC_SRC_CAN_CAN0_INT10.
 * To use register names with standard convention, please use OE_TC_SRC_CAN_CAN0_INT10.
 */
#define OE_TC_SRC_CANINT10              (OE_TC_SRC_CAN_CAN0_INT10)

/** \brief  92C, MULTICAN Service Request */
#define OE_TC_SRC_CAN_CAN0_INT11        (0x092CU)

/** Alias (User Manual Name) for OE_TC_SRC_CAN_CAN0_INT11.
 * To use register names with standard convention, please use OE_TC_SRC_CAN_CAN0_INT11.
 */
#define OE_TC_SRC_CANINT11              (OE_TC_SRC_CAN_CAN0_INT11)

/** \brief  930, MULTICAN Service Request */
#define OE_TC_SRC_CAN_CAN0_INT12        (0x0930U)

/** Alias (User Manual Name) for OE_TC_SRC_CAN_CAN0_INT12.
 * To use register names with standard convention, please use OE_TC_SRC_CAN_CAN0_INT12.
 */
#define OE_TC_SRC_CANINT12              (OE_TC_SRC_CAN_CAN0_INT12)

/** \brief  934, MULTICAN Service Request */
#define OE_TC_SRC_CAN_CAN0_INT13        (0x0934U)

/** Alias (User Manual Name) for OE_TC_SRC_CAN_CAN0_INT13.
 * To use register names with standard convention, please use OE_TC_SRC_CAN_CAN0_INT13.
 */
#define OE_TC_SRC_CANINT13              (OE_TC_SRC_CAN_CAN0_INT13)

/** \brief  938, MULTICAN Service Request */
#define OE_TC_SRC_CAN_CAN0_INT14        (0x0938U)

/** Alias (User Manual Name) for OE_TC_SRC_CAN_CAN0_INT14.
 * To use register names with standard convention, please use OE_TC_SRC_CAN_CAN0_INT14.
 */
#define OE_TC_SRC_CANINT14              (OE_TC_SRC_CAN_CAN0_INT14)

/** \brief  93C, MULTICAN Service Request */
#define OE_TC_SRC_CAN_CAN0_INT15        (0x093CU)

/** Alias (User Manual Name) for OE_TC_SRC_CAN_CAN0_INT15.
 * To use register names with standard convention, please use OE_TC_SRC_CAN_CAN0_INT15.
 */
#define OE_TC_SRC_CANINT15              (OE_TC_SRC_CAN_CAN0_INT15)

/** \brief  908, MULTICAN Service Request */
#define OE_TC_SRC_CAN_CAN0_INT2         (0x0908U)

/** Alias (User Manual Name) for OE_TC_SRC_CAN_CAN0_INT2.
 * To use register names with standard convention, please use OE_TC_SRC_CAN_CAN0_INT2.
 */
#define OE_TC_SRC_CANINT2               (OE_TC_SRC_CAN_CAN0_INT2)

/** \brief  90C, MULTICAN Service Request */
#define OE_TC_SRC_CAN_CAN0_INT3         (0x090CU)

/** Alias (User Manual Name) for OE_TC_SRC_CAN_CAN0_INT3.
 * To use register names with standard convention, please use OE_TC_SRC_CAN_CAN0_INT3.
 */
#define OE_TC_SRC_CANINT3               (OE_TC_SRC_CAN_CAN0_INT3)

/** \brief  910, MULTICAN Service Request */
#define OE_TC_SRC_CAN_CAN0_INT4         (0x0910U)

/** Alias (User Manual Name) for OE_TC_SRC_CAN_CAN0_INT4.
 * To use register names with standard convention, please use OE_TC_SRC_CAN_CAN0_INT4.
 */
#define OE_TC_SRC_CANINT4               (OE_TC_SRC_CAN_CAN0_INT4)

/** \brief  914, MULTICAN Service Request */
#define OE_TC_SRC_CAN_CAN0_INT5         (0x0914U)

/** Alias (User Manual Name) for OE_TC_SRC_CAN_CAN0_INT5.
 * To use register names with standard convention, please use OE_TC_SRC_CAN_CAN0_INT5.
 */
#define OE_TC_SRC_CANINT5               (OE_TC_SRC_CAN_CAN0_INT5)

/** \brief  918, MULTICAN Service Request */
#define OE_TC_SRC_CAN_CAN0_INT6         (0x0918U)

/** Alias (User Manual Name) for OE_TC_SRC_CAN_CAN0_INT6.
 * To use register names with standard convention, please use OE_TC_SRC_CAN_CAN0_INT6.
 */
#define OE_TC_SRC_CANINT6               (OE_TC_SRC_CAN_CAN0_INT6)

/** \brief  91C, MULTICAN Service Request */
#define OE_TC_SRC_CAN_CAN0_INT7         (0x091CU)

/** Alias (User Manual Name) for OE_TC_SRC_CAN_CAN0_INT7.
 * To use register names with standard convention, please use OE_TC_SRC_CAN_CAN0_INT7.
 */
#define OE_TC_SRC_CANINT7               (OE_TC_SRC_CAN_CAN0_INT7)

/** \brief  920, MULTICAN Service Request */
#define OE_TC_SRC_CAN_CAN0_INT8         (0x0920U)

/** Alias (User Manual Name) for OE_TC_SRC_CAN_CAN0_INT8.
 * To use register names with standard convention, please use OE_TC_SRC_CAN_CAN0_INT8.
 */
#define OE_TC_SRC_CANINT8               (OE_TC_SRC_CAN_CAN0_INT8)

/** \brief  924, MULTICAN Service Request */
#define OE_TC_SRC_CAN_CAN0_INT9         (0x0924U)

/** Alias (User Manual Name) for OE_TC_SRC_CAN_CAN0_INT9.
 * To use register names with standard convention, please use OE_TC_SRC_CAN_CAN0_INT9.
 */
#define OE_TC_SRC_CANINT9               (OE_TC_SRC_CAN_CAN0_INT9)

/** \brief  940, MULTICAN1 Service Request */
#define OE_TC_SRC_CAN_CAN10_INT0        (0x0940U)

/** Alias (User Manual Name) for OE_TC_SRC_CAN_CAN10_INT0.
 * To use register names with standard convention, please use OE_TC_SRC_CAN_CAN10_INT0.
 */
#define OE_TC_SRC_CAN1INT0              (OE_TC_SRC_CAN_CAN10_INT0)

/** \brief  944, MULTICAN1 Service Request */
#define OE_TC_SRC_CAN_CAN10_INT1        (0x0944U)

/** Alias (User Manual Name) for OE_TC_SRC_CAN_CAN10_INT1.
 * To use register names with standard convention, please use OE_TC_SRC_CAN_CAN10_INT1.
 */
#define OE_TC_SRC_CAN1INT1              (OE_TC_SRC_CAN_CAN10_INT1)

/** \brief  948, MULTICAN1 Service Request */
#define OE_TC_SRC_CAN_CAN10_INT2        (0x0948U)

/** Alias (User Manual Name) for OE_TC_SRC_CAN_CAN10_INT2.
 * To use register names with standard convention, please use OE_TC_SRC_CAN_CAN10_INT2.
 */
#define OE_TC_SRC_CAN1INT2              (OE_TC_SRC_CAN_CAN10_INT2)

/** \brief  94C, MULTICAN1 Service Request */
#define OE_TC_SRC_CAN_CAN10_INT3        (0x094CU)

/** Alias (User Manual Name) for OE_TC_SRC_CAN_CAN10_INT3.
 * To use register names with standard convention, please use OE_TC_SRC_CAN_CAN10_INT3.
 */
#define OE_TC_SRC_CAN1INT3              (OE_TC_SRC_CAN_CAN10_INT3)

/** \brief  950, MULTICAN1 Service Request */
#define OE_TC_SRC_CAN_CAN10_INT4        (0x0950U)

/** Alias (User Manual Name) for OE_TC_SRC_CAN_CAN10_INT4.
 * To use register names with standard convention, please use OE_TC_SRC_CAN_CAN10_INT4.
 */
#define OE_TC_SRC_CAN1INT4              (OE_TC_SRC_CAN_CAN10_INT4)

/** \brief  954, MULTICAN1 Service Request */
#define OE_TC_SRC_CAN_CAN10_INT5        (0x0954U)

/** Alias (User Manual Name) for OE_TC_SRC_CAN_CAN10_INT5.
 * To use register names with standard convention, please use OE_TC_SRC_CAN_CAN10_INT5.
 */
#define OE_TC_SRC_CAN1INT5              (OE_TC_SRC_CAN_CAN10_INT5)

/** \brief  958, MULTICAN1 Service Request */
#define OE_TC_SRC_CAN_CAN10_INT6        (0x0958U)

/** Alias (User Manual Name) for OE_TC_SRC_CAN_CAN10_INT6.
 * To use register names with standard convention, please use OE_TC_SRC_CAN_CAN10_INT6.
 */
#define OE_TC_SRC_CAN1INT6              (OE_TC_SRC_CAN_CAN10_INT6)

/** \brief  95C, MULTICAN1 Service Request */
#define OE_TC_SRC_CAN_CAN10_INT7        (0x095CU)

/** Alias (User Manual Name) for OE_TC_SRC_CAN_CAN10_INT7.
 * To use register names with standard convention, please use OE_TC_SRC_CAN_CAN10_INT7.
 */
#define OE_TC_SRC_CAN1INT7              (OE_TC_SRC_CAN_CAN10_INT7)

/** \brief  420, CCU6 Service Request 0 */
#define OE_TC_SRC_CCU6_CCU60_SR0        (0x0420U)

/** Alias (User Manual Name) for OE_TC_SRC_CCU6_CCU60_SR0.
 * To use register names with standard convention, please use OE_TC_SRC_CCU6_CCU60_SR0.
 */
#define OE_TC_SRC_CCU60SR0              (OE_TC_SRC_CCU6_CCU60_SR0)

/** \brief  424, CCU6 Service Request 1 */
#define OE_TC_SRC_CCU6_CCU60_SR1        (0x0424U)

/** Alias (User Manual Name) for OE_TC_SRC_CCU6_CCU60_SR1.
 * To use register names with standard convention, please use OE_TC_SRC_CCU6_CCU60_SR1.
 */
#define OE_TC_SRC_CCU60SR1              (OE_TC_SRC_CCU6_CCU60_SR1)

/** \brief  428, CCU6 Service Request 2 */
#define OE_TC_SRC_CCU6_CCU60_SR2        (0x0428U)

/** Alias (User Manual Name) for OE_TC_SRC_CCU6_CCU60_SR2.
 * To use register names with standard convention, please use OE_TC_SRC_CCU6_CCU60_SR2.
 */
#define OE_TC_SRC_CCU60SR2              (OE_TC_SRC_CCU6_CCU60_SR2)

/** \brief  42C, CCU6 Service Request 3 */
#define OE_TC_SRC_CCU6_CCU60_SR3        (0x042CU)

/** Alias (User Manual Name) for OE_TC_SRC_CCU6_CCU60_SR3.
 * To use register names with standard convention, please use OE_TC_SRC_CCU6_CCU60_SR3.
 */
#define OE_TC_SRC_CCU60SR3              (OE_TC_SRC_CCU6_CCU60_SR3)

/** \brief  430, CCU6 Service Request 0 */
#define OE_TC_SRC_CCU6_CCU61_SR0        (0x0430U)

/** Alias (User Manual Name) for OE_TC_SRC_CCU6_CCU61_SR0.
 * To use register names with standard convention, please use OE_TC_SRC_CCU6_CCU61_SR0.
 */
#define OE_TC_SRC_CCU61SR0              (OE_TC_SRC_CCU6_CCU61_SR0)

/** \brief  434, CCU6 Service Request 1 */
#define OE_TC_SRC_CCU6_CCU61_SR1        (0x0434U)

/** Alias (User Manual Name) for OE_TC_SRC_CCU6_CCU61_SR1.
 * To use register names with standard convention, please use OE_TC_SRC_CCU6_CCU61_SR1.
 */
#define OE_TC_SRC_CCU61SR1              (OE_TC_SRC_CCU6_CCU61_SR1)

/** \brief  438, CCU6 Service Request 2 */
#define OE_TC_SRC_CCU6_CCU61_SR2        (0x0438U)

/** Alias (User Manual Name) for OE_TC_SRC_CCU6_CCU61_SR2.
 * To use register names with standard convention, please use OE_TC_SRC_CCU6_CCU61_SR2.
 */
#define OE_TC_SRC_CCU61SR2              (OE_TC_SRC_CCU6_CCU61_SR2)

/** \brief  43C, CCU6 Service Request 3 */
#define OE_TC_SRC_CCU6_CCU61_SR3        (0x043CU)

/** Alias (User Manual Name) for OE_TC_SRC_CCU6_CCU61_SR3.
 * To use register names with standard convention, please use OE_TC_SRC_CCU6_CCU61_SR3.
 */
#define OE_TC_SRC_CCU61SR3              (OE_TC_SRC_CCU6_CCU61_SR3)

/** \brief  50, Cerberus Service Request */
#define OE_TC_SRC_CERBERUS_CERBERUS_SR0 (0x0050U)

/** Alias (User Manual Name) for OE_TC_SRC_CERBERUS_CERBERUS_SR0.
 * To use register names with standard convention, please use OE_TC_SRC_CERBERUS_CERBERUS_SR0.
 */
#define OE_TC_SRC_CERBERUS0             (OE_TC_SRC_CERBERUS_CERBERUS_SR0)

/** \brief  54, Cerberus Service Request */
#define OE_TC_SRC_CERBERUS_CERBERUS_SR1 (0x0054U)

/** Alias (User Manual Name) for OE_TC_SRC_CERBERUS_CERBERUS_SR1.
 * To use register names with standard convention, please use OE_TC_SRC_CERBERUS_CERBERUS_SR1.
 */
#define OE_TC_SRC_CERBERUS1             (OE_TC_SRC_CERBERUS_CERBERUS_SR1)

/** \brief  0, CPUSoftware Breakpoint Service Request */
#define OE_TC_SRC_CPU_CPU0_SBSRC        (0x0000U)

/** Alias (User Manual Name) for OE_TC_SRC_CPU_CPU0_SBSRC.
 * To use register names with standard convention, please use OE_TC_SRC_CPU_CPU0_SBSRC.
 */
#define OE_TC_SRC_CPU0SBSRC             (OE_TC_SRC_CPU_CPU0_SBSRC)

/** \brief  500, DMA Channel Service Request */
#define OE_TC_SRC_DMA_DMA0_CH0          (0x0500U)

/** Alias (User Manual Name) for OE_TC_SRC_DMA_DMA0_CH0.
 * To use register names with standard convention, please use OE_TC_SRC_DMA_DMA0_CH0.
 */
#define OE_TC_SRC_DMACH0                (OE_TC_SRC_DMA_DMA0_CH0)

/** \brief  504, DMA Channel Service Request */
#define OE_TC_SRC_DMA_DMA0_CH1          (0x0504U)

/** Alias (User Manual Name) for OE_TC_SRC_DMA_DMA0_CH1.
 * To use register names with standard convention, please use OE_TC_SRC_DMA_DMA0_CH1.
 */
#define OE_TC_SRC_DMACH1                (OE_TC_SRC_DMA_DMA0_CH1)

/** \brief  528, DMA Channel Service Request */
#define OE_TC_SRC_DMA_DMA0_CH10         (0x0528U)

/** Alias (User Manual Name) for OE_TC_SRC_DMA_DMA0_CH10.
 * To use register names with standard convention, please use OE_TC_SRC_DMA_DMA0_CH10.
 */
#define OE_TC_SRC_DMACH10               (OE_TC_SRC_DMA_DMA0_CH10)

/** \brief  52C, DMA Channel Service Request */
#define OE_TC_SRC_DMA_DMA0_CH11         (0x052CU)

/** Alias (User Manual Name) for OE_TC_SRC_DMA_DMA0_CH11.
 * To use register names with standard convention, please use OE_TC_SRC_DMA_DMA0_CH11.
 */
#define OE_TC_SRC_DMACH11               (OE_TC_SRC_DMA_DMA0_CH11)

/** \brief  530, DMA Channel Service Request */
#define OE_TC_SRC_DMA_DMA0_CH12         (0x0530U)

/** Alias (User Manual Name) for OE_TC_SRC_DMA_DMA0_CH12.
 * To use register names with standard convention, please use OE_TC_SRC_DMA_DMA0_CH12.
 */
#define OE_TC_SRC_DMACH12               (OE_TC_SRC_DMA_DMA0_CH12)

/** \brief  534, DMA Channel Service Request */
#define OE_TC_SRC_DMA_DMA0_CH13         (0x0534U)

/** Alias (User Manual Name) for OE_TC_SRC_DMA_DMA0_CH13.
 * To use register names with standard convention, please use OE_TC_SRC_DMA_DMA0_CH13.
 */
#define OE_TC_SRC_DMACH13               (OE_TC_SRC_DMA_DMA0_CH13)

/** \brief  538, DMA Channel Service Request */
#define OE_TC_SRC_DMA_DMA0_CH14         (0x0538U)

/** Alias (User Manual Name) for OE_TC_SRC_DMA_DMA0_CH14.
 * To use register names with standard convention, please use OE_TC_SRC_DMA_DMA0_CH14.
 */
#define OE_TC_SRC_DMACH14               (OE_TC_SRC_DMA_DMA0_CH14)

/** \brief  53C, DMA Channel Service Request */
#define OE_TC_SRC_DMA_DMA0_CH15         (0x053CU)

/** Alias (User Manual Name) for OE_TC_SRC_DMA_DMA0_CH15.
 * To use register names with standard convention, please use OE_TC_SRC_DMA_DMA0_CH15.
 */
#define OE_TC_SRC_DMACH15               (OE_TC_SRC_DMA_DMA0_CH15)

/** \brief  508, DMA Channel Service Request */
#define OE_TC_SRC_DMA_DMA0_CH2          (0x0508U)

/** Alias (User Manual Name) for OE_TC_SRC_DMA_DMA0_CH2.
 * To use register names with standard convention, please use OE_TC_SRC_DMA_DMA0_CH2.
 */
#define OE_TC_SRC_DMACH2                (OE_TC_SRC_DMA_DMA0_CH2)

/** \brief  50C, DMA Channel Service Request */
#define OE_TC_SRC_DMA_DMA0_CH3          (0x050CU)

/** Alias (User Manual Name) for OE_TC_SRC_DMA_DMA0_CH3.
 * To use register names with standard convention, please use OE_TC_SRC_DMA_DMA0_CH3.
 */
#define OE_TC_SRC_DMACH3                (OE_TC_SRC_DMA_DMA0_CH3)

/** \brief  510, DMA Channel Service Request */
#define OE_TC_SRC_DMA_DMA0_CH4          (0x0510U)

/** Alias (User Manual Name) for OE_TC_SRC_DMA_DMA0_CH4.
 * To use register names with standard convention, please use OE_TC_SRC_DMA_DMA0_CH4.
 */
#define OE_TC_SRC_DMACH4                (OE_TC_SRC_DMA_DMA0_CH4)

/** \brief  514, DMA Channel Service Request */
#define OE_TC_SRC_DMA_DMA0_CH5          (0x0514U)

/** Alias (User Manual Name) for OE_TC_SRC_DMA_DMA0_CH5.
 * To use register names with standard convention, please use OE_TC_SRC_DMA_DMA0_CH5.
 */
#define OE_TC_SRC_DMACH5                (OE_TC_SRC_DMA_DMA0_CH5)

/** \brief  518, DMA Channel Service Request */
#define OE_TC_SRC_DMA_DMA0_CH6          (0x0518U)

/** Alias (User Manual Name) for OE_TC_SRC_DMA_DMA0_CH6.
 * To use register names with standard convention, please use OE_TC_SRC_DMA_DMA0_CH6.
 */
#define OE_TC_SRC_DMACH6                (OE_TC_SRC_DMA_DMA0_CH6)

/** \brief  51C, DMA Channel Service Request */
#define OE_TC_SRC_DMA_DMA0_CH7          (0x051CU)

/** Alias (User Manual Name) for OE_TC_SRC_DMA_DMA0_CH7.
 * To use register names with standard convention, please use OE_TC_SRC_DMA_DMA0_CH7.
 */
#define OE_TC_SRC_DMACH7                (OE_TC_SRC_DMA_DMA0_CH7)

/** \brief  520, DMA Channel Service Request */
#define OE_TC_SRC_DMA_DMA0_CH8          (0x0520U)

/** Alias (User Manual Name) for OE_TC_SRC_DMA_DMA0_CH8.
 * To use register names with standard convention, please use OE_TC_SRC_DMA_DMA0_CH8.
 */
#define OE_TC_SRC_DMACH8                (OE_TC_SRC_DMA_DMA0_CH8)

/** \brief  524, DMA Channel Service Request */
#define OE_TC_SRC_DMA_DMA0_CH9          (0x0524U)

/** Alias (User Manual Name) for OE_TC_SRC_DMA_DMA0_CH9.
 * To use register names with standard convention, please use OE_TC_SRC_DMA_DMA0_CH9.
 */
#define OE_TC_SRC_DMACH9                (OE_TC_SRC_DMA_DMA0_CH9)

/** \brief  4F0, DMA Error Service Request */
#define OE_TC_SRC_DMA_DMA0_ERR          (0x04F0U)

/** Alias (User Manual Name) for OE_TC_SRC_DMA_DMA0_ERR.
 * To use register names with standard convention, please use OE_TC_SRC_DMA_DMA0_ERR.
 */
#define OE_TC_SRC_DMAERR                (OE_TC_SRC_DMA_DMA0_ERR)

/** \brief  20, Emulation Memory Service Request */
#define OE_TC_SRC_EMEM_EMEM0_SR         (0x0020U)

/** Alias (User Manual Name) for OE_TC_SRC_EMEM_EMEM0_SR.
 * To use register names with standard convention, please use OE_TC_SRC_EMEM_EMEM0_SR.
 */
#define OE_TC_SRC_EMEM                  (OE_TC_SRC_EMEM_EMEM0_SR)

/** \brief  C04, E-RAY Input BUffer BUsy Service Request */
#define OE_TC_SRC_ERAY_ERAY0_IBUSY      (0x0C04U)

/** Alias (User Manual Name) for OE_TC_SRC_ERAY_ERAY0_IBUSY.
 * To use register names with standard convention, please use OE_TC_SRC_ERAY_ERAY0_IBUSY.
 */
#define OE_TC_SRC_ERAYIBUSY             (OE_TC_SRC_ERAY_ERAY0_IBUSY)

/** \brief  BE0, E-RAY Service Request */
#define OE_TC_SRC_ERAY_ERAY0_INT0       (0x0BE0U)

/** Alias (User Manual Name) for OE_TC_SRC_ERAY_ERAY0_INT0.
 * To use register names with standard convention, please use OE_TC_SRC_ERAY_ERAY0_INT0.
 */
#define OE_TC_SRC_ERAYINT0              (OE_TC_SRC_ERAY_ERAY0_INT0)

/** \brief  BE4, E-RAY Service Request */
#define OE_TC_SRC_ERAY_ERAY0_INT1       (0x0BE4U)

/** Alias (User Manual Name) for OE_TC_SRC_ERAY_ERAY0_INT1.
 * To use register names with standard convention, please use OE_TC_SRC_ERAY_ERAY0_INT1.
 */
#define OE_TC_SRC_ERAYINT1              (OE_TC_SRC_ERAY_ERAY0_INT1)

/** \brief  BF8, E-RAY Message BUffer Status Changed Service Request */
#define OE_TC_SRC_ERAY_ERAY0_MBSC0      (0x0BF8U)

/** Alias (User Manual Name) for OE_TC_SRC_ERAY_ERAY0_MBSC0.
 * To use register names with standard convention, please use OE_TC_SRC_ERAY_ERAY0_MBSC0.
 */
#define OE_TC_SRC_ERAYMBSC0             (OE_TC_SRC_ERAY_ERAY0_MBSC0)

/** \brief  BFC, E-RAY Message BUffer Status Changed Service Request */
#define OE_TC_SRC_ERAY_ERAY0_MBSC1      (0x0BFCU)

/** Alias (User Manual Name) for OE_TC_SRC_ERAY_ERAY0_MBSC1.
 * To use register names with standard convention, please use OE_TC_SRC_ERAY_ERAY0_MBSC1.
 */
#define OE_TC_SRC_ERAYMBSC1             (OE_TC_SRC_ERAY_ERAY0_MBSC1)

/** \brief  BF0, E-RAY New Data Service Request */
#define OE_TC_SRC_ERAY_ERAY0_NDAT0      (0x0BF0U)

/** Alias (User Manual Name) for OE_TC_SRC_ERAY_ERAY0_NDAT0.
 * To use register names with standard convention, please use OE_TC_SRC_ERAY_ERAY0_NDAT0.
 */
#define OE_TC_SRC_ERAYNDAT0             (OE_TC_SRC_ERAY_ERAY0_NDAT0)

/** \brief  BF4, E-RAY New Data Service Request */
#define OE_TC_SRC_ERAY_ERAY0_NDAT1      (0x0BF4U)

/** Alias (User Manual Name) for OE_TC_SRC_ERAY_ERAY0_NDAT1.
 * To use register names with standard convention, please use OE_TC_SRC_ERAY_ERAY0_NDAT1.
 */
#define OE_TC_SRC_ERAYNDAT1             (OE_TC_SRC_ERAY_ERAY0_NDAT1)

/** \brief  C00, E-RAY Output BUffer BUsy Service Request */
#define OE_TC_SRC_ERAY_ERAY0_OBUSY      (0x0C00U)

/** Alias (User Manual Name) for OE_TC_SRC_ERAY_ERAY0_OBUSY.
 * To use register names with standard convention, please use OE_TC_SRC_ERAY_ERAY0_OBUSY.
 */
#define OE_TC_SRC_ERAYOBUSY             (OE_TC_SRC_ERAY_ERAY0_OBUSY)

/** \brief  BE8, E-RAY Timer Interrupt Service Request */
#define OE_TC_SRC_ERAY_ERAY0_TINT0      (0x0BE8U)

/** Alias (User Manual Name) for OE_TC_SRC_ERAY_ERAY0_TINT0.
 * To use register names with standard convention, please use OE_TC_SRC_ERAY_ERAY0_TINT0.
 */
#define OE_TC_SRC_ERAYTINT0             (OE_TC_SRC_ERAY_ERAY0_TINT0)

/** \brief  BEC, E-RAY Timer Interrupt Service Request */
#define OE_TC_SRC_ERAY_ERAY0_TINT1      (0x0BECU)

/** Alias (User Manual Name) for OE_TC_SRC_ERAY_ERAY0_TINT1.
 * To use register names with standard convention, please use OE_TC_SRC_ERAY_ERAY0_TINT1.
 */
#define OE_TC_SRC_ERAYTINT1             (OE_TC_SRC_ERAY_ERAY0_TINT1)

/** \brief  8F0, Ethernet Service Request */
#define OE_TC_SRC_ETH_ETH0_SR           (0x08F0U)

/** Alias (User Manual Name) for OE_TC_SRC_ETH_ETH0_SR.
 * To use register names with standard convention, please use OE_TC_SRC_ETH_ETH0_SR.
 */
#define OE_TC_SRC_ETH                   (OE_TC_SRC_ETH_ETH0_SR)

/** \brief  FB4, EVR Supply Service Request */
#define OE_TC_SRC_EVR_EVR0_SCDC         (0x0FB4U)

/** Alias (User Manual Name) for OE_TC_SRC_EVR_EVR0_SCDC.
 * To use register names with standard convention, please use OE_TC_SRC_EVR_EVR0_SCDC.
 */
#define OE_TC_SRC_EVRSCDC               (OE_TC_SRC_EVR_EVR0_SCDC)

/** \brief  FB0, EVR Wake Up Timer Service Request */
#define OE_TC_SRC_EVR_EVR0_WUT          (0x0FB0U)

/** Alias (User Manual Name) for OE_TC_SRC_EVR_EVR0_WUT.
 * To use register names with standard convention, please use OE_TC_SRC_EVR_EVR0_WUT.
 */
#define OE_TC_SRC_EVRWUT                (OE_TC_SRC_EVR_EVR0_WUT)

/** \brief  FC0, FFT Done Service Request */
#define OE_TC_SRC_FFT_FFT0_DONE         (0x0FC0U)

/** Alias (User Manual Name) for OE_TC_SRC_FFT_FFT0_DONE.
 * To use register names with standard convention, please use OE_TC_SRC_FFT_FFT0_DONE.
 */
#define OE_TC_SRC_FFTDONE               (OE_TC_SRC_FFT_FFT0_DONE)

/** \brief  FC4, FFT Error Service Request */
#define OE_TC_SRC_FFT_FFT0_ERR          (0x0FC4U)

/** Alias (User Manual Name) for OE_TC_SRC_FFT_FFT0_ERR.
 * To use register names with standard convention, please use OE_TC_SRC_FFT_FFT0_ERR.
 */
#define OE_TC_SRC_FFTERR                (OE_TC_SRC_FFT_FFT0_ERR)

/** \brief  FC8, FFT Ready For Start Service Request */
#define OE_TC_SRC_FFT_FFT0_RFS          (0x0FC8U)

/** Alias (User Manual Name) for OE_TC_SRC_FFT_FFT0_RFS.
 * To use register names with standard convention, please use OE_TC_SRC_FFT_FFT0_RFS.
 */
#define OE_TC_SRC_FFTRFS                (OE_TC_SRC_FFT_FFT0_RFS)

/** \brief  1000, General Purpose Service Request 0 */
#define OE_TC_SRC_GPSR_GPSR0_SR0        (0x1000U)

/** Alias (User Manual Name) for OE_TC_SRC_GPSR_GPSR0_SR0.
 * To use register names with standard convention, please use OE_TC_SRC_GPSR_GPSR0_SR0.
 */
#define OE_TC_SRC_GPSR00                (OE_TC_SRC_GPSR_GPSR0_SR0)

/** \brief  1004, General Purpose Service Request 1 */
#define OE_TC_SRC_GPSR_GPSR0_SR1        (0x1004U)

/** Alias (User Manual Name) for OE_TC_SRC_GPSR_GPSR0_SR1.
 * To use register names with standard convention, please use OE_TC_SRC_GPSR_GPSR0_SR1.
 */
#define OE_TC_SRC_GPSR01                (OE_TC_SRC_GPSR_GPSR0_SR1)

/** \brief  1008, General Purpose Service Request 2 */
#define OE_TC_SRC_GPSR_GPSR0_SR2        (0x1008U)

/** Alias (User Manual Name) for OE_TC_SRC_GPSR_GPSR0_SR2.
 * To use register names with standard convention, please use OE_TC_SRC_GPSR_GPSR0_SR2.
 */
#define OE_TC_SRC_GPSR02                (OE_TC_SRC_GPSR_GPSR0_SR2)

/** \brief  100C, General Purpose Service Request 3 */
#define OE_TC_SRC_GPSR_GPSR0_SR3        (0x100CU)

/** Alias (User Manual Name) for OE_TC_SRC_GPSR_GPSR0_SR3.
 * To use register names with standard convention, please use OE_TC_SRC_GPSR_GPSR0_SR3.
 */
#define OE_TC_SRC_GPSR03                (OE_TC_SRC_GPSR_GPSR0_SR3)

/** \brief  460, GPT12 CAPREL Service Request */
#define OE_TC_SRC_GPT12_GPT120_CIRQ     (0x0460U)

/** Alias (User Manual Name) for OE_TC_SRC_GPT12_GPT120_CIRQ.
 * To use register names with standard convention, please use OE_TC_SRC_GPT12_GPT120_CIRQ.
 */
#define OE_TC_SRC_GPT120CIRQ            (OE_TC_SRC_GPT12_GPT120_CIRQ)

/** \brief  464, GPT12 T2 Overflow/Underflow Service Request */
#define OE_TC_SRC_GPT12_GPT120_T2       (0x0464U)

/** Alias (User Manual Name) for OE_TC_SRC_GPT12_GPT120_T2.
 * To use register names with standard convention, please use OE_TC_SRC_GPT12_GPT120_T2.
 */
#define OE_TC_SRC_GPT120T2              (OE_TC_SRC_GPT12_GPT120_T2)

/** \brief  468, GPT12 T3 Overflow/Underflow Service Request */
#define OE_TC_SRC_GPT12_GPT120_T3       (0x0468U)

/** Alias (User Manual Name) for OE_TC_SRC_GPT12_GPT120_T3.
 * To use register names with standard convention, please use OE_TC_SRC_GPT12_GPT120_T3.
 */
#define OE_TC_SRC_GPT120T3              (OE_TC_SRC_GPT12_GPT120_T3)

/** \brief  46C, GPT12 T4 Overflow/Underflow Service Request */
#define OE_TC_SRC_GPT12_GPT120_T4       (0x046CU)

/** Alias (User Manual Name) for OE_TC_SRC_GPT12_GPT120_T4.
 * To use register names with standard convention, please use OE_TC_SRC_GPT12_GPT120_T4.
 */
#define OE_TC_SRC_GPT120T4              (OE_TC_SRC_GPT12_GPT120_T4)

/** \brief  470, GPT12 T5 Overflow/Underflow Service Request */
#define OE_TC_SRC_GPT12_GPT120_T5       (0x0470U)

/** Alias (User Manual Name) for OE_TC_SRC_GPT12_GPT120_T5.
 * To use register names with standard convention, please use OE_TC_SRC_GPT12_GPT120_T5.
 */
#define OE_TC_SRC_GPT120T5              (OE_TC_SRC_GPT12_GPT120_T5)

/** \brief  474, GPT12 T6 Overflow/Underflow Service Request */
#define OE_TC_SRC_GPT12_GPT120_T6       (0x0474U)

/** Alias (User Manual Name) for OE_TC_SRC_GPT12_GPT120_T6.
 * To use register names with standard convention, please use OE_TC_SRC_GPT12_GPT120_T6.
 */
#define OE_TC_SRC_GPT120T6              (OE_TC_SRC_GPT12_GPT120_T6)

/** \brief  1600, GTM AEI Shared Service Request */
#define OE_TC_SRC_GTM_GTM0_AEIIRQ       (0x1600U)

/** Alias (User Manual Name) for OE_TC_SRC_GTM_GTM0_AEIIRQ.
 * To use register names with standard convention, please use OE_TC_SRC_GTM_GTM0_AEIIRQ.
 */
#define OE_TC_SRC_GTMAEIIRQ             (OE_TC_SRC_GTM_GTM0_AEIIRQ)

/** \brief  1770, GTM Error Service Request */
#define OE_TC_SRC_GTM_GTM0_ERR          (0x1770U)

/** Alias (User Manual Name) for OE_TC_SRC_GTM_GTM0_ERR.
 * To use register names with standard convention, please use OE_TC_SRC_GTM_GTM0_ERR.
 */
#define OE_TC_SRC_GTMERR                (OE_TC_SRC_GTM_GTM0_ERR)

/** \brief  1780, GTM TIM Shared Service Request */
#define OE_TC_SRC_GTM_GTM0_TIM0_0       (0x1780U)

/** Alias (User Manual Name) for OE_TC_SRC_GTM_GTM0_TIM0_0.
 * To use register names with standard convention, please use OE_TC_SRC_GTM_GTM0_TIM0_0.
 */
#define OE_TC_SRC_GTMTIM00              (OE_TC_SRC_GTM_GTM0_TIM0_0)

/** \brief  1784, GTM TIM Shared Service Request */
#define OE_TC_SRC_GTM_GTM0_TIM0_1       (0x1784U)

/** Alias (User Manual Name) for OE_TC_SRC_GTM_GTM0_TIM0_1.
 * To use register names with standard convention, please use OE_TC_SRC_GTM_GTM0_TIM0_1.
 */
#define OE_TC_SRC_GTMTIM01              (OE_TC_SRC_GTM_GTM0_TIM0_1)

/** \brief  1788, GTM TIM Shared Service Request */
#define OE_TC_SRC_GTM_GTM0_TIM0_2       (0x1788U)

/** Alias (User Manual Name) for OE_TC_SRC_GTM_GTM0_TIM0_2.
 * To use register names with standard convention, please use OE_TC_SRC_GTM_GTM0_TIM0_2.
 */
#define OE_TC_SRC_GTMTIM02              (OE_TC_SRC_GTM_GTM0_TIM0_2)

/** \brief  178C, GTM TIM Shared Service Request */
#define OE_TC_SRC_GTM_GTM0_TIM0_3       (0x178CU)

/** Alias (User Manual Name) for OE_TC_SRC_GTM_GTM0_TIM0_3.
 * To use register names with standard convention, please use OE_TC_SRC_GTM_GTM0_TIM0_3.
 */
#define OE_TC_SRC_GTMTIM03              (OE_TC_SRC_GTM_GTM0_TIM0_3)

/** \brief  1790, GTM TIM Shared Service Request */
#define OE_TC_SRC_GTM_GTM0_TIM0_4       (0x1790U)

/** Alias (User Manual Name) for OE_TC_SRC_GTM_GTM0_TIM0_4.
 * To use register names with standard convention, please use OE_TC_SRC_GTM_GTM0_TIM0_4.
 */
#define OE_TC_SRC_GTMTIM04              (OE_TC_SRC_GTM_GTM0_TIM0_4)

/** \brief  1794, GTM TIM Shared Service Request */
#define OE_TC_SRC_GTM_GTM0_TIM0_5       (0x1794U)

/** Alias (User Manual Name) for OE_TC_SRC_GTM_GTM0_TIM0_5.
 * To use register names with standard convention, please use OE_TC_SRC_GTM_GTM0_TIM0_5.
 */
#define OE_TC_SRC_GTMTIM05              (OE_TC_SRC_GTM_GTM0_TIM0_5)

/** \brief  1798, GTM TIM Shared Service Request */
#define OE_TC_SRC_GTM_GTM0_TIM0_6       (0x1798U)

/** Alias (User Manual Name) for OE_TC_SRC_GTM_GTM0_TIM0_6.
 * To use register names with standard convention, please use OE_TC_SRC_GTM_GTM0_TIM0_6.
 */
#define OE_TC_SRC_GTMTIM06              (OE_TC_SRC_GTM_GTM0_TIM0_6)

/** \brief  179C, GTM TIM Shared Service Request */
#define OE_TC_SRC_GTM_GTM0_TIM0_7       (0x179CU)

/** Alias (User Manual Name) for OE_TC_SRC_GTM_GTM0_TIM0_7.
 * To use register names with standard convention, please use OE_TC_SRC_GTM_GTM0_TIM0_7.
 */
#define OE_TC_SRC_GTMTIM07              (OE_TC_SRC_GTM_GTM0_TIM0_7)

/** \brief  1B80, GTM TOM Shared Service Request */
#define OE_TC_SRC_GTM_GTM0_TOM0_0       (0x1B80U)

/** Alias (User Manual Name) for OE_TC_SRC_GTM_GTM0_TOM0_0.
 * To use register names with standard convention, please use OE_TC_SRC_GTM_GTM0_TOM0_0.
 */
#define OE_TC_SRC_GTMTOM00              (OE_TC_SRC_GTM_GTM0_TOM0_0)

/** \brief  1B84, GTM TOM Shared Service Request */
#define OE_TC_SRC_GTM_GTM0_TOM0_1       (0x1B84U)

/** Alias (User Manual Name) for OE_TC_SRC_GTM_GTM0_TOM0_1.
 * To use register names with standard convention, please use OE_TC_SRC_GTM_GTM0_TOM0_1.
 */
#define OE_TC_SRC_GTMTOM01              (OE_TC_SRC_GTM_GTM0_TOM0_1)

/** \brief  1B88, GTM TOM Shared Service Request */
#define OE_TC_SRC_GTM_GTM0_TOM0_2       (0x1B88U)

/** Alias (User Manual Name) for OE_TC_SRC_GTM_GTM0_TOM0_2.
 * To use register names with standard convention, please use OE_TC_SRC_GTM_GTM0_TOM0_2.
 */
#define OE_TC_SRC_GTMTOM02              (OE_TC_SRC_GTM_GTM0_TOM0_2)

/** \brief  1B8C, GTM TOM Shared Service Request */
#define OE_TC_SRC_GTM_GTM0_TOM0_3       (0x1B8CU)

/** Alias (User Manual Name) for OE_TC_SRC_GTM_GTM0_TOM0_3.
 * To use register names with standard convention, please use OE_TC_SRC_GTM_GTM0_TOM0_3.
 */
#define OE_TC_SRC_GTMTOM03              (OE_TC_SRC_GTM_GTM0_TOM0_3)

/** \brief  1B90, GTM TOM Shared Service Request */
#define OE_TC_SRC_GTM_GTM0_TOM0_4       (0x1B90U)

/** Alias (User Manual Name) for OE_TC_SRC_GTM_GTM0_TOM0_4.
 * To use register names with standard convention, please use OE_TC_SRC_GTM_GTM0_TOM0_4.
 */
#define OE_TC_SRC_GTMTOM04              (OE_TC_SRC_GTM_GTM0_TOM0_4)

/** \brief  1B94, GTM TOM Shared Service Request */
#define OE_TC_SRC_GTM_GTM0_TOM0_5       (0x1B94U)

/** Alias (User Manual Name) for OE_TC_SRC_GTM_GTM0_TOM0_5.
 * To use register names with standard convention, please use OE_TC_SRC_GTM_GTM0_TOM0_5.
 */
#define OE_TC_SRC_GTMTOM05              (OE_TC_SRC_GTM_GTM0_TOM0_5)

/** \brief  1B98, GTM TOM Shared Service Request */
#define OE_TC_SRC_GTM_GTM0_TOM0_6       (0x1B98U)

/** Alias (User Manual Name) for OE_TC_SRC_GTM_GTM0_TOM0_6.
 * To use register names with standard convention, please use OE_TC_SRC_GTM_GTM0_TOM0_6.
 */
#define OE_TC_SRC_GTMTOM06              (OE_TC_SRC_GTM_GTM0_TOM0_6)

/** \brief  1B9C, GTM TOM Shared Service Request */
#define OE_TC_SRC_GTM_GTM0_TOM0_7       (0x1B9CU)

/** Alias (User Manual Name) for OE_TC_SRC_GTM_GTM0_TOM0_7.
 * To use register names with standard convention, please use OE_TC_SRC_GTM_GTM0_TOM0_7.
 */
#define OE_TC_SRC_GTMTOM07              (OE_TC_SRC_GTM_GTM0_TOM0_7)

/** \brief  1BA0, GTM TOM Shared Service Request */
#define OE_TC_SRC_GTM_GTM0_TOM1_0       (0x1BA0U)

/** Alias (User Manual Name) for OE_TC_SRC_GTM_GTM0_TOM1_0.
 * To use register names with standard convention, please use OE_TC_SRC_GTM_GTM0_TOM1_0.
 */
#define OE_TC_SRC_GTMTOM10              (OE_TC_SRC_GTM_GTM0_TOM1_0)

/** \brief  1BA4, GTM TOM Shared Service Request */
#define OE_TC_SRC_GTM_GTM0_TOM1_1       (0x1BA4U)

/** Alias (User Manual Name) for OE_TC_SRC_GTM_GTM0_TOM1_1.
 * To use register names with standard convention, please use OE_TC_SRC_GTM_GTM0_TOM1_1.
 */
#define OE_TC_SRC_GTMTOM11              (OE_TC_SRC_GTM_GTM0_TOM1_1)

/** \brief  1BA8, GTM TOM Shared Service Request */
#define OE_TC_SRC_GTM_GTM0_TOM1_2       (0x1BA8U)

/** Alias (User Manual Name) for OE_TC_SRC_GTM_GTM0_TOM1_2.
 * To use register names with standard convention, please use OE_TC_SRC_GTM_GTM0_TOM1_2.
 */
#define OE_TC_SRC_GTMTOM12              (OE_TC_SRC_GTM_GTM0_TOM1_2)

/** \brief  1BAC, GTM TOM Shared Service Request */
#define OE_TC_SRC_GTM_GTM0_TOM1_3       (0x1BACU)

/** Alias (User Manual Name) for OE_TC_SRC_GTM_GTM0_TOM1_3.
 * To use register names with standard convention, please use OE_TC_SRC_GTM_GTM0_TOM1_3.
 */
#define OE_TC_SRC_GTMTOM13              (OE_TC_SRC_GTM_GTM0_TOM1_3)

/** \brief  1BB0, GTM TOM Shared Service Request */
#define OE_TC_SRC_GTM_GTM0_TOM1_4       (0x1BB0U)

/** Alias (User Manual Name) for OE_TC_SRC_GTM_GTM0_TOM1_4.
 * To use register names with standard convention, please use OE_TC_SRC_GTM_GTM0_TOM1_4.
 */
#define OE_TC_SRC_GTMTOM14              (OE_TC_SRC_GTM_GTM0_TOM1_4)

/** \brief  1BB4, GTM TOM Shared Service Request */
#define OE_TC_SRC_GTM_GTM0_TOM1_5       (0x1BB4U)

/** Alias (User Manual Name) for OE_TC_SRC_GTM_GTM0_TOM1_5.
 * To use register names with standard convention, please use OE_TC_SRC_GTM_GTM0_TOM1_5.
 */
#define OE_TC_SRC_GTMTOM15              (OE_TC_SRC_GTM_GTM0_TOM1_5)

/** \brief  1BB8, GTM TOM Shared Service Request */
#define OE_TC_SRC_GTM_GTM0_TOM1_6       (0x1BB8U)

/** Alias (User Manual Name) for OE_TC_SRC_GTM_GTM0_TOM1_6.
 * To use register names with standard convention, please use OE_TC_SRC_GTM_GTM0_TOM1_6.
 */
#define OE_TC_SRC_GTMTOM16              (OE_TC_SRC_GTM_GTM0_TOM1_6)

/** \brief  1BBC, GTM TOM Shared Service Request */
#define OE_TC_SRC_GTM_GTM0_TOM1_7       (0x1BBCU)

/** Alias (User Manual Name) for OE_TC_SRC_GTM_GTM0_TOM1_7.
 * To use register names with standard convention, please use OE_TC_SRC_GTM_GTM0_TOM1_7.
 */
#define OE_TC_SRC_GTMTOM17              (OE_TC_SRC_GTM_GTM0_TOM1_7)

/** \brief  CC0, HSM Service Request */
#define OE_TC_SRC_HSM_HSM0_HSM0         (0x0CC0U)

/** Alias (User Manual Name) for OE_TC_SRC_HSM_HSM0_HSM0.
 * To use register names with standard convention, please use OE_TC_SRC_HSM_HSM0_HSM0.
 */
#define OE_TC_SRC_HSM0                  (OE_TC_SRC_HSM_HSM0_HSM0)

/** \brief  CC4, HSM Service Request */
#define OE_TC_SRC_HSM_HSM0_HSM1         (0x0CC4U)

/** Alias (User Manual Name) for OE_TC_SRC_HSM_HSM0_HSM1.
 * To use register names with standard convention, please use OE_TC_SRC_HSM_HSM0_HSM1.
 */
#define OE_TC_SRC_HSM1                  (OE_TC_SRC_HSM_HSM0_HSM1)

/** \brief  DE0, LMU Service Request */
#define OE_TC_SRC_LMU_LMU0_SR           (0x0DE0U)

/** Alias (User Manual Name) for OE_TC_SRC_LMU_LMU0_SR.
 * To use register names with standard convention, please use OE_TC_SRC_LMU_LMU0_SR.
 */
#define OE_TC_SRC_LMU                   (OE_TC_SRC_LMU_LMU0_SR)

/** \brief  C30, PMU  Service Request */
#define OE_TC_SRC_PMU_PMU0_SR           (0x0C30U)

/** Alias (User Manual Name) for OE_TC_SRC_PMU_PMU0_SR.
 * To use register names with standard convention, please use OE_TC_SRC_PMU_PMU0_SR.
 */
#define OE_TC_SRC_PMU00                 (OE_TC_SRC_PMU_PMU0_SR)

/** \brief  C34, PMU  Service Request */
#define OE_TC_SRC_PMU_PMU1_SR           (0x0C34U)

/** Alias (User Manual Name) for OE_TC_SRC_PMU_PMU1_SR.
 * To use register names with standard convention, please use OE_TC_SRC_PMU_PMU1_SR.
 */
#define OE_TC_SRC_PMU01                 (OE_TC_SRC_PMU_PMU1_SR)

/** \brief  198, QSPI Error Service Request */
#define OE_TC_SRC_QSPI_QSPI0_ERR        (0x0198U)

/** Alias (User Manual Name) for OE_TC_SRC_QSPI_QSPI0_ERR.
 * To use register names with standard convention, please use OE_TC_SRC_QSPI_QSPI0_ERR.
 */
#define OE_TC_SRC_QSPI0ERR              (OE_TC_SRC_QSPI_QSPI0_ERR)

/** \brief  1A0, QSPI High Speed Capture Service Request */
#define OE_TC_SRC_QSPI_QSPI0_HC         (0x01A0U)

/** Alias (User Manual Name) for OE_TC_SRC_QSPI_QSPI0_HC.
 * To use register names with standard convention, please use OE_TC_SRC_QSPI_QSPI0_HC.
 */
#define OE_TC_SRC_RESERVED10            (OE_TC_SRC_QSPI_QSPI0_HC)

/** \brief  19C, QSPI Phase Transition Service Request */
#define OE_TC_SRC_QSPI_QSPI0_PT         (0x019CU)

/** Alias (User Manual Name) for OE_TC_SRC_QSPI_QSPI0_PT.
 * To use register names with standard convention, please use OE_TC_SRC_QSPI_QSPI0_PT.
 */
#define OE_TC_SRC_QSPI0PT               (OE_TC_SRC_QSPI_QSPI0_PT)

/** \brief  194, QSPI Receive Service Request */
#define OE_TC_SRC_QSPI_QSPI0_RX         (0x0194U)

/** Alias (User Manual Name) for OE_TC_SRC_QSPI_QSPI0_RX.
 * To use register names with standard convention, please use OE_TC_SRC_QSPI_QSPI0_RX.
 */
#define OE_TC_SRC_QSPI0RX               (OE_TC_SRC_QSPI_QSPI0_RX)

/** \brief  190, QSPI Transmit Service Request */
#define OE_TC_SRC_QSPI_QSPI0_TX         (0x0190U)

/** Alias (User Manual Name) for OE_TC_SRC_QSPI_QSPI0_TX.
 * To use register names with standard convention, please use OE_TC_SRC_QSPI_QSPI0_TX.
 */
#define OE_TC_SRC_QSPI0TX               (OE_TC_SRC_QSPI_QSPI0_TX)

/** \brief  1A4, QSPI User Defined Service Request */
#define OE_TC_SRC_QSPI_QSPI0_U          (0x01A4U)

/** Alias (User Manual Name) for OE_TC_SRC_QSPI_QSPI0_U.
 * To use register names with standard convention, please use OE_TC_SRC_QSPI_QSPI0_U.
 */
#define OE_TC_SRC_QSPI0U                (OE_TC_SRC_QSPI_QSPI0_U)

/** \brief  1B0, QSPI Error Service Request */
#define OE_TC_SRC_QSPI_QSPI1_ERR        (0x01B0U)

/** Alias (User Manual Name) for OE_TC_SRC_QSPI_QSPI1_ERR.
 * To use register names with standard convention, please use OE_TC_SRC_QSPI_QSPI1_ERR.
 */
#define OE_TC_SRC_QSPI1ERR              (OE_TC_SRC_QSPI_QSPI1_ERR)

/** \brief  1B8, QSPI High Speed Capture Service Request */
#define OE_TC_SRC_QSPI_QSPI1_HC         (0x01B8U)

/** Alias (User Manual Name) for OE_TC_SRC_QSPI_QSPI1_HC.
 * To use register names with standard convention, please use OE_TC_SRC_QSPI_QSPI1_HC.
 */
#define OE_TC_SRC_RESERVED11            (OE_TC_SRC_QSPI_QSPI1_HC)

/** \brief  1B4, QSPI Phase Transition Service Request */
#define OE_TC_SRC_QSPI_QSPI1_PT         (0x01B4U)

/** Alias (User Manual Name) for OE_TC_SRC_QSPI_QSPI1_PT.
 * To use register names with standard convention, please use OE_TC_SRC_QSPI_QSPI1_PT.
 */
#define OE_TC_SRC_QSPI1PT               (OE_TC_SRC_QSPI_QSPI1_PT)

/** \brief  1AC, QSPI Receive Service Request */
#define OE_TC_SRC_QSPI_QSPI1_RX         (0x01ACU)

/** Alias (User Manual Name) for OE_TC_SRC_QSPI_QSPI1_RX.
 * To use register names with standard convention, please use OE_TC_SRC_QSPI_QSPI1_RX.
 */
#define OE_TC_SRC_QSPI1RX               (OE_TC_SRC_QSPI_QSPI1_RX)

/** \brief  1A8, QSPI Transmit Service Request */
#define OE_TC_SRC_QSPI_QSPI1_TX         (0x01A8U)

/** Alias (User Manual Name) for OE_TC_SRC_QSPI_QSPI1_TX.
 * To use register names with standard convention, please use OE_TC_SRC_QSPI_QSPI1_TX.
 */
#define OE_TC_SRC_QSPI1TX               (OE_TC_SRC_QSPI_QSPI1_TX)

/** \brief  1BC, QSPI User Defined Service Request */
#define OE_TC_SRC_QSPI_QSPI1_U          (0x01BCU)

/** Alias (User Manual Name) for OE_TC_SRC_QSPI_QSPI1_U.
 * To use register names with standard convention, please use OE_TC_SRC_QSPI_QSPI1_U.
 */
#define OE_TC_SRC_QSPI1U                (OE_TC_SRC_QSPI_QSPI1_U)

/** \brief  1C8, QSPI Error Service Request */
#define OE_TC_SRC_QSPI_QSPI2_ERR        (0x01C8U)

/** Alias (User Manual Name) for OE_TC_SRC_QSPI_QSPI2_ERR.
 * To use register names with standard convention, please use OE_TC_SRC_QSPI_QSPI2_ERR.
 */
#define OE_TC_SRC_QSPI2ERR              (OE_TC_SRC_QSPI_QSPI2_ERR)

/** \brief  1D0, QSPI High Speed Capture Service Request */
#define OE_TC_SRC_QSPI_QSPI2_HC         (0x01D0U)

/** Alias (User Manual Name) for OE_TC_SRC_QSPI_QSPI2_HC.
 * To use register names with standard convention, please use OE_TC_SRC_QSPI_QSPI2_HC.
 */
#define OE_TC_SRC_QSPI2HC               (OE_TC_SRC_QSPI_QSPI2_HC)

/** \brief  1CC, QSPI Phase Transition Service Request */
#define OE_TC_SRC_QSPI_QSPI2_PT         (0x01CCU)

/** Alias (User Manual Name) for OE_TC_SRC_QSPI_QSPI2_PT.
 * To use register names with standard convention, please use OE_TC_SRC_QSPI_QSPI2_PT.
 */
#define OE_TC_SRC_QSPI2PT               (OE_TC_SRC_QSPI_QSPI2_PT)

/** \brief  1C4, QSPI Receive Service Request */
#define OE_TC_SRC_QSPI_QSPI2_RX         (0x01C4U)

/** Alias (User Manual Name) for OE_TC_SRC_QSPI_QSPI2_RX.
 * To use register names with standard convention, please use OE_TC_SRC_QSPI_QSPI2_RX.
 */
#define OE_TC_SRC_QSPI2RX               (OE_TC_SRC_QSPI_QSPI2_RX)

/** \brief  1C0, QSPI Transmit Service Request */
#define OE_TC_SRC_QSPI_QSPI2_TX         (0x01C0U)

/** Alias (User Manual Name) for OE_TC_SRC_QSPI_QSPI2_TX.
 * To use register names with standard convention, please use OE_TC_SRC_QSPI_QSPI2_TX.
 */
#define OE_TC_SRC_QSPI2TX               (OE_TC_SRC_QSPI_QSPI2_TX)

/** \brief  1D4, QSPI User Defined Service Request */
#define OE_TC_SRC_QSPI_QSPI2_U          (0x01D4U)

/** Alias (User Manual Name) for OE_TC_SRC_QSPI_QSPI2_U.
 * To use register names with standard convention, please use OE_TC_SRC_QSPI_QSPI2_U.
 */
#define OE_TC_SRC_QSPI2U                (OE_TC_SRC_QSPI_QSPI2_U)

/** \brief  1E0, QSPI Error Service Request */
#define OE_TC_SRC_QSPI_QSPI3_ERR        (0x01E0U)

/** Alias (User Manual Name) for OE_TC_SRC_QSPI_QSPI3_ERR.
 * To use register names with standard convention, please use OE_TC_SRC_QSPI_QSPI3_ERR.
 */
#define OE_TC_SRC_QSPI3ERR              (OE_TC_SRC_QSPI_QSPI3_ERR)

/** \brief  1E8, QSPI High Speed Capture Service Request */
#define OE_TC_SRC_QSPI_QSPI3_HC         (0x01E8U)

/** Alias (User Manual Name) for OE_TC_SRC_QSPI_QSPI3_HC.
 * To use register names with standard convention, please use OE_TC_SRC_QSPI_QSPI3_HC.
 */
#define OE_TC_SRC_QSPI3HC               (OE_TC_SRC_QSPI_QSPI3_HC)

/** \brief  1E4, QSPI Phase Transition Service Request */
#define OE_TC_SRC_QSPI_QSPI3_PT         (0x01E4U)

/** Alias (User Manual Name) for OE_TC_SRC_QSPI_QSPI3_PT.
 * To use register names with standard convention, please use OE_TC_SRC_QSPI_QSPI3_PT.
 */
#define OE_TC_SRC_QSPI3PT               (OE_TC_SRC_QSPI_QSPI3_PT)

/** \brief  1DC, QSPI Receive Service Request */
#define OE_TC_SRC_QSPI_QSPI3_RX         (0x01DCU)

/** Alias (User Manual Name) for OE_TC_SRC_QSPI_QSPI3_RX.
 * To use register names with standard convention, please use OE_TC_SRC_QSPI_QSPI3_RX.
 */
#define OE_TC_SRC_QSPI3RX               (OE_TC_SRC_QSPI_QSPI3_RX)

/** \brief  1D8, QSPI Transmit Service Request */
#define OE_TC_SRC_QSPI_QSPI3_TX         (0x01D8U)

/** Alias (User Manual Name) for OE_TC_SRC_QSPI_QSPI3_TX.
 * To use register names with standard convention, please use OE_TC_SRC_QSPI_QSPI3_TX.
 */
#define OE_TC_SRC_QSPI3TX               (OE_TC_SRC_QSPI_QSPI3_TX)

/** \brief  1EC, QSPI User Defined Service Request */
#define OE_TC_SRC_QSPI_QSPI3_U          (0x01ECU)

/** Alias (User Manual Name) for OE_TC_SRC_QSPI_QSPI3_U.
 * To use register names with standard convention, please use OE_TC_SRC_QSPI_QSPI3_U.
 */
#define OE_TC_SRC_QSPI3U                (OE_TC_SRC_QSPI_QSPI3_U)

/** \brief  CD0, SCU DTS Busy Service Request */
#define OE_TC_SRC_SCU_SCU_DTS           (0x0CD0U)

/** Alias (User Manual Name) for OE_TC_SRC_SCU_SCU_DTS.
 * To use register names with standard convention, please use OE_TC_SRC_SCU_SCU_DTS.
 */
#define OE_TC_SRC_SCUDTS                (OE_TC_SRC_SCU_SCU_DTS)

/** \brief  CD4, SCU ERU Service Request */
#define OE_TC_SRC_SCU_SCU_ERU0          (0x0CD4U)

/** Alias (User Manual Name) for OE_TC_SRC_SCU_SCU_ERU0.
 * To use register names with standard convention, please use OE_TC_SRC_SCU_SCU_ERU0.
 */
#define OE_TC_SRC_SCUERU0               (OE_TC_SRC_SCU_SCU_ERU0)

/** \brief  CD8, SCU ERU Service Request */
#define OE_TC_SRC_SCU_SCU_ERU1          (0x0CD8U)

/** Alias (User Manual Name) for OE_TC_SRC_SCU_SCU_ERU1.
 * To use register names with standard convention, please use OE_TC_SRC_SCU_SCU_ERU1.
 */
#define OE_TC_SRC_SCUERU1               (OE_TC_SRC_SCU_SCU_ERU1)

/** \brief  CDC, SCU ERU Service Request */
#define OE_TC_SRC_SCU_SCU_ERU2          (0x0CDCU)

/** Alias (User Manual Name) for OE_TC_SRC_SCU_SCU_ERU2.
 * To use register names with standard convention, please use OE_TC_SRC_SCU_SCU_ERU2.
 */
#define OE_TC_SRC_SCUERU2               (OE_TC_SRC_SCU_SCU_ERU2)

/** \brief  CE0, SCU ERU Service Request */
#define OE_TC_SRC_SCU_SCU_ERU3          (0x0CE0U)

/** Alias (User Manual Name) for OE_TC_SRC_SCU_SCU_ERU3.
 * To use register names with standard convention, please use OE_TC_SRC_SCU_SCU_ERU3.
 */
#define OE_TC_SRC_SCUERU3               (OE_TC_SRC_SCU_SCU_ERU3)

/** \brief  350, SENT TRIG Service Request */
#define OE_TC_SRC_SENT_SENT0_SR0        (0x0350U)

/** Alias (User Manual Name) for OE_TC_SRC_SENT_SENT0_SR0.
 * To use register names with standard convention, please use OE_TC_SRC_SENT_SENT0_SR0.
 */
#define OE_TC_SRC_SENT0                 (OE_TC_SRC_SENT_SENT0_SR0)

/** \brief  354, SENT TRIG Service Request */
#define OE_TC_SRC_SENT_SENT0_SR1        (0x0354U)

/** Alias (User Manual Name) for OE_TC_SRC_SENT_SENT0_SR1.
 * To use register names with standard convention, please use OE_TC_SRC_SENT_SENT0_SR1.
 */
#define OE_TC_SRC_SENT1                 (OE_TC_SRC_SENT_SENT0_SR1)

/** \brief  358, SENT TRIG Service Request */
#define OE_TC_SRC_SENT_SENT0_SR2        (0x0358U)

/** Alias (User Manual Name) for OE_TC_SRC_SENT_SENT0_SR2.
 * To use register names with standard convention, please use OE_TC_SRC_SENT_SENT0_SR2.
 */
#define OE_TC_SRC_SENT2                 (OE_TC_SRC_SENT_SENT0_SR2)

/** \brief  35C, SENT TRIG Service Request */
#define OE_TC_SRC_SENT_SENT0_SR3        (0x035CU)

/** Alias (User Manual Name) for OE_TC_SRC_SENT_SENT0_SR3.
 * To use register names with standard convention, please use OE_TC_SRC_SENT_SENT0_SR3.
 */
#define OE_TC_SRC_SENT3                 (OE_TC_SRC_SENT_SENT0_SR3)

/** \brief  D10, SMU Service Request */
#define OE_TC_SRC_SMU_SMU0_SR0          (0x0D10U)

/** Alias (User Manual Name) for OE_TC_SRC_SMU_SMU0_SR0.
 * To use register names with standard convention, please use OE_TC_SRC_SMU_SMU0_SR0.
 */
#define OE_TC_SRC_SMU0                  (OE_TC_SRC_SMU_SMU0_SR0)

/** \brief  D14, SMU Service Request */
#define OE_TC_SRC_SMU_SMU0_SR1          (0x0D14U)

/** Alias (User Manual Name) for OE_TC_SRC_SMU_SMU0_SR1.
 * To use register names with standard convention, please use OE_TC_SRC_SMU_SMU0_SR1.
 */
#define OE_TC_SRC_SMU1                  (OE_TC_SRC_SMU_SMU0_SR1)

/** \brief  D18, SMU Service Request */
#define OE_TC_SRC_SMU_SMU0_SR2          (0x0D18U)

/** Alias (User Manual Name) for OE_TC_SRC_SMU_SMU0_SR2.
 * To use register names with standard convention, please use OE_TC_SRC_SMU_SMU0_SR2.
 */
#define OE_TC_SRC_SMU2                  (OE_TC_SRC_SMU_SMU0_SR2)

/** \brief  490, System Timer  Service Request 0 */
#define OE_TC_SRC_STM_STM0_SR0          (0x0490U)

/** Alias (User Manual Name) for OE_TC_SRC_STM_STM0_SR0.
 * To use register names with standard convention, please use OE_TC_SRC_STM_STM0_SR0.
 */
#define OE_TC_SRC_STM0SR0               (OE_TC_SRC_STM_STM0_SR0)

/** \brief  494, System Timer  Service Request 1 */
#define OE_TC_SRC_STM_STM0_SR1          (0x0494U)

/** Alias (User Manual Name) for OE_TC_SRC_STM_STM0_SR1.
 * To use register names with standard convention, please use OE_TC_SRC_STM_STM0_SR1.
 */
#define OE_TC_SRC_STM0SR1               (OE_TC_SRC_STM_STM0_SR1)

/** \brief  AA0, VADC Common Group  Service Request 0 */
#define OE_TC_SRC_VADC_CG0_SR0          (0x0AA0U)

/** Alias (User Manual Name) for OE_TC_SRC_VADC_CG0_SR0.
 * To use register names with standard convention, please use OE_TC_SRC_VADC_CG0_SR0.
 */
#define OE_TC_SRC_VADCCG0SR0            (OE_TC_SRC_VADC_CG0_SR0)

/** \brief  AA4, VADC Common Group  Service Request 1 */
#define OE_TC_SRC_VADC_CG0_SR1          (0x0AA4U)

/** Alias (User Manual Name) for OE_TC_SRC_VADC_CG0_SR1.
 * To use register names with standard convention, please use OE_TC_SRC_VADC_CG0_SR1.
 */
#define OE_TC_SRC_VADCCG0SR1            (OE_TC_SRC_VADC_CG0_SR1)

/** \brief  AA8, VADC Common Group  Service Request 2 */
#define OE_TC_SRC_VADC_CG0_SR2          (0x0AA8U)

/** Alias (User Manual Name) for OE_TC_SRC_VADC_CG0_SR2.
 * To use register names with standard convention, please use OE_TC_SRC_VADC_CG0_SR2.
 */
#define OE_TC_SRC_VADCCG0SR2            (OE_TC_SRC_VADC_CG0_SR2)

/** \brief  AAC, VADC Common Group  Service Request 3 */
#define OE_TC_SRC_VADC_CG0_SR3          (0x0AACU)

/** Alias (User Manual Name) for OE_TC_SRC_VADC_CG0_SR3.
 * To use register names with standard convention, please use OE_TC_SRC_VADC_CG0_SR3.
 */
#define OE_TC_SRC_VADCCG0SR3            (OE_TC_SRC_VADC_CG0_SR3)

/** \brief  980, VADC Group  Service Request 0 */
#define OE_TC_SRC_VADC_G0_SR0           (0x0980U)

/** Alias (User Manual Name) for OE_TC_SRC_VADC_G0_SR0.
 * To use register names with standard convention, please use OE_TC_SRC_VADC_G0_SR0.
 */
#define OE_TC_SRC_VADCG0SR0             (OE_TC_SRC_VADC_G0_SR0)

/** \brief  984, VADC Group  Service Request 1 */
#define OE_TC_SRC_VADC_G0_SR1           (0x0984U)

/** Alias (User Manual Name) for OE_TC_SRC_VADC_G0_SR1.
 * To use register names with standard convention, please use OE_TC_SRC_VADC_G0_SR1.
 */
#define OE_TC_SRC_VADCG0SR1             (OE_TC_SRC_VADC_G0_SR1)

/** \brief  988, VADC Group  Service Request 2 */
#define OE_TC_SRC_VADC_G0_SR2           (0x0988U)

/** Alias (User Manual Name) for OE_TC_SRC_VADC_G0_SR2.
 * To use register names with standard convention, please use OE_TC_SRC_VADC_G0_SR2.
 */
#define OE_TC_SRC_VADCG0SR2             (OE_TC_SRC_VADC_G0_SR2)

/** \brief  98C, VADC Group  Service Request 3 */
#define OE_TC_SRC_VADC_G0_SR3           (0x098CU)

/** Alias (User Manual Name) for OE_TC_SRC_VADC_G0_SR3.
 * To use register names with standard convention, please use OE_TC_SRC_VADC_G0_SR3.
 */
#define OE_TC_SRC_VADCG0SR3             (OE_TC_SRC_VADC_G0_SR3)

/** \brief  990, VADC Group  Service Request 0 */
#define OE_TC_SRC_VADC_G1_SR0           (0x0990U)

/** Alias (User Manual Name) for OE_TC_SRC_VADC_G1_SR0.
 * To use register names with standard convention, please use OE_TC_SRC_VADC_G1_SR0.
 */
#define OE_TC_SRC_VADCG1SR0             (OE_TC_SRC_VADC_G1_SR0)

/** \brief  994, VADC Group  Service Request 1 */
#define OE_TC_SRC_VADC_G1_SR1           (0x0994U)

/** Alias (User Manual Name) for OE_TC_SRC_VADC_G1_SR1.
 * To use register names with standard convention, please use OE_TC_SRC_VADC_G1_SR1.
 */
#define OE_TC_SRC_VADCG1SR1             (OE_TC_SRC_VADC_G1_SR1)

/** \brief  998, VADC Group  Service Request 2 */
#define OE_TC_SRC_VADC_G1_SR2           (0x0998U)

/** Alias (User Manual Name) for OE_TC_SRC_VADC_G1_SR2.
 * To use register names with standard convention, please use OE_TC_SRC_VADC_G1_SR2.
 */
#define OE_TC_SRC_VADCG1SR2             (OE_TC_SRC_VADC_G1_SR2)

/** \brief  99C, VADC Group  Service Request 3 */
#define OE_TC_SRC_VADC_G1_SR3           (0x099CU)

/** Alias (User Manual Name) for OE_TC_SRC_VADC_G1_SR3.
 * To use register names with standard convention, please use OE_TC_SRC_VADC_G1_SR3.
 */
#define OE_TC_SRC_VADCG1SR3             (OE_TC_SRC_VADC_G1_SR3)

/** \brief  9A0, VADC Group  Service Request 0 */
#define OE_TC_SRC_VADC_G2_SR0           (0x09A0U)

/** Alias (User Manual Name) for OE_TC_SRC_VADC_G2_SR0.
 * To use register names with standard convention, please use OE_TC_SRC_VADC_G2_SR0.
 */
#define OE_TC_SRC_VADCG2SR0             (OE_TC_SRC_VADC_G2_SR0)

/** \brief  9A4, VADC Group  Service Request 1 */
#define OE_TC_SRC_VADC_G2_SR1           (0x09A4U)

/** Alias (User Manual Name) for OE_TC_SRC_VADC_G2_SR1.
 * To use register names with standard convention, please use OE_TC_SRC_VADC_G2_SR1.
 */
#define OE_TC_SRC_VADCG2SR1             (OE_TC_SRC_VADC_G2_SR1)

/** \brief  9A8, VADC Group  Service Request 2 */
#define OE_TC_SRC_VADC_G2_SR2           (0x09A8U)

/** Alias (User Manual Name) for OE_TC_SRC_VADC_G2_SR2.
 * To use register names with standard convention, please use OE_TC_SRC_VADC_G2_SR2.
 */
#define OE_TC_SRC_VADCG2SR2             (OE_TC_SRC_VADC_G2_SR2)

/** \brief  9AC, VADC Group  Service Request 3 */
#define OE_TC_SRC_VADC_G2_SR3           (0x09ACU)

/** Alias (User Manual Name) for OE_TC_SRC_VADC_G2_SR3.
 * To use register names with standard convention, please use OE_TC_SRC_VADC_G2_SR3.
 */
#define OE_TC_SRC_VADCG2SR3             (OE_TC_SRC_VADC_G2_SR3)

/** \brief  9B0, VADC Group  Service Request 0 */
#define OE_TC_SRC_VADC_G3_SR0           (0x09B0U)

/** Alias (User Manual Name) for OE_TC_SRC_VADC_G3_SR0.
 * To use register names with standard convention, please use OE_TC_SRC_VADC_G3_SR0.
 */
#define OE_TC_SRC_VADCG3SR0             (OE_TC_SRC_VADC_G3_SR0)

/** \brief  9B4, VADC Group  Service Request 1 */
#define OE_TC_SRC_VADC_G3_SR1           (0x09B4U)

/** Alias (User Manual Name) for OE_TC_SRC_VADC_G3_SR1.
 * To use register names with standard convention, please use OE_TC_SRC_VADC_G3_SR1.
 */
#define OE_TC_SRC_VADCG3SR1             (OE_TC_SRC_VADC_G3_SR1)

/** \brief  9B8, VADC Group  Service Request 2 */
#define OE_TC_SRC_VADC_G3_SR2           (0x09B8U)

/** Alias (User Manual Name) for OE_TC_SRC_VADC_G3_SR2.
 * To use register names with standard convention, please use OE_TC_SRC_VADC_G3_SR2.
 */
#define OE_TC_SRC_VADCG3SR2             (OE_TC_SRC_VADC_G3_SR2)

/** \brief  9BC, VADC Group  Service Request 3 */
#define OE_TC_SRC_VADC_G3_SR3           (0x09BCU)

/** Alias (User Manual Name) for OE_TC_SRC_VADC_G3_SR3.
 * To use register names with standard convention, please use OE_TC_SRC_VADC_G3_SR3.
 */
#define OE_TC_SRC_VADCG3SR3             (OE_TC_SRC_VADC_G3_SR3)

/** \brief  48, XBAR_SRI Service Request */
#define OE_TC_SRC_XBAR_XBAR_SRC         (0x0048U)

/** Alias (User Manual Name) for OE_TC_SRC_XBAR_XBAR_SRC.
 * To use register names with standard convention, please use OE_TC_SRC_XBAR_XBAR_SRC.
 */
#define OE_TC_SRC_XBARSRC               (OE_TC_SRC_XBAR_XBAR_SRC)

/******************************************************************************/
/******************************************************************************/
#endif /* OE_TC_SRC_H */
