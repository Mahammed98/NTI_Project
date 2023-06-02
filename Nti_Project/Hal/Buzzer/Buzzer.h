/*
 * Buzzer.h
 *
 * Created: 2/25/2023 12:27:29 PM
 *  Author: Muhammed El Nabawy
 */ 


#ifndef BUZZER_H_
#define BUZZER_H_
/*****************************************_MACROS_***********************************/

/*****************************************_INCLUDE_**********************************/
#include "BuzzerCfg.h"
#include "Dio.h"
/*****************************************_POROTYPES_********************************/
void H_Buzzer_Void_Init(void);
void H_Buzzer_Void_On(void);
void H_Buzzer_Void_Off(void);
void H_Buzzer_Void_Once(void);
void H_Buzzer_Void_Twice(void);
void H_Buzzer_Void_Triple(void);
void H_Buzzer_Void_OnceLong(void);







#endif /* BUZZER_H_ */