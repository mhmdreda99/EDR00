/*
 * Main.c
 *
 *  Created on: Mar 8, 2022
 *      Author: Mostafa
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Delay.h"
#include<util/delay.h>


#include "DIO_interface.h"
#include "DIO_register.h"
#include "EXTI_interface.h"
#include "GIE_interface.h"
#include "SSD_interface.h"
#include "SSD_config.h"


#define F_CPU 8000000UL
void Stop_StopWatch(void);

u8 x,i,j,k,l,z;

int main()
{

	/*Define new  7-Segment */
	SSD_t SSD1={Cathode,DIO_u8PORTB,DIO_u8PORTC,DIO_u8PIN4};

	/*Define pointer to the struct*/
	SSD_t*ptr1=&SSD1;

	/*Define the Start button*/
	DIO_u8SetPinDirection(DIO_u8PORTD,DIO_u8PIN0,DIO_u8PIN_INPUT);
	DIO_u8SetPinValue(DIO_u8PORTD,DIO_u8PIN0,DIO_u8PIN_HIGH);

	/*Define the Reset button*/
	DIO_u8SetPinDirection(DIO_u8PORTD,DIO_u8PIN1,DIO_u8PIN_INPUT);
	DIO_u8SetPinValue(DIO_u8PORTD,DIO_u8PIN1,DIO_u8PIN_HIGH);

	/*Define the Stop button*/
	DIO_u8SetPinDirection(DIO_u8PORTD,DIO_u8PIN2,DIO_u8PIN_INPUT);
	DIO_u8SetPinValue(DIO_u8PORTD,DIO_u8PIN2,DIO_u8PIN_HIGH);

	EXTI_u8Int0Init(EXTI_FALLING_EDGE);
	GIE_voidEnable();
	INT0_voidCallBack(Stop_StopWatch);

	SSD_DEMUX_Init(ptr1);

	while(1)
	{
		if(GET_BIT(PIND,0)==0)
		{
			for(l=0;l<10;l++)
			{
				for(k=0;k<10;k++)
				{
					for(j=0;j<6;j++)
					{
						for(i=0;i<10;i++)
						{
							for(x=0;x<50;x++)
							{
								if(GET_BIT(PIND,1)==0)
								{
									x=0;i=0;j=0;k=0;l=0;
								}
								SSD_Switching_BY_DEMUX(SSD_1);
								SSD_DEMUX_Set_Number(i);
								_delay_ms(5);
								SSD_Switching_BY_DEMUX(SSD_2);
								SSD_DEMUX_Set_Number(j);
								_delay_ms(5);
								SSD_Switching_BY_DEMUX(SSD_3);
								SSD_DEMUX_Set_Number(k);
								_delay_ms(5);
								SSD_Switching_BY_DEMUX(SSD_4);
								SSD_DEMUX_Set_Number(l);
								_delay_ms(5);
							}
						}
					}
				}
			}
		}
	}
}

/*void Stop_StopWatch(void)
{
	while(1)
	{
		SSD_Switching_BY_DEMUX(SSD_1);
		SSD_DEMUX_Set_Number(i);
		_delay_ms(5);
		SSD_Switching_BY_DEMUX(SSD_2);
		SSD_DEMUX_Set_Number(j);
		_delay_ms(5);
		SSD_Switching_BY_DEMUX(SSD_3);
		SSD_DEMUX_Set_Number(k);
		_delay_ms(5);
		SSD_Switching_BY_DEMUX(SSD_4);
		SSD_DEMUX_Set_Number(l);
		_delay_ms(5);
		if(GET_BIT(PIND,DIO_u8PIN2)==0)
		{
			_delay_ms(500);
			if(GET_BIT(PIND,DIO_u8PIN2)==0)
				break;
		}
	}
}*/

void Stop_StopWatch(void)
{
	while(1)
	{
		do
		{
			z=GET_BIT(PIND,DIO_u8PIN2);
			SSD_Switching_BY_DEMUX(SSD_1);
			SSD_DEMUX_Set_Number(i);
			_delay_ms(5);
			SSD_Switching_BY_DEMUX(SSD_2);
			SSD_DEMUX_Set_Number(j);
			_delay_ms(5);
			SSD_Switching_BY_DEMUX(SSD_3);
			SSD_DEMUX_Set_Number(k);
			_delay_ms(5);
			SSD_Switching_BY_DEMUX(SSD_4);
			SSD_DEMUX_Set_Number(l);
			_delay_ms(5);
			if(GET_BIT(PIND,DIO_u8PIN0)==0)
				z=5;
		}
		while(z==1);
		if(z==5)
			break;
	}

}

