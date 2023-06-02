#define F_CPU 16000000UL
#include <util/delay.h>
#include "Lcd.h"
#include "Dio.h"
#include "LM293.h"
#include "KeyPad.h"
#include "TempSensor.h"
#include "Led.h"

u8_t APP_Main_U8_CompareString(const u8_t *, u8_t *);
void APP_Main_Void_CheckingPassword(const u8_t *);

int main (void)
{
	u16_t Local_u16_StroingSensorValue = 0;
	u8_t Local_u8_ReadingValue = 0;
	u8_t Local_u8_StoredPassword [16] = "759860AB";
	H_Void_Lm293Init();
	H_Lcd_Void_Init();
	H_Void_TempSensor_Init();
	H_Void_KeyPad_Init();
	H_Led_void_Init(GRE_LED);
	H_Led_void_Init(RED_LED);
	/*
		PINS FOR L293 (MOTOR DRIVER)
	*/
	M_Dio_Void_PinMode(PC4, OUTPUT);
	M_Dio_Void_PinMode(PC5, OUTPUT);
	M_Dio_Void_PinMode(PD6, OUTPUT);
	/*
		                        WELCOME MESSAGE
	*/
	H_Lcd_Void_WriteString("Welcome User-_-");
	_delay_ms(1000);
	H_Lcd_Void_ClrLcd();
	APP_Main_Void_CheckingPassword(Local_u8_StoredPassword);
	
	H_Lcd_Void_WriteString("1- LEDs ON");
	H_Lcd_Void_GoTo(1,0);
	H_Lcd_Void_WriteString("2- LEDs OFF");
	for(;;)
	{
		Local_u8_ReadingValue = H_u8_KeyPad_Read();
		if(Local_u8_ReadingValue)   break;
	}
	if(Local_u8_ReadingValue == '1')
	{
		H_Led_void_On(RED_LED);
		H_Led_void_On(GRE_LED);
	}
	else if(Local_u8_ReadingValue == '2')
	{
		H_Led_void_Off(RED_LED);
		H_Led_void_Off(GRE_LED);
	}

	_delay_ms(3000);
	H_Lcd_Void_ClrLcd();
	while(1)
	{
		Local_u16_StroingSensorValue = H_u16_TempSensor_Read(A7);
		H_Lcd_Void_WriteNum(Local_u16_StroingSensorValue);
		if(Local_u16_StroingSensorValue <= 25)
		{
			M_Dio_Void_PinWrite(PC4, LOW);
		}
		else if((Local_u16_StroingSensorValue > 25) && (Local_u16_StroingSensorValue < 30))
		{
			M_Dio_Void_PinWrite(PC4, HIGH);
			H_Void_Lm293WritePwm(50, 1);
		}
		else if(Local_u16_StroingSensorValue >= 30)
		{
			M_Dio_Void_PinWrite(PC4, HIGH);
			H_Void_Lm293WritePwm(99, 1);
		}
		_delay_ms(200);
		H_Lcd_Void_ClrLcd();
		
	}
}// end main function 

u8_t APP_Main_U8_CompareString(const u8_t * Copy_u8_String1, u8_t * Copy_u8_String2)
{
	u8_t Local_u8_Counter1 = 0;
	u8_t Local_u8_Value = 0;
	while(Copy_u8_String2[Local_u8_Counter1] != '\0' && Copy_u8_String1[Local_u8_Counter1] != '\0')
	{
		if(Copy_u8_String1[Local_u8_Counter1] != Copy_u8_String2[Local_u8_Counter1])
		{
			Local_u8_Value = 1;
			break;
		}
		Local_u8_Counter1++;
	}
	return Local_u8_Value;
	
} // End function 
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void APP_Main_Void_CheckingPassword(const u8_t * Copy_u8_Password)
{
	u8_t Local_u8_StoringKeyValue = 0;
	u8_t Local_u8_Counter1 ;
	u8_t Local_u8_Counter2 = 0;
	u8_t Local_u8_CheckingPassword [16];
	Enter_password:
	Local_u8_Counter1 = 0;
	H_Lcd_Void_WriteString("Enter password:");
	H_Lcd_Void_WriteCommand(0x0F);           // cursor blinking
	H_Lcd_Void_GoTo(1,0);                    // go to second row
	while(1)
	{
		while(1)
		{
			Local_u8_StoringKeyValue = H_u8_KeyPad_Read();
			if(Local_u8_StoringKeyValue)   break;
		} // polling until reading value from keypad
		H_Lcd_Void_WriteCharacter('*');   // hidden password
		if(Local_u8_StoringKeyValue == '#' || Local_u8_Counter1 == 16)  break;
		Local_u8_CheckingPassword[Local_u8_Counter1++] = Local_u8_StoringKeyValue;
		Local_u8_StoringKeyValue = 0;
	} // polling until user enter a password
	H_Lcd_Void_ClrLcd();
	if(APP_Main_U8_CompareString(Copy_u8_Password, Local_u8_CheckingPassword))
	{
		H_Lcd_Void_ClrLcd();
		Local_u8_Counter2++;
		if(Local_u8_Counter2 == 3)     // if number of trying for enter password exceeded 3 times reentering password
		{
			Local_u8_Counter2 = 0;
			H_Lcd_Void_WriteString("System Locked :(");
			H_Lcd_Void_GoTo(1,0);                    // go to second row
			H_Lcd_Void_WriteString("Try after 10Sec");
			_delay_ms(10000);
			H_Lcd_Void_ClrLcd();
			goto Enter_password;
		}// end second if 
		
		H_Lcd_Void_WriteString("Wrong Password");
		H_Lcd_Void_GoTo(1,0);                    // go to second row
		H_Lcd_Void_WriteString("Please Try again");
		_delay_ms(2000);
		H_Lcd_Void_ClrLcd();
		goto Enter_password;
	}// end main if
	else
	{
		H_Lcd_Void_ClrLcd();
		H_Lcd_Void_WriteString("Right Password:)");
		H_Lcd_Void_GoTo(1,0);                    // go to second row
		H_Lcd_Void_WriteString("Welcome Mohamed");
		_delay_ms(2000);
		H_Lcd_Void_ClrLcd();
	}
}
