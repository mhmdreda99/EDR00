#include "STD_TYPES.h"
#include "DIO_interface.h"

void main (void)

{
	//define A0 as output

		while(1)
		{
			DIO_u8SetPinDirection(DIO_u8PORTA,DIO_u8PIN5,DIO_u8PIN_OUTPUT);

			DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN5,DIO_u8PIN_HIGH);


		}
}
