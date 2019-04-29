/*******************************************************************************************/
/*                                                                                        */
/* File Name   : ADC_config.h                                                            */
/*                                                                                      */
/* Created on  : Apr 27, 2019                                                          */
/*                                                                                    */
/* Author      : shereen  Abd Elhady                                                 */
/*                                                                                  */
/* Version     : V01                                                               */
/*                                                                                */
/* Description : Basic Public and Private configurations for ADC driver          */
/*               defines it's reference voltage, presacler, left mode adjustment*/
/*               and connected channels according to the user desire.          */
/*                                                                            */
/* Layer       : MCAL                                                        */
/****************************************************************************/

            /**************************Public Configurations **********************************/
/* The first preprocessor guard is for the Public configurations which will be included in the interface file */
#ifndef ADC_PUBLIC_CONFIG_H_
#ifdef  ADC_INTERFACE_H_
#define ADC_PUBLIC_CONFIG_H_


#endif     /* ADC_INTERFACE_H_ */
#endif     /* ADC_PUBLIC_CONFIG_H_ */



         /**************************Private Configurations **********************************/
/* The second preprocessor guard is for the Private configurations which will be included in the private file */
#ifndef ADC_PRIVATEC_CONFIG_H_
#ifdef  ADC_PRIVATE_H_
#define ADC_PRIVATE_CONFIG_H_

/* The configurator will configure the reference voltage according to the customer desire      */
/* Range : ADC_u8_AREF_INTERNAL_TURNED_OFF                                                     */
/*         ADC_u8_AVCC_EXTERNAL_CAP_AREF_PIN                                                   */
/*         ADC_u8_INTERNAL_2.65V_EXTERNAL_CAP_AREF_PIN                                         */
#define ADC_u8_REFERENCE_VOLTAGE     ADC_u8_AVCC_EXTERNAL_CAP_AREF_PIN

/* The configurator will configure the left adjust result according to the customer desire     */
/* Range : ADC_u8_LEFT_ADJUST_RESULT_ON                                                        */
/*         ADC_u8_LEFT_ADJUST_RESULT_OFF                                                       */
#define ADC_u8_LEFT_ADJUST_RESULT    ADC_u8_LEFT_ADJUST_RESULT_ON

/* The configurator will configure the ADC prescaler according to the customer desire          */
/* Range :  ADC_u8_PRESCALER_DIV2_1                                                            */
/*          ADC_u8_PRESCALER_DIV2                                                              */
/*          ADC_u8_PRESCALER_DIV4                                                              */
/*          ADC_u8_PRESCALER_DIV8                                                              */
/*          ADC_u8_PRESCALER_DIV16                                                             */
/*          ADC_u8_PRESCALER_DIV32                                                             */
/*          ADC_u8_PRESCALER_DIV64                                                             */
/*          ADC_u8_PRESCALER_DIV128                                                            */
#define ADC_u8_PRESCALER_SELECTION   ADC_u8_PRESCALER_DIV16

/* The configurator will configure the ADC resolution according to the customer desire         */
/* Range :  ADC_u8_8BIT_RESOLUTION                                                             */
/*          ADC_u8_10BIT_RESOLUTION                                                            */
#define ADC_u8_RESOLUTION       ADC_u8_8BIT_RESOLUTION

/*the configurator will configure the number of channels needed to be converted                */
#define ADC_u8_NUM_CHANNELS_TO_CONVERT  (u8)2

/*the configurator will configure the channel number to be converted in this array            */
u8 ADC_u8ChainConverterChannels[ADC_u8_NUM_CHANNELS_TO_CONVERT] ={ADC_u8_ADC0 ,ADC_u8_ADC1};

#endif    /* ADC_PRIVATE_H_ */
#endif   /* ADC_PRIVATE_CONFIG_H_ */
