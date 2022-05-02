/*
 * @file          DIO_register.h
 * @author        MostafaMagdy
 * @email         MostafaMagii7@gmail.com
 * @Git account:  https:github.com/MostafaMagdy99
 * @version       0.1
 * @date 		  2022-04-28
 * 
 * @copyright Copyright (c) 2022
 * 
 * Description :  Header file for the Atmega32 Register
 */

/*This is preprocessor Header file guard  */
#ifndef DIO_REGISTER_H_
#define DIO_REGISTER_H_

/******************************************PORTA**********************************************/
#define PORTA		*((volatile u8* const)0x3B)
#define DDRA		*((volatile u8* const)0x3A)
#define PINA		*((volatile u8* const)0x39)
/******************************************PORTB**********************************************/
#define PORTB		*((volatile u8* const)0x38)
#define DDRB		*((volatile u8* const)0x37)
#define PINB		*((volatile u8*const )0x36)
/******************************************PORTC**********************************************/
#define PORTC		*((volatile u8* const)0x35)
#define DDRC		*((volatile u8* const)0x34)
#define PINC		*((volatile u8* const)0x33)
/******************************************PORTD**********************************************/
#define PORTD		*((volatile u8* const)0x32)
#define DDRD		*((volatile u8* const)0x31)
#define PIND		*((volatile u8* const)0x30)

/***************************************Status Register****************************************/
#define SREG		*((volatile u8* const)0x5F)
/* Global_interrupt_Enable Pin (I_BIT) */
#define GIE				7 						
/********************************External interrupt Register***********************************/
#define GICR		*((volatile u8* const)0x5B)
#define INT0			6
#define INT1			7
#define INT2			5
/******************************External interrupt Flag Register********************************/
#define GIFR		*((volatile u8* const)0x5A)
#define INTF0			6
#define INTF1			7
#define INTF2			5
/***********************************Sense Control Registers*************************************/
#define MCUCR		*((volatile u8* const)0x55)
#define ISC00			0
#define ISC01			1
#define ISC10			2
#define ISC11			3

#define MCUCSR		*((volatile u8* const)0x54)
#define ISC2			6
/******************************************ADC Registers*****************************************/
#define ADMUX	(*((volatile unsigned char* const)(0x27)))
#define REFS1	7		//ADC select reference
#define REFS0	6		//ADC select reference
#define ADLAR	5       
#define MUX4	4
#define MUX3	3
#define MUX2	2
#define MUX1	1
#define MUX0	0

#define ADCSRA	(*((volatile unsigned char* const)(0x26)))
#define ADEN	7		//Enable ADC
#define ADSC	6		//Start_ADC_Conversion_Enable
#define ADATE	5		//AutoTrigger_Enable
#define ADIF	4		//ADC interrupt flag
#define ADIE	3		//ADC interrupt enable
#define ADPS2	2
#define ADPS1	1
#define ADPS0	0

#define ADCH	(*((volatile unsigned char* const)(0x25)))		//ADC data register high
#define ADCL	(*((volatile unsigned char* const)(0x24)))		//ADC data register low
/**************************************Special function I/O Register************************************/
#define SFIOR	(*((volatile u8* const)(0x50)))
#define PUD				2						//Pull up disable bit in SFIOR
/*******************************************************************************************************/
/*This is preprocessor Header file guard End  */
#endif /* DIO_REGISTER_H_ */
