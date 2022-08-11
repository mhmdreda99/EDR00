/*******************************************************************************************/
/*******************************************************************************************/
/****************************    Author  : Mostafa Mahmoud      ****************************/
/****************************    Layer   : HAL                  ****************************/
/****************************    HWC     : EEPROM               ****************************/
/****************************    Version : 1.00                 ****************************/
/*******************************************************************************************/
/*******************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "TWI_interface.h"
#include "EEPROM_interface.h"



void EEPROM_WriteByte(u16 Copy_u16Address,u8 Copy_u8Data)
{
	TWI_SendStartCondition();
	TWI_SendSlaveAddressWithWrite((u8)(0xA0 | ((Copy_u16Address & 0x0700) >> 7)));
	TWI_MasterWriteDataByte((u8)Copy_u16Address);
	TWI_MasterWriteDataByte(Copy_u8Data);
	TWI_SendStopCondition();
}
void EEPROM_ReadByte(u16 Copy_u16Address,u8 *Copy_u8Data)	
{
    TWI_SendStartCondition();
	TWI_SendSlaveAddressWithWrite((u8)(0xA0 | ((Copy_u16Address & 0x0700) >> 7)));
	TWI_MasterWriteDataByte((u8)Copy_u16Address);
	TWI_SendRepeatedStart();
	TWI_SendSlaveAddressWithRead((u8)(0xA0 | ((Copy_u16Address & 0x0700) >> 7) | 1));
	TWI_MasterReadDataByte(Copy_u8Data);
	TWI_SendStopCondition();
}
