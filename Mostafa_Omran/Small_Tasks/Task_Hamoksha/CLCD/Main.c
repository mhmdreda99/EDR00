/*
 * Main.c
 *
 *  Created on: Mar 28, 2022
 *      Author: Mostafa
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include <util/delay.h>

#include "CLCD_interface.h"
#include "DIO_interface.h"


#include "CLCD_interface.h"
#include "DIO_interface.h"

void main(void)
{
	/*Initialize LCD pins direction*/
	CLCD_voidInit(CLCD_2Lines_5x11Fontsize,CLCD_Curser_OFF);

	u8 i;
	u8 arr_hamoksha[8]={
			0b00000100
			,0b00001010
			,0b00000100
			,0b00001110
			,0b00010101
			,0b00001010
			,0b00010001};

	u8 arr_Foot[8]={
			0b00000100
			,0b00001010
			,0b00000100
			,0b00001110
			,0b00000100
			,0b00001010
			,0b00010001};

	u8 arr_Run1[8]={
			0b00000100
			,0b00001010
			,0b00000101
			,0b00001110
			,0b00010100
			,0b00001100
			,0b00010100};

	u8 arr_Run2[8]={
			0b00000100
			,0b00001010
			,0b00010100
			,0b00001110
			,0b00000101
			,0b00000110
			,0b00000101};

	u8 arr_yah[8]={
			0b00000000
			,0b00000000
			,0b00000000
			,0b00000000
			,0b00010001
			,0b00010001
			,0b00011111};

	CLCD_voidWriteSpecialCharacter(arr_hamoksha,0,0,0);
	CLCD_voidGoToXY(0,3);
	CLCD_voidSendString("Hello Iam");
	CLCD_voidGoToXY(1,5);
	CLCD_voidSendString("Hamoksha");
	_delay_ms(1000);
	CLCD_voidSendCommand(CLCD_Clear_Display);
	CLCD_voidGoToXY(0,3);
	CLCD_voidSendString("I can Play");
	CLCD_voidGoToXY(1,5);
	CLCD_voidSendString("Football");

	for(i=0;i<6;i++)
	{
		SET_BIT(arr_Foot[5-i],4);
		CLCD_voidWriteSpecialCharacter(arr_Foot,1,1,0);
		CLR_BIT(arr_Foot[5-i],4);
		_delay_ms(200);
	}
	for(i=5;i>0;i--)
	{
		SET_BIT(arr_Foot[5-i],4);
		CLCD_voidWriteSpecialCharacter(arr_Foot,1,1,0);
		CLR_BIT(arr_Foot[5-i],4);
		_delay_ms(200);
	}
	CLCD_voidSendCommand(CLCD_Clear_Display);
	CLCD_voidGoToXY(0,3);
	CLCD_voidSendString("I can Play");
	CLCD_voidGoToXY(1,5);
	CLCD_voidSendString("Run");
	_delay_ms(500);
	CLCD_voidSendCommand(CLCD_Clear_Display);
	CLCD_voidWriteSpecialCharacter(arr_hamoksha,0,0,0);
	for(i=0;i<8;i++)
	{
		CLCD_voidSendCommand(CLCD_Clear_Display);
		CLCD_voidWriteSpecialCharacter(arr_Run1,2,0,1+2*i);
		_delay_ms(200);
		CLCD_voidSendCommand(CLCD_Clear_Display);
		CLCD_voidWriteSpecialCharacter(arr_Run2,2,0,2+2*i);
		_delay_ms(200);
	}
	for(i=1;i<8;i++)
	{
		CLCD_voidSendCommand(CLCD_Clear_Display);
		CLCD_voidWriteSpecialCharacter(arr_Run2,2,0,16-2*i);
		_delay_ms(200);
		CLCD_voidSendCommand(CLCD_Clear_Display);
		CLCD_voidWriteSpecialCharacter(arr_Run1,2,0,15-2*i);
		_delay_ms(200);

	}
	CLCD_voidSendCommand(CLCD_Clear_Display);
	CLCD_voidWriteSpecialCharacter(arr_hamoksha,0,0,0);
	_delay_ms(200);

	CLCD_voidSendCommand(CLCD_Clear_Display);
	CLCD_voidGoToXY(0,3);
	CLCD_voidSendString("I can Dance");
	_delay_ms(500);
	for(i=1;i<8;i++)
	{

		CLCD_voidWriteSpecialCharacter(arr_Run2,2,0,0);
		_delay_ms(200);

		CLCD_voidWriteSpecialCharacter(arr_Run1,2,0,0);
		_delay_ms(200);

	}

	while(1)
	{



	}
}
