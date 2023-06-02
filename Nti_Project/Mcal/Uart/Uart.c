/*
 * Uart.c
 *
 * Created: 5/3/2023 5:29:57 PM
 *  Author: Muhammed El Nabawy
 */ 
#define F_CPU 16000000
#include <util/delay.h>
#include "Uart.h"
void M_Uart_Void_Init(u32_t Copy_u32_BaudRate)
{
	u16_t Local_u16_BaudRateValue;
//ENABLE TX, RX
	SetBit(UCSRB,RXEN);
	SetBit(UCSRB,TXEN);
// SET AS A ASYNCROUNACE 
	ClrBit(UCSRC, UMSEL0);
	ClrBit(UCSRC, UMSEL1);	
//STOP BITS (ONE OR TWO)
	#if   Number_of_Bits    ==     __UART_STOP_BITS_1__
		ClrBit(UCSRC, USBS);
	#elif Number_of_Bits    ==     __UART_STOP_BITS_2__
		SetBit(UCSRC, USBS);
	#else
		#error "wrong stop bits Number"
	#endif
//PARITY (EVEN OR ODD)
	#if   Parity_Type    ==     __UART_NO_PARITY__
		ClrBit(UCSRC, UPM0);
		ClrBit(UCSRC, UPM1);
	#elif Parity_Type    ==     __UART_PARITY_EVEN__
		ClrBit(UCSRC, UPM0);
		SetBit(UCSRC, UPM1);
	#elif Parity_Type    ==     __UART_PARITY_ODD__
		SetBit(UCSRC, UPM0);
		ClrBit(UCSRC, UPM1);
	#else
		#error "wrong parity type"
	#endif
//DATA BITS (5-9)
#if ((data_size == __UART_DATA_SIZE_5__)||(data_size == __UART_DATA_SIZE_6__)||(data_size == __UART_DATA_SIZE_7__)||(data_size == __UART_DATA_SIZE_8__))
	UCSRC &= __data_size_mask__;
	UCSRC |=   data_size << 1;
	//ClrBit(UCSRB, UCSZ2);
#else 
	#error "wrong data size"
#endif

//BAUD RATE
 Local_u16_BaudRateValue = (F_CPU/16/ Copy_u32_BaudRate) - 1;
 UBRRL = Local_u16_BaudRateValue;
 UBRRH = Local_u16_BaudRateValue >> 8;
}
void M_Uart_Void_SendChar(u8_t Copy_u8_Character)
{
	// polling wait until  transmitter register is empty
	while(GetBit(UCSRA, UDRE) == 0);
	UDR = Copy_u8_Character;

}
u8_t M_Uart_Void_ReciveChar(void)
{	
	// polling wait until  transmitter register is empty
	while(GetBit(UCSRA, RXC) == 0);
	return UDR;
}
void M_Uart_Void_SendString( u8_t *Copy_u8_Ptr)
{
	u32_t Local_u8_Increament = 0;
	while(Copy_u8_Ptr[Local_u8_Increament] != '\0')
	{
		M_Uart_Void_SendChar(Copy_u8_Ptr[Local_u8_Increament]);
		Local_u8_Increament++;
	}
}