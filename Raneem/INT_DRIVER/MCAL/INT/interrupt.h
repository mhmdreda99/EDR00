/*
 * interrupt.h
 *
 *  Created on: Apr 18, 2022
 *      Author: Raneem
 */

#ifndef MCAL_INT_INTERRUPT_H_
#define MCAL_INT_INTERRUPT_H_

#include "../../Controller/ATMEGA32/Interrupts.h"
#include "../../Service/StdMacros.h"
#include "../../Service/StdTypes.h"
#include "../../Controller/ATMEGA32/Registers.h"


//Data type for selecting the sense edge
typedef enum{
	INT_RISING_EDGE,
	INT_FALLING_EDGE
}Int_senseControl;


//Initialize external interrupt 0
StdReturn Int0_init(Int_senseControl senseLevel);
//Set the user function to be executed on ISR
StdReturn Int0_callback(void (*func_ptr)(void));

//Initialize external interrupt 1
StdReturn Int1_init(Int_senseControl senseLevel);
//Set the user function to be executed on ISR
StdReturn Int1_callback(void (*func_ptr)(void));

//Initialize external interrupt 2
StdReturn Int2_init(Int_senseControl senseLevel);
//Set the user function to be executed on ISR
StdReturn Int2_callback(void (*func_ptr)(void));


#endif /* MCAL_INT_INTERRUPT_H_ */
