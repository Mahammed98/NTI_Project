/*
 * Dio.h
 *
 * Created: 1/31/2023 1:55:29 PM
 *  Author: Muhammed El Nabawy
 */ 

#ifndef DIO_H_
#define DIO_H_
/********************************************MACROS************************************/
#define INPUT       0
#define OUTPUT      1
#define LOW         0
#define HIGH        1

#define	B           1
#define	C           2
#define	D           3

#define PB0			10
#define PB1			11
#define PB2			12
#define PB3			13
#define PB4			14
#define PB5			15
#define PB6			16
#define PB7			17

#define PC0			20
#define PC1			21
#define PC2			22
#define PC3			23
#define PC4			24
#define PC5			25
#define PC6			26
#define PC7			27

#define PD0			30
#define PD1			31
#define PD2			32
#define PD3			33
#define PD4			34
#define PD5			35
#define PD6			36
#define PD7			37


/********************************************_INCLUDE**********************************/
#include "BitMath.h"
#include "Std.h"
#include "Reg.h"
/********************************************_PROTOTYPES_********************************/

/*
		This function used to change Pin state for any port in MCU
	u should pass two parameters, First: the pin which u want to change it's state
	{this Number in first parameter divided into two numbers 1-pin_number[ones]
	2- Port_Number[tens], second: the pin state {Output or input }
	  
	### the macros of pins_number, and Status is defined in Dio.h ###
*/

void M_Dio_Void_PinMode(u8_t, u8_t);            //PIN MODE (OUTPUT OR INPUT)
void M_Dio_Void_PinWrite(u8_t, u8_t);           //PIN STATU (LOW OR HIGH)
u8_t M_Dio_U8_PinRead(u8_t);
void M_Dio_Void_PinToggle(u8_t);                //PIN TOGGLED 
void M_Dio_Void_PortMode(u8_t, u8_t);
void M_Dio_Void_PortWrite(u8_t, u8_t);





#endif /* DIO_H_ */