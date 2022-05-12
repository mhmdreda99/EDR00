/*
 * Main.c
 *
 *  Created on: Apr 24, 2022
 *      Author: Mostafa
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "DIO_interface.h"
#include "TIMER_interface.h"
#include "GIE_interface.h"
#include "SSD_interface.h"

void LED(void);
static u8 Global_u8Counter=0;
SSD_t*gptr;
SSD_t*gptr1;

void main (void)
{

	PORT_voidInit();
	TIMER0_voidInit();
	TIMER0_u8SetCallBack(&LED);
	GIE_voidEnable();

	SSD_t SSD={Cathode,DIO_u8PORTC,DIO_u8PORTD,DIO_u8PIN0};
	SSD_t SSD1={Cathode,DIO_u8PORTC,DIO_u8PORTD,DIO_u8PIN1};
	gptr=&SSD;
	gptr1=&SSD1;
	while(1)
	{
		if(Global_u8Counter==10)
		Global_u8Counter=0;
	}

}

void LED(void)
{
	static u16 Local_u16Counter=0;
	Local_u16Counter++;
	if(Local_u16Counter%40 == 0)
	{
		SSD_Enable(gptr);
		SSD_Set_Number(Global_u8Counter,gptr);
		SSD_Disable(gptr1);
	}
	if(Local_u16Counter%80 == 0)
	{
		SSD_Enable(gptr1);
		SSD_Set_Number(9-Global_u8Counter,gptr);
		SSD_Disable(gptr);
	}

	if(Local_u16Counter==4000)
	{
		Global_u8Counter++;
		Local_u16Counter=0;
	}
}
