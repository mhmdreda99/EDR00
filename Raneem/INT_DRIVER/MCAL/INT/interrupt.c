/*
 * interrupt.c
 *
 *  Created on: Apr 18, 2022
 *      Author: Raneem
 */



#include "interrupt.h"

void INT_init(void)
{
	//Enable external interrupt 0 mask
	SET_BIT(GICR, INT1);
}
StdReturn Int0_init(Int_senseControl senseLevel) {
	StdReturn return_Loc = E_OK;

	//Enable external interrupt 0 mask
	SET_BIT(GICR, INT0);

	//Configure sense control
	switch (senseLevel) {
	case INT_RISING_EDGE:		//Rising edge causes interrupt
		SET_BIT(MCUCR, ISC01);
		SET_BIT(MCUCR, ISC00);
		break;
	case INT_FALLING_EDGE:		//Falling edge causes interrupt
		SET_BIT(MCUCR, ISC01);
		CLEAR_BIT(MCUCR, ISC00);
		break;
	default:						//Wrong configuration is sent
		return_Loc = E_NOK;
		break;
	}
	//Return API status
	return return_Loc;
}

//Set the user function to be executed on ISR
StdReturn Int0_callback(void (*func_ptr)(void)) {
	user_func0 = func_ptr;
	return E_OK;
}
//Initialize external interrupt 1
StdReturn Int1_init(Int_senseControl senseLevel) {
	StdReturn return_Loc = E_OK;

	//Enable external interrupt 1 mask
	SET_BIT(GICR, INT1);

	//Configure sense control
	switch (senseLevel) {
	case INT_RISING_EDGE:
		SET_BIT(MCUCR, ISC11);
		SET_BIT(MCUCR, ISC10);
		break;
	case INT_FALLING_EDGE:
		SET_BIT(MCUCR, ISC11);
		CLEAR_BIT(MCUCR, ISC10);
		break;
	default:
		return_Loc = E_NOK;
		break;
	}
	return return_Loc;
}

//Set the user function to be executed on ISR
StdReturn Int1_callback(void (*func_ptr)(void)) {
	user_func1 = func_ptr;
	return E_OK;
}

//Initialize external interrupt 2
StdReturn Int2_init(Int_senseControl senseLevel) {
	StdReturn return_Loc = E_OK;

	//Enable external interrupt 2 mask
	SET_BIT(GICR, INT2);

	//Configure sense control
	switch (senseLevel) {
	case INT_RISING_EDGE:
		SET_BIT(MCUCSR, ISC2);
		break;
	case INT_FALLING_EDGE:
		CLEAR_BIT(MCUCSR, ISC2);
		break;
	default:
		return_Loc = E_NOK;
		break;
	}
	return return_Loc;
}

//Set the user function to be executed on ISR
StdReturn Int2_callback(void (*func_ptr)(void)) {
	user_func2 = func_ptr;
	return E_OK;
}

