/*
 * Ext_Int.c
 *
 *  Created on: 28 Apr 2022
 *      Author: Mahmoud
 */


#include "Ext_Int.h"
static void (*INT0_Func_Address)(void) =0;

static void (*INT1_Func_Address)(void) =0;

static void (*INT2_Func_Address) (void)=0;



StdReturn GIE_INT_ENABLE( GLOBAL_INT_ENABLE_t state )
{
	switch (state)
	{
	case  GLOBAL_INT_DISABLE :
	{
		CLR_BIT(SREG,GIE);
	}
	break;
	case  GLOBAL_INT_ENABLE :
	{
		SET_BIT(SREG,GIE);
	}
	break;
	}
}
StdReturn GENERAL_INT_CONTROL(GENERAL_INT_CONTROL_t control,GICR_ENABLE_t enable)
{
	switch (control)
	{
	case GENERAL_INT0 :
	{
		switch (enable)
		{
		case GICR_DISABLE :
		{
			CLR_BIT(GICR,INT0);
		}
		break;
		case GICR_ENABLE :
		{
			SET_BIT(GICR,INT0);
		}
		break;

		}
	}
	break;
	//int1
	case GENERAL_INT1 :
	{
		switch (enable)
		{
		case GICR_DISABLE :
		{
			CLR_BIT(GICR,INT1);
		}
		break;
		case GICR_ENABLE :
		{
			SET_BIT(GICR,INT1);
		}
		break;

		}
	}
	break;
	//int2
	case GENERAL_INT2 :
	{
		switch (enable)
		{
		case GICR_DISABLE :
		{
			CLR_BIT(GICR,INT2);
		}
		break;
		case GICR_ENABLE :
		{
			SET_BIT(GICR,INT2);
		}
		break;

		}

	}
	break;
	}


}
/*******************************************************************************************/
StdReturn EXT_INT_SENSE_CONTROL (GENERAL_INT_CONTROL_t INT, EXT_INT_SENSE_CONTROL_t sense)

{
	switch (INT)
	{
	//int0
	case GENERAL_INT0 :
	{
		switch (sense)
		{
		case INT_RISING :
		{
			SET_BIT(MCUCR,ISC00);
			SET_BIT(MCUCR,ISC01);
		}break;

		case INT_FALLING :
		{
			CLR_BIT(MCUCR,ISC00);
			SET_BIT(MCUCR,ISC01);
		}break;

		}
	}break;

	//int1
	case GENERAL_INT1 :
	{
		switch (sense)
		{
		case INT_RISING :
		{
			SET_BIT(MCUCR,ISC10);
			SET_BIT(MCUCR,ISC11);
		}break;

		case INT_FALLING :
		{
			CLR_BIT(MCUCR,ISC10);
			SET_BIT(MCUCR,ISC11);
		}break;

		}
	}break;

	//int2
	case GENERAL_INT2 :
	{
		switch (sense)
		{
		case INT_RISING :
		{
			SET_BIT(MCUCSR,ISC2);

		}break;

		case INT_FALLING :
		{
			CLR_BIT(MCUCSR,ISC2);

		}break;

		}
	}break;



	}

}
/*******************************************************************************************/

StdReturn EXT_INT_CLEAR_FLAG (GENERAL_INT_CONTROL_t INT)
{
	switch (INT)
	{
	case GENERAL_INT0 :
	{
		SET_BIT(GIFR,INTF0);
	}break;

	case GENERAL_INT1 :
	{
		SET_BIT(GIFR,INTF1);
	}break;
	case GENERAL_INT2 :
	{
		SET_BIT(GIFR,INTF2);
	}break;
	}
}
/*******************************************************************************************/
//callback int0
StdReturn INT0_Callback_Function(void(*Fptr0)(void))
{
	INT0_Func_Address=&Fptr0;

}
/*void __vector_1(void)__attribute__((signal));
void __vector_1(void)
{
	INT0_Func_Address();
}*/
/*******************************************************************************************/
//callback int 1

StdReturn INT1_Callback_Function(void(*Fptr1)(void))
{
	INT1_Func_Address=&Fptr1;

}
void __vector_2(void)__attribute__((signal));
void __vector_2(void)
{
	INT1_Func_Address();
}
/*******************************************************************************************/
//callback int 2

StdReturn INT2_Callback_Function(void(*Fptr2)(void))
{
	INT2_Func_Address=&Fptr2;

}
void __vector_3(void)__attribute__((signal));
void __vector_3(void)
{
	INT2_Func_Address();
}






