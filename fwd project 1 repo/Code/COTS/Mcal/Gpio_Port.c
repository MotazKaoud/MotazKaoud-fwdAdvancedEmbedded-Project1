/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Gpio_Port.c
 *        \brief  Header file for the Gpio_Port, driver used to configure someport pin to work in some functionality 
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Gpio_Port.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : void PortPin_Init_AHB (const PortPin_ConfigType* Configptr)        
* \Description     : Function to configure some GPIO port pin to work with some functionallity USING THE "AHB" BUS                                  
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : Configptr   struct with the required port configurations
Configptr parameters :  porttype										the required port (PORTA,PORTB,PORTC,PORTD,PORTE,PORTF) 
												portpindirection			 			the required pin direction (IN/OUT)
												portpin					 						the required channel id in the port (P1,P2,P3,P4,P5,P6,P7)
												portpinmode			 						the required channel functionallity (DIO,UARTpin,etc............)
												portpinlevel	 							if DIO the required intial state (HIGH/LOW)
												portpinoutputcurrent	      the required pin current capabillity (2mA, 4mA, 8mA)
												portpinattach						  the required internal attach (Pull Up, Pull Down) 									
* \Parameters (out): None                                                      
* \Return value:   : void

*******************************************************************************/
void PortPin_Init_AHB (const PortPin_ConfigType* Configptr)
{
	
/*0. Select which internal bus is used to access each GPIO port from GPIOHBCTL, set the port corresponding bit to use AHB bus */	
	// use AHB Bus, set PORT corresponding bit 
	GPIOHBCTL |= (1<<(Configptr->porttype));
	
/*1. Enable the clock to the port by setting the appropriate bits in the RCGCGPIO register (see
page 340).*/


   RCGCGPIO |= (1<<(Configptr->porttype)); 

/*2. Set the direction of the GPIO port pins by programming the GPIODIR register. page(662)*/
	if (Configptr->portpindirection) // Output pin, set the bit
	{AHB_GPIODIR_PORT((Configptr->porttype)) |= (1<<(Configptr->portpin));}
  else 	// Input pin, clear the bit
	{AHB_GPIODIR_PORT((Configptr->porttype)) &= ~(1<<(Configptr->portpin));}

/*3. Configure the GPIOAFSEL register to program each bit as a GPIO or alternate pin. If an alternate
pin is chosen for a bit, then the PMCx field must be programmed in the GPIOPCTL register for
the specific peripheral required. 
	refer to Table 23-5. GPIO Pins and Alternate Functions*/
	if ((Configptr->portpinmode) == 0) // Pin is DIO, clear the corresponding bit 
	{
		AHB_GPIOAFSEL_PORT((Configptr->porttype)) &= ~(1<<(Configptr->portpin)); 
	  /* if DIO, intiate the pin with some value*/	
		if (Configptr->portpinlevel) // required level is HIGH, write 1 to bit
	   {AHB_GPIODATA_PORT(Configptr->porttype) |=  (uint32_t)(1<<Configptr->portpin);}
	  else  // required level is LOW, write 0 to bit
	   {AHB_GPIODATA_PORT(Configptr->porttype) &= ~(uint32_t)(1<<Configptr->portpin);}	
	 }
	else // Pin is alterntive function, 1)  
	{
	// set the corresponding bit in GPIOAFSEL	
	AHB_GPIOAFSEL_PORT((Configptr->porttype)) |= (1<<(Configptr->portpin));
		
	// choose the required functionallity in GPIOPCTL
	AHB_GPIOPCTL_PORT(Configptr->porttype) |= ((Configptr->portpinmode)<<((Configptr->portpin)*4)) ; 
	}
	
/*4. Set the drive strength for each of the pins through the GPIODR2R, GPIODR4R, and GPIODR8R
registers.*/	
	
	if      ((Configptr->portpinoutputcurrent) == 0) // required 2-mA, set corresponding bit in GPIODR2R
	{AHB_GPIODR2R_PORT(Configptr->porttype) |= (1<<(Configptr->portpin)); }
	else if ((Configptr->portpinoutputcurrent) == 1) // required 2-mA, set corresponding bit in GPIODR4R
	{AHB_GPIODR4R_PORT(Configptr->porttype) |= (1<<(Configptr->portpin)); }
	else if ((Configptr->portpinoutputcurrent) == 2) // required 2-mA, set corresponding bit in GPIODR8R
	{AHB_GPIODR8R_PORT(Configptr->porttype) |= (1<<(Configptr->portpin)); }

/*5. Program each pad in the port to have either pull-up, pull-down, or open drain functionality through
the GPIOPUR, GPIOPDR, GPIOODR register. Slew rate may also be programmed, if needed,
through the GPIOSLR register. */
	if ((Configptr->portpinattach) == 0) // Pull-Up is required
	{AHB_GPIOPUR_PORT(Configptr->porttype) |= (1<<(Configptr->portpin));}
	else // Pull-Down is required
	{AHB_GPIOPDR_PORT(Configptr->porttype) |= (1<<(Configptr->portpin));}
	
/*6. To enable GPIO pins as digital I/Os, set the appropriate DEN bit in the GPIODEN register. To
enable GPIO pins to their analog function (if available), set the GPIOAMSEL bit in the
GPIOAMSEL register. */
	if ((Configptr->portpinmode) == 0) // Pin is DIO,
	{AHB_GPIODEN_PORT(Configptr->porttype) |= (1<<(Configptr->portpin));}
}


/******************************************************************************
* \Syntax          : void PortPin_Init_AHB (const PortPin_ConfigType* Configptr)        
* \Description     : Function to configure some GPIO port pin to work with some functionallity USING THE "APB" BUS                                  
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : Configptr   struct with the required port configurations
Configptr parameters :  porttype										the required port (PORTA,PORTB,PORTC,PORTD,PORTE,PORTF) 
												portpindirection			 			the required pin direction (IN/OUT)
												portpin					 						the required channel id in the port (P1,P2,P3,P4,P5,P6,P7)
												portpinmode			 						the required channel functionallity (DIO,UARTpin,etc............)
												portpinlevel	 							if DIO the required intial state (HIGH/LOW)
												portpinoutputcurrent	      the required pin current capabillity (2mA, 4mA, 8mA)
												portpinattach						  the required internal attach (Pull Up, Pull Down)  									
* \Parameters (out): None                                                      
* \Return value:   : void

*******************************************************************************/
void PortPin_Init_APB (const PortPin_ConfigType* Configptr)
{

/*0. Select which internal bus is used to access each GPIO port from GPIOHBCTL, set the port corresponding bit to use AHB bus */	
	// use APB Bus, clear PORT corresponding bit 
	GPIOHBCTL &= ~(1<<(Configptr->porttype));
	
/*1. Enable the clock to the port by setting the appropriate bits in the RCGCGPIO register (see
page 340).*/

	 *((uint32_t *)(0x400FE608)) = 0x1;
   RCGCGPIO |= (1<<(Configptr->porttype)); 

/*2. Set the direction of the GPIO port pins by programming the GPIODIR register. page(662)*/
	if (Configptr->portpindirection) // Output pin, set the bit
	{APB_GPIODIR_PORT((Configptr->porttype)) |= (1<<(Configptr->portpin));}
  else 	// Input pin, clear the bit
	{APB_GPIODIR_PORT((Configptr->porttype)) &= ~(1<<(Configptr->portpin));}

/*3. Configure the GPIOAFSEL register to program each bit as a GPIO or alternate pin. If an alternate
pin is chosen for a bit, then the PMCx field must be programmed in the GPIOPCTL register for
the specific peripheral required. */
	if ((Configptr->portpinmode) == 0) // Pin is DIO, clear the corresponding bit 
	{
	  APB_GPIOAFSEL_PORT((Configptr->porttype)) &= ~(1<<(Configptr->portpin)); 
/* if DIO, intiate the pin with some value*/	
		if (Configptr->portpinlevel) // required level is HIGH, write 1 to bit
	   {APB_GPIODATA_PORT(Configptr->porttype) |=  (uint32_t)(1<<Configptr->portpin);}
	  else  // required level is LOW, write 0 to bit
	   {APB_GPIODATA_PORT(Configptr->porttype) &= ~(uint32_t)(1<<Configptr->portpin);}	
	 }
	else // Pin is alterntive function, 1)  
	{
	// set the corresponding bit in GPIOAFSEL	
	APB_GPIOAFSEL_PORT((Configptr->porttype)) |= (1<<(Configptr->portpin));
		
	// choose the required functionallity in GPIOPCTL
	APB_GPIOPCTL_PORT(Configptr->porttype) |= ((Configptr->portpinmode)<<((Configptr->portpin)*4)) ; 
	}
	
/*4. Set the drive strength for each of the pins through the GPIODR2R, GPIODR4R, and GPIODR8R
registers.*/	
	
	if      ((Configptr->portpinoutputcurrent) == 0) // required 2-mA, set corresponding bit in GPIODR2R
	{APB_GPIODR2R_PORT(Configptr->porttype) |= (1<<(Configptr->portpin)); }
	else if ((Configptr->portpinoutputcurrent) == 1) // required 2-mA, set corresponding bit in GPIODR4R
	{APB_GPIODR4R_PORT(Configptr->porttype) |= (1<<(Configptr->portpin)); }
	else if ((Configptr->portpinoutputcurrent) == 2) // required 2-mA, set corresponding bit in GPIODR8R
	{APB_GPIODR4R_PORT(Configptr->porttype) |= (1<<(Configptr->portpin)); }

/*5. Program each pad in the port to have either pull-up, pull-down, or open drain functionality through
the GPIOPUR, GPIOPDR, GPIOODR register. Slew rate may also be programmed, if needed,
through the GPIOSLR register. */
	if ((Configptr->portpinattach) == 0) // Pull-Up is required
	{APB_GPIOPUR_PORT(Configptr->porttype) |= (1<<(Configptr->portpin));}
	else // Pull-Down is required
	{APB_GPIOPDR_PORT(Configptr->porttype) |= (1<<(Configptr->portpin));}
	
/*6. To enable GPIO pins as digital I/Os, set the appropriate DEN bit in the GPIODEN register. To
enable GPIO pins to their analog function (if available), set the GPIOAMSEL bit in the
GPIOAMSEL register. */
	if ((Configptr->portpinmode) == 0) // Pin is DIO,
	{APB_GPIODEN_PORT(Configptr->porttype) |= (1<<(Configptr->portpin));}
	


}




/**********************************************************************************************************************
 *  END OF FILE: Gpio_Port.c
 *********************************************************************************************************************/






