#include "IntCtrl.h"

void IntCtrl_Init (void) 
{

	/*TODO Configure Grouping\SubGrouping System in APINT register in SCB*/
 
		//APINT = APINT_Clear ; 
    APINT =	APINT_PRI_XXY;
	
    /*TODO : Assign Group\Subgroup priority in NVIC_PRIx Nvic and SCB_SYSPRIx Registers*/  
   // NVIC_PRI(5) = 3 ;

	/*TODO : Enable\Disable based on user configurations in NVIC_ENx and SCB_Sys Registers */


	
}
