/*
 * Timers_prog.c
 *
 *  Created on: Apr 6, 2019
 *      Author: shereen
 */

#include "STD_TYPES.h"
#include "MCU_interface.h"
#include "Timers_interface.h"
#include "Timers_private.h"


/* Array of pointers to function, each pointer will carry the address of the function wanted to be implemented by the ISR           */
/* Initialize all the pointers with Null in the beginning to avoid this pointer from garbage value and implementation of wrong code */
/* Global & Static to be seen within this file only                                                                                 */
static void (*PVidFunCallback[Timer_u8_NUM_INTERRUPTS]) (void) = {NULL , NULL , NULL , NULL , NULL , NULL , NULL};

/*Global variables to save the ON & OFF time of the PWM which will be the input to the ICU                                         */
u16 Global_u16PwmON_Time =0 , Global_u16PwmOFF_Time = 0;

/*************************************************************************************************************
 * Description:Function to initialize the 3 timers by setting their modes, submodes and presscaler
 *             Through calling a different private functions, each function is responsible for a specific mode
 * Outputs   : None
 * Inputs    : None
 *************************************************************************************************************/
void  TIMER_VidInitialize (void)
{
	/******** Timer0 *******/
	/* If the initial state of timer0 is disable then disable the timer                                                 */
	if(TIMER_0_u8_STATE == TIMER_u8_DISABLE)
	{
		TIMER_u8DisableTimer (TIMER_u8_TIMER0);
	}
	/* If the initial state of timer0 is enable then do the following logic                                             */
	else
	{
		/*Switch on the timer mode                                                                                     */
		switch (TIMER_0_u8_MODE)
		{
		case TIMER_0_NORMAL_MODE:
			/*in case of normal mode call the overflow private function                                                */
			/*this function set mode only not the prescaler to set the prescaler you have to call enable timer function*/
			TIMER_VidTimer0_Overflow_Initialize ();
			break;
		case TIMER_0_CTC_MODE:
			/*in case of clear timer compare mode call the CTC private function                                        */
			/*This function only set the mode and submode to set the prescaler you have to call enable timer function  */
			TIMER_VidTimer0_CTC_Initialize ();
			break;
		case TIMER_0_FAST_PWM_MODE:
			/*in case of fast PWM call the fast PWM function to set mode and submode                                   */
			/*call update duty cycle function to set the OCR with value corresponding to the given duty cycle          */
			/*This function only set the mode and submode to set the prescaler you have to call enable timer function  */
			TIMER_VidTimer0_FastPWM_Initialize ();
			break;
		case TIMER_0_PHASE_CORRECT_MODE:
			/*in case of phase correct call the phase correct function to set mode and submode                         */
			/*call update duty cycle function to set the OCR with value corresponding to the given duty cycle          */
			/*This function only set the mode and submode to set the prescaler you have to call enable timer function  */
			TIMER_VidTimer0_PhaseCorrectPWM_Initialize ();
			break;
		}
	}


	/******** Timer1 *******/
	/* If the initial state of timer1 is disable then disable the timer                                                 */
	if(TIMER_1_u8_STATE == TIMER_u8_DISABLE)
	{
		TIMER_u8DisableTimer (TIMER_u8_TIMER1);
	}
	/* If the initial state of timer1 is enable then do the following logic                                             */
	else
	{
		/*Switch on the timer mode                                                                                      */
		switch (TIMER_1_u8_MODE)
		{
		case TIMER_1_NORMAL_MODE:
			/*in case of normal mode call the overflow private function                                                */
			/*this function set mode only not the prescaler to set the prescaler you have to call enable timer function*/
			TIMER_VidTimer1_Overflow_Initialize ();
			break;
		case TIMER_1_CTC_MODE_OCR1A:
			/*in case of clear timer compare mode call the CTC private function                                        */
			/*This function only set the mode and submode to set the prescaler you have to call enable timer function  */
			TIMER_VidTimer1_CTC_Initialize ();
			break;
		case TIMER_1_FAST_PWM_MODE_OCR1A:
			/*in case of fast PWM call the fast PWM function to set mode and submode                                   */
			/*call update duty cycle function to set the OCR with value corresponding to the given duty cycle          */
			/*This function only set the mode and submode to set the prescaler you have to call enable timer function  */
			TIMER_VidTimer1_FastPWM_Initialize ();
			break;
		case TIMER_1_PHASE_CORRECT_MODE_OCR1A:
			/*in case of phase correct call the phase correct function to set mode and submode                         */
			/*call update duty cycle function to set the OCR with value corresponding to the given duty cycle          */
			/*This function only set the mode and submode to set the prescaler you have to call enable timer function  */
			TIMER_VidTimer1_PhaseCorrectPWM_Initialize ();
			break;
		}
	}

	/******** Timer2 *******/
	/* If the initial state of timer2 is disable then disable the timer                                               */
	if(TIMER_2_u8_STATE == TIMER_u8_DISABLE)
	{
		TIMER_u8DisableTimer (TIMER_u8_TIMER2);
	}
	/* If the initial state of timer2 is enable then do the following logic                                           */
	else
	{
		/*Switch on the timer mode                                                                                   */
		switch (TIMER_2_u8_MODE)
		{
		case TIMER_2_NORMAL_MODE:
			/*in case of normal mode call the overflow private function                                              */
			TIMER_VidTimer2_Overflow_Initialize ();
			break;
		case TIMER_2_CTC_MODE:
			/*in case of clear timer compare mode call the CTC private function                                        */
			/*This function only set the mode and submode to set the prescaler you have to call enable timer function  */
			TIMER_VidTimer2_CTC_Initialize ();
			break;
		case TIMER_2_FAST_PWM_MODE:
			/*in case of fast PWM call the fast PWM function to set mode and submode                                   */
			/*call update duty cycle function to set the OCR with value corresponding to the given duty cycle          */
			/*This function only set the mode and submode to set the prescaler you have to call enable timer function  */
			TIMER_VidTimer2_FastPWM_Initialize ();
			break;
		case TIMER_2_PHASE_CORRECT_MODE:
			/*in case of phase correct call the phase correct function to set mode and submode                         */
			/*call update duty cycle function to set the OCR with value corresponding to the given duty cycle          */
			/*This function only set the mode and submode to set the prescaler you have to call enable timer function  */
			TIMER_VidTimer2_PhaseCorrectPWM_Initialize ();
			break;
		}
	}
	return;
}

/**********************************************************************************************************
 * Description:Function to disable any timer of the three timers by setting their prescaler to zero.
 * Outputs   : Error State
 * Inputs    : Copy_u8TimerNb     : Number of Timer
 ***********************************************************************************************************/
u8 TIMER_u8DisableTimer (u8 Copy_u8TimerNb)
{
	/* Local Variable indication for Error status                                                                */
	u8 Local_u8Error = STD_TYPES_u8_ERROR_OK;
	switch(Copy_u8TimerNb)
	{
	/* Timer 0 */
	case TIMER_u8_TIMER0:
		/*No Clk source                                                                                          */
		TIMER_u8_TCCR0 &= (~(1<<TIMER_u8_TCCR0_CS00));
		TIMER_u8_TCCR0 &= (~(1<<TIMER_u8_TCCR0_CS01));
		TIMER_u8_TCCR0 &= (~(1<<TIMER_u8_TCCR0_CS02));
		break;
		/* Timer1 */
	case TIMER_u8_TIMER1:
		/*No Clk source                                                                                         */
		TIMER_u8_TCCR1B &= (~(1<<TIMER_u8_TCCR1B_CS10));
		TIMER_u8_TCCR1B &= (~(1<<TIMER_u8_TCCR1B_CS11));
		TIMER_u8_TCCR1B &= (~(1<<TIMER_u8_TCCR1B_CS12));

		break;
		/*Timer 2 */
	case TIMER_u8_TIMER2:
		/*No Clk source                                                                                          */
		TIMER_u8_TCCR2 &= (~(1<<TIMER_u8_TCCR2_CS20));
		TIMER_u8_TCCR2 &= (~(1<<TIMER_u8_TCCR2_CS21));
		TIMER_u8_TCCR2 &= (~(1<<TIMER_u8_TCCR2_CS22));
		break;
		/*if it is not timer0 , timer1 , timer2 then return an error and this is considered as input validation  */
	default: Local_u8Error = STD_TYPES_u8_ERROR_NOK;
	break;
	}
	/* Function Return                                                                                           */
	return Local_u8Error;
}


/**********************************************************************************************************************
 * Description:Function to enable any timer of the three timers prescaler ONLY and save the old value of TCCR as it is
 * Outputs   : Error State
 * Inputs    : Copy_u8TimerNb     : Number of Timer
 **********************************************************************************************************************/
u8 TIMER_u8EnableTimer (u8 Copy_u8TimerNb)
{
	/* Local Variable indication for Error status                                                                     */
	u8 Local_u8Error = STD_TYPES_u8_ERROR_OK;
	/*in this function i used |= with the TCCR as i want to save the old value and change only the prescaler here     */
	switch(Copy_u8TimerNb)
	{
	/* Timer 0 */
	case TIMER_u8_TIMER0:
		/* Switch on the presacler value                                                                               */
		switch(TIMER_0_CLK_PRESCALER)
		{
		/* Ftimer = Fclk / 1                                                                                           */
		case TIMER_0_CLK_PRESCALLING_1:      TIMER_u8_TCCR0 |= (1<< TIMER_u8_TCCR0_CS00 );
		break;
		/* Ftimer = Fclk / 8                                                                                           */
		case TIMER_0_CLK_PRESCALLING_8:      TIMER_u8_TCCR0 |= (1<< TIMER_u8_TCCR0_CS01 );
		break;
		/* Ftimer = Fclk / 64                                                                                          */
		case TIMER_0_CLK_PRESCALLING_64:     TIMER_u8_TCCR0 |= (1<< TIMER_u8_TCCR0_CS01 ) | (1<< TIMER_u8_TCCR0_CS00 );
		break;
		/* Ftimer = Fclk / 256                                                                                          */
		case TIMER_0_CLK_PRESCALLING_256:    TIMER_u8_TCCR0 |= (1<< TIMER_u8_TCCR0_CS02 );
		break;
		/* Ftimer = Fclk / 1024                                                                                         */
		case TIMER_0_CLK_PRESCALLING_1024:   TIMER_u8_TCCR0 |= (1<< TIMER_u8_TCCR0_CS02 ) | (1<< TIMER_u8_TCCR0_CS00 );
		break;
		/*timer operates as Counter and counts events' numbers at falling edge                                          */
		case TIMER_0_EXT_CLK_T0_FALLING_EDGE:TIMER_u8_TCCR0 |=(1<< TIMER_u8_TCCR0_CS02 ) | (1<< TIMER_u8_TCCR0_CS01 );
		break;
		/*timer operates as Counter and counts events' numbers at rising edge                                           */
		case TIMER_0_EXT_CLK_T0_RISING_EDGE: TIMER_u8_TCCR0 |= (1<< TIMER_u8_TCCR0_CS02 ) | (1<< TIMER_u8_TCCR0_CS01 ) | (1<< TIMER_u8_TCCR0_CS00 );
		break;
		}
		break;
		/* Timer 1 */
		case TIMER_u8_TIMER1:
			/* Switch on the presacler value                                                                               */
			switch(TIMER_1_CLK_PRESCALER)
			{
			/* Ftimer = Fclk / 1                                                                                           */
			case TIMER_1_CLK_PRESCALLING_1:      TIMER_u8_TCCR1B |= (1<< TIMER_u8_TCCR1B_CS10 );
			break;
			/* Ftimer = Fclk / 8                                                                                           */
			case TIMER_1_CLK_PRESCALLING_8:      TIMER_u8_TCCR1B |= (1<< TIMER_u8_TCCR1B_CS11 );
			break;
			/* Ftimer = Fclk / 64                                                                                          */
			case TIMER_1_CLK_PRESCALLING_64:     TIMER_u8_TCCR1B |= (1<< TIMER_u8_TCCR1B_CS11 ) | (1<< TIMER_u8_TCCR1B_CS10 );
			break;
			/* Ftimer = Fclk / 256                                                                                          */
			case TIMER_1_CLK_PRESCALLING_256:    TIMER_u8_TCCR1B |= (1<< TIMER_u8_TCCR1B_CS12 );
			break;
			/* Ftimer = Fclk / 1024                                                                                         */
			case TIMER_1_CLK_PRESCALLING_1024:   TIMER_u8_TCCR1B |= (1<< TIMER_u8_TCCR1B_CS12 ) | (1<< TIMER_u8_TCCR1B_CS10 );
			break;
			/*timer operates as Counter and counts events' numbers at falling edge                                          */
			case TIMER_1_EXT_CLK_T0_FALLING_EDGE:TIMER_u8_TCCR1B |=(1<< TIMER_u8_TCCR1B_CS12 ) | (1<< TIMER_u8_TCCR1B_CS11 );
			break;
			/*timer operates as Counter and counts events' numbers at rising edge                                           */
			case TIMER_1_EXT_CLK_T0_RISING_EDGE: TIMER_u8_TCCR1B |= (1<< TIMER_u8_TCCR1B_CS12 ) | (1<< TIMER_u8_TCCR1B_CS11 ) | (1<< TIMER_u8_TCCR1B_CS10 );
			break;
			}
			break;
			/* Timer 2 */
			case TIMER_u8_TIMER2:
				/* Switch on the presacler value                                                                         */
				switch(TIMER_2_CLK_PRESCALER)
				{
				/* Ftimer = Fclk / 1                                                                                      */
				case TIMER_2_CLK_PRESCALLING_1:   TIMER_u8_TCCR2 |= (1<< TIMER_u8_TCCR2_CS20 );
				break;
				/* Ftimer = Fclk / 8                                                                                      */
				case TIMER_2_CLK_PRESCALLING_8:   TIMER_u8_TCCR2 |= (1<< TIMER_u8_TCCR2_CS21 );
				break;
				/* Ftimer = Fclk / 32                                                                                     */
				case TIMER_2_CLK_PRESCALLING_32:  TIMER_u8_TCCR2 |= (1<< TIMER_u8_TCCR2_CS21 ) | (1<< TIMER_u8_TCCR2_CS20 );
				break;
				/* Ftimer = Fclk / 64                                                                                     */
				case TIMER_2_CLK_PRESCALLING_64:  TIMER_u8_TCCR2 |= (1<< TIMER_u8_TCCR2_CS22 );
				break;
				/* Ftimer = Fclk / 128                                                                                   */
				case TIMER_2_CLK_PRESCALLING_128:  TIMER_u8_TCCR2 |= (1<< TIMER_u8_TCCR2_CS22 ) | (1<< TIMER_u8_TCCR2_CS20 );
				break;
				/* Ftimer = Fclk / 256                                                                                   */
				case TIMER_2_CLK_PRESCALLING_256:  TIMER_u8_TCCR2 |=  (1<< TIMER_u8_TCCR2_CS22 ) | (1<< TIMER_u8_TCCR2_CS21 );
				break;
				/* Ftimer = Fclk / 1024                                                                                   */
				case TIMER_2_CLK_PRESCALLING_1024: TIMER_u8_TCCR2 |= (1<< TIMER_u8_TCCR2_CS22 ) | (1<< TIMER_u8_TCCR2_CS21 ) | (1<< TIMER_u8_TCCR2_CS20 );
				break;
				}
				break;
				/*if it is not timer0 , timer1 , timer2 then return an error and this is considered as input validation  */
				default: Local_u8Error = STD_TYPES_u8_ERROR_NOK;
				break;
	}
	/* Function Return                                                                                                   */
	return Local_u8Error;
}


/**********************************************************************************************************************
 * Description:Function to update duty cycle value for any timer and put it in the OCR register.
 * Outputs   : Error State
 * Inputs    : Copy_u8TimerNb     : Number of Timer
 *             Copy_u8DutyCycle   : Duty cycle
 **********************************************************************************************************************/
u8 TIMER_u8UpdatePwmDutyCycle(u8 Copy_u8TimerNb , u8 Copy_u8DutyCycle)
{
	/* Local Variable indication for Error status                                                                                  */
	u16 Local_u8Error = STD_TYPES_u8_ERROR_OK;
	/* Local variable to save in it the value required to be put in the OCR and equivalent to the given duty cycle                 */
	static u16 Local_u16OCRvalue = 0;
	//u16 Local_u16OCRBvalue = 0;
	/*Switch on the timer number                                                                                                   */
	switch (Copy_u8TimerNb)
	{
	/*calculating the number of counts should be written in the OCR0 to generate a PWM signal with the given duty cycle            */
	case TIMER_u8_TIMER0:
		TIMER_u8_OCR0 = ((Copy_u8DutyCycle * TIMER_u8_MAX_COUNT_TIMER0) / 100);
		break;
		/*calculating the number of counts should be written in the OCR1A/OCR1B to generate a PWM signal with the given duty cycle */
	case TIMER_u8_TIMER1:
		Local_u16OCRvalue = ( ((u32)(Copy_u8DutyCycle * TIMER_u16_MAX_COUNT_TIMER1)) / 100);
		if (TIMER_1_u8_OUTPUT_COMP_A == TIMER_u8_ENABLE)
		{
			/* The value required to be put in the OCR1A register where an ISR is executed when TCNT1 reaches this value           */
			/*while writing in a 16 bit register we write the High byte firstly then the low (reading -> vice versa)               */
			/*We shift the preload value by 8 bits to right to put the most 8 bits in OCR1AH                                       */
			TIMER_u8_OCR1AH = Local_u16OCRvalue >> TIMER_u8_ACCESS_REG_NUM_BITS;
			/*Cast to u8 to access the least 8 bits and put them in the OCR1AL                                                     */
			TIMER_u8_OCR1AL = (u8)Local_u16OCRvalue;
		}
		if (TIMER_1_u8_OUTPUT_COMP_B == TIMER_u8_ENABLE)
		{
			/* The value required to be put in the OCR1B register where an ISR is executed when TCNT1 reaches this value           */
			/*while writing in a 16 bit register we write the High byte firstly then the low (reading -> vice versa)               */
			/*We shift the preload value by 8 bits to right to put the most 8 bits in OCR1BH                                       */
			TIMER_u8_OCR1BH = Local_u16OCRvalue >> TIMER_u8_ACCESS_REG_NUM_BITS;
			/*Cast to u8 to access the least 8 bits and put them in the OCR1BL                                                     */
			TIMER_u8_OCR1BL = (u8)Local_u16OCRvalue;
		}
		break;
		/*calculating the number of counts should be written in the OCR2 to generate a PWM signal with the given duty cycle        */
	case TIMER_u8_TIMER2:
		TIMER_u8_OCR2 = ((Copy_u8DutyCycle * TIMER_u8_MAX_COUNT_TIMER2) / 100);
		break;
		/*if it is not timer0 , timer1 , timer2 then return an error and this is considered as input validation                    */
	default: Local_u8Error = STD_TYPES_u8_ERROR_NOK;
	break;
	}
	/* Function Return                                                                                                             */
	return Local_u8Error;
}


/***********************************************************************************************************************
 * Description:Function to initialize the input capture unit in timer 1 by setting it's sense level whether it's gonna
 *             be with rising edge or with the falling edge.
 * Outputs   : None
 * Inputs    : None
 ***********************************************************************************************************************/
void  TIMER_VidInitializeICU (void)
{
	if (TIMER_1_u8_ICU_INIT_SENSE_LEVEL == TIMER_1_ICU_RISING_EDGE)
	{
		/*Initialize the ICU to sense the rising edge firstly                                                                  */
		TIMER_u8_TCCR1B |= (1 << TIMER_u8_TCCR1B_ICES1);
	}
	else
	{
		/*Initialize the ICU to sense the falling edge firstly                                                                 */
		TIMER_u8_TCCR1B &= (~(1 << TIMER_u8_TCCR1B_ICES1));
	}
}


/**********************************************************************************************************************
 * Description:Function to enable the input capture unit interrupt through the TIMSK Register.
 * Outputs   : None
 * Inputs    : None
 **********************************************************************************************************************/
void TIMER_VidInterruptEnableICU(void)
{
	/*Enable the input capture unit interrupt                                                                                   */
	TIMERS_u8_TIMSK |= (1<<TIMER_u8_TIMSK_TICIE1);
}


/**********************************************************************************************************************
 * Description:Function to disable the input capture unit interrupt through the TIMSK Register.
 * Outputs   : None
 * Inputs    : None
 **********************************************************************************************************************/
void TIMER_VidInterruptDisableICU(void)
{
	/*Disable the input capture unit interrupt                                                                                   */
	TIMERS_u8_TIMSK &= (~(1<<TIMER_u8_TIMSK_TICIE1));
}


/**********************************************************************************************************************
 * Description:Function to get the on time of the PWM
 * Outputs   : Error State
 * Inputs    : *Copy_Pu16OnTime : pointer to u16 variable to save the on time in it
 **********************************************************************************************************************/
u8 TIMER_u8GetPwmOnTime (u16 *Copy_Pu16OnTime)
{
	/* Local Variable indication for Error status                                                                                  */
	u16 Local_u8Error = STD_TYPES_u8_ERROR_OK;
	if (Copy_Pu16OnTime == NULL)
	{
		Local_u8Error = STD_TYPES_u8_ERROR_NOK;
	}
	else
	{
		*Copy_Pu16OnTime = Global_u16PwmON_Time * TIMER_1_u8_TICK_TIME;
	}
	/* Function Return                                                                                                             */
	return Local_u8Error;
}


/**********************************************************************************************************************
 * Description:Function to get the off time of the PWM
 * Outputs   : Error State
 * Inputs    : *Copy_Pu16OnTime : pointer to u16 variable to save the off time in it
 **********************************************************************************************************************/
u8 TIMER_u8GetPwmOffTime (u16 *Copy_Pu16OffTime)
{
	/* Local Variable indication for Error status                                                                                  */
	u16 Local_u8Error = STD_TYPES_u8_ERROR_OK;
	if (Copy_Pu16OffTime == NULL)
	{
		Local_u8Error = STD_TYPES_u8_ERROR_NOK;
	}
	else
	{
		*Copy_Pu16OffTime = Global_u16PwmOFF_Time * TIMER_1_u8_TICK_TIME;
	}
	/* Function Return                                                                                                             */
	return Local_u8Error;
}


/**********************************************************************************************************************
 * Description:Function to get the period of the PWM
 * Outputs   : Error State
 * Inputs    : *Copy_Pu32OnTime : pointer to u32 variable to save the period time in it
 **********************************************************************************************************************/
u8 TIMER_u8GetPwmPeriod (u32 *Copy_Pu32Period)
{
	/* Local Variable indication for Error status                                                                                  */
	u16 Local_u8Error = STD_TYPES_u8_ERROR_OK;
	if (Copy_Pu32Period == NULL)
	{
		Local_u8Error = STD_TYPES_u8_ERROR_NOK;
	}
	else
	{
		*Copy_Pu32Period = ((Global_u16PwmON_Time + Global_u16PwmOFF_Time)* TIMER_1_u8_TICK_TIME);
	}
	/* Function Return                                                                                                             */
	return Local_u8Error;
}


/**********************************************************************************************************************
 * Description:Function to get the Duty cycle of the PWM
 * Outputs   : Error State
 * Inputs    : *Copy_Pu32OnTime : pointer to u8 variable to save the duty cycle in it
 **********************************************************************************************************************/
u8 TIMER_u8GetPwmDutyCycle (u8 *Copy_Pu8DutyCycle)
{
	/* Local Variable indication for Error status                                                                                  */
	u16 Local_u8Error = STD_TYPES_u8_ERROR_OK;
	if (Copy_Pu8DutyCycle == NULL)
	{
		Local_u8Error = STD_TYPES_u8_ERROR_NOK;
	}
	else
	{
		*Copy_Pu8DutyCycle = ((Global_u16PwmON_Time * TIMER_1_u8_TICK_TIME * 100) / ((Global_u16PwmON_Time + Global_u16PwmOFF_Time)* 1.0));
	}
	/* Function Return                                                                                                             */
	return Local_u8Error;
}


/**********************************************************************************************************
 * Description:Private Function to set timer0 in overflow mode and adjust it's settings
 * Outputs   : None
 * Inputs    : None
 ***********************************************************************************************************/
static void TIMER_VidTimer0_Overflow_Initialize (void)
{
	/*Set the timer counter control register with the preload value to start counting from this value                             */
	TIMER_u8_TCNT0 = TIMER_0_u8_PRELOAD;
	/*Enable the overflow interrupt                                                                                               */
	TIMERS_u8_TIMSK |= (1<<TIMER_u8_TIMSK_TOIE0);
	/*Enable global interrupts in MC by setting the I-Bit                                                                         */
	MCU_VidEnableGlobalINTP();
	/* set the overflow mode through this register                                                                                */
	TIMER_u8_TCCR0 = (1 << TIMER_u8_TCCR0_FOC0 );
	return;
}


/**********************************************************************************************************
 * Description:Private Function to set timer1 in overflow mode and adjust it's settings
 * Outputs   : None
 * Inputs    : None
 ***********************************************************************************************************/
static void TIMER_VidTimer1_Overflow_Initialize (void)
{
	/*Set the timer counter control register with the preload value to start counting from this value                            */
	//TIMER_u16_TCNT1 = TIMER_1_u16_PRELOAD;
	/*We shift the preload value by 8 bits to right to put the most 8 bits in TCTNTH                                             */
	TIMER_u8_TCNT1H = TIMER_1_u16_PRELOAD >> TIMER_u8_ACCESS_REG_NUM_BITS;
	/*Cast to u8 to access the least 8 bits and put them in the TCNT1L                                                           */
	TIMER_u8_TCNT1L = (u8)TIMER_1_u16_PRELOAD ;
	/*Enable the overflow interrupt                                                                                              */
	TIMERS_u8_TIMSK |= (1<<TIMER_u8_TIMSK_TOIE1);
	/*Enable global interrupts in MC by setting the I-Bit                                                                        */
	MCU_VidEnableGlobalINTP();
	/* set the overflow mode through these registers                                                                             */
	TIMER_u8_TCCR1A = (1 << TIMER_u8_TCCR1A_FOC1A) | (1 << TIMER_u8_TCCR1A_FOC1B) ;
	TIMER_u8_TCCR1B = 0X00;
	return;
}


/**********************************************************************************************************
 * Description:Private Function to set timer2 in overflow mode and adjust it's settings
 * Outputs   : None
 * Inputs    : None
 ***********************************************************************************************************/
static void TIMER_VidTimer2_Overflow_Initialize (void)
{
	/*Set the timer counter control register with the preload value to start counting from this value             */
	TIMER_u8_TCNT2 = TIMER_2_u8_PRELOAD;
	/*Enable the overflow interrupt                                                                               */
	TIMERS_u8_TIMSK |= (1<<TIMER_u8_TIMSK_TOIE2);
	/*Enable global interrupts in MC by setting the I-Bit                                                         */
	MCU_VidEnableGlobalINTP();
	/* set the overflow mode through this register                                                                */
	TIMER_u8_TCCR2 = (1 << TIMER_u8_TCCR2_FOC2 );
	return;
}


/**********************************************************************************************************
 * Description:Private Function to set timer0 in clear timer compare mode and adjust it's settings
 * Outputs   : None
 * Inputs    : None
 ***********************************************************************************************************/
static void TIMER_VidTimer0_CTC_Initialize (void)
{
	/*Set the timer counter control register with the zero value to start counting from this value             */
	TIMER_u8_TCNT0 = 0x00;
	/*Enable the output compare interrupt                                                                      */
	TIMERS_u8_TIMSK |= (1<<TIMER_u8_TIMSK_OCIE0);
	/* The value required to be put in the OCR0 register where an ISR is executed when TCNT0 reaches this value*/
	TIMER_u8_OCR0 = TIMER_0_u8_COMP_MATCH_VALUE;
	/*Enable global interrupts in MC by setting the I-Bit                                                      */
	MCU_VidEnableGlobalINTP();
	/*Switch on the submode                                                                                    */
	switch(TIMER_0_u8_CTC_SUBMODE )
	{
	/* OC0 is not connected                                                                                    */
	case TIMER_0_CTC_OC0_DISCONNECTED:
		TIMER_u8_TCCR0 = (1 << TIMER_u8_TCCR0_FOC0 ) | (1 << TIMER_u8_TCCR0_WGM01);
		break;
		/*Toggle OC0 on compare match                                                                          */
	case TIMER_0_CTC_OC0_TOGGLE_ON_COMP:
		TIMER_u8_TCCR0 = (1 << TIMER_u8_TCCR0_FOC0 ) | (1 << TIMER_u8_TCCR0_COM00 ) | (1 << TIMER_u8_TCCR0_WGM01);
		break;
		/*Clear OC0 on compare match                                                                          */
	case TIMER_0_CTC_OC0_CLEAR_ON_COMP:
		TIMER_u8_TCCR0 = (1 << TIMER_u8_TCCR0_FOC0 ) | (1 << TIMER_u8_TCCR0_COM01 ) | (1 << TIMER_u8_TCCR0_WGM01);
		break;
		/*Set OC0 on compare match                                                                            */
	case TIMER_0_CTC_OC0_SET_ON_COMP:
		TIMER_u8_TCCR0 = (1 << TIMER_u8_TCCR0_FOC0 ) | (1 << TIMER_u8_TCCR0_COM01 ) | (1 << TIMER_u8_TCCR0_COM00 ) | (1 << TIMER_u8_TCCR0_WGM01);
		break;
	}
	return;
}


/****************************************************************************************************************************
 * Description:Private Function to set timer1 in clear timer compare mode and adjust it's settings for channel A & channel B
 * Outputs   : None
 * Inputs    : None
 ****************************************************************************************************************************/
static void TIMER_VidTimer1_CTC_Initialize (void)
{
	/*Set the timer counter control register with the zero value to start counting from this value                  */
	TIMER_u8_TCNT1H = 0x00;
	TIMER_u8_TCNT1L = 0x00;
	/*if the output compare interrupt for channel A is enabled                                                      */
	if(TIMER_1_u8_OUTPUT_COMP_INT_A == TIMER_u8_ENABLE)
	{
		/*Enable the output compare interrupt for channel A                                                         */
		TIMERS_u8_TIMSK |= (1 << TIMER_u8_TIMSK_OCIE1A);
		/* The value required to be put in the OCR1A register where an ISR is executed when TCNT1 reaches this value*/
		/*while writing in a 16 bit register we write the High byte firstly then the low (reading -> vice versa)    */
		/*We shift the preload value by 8 bits to right to put the most 8 bits in OCR1AH                            */
		TIMER_u8_OCR1AH = TIMER_1_u16_COMP_MATCH_VALUE_A >> TIMER_u8_ACCESS_REG_NUM_BITS;
		/*Cast to u8 to access the least 8 bits and put them in the OCR1AL                                          */
		TIMER_u8_OCR1AL = (u8)TIMER_1_u16_COMP_MATCH_VALUE_A;
	}
	/*if the output compare interrupt for channel B is enabled                                                      */
	if(TIMER_1_u8_OUTPUT_COMP_INT_B == TIMER_u8_ENABLE)
	{
		/*Enable the output compare interrupt for channel B                                                         */
		TIMERS_u8_TIMSK |= (1 << TIMER_u8_TIMSK_OCIE1B);
		/* The value required to be put in the OCR1B register where an ISR is executed when TCNT1 reaches this value*/
		/*while writing in a 16 bit register we write the High byte firstly then the low (reading -> vice versa)    */
		/*We shift the preload value by 8 bits to right to put the most 8 bits in OCR1BH                            */
		TIMER_u8_OCR1BH = TIMER_1_u16_COMP_MATCH_VALUE_B >> TIMER_u8_ACCESS_REG_NUM_BITS;
		/*Cast to u8 to access the least 8 bits and put them in the OCR1BL                                          */
		TIMER_u8_OCR1BL = (u8)TIMER_1_u16_COMP_MATCH_VALUE_B;
	}
	/*Enable global interrupts in MC by setting the I-Bit                                                           */
	MCU_VidEnableGlobalINTP();
	/*Switch on the submode                                                                                         */
	switch(TIMER_1_u8_CTC_SUBMODE )
	{
	/* OC1A / OC1B is not connected                                                                                 */
	case TIMER_1_CTC_OC1A_OC1B_DISCONNECTED:
		TIMER_u8_TCCR1A = (1 << TIMER_u8_TCCR1A_FOC1A) | (1 << TIMER_u8_TCCR1A_FOC1B);
		TIMER_u8_TCCR1B = (1 << TIMER_u8_TCCR1B_WGM12);
		break;
		/*Toggle OC1A / OC1B on compare match                                                                       */
	case TIMER_1_CTC_OC1A_OC1B_TOGGLE_ON_COMP:
		TIMER_u8_TCCR1A = (1 << TIMER_u8_TCCR1A_COM1A0) | (1 << TIMER_u8_TCCR1A_COM1B0) | (1 << TIMER_u8_TCCR1A_FOC1A) | (1 << TIMER_u8_TCCR1A_FOC1B);
		TIMER_u8_TCCR1B = (1 << TIMER_u8_TCCR1B_WGM12);
		break;
		/*Clear OC1A / OC1B on compare match                                                                        */
	case TIMER_1_CTC_OC1A_OC1B_CLEAR_ON_COMP:
		TIMER_u8_TCCR1A = (1 << TIMER_u8_TCCR1A_COM1A1) | (1 << TIMER_u8_TCCR1A_COM1B1) | (1 << TIMER_u8_TCCR1A_FOC1A) | (1 << TIMER_u8_TCCR1A_FOC1B);
		TIMER_u8_TCCR1B = (1 << TIMER_u8_TCCR1B_WGM12);
		break;
		/*Set OC1A / OC1B on compare match                                                                          */
	case TIMER_1_CTC_OC1A_OC1B_SET_ON_COMP:
		TIMER_u8_TCCR1A = (1 << TIMER_u8_TCCR1A_COM1A1) | (1 << TIMER_u8_TCCR1A_COM1A0) | (1 << TIMER_u8_TCCR1A_COM1B1) | (1 << TIMER_u8_TCCR1A_COM1B0) | (1 << TIMER_u8_TCCR1A_FOC1A) | (1 << TIMER_u8_TCCR1A_FOC1B);
		TIMER_u8_TCCR1B = (1 << TIMER_u8_TCCR1B_WGM12);
		break;
	}
	return;
}


/**********************************************************************************************************
 * Description:Private Function to set timer2 in clear timer compare mode and adjust it's settings
 * Outputs   : None
 * Inputs    : None
 ***********************************************************************************************************/
static void TIMER_VidTimer2_CTC_Initialize (void)
{
	/*Set the timer counter control register with the zero value to start counting from this value             */
	TIMER_u8_TCNT2 = 0x00;
	/*Enable the output compare interrupt                                                                      */
	TIMERS_u8_TIMSK |= (1<<TIMER_u8_TIMSK_OCIE2);
	/* The value required to be put in the OCR2 register where an ISR is executed when TCNT2 reaches this value*/
	TIMER_u8_OCR2 = TIMER_2_u8_COMP_MATCH_VALUE;
	/*Enable global interrupts in MC by setting the I-Bit                                                      */
	MCU_VidEnableGlobalINTP();
	/*Switch on the submode                                                                                    */
	switch(TIMER_2_u8_CTC_SUBMODE )
	{
	/* OC2 is not connected                                                                                    */
	case TIMER_2_CTC_OC2_DISCONNECTED:
		TIMER_u8_TCCR2 = (1 << TIMER_u8_TCCR2_FOC2 ) | (1 << TIMER_u8_TCCR2_WGM21);
		break;
		/*Toggle OC2 on compare match                                                                          */
	case TIMER_2_CTC_OC2_TOGGLE_ON_COMP:
		TIMER_u8_TCCR2 = (1 << TIMER_u8_TCCR2_FOC2 ) | (1 << TIMER_u8_TCCR2_COM20 ) | (1 << TIMER_u8_TCCR2_WGM21);
		break;
		/*Clear OC2 on compare match                                                                          */
	case TIMER_2_CTC_OC2_CLEAR_ON_COMP:
		TIMER_u8_TCCR2 = (1 << TIMER_u8_TCCR2_FOC2 ) | (1 << TIMER_u8_TCCR2_COM21 ) | (1 << TIMER_u8_TCCR2_WGM21);
		break;
		/*Set OC2 on compare match                                                                            */
	case TIMER_2_CTC_OC2_SET_ON_COMP:
		TIMER_u8_TCCR2 = (1 << TIMER_u8_TCCR2_FOC2 ) | (1 << TIMER_u8_TCCR2_COM21 ) | (1 << TIMER_u8_TCCR2_COM20 ) | (1 << TIMER_u8_TCCR2_WGM21);
		break;
	}
	return;
}


/**********************************************************************************************************
 * Description:Private Function to set timer0 in fast PWM mode and adjust it's settings
 * Outputs   : None
 * Inputs    : None
 ***********************************************************************************************************/
static void TIMER_VidTimer0_FastPWM_Initialize (void)
{
	/*Set the timer counter control register with the zero value to start counting from this value             */
	TIMER_u8_TCNT0 = 0x00;
	/*Enable global interrupts in MC by setting the I-Bit                                                      */
	MCU_VidEnableGlobalINTP();
	switch(TIMER_0_u8_PWM_SUBMODE)
	{
	/* OC0 is not connected                                                                                    */
	case TIMER_0_PWM_OC0_DISCONNECTED: TIMER_u8_TCCR0 = (1 << TIMER_u8_TCCR0_WGM00) | (1 << TIMER_u8_TCCR0_WGM01);
	break;
	/*Clear OC0 on compare match                                                                               */
	case TIMER_0_PWM_OC0_CLEAR_ON_COMP_NOT_INVERTED: TIMER_u8_TCCR0 = (1 << TIMER_u8_TCCR0_WGM00) | (1 << TIMER_u8_TCCR0_COM01) | (1 << TIMER_u8_TCCR0_WGM01);
	break;
	/*Set OC0 on compare match                                                                                 */
	case TIMER_0_PWM_OC0_SET_ON_COMP_INVERTED: TIMER_u8_TCCR0 = (1 << TIMER_u8_TCCR0_WGM00) | (1 << TIMER_u8_TCCR0_COM01) | (1 << TIMER_u8_TCCR0_COM00) | (1 << TIMER_u8_TCCR0_WGM01);
	break;
	}
	return;
}


/**********************************************************************************************************
 * Description:Private Function to set timer1 in fast PWM mode and adjust it's settings
 * Outputs   : None
 * Inputs    : None
 ***********************************************************************************************************/
static void TIMER_VidTimer1_FastPWM_Initialize (void)
{

	/*Set the timer counter control register with the zero value to start counting from this value             */
	//TIMER_u8_TCNT1H = 0x00;
	//TIMER_u8_TCNT1L = 0x00;
	/*Enable global interrupts in MC by setting the I-Bit                                                      */
	MCU_VidEnableGlobalINTP();
	switch (TIMER_1_u8_PWM_SUBMODE)
	{
	/* OC1A / OC1B is not connected                                                                            */
	case TIMER_1_PWM_OC1A_OC1B_DISCONNECTED:
		TIMER_u8_TCCR1A = (1 << TIMER_u8_TCCR1A_WGM11) | (1 << TIMER_u8_TCCR1A_WGM10);
		TIMER_u8_TCCR1B = (1 << TIMER_u8_TCCR1B_WGM13) | (1 << TIMER_u8_TCCR1B_WGM12);
		break;
		/*Toggle OC1A / Disconnect OC1B on compare match                                                       */
	case TIMER_1_PWM_TOGGLE_OC1A_DISCONNECTED_OC1B :
		if (TIMER_1_u8_OUTPUT_COMP_A == TIMER_u8_ENABLE)
		{
			TIMER_u8_TCCR1A = (1 << TIMER_u8_TCCR1A_COM1A0) | (1 << TIMER_u8_TCCR1A_WGM11) | (1 << TIMER_u8_TCCR1A_WGM10);
		}
		if (TIMER_1_u8_OUTPUT_COMP_B == TIMER_u8_ENABLE)
		{
			TIMER_u8_TCCR1A = (1 << TIMER_u8_TCCR1A_COM1B0) | (1 << TIMER_u8_TCCR1A_WGM11) | (1 << TIMER_u8_TCCR1A_WGM10);
		}
		TIMER_u8_TCCR1B = (1 << TIMER_u8_TCCR1B_WGM13) | (1 << TIMER_u8_TCCR1B_WGM12);
		break;
		/*Clear OC1A / OC1B on compare match                                                                   */
	case TIMER_1_PWM_OC1A_OC1B_CLEAR_ON_COMP_NOT_INVERTED:
		if (TIMER_1_u8_OUTPUT_COMP_A == TIMER_u8_ENABLE)
		{
			TIMER_u8_TCCR1A = (1 << TIMER_u8_TCCR1A_COM1A1) | (1 << TIMER_u8_TCCR1A_WGM11) | (1 << TIMER_u8_TCCR1A_WGM10);
			TIMER_u8_TCCR1B = (1 << TIMER_u8_TCCR1B_WGM13) | (1 << TIMER_u8_TCCR1B_WGM12);
		}
		if (TIMER_1_u8_OUTPUT_COMP_B == TIMER_u8_ENABLE)
		{
			TIMER_u8_TCCR1A = (1 << TIMER_u8_TCCR1A_COM1B1) | (1 << TIMER_u8_TCCR1A_WGM11) | (1 << TIMER_u8_TCCR1A_WGM10);
		}

		break;
		/*Set OC1A / OC1B on compare match                                                                    */
	case TIMER_1_PWM_OC1A_OC1B_SET_ON_COMP_INVERTED:
		if (TIMER_1_u8_OUTPUT_COMP_A == TIMER_u8_ENABLE)
		{
			TIMER_u8_TCCR1A = (1 << TIMER_u8_TCCR1A_COM1A1) | (1 << TIMER_u8_TCCR1A_COM1A0) | (1 << TIMER_u8_TCCR1A_WGM11) | (1 << TIMER_u8_TCCR1A_WGM10);
		}
		if (TIMER_1_u8_OUTPUT_COMP_B == TIMER_u8_ENABLE)
		{
			TIMER_u8_TCCR1A = (1 << TIMER_u8_TCCR1A_COM1B1) | (1 << TIMER_u8_TCCR1A_COM1B0) | (1 << TIMER_u8_TCCR1A_WGM11) | (1 << TIMER_u8_TCCR1A_WGM10);
		}
		TIMER_u8_TCCR1B = (1 << TIMER_u8_TCCR1B_WGM13) | (1 << TIMER_u8_TCCR1B_WGM12);
		break;
	}
	return;
}


/**********************************************************************************************************
 * Description:Private Function to set timer2 in fast PWM mode and adjust it's settings
 * Outputs   : None
 * Inputs    : None
 ***********************************************************************************************************/
static void TIMER_VidTimer2_FastPWM_Initialize (void)
{
	/*Set the timer counter control register with the zero value to start counting from this value             */
	TIMER_u8_TCNT2 = 0x00;
	/*Enable global interrupts in MC by setting the I-Bit                                                      */
	MCU_VidEnableGlobalINTP();
	switch(TIMER_2_u8_PWM_SUBMODE)
	{
	/* OC2 is not connected                                                                                    */
	case TIMER_2_PWM_OC2_DISCONNECTED: TIMER_u8_TCCR2 = (1 << TIMER_u8_TCCR2_WGM20) | (1 << TIMER_u8_TCCR2_WGM21);
	break;
	/*Clear OC2 on compare match                                                                               */
	case TIMER_2_PWM_OC2_CLEAR_ON_COMP_NOT_INVERTED: TIMER_u8_TCCR2 = (1 << TIMER_u8_TCCR2_WGM20) | (1 << TIMER_u8_TCCR2_COM21) | (1 << TIMER_u8_TCCR2_WGM21);
	break;
	/*Set OC2 on compare match                                                                               */
	case TIMER_2_PWM_OC2_SET_ON_COMP_INVERTED: TIMER_u8_TCCR2 = (1 << TIMER_u8_TCCR2_WGM20) | (1 << TIMER_u8_TCCR2_COM21) | (1 << TIMER_u8_TCCR2_COM20) | (1 << TIMER_u8_TCCR2_WGM21);
	break;
	}
	return;
}


/**********************************************************************************************************
 * Description:Private Function to set timer0 in phase correct mode and adjust it's settings
 * Outputs   : None
 * Inputs    : None
 ***********************************************************************************************************/
static void TIMER_VidTimer0_PhaseCorrectPWM_Initialize (void)
{
	/*Set the timer counter control register with the zero value to start counting from this value             */
	TIMER_u8_TCNT0 = 0x00;
	/*Enable global interrupts in MC by setting the I-Bit                                                      */
	MCU_VidEnableGlobalINTP();
	switch(TIMER_0_u8_PHASE_CORRECT_SUBMODE)
	{
	/* OC0 is not connected                                                                                    */
	case TIMER_0_PHASE_CORRECT_OC0_DISCONNECTED: TIMER_u8_TCCR0 = (1 << TIMER_u8_TCCR0_WGM00) ;
	break;
	/*Clear OC0 on compare match while up counting and set OC0 on compare match while down counting            */
	case TIMER_0_PHASE_CORRECT_OC0_CLEAR_UP_SET_DOWN_COUNT: TIMER_u8_TCCR0 = (1 << TIMER_u8_TCCR0_WGM00) | (1 << TIMER_u8_TCCR0_COM01);
	break;
	/*Set OC0 on compare match while up counting and clear OC0 on compare match while down counting            */
	case TIMER_0_PHASE_CORRECT_OC0_SET_UP_CLEAR_DOWN_COUNT: TIMER_u8_TCCR0 = (1 << TIMER_u8_TCCR0_WGM00) | (1 << TIMER_u8_TCCR0_COM01) | (1 << TIMER_u8_TCCR0_COM00);
	break;
	}
	return;
}



/**********************************************************************************************************
 * Description:Private Function to set timer1 in phase correct mode and adjust it's settings
 * Outputs   : None
 * Inputs    : None
 ***********************************************************************************************************/
static void TIMER_VidTimer1_PhaseCorrectPWM_Initialize (void)
{
	/*Set the timer counter control register with the zero value to start counting from this value                  */
	//TIMER_u8_TCNT1H = 0x00;
	//TIMER_u8_TCNT1L = 0x00;
	/*Enable global interrupts in MC by setting the I-Bit                                                           */
	MCU_VidEnableGlobalINTP();
	switch(TIMER_1_u8_PHASE_CORRECT_SUBMODE)
	{
	/* OC1A / OC1B is not connected                                                                                 */
	case TIMER_1_PHASE_CORRECT_OC1A_OC1B_DISCONNECTED:
		TIMER_u8_TCCR1A = (1 << TIMER_u8_TCCR1A_WGM11) | (1 << TIMER_u8_TCCR1A_WGM10);
		TIMER_u8_TCCR1B = (1 << TIMER_u8_TCCR1B_WGM13);
		break;
		/*Toggle OC1A and disconnect OCR1B  on compare match                                                        */
	case TIMER_1_PHASE_CORRECT_TOGGLE_OC1A_DISCONNECTED_OC1B:
		TIMER_u8_TCCR1A = (1 << TIMER_u8_TCCR1A_COM1A0) | (1 << TIMER_u8_TCCR1A_COM1B0) | (1 << TIMER_u8_TCCR1A_WGM11) | (1 << TIMER_u8_TCCR1A_WGM10);
		TIMER_u8_TCCR1B = (1 << TIMER_u8_TCCR1B_WGM13);
		break;
		/*Clear OC1A / OC1B on compare match while up counting and set OC1A/OC1B on compare match while down counting*/
	case TIMER_1_PHASE_CORRECT_OC1A_OC1B_CLEAR_UP_SET_DOWN_COUNT:
		TIMER_u8_TCCR1A = (1 << TIMER_u8_TCCR1A_COM1A1) | (1 << TIMER_u8_TCCR1A_COM1B1) | (1 << TIMER_u8_TCCR1A_WGM11) | (1 << TIMER_u8_TCCR1A_WGM10);
		TIMER_u8_TCCR1B = (1 << TIMER_u8_TCCR1B_WGM13);
		break;
		/*Set OC1A / OC1B on compare match while up counting and clear OC1A/OC1B on compare match while down counting*/
	case TIMER_1_PHASE_CORRECT_OC1A_OC1B_SET_UP_CLEAR_DOWN_COUNT:
		TIMER_u8_TCCR1A = (1 << TIMER_u8_TCCR1A_COM1A1) | (1 << TIMER_u8_TCCR1A_COM1A0) | (1 << TIMER_u8_TCCR1A_COM1B1) | (1 << TIMER_u8_TCCR1A_COM1B0) | (1 << TIMER_u8_TCCR1A_WGM11) | (1 << TIMER_u8_TCCR1A_WGM10);
		TIMER_u8_TCCR1B = (1 << TIMER_u8_TCCR1B_WGM13);
		break;
	}
	return;
}


/**********************************************************************************************************
 * Description:Private Function to set timer2 in phase correct mode and adjust it's settings
 * Outputs   : None
 * Inputs    : None
 ***********************************************************************************************************/
static void TIMER_VidTimer2_PhaseCorrectPWM_Initialize (void)
{
	/*Set the timer counter control register with the zero value to start counting from this value             */
	TIMER_u8_TCNT2 = 0x00;
	/*Enable global interrupts in MC by setting the I-Bit                                                      */
	MCU_VidEnableGlobalINTP();
	switch(TIMER_2_u8_PHASE_CORRECT_SUBMODE)
	{
	/* OC2 is not connected                                                                                    */
	case TIMER_2_PHASE_CORRECT_OC2_DISCONNECTED: TIMER_u8_TCCR2 = (1 << TIMER_u8_TCCR2_WGM20) ;
	break;
	/*Clear OC2 on compare match while up counting and set OC2 on compare match while down counting            */
	case TIMER_2_PHASE_CORRECT_OC2_CLEAR_UP_SET_DOWN_COUNT: TIMER_u8_TCCR2 = (1 << TIMER_u8_TCCR2_WGM20) | (1 << TIMER_u8_TCCR2_COM21);
	break;
	/*Set OC2 on compare match while up counting and clear OC2 on compare match while down counting            */
	case TIMER_2_PHASE_CORRECT_OC2_SET_UP_CLEAR_DOWN_COUNT: TIMER_u8_TCCR2 = (1 << TIMER_u8_TCCR2_WGM20) | (1 << TIMER_u8_TCCR2_COM21) | (1 << TIMER_u8_TCCR2_COM20);
	break;
	}
	return;

}


/****************************************************************************************************
 * Description:Function to Set the pointer to callback function with the address of the function
 *              Needed to be implemented by the ISR.
 * Outputs   : Error State
 * Inputs    : void (*Copy_PVidFunCallback) (void): pointer to callback function to set the pointer
 *             Value with the address of the function needed to be implemented by the ISR.
 *             Copy_u8Timer_INT_index             : Interrupt Index number
 ***************************************************************************************************/
u8 TIMER_u8SetCallback (u8 Copy_u8Timer_INT_Index , void (*Copy_PVidFunCallback) (void))
{
	/* Local Variable indication for Error status                                            */
	u8 Local_u8Error = STD_TYPES_u8_ERROR_OK;
	/* Input arguments validation                                                            */
	if (Copy_u8Timer_INT_Index >= Timer_u8_NUM_INTERRUPTS)
	{
		Local_u8Error = STD_TYPES_u8_ERROR_NOK;
	}
	else
	{
		/* Set the pointer with address of the function needed to be implemented by the ISR  */
		PVidFunCallback[Copy_u8Timer_INT_Index] = Copy_PVidFunCallback;
	}
	/* Function Return                                                                       */
	return Local_u8Error;
}



/***********************************************************************************************************
 * Description:Timer2 Compare Match Interrupt Service Routine which includes a pointer points to a function
 *             Send by user to be implemented.
 * Outputs    :Error State
 * Inputs     :None
 **********************************************************************************************************/
void __vector_4 (void)
{
	/* Local variable needed by the ISR to count the number of compare match overflow counts                    */
	static u32 TIMER_u32LocalTimer2Counter_CTC =0;
	/* Pointer validation                                                                                       */
	if (PVidFunCallback[TIMER_u8_TIMER2_COMP] != NULL)
	{
		/* Increment timer counter                                                                              */
		TIMER_u32LocalTimer2Counter_CTC ++;
		/* if the counter reaches the number of overflow output compare counts required to reach a specific time*/
		if(TIMER_u32LocalTimer2Counter_CTC == TIMER_2_u32_OVF_COMP_MATCH_COUNTS)
		{
			/* return the counter to zero again to be able to receive another interrupt                        */
			TIMER_u32LocalTimer2Counter_CTC = 0;
			/* Set the OCR2 with value where an ISR is executed when TCNT2 matches this value again            */
			TIMER_u8_OCR2 = TIMER_2_u8_COMP_MATCH_VALUE;
			/* ISR of Timer2 Compare Match Interrupt Function calling                                          */
			PVidFunCallback[TIMER_u8_TIMER2_COMP] ();
		}
	}
	return;
}

/***********************************************************************************************************
 * Description:Timer2 Overflow Interrupt Service Routine which includes a pointer points to a function
 *             Send by user to be implemented.
 * Outputs    :Error State
 * Inputs     :None
 **********************************************************************************************************/
void __vector_5 (void)
{
	/* Local variable needed by the ISR to count the number of overflow counts                                                       */
	static u32 TIMER_u32LocalTimer2Counter_OVF =0;
	/* Pointer validation                                         */
	if (PVidFunCallback[TIMER_u8_TIMER2_OVF] != NULL)
	{
		/* Increment timer counter                                                                                                   */
		TIMER_u32LocalTimer2Counter_OVF ++;
		/* if the counter reaches the number of overflows counts required to reach a specific time                                   */
		if(TIMER_u32LocalTimer2Counter_OVF == TIMER_2_u32_OVF_COUNTS)
		{
			/* return the counter to zero again to be able to receive another interrupt                                             */
			TIMER_u32LocalTimer2Counter_OVF = 0;
			/* Set the TCNT2 with the preload to be able to execute another ISR and the timer starts counting from this value again */
			TIMER_u8_TCNT2 = TIMER_2_u8_PRELOAD ;
			/* ISR of Timer2 Compare Match Interrupt Function calling                                                               */
			PVidFunCallback[TIMER_u8_TIMER2_OVF] ();
		}
	}
	return;
}


/***********************************************************************************************************
 * Description:Timer1 Capture event Interrupt Service Routine to be implemented when an interrupt capture event occurs
 * Outputs    :None
 * Inputs     :None
 **********************************************************************************************************/
void __vector_6 (void)
{
	/*Local variable to save the number of counts saved in the ICR1                                                                 */
	static u16 Local_u16Time = 0;
	/*Flag to switch between the falling & rising events                                                                            */
	static u8 Local_u8Flag = 0;
	/*Local variable to save the old value which is saved in the ICR                                                                */
	static u16 Local_u16OldTime = 0;
	/* we take the timer value first to save the time wasted                                                                        */
	Local_u16Time = TIMER_u16_ICR1;

	/* PWM calculations at Rising edge event to calculate the OFF time                                                              */
	if (Local_u8Flag == 0)
	{
		/* here we calculate the off time as at the rising edge the number of counts was for the off time                           */
		/*3shan l rising edge l time l ablha kan bta3 falling y3ny off time                                                         */
		Global_u16PwmOFF_Time  = Local_u16Time - Local_u16OldTime;
		/* change the sense level to falling edge to be able to sense the next interrupt                                            */
		TIMER_u8_TCCR1B &= (~(1 << TIMER_u8_TCCR1B_ICES1));
		/*Flag = 1 to let the ISR the next time enters the Falling edge calculations                                                */
		Local_u8Flag  = 1;
	}
	/* PWM calculations at Falling edge event to calculate the ON time                                                              */
	else
	{
		/* here we calculate the on time as at the falling edge the number of counts was for the on time                            */
		/*3shan l falling edge l time l ablha kan bta3 rising y3ny on time                                                          */
		Global_u16PwmON_Time  = Local_u16Time - Local_u16OldTime;
		/* change the sense level to rising edge to be able to sense the next interrupt                                            */
		TIMER_u8_TCCR1B |= (1 << TIMER_u8_TCCR1B_ICES1);
		/*Flag = 0 to let the ISR the next time enters the rising edge calculations                                                */
		Local_u8Flag  = 0;
	}
	/*make the old time = ICR value to calculate the on time correctly in the next iteration and avoid the percentage of error  */
	Local_u16OldTime = TIMER_u16_ICR1;
}


/***********************************************************************************************************
 * Description:Timer1 Compare Match A Interrupt Service Routine which includes a pointer points to a function
 *             Send by user to be implemented.
 * Outputs    :Error State
 * Inputs     :None
 **********************************************************************************************************/
void __vector_7 (void)
{
	/* Local variable needed by the ISR to count the number of compare match overflow counts                        */
	static u32 TIMER_u32LocalTimer1Counter_CTC_A = 0;
	/* Pointer validation                                         */
	if (PVidFunCallback[TIMER_u8_TIMER1_COMPA] != NULL)
	{
		/* Increment timer counter                                                                                  */
		TIMER_u32LocalTimer1Counter_CTC_A ++;
		/* if the counter reaches the number of overflow output compare counts required to reach a specific time    */
		if(TIMER_u32LocalTimer1Counter_CTC_A == TIMER_1_u32_OVF_COMP_MATCH_COUNTS_A)
		{
			/* return the counter to zero again to be able to receive another interrupt                             */
			TIMER_u32LocalTimer1Counter_CTC_A = 0;
			/*Put in the OCR1A register a value where an ISR is executed when TCNT1 matches this value again        */
			/*while writing in a 16 bit register we write the High byte firstly then the low (reading -> vice versa)*/
			/*We shift the preload value by 8 bits to right to put the most 8 bits in OCR1AH                        */
			TIMER_u8_OCR1AH = TIMER_1_u16_COMP_MATCH_VALUE_A >> TIMER_u8_ACCESS_REG_NUM_BITS;
			/*Cast to u8 to access the least 8 bits and put them in the OCR1AL                                      */
			TIMER_u8_OCR1AL = (u8)TIMER_1_u16_COMP_MATCH_VALUE_A;
			/* ISR of Timer1 Compare Match A Interrupt Function calling                                             */
			PVidFunCallback[TIMER_u8_TIMER1_COMPA] ();
		}
	}
	return;
}


/***********************************************************************************************************
 * Description:Timer1 Compare Match B Interrupt Service Routine which includes a pointer points to a function
 *             Send by user to be implemented.
 * Outputs    :Error State
 * Inputs     :None
 **********************************************************************************************************/
void __vector_8 (void)
{
	/* Local variable needed by the ISR to count the number of compare match overflow counts                        */
	static u32 TIMER_u32LocalTimer1Counter_CTC_B = 0;
	/* Pointer validation                                                                                           */
	if (PVidFunCallback[TIMER_u8_TIMER1_COMPB] != NULL)
	{
		/* Increment timer counter                                                                                  */
		TIMER_u32LocalTimer1Counter_CTC_B ++;
		/* if the counter reaches the number of overflow output compare counts required to reach a specific time    */
		if(TIMER_u32LocalTimer1Counter_CTC_B == TIMER_1_u32_OVF_COMP_MATCH_COUNTS_B)
		{
			/* return the counter to zero again to be able to receive another interrupt                             */
			TIMER_u32LocalTimer1Counter_CTC_B = 0;
			/*Put in the OCR1B register a value where an ISR is executed when TCNT1 matches this value again        */
			/*while writing in a 16 bit register we write the High byte firstly then the low (reading -> vice versa)*/
			/*We shift the preload value by 8 bits to right to put the most 8 bits in OCR1BH                        */
			TIMER_u8_OCR1BH = TIMER_1_u16_COMP_MATCH_VALUE_B >> TIMER_u8_ACCESS_REG_NUM_BITS;
			/*Cast to u8 to access the least 8 bits and put them in the OCR1BL                                      */
			TIMER_u8_OCR1BL = (u8)TIMER_1_u16_COMP_MATCH_VALUE_B;
			/* ISR of Timer1 Compare Match B Interrupt Function calling                                             */
			PVidFunCallback[TIMER_u8_TIMER1_COMPB] ();
		}
	}
	return;
}


/***********************************************************************************************************
 * Description:Timer1 Overflow Interrupt Service Routine which includes a pointer points to a function
 *             Send by user to be implemented.
 * Outputs    :Error State
 * Inputs     :None
 **********************************************************************************************************/
void __vector_9 (void)
{
	/* Local variable needed by the ISR to count the number of overflow counts                                                       */
	static u32 TIMER_u32LocalTimer1Counter_OVF = 0;
	/* Pointer validation                                         */
	if (PVidFunCallback[TIMER_u8_TIMER1_OVF] != NULL)
	{
		/* Increment timer counter                                                                                                   */
		TIMER_u32LocalTimer1Counter_OVF ++;
		/* if the counter reaches the number of overflows counts required to reach a specific time                                   */
		if(TIMER_u32LocalTimer1Counter_OVF == TIMER_1_u32_OVF_COUNTS)
		{
			/* return the counter to zero again to be able to receive another interrupt                                             */
			TIMER_u32LocalTimer1Counter_OVF = 0;
			/* Set the TCNT1 with the preload to be able to execute another ISR and the timer starts counting from this value again */
			//TIMER_u16_TCNT1 = TIMER_1_u16_PRELOAD ;
			/*We shift the preload value by 8 bits to right to put the most 8 bits in TCTNTH                                        */
			TIMER_u8_TCNT1H = TIMER_1_u16_PRELOAD >> TIMER_u8_ACCESS_REG_NUM_BITS;
			/*Cast to u8 to access the least 8 bits and put them in the TCNT1L                                                      */
			TIMER_u8_TCNT1L = (u8)TIMER_1_u16_PRELOAD ;
			/* ISR of Timer1 Overflow Interrupt Function calling                                                                    */
			PVidFunCallback[TIMER_u8_TIMER1_OVF] ();
		}
	}
	return;
}


/***********************************************************************************************************
 * Description:Timer0 Compare Match Interrupt Service Routine which includes a pointer points to a function
 *             Send by user to be implemented.
 * Outputs    :Error State
 * Inputs     :None
 **********************************************************************************************************/
void __vector_10 (void)
{
	/* Local variable needed by the ISR to count the number of compare match overflow counts                    */
	static u32 TIMER_u32LocalTimer0Counter_CTC =0;
	/* Pointer validation                                                                                       */
	if (PVidFunCallback[TIMER_u8_TIMER0_COMP] != NULL)
	{
		/* Increment timer counter                                                                              */
		TIMER_u32LocalTimer0Counter_CTC ++;
		/* if the counter reaches the number of overflow output compare counts required to reach a specific time*/
		if(TIMER_u32LocalTimer0Counter_CTC == TIMER_0_u32_OVF_COMP_MATCH_COUNTS)
		{
			/* return the counter to zero again to be able to receive another interrupt                        */
			TIMER_u32LocalTimer0Counter_CTC = 0;
			/* Set the OCR0 with value where an ISR is executed when TCNT0 matches this value again            */
			TIMER_u8_OCR0 = TIMER_0_u8_COMP_MATCH_VALUE;
			/* ISR of Timer0 Compare Match Interrupt Function calling                                          */
			PVidFunCallback[TIMER_u8_TIMER0_COMP] ();
		}
	}
	return;
}


/***********************************************************************************************************
 * Description:Timer0 Overflow Interrupt Service Routine which includes a pointer points to a function
 *             Send by user to be implemented.
 * Outputs    :Error State
 * Inputs     :None
 **********************************************************************************************************/
void __vector_11 (void)
{
	/* Local variable needed by the ISR to count the number of overflow counts                                                       */
	static u32 TIMER_u32LocalTimer0Counter_OVF =0;
	/* Pointer validation                                         */
	if (PVidFunCallback[TIMER_u8_TIMER0_OVF] != NULL)
	{
		/* Increment timer counter                                                                                                   */
		TIMER_u32LocalTimer0Counter_OVF ++;
		/* if the counter reaches the number of overflows counts required to reach a specific time                                   */
		if(TIMER_u32LocalTimer0Counter_OVF == TIMER_0_u32_OVF_COUNTS)
		{
			/* return the counter to zero again to be able to receive another interrupt                                             */
			TIMER_u32LocalTimer0Counter_OVF = 0;
			/* Set the TCNT0 with the preload to be able to execute another ISR and the timer starts counting from this value again */
			TIMER_u8_TCNT0 = TIMER_0_u8_PRELOAD ;
			/* ISR of Timer0 Compare Match Interrupt Function calling                                                               */
			PVidFunCallback[TIMER_u8_TIMER0_OVF] ();
		}
	}
	return;
}
