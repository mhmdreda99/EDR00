/****************************************************/
/****************************************************/
/************  Author: Mahmoud Mohamed   ************/
/************  Layer: MCAL               ************/
/************  SWC: GIE                  ************/
/************  Version: 1.00             ************/
/************  Date:29-4-2022            ************/
/****************************************************/
/****************************************************/

#include"../STD_Types.h"
#include"../BIT_Math.h"

#include "GIE_interface.h"
#include "GIE_register.h"

void GIE_voidEnable(void)
{
	SET_BIT(SREG,SREG_I);
}

void GIE_voidDisable(void)
{
	CLR_BIT(SREG,SREG_I);


}
