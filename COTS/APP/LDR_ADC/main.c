/*
 * file name :main.c
 * Description : Reading LDR sensor analog voltage and convert to digital reading
 *               using ADC, turn on LED when light is OFF and turn OFF LED when light is ON
 *               Also display on the LCD analog voltage reading corresponding to LDR sensor
 *               reading.
 *  Created on: Apr 8, 2019
 *  Author: shereen
 */

#include "STD_TYPES.h"
#include "BIT_CALC.h"
#include "DIO_interface.h"
#include "DIO_private.h"
#include "MCU_interface.h"
#include "LCD_interface.h"
#include "LCD_private.h"
#include "Delay.h"
#include "ADC_interface.h"

static u16 value = 0;
static u8 volt = 0;


/* Description: Writing an integer number on the LCD
 * Inputs: u32 Number: unsigned integer number to be displayed
 * Output: void
 */
void LCD_VidWriteNumber(u32 Number)
{
	u32 temp=1;

	if(Number==0)
	{
		LCD_VidWriteChar('0');
	}
	while(Number != 0)
	{
		u8 rem= Number %10;
		Number /=10;
		temp= temp *10 + rem;
	}

	while(temp != 1)
	{
		u8 rem2= temp %10;
		LCD_VidWriteChar(rem2 + 48);
		temp/=10;
	}
}

void LDR (void)
{
	/* read ADC value */
	ADC_u8GetADCNonBlocking(&value , ADC_u8_ADC1_CH);
}

int main (void)
{
	DIO_vidinit();
	/* Initialize the LCD in 8 bit Data mode                                 */
	LCD_VidInitialize ();
	/* display welcome for 2 seconds                                         */
	LCD_u8WriteString("Welcome :)", LCD_u8_COL4 ,LCD_u8_ROW1);
	delay_milliSecond(1000);
	/* clear the screen                                                      */
	LCD_VidClearScreen();
	/*enable global interrupt*/
	MCU_VidEnableGlobalINTP();
	/*ADC prescaler , ref voltage , ADC enable                               */
	ADC_Vidinit();
	ADC_u8SetCallback(&LDR);
	while(1)
	{
		/*start first channel conversion and enable interrupt then go to ISR and read ADC value              */
		ADC_VidRefreshADC();
		/* calculate LDR voltage                                              */
		volt = ((value * 5) / (256));
		if (volt <= 2 )
		{
			DIO_u8SetPinValue(31, DIO_u8_PIN_LOW);
		}
		else
		{
			DIO_u8SetPinValue(31, DIO_u8_PIN_HIGH);
		}

		LCD_u8WriteString("volt:", LCD_u8_COL0 ,LCD_u8_ROW0);
		LCD_VidWriteNumber(volt);
		delay_milliSecond(500);
		LCD_VidClearScreen();
	}
	return 0;
}
