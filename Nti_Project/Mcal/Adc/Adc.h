/*
 * Adc.h
 *
 * Created: 3/14/2023 11:46:10 AM
 *  Author: Muhammed El Nabawy
 */ 


#ifndef ADC_H_
#define ADC_H_


/*****************************************_MACROS_***********************************/
#define AREF       1
#define VCC		   2
#define INTERNAL   3

#define  A0        0
#define  A1        1
#define  A2        2
#define  A3        3
#define  A4        4
#define  A5        5
#define  A6        6
#define  A7        7

/*****************************************_INCLUDE_**********************************/
#include "AdcCfg.h"
#include "Dio.h"
#include "Std.h"
#include "Reg.h"
/*****************************************_POROTYPES_********************************/
void M_Adc_Void_Init(void);       // to initialization analog pin 
u16_t M_Adc_u16_Read(u8_t);       // to read data from analog pin, which you taken as parameter
 
#endif /* ADC_H_ */