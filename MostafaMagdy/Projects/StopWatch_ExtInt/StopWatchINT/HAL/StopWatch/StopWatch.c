/**
 * @file 		  StopWatch.c
 * @author        MostafaMagdy
 * @email         MostafaMagii7@gmail.com
 * @Git account:  https:github.com/MostafaMagdy99
 * @version       0.1
 * @date 		  2022-04-28
 * 
 * @copyright Copyright (c) 2022
 * 
 * Description :  Source file for StopWatch
 */

/******************************************Includes**************************************************/
#include "StopWatch.h"
/*****************************************************************************************************/
/**
 * @brief 
 * 
 * @param StopWatch_ControlPort 	: takes which DIO_PORT used to control the 4 sevensegment
 * @param TYPE 						: takes the sevensegment types CommonAnode/CommonCathode
 * @param Time 						: take which time will activated Sec01/Sec10/Min01/Min10			
 * @return STD_Return 
 */
STD_Return TimingSelection(u8 StopWatch_ControlPort,SevenSegment_Type_t TYPE,SevenSegment_Sel_t Time)
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
/*****************************************************************************************************/

