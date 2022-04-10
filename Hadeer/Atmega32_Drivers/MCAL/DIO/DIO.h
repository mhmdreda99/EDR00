/*
 * DIO.h
 *
 *  	Created on: Mar 30, 2022 , 2:51 AM
 *
 *      Author: Hadeer_Esmat
 *
 *      VERSION : 1
 *
 */


#include "../Service/StdMacros.h"
#include "../Service/StdTypes.h"
#include "../Controller/ATMEGA32/Registers.h"
#include "../Controller/ATMEGA32/Interrupts.h"



#ifndef DIO_H_
#define DIO_H_
#define MAX_PIN_NUM 7



typedef enum
{
	DIO_PORT_A,
	DIO_PORT_B,
	DIO_PORT_C,
	DIO_PORT_D

}DIO_PORT_t;


typedef enum
{
	DIO_pin_INPUT ,
	DIO_pin_OUTPUT

}DIO_pin_DIRECTION_t ;


typedef enum
{
	DIO_pin_LOW ,
	DIO_pin_HIGH
}DIO_pin_CASE_t ;


typedef enum
{
	DIO_PUD_DISABLE,  // set bit
	DIO_PUD_ENABLE	 //  clear bit


}DIO_PUD_ENABLE_t;



StdReturn DIO_SET_DIRECTION (DIO_PORT_t Port , uint8 pin , DIO_pin_DIRECTION_t  direction);

/* DIO_SET_DIRECTION ,Is a function used to set the direction of 'DIO'
 ******* TO set the direction : 1) firstly set the port[A ,B ,C, D ]
 ******* 						2) Set The pin number
 ******* 						3)Set the DIO _Direction
 ******* 							****(If the input Is(0) the direction is 'INPUT'
 ******* 							****(If the input Is(1) the direction is 'OUTNPUT'
 *******
 *******
 */

StdReturn DIO_OUTPUT (DIO_PORT_t Port , uint8 pin ,DIO_pin_CASE_t state);



StdReturn DIO_INPUT (DIO_PORT_t Port , uint8 pin ,DIO_pin_CASE_t *state);


StdReturn DIO_PUD (DIO_PORT_t Port , uint8 pin ,DIO_PUD_ENABLE_t state);

StdReturn GPIO_togglePin(DIO_PORT_t  port, uint8 pin);

#endif /* DIO_H_ */
