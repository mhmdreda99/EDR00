/*
 * @file 		  Interrupt_Vector.h
 * @author        MostafaMagdy
 * @email         MostafaMagii7@gmail.com
 * @Git account:  https:github.com/MostafaMagdy99
 * @version       0.1
 * @date 		  2022-04-28
 * 
 * @copyright Copyright (c) 2022
 * 
 *  Description :  Header file for the Interrupt vectors
 */

/*This is preprocessor Header file guard  */
#ifndef SERVICE_INTERRUPT_VECTOR_H_
#define SERVICE_INTERRUPT_VECTOR_H_
/******************************************Includes**************************************************/
#include "DIO_register.h"
/*****************************************EXT INT ISR************************************************/
#define ISR(vector, ...) \
	void vector(void) __attribute__ ((signal,used,externally_visible)) __VA_ARGS__;\
	void vector(void)
/***********************************Interrupt Vectors Section****************************************/

/*****************************************INT VECTORS************************************************/
#define INT0_Vect		__vector_1
#define INT1_Vect		__vector_2
#define INT2_Vect		__vector_3
/*****************************************ADC VECTORS************************************************/
#define ADC_Vect			__vector_16
/****************************************************************************************************/
/*This is preprocessor Header file guard End  */
#endif /* SERVICE_INTERRUPT_VECTOR_H_ */
