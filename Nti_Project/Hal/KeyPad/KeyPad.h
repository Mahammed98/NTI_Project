/*
 * KeyPad.h
 *
 * Created: 3/4/2023 12:24:43 PM
 *  Author: Muhammed El Nabawy
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

/*****************************************_MACROS_***********************************/
#define MODEL_1      1
#define MODEL_2      2
/*****************************************_INCLUDE_**********************************/
#define F_CPU 16000000UL
#include <util/delay.h>
#include "Dio.h"
#include "Std.h"
#include "KeyPadCfg.h"
/*****************************************_POROTYPES_********************************/
void H_Void_KeyPad_Init(void);
u8_t H_u8_KeyPad_Read(void);





#endif /* KEYPAD_H_ */