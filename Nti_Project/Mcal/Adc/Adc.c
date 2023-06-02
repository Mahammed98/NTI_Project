/*
 * Adc.c
 *
 * Created: 3/14/2023 11:46:01 AM
 *  Author: Muhammed El Nabawy
 */ 
#include "Adc.h"
void M_Adc_Void_Init(void)
{
	#if    VOLTAGE_REF    ==     AREF
		ClrBit(ADMUX,7);
		ClrBit(ADMUX,6);
	#elif  VOLTAGE_REF    ==     VCC
		ClrBit(ADMUX,7);
		SetBit(ADMUX,6);
	#elif  VOLTAGE_REF    ==     INTERNAL
		SetBit(ADMUX,7);
		SetBit(ADMUX,6);
	#endif
	ClrBit(ADMUX,5);							//to right adjusting (8 bitS on ADCL,and first 2 bitS of ADCH)
	/*
		ADC read from ADC0 pin
	
	SetBit(ADMUX,0);
	ClrBit(ADMUX,1);
	ClrBit(ADMUX,2);
	ClrBit(ADMUX,3);
	*/
	
	SetBit(ADCSRA,7);							//ENABLE ADC
	SetBit(ADCSRA,5);							//ENABLE Auto trigger (renewable ACD REGISTER value when set this bit)  
	
	/*
		SET THE ADC PRESCALER 
	*/
	#if   PRESCALRE           ==     128
		SetBit(ADCSRA,0);
		SetBit(ADCSRA,1);
		SetBit(ADCSRA,2);
	#elif   PRESCALRE         ==     64
		ClrBit(ADCSRA,0);
		SetBit(ADCSRA,1);
		SetBit(ADCSRA,2);
	#elif   PRESCALRE         ==     32
		SetBit(ADCSRA,0);
		ClrBit(ADCSRA,1);
		SetBit(ADCSRA,2);
	#elif   PRESCALRE         ==     16
		ClrBit(ADCSRA,0);
		ClrBit(ADCSRA,1);
		SetBit(ADCSRA,2);
	#elif   PRESCALRE         ==     8
		SetBit(ADCSRA,0);
		SetBit(ADCSRA,1);
		ClrBit(ADCSRA,2);
	#elif   PRESCALRE         ==     4
		ClrBit(ADCSRA,0);
		SetBit(ADCSRA,1);
		ClrBit(ADCSRA,2);
	#elif   PRESCALRE         ==     2
		SetBit(ADCSRA,0);
		ClrBit(ADCSRA,1);
		ClrBit(ADCSRA,2);
	#endif
}
u16_t M_Adc_u16_Read(u8_t Local_u8_Num)
{
	switch (Local_u8_Num)
	{
		case A0:
			ClrBit(ADMUX,0);
			ClrBit(ADMUX,1);
			ClrBit(ADMUX,2);
			ClrBit(ADMUX,3);
			break;
		case A1:
			SetBit(ADMUX,0);
			ClrBit(ADMUX,1);
			ClrBit(ADMUX,2);
			ClrBit(ADMUX,3);
			break;
		case A2:
			ClrBit(ADMUX,0);
			SetBit(ADMUX,1);
			ClrBit(ADMUX,2);
			ClrBit(ADMUX,3);
			break;
		case A3:
			SetBit(ADMUX,0);
			SetBit(ADMUX,1);
			ClrBit(ADMUX,2);
			ClrBit(ADMUX,3);
			break;
		case A4:
			ClrBit(ADMUX,0);
			ClrBit(ADMUX,1);
			SetBit(ADMUX,2);
			ClrBit(ADMUX,3);
			break;
		case A5:
			SetBit(ADMUX,0);
			ClrBit(ADMUX,1);
			SetBit(ADMUX,2);
			ClrBit(ADMUX,3);
			break;
		case A6:
			ClrBit(ADMUX,0);
			SetBit(ADMUX,1);
			SetBit(ADMUX,2);
			ClrBit(ADMUX,3);
			break;
		case A7:
			SetBit(ADMUX,0);
			SetBit(ADMUX,1);
			SetBit(ADMUX,2);
			ClrBit(ADMUX,3);
			break;
		default:
			break;
	}	
	SetBit(ADCSRA,6);					            // START conversion 
	while(GetBit(ADCSRA,4) == 0);					// wait until conversion is completed (flag = 1)	

	return (ADCL | (ADCH << 8));
}
