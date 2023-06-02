/*
 * I2cPrivate.h
 *
 * Created: 5/20/2023 11:59:50 AM
 *  Author: Muhammed El Nabawy
 */ 


#ifndef I2CPRIVATE_H_
#define I2CPRIVATE_H_

#define TWDR    *(volatile u8_t *)0xBB
#define TWBR    *(volatile u8_t *)0xB8
#define TWCR    *(volatile u8_t *)0xBC
#define TWSR    *(volatile u8_t *)0xB9
#define TWAR    *(volatile u8_t *)0xBA
#define TWAMR   *(volatile u8_t *)0xBD


// bits for TWCR register
#define TWINT         7
#define TWEA          6
#define TWSTA         5
#define TWSTO         4
#define TWWC          3
#define TWEN          2
#define TWIE          0

// bits for TWSR register
#define TWPS1          1
#define TWPS0          0

// bits for TWAR register
#define TWGCE          0


#endif /* I2CPRIVATE_H_ */