
#include "../MCAL/EXT_INT/Ext_Int.h"
#include "../MCAL/DIO/DIO_config.h"
#include "../MCAL/DIO/DIO_private.h"
#include "../MCAL/DIO/DIO_register.h"
#include "../MCAL/DIO/DIO_interface.h"

int main()
{
DIO_u8SetPinDirection(DIO_PORT_A,DIO_u8PIN1,DIO_u8PIN_OUTPUT);
DIO_u8SetPinValue(DIO_PORT_A,DIO_u8PIN1,DIO_u8PIN_LOW);


DIO_u8SetPinDirection(DIO_PORT_D,DIO_u8PIN2,DIO_u8PIN_INPUT);
DIO_u8SetPinValue(DIO_PORT_D,DIO_u8PIN2,DIO_u8PIN_HIGH);

EXT_INT_SENSE_CONTROL(GENERAL_INT0,INT_FALLING);
 GIE_INT_ENABLE( GLOBAL_INT_ENABLE );

 GENERAL_INT_CONTROL(GENERAL_INT0 ,GICR_ENABLE );










	while (1)
	{

	}


}
void __vector_1(void)__attribute__((signal));
void __vector_1(void)
{
	DIO_u8SetPinValue(DIO_PORT_A,DIO_u8PIN1,DIO_u8PIN_HIGH);

}
