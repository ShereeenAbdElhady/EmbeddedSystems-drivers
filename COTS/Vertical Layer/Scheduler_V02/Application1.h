/**********************************************************************************/
/*                                                                               */
/* File Name   : Application1.h                                                 */
/*                                                                             */
/* Created on  : May 20, 2019                                                 */
/*                                                                           */
/* Author      : shereen Abd Elhady                                         */
/*                                                                         */
/* Version     : V02                                                      */
/*                                                                       */
/* Description : first task to be implemented by the scheduler          */
/*                                                                     */
/* Layer       : APP layer                                            */
/*********************************************************************/

#ifndef APPLICATION1_H_
#define APPLICATION1_H_


/********************************************************************************************************
 * Description: Function to initialize the first task tick, Priority and offset number
 * Outputs   :  None
 * Inputs    :  None
 *******************************************************************************************************/
void APP1_VidInitialize(void);


/********************************************************************************************************
 * Description: First Task implementation is to toggle LED
 * Outputs   :  None
 * Inputs    :  None
 *******************************************************************************************************/
void APP1_VidFunc(void);


#endif /* APPLICATION1_H_ */
