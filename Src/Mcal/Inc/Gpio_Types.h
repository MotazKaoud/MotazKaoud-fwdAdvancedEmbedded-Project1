#include <stdint.h>

#ifndef GPIO_TYPES_H
#define GPIO_TYPES_H

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

typedef uint8_t PortLevelType ; 

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
PA7_DIO=0, PA7_I2C1SDA=3, PA6_M1PWM3=5

/* PORTB pins diffrent modes */
	
/* PORTC pins diffrent modes */
	
/* PORTD pins diffrent modes */
	
/* PORTE pins diffrent modes */
	
/* PORTF pins diffrent modes */
} Port_PinModeType;

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
	
#endif
