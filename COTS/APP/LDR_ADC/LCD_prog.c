/******************************************************************************************/
/*                                                                                       */
/* File Name   : LCD_prog.c                                                             */
/*                                                                                     */
/* Created on  : Mar 6, 2019                                                          */
/*                                                                                   */
/* Author      : shereen Abd Elhady                                                 */
/*                                                                                 */
/* Version     : V01                                                              */
/*                                                                               */
/* Description : software driver for liquid crystal display with configurable   */
/*               Number of ROWs and COLs , data mode , font , cursor settings  */
/*               with a defined public and private functions                  */
/* Layer       : HAL                                                         */
/****************************************************************************/


#include "STD_TYPES.h"
#include "BIT_CALC.h"
#include "Delay.h"
#include "DIO_interface.h"
#include "DIO_private.h"
#include "LCD_interface.h"
#include "LCD_private.h"


/***********************************************************************
 * Description: Function to initialize the LCD in 4BIT / 8BIT Data mode
 * Outputs   : None
 * Inputs    : None
 ***********************************************************************/
void LCD_VidInitialize (void)
{
	/******** 8 bit Data Length Mode  ********/
	if(LCD_u8_DATA_LENGTH_MODE == LCD_u8_8BIT_DATA_MODE)
	{
		/* wait for more than 30ms after VDD rises to 4.5v */
		delay_milliSecond(30);
		/* Function set                                    */
		LCD_VidWriteCommand(LCD_u8_8BIT_FUNCTION_SET_REG_MODE);
		/* Wait  for more than 39 micro second             */
		delay_milliSecond(1);
		/* Display ON / OFF control                        */
		LCD_VidWriteCommand(LCD_u8_8BIT_DISPLAY_CONTROL_REG_MODE);
		/* Wait  for more than 39 micro second             */
		delay_milliSecond(1);
		/* Display Clear                                   */
		LCD_VidWriteCommand(LCD_u8_DISPLAY_CLEAR);
		/* Wait  for more than 1.53ms second               */
		delay_milliSecond(1.5);
	}
	/******** 4 bit Data Length Mode  ********/
	else if (LCD_u8_DATA_LENGTH_MODE == LCD_u8_4BIT_DATA_MODE)
	{
		/* wait for more than 30ms after VDD rises to 4.5v */
		delay_milliSecond(30);
		/* Function set                                    */
		//LCD_u8WriteCommand(LCD_u8_4BIT_FUNCTION_SET_REG_NIBBLE);
		//LCD_u8WriteCommand(LCD_u8_4BIT_FUNCTION_SET_REG_NIBBLE);
		LCD_VidWriteCommand(LCD_u8_4BIT_FUNCTION_SET_REG_MODE);
		/* Wait  for more than 39 micro second             */
		delay_milliSecond(1);
		/* Display ON / OFF control                        */
		//LCD_u8WriteCommand(LCD_u8_4BIT_DISPLAY_CONTROL_REG_NIBBLE);
		LCD_VidWriteCommand(LCD_u8_4BIT_DISPLAY_CONTROL_REG_MODE);
		/* Wait  for more than 39 micro second             */
		delay_milliSecond(1);
		/* Display Clear                                   */
		//LCD_u8WriteCommand(LCD_u8_4BIT_DISPLAY_CLEAR_REG_NIBBLE);
		LCD_VidWriteCommand(LCD_u8_DISPLAY_CLEAR);
		/* Wait  for more than 1.53ms second               */
		delay_milliSecond(1.5);
	}
}


/***********************************************************************
 * Description: Function to write a string on the LCD
 * Outputs   : Error state
 * Inputs    : u8 *Copy_Pu8Data : pointer to the sent string
 *             u8 Copy_u8XPos   : X axis position
 *             u8 Copy_u8YPos   : Y axis position
 ***********************************************************************/
u8 LCD_u8WriteString(u8 *Copy_Pu8Data, u8 Copy_u8XPos , u8 Copy_u8YPos)
{
	/* Local Variable indication for Error status       */
	u8 Local_u8Error = STD_TYPES_u8_ERROR_OK;
	/* Local Variable to save the DDRAM address in it   */
	u8 Local_u8Address;
	/* Arguments validation                             */
	if ( (Copy_u8XPos < LCD_u8_MAX_COL_NUMBER) && (Copy_u8YPos < LCD_u8_MAX_ROW_NUMBER) && (Copy_Pu8Data != NULL))
	{
		/* (Copy_u8YPos * LCD_u8_LINE2_START_ADDRESS) --> Copy_u8YPos=0 will go to the first line */
		/* (Copy_u8YPos * LCD_u8_LINE2_START_ADDRESS) --> Copy_u8YPos=1 will go to the second line*/
		Local_u8Address = Copy_u8XPos + (Copy_u8YPos * LCD_u8_LINE2_START_ADDRESS);
		/* The start of line 1 (0x00 = 0000 0000)                                                 */
		/* set DDRAM address (1| 7 bits) --> 0x80 = 1000 0000                                     */
		/* after calculating the address this address always will have one on the left side       */
		/* whatever the address value is  to send it to the writeCommand function as a command    */
		Local_u8Address |= LCD_u8_LINE1_START_ADDRESS_COMMAND;
		/* call the writeCommand function and send a command to it to goto the DDRAM and sit      */
		/* at this address                                                                        */
		LCD_VidWriteCommand(Local_u8Address);
		/* loop till the end of the string                                                        */
		while(*Copy_Pu8Data != '\0')
		{
			/* call the writeChar function to write a character                                   */
			LCD_VidWriteChar(*Copy_Pu8Data);
			/* increment the pointer to go to the next character                                  */
			Copy_Pu8Data++;
			/* increment the address DDRAM address as it is increases with the address counter(AC)*/
			/* so we consider it as an indication for the address counter value                   */
			Local_u8Address++;
			/* The end of line 1 (0x0F + 1 = 0X10 = 0001 0000)                                    */
			/* set DDRAM address (1| 7 bits) --> 0x90 = 1001 0000                                 */
			/* after calculating the address this address always will have one on the left side   */
			/* whatever the address value is  to send it to the writeCommand function as a command*/
			if (Local_u8Address == LCD_u8_LINE1_END_ADDRESS_COMMAND)
			{
				/* The start of line 2 (0x40 = 0100 0000)                                             */
				/* set DDRAM address (1| 7 bits) --> 0xC0 = 1100 0000                                 */
				/* after calculating the address this address always will have one on the left side   */
				/* whatever the address value is  to send it to the writeCommand function as a command*/
				Local_u8Address = LCD_u8_LINE2_START_ADDRESS_COMMAND;
				/* if you reach the end of the first line go to the second line                       */
				LCD_VidWriteCommand(Local_u8Address);
			}
			/* The end of line 2 (0x4F + 1 = 0X10 = 0101 0000)                                        */
			/* set DDRAM address (1| 7 bits) --> 0xD0 = 1101 0000                                     */
			/* after calculating the address this address always will have one on the left side       */
			/* whatever the address value is  to send it to the writeCommand function as a command    */
			else if (Local_u8Address ==LCD_u8_LINE2_END_ADDRESS_COMMAND )
			{
				/* The start of line 1 (0x00 = 0000 0000)                                                 */
				/* set DDRAM address (1| 7 bits) --> 0x80 = 1000 0000                                     */
				/* after calculating the address this address always will have one on the left side       */
				/* whatever the address value is  to send it to the writeCommand function as a command    */
				Local_u8Address = LCD_u8_LINE1_START_ADDRESS_COMMAND;
				/* if you reach the end of the second line go to the first line                           */
				LCD_VidWriteCommand(Local_u8Address);
			}
		}
	}
	else
	{
		/* input arguments failure                                                                        */
		Local_u8Error = STD_TYPES_u8_ERROR_NOK;
	}
	/* Function Return */
	return Local_u8Error;
}


/***********************************************************************
 * Description: Function to clear the LCD in 4BIT / 8BIT Data mode
 * Outputs   : None
 * Inputs    : None
 ***********************************************************************/
void LCD_VidClearScreen(void)
{
	/* clear display                          */
	LCD_VidWriteCommand(LCD_u8_DISPLAY_CLEAR);
}


/**************************************************************************************
 * Description: Function to write a special characters on the LCD at any position
 * Outputs   : Error state
 * Inputs    : u8 *Copy_Pu8Array     : pointer to the sent array which contains the patterns
 *             u8 Copy_u8PatternIndex: the index of pattern to be displayed
 *             u8 Copy_u8XPos        : X axis position (columns)
 *             u8 Copy_u8YPos        : Y axis position (rows)
 **************************************************************************************/
u8 LCD_u8WriteSpecialCharacter(u8 *Copy_Pu8Array,u8 Copy_u8PatternIndex,u8 Copy_u8XPos , u8 Copy_u8YPos)
{
	/* Local Variable indication for Error status       */
	u8 Local_u8Error = STD_TYPES_u8_ERROR_OK;
	/* Local Variable to save the DDRAM address in it   */
	u8 Local_u8DDRAMaddress;
	/* Local Variable to save the CGRAM address in it   */
	u8 Local_u8CGRAMaddress;
	/* Local variable for loop indexing                 */
	u8 Local_u8CopyIndex;
	/* Arguments validation                             */
	if ((Copy_u8XPos < LCD_u8_MAX_COL_NUMBER) && (Copy_u8YPos < LCD_u8_MAX_ROW_NUMBER) &&(Copy_Pu8Array != NULL) && (Copy_u8PatternIndex <= LCD_u8_SPECIAL_PATTERN_INDEX7))
	{
		/***** DDRAM Address adjustments *****/
		/* (Copy_u8YPos * LCD_u8_LINE2_START_ADDRESS) --> Copy_u8YPos=0 will go to the first line */
		/* (Copy_u8YPos * LCD_u8_LINE2_START_ADDRESS) --> Copy_u8YPos=1 will go to the second line*/
		Local_u8DDRAMaddress = Copy_u8XPos + (Copy_u8YPos * LCD_u8_LINE2_START_ADDRESS);
		/* The start of line 1 (0x00 = 0000 0000)                                                 */
		/* set DDRAM address (1| 7 bits) --> 0x80 = 1000 0000                                     */
		/* after calculating the address this address always will have one on the left side       */
		/* whatever the address value is  to send it to the writeCommand function as a command    */
		Local_u8DDRAMaddress |= LCD_u8_LINE1_START_ADDRESS_COMMAND;

		/***** CGRAM Address adjustments *****/
		/* We adjust the CGRAM address to be able to write another pattern in the next location   */
		/* CGRAM address of any pattern in the beginning = INDEX_NO. * 8                          */
		Local_u8CGRAMaddress = (Copy_u8PatternIndex * LCD_u8_CGRAM_NUM_LOCATIONS_PER_PATTERN);
		/* set CGRAM address (01 | 6 bits) --> 0x40 = 0100 0000                                   */
		/* after calculating the address this address always will have zero and one               */
		/* on the left side  to send it to the writeCommand function as a command                 */
		Local_u8CGRAMaddress |= LCD_u8_SET_CGRAM_ADRESS_IN_AC_COMMAND;
		/* call the writeCommand function and send a command to it to goto the CGRAM              */
		LCD_VidWriteCommand(Local_u8CGRAMaddress);
		/* loop till the end of the pattern                                                       */
		for(Local_u8CopyIndex = 0 ;Local_u8CopyIndex <LCD_u8_CGRAM_NUM_LOCATIONS_PER_PATTERN; Local_u8CopyIndex++ )
		{
			/* call the writeChar function to write a character in a specific pattern             */
			LCD_VidWriteChar(*Copy_Pu8Array);
			/* increment the pointer to go to the next character in this pattern                  */
			Copy_Pu8Array++;
			/* increment the address CGRAM address as it is increases with the address counter(AC)*/
			/* so we consider it as an indication for the address counter value                   */
			/* we could remove this line as th AC is incremented automatically                    */
			Local_u8CGRAMaddress++;
		}
		/* call the writeCommand function and send a command to it to goto the DDRAM              */
		LCD_VidWriteCommand(Local_u8DDRAMaddress);
		/* call the writeChar function and send it the pattern you want to display                */
		LCD_VidWriteChar(Copy_u8PatternIndex);
	}
	else
	{
		/* input arguments failure                                                                        */
		Local_u8Error = STD_TYPES_u8_ERROR_NOK;
	}
	/* Function Return */
	return Local_u8Error;
}


/*******************************************************************************
 * Description: Function to write a character on the LCD
 * Outputs   : None
 * Inputs    : u8 Copy_uData : argument to receive an 8 bit data
 ********************************************************************************/
void LCD_VidWriteChar(u8 Copy_u8Data)
{
	/* set the RS BIT with high value to activate the data mode */
	DIO_u8SetPinValue(LCD_u8_RS,LCD_u8_PIN_HIGH );
	LCD_VidWrite(Copy_u8Data);
}

/******************************************************************************
 * Description: Function to write a command on the LCD
 * Outputs   : None
 * Inputs    : u8 Copy_u8Command : argument to receive an 8 bit command
 ******************************************************************************/
static void LCD_VidWriteCommand(u8 Copy_u8Command)
{
	/* set the RS BIT with low value to activate the command mode */
	DIO_u8SetPinValue(LCD_u8_RS,LCD_u8_PIN_LOW);
	LCD_VidWrite(Copy_u8Command);
}


// shofy haga asr3 mn get bit
//dlw2ty lw high w low 8er 1 w zero msh hytsh8l m3 driver l dio arm f l 7al ank t3ml if
/*********************************************************************************
 * Description: Function to write a command / data on the LCD bit by bit
 *              which handles the 8 bit data mode and 4 bit data mode
 * Outputs   : None
 * Inputs    : u8 Copy_uDataCommand : argument to receive an 8 bit data/ command
 *********************************************************************************/
static void LCD_VidWrite(u8 Copy_u8DataCommand)
{
	/* Local variable to store the data/command bit value in it     */
	u8 Local_u8DataCommandValue;
	/* set Read/Write pin with low value to activate the write mode */
	DIO_u8SetPinValue(LCD_u8_RW,LCD_u8_PIN_LOW);
	/* set the Enable pin with low value as it is active low pin    */
	DIO_u8SetPinValue(LCD_u8_E,LCD_u8_PIN_LOW);

	/*********** setting the 8 Data PINs in the LCD**********************/
	/* to solve the problem of defined high and low with values not equal one or zero*/
	/* As it will not work in ARM driver if the value wasn't high or low             */

	/********* 8 Bit Data Mode ************/
	if(LCD_u8_DATA_LENGTH_MODE == LCD_u8_8BIT_DATA_MODE)
	{
		/** D0**/
		Local_u8DataCommandValue =  BITCALC_GET_BIT(Copy_u8DataCommand,LCD_u8_BIT0);
		if (Local_u8DataCommandValue == LCD_u8_PIN_HIGH)
		{
			DIO_u8SetPinValue(LCD_u8_D0,LCD_u8_PIN_HIGH);
		}
		else
		{
			DIO_u8SetPinValue(LCD_u8_D0,LCD_u8_PIN_LOW);
		}
		/** D1**/
		Local_u8DataCommandValue =  BITCALC_GET_BIT(Copy_u8DataCommand,LCD_u8_BIT1);
		if (Local_u8DataCommandValue == LCD_u8_PIN_HIGH)
		{
			DIO_u8SetPinValue(LCD_u8_D1,LCD_u8_PIN_HIGH);
		}
		else
		{
			DIO_u8SetPinValue(LCD_u8_D1,LCD_u8_PIN_LOW);
		}
		/** D2**/
		Local_u8DataCommandValue =  BITCALC_GET_BIT(Copy_u8DataCommand,LCD_u8_BIT2);
		if (Local_u8DataCommandValue == LCD_u8_PIN_HIGH)
		{
			DIO_u8SetPinValue(LCD_u8_D2,LCD_u8_PIN_HIGH);
		}
		else
		{
			DIO_u8SetPinValue(LCD_u8_D2,LCD_u8_PIN_LOW);
		}
		/** D3**/
		Local_u8DataCommandValue =  BITCALC_GET_BIT(Copy_u8DataCommand,LCD_u8_BIT3);
		if (Local_u8DataCommandValue == LCD_u8_PIN_HIGH)
		{
			DIO_u8SetPinValue(LCD_u8_D3,LCD_u8_PIN_HIGH);
		}
		else
		{
			DIO_u8SetPinValue(LCD_u8_D3,LCD_u8_PIN_LOW);
		}
		/** D4**/
		Local_u8DataCommandValue =  BITCALC_GET_BIT(Copy_u8DataCommand,LCD_u8_BIT4);
		if (Local_u8DataCommandValue == LCD_u8_PIN_HIGH)
		{
			DIO_u8SetPinValue(LCD_u8_D4,LCD_u8_PIN_HIGH);
		}
		else
		{
			DIO_u8SetPinValue(LCD_u8_D4,LCD_u8_PIN_LOW);
		}
		/** D5**/
		Local_u8DataCommandValue =  BITCALC_GET_BIT(Copy_u8DataCommand,LCD_u8_BIT5);
		if (Local_u8DataCommandValue == LCD_u8_PIN_HIGH)
		{
			DIO_u8SetPinValue(LCD_u8_D5,LCD_u8_PIN_HIGH);
		}
		else
		{
			DIO_u8SetPinValue(LCD_u8_D5,LCD_u8_PIN_LOW);
		}
		/** D6**/
		Local_u8DataCommandValue =  BITCALC_GET_BIT(Copy_u8DataCommand,LCD_u8_BIT6);
		if (Local_u8DataCommandValue == LCD_u8_PIN_HIGH)
		{
			DIO_u8SetPinValue(LCD_u8_D6,LCD_u8_PIN_HIGH);
		}
		else
		{
			DIO_u8SetPinValue(LCD_u8_D6,LCD_u8_PIN_LOW);
		}
		/** D7**/
		Local_u8DataCommandValue =  BITCALC_GET_BIT(Copy_u8DataCommand,LCD_u8_BIT7);
		if (Local_u8DataCommandValue == LCD_u8_PIN_HIGH)
		{
			DIO_u8SetPinValue(LCD_u8_D7,LCD_u8_PIN_HIGH);
		}
		else
		{
			DIO_u8SetPinValue(LCD_u8_D7,LCD_u8_PIN_LOW);
		}
	}

	/********* 4 Bit Data Mode ************/
	else if (LCD_u8_DATA_LENGTH_MODE == LCD_u8_4BIT_DATA_MODE)
	{
		/****** send the high bits firstly *******/
		/** D4**/
		Local_u8DataCommandValue =  BITCALC_GET_BIT(Copy_u8DataCommand,LCD_u8_BIT4);
		if (Local_u8DataCommandValue == LCD_u8_PIN_HIGH)
		{
			DIO_u8SetPinValue(LCD_u8_D4,LCD_u8_PIN_HIGH);
		}
		else
		{
			DIO_u8SetPinValue(LCD_u8_D4,LCD_u8_PIN_LOW);
		}
		/** D5**/
		Local_u8DataCommandValue =  BITCALC_GET_BIT(Copy_u8DataCommand,LCD_u8_BIT5);
		if (Local_u8DataCommandValue == LCD_u8_PIN_HIGH)
		{
			DIO_u8SetPinValue(LCD_u8_D5,LCD_u8_PIN_HIGH);
		}
		else
		{
			DIO_u8SetPinValue(LCD_u8_D5,LCD_u8_PIN_LOW);
		}
		/** D6**/
		Local_u8DataCommandValue =  BITCALC_GET_BIT(Copy_u8DataCommand,LCD_u8_BIT6);
		if (Local_u8DataCommandValue == LCD_u8_PIN_HIGH)
		{
			DIO_u8SetPinValue(LCD_u8_D6,LCD_u8_PIN_HIGH);
		}
		else
		{
			DIO_u8SetPinValue(LCD_u8_D6,LCD_u8_PIN_LOW);
		}
		/** D7**/
		Local_u8DataCommandValue =  BITCALC_GET_BIT(Copy_u8DataCommand,LCD_u8_BIT7);
		if (Local_u8DataCommandValue == LCD_u8_PIN_HIGH)
		{
			DIO_u8SetPinValue(LCD_u8_D7,LCD_u8_PIN_HIGH);
		}
		else
		{
			DIO_u8SetPinValue(LCD_u8_D7,LCD_u8_PIN_LOW);
		}

		/**** Enable sequence ***/
		DIO_u8SetPinValue(LCD_u8_E,DIO_u8_PIN_HIGH);
		// mfrod 1 ms bs bn3mlha 2ms 3shan msh zbteen delay hna
		delay_milliSecond(2);
		DIO_u8SetPinValue(LCD_u8_E,LCD_u8_PIN_LOW);

		/****** send the lower bits secondly *******/
		/** D0**/
		Local_u8DataCommandValue =  BITCALC_GET_BIT(Copy_u8DataCommand,LCD_u8_BIT0);
		if (Local_u8DataCommandValue == LCD_u8_PIN_HIGH)
		{
			DIO_u8SetPinValue(LCD_u8_D4,LCD_u8_PIN_HIGH);
		}
		else
		{
			DIO_u8SetPinValue(LCD_u8_D4,LCD_u8_PIN_LOW);
		}
		/** D1**/
		Local_u8DataCommandValue =  BITCALC_GET_BIT(Copy_u8DataCommand,LCD_u8_BIT1);
		if (Local_u8DataCommandValue == LCD_u8_PIN_HIGH)
		{
			DIO_u8SetPinValue(LCD_u8_D5,LCD_u8_PIN_HIGH);
		}
		else
		{
			DIO_u8SetPinValue(LCD_u8_D5,LCD_u8_PIN_LOW);
		}
		/** D2**/
		Local_u8DataCommandValue =  BITCALC_GET_BIT(Copy_u8DataCommand,LCD_u8_BIT2);
		if (Local_u8DataCommandValue == LCD_u8_PIN_HIGH)
		{
			DIO_u8SetPinValue(LCD_u8_D6,LCD_u8_PIN_HIGH);
		}
		else
		{
			DIO_u8SetPinValue(LCD_u8_D6,LCD_u8_PIN_LOW);
		}
		/** D3**/
		Local_u8DataCommandValue =  BITCALC_GET_BIT(Copy_u8DataCommand,LCD_u8_BIT3);
		if (Local_u8DataCommandValue == LCD_u8_PIN_HIGH)
		{
			DIO_u8SetPinValue(LCD_u8_D7,LCD_u8_PIN_HIGH);
		}
		else
		{
			DIO_u8SetPinValue(LCD_u8_D7,LCD_u8_PIN_LOW);
		}

	}
	/**** Enable sequence ***/
	DIO_u8SetPinValue(LCD_u8_E,DIO_u8_PIN_HIGH);
	// mfrod 1 ms bs bn3mlha 2ms 3shan msh zbteen delay hna
	delay_milliSecond(2);
	DIO_u8SetPinValue(LCD_u8_E,LCD_u8_PIN_LOW);
}

//void LCD_VidInetgerToString(u8 Copy_u8Data , u8 Copy_u8XPos , u8 Copy_u8YPos)
//{
/* String to hold the ascii result           */
//u8 buff[16];
/* function to convert the integer to string */
/* 10 for decimal                            */
//itoa(Copy_u8Data ,buff,10);
/* writr string function calling             */
//LCD_vidWriteString(buff,Copy_u8XPos,Copy_u8YPos);
//}
