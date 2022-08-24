#include "SysTick_Timer.h"

void Systick_Init (Systick_Configs *ConfigPtr)
{
	// 1. Program the value in the STRELOAD register.
	//-> tick_time = Periodic_Timer * LoadReg_Value = (1/Clock_Freq) * LoadReg_Value
	//-> LoadReg_Value = tick_time * Clock_Freq 
	STRELOAD = (uint32_t)((ConfigPtr->Systick_Period) * (12000000));

	//2. Clear the STCURRENT register by writing to it with any value.
	STCURRENT  = 0x0 ;
\
	//3. Configure the STCTRL register for the required operation.
	if (ConfigPtr->Systick_Clock == SYSTEM_CLOCK)
	{ STCTRL |= (uint32_t)(1<<2) ; } // set bit2
	else if (ConfigPtr->Systick_Clock == PIOSCby4)
	{ STCTRL &= ~((uint32_t)(1<<2)) ; } // clear bit2
	
	if (ConfigPtr->Systick_Int == ENABLE)
	{STCTRL |= (uint32_t)(1<<1) ; }// Interrupt Enable
	else if (ConfigPtr->Systick_Int == DISABLE)
	{STCTRL &= ~((uint32_t)(1<<1)) ; }// Interrupt Enable
}	


void Start_Systick (void){
	STCTRL |= (uint32_t) 0x1 ; // enable timer
}

void Stop_Systick (void){
	STCTRL &= ~(uint32_t) 0x1 ; // Disable timer
}

Systick_Current_Value_Type Systick_STCURRENT_Value (void){
return STCURRENT ;
}


