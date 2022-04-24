/*
 ============================================================================
 Name        : DIO_interface.h
 Author      : Mostafa Magdy
 Layer		 : MCAL
 Target		 : ATMEGA 32
 Version     : 1.0
 Date		 : 4/3/2021
 Copyright   : This is an open source code for all embedded systems students
 Description : Header file for the DIO driver
 ============================================================================
 */

//service files first

//driver files
#include "DIO_interface.h"


void DIO_init(void)
{
    // initializing all pins are input
    DDRA=0;
    DDRB=0;
    DDRC=0;
    DDRD=0;

    PORTA=0;
    PORTB=0;
    PORTC=0;
    PORTD=0;
    //enable the internal pull up resistor
    CLEAR_BIT(SFIOR,PUD);
}

STD_Return DIO_SetPinDirection(DIO_Ports PORT, u8 PIN, DIO_Direction Direction)
	{
		// check for safety
		if(PIN>MAX_PinNum)
			{
				return E_OK;
			}
		else
			{
				switch(PORT)
					{
						case DIO_PORTA:
							switch (Direction)
								{
									case DIO_INPUT:
									CLEAR_BIT(DDRA,PIN);
									break;
									case DIO_OUTPUT:
									SET_BIT(DDRA,PIN);
									break;
									default:
									return E_OK;
								}
						break;
						case DIO_PORTB:
							switch (Direction)
								{
									case DIO_INPUT:
										CLEAR_BIT(DDRB,PIN);
										break;
									case DIO_OUTPUT:
										SET_BIT(DDRB,PIN);
										break;
									default:
									return E_OK;
								}
						break;
						case DIO_PORTC:
							switch (Direction)
								{
									case DIO_INPUT:
										CLEAR_BIT(DDRC,PIN);
										break;
									case DIO_OUTPUT:
										SET_BIT(DDRC,PIN);
										break;
									default:
										return E_OK;
								}
						break;
						case DIO_PORTD:
							switch (Direction)
								{
									case DIO_INPUT:
										CLEAR_BIT(DDRD,PIN);
										break;
									case DIO_OUTPUT:
										SET_BIT(DDRD,PIN);
										break;
									default:
										return E_OK;
								}
							break;
							default:
								return E_OK;
					}
			}
	return E_NOK;
	}

STD_Return DIO_SetPortDirection(DIO_Ports PORT,u8 Direction)
{
					switch(PORT)
						{
							case DIO_PORTA:
								DDRA=Direction;
							break;
							case DIO_PORTB:
								DDRB=Direction;
							break;
							case DIO_PORTC:
								DDRC=Direction;
							break;
							case DIO_PORTD:
								DDRD=Direction;
							break;
							default:
							return E_OK;

						}
	return E_NOK;
}

STD_Return DIO_SetPinValue(DIO_Ports PORT,u8 PIN,DIO_State State)
	{
		if(PIN>MAX_PinNum)
			{
				return E_OK;
			}
		else
			{
				switch(PORT)
					{
						case DIO_PORTA:
							switch(State)
								{
									case DIO_LOW:
										CLEAR_BIT(PORTA,PIN);
										break;
									case DIO_HIGH:
										SET_BIT(PORTA,PIN);
										break;
									default:
										return E_OK;
								}
						break;
						case DIO_PORTB:
							switch(State)
								{
									case DIO_LOW:
										CLEAR_BIT(PORTB,PIN);
										break;
									case DIO_HIGH:
										SET_BIT(PORTB,PIN);
										break;
									default:
										return E_OK;
								}
						break;
						case DIO_PORTC:
							switch(State)
								{
									case DIO_LOW:
										CLEAR_BIT(PORTC,PIN);
										break;
									case DIO_HIGH:
										SET_BIT(PORTC,PIN);
										break;
									default:
										return E_OK;
								}
						break;
						case DIO_PORTD:
							switch(State)
								{
									case DIO_LOW:
										CLEAR_BIT(PORTD,PIN);
										break;
									case DIO_HIGH:
										SET_BIT(PORTD,PIN);
										break;
									default:
										return E_OK;
								}
						break;
							default:
							return E_OK;
					}
			}
		return E_NOK;
	}

STD_Return DIO_SetPortValue(DIO_Ports PORT,u8 value)
{
					switch(PORT)
						{
							case DIO_PORTA:
								PORTA=value;
							break;
							case DIO_PORTB:
								PORTB=value;
							break;
							case DIO_PORTC:
								PORTC=value;
							break;
							case DIO_PORTD:
								PORTD=value;

							break;
							default:
							return E_OK;

						}
	return E_NOK;
}

STD_Return DIO_GetPinValue(DIO_Ports PORT,u8 PIN,DIO_State* State)
	{
		if(PIN>MAX_PinNum)
			{
				return E_OK;
			}
		else
			{
					switch(PORT)
						{
							case DIO_PORTA:
								*State=GET_BIT(PINA,PIN);
								break;
							case DIO_PORTB:
								*State=GET_BIT(PINB,PIN);
								break;
							case DIO_PORTC:
								*State=GET_BIT(PINC,PIN);
								break;
							case DIO_PORTD:
								*State=GET_BIT(PIND,PIN);
								break;
							default:
								return E_OK;
						}
			}
		return E_NOK;
	}

STD_Return DIO_togglePin(DIO_Ports port,u8 pin)
 {
	if (pin > MAX_PinNum)
		{
			return E_OK;
		}
	else
		{
			switch (port)
				{
					case DIO_PORTA:
						TOGGLE_BIT(PORTA, pin);
						break;
					case DIO_PORTB:
						TOGGLE_BIT(PORTB, pin);
						break;
					case DIO_PORTC:
						TOGGLE_BIT(PORTC, pin);
						break;
					case DIO_PORTD:
						TOGGLE_BIT(PORTD, pin);
						break;
					default:
						return E_OK;
				}
	}

	return E_NOK;
}

STD_Return DIO_EnablePullup(DIO_Ports PORT, u8 PIN, DIO_PullUpState Pullstate)
	{
		if(PIN>MAX_PinNum)
			{
				return E_OK;
			}
		else
			{
				switch(PORT)
				{
					case DIO_PORTA:
						switch(Pullstate)
							{
								case ENABLE_PullUp:
									CLEAR_BIT(PORTA,PIN);
									break;
								case DISABLE_PullUp:
									SET_BIT(PORTA,PIN);
									break;
								default:
									return E_OK;
							}
						break;
						case DIO_PORTB:
							switch(Pullstate)
								{
									case ENABLE_PullUp:
										CLEAR_BIT(PORTB,PIN);
										break;
									case DISABLE_PullUp:
										SET_BIT(PORTB,PIN);
										break;
									default:
										return E_OK;
								}
							break;
							case DIO_PORTC:
								switch(Pullstate)
									{
										case ENABLE_PullUp:
											CLEAR_BIT(PORTC,PIN);
											break;
										case DISABLE_PullUp:
											SET_BIT(PORTC,PIN);
											break;
										default:
											return E_OK;
									}
								break;
								case DIO_PORTD:
									switch(Pullstate)
										{
											case ENABLE_PullUp:
												CLEAR_BIT(PORTD,PIN);
												break;
											case DISABLE_PullUp:
												SET_BIT(PORTD,PIN);
												break;
											default:
												return E_OK;
										}
									break;
									default:
									return E_OK;

				}
			}
		return E_NOK;
	}


