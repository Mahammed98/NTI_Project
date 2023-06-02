/*
 * Timer0.c
 *
 * Created: 3/25/2023 1:20:06 PM
 *  Author: Muhammed El Nabawy
 */ 
#include "Std.h"
#include "Dio.h"
#include "BitMath.h"
#include "TimerPrivat.h"
#include "TimerCfg.h"
#include "Timer.h"
#include <avr/interrupt.h>
/******************* global variable *********************************/
void (*ptr_CallBack[3])(void);  // this is for timer 0
void (*ptr_CallBackIcu)(void);  // this for ICU on timer1 
void M_Timer_Void_Timer0Init(void)
{
	/************************** first chose timer mode ***********************/
	#if		TIMER0_MODE     ==   TIMER0_NORMAL_MODE
		ClrBit(TCCR0A,WGM00);
		ClrBit(TCCR0A,WGM01);
		ClrBit(TCCR0B,WGM02);
		#if ((__TIMER0_OC0A_MODE__ >= 0) && (__TIMER0_OC0A_MODE__ <= 3))
			TCCR0A &= __TIMER0_OC0A_MASK__;               // COM0A1, COM0A0 to ensure this two bits equal to zero
			TCCR0A |=( __TIMER0_OC0A_MODE__ << 6);	      // chose OC0A MODE
		#else
			#error "__WRONG__OC0A_NORMAL__MODE__"
		#endif
		
		#if	((__TIMER0_OC0B_MODE__ >= 0) && (__TIMER0_OC0B_MODE__ <= 3))
			TCCR0A &= __TIMER0_OC0B_MASK__;               // COM0B1, COM0B0 to ensure this two bits equal to zero
			TCCR0A |= (__TIMER0_OC0B_MODE__ << 4);	      // chose OC0B MODE
		#else
			#error "__WRONG__OC0B_NORMAL__MODE__"
		#endif	
	#elif	TIMER0_MODE     ==   TIMER0_PHASE_CORRECT_MODE
		SetBit(TCCR0A,WGM00);
		ClrBit(TCCR0A,WGM01);
		ClrBit(TCCR0B,WGM02);	
		#if ((__TIMER0_OC0A_MODE__ == __TIMER0_OC0_MODE_NON_INVERTING_PHASE_CORRECT__) || (__TIMER0_OC0A_MODE__ == __TIMER0_OC0_MODE_INVERTING_PHASE_CORRECT__) || (__TIMER0_OC0A_MODE__ == __TIMER0_OC0_MODE_DISCONNECTED__))  // phase correct
			TCCR0A |= (__TIMER0_OC0A_MODE__<< 2) ;
		#else
			#error "__WRONG__OC0A_PHASE_CORRECT__MODE__"
		#endif
		#if ((__TIMER0_OC0B_MODE__ == __TIMER0_OC0_MODE_NON_INVERTING_PHASE_CORRECT__) || (__TIMER0_OC0B_MODE__ == __TIMER0_OC0_MODE_INVERTING_PHASE_CORRECT__) || (__TIMER0_OC0B_MODE__ == __TIMER0_OC0_MODE_DISCONNECTED__))	// phase correct
			TCCR0A |= __TIMER0_OC0B_MODE__ ;             // don't make shifting
		#else
			#error "__WRONG__OC0B_PHASE_CORRECT__MODE__"
		#endif
	#elif	TIMER0_MODE     ==   TIMER0_CTC_MODE
		ClrBit(TCCR0A,WGM00);
		SetBit(TCCR0A,WGM01);
		ClrBit(TCCR0B,WGM02);
		
		#if ((__TIMER0_OC0A_MODE__ >= 0) && (__TIMER0_OC0A_MODE__ <= 3))
			TCCR0A &= __TIMER0_OC0A_MASK__;               // COM0A1, COM0A0 to ensure this two bits equal to zero
			TCCR0A |=( __TIMER0_OC0A_MODE__ << 6);	      // chose OC0A MODE
		#else
			#error "__WRONG__OC0A_CTC__MODE__"
		#endif	
		#if	((__TIMER0_OC0B_MODE__ >= 0) && (__TIMER0_OC0B_MODE__ <= 3))
			TCCR0A &= __TIMER0_OC0B_MASK__;               // COM0B1, COM0B0 to ensure this two bits equal to zero
			TCCR0A |= (__TIMER0_OC0B_MODE__ << 4);	      // chose OC0B MODE
		#else
			#error "__WRONG__OC0B_CTC__MODE__"
		#endif
	#elif	TIMER0_MODE     ==   TIMER0_FAST_PWM_MODE
		SetBit(TCCR0A,WGM00);
		SetBit(TCCR0A,WGM01);
		ClrBit(TCCR0B,WGM02);
		#if (__TIMER0_OC0A_MODE__ == __TIMER0_OC0_MODE_NON_INVERTING_FAST_PWM__) || ((__TIMER0_OC0A_MODE__ == __TIMER0_OC0_MODE_INVERTING_FAST_PWM__) || (__TIMER0_OC0A_MODE__ == __TIMER0_OC0_MODE_DISCONNECTED__))	// fast pwm
			TCCR0A |= (__TIMER0_OC0A_MODE__<< 2);
		#else
			#error "__WRONG__OC0A_NORMAL__MODE__"
		#endif	
		#if (__TIMER0_OC0B_MODE__ == __TIMER0_OC0_MODE_NON_INVERTING_FAST_PWM__) || ((__TIMER0_OC0B_MODE__ == __TIMER0_OC0_MODE_INVERTING_FAST_PWM__) || (__TIMER0_OC0B_MODE__ == __TIMER0_OC0_MODE_DISCONNECTED__))	// fast pwm
			TCCR0A |= __TIMER0_OC0B_MODE__ ;             // don't make shifting
		#else
			#error "__WRONG__OC0B _NORMAL__MODE__"	
		#endif	
	#else
		#error "__WRONG__TIMER__MODE__"
	#endif	 	   
}// end function  
void M_Timer_Void_Timer0Stop(void)
{
	TCCR0B &= __TIMER0_PRESCALLER_MASK__;   // CS02, CS01, CS00 reset this three bits, no CLK source	
	TCCR0B |= __NO_CLOCK_SOURCE__;          // chose PRESCALLER MODE

}// end function 
void M_Timer_Void_Timer0Start(void)
{
	TCCR0B &= __TIMER0_PRESCALLER_MASK__;   // CS02, CS01, CS00 to ensure this three bits equal to  zero,(no CLK source)
	TCCR0B |= __TIMER0_PRESCALLER__;        // chose PRESCALLER MODE
}// end function 
void M_Timer_Void_Timer0Preload(u8_t Copy_u8_Preload)
{
	TCNT0 = Copy_u8_Preload; 
}// end function 
void M_Timer_Void_Timer0CompareMatch(u8_t Copy_u8_CmpMatch, u8_t Copy_u8_Value)
{
	switch(Copy_u8_Value)
	{
		case 1: OCR0A = Copy_u8_CmpMatch; break;
		case 2: OCR0B = Copy_u8_CmpMatch; break;
		default:						  break;		
	}
} // end function 
void M_Timer_Void_SetCallBack(void(*Copy_Void_ptrCallBack)(void),u8_t Copy_u8_Id, u8_t Copy_u8_OcId)
{
	switch(Copy_u8_Id)
	{
		case __TIMER0_OVF_INT__:
			ptr_CallBack[__TIMER0_OVF_INT__] = Copy_Void_ptrCallBack;
			break;
		case __TIMER0_CTC_INT__:
			switch(Copy_u8_OcId)
			{
				case 1:
					ptr_CallBack[1] = Copy_Void_ptrCallBack;
					break;
				case 2:
					ptr_CallBack[2] = Copy_Void_ptrCallBack;
					break;
				default:
					break;
			}
			break;
		default:
			return;
	}
}// end function 
void M_Timer_Void_InterruptEnable(u8_t Copy_u8_Id, u8_t Copy_u8_OcId)
{
	switch(Copy_u8_Id)
	{
		case __TIMER0_OVF_INT__:
			SetBit(TIMSK0,TOIE0);
			break;
		case __TIMER0_CTC_INT__:
			switch(Copy_u8_OcId)
			{
				case 1:
					SetBit(TIMSK0,OCIE0A);
					break;
				case 2:
					SetBit(TIMSK0,OCIE0B);	
					break;
				default: 
					break;
			}
		default:
			break;
	}
}// end function 
void M_Timer_Void_InterruptDisable(u8_t Copy_u8_Id, u8_t Copy_u8_OcId)
{
	switch(Copy_u8_Id)
		{
			case __TIMER0_OVF_INT__:
				ClrBit(TIMSK0,TOIE0);
				break;
			case __TIMER0_CTC_INT__:
				switch(Copy_u8_OcId)
				{
					case 1:
						ClrBit(TIMSK0,OCIE0A);
						break;
					case 2:
						ClrBit(TIMSK0,OCIE0B);	
						break;
					default: 
						break;
				}
			default:
				break;
		}
}// end function 
void M_Timer_void_FastPwm_Write(u8_t Copy_u8_DutyCycle, u8_t Copy_u8_OcId)
{
	switch(Copy_u8_OcId)
	{
		case 1:         // OC0A register 
			#if (__TIMER0_OC0A_MODE__ == __TIMER0_OC0_MODE_NON_INVERTING_FAST_PWM__)
				OCR0A = ((256 * Copy_u8_DutyCycle)/100) - 1;
			#elif (__TIMER0_OC0A_MODE__ == __TIMER0_OC0_MODE_INVERTING_FAST_PWM__)
				OCR0A = 255 - ((256 * Copy_u8_DutyCycle)/100);
			#else	
				#error "__WRONG_OC0_MODE__"
			#endif		
				break;
		case 2:			// OC0B register 
			#if (__TIMER0_OC0B_MODE__ == __TIMER0_OC0_MODE_NON_INVERTING_FAST_PWM__)
				OCR0B = ((256 * Copy_u8_DutyCycle)/100) - 1;
			#elif (__TIMER0_OC0B_MODE__ == __TIMER0_OC0_MODE_INVERTING_FAST_PWM__)
				OCR0B = 255 - ((256 * Copy_u8_DutyCycle)/100);
			#else
				#error "__WRONG_OC0_MODE__"
			#endif		
				break;
		default:
				break;
	}	
}
void M_Timer_void_PhaseCorrectPwm_Write(u8_t Copy_u8_DutyCycle, u8_t Copy_u8_OcId)
{
	switch(Copy_u8_OcId)
	{
		case 1:         // OC0A register
			#if (__TIMER0_OC0A_MODE__ == __TIMER0_OC0_MODE_NON_INVERTING_PHASE_CORRECT__)
				OCR0A = (255 * Copy_u8_DutyCycle)/100;
			#elif (__TIMER0_OC0A_MODE__ == __TIMER0_OC0_MODE_INVERTING_PHASE_CORRECT__)
				OCR0A = 255 - ((255 * Copy_u8_DutyCycle)/100);
			#endif
				break;
		case 2:			// OC0B register
			#if (__TIMER0_OC0B_MODE__ == __TIMER0_OC0_MODE_NON_INVERTING_PHASE_CORRECT__)
				OCR0B = (255 * Copy_u8_DutyCycle)/100;
			#elif (__TIMER0_OC0B_MODE__ == __TIMER0_OC0_MODE_INVERTING_PHASE_CORRECT__)
				OCR0B = 255 - ((255 * Copy_u8_DutyCycle)/100);
			#endif
				break;
		default:
				break;
	}
}                  

ISR(TIMER0_OVF_vect)
{
	ptr_CallBack[0]();	
} // for over flow interrupt 

ISR(TIMER0_COMPA_vect)
{	
	ptr_CallBack[1]();
} // for compare interrupt 
ISR(TIMER0_COMPB_vect)
{
	ptr_CallBack[2]();
} // for compare interrupt

/*
*
*
*
*				                              ICU	
*											  
*	NOTE: when edge selected is coming the TCNT1 register take screenshot, and save it in ICR register 
*
*
*
*/
void M_Timer_Void_Timer1Init(void)
{
	/* 
		this function to initialization timer1 as ICU
		TIMER1 -> ON NORMAL MODE, AND WORK ON 8CLK PRESCALLER 
		
	*/
	SetBit(TCCR1B,CS10);
	ClrBit(TCCR1B,CS11);
	ClrBit(TCCR1B,CS12);
}
void M_Timer_Void_ICUInit(void)
{
	// SET TRIGGER, AND ENABLE INTERRUPTE
	SetBit(TCCR1B,ICES1); // SET TRIGGER ON RISING EDGE
	SetBit(TIMSK1,ICIE1); // ENABLE INTERRUPTE
	#warning "this function should be continued "

}
void M_Timer_ICUReadValue(u16_t *Copy_u16_PointerValue)
{
	*Copy_u16_PointerValue = ICR1;
}
void M_Timer_Void_ICUSetTrigger(u8_t Copy_u8_Trigger)
{
	switch(Copy_u8_Trigger)
	{
		case __ICU_TRIGGER_FALLING_EDGE__:
			ClrBit(TCCR1B,ICES1); // SET TRIGGER ON FALLING EDGE
			break;
		case __ICU_TRIGGER_RISING_EDGE__:
			SetBit(TCCR1B,ICES1); // SET TRIGGER ON RISING EDGE
			break;
		default:
			break;	
	}
}
void M_Timer_Void_ICUEnableInterrupt(void)
{
	SetBit(TIMSK1,ICIE1); // ENABLE INTERRUPTE
}
void M_Timer_Void_ICUDisableInterrupt(void)
{
	ClrBit(TIMSK1,ICIE1); // DISABLE INTERRUPTE
}
void M_Timer_Void_ICUSetCallBack(void(*Copy_Void_ptrCallBack)(void))	   
{
	ptr_CallBackIcu = Copy_Void_ptrCallBack;
}
ISR(TIMER1_CAPT_vect)
{
	ptr_CallBackIcu();
}