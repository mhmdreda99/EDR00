/*
 * StopWatch.c
 *
 *  Created on: Mar 31, 2022
 *      Author: Seko
 */

#include "StopWatch.h"

STD_Return TimingSelection(u8 StopWatch_ControlPort,SevenSegment_Type TYPE,SevenSegment_Sel Time)
{
	#ifdef StopWatch_ControlPort_A
	switch(TYPE)
	{
		case CommonCathod:
			switch(Time)
				{
					case Sec01:
						DIO_SetPinDirection(StopWatch_ControlPort_A,Control_SEL_0,DIO_OUTPUT);
						DIO_SetPinDirection(StopWatch_ControlPort_A,Control_SEL_1,DIO_OUTPUT);
						DIO_SetPinValue(StopWatch_ControlPort_A,Control_SEL_0,DIO_HIGH);
						DIO_SetPinValue(StopWatch_ControlPort_A,Control_SEL_1,DIO_HIGH);
						break;
					case Sec10:
						DIO_SetPinDirection(StopWatch_ControlPort_A,Control_SEL_0,DIO_OUTPUT);
						DIO_SetPinDirection(StopWatch_ControlPort_A,Control_SEL_1,DIO_OUTPUT);
						DIO_SetPinValue(StopWatch_ControlPort_A,Control_SEL_0,DIO_LOW);
						DIO_SetPinValue(StopWatch_ControlPort_A,Control_SEL_1,DIO_HIGH);
						break;
					case Min01:
						DIO_SetPinDirection(StopWatch_ControlPort_A,Control_SEL_0,DIO_OUTPUT);
						DIO_SetPinDirection(StopWatch_ControlPort_A,Control_SEL_1,DIO_OUTPUT);
						DIO_SetPinValue(StopWatch_ControlPort_A,Control_SEL_0,DIO_HIGH);
						DIO_SetPinValue(StopWatch_ControlPort_A,Control_SEL_1,DIO_LOW);
						break;
					case Min10:
						DIO_SetPinDirection(StopWatch_ControlPort_A,Control_SEL_0,DIO_OUTPUT);
						DIO_SetPinDirection(StopWatch_ControlPort_A,Control_SEL_1,DIO_OUTPUT);
						DIO_SetPinValue(StopWatch_ControlPort_A,Control_SEL_0,DIO_LOW);
						DIO_SetPinValue(StopWatch_ControlPort_A,Control_SEL_1,DIO_LOW);
						break;
					default: return E_OK;
				}
		break;
		case CommonAnode:
			switch(Time)
				{
					case Sec01:
						DIO_SetPinDirection(StopWatch_ControlPort_A,Control_SEL_0,DIO_OUTPUT);
						DIO_SetPinDirection(StopWatch_ControlPort_A,Control_SEL_1,DIO_OUTPUT);
						DIO_SetPinValue(StopWatch_ControlPort_A,Control_SEL_0,DIO_LOW);
						DIO_SetPinValue(StopWatch_ControlPort_A,Control_SEL_1,DIO_LOW);
						break;
					case Sec10:
						DIO_SetPinDirection(StopWatch_ControlPort_A,Control_SEL_0,DIO_OUTPUT);
						DIO_SetPinDirection(StopWatch_ControlPort_A,Control_SEL_1,DIO_OUTPUT);
						DIO_SetPinValue(StopWatch_ControlPort_A,Control_SEL_0,DIO_HIGH);
						DIO_SetPinValue(StopWatch_ControlPort_A,Control_SEL_1,DIO_LOW);
						break;
					case Min01:
						DIO_SetPinDirection(StopWatch_ControlPort_A,Control_SEL_0,DIO_OUTPUT);
						DIO_SetPinDirection(StopWatch_ControlPort_A,Control_SEL_1,DIO_OUTPUT);
						DIO_SetPinValue(StopWatch_ControlPort_A,Control_SEL_0,DIO_LOW);
						DIO_SetPinValue(StopWatch_ControlPort_A,Control_SEL_1,DIO_HIGH);
						break;
					case Min10:
						DIO_SetPinDirection(StopWatch_ControlPort_A,Control_SEL_0,DIO_OUTPUT);
						DIO_SetPinDirection(StopWatch_ControlPort_A,Control_SEL_1,DIO_OUTPUT);
						DIO_SetPinValue(StopWatch_ControlPort_A,Control_SEL_0,DIO_HIGH);
						DIO_SetPinValue(StopWatch_ControlPort_A,Control_SEL_0,DIO_HIGH);
						break;
					default: return E_OK;
				}
		break;
		default:
		return E_OK;
	}
#elif StopWatch_ControlPort_B
	switch(TYPE)
		{
			case CommonCathod:
				switch(Time)
					{
						case Sec01:
							DIO_SetPinDirection(StopWatch_ControlPort_B,Control_SEL_0,DIO_OUTPUT);
							DIO_SetPinDirection(StopWatch_ControlPort_B,Control_SEL_1,DIO_OUTPUT);
							DIO_SetPinValue(StopWatch_ControlPort_B,Control_SEL_0,DIO_HIGH);
							DIO_SetPinValue(StopWatch_ControlPort_B,Control_SEL_1,DIO_HIGH);
							break;
						case Sec10:
							DIO_SetPinDirection(StopWatch_ControlPort_B,Control_SEL_0,DIO_OUTPUT);
							DIO_SetPinDirection(StopWatch_ControlPort_B,Control_SEL_1,DIO_OUTPUT);
							DIO_SetPinValue(StopWatch_ControlPort_B,Control_SEL_0,DIO_LOW);
							DIO_SetPinValue(StopWatch_ControlPort_B,Control_SEL_1,DIO_HIGH);
							break;
						case Min01:
							DIO_SetPinDirection(StopWatch_ControlPort_B,Control_SEL_0,DIO_OUTPUT);
							DIO_SetPinDirection(StopWatch_ControlPort_B,Control_SEL_1,DIO_OUTPUT);
							DIO_SetPinValue(StopWatch_ControlPort_B,Control_SEL_0,DIO_HIGH);
							DIO_SetPinValue(StopWatch_ControlPort_B,Control_SEL_1,DIO_LOW);
							break;
						case Min10:
							DIO_SetPinDirection(StopWatch_ControlPort_B,Control_SEL_0,DIO_OUTPUT);
							DIO_SetPinDirection(StopWatch_ControlPort_B,Control_SEL_1,DIO_OUTPUT);
							DIO_SetPinValue(StopWatch_ControlPort_B,Control_SEL_0,DIO_LOW);
							DIO_SetPinValue(StopWatch_ControlPort_B,Control_SEL_0,DIO_LOW);
							break;
						default: return E_OK;
					}
			break;
			case CommonAnode:
				switch(Time)
					{
						case Sec01:
							DIO_SetPinDirection(StopWatch_ControlPort_B,Control_SEL_0,DIO_OUTPUT);
							DIO_SetPinDirection(StopWatch_ControlPort_B,Control_SEL_1,DIO_OUTPUT);
							DIO_SetPinValue(StopWatch_ControlPort_B,Control_SEL_0,DIO_LOW);
							DIO_SetPinValue(StopWatch_ControlPort_B,Control_SEL_1,DIO_LOW);
							break;
						case Sec10:
							DIO_SetPinDirection(StopWatch_ControlPort_B,Control_SEL_0,DIO_OUTPUT);
							DIO_SetPinDirection(StopWatch_ControlPort_B,Control_SEL_1,DIO_OUTPUT);
							DIO_SetPinValue(StopWatch_ControlPort_B,Control_SEL_0,DIO_HIGH);
							DIO_SetPinValue(StopWatch_ControlPort_B,Control_SEL_1,DIO_LOW);
							break;
						case Min01:
							DIO_SetPinDirection(StopWatch_ControlPort_B,Control_SEL_0,DIO_OUTPUT);
							DIO_SetPinDirection(StopWatch_ControlPort_B,Control_SEL_1,DIO_OUTPUT);
							DIO_SetPinValue(StopWatch_ControlPort_B,Control_SEL_0,DIO_LOW);
							DIO_SetPinValue(StopWatch_ControlPort_B,Control_SEL_1,DIO_HIGH);
							break;
						case Min10:
							DIO_SetPinDirection(StopWatch_ControlPort_B,Control_SEL_0,DIO_OUTPUT);
							DIO_SetPinDirection(StopWatch_ControlPort_B,Control_SEL_1,DIO_OUTPUT);
							DIO_SetPinValue(StopWatch_ControlPort_B,Control_SEL_0,DIO_HIGH);
							DIO_SetPinValue(StopWatch_ControlPort_B,Control_SEL_0,DIO_HIGH);
							break;
						default: return E_OK;
					}
			break;
			default:
			return E_OK;
		}
#elif StopWatch_ControlPort_C
	switch(TYPE)
		{
			case CommonCathod:
				switch(Time)
					{
						case Sec01:
							DIO_SetPinDirection(StopWatch_ControlPort_C,Control_SEL_0,DIO_OUTPUT);
							DIO_SetPinDirection(StopWatch_ControlPort_C,Control_SEL_1,DIO_OUTPUT);
							DIO_SetPinValue(StopWatch_ControlPort_C,Control_SEL_0,DIO_HIGH);
							DIO_SetPinValue(StopWatch_ControlPort_C,Control_SEL_1,DIO_HIGH);
							break;
						case Sec10:
							DIO_SetPinDirection(StopWatch_ControlPort_C,Control_SEL_0,DIO_OUTPUT);
							DIO_SetPinDirection(StopWatch_ControlPort_C,Control_SEL_1,DIO_OUTPUT);
							DIO_SetPinValue(StopWatch_ControlPort_C,Control_SEL_0,DIO_LOW);
							DIO_SetPinValue(StopWatch_ControlPort_C,Control_SEL_1,DIO_HIGH);
							break;
						case Min01:
							DIO_SetPinDirection(StopWatch_ControlPort_C,Control_SEL_0,DIO_OUTPUT);
							DIO_SetPinDirection(StopWatch_ControlPort_C,Control_SEL_1,DIO_OUTPUT);
							DIO_SetPinValue(StopWatch_ControlPort_C,Control_SEL_0,DIO_HIGH);
							DIO_SetPinValue(StopWatch_ControlPort_C,Control_SEL_1,DIO_LOW);
							break;
						case Min10:
							DIO_SetPinDirection(StopWatch_ControlPort_C,Control_SEL_0,DIO_OUTPUT);
							DIO_SetPinDirection(StopWatch_ControlPort_C,Control_SEL_1,DIO_OUTPUT);
							DIO_SetPinValue(StopWatch_ControlPort_C,Control_SEL_0,DIO_LOW);
							DIO_SetPinValue(StopWatch_ControlPort_C,Control_SEL_0,DIO_LOW);
							break;
						default: return E_OK;
					}
			break;
			case CommonAnode:
				switch(Time)
					{
						case Sec01:
							DIO_SetPinDirection(StopWatch_ControlPort_C,Control_SEL_0,DIO_OUTPUT);
							DIO_SetPinDirection(StopWatch_ControlPort_C,Control_SEL_1,DIO_OUTPUT);
							DIO_SetPinValue(StopWatch_ControlPort_C,Control_SEL_0,DIO_LOW);
							DIO_SetPinValue(StopWatch_ControlPort_C,Control_SEL_1,DIO_LOW);
							break;
						case Sec10:
							DIO_SetPinDirection(StopWatch_ControlPort_C,Control_SEL_0,DIO_OUTPUT);
							DIO_SetPinDirection(StopWatch_ControlPort_C,Control_SEL_1,DIO_OUTPUT);
							DIO_SetPinValue(StopWatch_ControlPort_C,Control_SEL_0,DIO_HIGH);
							DIO_SetPinValue(StopWatch_ControlPort_C,Control_SEL_1,DIO_LOW);
							break;
						case Min01:
							DIO_SetPinDirection(StopWatch_ControlPort_C,Control_SEL_0,DIO_OUTPUT);
							DIO_SetPinDirection(StopWatch_ControlPort_C,Control_SEL_1,DIO_OUTPUT);
							DIO_SetPinValue(StopWatch_ControlPort_C,Control_SEL_0,DIO_LOW);
							DIO_SetPinValue(StopWatch_ControlPort_C,Control_SEL_1,DIO_HIGH);
							break;
						case Min10:
							DIO_SetPinDirection(StopWatch_ControlPort_C,Control_SEL_0,DIO_OUTPUT);
							DIO_SetPinDirection(StopWatch_ControlPort_C,Control_SEL_1,DIO_OUTPUT);
							DIO_SetPinValue(StopWatch_ControlPort_C,Control_SEL_0,DIO_HIGH);
							DIO_SetPinValue(StopWatch_ControlPort_C,Control_SEL_0,DIO_HIGH);
							break;
						default: return E_OK;
					}
			break;
			default:
			return E_OK;
		}
#elif StopWatch_ControlPort_D
	switch(TYPE)
		{
			case CommonCathod:
				switch(Time)
					{
						case Sec01:
							DIO_SetPinDirection(StopWatch_ControlPort_D,Control_SEL_0,DIO_OUTPUT);
							DIO_SetPinDirection(StopWatch_ControlPort_D,Control_SEL_1,DIO_OUTPUT);
							DIO_SetPinValue(StopWatch_ControlPort_D,Control_SEL_0,DIO_HIGH);
							DIO_SetPinValue(StopWatch_ControlPort_D,Control_SEL_1,DIO_HIGH);
							break;
						case Sec10:
							DIO_SetPinDirection(StopWatch_ControlPort_D,Control_SEL_0,DIO_OUTPUT);
							DIO_SetPinDirection(StopWatch_ControlPort_D,Control_SEL_1,DIO_OUTPUT);
							DIO_SetPinValue(StopWatch_ControlPort_D,Control_SEL_0,DIO_LOW);
							DIO_SetPinValue(StopWatch_DataPort,Control_SEL_1,DIO_HIGH);
							break;
						case Min01:
							DIO_SetPinDirection(StopWatch_ControlPort_D,Control_SEL_0,DIO_OUTPUT);
							DIO_SetPinDirection(StopWatch_ControlPort_D,Control_SEL_1,DIO_OUTPUT);
							DIO_SetPinValue(StopWatch_ControlPort_D,Control_SEL_0,DIO_HIGH);
							DIO_SetPinValue(StopWatch_ControlPort_D,Control_SEL_1,DIO_LOW);
							break;
						case Min10:
							DIO_SetPinDirection(StopWatch_ControlPort_D,Control_SEL_0,DIO_OUTPUT);
							DIO_SetPinDirection(StopWatch_ControlPort_D,Control_SEL_1,DIO_OUTPUT);
							DIO_SetPinValue(StopWatch_ControlPort_D,Control_SEL_0,DIO_LOW);
							DIO_SetPinValue(StopWatch_ControlPort_D,Control_SEL_0,DIO_LOW);
							break;
						default: return E_OK;
					}
			break;
			case CommonAnode:
				switch(Time)
					{
						case Sec01:
							DIO_SetPinDirection(StopWatch_ControlPort_D,Control_SEL_0,DIO_OUTPUT);
							DIO_SetPinDirection(StopWatch_ControlPort_D,Control_SEL_1,DIO_OUTPUT);
							DIO_SetPinValue(StopWatch_ControlPort_D,Control_SEL_0,DIO_LOW);
							DIO_SetPinValue(StopWatch_ControlPort_D,Control_SEL_1,DIO_LOW);
							break;
						case Sec10:
							DIO_SetPinDirection(StopWatch_ControlPort_D,Control_SEL_0,DIO_OUTPUT);
							DIO_SetPinDirection(StopWatch_ControlPort_D,Control_SEL_1,DIO_OUTPUT);
							DIO_SetPinValue(StopWatch_ControlPort_D,Control_SEL_0,DIO_HIGH);
							DIO_SetPinValue(StopWatch_ControlPort_D,Control_SEL_1,DIO_LOW);
							break;
						case Min01:
							DIO_SetPinDirection(StopWatch_ControlPort_D,Control_SEL_0,DIO_OUTPUT);
							DIO_SetPinDirection(StopWatch_ControlPort_D,Control_SEL_1,DIO_OUTPUT);
							DIO_SetPinValue(StopWatch_ControlPort_D,Control_SEL_0,DIO_LOW);
							DIO_SetPinValue(StopWatch_ControlPort_D,Control_SEL_1,DIO_HIGH);
							break;
						case Min10:
							DIO_SetPinDirection(StopWatch_ControlPort_D,Control_SEL_0,DIO_OUTPUT);
							DIO_SetPinDirection(StopWatch_ControlPort_D,Control_SEL_1,DIO_OUTPUT);
							DIO_SetPinValue(StopWatch_ControlPort_D,Control_SEL_0,DIO_HIGH);
							DIO_SetPinValue(StopWatch_ControlPort_D,Control_SEL_0,DIO_HIGH);
							break;
						default: return E_OK;
					}
			break;
			default:
			return E_OK;
		}
#endif
	return E_NOK;
}

