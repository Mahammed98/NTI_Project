/*
 * Uart.h
 *
 * Created: 5/3/2023 5:30:59 PM
 *  Author: Muhammed El Nabawy
 */ 


#ifndef UART_H_
#define UART_H_

#include "Std.h"
#include "Dio.h"
#include "Reg.h"
#include "BitMath.h"
#include "UartCfg.h"
#include "UartPrivate.h"

void M_Uart_Void_Init(u32_t);
void M_Uart_Void_SendChar(u8_t);
u8_t M_Uart_Void_ReciveChar(void);
void M_Uart_Void_SendString( u8_t *);

#endif /* UART_H_ */