/**********************************************************************************/
/*                                                                               */
/* File Name   : EXTI_prog.c                                                    */
/*                                                                             */
/* Created on  : Mar 24, 2019                                                 */
/*                                                                           */
/* Author      : shereen Abd Elhady                                         */
/*                                                                         */
/* Version     : V01                                                      */
/*                                                                       */
/* Description : software driver for External interrupts                */
/*                                                                     */
/*               with a defined public and private functions.         */
/*                                                                   */
/* Layer       : MCAL                                               */
/*******************************************************************/

#include "STD_TYPES.h"
#include "EXTI_interface.h"
#include "EXTI_private.h"


/* Array of pointers to function, each pointer will carry the address of the function wanted to be implemented by the ISR           */
/* Initialize all the pointers with Null in the beginning to avoid this pointer from garbage value and implementation of wrong code */
/* Global & Static to be seen within this file only                                                                                 */
static void (*PVidFunCallback[EXTI_NUM_OF_INTERRUPTS]) (void) = {NULL_PTR , NULL_PTR , NULL_PTR};

/****************************************************************************************************
 * Description:External INT initialization function which initialize the PIE state and sense level
 * Outputs    :None
 * Inputs     :None
 ***************************************************************************************************/
void EXTI_VidInitialize(void)
{
	/* Local variable for loop indexing */
	u8 Local_u8LoopIndex;
	/* Disable interrupts by clearing I-bit        */
	MCU_u8_SREG &= (~(1<<MCU_u8_SREG_I_BIT));
	/* For loop to go through the 3 external interrupts to set their initial state and sense level */
	for (Local_u8LoopIndex = 0 ; Local_u8LoopIndex < EXTI_NUM_OF_INTERRUPTS ; Local_u8LoopIndex++)
	{
		/* if the initial state was enable                                 */
		if (EXTI_Au8State[Local_u8LoopIndex] == EXTI_u8_PIE_ENABLE )
		{
			/* Enable function calling                                      */
			EXTI_u8PeripheralInterruptEnable (Local_u8LoopIndex);
		}
		else
		{
			/* Disable function calling                                     */
			EXTI_u8PeripheralInterruptDisable (Local_u8LoopIndex);
		}
		/* set sense level function calling */
		EXTI_u8SetSenseLevel (Local_u8LoopIndex , EXTI_Au8SenseLevel[Local_u8LoopIndex]);
	}
	/* Enable interrupts by setting I-bit          */
	MCU_u8_SREG  |= (1<<MCU_u8_SREG_I_BIT);
}


/****************************************************************************************************
 * Description:Function to Set the pointer to callback function with the address of the function
 *              Needed to be implemented by the ISR.
 * Outputs   : Error State
 * Inputs    : void (*Copy_PVidFunCallback) (void): pointer to callback function to set the pointer
 *             Value with the address of the function needed to be implemented by the ISR.
 *             Copy_u8INTNb             : Interrupt Index number
 ***************************************************************************************************/
u8 EXTI_u8SetCallback (u8 Copy_u8INTIndex , void (*Copy_PVidFunCallback) (void))
{
	/* Local Variable indication for Error status                                            */
	u8 Local_u8Error = STD_TYPES_u8_ERROR_OK;
	/* Input arguments validation                                                            */
	if (Copy_u8INTIndex >= EXTI_NUM_OF_INTERRUPTS)
	{
		Local_u8Error = STD_TYPES_u8_ERROR_NOK;
	}
	else
	{
		/* Set the pointer with address of the function needed to be implemented by the ISR  */
		PVidFunCallback[Copy_u8INTIndex] = Copy_PVidFunCallback;
	}
	/* Function Return                                                                       */
	return Local_u8Error;
}


/****************************************************************************************************
 * Description:External INT0 Interrupt Service Routine which includes a pointer points to a function
 *             Send by user to be implemented.
 * Outputs    :Error State
 * Inputs     :None
 ***************************************************************************************************/
void __vector_1 (void)
{
	/* Pointer validation                                */
	if (PVidFunCallback[EXTI_u8_INDEX_INT0] != NULL_PTR)
	{
		/* ISR of INT0 Function calling                  */
		PVidFunCallback[EXTI_u8_INDEX_INT0] ();
	}
}


/****************************************************************************************************
 * Description:External INT1 Interrupt Service Routine which includes a pointer points to a function
 *             Send by user to be implemented.
 * Outputs    :Error State
 * Inputs     :None
 ***************************************************************************************************/
void __vector_2 (void)
{
	/* Pointer validation                                */
	if (PVidFunCallback[EXTI_u8_INDEX_INT1] != NULL_PTR)
	{
		/* ISR of INT1 Function calling                  */
		PVidFunCallback[EXTI_u8_INDEX_INT1] ();
	}
}


/****************************************************************************************************
 * Description:External INT2 Interrupt Service Routine which includes a pointer points to a function
 *             Send by user to be implemented.
 * Outputs    :Error State
 * Inputs     :None
 ***************************************************************************************************/
void __vector_3 (void)
{
	/* Pointer validation                                */
	if (PVidFunCallback[EXTI_u8_INDEX_INT2] != NULL_PTR)
	{
		/* ISR of INT2 Function calling                  */
		PVidFunCallback[EXTI_u8_INDEX_INT2] ();
	}
}


/****************************************************************************************************
 * Description:Function to Set the peripheral interrupt enable (PIE)
 * Outputs   : Error State
 * Inputs    : Copy_u8INTNb             : Interrupt Index number
 ***************************************************************************************************/
u8 EXTI_u8PeripheralInterruptEnable (u8 Copy_u8INTIndex)
{
	/* Local Variable indication for Error status         */
	u8 Local_u8Error = STD_TYPES_u8_ERROR_OK;
	/* Input arguments validation                         */
	if (Copy_u8INTIndex >= EXTI_NUM_OF_INTERRUPTS)
	{
		Local_u8Error = STD_TYPES_u8_ERROR_NOK;
	}
	else
	{
		/* Switch on the interrupt index                  */
		switch(Copy_u8INTIndex)
		{
		/*** INT0 ***/
		case EXTI_u8_INDEX_INT0:
			/* Enable external interrupt pin INT0          */
			EXTI_u8_GICR |= (EXTI_u8_PIE_ENABLE <<EXTI_u8_GICR_INT0_BIT);
			break;
			/*** INT1 ***/
		case EXTI_u8_INDEX_INT1:
			/* Enable external interrupt pin INT1          */
			EXTI_u8_GICR |= (EXTI_u8_PIE_ENABLE <<EXTI_u8_GICR_INT1_BIT);
			break;
			/*** INT2 ***/
		case EXTI_u8_INDEX_INT2:
			/* Enable external interrupt pin INT2          */
			EXTI_u8_GICR |= (EXTI_u8_PIE_ENABLE <<EXTI_u8_GICR_INT2_BIT);
			break;
		}
	}
	/* Function Return                                     */
	return Local_u8Error;
}


/****************************************************************************************************
 * Description:Function to clear the peripheral interrupt enable (PIE)
 * Outputs   : Error State
 * Inputs    : Copy_u8INTNb             : Interrupt Index number
 ***************************************************************************************************/
u8 EXTI_u8PeripheralInterruptDisable (u8 Copy_u8INTIndex)
{
	/* Local Variable indication for Error status         */
	u8 Local_u8Error = STD_TYPES_u8_ERROR_OK;
	/* Input arguments validation                         */
	if (Copy_u8INTIndex >= EXTI_NUM_OF_INTERRUPTS)
	{
		Local_u8Error = STD_TYPES_u8_ERROR_NOK;
	}
	else
	{
		/* Switch on the interrupt index                  */
		switch(Copy_u8INTIndex)
		{
		/*** INT0 ***/
		case EXTI_u8_INDEX_INT0:
			/* Disable external interrupt pin INT0          */
			EXTI_u8_GICR &= (~(EXTI_u8_PIE_ENABLE <<EXTI_u8_GICR_INT0_BIT));
			break;
			/*** INT1 ***/
		case EXTI_u8_INDEX_INT1:
			/* Disable external interrupt pin INT1          */
			EXTI_u8_GICR &= (~(EXTI_u8_PIE_ENABLE <<EXTI_u8_GICR_INT1_BIT));
			break;
			/*** INT2 ***/
		case EXTI_u8_INDEX_INT2:
			/* Disable external interrupt pin INT2          */
			EXTI_u8_GICR &= (~(EXTI_u8_PIE_ENABLE <<EXTI_u8_GICR_INT2_BIT));
			break;
		}
	}
	/* Function Return                                     */
	return Local_u8Error;
}


/****************************************************************************************************
 * Description:Function to set the interrupt sense level whether it is
 *             Low Level , Rising edge , Falling edge , on change.
 * Outputs   : Error State
 * Inputs    : Copy_u8INTNb             : Interrupt Index number
 *             Copy_u8SenseLevel        : interrupt sense level
 ***************************************************************************************************/
u8 EXTI_u8SetSenseLevel (u8 Copy_u8INTIndex , u8 Copy_u8SenseLevel)
{
	/* Local Variable indication for Error status                */
	u8 Local_u8Error = STD_TYPES_u8_ERROR_OK;
	/* Input arguments validation                                */
	if (Copy_u8INTIndex >= EXTI_NUM_OF_INTERRUPTS)
	{
		Local_u8Error = STD_TYPES_u8_ERROR_NOK;
	}
	else
	{
		switch(Copy_u8SenseLevel)
		{
		/* Low Level interrupt source in case of INT0 & INT1 Only*/
		case EXTI_u8_LOW_LEVEL:
			/* INT0 */
			if (Copy_u8INTIndex == EXTI_u8_INDEX_INT0)
			{
				/* Trigger INT0 with the low level               */
				EXTI_u8_MCUCR &= (~(1<<EXTI_u8_MCUCR_ISC00_BIT)) ;
				EXTI_u8_MCUCR &= (~(1<<EXTI_u8_MCUCR_ISC01_BIT)) ;
			}
			/* INT1 */
			else if (Copy_u8INTIndex == EXTI_u8_INDEX_INT1)
			{
				/* Trigger INT1 with the low level               */
				EXTI_u8_MCUCR &= (~(1<<EXTI_u8_MCUCR_ISC10_BIT)) ;
				EXTI_u8_MCUCR &= (~(1<<EXTI_u8_MCUCR_ISC11_BIT)) ;
			}
			break;
			/* Any Logical Change interrupt source in case of INT0 & INT1*/
		case EXTI_u8_ANY_LOGICAL_CHANGE:
			/* INT0 */
			if (Copy_u8INTIndex == EXTI_u8_INDEX_INT0)
			{
				/* Trigger INT0 with any logical change          */
				EXTI_u8_MCUCR |= (1<<EXTI_u8_MCUCR_ISC00_BIT)    ;
				EXTI_u8_MCUCR &= (~(1<<EXTI_u8_MCUCR_ISC01_BIT)) ;
			}
			/* INT1 */
			else if (Copy_u8INTIndex == EXTI_u8_INDEX_INT1)
			{
				/* Trigger INT1 with any logical change          */
				EXTI_u8_MCUCR |= (1<<EXTI_u8_MCUCR_ISC10_BIT)    ;
				EXTI_u8_MCUCR &= (~(1<<EXTI_u8_MCUCR_ISC11_BIT)) ;
			}
			break;
			/* Falling Edge interrupt source in case of INT0 , INT1 & INT2*/
		case EXTI_u8_FALLING_EDGE:
			/* INT0 */
			if (Copy_u8INTIndex == EXTI_u8_INDEX_INT0)
			{
				/* Trigger INT0 with Falling edge                */
				EXTI_u8_MCUCR &= (~(1<<EXTI_u8_MCUCR_ISC00_BIT)) ;
				EXTI_u8_MCUCR |= (1<<EXTI_u8_MCUCR_ISC01_BIT)    ;
			}
			/* INT1 */
			else if (Copy_u8INTIndex == EXTI_u8_INDEX_INT1)
			{
				/* Trigger INT1 with Falling edge               */
				EXTI_u8_MCUCR &= (~(1<<EXTI_u8_MCUCR_ISC10_BIT)) ;
				EXTI_u8_MCUCR |= (1<<EXTI_u8_MCUCR_ISC11_BIT)    ;
			}
			/* INT2 */
			else if (Copy_u8INTIndex == EXTI_u8_INDEX_INT2)
			{
				/* Trigger INT2 with Falling edge               */
				EXTI_u8_MCUCSR &= (~(1<<EXTI_u8_MCUCSR_ISC2_BIT)) ;
			}
			break;
			/* Rising Edge interrupt source in case of INT0 , INT1 & INT2*/
		case EXTI_u8_RISING_EDGE:
			/* INT0 */
			if (Copy_u8INTIndex == EXTI_u8_INDEX_INT0)
			{
				/* Trigger INT0 with the rising edge           */
				EXTI_u8_MCUCR |= (1<<EXTI_u8_MCUCR_ISC00_BIT) | (1<<EXTI_u8_MCUCR_ISC01_BIT);
			}
			/* INT1 */
			else if (Copy_u8INTIndex == EXTI_u8_INDEX_INT1)
			{
				/* Trigger INT1 with the rising edge           */
				EXTI_u8_MCUCR |= (1<<EXTI_u8_MCUCR_ISC10_BIT) | (1<<EXTI_u8_MCUCR_ISC11_BIT);
			}
			/* INT2 */
			else if (Copy_u8INTIndex == EXTI_u8_INDEX_INT2)
			{
				/* Trigger INT2 with Rising edge               */
				EXTI_u8_MCUCSR |= (1<<EXTI_u8_MCUCSR_ISC2_BIT) ;
			}
			break;
		}
	}
	/* Function Return                                         */
	return Local_u8Error;
}
