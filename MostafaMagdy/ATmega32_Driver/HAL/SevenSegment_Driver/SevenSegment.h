/*
 * @file 		  SevenSegment.h
* @author         MostafaMagdy
 * @email         MostafaMagii7@gmail.com
 * @Git account:  https:github.com/MostafaMagdy99
 * @version       0.1
 * @date 		  2022-04-28
 * 
 * @copyright Copyright (c) 2022
 * 
 *  Description :  Header file for the Seven_Segment
 */

/*This is preprocessor Header file guard  */
#ifndef SEVENSEGMENT_H_
#define SEVENSEGMENT_H_
/******************************************Includes**************************************************/
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_Types.h"
#include "../../SERVICE/DIO_register.h"
#include "../../MCAL/DIO/DIO_interface.h"
/*******************************************Macros***************************************************/
#define A 0
#define B 1
#define C 2
#define D 3
#define E 4
#define F 5
#define G 6
#define Common_PIN 7
/*****************************************************************************************************/
/**
 * @brief 
 * enum : 			user define
 * Description :	State SevenSegment type  CommonCathode/ CommonAnode 
 * 
 * _t means that it is a datatype
**/
typedef enum
{
	CommonCathod,
	CommonAnode
}SevenSegment_Type_t;
/*****************************************************************************************************/
/**
 * @brief 
 * enum : 			user define
 * Description :	State Number that will Displayed on the SevenSegment
 * 
 * _t means that it is a datatype
**/
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
}Display_Number_t;
/*****************************************************************************************************/
/**
 * @brief 
 * Prototype    	 	: 		STD_Return SevenSegment_Display(DIO_Ports_t PORT,SevenSegment_Type TYPE,Display_Number NUM);
 * Description  	 	:		function state that which port is used the type pf seventsegment that used and the diplayed number 
 * 
 * @param PORT	 		: 		takes DIO_PORTS: DIO_PORTA,DIO_PORTB,DIO_PORTC,DIO_PORTD
 * @param TYPE 			:	`	takes type of Sevensegment CommonCathode/ CommonAnode
 * @param NUM 			:		takes the number that will be displayed from one to nine
 * @return STD_Return 	 :		STD_Return for Error identification
 * 
 * 								return 0 mean Error is found , return 1 mean Error is not found
 **/
STD_Return SevenSegment_Display(DIO_Ports_t PORT,SevenSegment_Type_t TYPE,Display_Number_t NUM);
/*****************************************************************************************************/
/*This is preprocessor Header file guard End  */
#endif /* SEVENSEGMENT_H_ */
