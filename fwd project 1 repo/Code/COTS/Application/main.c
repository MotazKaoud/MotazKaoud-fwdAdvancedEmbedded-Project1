#include "Gpio_Dio.h"
#include "Gpio_Types.h"
#include "SysTick_Timer.h"
#include "User_Configs.h"

void SysTick_Handler (void);

extern uint32_t systickcounter = 0;



int main (void)
{

/****************************************Testing Gpio_Driver including port dirver and dio driver************************
	
static Port_Type port_1= PORTB;
static Port_PinDirectionType pindir_1 = OUT ;
static Dio_Channel_Type pin_1 = P2;
static Port_PinModeType pinmode_1 = PA0_DIO ;
static Dio_Level_type pinlevel_1 = HIGH;
static Port_PinOutputCurrentType pincurrent_1 = mA8;
static Port_PinInternalAttachType pinattach_1 = UP;
PortPin_ConfigType PB2 = {port_1, pindir_1, pin_1, pinmode_1, pinlevel_1, pincurrent_1, pinattach_1} ;	

PortPin_Init_AHB (&PB2);


Dio_WriteChannel(pin_1, port_1, LOW);
Dio_WriteChannel(pin_1, port_1, HIGH);

Dio_FlipChannel(pin_1, port_1) ;


Dio_FlipChannel(pin_1, port_1) ;



****************************************Testing Gpio_Driver including port dirver and dio driver end**********************/
 

/****************************************Testing systick_driver including port dirver and dio driver end**********************/


Systick_Interrupt_Type 		sys1_int = ENABLE		;
Systick_Clock_Type 				sys1_clck = SYSTEM_CLOCK  ;
Sys_Tick_Period 					sys1_per = (0x1) ;


Systick_Configs sys_config1 = {sys1_int, sys1_clck, sys1_per} ;
Systick_Init( &sys_config1) ;
Start_Systick ();

/****************************************Testing systick_driver including port dirver and dio driver end**********************/
return 0;

}



void SysTick_Handler ()
{
systickcounter ++ ;
	if (NOTFICATION)
	{
	CBK(& systickcounter);
	}
}
