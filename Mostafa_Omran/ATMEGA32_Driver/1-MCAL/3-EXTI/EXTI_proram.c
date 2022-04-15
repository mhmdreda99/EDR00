/*******************************************************************************************/
/*******************************************************************************************/
/****************************    Author  : Mostafa Mahmoud      ****************************/
/****************************    Layer   : MCAL                 ****************************/
/****************************    SWC     : EXTI                 ****************************/
/****************************    Version : 1.00                 ****************************/
/*******************************************************************************************/
/*******************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "EXTI_register.h"
#include "EXTI_interface.h"







//Data section
static void(*User_Func0)(void);
static void(*User_Func1)(void);
static void(*User_Func2)(void);

//ISR for external interrupt 0
ISR(INT0_vect)
{ 
	(*User_Func0)();
}

//ISR for external interrupt 1
ISR(INT1_vect) 
{
	(*User_Func1)();
}
//ISR for external interrupt 2
ISR( INT2_vect)
{
	(*User_Func2)();
}

// initializaing the External Interrupt 0
u8 EXTI_u8Int0Init(u8 ExtInt_SenseControl)
{
    u8 Local_u8ErrorState=0;

    //Enable external interrupt 0
    SET_BIT(GICR,GICR_INT0);

    switch(ExtInt_SenseControl)
    {
        case EXTI_FALLING_EDGE:
            SET_BIT(MCUCR,MCUCR_ISC01);
            CLR_BIT(MCUCR,MCUCR_ISC00);
            break;
        case EXTI_RISING_EDGE:
            SET_BIT(MCUCR,MCUCR_ISC00);
            SET_BIT(MCUCR,MCUCR_ISC01);
            break;
        default:
            Local_u8ErrorState=1;
            break;
    }
    return Local_u8ErrorState;
}

//set user function to be executed on ISR
void INT0_voidCallBack(void(*func_Ptr)(void))
{
    User_Func0=func_Ptr;
}

// initializaing the External Interrupt 1
u8 EXTI_u8Int1Init(u8 ExtInt_SenseControl)
{
    u8 Local_u8ErrorState=0;

    //Enable external interrupt 1
    SET_BIT(GICR,GICR_INT1);

    switch(ExtInt_SenseControl)
    {
        case EXTI_FALLING_EDGE:
            SET_BIT(MCUCR,MCUCR_ISC11);
            CLR_BIT(MCUCR,MCUCR_ISC10);
            break;
        case EXTI_RISING_EDGE:
            SET_BIT(MCUCR,MCUCR_ISC10);
            SET_BIT(MCUCR,MCUCR_ISC11);
            break;
        default:
            Local_u8ErrorState=1;
            break;
    }
    return Local_u8ErrorState;
}

//set user function to be executed on ISR
void INT1_voidCallBack(void(*func_Ptr)(void))
{
    User_Func1=func_Ptr;
}

// initializaing the External Interrupt 2
u8 EXTI_u8Int2Init(u8 ExtInt_SenseControl)
{
    u8 Local_u8ErrorState=0;

    //Enable external interrupt 2
    SET_BIT(GICR,GICR_INT2);

    switch(ExtInt_SenseControl)
    {
        case EXTI_FALLING_EDGE:
            CLR_BIT(MCUSCR,MCUSCR_ISC2);
            break;
        case EXTI_RISING_EDGE:
            SET_BIT(MCUSCR,MCUSCR_ISC2);
            break;
        default:
            Local_u8ErrorState=1;
            break;
    }
    return Local_u8ErrorState;
}

//set user function to be executed on ISR
void INT2_voidCallBack(void(*func_Ptr)(void))
{
    User_Func2=func_Ptr;
}


