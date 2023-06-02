/*
 * Extint.h
 *
 * Created: 3/11/2023 12:45:10 PM
 *  Author: Muhammed El Nabawy
 */ 


#ifndef EXTINT_H_
#define EXTINT_H_
#include "Reg.h"
#include "BitMath.h"
#include "Dio.h"
#include "ExtintCfg.h"
#include <avr/interrupt.h>

/*****************************************_MACROS_***********************************/
#define ExtInt0     0
#define ExtInt1     1

#define FALLING_EDGE         0
#define RISING_EDGE          1
#define LOW_LEVEL            2 
#define LOGICAL_CHANGE       3
/*****************************************_INCLUDE_**********************************/
/*****************************************_POROTYPES_********************************/
void M_Void_ExtInt_Init(u8_t);           // to initialization external interrupt 
void M_Void_ExtInt_SetCallBack(void(*)(void));    /*
													 this function take pointer to function, that pointed to 
													 function that including functions done after interrupt is occurred 
												  */

#endif /* EXTINT_H_ */