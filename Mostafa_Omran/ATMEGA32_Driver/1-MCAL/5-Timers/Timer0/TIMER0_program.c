/*******************************************************************************************/
/*******************************************************************************************/
/****************************    Auther  : Mostafa Mahmoud      ****************************/
/****************************    Layer   : MCAL                 ****************************/
/****************************    SWC     : TIMER0               ****************************/
/****************************    Version : 1.00                 ****************************/
/*******************************************************************************************/
/*******************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "TIMER0_interface.h"
#include "TIMER0_register.h"
#include "TIMER0_private.h"
#include "TIMER0_config.h"

static void (*TIMER0_pvCallBackFuncOVF)(void)=NULL;

static void (*TIMER0_pvCallBackFuncCTC)(void)=NULL;

void TIMER0_voidInit(u8 Copy_u8Mode,u8 Copy_u8Prescale)
{
	switch (Copy_u8Mode)
	{
	case NormalMode:

		/*Select Normal Mode*/
		CLR_BIT(TCCR0,TCCR0_WGM00);
		CLR_BIT(TCCR0,TCCR0_WGM01);
		break;

	case PhaseCorrect_PWM_NonInverted:

		/*Select Phase Correct PWM Mode*/
		SET_BIT(TCCR0,TCCR0_WGM00);
		CLR_BIT(TCCR0,TCCR0_WGM01);

		/*Select Compare Match NonInverted Mode ( Clear on compare match when up-counting.Set on compare
					match when down-counting)*/
		SET_BIT(TCCR0,TCCR0_COM01);
		CLR_BIT(TCCR0,TCCR0_COM00);
		break;

	case PhaseCorrect_PWM_Inverted:

		/*Select Phase Correct PWM Mode*/
		SET_BIT(TCCR0,TCCR0_WGM00);
		CLR_BIT(TCCR0,TCCR0_WGM01);

		/*Select Compare Match Inverted Mode ( Set on compare match when up-counting.Clear on compare
					match when down-counting)*/
		SET_BIT(TCCR0,TCCR0_COM01);
		SET_BIT(TCCR0,TCCR0_COM00);
		break;

	case CTC_TogglePin:

		/*Select CTC Mode*/
		SET_BIT(TCCR0,TCCR0_WGM01);
		CLR_BIT(TCCR0,TCCR0_WGM00);

		/*Toggle OC0 on compare match */
		CLR_BIT(TCCR0,TCCR0_COM01);
		SET_BIT(TCCR0,TCCR0_COM00);
		break;

	case CTC_ClearPin:

		/*Select CTC Mode*/
		SET_BIT(TCCR0,TCCR0_WGM01);
		CLR_BIT(TCCR0,TCCR0_WGM00);

		/*Clear OC0 on compare match */
		SET_BIT(TCCR0,TCCR0_COM01);
		CLR_BIT(TCCR0,TCCR0_COM00);
		break;

	case CTC_SetPin:

		/*Select CTC Mode*/
		SET_BIT(TCCR0,TCCR0_WGM01);
		CLR_BIT(TCCR0,TCCR0_WGM00);

		/*Set OC0 on compare match */
		SET_BIT(TCCR0,TCCR0_COM01);
		SET_BIT(TCCR0,TCCR0_COM00);
		break;

	case CTC_DisconnectedPin:

		/*Select CTC Mode*/
		SET_BIT(TCCR0,TCCR0_WGM01);
		CLR_BIT(TCCR0,TCCR0_WGM00);

		/*DisconnectedPin OC0 on compare match */
		CLR_BIT(TCCR0,TCCR0_COM01);
		CLR_BIT(TCCR0,TCCR0_COM00);
		break;

	case Fast_PWM_NonInverted:

		/*Select Fast PWM Mode*/
		SET_BIT(TCCR0,TCCR0_WGM00);
		SET_BIT(TCCR0,TCCR0_WGM01);

		/*Select Compare Match NonInverted Mode (Clear on compare match, Set at TOP)*/
		SET_BIT(TCCR0,TCCR0_COM01);
		CLR_BIT(TCCR0,TCCR0_COM00);
		break;

	case Fast_PWM_Inverted:

		/*Select Fast PWM Mode*/
		SET_BIT(TCCR0,TCCR0_WGM00);
		SET_BIT(TCCR0,TCCR0_WGM01);

		/*Select Compare Match NonInverted Mode (Set on compare match, Clear at TOP)*/
		SET_BIT(TCCR0,TCCR0_COM01);
		SET_BIT(TCCR0,TCCR0_COM00);
		break;

	}

	switch (Copy_u8Prescale)
	{
	case NoDivsion:
		CLR_BIT(TCCR0,TCCR0_CS02);
		CLR_BIT(TCCR0,TCCR0_CS01);
		SET_BIT(TCCR0,TCCR0_CS00);
		break;
	case DivsionBy8:
		CLR_BIT(TCCR0,TCCR0_CS02);
		SET_BIT(TCCR0,TCCR0_CS01);
		CLR_BIT(TCCR0,TCCR0_CS00);
		break;
	case DivsionBy64:
		CLR_BIT(TCCR0,TCCR0_CS02);
		SET_BIT(TCCR0,TCCR0_CS01);
		SET_BIT(TCCR0,TCCR0_CS00);
		break;
	case DivsionBy256:
		SET_BIT(TCCR0,TCCR0_CS02);
		CLR_BIT(TCCR0,TCCR0_CS01);
		CLR_BIT(TCCR0,TCCR0_CS00);
		break;
	case DivsionBy1024:
		SET_BIT(TCCR0,TCCR0_CS02);
		CLR_BIT(TCCR0,TCCR0_CS01);
		SET_BIT(TCCR0,TCCR0_CS00);
		break;
	}

}

void TIMER0_voidSetComareMatchValue(u8 Copy_u8Value)
{
	OCR0=Copy_u8Value;
}

u8 TIMER0_u8SetCallBack(void (*Copy_pvCallBackFunc)(void),u8 Copy_u8InterruptType)
{
	u8 Local_u8ErrorStatus=0;
	if(Copy_pvCallBackFunc != NULL)
	{
		switch(Copy_u8InterruptType)
		{
		case CTCInterrupt:
			TIMER0_pvCallBackFuncCTC=Copy_pvCallBackFunc;
			break;
		case OVFInterrupt:
			TIMER0_pvCallBackFuncOVF=Copy_pvCallBackFunc;
			break;
		}
	}
	else
	{
		Local_u8ErrorStatus=2;
	}
	return Local_u8ErrorStatus;
}

void TIMER0_voidInterruptEnable(u8 Copy_u8InterruptType)
{
	switch(Copy_u8InterruptType)
	{
	case CTCInterrupt:
		SET_BIT(TIMSK,TIMSK_OCIE0);
		break;
	case OVFInterrupt:
		SET_BIT(TIMSK,TIMSK_TOIE0);
		break;
	}
}

ISR(TIMER0_CTC)
{
	if(TIMER0_pvCallBackFuncCTC != NULL)
	{
		TIMER0_pvCallBackFuncCTC();
	}
}

ISR(TIMER0_OVF)
{
	if(TIMER0_pvCallBackFuncOVF != NULL)
	{
		TIMER0_pvCallBackFuncOVF();
	}
}
