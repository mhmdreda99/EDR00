/*******************************************************************************************/
/*******************************************************************************************/
/****************************    Auther  : Mostafa Mahmoud      ****************************/
/****************************    Layer   : MCAL                 ****************************/
/****************************    SWC     : SPI                  ****************************/
/****************************    Version : 1.00                 ****************************/
/*******************************************************************************************/
/*******************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SPI_register.h"
#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_config.h"

static u8*GPReceived_Data=NULL;
static void(*Transmission_pvCallBackNotificationFunc)(void)=NULL;

void SPI_voidInitMaster(void)
{
	/*Master Initialization*/
	SET_BIT(SPCR,SPCR_MSTR);

#if defined dividedBy_2
	/*Clock Prescaler: divide by 2*/
	CLR_BIT(SPCR,SPCR_SPR0);
	CLR_BIT(SPCR,SPCR_SPR1);
	SET_BIT(SPSR,SPSR_SPI2X);
#elif defined dividedBy_4
	/*Clock Prescaler: divide by 4*/
	CLR_BIT(SPCR,SPCR_SPR0);
	CLR_BIT(SPCR,SPCR_SPR1);
	CLR_BIT(SPSR,SPSR_SPI2X);
#elif defined dividedBy_8
	/*Clock Prescaler: divide by 8*/
	SET_BIT(SPCR,SPCR_SPR0);
	CLR_BIT(SPCR,SPCR_SPR1);
	SET_BIT(SPSR,SPSR_SPI2X);
#elif defined dividedBy_16
	/*Clock Prescaler: divide by 16*/
	SET_BIT(SPCR,SPCR_SPR0);
	CLR_BIT(SPCR,SPCR_SPR1);
	CLR_BIT(SPSR,SPSR_SPI2X);
#elif defined dividedBy_32
	/*Clock Prescaler: divide by 32*/
	CLR_BIT(SPCR,SPCR_SPR0);
	SET_BIT(SPCR,SPCR_SPR1);
	SET_BIT(SPSR,SPSR_SPI2X);
#elif defined dividedBy_64
	/*Clock Prescaler: divide by 64*/
	SET_BIT(SPCR,SPCR_SPR0);
	SET_BIT(SPCR,SPCR_SPR1);
	SET_BIT(SPSR,SPSR_SPI2X);
#elif defined dividedBy_128
	/*Clock Prescaler: divide by 128*/
	SET_BIT(SPCR,SPCR_SPR0);
	SET_BIT(SPCR,SPCR_SPR1);
	CLR_BIT(SPSR,SPSR_SPI2X);
#endif

#if defined LeadingEdge_Rising
	CLR_BIT(SPCR,SPCR_CPOL);
#elif defined LeadingEdge_Falling
	SET_BIT(SPCR,SPCR_CPOL);
#endif

#if defined LeadingEdge_Sample
	CLR_BIT(SPCR,SPCR_CPHA);
#elif defined LeadingEdge_Setup
	SET_BIT(SPCR,SPCR_CPHA);
#endif

	/*SPI Enable*/
	SET_BIT(SPCR,SPCR_SPE);
}

void SPI_voidInitSlave(void)
{
	/*Slave Initialization*/
	CLR_BIT(SPCR,SPCR_MSTR);

	/*SPI Enable*/
	SET_BIT(SPCR,SPCR_SPE);
}

u8 SPI_u8TransceiveSynch(u8 Copy_u8TrasmitData,u8*Copy_u8ReceivedData)
{
	u32 Local_u32Couter=0;

	/*Send the data*/
	SPDR=Copy_u8TrasmitData;

	/*Wait (busy waiting) until transfer complete*/
	while(GET_BIT(SPSR,SPSR_SPIF)==0 && Local_u32Couter<SPI_TIMEOUT);
	{
		Local_u32Couter++;
	}
	if (Local_u32Couter == SPI_TIMEOUT)
	{
		return 4;
	}
	else
	{
		/*Get the exchange data*/
		*Copy_u8ReceivedData=SPDR;
		return SPDR;
	}
}

u8 SPI_u8TransceiveASynch(u8 Copy_u8TrasmitData,u8*Copy_u8ReceivedData,void(*Copy_pvNotificationFunc)(void))
{
	/*Send the data*/
	SPDR=Copy_u8TrasmitData;

	/*Make The Pointer Global*/
	GPReceived_Data=Copy_u8ReceivedData;

	/*Make the Notification func global*/
	Transmission_pvCallBackNotificationFunc=Copy_pvNotificationFunc;

	/*Enable SPI Interrupt*/
	SET_BIT(SPCR,SPCR_SPIE);

	return 0;
}



ISR(SPI_Transfer_vect)
{
	*GPReceived_Data=SPDR;
	(*Transmission_pvCallBackNotificationFunc)();
	CLR_BIT(SPCR,SPCR_SPIE);
}
