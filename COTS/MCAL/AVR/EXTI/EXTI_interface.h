/***********************************************************************************/
/*                                                                                */
/* File Name   : EXTI_interface.h                                                */
/*                                                                              */
/* Created on  : Mar 24, 2019                                                  */
/*                                                                            */
/* Author      : shereen Abd Elhady                                          */
/*                                                                          */
/* Version     : V01                                                       */
/*                                                                        */
/* Description : Interface file for external interrupt driver includes   */
/*                                                                      */
/*               APIs' prototypes And MACROS for call                  */
/*                                                                    */
/* Layer       : MCAL                                                */
/*                                                                  */
/*******************************************************************/

#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

/* 	The interface file includes only the Public configurations from the configuration file */
#include "EXTI_config.h"

/* External Interrupts index definitions                                                   */
#define EXTI_u8_INT0 (u8)0
#define EXTI_u8_INT1 (u8)1
#define EXTI_u8_INT2 (u8)2

/* External Interrupts Sense levels definitions                                            */
#define EXTI_u8_LOW_LEVEL          (u8)0
#define EXTI_u8_ANY_LOGICAL_CHANGE (u8)1
#define EXTI_u8_FALLING_EDGE       (u8)2
#define EXTI_u8_RISING_EDGE        (u8)3


/****************************************************************************************************
 * Description:Function to Set the pointer to callback function with the address of the function
 *              Needed to be implemented by the ISR.
 * Outputs   : Error State
 * Inputs    : void (*Copy_PVidFunCallback) (void): pointer to callback function to set the pointer
 *             Value with the address of the function needed to be implemented by the ISR.
 *             Copy_u8INTNb             : Interrupt Index number
 ***************************************************************************************************/
u8 EXTI_u8SetCallback (u8 Copy_u8INTNb , void (*Copy_PVidFunCallback) (void));


/****************************************************************************************************
 * Description:External INT0 Interrupt Service Routine which includes a pointer points to a function
 *             Send by user to be implemented.
 * Outputs    :Error State
 * Inputs     :None
 ***************************************************************************************************/
void __vector_1 (void) __attribute__((signal));


/****************************************************************************************************
 * Description:External INT1 Interrupt Service Routine which includes a pointer points to a function
 *             Send by user to be implemented.
 * Outputs    :Error State
 * Inputs     :None
 ***************************************************************************************************/
void __vector_2 (void) __attribute__((signal));


/****************************************************************************************************
 * Description:External INT2 Interrupt Service Routine which includes a pointer points to a function
 *             Send by user to be implemented.
 * Outputs    :Error State
 * Inputs     :None
 ***************************************************************************************************/
void __vector_3 (void) __attribute__((signal));


/****************************************************************************************************
 * Description:Function to Set the peripheral interrupt enable
 * Outputs   : Error State
 * Inputs    : Copy_u8INTNb             : Interrupt Index number
 ***************************************************************************************************/
u8 EXTI_u8PeripheralInterruptEnable (u8 Copy_u8INTIndex);


/****************************************************************************************************
 * Description:Function to clear the peripheral interrupt enable (PIE)
 * Outputs   : Error State
 * Inputs    : Copy_u8INTNb             : Interrupt Index number
 ***************************************************************************************************/
u8 EXTI_u8PeripheralInterruptDisable (u8 Copy_u8INTIndex);


/****************************************************************************************************
 * Description:Function to set the interrupt sense level whether it is
 *             Low Level , Rising edge , Falling edge , on change.
 * Outputs   : Error State
 * Inputs    : Copy_u8INTNb             : Interrupt Index number
 *             Copy_u8SenseLevel        : interrupt sense level
 ***************************************************************************************************/
u8 EXTI_u8SetSenseLevel (u8 Copy_u8INTIndex , u8 Copy_u8SenseLevel);


/****************************************************************************************************
 * Description:External INT initialization function which initialize the PIE state and sense level
 * Outputs    :None
 * Inputs     :None
 ***************************************************************************************************/
void EXTI_VidInitialize(void);


#endif /* EXTI_INTERFACE_H_ */
