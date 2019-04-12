/**********************************************************************************/
/* File Name   : BIT_CALC.h                                                      */
/*                                                                              */
/* Created on  : Dec 1, 2018                                                   */
/*                                                                            */
/* Author      : shereen Abd Elhady                                          */
/*                                                                          */
/* Version     : V01                                                       */
/*                                                                        */
/* Description : Commonly used MACROS which performs different operations*/
/*               on any BIT in any register.                            */
/*                                                                     */
/**********************************************************************/


/*This is preprocessor (Header file) guard  */
#ifndef BIT_CALC_H_
#define BIT_CALC_H_

/******************************************************************/
/* This macro sets a certain bit in any variable                 */
/* input : VAR: variable to be changed                          */
/*         BIT_NO: number of the bit to be set                 */
/**************************************************************/
#define BITCALC_SET_BIT(VAR,BIT_NO) ((VAR)|=(1<<(BIT_NO)))                               //4 cycles  improve to 2 cycles

/**************************************************************/
/*This macro clears a certain bit in any variable            */
/* input : VAR: variable to be changed                      */
/*         BIT_NO: number of the bit to be cleared         */
/**********************************************************/
#define BITCALC_CLEAR_BIT(VAR,BIT_NO) ((VAR)&=(~(1<<(BIT_NO))))                          //5 cycles improve to 3 cycles


/************************************************************/
/*This macro toggles a certain bit in any variable         */
/* input : VAR: variable to be changed                    */
/*         BIT_NO: number of the bit to be toggle        */
/********************************************************/
#define BITCALC_TOGGLE_BIT(VAR,BIT_NO) ((VAR)^=(1<<(BIT_NO)))                            //4 cycles improve to 2 cycles


/*********************************************************/
/*This macro assign a certain bit in any variable       */
/* input : VAR: variable to be changed                 */
/*         BIT_NO: number of the bit to be assign     */
/*        VAL: value of bit to assign the macro with */
/****************************************************/
/*if VAL == 1 assign the bit with 1 value otherwise assign it with 0 value */
#define VAL 1
#define BITCALC_ASSIGN_BIT(VAR,BIT_NO,VAL) VAR=((VAR)&(~(1<<(BIT_NO))))|(VAL<<(BIT_NO))  //7 cycles improve to 2 cycles


/********************************************************/
/*This macro to get a certain bit in any variable      */
/* input : VAR: variable value                        */
/*         BIT_NO: number of the bit to get          */
/****************************************************/
//#define BITCALC_GET_BIT(VAR,BIT_NO) ((VAR)&(1<<BIT_NO))!=0 ? (printf("%d",1)):(printf("%d",0))
#define BITCALC_GET_BIT(VAR,BIT_NO) ((VAR)>>(BIT_NO))&(0X01)



/***********************************************************/
/*This macro assign a certain nibble in any register      */
/* input : REG: register to be changed                   */
/*         NIBBLE_NO: number of the nibble to be assign */
/*        VAL: value of nibble to assign the macro with*/
/******************************************************/
#define BITCALC_ASSIGN_NIBBLE(REG,NIBBLE_NO,VAL) REG=(((REG)&(~((0xF)<<(NIBBLE_NO*4))))|((VAL)<<(NIBBLE_NO*4)))



/*********************************************************/
/*This macro assign 32 bit variable with any value      */
/* input : VAR: variable to be changed                 */
/*        VAL: value  to assign the macro with        */
/*****************************************************/
#define BITCALC_ASSIGN_PORT(VAR,VAL) VAR = (((VAR)&(0x00000000))|(VAL))


/******************************************************/
/*This macro to get value of any variable            */
/* input : VAR: variable value                      */
/****************************************************/
#define BITCALC_GET_PORT(VAR) ((VAR)&(0xFFFFFFFF))




#endif /* BIT_CALC_H_ */

