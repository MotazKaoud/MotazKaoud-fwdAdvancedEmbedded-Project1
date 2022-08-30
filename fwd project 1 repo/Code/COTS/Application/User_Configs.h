#include <stdint.h>
#include "Gpio_Types.h"
#include "Gpio_Port.h"
#include "Gpio_Dio.h"
#include "SysTick_Timer.h"

/************** GPIO User Requirments ******************/
#define REQ_PORT_TYPE									PORTB				
#define REQ_PORT_PIN_DIRECTION_TYPE 	OUT	
#define REQ_DIO_CHANNEL_TYPE 					P2	
#define REQ_PORT_PIN_MODE_TYPE				PB2_DIO
#define REQ_DIO_LEVEL_TYPE 						HIGH
#define REQ_PIN_OUTPUT_CURRENT_TYPE		mA8
#define REQ_PIN_INTERNAL_ATTACH_TYPE	UP


/************** SysTick Timer User Requirments ******************/
#define REQ_SYSTICK_INTERRUPT_TYPE	ENABLE 
#define REQ_SYSTICK_CLOCK_TYPE			SYSTEM_CLOCK
#define REQ_SYSTICK_PERIOD 					(0x01)

/************** Application User Requirments ******************/
#define on_time (uint32_t)(0x05)
#define off_time (uint32_t)(0x0A)


void CBK (uint32_t *notif);

