/*
 * Led.h
 *
 * Created: 1/31/2023 7:40:16 PM
 *  Author: Muhammed El Nabawy
 */ 

#ifndef LED_H_
#define LED_H_

/*****************************************_MACROS_***********************************/
#define BLU_LED 1
#define GRE_LED 2
#define RED_LED 3
/*****************************************_INCLUDE_**********************************/
#define F_CPU 16000000UL
#include <util/delay.h>
#include "Dio.h"
#include "LedCfg.h"
/*****************************************_POROTYPES_********************************/
void H_Led_void_Init(u8_t);             //INTIALIZATION OF LED 
void H_Led_void_On(u8_t);				//TURN ON LED
void H_Led_void_Off(u8_t);				//TURN OFF LED
void H_Led_void_BlinkOnce(u8_t);		//LED BLINKING ONCE  (U MUST TURN OFF LED BEFOR CALL THIS FANCCTION)
void H_Led_void_BlinkTwice(u8_t);	    //LED BLINKING TWICE (U MUST TURN OFF LED BEFOR CALL THIS FANCCTION)
void H_Led_void_Toggle(u8_t);



#endif /* LED_H_ */