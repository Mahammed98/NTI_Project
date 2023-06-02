/*
 * BiiMath.h
 *
 * Created: 1/28/2023 12:09:10 PM
 *  Author: Muhammed El Nabawy
 */ 
#ifndef BIIMATH_H_
#define BIIMATH_H_

#define SetBit(reg,bit)  reg|=(1<<bit)
#define ClrBit(reg,bit)  reg&= ~(1<<bit)
#define TogBit(reg,bit)  reg^=(1<<bit)
#define GetBit(reg,bit)  (1&(reg>>bit))


#endif /* BIIMATH_H_ */