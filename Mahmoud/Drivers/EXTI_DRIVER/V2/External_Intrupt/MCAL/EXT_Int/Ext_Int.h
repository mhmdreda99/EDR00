/*
 * Ext_Int.h
 *
 *  Created on: 28 Apr 2022
 *      Author: Mahmoud
 */

#ifndef EXT_INT_H_
#define EXT_INT_H_
#include "../../Controller/ATMEGA32/Registers.h"
#include"../../Controller/ATMEGA32/Interrupts.h"
#include"../../4-LIB/STD_TYPES.h"
#include"../../4-LIB/BIT_Math.h"

/*global*/
typedef enum
{
	GLOBAL_INT_DISABLE,
	GLOBAL_INT_ENABLE

}GLOBAL_INT_ENABLE_t;

StdReturn GIE_INT_ENABLE( GLOBAL_INT_ENABLE_t state );



/*sense control*/

/*prephral*/
typedef enum
{
	GICR_DISABLE,
	GICR_ENABLE

}GICR_ENABLE_t;



typedef enum
{
	GENERAL_INT0 ,
	GENERAL_INT1,
	GENERAL_INT2

}GENERAL_INT_CONTROL_t;


StdReturn GENERAL_INT_CONTROL(GENERAL_INT_CONTROL_t control,GICR_ENABLE_t enable); //specific


typedef enum
{
	INT_FALLING,
	INT_RISING

}EXT_INT_SENSE_CONTROL_t;

StdReturn EXT_INT_SENSE_CONTROL (GENERAL_INT_CONTROL_t INT, EXT_INT_SENSE_CONTROL_t sense);


//FLAG

StdReturn EXT_INT_CLEAR_FLAG (GENERAL_INT_CONTROL_t INT);


//Callback
//callback int0
StdReturn INT0_Callback_Function(void(*Fptr0)(void));
//callback int1
StdReturn INT1_Callback_Function(void(*Fptr1)(void));
//callback int2
StdReturn INT2_Callback_Function(void(*Fptr2)(void));



#endif /* EXT_INT_H_ */
