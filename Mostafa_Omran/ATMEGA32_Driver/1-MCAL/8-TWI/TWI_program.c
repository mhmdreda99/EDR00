		/*******************************************************************************************/
/*******************************************************************************************/
/****************************    Auther  : Mostafa Mahmoud      ****************************/
/****************************    Layer   : MCAL                 ****************************/
/****************************    SWC     : TWI                  ****************************/
/****************************    Version : 1.00                 ****************************/
/*******************************************************************************************/
/*******************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "TWI_interface.h"
#include "TWI_register.h"
#include "TWI_private.h"
#include "TWI_config.h"


void TWI_voidMasterInit(u8 Copy_u8SlaveAddress)
{
	/*Set Clock frequency to 400Kbps*/
	/*Set TWBR to 2*/
	TWBR=2;

	/*Clear the 2 bits of TWPS*/
	CLR_BIT(TWSR,TWSR_TWPS0);
	CLR_BIT(TWSR,TWSR_TWPS1);

	/*Initialize the node address*/
	if(Copy_u8SlaveAddress !=0)
	{
		TWAR=Copy_u8SlaveAddress;
	}

	/*Enable TWI*/
	SET_BIT(TWCR,TWCR_TWEN);

}

void TWI_voidSlaveInit(u8 Copy_u8SlaveAddress)
{
	/*Initialize the node address*/
	TWAR=Copy_u8SlaveAddress<<1;

	/*Enable TWI*/
	SET_BIT(TWCR,TWCR_TWEN);
}

TWI_ErrStatus TWI_SendStartCondition(void)
{
	TWI_ErrStatus Local_ErrStatus= NoError;

	/*Send start condition on the bus*/
	SET_BIT(TWCR,TWCR_TWSTA);

	/*clear the interrupt flag to start the previous operation*/
	SET_BIT(TWCR,TWCR_TWINT);

	/*waiting until the interrupt flag is raised again and the previous operation is complete*/
	while(GET_BIT(TWCR,TWCR_TWINT)==0);

	/*Check the operation status in TWI Status Register 0xF8(0b11111000) is mask*/
	if ((TWSR & 0xF8) != START_ACK)
	{
		Local_ErrStatus=StartConditionErr;
	}
	else
	{
		/*Do nothing*/

	}
	return Local_ErrStatus;
}

TWI_ErrStatus TWI_SendRepeatedStart(void)
{
	TWI_ErrStatus Local_ErrStatus= NoError;

	/*Send start condition on the bus*/
	SET_BIT(TWCR,TWCR_TWSTA);

	/*clear the interrupt flag to start the previous operation*/
	SET_BIT(TWCR,TWCR_TWINT);

	/*waiting until the interrupt flag is raised again and the previous operation is complete*/
	while(GET_BIT(TWCR,TWCR_TWINT)==0);

	/*Check the operation status in TWI Status Register 0xF8(0b11111000) is mask*/
	if ((TWSR & 0xF8) != REP_START_ACK)
	{
		Local_ErrStatus=RepeatedStartErr;
	}
	else
	{
		/*Do nothing*/
	}
	return Local_ErrStatus;
}

TWI_ErrStatus TWI_SendSlaveAddressWithWrite(u8 Copy_u8SlaveAddress)
{
	TWI_ErrStatus Local_ErrStatus= NoError;
	u8 Local_TWCR=0;

	/*Clear the start condition bit And Set The Enable And Clear interrupt flag in the local variable*/
	CLR_BIT(Local_TWCR,TWCR_TWSTA);
	SET_BIT(Local_TWCR,TWCR_TWEN);
	SET_BIT(Local_TWCR,TWCR_TWINT);

	CLR_BIT(Copy_u8SlaveAddress,0);		/*for write request*/

	/*Set the slave address in the 7 MSB in the data register*/
	TWDR=Copy_u8SlaveAddress;

	/*Passing the local variable to the TWCR to do the previous operation*/
	TWCR=Local_TWCR;

	/*waiting until the interrupt flag is raised again and the previous operation is complete*/
	while(GET_BIT(TWCR,TWCR_TWINT)==0);

	/*Check the operation status in TWI Status Register 0xF8(0b11111000) is mask*/
	if ((TWSR & 0xF8) != SLAVE_ADD_AND_WR_ACK)
	{
		Local_ErrStatus=SlaveAdressWithWriteErr;

	}
	else
	{
		/*Do nothing*/
	}
	return Local_ErrStatus;
}

TWI_ErrStatus TWI_SendSlaveAddressWithRead(u8 Copy_u8SlaveAddress)
{
	TWI_ErrStatus Local_ErrStatus= NoError;
	u8 Local_TWCR=0;

	/*Clear the start condition bit And Set The Enable And Clear interrupt flag in the local variable*/
	CLR_BIT(Local_TWCR,TWCR_TWSTA);
	SET_BIT(Local_TWCR,TWCR_TWEN);
	SET_BIT(Local_TWCR,TWCR_TWINT);

	/*Set the slave address in the 7 MSB in the data register*/
	TWDR=Copy_u8SlaveAddress;
	SET_BIT(TWDR,0);		/*for read request*/

	/*Passing the local variable to the TWCR to do the previous operation*/
	TWCR=Local_TWCR;

	/*waiting until the interrupt flag is raised again and the previous operation is complete*/
	while(GET_BIT(TWCR,TWCR_TWINT)==0);

	/*Check the operation status in TWI Status Register 0xF8(0b11111000) is mask*/
	if ((TWSR & 0xF8) != SLAVE_ADD_AND_RD_ACK)
	{
		Local_ErrStatus=SlaveAdressWithReadErr;
	}
	else
	{
		/*Do nothing*/
	}
	return Local_ErrStatus;

}

TWI_ErrStatus TWI_MasterWriteDataByte(u8 Copy_u8DataByte)
{
	TWI_ErrStatus Local_ErrStatus= NoError;

	/*Write the data byte*/
	TWDR=Copy_u8DataByte;

	/*clear the interrupt flag to start the previous operation*/
	SET_BIT(TWCR,TWCR_TWINT);

	/*waiting until the interrupt flag is raised again and the previous operation is complete*/
	while(GET_BIT(TWCR,TWCR_TWINT)==0);

	/*Check the operation status in TWI Status Register 0xF8(0b11111000) is mask*/
	if ((TWSR & 0xF8) != MSTR_WR_BYTE_ACK)
	{
		Local_ErrStatus=MasterWriteByteErr;
	}
	else
	{
		/*Do nothing*/
	}
	return Local_ErrStatus;

}

TWI_ErrStatus TWI_MasterReadDataByte(u8 *Copy_pu8DataByte)
{
	TWI_ErrStatus Local_ErrStatus= NoError;

	/*Enable master generating acknowledge bit after receiving the data*/
	SET_BIT(TWCR,TWCR_TWEA);

	/*clear the interrupt flag to start the slave sending data*/
	SET_BIT(TWCR,TWCR_TWINT);

	/*waiting until the interrupt flag is raised again and the previous operation is complete*/
	while(GET_BIT(TWCR,TWCR_TWINT)==0);

	/*Check the operation status in TWI Status Register 0xF8(0b11111000) is mask*/
	if ((TWSR & 0xF8) != MSTR_RD_BYTE_WITH_ACK)
	{
		Local_ErrStatus=MasterReadByteErr;
	}
	else
	{
		/*Read the received data*/
		*Copy_pu8DataByte=TWDR;
	}
	return Local_ErrStatus;

}

void TWI_SendStopCondition(void)
{
	/*Generate stop condition on the bus*/
	SET_BIT(TWCR,TWCR_TWSTO);

	/*clear the interrupt flag to start the previous operation*/
	SET_BIT(TWCR,TWCR_TWINT);

}
