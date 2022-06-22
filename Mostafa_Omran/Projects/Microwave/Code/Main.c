/*
 * Main.c
 *
 *  Created on: Mar 28, 2022
 *      Author: Mostafa
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include <util/delay.h>

#include "DIO_interface.h"
#include "CLCD_interface.h"
#include "KPD_interface.h"
#include "TIMER_interface.h"
#include "GIE_interface.h"
#include "EXTI_interface.h"

void Delay(void);
void Stop(void);
static u32 Global_u32Counter=0;
u8 flag =0;

void main(void)
{

	PORT_voidInit();
	CLCD_voidInit(CLCD_2Lines_5x8Fontsize,CLCD_Curser_OFF);
	TIMER0_voidInit();
	TIMER0_u8SetCallBack(&Delay);
	EXTI_u8Int2Init(EXTI_FALLING_EDGE);
	INT2_voidCallBack(Stop);
	GIE_voidEnable();


	u8 Local_u8Key,Local_u8MinTens,Local_u8MinUnit,Again=0xff;
	u32 Local_u32Time;

	while(1)
	{
		CLCD_voidSendCommand(CLCD_Clear_Display);
		CLCD_voidSendString("To Set The Timer Press Enter");
		do
		{
			Local_u8Key=KPD_u8GetPressedKey();
		}while(Local_u8Key==0xff);
		if(Local_u8Key==11)
		{
			CLCD_voidSendCommand(CLCD_Clear_Display);
			CLCD_voidSendString("Enter The Time  in Min: ");
			do
			{
				Local_u8MinTens=KPD_u8GetPressedKey();
			}while(Local_u8MinTens==0xff);
			CLCD_voidGoToXY(1,7);
			CLCD_voidWriteNumber(Local_u8MinTens);
			do
			{
				Local_u8MinUnit=KPD_u8GetPressedKey();
			}while(Local_u8MinUnit==0xff);
			CLCD_voidGoToXY(1,8);
			CLCD_voidWriteNumber(Local_u8MinUnit);

			do
			{
				Local_u8Key=KPD_u8GetPressedKey();
			}while(Local_u8Key==0xff);

			if(Local_u8Key==11)
			{
				CLCD_voidSendCommand(CLCD_Clear_Display);
				CLCD_voidGoToXY(0,0);
				CLCD_voidSendString("Remaining Time  in sec:");
				Local_u32Time=(10*Local_u8MinTens+Local_u8MinUnit)*60;
				Global_u32Counter=Local_u32Time;
				flag=1;
			}
			while(Global_u32Counter!=0)
			{
				DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN5,DIO_u8PIN_HIGH);
				DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN6,DIO_u8PIN_HIGH);
				DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN7,DIO_u8PIN_HIGH);
			}
			if(Global_u32Counter==0)
			{
				flag=0;
				DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN5,DIO_u8PIN_LOW);
				DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN6,DIO_u8PIN_LOW);
				DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN7,DIO_u8PIN_LOW);
				CLCD_voidSendCommand(CLCD_Clear_Display);
				CLCD_voidSendString("Time out");
				while(Again==0xff)
				{
					do
					{
						Again=KPD_u8GetPressedKey();
					}while(Again==0xff);
				}
			}
		}
	}
}
void Delay(void)
{
	static u16 Local_u16Counter=0;
	Local_u16Counter++;
	if(flag==0)
	{
		Local_u16Counter=0;
	}
	else if(Local_u16Counter==1000 && flag==1)
	{
		Global_u32Counter--;
		CLCD_voidGoToXY(1,7);
		CLCD_voidWriteNumber(Global_u32Counter);
		if(Global_u32Counter==999)
		{
			CLCD_voidGoToXY(1,10);
			CLCD_voidSendData(' ');
		}
		if(Global_u32Counter==99)
		{
			CLCD_voidGoToXY(1,9);
			CLCD_voidSendData(' ');
		}
		if(Global_u32Counter==9)
		{
			CLCD_voidGoToXY(1,8);
			CLCD_voidSendData(' ');
		}
		Local_u16Counter=0;
	}
}
void Stop(void)
{
	DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN5,DIO_u8PIN_LOW);
	if(flag==1)
	{
		Global_u32Counter=0;
		flag=0;
	}
}

