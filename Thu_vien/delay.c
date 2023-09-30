#include "delay.h"

void SysTick_delay(unsigned int x)
{
SysTick->LOAD = System_clock /1000*x ; // set reload register
SysTick->VAL = 0; // Load the SysTick Counter Value
SysTick->CTRL = 5; // Select Core clock + ENABLE
while((SysTick->CTRL & 1<<16) == 0);
}


