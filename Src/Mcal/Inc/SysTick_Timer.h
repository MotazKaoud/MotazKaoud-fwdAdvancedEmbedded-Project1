#ifndef SYSTICK_TIMER_H
#define SYSTICK_TIMER_H
#include <stdint.h>
#include "Mcu_Hw.h"

typedef enum
{DISABLE, ENABLE} Systick_Interrupt_Type ;

typedef enum 
{PIOSCby4, SYSTEM_CLOCK } Systick_Clock_Type ;

typedef uint32_t Systick_Current_Value_Type; // hold values from 0x0 to 0xFF.FFFF

/*
-> clock speed = 12Mhz
-> tick_time = Periodic_Timer * LoadReg_Value = (1/Clock_Freq) * LoadReg_Value
-> Max_Delay = Periodic_Timer * Max_LoadReg_Value = (1/Clock_Freq) * Max_LoadReg_Value = (1/12000000) * (0xFFFFFF) = 1.4 sec
=============> therefore : tick period range is from 0 sec to 1.4 sec
*/
typedef float Sys_Tick_Period ; // holds values from 0 to 1.4

typedef struct 
{
Systick_Interrupt_Type 		Systick_Int		 ;
Systick_Clock_Type 				Systick_Clock  ;
Sys_Tick_Period 					Systick_Period ;
} Systick_Configs ;


void Systick_Init (Systick_Configs *ConfigPtr);
void Start_Systick (void);
void Stop_Systick (void);
Systick_Current_Value_Type Systick_STCURRENT_Value (void);

// msh hn3ml typedef 3lshan msh hy7sl en yb2a fe aktr mn variable odam 3shan hwa timer whaed, bs momkn wahed 3yz y3ml kza struct b kza configs mokhtlfa fa7sn n3ml




#endif