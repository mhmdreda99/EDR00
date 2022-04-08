/*
 * file.h
 *
 *  Created on: Mar 27, 2022
 *      Author: Seko
 */

#ifndef EXTERNAL_INTERRUPT_H_
#define EXTERNAL_INTERRUPT_H_

#include "../../SERVICE/Interrupt_Vector.h"
#include "../../SERVICE/DIO_register.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_Types.h"

typedef enum
{
	Enable_Interrupt,
	Disable_Interrupt
}Interrupt_State;
typedef enum
{
	Falling_Edge_Sense,
	Rising_Edge_Sense
}Int_Sense_Control;

//external_interrupt_Enable/Disable
STD_Return External_Interrupt(Interrupt_State state);

//Interrupt_No1
STD_Return External_Int0(Int_Sense_Control SenseLevel);
void CallBack_Int0(void (*Func_Ptr)(void));

//Interrupt_No2
STD_Return External_Int1(Int_Sense_Control SenseLevel);
void CallBack_Int1(void (*Func_Ptr)(void));

//Interrupt_No3
STD_Return External_Int2(Int_Sense_Control SenseLevel);
void CallBack_Int2(void (*Func_Ptr)(void));
#endif /* EXTERNAL_INTERRUPT_H_ */
