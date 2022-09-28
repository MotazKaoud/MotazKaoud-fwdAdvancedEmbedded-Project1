/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  IntCtrl.c
 *        \brief  source file for the interrupt driver 
 *
 *      \details  holds the required variables and functions defenation
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "IntCtrl.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
 

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
* \Syntax          : void IntCtrl_Init(void)        
* \Description     : Function to Intialize the interrupts in the system                                  
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None (Parameters are token from the user via User_Configs.h file)					
* \Parameters (out): None                                                      
* \Return value:   : void

*******************************************************************************/
void IntCtrl_Init(void) 
{
uint8_t counter; 
uint8_t int_en_bit ;
uint8_t int_pri_reg ;
uint8_t int_num ;	
	
	// Diable all interruprs, Enable then only the mentioned in userconfig.h 
NVIC_INT_EN(0) = (uint32_t)0x0;
NVIC_INT_EN(1) = (uint32_t)0x0;
NVIC_INT_EN(2) = (uint32_t)0x0;
NVIC_INT_EN(3) = (uint32_t)0x0;
NVIC_INT_EN(4) = (uint32_t)0x0;

for (counter = 0; counter < Int_User_Req_Size; counter++)
	{ 
		int_num = InterruptPeripheralGates[counter] ;
/***************** Enable Interrupt*******************/		
		// get the interrupt bit inside Interrupt Enable Register
	  // Map the interrupt number to 0-->31 bit number 
	  int_en_bit = InterruptPeripheralGates[counter] ;
	  while (int_en_bit > (uint8_t)31)	{int_en_bit -= 32; }
	  // Enable the Interrupt, map the interrupt number to one of the interrupt enable registers from 0-->4
	  NVIC_INT_EN((uint32_t)(int_num / 32)) |= (uint32_t)(1<<int_en_bit);
/***************** Set Interrupt Priority*******************/		
		// Select grouping-subgrouping from APINT
		NVIC_APINT = (0x05FA0000 | (uint32_t)(APINT_Req<<8));
		NVIC_APINT |= ((uint32_t)(APINT_Req<<8));
		// Select sub-Grouping
		int_pri_reg = (int_num / 4) ; 
	 	if      ( int_num == (4*int_pri_reg) )      /*interrupt with the number [4n], where n is the number of the Interrupt Priority register*/
		{NVIC_INT_PR((uint32_t)(int_pri_reg)) |= (uint32_t)((InterruptSubGroupPriority[counter])<< (uint32_t)5) ;}
	 	else if ( int_num == ((4*int_pri_reg)+1) )  /*interrupt with the number [4n+1], where n is the number of the Interrupt Priority register*/
		{NVIC_INT_PR((uint32_t)(int_pri_reg)) |= (uint32_t)((InterruptSubGroupPriority[counter])<< (uint32_t)13) ;}
	 	else if ( int_num == ((4*int_pri_reg)+2) )  /*interrupt with the number [4n+2], where n is the number of the Interrupt Priority register*/
		{NVIC_INT_PR((uint32_t)(int_pri_reg)) |= (uint32_t)((InterruptSubGroupPriority[counter])<< (uint32_t)21) ;}
	 	else if ( int_num == ((4*int_pri_reg)+3) )  /*interrupt with the number [4n+3], where n is the number of the Interrupt Priority register*/
		{NVIC_INT_PR((uint32_t)(int_pri_reg)) |= (uint32_t)((InterruptSubGroupPriority[counter])<< (uint32_t)29) ;}
		// select grouping
			 	if      ( int_num == (4*int_pri_reg) )      /*interrupt with the number [4n], where n is the number of the Interrupt Priority register*/
		{NVIC_INT_PR((uint32_t)(int_pri_reg)) |= (uint32_t)((InterruptGroupPriority[counter])<< (uint32_t)(APINT_Req+1)) ;}
	 	else if ( int_num == ((4*int_pri_reg)+1) )  /*interrupt with the number [4n+1], where n is the number of the Interrupt Priority register*/
		{NVIC_INT_PR((uint32_t)(int_pri_reg)) |= (uint32_t)((InterruptGroupPriority[counter])<< (uint32_t)(APINT_Req+1+8)) ;}
	 	else if ( int_num == ((4*int_pri_reg)+2) )  /*interrupt with the number [4n+2], where n is the number of the Interrupt Priority register*/
		{NVIC_INT_PR((uint32_t)(int_pri_reg)) |= (uint32_t)((InterruptGroupPriority[counter])<< (uint32_t)(APINT_Req+1+16)) ;}
	 	else if ( int_num == ((4*int_pri_reg)+3) )  /*interrupt with the number [4n+3], where n is the number of the Interrupt Priority register*/
		{NVIC_INT_PR((uint32_t)(int_pri_reg)) |= (uint32_t)((InterruptGroupPriority[counter])<< (uint32_t)(APINT_Req+1+24)) ;}
  
	
	}
	
	
}

/**********************************************************************************************************************
 *  END OF FILE: IntCtrl.c
 *********************************************************************************************************************/






