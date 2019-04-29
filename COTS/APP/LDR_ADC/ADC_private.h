/**************************************************************************************/
/*                                                                                   */
/* File Name   : ADC_private.h                                                      */
/*                                                                                 */
/* Created on  : Apr 27, 2019                                                     */
/*                                                                               */
/* Author      : shereen Abd Elhady                                             */
/*                                                                             */
/* Version     : V01                                                          */
/* Description : private header file for ADC driver                          */
/*               includes private functions prototypes.                     */
/*                                                                         */
/* Layer       : MCAL                                                     */
/*************************************************************************/

#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

/* Analog channels definitions                                                   */
#define ADC_u8_ADC0  0x00
#define ADC_u8_ADC1  0x01
#define ADC_u8_ADC2  0x02
#define ADC_u8_ADC3  0x03
#define ADC_u8_ADC4  0x04
#define ADC_u8_ADC5  0x05
#define ADC_u8_ADC6  0x06
#define ADC_u8_ADC7  0x07

/* 	The Private file includes only the Private configurations from the configuration file */
#include "ADC_config.h"


                     /******** Registers addresses definitions**********/
/* ADC Multiplexer selection register (ADMUX) address definition                  */
#define ADC_u8_ADMUX  *((volatile u8*) 0x27)
/* ADC control and status register (ADCSRA) address definition                    */
#define ADC_u8_ADCSRA *((volatile u8*) 0x26)
/* ADC high data register (ADCH) address definition                               */
#define ADC_u8_ADCH   *((volatile u8*) 0x25)
/* ADC low data register (ADCL) address definition                                */
#define ADC_u8_ADCL   *((volatile u8*) 0x24)
/* special function IO register (SFIOR) address definition                        */
#define ADC_u8_SFIOR  *((volatile u8*) 0x50)

/* ADMUX Register pins' numbers definitions                                       */
#define ADC_u8_REFS0_PIN  (u8)6
#define ADC_u8_ADLAR_PIN  (u8)5
#define ADC_u8_MUX0_PIN   (u8)0

/* ADCSRA Register pins' numbers definitions                                      */
#define ADC_u8_ADEN_PIN   (u8)7
#define ADC_u8_ADCSC_PIN  (u8)6
#define ADC_u8_ADIF_PIN   (u8)4
#define ADC_u8_ADIE_PIN   (u8)3
#define ADC_u8_ADPS0_PIN  (u8)0


/* Reference voltage selection bits for ADC definitions                           */
#define ADC_u8_AREF_INTERNAL_TURNED_OFF              0x00
#define ADC_u8_AVCC_EXTERNAL_CAP_AREF_PIN            0x01
#define ADC_u8_INTERNAL_2.65V_EXTERNAL_CAP_AREF_PIN  0x03

/* ADC left adjust result modes definition                                        */
#define ADC_u8_LEFT_ADJUST_RESULT_ON           1
#define ADC_u8_LEFT_ADJUST_RESULT_OFF          0

/* ADC prescaler selection                                                        */
#define ADC_u8_PRESCALER_DIV2_1   0x00
#define ADC_u8_PRESCALER_DIV2     0x01
#define ADC_u8_PRESCALER_DIV4     0x02
#define ADC_u8_PRESCALER_DIV8     0x03
#define ADC_u8_PRESCALER_DIV16    0x04
#define ADC_u8_PRESCALER_DIV32    0x05
#define ADC_u8_PRESCALER_DIV64    0x06
#define ADC_u8_PRESCALER_DIV128   0x07




/* Max channel number definition is 32                                              */
#define ADC_u8_MAX_CH_NUM         0X1F
/*number of shifts needed to access the high data value in case left adjustment OFF */
#define ADC_u8_SHIFT_HIGH_8BITS   (u8)8
/*number of shifts needed to access the high data value in case left adjustment ON */
#define ADC_u8_SHIFT_HIGH_2BITS   (u8)2

/* ADC resolution bits' definitions                                                 */
#define ADC_u8_8BIT_RESOLUTION    8
#define ADC_u8_10BIT_RESOLUTION  10

#endif /* ADC_PRIVATE_H_ */
