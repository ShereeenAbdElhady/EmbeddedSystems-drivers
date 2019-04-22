/**********************************************************************************/
/*                                                                               */
/* File Name   : OS_interface.h                                                 */
/*                                                                             */
/* Created on  : Apr 22, 2019                                                 */
/*                                                                           */
/* Author      : shereen Abd Elhady                                         */
/*                                                                         */
/* Version     : V01                                                      */
/*                                                                       */
/* Description : scheduler implementation using systick timer of        */
/*               STM32F103C8 ARM Microcontroller.                      */
/*                                                                    */
/* Layer       : vertical layer                                      */
/********************************************************************/

#ifndef OS_INTERFACE_H_
#define OS_INTERFACE_H_

/*Note: every task is a structure                                                                               */
/*Structure describes the features of each Task                                                                */
typedef struct
{
	/*Runnable of type pointer to function                                                                     */
	Callback_type Runnable;
	/*The task running after a certain number of ticks                                                         */
	u8 Tick;
	/*Priority of Task by setting the index of the array of tasks(the lower the index the  higher the priority)*/
	u8 Priority;
	/*will start after a certain delay represented by the offset number                                        */
	u8 Offset;
}Task_type;


/*Number of tasks could be handled by the scheduler                                                            */
#define OS_u8_SCHEDULER_TASKS_NUM      (u8)2

/*we will create array of pointers to constant tasks(structures) instead of creating array of tasks(structures)*/
/*to decrease the memory waste                                                                                 */
const Task_type* OS_ArrayPtrTasks[OS_u8_SCHEDULER_TASKS_NUM] ;


                               /*******APIs Prototypes ********/

/********************************************************************************************************
 * Description: Function to initialize the systick with the time after which the ISR will be implemented
 *              And to set the callback to the scheduler to be implemented.
 * Outputs   :  None
 * Inputs    :  None
 *******************************************************************************************************/
extern void OS_VidInitialize(void);


/********************************************************************************************************
 * Description: Function to start the OS by enabling the systick timer
 *              Take care this function must be called after the OS_VidInit function.
 * Outputs   :  None
 * Inputs    :  None
 *******************************************************************************************************/
extern void OS_VidStart(void);


/********************************************************************************************************
 * Description: Function to create a new task by inserting it's address in the array of pointers to tasks
 *              and adjusting it's position in the array according to it's priority.
 * Outputs   :  Error state
 * Inputs    :  const Task_type* Copy_PtrTask: pointer to task structure
 *******************************************************************************************************/
extern u8 OS_u8CreateTask(const Task_type* Copy_PtrTask);


/********************************************************************************************************
 * Description: scheduler function to organize the task needed to be run according to it's tick time
 *              and offset.
 * Outputs   :  None
 * Inputs    :  None
 *******************************************************************************************************/
static void OS_VidScheduler (void);


#endif /* OS_INTERFACE_H_ */
