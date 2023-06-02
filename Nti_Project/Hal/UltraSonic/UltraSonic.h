/*
 * UltraSonic.h
 *
 * Created: 4/27/2023 1:53:10 PM
 *  Author: Muhammed El Nabawy
 */ 

/*
*	THIS driver for ultrasonic sensor that is used for measuring the distance 
*	but using some restricted  conditions: using 2 or more ultrasonic sensor on one ICU pin
*	that connected to echo pin of sensor, and connecting trigger pin to any GPIO pin
*/
#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_
#include "Std.h"
#include "UltraSonicCfg.h"

typedef struct __ULTRA_SONIC__
{
	u8_t _ULtra_Sonic_Pin;	
}UltraSonic;
void H_UltraSonic_Void_Init(void);
u8_t H_ULtraSonic_u8_ReadDistace(u8_t);
void M_Timer_Void_UltraSonicSetCallBack(void(*)(void));

#endif /* ULTRASONIC_H_ */