/*
 * PushButtonCfg.h
 *
 * Created: 2/6/2023 11:39:17 AM
 *  Author: Muhammed El Nabawy
 */ 


#ifndef PUSHBUTTONCFG_H_
#define PUSHBUTTONCFG_H_

#define F_CPU 16000000UL
#include <util/delay.h>
#include "Dio.h"

#define PUSH_BOTTON_1_PIN		PD2          //SELECT PUSH BUTTON PINS
#define PUSH_BOTTON_2_PIN		PD3          //SELECT PUSH BUTTON PINS
#define PUSH_BOTTON_3_PIN		PD4          //SELECT PUSH BUTTON PINS
#define PUSH_BOTTON_4_PIN		PD5          //SELECT PUSH BUTTON PINS

#define PUSH_BUTTON_MODE    ACTIVE_LOW   // SELECT PUSH BUTTON MODE(ACTIVE_LOW -> PULL UP RESISTOR) (ACTIVE_HIGH -> PULL DOWN RESISTOR)
#define DEBUNCING_TIME		140			// SELECT TIME FOR DEBUNCING (DEPENDING ON QUALITY TYPE OF THE SWITCH)




#endif /* PUSHBUTTONCFG_H_ */