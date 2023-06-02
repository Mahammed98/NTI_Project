/*
 * TempSensor.c
 *
 * Created: 3/17/2023 11:26:51 AM
 *  Author: Muhammed El Nabawy
 */ 
#include "TempSensor.h"
void  H_Void_TempSensor_Init(void)
{
	M_Adc_Void_Init();
}
u16_t H_u16_TempSensor_Read(u8_t Local_u8_Num)
{
	u16_t Local_u16_ReadValue = M_Adc_u16_Read(Local_u8_Num);
	u16_t Local_u16_ReadTemp  = (((u32_t)Local_u16_ReadValue * 500) / 1023);
	return Local_u16_ReadTemp;	
}