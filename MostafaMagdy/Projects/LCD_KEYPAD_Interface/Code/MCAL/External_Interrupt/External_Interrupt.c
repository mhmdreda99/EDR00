/*
 * main.c
 *
 *  Created on: Mar 27, 2022
 *      Author: Seko
 */
#include "External_Interrupt.h"

static void (*External_Function0)(void);
static void (*External_Function1)(void);
static void (*External_Function2)(void);

//Interrupt Service Routine for external interrupt 1
ISR(INT0_Vect)
{
	(*External_Function0)();
}

//Interrupt Service Routine for external interrupt 2
ISR(INT1_Vect)
{
	(*External_Function1)();
}

//Interrupt Service Routine for external interrupt 3
ISR(INT2_Vect)
{
	(*External_Function2)();
}

STD_Return Enable_Global_Interrupt(Interrupt_State state)
{
	switch(state)
		{
			case Enable_Interrupt:
				SET_BIT(SREG,GIE);
				break;
			case Disable_Interrupt:
				CLEAR_BIT(SREG,GIE);
				break;
			default:
				return E_OK;
		}
	return E_NOK;
}

//Interrupt_No1
STD_Return External_Int0(Int_Sense_Control SenseLevel)
{
	SET_BIT(GICR,INT0);

	switch(SenseLevel)
		{
			case Rising_Edge_Sense:
					SET_BIT(MCUCR,ISC00);
					SET_BIT(MCUCR,ISC01);
					break;
			case Falling_Edge_Sense:
					CLEAR_BIT(MCUCR,ISC00);
					SET_BIT(MCUCR,ISC01);
					break;
			default:
				return E_OK;
		}
	return E_NOK;
}
STD_Return CallBack_Int0(void (*Func_Ptr)(void))
{
	External_Function0=Func_Ptr;
	return E_NOK;
}

//Interrupt_No2
STD_Return External_Int1(Int_Sense_Control SenseLevel)
{
	SET_BIT(GICR,INT1);

	switch(SenseLevel)
		{
			case Rising_Edge_Sense:
					SET_BIT(MCUCR,ISC10);
					SET_BIT(MCUCR,ISC11);
					return E_NOK;
					break;
			case Falling_Edge_Sense:
					CLEAR_BIT(MCUCR,ISC10);
					SET_BIT(MCUCR,ISC11);
					return E_NOK;
					break;
			default:
				return E_OK;
		}
	return E_NOK;
}

STD_Return CallBack_Int1(void (*Func_Ptr)(void))
{
	External_Function1=Func_Ptr;
	return E_NOK;
}

//Interrupt_No3
STD_Return External_Int2(Int_Sense_Control SenseLevel)
{
	SET_BIT(GICR,INT2);

	switch(SenseLevel)
		{
			case Rising_Edge_Sense:
					SET_BIT(MCUCSR,ISC2);
					return E_NOK;
					break;
			case Falling_Edge_Sense:
					CLEAR_BIT(MCUCSR,ISC2);
					return E_NOK;
					break;
			default:
				return E_OK;
		}
	return E_NOK;

}
STD_Return CallBack_Int2(void (*Func_Ptr)(void))
{
	External_Function2=Func_Ptr;
	return E_NOK;
}
