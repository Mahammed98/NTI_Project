/*
 * KeyPadCfg.h
 *
 * Created: 3/4/2023 12:25:05 PM
 *  Author: Muhammed El Nabawy
 */
 /*
	Note: this driver is applicable for 4 bits in same port and pins behind each other 
 */

#ifndef KEYPADCFG_H_
#define KEYPADCFG_H_

#define KEYPAD_C3    PD3
#define KEYPAD_C2    PD2
#define KEYPAD_C1    PD1
#define KEYPAD_C0    PD0

#define KEYPAD_R0    PB0
#define KEYPAD_R1    PB1
#define KEYPAD_R2    PB2
#define KEYPAD_R3    PB3

#define DEBUNCING_TIME		120			// SELECT TIME FOR DEBUNCING (DEPENDING ON QUALITY TYPE OF THE SWITCH)
#define KEYPAD_MODEL        MODEL_1     // SELECT KEYPAD MODEL (MODEL_1 OR MODEL_2)


#endif /* KEYPADCFG_H_ */