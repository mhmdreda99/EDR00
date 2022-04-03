/*
 * LCD.c
 *
 *  Created on: Apr 2, 2022
 *      Author: Seko
 */

#include "LCD.h"
#include "LCD_Config.h"
#include <util/delay.h>


void CLCD_init(void)
{
	_delay_ms(40);

	#ifdef CLCD_OneLine_5x8Size
	CLCD_SendCommand(CLCD_OneLine_5x8Size);
	#elif CLCD_OneLine_5x11Size
	CLCD_SendCommand(CLCD_OneLine_5x11Size );
	#elif  CLCD_TwoLines_5x8Size
	CLCD_SendCommand(CLCD_TwoLines_5x8Size);
	#elif CLCD_TwoLines_5x11Size
	CLCD_SendCommand(CLCD_TwoLines_5x11Size);
	#endif

	CLCD_SendCommand(CLCD_DISP_ON_CURSOR_BLINK);
	CLCD_SendCommand(CLCD_CLEAR);
}
void CLCD_SendCommand(u8 Command)
{
	//SET RegisterSelect pin o/p
	DIO_SetPinDirection(CLCD_ControlPort,CLCD_RS_PIN,DIO_OUTPUT);
	//SET ReadWrite pin o/p
	DIO_SetPinDirection(CLCD_ControlPort,CLCD_RW_PIN,DIO_OUTPUT);
	//SET Enable pin o/p
	DIO_SetPinDirection(CLCD_ControlPort,CLCD_E_PIN,DIO_OUTPUT);
	//SET RegisterSelect pin low
	DIO_SetPinValue(CLCD_ControlPort,CLCD_RS_PIN,DIO_LOW);
	//SET ReadWrite pin low to write
	DIO_SetPinValue(CLCD_ControlPort,CLCD_RW_PIN,DIO_LOW);
	//SET Data/Command Port o/p
	DIO_SetPortDirection(CLCD_DataPort,DIO_OUTPUT);
	DIO_SetPortValue(CLCD_DataPort,Command);
	//SET Enable pin high
	DIO_SetPinValue(CLCD_ControlPort,CLCD_E_PIN,DIO_HIGH);
	_delay_ms(2);
	//SET Enable pin low
	DIO_SetPinValue(CLCD_ControlPort,CLCD_E_PIN,DIO_LOW);
}

void CLCD_SendData(u8 Data)
{
	//SET RegisterSelect pin o/p
	DIO_SetPinDirection(CLCD_ControlPort,CLCD_RS_PIN,DIO_OUTPUT);
	//SET ReadWrite pin o/p
	DIO_SetPinDirection(CLCD_ControlPort,CLCD_RW_PIN,DIO_OUTPUT);
	//SET Enable pin o/p
	DIO_SetPinDirection(CLCD_ControlPort,CLCD_E_PIN,DIO_OUTPUT);
	//SET RegisterSelect pin high
	DIO_SetPinValue(CLCD_ControlPort,CLCD_RS_PIN,DIO_HIGH);
	//SET ReadWrite pin high
	DIO_SetPinValue(CLCD_ControlPort,CLCD_RW_PIN,DIO_LOW);
	//SET Data/Command Port o/p
	DIO_SetPortDirection(CLCD_DataPort,DIO_OUTPUT);
	DIO_SetPortValue(CLCD_DataPort,Data);
	//SET Enable pin high
	DIO_SetPinValue(CLCD_ControlPort,CLCD_E_PIN,DIO_HIGH);
	_delay_ms(2);
	//SET Enable pin low
	DIO_SetPinValue(CLCD_ControlPort,CLCD_E_PIN,DIO_LOW);
}
