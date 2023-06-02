/*
 * Timer0Privat.h
 *
 * Created: 3/25/2023 1:21:34 PM
 *  Author: Muhammed El Nabawy
 */ 


#ifndef TIMER0PRIVAT_H_
#define TIMER0PRIVAT_H_

/*****************************************_MACROS_***********************************/
#define TCCR0A      *(volatile u8_t*)0x44       // Timer REGISTER
#define TCCR0B      *(volatile u8_t*)0x45       // Timer REGISTER
#define TCNT0       *(volatile u8_t*)0x46       // Timer REGISTER
#define OCR0A       *(volatile u8_t*)0x47       // Timer REGISTER
#define OCR0B       *(volatile u8_t*)0x48       // Timer REGISTER
#define TIMSK0      *(volatile u8_t*)0x6E       // Timer REGISTER
#define TIFR0       *(volatile u8_t*)0x49       // Timer REGISTER

/* 
	TIMER1 REGISTERS  	
*/

#define TCCR1B        *(volatile u8_t*)0x81        // Timer1 REGISTER
/*
	we use u16 variable to write on 16 bit register ICR1L & ICR1H 
	ICR1H come after ICR1L on register map, so we type casting u16 for pointer to write on 16bit
*/ 
		
#define ICR1          *(volatile u16_t*)0x86       // Timer1 REGISTER
#define TCNT1         *(volatile u16_t*)0x84       // Timer1 REGISTER

#define TIMSK1        *(volatile u8_t*)0x6F        // Timer1 REGISTER
#define TIFR1         *(volatile u8_t*)0x36        // Timer1 REGISTER


//Bits of TCCR0A register on Timer0
#define COM0A1      7
#define COM0A0      6
#define COM0B1      5
#define COM0B0      4
#define WGM01       1
#define WGM00       0
//Bits of TCCR0B register on Timer0
#define FOC0A      7
#define FOC0B      6
#define WGM02      3
#define CS02       2
#define CS01       1
#define CS00       0
//Bits of TIMSK0 register on Timer0
#define OCIE0B      2
#define OCIE0A      1
#define TOIE0       0
//Bits of TIFR0 register on Timer0
#define OCF0B      2
#define OCF0A      1
#define TOV0       0
// BITS OF TCCR1B REGISTER ON TIMER1 
#define CS10       0
#define CS11       1
#define CS12       2
#define ICES1      6
// BITS OF TIFR1 REGISTER ON TIMER1
#define ICF1       5
// TIMER0 MODES
#define TIMER0_NORMAL_MODE              0 
#define TIMER0_PHASE_CORRECT_MODE		1
#define TIMER0_CTC_MODE					2
#define TIMER0_FAST_PWM_MODE			3
// TIMER0 PRESCALLER
#define __NO_CLOCK_SOURCE__                          0
#define __NO_PRESCALLER__                            1
#define __TIMER0_PRESCALLER_8__                      2
#define __TIMER0_PRESCALLER_64__                     3
#define __TIMER0_PRESCALLER_256__                    4
#define __TIMER0_PRESCALLER_1024__                   5
#define __EXTERNAL_CLK_SOURCE_FALLIN_EDGE__          6               // COUNTER
#define __EXTERNAL_CLK_SOURCE_RISING_EDGE__          7               // COUNTER

#define __TIMER0_PRESCALLER_MASK__                   0b11111000      //PRESCALLER mask of tccr0b register

// TIMER0 OC0 MODE, IF TIMER0 ON CTC OR NORMAL MODE 
#define __TIMER0_OC0_MODE_DISCONNECTED__		     0
#define __TIMER0_OC0_MODE_TOGGLE__					 1
#define __TIMER0_OC0_MODE_CLEAR__					 2
#define __TIMER0_OC0_MODE_SET__						 3
// TIMER0 OC0 MODE, IF TIMER0 ON FAST PULSE WIDTH
#define  __TIMER0_OC0_MODE_NON_INVERTING_FAST_PWM__           0b00100000     // 32
#define  __TIMER0_OC0_MODE_INVERTING_FAST_PWM__               0b00110000     // 48
// TIMER0 OC0 MODE, IF TIMER0 ON PHASE CORRECT MODE 
#define  __TIMER0_OC0_MODE_NON_INVERTING_PHASE_CORRECT__           0b00100000     // 32
#define  __TIMER0_OC0_MODE_INVERTING_PHASE_CORRECT__               0b00110000     // 48

#define __TIMER0_OC0A_MASK__                   0b00111111      //OC0 mask of tccr0a register
#define __TIMER0_OC0B_MASK__                   0b11001111      //OC0 mask of tccr0a register








/*****************************************_INCLUDE_**********************************/

/*****************************************_POROTYPES_********************************/



#endif /* TIMER0PRIVAT_H_ */