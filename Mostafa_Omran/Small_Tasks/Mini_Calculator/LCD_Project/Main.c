/*
 * Main.c
 *
 *  Created on: Mar 28, 2022
 *      Author: Mostafa
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include <util/delay.h>

#include "DIO_register.h"
#include "DIO_interface.h"
#include "CLCD_interface.h"
#include "KPD_interface.h"


void main(void)
{
	s8 x,y,z,i=0,j=0,k=0,l=0;
	PORT_voidInit();
	CLCD_voidInit(CLCD_2Lines_5x8Fontsize,CLCD_Curser_OFF);
	//CLCD_voidGoToXY(0,1);
	u8 arr_num[10]={0,1,2,3,4,5,6,7,8,9};
	u8 arr_sign[4]={'+','-','*','/'};
	u8 arr_arrow[8]={
			0b00000100,
			0b00001010,
			0b00010101,
			0b00000100,
			0b00000100,
			0b00000100,
			0b00000100};
	CLCD_voidWriteNumber(arr_num[0]);
	CLCD_voidSendData(arr_sign[0]);
	CLCD_voidWriteNumber(arr_num[0]);
	CLCD_voidSendData('=');
	CLCD_voidWriteNumber(0);
	while(1)
	{
		while(GET_BIT(PIND,0)==0)
		{
			_delay_ms(250);
			k++;
			while(k==1)
			{
				x=arr_num[i];
				if(GET_BIT(PIND,2)==0)
				{
					_delay_ms(200);
					i++;
				}
				if(GET_BIT(PIND,1)==0)
				{
					_delay_ms(200);
					i--;
				}
				if(i<0)
					i=0;
				if(i>9)
					i=9;
				CLCD_voidGoToXY(0,0);
				CLCD_voidWriteNumber(x);
				CLCD_voidWriteSpecialCharacter(arr_arrow,0,1,0);
				_delay_ms(25);
				if(GET_BIT(PIND,0)==0)
					break;

			}
			while(k==2)
			{
				z=arr_sign[j];
				if(GET_BIT(PIND,2)==0)
				{
					_delay_ms(200);
					j++;
				}
				if(GET_BIT(PIND,1)==0)
				{
					_delay_ms(200);
					j--;
				}
				if(j<0)
					j=0;
				if(j>3)
					j=3;
				CLCD_voidGoToXY(0,1);
				CLCD_voidSendData(z);
				CLCD_voidGoToXY(1,0);
				CLCD_voidSendData(' ');
				CLCD_voidWriteSpecialCharacter(arr_arrow,0,1,1);
				_delay_ms(25);
				if(GET_BIT(PIND,0)==0)
					break;

			}

			while(k==3)
			{
				y=arr_num[l];
				if(GET_BIT(PIND,2)==0)
				{
					_delay_ms(200);
					l++;
				}
				if(GET_BIT(PIND,1)==0)
				{
					_delay_ms(200);
					l--;
				}
				if(l>9)
					l=9;
				CLCD_voidGoToXY(0,2);
				CLCD_voidWriteNumber(y);
				CLCD_voidGoToXY(1,1);
				CLCD_voidSendData(' ');
				CLCD_voidWriteSpecialCharacter(arr_arrow,0,1,2);
				_delay_ms(25);
				if(GET_BIT(PIND,0)==0)
					break;

			}
			while(k==4)
			{
				CLCD_voidGoToXY(0,4);
				switch(z)
				{
				case '+':
					CLCD_voidWriteNumber(x+y);
					break;
				case '-':
					CLCD_voidWriteNumber(x-y);
					break;
				case '/':
					CLCD_voidWriteNumber(x/y);
					break;
				case '*':
					CLCD_voidWriteNumber(x*y);
				}

				CLCD_voidGoToXY(1,2);
				CLCD_voidSendData(' ');
				CLCD_voidWriteSpecialCharacter(arr_arrow,0,1,4);
				_delay_ms(25);
				if(GET_BIT(PIND,0)==0)
				{
					CLCD_voidGoToXY(1,4);
					CLCD_voidSendData(' ');
					break;
				}


			}
			if(k>4)
				k=0;

		}

	}

}
