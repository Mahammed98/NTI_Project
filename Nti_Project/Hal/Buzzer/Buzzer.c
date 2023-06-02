/*
 * Buzzer.c
 *
 * Created: 2/25/2023 12:27:18 PM
 *  Author: Muhammed El Nabawy
 */ 
#define F_CPU 16000000UL
#include <util/delay.h>
#include "Buzzer.h"

void H_Buzzer_Void_Init(void)
{
	M_Dio_Void_PinMode(BUZZER_PIN, OUTPUT);
}
void H_Buzzer_Void_On(void)
{
	M_Dio_Void_PinWrite(BUZZER_PIN, HIGH);
}
void H_Buzzer_Void_Off(void)
{
	M_Dio_Void_PinWrite(BUZZER_PIN, LOW);
}
void H_Buzzer_Void_Once(void)
{
	M_Dio_Void_PinWrite(BUZZER_PIN, HIGH);
	_delay_ms(BUZZER_DELAY_ON);
	M_Dio_Void_PinWrite(BUZZER_PIN, LOW);
}
void H_Buzzer_Void_Twice(void)
{
	 H_Buzzer_Void_Once();
	_delay_ms(BUZZER_DELAY_OFF);
	 H_Buzzer_Void_Once();
	
}
void H_Buzzer_Void_Triple(void)
{
	H_Buzzer_Void_Twice();
	_delay_ms(BUZZER_DELAY_OFF);
	H_Buzzer_Void_Once();
}
void H_Buzzer_Void_OnceLong(void)
{
	M_Dio_Void_PinWrite(BUZZER_PIN, HIGH);
	_delay_ms(BUZZER_DELAY_ON_LONG);
	M_Dio_Void_PinWrite(BUZZER_PIN, LOW);
}