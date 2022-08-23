#include "Gpio_Dio.h"



Dio_Level_type Dio_ReadChannel (Dio_Channel_Type ChannelId,Port_Type channelport) 
{
Dio_Level_type pintype ;
pintype = ((uint8_t)(( (AHB_GPIODATA_PORT(channelport)) >> ChannelId ) &0x01)) ;
return pintype;
}

void Dio_WriteChannel (Dio_Channel_Type ChannelId,Port_Type channelport, Dio_Level_type channellevel) 
{
	if (channellevel) // required level is HIGH, write 1 to bit
	{AHB_GPIODATA_PORT(channelport) |=  (uint32_t)(1<<ChannelId);}
	else  // required level is LOW, write 0 to bit
	{AHB_GPIODATA_PORT(channelport) &= ~(uint32_t)(1<<ChannelId);}
}

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

}
