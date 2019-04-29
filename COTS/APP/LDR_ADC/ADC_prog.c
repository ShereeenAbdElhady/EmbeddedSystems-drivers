/******************************************************************************************/
/*                                                                                       */
/* File Name   : ADC_prog.c                                                             */
/*                                                                                     */
/* Created on  : Apr 27, 2019                                                         */
/*                                                                                   */
/* Author      : shereen Abd Elhady                                                 */
/*                                                                                 */
/* Version     : V01                                                              */
/*                                                                               */
/* Description : software driver for Analog to digital converterfor AVR Atmega32*/
/*               includes Software automatic trigger using interrupt technique */
/*               & software single mode trigger using polling technique.      */
/*                                                                           */
/* Layer       : MCAL                                                       */
/***************************************************************************/


#include "STD_TYPES.h"
#include "ADC_interface.h"
#include "ADC_private.h"

/*Flag to indicate that the ADC completes the conversion of the whole channels connected to it*/
volatile u8  ADC_u8ConversionDoneFlag = 0;
/*Flag to start conversion for the first channel                                              */
u8 ADC_u8StartConversionFirstChFlag =0;
/*initialization for array of channels to start from index zero                               */
volatile u8 ADC_u8ChannelIndex =0;

/* pointer to function, pointer will carry the address of the function wanted to be implemented by the ISR                     */
/* Initialize the pointer with Null in the beginning to avoid this pointer from garbage value and implementation of wrong code */
/* Global & Static to be seen within this file only                                                                            */
static void (*PVidFunCallback) (void) = NULL ;

/*Array to store ADC Digital values after conversion (volatile as it is accessed in the ISR) */
volatile u16 ADC_u16ADCvalues[ADC_u8_NUM_CHANNELS_TO_CONVERT];


/*******************************************************************************
 * Description: Function to initialize ADC reference voltage, select prescaler,
 *              Set left & right adjustment finally enable the ADC.
 * Outputs   : None
 * Inputs    : None
 ******************************************************************************/
void ADC_Vidinit(void)
{
	/* Adjust reference voltage and left adjust result                                       */
#if (ADC_u8_LEFT_ADJUST_RESULT == ADC_u8_LEFT_ADJUST_RESULT_ON)
	{
		ADC_u8_ADMUX = (ADC_u8_REFERENCE_VOLTAGE << ADC_u8_REFS0_PIN) | (1 << ADC_u8_ADLAR_PIN);
	}
#elif (ADC_u8_LEFT_ADJUST_RESULT == ADC_u8_LEFT_ADJUST_RESULT_OFF)
	{
		ADC_u8_ADMUX = (ADC_u8_REFERENCE_VOLTAGE << ADC_u8_REFS0_PIN);
	}
#endif
	/* Enable ADC and adjust the prescaler                                                  */
	ADC_u8_ADCSRA = (1 << ADC_u8_ADEN_PIN) | (ADC_u8_PRESCALER_SELECTION << ADC_u8_ADPS0_PIN);
}


/*****************************************************************************************
 * Description: Function to select the ADC channel, start conversion and get the ADC
 *              digital value. (single conversion mode) (polling)
 * Outputs   : Error state
 * Inputs    : u16* Copy_Pu16PtrData : pointer  to variable to store digital value in it
 *             Copy_u8ChannelNb      : number of ADC channel which connected to a sensor
 ****************************************************************************************/
u8 ADC_u8GetADCBlocking(u16* Copy_Pu16PtrData , u8 Copy_u8ChannelNb)
{
	/* Local Variable indication for Error status                                          */
	u8 Local_u8Error = STD_TYPES_u8_ERROR_OK;
	/*input arguments validation                                                           */
	if ((Copy_Pu16PtrData == NULL) && (Copy_u8ChannelNb > ADC_u8_MAX_CH_NUM))
	{
		Local_u8Error = STD_TYPES_u8_ERROR_NOK;
	}
	else
	{
		/*ADC conversion complete interrupt disable                                        */
		ADC_u8_ADCSRA &= (~(1 << ADC_u8_ADIE_PIN));
		/* select channel number                                                           */
		ADC_u8_ADMUX |= (Copy_u8ChannelNb << ADC_u8_MUX0_PIN);
		/* Start conversion                                                                */
		ADC_u8_ADCSRA |= (1 << ADC_u8_ADCSC_PIN);
		/*wait as well as the ADIF equals to zero (polling)                                */
		/* when it turns to one, it means that the ADC conversion is complete              */
		while ( (((ADC_u8_ADCSRA) >> (ADC_u8_ADIF_PIN))&(0x01)) == 0 );
		/*in case of 8 bit resolution you have to adjust the result                        */
		/*to the left firstly then read the most 8 bits (high value)                       */
#if((ADC_u8_RESOLUTION == ADC_u8_8BIT_RESOLUTION) && (ADC_u8_LEFT_ADJUST_RESULT == ADC_u8_LEFT_ADJUST_RESULT_ON))
		{
			* Copy_Pu16PtrData = ADC_u8_ADCH;
		}
		/*in case of 10 bit resolution you have to read the least 8 bits(low)              */
		/*firstly then read the most 8 bits(high)                                          */
#elif((ADC_u8_RESOLUTION == ADC_u8_10BIT_RESOLUTION) && (ADC_u8_LEFT_ADJUST_RESULT == ADC_u8_LEFT_ADJUST_RESULT_OFF))
		{
			* Copy_Pu16PtrData = ADC_u8_ADCL;
			* Copy_Pu16PtrData |= (ADC_u8_ADCH << ADC_u8_SHIFT_HIGH_8BITS );
		}
		/*in case of 10 bit resolution you have to read the least 8 bits(low)              */
		/*firstly then read the most 8 bits(high)                                          */
#elif((ADC_u8_RESOLUTION == ADC_u8_10BIT_RESOLUTION) && (ADC_u8_LEFT_ADJUST_RESULT == ADC_u8_LEFT_ADJUST_RESULT_ON))
		{
			* Copy_Pu16PtrData = ADC_u8_ADCL;
			* Copy_Pu16PtrData |= (ADC_u8_ADCH << ADC_u8_SHIFT_HIGH_2BITS );
		}
#endif
	}
	/*Clear flag after conversion is complete it is cleared automatically in case of interrupts*/
	ADC_u8_ADCSRA |= (1 << ADC_u8_ADIF_PIN);
	/* Function Return                                                                     */
	return Local_u8Error;
}


/*****************************************************************************************
 * Description: Function to start the conversion of the first channel by selecting
 *              the channel number from an array contains a number of channels needed to be
 *              converted then enabling the ADC complete conversion interrupt
 *              and finally start conversion.
 * Outputs   :  None
 * Inputs    :  None
 ****************************************************************************************/
void ADC_VidRefreshADC(void)
{
	/*the following logic is only executed when we start conversion for the first time     */
	/*Or when the conversion for the whole channels is done and we want to start conversion*/
	/* again from the beginning                                                            */
	/*ly by5leny anfz l klam da n h3ml conversion l awl mra aw n l ADC 5ls conversion l kol*/
	/* l sensors w 3awez ybd2 tany mn awl sensor                                           */
	if ((ADC_u8StartConversionFirstChFlag == 0) || (ADC_u8ConversionDoneFlag == 1))
	{
		ADC_u8StartConversionFirstChFlag = 1;
		ADC_u8ConversionDoneFlag = 0;
		/* select the first channel number to start conversion of it                       */
		ADC_u8_ADMUX |= (ADC_u8ChainConverterChannels[ADC_u8ChannelIndex] << ADC_u8_MUX0_PIN);
		/*ADC conversion complete interrupt enable                                         */
		ADC_u8_ADCSRA |= (1 << ADC_u8_ADIE_PIN);
		/* Start conversion                                                                */
		ADC_u8_ADCSRA |= (1 << ADC_u8_ADCSC_PIN);
	}
}


/*****************************************************************************************
 * Description: Function to loop through the array which includes the ADC values
 *             and get the value corresponding to the sent channel number.
 *             (interrupt) (auto trigger by software)
 * Outputs   : Error state
 * Inputs    : u16* Copy_Pu16PtrData : pointer  to variable to store digital value in it
 *             Copy_u8ChannelNb      : number of ADC channel which connected to a sensor
 ****************************************************************************************/
u8 ADC_u8GetADCNonBlocking(u16* Copy_Pu16PtrData , u8 Copy_u8ChannelNb)
{
	/* Local Variable indication for Error status                                          */
	u8 Local_u8Error = STD_TYPES_u8_ERROR_OK;
	/*Local variable to loop through the array which contains the ADC values               */
	u8 Local_u8LoopArrayIndex = 0;
	/*input arguments validation                                                           */
	if ((Copy_Pu16PtrData == NULL) && (Copy_u8ChannelNb > ADC_u8_MAX_CH_NUM))
	{
		Local_u8Error = STD_TYPES_u8_ERROR_NOK;
	}
	else
	{
		/*loop through the array to get the corresponding channel number value             */
		for (Local_u8LoopArrayIndex = 0; Local_u8LoopArrayIndex < ADC_u8_NUM_CHANNELS_TO_CONVERT; Local_u8LoopArrayIndex++)
		{
			/*if the sent channel equivalent to any channel in the channels' chain         */
			if (Copy_u8ChannelNb == ADC_u8ChainConverterChannels[Local_u8LoopArrayIndex])
			{
				/*Store the converted value in the array in to the sent pointer            */
				* Copy_Pu16PtrData = ADC_u16ADCvalues[Local_u8LoopArrayIndex];
			}
			else
			{
				Local_u8Error = STD_TYPES_u8_ERROR_NOK;
			}
		}
	}
	/* Function Return                                                                     */
	return Local_u8Error;
}


/****************************************************************************************************
 * Description:Function to Set the pointer to callback function with the address of the function
 *              Needed to be implemented by the ISR.
 * Outputs   : Error State
 * Inputs    : void (*Copy_PVidFunCallback) (void): pointer to callback function to set the pointer
 *             Value with the address of the function needed to be implemented by the ISR.
 ***************************************************************************************************/
u8 ADC_u8SetCallback (void (*Copy_PVidFunCallback) (void))
{
	/* Local Variable indication for Error status                                            */
	u8 Local_u8Error = STD_TYPES_u8_ERROR_OK;
	/* Input arguments validation                                                            */
	if (Copy_PVidFunCallback == NULL)
	{
		Local_u8Error = STD_TYPES_u8_ERROR_NOK;
	}
	else
	{
		/* Set the pointer with address of the function needed to be implemented by the ISR  */
		PVidFunCallback = Copy_PVidFunCallback;
	}
	/* Function Return                                                                       */
	return Local_u8Error;
}


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
void __vector_16 (void)
{
	if (ADC_u8ChannelIndex < ADC_u8_NUM_CHANNELS_TO_CONVERT)
	{
		/*in case of 8 bit resolution you have to adjust the result                         */
		/*to the left firstly then read the most 8 bits (high value)                        */
#if((ADC_u8_RESOLUTION == ADC_u8_8BIT_RESOLUTION) && (ADC_u8_LEFT_ADJUST_RESULT == ADC_u8_LEFT_ADJUST_RESULT_ON))
		{
			/*Store the converted value in the array                                        */
			ADC_u16ADCvalues[ADC_u8ChannelIndex] = ADC_u8_ADCH;
		}
		/*in case of 10 bit resolution you have to read the least 8 bits(low)              */
		/*firstly then read the most 8 bits(high)                                          */
#elif((ADC_u8_RESOLUTION == ADC_u8_10BIT_RESOLUTION) && (ADC_u8_LEFT_ADJUST_RESULT == ADC_u8_LEFT_ADJUST_RESULT_OFF))
		{
			/*Store the converted value in the array                                        */
			ADC_u16ADCvalues[ADC_u8ChannelIndex] = ADC_u8_ADCL;
			ADC_u16ADCvalues[ADC_u8ChannelIndex] |= (ADC_u8_ADCH << ADC_u8_SHIFT_HIGH_8BITS );
		}
		/*in case of 10 bit resolution you have to read the least 8 bits(low)              */
		/*firstly then read the most 8 bits(high)                                          */
#elif((ADC_u8_RESOLUTION == ADC_u8_10BIT_RESOLUTION) && (ADC_u8_LEFT_ADJUST_RESULT == ADC_u8_LEFT_ADJUST_RESULT_ON))
		{
			/*Store the converted value in the array                                        */
			ADC_u16ADCvalues[ADC_u8ChannelIndex] = ADC_u8_ADCL;
			ADC_u16ADCvalues[ADC_u8ChannelIndex] |= (ADC_u8_ADCH << ADC_u8_SHIFT_HIGH_2BITS );
		}
#endif
		/*increment the channel index to get the next channel                               */
		ADC_u8ChannelIndex ++;
		/* select the next channel number to start conversion of it                         */
		ADC_u8_ADMUX |= (ADC_u8ChainConverterChannels[ADC_u8ChannelIndex] << ADC_u8_MUX0_PIN);
		/* Start conversion of the next channel                                             */
		ADC_u8_ADCSRA |= (1 << ADC_u8_ADCSC_PIN);
	}
	else
	{
		/* Pointer validation                                                               */
		if (PVidFunCallback != NULL)
		{
			/* ISR of ADC complete conversion Function calling                              */
			PVidFunCallback();
		}
		/* return index to the first channel again                                          */
		ADC_u8ChannelIndex = 0;
		/*set the conversion flag as an indication that the whole channels are done converted*/
		ADC_u8ConversionDoneFlag = 1;
	}
}
