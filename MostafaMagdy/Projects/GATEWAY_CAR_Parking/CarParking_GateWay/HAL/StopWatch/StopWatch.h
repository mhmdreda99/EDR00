/*
 * @file          StopWatch.h
 * @author        MostafaMagdy
 * @email         MostafaMagii7@gmail.com
 * @Git account:  https:github.com/MostafaMagdy99
 * @version       0.1
 * @date 		  2022-04-28
 * 
 * @copyright Copyright (c) 2022
 * 
 * Description :  Header file for StopWatch
 */

/*This is preprocessor Header file guard  */
#ifndef STOPWATCH_H_
#define STOPWATCH_H_
/******************************************Includes**************************************************/
#include "../../LIB/BIT_MATH.H"
#include "../../LIB/STD_Types.h"
#include "../../SERVICE/DIO_register.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "../../HAL/SevenSegment_Driver/SevenSegment.h"
#include "StopWatch_Config.h"
/******************************************Defintions**********************************************/
#define SEL0 0
#define SEL1 1
/*****************************************************************************************************/
/**
 * @brief 
 * enum : 			user define
 * Description :	Selection of which SevenSegment used for time Sec01/Sec10/Min01/Min10 
 * 
 * _t means that it is a datatype
**/
typedef enum
{
	Sec01,
	Sec10,
	Min01,
	Min10

}SevenSegment_Sel_t;
/*****************************************************************************************************/
/**
 * @brief 
 * 
 * @param StopWatch_ControlPort 	: takes which DIO_PORT used to control the 4 sevensegment
 * @param TYPE 						: takes the sevensegment types CommonAnode/CommonCathode
 * @param Time 						: take which time will activated Sec01/Sec10/Min01/Min10			
 * @return STD_Return 
 */
STD_Return TimingSelection(u8 StopWatch_ControlPort,SevenSegment_Type_t TYPE,SevenSegment_Sel_t Time);
/*****************************************************************************************************/
/*This is preprocessor Header file guard End  */
#endif /* STOPWATCH_H_ */
