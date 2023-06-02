/*
 * Ssd.h
 *
 * Created: 2/9/2023 12:31:30 PM
 *  Author: Muhammed El Nabawy
 */ 


#ifndef SSD_H_
#define SSD_H_

/*****************************************_MACROS_***********************************/
#define F_CPU 16000000UL
#define  DIRECT_MODE      1
#define  DECODE_MODE      2

/*****************************************_INCLUDE_**********************************/
#include "SsdCfg.h"
#include <util/delay.h>
/*****************************************_POROTYPES_********************************/
void H_Ssd_Void_Init(void);                     // this function to initialization ssd pins
void H_Ssd_Void_Write(u8_t);                    // this function used to write numbers in ssd from users (included H_Ssd_Void_Display())
void H_Ssd_Void_CountUp(u8_t);                  // this function used to count up from zero to number which input as a parameter 
void H_Ssd_Void_CountDown(s8_t);                // this function used to count down from number which input as a parameter to zero






#endif /* SSD_H_ */