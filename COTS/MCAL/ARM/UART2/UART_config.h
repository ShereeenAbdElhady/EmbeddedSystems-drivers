/***********************************************************************************/
/*                                                                                */
/* File Name   : UART_config.h                                                   */
/*                                                                              */
/* Created on  : May 13, 2019                                                  */
/*                                                                            */
/* Author      : shereen Abd Elhady                                          */
/*                                                                          */
/* Version     : V01                                                       */
/*                                                                        */
/* Description : configuration file for UART driver includes             */
/*               Basic private and public configurations                */
/*               for STM32F103C8 ARM microcontroller                   */
/*                                                                    */
/* Layer       : MCAL                                                */
/********************************************************************/


#ifndef UART_CONFIG_H_
#define UART_CONFIG_H_

/*the configurator will configure the UART initial state according to his desire      */
/*Range:   UART_u8_ENABLE                                                             */
/*         UART_u8_DISABLE                                                            */
#define UART_u8_INIT_STATE         UART_u8_ENABLE

/*the configurator will configure the word size according to his desire               */
/*Range:   UART_u8_8BITS_DATA                                                         */
/*         UART_u8_9BITS_DATA                                                         */
#define UART_u8_DATA_WORD_LENGTH   UART_u8_8BITS_DATA

/*the configurator will configure the parity control according to his desire          */
/*Range:   UART_u8_PARITY_ENABLE                                                      */
/*         UART_u8_PARITY_DISABLE                                                     */
#define UART_u8_PARITY_CONTROL   UART_u8_PARITY_DISABLE

/*the configurator r will configure the parity selection according to his desire      */
/*Range:   UART_u8_ODD_PARITY                                                         */
/*         UART_u8_EVEN_PARITY                                                        */
#define UART_u8_PARITY_SELECTION  UART_u8_ODD_PARITY

/*the configurator will configure the number of stop bits according to his desire     */
/*Range:   UART_u8_1_STOP_BIT                                                         */
/*         UART_u8_0_5_STOP_BIT                                                       */
/*         UART_u8_2_STOP_BIT                                                         */
/*         UART_u8_1_5_STOP_BIT                                                       */
#define UART_u8_STOP_BITS       UART_u8_1_STOP_BIT

/*to avoid being stuck in a loop during polling                                       */
#define UART_u8_TIMEOUT_POLLING   (u16)10000

/*The configuartor will configure the UART baud rate according to the customer desire */
#define UART_u32_BAUD_RATE         (u32)9600

/*the configurator will configure the clock frequency of the Microcontroller          */
#define UART_u32_CPU_FREQUENCY_HZ  (u32)8000000


#endif /* UART_CONFIG_H_ */
