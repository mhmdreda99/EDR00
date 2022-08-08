/*******************************************************************************************/
/*******************************************************************************************/
/****************************    Auther  : Mostafa Mahmoud      ****************************/
/****************************    Layer   : MCAL                 ****************************/
/****************************    SWC     : USART                ****************************/
/****************************    Version : 1.00                 ****************************/
/*******************************************************************************************/
/*******************************************************************************************/

#ifndef USART_REGISTER_H_
#define USART_REGISTER_H_

#define UDR 			    *((volatile u8*)0x2C)       /*USART I/O Data Register*/

#define UCSRA 			    *((volatile u8*)0x2B)       /*USART Control and Status Register A*/
#define UCSRA_RXC			7
#define UCSRA_TXC			6
#define UCSRA_UDRE			5
#define UCSRA_U2X			1



#define UCSRB 			    *((volatile u8*)0x2A)       /*USART Control and Status Register B*/
#define UCSRB_RXCIE			7							/*RX Complete Interrupt Enable*/
#define UCSRB_TXCIE			6							/*TX Complete Interrupt Enable*/
#define UCSRB_UDRIE			5							/*USART Data Register Empty Interrupt Enable*/
#define UCSRB_RXEN			4							/*Receiver Enable*/
#define UCSRB_TXEN			3							/*Transmitter Enable*/
#define UCSRB_UCSZ2			2							/*Character Size bit 2*/
#define UCSRB_RXB8			1							/*Receive Data Bit 8 and the ninth data for received character*/
#define UCSRB_TXB8			0							/*Transmit Data Bit 8 and the ninth data for transmitted character*/




#define UBRRL 			    *((volatile u8*)0x29)       /*USART Baud Rate Register Low*/


#define UCSRC 			    *((volatile u8*)0x40)       /*USART Control and Status Register C*/
#define UCSRC_URSEL			7							/*Register Select between UBRRH and UCSRC*/
#define UCSRC_UMSEL			6							/*USART Mode Select between Asynchronous and Synchronous*/
#define UCSRC_UPM1			5							/*Parity Mode bit 1*/
#define UCSRC_UPM0			4							/*Parity Mode bit 0*/
#define UCSRC_USBS			3							/*Stop Bit Select*/
#define UCSRC_UCSZ1			2							/*Character Size bit 1*/
#define UCSRC_UCSZ0			1							/*Character Size bit 0*/
#define UCSRC_UCPOL			0							/*Clock Polarity*/


#define ISR(vector, ...) \
	void vector(void) __attribute__ ((signal)) __VA_ARGS__;\
	void vector(void)


/*USART VECTORS*/
#define USART_RXC_vect			__vector_13				/**/
#define USART_UDRE_vect			__vector_14				/*USART Data Register Empty ISR*/
#define USART_TXC_vect			__vector_15				/**/




#endif
