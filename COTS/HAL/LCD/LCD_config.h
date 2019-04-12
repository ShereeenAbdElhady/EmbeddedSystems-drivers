/*********************************************************************************************/
/*                                                                                          */
/* File Name   : LCD_config.h                                                              */
/*                                                                                        */
/* Created on  : Mar 6, 2019                                                             */
/*                                                                                      */
/* Author      : shereen  Abd Elhady                                                   */
/*                                                                                    */
/* Version     : V01                                                                 */
/*                                                                                  */
/* Description : Basic Public and Private configurations for liquid crystal display*/
/*               defines it's PINs' connections , sending data mode               */
/*               Function set and display control registers settings             */
/*               according to the user desire.                                  */
/*                                                                             */
/* Layer       : HAL                                                          */
/*****************************************************************************/


/**************************Public Configurations **********************************/
/* The first preprocessor guard is for the Public configurations which will be included in the interface file */
#ifndef LCD_PUBLIC_CONFIG_H_
#ifdef  LCD_INTERFACE_H_
#define LCD_PUBLIC_CONFIG_H_



#endif     /* LCD_INTERFACE_H_ */
#endif     /* LCD_PUBLIC_CONFIG_H_ */




/**************************Private Configurations **********************************/
/* The second preprocessor guard is for the Private configurations which will be included in the private file */
#ifndef LCD_PRIVATEC_CONFIG_H_
#ifdef  LCD_PRIVATE_H_
#define LCD_PRIVATE_CONFIG_H_

/* LCD controller 3 PINs definitions                                   */
/* Range: DIO_u8_PIN0
          DIO_u8_PIN1
          DIO_u8_PIN2
          DIO_u8_PIN3
          DIO_u8_PIN4
          DIO_u8_PIN5
          DIO_u8_PIN6
          DIO_u8_PIN7
          DIO_u8_PIN8
          DIO_u8_PIN9
          DIO_u8_PIN10
          DIO_u8_PIN11
          DIO_u8_PIN12
          DIO_u8_PIN13
          DIO_u8_PIN14
          DIO_u8_PIN15
          DIO_u8_PIN16
          DIO_u8_PIN17
          DIO_u8_PIN18
          DIO_u8_PIN19
          DIO_u8_PIN20
          DIO_u8_PIN21
          DIO_u8_PIN22
          DIO_u8_PIN23
          DIO_u8_PIN24
          DIO_u8_PIN25
          DIO_u8_PIN26
          DIO_u8_PIN27
          DIO_u8_PIN28
          DIO_u8_PIN29
          DIO_u8_PIN30
          DIO_u8_PIN31
          DIO_u8_PIN32
          DIO_u8_PIN33
          DIO_u8_PIN34
          DIO_u8_PIN35
          DIO_u8_PIN36
                                                                                       */
#define LCD_u8_RS    DIO_u8_PIN28
#define LCD_u8_RW    DIO_u8_PIN30
#define LCD_u8_E     DIO_u8_PIN31

/* LCD Data 8 PINs definitions                                                         */
/* Range: DIO_u8_PIN0
          DIO_u8_PIN1
          DIO_u8_PIN2
          DIO_u8_PIN3
          DIO_u8_PIN4
          DIO_u8_PIN5
          DIO_u8_PIN6
          DIO_u8_PIN7
          DIO_u8_PIN8
          DIO_u8_PIN9
          DIO_u8_PIN10
          DIO_u8_PIN11
          DIO_u8_PIN12
          DIO_u8_PIN13
          DIO_u8_PIN14
          DIO_u8_PIN15
          DIO_u8_PIN16
          DIO_u8_PIN17
          DIO_u8_PIN18
          DIO_u8_PIN19
          DIO_u8_PIN20
          DIO_u8_PIN21
          DIO_u8_PIN22
          DIO_u8_PIN23
          DIO_u8_PIN24
          DIO_u8_PIN25
          DIO_u8_PIN26
          DIO_u8_PIN27
          DIO_u8_PIN28
          DIO_u8_PIN29
          DIO_u8_PIN30
          DIO_u8_PIN31
          DIO_u8_PIN32
          DIO_u8_PIN33
          DIO_u8_PIN34
          DIO_u8_PIN35
          DIO_u8_PIN36
                                                                                       */
#define LCD_u8_D0    DIO_u8_PIN0
#define LCD_u8_D1    DIO_u8_PIN1
#define LCD_u8_D2    DIO_u8_PIN2
#define LCD_u8_D3    DIO_u8_PIN3
#define LCD_u8_D4    DIO_u8_PIN4
#define LCD_u8_D5    DIO_u8_PIN5
#define LCD_u8_D6    DIO_u8_PIN6
#define LCD_u8_D7    DIO_u8_PIN7

/* Max Number of rows and columns values definitions */
#define LCD_u8_MAX_COL_NUMBER    (u8)16
#define LCD_u8_MAX_ROW_NUMBER    (u8)2

/* The customer will configure the data length according to his desire                  */
/* Range: LCD_u8_8BIT_DATA_MODE                                                         */
/*        LCD_u8_4BIT_DATA_MODE                                                         */
#define LCD_u8_DATA_LENGTH_MODE              LCD_u8_4BIT_DATA_MODE

/* The customer will configure the Function set register mode of 8 bits data mode       */
/* Range: LCD_u8_8BIT_2LINES_5X7_FONT                                                   */
/*        LCD_u8_8BIT_2LINES_5X10_FONT                                                  */
/*        LCD_u8_8BIT_1LINE_5X7_FONT                                                    */
/*        LCD_u8_8BIT_1LINE_5X10_FONT                                                   */
#define LCD_u8_8BIT_FUNCTION_SET_REG_MODE    LCD_u8_8BIT_2LINES_5X7_FONT

/* The customer will configure the display control register mode according to his desire */
/* Range: LCD_u8_8BIT_ENBALE_CURSORON_BLINKON                                            */
/*        LCD_u8_8BIT_ENBALE_CURSORON_BLINKOFF                                           */
/*        LCD_u8_8BIT_ENBALE_CURSOROFF_BLINKOFF                                          */
/*        LCD_u8_8BIT_DISABLE                                                            */
#define LCD_u8_8BIT_DISPLAY_CONTROL_REG_MODE  LCD_u8_8BIT_ENBALE_CURSORON_BLINKON


/* The customer will configure the Function set register mode of 4 bits data mode        */
/* Range: LCD_u8_4BIT_2LINES_5X7_FONT                                                    */
/*        LCD_u8_4BIT_2LINES_5X10_FONT                                                   */
/*        LCD_u8_4BIT_1LINE_5X7_FONT                                                     */
/*        LCD_u8_4BIT_1LINE_5X10_FONT                                                    */
#define LCD_u8_4BIT_FUNCTION_SET_REG_MODE     LCD_u8_4BIT_2LINES_5X7_FONT

/* The customer will configure the display control register mode according to his desire  */
/* Range: LCD_u8_4BIT_ENBALE_CURSORON_BLINKON                                             */
/*        LCD_u8_4BIT_ENBALE_CURSORON_BLINKOFF                                            */
/*        LCD_u8_4BIT_ENBALE_CURSOROFF_BLINKOFF                                           */
/*        LCD_u8_4BIT_DISABLE                                                             */
#define LCD_u8_4BIT_DISPLAY_CONTROL_REG_MODE  LCD_u8_4BIT_ENBALE_CURSORON_BLINKON

#endif   /* LCD_PRIVATE_CONFIG_H_ */
#endif /* LCD_CONFIG_H_ */

