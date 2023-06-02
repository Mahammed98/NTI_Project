/*
 * UltraSonic.c
 *
 * Created: 4/27/2023 1:52:57 PM
 *  Author: Muhammed El Nabawy
 */ 
#define F_CPU 16000000UL
#include <util/delay.h>

#include "Timer.h"
#include "UltraSonic.h"
#include "Dio.h"


void H_UltraSonic_Void_Init(void)
{
	M_Timer_Void_Timer1Init(); 
	M_Timer_Void_ICUSetTrigger(__ICU_TRIGGER_RISING_EDGE__);
}
u8_t H_ULtraSonic_u8_ReadDistace(u8_t Copy_Ultra_Pin)
{
	u8_t Local_u8_Distance = 0;
	u16_t Local_u16_Time = 0;

	TCNT1 = 0;
	SetBit(TIFR1,ICF1);                   // CLEAR ICU FLAG
	M_Dio_Void_PinWrite(Copy_Ultra_Pin, HIGH);
	_delay_us(10);
	M_Dio_Void_PinWrite(Copy_Ultra_Pin, LOW);
	
	while(GetBit(TIFR1,ICF1) == 0);
	M_Timer_Void_ICUSetTrigger(__ICU_TRIGGER_FALLING_EDGE__);
	TCNT1 = 0;
	SetBit(TIFR1,ICF1);                   // CLEAR ICU FLAG
	
	while(GetBit(TIFR1,ICF1) == 0);
	M_Timer_Void_ICUSetTrigger(__ICU_TRIGGER_RISING_EDGE__);
	Local_u16_Time = ICR1;
	SetBit(TIFR1,ICF1);                   // CLEAR ICU FLAG
	
	Local_u8_Distance =(17150 * (1.0/__CLK__MCU__) * Local_u16_Time);						 // calculate the distance
	return Local_u8_Distance;	
}
