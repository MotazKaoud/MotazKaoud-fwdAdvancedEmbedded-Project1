#include "Gpio_Types.h"
#include "Mcu_Hw.h"

#ifndef GPIO_DIO_H
#define GPIO_DIO_H

Dio_Level_type Dio_ReadChannel (Dio_Channel_Type ChannelId,Port_Type channelport);
void Dio_WriteChannel (Dio_Channel_Type ChannelId,Port_Type channelport, Dio_Level_type channellevel);
void Dio_FlipChannel (Dio_Channel_Type ChannelId,Port_Type channelport);



#endif
