/*
 * StopWatchmain.c
 *
 *  Created on: 9 Apr 2022
 *      Author: Mahmoud
 */

#include "util/delay.h"
#include "SSD_interface.h"
#include "STD_TYPES.h"
#include "BIT_Math.h"
#include "DIO_interface.h"

void main (void)
{

	DIO_u8SetPortDirection(DIO_u8PORTD,DIO_u8PORT_INPUT);
	DIO_u8SetPortDirection(DIO_u8PORTC,DIO_u8PORT_OUTPUT);
	DIO_u8SetPortDirection(DIO_u8PORTB,DIO_u8PORT_OUTPUT);



	u8 i,x,c,D1=0;

	u8 SevenSegmantArr [10]=
	{
			NUM_0,
			NUM_1,
			NUM_2,
			NUM_3,
			NUM_4,
			NUM_5,
			NUM_6,
			NUM_7,
			NUM_8,
			NUM_9,
	};




	while (1)
	{


		while(c<=9999) //while the seven segmant is not all filled git the pin
		{
			DIO_u8GetPinValue(DIO_u8PORTD,DIO_u8PIN0,&x);//get  pin0 in port D which is the start button


			DIO_u8GetPinValue(DIO_u8PORTD,DIO_u8PIN1,&D1);//get the pin1 in port D which is the stop button





			if (D1==1)
			{

				if(x==0)//start button is pressed
				{

					DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN3,DIO_u8PIN_LOW);//setting the COM to low "Ground"
					DIO_u8SetPortValue(DIO_u8PORTC,SevenSegmantArr[i]);//setting the Sevenseg Portc to the Array
					_delay_ms(500);
					if (i<=9)//while the counter "i" is less than or equal 9 which is the Array completion
					{


						i++;

					}
					else
					{
						i=0;
					}




				}
				else if (x==1)//start button is not pressed
				{
					//both the com and seven seg port are high so no output off
					DIO_u8SetPortValue(DIO_u8PORTB,DIO_u8PORT_HIGH);
					i=0;


				}
			}
			else
					{
						DIO_u8SetPortValue(DIO_u8PORTC,SevenSegmantArr[i]);//setting the Sevenseg Portc to the Array

					}
		}




	}

}
