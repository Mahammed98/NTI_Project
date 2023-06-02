/*
 * TempSensor.h
 *
 * Created: 3/17/2023 11:27:04 AM
 *  Author: Muhammed El Nabawy
 */ 


#ifndef TEMPSENSOR_H_
#define TEMPSENSOR_H_


/*****************************************_MACROS_***********************************/
/*****************************************_INCLUDE_**********************************/
#include "Adc.h"
#include "Std.h"
/*****************************************_POROTYPES_********************************/
void  H_Void_TempSensor_Init(void);        // initialization temperature sensor
u16_t H_u16_TempSensor_Read(u8_t);         // read data from temperature sensor, this function take analog pin as parameter 


#endif /* TEMPSENSOR_H_ */