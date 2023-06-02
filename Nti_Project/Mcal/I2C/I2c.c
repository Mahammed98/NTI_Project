/*
 * I2c.c
 *
 * Created: 5/20/2023 12:00:02 PM
 *  Author: Muhammed El Nabawy
 */ 
// master
#include "I2c.h"
void M_Void_I2c_MasterInit()
{
	// choose prescaler 
	#if    __PRESCALAR__    ==      1
		ClrBit(TWSR, TWPS0);
		ClrBit(TWSR, TWPS1);
	#elif  __PRESCALAR__    ==      4
		SetBit(TWSR, TWPS0);
		ClrBit(TWSR, TWPS1);
	#elif  __PRESCALAR__    ==      16
		ClrBit(TWSR, TWPS0);
		SetBit(TWSR, TWPS1);
	#elif  __PRESCALAR__    ==      64
		SetBit(TWSR, TWPS0);
		SetBit(TWSR, TWPS1);
	#else
		#error "WRONG PRESCALAR"
	#endif
	// select frequency
	TWBR = ((FCPU /__Frequancy__) - 16) / (2 * __PRESCALAR__);     //12
	// enable i2c
	TWCR = (1<<TWEN);  
	
}
void M_Void_I2c_SendStart(void)
{
	TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	while(GetBit(TWCR, TWINT) == 0);
}
void M_Void_I2c_RepeatStart(void)
{
	TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	while(GetBit(TWCR, TWINT) == 0); 
}
void M_Void_I2c_SendStop(void)
{
	TWCR = (1<<TWINT)|(1<<TWSTO)|(1<<TWEN);
	while(TWCR & (1<<TWSTO));
}

void M_Void_I2c_MSendData(u8_t copy_u8_Data)
{
	TWDR = copy_u8_Data ;
	TWCR = (1<<TWINT)|(1<<TWEN);
	while(GetBit(TWCR, TWINT) == 0);	
}
u8_t M_u8_I2c_MReadData(void)
{
	TWCR = (1<<TWINT)|(1<<TWEN);
	while(GetBit(TWCR, TWINT) == 0);
	return TWDR;	
}

//slave
void M_Void_I2c_SlaveInit(u8_t Copy_u8_Address)
{
	TWAR = Copy_u8_Address;
	SetBit(TWCR, TWEN);
}
void M_Void_I2c_SCheckAddress(void)
{
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);
	while(GetBit(TWCR, TWINT) == 0);
}
void M_Void_I2c_SSendData(u8_t copy_u8_Data)
{
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);
	TWDR = copy_u8_Data ;
	while(GetBit(TWCR, TWINT) == 0);
	
}
u8_t M_u8_I2c_SReadData(void)
{
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);
	while(GetBit(TWCR, TWINT) == 0);
	return TWDR;
	
}
u8_t M_u8_I2c_GetStatus(void)
{
	u8_t status = 0;
	status = (TWSR & 0xF8);
	return status;
}