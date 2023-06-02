/*
 * LM293.c
 *
 * Created: 5/31/2023 6:37:18 PM
 *  Author: Muhammed El Nabawy
 */ 

#include "LM293.h"

void H_Void_Lm293Init(void)
{
	M_Timer_Void_Timer0Init();
	M_Timer_Void_Timer0Start();
}

void H_Void_Lm293WritePwm(u8_t Copy_u8_Value, u8_t Copy_u8_PinId)
{
	M_Timer_void_FastPwm_Write(Copy_u8_Value, Copy_u8_PinId);
}