/*
 * eeprom.c
 *
 * Created: 5/23/2023 10:43:46 AM
 *  Author: Muhammed El Nabawy
 */ 

#include "eeprom.h"
void H_Void_EEPROM_Init(void)
{
	M_Void_I2c_MasterInit();
}
u8_t H_Void_EEPROM_Write(u16_t Copy_u16_Address, u8_t Copy_u8_Data)
{
	u8_t Local_u8_Flag = 0;
	// first send start condition 
	M_Void_I2c_SendStart();
	// second send address
	M_Void_I2c_MSendData((u8_t)(0xA0 | ((Copy_u16_Address & 0x0700) >> 7)));
	// third send (second section from address), by using send data method
	M_Void_I2c_MSendData((u8_t)Copy_u16_Address);	
	// forth send byte of data
	M_Void_I2c_MSendData(Copy_u8_Data);
	// fifth send stop condition
	M_Void_I2c_SendStop();
	return Local_u8_Flag;
}
u8_t H_Void_EEPROM_Read(u16_t Copy_u16_Address, u8_t * Copy_u8_Ptr)
{
	u8_t Local_u8_Flag = 0;
	//step 1 : send start condition
	M_Void_I2c_SendStart();
	//check status
	if(M_u8_I2c_GetStatus() != TWI_M_R_START_SUCCESS )
	{
		M_Void_I2c_SendStop();
		Local_u8_Flag = 2 ;
	}
	//step 2 : send Address + write
	M_Void_I2c_MSendData((u8_t)(0xA0 | ((Copy_u16_Address & 0x0700) >> 7)));
	//check status
	if(M_u8_I2c_GetStatus()  !=TWI_M_T_ADDRESS_ACK )
	{
		M_Void_I2c_SendStop();
		Local_u8_Flag = 3;
	}
	M_Void_I2c_MSendData((u8_t)Copy_u16_Address);
	//check status
	if(M_u8_I2c_GetStatus()  != TWI_M_T_DATA_ACK )
	{
		M_Void_I2c_SendStop();
		Local_u8_Flag = 4;
	}
	//step 3 : send repeated start
	M_Void_I2c_SendStart();
	//check status
	if(M_u8_I2c_GetStatus() != TWI_M_R_REPETATED_START_SUCCESS )
	{
		M_Void_I2c_SendStop();
		Local_u8_Flag = 5 ;
	}
	//step 4: send read to EEPROM
	M_Void_I2c_MSendData((u8_t)(0xA0 | ((Copy_u16_Address & 0x0700) >> 7)) | 1);
	//check status
	if(M_u8_I2c_GetStatus()  != TWI_M_R_ADDRESS_ACK )
	{
		M_Void_I2c_SendStop();
		Local_u8_Flag = 6;
	}
	//step 5 : get data
	* Copy_u8_Ptr = M_u8_I2c_MReadData();
	// check status
	M_Void_I2c_SendStop();
	return Local_u8_Flag ;
	
}