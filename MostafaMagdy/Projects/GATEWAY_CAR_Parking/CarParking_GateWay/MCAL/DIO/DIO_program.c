/**
 * @file 		  DIO_program.c
 * @author        MostafaMagdy
 * @email         MostafaMagii7@gmail.com
 * @Git account:  https:github.com/MostafaMagdy99
 * @version       0.1
 * @date          2022-04-26
 * 
 * @copyright Copyright (c) 2022
 * 
 * Description :  Source file for the DIO driver
 */

/***************************************Includes******************************************************/
#include "DIO_interface.h"
/*****************************************************************************************************/
/**
 * @brief 
 * Prototype    	 	: 		void DIO_init(void);
 * Description  	 	:		Initialize DIO Periphiral 
 * 
 * @param   	void 	:  		has no input paramater
 * @return  	void 	:		Return nothing
 **/
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
/*****************************************************************************************************/
/**
 * @brief 
 * Prototype    	 	: STD_Return DIO_SetPinDirection(DIO_Ports_t PORT, u8 PIN, DIO_Direction_t Direction);
 * Description  	 	: function for Set pin direction Input or Output
 * 
 * @param PORT 			: takes the four PORTS DIO_PORTA,DIO_PORTB,DIO_PORTC,DIO_PORTD
 * @param PIN 			: takes the number of pin in the PORT
 * @param Direction 	: takes the directon of the single PIN is DIO_INPUT or DIO_OUTPUT
 * @return STD_Return	 :		STD_Return for Error identification
 * 
 * 								return 0 mean Error is found , return 1 mean Error is not found
 **/
STD_Return DIO_SetPinDirection(DIO_Ports_t PORT, u8 PIN, DIO_Direction_t Direction)
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
/*****************************************************************************************************/
/**
 * @brief 
 * Prototype    	 	: STD_Return DIO_SetPortDirection(DIO_Ports_t PORT,DIO_Direction_t Direction);
 * Description  	 	: function for Set PORT direction Input or Output
 * 
 * @param PORT 		    : takes the four PORTS DIO_PORTA,DIO_PORTB,DIO_PORTC,DIO_PORTD		
 * @param Direction     : takes the direction of all pins in the port PORT_INPUT/PORT_OUTPUT
 * @return STD_Return	 :		STD_Return for Error identification
 * 
 * 								return 0 mean Error is found , return 1 mean Error is not found
 **/
STD_Return DIO_SetPortDirection(DIO_Ports_t PORT,DIO_Direction_t Direction)
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
/*****************************************************************************************************/
/**
 * @brief 
 * Prototype    	 	: STD_Return DIO_SetPinValue(DIO_Ports_t PORT,u8 PIN,DIO_State_t State);		  
 * Description  	 	: function for Set specific Pin in a port value High or Low
 * 
 * @param PORT 			: takes the four PORTS DIO_PORTA,DIO_PORTB,DIO_PORTC,DIO_PORTD
 * @param PIN 			: takes the number of pin in the PORT
 * @param State 		: takes the Value of the single PIN is DIO_HIGH or DIO_LOW
 * @return STD_Return	: STD_Return for Error identification
 * 
 * 							return 0 mean Error is found , return 1 mean Error is not found
 **/
STD_Return DIO_SetPinValue(DIO_Ports_t PORT,u8 PIN,DIO_State_t State)
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
/*****************************************************************************************************/
/**
 * @brief 
 * Prototype    	 	: STD_Return DIO_SetPortValue(DIO_Ports_t PORT,u8 value);
 * Description  	 	: function for Set PORT Value High or Low
 * 
 * @param PORT 			: takes the four PORTS DIO_PORTA,DIO_PORTB,DIO_PORTC,DIO_PORTD
 * @param value  		: takes the value  of all pins in the port PORT_HIGH/PORT_LOW
 * @return STD_Return	: STD_Return for Error identification
 * 
 * 						  return 0 mean Error is found , return 1 mean Error is not found
 **/
STD_Return DIO_SetPortValue(DIO_Ports_t PORT,u8 value)
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
/*****************************************************************************************************/
/**
 * @brief 
 * Prototype    	 	: STD_Return DIO_GetPinValue(DIO_Ports_t PORT,u8 PIN,DIO_State_t* State);  
 * Description  	 	: function for storing the value of pin 
 * 
 * @param PORT 			: takes the four PORTS DIO_PORTA,DIO_PORTB,DIO_PORTC,DIO_PORTD
 * @param PIN 		    : takes the number of pin in the PORT
 * @param State 		: pointer of the state that takes the Value of the single PIN is DIO_HIGH or DIO_LOW
 * @return STD_Return	: STD_Return for Error identification
 * 
 * 						  return 0 mean Error is found , return 1 mean Error is not found
 **/
STD_Return DIO_GetPinValue(DIO_Ports_t PORT,u8 PIN,DIO_State_t* State)
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
/*****************************************************************************************************/
/**
 * @brief 
 * Prototype    	 	: STD_Return DIO_togglePin(DIO_Ports_t port,u8 pin); 
 * Description  	 	: function for toggle the current value of pin 
 *  
 * @param port 			: takes the four PORTS DIO_PORTA,DIO_PORTB,DIO_PORTC,DIO_PORTD
 * @param pin 			: takes the number of pin in the PORT
 * @return STD_Return	: STD_Return for Error identification
 * 
 * 						  return 0 mean Error is found , return 1 mean Error is not found
 **/
STD_Return DIO_togglePin(DIO_Ports_t port,u8 pin)
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
/*****************************************************************************************************/
/**
 * @brief 
 * Prototype    	 	: STD_Return DIO_EnablePullup(DIO_Ports_t port, u8 pin, DIO_PullUpState_t Pullstate); 
 * Description  	 	: function for activting the pull up resistor 
 * 
 * @param port 			: takes the four PORTS DIO_PORTA,DIO_PORTB,DIO_PORTC,DIO_PORTD
 * @param pin 			: takes the number of pin in the PORT
 * @param Pullstate     : take the pull up state ENABLE_PullUp/DISABLE_PullUp
 * @return STD_Return	: STD_Return for Error identification
 * 
 * 						  return 0 mean Error is found , return 1 mean Error is not found
 **/
STD_Return DIO_EnablePullup(DIO_Ports_t PORT, u8 PIN, DIO_PullUpState_t Pullstate)
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
									CLEAR_BIT(DDRA,PIN);
									SET_BIT(PORTA,PIN);
									break;
								case DISABLE_PullUp:
									SET_BIT(SFIOR,PUD);
									break;
								default:
									return E_OK;
							}
						break;
						case DIO_PORTB:
							switch(Pullstate)
								{
									case ENABLE_PullUp:
										CLEAR_BIT(DDRB,PIN);
										SET_BIT(PORTB,PIN);
										break;
									case DISABLE_PullUp:
										SET_BIT(SFIOR,PUD);
										break;
									default:
										return E_OK;
								}
							break;
							case DIO_PORTC:
								switch(Pullstate)
									{
										case ENABLE_PullUp:
											CLEAR_BIT(DDRC,PIN);
											SET_BIT(PORTC,PIN);
											break;
										case DISABLE_PullUp:
											SET_BIT(SFIOR,PUD);
											break;
										default:
											return E_OK;
									}
								break;
								case DIO_PORTD:
									switch(Pullstate)
										{
											case ENABLE_PullUp:
												CLEAR_BIT(DDRD,PIN);
												SET_BIT(PORTD,PIN);
												break;
											case DISABLE_PullUp:
												SET_BIT(SFIOR,PUD);
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
/*****************************************************************************************************/

