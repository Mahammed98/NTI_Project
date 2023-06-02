/*
 * Reg.h
 *
 * Created: 1/31/2023 3:01:49 PM
 *  Author: Muhammed El Nabawy
 */ 


#ifndef REG_H_
#define REG_H_

#define DDRB       *(volatile u8_t*)0x24
#define PORTB      *(volatile u8_t*)0x25
#define PINB       *(volatile u8_t*)0x23

#define DDRC       *(volatile u8_t*)0x27
#define PORTC      *(volatile u8_t*)0x28
#define PINC       *(volatile u8_t*)0x26

#define DDRD       *(volatile u8_t*)0x2A
#define PORTD      *(volatile u8_t*)0x2B
#define PIND       *(volatile u8_t*)0x29

#define EICRA      *(volatile u8_t*)0x69       // INTERRUPT REGISTER
#define EIMSK      *(volatile u8_t*)0x3D       // INTERRUPT REGISTER
#define SREG       *(volatile u8_t*)0x5F       // INTERRUPT REGISTER

#define ADMUX      *(volatile u8_t*)0x7C       // ADC REGISTER
#define ADCSRA     *(volatile u8_t*)0x7A       // ADC REGISTER
#define ADCH       *(volatile u8_t*)0x79       // ADC REGISTER
#define ADCL       *(volatile u8_t*)0x78       // ADC REGISTER

#endif /* REG_H_ */