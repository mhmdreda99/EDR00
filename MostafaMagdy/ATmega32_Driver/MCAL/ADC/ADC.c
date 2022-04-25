/*
 * ADC.c
 *
 *  Created on: Apr 25, 2022
 *      Author: Seko
 */
#include "ADC.h"

//Userr External Function
static void (*User_Function)(void);
//voltage Reference selection
#if defined	AREF_Internal_VREF
#define VREF	2.56
#elif defined AREF_External_VREF
#define VREF 5
#endif

//Bit Resoltion Selection
#if defined Resolution_8_Bit
#define ADC_MAX 256
#elif defined Resolution_10_Bit
#define ADC_MAX 1024
#endif

void ADC_Init(void)
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

}
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

		while((GET_BIT(ADCSRA,ADIF))==1); //looping until the the flag is set and conversion finished
	}
	return E_NOK;
}
STD_Return ADC_Get_Value(u32 *AdcResult)
{
		u16 AdcResult_Temp=0;
	#if defined Resolution_8_Bit
		*AdcResult=ADCH;
	#elif defined Resolution_10_Bit
		AdcResult_Temp= ADCL + (ADCH<<8);
		*AdcResult = (AdcResult_Temp & Resolution_10Bit_MASK);
	#endif
		return E_NOK;
}
STD_Return ADC_Read_Value(u8 channel,u32 *AdcValue)
{
	if (channel>MaxPinNum)
		{
			return E_OK;
		}
		else
		{
			 // combine between start conversion and get value

			u16 AdcValue_Temp=0;

			//Mask for non used bits of the 8 bits of the Regsiter
			ADMUX &= Unselected_Channel_MASK;

			//Mask for the usage 3 bits of the 8 bits
			ADMUX |= channel;

			//Set the AdcStartConversion
			SET_BIT(ADCSRA,ADSC);

			while((GET_BIT(ADCSRA,ADIF))==1); //looping until the the flag is set and conversion finished

			#if defined Resolution_8_Bit
				*AdcValue=ADCH;
			#elif defined Resolution_10_Bit
				AdcValue_Temp= ADCL + (ADCH<<8);
				*AdcValue = (AdcValue_Temp & Resolution_10Bit_MASK);
			#endif
		}
	return E_NOK;
}
STD_Return ADC_ReadVolt (u8 channel,f32 *AdcVolt)
	{
		u32 AdcValue_Temp=0;
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
void ADC_CallBack(void (*func_ptr)(void))
	{
		User_Function = func_ptr;
	}
ISR(ADC_Vect)
{
	(*User_Function)();
}
