#ifndef __LED7SEG_H
#define __LED7SEG_H
#include "main.h"

extern unsigned char digitHex_Anode[10];
extern unsigned char digitHex_Cathode[10];
extern int buff[6];
extern uint16_t ledPins[6];
extern GPIO_TypeDef* ledPorts[6];
extern uint16_t ledPins_data[];
extern GPIO_TypeDef* ledPorts_data[];
void print_led(int num);
//void scanLED(int time_loop,int num);
void set_time(int h,int m, int s);
void scanLED(int time_loop,int h,int m, int s);
#endif
