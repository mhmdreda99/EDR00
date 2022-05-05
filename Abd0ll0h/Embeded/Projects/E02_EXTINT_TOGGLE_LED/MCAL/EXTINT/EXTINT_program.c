/*
 ============================================================================
 Name        : EXTI_program.c
 Author      : Abdullah Ayman
 Layer		 : MCAL
 Target		 : ATMEGA32
 Version     : 1.0
 Date		 : 27/04/2022
 Copyright   :
 Description : Header file for DIO Driver
 ============================================================================
 */
/************************************************************/
/*******************	Include section    ******************/
/************************************************************/

#include "EXTINT_interface.h"
//DISABLE_INT0()


/************************************************************/
/************	Function Implementation section	*************/
/************************************************************/
static void (*user_func0)(void);
static void (*user_func1)(void);
static void (*user_func2)(void);


ISR(INT0_vect)
{
	(*user_func0)();
}

ISR(INT1_vect)
{
	(*user_func1)();
}

ISR(INT2_vect)
{
	(*user_func2)();
}


STD_return_t EXTINT_uint8ExternalInt0(EXTINT_SENSE_CONTROL_t senseCtrl)
{
	ENABLE_INT0();

	switch (senseCtrl)
	{
	case EXTINT_FALLING_EDGE:
		CLEAR_BIT(MCUCR,ISC00);
		SET_BIT(MCUCR,ISC01);
		break;
	case EXTINT_RISING_EDGE:
		SET_BIT(MCUCR,ISC00);
		SET_BIT(MCUCR,ISC01);
		break;
		default:
		return P_NOK;
	}
	return P_OK;
}
extern void EXTINT_callbackInt0(void(*ptrfunc)())
{
	user_func0=ptrfunc;
}

STD_return_t EXTINT_uint8ExternalInt1(EXTINT_SENSE_CONTROL_t senseCtrl)
{
	ENABLE_INT1();

	switch (senseCtrl)
	{
	case EXTINT_FALLING_EDGE:
		CLEAR_BIT(MCUCR,ISC10);
		SET_BIT(MCUCR,ISC11);
		break;
	case EXTINT_RISING_EDGE:
		SET_BIT(MCUCR,ISC10);
		SET_BIT(MCUCR,ISC11);
		break;
		default:
		return P_NOK;
	}
	return P_OK;
}
extern void EXTINT_callbackInt1(void(*ptrfunc)())
{
	user_func1=ptrfunc;
}

STD_return_t EXTINT_uint8ExternalInt2(EXTINT_SENSE_CONTROL_t senseCtrl)
{
	ENABLE_INT2();

	switch (senseCtrl)
	{
	case EXTINT_FALLING_EDGE:
		CLEAR_BIT(MCUCR,ISC2);
		break;
	case EXTINT_RISING_EDGE:
		SET_BIT(MCUCR,ISC2);
		break;
		default:
		return P_NOK;
	}
	return P_OK;
}
extern void EXTINT_callbackInt2(void(*ptrfunc)())
{
	user_func2=ptrfunc;
}

