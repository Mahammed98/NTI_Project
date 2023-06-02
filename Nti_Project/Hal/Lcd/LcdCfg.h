/*
 * LcdCfg.h
 *
 * Created: 2/15/2023 5:06:45 PM
 *  Author: Muhammed El Nabawy
 */ 


#ifndef LCDCFG_H_
#define LCDCFG_H_

#define LCD_MODE             _4_BIT_MODE_			/*
														Select LCD mode (__8_BIT_MODE_COMMAND_) or (_4_BIT_MODE_COMMAND_)
													*/



#define SHITH_BITS          0					    /*
														select  0, if connect first 4 bit in port (b0-> d4, b1-> d5, b2-> d6, b3-> d7)
														select  4, if connect last  4 bit in port (b4-> d4, b5-> d5, b6-> d6, b7-> d7)
														
													 */
#define  __ANDING__VALUE__              0b11110000
													/*
														select  0b11110000, if connect first 4 bit in port (b0-> d4, b1-> d5, b2-> d6, b3-> d7)
														select  0b00001111, if connect last  4 bit in port (b4-> d4, b5-> d5, b6-> d6, b7-> d7)
														
													 */
#define LCD_DATA_PORT        PORTC					// DATA BAS
#define LCD_DATA_PIN_7       PC3
#define LCD_DATA_PIN_6       PC2
#define LCD_DATA_PIN_5       PC1
#define LCD_DATA_PIN_4       PC0
#define LCD_EN_PIN           PD7					// PIN TO ENABLE LCD
#define LCD_RS_PIN           PD4					/* 
														RS PIN (IF HIGH-> SENT CHARACTER (DATA REGISTER )),
														ELSE IF( LOW-> SENT COMMAND (COMMAND REGISTER) )
													*/





#endif /* LCDCFG_H_ */