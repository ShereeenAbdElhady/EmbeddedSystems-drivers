/*****************************************************************************************************/
/*                                                                                                  */
/* File Name   : UART_private.h                                                                    */
/*                                                                                                */
/* Created on  : May 13, 2019                                                                    */
/*                                                                                              */
/* Author      : shereen Abd Elhady                                                            */
/*                                                                                            */
/* Version     : V01                                                                         */
/*                                                                                          */
/* Description : Private header file for UART driver contains Registers address definitions*/
/*               of STM32F103C8 ARM Micro-Controller.                                     */
/*               Also contains private functions' prototypes                             */
/*               And the MACROS not needed by the upper layers' components.             */
/* Layer        : MCAL                                                                 */
/*                                                                                    */
/*************************************************************************************/


#ifndef UART_PRIVATE_H_
#define UART_PRIVATE_H_

                     /*********** UART2 Addresses definitions ************/
/*UART status register address definition (UART2 Base address = 0x40004400) (SR offset = 0x00)                 */
#define UART_u32_SR  *((volatile u32*)0x40004400)

/*UART data register address definition (UART2 Base address = 0x40004400) (DR offset = 0x04)                   */
#define UART_u32_DR  *((volatile u32*)0x40004404)

/*UART baud rate register address definition (UART2 Base address = 0x40004400) (DR offset = 0x08)              */
#define UART_u32_BRR  *((volatile u32*)0x40004408)

/*UART control register 1 address definition (UART2 Base address = 0x40004400) (DR offset = 0x0C)              */
#define UART_u32_CR1  *((volatile u32*)0x4000440C)

/*UART control register 2 address definition (UART2 Base address = 0x40004400) (DR offset = 0x10)              */
#define UART_u32_CR2  *((volatile u32*)0x40004410)

/*UART control register 3 address definition (UART2 Base address = 0x40004400) (DR offset = 0x14)              */
#define UART_u32_CR3  *((volatile u32*)0x40004414)

/*UART guard time & prescaler  register address definition (UART2 Base address = 0x40004400) (DR offset = 0x18)*/
#define UART_u32_GTPR  *((volatile u32*)0x40004418)


                   /*************** UART_CR1 register PINs definitions ************/
#define UART_CR1_UE_PIN        (u8)13
#define UART_CR1_M_PIN         (u8)12
#define UART_CR1_PCE_PIN       (u8)10
#define UART_CR1_PS_PIN        (u8)9
#define UART_CR1_u8_TXEIE_PIN  (u8)7
#define UART_CR1_u8_RXNEIE_PIN (u8)5
#define UART_CR1_u8_TE_PIN     (u8)3
#define UART_CR1_u8_RE_PIN     (u8)2

                  /*************** UART_CR2 register PINs definitions ************/
#define UART_CR2_STOP_PIN0    (u8)12
#define UART_CR2_STOP_PIN1    (u8)13

                 /*************** UART_SR register PINs definitions ************/
#define UART_SR_TXE_PIN       (u8)7
#define UART_SR_RXNE_PIN      (u8)5

/* UART enable & disable definitions                                                                           */
#define UART_u8_ENABLE  (u8)1
#define UART_u8_DISABLE (u8)0

/*word length definition                                                                                       */
#define UART_u8_8BITS_DATA   20
#define UART_u8_9BITS_DATA   22

/*Enable & disable parity definitions                                                                          */
#define UART_u8_PARITY_ENABLE  23
#define UART_u8_PARITY_DISABLE 24

/*Even & odd parity definitions                                                                                */
#define UART_u8_ODD_PARITY     25
#define UART_u8_EVEN_PARITY    26

/*Number of stop bits definitions                                                                              */
#define UART_u8_1_STOP_BIT     27
#define UART_u8_0_5_STOP_BIT   28
#define UART_u8_2_STOP_BIT     29
#define UART_u8_1_5_STOP_BIT   30
/*Pointers to function numbers definition */
#define UART_NUM_OF_INTERRUPTS  2
/*Tx ptr index                            */
#define UART_u8_INDEX_TX        0
/*Rx ptr index                            */
#define UART_u8_INDEX_RX        1

                     /******* private functions prototypes *************/

/****************************************************************************************************
* Description:Function to Set the pointer to callback function with the address of the function
*              Needed to be implemented by the ISR.
* Outputs   : Error State
* Inputs    : void (*Copy_PVidFunCallback) (void): pointer to callback function to set the pointer
*             Value with the address of the function needed to be implemented by the ISR.
*             Copy_u8INTNb             : Interrupt Index number
***************************************************************************************************/
static u8 UART_u8SetCallback (u8 Copy_u8INTIndex , void (*Copy_PVidFunCallback) (void));


/*******************************************************************************
 * Description: private function to disable the transmission complete interrupt.
 * Outputs   : None
 * Inputs    : None
 ******************************************************************************/
static void UART_VidDisableTXEInterrupt (void);

/*******************************************************************************
 * Description: private function to disable the read data register
 *              not empty interrupt.
 * Outputs   : None
 * Inputs    : None
 ******************************************************************************/
static void UART_VidDisableRXNEInterrupt (void);


/*******************************************************************************
 * Description: private function to enable the transmission complete interrupt.
 * Outputs   : None
 * Inputs    : None
 ******************************************************************************/
static void UART_VidEnableTXEInterrupt (void);


/*******************************************************************************
 * Description: private function to enable the read data register
 *              not empty interrupt.
 * Outputs   : None
 * Inputs    : None
 ******************************************************************************/
static void UART_VidEnableRXNEInterrupt (void);

#endif /* UART_PRIVATE_H_ */
