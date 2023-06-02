/*
 * Spi.h
 *
 * Created: 5/11/2023 8:16:25 AM
 *  Author: Muhammed El Nabawy
 */ 


#ifndef SPI_H_
#define SPI_H_

#include "Std.h"
#include "Dio.h"
#include "Reg.h"
#include "SpiCfg.h"
#include "SpiPrivate.h"


void M_Spi_Void_MasterInit(void);
void M_Spi_Void_SlaveInit(void);
u8_t M_Spi_u8_Transfer(u8_t);
u8_t M_Spi_u8_Recive(void);




#endif /* SPI_H_ */