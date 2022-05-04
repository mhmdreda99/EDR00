/*
 * Main.c
 *
 *  Created on: Apr 24, 2022
 *      Author: Mostafa
 */


#include "STD_TYPES.h"
#include <util/delay.h>


#include "DIO_interface.h"
#include "ADC_interface.h"
#include "CLCD_interface.h"

#define CeilDot			0b11011111

void main (void)
{
	u16 Local_u8ADCReading=0;
	u16 MiliVolt;
	u8 Temp;

	/*Port Initialization*/
	PORT_voidInit();

	/*ADC Initialization*/
	ADC_voidInit();

	/*Writing on the LCD*/
	CLCD_voidInit(CLCD_2Lines_5x8Fontsize,CLCD_Curser_OFF);
	CLCD_voidSendString("Temperature=00 C");
	CLCD_voidGoToXY(0,14);
	CLCD_voidSendData(CeilDot);

	while(1)
	{
		/*Delay to take the LM35 right voltage*/
		_delay_ms(300);

		/*Starting conversion and pulling the reading and storing it*/
		ADC_u8StartConversionSynch(1,&Local_u8ADCReading);

		/*Calculating the input voltage in milivolt*/
		MiliVolt=((u32)Local_u8ADCReading*5000UL)/1024UL;

		/*Calculating the temperature value corresponding to the input volt 10milivolt=1C */
		Temp=MiliVolt/10;

		/*Go to the temperature position to write the value*/
		CLCD_voidGoToXY(0,12);
		CLCD_voidWriteNumber(Temp);

		/*Check the temperature to determine the fan speed*/
		if(Temp>=10 && Temp<25)
		{
			/*Fan low speed*/
			DIO_u8SetPortValue(DIO_u8PORTB,85);
		}
		else if(Temp>=25 && Temp<30)
		{
			/*Fan medium speed*/
			DIO_u8SetPortValue(DIO_u8PORTB,170);
		}
		else if(Temp>=30)
		{
			/*Fan High speed*/
			DIO_u8SetPortValue(DIO_u8PORTB,255);
		}


	}
}
