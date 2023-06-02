/*
 * UartCfg.h
 *
 * Created: 5/3/2023 5:30:39 PM
 *  Author: Muhammed El Nabawy
 */ 


#ifndef UARTCFG_H_
#define UARTCFG_H_
/*
* CHOOSE NUMBER OF STOP BITS
* 1- __UART_STOP_BITS_1__
* 2- __UART_STOP_BITS_2__
*/
#define Number_of_Bits          __UART_STOP_BITS_1__
/*
* CHOOSE PARITY TYPE 
* 1- __UART_NO_PARITY__
* 2- __UART_PARITY_EVEN__
* 3- __UART_PARITY_ODD__
*/
#define Parity_Type             __UART_NO_PARITY__
/*
*  choose data_size
* 1- __UART_DATA_SIZE_5__
* 2- __UART_DATA_SIZE_6__
* 3- __UART_DATA_SIZE_7__
* 4- __UART_DATA_SIZE_8__
*/
#define data_size               __UART_DATA_SIZE_8__

#endif /* UARTCFG_H_ */