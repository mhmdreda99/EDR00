/*
 ============================================================================
 Name        : GPIO.h
 Author      : Mostafa Magdy
 Layer		 : MCAL
 Target		 : ATMEGA16-32
 Version     : 1.0
 Date		 : 29/08/2021
 Copyright   : This is an open source code for all embedded systems students
 Description : Header file for GPIO Driver
 ============================================================================
 */

//guard file
#ifndef GPIO_H_
#define GPIO_H_

#include "../../Controller/ATMEGA32/Registers.h"
#include "../../Service/StdMacros.h"
#include "../../Service/StdTypes.h"

//Max pin number in the port
#define MAX_PIN_NUM		7

//Data types for ports names
typedef enum{
	GPIO_PORTA,		//Port A
	GPIO_PORTB,		//Port B
	GPIO_PORTC,		//Port C
	GPIO_PORTD		//Port D
}GPIO_port;

//Data types for Pin Direction (DDR)
typedef enum{
	GPIO_INPUT,		//pin is input
	GPIO_OUTPUT		// pin is output
}GPIO_pinType;

//Data type for pin state
typedef enum{
	GPIO_LOW,		// pin low state give 0 volt
	GPIO_HIGH		// pin high state give 5 volt
}GPIO_pinState;

//Data type for pull up resistor in pins
typedef enum{
	GPIO_PULLUP_DISABLE,	//pull up resistor disabled when set  bit
	GPIO_PULLUP_ENABLE		//pull up resistor enabled  when clear bit
}GPIO_pullupEnable;



void GPIO_init(void);


// state the pin is input or output
StdReturn GPIO_SetPinDirection(GPIO_port port, uint8 pin, GPIO_pinType state);

// Write on pin high(5V) or low(0V)
StdReturn GPIO_WritePin(GPIO_port port, uint8 pin, GPIO_pinState state);

// used to to toggle pin convert it from low to high or high to low
StdReturn GPIO_TogglePin(GPIO_port port, uint8 pin);

// Read from pin high(5V) or low(0V)
StdReturn GPIO_ReadPin(GPIO_port port, uint8 pin, GPIO_pinState *state);

// enable the internal pull up resistor
StdReturn GPIO_EnablePullup(GPIO_port port, uint8 pin, GPIO_pullupEnable state);


#endif
