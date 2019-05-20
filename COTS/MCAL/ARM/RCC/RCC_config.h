/***********************************************************************************/
/*                                                                                */
/* File Name   : RCC_config.h                                                    */
/*                                                                              */
/* Created on  : Mar 5, 2019                                                   */
/*                                                                            */
/* Author      : shereen Abd Elhady                                          */
/*                                                                          */
/* Version     : V02                                                       */
/*                                                                        */
/* Description : configuration file for RCC driver includes              */
/*               Basic private and public clock configurations          */
/*               for STM32F103C8 ARM microcontroller                   */
/*                                                                    */
/* Layer       : MCAL                                                */
/********************************************************************/

            /**************************Public Configurations **********************************/
/* The first preprocessor guard is for the Public configurations which will be included in the interface file */
#ifndef RCC_PUBLIC_CONFIG_H_
#ifdef  RCC_INTERFACE_H_
#define RCC_PUBLIC_CONFIG_H_



#endif     /* RCC_INTERFACE_H_ */
#endif     /* RCC_PUBLIC_CONFIG_H_ */



         /**************************Private Configurations **********************************/
/* The second preprocessor guard is for the Private configurations which will be included in the private file*/
#ifndef RCC_PRIVATE_CONFIG_H_
#ifdef  RCC_PRIVATE_H_
#define RCC_PRIVATE_CONFIG_H_

                               /**** RCC_CR Register PINs Configurations ****/
/* HSION, HSEON and PLLON PINs configurations as they are set and cleared by the software to be enabled or disabled */
/* Range :  RCC_u8_ENABLE                                                                                    */
/*          RCC_u8_DISABLE                                                                                   */
#define RCC_u8_HSI_CLK_STATUS     RCC_u8_ENABLE
#define RCC_u8_HSE_CLK_STATUS     RCC_u8_ENABLE
#define RCC_u8_PLL_CLK_STATUS     RCC_u8_ENABLE

/* External high speed clock bypass PIN configuration as it is set and Cleared by software to bypass the oscillator with an external*/
/* HSEPYB can be  written only if the HSE oscillator is disabled                                             */
/* Range : RCC_u8_BYPASSED                                                                                   */
/*         RCC_u8_NOT_BYPASSED                                                                               */
#define RCC_u8_HSEPYB             RCC_u8_NOT_BYPASSED

/* Clock Security System PIN configuration as it is set and cleared by software to enable clk security system*/
/* Range : RCC_u8_CLK_DETECTOR_OFF                                                                           */
/*         RCC_u8_CLK_DETECTOR_ON                                                                            */
/* CLK detector is on if the HSE oscillator is ready and off if not                                          */
#define RCC_u8_CSSON              RCC_u8_CLK_DETECTOR_OFF

                              /**** RCC_CFGR Register PINs Configurations ****/

/* System clock switch 2 PINs configurations as it is set and cleared by software to select the SYSCLK       */
/* Range : RCC_u8_HSI_SYSCLK                                                                                 */
/*         RCC_u8_HSE_SYSCLK                                                                                 */
/*         RCC_u8_PLL_SYSCLK                                                                                 */
#define RCC_u8_2PIN_SYSCLK_SOURCE    RCC_u8_PLL_SYSCLK

/* AHB prescaler 4 PINs configurations as it set and cleared by the software to control AHB clock division factor*/
/* Range :   RCC_u8_SYSCLK_DIVIDE_NO
             RCC_u8_SYSCLK_DIVIDE_2
             RCC_u8_SYSCLK_DIVIDE_4
             RCC_u8_SYSCLK_DIVIDE_8
             RCC_u8_SYSCLK_DIVIDE_16
             RCC_u8_SYSCLK_DIVIDE_64
             RCC_u8_SYSCLK_DIVIDE_128
             RCC_u8_SYSCLK_DIVIDE_256
             RCC_u8_SYSCLK_DIVIDE_512                                                                            */
#define RCC_u8_4PIN_AHB_PRESCALER     RCC_u8_SYSCLK_DIVIDE_8

/* APB Low speed prescaler (APB1) 3 PINs configurations as it is set and cleared by the software             */
/*to control division factor of APB Low speed clock (PCLK1)                                                  */
/* Range : RCC_u8_HCLK_DIVIDE_NO
           RCC_u8_HCLK_DIVIDE_2
           RCC_u8_HCLK_DIVIDE_4
           RCC_u8_HCLK_DIVIDE_8
           RCC_u8_HCLK_DIVIDE_16                                                                             */
#define RCC_u8_3PIN_APB1_PRESCALER    RCC_u8_HCLK_DIVIDE_8

/* APB High speed prescaler (APB2) 3 PINs configurations as it is set and cleared by the software            */
/*to control division factor of APB High speed clock (PCLK2)                                                 */
/* Range : RCC_u8_HCLK_DIVIDE_NO
           RCC_u8_HCLK_DIVIDE_2
           RCC_u8_HCLK_DIVIDE_4
           RCC_u8_HCLK_DIVIDE_8
           RCC_u8_HCLK_DIVIDE_16                                                                             */
#define RCC_u8_3PIN_APB2_PRESCALER   RCC_u8_HCLK_DIVIDE_8

/* PLL entry clock source as it is set and cleared by software to select PLL clock source                    */
/* Range :  RCC_u8_PLL_INPUT_CLK_HSI/2
            RCC_u8_PLL_INPUT_CLK_HSE                                                                         */

#define RCC_u8_PLLSRC               RCC_u8_PLL_INPUT_CLK_HSI

/* PLL multiplication factor as they are written to define the PLL multiplication factor when PLL is disabled*/
/* Range :  RCC_u8_PLL_MUL_INPUTCLK_X2
            RCC_u8_PLL_MUL_INPUTCLK_X3
            RCC_u8_PLL_MUL_INPUTCLK_X4
            RCC_u8_PLL_MUL_INPUTCLK_X5
            RCC_u8_PLL_MUL_INPUTCLK_X6
            RCC_u8_PLL_MUL_INPUTCLK_X7
            RCC_u8_PLL_MUL_INPUTCLK_X8
            RCC_u8_PLL_MUL_INPUTCLK_X9
            RCC_u8_PLL_MUL_INPUTCLK_X10
            RCC_u8_PLL_MUL_INPUTCLK_X11
            RCC_u8_PLL_MUL_INPUTCLK_X12
            RCC_u8_PLL_MUL_INPUTCLK_X13
            RCC_u8_PLL_MUL_INPUTCLK_X14
            RCC_u8_PLL_MUL_INPUTCLK_X15
            RCC_u8_PLL_MUL_INPUTCLK_X16                                                                   */
#define RCC_u8_4PIN_PLL_MUL         RCC_u8_PLL_MUL_INPUTCLK_X2

#endif    /* RCC_PRIVATE_H_ */
#endif   /* RCC_PRIVATE_CONFIG_H_ */
