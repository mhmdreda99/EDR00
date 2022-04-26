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
#include <stdlib.h>
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

void CLCD_SendWord(u8 *Word_PTR)
{
	while(*Word_PTR) 		//Word = String = array of charaters
	{
		CLCD_SendData(*Word_PTR++);
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

void CLCD_Display_Decimal_Number(s32 num)
{
	u8 i = 0, j, digit, str[10];

	/* if number 0 */
	if (0 == num)
	{
		CLCD_SendData('0');
	}

	/* if the number is negative */
	if (num < 0)
	{
		CLCD_SendData('-');

		/* convert to positive form */
		num = num * -1;
	}

	/* loop on digits of the number */
	while (num > 0)
	{
		digit = (num % 10) + '0';
		str[i] = digit;
		num /= 10;
		i++;
	}

	/* print str on LCD */
	for (j = i; j > 0; j--)
	{
		CLCD_SendData(str[j - 1]);
	}
}
void CLCD_Display_RealNumber(f32 num)
{
	//Left number to the decimal point
	s32 left = (s32)num;
	//calculation to the Right number to the decimal point
	u8 right = (f32)(num - left) * 100;
	//Display Left number to the decimal point
	CLCD_Display_Decimal_Number(left);
	//Display the decimal point
	CLCD_SendData('.');
	//Display the Right number to the decimal point
	CLCD_Display_Decimal_Number(right);
}
