/*
 * DIO.C
 *
 * 		Created on: Mar 31, 2022 , 2:30 Am
 *
 *      Author: Hadeer_Esmat
 *
 *      VERSION : 1
 */
#include "DIO.h"
#include "../Controller/ATMEGA32/Registers.h"
#include "../Controller/ATMEGA32/Interrupts.h"
#include "../Service/StdMacros.h"
#include "../Service/StdTypes.h"


void GPIO_init()
{
	DDRA = 0;
	DDRB = 0;
	DDRC = 0;
	DDRD = 0;

	PORTA = 0;
	PORTB = 0;
	PORTC = 0;
	PORTD = 0;

	//Enable Global Pull-up resistor's control
	CLEAR_BIT(SFIOR, PUD);
}


/* DIO_SET_DIRECTION ,Is a function used to set the direction of 'DIO'
 ******* TO set the direction : 1) firstly set the port[A ,B ,C, D ]
 ******* 						2) Set The pin number
 ******* 						3)Set the DIO _Direction
 ******* 							****(If the input Is(0) the direction is 'INPUT'
 ******* 							****(If the input Is(1) the direction is 'OUTNPUT'
 *******
 *******
 */
StdReturn DIO_SET_DIRECTION (DIO_PORT_t Port , uint8 pin , DIO_pin_DIRECTION_t  direction)
{
		if (pin >7)
		{
		return ERROR ;
		}
		// To ensure that the input of pin number between (0,7)
		else
		{
		switch (Port)
		{
//********************************************************************FOR PORT A

		case (DIO_PORT_A):
		switch(direction)
		{
			case (DIO_pin_OUTPUT):
				SET_BIT(DDRA,pin);
			break ;
			case (	DIO_pin_INPUT):
				CLEAR_BIT(DDRA,pin);
			break;
		}
		break ;
		default :
		return ERROR ;
		break ;

//********************************************************************FOR PORT B
		case (DIO_PORT_B):
		switch(direction)
		{
		case (DIO_pin_OUTPUT):
		SET_BIT(DDRB,pin);
		break ;

		case (	DIO_pin_INPUT):
		CLEAR_BIT(DDRB,pin);
		break;
		}
		break ;
		default :
		return ERROR ;
		break ;
//********************************************************************FOR PORT C
		case (DIO_PORT_C):
		switch(direction)
		{
		case (DIO_pin_OUTPUT):
		SET_BIT(DDRC,pin);
		break ;

		case (	DIO_pin_INPUT):
		CLEAR_BIT(DDRC,pin);
		break;
		}
		break ;
		default :
		return ERROR ;
		break ;

//********************************************************************FOR PORT D

		case (DIO_PORT_D):
		switch(direction)
			{
		case (DIO_pin_OUTPUT):
		SET_BIT(DDRD,pin);
		break ;

		case (	DIO_pin_INPUT):
		CLEAR_BIT(DDRD,pin);
		break;
			}
		break ;
		default :
		return ERROR ;
		break ;



}   // SWITCH
}	// else
}	// Function

//**********************************************************************************
//**********************************************************************************

StdReturn DIO_OUTPUT (DIO_PORT_t Port , uint8 pin ,DIO_pin_CASE_t state)
{
				if (pin >7)
				{
				return ERROR ;
				}
				// To ensure that the input of pin number between (0,7)
				else
				{
				switch (Port)
				{
	//********************************************************************FOR PORT A
				case (DIO_PORT_A):
				switch (state)
				{
				case (DIO_pin_LOW):
				CLEAR_BIT(PORTA,pin);
				break ;

				case (DIO_pin_HIGH):
				SET_BIT(PORTA,pin);
				break ;
				}
				break ;
				default :
				return ERROR ;
				break ;

//********************************************************************FOR PORT B
				case (DIO_PORT_B):
				switch (state)
				{
				case (DIO_pin_LOW):
				CLEAR_BIT(PORTB,pin);
				break ;

				case (DIO_pin_HIGH):
				SET_BIT(PORTB,pin);
				break ;
					}
				break ;
				default :
				return ERROR ;
				break ;
//********************************************************************FOR PORT C
				case (DIO_PORT_C):
				switch (state)
							{
				case (DIO_pin_LOW):
				CLEAR_BIT(PORTC,pin);
				break ;

				case (DIO_pin_HIGH):
				SET_BIT(PORTC,pin);
				break ;
							}
				break ;
				default :
				return ERROR ;
				break ;

//********************************************************************FOR PORT D
				case (DIO_PORT_D):
				switch (state)
					{
				case (DIO_pin_LOW):
				CLEAR_BIT(PORTD,pin);
				break ;

				case (DIO_pin_HIGH):
				SET_BIT(PORTD,pin);
				break ;
					}
				break ;
				default :
				return ERROR ;
				break ;
	}
	}
	}
//*************************************************************************************
//*************************************************************************************
StdReturn DIO_INPUT (DIO_PORT_t Port , uint8 pin ,DIO_pin_CASE_t *state)
{
	if (pin >7)
	{
	return ERROR ;
	}
	// To ensure that the input of pin number between (0,7)
	else
	{
	switch(Port)
	{
	//********************************************************** For Port A
	case (DIO_PORT_A):
		*state = READ_BIT(PINA,pin);
	break ;
	//********************************************************** For Port A
	case (DIO_PORT_B):
		*state = READ_BIT(PINB,pin);
	break ;
	//********************************************************** For Port C
	case (DIO_PORT_C):
		*state = READ_BIT(PINC,pin);
	break ;
	//********************************************************** For Port A
	case (DIO_PORT_D):
			*state = READ_BIT(PIND,pin);
	break ;
	default :
			return ERROR ;
			break ;
}	//else
}	// switch
} 	// Write Function

 //********************************************************************
//*********************************************************************


StdReturn DIO_PUD (DIO_PORT_t Port , uint8 pin ,DIO_PUD_ENABLE_t state)
{
	if (pin >7)
	{
	return ERROR ;
	}
	// To ensure that the input of pin number between (0,7)
	else
	{
	switch(Port)
		{
		//********************************************************** For Port A
		case (DIO_PORT_A):
		switch(state)
		{
		case (DIO_PUD_DISABLE):
		SET_BIT(PORTA,pin);
		break ;
		case (DIO_PUD_ENABLE):
		CLEAR_BIT(PORTA,pin);//
		}
		break ;
		//********************************************************** For Port B
		case (DIO_PORT_B):
		switch(state)
		{
		case (DIO_PUD_DISABLE):
		SET_BIT(PORTB,pin);
		break ;
		case (DIO_PUD_ENABLE):
		CLEAR_BIT(PORTB,pin);//
		}
		break ;
		//********************************************************** For Port C
		case (DIO_PORT_C):
		switch(state)
		{
		case (DIO_PUD_DISABLE):
		SET_BIT(PORTC,pin);
		break ;
		case (DIO_PUD_ENABLE):
		CLEAR_BIT(PORTC,pin);//
		}
		break ;
		//********************************************************** For Port D
		case (DIO_PORT_D):
		switch(state)
		{
		case (DIO_PUD_DISABLE):
		SET_BIT(PORTD,pin);
		break ;
		case (DIO_PUD_ENABLE):
		CLEAR_BIT(PORTD,pin);//
		}
		break ;
}
}
}
//******************************************************************
//*****************************************************************
StdReturn GPIO_togglePin(DIO_PORT_t  Port, uint8 pin)
{
	if (pin >7)
	{
	return ERROR ;
	}
	// To ensure that the input of pin number between (0,7)
	else
	{
	switch (Port)
	{
		case (DIO_PORT_A):
		TOGGLE_BIT(PORTA,pin);
		break ;
		case (DIO_PORT_B):
		TOGGLE_BIT(PORTB,pin);
		break ;
		case (DIO_PORT_C):
		TOGGLE_BIT(PORTC,pin);
		break ;
		case (DIO_PORT_D):
		TOGGLE_BIT(PORTD,pin);
		break ;
		default:
		return ERROR;
}
}
}

