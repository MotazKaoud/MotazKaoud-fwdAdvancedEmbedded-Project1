#include "Gpio_Dio.h"
#include "Gpio_Types.h"

int main (void)
{


Port_Type port_1= PORTB;
Port_PinDirectionType pindir_1 = OUT ;
Dio_Channel_Type pin_1 = P2;
Port_PinModeType pinmode_1 = PA0_DIO ;
Dio_Level_type pinlevel_1 = HIGH;
Port_PinOutputCurrentType pincurrent_1 = mA8;
Port_PinInternalAttachType pinattach_1 = UP;
	
PortPin_ConfigType PA0 = {port_1, pindir_1, pin_1, pinmode_1, pinlevel_1, pincurrent_1, pinattach_1} ;	

PortPin_Init_AHB (&PA0);
PortPin_Init_APB (&PA0);

pinlevel_1 = HIGH;
Dio_WriteChannel(pin_1, port_1, pinlevel_1);
pinlevel_1 = Dio_ReadChannel(pin_1, port_1);


pinlevel_1 = LOW;
Dio_WriteChannel(pin_1, port_1, pinlevel_1);
pinlevel_1 = Dio_ReadChannel(pin_1, port_1);
	


Dio_FlipChannel(pin_1, port_1) ;
Dio_FlipChannel(pin_1, port_1) ;
Dio_FlipChannel(pin_1, port_1) ;
Dio_FlipChannel(pin_1, port_1) ;



int x ;
x = 10 * 10 ;

return 0;
}

