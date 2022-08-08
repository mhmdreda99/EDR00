 		/*******************************************************************************************/
/*******************************************************************************************/
/****************************    Auther  : Mostafa Mahmoud      ****************************/
/****************************    Layer   : MCAL                 ****************************/
/****************************    SWC     : USART                ****************************/
/****************************    Version : 1.00                 ****************************/
/*******************************************************************************************/
/*******************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "USART_interface.h"
#include "USART_register.h"
#include "USART_private.h"
#include "USART_config.h"

static u8 GDataTrasmit=0;	//Transmit Data
static void (*Transmission_pvCallBackNotificationFunc)(void)=NULL;	//Transmission Complete Notification

static u8 *GPDataReceive=NULL;	//Received Data pointer
static void (*Receive_pvCallBackNotificationFunc)(void)=NULL;	//Receive Complete Notification


void USART_voidInit(void)
{
	u8 Local_u8UCRCValue=0;
	u16 Local_u16UBRR=0;

#if defined Eight_BitData
	/*Set 8 bit*/
	SET_BIT(Local_u8UCRCValue,7);			//Access the UCSRC
	SET_BIT(Local_u8UCRCValue,UCSRC_UCSZ1);
	SET_BIT(Local_u8UCRCValue,UCSRC_UCSZ0);
#elif defined Seven_BitData
	/*Set 7 bit*/
	SET_BIT(Local_u8UCRCValue,7);			//Access the UCSRC
	SET_BIT(Local_u8UCRCValue,UCSRC_UCSZ1);
	CLR_BIT(Local_u8UCRCValue,UCSRC_UCSZ0);
#elif defined Six_BitData
	/*Set 6 bit*/
	SET_BIT(Local_u8UCRCValue,7);			//Access the UCSRC
	CLR_BIT(Local_u8UCRCValue,UCSRC_UCSZ1);
	SET_BIT(Local_u8UCRCValue,UCSRC_UCSZ0);
#elif defined Five_BitData
	/*Set 5 bit*/
	SET_BIT(Local_u8UCRCValue,7);			//Access the UCSRC
	CLR_BIT(Local_u8UCRCValue,UCSRC_UCSZ1);
	CLR_BIT(Local_u8UCRCValue,UCSRC_UCSZ0);
#endif

#if defined Even_Parity
	SET_BIT(Local_u8UCRCValue,UCSRC_UPM1);
	CLR_BIT(Local_u8UCRCValue,UCSRC_UPM0);
#elif defined Odd_Parity
	SET_BIT(Local_u8UCRCValue,UCSRC_UPM1);
	SET_BIT(Local_u8UCRCValue,UCSRC_UPM0);
#endif

#if defined Stop_2Bit
	SET_BIT(Local_u8UCRCValue,UCSRC_USBS);
#endif

	UCSRC=Local_u8UCRCValue;

	/*baud rate */
	Local_u16UBRR=(u16)(((oscillatorFreq)/(16*BaudRate))-1);
	UCSRC=Local_u16UBRR>>8;		//Access UBRRH
	UBRRL=(u8)Local_u16UBRR;

    /*Enable the receiver*/
	SET_BIT(UCSRB,UCSRB_RXEN);
    
	/*Enable the Transmitter*/
	SET_BIT(UCSRB,UCSRB_TXEN);

}

u8 USART_u8ReceiveCharSynch(char *Copy_u8Data)
{
	u32 Local_u32Counter=0;
	// Wait flag receive complete
	while(GET_BIT(UCSRA,UCSRA_RXC)==0 && Local_u32Counter!=USART_TIMEOUT)
	{
		Local_u32Counter++;
	}
	if (USART_TIMEOUT==Local_u32Counter)
	{
		return 4;
	}
	else
	{
		*Copy_u8Data=UDR;
		return 0;
	}
}
void USART_voidReceiveBufferSynch(char*Buffer,u8 BufferSize)
{
	u8 Local_u8Counter=0;
	while(Local_u8Counter != BufferSize)
	{
		USART_u8ReceiveCharSynch(&Buffer[Local_u8Counter]);
		Local_u8Counter++;
	}

}

u8 USART_u8SendCharSynch(u8 Copy_u8Data)
{
	u32 Local_u32Counter=0;
	//Wait until transmit data register is empty or the time out
	while(GET_BIT(UCSRA,UCSRA_UDRE)==0 && Local_u32Counter!=USART_TIMEOUT)
	{
		Local_u32Counter++;
	}
	if (USART_TIMEOUT==Local_u32Counter)
	{
		return 4;
	}
	else
	{
		UDR=Copy_u8Data;
		return 0;
	}

}
void USART_voidSendStringSynch(char*String)
{
	u8 Local_u8Counter=0;
	while(String[Local_u8Counter]!='\0')
	{
		USART_u8SendCharSynch(String[Local_u8Counter]);
		Local_u8Counter++;
	}
}
void USART_voidSendCharAsynch(u8 Copy_u8Data,void(*Copy_pvNotificationFunc)(void))
{
	/*Make The Data Global*/
	GDataTrasmit=Copy_u8Data;

	/*Make The Notification Function Global*/
	Transmission_pvCallBackNotificationFunc=Copy_pvNotificationFunc;

	/*Enable USART Data Register Empty Interrupt*/
	SET_BIT(UCSRB,UCSRB_UDRIE);
}

void USART_voidReceiveCharAsynch(u8 *Copy_u8Data,void(*Copy_pvNotificationFunc)(void))
{
	/*Make The data pointer Global*/
	GPDataReceive=Copy_u8Data;

	/*Make The Notification Function Global*/
	Receive_pvCallBackNotificationFunc=Copy_pvNotificationFunc;

	/*Enable USART RX Complete Interrupt*/
	SET_BIT(UCSRB,UCSRB_RXCIE);
}

ISR(USART_UDRE_vect)
{
	static u8 Local_u8Check=0;
	UDR=GDataTrasmit;

	 //Check if is the second time
	if (Local_u8Check==1)
	{
		/*Disable USART Data Register Empty Interrupt*/
		CLR_BIT(UCSRB,UCSRB_UDRIE);

		/*Calling the Notification Function*/
		(*Transmission_pvCallBackNotificationFunc)();
	}
	Local_u8Check++;
	/*Enable USART TX Complete Interrupt*/
	//SET_BIT(UCSRB,UCSRB_TXCIE);
}
ISR(USART_TXC_vect)
{

	/*Disable USART TX Complete Interrupt*/
	//CLR_BIT(UCSRB,UCSRB_TXCIE);
}
ISR(USART_RXC_vect)
{
	/*Calling the Notification Function*/
	(*Receive_pvCallBackNotificationFunc)();

	/*Disable USART RX Complete Interrupt*/
	CLR_BIT(UCSRB,UCSRB_RXCIE);
}

