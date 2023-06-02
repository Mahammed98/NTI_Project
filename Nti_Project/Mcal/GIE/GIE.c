/*
 * GIE.c
 *
 * Created: 4/2/2023 4:35:24 PM
 *  Author: Muhammed El Nabawy
 */ 

#include "Std.h"
#include "BitMath.h"
#include "Reg.h"
#include "GIE.h"


void M_Gie_Void_Enable(void)
{
	SetBit(SREG,7);        // we can replace it  by assembly code : asm("SEI")
}
void M_Gie_Void_Disable(void)
{
	ClrBit(SREG,7);		   // we can replace it  by assembly code : asm("CLI")
}