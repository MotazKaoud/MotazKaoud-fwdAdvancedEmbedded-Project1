#include "Gpio_Dio.h"
#include "Gpio_Types.h"
#include "SysTick_Timer.h"

void SysTick_Handler (void);
void systick_delay (void);


static uint8_t on_time = 0xA;
static uint8_t off_time = 0x5;
static uint32_t test = 0x0;
static uint64_t systick_counter = 0;

enum state {OFF, ON} ;
enum state LED_State = OFF ;

int main (void)
{

/****************************************Testing Gpio_Driver including port dirver and dio driver*************************

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

****************************************Testing Gpio_Driver including port dirver and dio driver end**********************/
 

/****************************************Testing systick_driver including port dirver and dio driver end**********************/

/*typedef struct 
{
Systick_Interrupt_Type 		Systick_Int		 ;
Systick_Clock_Type 				Systick_Clock  ;
Sys_Tick_Period 					Systick_Period ;
} Systick_Configs ;*/

Systick_Interrupt_Type 		sys1_int = ENABLE		 ;
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
	systick_counter += 0x1 ;
	if(LED_State == OFF)
		{
			if(systick_counter >= off_time)
				{
					LED_State = ON;
					systick_counter = 0x0;
				}
		}
	else // LED_State = ON
		{
			if(systick_counter >= on_time)
				{
					LED_State = OFF;
					systick_counter = 0x0;
				}
		}
}