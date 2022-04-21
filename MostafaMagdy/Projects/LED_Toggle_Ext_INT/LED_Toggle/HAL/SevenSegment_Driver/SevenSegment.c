/*
 * main.c
 *
 *  Created on: Mar 28, 2022
 *      Author: Seko
 */

#include "SevenSegment.h"

STD_Return SevenSegment_Display(DIO_Ports PORT,SevenSegment_Type TYPE,Display_Number NUM)
{
	switch(PORT)
	{
		case DIO_PORTA:
		switch(TYPE)
			{
				case CommonCathod:
					DIO_SetPortDirection(DIO_PORTA,PORT_OUTPUT);
					DIO_SetPinValue(DIO_PORTA,Common_PIN,DIO_LOW);
					switch(NUM)
						{
						case Zero:
							DIO_SetPortDirection(DIO_PORTA,PORT_OUTPUT);
							DIO_SetPortValue(DIO_PORTA,PORT_HIGH);
							DIO_SetPinValue(DIO_PORTA,G,DIO_LOW);
							break;
						case One:
							DIO_SetPortDirection(DIO_PORTA,PORT_OUTPUT);
							DIO_SetPortValue(DIO_PORTA,PORT_LOW);
							DIO_SetPinValue(DIO_PORTA,B,DIO_HIGH);
							DIO_SetPinValue(DIO_PORTA,C,DIO_HIGH);
							break;
						case Two:
							DIO_SetPortDirection(DIO_PORTA,PORT_OUTPUT);
							DIO_SetPortValue(DIO_PORTA,PORT_HIGH);
							DIO_SetPinValue(DIO_PORTA,C,DIO_LOW);
							DIO_SetPinValue(DIO_PORTA,F,DIO_LOW);
							break;
						case Three:
							DIO_SetPortDirection(DIO_PORTA,PORT_OUTPUT);
							DIO_SetPortValue(DIO_PORTA,PORT_HIGH);
							DIO_SetPinValue(DIO_PORTA,E,DIO_LOW);
							DIO_SetPinValue(DIO_PORTA,F,DIO_LOW);
							break;
						case Four:
							DIO_SetPortDirection(DIO_PORTA,PORT_OUTPUT);
							DIO_SetPortValue(DIO_PORTA,PORT_HIGH);
							DIO_SetPinValue(DIO_PORTA,A,DIO_LOW);
							DIO_SetPinValue(DIO_PORTA,D,DIO_LOW);
							DIO_SetPinValue(DIO_PORTA,E,DIO_LOW);
							break;
						case Five:
							DIO_SetPortDirection(DIO_PORTA,PORT_OUTPUT);
							DIO_SetPortValue(DIO_PORTA,PORT_HIGH);
							DIO_SetPinValue(DIO_PORTA,B,DIO_LOW);
							DIO_SetPinValue(DIO_PORTA,E,DIO_LOW);
							break;
						case Six:
							DIO_SetPortDirection(DIO_PORTA,PORT_OUTPUT);
							DIO_SetPortValue(DIO_PORTA,PORT_HIGH);
							DIO_SetPinValue(DIO_PORTA,B,DIO_LOW);
							break;
						case Seven:
							DIO_SetPortDirection(DIO_PORTA,PORT_OUTPUT);
							DIO_SetPortValue(DIO_PORTA,PORT_LOW);
							DIO_SetPinValue(DIO_PORTA,A,DIO_HIGH);
							DIO_SetPinValue(DIO_PORTA,B,DIO_HIGH);
							DIO_SetPinValue(DIO_PORTA,C,DIO_HIGH);
							break;
						case Eight:
							DIO_SetPortDirection(DIO_PORTA,PORT_OUTPUT);
							DIO_SetPortValue(DIO_PORTA,PORT_HIGH);
							break;
						case Nine:
							DIO_SetPortDirection(DIO_PORTA,PORT_OUTPUT);
							DIO_SetPortValue(DIO_PORTA,PORT_HIGH);
							DIO_SetPinValue(DIO_PORTA,E,DIO_LOW);
							break;
						default:
						return E_OK;
					}
					break;
			case CommonAnode:
				DIO_SetPortDirection(DIO_PORTA,PORT_OUTPUT);
				DIO_SetPinValue(DIO_PORTA,Common_PIN,DIO_HIGH);
				switch(NUM)
					{
						case Zero:
							DIO_SetPortDirection(DIO_PORTA,PORT_OUTPUT);
							DIO_SetPortValue(DIO_PORTA,PORT_LOW);
							DIO_SetPinValue(DIO_PORTA,G,DIO_HIGH);
							break;
						case One:
							DIO_SetPortDirection(DIO_PORTA,PORT_OUTPUT);
							DIO_SetPortValue(DIO_PORTA,PORT_HIGH);
							DIO_SetPinValue(DIO_PORTA,B,DIO_LOW);
							DIO_SetPinValue(DIO_PORTA,C,DIO_LOW);
							break;
						case Two:
							DIO_SetPortDirection(DIO_PORTA,PORT_OUTPUT);
							DIO_SetPortValue(DIO_PORTA,PORT_LOW);
							DIO_SetPinValue(DIO_PORTA,C,DIO_HIGH);
							DIO_SetPinValue(DIO_PORTA,F,DIO_HIGH);
							break;
						case Three:
							DIO_SetPortDirection(DIO_PORTA,PORT_OUTPUT);
							DIO_SetPortValue(DIO_PORTA,PORT_LOW);
							DIO_SetPinValue(DIO_PORTA,E,DIO_HIGH);
							DIO_SetPinValue(DIO_PORTA,F,DIO_HIGH);
							break;
						case Four:
							DIO_SetPortDirection(DIO_PORTA,PORT_OUTPUT);
							DIO_SetPortValue(DIO_PORTA,PORT_LOW);
							DIO_SetPinValue(DIO_PORTA,A,DIO_HIGH);
							DIO_SetPinValue(DIO_PORTA,D,DIO_HIGH);
							DIO_SetPinValue(DIO_PORTA,E,DIO_HIGH);
							break;
						case Five:
							DIO_SetPortDirection(DIO_PORTA,PORT_OUTPUT);
							DIO_SetPortValue(DIO_PORTA,PORT_LOW);
							DIO_SetPinValue(DIO_PORTA,B,DIO_HIGH);
							DIO_SetPinValue(DIO_PORTA,E,DIO_HIGH);
							break;
						case Six:
							DIO_SetPortDirection(DIO_PORTA,PORT_OUTPUT);
							DIO_SetPortValue(DIO_PORTA,PORT_LOW);
							DIO_SetPinValue(DIO_PORTA,B,DIO_HIGH);
							break;
						case Seven:
							DIO_SetPortDirection(DIO_PORTA,PORT_OUTPUT);
							DIO_SetPortValue(DIO_PORTA,PORT_HIGH);
							DIO_SetPinValue(DIO_PORTA,A,DIO_LOW);
							DIO_SetPinValue(DIO_PORTA,B,DIO_LOW);
							DIO_SetPinValue(DIO_PORTA,C,DIO_LOW);
							break;
						case Eight:
							DIO_SetPortDirection(DIO_PORTA,PORT_OUTPUT);
							DIO_SetPortValue(DIO_PORTA,PORT_LOW);
							break;
						case Nine:
							DIO_SetPortDirection(DIO_PORTA,PORT_OUTPUT);
							DIO_SetPortValue(DIO_PORTA,PORT_LOW);
							DIO_SetPinValue(DIO_PORTA,E,DIO_HIGH);
							break;
						default:
						return E_OK;
					}
			break;
			default:
			return E_OK;
		}
		break;
		case DIO_PORTB:
			switch(TYPE)
				{
					case CommonCathod:
						DIO_SetPortDirection(DIO_PORTB,PORT_OUTPUT);
						DIO_SetPinValue(DIO_PORTB,Common_PIN,DIO_LOW);
						switch(NUM)
							{
							case Zero:
								DIO_SetPortDirection(DIO_PORTB,PORT_OUTPUT);
								DIO_SetPortValue(DIO_PORTB,PORT_HIGH);
								DIO_SetPinValue(DIO_PORTB,G,DIO_LOW);
								break;
							case One:
								DIO_SetPortDirection(DIO_PORTB,PORT_OUTPUT);
								DIO_SetPortValue(DIO_PORTB,PORT_LOW);
								DIO_SetPinValue(DIO_PORTB,B,DIO_HIGH);
								DIO_SetPinValue(DIO_PORTB,C,DIO_HIGH);
								break;
							case Two:
								DIO_SetPortDirection(DIO_PORTB,PORT_OUTPUT);
								DIO_SetPortValue(DIO_PORTB,PORT_HIGH);
								DIO_SetPinValue(DIO_PORTB,C,DIO_LOW);
								DIO_SetPinValue(DIO_PORTB,F,DIO_LOW);
								break;
							case Three:
								DIO_SetPortDirection(DIO_PORTB,PORT_OUTPUT);
								DIO_SetPortValue(DIO_PORTB,PORT_HIGH);
								DIO_SetPinValue(DIO_PORTB,E,DIO_LOW);
								DIO_SetPinValue(DIO_PORTB,F,DIO_LOW);
								break;
							case Four:
								DIO_SetPortDirection(DIO_PORTB,PORT_OUTPUT);
								DIO_SetPortValue(DIO_PORTB,PORT_HIGH);
								DIO_SetPinValue(DIO_PORTB,A,DIO_LOW);
								DIO_SetPinValue(DIO_PORTB,D,DIO_LOW);
								DIO_SetPinValue(DIO_PORTB,E,DIO_LOW);
								break;
							case Five:
								DIO_SetPortDirection(DIO_PORTB,PORT_OUTPUT);
								DIO_SetPortValue(DIO_PORTB,PORT_HIGH);
								DIO_SetPinValue(DIO_PORTB,B,DIO_LOW);
								DIO_SetPinValue(DIO_PORTB,E,DIO_LOW);
								break;
							case Six:
								DIO_SetPortDirection(DIO_PORTB,PORT_OUTPUT);
								DIO_SetPortValue(DIO_PORTB,PORT_HIGH);
								DIO_SetPinValue(DIO_PORTB,B,DIO_LOW);
								break;
							case Seven:
								DIO_SetPortDirection(DIO_PORTB,PORT_OUTPUT);
								DIO_SetPortValue(DIO_PORTB,PORT_LOW);
								DIO_SetPinValue(DIO_PORTB,A,DIO_HIGH);
								DIO_SetPinValue(DIO_PORTB,B,DIO_HIGH);
								DIO_SetPinValue(DIO_PORTB,C,DIO_HIGH);
								break;
							case Eight:
								DIO_SetPortDirection(DIO_PORTB,PORT_OUTPUT);
								DIO_SetPortValue(DIO_PORTB,PORT_HIGH);
								break;
							case Nine:
								DIO_SetPortDirection(DIO_PORTB,PORT_OUTPUT);
								DIO_SetPortValue(DIO_PORTB,PORT_HIGH);
								DIO_SetPinValue(DIO_PORTB,E,DIO_LOW);
								break;
							default:
							return E_OK;
						}
						break;
				case CommonAnode:
					DIO_SetPortDirection(DIO_PORTB,PORT_OUTPUT);
					DIO_SetPinValue(DIO_PORTB,Common_PIN,DIO_HIGH);
					switch(NUM)
						{
							case Zero:
								DIO_SetPortDirection(DIO_PORTB,PORT_OUTPUT);
								DIO_SetPortValue(DIO_PORTB,PORT_LOW);
								DIO_SetPinValue(DIO_PORTB,G,DIO_HIGH);
								break;
							case One:
								DIO_SetPortDirection(DIO_PORTB,PORT_OUTPUT);
								DIO_SetPortValue(DIO_PORTB,PORT_HIGH);
								DIO_SetPinValue(DIO_PORTB,B,DIO_LOW);
								DIO_SetPinValue(DIO_PORTB,C,DIO_LOW);
								break;
							case Two:
								DIO_SetPortDirection(DIO_PORTB,PORT_OUTPUT);
								DIO_SetPortValue(DIO_PORTB,PORT_LOW);
								DIO_SetPinValue(DIO_PORTB,C,DIO_HIGH);
								DIO_SetPinValue(DIO_PORTB,F,DIO_HIGH);
								break;
							case Three:
								DIO_SetPortDirection(DIO_PORTB,PORT_OUTPUT);
								DIO_SetPortValue(DIO_PORTB,PORT_LOW);
								DIO_SetPinValue(DIO_PORTB,E,DIO_HIGH);
								DIO_SetPinValue(DIO_PORTB,F,DIO_HIGH);
								break;
							case Four:
								DIO_SetPortDirection(DIO_PORTB,PORT_OUTPUT);
								DIO_SetPortValue(DIO_PORTB,PORT_LOW);
								DIO_SetPinValue(DIO_PORTB,A,DIO_HIGH);
								DIO_SetPinValue(DIO_PORTB,D,DIO_HIGH);
								DIO_SetPinValue(DIO_PORTB,E,DIO_HIGH);
								break;
							case Five:
								DIO_SetPortDirection(DIO_PORTB,PORT_OUTPUT);
								DIO_SetPortValue(DIO_PORTB,PORT_LOW);
								DIO_SetPinValue(DIO_PORTB,B,DIO_HIGH);
								DIO_SetPinValue(DIO_PORTB,E,DIO_HIGH);
								break;
							case Six:
								DIO_SetPortDirection(DIO_PORTB,PORT_OUTPUT);
								DIO_SetPortValue(DIO_PORTB,PORT_LOW);
								DIO_SetPinValue(DIO_PORTB,B,DIO_HIGH);
								break;
							case Seven:
								DIO_SetPortDirection(DIO_PORTB,PORT_OUTPUT);
								DIO_SetPortValue(DIO_PORTB,PORT_HIGH);
								DIO_SetPinValue(DIO_PORTB,A,DIO_LOW);
								DIO_SetPinValue(DIO_PORTB,B,DIO_LOW);
								DIO_SetPinValue(DIO_PORTB,C,DIO_LOW);
								break;
							case Eight:
								DIO_SetPortDirection(DIO_PORTB,PORT_OUTPUT);
								DIO_SetPortValue(DIO_PORTB,PORT_LOW);
								break;
							case Nine:
								DIO_SetPortDirection(DIO_PORTB,PORT_OUTPUT);
								DIO_SetPortValue(DIO_PORTB,PORT_LOW);
								DIO_SetPinValue(DIO_PORTB,E,DIO_HIGH);
								break;
							default:
							return E_OK;
						}
				break;
				default:
				return E_OK;
			}
			break;
		case DIO_PORTC:
			switch(TYPE)
				{
					case CommonCathod:
						DIO_SetPortDirection(DIO_PORTC,PORT_OUTPUT);
						DIO_SetPinValue(DIO_PORTC,Common_PIN,DIO_LOW);
						switch(NUM)
							{
							case Zero:
								DIO_SetPortDirection(DIO_PORTC,PORT_OUTPUT);
								DIO_SetPortValue(DIO_PORTC,PORT_HIGH);
								DIO_SetPinValue(DIO_PORTC,G,DIO_LOW);
								break;
							case One:
								DIO_SetPortDirection(DIO_PORTC,PORT_OUTPUT);
								DIO_SetPortValue(DIO_PORTC,PORT_LOW);
								DIO_SetPinValue(DIO_PORTC,B,DIO_HIGH);
								DIO_SetPinValue(DIO_PORTC,C,DIO_HIGH);
								break;
							case Two:
								DIO_SetPortDirection(DIO_PORTC,PORT_OUTPUT);
								DIO_SetPortValue(DIO_PORTC,PORT_HIGH);
								DIO_SetPinValue(DIO_PORTC,C,DIO_LOW);
								DIO_SetPinValue(DIO_PORTC,F,DIO_LOW);
								break;
							case Three:
								DIO_SetPortDirection(DIO_PORTC,PORT_OUTPUT);
								DIO_SetPortValue(DIO_PORTC,PORT_HIGH);
								DIO_SetPinValue(DIO_PORTC,E,DIO_LOW);
								DIO_SetPinValue(DIO_PORTC,F,DIO_LOW);
								break;
							case Four:
								DIO_SetPortDirection(DIO_PORTC,PORT_OUTPUT);
								DIO_SetPortValue(DIO_PORTC,PORT_HIGH);
								DIO_SetPinValue(DIO_PORTC,A,DIO_LOW);
								DIO_SetPinValue(DIO_PORTC,D,DIO_LOW);
								DIO_SetPinValue(DIO_PORTC,E,DIO_LOW);
								break;
							case Five:
								DIO_SetPortDirection(DIO_PORTC,PORT_OUTPUT);
								DIO_SetPortValue(DIO_PORTC,PORT_HIGH);
								DIO_SetPinValue(DIO_PORTC,B,DIO_LOW);
								DIO_SetPinValue(DIO_PORTC,E,DIO_LOW);
								break;
							case Six:
								DIO_SetPortDirection(DIO_PORTC,PORT_OUTPUT);
								DIO_SetPortValue(DIO_PORTC,PORT_HIGH);
								DIO_SetPinValue(DIO_PORTC,B,DIO_LOW);
								break;
							case Seven:
								DIO_SetPortDirection(DIO_PORTC,PORT_OUTPUT);
								DIO_SetPortValue(DIO_PORTC,PORT_LOW);
								DIO_SetPinValue(DIO_PORTC,A,DIO_HIGH);
								DIO_SetPinValue(DIO_PORTC,B,DIO_HIGH);
								DIO_SetPinValue(DIO_PORTC,C,DIO_HIGH);
								break;
							case Eight:
								DIO_SetPortDirection(DIO_PORTC,PORT_OUTPUT);
								DIO_SetPortValue(DIO_PORTC,PORT_HIGH);
								break;
							case Nine:
								DIO_SetPortDirection(DIO_PORTC,PORT_OUTPUT);
								DIO_SetPortValue(DIO_PORTC,PORT_HIGH);
								DIO_SetPinValue(DIO_PORTC,E,DIO_LOW);
								break;
							default:
							return E_OK;
						}
						break;
				case CommonAnode:
					DIO_SetPortDirection(DIO_PORTC,PORT_OUTPUT);
					DIO_SetPinValue(DIO_PORTC,Common_PIN,DIO_HIGH);
					switch(NUM)
						{
							case Zero:
								DIO_SetPortDirection(DIO_PORTC,PORT_OUTPUT);
								DIO_SetPortValue(DIO_PORTC,PORT_LOW);
								DIO_SetPinValue(DIO_PORTC,G,DIO_HIGH);
								break;
							case One:
								DIO_SetPortDirection(DIO_PORTC,PORT_OUTPUT);
								DIO_SetPortValue(DIO_PORTC,PORT_HIGH);
								DIO_SetPinValue(DIO_PORTC,B,DIO_LOW);
								DIO_SetPinValue(DIO_PORTC,C,DIO_LOW);
								break;
							case Two:
								DIO_SetPortDirection(DIO_PORTC,PORT_OUTPUT);
								DIO_SetPortValue(DIO_PORTC,PORT_LOW);
								DIO_SetPinValue(DIO_PORTC,C,DIO_HIGH);
								DIO_SetPinValue(DIO_PORTC,F,DIO_HIGH);
								break;
							case Three:
								DIO_SetPortDirection(DIO_PORTC,PORT_OUTPUT);
								DIO_SetPortValue(DIO_PORTC,PORT_LOW);
								DIO_SetPinValue(DIO_PORTC,E,DIO_HIGH);
								DIO_SetPinValue(DIO_PORTC,F,DIO_HIGH);
								break;
							case Four:
								DIO_SetPortDirection(DIO_PORTC,PORT_OUTPUT);
								DIO_SetPortValue(DIO_PORTC,PORT_LOW);
								DIO_SetPinValue(DIO_PORTC,A,DIO_HIGH);
								DIO_SetPinValue(DIO_PORTC,D,DIO_HIGH);
								DIO_SetPinValue(DIO_PORTC,E,DIO_HIGH);
								break;
							case Five:
								DIO_SetPortDirection(DIO_PORTC,PORT_OUTPUT);
								DIO_SetPortValue(DIO_PORTC,PORT_LOW);
								DIO_SetPinValue(DIO_PORTC,B,DIO_HIGH);
								DIO_SetPinValue(DIO_PORTC,E,DIO_HIGH);
								break;
							case Six:
								DIO_SetPortDirection(DIO_PORTC,PORT_OUTPUT);
								DIO_SetPortValue(DIO_PORTC,PORT_LOW);
								DIO_SetPinValue(DIO_PORTC,B,DIO_HIGH);
								break;
							case Seven:
								DIO_SetPortDirection(DIO_PORTC,PORT_OUTPUT);
								DIO_SetPortValue(DIO_PORTC,PORT_HIGH);
								DIO_SetPinValue(DIO_PORTC,A,DIO_LOW);
								DIO_SetPinValue(DIO_PORTC,B,DIO_LOW);
								DIO_SetPinValue(DIO_PORTC,C,DIO_LOW);
								break;
							case Eight:
								DIO_SetPortDirection(DIO_PORTC,PORT_OUTPUT);
								DIO_SetPortValue(DIO_PORTC,PORT_LOW);
								break;
							case Nine:
								DIO_SetPortDirection(DIO_PORTC,PORT_OUTPUT);
								DIO_SetPortValue(DIO_PORTC,PORT_LOW);
								DIO_SetPinValue(DIO_PORTC,E,DIO_HIGH);
								break;
							default:
							return E_OK;
						}
				break;
				default:
				return E_OK;
			}
			break;
			case DIO_PORTD:
				switch(TYPE)
					{
						case CommonCathod:
							DIO_SetPortDirection(DIO_PORTD,PORT_OUTPUT);
							DIO_SetPinValue(DIO_PORTD,Common_PIN,DIO_LOW);
							switch(NUM)
								{
								case Zero:
									DIO_SetPortDirection(DIO_PORTD,PORT_OUTPUT);
									DIO_SetPortValue(DIO_PORTD,PORT_HIGH);
									DIO_SetPinValue(DIO_PORTD,G,DIO_LOW);
									break;
								case One:
									DIO_SetPortDirection(DIO_PORTD,PORT_OUTPUT);
									DIO_SetPortValue(DIO_PORTD,PORT_LOW);
									DIO_SetPinValue(DIO_PORTD,B,DIO_HIGH);
									DIO_SetPinValue(DIO_PORTD,C,DIO_HIGH);
									break;
								case Two:
									DIO_SetPortDirection(DIO_PORTD,PORT_OUTPUT);
									DIO_SetPortValue(DIO_PORTD,PORT_HIGH);
									DIO_SetPinValue(DIO_PORTD,C,DIO_LOW);
									DIO_SetPinValue(DIO_PORTD,F,DIO_LOW);
									break;
								case Three:
									DIO_SetPortDirection(DIO_PORTD,PORT_OUTPUT);
									DIO_SetPortValue(DIO_PORTD,PORT_HIGH);
									DIO_SetPinValue(DIO_PORTD,E,DIO_LOW);
									DIO_SetPinValue(DIO_PORTD,F,DIO_LOW);
									break;
								case Four:
									DIO_SetPortDirection(DIO_PORTD,PORT_OUTPUT);
									DIO_SetPortValue(DIO_PORTD,PORT_HIGH);
									DIO_SetPinValue(DIO_PORTD,A,DIO_LOW);
									DIO_SetPinValue(DIO_PORTD,D,DIO_LOW);
									DIO_SetPinValue(DIO_PORTD,E,DIO_LOW);
									break;
								case Five:
									DIO_SetPortDirection(DIO_PORTD,PORT_OUTPUT);
									DIO_SetPortValue(DIO_PORTD,PORT_HIGH);
									DIO_SetPinValue(DIO_PORTD,B,DIO_LOW);
									DIO_SetPinValue(DIO_PORTD,E,DIO_LOW);
									break;
								case Six:
									DIO_SetPortDirection(DIO_PORTD,PORT_OUTPUT);
									DIO_SetPortValue(DIO_PORTD,PORT_HIGH);
									DIO_SetPinValue(DIO_PORTD,B,DIO_LOW);
									break;
								case Seven:
									DIO_SetPortDirection(DIO_PORTD,PORT_OUTPUT);
									DIO_SetPortValue(DIO_PORTD,PORT_LOW);
									DIO_SetPinValue(DIO_PORTD,A,DIO_HIGH);
									DIO_SetPinValue(DIO_PORTD,B,DIO_HIGH);
									DIO_SetPinValue(DIO_PORTD,C,DIO_HIGH);
									break;
								case Eight:
									DIO_SetPortDirection(DIO_PORTD,PORT_OUTPUT);
									DIO_SetPortValue(DIO_PORTD,PORT_HIGH);
									break;
								case Nine:
									DIO_SetPortDirection(DIO_PORTD,PORT_OUTPUT);
									DIO_SetPortValue(DIO_PORTD,PORT_HIGH);
									DIO_SetPinValue(DIO_PORTD,E,DIO_LOW);
									break;
								default:
								return E_OK;
							}
							break;
					case CommonAnode:
						DIO_SetPortDirection(DIO_PORTD,PORT_OUTPUT);
						DIO_SetPinValue(DIO_PORTD,Common_PIN,DIO_HIGH);
						switch(NUM)
							{
								case Zero:
									DIO_SetPortDirection(DIO_PORTD,PORT_OUTPUT);
									DIO_SetPortValue(DIO_PORTD,PORT_LOW);
									DIO_SetPinValue(DIO_PORTD,G,DIO_HIGH);
									break;
								case One:
									DIO_SetPortDirection(DIO_PORTD,PORT_OUTPUT);
									DIO_SetPortValue(DIO_PORTD,PORT_HIGH);
									DIO_SetPinValue(DIO_PORTD,B,DIO_LOW);
									DIO_SetPinValue(DIO_PORTD,C,DIO_LOW);
									break;
								case Two:
									DIO_SetPortDirection(DIO_PORTD,PORT_OUTPUT);
									DIO_SetPortValue(DIO_PORTD,PORT_LOW);
									DIO_SetPinValue(DIO_PORTD,C,DIO_HIGH);
									DIO_SetPinValue(DIO_PORTD,F,DIO_HIGH);
									break;
								case Three:
									DIO_SetPortDirection(DIO_PORTD,PORT_OUTPUT);
									DIO_SetPortValue(DIO_PORTD,PORT_LOW);
									DIO_SetPinValue(DIO_PORTD,E,DIO_HIGH);
									DIO_SetPinValue(DIO_PORTD,F,DIO_HIGH);
									break;
								case Four:
									DIO_SetPortDirection(DIO_PORTD,PORT_OUTPUT);
									DIO_SetPortValue(DIO_PORTD,PORT_LOW);
									DIO_SetPinValue(DIO_PORTD,A,DIO_HIGH);
									DIO_SetPinValue(DIO_PORTD,D,DIO_HIGH);
									DIO_SetPinValue(DIO_PORTD,E,DIO_HIGH);
									break;
								case Five:
									DIO_SetPortDirection(DIO_PORTD,PORT_OUTPUT);
									DIO_SetPortValue(DIO_PORTD,PORT_LOW);
									DIO_SetPinValue(DIO_PORTD,B,DIO_HIGH);
									DIO_SetPinValue(DIO_PORTD,E,DIO_HIGH);
									break;
								case Six:
									DIO_SetPortDirection(DIO_PORTD,PORT_OUTPUT);
									DIO_SetPortValue(DIO_PORTD,PORT_LOW);
									DIO_SetPinValue(DIO_PORTD,B,DIO_HIGH);
									break;
								case Seven:
									DIO_SetPortDirection(DIO_PORTD,PORT_OUTPUT);
									DIO_SetPortValue(DIO_PORTD,PORT_HIGH);
									DIO_SetPinValue(DIO_PORTD,A,DIO_LOW);
									DIO_SetPinValue(DIO_PORTD,B,DIO_LOW);
									DIO_SetPinValue(DIO_PORTD,C,DIO_LOW);
									break;
								case Eight:
									DIO_SetPortDirection(DIO_PORTD,PORT_OUTPUT);
									DIO_SetPortValue(DIO_PORTD,PORT_LOW);
									break;
								case Nine:
									DIO_SetPortDirection(DIO_PORTD,PORT_OUTPUT);
									DIO_SetPortValue(DIO_PORTD,PORT_LOW);
									DIO_SetPinValue(DIO_PORTD,E,DIO_HIGH);
									break;
								default:
								return E_OK;
							}
					break;
					default:
					return E_OK;
				}
				break;
	default:
	return E_OK;
}
	return E_NOK;
}



