/*
 * @file 		  External_Interrupt.c
 * @author        MostafaMagdy
 * @email         MostafaMagii7@gmail.com
 * @Git account:  https:github.com/MostafaMagdy99
 * @version       0.1
 * @date          2022-04-26
 * 
 * @copyright Copyright (c) 2022
 * 
 * Description :  Source file for the External Interrupt driver
 */

/***************************************Includes******************************************************/
#include "External_Interrupt.h"
/************************************User/External Function*******************************************/
static void (*External_Function0)(void);
static void (*External_Function1)(void);
static void (*External_Function2)(void);
/****************************************ISR for INT0*************************************************/
ISR(INT0_Vect)
{
	(*External_Function0)();
}
/****************************************ISR for INT1*************************************************/
ISR(INT1_Vect)
{
	(*External_Function1)();
}
/****************************************ISR for INT2*************************************************/
ISR(INT2_Vect)
{
	(*External_Function2)();
}
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
STD_Return Enable_Global_Interrupt(Interrupt_State_t state)
{
	switch(state)
		{
			case Enable_Interrupt:
				SET_BIT(SREG,GIE);
				break;
			case Disable_Interrupt:
				CLEAR_BIT(SREG,GIE);
				break;
			default:
				return E_OK;
		}
	return E_NOK;
}
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
STD_Return External_Int0(Int_Sense_Control_t SenseLevel)
{
	SET_BIT(GICR,INT0);

	switch(SenseLevel)
		{
			case Rising_Edge_Sense:
					SET_BIT(MCUCR,ISC00);
					SET_BIT(MCUCR,ISC01);
					break;
			case Falling_Edge_Sense:
					CLEAR_BIT(MCUCR,ISC00);
					SET_BIT(MCUCR,ISC01);
					break;
			default:
				return E_OK;
		}
	return E_NOK;
}
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
STD_Return CallBack_Int0(void (*Func_Ptr)(void))
{
	External_Function0=Func_Ptr;
	return E_NOK;
}
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
STD_Return External_Int1(Int_Sense_Control_t SenseLevel)
{
	SET_BIT(GICR,INT1);

	switch(SenseLevel)
		{
			case Rising_Edge_Sense:
					SET_BIT(MCUCR,ISC10);
					SET_BIT(MCUCR,ISC11);
					return E_NOK;
					break;
			case Falling_Edge_Sense:
					CLEAR_BIT(MCUCR,ISC10);
					SET_BIT(MCUCR,ISC11);
					return E_NOK;
					break;
			default:
				return E_OK;
		}
	return E_NOK;
}
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
STD_Return CallBack_Int1(void (*Func_Ptr)(void))
{
	External_Function1=Func_Ptr;
	return E_NOK;
}
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
STD_Return External_Int2(Int_Sense_Control_t SenseLevel)
{
	SET_BIT(GICR,INT2);

	switch(SenseLevel)
		{
			case Rising_Edge_Sense:
					SET_BIT(MCUCSR,ISC2);
					return E_NOK;
					break;
			case Falling_Edge_Sense:
					CLEAR_BIT(MCUCSR,ISC2);
					return E_NOK;
					break;
			default:
				return E_OK;
		}
	return E_NOK;
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
}
STD_Return CallBack_Int2(void (*Func_Ptr)(void))
{
	External_Function2=Func_Ptr;
	return E_NOK;
}
/*****************************************************************************************************/