/*
 * Spi.c
 *
 * Created: 5/11/2023 8:15:34 AM
 *  Author: Muhammed El Nabawy
 */ 
#include "Spi.h"
void M_Spi_Void_MasterInit(void)
{
	//first:   enable SPI and enable master
	SetBit(SPCR, SPE);
    SetBit(SPCR, MSTR);
	//second: choose data order (MSB or LSB)
	#if (__SPI_DATA_ORDER__   == _MSB_FIRST_)
		ClrBit(SPCR,DORD);
	#elif (__SPI_DATA_ORDER__ == _LSB_FIRST_)
		SetBit(SPCR,DORD);
	#else
		#error "Wrong data order"
	#endif
	//third: choose  CLK polarity
	#if (__SPI_POLARITY__   == _LOW_POLARITY_)
		ClrBit(SPCR,CPOL);
	#elif (__SPI_POLARITY__ == _HIGH_POLARITY_) 
		SetBit(SPCR,CPOL);
	#else	
		#error "Wrong polarity"
	#endif
	//fourth: choose CLK phase
	#if (__SPI_PHASE__   == _SAMPLE_FIRST_)
		ClrBit(SPCR,CPHA);
	#elif (__SPI_PHASE__ == _SAMPLE_LAST_)
		SetBit(SPCR,CPHA);
	#else
		#error "Wrong CLK phase"
	#endif
	//fifth:  choose CLK speed (Normal or double)
	#if (__SPI_SPEED_MODE__   == _NORMAL_MODE_)
		ClrBit(SPSR,SPI2X);
	#elif (__SPI_SPEED_MODE__ == _DOUBLE_SPEED_MODE_)
		SetBit(SPSR,SPI2X);
	#else
		#error "Wrong CLK speed"
	#endif
	//sixth: choose CLK PRESCALER
	SPCR &= __SPI_PRESCALE_MASK__;
	SPCR |= __SPI_PRESCALER__;

}
void M_Spi_Void_SlaveInit(void)
{
	//first:   enable SPI and enable slave
	SetBit(SPCR, SPE);
	ClrBit(SPCR, MSTR);
	//second: choose data order (MSB or LSB)
	#if (__SPI_DATA_ORDER__   == _MSB_FIRST_)
		ClrBit(SPCR,DORD);
	#elif (__SPI_DATA_ORDER__ == _LSB_FIRST_)
		SetBit(SPCR,DORD);
	#else
		#error "Wrong data order"
	#endif
	//third: choose  CLK polarity
	#if (__SPI_POLARITY__   == _LOW_POLARITY_)
		ClrBit(SPCR,CPOL);
	#elif (__SPI_POLARITY__ == _HIGH_POLARITY_)
		SetBit(SPCR,CPOL);
	#else
		#error "Wrong polarity"
	#endif
	//fourth: choose CLK phase
	#if (__SPI_PHASE__   == _SAMPLE_FIRST_)
		ClrBit(SPCR,CPHA);
	#elif (__SPI_PHASE__ == _SAMPLE_LAST_)
		SetBit(SPCR,CPHA);
	#else
		#error "Wrong CLK phase"
	#endif
}
 u8_t M_Spi_u8_Transfer(u8_t Copy_u8_Data)
{	
	// first send data 
	SPDR = Copy_u8_Data;
	while(GetBit(SPSR,SPIF) == 0); //  polling until (data transfer)
	ClrBit(SPSR,SPIF);
	return SPDR;
}

