/*
 * Lcd.h
 *
 * Created: 2/15/2023 5:06:31 PM
 *  Author: Muhammed El Nabawy
 */ 
/*****************************************_MACROS_***********************************/
/*****************************************_INCLUDE_**********************************/
/*****************************************_POROTYPES_********************************/

#ifndef LCD_H_
#define LCD_H_


/*****************************************_MACROS_***********************************/
#define  _8_BIT_MODE_								 1
#define  _4_BIT_MODE_								 2

#define _NULL_										'\0'
#define	LCD_CLR										0x01
#define LCD_RETURN_HOME								0x02
#define	LCD_DISPLAY_ON_CURSOR_OFF					0x0c
#define _8_BIT_MODE_COMMAND_                        0x38
#define _4_BIT_MODE_COMMAND_                        0x31


/*#if   LCD_DATA_PORT    ==		 PORTB
#define   LCD_DIRECTION_PORT     B
#elif LCD_DATA_PORT    ==		 PORTC
#define   LCD_DIRECTION_PORT     C
#elif LCD_DATA_PORT    ==		 PORTD
#define   LCD_DIRECTION_PORT     D
#endif*/

/*****************************************_INCLUDE_**********************************/
#define F_CPU 16000000UL
#include <util/delay.h>
#include "LcdCfg.h"
#include "Std.h"

/*****************************************_POROTYPES_********************************/
void H_Lcd_Void_Init(void);                   //this function used to initialization LCD 
void H_Lcd_Void_WriteCharacter(u8_t);     //this function used to send one character to LCD 
void H_Lcd_Void_WriteString( u8_t *);
void H_Lcd_Void_WriteCommand(u8_t);
void H_Lcd_Void_WriteNum(s32_t);
void H_Lcd_Void_ClrLcd(void);
void H_Lcd_Void_GoTo(u8_t, u8_t);




#endif /* LCD_H_ */