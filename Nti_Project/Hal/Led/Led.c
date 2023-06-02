/*
 * Led.c
 *
 * Created: 1/31/2023 7:40:48 PM
 *  Author: Muhammed El Nabawy
 */  
#include "Led.h"

/*************************************************_FUNCTIONS_*****************************/
void H_Led_void_Init(u8_t Local_u8_LedName)
{
	switch(Local_u8_LedName)
	{
		case BLU_LED:   M_Dio_Void_PinMode(BLU_LED_PIN, OUTPUT);	break;
		case GRE_LED:   M_Dio_Void_PinMode(GRE_LED_PIN, OUTPUT);	break;
		case RED_LED:   M_Dio_Void_PinMode(RED_LED_PIN, OUTPUT);	break;
		default:													break;

	}
}
void H_Led_void_On(u8_t Local_u8_LedName)
{
	switch(Local_u8_LedName)
	{
		case BLU_LED:   M_Dio_Void_PinWrite(BLU_LED_PIN, HIGH);		break;
		case GRE_LED:   M_Dio_Void_PinWrite(GRE_LED_PIN, HIGH);		break;
		case RED_LED:   M_Dio_Void_PinWrite(RED_LED_PIN, HIGH);		break;
		default:													break;

	}
}
void H_Led_void_Off(u8_t Local_u8_LedName)
{
	switch(Local_u8_LedName)
	{
		case BLU_LED:   M_Dio_Void_PinWrite(BLU_LED_PIN, LOW);		break;
		case GRE_LED:   M_Dio_Void_PinWrite(GRE_LED_PIN, LOW);		break;
		case RED_LED:   M_Dio_Void_PinWrite(RED_LED_PIN, LOW);		break;
		default:													break;

	}
}
void H_Led_void_BlinkOnce(u8_t Local_u8_LedName)
{
	switch(Local_u8_LedName)
	{
		case BLU_LED:  
			M_Dio_Void_PinWrite(BLU_LED_PIN, HIGH);
			_delay_ms(200);
			M_Dio_Void_PinWrite(BLU_LED_PIN, LOW);
			break;
		case GRE_LED:
			M_Dio_Void_PinWrite(GRE_LED_PIN, HIGH);
			_delay_ms(200);
			M_Dio_Void_PinWrite(GRE_LED_PIN, LOW);
			break;
		case RED_LED:
			M_Dio_Void_PinWrite(RED_LED_PIN, HIGH);
			_delay_ms(200);
			M_Dio_Void_PinWrite(RED_LED_PIN, LOW);	
		    break;
		default:
			break;
	}
}
void H_Led_void_BlinkTwice(u8_t Local_u8_LedName)
{
		switch(Local_u8_LedName)
		{
			case BLU_LED:
				M_Dio_Void_PinWrite(BLU_LED_PIN, HIGH);
				_delay_ms(200);
				M_Dio_Void_PinWrite(BLU_LED_PIN, LOW);
				_delay_ms(200);
				M_Dio_Void_PinWrite(BLU_LED_PIN, HIGH);
				_delay_ms(200);
				M_Dio_Void_PinWrite(BLU_LED_PIN, LOW);
				break;
			case GRE_LED:
				M_Dio_Void_PinWrite(GRE_LED_PIN, HIGH);
				_delay_ms(200);		
				M_Dio_Void_PinWrite(GRE_LED_PIN, LOW);
				_delay_ms(200);		
				M_Dio_Void_PinWrite(GRE_LED_PIN, HIGH);
				_delay_ms(200);		
				M_Dio_Void_PinWrite(GRE_LED_PIN, LOW);
				break;
			case RED_LED:
				M_Dio_Void_PinWrite(RED_LED_PIN, HIGH);
				_delay_ms(200);		
				M_Dio_Void_PinWrite(RED_LED_PIN, LOW);
				_delay_ms(200);		
				M_Dio_Void_PinWrite(RED_LED_PIN, HIGH);
				_delay_ms(200);		
				M_Dio_Void_PinWrite(RED_LED_PIN, LOW);
				break;
			default:
				break;
		}
}
void H_Led_void_Toggle(u8_t Local_u8_LedName)
{
	switch(Local_u8_LedName)
	{
		case BLU_LED:   M_Dio_Void_PinToggle(BLU_LED_PIN);	break;
		case GRE_LED:   M_Dio_Void_PinToggle(GRE_LED_PIN);	break;
		case RED_LED:   M_Dio_Void_PinToggle(RED_LED_PIN);	break;
		default:													break;

	}
}
