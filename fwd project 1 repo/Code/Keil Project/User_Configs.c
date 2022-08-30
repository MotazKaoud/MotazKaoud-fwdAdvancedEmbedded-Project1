#include "User_Configs.h"

void CBK_Fn (uint32_t *notif)
{
if (*notif > 5)
{*notif = 0 ;}
}

void testfn (uint32_t *x) {x+=100;}
	
	