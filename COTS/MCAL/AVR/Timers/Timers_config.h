/*
 * Timers_config.h
 *
 *  Created on: Apr 6, 2019
 *      Author: shereen
 */

/**************************Public Configurations **********************************/
/* The first preprocessor guard is for the Public configurations which will be included in the interface file */
#ifndef TIMERS_PUBLIC_CONFIG_H_
#ifdef  TIMERS_INTERFACE_H_
#define TIMERS_PUBLIC_CONFIG_H_




#endif     /* TIMERS_INTERFACE_H_ */
#endif     /* TIMERS_PUBLIC_CONFIG_H_ */


          /**************************Private Configurations **********************************/
/* The second preprocessor guard is for the Private configurations which will be included in the private file */
#ifndef TIMERS_PRIVATEC_CONFIG_H_
#ifdef  TIMERS_PRIVATE_H_
#define TIMERS_PRIVATE_CONFIG_H_

/* Timer0, Timer1, TImer2 initial states whether they are enabled or disabled                                                     */
/* Range:TIMER_u8_ENABLE                                                                                                          */
/*       TIMER_u8_DISABLE                                                                                                         */
#define TIMER_0_u8_STATE   TIMER_u8_ENABLE
#define TIMER_1_u8_STATE   TIMER_u8_ENABLE
#define TIMER_2_u8_STATE   TIMER_u8_DISABLE


/* Timer0 preload value to be set in TCNT0 register to start counting from this value                                              */
#define TIMER_0_u8_PRELOAD   (u8)192
/* Timer1 preload value to be set in TCNT1 register to start counting from this value                                              */
#define TIMER_1_u16_PRELOAD  (u16)0
/* Timer2 preload value to be set in TCNT2 register to start counting from this value                                              */
#define TIMER_2_u8_PRELOAD   (u8)192


/* Timer0 number of overflow counts in which the timer will reach the overflow state this number of counts to reach a certain time */
#define TIMER_0_u32_OVF_COUNTS (u32)3907
/* Timer1 number of overflow counts in which the timer will reach the overflow state this number of counts to reach a certain time */
#define TIMER_1_u32_OVF_COUNTS (u32)1
/* Timer2 number of overflow counts in which the timer will reach the overflow state this number of counts to reach a certain time */
#define TIMER_2_u32_OVF_COUNTS (u32)3907


/*The customer configures the tick time of the timer according to the system clock and the choosen prescaler                      */
/*Fcpu = 8MHZ ,  Prescaler = 8 , so the Ftimer = 1MHZ anf  tick time = 1 micro                                                    */
#define TIMER_1_u8_TICK_TIME   (u8)1


/* Timer0 number of overflows that the compare match mode counts and required to reach a certain time                              */
#define TIMER_0_u32_OVF_COMP_MATCH_COUNTS   (u32)1
/* Timer1 number of overflows that the compare match mode counts and required to reach a certain time in channel A                 */
#define TIMER_1_u32_OVF_COMP_MATCH_COUNTS_A (u32)1
/* Timer1 number of overflows that the compare match mode counts and required to reach a certain time in channel B                 */
#define TIMER_1_u32_OVF_COMP_MATCH_COUNTS_B (u32)1
/* Timer2 number of overflows that the compare match mode counts and required to reach a certain time                              */
#define TIMER_2_u32_OVF_COMP_MATCH_COUNTS   (u32)2


/* The value required to be put in the OCR0 register where an ISR is executed when TCNT0 reaches this value                        */
#define TIMER_0_u8_COMP_MATCH_VALUE        (u8)128
/* The value required to be put in the OCR1A register where an ISR is executed when TCNT1 reaches this value                       */
#define TIMER_1_u16_COMP_MATCH_VALUE_A     (u16)128
/* The value required to be put in the OCR1B register where an ISR is executed when TCNT1 reaches this value                       */
#define TIMER_1_u16_COMP_MATCH_VALUE_B     (u16)128
/* The value required to be put in the OCR2 register where an ISR is executed when TCNT2 reaches this value                        */
#define TIMER_2_u8_COMP_MATCH_VALUE         (u8)250


/* The customer configures the mode of operation for timer0 according to his desire                                                */
/* Range: TIMER_0_NORMAL_MODE           */
/*        TIMER_0_PHASE_CORRECT_MODE    */
/*        TIMER_0_CTC_MODE              */
/*        TIMER_0_FAST_PWM_MODE         */
/*                                      */
#define TIMER_0_u8_MODE             TIMER_0_FAST_PWM_MODE

/*The customer configures the CTC submode according to his desire                                                                  */
/*Range:  TIMER_0_CTC_OC0_DISCONNECTED                                                                                             */
/*        TIMER_0_CTC_OC0_TOGGLE_ON_COMP                                                                                           */
/*        TIMER_0_CTC_OC0_CLEAR_ON_COMP                                                                                            */
/*        TIMER_0_CTC_OC0_SET_ON_COMP                                                                                              */
#define TIMER_0_u8_CTC_SUBMODE     TIMER_0_CTC_OC0_DISCONNECTED

/*The customer configures the fast PWM submode according to his desire whether he wants the PWM to be inverted or not inverted    */
/*Range: TIMER_0_PWM_OC0_DISCONNECTED                                                                                             */
/*       TIMER_0_PWM_OC0_CLEAR_ON_COMP_NOT_INVERTED                                                                               */
/*       TIMER_0_PWM_OC0_SET_ON_COMP_INVERTED                                                                                     */
#define TIMER_0_u8_PWM_SUBMODE    TIMER_0_PWM_OC0_CLEAR_ON_COMP_NOT_INVERTED


/*The customer configures the phase correct submode according to his desire whether he wants the PWM to be inverted or nor inverted*/
/*Range :TIMER_0_PHASE_CORRECT_OC0_DISCONNECTED                                                                                    */
/*       TIMER_0_PHASE_CORRECT_OC0_CLEAR_UP_SET_DOWN_COUNT                                                                         */
/*       TIMER_0_PHASE_CORRECT_OC0_SET_UP_CLEAR_DOWN_COUNT                                                                         */
#define TIMER_0_u8_PHASE_CORRECT_SUBMODE  TIMER_0_PHASE_CORRECT_OC0_CLEAR_UP_SET_DOWN_COUNT


/* The customer configures the mode of operation for timer1 according to his desire                                                */
/* Range: TIMER_1_NORMAL_MODE                                                                                                      */
/*        TIMER_1_PHASE_CORRECT_MODE_8BIT                                                                                          */
/*        TIMER_1_PHASE_CORRECT_MODE_9BIT                                                                                          */
/*        TIMER_1_PHASE_CORRECT_MODE_10BIT                                                                                         */
/*        TIMER_1_CTC_MODE_OCR1A                                                                                                   */
/*        TIMER_1_FAST_PWM_MODE_8BIT                                                                                               */
/*        TIMER_1_FAST_PWM_MODE_9BIT                                                                                               */
/*        TIMER_1_FAST_PWM_MODE_10BIT                                                                                              */
/*        TIMER_1_PWM_PHASE_FREQ_CORRECT_MODE_ICR1                                                                                 */
/*        TIMER_1_PWM_PHASE_FREQ_CORRECT_MODE_OCR1A                                                                                */
/*        TIMER_1_PHASE_CORRECT_MODE_ICR1                                                                                          */
/*        TIMER_1_PHASE_CORRECT_MODE_OCR1A                                                                                         */
/*        TIMER_1_CTC_MODE_ICR1                                                                                                    */
/*        TIMER_1_FAST_PWM_MODE_ICR1                                                                                               */
/*        TIMER_1_FAST_PWM_MODE_OCR1A                                                                                              */
#define TIMER_1_u8_MODE    TIMER_1_NORMAL_MODE


/*The customer configures the CTC submode according to his desire                                                                  */
/*Range:  TIMER_1_CTC_OC1A_OC1B_DISCONNECTED                                                                                       */
/*        TIMER_1_CTC_OC1A_OC1B_TOGGLE_ON_COMP                                                                                     */
/*        TIMER_1_CTC_OC1A_OC1B_CLEAR_ON_COMP                                                                                      */
/*        TIMER_1_CTC_OC1A_OC1B_SET_ON_COMP                                                                                        */
#define TIMER_1_u8_CTC_SUBMODE     TIMER_1_CTC_OC1A_OC1B_DISCONNECTED


/*The customer configures the Output compare interrupt match enable for channel A & B                                              */
/*Range :TIMER_u8_ENABLE                                                                                                           */
/*       TIMER_u8_DISABLE                                                                                                          */
#define TIMER_1_u8_OUTPUT_COMP_INT_A   TIMER_u8_ENABLE
#define TIMER_1_u8_OUTPUT_COMP_INT_B   TIMER_u8_ENABLE


/*The customer configures the fast PWM submode according to his desire whether he wants the PWM to be inverted or not inverted    */
/*Range:  TIMER_1_PWM_OC1A_OC1B_DISCONNECTED                                                                                      */
/*        TIMER_1_PWM_TOGGLE_OC1A_DISCONNECTED_OC1B                                                                               */
/*        TIMER_1_PWM_OC1A_OC1B_CLEAR_ON_COMP_NOT_INVERTED                                                                        */
/*        TIMER_1_PWM_OC1A_OC1B_SET_ON_COMP_INVERTED                                                                              */
#define TIMER_1_u8_PWM_SUBMODE    TIMER_1_PWM_OC1A_OC1B_CLEAR_ON_COMP_NOT_INVERTED


/*The customer configures the phase correct submode according to his desire whether he wants the PWM to be inverted or nor inverted*/
/*Range: TIMER_1_PHASE_CORRECT_OC1A_OC1B_DISCONNECTED                                                                              */
/*       TIMER_1_PHASE_CORRECT_TOGGLE_OC1A_DISCONNECTED_OC1B                                                                       */
/*       TIMER_1_PHASE_CORRECT_OC1A_OC1B_CLEAR_UP_SET_DOWN_COUNT                                                                   */
/*       TIMER_1_PHASE_CORRECT_OC1A_OC1B_SET_UP_CLEAR_DOWN_COUNT                                                                   */
#define TIMER_1_u8_PHASE_CORRECT_SUBMODE  TIMER_1_PHASE_CORRECT_OC1A_OC1B_SET_UP_CLEAR_DOWN_COUNT


/*The customer configures the Output compare match enable for channel A & B to generate PWM through it                             */
/*Range :TIMER_u8_ENABLE                                                                                                           */
/*       TIMER_u8_DISABLE                                                                                                          */
#define TIMER_1_u8_OUTPUT_COMP_A   TIMER_u8_ENABLE
#define TIMER_1_u8_OUTPUT_COMP_B   TIMER_u8_DISABLE


/*The customer configures the initial sense level of the input capture unit whether it's gonna be rising or falling edge          */
/*Range: TIMER_1_ICU_RISING_EDGE                                                                                                  */
/*       TIMER_1_ICU_FALLING_EDGE                                                                                                 */
#define TIMER_1_u8_ICU_INIT_SENSE_LEVEL   TIMER_1_ICU_RISING_EDGE


/* The customer configures the mode of operation for timer2 according to his desire                                                */
/* Range: TIMER_2_NORMAL_MODE                                                                                                      */
/*        TIMER_2_PHASE_CORRECT_MODE                                                                                               */
/*        TIMER_2_CTC_MODE                                                                                                         */
/*        TIMER_2_FAST_PWM_MODE                                                                                                    */
/*                                                                                                                                 */
#define TIMER_2_u8_MODE  TIMER_2_FAST_PWM_MODE

/*The customer configures the CTC submode according to his desire                                                                  */
/*Range:  TIMER_2_CTC_OC2_DISCONNECTED                                                                                             */
/*        TIMER_2_CTC_OC2_TOGGLE_ON_COMP                                                                                           */
/*        TIMER_2_CTC_OC2_CLEAR_ON_COMP                                                                                            */
/*        TIMER_2_CTC_OC2_SET_ON_COMP                                                                                              */
#define TIMER_2_u8_CTC_SUBMODE     TIMER_2_CTC_OC2_DISCONNECTED

/*The customer configures the fast PWM submode according to his desire whether he wants the PWM to be inverted or not inverted    */
/*Range: TIMER_2_PWM_OC2_DISCONNECTED                                                                                             */
/*       TIMER_2_PWM_OC2_CLEAR_ON_COMP_NOT_INVERTED                                                                               */
/*       TIMER_2_PWM_OC2_SET_ON_COMP_INVERTED                                                                                     */
#define TIMER_2_u8_PWM_SUBMODE    TIMER_2_PWM_OC2_CLEAR_ON_COMP_NOT_INVERTED


/*The customer configures the phase correct submode according to his desire whether he wants the PWM to be inverted or nor inverted*/
/*Range :TIMER_2_PHASE_CORRECT_OC2_DISCONNECTED                                                                                    */
/*       TIMER_2_PHASE_CORRECT_OC2_CLEAR_UP_SET_DOWN_COUNT                                                                         */
/*       TIMER_2_PHASE_CORRECT_OC2_SET_UP_CLEAR_DOWN_COUNT                                                                         */
#define TIMER_2_u8_PHASE_CORRECT_SUBMODE  TIMER_2_PHASE_CORRECT_OC2_CLEAR_UP_SET_DOWN_COUNT


/* The customer configure the clock prescalling of timer 0 according to his desire */
/* Range: TIMER_0_NO_CLK_SOURCE          */
/*        TIMER_0_CLK_PRESCALLING_1      */
/*        TIMER_0_CLK_PRESCALLING_8      */
/*        TIMER_0_CLK_PRESCALLING_64     */
/*        TIMER_0_CLK_PRESCALLING_256    */
/*        TIMER_0_CLK_PRESCALLING_1024   */
/*        TIMER_0_EXT_CLK_T0_FALLING_EDGE*/
/*        TIMER_0_EXT_CLK_T0_RISING_EDGE */
#define TIMER_0_CLK_PRESCALER       TIMER_0_CLK_PRESCALLING_8


/* The customer configure the clock prescalling of timer 1 according to his desire */
/* Range: TIMER_1_NO_CLK_SOURCE           */
/*        TIMER_1_CLK_PRESCALLING_1       */
/*        TIMER_1_CLK_PRESCALLING_8       */
/*        TIMER_1_CLK_PRESCALLING_64      */
/*        TIMER_1_CLK_PRESCALLING_256     */
/*        TIMER_1_CLK_PRESCALLING_1024    */
/*        TIMER_1_EXT_CLK_T0_FALLING_EDGE */
/*        TIMER_1_EXT_CLK_T0_RISING_EDGE  */
#define TIMER_1_CLK_PRESCALER       TIMER_1_CLK_PRESCALLING_8


/* The customer configure the clock prescalling of timer 2 according to his desire */
/* Range: TIMER_2_NO_CLK_SOURCE        */
/*        TIMER_2_CLK_PRESCALLING_1    */
/*        TIMER_2_CLK_PRESCALLING_8    */
/*        TIMER_2_CLK_PRESCALLING_32   */
/*        TIMER_2_CLK_PRESCALLING_64   */
/*        TIMER_2_CLK_PRESCALLING_128  */
/*        TIMER_2_CLK_PRESCALLING_256  */
/*        TIMER_2_CLK_PRESCALLING_1024 */
#define TIMER_2_CLK_PRESCALER       TIMER_2_CLK_PRESCALLING_8




#endif    /* TIMERS_PRIVATE_H_ */
#endif   /* TIMERS_PRIVATE_CONFIG_H_ */
