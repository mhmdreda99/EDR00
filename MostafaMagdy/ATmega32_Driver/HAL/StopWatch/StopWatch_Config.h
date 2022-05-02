/*
 * @file          StopWatch_Config.h
 * @author        MostafaMagdy
 * @email         MostafaMagii7@gmail.com
 * @Git account:  https:github.com/MostafaMagdy99
 * @version       0.1
 * @date 		  2022-04-28
 * 
 * @copyright Copyright (c) 2022
 * 
 * Description :  Configuration file for StopWatch
 */

/*This is preprocessor Header file guard  */
#ifndef HAL_LCD_LCD_CONFIG_H_
#define HAL_LCD_LCD_CONFIG_H_
/******************************************Defintions**********************************************/
//Selection of Port Used to display Data/ Send Commands
//#define StopWatch_DataPort_A 		DIO_PORTA
#define StopWatch_DataPort_B	DIO_PORTB
//#define StopWatch_DataPort_C	DIO_PORTC
//#define StopWatch_DataPort_D	DIO_PORTD
/***********************************Control PORT Selection*******************************************/
#define StopWatch_ControlPort_A			DIO_PORTA
//#define StopWatch_ControlPort_B		DIO_PORTB
//#define StopWatch_ControlPort_C		DIO_PORTC
//#define StopWatch_ControlPort_D		DIO_PORTD
/***********************************Register Pin Selection*******************************************/
//#define Control_SEL_0		7
//#define Control_SEL_0		6
//#define Control_SEL_0		5
//#define Control_SEL_0		4
//#define Control_SEL_0		3
//#define Control_SEL_0		2
//#define Control_SEL_0		1
#define Control_SEL_0		0
/***************************************R/W Pin Selection*********************************************/
//#define Control_SEL_1		7
//#define Control_SEL_1		6
//#define Control_SEL_1		5
//#define Control_SEL_1		4
//#define Control_SEL_1		3
//#define Control_SEL_1		2
#define Control_SEL_1		1
//#define Control_SEL_0		0
/*****************************************************************************************************/
/*This is preprocessor Header file guard End  */
#endif /* HAL_LCD_LCD_CONFIG_H_ */
