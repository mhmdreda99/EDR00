/*
 ============================================================================
 Name        : main.c
 Author      : Abd0ll0h
 Layer		 : APP
 Target		 : ATMEGA-32
 Version     : 2.0
 Date		 : Apr 17, 2022
 Copyright   :
 Description : 
 ============================================================================
 */

/************************************************************/
/*******************	Include section    ******************/
/************************************************************/

#include <util/delay.h>
#include "config.h"
#include "../LIB/STD_MACROS.h"
#include "../LIB/STD_TYPES.h"
#include "../MCAL/DIO/DIO_interface.h"
#include "../MCAL/EXTINT/EXTINT_interface.h"

/************************************************************/
/*****************	MAIN Function section    ****************/
/************************************************************/

/**
 * Global variables
 */
uint8 sevenSeg[10] =
{ Digit_0,
Digit_1,
Digit_2,
Digit_3,
Digit_4,
Digit_5,
Digit_6,
Digit_7,
Digit_8,
Digit_9 };

uint8 delay, sec_ones, sec_tens, min_ones, min_tens;

void StopFunc()
{
	DISABLE_GLOBAL_INTERRUPT();

	while (READ_BIT(PIND,0) == 1)
	{

		//Enable sec_ones
		DIO_uint8SetPinValue(DIO_PORT_B, DIO_PIN_0, DIO_PIN_LOW);
		DIO_uint8SetPinValue(DIO_PORT_B, DIO_PIN_1, DIO_PIN_LOW);
		DIO_uint8SetPortValue(DIO_PORT_C, sevenSeg[sec_ones]);
		_delay_ms(5);

		//Enable sec_tens
		DIO_uint8SetPinValue(DIO_PORT_B, DIO_PIN_0, DIO_PIN_HIGH);
		DIO_uint8SetPinValue(DIO_PORT_B, DIO_PIN_1, DIO_PIN_LOW);
		DIO_uint8SetPortValue(DIO_PORT_C, sevenSeg[sec_tens]);
		_delay_ms(5);

		//Enable min_ones
		DIO_uint8SetPinValue(DIO_PORT_B, DIO_PIN_0, DIO_PIN_LOW);
		DIO_uint8SetPinValue(DIO_PORT_B, DIO_PIN_1, DIO_PIN_HIGH);
		DIO_uint8SetPortValue(DIO_PORT_C, sevenSeg[min_ones]);
		_delay_ms(5);

		//Enable min_tens
		DIO_uint8SetPinValue(DIO_PORT_B, DIO_PIN_0, DIO_PIN_HIGH);
		DIO_uint8SetPinValue(DIO_PORT_B, DIO_PIN_1, DIO_PIN_HIGH);
		DIO_uint8SetPortValue(DIO_PORT_C, sevenSeg[min_tens]);
		_delay_ms(5);
		if (READ_BIT(PIND,1) == 0)
		{
			delay = 0, sec_ones = 0, sec_tens = 0, min_ones = 0, min_tens = 0;
		}

	}
	ENABLE_GLOBAL_INTERRUPT();
}

void main(void)
{
	DIO_init();
	//7-segment
	DIO_uint8SetPortDirection(DIO_PORT_C, DIO_PORT_OUT);

	//Multiplexer
	DIO_uint8SetPortDirection(DIO_PORT_B, DIO_PORT_OUT);

	//start button
	DIO_uint8SetPinDirection(DIO_PORT_D, DIO_PIN_0, DIO_PIN_IN);
	DIO_uint8SetPinValue(DIO_PORT_D, DIO_PIN_0, DIO_PIN_HIGH); //EN PullUp Resistance

	//Reset button
	DIO_uint8SetPinDirection(DIO_PORT_D, DIO_PIN_1, DIO_PIN_IN);
	DIO_uint8SetPinValue(DIO_PORT_D, DIO_PIN_1, DIO_PIN_HIGH); //EN PullUp Resistance

	//stop button
	DIO_uint8SetPinDirection(DIO_PORT_D, DIO_PIN_2, DIO_PIN_IN);
	DIO_uint8SetPinValue(DIO_PORT_D, DIO_PIN_2, DIO_PIN_HIGH); //EN PullUp Resistance

	//EN INT0
	ENABLE_GLOBAL_INTERRUPT();
	EXTINT_uint8ExternalInt0(EXTINT_FALLING_EDGE);
	EXTINT_callbackInt0(StopFunc);

	//Initial Global Variables
	delay = 0, sec_ones = 0, sec_tens = 0, min_ones = 0, min_tens = 0;
	DIO_uint8SetPortDirection(DIO_PORT_A, DIO_PORT_OUT);

	while (1)
	{
		if (READ_BIT(PIND,0) == 0)
		{
			for (min_tens = 0; min_tens < 6; min_tens++)
			{
				for (min_ones = 0; min_ones < 10; min_ones++)
				{
					for (sec_tens = 0; sec_tens < 6; sec_tens++)
					{
						for (sec_ones = 0; sec_ones < 10; sec_ones++)
						{
							for (delay = 0; delay < 50; delay++)
							{

								//Enable sec_ones
								DIO_uint8SetPinValue(DIO_PORT_B, DIO_PIN_0,
										DIO_PIN_LOW);
								DIO_uint8SetPinValue(DIO_PORT_B, DIO_PIN_1,
										DIO_PIN_LOW);
								DIO_uint8SetPortValue(DIO_PORT_C,
										sevenSeg[sec_ones]);
								_delay_ms(5);

								//Enable sec_tens
								DIO_uint8SetPinValue(DIO_PORT_B, DIO_PIN_0,
										DIO_PIN_HIGH);
								DIO_uint8SetPinValue(DIO_PORT_B, DIO_PIN_1,
										DIO_PIN_LOW);
								DIO_uint8SetPortValue(DIO_PORT_C,
										sevenSeg[sec_tens]);
								_delay_ms(5);

								//Enable min_ones
								DIO_uint8SetPinValue(DIO_PORT_B, DIO_PIN_0,
										DIO_PIN_LOW);
								DIO_uint8SetPinValue(DIO_PORT_B, DIO_PIN_1,
										DIO_PIN_HIGH);
								DIO_uint8SetPortValue(DIO_PORT_C,
										sevenSeg[min_ones]);
								_delay_ms(5);

								//Enable min_tens
								DIO_uint8SetPinValue(DIO_PORT_B, DIO_PIN_0,
										DIO_PIN_HIGH);
								DIO_uint8SetPinValue(DIO_PORT_B, DIO_PIN_1,
										DIO_PIN_HIGH);
								DIO_uint8SetPortValue(DIO_PORT_C,
										sevenSeg[min_tens]);
								_delay_ms(5);

								if (READ_BIT(PIND,1) == 0)
								{
									delay = 0, sec_ones = 0, sec_tens = 0, min_ones =
											0, min_tens = 0;
									StopFunc();
								}

							}
						}
					}
				}
			}
		}
	}
}

