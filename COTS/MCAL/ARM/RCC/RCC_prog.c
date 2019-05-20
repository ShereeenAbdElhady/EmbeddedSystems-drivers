/**********************************************************************************/
/*                                                                               */
/* File Name   : RCC_prog.c                                                     */
/*                                                                             */
/* Created on  : Mar 5, 2019                                                  */
/*                                                                           */
/* Author      : shereen Abd Elhady                                         */
/*                                                                         */
/* Version     : V02                                                      */
/*                                                                       */
/* Description : software driver for Reset & clock control              */
/*                                                                     */
/*               with a defined public and private functions for the  */
/*               For STM32F103C8 ARM Microcontroller.                */
/*                                                                  */
/* Layer       : MCAL                                              */
/******************************************************************/

#include "../STD_TYPES.h"
#include "../BIT_CALC.h"
#include "../include/RCC_interface.h"
#include "../include/RCC_private.h"


/*********************************************************************************
 * Description:Function to initialize the clock & reset registers
 * Outputs   : None
 * Inputs    : None
 ********************************************************************************/
void RCC_vidinit(void)
{
	/******************************************************************************************************/
	/*Firstly will switch to another clock source as PLL is selected as a clock source by the startup code*/
	/******** Clock control (CR) Register ********/
	/*set the first bit (HSION) with one (internal high speed clock enable) (8MHZ RC oscillator ON)       */
	BITCALC_SET_BIT(RCC->CR.FourByteAccess,RCC_u8_HSION_PIN);
	//RCC->CR.BitAccess.Bit0=1;
	/* Wait until the HSI Ready flag equals one                                                           */
	//while( !( BITCALC_GET_BIT(RCC->CR.FourByteAccess,RCC_u8_HSIRDY_PIN) ) ) {}
	/******** Clock Configuration (CFGR) Register ********/
	/* Select HSI as system clock                                                                         */
	BITCALC_ASSIGN_NIBBLE(RCC->CFGR.FourByteAccess,RCC_u8_SYSCLK_NIBLLE_NUM ,RCC_u8_2PIN_SYSCLK_SOURCE);
	/******************************************************************************************************/

	/******************************************************************************************************/
	/* Secondly disable or switch off all the other clock sources                                         */
	/******** Clock control (CR) Register ********/
	/*clear this bit (PLLON) with zero (PLL disable)                                                      */
	//RCC->CR.BitAccess.Bit24=0;
	BITCALC_CLEAR_BIT(RCC->CR.FourByteAccess,RCC_u8_PLLON_PIN );
	/* Wait until the PLL Ready flag equals zero                                                          */
	//while( ( BITCALC_GET_BIT(RCC->CR.FourByteAccess,RCC_u8_PLLRDY_PIN) ) ) {}
	/*clear this bit (HSEON) with zero (HSE disable)                                                      */
	BITCALC_CLEAR_BIT(RCC->CR.FourByteAccess,RCC_u8_HSEON_PIN);
	/* Wait until the HSE Ready flag equals zero                                                          */
	//while( ( BITCALC_GET_BIT(RCC->CR.FourByteAccess,RCC_u8_HSERDY_PIN) ) ) {}
	/******************************************************************************************************/

	/*********************** HSI***************************/
	/* if the HSI is enabled then set it's bit and wait for it's flag to be ready                         */
	if(RCC_u8_HSI_CLK_STATUS == RCC_u8_ENABLE)
	{
		/*set the first bit (HSION) with one (internal high speed clock enable) (8MHZ RC oscillator ON)    */
		BITCALC_SET_BIT(RCC->CR.FourByteAccess,RCC_u8_HSION_PIN);
		/* Wait until the HSI Ready flag equals one                                                        */
		while( !( BITCALC_GET_BIT(RCC->CR.FourByteAccess,RCC_u8_HSIRDY_PIN) ) ) {}
	}

	/*********************** HSE ***************************/
	/* if the HSE is enabled then set it's bit and wait for it's flag to be ready                           */
	if(RCC_u8_HSE_CLK_STATUS == RCC_u8_ENABLE)
	{
		/*set this bit (HSEON) with one                                                                     */
		BITCALC_SET_BIT(RCC->CR.FourByteAccess,RCC_u8_HSEON_PIN);
		/* Wait until the HSE Ready flag equals one                                                         */
		while( !( BITCALC_GET_BIT(RCC->CR.FourByteAccess,RCC_u8_HSERDY_PIN) ) ) {}
	}

	/*********************** PLL ***************************/
	/* if the PLL is enabled do the following logic                                                          */
	if(RCC_u8_PLL_CLK_STATUS == RCC_u8_ENABLE)
	{
		/****************** PLL source ******************/
		/* check for the PLL clk entry if it is HSI then make sure that it is enabled and it's flag is ready */
		if (RCC_u8_PLLSRC == RCC_u8_PLL_INPUT_CLK_HSI)
		{
			/* if the HSI flag is not ready                                                                  */
			if(!( BITCALC_GET_BIT(RCC->CR.FourByteAccess,RCC_u8_HSIRDY_PIN) ))
			{
				/* then enable the HSION                                                                     */
				BITCALC_SET_BIT(RCC->CR.FourByteAccess,RCC_u8_HSION_PIN);
				/* Wait until the HSI Ready flag equals one                                                  */
				while( !( BITCALC_GET_BIT(RCC->CR.FourByteAccess,RCC_u8_HSIRDY_PIN) ) ) {}
			}
			/* set the PLLSRC PIN with zero to select the HSI as an entry for the  PLL                       */
			BITCALC_CLEAR_BIT(RCC->CFGR.FourByteAccess,RCC_u8_PLLSRC_PIN);
		}
		/* check for the PLL clk entry if it is HSE then make sure that it is enabled and it's flag is ready */
		if (RCC_u8_PLLSRC == RCC_u8_PLL_INPUT_CLK_HSE)
		{
			/* if the HSE flag is not ready                                                                  */
			if(!( BITCALC_GET_BIT(RCC->CR.FourByteAccess,RCC_u8_HSERDY_PIN) ))
			{
				/* then enable the HSEON                                                                     */
				BITCALC_SET_BIT(RCC->CR.FourByteAccess,RCC_u8_HSEON_PIN);
				/* Wait until the HSE Ready flag equals one                                                  */
				while( !( BITCALC_GET_BIT(RCC->CR.FourByteAccess,RCC_u8_HSERDY_PIN) ) ) {}
			}
			/* set the PLLSRC PIN with one to select the HSE as an entry for the  PLL                       */
			BITCALC_SET_BIT(RCC->CFGR.FourByteAccess,RCC_u8_PLLSRC_PIN);
		}

		/****************** PLL multiplication factor ******************/
		/* set the PLL multiplication factor                                                                */
		BITCALC_ASSIGN_BIT(RCC->CFGR.FourByteAccess,RCC_u8_PLLMUL_PIN18,BITCALC_GET_BIT( RCC_u8_4PIN_PLL_MUL,0));
		BITCALC_ASSIGN_BIT(RCC->CFGR.FourByteAccess,RCC_u8_PLLMUL_PIN19,BITCALC_GET_BIT( RCC_u8_4PIN_PLL_MUL,1));
		BITCALC_ASSIGN_BIT(RCC->CFGR.FourByteAccess,RCC_u8_PLLMUL_PIN20,BITCALC_GET_BIT( RCC_u8_4PIN_PLL_MUL,2));
		BITCALC_ASSIGN_BIT(RCC->CFGR.FourByteAccess,RCC_u8_PLLMUL_PIN21,BITCALC_GET_BIT( RCC_u8_4PIN_PLL_MUL,3));

		/****************** PLL enable ******************/
		/*set this bit (PLLON) with one (PLL clock enable)                                                 */
		BITCALC_SET_BIT(RCC->CR.FourByteAccess,RCC_u8_PLLON_PIN);
		/* Wait until the PLL Ready flag equals one                                                        */
		while( !( BITCALC_GET_BIT(RCC->CR.FourByteAccess,RCC_u8_PLLRDY_PIN) ) ) {}
	}

	/****************** system clock selection ******************/
	/* Select HSI as system clock                                                                         */
	BITCALC_ASSIGN_NIBBLE(RCC->CFGR.FourByteAccess,RCC_u8_SYSCLK_NIBLLE_NUM ,RCC_u8_2PIN_SYSCLK_SOURCE);

	/****************** AHB Prescaler ******************/
	/* assign the AHB prescaler with the configured value                                                 */
	BITCALC_ASSIGN_NIBBLE(RCC->CFGR.FourByteAccess,RCC_u8_AHB_PRESCALER_NIBLLE_NUM,RCC_u8_4PIN_AHB_PRESCALER);

	/****************** APB1 Prescaler ******************/
	/* assign the APB1 prescaler with the configured value                                                  */
	BITCALC_ASSIGN_BIT(RCC->CFGR.FourByteAccess,RCC_u8_APB1PRE_PIN8,BITCALC_GET_BIT( RCC_u8_3PIN_APB1_PRESCALER,0));
	BITCALC_ASSIGN_BIT(RCC->CFGR.FourByteAccess,RCC_u8_APB1PRE_PIN9,BITCALC_GET_BIT( RCC_u8_3PIN_APB1_PRESCALER,1));
	BITCALC_ASSIGN_BIT(RCC->CFGR.FourByteAccess,RCC_u8_APB1PRE_PIN10,BITCALC_GET_BIT( RCC_u8_3PIN_APB1_PRESCALER,2));

	/****************** APB2 Prescaler ******************/
	/* assign the APB2 prescaler with the configured value                                                  */
	BITCALC_ASSIGN_BIT(RCC->CFGR.FourByteAccess,RCC_u8_APB2PRE_PIN11,BITCALC_GET_BIT( RCC_u8_3PIN_APB2_PRESCALER,0));
	BITCALC_ASSIGN_BIT(RCC->CFGR.FourByteAccess,RCC_u8_APB2PRE_PIN12,BITCALC_GET_BIT( RCC_u8_3PIN_APB2_PRESCALER,1));
	BITCALC_ASSIGN_BIT(RCC->CFGR.FourByteAccess,RCC_u8_APB2PRE_PIN13,BITCALC_GET_BIT( RCC_u8_3PIN_APB2_PRESCALER,2));
}


/*********************************************************************************
 * Description:Function to enable the peripheral clock
 * Outputs   : Error State
 * Inputs    : Copy_u8State       : The clock state whether it is enabled or disabled
 *             Copy_u8Peripheral: The  peripheral we want to enable
 *********************************************************************************/
u8 RCC_u8EnablePeripheralClock(u8 Copy_u8Peripheral , u8 Copy_u8State)
{
	/* Local Variable indication for Error status */
	u8 Local_u8Error = STD_TYPES_u8_ERROR_OK;
	switch(Copy_u8Peripheral)
	{
	/****** PORTA******/
	/*set the third bit in APB2 peripheral clock enable register with one (IO PORT A clock enable)   */
	case RCC_u8_GPIOA : RCC->APB2ENR.BitAccess.Bit2 = Copy_u8State;
	break;
	/****** PORTB******/
	/*set the fourth bit in APB2 peripheral clock enable register with one (IO PORT B clock enable)   */
	case RCC_u8_GPIOB : RCC->APB2ENR.BitAccess.Bit3 = Copy_u8State;
	break;
	/****** PORTC******/
	/*set the fifth bit in APB2 peripheral clock enable register with one (IO PORT C clock enable)   */
	case RCC_u8_GPIOC : RCC->APB2ENR.BitAccess.Bit4 = Copy_u8State;
	break;
	/****** PORTD******/
	/*set the sixth bit in APB2 peripheral clock enable register with one (IO PORT D clock enable)   */
	case RCC_u8_GPIOD : RCC->APB2ENR.BitAccess.Bit5 = Copy_u8State;
	break;
	/****** UART2******/
	/*set bit 17 in APB1 peripheral clock enable register with one (UART2 clock enable)              */
	case RCC_u8_UART2 : RCC->APB1ENR.BitAccess.Bit17 = Copy_u8State;
	break;
	/****** AFIO******/
	/*set bit0 in APB2 peripheral clock enable register with one (alternative function IO clock enable)*/
	case RCC_u8_AFIO  : RCC->APB2ENR.BitAccess.Bit0 = Copy_u8State;
	break;
	/* In case of wrong peripheral return an error and this is considered as input validation checking*/
	default          : Local_u8Error = STD_TYPES_u8_ERROR_NOK;
	break;
	}
	/* Function Return */
	return Local_u8Error;
}





/*********************************************************************************
 * Description:Function to enable the peripheral clock
 * Outputs   : Error State
 * Inputs    : Copy_u8Bus       : The bus on which the peripheral is connected
 *             Copy_u8Peripheral: The  peripheral we want to enable
 *********************************************************************************/
//u8 RCC_u8EnablePeripheralClock(u8 Copy_u8Bus , u8 Copy_u8Peripheral)
