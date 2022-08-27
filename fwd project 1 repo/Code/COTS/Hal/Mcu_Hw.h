/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Mcu_Hw.h
 *       Module:  -
 *
 *  Description:  microcontroller hardware registers adress mapping
 *  
 *********************************************************************************************************************/
#ifndef MCU_HW_H
#define MCU_HW_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include <stdint.h>

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
*********************************************************************************************************************/
////////////////////// NVIC Registers ///////////////////////////

#define PERIPHERAL_BASE_ADRESS  0xE000E000
#define APINT *((uint32_t *)(PERIPHERAL_BASE_ADRESS + 0XD0C))
#define APINT_MASK (0xFFFF0700)
#define APINT_Clear (APINT & ~(APINT_MASK))
#define APINT_PRI_XXX  (APINT | 0x05FA0400)
#define APINT_PRI_XXY  (APINT | 0x05FA0500)
#define APINT_PRI_XYY  (APINT | 0x05FA0600)
#define APINT_PRI_YYY  (APINT | 0x05FA0700)

#define NVIC_PRI(x) *((uint32_t *)(PERIPHERAL_BASE_ADRESS + 0X400 + (x*4) )
#define INTA(x) (x<<5)
#define INTB(x) (x<<13)
#define INTC(x) (x<<21)
#define INTD(x) (x<<29)

////////////////////// Systick Timer Registers ///////////////////////////
#define CORE_PERIPHERALS_BASE_ADRESS  (0xE000E000)
 
#define STCTRL									*((uint32_t *)(CORE_PERIPHERALS_BASE_ADRESS + 0x010))
#define STRELOAD								*((uint32_t *)(CORE_PERIPHERALS_BASE_ADRESS + 0x014))
#define STCURRENT 							*((uint32_t *)(CORE_PERIPHERALS_BASE_ADRESS + 0x018))


////////////////////// GPIO Registers ///////////////////////////
#define PORTS_CONFIG_BASE 						(0x400FE000)
#define AHB_BASE_ADRESS_PORT(x) 			(0x40058000 + (0x1000 * x))
#define APB_BASE_ADRESS_PORT(x) 			(0x40004000 + (0x1000 * x))
// x : PORTA=0, PORTB=1, PORTC=2, PORTD=3, PORTE=4, PORTF=5


#define GPIOHBCTL								*((uint32_t *)(PORTS_CONFIG_BASE + 0x06C))
#define RCGCGPIO					      *((uint32_t *)(PORTS_CONFIG_BASE + 0x608))
#define AHB_GPIODATA_PORT(x) 		*((uint32_t *)(AHB_BASE_ADRESS_PORT(x) +  0x000))
#define APB_GPIODATA_PORT(x) 		*((uint32_t *)(APB_BASE_ADRESS_PORT(x) +  0x000))
#define AHB_GPIODIR_PORT(x)     *((uint32_t *)(AHB_BASE_ADRESS_PORT(x) +  0x400))
#define APB_GPIODIR_PORT(x)     *((uint32_t *)(APB_BASE_ADRESS_PORT(x) +  0x400))
#define AHB_GPIOAFSEL_PORT(x)   *((uint32_t *)(AHB_BASE_ADRESS_PORT(x) +  0x420))
#define APB_GPIOAFSEL_PORT(x)   *((uint32_t *)(APB_BASE_ADRESS_PORT(x) +  0x420))
#define AHB_GPIOPCTL_PORT(x) 		*((uint32_t *)(AHB_BASE_ADRESS_PORT(x) +  0x52C))
#define APB_GPIOPCTL_PORT(x) 		*((uint32_t *)(APB_BASE_ADRESS_PORT(x) +  0x52C))
#define AHB_GPIODR2R_PORT(x) 		*((uint32_t *)(AHB_BASE_ADRESS_PORT(x) +  0x500))
#define APB_GPIODR2R_PORT(x) 		*((uint32_t *)(APB_BASE_ADRESS_PORT(x) +  0x500))
#define AHB_GPIODR4R_PORT(x) 		*((uint32_t *)(AHB_BASE_ADRESS_PORT(x) +  0x504))
#define APB_GPIODR4R_PORT(x) 		*((uint32_t *)(APB_BASE_ADRESS_PORT(x) +  0x504))
#define AHB_GPIODR8R_PORT(x) 		*((uint32_t *)(AHB_BASE_ADRESS_PORT(x) +  0x508))
#define APB_GPIODR8R_PORT(x) 		*((uint32_t *)(APB_BASE_ADRESS_PORT(x) +  0x508))
#define AHB_GPIOPUR_PORT(x) 		*((uint32_t *)(AHB_BASE_ADRESS_PORT(x) +  0x510))
#define APB_GPIOPUR_PORT(x) 		*((uint32_t *)(APB_BASE_ADRESS_PORT(x) +  0x510))
#define AHB_GPIOPDR_PORT(x)			*((uint32_t *)(AHB_BASE_ADRESS_PORT(x) +  0x514))
#define APB_GPIOPDR_PORT(x)			*((uint32_t *)(APB_BASE_ADRESS_PORT(x) +  0x514))
#define AHB_GPIODEN_PORT(x)			*((uint32_t *)(AHB_BASE_ADRESS_PORT(x) +  0x51C))
#define APB_GPIODEN_PORT(x)			*((uint32_t *)(APB_BASE_ADRESS_PORT(x) +  0x51C))





/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef struct
{
	uint8_t P0 :1 ;
	uint8_t P1 :1 ;
	uint8_t P2 :1 ;
	uint8_t P3 :1 ;
	uint8_t P4 :1 ;
	uint8_t P5 :1 ;
	uint8_t P6 :1 ;
	uint8_t P7 :1 ;

}GPIODATA;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

 
#endif


/**********************************************************************************************************************
 *  END OF FILE: Mcu_Hw.h
 *********************************************************************************************************************/
