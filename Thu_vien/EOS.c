#include "EOS.h"

void EOS_init(unsigned int x)
{
SysTick->LOAD = System_clock/1000*x;
SysTick->VAL=0;
SysTick->CTRL=7;
}

