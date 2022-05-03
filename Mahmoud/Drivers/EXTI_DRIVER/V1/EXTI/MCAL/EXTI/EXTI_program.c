/****************************************************/
/****************************************************/
/************  Author: Mahmoud Mohamed   ************/
/************  Layer: MCAL               ************/
/************  SWC: EXTI                 ************/
/************  Version: 1.00             ************/
/************  Date:29-4-2022            ************/
/****************************************************/
/****************************************************/

#include"../../SERVICE/STD_Types.h"
#include"../../SERVICE/BIT_Math.h"

#include"EXTI_interface.h"
#include"EXTI_private.h"
#include"EXTI_register.h"
#include"EXTI_config.h"

/*****************INT0**********************/

u8 EXTI_u8Int0Init(u8 ExtInt_SenseControl)
{
	u8 Local_u8ErrorState=0;

	/*Peripheral interupt enable for INT0 "Specific"*/
	SET_BIT(GICR,GICR_INT0);

	switch (ExtInt_SenseControl)
	{
	/*Set Sense Control for INT0 to falling edge*/
	case EXTI_FALLING_EDGE :
		SET_BIT(MCUCR,MCUCR_ISC01);
		CLR_BIT(MCUCR,MCUCR_ISC00);
		break ;

		/*Set Sense Control for INT0 to rising edge*/
	case EXTI_RISING_EDGE:
		SET_BIT(MCUCR,MCUCR_ISC00);
		SET_BIT(MCUCR,MCUCR_ISC01);
		break;

		/*other options return error*/
	default:
		Local_u8ErrorState=1;
		break;
	}
	return Local_u8ErrorState;
}

/*****************INT1**********************/

u8 EXTI_u8Int1Init(u8 ExtInt_SenseControl)
{
	u8 Local_u8ErrorState=0;

	/*Peripheral interupt enable for INT1 "Specific"*/
	SET_BIT(GICR,GICR_INT1);

	switch (ExtInt_SenseControl)
	{
	/*Set Sense Control for INT1 to falling edge*/
	case EXTI_FALLING_EDGE :
		SET_BIT(MCUCR,MCUCR_ISC11);
		CLR_BIT(MCUCR,MCUCR_ISC10);
		break ;

		/*Set Sense Control for INT1 to rising edge*/
	case EXTI_RISING_EDGE:
		SET_BIT(MCUCR,MCUCR_ISC10);
		SET_BIT(MCUCR,MCUCR_ISC11);
		break;

		/*other options return error*/
	default:
		Local_u8ErrorState=1;
		break;
	}
	return Local_u8ErrorState;
}

/*****************INT2**********************/

u8 EXTI_u8Int2Init(u8 ExtInt_SenseControl)
{
	u8 Local_u8ErrorState=0;

	/*Peripheral interupt enable for INT2 "Specific"*/
	SET_BIT(GICR,GICR_INT2);

	switch (ExtInt_SenseControl)
	{
	/*Set Sense Control for INT2 to falling edge*/
	case EXTI_FALLING_EDGE :
		CLR_BIT(MCUSCR,MCUSCR_ISC2);
		break ;

	/*Set Sense Control for INT2 to rising edge*/
	case EXTI_RISING_EDGE:
		SET_BIT(MCUSCR,MCUSCR_ISC2);
		break;

	/*other options return error*/
	default:
		Local_u8ErrorState=1;
		break;
	}
	return Local_u8ErrorState;
}


