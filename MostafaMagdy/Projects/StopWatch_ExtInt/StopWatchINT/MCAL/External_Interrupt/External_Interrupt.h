/*
 * @file 	      External_Interrupt.h
 * @author        MostafaMagdy
 * @email         MostafaMagii7@gmail.com
 * @Git account:  https:github.com/MostafaMagdy99
 * @version       0.1
 * @date          2022-04-26
 * 
 * @copyright Copyright (c) 2022
 * 
 * Description :  Header file for the External Interrupt driver
 */

/*This is preprocessor Header file guard  */
#ifndef EXTERNAL_INTERRUPT_H_
#define EXTERNAL_INTERRUPT_H_
/******************************************Includes**************************************************/
#include "../../SERVICE/Interrupt_Vector.h"
#include "../../SERVICE/DIO_register.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_Types.h"
/*****************************************************************************************************/
/**
 * @brief 
 * enum : 			user define
 * Description :	State Enable / Disable External interrupt 
 * 
 * _t means that it is a datatype
**/
typedef enum
{
	Enable_Interrupt,
	Disable_Interrupt
}Interrupt_State_t;
/*****************************************************************************************************/
/**
 * @brief 
 * enum : 			user define
 * Description :	State interrupt sense level Rising / Falling 
 * 
 * _t means that it is a datatype
**/
typedef enum
{
	Falling_Edge_Sense,
	Rising_Edge_Sense
}Int_Sense_Control_t;
/*****************************************************************************************************/
/**
 * @brief 
 * Prototype    	 	: 		STD_Return Enable_Global_Interrupt(Interrupt_State_t state);
 * Description  	 	:		function to activte the Global interrupt/Enable or Disable External interrupt
 * 
 * @param state 		:		takes two states Enable_Interrupt/Disable_Interrupt
 * @return STD_Return	 :		STD_Return for Error identification
 * 
 * 								return 0 mean Error is found , return 1 mean Error is not found
 **/
STD_Return Enable_Global_Interrupt(Interrupt_State_t state);
/*****************************************************************************************************/
/**
 * @brief 
 * Prototype    	 	: 		STD_Return External_Int0(Int_Sense_Control_t SenseLevel);
 * Description  	 	:		function to activte the External interrupt _ No1 (INT0) 
 * 
 * @param SenseLevel 	 :		takes two states of the senslevel Raising or Falling
 * @return STD_Return	 :		STD_Return for Error identification
 * 
 * 								return 0 mean Error is found , return 1 mean Error is not found
 **/
STD_Return External_Int0(Int_Sense_Control_t SenseLevel);
/*****************************************************************************************************/
/**
 * @brief 
 * Prototype    	 	: 		STD_Return CallBack_Int0(void (*Func_Ptr)(void));
 * Description  	 	:		function to Callback the function of user/External function_ No1 (INT0) 
 * 
 * @param Func_Ptr 	 	:  	 	function pointer that points to the External/User functions  1
 * @return STD_Return	 :		STD_Return for Error identification
 * 
 * 								return 0 mean Error is found , return 1 mean Error is not found
 **/
STD_Return CallBack_Int0(void (*Func_Ptr)(void));
/*****************************************************************************************************/
/**
 * @brief 
 * Prototype    	 	: 		STD_Return External_Int1(Int_Sense_Control_t SenseLevel);
 * Description  	 	:		function to activte the External interrupt _ No2 (INT1) 
 * 
 * @param SenseLevel 	 :		takes two states of the senslevel Raising or Falling 
 * @return STD_Return	 :		STD_Return for Error identification
 * 
 * 								return 0 mean Error is found , return 1 mean Error is not found
 **/
STD_Return External_Int1(Int_Sense_Control_t SenseLevel);
/*****************************************************************************************************/
/**
 * @brief 
 * Prototype    	 	: 		STD_Return CallBack_Int1(void (*Func_Ptr)(void));
 * Description  	 	:		function to Callback the function of user/External function_ No2 (INT1) 
 * 
 * @param Func_Ptr 	 	:  	 	function pointer that points to the External/User functions 2
 * @return STD_Return	 :		STD_Return for Error identification
 * 
 * 								return 0 mean Error is found , return 1 mean Error is not found
 **/
STD_Return CallBack_Int1(void (*Func_Ptr)(void));
/*****************************************************************************************************/
/**
 * @brief 
 * Prototype    	 	: 		STD_Return External_Int2(Int_Sense_Control_t SenseLevel);
 * Description  	 	:		function to activte the External interrupt _ No3 (INT2) 
 * 
 * @param SenseLevel 	 :		takes two states of the senslevel Raising or Falling 
 * @return STD_Return	 :		STD_Return for Error identification
 * 
 * 								return 0 mean Error is found , return 1 mean Error is not found
 **/
STD_Return External_Int2(Int_Sense_Control_t SenseLevel);
/*****************************************************************************************************/
/**
 * @brief 
 * Prototype    	 	: 		STD_Return CallBack_Int2(void (*Func_Ptr)(void));
 * Description  	 	:		function to Callback the function of user/External function_ No3 (INT2) 
 * 
 * @param Func_Ptr 	 	:  	 	function pointer that points to the External/User functions 3
 * @return STD_Return	 :		STD_Return for Error identification
 * 
 * 								return 0 mean Error is found , return 1 mean Error is not found
 **/
STD_Return CallBack_Int2(void (*Func_Ptr)(void));
/*****************************************************************************************************/
/*This is preprocessor Header file guard End  */
#endif /* EXTERNAL_INTERRUPT_H_ */
