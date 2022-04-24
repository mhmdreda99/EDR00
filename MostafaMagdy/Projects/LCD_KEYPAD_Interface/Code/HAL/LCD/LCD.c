/*
 * LCD.c
 *
 *  Created on: Apr 2, 2022
 *      Author: Seko
 */

#include "LCD.h"
#include "LCD_Config.h"
#include <stdio.h>
#include <util/delay.h>


void CLCD_init(void)
{
	//Initialize LCD pins direction
	DIO_SetPortDirection(CLCD_DataPort,DIO_OUTPUT);
	DIO_SetPinDirection(CLCD_ControlPort,CLCD_RS_PIN,DIO_OUTPUT);
	DIO_SetPinDirection(CLCD_ControlPort,CLCD_RW_PIN,DIO_OUTPUT);
	DIO_SetPinDirection(CLCD_ControlPort,CLCD_E_PIN,DIO_OUTPUT);

	//delay more than 30ms
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
	//SET RegisterSelect pin low
	DIO_SetPinValue(CLCD_ControlPort,CLCD_RS_PIN,DIO_LOW);
	//SET ReadWrite pin low to write
	DIO_SetPinValue(CLCD_ControlPort,CLCD_RW_PIN,DIO_LOW);
	//SET Data/Command Port value is the command
	DIO_SetPortValue(CLCD_DataPort,Command);
	//SET Enable pin high
	DIO_SetPinValue(CLCD_ControlPort,CLCD_E_PIN,DIO_HIGH);
	_delay_ms(2);
	//SET Enable pin low
	DIO_SetPinValue(CLCD_ControlPort,CLCD_E_PIN,DIO_LOW);
}

void CLCD_SendData(u8 Data)
{
	//SET RegisterSelect pin high
	DIO_SetPinValue(CLCD_ControlPort,CLCD_RS_PIN,DIO_HIGH);
	//SET ReadWrite pin low
	DIO_SetPinValue(CLCD_ControlPort,CLCD_RW_PIN,DIO_LOW);
	//SET Data/Command Port value is the Data
	DIO_SetPortValue(CLCD_DataPort,Data);
	//SET Enable pin high
	DIO_SetPinValue(CLCD_ControlPort,CLCD_E_PIN,DIO_HIGH);
	_delay_ms(2);
	//SET Enable pin low
	DIO_SetPinValue(CLCD_ControlPort,CLCD_E_PIN,DIO_LOW);
}

void CLCD_SendWord(const u8 *Word_PTR)
{
	u8 counter=0;
	while((Word_PTR[counter])!='\0') 		//Word = String = array of charaters
	{
		CLCD_SendData(Word_PTR[counter]);
		counter++;
	}
}

//to move from position to another in CLCD
STD_Return CLCD_GoToXY(u8 X_Position,u8 Y_Position)
{
	u8 DDRAM_address;
	if(X_Position == 0)
		{
			DDRAM_address = Y_Position;
			CLCD_SendCommand(DDRAM_address+Set_Bit7); //128 the value of bit 7 when it set high in DDRAM
			return E_NOK;
		}
	else if (X_Position == 1)
		{
		DDRAM_address = Y_Position + FirstLoc_SecondLine;
		CLCD_SendCommand(DDRAM_address+Set_Bit7); //128 the value of bit 7 when it set high in DDRAM
		return E_NOK;
		}
	else
	{
		return E_OK;
	}
}
//to write special function by CGRAM
void CLCD_SendSpecialChar(u8 *Pattern,u8 BlockNumber,u8 X_Position,u8 Y_Position)
{
	u8 CGRAM_address=0;
	u8 counter;
	CGRAM_address = BlockNumber*8;
	CLCD_SendCommand(CGRAM_address+Set_Bit6);

	for(counter=0;counter<8;counter++)
		{
			CLCD_SendData(Pattern[counter]);
		}
	CLCD_GoToXY(X_Position,Y_Position);
	CLCD_SendData(BlockNumber);
}

void CLCD_display_Decimal_Number (u8 Number)
{

	u8  str[7]; //array pointer where the result will be stored

	sprintf((u8*) str,"%d",Number);

	CLCD_SendWord((u8*) str);

}

void CLCD_display_Real_Number(f64 Number)
{
	u8  str[16];

	char *TempSign = (Number < 0) ? "-" : "";
	f32 TempValue = (Number < 0) ? -Number : Number;

	u8 TempInt1 = TempValue;                  		  // Get the integer (678).
	f32 TempFraction_1 = TempValue - TempInt1;      // Get fraction (0.0123).
	u8 TempInt2 = TempFraction_1 * 10000;  		  // Turn into integer (123).

	// Print as parts, note that you need 0-padding for fractional bit.
	sprintf ((u8*) str, "%s%d.%04d", (u8*) TempSign, TempInt1, TempInt2);

	CLCD_SendWord((u8*) str) ;

}
