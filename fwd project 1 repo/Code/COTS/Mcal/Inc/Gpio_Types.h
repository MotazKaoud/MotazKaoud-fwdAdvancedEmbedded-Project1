/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Gpio_Types.h
 *       Module:  -
 *
 *  Description:  header file includes the required defenations for the GPIO Driver     
 *  
 *********************************************************************************************************************/
#ifndef GPIO_TYPES_H
#define GPIO_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include <stdint.h>


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

typedef enum
{
P0,
P1,
P2,
P3,
P4,
P5,
P6,
P7
}Dio_Channel_Type;

typedef enum
{PORTA,PORTB,PORTC,PORTD,PORTE,PORTF}Port_Type;

typedef enum 
{LOW,HIGH} Dio_Level_type;



typedef enum 
{
/* PORTA pins diffrent modes */
PA0_DIO=0, PA0_U0Rx=1   , PA0_CAN1Rx=8,
PA1_DIO=0, PA1_U0Tx=1   , PA1_CAN1Tx=8,
PA2_DIO=0, PA2_SSI0CLk=2,
PA3_DIO=0, PA3_SSI0Fss=2,
PA4_DIO=0, PA4_SSI0Rx=2 ,
PA5_DIO=0, PA5_SSI0Tx=2 ,
PA6_DIO=0, PA6_I2C1SCL=3, PA6_M1PWM2=5,
PA7_DIO=0, PA7_I2C1SDA=3, PA6_M1PWM3=5,

/* PORTB pins diffrent modes */
PB0_DIO=0, PB0_U1Rx=1, 		PB0_T2CCP0=7,
PB1_DIO=0, PB1_U1Tx=1, 		PB1_T2CCP1=7,
PB2_DIO=0, PB2_I2C0SCL=3, PB2_T3CCP0=7, 
PB3_DIO=0, PB3_I2C0SDA=3, PB3_T3CCP1=7,
PB4_DIO=0, PB4_SSI2Clk=2, PB4_M0PWM2=4, PB4_T1CCP0=7, PB4_CAN0Rx=8,
PB5_DIO=0, PB5_SSI2Fss=2, PB5_M0PWM3=4, PB5_T1CCP1=7, PB5_CAN0Tx=8,
PB6_DIO=0, PB6_SSI2Rx=2,  PB6_M0PWM0=4, PB6_T1CCP0=7,  
PB7_DIO=0, PB6_SSI2Tx=2,  PB6_M0PWM1=4, PB6_T1CCP1=7   
	
/* PORTC pins diffrent modes */
	
/* PORTD pins diffrent modes */
	
/* PORTE pins diffrent modes */
	
/* PORTF pins diffrent modes */
} Port_PinModeType;
//Table 23-5. GPIO Pins and Alternate Functions Page:1350


typedef enum
{IN,OUT} Port_PinDirectionType;

typedef enum
{UP,DOWN} Port_PinInternalAttachType;	

typedef enum
{mA2, mA4, mA8} Port_PinOutputCurrentType; 


typedef struct 
{
Port_Type										porttype;
Port_PinDirectionType 			portpindirection;
Dio_Channel_Type 						portpin;
Port_PinModeType 						portpinmode;
Dio_Level_type 							portpinlevel;
Port_PinOutputCurrentType   portpinoutputcurrent;
Port_PinInternalAttachType  portpinattach;
}PortPin_ConfigType;


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

 
#endif  /* FILE_NAME_H */

/**********************************************************************************************************************
 *  END OF FILE: Gpio_Types.h
 *********************************************************************************************************************/
