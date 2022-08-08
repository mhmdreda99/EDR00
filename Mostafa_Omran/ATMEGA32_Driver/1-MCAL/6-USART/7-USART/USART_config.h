/*******************************************************************************************/
/*******************************************************************************************/
/****************************    Auther  : Mostafa Mahmoud      ****************************/
/****************************    Layer   : MCAL                 ****************************/
/****************************    SWC     : USART                ****************************/
/****************************    Version : 1.00                 ****************************/
/*******************************************************************************************/
/*******************************************************************************************/

#ifndef USART_CONFIG_H_
#define USART_CONFIG_H_

#define USART_TIMEOUT	500000




/*Character Size*/
#define Eight_BitData
//#define Seven_BitData
//#define Six_BitData
//#define Five_BitData

/*Baud Rate*/
#define oscillatorFreq		8000000UL
#define BaudRate			9600UL

/*Parity Mode The default is disable*/
//#define Even_Parity
//#define Odd_Parity

/*Stop Bit Select The default is 1 bit */
//#define Stop_2Bit


#endif
