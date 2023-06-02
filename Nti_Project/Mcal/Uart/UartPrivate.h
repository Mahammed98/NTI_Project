/*
 * UartPrivate.h
 *
 * Created: 5/3/2023 5:30:18 PM
 *  Author: Muhammed El Nabawy
 */ 


#ifndef UARTPRIVATE_H_
#define UARTPRIVATE_H_

#define UDR         *(volatile u8_t*)0xC6
#define UCSRC       *(volatile u8_t*)0xC2
#define UCSRB       *(volatile u8_t*)0xC1
#define UCSRA       *(volatile u8_t*)0xC0
#define UBRRH       *(volatile u8_t*)0xC5
#define UBRRL		*(volatile u8_t*)0xC4

// BITS OF UCSRA REGISTER
#define RXC                          7
#define TXC                          6
#define UDRE                         5
#define FE                           4
#define DOR                          3
#define UPE                          2
#define U2X                          1
#define PMCP                         0
// BITS OF UCSRB REGISTER            
#define RXCIE                        7
#define TXCIE                        6
#define UDRIE                        5
#define RXEN                         4
#define TXEN                         3
#define UCSZ2                        2
#define RXB8                         1
#define TXB8                         0
// BITS OF UCSRC REGISTER
#define UMSEL1                       7
#define UMSEL0                       6
#define UPM1                         5
#define UPM0                         4
#define USBS                         3
#define UCSZ1                        2
#define UCSZ0                        1
#define UCPOL0					     0
// uart number of stop bits
#define __UART_STOP_BITS_1__         0
#define __UART_STOP_BITS_2__         1
// uart parity type
#define __UART_NO_PARITY__           0
#define __UART_PARITY_EVEN__         2
#define __UART_PARITY_ODD__          3
// uart data size 
#define  __UART_DATA_SIZE_5__        0
#define  __UART_DATA_SIZE_6__        1
#define  __UART_DATA_SIZE_7__        2
#define  __UART_DATA_SIZE_8__        3
#define  __data_size_mask__      0b11111001

#endif /* UARTPRIVATE_H_ */