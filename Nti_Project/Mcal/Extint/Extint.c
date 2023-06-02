/*
 * CFile1.c
 *
 * Created: 3/11/2023 12:44:46 PM
 *  Author: Muhammed El Nabawy
 */ 

#include "Extint.h"

void(*CallBack)(void);

void M_Void_ExtInt_Init(u8_t Local_u8_Num)
{
	switch(Local_u8_Num)
	{
		case 0: 
			#if    SENS_CONTROL           ==        RISING_EDGE
				SetBit(EICRA,0);
				SetBit(EICRA,1);
			#elif  SENS_CONTROL           ==        FALLING_EDGE
				ClrBit(EICRA,0);
				SetBit(EICRA,1);
			#elif  SENS_CONTROL           ==        LOW_LEVEL
				ClrBit(EICRA,0);
				ClrBit(EICRA,1);
			#elif  SENS_CONTROL           ==        LOGICAL_CHANGE
				SetBit(EICRA,0);
				ClrBit(EICRA,1);
			#endif
			SetBit(EIMSK,0);
		break;
		case 1:
			#if    SENS_CONTROL           ==        RISING_EDGE
				SetBit(EICRA,2);
				SetBit(EICRA,3);
			#elif  SENS_CONTROL           ==        FALLING_EDGE
				ClrBit(EICRA,2);
				SetBit(EICRA,3);
			#elif  SENS_CONTROL           ==        LOW_LEVEL
				ClrBit(EICRA,2);
				ClrBit(EICRA,3);
			#elif  SENS_CONTROL           ==        LOGICAL_CHANGE
				SetBit(EICRA,2);
				ClrBit(EICRA,3);
			#endif
			SetBit(EIMSK,1);
		break;
		default:									break;		
	}
	SetBit(SREG,7);                    // enable global interrupt 
}
void M_Void_ExtInt_SetCallBack(void(*ptr)(void))
{
	CallBack = ptr;
}
ISR(INT0_vect)              // EXTERNAL INTERRUPT FUNCTION 
{
	CallBack();             // POINTER TO FUNCTION
}