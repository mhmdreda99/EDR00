/*
 * file.h
 *
 *  Created on: Mar 28, 2022
 *      Author: Seko
 */

#ifndef SEVENSEGMENT_H_
#define SEVENSEGMENT_H_

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_Types.h"
#include "../../SERVICE/DIO_register.h"
#include "../../MCAL/DIO/DIO_interface.h"

#define A 0
#define B 1
#define C 2
#define D 3
#define E 4
#define F 5
#define G 6
#define Common_PIN 7

typedef enum
{
	CommonCathod,
	CommonAnode
}SevenSegment_Type;

typedef enum
{
	Zero,
	One,
	Two,
	Three,
	Four,
	Five,
	Six,
	Seven,
	Eight,
	Nine,
}Display_Number;


STD_Return SevenSegment_Display(DIO_Ports PORT,SevenSegment_Type TYPE,Display_Number NUM);

#endif /* SEVENSEGMENT_H_ */
