/*******************************************************************************************/
/*******************************************************************************************/
/****************************    Auther  : Mostafa Mahmoud      ****************************/
/****************************    Layer   : MCAL                 ****************************/
/****************************    SWC     : USART                ****************************/
/****************************    Version : 1.00                 ****************************/
/*******************************************************************************************/
/*******************************************************************************************/

#ifndef USART_INTERFACE_H_
#define USART_INTERFACE_H_

void USART_voidInit(void);
u8 USART_u8SendCharSynch(u8 Copy_u8Data);
u8 USART_u8ReceiveCharSynch(char *Copy_u8Data);


void USART_voidSendStringSynch(char*String);
void USART_voidReceiveBufferSynch(char *Buffer,u8 BufferSize);

void USART_voidSendCharAsynch(u8 Copy_u8Data,void(*Copy_pvNotificationFunc)(void));
void USART_voidReceiveCharAsynch(u8 *Copy_u8Data,void(*Copy_pvNotificationFunc)(void));



#endif
