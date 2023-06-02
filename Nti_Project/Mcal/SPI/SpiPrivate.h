/*
 * SpiPrivate.h
 *
 * Created: 5/11/2023 8:15:59 AM
 *  Author: Muhammed El Nabawy
 */ 


#ifndef SPIPRIVATE_H_
#define SPIPRIVATE_H_

#define  SPCR		*(volatile u8_t*)0x4C
#define  SPSR		*(volatile u8_t*)0x4D
#define  SPDR		*(volatile u8_t*)0x4E

// BITS OF SPCR REGISTER
#define SPIE                          7            // spi inteerrupt enable
#define SPE                           6            // spi enable
#define DORD                          5            // data orderd  msb or lsb
#define MSTR                          4            //master or slave 
#define CPOL                          3            // spi clock polarity
#define CPHA                          2            // spi clock phase
#define SPR1                          1            // spi prescaler
#define SPR0                          0            // spi prescaler
// BITS OF SPSR REGISTER
#define SPIF                          7            // spi flag (transfer complete)
#define WCOL                          6            // collision flag
#define SPI2X                         0            //double speed mode 


#define _LOW_POLARITY_				  0
#define _HIGH_POLARITY_				  1
 
#define _SAMPLE_FIRST_                0	
#define _SAMPLE_LAST_                 1

#define _MSB_FIRST_				      0
#define _LSB_FIRST_				      1

#define _NORMAL_MODE_                 0
#define _DOUBLE_SPEED_MODE_           1

#define __SPI_PRESCALE_MASK__     0b11111100

#define _SPI_PRESCALE_NORMAL_4        0
#define _SPI_PRESCALE_NORMAL_16       1
#define _SPI_PRESCALE_NORMAL_64       2
#define _SPI_PRESCALE_NORMAL_128      3


#define _SPI_PRESCALE_DOUBLE_2        0
#define _SPI_PRESCALE_DOUBLE_8        1
#define _SPI_PRESCALE_DOUBLE_32       2
#define _SPI_PRESCALE_DOUBLE_64       3


#endif /* SPIPRIVATE_H_ */