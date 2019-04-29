/***************************************************************************************/
/*                                                                                    */
/* File Name   : ADC_interface.h                                                     */
/*                                                                                  */
/* Created on  : Apr 27, 2019                                                      */
/*                                                                                */
/* Author      : shereen Abd Elhady                                              */
/*                                                                              */
/* Version     : V01                                                           */
/*                                                                            */
/* Description : interface file for ADC driver                               */
/*               includes APIs' prototypes and MACROS for call              */
/*                                                                         */
/* Layer       : MCAL                                                     */
/*************************************************************************/

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

/* 	The interface file includes only the Public configurations from the configuration file */
#include "ADC_config.h"

/* Analog channels definitions                           */
#define ADC_u8_ADC0_CH  0x00
#define ADC_u8_ADC1_CH  0x01
#define ADC_u8_ADC2_CH  0x02
#define ADC_u8_ADC3_CH  0x03
#define ADC_u8_ADC4_CH  0x04
#define ADC_u8_ADC5_CH  0x05
#define ADC_u8_ADC6_CH  0x06
#define ADC_u8_ADC7_CH  0x07

/*********************************** APIs Prototypes ************************************/

/*******************************************************************************
 * Description: Function to initialize ADC reference voltage, select prescaler,
 *              Set left & right adjustment finally enable the ADC.
 * Outputs   : None
 * Inputs    : None
 ******************************************************************************/
void ADC_Vidinit(void);


/*****************************************************************************************
 * Description: Function to select the ADC channel, start conversion and get the ADC
 *              digital value.
 * Outputs   : Error state
 * Inputs    : u16* Copy_Pu16PtrData : pointer  to variable to store digital value in it
 *             Copy_u8ChannelNb      : number of ADC channel which connected to a sensor
 ****************************************************************************************/
u8 ADC_u8GetADCBlocking(u16* Copy_Pu16PtrData , u8 Copy_u8ChannelNb);


/*****************************************************************************************
 * Description: Function to start the conversion of the first channel by selecting
 *              the channel number from an array contains a number of channels needed to be
 *              converted then enabling the ADC complete conversion interrupt
 *              and finally start conversion.
 * Outputs   :  None
 * Inputs    :  None
 ****************************************************************************************/
void ADC_VidRefreshADC(void);


/*****************************************************************************************
 * Description: Function to loop through the array which includes the ADC values
 *             and get the value corresponding to the sent channel number.
 *             (interrupt) (auto trigger by software)
 * Outputs   : Error state
 * Inputs    : u16* Copy_Pu16PtrData : pointer  to variable to store digital value in it
 *             Copy_u8ChannelNb      : number of ADC channel which connected to a sensor
 ****************************************************************************************/
u8 ADC_u8GetADCNonBlocking(u16* Copy_Pu16PtrData , u8 Copy_u8ChannelNb);


/****************************************************************************************************
 * Description:Function to Set the pointer to callback function with the address of the function
 *              Needed to be implemented by the ISR.
 * Outputs   : Error State
 * Inputs    : void (*Copy_PVidFunCallback) (void): pointer to callback function to set the pointer
 *             Value with the address of the function needed to be implemented by the ISR.
 ***************************************************************************************************/
u8 ADC_u8SetCallback (void (*Copy_PVidFunCallback) (void));


/****************************************************************************************************
 * Description:ADC complete conversion Interrupt Service Routine which includes a pointer
 *             points to a function send by user to be implemented.
 *             1)this ISR save the current channel converted value
 *             2)increment the array index to get the next channel
 *             3)select the next channel and start conversion of it
 *             4)call back at the last channel
 *
 * Outputs    :None
 * Inputs     :None
 ***************************************************************************************************/
void __vector_16 (void) __attribute__((signal));

#endif /* ADC_INTERFACE_H_ */
