/*
 * Timers_interface.h
 *
 *  Created on: Apr 6, 2019
 *      Author: shereen
 */

#ifndef TIMERS_INTERFACE_H_
#define TIMERS_INTERFACE_H_

/* 	The interface file includes only the Public configurations from the configuration file */
#include "TIMERS_config.h"

/* Timers' index definitions                                                            */
#define TIMER_u8_TIMER0                                    (u8)0
#define TIMER_u8_TIMER1                                    (u8)1
#define TIMER_u8_TIMER2                                    (u8)2

/*Different duty cycles definitions                                                 */
#define TIMER_u8_0_DUTY_CYCLE                             (u8)0
#define TIMER_u8_25_DUTY_CYCLE                            (u8)25
#define TIMER_u8_50_DUTY_CYCLE                            (u8)50
#define TIMER_u8_75_DUTY_CYCLE                            (u8)75
#define TIMER_u8_100_DUTY_CYCLE                           (u8)100

/* Timer0 Modes of operation                                                          */
#define TIMER_0_NORMAL_MODE                                (u8)0
#define TIMER_0_PHASE_CORRECT_MODE                         (u8)1
#define TIMER_0_CTC_MODE                                   (u8)2
#define TIMER_0_FAST_PWM_MODE                              (u8)3

/* Timer0 submodes (non PWM mode)                                                     */
#define TIMER_0_CTC_OC0_DISCONNECTED                       (u8)0
#define TIMER_0_CTC_OC0_TOGGLE_ON_COMP                     (u8)1
#define TIMER_0_CTC_OC0_CLEAR_ON_COMP                      (u8)2
#define TIMER_0_CTC_OC0_SET_ON_COMP                        (u8)3

/* Timer0 submodes (Fast PWM mode)                                                     */
#define TIMER_0_PWM_OC0_DISCONNECTED                       (u8)0
#define TIMER_0_PWM_OC0_CLEAR_ON_COMP_NOT_INVERTED         (u8)2
#define TIMER_0_PWM_OC0_SET_ON_COMP_INVERTED               (u8)3

/* Timer0 submodes (Phase correct PWM mode)                                            */
#define TIMER_0_PHASE_CORRECT_OC0_DISCONNECTED             (u8)0
#define TIMER_0_PHASE_CORRECT_OC0_CLEAR_UP_SET_DOWN_COUNT  (u8)2
#define TIMER_0_PHASE_CORRECT_OC0_SET_UP_CLEAR_DOWN_COUNT  (u8)3


/* Timer1 Modes of operation                                                          */
#define TIMER_1_NORMAL_MODE                                (u8)0
#define TIMER_1_PHASE_CORRECT_MODE_8BIT                    (u8)1
#define TIMER_1_PHASE_CORRECT_MODE_9BIT                    (u8)2
#define TIMER_1_PHASE_CORRECT_MODE_10BIT                   (u8)3
#define TIMER_1_CTC_MODE_OCR1A                             (u8)4
#define TIMER_1_FAST_PWM_MODE_8BIT                         (u8)5
#define TIMER_1_FAST_PWM_MODE_9BIT                         (u8)6
#define TIMER_1_FAST_PWM_MODE_10BIT                        (u8)7
#define TIMER_1_PWM_PHASE_FREQ_CORRECT_MODE_ICR1           (u8)8
#define TIMER_1_PWM_PHASE_FREQ_CORRECT_MODE_OCR1A          (u8)9
#define TIMER_1_PHASE_CORRECT_MODE_ICR1                    (u8)10
#define TIMER_1_PHASE_CORRECT_MODE_OCR1A                   (u8)11
#define TIMER_1_CTC_MODE_ICR1                              (u8)12
#define TIMER_1_FAST_PWM_MODE_ICR1                         (u8)14
#define TIMER_1_FAST_PWM_MODE_OCR1A                        (u8)15


/* Timer1 submodes (non PWM mode)                                                     */
#define TIMER_1_CTC_OC1A_OC1B_DISCONNECTED                  (u8)0
#define TIMER_1_CTC_OC1A_OC1B_TOGGLE_ON_COMP                (u8)1
#define TIMER_1_CTC_OC1A_OC1B_CLEAR_ON_COMP                 (u8)2
#define TIMER_1_CTC_OC1A_OC1B_SET_ON_COMP                   (u8)3


/* Timer1 submodes (Fast PWM mode)                                                     */
#define TIMER_1_PWM_OC1A_OC1B_DISCONNECTED                  (u8)0
#define TIMER_1_PWM_TOGGLE_OC1A_DISCONNECTED_OC1B           (u8)1
#define TIMER_1_PWM_OC1A_OC1B_CLEAR_ON_COMP_NOT_INVERTED    (u8)2
#define TIMER_1_PWM_OC1A_OC1B_SET_ON_COMP_INVERTED          (u8)3


/* Timer1 submodes (Phase correct PWM mode)                                            */
#define TIMER_1_PHASE_CORRECT_OC1A_OC1B_DISCONNECTED             (u8)0
#define TIMER_1_PHASE_CORRECT_TOGGLE_OC1A_DISCONNECTED_OC1B      (u8)1
#define TIMER_1_PHASE_CORRECT_OC1A_OC1B_CLEAR_UP_SET_DOWN_COUNT  (u8)2
#define TIMER_1_PHASE_CORRECT_OC1A_OC1B_SET_UP_CLEAR_DOWN_COUNT  (u8)3


/* input capture unit sense level definitions                                          */
#define TIMER_1_ICU_RISING_EDGE                                  (u8)1
#define TIMER_1_ICU_FALLING_EDGE                                 (u8)0


/* Timer2 Modes of operation                                                          */
#define TIMER_2_NORMAL_MODE                                (u8)0
#define TIMER_2_PHASE_CORRECT_MODE                         (u8)1
#define TIMER_2_CTC_MODE                                   (u8)2
#define TIMER_2_FAST_PWM_MODE                              (u8)3

/* Timer2 submodes (non PWM mode)                                                     */
#define TIMER_2_CTC_OC2_DISCONNECTED                       (u8)0
#define TIMER_2_CTC_OC2_TOGGLE_ON_COMP                     (u8)1
#define TIMER_2_CTC_OC2_CLEAR_ON_COMP                      (u8)2
#define TIMER_2_CTC_OC2_SET_ON_COMP                        (u8)3

/* Timer2 submodes (Fast PWM mode)                                                     */
#define TIMER_2_PWM_OC2_DISCONNECTED                       (u8)0
#define TIMER_2_PWM_OC2_CLEAR_ON_COMP_NOT_INVERTED         (u8)2
#define TIMER_2_PWM_OC2_SET_ON_COMP_INVERTED               (u8)3

/* Timer2 submodes (Phase correct PWM mode)                                            */
#define TIMER_2_PHASE_CORRECT_OC2_DISCONNECTED             (u8)0
#define TIMER_2_PHASE_CORRECT_OC2_CLEAR_UP_SET_DOWN_COUNT  (u8)2
#define TIMER_2_PHASE_CORRECT_OC2_SET_UP_CLEAR_DOWN_COUNT  (u8)3

/* Timers' interrupts index definitions                                                */
#define TIMER_u8_TIMER2_COMP            (u8)0
#define TIMER_u8_TIMER2_OVF             (u8)1
#define TIMER_u8_TIMER1_COMPA           (u8)2
#define TIMER_u8_TIMER1_COMPB           (u8)3
#define TIMER_u8_TIMER1_OVF             (u8)4
#define TIMER_u8_TIMER0_COMP            (u8)5
#define TIMER_u8_TIMER0_OVF             (u8)6

                                            /***Timer0 Prescaler***/
/* Timer0 3 clock select bits  select the clock source to be used by the timer/counter */
#define TIMER_0_NO_CLK_SOURCE           (u8)0
#define TIMER_0_CLK_PRESCALLING_1       (u8)1
#define TIMER_0_CLK_PRESCALLING_8       (u8)2
#define TIMER_0_CLK_PRESCALLING_64      (u8)3
#define TIMER_0_CLK_PRESCALLING_256     (u8)4
#define TIMER_0_CLK_PRESCALLING_1024    (u8)5
#define TIMER_0_EXT_CLK_T0_FALLING_EDGE (u8)6
#define TIMER_0_EXT_CLK_T0_RISING_EDGE  (u8)7


                                           /***Timer1 Prescaler***/
/* Timer0 3 clock select bits  select the clock source to be used by the timer/counter */
#define TIMER_1_NO_CLK_SOURCE           (u8)0
#define TIMER_1_CLK_PRESCALLING_1       (u8)1
#define TIMER_1_CLK_PRESCALLING_8       (u8)2
#define TIMER_1_CLK_PRESCALLING_64      (u8)3
#define TIMER_1_CLK_PRESCALLING_256     (u8)4
#define TIMER_1_CLK_PRESCALLING_1024    (u8)5
#define TIMER_1_EXT_CLK_T0_FALLING_EDGE (u8)6
#define TIMER_1_EXT_CLK_T0_RISING_EDGE  (u8)7


                                           /***Timer2 Prescaler***/
/* Timer0 3 clock select bits  select the clock source to be used by the timer/counter */
#define TIMER_2_NO_CLK_SOURCE           (u8)0
#define TIMER_2_CLK_PRESCALLING_1       (u8)1
#define TIMER_2_CLK_PRESCALLING_8       (u8)2
#define TIMER_2_CLK_PRESCALLING_32      (u8)3
#define TIMER_2_CLK_PRESCALLING_64      (u8)4
#define TIMER_2_CLK_PRESCALLING_128     (u8)5
#define TIMER_2_CLK_PRESCALLING_256     (u8)6
#define TIMER_2_CLK_PRESCALLING_1024    (u8)7



/*************************************************************************************************************
 * Description:Function to initialize the 3 timers by setting their modes, submodes and presscaler
 *             Through calling a different private functions, each function is responsible for a specific mode
 * Outputs   : None
 * Inputs    : None
 *************************************************************************************************************/
void  TIMER_VidInitialize (void);


/**********************************************************************************************************
 * Description:Function to disable any timer of the three timers by setting their prescaler to zero.
 * Outputs   : Error State
 * Inputs    : Copy_u8TimerNb     : Number of Timer
 ***********************************************************************************************************/
u8 TIMER_u8DisableTimer (u8 Copy_u8TimerNb);


/**********************************************************************************************************************
 * Description:Function to enable any timer of the three timers prescaler ONLY and save the old value of TCCR as it is
 * Outputs   : Error State
 * Inputs    : Copy_u8TimerNb     : Number of Timer
 **********************************************************************************************************************/
u8 TIMER_u8EnableTimer (u8 Copy_u8TimerNb);


/**********************************************************************************************************************
 * Description:Function to update duty cycle value for any timer and put it in the OCR register.
 * Outputs   : Error State
 * Inputs    : Copy_u8TimerNb     : Number of Timer
 *             Copy_u8DutyCycle   : Duty cycle
 **********************************************************************************************************************/
u8 TIMER_u8UpdatePwmDutyCycle(u8 Copy_u8TimerNb , u8 Copy_u8DutyCycle);


/***********************************************************************************************************************
 * Description:Function to initialize the input capture unit in timer 1 by setting it's sense level whether it's gonna
 *             be with rising edge or with the falling edge.
 * Outputs   : None
 * Inputs    : None
 ***********************************************************************************************************************/
void  TIMER_VidInitializeICU (void);


/**********************************************************************************************************************
 * Description:Function to enable the input capture unit interrupt through the TIMSK Register.
 * Outputs   : None
 * Inputs    : None
 **********************************************************************************************************************/
void TIMER_VidInterruptEnableICU(void);


/**********************************************************************************************************************
 * Description:Function to disable the input capture unit interrupt through the TIMSK Register.
 * Outputs   : None
 * Inputs    : None
 **********************************************************************************************************************/
void TIMER_VidInterruptDisableICU(void);


/**********************************************************************************************************************
 * Description:Function to get the on time of the PWM
 * Outputs   : Error State
 * Inputs    : *Copy_Pu16OnTime : pointer to u16 variable to save the on time in it
 **********************************************************************************************************************/
u8 TIMER_u8GetPwmOnTime (u16 *Copy_Pu16OnTime);


/**********************************************************************************************************************
 * Description:Function to get the off time of the PWM
 * Outputs   : Error State
 * Inputs    : *Copy_Pu16OnTime : pointer to u16 variable to save the off time in it
 **********************************************************************************************************************/
u8 TIMER_u8GetPwmOffTime (u16 *Copy_Pu16OffTime);


/**********************************************************************************************************************
 * Description:Function to get the period of the PWM
 * Outputs   : Error State
 * Inputs    : *Copy_Pu32OnTime : pointer to u32 variable to save the period time in it
 **********************************************************************************************************************/
u8 TIMER_u8GetPwmPeriod (u32 *Copy_Pu32Period);


/**********************************************************************************************************************
 * Description:Function to get the Duty cycle of the PWM
 * Outputs   : Error State
 * Inputs    : *Copy_Pu32OnTime : pointer to u8 variable to save the duty cycle in it
 **********************************************************************************************************************/
u8 TIMER_u8GetPwmDutyCycle (u8 *Copy_Pu8DutyCycle);


/****************************************************************************************************
 * Description:Function to Set the pointer to callback function with the address of the function
 *              Needed to be implemented by the ISR.
 * Outputs   : Error State
 * Inputs    : void (*Copy_PVidFunCallback) (void): pointer to callback function to set the pointer
 *             Value with the address of the function needed to be implemented by the ISR.
 *             Copy_u8Timer_INT_index             : Interrupt Index number
 ***************************************************************************************************/
u8 TIMER_u8SetCallback (u8 Copy_u8Timer_INT_Index , void (*Copy_PVidFunCallback) (void));


/***********************************************************************************************************
 * Description:Timer2 Compare Match Interrupt Service Routine which includes a pointer points to a function
 *             Send by user to be implemented.
 * Outputs    :Error State
 * Inputs     :None
 **********************************************************************************************************/
void __vector_4 (void) __attribute__((signal));


/***********************************************************************************************************
 * Description:Timer2 Overflow Interrupt Service Routine which includes a pointer points to a function
 *             Send by user to be implemented.
 * Outputs    :Error State
 * Inputs     :None
 **********************************************************************************************************/
void __vector_5 (void) __attribute__((signal));


/***********************************************************************************************************
 * Description:Timer1 Capture event Interrupt Service Routine which includes a pointer points to a function
 *             Send by user to be implemented.
 * Outputs    :Error State
 * Inputs     :None
 **********************************************************************************************************/
void __vector_6 (void) __attribute__((signal));


/***********************************************************************************************************
 * Description:Timer1 Compare Match A Interrupt Service Routine which includes a pointer points to a function
 *             Send by user to be implemented.
 * Outputs    :Error State
 * Inputs     :None
 **********************************************************************************************************/
void __vector_7 (void) __attribute__((signal));


/***********************************************************************************************************
 * Description:Timer1 Compare Match B Interrupt Service Routine which includes a pointer points to a function
 *             Send by user to be implemented.
 * Outputs    :Error State
 * Inputs     :None
 **********************************************************************************************************/
void __vector_8 (void) __attribute__((signal));


/***********************************************************************************************************
 * Description:Timer1 Overflow Interrupt Service Routine which includes a pointer points to a function
 *             Send by user to be implemented.
 * Outputs    :Error State
 * Inputs     :None
 **********************************************************************************************************/
void __vector_9 (void) __attribute__((signal));


/***********************************************************************************************************
 * Description:Timer0 Compare Match Interrupt Service Routine which includes a pointer points to a function
 *             Send by user to be implemented.
 * Outputs    :Error State
 * Inputs     :None
 **********************************************************************************************************/
void __vector_10 (void) __attribute__((signal));


/***********************************************************************************************************
 * Description:Timer0 Overflow Interrupt Service Routine which includes a pointer points to a function
 *             Send by user to be implemented.
 * Outputs    :Error State
 * Inputs     :None
 **********************************************************************************************************/
void __vector_11 (void) __attribute__((signal));


#endif /* TIMERS_INTERFACE_H_ */
