/*
 * SsdCfg.h
 *
 * Created: 2/9/2023 12:32:07 PM
 *  Author: Muhammed El Nabawy
 */ 


#ifndef SSDCFG_H_
#define SSDCFG_H_

#include "Dio.h"

#define SSD_MODE            DIRECT_MODE   // SELECT SSD MODE(DIRECT_MODE -> USING 8 BITS FROM MCU) 
										  //(DECODE_MODE -> USING ONLY 4 BITS FROM MCU, CONNECTED TO DECODER)
										  // SELECT TIME FOR DEBUNCING (DEPENDING ON QUALITY TYPE OF THE SWITCH)
#define SSD_A_PIN			PB0
#define SSD_B_PIN			PB1
#define SSD_C_PIN			PB2
#define SSD_D_PIN			PB3
#define SSD_E_PIN			PB4
#define SSD_F_PIN			PB5
#define SSD_G_PIN			PC0
#define SSD_1_ENABLE_PIN	PC1
#define SSD_2_ENABLE_PIN	PC2





#endif /* SSDCFG_H_ */