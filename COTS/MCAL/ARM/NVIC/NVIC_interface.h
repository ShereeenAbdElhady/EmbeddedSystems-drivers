/***********************************************************************************/
/*                                                                                */
/* File Name   : NVIC_interface.h                                                */
/*                                                                              */
/* Created on  : Mar 28, 2019                                                  */
/*                                                                            */
/* Author      : shereen Abd Elhady                                          */
/*                                                                          */
/* Version     : V01                                                       */
/*                                                                        */
/* Description :Interface file for NVIC driver includes APIs' prototypes */
/*              And MACROS for call  for STM32F103C8 ARM microcontroller*/
/*                                                                     */
/* Layer       : MCAL                                                 */
/*********************************************************************/


#ifndef NVIC_INTERFACE_H_
#define NVIC_INTERFACE_H_


/* 	The interface file includes only the Public configurations from the configuration file */
#include "NVIC_config.h"

/* Definitions of interrupt enable and disable        */
#define NVIC_u8_INTERRUPT_ENABLE      (u8)1
#define NVIC_u8_INTERRUPT_DISABLE     (u8)0

/* Definitions of interrupt pending and not pending   */
#define NVIC_u8_INTERRUPT_PENDING     (u8)1
#define NVIC_u8_INTERRUPT_NOT_PENDING (u8)0

/* External interrupts positions' definitions         */
#define NVIC_u8_EXTI0_INDEX           (u8)6
#define NVIC_u8_EXTI1_INDEX           (u8)7
#define NVIC_u8_EXTI2_INDEX           (u8)8
#define NVIC_u8_EXTI3_INDEX           (u8)9
#define NVIC_u8_EXTI4_INDEX           (u8)10

/* External interrupts priorities definitions         */
#define NVIC_u8_EXTI0_PRIORITY        (u8)13
#define NVIC_u8_EXTI1_PRIORITY        (u8)20
#define NVIC_u8_EXTI2_PRIORITY        (u8)15
#define NVIC_u8_EXTI3_PRIORITY        (u8)16
#define NVIC_u8_EXTI4_PRIORITY        (u8)17



/*********************************** APIs Prototypes ************************************/


/**************************************************************************************************
 * Description: Function to Set or clear interrupt enable through NVIC_ISER & NVIC_ICER Registers.
 * Outputs   :                   Error State
 * Inputs    : u8 Copy_u8InterruptNumber:  Interrupt Number
 *             Copy_u8InterruptStatus   : Interrupt status whether it is enabled or disabled.
 **************************************************************************************************/
u8 NVIC_u8SetClearInterruptEnable (u8 Copy_u8InterruptNumber , u8 Copy_u8InterruptStatus);


/*******************************************************************************************************
 * Description: Function to Set or clear interrupt pending flag through NVIC_ISPR & NVIC_ICPR Registers.
 * Outputs   :                   Error State
 * Inputs    : u8 Copy_u8InterruptNumber:  Interrupt Number
 *             Copy_u8PendingStatus   : Interrupt pending status whether it is pending or not.
 ********************************************************************************************************/
u8 NVIC_u8SetClearInterruptPending (u8 Copy_u8InterruptNumber , u8 Copy_u8PendingStatus);


/**************************************************************************************************
 * Description: Function to Select the interrupt priority through NVIC_IPR Registers.
 * Outputs   :                   Error State
 * Inputs    : u8 Copy_u8InterruptNumber:   Interrupt Number
 *             Copy_u8InterruptPriority   : Interrupt Priority.
 **************************************************************************************************/
u8 NVIC_u8SetInterruptPriority (u8 Copy_u8InterruptNumber , u8 Copy_u8InterruptPriority);


#endif /* NVIC_INTERFACE_H_ */
