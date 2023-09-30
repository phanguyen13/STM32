#ifndef __DELAY_H
#define __DELAY_H
#include "main.h"
#include "stm32f1xx_hal.h" 
#define System_clock 8000000UL

void SysTick_delay(unsigned int x);

#endif
