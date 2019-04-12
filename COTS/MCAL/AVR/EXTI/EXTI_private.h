/*****************************************************************************************************/
/*                                                                                                  */
/* File Name   : EXTI_private.h                                                                    */
/*                                                                                                */
/* Created on  :  Mar 24, 2019                                                                   */
/*                                                                                              */
/* Author      : shereen Abd Elhady                                                            */
/*                                                                                            */
/* Version     : V01                                                                         */
/*                                                                                          */
/* Description : Private header file for External interrupts                               */
/*               driver contains Registers address definitions                            */
/*               of AVR Atmega32 Micro-Controller.                                       */
/*               Also contains private functions' prototypes                            */
/*               And the MACROS not needed by the upper layers' components.            */
/* Layer        : MCAL                                                                */
/*                                                                                   */
/************************************************************************************/

#ifndef EXTI_PRIVATE_H_
#define EXTI_PRIVATE_H_

/* Number of External Interrupts definitions INT0 , INT1 , INT2 */
#define EXTI_NUM_OF_INTERRUPTS (u8)3

/* Peripheral interrupt enable and disable definitions          */
#define EXTI_u8_PIE_ENABLE     (u8)1
#define EXTI_u8_PIE_DISABLE    (u8)0

/* 	The Private file includes only the Private configurations from the configuration file */
#include "EXTI_config.h"



/* External Interrupts index definitions                        */
#define EXTI_u8_INDEX_INT0     (u8)0
#define EXTI_u8_INDEX_INT1     (u8)1
#define EXTI_u8_INDEX_INT2     (u8)2


/* SREG (Status Register ) Address definition                   */
#define MCU_u8_SREG    ((Register*) 0x5F)->ByteAccess

/* GICR (General interrupt Control Register) Address definition */
#define EXTI_u8_GICR   ((Register*) 0x5B)->ByteAccess

/* MCUCR (MCU Control Register) Address definition              */
#define EXTI_u8_MCUCR  ((Register*) 0x55)->ByteAccess

/* MCUCSR (MCU Control & Status Register) Address definition    */
#define EXTI_u8_MCUCSR ((Register*) 0x54)->ByteAccess


/* SREG (Status Register ) Bits definitions                     */
#define MCU_u8_SREG_I_BIT  (u8)7

/* GICR (General interrupt Control Register) Bits definitions   */
#define EXTI_u8_GICR_INT2_BIT (u8)5
#define EXTI_u8_GICR_INT0_BIT (u8)6
#define EXTI_u8_GICR_INT1_BIT (u8)7

/* MCUCR (MCU Control Register) Bits definitions                */

/* For External Interrupt 0 INT0                                */
#define EXTI_u8_MCUCR_ISC00_BIT (u8)0
#define EXTI_u8_MCUCR_ISC01_BIT (u8)1
/* For External Interrupt 1 INT1                                */
#define EXTI_u8_MCUCR_ISC10_BIT (u8)2
#define EXTI_u8_MCUCR_ISC11_BIT (u8)3


/* MCUCSR (MCU Control and status Register) Bits definitions    */
/* For External Interrupt 2 INT2                                */
#define EXTI_u8_MCUCSR_ISC2_BIT (u8)6


#endif /* EXTI_PRIVATE_H_ */
