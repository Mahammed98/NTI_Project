/*
 * Dio.c
 *
 * Created: 1/31/2023 1:55:40 PM
 *  Author: Muhammed El Nabawy
 */ 

/****************************************_INCLUDES_*************************************/
#include "Dio.h"
/************************************_FUNCTIONS_IMPLEMENTATION_************************/


void M_Dio_Void_PinMode(u8_t Local_u8_Num, u8_t Local_u8_Mode)
{
	u8_t Local_u8_Pin  = Local_u8_Num % 10;
	u8_t Local_u8_Port = Local_u8_Num / 10;
	
	switch(Local_u8_Mode)
	{
		case INPUT:
			switch(Local_u8_Port)
			{
				case 1: ClrBit(DDRB,Local_u8_Pin);	break;
				case 2: ClrBit(DDRC,Local_u8_Pin);	break;
				case 3: ClrBit(DDRD,Local_u8_Pin);	break;
				default:                            break;
			}
			break; // end first case 
			
		case OUTPUT:
		switch(Local_u8_Port)
		{
			case 1: SetBit(DDRB,Local_u8_Pin);	break;
			case 2: SetBit(DDRC,Local_u8_Pin);	break;
			case 3: SetBit(DDRD,Local_u8_Pin);	break;
			default:                            break;
		}
		break;		// end second case	
	    default:									break;
	}	
}// end function 

void M_Dio_Void_PinWrite(u8_t Local_u8_Num, u8_t Local_u8_Mode)
{	
	u8_t Local_u8_Pin  = Local_u8_Num % 10;
	u8_t Local_u8_Port = Local_u8_Num / 10;
	
	switch(Local_u8_Mode)
	{
		case LOW:
		switch(Local_u8_Port)
		{
			case 1: ClrBit(PORTB,Local_u8_Pin);	break;
			case 2: ClrBit(PORTC,Local_u8_Pin);	break;
			case 3: ClrBit(PORTD,Local_u8_Pin);	break;
			default:                            break;
		}
		break; // end first case
		
		case HIGH:
		switch(Local_u8_Port)
		{
			case 1: SetBit(PORTB,Local_u8_Pin);	break;
			case 2: SetBit(PORTC,Local_u8_Pin);	break;
			case 3: SetBit(PORTD,Local_u8_Pin);	break;
			default:                            break;
		}
		break;		// end second case
		default:									break;
	}
}// end function

u8_t M_Dio_U8_PinRead(u8_t Local_u8_Num)
{
	u8_t Local_u8_Pin  = Local_u8_Num % 10;
	u8_t Local_u8_Port = Local_u8_Num / 10;
	u8_t Local_u8_Read = 0;
	
	switch(Local_u8_Port)
	{
		case 1: Local_u8_Read = GetBit(PINB,Local_u8_Pin);	break;
		case 2: Local_u8_Read = GetBit(PINC,Local_u8_Pin);	break;
		case 3: Local_u8_Read = GetBit(PIND,Local_u8_Pin);	break;
		default:                            break;
	}
	 return Local_u8_Read;
}// end function 

void M_Dio_Void_PinToggle(u8_t Local_u8_Num)
{
	u8_t Local_u8_Pin  = Local_u8_Num % 10;
	u8_t Local_u8_Port = Local_u8_Num / 10;
	
		switch(Local_u8_Port)
		{
			case 1: TogBit(PORTB,Local_u8_Pin);	break;
			case 2: TogBit(PORTC,Local_u8_Pin);	break;
			case 3: TogBit(PORTD,Local_u8_Pin);	break;
			default:                            break;
		}
	
	
}// end function  

void M_Dio_Void_PortMode(u8_t Local_u8_Num, u8_t Local_u8_Mode)
{
		switch(Local_u8_Mode)
		{
			case INPUT:
			switch(Local_u8_Num)
			{
				case 1: DDRB = 0X00;	break;
				case 2: DDRC = 0X00;	break;
				case 3: DDRD = 0X00;	break;
				default:                break;
			}
			break; // end first case
			
			case OUTPUT:
			switch(Local_u8_Num)
			{
				case 1: DDRB = 0XFF;	break;
				case 2: DDRC = 0XFF;	break;
				case 3: DDRD = 0XFF;	break;
				default:                break;
			}
			break;		// end second case
			default:				    break;
		}
}
void M_Dio_Void_PortWrite(u8_t Local_u8_Num, u8_t Local_u8_Mode)
{
	switch(Local_u8_Mode)
	{
		case LOW:
		switch(Local_u8_Num)
		{
			case 1: PORTB = 0X00;	break;
			case 2: PORTC = 0X00;	break;
			case 3: PORTD = 0X00;	break;
			default:                break;
		}
		break; // end first case
		
		case HIGH:
		switch(Local_u8_Num)
		{
			case 1: PORTB = 0XFF;	break;
			case 2: PORTC = 0XFF;	break;
			case 3: PORTD = 0XFF;	break;
			default:                break;
		}
		break;		// end second case
		default:
			switch(Local_u8_Num)
			{
				case 1: PORTB = Local_u8_Mode;	break;
				case 2: PORTC = Local_u8_Mode;	break;
				case 3: PORTD = Local_u8_Mode;	break;
				default:					    break;
			}							
		break;
	}
}

