/*
 * StopWatch.h
 *
 *  Created on: Mar 31, 2022
 *      Author: Seko
 */

#ifndef STOPWATCH_H_
#define STOPWATCH_H_
#include "../../LIB/BIT_MATH.H"
#include "../../LIB/STD_Types.h"
#include "../../SERVICE/DIO_register.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "../../HAL/SevenSegment_Driver/SevenSegment.h"
#include "StopWatch_Config.h"

#define SEL0 0
#define SEL1 1

typedef enum
{
	Sec01,
	Sec10,
	Min01,
	Min10

}SevenSegment_Sel;

STD_Return TimingSelection(u8 StopWatch_ControlPort,SevenSegment_Type TYPE,SevenSegment_Sel Time);

#endif /* STOPWATCH_H_ */
