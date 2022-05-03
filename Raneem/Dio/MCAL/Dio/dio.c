/*
 * dio.c
 *
 *  Created on: Apr 16, 2022
 *      Author: Raneem
 */

#include "../../MCAL/DIO/dio.h"
#include "../../Service/StdMacros.h"
#include "../../Service/StdTypes.h"

StdReturn DIO_setPinDirection(DIO_port port, uint8 pin, DIO_pinType state)
{
	if (pin > MAX_PIN_NUMBER)     //åá ÇäÊ ÚÈíØØØØØØØ¿
	{
		return E_NOK;
	} else {
		switch (port) {
		//Controlling PORTA
		case DIO_PORTA:
			switch (state)
			{
			case DIO_INPUT:
				CLEAR_BIT(DDRA, pin);
				break;
			case DIO_OUTPUT:
				SET_BIT(DDRA, pin);
				break;
			default:
				return E_NOK;
			}
			break;
			//Controlling PORTB
			case DIO_PORTB:
				switch (state)
				{
				case DIO_INPUT:
					CLEAR_BIT(DDRB, pin);
					break;
				case DIO_OUTPUT:
					SET_BIT(DDRB, pin);
					break;
				default:
					return E_NOK;
				}
				break;
				//Controlling PORTC
				case DIO_PORTC:
					switch (state)
					{
					case DIO_INPUT:
						CLEAR_BIT(DDRC, pin);
						break;
					case DIO_OUTPUT:
						SET_BIT(DDRC, pin);
						break;
					default:
						return E_NOK;
					}
					break;
					//Controlling PORTD
					case DIO_PORTD:
						switch (state)
						{
						case DIO_INPUT:
							CLEAR_BIT(DDRD, pin);
							break;
						case DIO_OUTPUT:
							SET_BIT(DDRD, pin);
							break;
						default:
							return E_NOK;
						}
						break;
						//Handling port name out of range
						default:
							return E_NOK;
		}
	}

	return E_OK;
}
}

StdReturn DIO_setPORTDirection(DIO_port port, DIO_pinType state)
{
	if (pin > MAX_PIN_NUMBER)
	{
		return E_NOK;
	}
	else
	{
		switch (port)
		{
		case DIO_PORTA:
			switch (state)
			{
			case DIO_HIGH:
				SET_BIT(DIO_PORTA, pin);
				break;
			case DIO_LOW:
				CLEAR_BIT(DIO_PORTA, pin);
				break;
			default:
				return E_NOK;
			}
			break;

			case DIO_PORTB:
				switch (state)
				{
				case DIO_HIGH:
					SET_BIT(DIO_PORTB, pin);
					break;
				case DIO_LOW:
					CLEAR_BIT(DIO_PORTB, pin);
					break;
				default:
					return E_NOK;
				}
				break;

				case DIO_PORTC:
					switch (state)
					{
					case DIO_HIGH:
						SET_BIT(DIO_PORTC, pin);
						break;
					case DIO_LOW:
						CLEAR_BIT(DIO_PORTC, pin);
						break;
					default:
						return E_NOK;
					}
					break;
					case DIO_PORTD:
						switch (state)
						{
						case DIO_HIGH:
							SET_BIT(DIO_PORTD, pin);
							break;
						case DIO_LOW:
							CLEAR_BIT(DIO_PORTD, pin);
							break;
						default:
							return E_NOK;
						}
						break;

		}
	}

	return E_OK;
}



StdReturn DIO_READPinValue(DIO_port port, uint8 pin, DIO_pinState *state)
{
	if (pin > MAX_PIN_NUMBER)
	{
		return E_NOK;
	}
	else
	{
		switch (port)
		{
		case DIO_PORTA:
			*state = READ_BIT(PINA, pin);
			break;
		case DIO_PORTB:
			*state = READ_BIT(PINB, pin);
			break;
		case DIO_PORTC:
			*state = READ_BIT(PINC, pin);
			break;
		case DIO_PORTD:
			*state = READ_BIT(PIND, pin);
			break;
		}
	}

	return E_OK;
}
