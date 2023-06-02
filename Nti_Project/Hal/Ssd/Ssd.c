/*
 * Ssd.c
 *
 * Created: 2/9/2023 12:31:43 PM
 *  Author: Muhammed El Nabawy
 */ 
#include "Ssd.h"
static void H_Ssd_Void_Display(u8_t, u8_t);    // this function not available to users, used to display numbers in SSD
                                               // we put this prototype here for not using in app layer 
void H_Ssd_Void_Init(void)
{
	M_Dio_Void_PinMode(SSD_A_PIN, OUTPUT);
	M_Dio_Void_PinMode(SSD_B_PIN, OUTPUT);
	M_Dio_Void_PinMode(SSD_C_PIN, OUTPUT);
	M_Dio_Void_PinMode(SSD_D_PIN, OUTPUT);
	M_Dio_Void_PinMode(SSD_E_PIN, OUTPUT);
	M_Dio_Void_PinMode(SSD_F_PIN, OUTPUT);
	M_Dio_Void_PinMode(SSD_G_PIN, OUTPUT);
	M_Dio_Void_PinMode(SSD_1_ENABLE_PIN, OUTPUT);
	M_Dio_Void_PinMode(SSD_2_ENABLE_PIN, OUTPUT);

}
 static void H_Ssd_Void_Display(u8_t Local_u8_Ssd, u8_t Local_u8_Num)
{
	switch(Local_u8_Ssd)
	{
		case 1:
			M_Dio_Void_PinWrite(SSD_1_ENABLE_PIN, HIGH);
			M_Dio_Void_PinWrite(SSD_2_ENABLE_PIN, LOW);
			break;
		case 2:
			M_Dio_Void_PinWrite(SSD_1_ENABLE_PIN, LOW);
			M_Dio_Void_PinWrite(SSD_2_ENABLE_PIN, HIGH);
			break;
		default:
			break;
	}
	#if SSD_MODE    == DIRECT_MODE
	switch(Local_u8_Num)
	{
		case 0:
			M_Dio_Void_PinWrite(SSD_A_PIN, HIGH);
			M_Dio_Void_PinWrite(SSD_B_PIN, HIGH);
			M_Dio_Void_PinWrite(SSD_C_PIN, HIGH);
			M_Dio_Void_PinWrite(SSD_D_PIN, HIGH);
			M_Dio_Void_PinWrite(SSD_E_PIN, HIGH);
			M_Dio_Void_PinWrite(SSD_F_PIN, HIGH);
			M_Dio_Void_PinWrite(SSD_G_PIN, LOW);
			break;
		case 1:
			M_Dio_Void_PinWrite(SSD_A_PIN, LOW);
			M_Dio_Void_PinWrite(SSD_B_PIN, HIGH);
			M_Dio_Void_PinWrite(SSD_C_PIN, HIGH);
			M_Dio_Void_PinWrite(SSD_D_PIN, LOW);
			M_Dio_Void_PinWrite(SSD_E_PIN, LOW);
			M_Dio_Void_PinWrite(SSD_F_PIN, LOW);
			M_Dio_Void_PinWrite(SSD_G_PIN, LOW);
			break;
		case 2:
			M_Dio_Void_PinWrite(SSD_A_PIN, HIGH);
			M_Dio_Void_PinWrite(SSD_B_PIN, HIGH);
			M_Dio_Void_PinWrite(SSD_C_PIN, LOW);
			M_Dio_Void_PinWrite(SSD_D_PIN, HIGH);
			M_Dio_Void_PinWrite(SSD_E_PIN, HIGH);
			M_Dio_Void_PinWrite(SSD_F_PIN, LOW);
			M_Dio_Void_PinWrite(SSD_G_PIN, HIGH);
			break;
		case 3:
			M_Dio_Void_PinWrite(SSD_A_PIN, HIGH);
			M_Dio_Void_PinWrite(SSD_B_PIN, HIGH);
			M_Dio_Void_PinWrite(SSD_C_PIN, HIGH);
			M_Dio_Void_PinWrite(SSD_D_PIN, HIGH);
			M_Dio_Void_PinWrite(SSD_E_PIN, LOW);
			M_Dio_Void_PinWrite(SSD_F_PIN, LOW);
			M_Dio_Void_PinWrite(SSD_G_PIN, HIGH);
			break;
		case 4:
			M_Dio_Void_PinWrite(SSD_A_PIN, LOW);
			M_Dio_Void_PinWrite(SSD_B_PIN, HIGH);
			M_Dio_Void_PinWrite(SSD_C_PIN, HIGH);
			M_Dio_Void_PinWrite(SSD_D_PIN, LOW);
			M_Dio_Void_PinWrite(SSD_E_PIN, LOW);
			M_Dio_Void_PinWrite(SSD_F_PIN, HIGH);
			M_Dio_Void_PinWrite(SSD_G_PIN, HIGH);
			break;
		case 5:
			M_Dio_Void_PinWrite(SSD_A_PIN, HIGH);
			M_Dio_Void_PinWrite(SSD_B_PIN, LOW);
			M_Dio_Void_PinWrite(SSD_C_PIN, HIGH);
			M_Dio_Void_PinWrite(SSD_D_PIN, HIGH);
			M_Dio_Void_PinWrite(SSD_E_PIN, LOW);
			M_Dio_Void_PinWrite(SSD_F_PIN, HIGH);
			M_Dio_Void_PinWrite(SSD_G_PIN, HIGH);
			break;
		case 6:
			M_Dio_Void_PinWrite(SSD_A_PIN, HIGH);
			M_Dio_Void_PinWrite(SSD_B_PIN, LOW);
			M_Dio_Void_PinWrite(SSD_C_PIN, HIGH);
			M_Dio_Void_PinWrite(SSD_D_PIN, HIGH);
			M_Dio_Void_PinWrite(SSD_E_PIN, HIGH);
			M_Dio_Void_PinWrite(SSD_F_PIN, HIGH);
			M_Dio_Void_PinWrite(SSD_G_PIN, HIGH);
			break;
		case 7:
			M_Dio_Void_PinWrite(SSD_A_PIN, HIGH);
			M_Dio_Void_PinWrite(SSD_B_PIN, HIGH);
			M_Dio_Void_PinWrite(SSD_C_PIN, HIGH);
			M_Dio_Void_PinWrite(SSD_D_PIN, LOW);
			M_Dio_Void_PinWrite(SSD_E_PIN, LOW);
			M_Dio_Void_PinWrite(SSD_F_PIN, LOW);
			M_Dio_Void_PinWrite(SSD_G_PIN, LOW);
			break;
		case 8:
			M_Dio_Void_PinWrite(SSD_A_PIN, HIGH);
			M_Dio_Void_PinWrite(SSD_B_PIN, HIGH);
			M_Dio_Void_PinWrite(SSD_C_PIN, HIGH);
			M_Dio_Void_PinWrite(SSD_D_PIN, HIGH);
			M_Dio_Void_PinWrite(SSD_E_PIN, HIGH);
			M_Dio_Void_PinWrite(SSD_F_PIN, HIGH);
			M_Dio_Void_PinWrite(SSD_G_PIN, HIGH);
			break;
		case 9:
			M_Dio_Void_PinWrite(SSD_A_PIN, HIGH);
			M_Dio_Void_PinWrite(SSD_B_PIN, HIGH);
			M_Dio_Void_PinWrite(SSD_C_PIN, HIGH);
			M_Dio_Void_PinWrite(SSD_D_PIN, LOW);
			M_Dio_Void_PinWrite(SSD_E_PIN, LOW);
			M_Dio_Void_PinWrite(SSD_F_PIN, HIGH);
			M_Dio_Void_PinWrite(SSD_G_PIN, HIGH);
			break;
		default:
			break;	
	}	
	#elif	SSD_MODE    ==	DECODE_MODE
	switch(Local_u8_Num)
	{
		case 0:
			M_Dio_Void_PinWrite(SSD_A_PIN, LOW);
			M_Dio_Void_PinWrite(SSD_B_PIN, LOW);
			M_Dio_Void_PinWrite(SSD_C_PIN, LOW);
			M_Dio_Void_PinWrite(SSD_D_PIN, LOW);
			break;
		case 1:
			M_Dio_Void_PinWrite(SSD_A_PIN, HIGH);
			M_Dio_Void_PinWrite(SSD_B_PIN, LOW);
			M_Dio_Void_PinWrite(SSD_C_PIN, LOW);
			M_Dio_Void_PinWrite(SSD_D_PIN, LOW);

			break;
		case 2:
			M_Dio_Void_PinWrite(SSD_A_PIN, LOW);
			M_Dio_Void_PinWrite(SSD_B_PIN, HIGH);
			M_Dio_Void_PinWrite(SSD_C_PIN, LOW);
			M_Dio_Void_PinWrite(SSD_D_PIN, LOW);

			break;
		case 3:
			M_Dio_Void_PinWrite(SSD_A_PIN, HIGH);
			M_Dio_Void_PinWrite(SSD_B_PIN, HIGH);
			M_Dio_Void_PinWrite(SSD_C_PIN, LOW);
			M_Dio_Void_PinWrite(SSD_D_PIN, LOW);
			
			break;
		case 4:
			M_Dio_Void_PinWrite(SSD_A_PIN, LOW);
			M_Dio_Void_PinWrite(SSD_B_PIN, LOW);
			M_Dio_Void_PinWrite(SSD_C_PIN, HIGH);
			M_Dio_Void_PinWrite(SSD_D_PIN, LOW);
		
			break;
		case 5:
			M_Dio_Void_PinWrite(SSD_A_PIN, HIGH);
			M_Dio_Void_PinWrite(SSD_B_PIN, LOW);
			M_Dio_Void_PinWrite(SSD_C_PIN, HIGH);
			M_Dio_Void_PinWrite(SSD_D_PIN, LOW);
	
			break;
		case 6:
			M_Dio_Void_PinWrite(SSD_A_PIN, LOW);
			M_Dio_Void_PinWrite(SSD_B_PIN, HIGH);
			M_Dio_Void_PinWrite(SSD_C_PIN, HIGH);
			M_Dio_Void_PinWrite(SSD_D_PIN, LOW);
	
			break;
		case 7:
			M_Dio_Void_PinWrite(SSD_A_PIN, HIGH);
			M_Dio_Void_PinWrite(SSD_B_PIN, HIGH);
			M_Dio_Void_PinWrite(SSD_C_PIN, HIGH);
			M_Dio_Void_PinWrite(SSD_D_PIN, LOW);
		
			break;
		case 8:
			M_Dio_Void_PinWrite(SSD_A_PIN, LOW);
			M_Dio_Void_PinWrite(SSD_B_PIN, LOW);
			M_Dio_Void_PinWrite(SSD_C_PIN, LOW);
			M_Dio_Void_PinWrite(SSD_D_PIN, HIGH);
			
			break;
		case 9:
			M_Dio_Void_PinWrite(SSD_A_PIN, HIGH);
			M_Dio_Void_PinWrite(SSD_B_PIN, LOW);
			M_Dio_Void_PinWrite(SSD_C_PIN, LOW);
			M_Dio_Void_PinWrite(SSD_D_PIN, HIGH);
			break;
		default:
			break;
	}
	#endif


}

void H_Ssd_Void_Write(u8_t Local_u8_Num)
{
	u8_t Local_u8_Units = Local_u8_Num % 10;
	u8_t Local_u8_Tens  = Local_u8_Num / 10;
	u8_t Local_u8_Counter = 0;
	/*
		this loop for show number on SSD within t time 
	*/
	for (Local_u8_Counter = 0; Local_u8_Counter < 100; Local_u8_Counter++)
	{
		H_Ssd_Void_Display(1, Local_u8_Units);
		_delay_ms(3);
		H_Ssd_Void_Display(2, Local_u8_Tens);
		_delay_ms(3);	
	}
	M_Dio_Void_PinWrite(SSD_1_ENABLE_PIN, LOW);
	M_Dio_Void_PinWrite(SSD_2_ENABLE_PIN, LOW);
	
}
void H_Ssd_Void_CountUp(u8_t Local_u8_Num)
{	
	u8_t Local_u8_counter = 0;
	for( Local_u8_counter = 0; Local_u8_counter <= Local_u8_Num; Local_u8_counter++)
	{
		H_Ssd_Void_Write(Local_u8_counter);
	}
	
}             
void H_Ssd_Void_CountDown(s8_t Local_s8_Num)
{

	/*
		we make s8_t, because if Local_s8_Num reached to zero and decreased it will be 255 (over flow), because unsigned,
		so, we make it signed
	*/
	for(; Local_s8_Num >= 0; Local_s8_Num--)
	{
		H_Ssd_Void_Write(Local_s8_Num);
	}
	
}



