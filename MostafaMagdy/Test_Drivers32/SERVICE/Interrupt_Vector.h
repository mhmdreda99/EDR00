/*
 * Interrupt_Vector.h
 *
 *  Created on: Mar 27, 2022
 *      Author: Seko
 */

#ifndef SERVICE_INTERRUPT_VECTOR_H_
#define SERVICE_INTERRUPT_VECTOR_H_

#include "DIO_register.h"

#define ISR(vector, ...) \
	void vector(void) __attribute__ ((signal,used,externally_visible)) __VA_ARGS__;\
	void vector(void)


//External Interrupts Interrupt Vectors
#define INT0_Vect		__vector_1
#define INT1_Vect		__vector_2
#define INT2_Vect		__vector_3

//ADC Interrupt Vector
#define ADC_Vect			__vector_16


#endif /* SERVICE_INTERRUPT_VECTOR_H_ */
