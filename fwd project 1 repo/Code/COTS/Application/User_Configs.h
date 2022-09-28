




/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  User_Configs.h
 *       Module:  -
 *
 *  Description:  header file includes the required defenations for the user configurations
 *  
 *********************************************************************************************************************/
#ifndef USER_CONFIGS_H
#define USER_CONFIGS_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include <stdint.h>
#include <stddef.h>
#include "Gpio_Types.h"
#include "Gpio_Port.h"
#include "Gpio_Dio.h"
#include "SysTick_Timer.h"
#include "IntCtrl_Types.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/************** GPIO User Requirments ******************/
#define REQ_PORT_TYPE_2												PORTA				
#define REQ_PORT_PIN_DIRECTION_TYPE_2 				OUT	
#define REQ_DIO_CHANNEL_TYPE_2 								P0	
#define REQ_PORT_PIN_MODE_TYPE_2							PA0_DIO
#define REQ_DIO_LEVEL_TYPE_2 									LOW
#define REQ_PIN_OUTPUT_CURRENT_TYPE_2					mA8
#define REQ_PIN_INTERNAL_ATTACH_TYPE_2				UP
#define REQ_PIN_INTERRUPT_STATE_TYPE_2				ENABLE_GINT
#define REQ_PIN_INTERRUPT_EVENT_TYPE_2				ON_EDGE
#define REQ_PIN_INTERRUPT_EVENT_STATE_TYPE_2	ON_HIGH







/************** SysTick Timer User Requirments ******************/
#define REQ_SYSTICK_INTERRUPT_TYPE	ENABLE 
#define REQ_SYSTICK_CLOCK_TYPE			SYSTEM_CLOCK
#define REQ_SYSTICK_PERIOD 					(0x01)

/************** Interrupts User Requirments ******************/
/*Add elements for the required interrupts to be enabled, Interrupt No direct or one of the #defines in IntCtrl_Types */
uint8_t InterruptPeripheralGates[] = {INT_GPIOPortA, INT_GPIOPortB, INT_GPIOPortC} ;  
uint8_t Int_User_Req_Size = sizeof (InterruptPeripheralGates) / sizeof(uint8_t);
/*Add required group priorities (Integer from  0-->7) for the selected Interrupts in InterruptPeripheralGates with the same order (index 0 is the group priority for the first element in InterruptPeripheralGates)*/
uint8_t InterruptGroupPriority[] = {0x1,0x1,01} ;  
/*Add required subgroup priorities (Integer from  0-->7) for the selected Interrupts in InterruptPeripheralGates with the same order (index 0 is the subgroup priority for the first element in InterruptPeripheralGates)*/
uint8_t InterruptSubGroupPriority[] = {0x1,0x1,0x1} ; 
/*Select the required Group-Subgroup managment in APINT among : XXX/XXY/XYY/YYY*/
APINT_Type APINT_Req = XXY;

/************** Application User Requirments ******************/
#define REQ_OFF_TIME (0x05)
#define REQ_ON_TIME  (0x0A)




/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void CBK (void);

#endif  /* FILE_NAME_H */

/**********************************************************************************************************************
 *  END OF FILE: User_Configs.h
 *********************************************************************************************************************/
