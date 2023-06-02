/*
 * I2c.h
 *
 * Created: 5/20/2023 11:59:16 AM
 *  Author: Muhammed El Nabawy
 */ 


#ifndef I2C_H_
#define I2C_H_

#include "Std.h"
#include "BitMath.h"
#include "I2cPrivate.h"
#include "I2cCfg.h"

//Master Transmitter
#define TWI_M_T_START_SUCCESS                0x08 //A START condition has been  transmitted
#define TWI_M_T_REPETATED_START_SUCCESS      0x10 //A repeated START condition has been transmitted
#define TWI_M_T_ADDRESS_ACK                  0x18 //SLA+W has been transmitted;ACK has been received
#define TWI_M_T_ADDRESS_NO_ACK               0x20 //SLA+W has been transmitted;NO ACK has been received
#define TWI_M_T_DATA_ACK                     0x28 //Data byte has been transmitted, ACK has been received
#define TWI_M_T_DATA_NO_ACK                  0x30// Data byte has been transmitted,NO ACK has been received
#define TWI_M_T_ARBITRATION_LOST             0x38 //Arbitration lost in SLA+W or data bytes

//Master Receiver
#define TWI_M_R_START_SUCCESS                0x08 //A START condition has been  transmitted
#define TWI_M_R_REPETATED_START_SUCCESS      0x10 //A repeated START condition has been transmitted
#define TWI_M_R_ADDRESS_ACK                  0x40 //SLA+R has been transmitted;ACK has been received
#define TWI_M_R_ADDRESS_NO_ACK               0x48 //SLA+R has been transmitted;NO ACK has been received
#define TWI_M_R_DATA_ACK                     0x50 //Data byte has been received;ACK has been returned
#define TWI_M_R_DATA_NO_ACK                  0x58// Data byte has been received;NO ACK has been returned
#define TWI_M_R_ARBITRATION_LOST             0x38 //Arbitration lost in SLA+W or data bytes

// master
void M_Void_I2c_MasterInit(void);
void M_Void_I2c_SendStart(void);
void M_Void_I2c_RepeatStart(void);
void M_Void_I2c_SendStop(void);
void M_Void_I2c_MSendAddress_ReadRq(u8_t copy_u8_Data);
void M_Void_I2c_MSendAddress_WriteRq(u8_t copy_u8_Data);
void M_Void_I2c_MSendData(u8_t copy_u8_Data);
u8_t M_u8_I2c_MReadData(void);

//slave
void M_Void_I2c_SlaveInit(u8_t Copy_u8_Address);
void M_Void_I2c_SCheckAddress(void);
void M_Void_I2c_SSendData(u8_t copy_u8_Data);
u8_t M_u8_I2c_SReadData(void);

u8_t M_u8_I2c_GetStatus(void);


#endif /* I2C_H_ */