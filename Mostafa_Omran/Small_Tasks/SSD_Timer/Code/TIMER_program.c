/*******************************************************************************************/
/*******************************************************************************************/
/****************************    Auther  : Mostafa Mahmoud      ****************************/
/****************************    Layer   : MCAL                 ****************************/
/****************************    SWC     : TIMER                ****************************/
/****************************    Version : 1.00                 ****************************/
/*******************************************************************************************/
/*******************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "TIMER_interface.h"
#include "TIMER_register.h"
#include "TIMER_private.h"
#include "TIMER_config.h"

static void (*TIMER0_pvCallBackFunc)(void)=NULL;

void TIMER0_voidInit(void)
{
	/*Choose CTC mode*/
	CLR_BIT(TCCR0,TCCR0_WGM00);
	SET_BIT(TCCR0,TCCR0_WGM01);

	/*output compare match interrupt  enable */
	SET_BIT(TIMSK,TIMSK_OCIE0);

	/*Set compare match value to 255*/
	OCR0=250;

	/*Prescaler: Division by 8*/
	CLR_BIT(TCCR0,TCCR0_CS00);
	SET_BIT(TCCR0,TCCR0_CS01);
	CLR_BIT(TCCR0,TCCR0_CS02);

}

u8 TIMER0_u8SetCallBack(void (*Copy_pvCallBackFunc)(void))
{
    u8 Local_u8ErrorStatus=0;
    if(Copy_pvCallBackFunc != NULL)
    {
    	TIMER0_pvCallBackFunc=Copy_pvCallBackFunc;
    }
    else
    {
    	Local_u8ErrorStatus=2;
    }
    return Local_u8ErrorStatus;
}

void(__vector_10)(void) __attribute__((signal));
void(__vector_10)(void)
{
	if(TIMER0_pvCallBackFunc != NULL)
	{
		TIMER0_pvCallBackFunc();
	}
}
