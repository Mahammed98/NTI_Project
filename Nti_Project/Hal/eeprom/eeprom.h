/*
 * eeprom.h
 *
 * Created: 5/23/2023 10:43:55 AM
 *  Author: Muhammed El Nabawy
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_

#include "Std.h"
#include "Dio.h"
#include "I2c.h"

void H_Void_EEPROM_Init(void);
u8_t H_Void_EEPROM_Write(u16_t, u8_t);
u8_t H_Void_EEPROM_Read(u16_t, u8_t *);



#endif /* EEPROM_H_ */