
/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Gpio_Dio.c
 *        \brief  the source file for Gpio_Dio Driver
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Gpio_Dio.h"


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
/**************************AHB*********************************/


/******************************************************************************
* \Syntax          : Dio_Level_type Dio_ReadChannel (Dio_Channel_Type ChannelId,Port_Type channelport)         
* \Description     : function to read some dio channel state (HIGH/LOW)                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : ChannelId     the required channel id in the port (P1,P2,P3,P4,P5,P6,P7)  
										 channelport   the required channel port (PORTA,PORTB,PORTC,PORTD,PORTE,PORTF)  
* \Parameters (out): None                                                      
* \Return value:   : void
*                                                                    
*******************************************************************************/
Dio_Level_type Dio_ReadChannel (Dio_Channel_Type ChannelId,Port_Type channelport) 
{
Dio_Level_type pintype ;
pintype = ((uint8_t)(( (AHB_GPIODATA_PORT(channelport)) >> ChannelId ) &0x01)) ;
return pintype;
}


/******************************************************************************
* \Syntax          : Dio_WriteChannel (Dio_Channel_Type ChannelId,Port_Type channelport, Dio_Level_type channellevel)         
* \Description     : function to write some dio channel state (HIGH/LOW)                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : ChannelId     the required channel id in the port (P1,P2,P3,P4,P5,P6,P7)  
										 channelport   the required channel port (PORTA,PORTB,PORTC,PORTD,PORTE,PORTF) 
										 channellevel  the required level to be wirtten (HIGH/LOW)
* \Parameters (out): None                                                      
* \Return value:   : void
*                                                                    
*******************************************************************************/
void Dio_WriteChannel (Dio_Channel_Type ChannelId,Port_Type channelport, Dio_Level_type channellevel) 
{
	if (channellevel) // required level is HIGH, write 1 to bit
	{AHB_GPIODATA_PORT(channelport) |=  (uint32_t)(1<<ChannelId);}
	else  // required level is LOW, write 0 to bit
	{AHB_GPIODATA_PORT(channelport) &= ~(uint32_t)(1<<ChannelId);}
}


/******************************************************************************
* \Syntax          : Dio_FlipChannel (Dio_Channel_Type ChannelId, Port_Type channelport)         
* \Description     : function to toggle some dio channel state (HIGH->LOW/LOW->HIGH)                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : ChannelId     the required channel id in the port (P1,P2,P3,P4,P5,P6,P7)  
										 channelport   the required channel port (PORTA,PORTB,PORTC,PORTD,PORTE,PORTF) 
* \Parameters (out): None                                                      
* \Return value:   : void
*                                                                    
*******************************************************************************/
void Dio_FlipChannel (Dio_Channel_Type ChannelId, Port_Type channelport)
{
Dio_Level_type channellevel = ((uint8_t)(( (AHB_GPIODATA_PORT(channelport)) >> ChannelId ) &0x01)) ;
	
	if (channellevel) // pin was HIGH
	{//write low
	 AHB_GPIODATA_PORT(channelport) &= ~(uint32_t)(1<<ChannelId);
	}
	else // pin was LOW
	{//write high
	AHB_GPIODATA_PORT(channelport) |=  (uint32_t)(1<<ChannelId);
	}
	
//	AHB_GPIODATA_PORT(channelport) ^=  (uint32_t)(1<<ChannelId);

}



/***************************APB**********************************/

/******************************************************************************
* \Syntax          : Dio_Level_type Dio_ReadChannel_APB (Dio_Channel_Type ChannelId,Port_Type channelport)         
* \Description     : function to read some dio channel state (HIGH/LOW)                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : ChannelId     the required channel id in the port (P1,P2,P3,P4,P5,P6,P7)  
										 channelport   the required channel port (PORTA,PORTB,PORTC,PORTD,PORTE,PORTF)  
* \Parameters (out): None                                                      
* \Return value:   : void
*                                                                    
*******************************************************************************/
Dio_Level_type Dio_ReadChannel_APB (Dio_Channel_Type ChannelId,Port_Type channelport) 
{
Dio_Level_type pintype ;
pintype = ((uint8_t)(( (APB_GPIODATA_PORT(channelport)) >> ChannelId ) &0x01)) ;
return pintype;
}


/******************************************************************************
* \Syntax          : Dio_WriteChannel_APB (Dio_Channel_Type ChannelId,Port_Type channelport, Dio_Level_type channellevel)         
* \Description     : function to write some dio channel state (HIGH/LOW)                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : ChannelId     the required channel id in the port (P1,P2,P3,P4,P5,P6,P7)  
										 channelport   the required channel port (PORTA,PORTB,PORTC,PORTD,PORTE,PORTF) 
										 channellevel  the required level to be wirtten (HIGH/LOW)
* \Parameters (out): None                                                      
* \Return value:   : void
*                                                                    
*******************************************************************************/
void Dio_WriteChannel_APB (Dio_Channel_Type ChannelId,Port_Type channelport, Dio_Level_type channellevel) 
{
	if (channellevel) // required level is HIGH, write 1 to bit
	{APB_GPIODATA_PORT(channelport) |=  (uint32_t)(1<<ChannelId);}
	else  // required level is LOW, write 0 to bit
	{APB_GPIODATA_PORT(channelport) &= ~(uint32_t)(1<<ChannelId);}
}


/******************************************************************************
* \Syntax          : Dio_FlipChannel_APB (Dio_Channel_Type ChannelId, Port_Type channelport)         
* \Description     : function to toggle some dio channel state (HIGH->LOW/LOW->HIGH)                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : ChannelId     the required channel id in the port (P1,P2,P3,P4,P5,P6,P7)  
										 channelport   the required channel port (PORTA,PORTB,PORTC,PORTD,PORTE,PORTF) 
* \Parameters (out): None                                                      
* \Return value:   : void
*                                                                    
*******************************************************************************/
void Dio_FlipChannel_APB (Dio_Channel_Type ChannelId, Port_Type channelport)
{
Dio_Level_type channellevel = ((uint8_t)(( (APB_GPIODATA_PORT(channelport)) >> ChannelId ) &0x01)) ;
	
	if (channellevel) // pin was HIGH
	{//write low
	 APB_GPIODATA_PORT(channelport) &= ~(uint32_t)(1<<ChannelId);
	}
	else // pin was LOW
	{//write high
	APB_GPIODATA_PORT(channelport) |=  (uint32_t)(1<<ChannelId);
	}
	
//	APB_GPIODATA_PORT(channelport) ^=  (uint32_t)(1<<ChannelId);

}


/**********************************************************************************************************************
 *  END OF FILE: GPIO_Dio.c
 *********************************************************************************************************************/
