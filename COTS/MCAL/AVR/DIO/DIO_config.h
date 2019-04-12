/**********************************************************************************************/
/*                                                                                           */
/* File Name   : DIO_config.h                                                               */
/*                                                                                         */
/* Created on  : Jan 31, 2019                                                             */
/*                                                                                       */
/* Author      : shereen Abd Elhady                                                     */
/*                                                                                     */
/* Version     : V01                                                                  */
/*                                                                                   */
/* Description : configuration file for DIO driver contains                         */
/*               the initial conditions for all micro-controller pins              */
/*               which initiates the DIO driver according to the customer desire  */
/*                                                                               */
/* Layer       : MCAL                                                           */
/*******************************************************************************/


            /**************************Public Configurations **********************************/
/* The first preprocessor guard is for the Public configurations which will be included in the interface file */
#ifndef DIO_PUBLIC_CONFIG_H_
#ifdef  DIO_INTERFACE_H_
#define DIO_PUBLIC_CONFIG_H_




#endif     /* DIO_INTERFACE_H_ */
#endif     /* DIO_PUBLIC_CONFIG_H_ */


          /**************************Private Configurations **********************************/
/* The second preprocessor guard is for the Private configurations which will be included in the private file */
#ifndef DIO_PRIVATEC_CONFIG_H_
#ifdef  DIO_PRIVATE_H_
#define DIO_PRIVATE_CONFIG_H_

/* The customer configures the internal resistance according to his desire  */
/* whether it is gonna be internal pull up or floating                      */
#define DIO_u8_INTERNAL_RESISTANCE_STATE   DIO_u8_INTERNAL_PULL_UP


/* Comment : Initial direction for DIO PINs  */
/* Range   : DIO_u8_PIN_INIT_INPUT          */
/*           DIO_u8_PIN_INIT_OUTPUT        */

/* Initialization of the direction of each PIN */
#define DIO_u8_PIN0_INIT_DIR   DIO_u8_PIN_INIT_INPUT
#define DIO_u8_PIN1_INIT_DIR   DIO_u8_PIN_INIT_OUTPUT
#define DIO_u8_PIN2_INIT_DIR   DIO_u8_PIN_INIT_OUTPUT
#define DIO_u8_PIN3_INIT_DIR   DIO_u8_PIN_INIT_OUTPUT
#define DIO_u8_PIN4_INIT_DIR   DIO_u8_PIN_INIT_OUTPUT
#define DIO_u8_PIN5_INIT_DIR   DIO_u8_PIN_INIT_OUTPUT
#define DIO_u8_PIN6_INIT_DIR   DIO_u8_PIN_INIT_OUTPUT
#define DIO_u8_PIN7_INIT_DIR   DIO_u8_PIN_INIT_OUTPUT
#define DIO_u8_PIN8_INIT_DIR   DIO_u8_PIN_INIT_OUTPUT
#define DIO_u8_PIN9_INIT_DIR   DIO_u8_PIN_INIT_OUTPUT
#define DIO_u8_PIN10_INIT_DIR  DIO_u8_PIN_INIT_OUTPUT
#define DIO_u8_PIN11_INIT_DIR  DIO_u8_PIN_INIT_OUTPUT
#define DIO_u8_PIN12_INIT_DIR  DIO_u8_PIN_INIT_OUTPUT
#define DIO_u8_PIN13_INIT_DIR  DIO_u8_PIN_INIT_OUTPUT
#define DIO_u8_PIN14_INIT_DIR  DIO_u8_PIN_INIT_OUTPUT
#define DIO_u8_PIN15_INIT_DIR  DIO_u8_PIN_INIT_OUTPUT
#define DIO_u8_PIN16_INIT_DIR  DIO_u8_PIN_INIT_OUTPUT
#define DIO_u8_PIN17_INIT_DIR  DIO_u8_PIN_INIT_OUTPUT
#define DIO_u8_PIN18_INIT_DIR  DIO_u8_PIN_INIT_OUTPUT
#define DIO_u8_PIN19_INIT_DIR  DIO_u8_PIN_INIT_OUTPUT
#define DIO_u8_PIN20_INIT_DIR  DIO_u8_PIN_INIT_OUTPUT
#define DIO_u8_PIN21_INIT_DIR  DIO_u8_PIN_INIT_OUTPUT
#define DIO_u8_PIN22_INIT_DIR  DIO_u8_PIN_INIT_OUTPUT
#define DIO_u8_PIN23_INIT_DIR  DIO_u8_PIN_INIT_OUTPUT
#define DIO_u8_PIN24_INIT_DIR  DIO_u8_PIN_INIT_OUTPUT
#define DIO_u8_PIN25_INIT_DIR  DIO_u8_PIN_INIT_OUTPUT
#define DIO_u8_PIN26_INIT_DIR  DIO_u8_PIN_INIT_OUTPUT
#define DIO_u8_PIN27_INIT_DIR  DIO_u8_PIN_INIT_OUTPUT
#define DIO_u8_PIN28_INIT_DIR  DIO_u8_PIN_INIT_OUTPUT
#define DIO_u8_PIN29_INIT_DIR  DIO_u8_PIN_INIT_OUTPUT
#define DIO_u8_PIN30_INIT_DIR  DIO_u8_PIN_INIT_OUTPUT
#define DIO_u8_PIN31_INIT_DIR  DIO_u8_PIN_INIT_OUTPUT


/* Initialization of the Value of each PIN */
/* Range : DIO_u8_PIN_INIT_HIGH           */
/*         DIO_u8_PIN_INIT_LOW           */
/*         DIO_u8_PIN_INIT_DEF          */
/* Warning: Any input pin must be      */
/*          configured as default     */

#define DIO_u8_PIN0_INIT_VALUE  DIO_u8_PIN_INIT_LOW
#define DIO_u8_PIN1_INIT_VALUE  DIO_u8_PIN_INIT_HIGH
#define DIO_u8_PIN2_INIT_VALUE  DIO_u8_PIN_INIT_HIGH
#define DIO_u8_PIN3_INIT_VALUE  DIO_u8_PIN_INIT_HIGH
#define DIO_u8_PIN4_INIT_VALUE  DIO_u8_PIN_INIT_HIGH
#define DIO_u8_PIN5_INIT_VALUE  DIO_u8_PIN_INIT_HIGH
#define DIO_u8_PIN6_INIT_VALUE  DIO_u8_PIN_INIT_HIGH
#define DIO_u8_PIN7_INIT_VALUE  DIO_u8_PIN_INIT_HIGH
#define DIO_u8_PIN8_INIT_VALUE  DIO_u8_PIN_INIT_HIGH
#define DIO_u8_PIN9_INIT_VALUE  DIO_u8_PIN_INIT_HIGH
#define DIO_u8_PIN10_INIT_VALUE DIO_u8_PIN_INIT_HIGH
#define DIO_u8_PIN11_INIT_VALUE DIO_u8_PIN_INIT_HIGH
#define DIO_u8_PIN12_INIT_VALUE DIO_u8_PIN_INIT_HIGH
#define DIO_u8_PIN13_INIT_VALUE DIO_u8_PIN_INIT_HIGH
#define DIO_u8_PIN14_INIT_VALUE DIO_u8_PIN_INIT_HIGH
#define DIO_u8_PIN15_INIT_VALUE DIO_u8_PIN_INIT_HIGH
#define DIO_u8_PIN16_INIT_VALUE DIO_u8_PIN_INIT_HIGH
#define DIO_u8_PIN17_INIT_VALUE DIO_u8_PIN_INIT_HIGH
#define DIO_u8_PIN18_INIT_VALUE DIO_u8_PIN_INIT_HIGH
#define DIO_u8_PIN19_INIT_VALUE DIO_u8_PIN_INIT_HIGH
#define DIO_u8_PIN20_INIT_VALUE DIO_u8_PIN_INIT_HIGH
#define DIO_u8_PIN21_INIT_VALUE DIO_u8_PIN_INIT_HIGH
#define DIO_u8_PIN22_INIT_VALUE DIO_u8_PIN_INIT_HIGH
#define DIO_u8_PIN23_INIT_VALUE DIO_u8_PIN_INIT_HIGH
#define DIO_u8_PIN24_INIT_VALUE DIO_u8_PIN_INIT_HIGH
#define DIO_u8_PIN25_INIT_VALUE DIO_u8_PIN_INIT_HIGH
#define DIO_u8_PIN26_INIT_VALUE DIO_u8_PIN_INIT_HIGH
#define DIO_u8_PIN27_INIT_VALUE DIO_u8_PIN_INIT_HIGH
#define DIO_u8_PIN28_INIT_VALUE DIO_u8_PIN_INIT_HIGH
#define DIO_u8_PIN29_INIT_VALUE DIO_u8_PIN_INIT_HIGH
#define DIO_u8_PIN30_INIT_VALUE DIO_u8_PIN_INIT_HIGH
#define DIO_u8_PIN31_INIT_VALUE DIO_u8_PIN_INIT_HIGH


#endif    /* DIO_PRIVATE_H_ */
#endif   /* DIO_PRIVATE_CONFIG_H_ */


