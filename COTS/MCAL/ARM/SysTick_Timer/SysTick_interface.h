/***********************************************************************************/
/*                                                                                */
/* File Name   : SysTick_interface.h                                             */
/*                                                                              */
/* Created on  : Apr 22, 2019                                                  */
/*                                                                            */
/* Author      : shereen Abd Elhady                                          */
/*                                                                          */
/* Version     : V01                                                       */
/*                                                                        */
/* Description : Interface file for systick timer driver includes        */
/*                                                                      */
/*               APIs' prototypes And MACROS for call                  */
/*                                                                    */
/* Layer       : MCAL                                                */
/*                                                                  */
/*******************************************************************/

#ifndef SYSTICK_INTERFACE_H_
#define SYSTICK_INTERFACE_H_


              /******************************* Registers Addresses *****************************/
                                   /********* SysTick Base address (0xE000E010)**********/

/* (STK_CTRL) systick control & status register address definition, Offset address (0x00) */
#define SYSTICK_u32_CTRL  *((u32*) 0xE000E010)

/* (STK_LOAD) systick reload value register address definition, Offset address (0x04)     */
#define SYSTICK_u32_LOAD  *((u32*) 0xE000E014)

/* (STK_VAL) systick current value register address definition, Offset address (0x08)     */
#define SYSTICK_u32_VAL   *((u32*) 0xE000E018)

/* STK_CTRL PINs' definitions                                                             */
#define SYSTICK_u8_CTRL_ENABLE    (u8)0
#define SYSTICK_u8_CTRL_TICKINT   (u8)1
#define SYSTICK_u8_CTRL_CLKSOURCE (u8)2

/*SysTick values' definitions to be used in the configurations' structure                */
#define SYSTICK_u8_TICKINT_ENABLE           (u8)0x02
#define SYSTICK_u8_TICKINT_DISABLE          (u8)0x00
#define SYSTICK_u8_CLKSOURCE_AHB	        (u8)0x04
#define SYSTICK_u8_CLKSOURCE_AHB_DIVIDED_8  (u8)0x00


/*Structure to be used by the configurator to set the clock prescaler & interrupt state   */
typedef struct
{
	u8 Clock_Prescaler;
	u8 Interrupt_State;
}SysTickConfigurations_type;


       /*********************************** APIs Prototypes ************************************/

/**************************************************************************************************
 * Description: Function to configure the systick timer clock prescaler whether it's gonna be
 *              AHB or AHB/8 processor clock, also to enable the systick exception request.
 * Outputs   :  None
 * Inputs    :  None
 **************************************************************************************************/
extern void SysTick_VidInit(void);

/**************************************************************************************************
 * Description: Function to enable the systick timer to load the reload value from the load register
 *              and then counts down.
 * Outputs   :  None
 * Inputs    :  None
 **************************************************************************************************/
extern void SysTick_VidEnable (void);

/**************************************************************************************************
 * Description: Function to enable the systick timer
 * Outputs   :  None
 * Inputs    :  None
 **************************************************************************************************/
extern void SysTick_VidDisable (void);


/**************************************************************************************************
 * Description: Function to calculate the reload value in case of the desired time was in milli seconds
 *              and  load the reload value to the load register.
 *              and then counts down.
 * Outputs   :  None
 * Inputs    :  Copy_u16TimeMilliSec : desired time milli second
 **************************************************************************************************/
void SysTick_VidSetTickTimeMilliSecond(u16 Copy_u16TimeMilliSec);


/**************************************************************************************************
 * Description: Function to calculate the reload value in case of the desired time was in micro seconds
 *              and  load the reload value to the load register.
 *              and then counts down.
 * Outputs   :  None
 * Inputs    :  Copy_u16TimeMicroSec : desired time micro second
 **************************************************************************************************/
void SysTick_VidSetTickTimeMicroSecond(u16 Copy_u16TimeMicroSec);


/****************************************************************************************************
 * Description:Function to Set the pointer to callback function with the address of the function
 *              Needed to be implemented by the ISR.
 * Outputs   : None
 * Inputs    : Copy_PVidFunCallback: pointer to callback function to set the pointer
 *             Value with the address of the function needed to be implemented by the ISR.
 ***************************************************************************************************/
extern void SysTick_VidSetCallback(Callback_type Copy_PVidFunCallback);


/****************************************************************************************************
 * Description:SysTick timer Interrupt Service Routine which includes a pointer points to a function
 *             Send by user to be implemented.
 * Outputs    :None
 * Inputs     :None
 ***************************************************************************************************/
void SysTick_Handler (void);


#endif /* SYSTICK_INTERFACE_H_ */

