/*
 * dio.h
 *
 *  Created on: Apr 16, 2022
 *      Author: Raneem
 */

#ifndef MCAL_DIO_DIO_H_
#define MCAL_DIO_DIO_H_
#include "../../Service/StdMacros.h"
#include "../../Service/StdTypes.h"

void DIO_init(void);

//Max pin number in the port
#define MAX_PIN_NUMBER		7
#define NULL   0
#define Local_ ErrorState
//Data type for ports names
typedef enum{
	DIO_PORTA,		//Port A
	DIO_PORTB,		//Port B
	DIO_PORTC,		//Port C
	DIO_PORTD		//Port D
}DIO_PORT;

//Data type for pin direction
typedef enum{
DIO_OUTPUT,
DIO_INPUT
}DIO_PIN_TYPE;


//Define PINS
#define DIO unsigned char PIN0             0
#define DIO unsigned char PIN1             1
#define DIO unsigned char PIN2             2
#define DIO unsigned char PIN3             3
#define DIO unsigned char PIN4             4
#define DIO unsigned char PIN5             5
#define DIO unsigned char PIN6             6
#define DIO unsigned char PIN7             7

//Dio ports
#define PORTA    * ((volatile u8*) 0x3b)
#define DDRA   * ( (volatile u8*) 0x3a)
#define PINA   * ( (volatile u8*) 0x39)
#define PORTB  * ( (volatile u8*) 0x38)
#define DDRB   * ( (volatile u8*) 0x37)
#define PINB   * ( (volatile u8*) 0x36)
#define PORTC  * ( (volatile u8*) 0x35)
#define DDRC   * ((volatile u8*) 0x34)
#define PINC   * ((volatile u8*) 0x33)
#define PORTD  * ( (volatile u8*) 0x32)
#define DDRD   * ( (volatile u8*) 0x31)
#define PIND   * ( (volatile u8*) 0x30)

//Data type for pin state
typedef enum{
 DIO_HIGH,        //pin high
 DIO_LOW         //pin low

}DIO_PIN_STATE;

//Data type for PORT state
typedef enum{
 DIO_HIGH_PORT,        //PORT high
 DIO_LOW_PORT         //PORT low

}DIO_PORT_STATE;



StdReturn DIO_setPinDirection(DIO_port port, uint8 pin, DIO_pinType state);
StdReturn DIO_setPORTDirection(DIO_port port, DIO_pinType state);
StdReturn DIO_READValue(DIO_port port, uint8 pin, DIO_pinState *state);




#endif /* MCAL_DIO_DIO_H_ */
