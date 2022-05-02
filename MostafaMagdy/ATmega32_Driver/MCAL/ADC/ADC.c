/*
 * @file 		  ADC.c
 * @author        MostafaMagdy
 * @email         MostafaMagii7@gmail.com
 * @Git account:  https:github.com/MostafaMagdy99
 * @version       0.1
 * @date          2022-04-26
 * 
 * @copyright Copyright (c) 2022
 * 
 *  Description :  Source file for the ADC driver
 */

/***************************************Includes******************************************************/
#include "ADC.h"
/*********************************User/External Function*****************************************/
static void (*User_Function)(void);
/*********************************Voltage Reference Defintion*****************************************/
#if defined	AREF_Internal_VREF
#define VREF	2.56
#elif defined AREF_External_VREF
#define VREF 5
#endif
/*************************************Resolution Defintion********************************************/
#if defined Resolution_8_Bit
#define ADC_MAX 256
#elif defined Resolution_10_Bit
#define ADC_MAX 1024
#endif
/*****************************************************************************************************/
/**
 * @brief 
 * Prototype    	 	: 		extern void ADC_Init(void);
 * Description  	 	:		Initialize ADC Periphiral 
 * 
 * @param   	void 	:  		has no input paramater
 * @return  	void 	:		Return nothing
 */
 /*****************************************************************************************************/
STD_Return ADC_Init(ADC__State_t State)
{
	//Resolution Selection
	#if defined Resolution_8_Bit
	SET_BIT(ADMUX,ADLAR);
	#elif defined Resolution_10_Bit
	CLEAR_BIT(ADMUX,ADLAR);
	#endif

	//Voltage Reference Selection
	#if defined AREF_Internal_VREF
	SET_BIT(ADMUX,REFS0);
	SET_BIT(ADMUX,REFS1);
	#elif defined AREF_External_VREF
	SET_BIT(ADMUX,REFS0);
	CLEAR_BIT(ADMUX,REFS1);
	#endif

	#if defined ADC_Prescaler_2
		SET_BIT(ADCSRA,ADPS0);
	#elif defined ADC_Prescaler_4
		SET_BIT(ADCSRA,ADPS1);
	#elif defined ADC_Prescaler_8
		SET_BIT(ADCSRA,ADPS0);
		SET_BIT(ADCSRA,ADPS1);
	#elif defined ADC_Prescaler_16
		SET_BIT(ADCSRA,ADPS2);
	#elif defined ADC_Prescaler_32
		SET_BIT(ADCSRA,ADPS0);
		SET_BIT(ADCSRA,ADPS2);
	#elif defined ADC_Prescaler_64
		SET_BIT(ADCSRA,ADPS1);
		SET_BIT(ADCSRA,ADPS2);
	#elif defined ADC_Prescaler_128
		SET_BIT(ADCSRA,ADPS0);
		SET_BIT(ADCSRA,ADPS1);
		SET_BIT(ADCSRA,ADPS2);
	#endif
	switch (State)
		{
			case ADC_ENABLE:
				SET_BIT(ADCSRA,ADEN);
				break;
			case ADC_DISABLE:
				CLEAR_BIT(ADCSRA,ADEN);
				break;
			default:
				return E_OK;
		}
		return E_NOK;

}
/*****************************************************************************************************/
/**
 * @brief 
 * Prototype			 :	 	extern STD_Return ADC_SetInterrupt_Enable(ADC_Interrupt_State_t State);	
 * Description		 	 :		function to enable the ADC periphiral
 * 
 * @param State  	 	 :		State takes only ADC_Interrupt_Enable,ADC_Interrupt_DISABLE
 * @return STD_Return	 :		STD_Return for Error identification
 * 
 * 								return 0 mean Error is found , return 1 mean Error is not found
 */
STD_Return ADC_SetInterrupt_Enable(ADC_Interrupt_State_t State)
{
	switch (State)
	{
		case ADC_Interrupt_ENABLE:
			SET_BIT(ADCSRA,ADIE);
			break;
		case ADC_Interrupt_DISABLE:
			CLEAR_BIT(ADCSRA,ADIE);
			break;
		default:
			return E_OK;
	}
	return E_NOK;
}
/*****************************************************************************************************/
/**
 * @brief 
 * Prototype 			 :		extern STD_Return ADC_Start_conversion(u8 channel); 
 * Description			 : 		function to start the Analog to Digital conversion
 * 
 * @param channel  	 	 :		Takes the number of pin/ channel which is used in the conversion
 * @return STD_Return	 :		STD_Return for Error identification
 * 
 * 								return 0 mean Error is found , return 1 mean Error is not found
 **/
STD_Return ADC_Start_conversion(u8 channel)
{
	if (channel>MaxPinNum)
	{
		return E_OK;
	}
	else
	{

			//Mask for non used bits of the 8 bits of the Regsiter
			ADMUX &= Unselected_Channel_MASK;

			//Mask for the usage 3 bits of the 8 bits
			ADMUX |= channel;

			//Set the AdcStartConversion
			SET_BIT(ADCSRA,ADSC);
		while(GET_BIT(ADCSRA,ADSC) == 1);
		 //Wait conversion to finish
	}
	return E_NOK;
}
/*****************************************************************************************************/
/**
 * @brief
 * Prototype			 :		extern STD_Return ADC_Get_Value(u32 *AdcResult);		
 * Description 			 :		function to get the value 
 * 
 * @param AdcResult 	 :		Get the value in ADC data registers
 * @return STD_Return 	 :		STD_Return for Error identification
 * 
 * 								return 0 mean Error is found , return 1 mean Error is not found
 **/
STD_Return ADC_Get_Value(u16 *AdcResult)
{
		u16 AdcResult_Temp=0;
	#if defined Resolution_8_Bit
		*AdcResult=ADCH;
	#elif defined Resolution_10_Bit
		AdcResult_Temp= ADCL + (ADCH<<8); //Get the values of the two ADC registers
		*AdcResult = (AdcResult_Temp & Resolution_10Bit_MASK);//Mask higher bits in ADCH and read only the 10 bits for the ADC
	#endif
		return E_NOK;
}
/*****************************************************************************************************/
/**
 * @brief 
 * Prototype			 :		extern STD_Return ADC_Read_Value(u8 channel,u32 *AdcValue);		
 * Description 			 :		function Combine between the Conversion and GetValue Function in one function
 * 
 * @param channel 		 :		takes the number of pin/ channel which is used in the conversion
 * @param AdcValue 		 :		Get the value in ADC data registers
 * @return STD_Return 	 :		STD_Return for Error identification
 * 
 * 								return 0 mean Error is found , return 1 mean Error is not found
 **/
STD_Return ADC_Read_Value(u8 channel,u16 *AdcValue)
{
	u16 AdcValue_Temp=0;
	if (channel>MaxPinNum)
		{
			return E_OK;
		}
		else
		{
			 // combine between start conversion and get value

			while(GET_BIT(ADCSRA,ADSC) == 1)
			{
				//Mask for non used bits of the 8 bits of the Regsiter
				ADMUX &= Unselected_Channel_MASK;

				//Mask for the usage 3 bits of the 8 bits
				ADMUX |= channel;

				//Set the AdcStartConversion
				SET_BIT(ADCSRA,ADSC);
			} //looping until the the flag is set and conversion finished

			//return the read value

			#if defined Resolution_8_Bit
				*AdcValue=ADCH;
			#elif defined Resolution_10_Bit
				AdcValue_Temp= ADCL + (ADCH<<8); //Get the values of the two ADC registers
				*AdcValue = (AdcValue_Temp & Resolution_10Bit_MASK); //Mask higher bits in ADCH and read only the 10 bits for the ADC
			#endif
		}
	return E_NOK;
}
/*****************************************************************************************************/
/**
 * @brief 
 * Prototype			 :		extern STD_Return ADC_ReadVolt (u8 channel,f32 *AdcVolt);	
 * Description 			 :		function calculate the voltage value of the ADC value
 * 
 * @param channel 		 :		takes the number of pin/ channel which is used in the conversion
 * @param AdcVolt        : 		the value of the ADC conversion
 * @return STD_Return 	 :		STD_Return for Error identification
 * 
 * 								return 0 mean Error is found , return 1 mean Error is not found
 **/
STD_Return ADC_ReadVolt (u8 channel,f32 *AdcVolt)
	{
		u16 AdcValue_Temp=0;
		if(channel>MaxPinNum)
			{
				return E_OK;
			}
		else
			{
				ADC_Read_Value(channel,&AdcValue_Temp);
				*AdcVolt= (((f32)AdcValue_Temp)*((f32)VREF))/((f32)(ADC_MAX));
			}
		return E_NOK;
	}
/*****************************************************************************************************/
/**
 * @brief 
 * Prototype			 :		extern STD_Return ADC_ReadVolt (u8 channel,f32 *AdcVolt);	
 * Description 			 :		function calculate the voltage value of the ADC value
 * 
 * @param func_ptr 		 :		pointer to function that points to the user/ External function
 * @return void			 : 		return nothing
 **/
void ADC_CallBack(void (*func_ptr)(void))
	{
		User_Function = func_ptr;
	}
/*********************************ISR ADC Vector******************************************************/
ISR(ADC_Vect)
{
	(*User_Function)();
}
/*****************************************************************************************************/
