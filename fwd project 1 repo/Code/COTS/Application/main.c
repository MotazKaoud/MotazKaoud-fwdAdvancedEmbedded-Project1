#include "Gpio_Dio.h"
#include "Gpio_Types.h"
#include "SysTick_Timer.h"
#include "User_Configs.h"

void SysTick_Handler (void);
void CBK (void);

static Port_Type 									 port_1				= REQ_PORT_TYPE;
static Port_PinDirectionType 			 pindir_1 		= REQ_PORT_PIN_DIRECTION_TYPE ;
static Dio_Channel_Type 					 pin_1 				= REQ_DIO_CHANNEL_TYPE;
static Port_PinModeType 					 pinmode_1 		= REQ_PORT_PIN_MODE_TYPE ;
static Dio_Level_type 						 pinlevel_1 	= REQ_DIO_LEVEL_TYPE;
static Port_PinOutputCurrentType   pincurrent_1 = REQ_PIN_OUTPUT_CURRENT_TYPE;
static Port_PinInternalAttachType  pinattach_1 	= REQ_PIN_INTERNAL_ATTACH_TYPE;
static PortPin_ConfigType 				 PB2 ;

extern uint32_t  systickcounter = 0;
static uint32_t *syscounterptr  = &systickcounter;
static Systick_Interrupt_Type			sys1_int  = REQ_SYSTICK_INTERRUPT_TYPE ;
static Systick_Clock_Type 				sys1_clck = REQ_SYSTICK_CLOCK_TYPE  ;
static Sys_Tick_Period 					  sys1_per  = REQ_SYSTICK_PERIOD ;
static Systick_Configs 						sys_config1 ;


int main (void)
{

/**************************************** Gpio_Driver Intialization************************/
PB2.porttype = port_1;
PB2.portpindirection = pindir_1;
PB2.portpin = pin_1 ;
PB2.portpinmode = pinmode_1 ;
PB2.portpinlevel = pinlevel_1 ;
PB2.portpinoutputcurrent = pincurrent_1 ;
PB2.portpinattach = pinattach_1 ;
	
PortPin_Init_AHB (&PB2);

/**************************************** Systick_driver Intializations**********************/
sys_config1.Systick_Int = sys1_int;
sys_config1.Systick_Clock = sys1_clck;
sys_config1.Systick_Period = sys1_per ;

Systick_Init( &sys_config1) ;
Start_Systick ();

	return 0;
}




void SysTick_Handler ()
{
(*syscounterptr) ++ ;
	
}


void CBK ()
{
	if(Dio_ReadChannel(pin_1,port_1) == LOW ) // LED_OFF

		{
			if((*syscounterptr >= off_time) == 0x1)
				{
					Dio_WriteChannel(pin_1, port_1, HIGH); //turn on
					*syscounterptr  = 0x0;
				}
		}
	else if (Dio_ReadChannel(pin_1,port_1) == HIGH )// LED = ON
		{
			if(*syscounterptr >= on_time)
				{
					Dio_WriteChannel(pin_1, port_1, LOW); //tun off
					*syscounterptr = 0x0;
			}
		}
}

