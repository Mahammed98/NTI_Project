/*
 * PushButton.c
 *
 * Created: 2/6/2023 11:38:45 AM
 *  Author: Muhammed El Nabawy
 */ 
#include "PushButton.h"


void H_PushButton_Void_Init(u8_t Local_u8_PushButton)
{
	switch(Local_u8_PushButton)
	{
		case PUSH_BUTTON_1: 	M_Dio_Void_PinMode(PUSH_BOTTON_1_PIN,INPUT);	break;
		case PUSH_BUTTON_2: 	M_Dio_Void_PinMode(PUSH_BOTTON_2_PIN,INPUT);	break;
		case PUSH_BUTTON_3: 	M_Dio_Void_PinMode(PUSH_BOTTON_3_PIN,INPUT);	break;
		case PUSH_BUTTON_4: 	M_Dio_Void_PinMode(PUSH_BOTTON_4_PIN,INPUT);	break;
		default:			    M_Dio_Void_PinMode(Local_u8_PushButton,INPUT);  break;
	}
}

u8_t H_PushButton_Void_Read(u8_t Local_u8_PushButton)
{
	u8_t Local_u8_Value = RELESED;
	/*
		WE MAKE DELAY AND TWO CHECKING FOR DEBUNCING 
	*/
	switch(Local_u8_PushButton)
	{
		case PUSH_BUTTON_1: 	
			if(M_Dio_U8_PinRead(PUSH_BOTTON_1_PIN) == PRESSED)
			{
				_delay_ms(DEBUNCING_TIME);
				if(M_Dio_U8_PinRead(PUSH_BOTTON_1_PIN) == PRESSED)
				{
					Local_u8_Value = PRESSED;
					while(M_Dio_U8_PinRead(PUSH_BOTTON_1_PIN) == PRESSED);  // THIS LINE FOR -> IF U STILL PRESSED IN BUTTON NO ACTION ACCURE
					//              (THIS CASE USED IN SOME APPLICATIONS)
				}
			}
			break;
		case PUSH_BUTTON_2: 	
			if(M_Dio_U8_PinRead(PUSH_BOTTON_2_PIN) == PRESSED)
			{
				_delay_ms(DEBUNCING_TIME);
				if(M_Dio_U8_PinRead(PUSH_BOTTON_2_PIN) == PRESSED)
				{
					Local_u8_Value = PRESSED;
					while(M_Dio_U8_PinRead(PUSH_BOTTON_2_PIN) == PRESSED);  // THIS LINE FOR -> IF U STILL PRESSED IN BUTTON NO ACTION ACCURE
					//              (THIS CASE USED IN SOME APPLICATIONS)
				}
			}
			break;
		case PUSH_BUTTON_3: 	
			if(M_Dio_U8_PinRead(PUSH_BOTTON_3_PIN) == PRESSED)
			{
				_delay_ms(DEBUNCING_TIME);
				if(M_Dio_U8_PinRead(PUSH_BOTTON_3_PIN) == PRESSED)
				{
					Local_u8_Value = PRESSED;
					while(M_Dio_U8_PinRead(PUSH_BOTTON_3_PIN) == PRESSED);  // THIS LINE FOR -> IF U STILL PRESSED IN BUTTON NO ACTION ACCURE
					//              (THIS CASE USED IN SOME APPLICATIONS)
				}
			}
			break;
		case PUSH_BUTTON_4: 	
			if(M_Dio_U8_PinRead(PUSH_BOTTON_4_PIN) == PRESSED)
			{
				_delay_ms(DEBUNCING_TIME);
				if(M_Dio_U8_PinRead(PUSH_BOTTON_4_PIN) == PRESSED)
				{
					Local_u8_Value = PRESSED;
					while(M_Dio_U8_PinRead(PUSH_BOTTON_4_PIN) == PRESSED);  // THIS LINE FOR -> IF U STILL PRESSED IN BUTTON NO ACTION ACCURE
					//              (THIS CASE USED IN SOME APPLICATIONS)
				}
			}
			break;
		default:			    
			if(M_Dio_U8_PinRead(Local_u8_PushButton) == PRESSED)
			{
				_delay_ms(DEBUNCING_TIME);
				if(M_Dio_U8_PinRead(Local_u8_PushButton) == PRESSED)
				{
					Local_u8_Value = PRESSED;
					while(M_Dio_U8_PinRead(Local_u8_PushButton) == PRESSED);  // THIS LINE FOR -> IF U STILL PRESSED IN BUTTON NO ACTION ACCURE
					//              (THIS CASE USED IN SOME APPLICATIONS)
				}
			}
			break;
	}
	return Local_u8_Value;
}