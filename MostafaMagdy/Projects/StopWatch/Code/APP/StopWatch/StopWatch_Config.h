/*
 * LCD_Config.h
 *
 *  Created on: Apr 2, 2022
 *      Author: Seko
 */

#ifndef HAL_LCD_LCD_CONFIG_H_
#define HAL_LCD_LCD_CONFIG_H_

//Selection of Port Used to display Data/ Send Commands
//#define StopWatch_DataPort_A 		DIO_PORTA
#define StopWatch_DataPort_B	DIO_PORTB
//#define StopWatch_DataPort_C	DIO_PORTC
//#define StopWatch_DataPort_D	DIO_PORTD

//Selection of Port Used to Control LCD
#define StopWatch_ControlPort_A			DIO_PORTA
//#define StopWatch_ControlPort_B		DIO_PORTB
//#define StopWatch_ControlPort_C		DIO_PORTC
//#define StopWatch_ControlPort_D		DIO_PORTD

//RegisterSelect pin selections
//#define Control_SEL_0		7
//#define Control_SEL_0		6
//#define Control_SEL_0		5
//#define Control_SEL_0		4
//#define Control_SEL_0		3
//#define Control_SEL_0		2
//#define Control_SEL_0		1
#define Control_SEL_0		0

//Read/Write pin selections
//#define Control_SEL_1		7
//#define Control_SEL_1		6
//#define Control_SEL_1		5
//#define Control_SEL_1		4
//#define Control_SEL_1		3
//#define Control_SEL_1		2
#define Control_SEL_1		1
//#define Control_SEL_0		0



#endif /* HAL_LCD_LCD_CONFIG_H_ */
