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
	PORT_voidInit();
	CLCD_voidInit(CLCD_2Lines_5x8Fontsize,CLCD_Curser_OFF);
	static s8 a,b,c,d,e,f,i=0,j=0,k=0,l=0,m=0,n=0,o=0;
	static u8 arr_num[10]={0,1,2,3,4,5,6,7,8,9};
	static u8 arr_arrow[8]={
			0b00000100,
			0b00001010,
			0b00010101,
			0b00000100,
			0b00000100,
			0b00000100,
			0b00000100};
	static u8 arr_hamoksha[8]={
			 0b00000100
			,0b00001010
			,0b00000100
			,0b00001110
			,0b00010101
			,0b00001010
			,0b00010001};
	CLCD_voidWriteNumber(arr_num[0]);
	CLCD_voidWriteNumber(arr_num[0]);
	CLCD_voidSendData(':');
	CLCD_voidWriteNumber(arr_num[0]);
	CLCD_voidWriteNumber(arr_num[0]);
	CLCD_voidSendData(':');
	CLCD_voidWriteNumber(arr_num[0]);
	CLCD_voidWriteNumber(arr_num[0]);
	while(1)
	{
		while(GET_BIT(PIND,0)==0)
		{
			_delay_ms(250);
			k++;
			while(k==1)
			{
				a=arr_num[i];
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
				if(i>2)
					i=2;
				CLCD_voidGoToXY(0,0);
				CLCD_voidWriteNumber(a);
				CLCD_voidWriteSpecialCharacter(arr_arrow,0,1,0);
				_delay_ms(25);
				if(GET_BIT(PIND,0)==0)
					break;

			}
			while(k==2)
			{
				b=arr_num[j];
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
				if(j>9)
					j=9;
				if(i==2)
				{
					if(j>4)
						j=4;
				}
				CLCD_voidGoToXY(0,1);
				CLCD_voidWriteNumber(b);
				CLCD_voidGoToXY(1,0);
				CLCD_voidSendData(' ');
				CLCD_voidWriteSpecialCharacter(arr_arrow,0,1,1);
				_delay_ms(25);
				if(GET_BIT(PIND,0)==0)
					break;

			}

			while(k==3)
			{
				c=arr_num[l];
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
				if(l>5)
					l=5;
				if(i==2 && j==4)
					l=0;
				CLCD_voidGoToXY(0,3);
				CLCD_voidWriteNumber(c);
				CLCD_voidGoToXY(1,1);
				CLCD_voidSendData(' ');
				CLCD_voidWriteSpecialCharacter(arr_arrow,0,1,3);
				_delay_ms(25);
				if(GET_BIT(PIND,0)==0)
					break;

			}
			while(k==4)
			{
				d=arr_num[m];
				if(GET_BIT(PIND,2)==0)
				{
					_delay_ms(200);
					m++;
				}
				if(GET_BIT(PIND,1)==0)
				{
					_delay_ms(200);
					m--;
				}
				if(m>9)
					m=9;
				if(i==2 && j==4)
					m=0;
				CLCD_voidGoToXY(0,4);
				CLCD_voidWriteNumber(m);
				CLCD_voidGoToXY(1,3);
				CLCD_voidSendData(' ');
				CLCD_voidWriteSpecialCharacter(arr_arrow,0,1,4);
				_delay_ms(25);
				if(GET_BIT(PIND,0)==0)
					break;

			}
			while(k==5)
			{
				e=arr_num[n];
				if(GET_BIT(PIND,2)==0)
				{
					_delay_ms(200);
					n++;
				}
				if(GET_BIT(PIND,1)==0)
				{
					_delay_ms(200);
					n--;
				}
				if(n>5)
					n=5;
				if(i==2 && j==4)
					n=0;
				CLCD_voidGoToXY(0,6);
				CLCD_voidWriteNumber(e);
				CLCD_voidGoToXY(1,4);
				CLCD_voidSendData(' ');
				CLCD_voidWriteSpecialCharacter(arr_arrow,0,1,6);
				_delay_ms(25);
				if(GET_BIT(PIND,0)==0)
					break;

			}
			while(k==6)
			{
				f=arr_num[o];
				if(GET_BIT(PIND,2)==0)
				{
					_delay_ms(200);
					o++;
				}
				if(GET_BIT(PIND,1)==0)
				{
					_delay_ms(200);
					o--;
				}
				if(o>9)
					o=9;
				if(i==2 && j==4)
					o=0;
				CLCD_voidGoToXY(0,7);
				CLCD_voidWriteNumber(f);
				CLCD_voidGoToXY(1,6);
				CLCD_voidSendData(' ');
				CLCD_voidWriteSpecialCharacter(arr_arrow,0,1,7);
				_delay_ms(25);
				if(GET_BIT(PIND,0)==0)
					break;

			}
			while(k==7)
			{
				CLCD_voidGoToXY(1,7);
				CLCD_voidSendData(' ');
				if(o!=0)
				{
					o--;
					e=arr_num[n];
					CLCD_voidGoToXY(0,6);
					f=arr_num[o];
					CLCD_voidGoToXY(0,7);
					CLCD_voidWriteNumber(f);
					_delay_ms(749);
				}

				if(n>0 && o==0)
				{
					n--;
					e=arr_num[n];
					CLCD_voidGoToXY(0,6);
					CLCD_voidWriteNumber(e);
					o=10;
				}
				if(m>0 && n==0 && o==0)
				{
					m--;
					d=arr_num[m];
					CLCD_voidGoToXY(0,4);
					CLCD_voidWriteNumber(m);
					n=5;
					e=arr_num[n];
					CLCD_voidGoToXY(0,6);
					CLCD_voidWriteNumber(e);
					o=10;
				}
				if(l>0 && m==0 && n==0 && o==0)
				{
					l--;
					c=arr_num[l];
					CLCD_voidGoToXY(0,3);
					CLCD_voidWriteNumber(c);
					m=9;
					d=arr_num[m];
					CLCD_voidGoToXY(0,4);
					CLCD_voidWriteNumber(m);
					n=5;
					e=arr_num[n];
					CLCD_voidGoToXY(0,6);
					CLCD_voidWriteNumber(e);
					o=10;
				}
				if(j>0 && l==0 && m==0 && n==0 && o==0)
				{
					j--;
					b=arr_num[j];
					CLCD_voidGoToXY(0,1);
					CLCD_voidWriteNumber(b);
					l=5;
					c=arr_num[l];
					CLCD_voidGoToXY(0,3);
					CLCD_voidWriteNumber(c);
					m=9;
					d=arr_num[m];
					CLCD_voidGoToXY(0,4);
					CLCD_voidWriteNumber(m);
					n=5;
					e=arr_num[n];
					CLCD_voidGoToXY(0,6);
					CLCD_voidWriteNumber(e);
					o=10;
				}
				if(i>0 && j==0 && l==0 && m==0 && n==0 && o==0)
				{
					i--;
					a=arr_num[i];
					CLCD_voidGoToXY(0,0);
					CLCD_voidWriteNumber(a);

					j=9;
					b=arr_num[j];
					CLCD_voidGoToXY(0,1);
					CLCD_voidWriteNumber(b);
					l=5;
					c=arr_num[l];
					CLCD_voidGoToXY(0,3);
					CLCD_voidWriteNumber(c);
					m=9;
					d=arr_num[m];
					CLCD_voidGoToXY(0,4);
					CLCD_voidWriteNumber(m);
					n=5;
					e=arr_num[n];
					CLCD_voidGoToXY(0,6);
					CLCD_voidWriteNumber(e);
					o=10;
				}
				if(i==0 && j==0 && l==0 && m==0 && n==0 && o==0)
				{
					CLCD_voidGoToXY(1,1);
					CLCD_voidSendString("It's TIME");
					CLCD_voidWriteSpecialCharacter(arr_hamoksha,0,1,12);
					break;
				}
			}
			if(k>7)
			{
				k=0;
				CLCD_voidSendCommand(CLCD_Clear_Display);
				CLCD_voidWriteNumber(arr_num[0]);
				CLCD_voidWriteNumber(arr_num[0]);
				CLCD_voidSendData(':');
				CLCD_voidWriteNumber(arr_num[0]);
				CLCD_voidWriteNumber(arr_num[0]);
				CLCD_voidSendData(':');
				CLCD_voidWriteNumber(arr_num[0]);
				CLCD_voidWriteNumber(arr_num[0]);
				i=0,j=0,k=0,l=0,m=0,n=0,o=0;
			}

		}

	}

}
