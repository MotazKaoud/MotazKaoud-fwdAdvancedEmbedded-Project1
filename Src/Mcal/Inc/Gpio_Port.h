#ifndef GPIO_PORT_H
#define GPIO_PORT_H

#include "Gpio_Types.h"
#include "Mcu_Hw.h"

void PortPin_Init_AHB (const PortPin_ConfigType* Configptr);
void PortPin_Init_APB (const PortPin_ConfigType* Configptr);

/*
Port_Type port_1 ;
Port_PinDirectionType pindir_1 ;
Dio_Channel_Type pin_1 ;
Port_PinModeType pinmode_1 ;
Dio_Level_type pinlevel_1 ;
Port_PinOutputCurrentType pincurrent_1;
Port_PinInternalAttachType pinattach_1;
*/

#endif
