/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  SysTick_Timer.c
 *        \brief  
 *
 *      \details  c file for the systick timer driver
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "SysTick_Timer.h"
#include "User_Configs.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
extern uint32_t systickcounter;
/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : void Systick_Init (Systick_Configs *ConfigPtr)        
* \Description     : f                   unction intialize the systick timer with some configurations                 
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : ConfigPtr   struct contains the configuration parameters

ConfigPtr          : Systick_Int		interrupt enabled or not ? (ENABLE/DISABLE)
										 Systick_Clock  Clock tied to the systick timer (PIOSCby4/SYSTEM_CLOCK)
										 Systick_Period period for each Tick (value from 0 to 1.4 sec)

* \Parameters (out): None                                                      
* \Return value:   : void                                
*******************************************************************************/
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




/******************************************************************************
* \Syntax          : Start_Systick (void)        
* \Description     : function starts the systick timer operation
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None
* \Parameters (out): None                                                      
* \Return value:   : void                                
*******************************************************************************/
void Start_Systick (void){
	STCTRL |= (uint32_t) 0x1 ; // enable timer
}




/******************************************************************************
* \Syntax          : Stop_Systick (void)      
* \Description     : function stops the systick timer operation
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None
* \Parameters (out): None                                                      
* \Return value:   : void                                
*******************************************************************************/
void Stop_Systick (void){
	STCTRL &= ~(uint32_t) 0x1 ; // Disable timer
}


/******************************************************************************
* \Syntax          : Systick_STCURRENT_Value (void)      
* \Description     : function returns the systick timer current value storred in STCURRENT Register
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None
* \Parameters (out): Systick_Current_Value_Type uint32_t variable 
* \Return value:   : void                                
*******************************************************************************/
Systick_Current_Value_Type Systick_STCURRENT_Value (void){
return STCURRENT ;
}



/**********************************************************************************************************************
 *  END OF FILE: SysTick_Timer.c
 *********************************************************************************************************************/

