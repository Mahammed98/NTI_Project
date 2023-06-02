/*
 * PushButton.h
 *
 * Created: 2/6/2023 11:39:00 AM
 *  Author: Muhammed El Nabawy
 */ 


#ifndef PUSHBUTTON_H_
#define PUSHBUTTON_H_
/*****************************************_INCLUDE_**********************************/

#include "Std.h"
#include "PushButtonCfg.h"
#include "Dio.h"
/*****************************************_MACROS_***********************************/
#define PUSH_BUTTON_1         1
#define PUSH_BUTTON_2         2
#define PUSH_BUTTON_3         3
#define PUSH_BUTTON_4         4

#define  ACTIVE_LOW			 0
#define  ACTIVE_HIGH		 1
#if PUSH_BUTTON_MODE     ==   ACTIVE_LOW
#define PRESSED				 0
#define RELESED				 1
#elif PUSH_BUTTON_MODE   ==   ACTIVE_HIGH
#define PRESSED				 1
#define RELESED				 0
#endif

/*****************************************_POROTYPES_********************************/

void H_PushButton_Void_Init(u8_t);   // make pin as INPUT
u8_t H_PushButton_Void_Read(u8_t);   /* read pin, this function depend on connection of Push button 
										(pull up resistor or pull down resistor), 
										in our hardware it is pull up resistor, so, if (return 1 -> Not pressed in push button(defult)) 
										(return 0 -> pressed push button )
									*/





#endif /* PUSHBUTTON_H_ */