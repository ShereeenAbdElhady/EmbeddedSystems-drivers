/**********************************************************************************/
/*                                                                               */
/* File Name   : OS_prog.c                                                      */
/*                                                                             */
/* Created on  : Apr 22, 2019                                                 */
/*                                                                           */
/* Author      : shereen Abd Elhady                                         */
/*                                                                         */
/* Version     : V01                                                      */
/*                                                                       */
/* Description : scheduler implementation using systick timer of        */
/* STM32F103C8 ARM Microcontroller.                                    */
/*                                                                    */
/* Layer       : vertical layer                                      */
/********************************************************************/

#include "../STD_TYPES.h"
#include "../include/SysTick_interface.h"
#include "../include/OS_interface.h"

/*Note: every task is a structure                                                                      */
/*static global variable used by the scheduler to handle the Tasks                                     */
static u32 OS_u32SchedulerCounter;

/********************************************************************************************************
 * Description: Function to initialize the systick with the time after which the ISR will be implemented
 *              And to set the callback to the scheduler to be implemented.
 * Outputs   :  None
 * Inputs    :  None
 *******************************************************************************************************/
extern void OS_VidInitialize(void)
{
	/*Time to generate an interrupt through systick timer                                              */
	SysTick_VidSetTickTimeMilliSecond(1000);
	/*Set the callback with the address of the function Needed to be implemented by the ISR (scheduler)*/
	SysTick_VidSetCallback(& OS_VidScheduler);
}


/********************************************************************************************************
 * Description: Function to start the OS by enabling the systick timer
 *              Take care this function must be called after the OS_VidInit function.
 * Outputs   :  None
 * Inputs    :  None
 *******************************************************************************************************/
extern void OS_VidStart(void)
{
	/*Enable systick timer                                                                           */
	SysTick_VidEnable ();
}


/********************************************************************************************************
 * Description: Function to create a new task by inserting it's address in the array of pointers to tasks
 *              and adjusting it's position in the array according to it's priority.
 * Outputs   :  Error state
 * Inputs    :  const Task_type* Copy_PtrTask: pointer to task structure
 *******************************************************************************************************/
extern u8 OS_u8CreateTask(const Task_type* Copy_PtrTask)
{
	/* Local Variable indication for Error status                                                       */
	u8 Local_u8Error = STD_TYPES_u8_ERROR_OK;
	if (Copy_PtrTask != NULL)
	{
		/*storing the address of the new task in the array of pointers to tasks in it's index(priority)*/
		OS_ArrayPtrTasks[Copy_PtrTask->Priority] =  Copy_PtrTask;
	}
	else
	{
		Local_u8Error = STD_TYPES_u8_ERROR_NOK;
	}
	/* Function Return                                                                                 */
	return Local_u8Error;
}


/********************************************************************************************************
 * Description: scheduler function to organize the task needed to be run according to it's tick time
 *              and offset.
 * Outputs   :  None
 * Inputs    :  None
 *******************************************************************************************************/
static void OS_VidScheduler (void)
{
	/*local variable represents task index used by for loop to loop through the tasks               */
	u8 Local_u8TaskIndex=0;
	for( Local_u8TaskIndex=0 ; Local_u8TaskIndex < OS_u8_SCHEDULER_TASKS_NUM ; Local_u8TaskIndex++)
	{
		if (OS_ArrayPtrTasks[Local_u8TaskIndex] != NULL)
		{
			/*call the runnable task if it meets it's tick and offset number                        */
			if ((OS_u32SchedulerCounter % OS_ArrayPtrTasks[Local_u8TaskIndex]->Tick) == (OS_ArrayPtrTasks[Local_u8TaskIndex]->Offset))
			{
				/* Call the Runnable Task                                                           */
				OS_ArrayPtrTasks[Local_u8TaskIndex]->Runnable();
			}
		}
	}
	OS_u32SchedulerCounter++;
}
