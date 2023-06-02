/*
 * AdcCfg.h
 *
 * Created: 3/14/2023 11:46:24 AM
 *  Author: Muhammed El Nabawy
 */ 


#ifndef ADCCFG_H_
#define ADCCFG_H_

#define VOLTAGE_REF         VCC   //select voltage reference source(INTERNAL -> 1.1volt, VCC, AREF)


#define PRESCALRE           128  // SELECT THE PRESCALER OF ADC (NOTE :  ADC WORKNING ON 200KHz maximum)
							     //  2, 4, 8, 16, 32, 64, 128

#endif /* ADCCFG_H_ */