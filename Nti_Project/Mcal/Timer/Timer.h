/*
 * Timer0.h
 *
 * Created: 3/25/2023 1:20:22 PM
 *  Author: Muhammed El Nabawy
 */ 
/* 
		this file for sharing between main.c and driver 
*/
#ifndef TIMER0_H_
#define TIMER0_H_
/*****************************************_MACROS_***********************************/
#define __TIMER0_OVF_INT__       0
#define __TIMER0_CTC_INT__       1

#define __ICU_TRIGGER_RISING_EDGE__        1
#define __ICU_TRIGGER_FALLING_EDGE__       0
#include "Std.h"
#include "Dio.h"
#include "TimerPrivat.h"


/*****************************************_INCLUDE_**********************************/
/*****************************************_POROTYPES_********************************/
void M_Timer_Void_Timer0Init(void);							   // to initialization timer0 
void M_Timer_Void_Timer0Stop(void);							   // stop timer (no clk source)
void M_Timer_Void_Timer0Start(void);						   // start timer (give clk source)					
void M_Timer_Void_Timer0Preload(u8_t);						   // load value in timer register 
void M_Timer_Void_Timer0CompareMatch(u8_t, u8_t);			   // load value in OC register, first parameter take register value second parameter take 1 for OCOA, and 2 for OC0B
void M_Timer_Void_SetCallBack(void(*)(void), u8_t, u8_t);	   // call back function for ISR
void M_Timer_Void_InterruptEnable(u8_t, u8_t);				   // to enable interrupt first parameter for __TIMER0_OVF_INT__ or __TIMER0_CTC_INT__, second parameter take 1 for OCOA, and 2 for OC0B   
void M_Timer_Void_InterruptDisable(u8_t, u8_t);				   // to disable interrupt first parameter for __TIMER0_OVF_INT__ or __TIMER0_CTC_INT__, second parameter take 1 for OCOA, and 2 for OC0B   
void M_Timer_void_FastPwm_Write(u8_t, u8_t);                   // generate PWM from oc0a write 1, or oc0b write 2 
void M_Timer_void_PhaseCorrectPwm_Write(u8_t, u8_t);           // generate PWM from oc0a write 1, or oc0b write 2

void M_Timer_Void_Timer1Init(void);								// initialization of timer1 
void M_Timer_Void_ICUInit(void);                                // initialization of ICU
void M_Timer_ICUReadValue(u16_t*);								// read value from ICR register
void M_Timer_Void_ICUSetTrigger(u8_t);						    //changed edge of signal that causes interrupt 
void M_Timer_Void_ICUEnableInterrupt(void);						// enable interrupt
void M_Timer_Void_ICUDisableInterrupt(void);					// disable interrupt
void M_Timer_Void_ICUSetCallBack(void(*)(void));				// call back function for ISR



#endif /* TIMER0_H_ */