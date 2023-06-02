/*
 * LM293.h
 *
 * Created: 5/31/2023 6:37:30 PM
 *  Author: Muhammed El Nabawy
 */ 


#ifndef LM293_H_
#define LM293_H_

#include "TimerCfg.h"
#include "Timer.h"

void H_Void_Lm293Init(void);
void H_Void_Lm293WritePwm(u8_t Copy_u8_Value, u8_t Copy_u8_PinId);



#endif /* LM293_H_ */