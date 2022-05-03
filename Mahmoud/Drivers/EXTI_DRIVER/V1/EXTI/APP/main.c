#include"../SERVICE/STD_TYPES.h"
#include"../SERVICE/BIT_Math.h"

#include"../SERVICE/GIE/GIE_interface.h"

#include "../MCAL/DIO/DIO_interface.h"
#include "../MCAL/EXTI/EXTI_interface.h"

void main (void)
{
	DIO_u8SetPinDirection(DIO_PORT_D,DIO_u8PIN2,DIO_u8PIN_INPUT);

	DIO_u8SetPinValue(DIO_PORT_D,DIO_u8PIN2,DIO_u8PIN_HIGH);


	DIO_u8SetPinDirection(DIO_PORT_A,DIO_u8PIN0,DIO_u8PIN_OUTPUT);

	EXTI_u8Int0Init(EXTI_FALLING_EDGE);//set sense control falling edge & set prephiral
	GIE_voidEnable();//open global

	while (1)
	{

	}

}
void __vector_1(void) __attribute__((signal));
void __vector_1(void)
{
	DIO_u8SetPinValue(DIO_PORT_A,DIO_u8PIN0,DIO_u8PIN_HIGH);


}
