/*
 * Timers_private.h
 *
 *  Created on: Apr 6, 2019
 *      Author: shereen
 */

#ifndef TIMERS_PRIVATE_H_
#define TIMERS_PRIVATE_H_

/* 	The Private file includes only the Private configurations from the configuration file */
#include "TIMERS_config.h"

/* Timer interrupt mask register address definition                      */
#define TIMERS_u8_TIMSK ((Register*) 0x59)->ByteAccess


                                    /*** Timer 0 Registers' addresses definitions ***/
/* Output compare register of timer 0 address definition                 */
#define TIMER_u8_OCR0 ((Register*) 0x5C)->ByteAccess

/* Timer counter control register of timer 0 address definition          */
#define TIMER_u8_TCCR0 ((Register*) 0x53)->ByteAccess

/* Timer counter register of timer 0 address definition                  */
#define TIMER_u8_TCNT0 ((Register*) 0x52)->ByteAccess


                                   /*** Timer 1 Registers' addresses definitions ***/
/* Timer counter control register A of timer 1 address definition        */
#define TIMER_u8_TCCR1A ((Register*) 0x4F)->ByteAccess
/* Timer counter control register B of timer 1 address definition        */
#define TIMER_u8_TCCR1B ((Register*) 0x4E)->ByteAccess


/* Timer counter register high byte of timer 1 address definition        */
#define TIMER_u8_TCNT1H ((Register*) 0x4D)->ByteAccess
/* Timer counter register low byte of timer 1 address definition         */
#define TIMER_u8_TCNT1L ((Register*) 0x4C)->ByteAccess
/* cast the TCNT1 as u16 pointer to access the TCNT1 low & high together */
#define TIMER_u16_TCNT1 *((u16*) 0x4C)


/* Output compare register A high byte of timer 1 address definition     */
#define TIMER_u8_OCR1AH ((Register*) 0x4B)->ByteAccess
/* Output compare register A low byte of timer 1 address definition      */
#define TIMER_u8_OCR1AL ((Register*) 0x4A)->ByteAccess
/* cast the OCR1A as u16 pointer to access the OCR1A low & high together */
#define TIMER_u16_OCR1A *((u16*) 0x4A)


/* Output compare register B high byte of timer 1 address definition     */
#define TIMER_u8_OCR1BH ((Register*) 0x49)->ByteAccess
/* Output compare register B low byte of timer 1 address definition      */
#define TIMER_u8_OCR1BL ((Register*) 0x48)->ByteAccess
/* cast the OCR1B as u16 pointer to access the OCR1B low & high together */
#define TIMER_u16_OCR1B *((u16*) 0x48)


/* Input capture register high byte of timer 1 address definition        */
#define TIMER_u8_ICR1H ((Register*) 0x47)->ByteAccess
/* Input capture register low byte of timer 1 address definition         */
#define TIMER_u8_ICR1L ((Register*) 0x46)->ByteAccess
/* cast the ICR1 as u16 pointer to access the ICR1 low & high together   */
#define TIMER_u16_ICR1 *((u16*) 0x46)


                                    /*** Timer 2 Registers' addresses definitions ***/
/* Output compare register of timer 2 address definition                 */
#define TIMER_u8_OCR2 ((Register*) 0x43)->ByteAccess

/* Timer counter control register of timer 2 address definition          */
#define TIMER_u8_TCCR2 ((Register*) 0x45)->ByteAccess

/* Timer counter register of timer 2 address definition                  */
#define TIMER_u8_TCNT2 ((Register*) 0x44)->ByteAccess


                                                    /** Registers pins' definitions **/
/* TCCR0 Pins' numbers definitions                                       */
#define TIMER_u8_TCCR0_CS00             (u8)0
#define TIMER_u8_TCCR0_CS01             (u8)1
#define TIMER_u8_TCCR0_CS02             (u8)2
#define TIMER_u8_TCCR0_WGM01            (u8)3
#define TIMER_u8_TCCR0_COM00            (u8)4
#define TIMER_u8_TCCR0_COM01            (u8)5
#define TIMER_u8_TCCR0_WGM00            (u8)6
#define TIMER_u8_TCCR0_FOC0             (u8)7



/* TCCR1A Pins' numbers definitions                                       */
#define TIMER_u8_TCCR1A_WGM10            (u8)0
#define TIMER_u8_TCCR1A_WGM11            (u8)1
#define TIMER_u8_TCCR1A_FOC1B            (u8)2
#define TIMER_u8_TCCR1A_FOC1A            (u8)3
#define TIMER_u8_TCCR1A_COM1B0           (u8)4
#define TIMER_u8_TCCR1A_COM1B1           (u8)5
#define TIMER_u8_TCCR1A_COM1A0           (u8)6
#define TIMER_u8_TCCR1A_COM1A1           (u8)7

/* TCCR1B Pins' numbers definitions                                       */
#define TIMER_u8_TCCR1B_CS10             (u8)0
#define TIMER_u8_TCCR1B_CS11             (u8)1
#define TIMER_u8_TCCR1B_CS12             (u8)2
#define TIMER_u8_TCCR1B_WGM12            (u8)3
#define TIMER_u8_TCCR1B_WGM13            (u8)4
#define TIMER_u8_TCCR1B_ICES1            (u8)6
#define TIMER_u8_TCCR1B_ICNC1            (u8)7

/* TCCR2 Pins' numbers definitions                                       */
#define TIMER_u8_TCCR2_CS20             (u8)0
#define TIMER_u8_TCCR2_CS21             (u8)1
#define TIMER_u8_TCCR2_CS22             (u8)2
#define TIMER_u8_TCCR2_WGM21            (u8)3
#define TIMER_u8_TCCR2_COM20            (u8)4
#define TIMER_u8_TCCR2_COM21            (u8)5
#define TIMER_u8_TCCR2_WGM20            (u8)6
#define TIMER_u8_TCCR2_FOC2             (u8)7

/* TIMSK Pins' numbers definitions                                       */
#define TIMER_u8_TIMSK_TOIE0            (u8)0
#define TIMER_u8_TIMSK_OCIE0            (u8)1
#define TIMER_u8_TIMSK_TOIE1            (u8)2
#define TIMER_u8_TIMSK_OCIE1B           (u8)3
#define TIMER_u8_TIMSK_OCIE1A           (u8)4
#define TIMER_u8_TIMSK_TICIE1           (u8)5
#define TIMER_u8_TIMSK_TOIE2            (u8)6
#define TIMER_u8_TIMSK_OCIE2            (u8)7



/* Number of interrupts in timers                                        */
/* Timer 0 -> TIMER0 OVF , TIMERO COMP                                   */
/* Timer 1 -> TIMER1 OVF , TIMER1 COMPA , TIMER1 COMPB , TIMER1 CAPT     */
/* Timer 2 -> TIMER2 OVF , TIMER2 COMP                                   */
#define Timer_u8_NUM_INTERRUPTS          (u8)8


/* Timer enable and disable values definitions                           */
#define TIMER_u8_ENABLE                  (u8)1
#define TIMER_u8_DISABLE                 (u8)0

/*Timers' maximum count they could reach                                 */
#define TIMER_u8_MAX_COUNT_TIMER0        (u8)255
#define TIMER_u16_MAX_COUNT_TIMER1       (u16)65535
#define TIMER_u8_MAX_COUNT_TIMER2        (u8)255

/*The number of bits needed to be shifted to be able to access 16 bit register*/
#define TIMER_u8_ACCESS_REG_NUM_BITS     (u8)8



                                      /******* Private functions APIs **********/


/**********************************************************************************************************
 * Description:Private Function to set timer0 in overflow mode and adjust it's settings
 * Outputs   : None
 * Inputs    : None
 ***********************************************************************************************************/
static void TIMER_VidTimer0_Overflow_Initialize (void);


/**********************************************************************************************************
 * Description:Private Function to set timer1 in overflow mode and adjust it's settings
 * Outputs   : None
 * Inputs    : None
 ***********************************************************************************************************/
static void TIMER_VidTimer1_Overflow_Initialize (void);


/**********************************************************************************************************
 * Description:Private Function to set timer2 in overflow mode and adjust it's settings
 * Outputs   : None
 * Inputs    : None
 ***********************************************************************************************************/
static void TIMER_VidTimer2_Overflow_Initialize (void);


/**********************************************************************************************************
 * Description:Private Function to set timer0 in clear timer compare mode and adjust it's settings
 * Outputs   : None
 * Inputs    : None
 ***********************************************************************************************************/
static void TIMER_VidTimer0_CTC_Initialize (void);


/****************************************************************************************************************************
 * Description:Private Function to set timer1 in clear timer compare mode and adjust it's settings for channel A & channel B
 * Outputs   : None
 * Inputs    : None
 ****************************************************************************************************************************/
static void TIMER_VidTimer1_CTC_Initialize (void);


/**********************************************************************************************************
 * Description:Private Function to set timer2 in clear timer compare mode and adjust it's settings
 * Outputs   : None
 * Inputs    : None
 ***********************************************************************************************************/
static void TIMER_VidTimer2_CTC_Initialize (void);


/**********************************************************************************************************
 * Description:Private Function to set timer0 in fast PWM mode and adjust it's settings
 * Outputs   : None
 * Inputs    : None
 ***********************************************************************************************************/
static void TIMER_VidTimer0_FastPWM_Initialize (void);


/**********************************************************************************************************
 * Description:Private Function to set timer1 in fast PWM mode and adjust it's settings
 * Outputs   : None
 * Inputs    : None
 ***********************************************************************************************************/
static void TIMER_VidTimer1_FastPWM_Initialize (void);


/**********************************************************************************************************
 * Description:Private Function to set timer2 in fast PWM mode and adjust it's settings
 * Outputs   : None
 * Inputs    : None
 ***********************************************************************************************************/
static void TIMER_VidTimer2_FastPWM_Initialize (void);


/**********************************************************************************************************
 * Description:Private Function to set timer0 in phase correct mode and adjust it's settings
 * Outputs   : None
 * Inputs    : None
 ***********************************************************************************************************/
static void TIMER_VidTimer0_PhaseCorrectPWM_Initialize (void);



/**********************************************************************************************************
 * Description:Private Function to set timer1 in phase correct mode and adjust it's settings
 * Outputs   : None
 * Inputs    : None
 ***********************************************************************************************************/
static void TIMER_VidTimer1_PhaseCorrectPWM_Initialize (void);


/**********************************************************************************************************
 * Description:Private Function to set timer2 in phase correct mode and adjust it's settings
 * Outputs   : None
 * Inputs    : None
 ***********************************************************************************************************/
static void TIMER_VidTimer2_PhaseCorrectPWM_Initialize (void);


#endif /* TIMERS_PRIVATE_H_ */
