/************************************************************************/
/*                         Includes                                     */
/************************************************************************/

#include "Delay.h"

/************************************************************************/
/*                        Software Delay functions                      */
/************************************************************************/

void softwareDelayMs(int u32_delay_in_ms)
{
	/*looping for number of counts that each count is 1ms approximately*/
	while(u32_delay_in_ms > 0)
	{
		for (int i = 0 ; i < 2000 ; i++);
		u32_delay_in_ms--;
	}
	return;
}
