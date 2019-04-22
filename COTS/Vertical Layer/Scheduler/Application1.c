/**********************************************************************************/
/*                                                                               */
/* File Name   : Application1.c                                                 */
/*                                                                             */
/* Created on  : Apr 22, 2019                                                 */
/*                                                                           */
/* Author      : shereen Abd Elhady                                         */
/*                                                                         */
/* Version     : V01                                                      */
/*                                                                       */
/* Description : first task to be implemented by the scheduler          */
/*                                                                     */
/* Layer       : APP layer                                            */
/*********************************************************************/

#include "../STD_TYPES.h"
#include "../include/DIO_interface.h"
#include "../include/OS_interface.h"
#include "../include/Application1.h"

/*create an object (task) of a Task type structure                            */
Task_type Task1;

/********************************************************************************************************
 * Description: Function to initialize the first task tick, Priority and offset number
 * Outputs   :  None
 * Inputs    :  None
 *******************************************************************************************************/
void APP1_VidInitialize(void)
{
	Task1.Runnable = APP1_VidFunc;
	Task1.Tick    = 1;
	Task1.Priority = 1;
	Task1.Offset = 0;
	/*passing the address of task1(structure) to array of pointers to structures*/
	OS_u8CreateTask(&Task1);
}


/********************************************************************************************************
 * Description: First Task implementation is to toggle LED
 * Outputs   :  None
 * Inputs    :  None
 *******************************************************************************************************/
void APP1_VidFunc(void)
{
	static u8 flag=0;
	if (flag == 0)
	{
		DIO_u8SetPinValue (DIO_u8_PIN34, DIO_u8_PIN_HIGH);
		flag = 1;
	}
	else
	{
		DIO_u8SetPinValue (DIO_u8_PIN34, DIO_u8_PIN_LOW);
		flag = 0;
	}
}
