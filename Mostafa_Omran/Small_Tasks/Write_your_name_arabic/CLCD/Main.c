/*
 * Main.c
 *
 *  Created on: Mar 28, 2022
 *      Author: Mostafa
 */

#include "STD_TYPES.h"

#include <util/delay.h>

#include "CLCD_interface.h"
#include "DIO_interface.h"

#include "STD_TYPES.h"

#include "CLCD_interface.h"
#include "DIO_interface.h"

void main(void)
{
	/*Initialize LCD pins direction*/
	CLCD_voidInit(CLCD_2Lines_5x11Fontsize,CLCD_Curser_OFF);

	s8 i,j=1;
	u8 arr_mem[8]={
			 0b00000000
			,0b00001111
			,0b00001001
			,0b00001001
			,0b00011111
			,0b00000000
			,0b00000000};

	u8 arr_sad[8]={
			 0b00000000
			,0b00000001
			,0b00000111
			,0b00011001
			,0b00011111
			,0b00000000
			,0b00000000};

	u8 arr_tah[8]={
			 0b00000100
			,0b00000101
			,0b00000111
			,0b00001001
			,0b00011111
			,0b00000000
			,0b00000000};

	u8 arr_fah[8]={
			 0b00000100
			,0b00000000
			,0b00001110
			,0b00001010
			,0b00011111
			,0b00000000
			,0b00000000};

	u8 arr_yah[8]={
			 0b00000000
			,0b00000000
			,0b00000000
			,0b00000000
			,0b00010001
			,0b00010001
			,0b00011111};



while(1)
{
	/*for(i=0;i<16;i++)
		{
			CLCD_voidGoToXY(0,i);
			CLCD_voidSendString("Ramadan Gana");
			_delay_ms(250);
			CLCD_voidSendCommand(CLCD_Clear_Display);
			CLCD_voidGoToXY(1,i);
			CLCD_voidSendString("Ramadan Gana");
			_delay_ms(250);
			CLCD_voidSendCommand(CLCD_Clear_Display);
		}*/

		for(i=0;i<=12;i+=4)
		{
			CLCD_voidWriteSpecialCharacter(arr_mem,0,j,4+i);
			CLCD_voidWriteSpecialCharacter(arr_sad,1,j,3+i);
			CLCD_voidWriteSpecialCharacter(arr_tah,2,j,2+i);
			CLCD_voidWriteSpecialCharacter(arr_fah,3,j,1+i);
			CLCD_voidWriteSpecialCharacter(arr_yah,4,j,0+i);
			_delay_ms(200);
			CLCD_voidSendCommand(CLCD_Clear_Display);
			j-=1;
			if(j<0)
				j=1;
		}



}
}
