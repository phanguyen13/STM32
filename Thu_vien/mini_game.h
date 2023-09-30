
#include "main.h"
#include "keypad.h"
#include "led7seg.h"
#include <stdlib.h>
#include <stdio.h>
#define NUM_LEDS 10

GPIO_TypeDef *led_ports_game[NUM_LEDS];
uint16_t led_pins_game[NUM_LEDS];
void initializeLEDs(void);
void runGame(void);



