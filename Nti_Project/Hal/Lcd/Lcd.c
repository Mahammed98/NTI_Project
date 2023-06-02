/*
 * Lcd.c
 *
 * Created: 2/15/2023 5:06:22 PM
 *  Author: Muhammed El Nabawy
 */ 
#include "Dio.h"
#include "Lcd.h"

void H_Lcd_Void_Init(void)
{
	#if LCD_MODE   ==  _8_BIT_MODE_
		M_Dio_Void_PortMode(D, OUTPUT);
		M_Dio_Void_PinMode(LCD_EN_PIN, OUTPUT);
		M_Dio_Void_PinMode(LCD_RS_PIN, OUTPUT);
		_delay_ms(1000);										// WAIT MCU IN LCD TO WAKEUP, BECAUSE MCU IS FASTER THAN MCU IN LCD 
		H_Lcd_Void_WriteCommand(_8_BIT_MODE_COMMAND_);			// SET LCD MODE (8-BIT) OR (4-BIT) (0X38 -> 8 BIT MODE)
		H_Lcd_Void_WriteCommand(LCD_CLR);						// to clear LCD
		H_Lcd_Void_WriteCommand(LCD_RETURN_HOME);				// RETURN FROM FIRST COLOUM AND FIRST RAW 
		H_Lcd_Void_WriteCommand(LCD_DISPLAY_ON_CURSOR_OFF);     // SET ON DISPLAY AND SET OFF CURSOR	
	#elif LCD_MODE  ==   _4_BIT_MODE_
		M_Dio_Void_PinMode(LCD_DATA_PIN_7, OUTPUT);
		M_Dio_Void_PinMode(LCD_DATA_PIN_6, OUTPUT);
		M_Dio_Void_PinMode(LCD_DATA_PIN_5, OUTPUT);
		M_Dio_Void_PinMode(LCD_DATA_PIN_4, OUTPUT);
		M_Dio_Void_PinMode(LCD_EN_PIN, OUTPUT);
		M_Dio_Void_PinMode(LCD_RS_PIN, OUTPUT);
		_delay_ms(1000);										// WAIT MCU IN LCD TO WAKEUP, BECAUSE MCU IS FASTER THAN MCU IN LCD
		H_Lcd_Void_WriteCommand(0x33);							//
		H_Lcd_Void_WriteCommand(0x32);							//		SET LCD MODE (4-BIT) 											
		H_Lcd_Void_WriteCommand(0x28);							//
		H_Lcd_Void_WriteCommand(LCD_CLR);						// to clear LCD
		H_Lcd_Void_WriteCommand(LCD_RETURN_HOME);				// RETURN FROM FIRST COLOUM AND FIRST RAW
		H_Lcd_Void_WriteCommand(LCD_DISPLAY_ON_CURSOR_OFF);     // SET ON DISPLAY AND SET OFF CURSOR
	#endif
}//end function

void H_Lcd_Void_WriteCharacter(u8_t Local_u8_Data)
{	
	#if LCD_MODE  ==   _8_BIT_MODE_
		M_Dio_Void_PinWrite(LCD_RS_PIN,HIGH);          // SENT DATA
		/*
			we should prepare data first before enable lcd_en_pin	
				(note -> give clock pulse befor sent data)
		*/
		LCD_DATA_PORT = Local_u8_Data;				   // sent data(data)
		M_Dio_Void_PinWrite(LCD_EN_PIN,HIGH);
		_delay_ms(1);                                  // to MCU of LCD recognize that lcd_en_pin is set high
		M_Dio_Void_PinWrite(LCD_EN_PIN,LOW);
		_delay_ms(3);                                  // delay before each data sent
	#elif LCD_MODE  ==   _4_BIT_MODE_
		M_Dio_Void_PinWrite(LCD_RS_PIN,HIGH);          // SENT DATA
		/*
			we should prepare data first before enable lcd_en_pin	
				(note -> give clock pulse befor sent data)  
		*/ //                                                           1 0 0 0 0 1 0 1 & 1 0 0 0 0 1 1 1
		LCD_DATA_PORT = ((Local_u8_Data & 0XF0) >> (4 - SHITH_BITS)) | (LCD_DATA_PORT & __ANDING__VALUE__);  // sent first half of data
		M_Dio_Void_PinWrite(LCD_EN_PIN,HIGH);
		_delay_ms(1);                                  // to MCU of LCD recognize that lcd_en_pin is set high
		M_Dio_Void_PinWrite(LCD_EN_PIN,LOW);
		_delay_ms(3);                                  // delay before each data sent
		LCD_DATA_PORT = ((Local_u8_Data & 0X0F) << SHITH_BITS) | (LCD_DATA_PORT & __ANDING__VALUE__);			   // sent second half of data
		M_Dio_Void_PinWrite(LCD_EN_PIN,HIGH);
		_delay_ms(1);                                  // to MCU of LCD recognize that lcd_en_pin is set high
		M_Dio_Void_PinWrite(LCD_EN_PIN,LOW);
		_delay_ms(3);                                  // delay before each data sent
	#endif
}//end function

void H_Lcd_Void_WriteString( u8_t * Local_u8_String)
{
	u8_t Local_u8_Counter = 0;
	while(Local_u8_String[Local_u8_Counter] != _NULL_)
	{
		H_Lcd_Void_WriteCharacter(Local_u8_String[Local_u8_Counter]);
		Local_u8_Counter++;
	}
}// end function
 
void H_Lcd_Void_WriteCommand(u8_t Local_u8_Command)
{
	#if LCD_MODE  ==   _8_BIT_MODE_
		M_Dio_Void_PinWrite(LCD_RS_PIN,LOW);          // SENT Command
		/*
			we should prepare data first before enable lcd_en_pin	
				(note -> give clock pulse befor sent data)
		*/
		LCD_DATA_PORT = Local_u8_Command;				   // sent data(Command)
		M_Dio_Void_PinWrite(LCD_EN_PIN,HIGH);
		_delay_ms(1);                                  // to MCU of LCD recognize that lcd_en_pin is set high
		M_Dio_Void_PinWrite(LCD_EN_PIN,LOW);
		_delay_ms(3);                                  // delay before each data sent
	#elif LCD_MODE  ==   _4_BIT_MODE_
		M_Dio_Void_PinWrite(LCD_RS_PIN,LOW);          // SENT Command
		/*
			we should prepare data first before enable lcd_en_pin	
				(note -> give clock pulse befor sent data)
		*/
		LCD_DATA_PORT = ((Local_u8_Command & 0XF0) >> (4 - SHITH_BITS)) | (LCD_DATA_PORT & __ANDING__VALUE__);		// sent data(data)
		M_Dio_Void_PinWrite(LCD_EN_PIN,HIGH);
		_delay_ms(1);                                  // to MCU of LCD recognize that lcd_en_pin is set high
		M_Dio_Void_PinWrite(LCD_EN_PIN,LOW);
		_delay_ms(3);                                  // delay before each data sent
		LCD_DATA_PORT = ((Local_u8_Command & 0X0F) << SHITH_BITS) | (LCD_DATA_PORT & __ANDING__VALUE__);		// sent data(data)
		M_Dio_Void_PinWrite(LCD_EN_PIN,HIGH);
		_delay_ms(1);                                  // to MCU of LCD recognize that lcd_en_pin is set high
		M_Dio_Void_PinWrite(LCD_EN_PIN,LOW);
		_delay_ms(3);                                  // delay before each data sent
	#endif
}// end function

void H_Lcd_Void_WriteNum(s32_t Local_s32_Num)
{
	/*
		input number like 4321, so we want to print first number (4)
		but this % operation give unit from number(last number), so 
		making array to store the number and print it from last element to first 
		(storing first unit in first element and last unit in last element
	*/ 
	u8_t Local_u8_Unit = 0;
	s8_t Local_s8_Counter = 0;
	u8_t Local_u8_Arr[8] = {0};  // 8 elements because u32(long int) bit data size only have 8 digit maximum 
	
	if(Local_s32_Num == 0)
	{
		H_Lcd_Void_WriteCharacter('0');
	}
	else
	{
		if(Local_s32_Num < 0)
		{
			H_Lcd_Void_WriteCharacter('-');
			Local_s32_Num *= (-1);
		}
		while(Local_s32_Num != 0)
		{
			Local_u8_Unit = Local_s32_Num % 10;
			Local_u8_Arr[Local_s8_Counter] = Local_u8_Unit;
			Local_s8_Counter++;
			Local_s32_Num = Local_s32_Num / 10;
		}
		Local_s8_Counter--;
		while(Local_s8_Counter >= 0)
		{
			H_Lcd_Void_WriteCharacter(Local_u8_Arr[Local_s8_Counter]+48);
			Local_s8_Counter--;
		}	
	}
	

		
}// end function

void H_Lcd_Void_ClrLcd(void)
{
	H_Lcd_Void_WriteCommand(LCD_CLR);							// to clear LCD
}// write this function for readability for easy use for user

void H_Lcd_Void_GoTo(u8_t Local_u8_Row, u8_t Local_u8_Coloum)
{
	if(Local_u8_Row > 1)
	{
		Local_u8_Row = 0;      // start from first raw -> default value 
	}
	if(Local_u8_Coloum > 15)
	{
		Local_u8_Coloum = 0;   // start from first Coloum -> default value
	}
	u8_t Local_u8_Array [2]= {0x80, 0xc0};
	H_Lcd_Void_WriteCommand(Local_u8_Array[Local_u8_Row] + Local_u8_Coloum);
}
