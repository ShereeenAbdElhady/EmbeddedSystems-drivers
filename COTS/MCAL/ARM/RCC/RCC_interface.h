/***********************************************************************************/
/*                                                                                */
/* File Name   : RCC_interface.h                                                 */
/*                                                                              */
/* Created on  : Mar 5, 2019                                                   */
/*                                                                            */
/* Author      : shereen Abd Elhady                                          */
/*                                                                          */
/* Version     : V02                                                       */
/*                                                                        */
/* Description : Interface file for RCC driver includes APIs' prototypes */
/*              And MACROS for call  for STM32F103C8 ARM microcontroller*/
/*                                                                     */
/* Layer       : MCAL                                                 */
/*********************************************************************/


#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_

/* 	The interface file includes only the Public configurations from the configuration file */
#include "RCC_config.h"


/* Peripherals to be enabled definitions */
#define RCC_u8_GPIOA  (u8)0
#define RCC_u8_GPIOB  (u8)1
#define RCC_u8_GPIOC  (u8)2
#define RCC_u8_GPIOD  (u8)3
#define RCC_u8_UART2  (u8)4
#define RCC_u8_AFIO   (u8)5

/* clock state definitions               */
#define RCC_u8_ENABLE_CLK  (u8)1
#define RCC_u8_DISABLE_CLK (u8)0


        /*********************************** APIs Prototypes ************************************/

/*********************************************************************************
 * Description:Function to initialize the clock & reset registers
 * Outputs   : None
 * Inputs    : None
 ********************************************************************************/
void RCC_vidinit(void);

/*********************************************************************************
 * Description:Function to enable the peripheral clock
 * Outputs   : Error State
 * Inputs    : Copy_u8State       : The clock state whether it is enabled or disabled
 *             Copy_u8Peripheral: The  peripheral we want to enable
 *********************************************************************************/
u8 RCC_u8EnablePeripheralClock(u8 Copy_u8Peripheral , u8 Copy_u8State);

#endif /* RCC_INTERFACE_H_ */
