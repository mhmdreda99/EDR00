/*******************************************************************************************/
/*******************************************************************************************/
/****************************    Auther  : Mostafa Mahmoud      ****************************/
/****************************    Layer   : MCAL                 ****************************/
/****************************    SWC     : ADC                  ****************************/
/****************************    Version : 1.00                 ****************************/
/*******************************************************************************************/
/*******************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "ADC_interface.h"
#include "ADC_private.h"
#include "ADC_config.h"
#include "ADC_register.h"

static u16* ADC_pu8Reading=NULL;
static void (*ADC_pvCallBackNotificationFunc)(void)=NULL;
#if(Resolution==1)
static u16 adcVal;
#endif

u8 ADC_u8BusyState=0;

void ADC_voidInit(void)
{
	/*AVCC as reference voltage*/
#if(VREF==0)
	CLR_BIT(ADMUX,ADMUX_REFS0);
	CLR_BIT(ADMUX,ADMUX_REFS1);
#elif(VREF==1)
	SET_BIT(ADMUX,ADMUX_REFS0);
	CLR_BIT(ADMUX,ADMUX_REFS1);
#elif(VREF==2)
	SET_BIT(ADMUX,ADMUX_REFS0);
	SET_BIT(ADMUX,ADMUX_REFS1);
#endif

	/*Activate Left adjust result*/
#if(Resolution==0)
	SET_BIT(ADMUX,ADMUX_ADLAR);
#endif

	/*Set Prescaler to division */
#if(PS==0)
	CLR_BIT(ADCSRA,ADCSRA_ADPS2);
	CLR_BIT(ADCSRA,ADCSRA_ADPS1);
	CLR_BIT(ADCSRA,ADCSRA_ADPS0);
#elif(PS==1)
	CLR_BIT(ADCSRA,ADCSRA_ADPS2);
	SET_BIT(ADCSRA,ADCSRA_ADPS1);
	CLR_BIT(ADCSRA,ADCSRA_ADPS0);
#elif(PS==2)
	CLR_BIT(ADCSRA,ADCSRA_ADPS2);
	SET_BIT(ADCSRA,ADCSRA_ADPS1);
	SET_BIT(ADCSRA,ADCSRA_ADPS0);
#elif(PS==3)
	SET_BIT(ADCSRA,ADCSRA_ADPS2);
	CLR_BIT(ADCSRA,ADCSRA_ADPS1);
	CLR_BIT(ADCSRA,ADCSRA_ADPS0);
#elif(PS==4)
	SET_BIT(ADCSRA,ADCSRA_ADPS2);
	CLR_BIT(ADCSRA,ADCSRA_ADPS1);
	SET_BIT(ADCSRA,ADCSRA_ADPS0);
#elif(PS==5)
	SET_BIT(ADCSRA,ADCSRA_ADPS2);
	SET_BIT(ADCSRA,ADCSRA_ADPS1);
	CLR_BIT(ADCSRA,ADCSRA_ADPS0);
#elif(PS==6)
	SET_BIT(ADCSRA,ADCSRA_ADPS2);
	SET_BIT(ADCSRA,ADCSRA_ADPS1);
	SET_BIT(ADCSRA,ADCSRA_ADPS0);
#endif
	/*Enable peripheral */
	SET_BIT(ADCSRA,ADCSRA_ADEN);
}

u8 ADC_u8StartConversionSynch(u8 Copy_u8Channel,u16*Copy_pu8Reading)
{
	u32 Local_u32Counter=0;
	u8 Local_u8ErrorState=0;
	if(ADC_u8BusyState==0)
	{
		/*ADC is now busy*/
		ADC_u8BusyState=1;

		/*Clear the MUX bits in ADMUX register*/
		ADMUX &= MUXMask;

		/*Set the required channel into the MUX bits*/
		ADMUX |= Copy_u8Channel;

		/*Start conversion*/
		SET_BIT(ADCSRA,ADCSRA_ADSC);

		/*Polling (busy waiting) until the conversion complete flag is set or counter reaching timeout value*/
		while( ((GET_BIT(ADCSRA,ADCSRA_ADIF))==0) && (Local_u32Counter<ADC_u32TIMEOUT) )
		{
			Local_u32Counter++;
		}
		if(Local_u32Counter==ADC_u32TIMEOUT)
		{
			/*Loop is broken because the timeout is reached*/
			Local_u8ErrorState=1;
		}
		else
		{
			/*Loop is broken because flag is raised*/

			/*Clear the conversion clear flag*/
			SET_BIT(ADCSRA,ADCSRA_ADIF);
#if(Resolution==0)
			/*Return the reading*/
			*Copy_pu8Reading=ADCH;
#elif(Resolution==1)
			adcVal=0;
			adcVal = ADCL + (ADCH << 8); //Get the values of the two ADC registers
			*Copy_pu8Reading = (adcVal & _10_BIT_MASK); //Mask higher bits in ADCH and read only the 10 bits for the ADC
#endif
			/*ADC is finished, return it to idle */
			ADC_u8BusyState=0;
		}

	}
	else
	{
		Local_u8ErrorState=1;
	}
	return Local_u8ErrorState;
}

u8 ADC_u8StartConversionAsynch(u8 Copy_u8Channel,u16*Copy_pu8Reading,void(*Copy_pvNotificationFunc)(void))
{
	u8 Local_u8ErrorState=0;
	if(ADC_u8BusyState==0)
	{
		if(Copy_pu8Reading == NULL || Copy_pvNotificationFunc == NULL)
		{
			Local_u8ErrorState=1;
		}
		else
		{
			/*Make ADC busy in order not to work until being idle 0*/
			ADC_u8BusyState=1;

			/*Initialize the reading variable globally*/
			ADC_pu8Reading=Copy_pu8Reading;

			/*Initialize the callback notification function globally*/
			ADC_pvCallBackNotificationFunc=Copy_pvNotificationFunc;

			/*Clear the MUX bits in ADMUX register*/
			ADMUX &= MUXMask;

			/*Set the required channel into the MUX bits*/
			ADMUX |= Copy_u8Channel;

			/*Start conversion*/
			SET_BIT(ADCSRA,ADCSRA_ADSC);

			/*ADC interrupt enable */
			SET_BIT(ADCSRA,ADCSRA_ADIE);

		}

	}
	else
	{
		Local_u8ErrorState=1;
	}
	return Local_u8ErrorState;
}


void ADC_u8ReadInput(u16*Copy_pu8Reading)
{
#if(Resolution==0)
			/*Return the reading*/
			*Copy_pu8Reading=ADCH;
#elif(Resolution==1)
			adcVal=0;
			adcVal = ADCL + (ADCH << 8); //Get the values of the two ADC registers
			*Copy_pu8Reading = (adcVal & _10_BIT_MASK); //Mask higher bits in ADCH and read only the 10 bits for the ADC
#endif

}


ISR(__vector_16)
{
#if(Resolution==0)
	/*Read ADC result*/
	*ADC_pu8Reading=ADCH;
#elif(Resolution==1)
	adcVal=0;
	adcVal = ADCL + (ADCH << 8); //Get the values of the two ADC registers
	*ADC_pu8Reading = (adcVal & _10_BIT_MASK); //Mask higher bits in ADCH and read only the 10 bits for the ADC
#endif
	/*Make ADC state be idle (0) because it finished */
	ADC_u8BusyState=0;

	/*Invoke the callback notification function*/
	(*ADC_pvCallBackNotificationFunc)();

	/*Disable ADC conversion complete interrupt*/
	CLR_BIT(ADCSRA,ADCSRA_ADIE);
}
