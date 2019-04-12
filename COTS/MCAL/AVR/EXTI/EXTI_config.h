/**********************************************************************************************/
/*                                                                                           */
/* File Name   : EXTI_config.h                                                              */
/*                                                                                         */
/* Created on  : Mar 24, 2019                                                             */
/*                                                                                       */
/* Author      : shereen Abd Elhady                                                     */
/*                                                                                     */
/* Version     : V01                                                                  */
/*                                                                                   */
/* Description : configuration file for External interrupts driver contains         */
/*               the initial conditions which initiates the external interrupt     */
/*               driver according to the customer desire                          */
/*                                                                               */
/* Layer       : MCAL                                                           */
/*******************************************************************************/


/**************************Public Configurations **********************************/
/* The first preprocessor guard is for the Public configurations which will be included in the interface file */
#ifndef EXTI_PUBLIC_CONFIG_H_
#ifdef  EXTI_INTERFACE_H_
#define EXTI_PUBLIC_CONFIG_H_




#endif     /* EXTI_INTERFACE_H_ */
#endif     /* EXTI_PUBLIC_CONFIG_H_ */



          /**************************Private Configurations **********************************/
/* The second preprocessor guard is for the Private configurations which will be included in the private file */
#ifndef EXTI_PRIVATEC_CONFIG_H_
#ifdef  EXTI_PRIVATE_H_
#define EXTI_PRIVATE_CONFIG_H_


/* Array contains the interrupts state according to the customer desire       */
/* Range : EXTI_u8_PIE_ENABLE                                                 */
/*         EXTI_u8_PIE_DISABLE                                                */
u8 EXTI_Au8State[EXTI_NUM_OF_INTERRUPTS]  = { EXTI_u8_PIE_ENABLE , EXTI_u8_PIE_DISABLE , EXTI_u8_PIE_DISABLE };


/* Array contains the interrupts sense level according to the customer desire */
/* Range : EXTI_u8_LOW_LEVEL                                                  */
/*         EXTI_u8_ANY_LOGICAL_CHANGE                                         */
/*         EXTI_u8_FALLING_EDGE                                               */
/*         EXTI_u8_RISING_EDGE                                                */
u8 EXTI_Au8SenseLevel[EXTI_NUM_OF_INTERRUPTS]  = { EXTI_u8_RISING_EDGE , EXTI_u8_FALLING_EDGE , EXTI_u8_FALLING_EDGE };


#endif    /* EXTI_PRIVATE_H_ */
#endif   /* EXTI_PRIVATE_CONFIG_H_ */

