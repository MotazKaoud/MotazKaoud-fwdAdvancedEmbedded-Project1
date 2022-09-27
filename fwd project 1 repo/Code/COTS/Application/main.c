#include "Gpio_Dio.h"
#include "Gpio_Types.h"
#include "SysTick_Timer.h"
#include "User_Configs.h"
#include "IntCtrl.h"
#include <stdio.h>

void SysTick_Handler (void);
void GPIOB_Handler (void) ;
void CBK (void);

static PortPin_ConfigType 				 	 PB2 ;


extern uint32_t  systickcounter = 0;
static uint32_t *syscounterptr  = &systickcounter;
static Systick_Interrupt_Type			sys1_int  = REQ_SYSTICK_INTERRUPT_TYPE ;
static Systick_Clock_Type 				sys1_clck = REQ_SYSTICK_CLOCK_TYPE  ;
static Sys_Tick_Period 					  sys1_per  = REQ_SYSTICK_PERIOD ;
static Systick_Configs 						sys_config1 ;


//extern uint8_t on_time  ;
//extern uint8_t off_time ;

uint8_t on_time  =  REQ_ON_TIME;
uint8_t off_time =  REQ_OFF_TIME;

int main (void)
{

/**************************************** Interrupt_NVIC_driver Intializations**********************/
IntCtrl_Init();

	
/**************************************** Gpio_Driver Intialization************************/
PB2.porttype 									= REQ_PORT_TYPE_2;
PB2.portpindirection 					= REQ_PORT_PIN_DIRECTION_TYPE_2;
PB2.portpin 									= REQ_DIO_CHANNEL_TYPE_2 ;
PB2.portpinmode 							= REQ_PORT_PIN_MODE_TYPE_2 ;
PB2.portpinlevel 							= REQ_DIO_LEVEL_TYPE_2 ;
PB2.portpinoutputcurrent 			= REQ_PIN_OUTPUT_CURRENT_TYPE_2 ;
PB2.portpinattach 						= REQ_PIN_INTERNAL_ATTACH_TYPE_2 ;
PB2.portinterruptstate				= REQ_PIN_INTERRUPT_STATE_TYPE_2 ;
PB2.portinterruptevent 				= REQ_PIN_INTERRUPT_EVENT_TYPE_2	;
PB2.portinterrupteventstate		= REQ_PIN_INTERRUPT_EVENT_STATE_TYPE_2	;

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
if (NOTFICATION)
	{
		CBK();
	}
}



void CBK ()
{
	if(Dio_ReadChannel_APB(REQ_DIO_CHANNEL_TYPE_2,REQ_PORT_TYPE_2) == LOW ) // LED_OFF

		{
			if((*syscounterptr >= off_time) == 0x1)
				{
					Dio_WriteChannel_APB(REQ_DIO_CHANNEL_TYPE_2, REQ_PORT_TYPE_2, HIGH); //turn on
					*syscounterptr  = 0x0;
				}
		}
	else if (Dio_ReadChannel_APB(REQ_DIO_CHANNEL_TYPE_2,REQ_PORT_TYPE_2) == HIGH )// LED = ON
		{
			if(*syscounterptr >= on_time)
				{
					Dio_WriteChannel_APB(REQ_DIO_CHANNEL_TYPE_2, REQ_PORT_TYPE_2, LOW); //tun off
					*syscounterptr = 0x0;
			}
		}
}

