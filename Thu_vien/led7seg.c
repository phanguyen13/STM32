#include "led7seg.h"
#include "delay.h"

unsigned char digitHex_Anode[10] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};
unsigned char digitHex_Cathode[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};
int buff[6] = {0, 0, 0, 0, 0, 0};

uint16_t ledPins[] = {GPIO_PIN_0, GPIO_PIN_1, GPIO_PIN_2, GPIO_PIN_3,GPIO_PIN_7,GPIO_PIN_14};

GPIO_TypeDef* ledPorts[] = {GPIOB, GPIOB, GPIOB, GPIOB, GPIOB ,GPIOB};

uint16_t ledPins_data[] = {GPIO_PIN_0, GPIO_PIN_1, GPIO_PIN_2, GPIO_PIN_3,GPIO_PIN_4,GPIO_PIN_5,GPIO_PIN_6,GPIO_PIN_7,GPIO_PIN_8,GPIO_PIN_9};

GPIO_TypeDef* ledPorts_data[] = {GPIOA, GPIOA, GPIOA, GPIOA, GPIOA , GPIOA, GPIOA, GPIOA, GPIOA};

void print_led(int num) {
    buff[0] = num / 100000; 
    buff[1] = (num % 100000) / 10000; 
    buff[2] = (num % 10000) / 1000; 
    buff[3] = (num % 1000) / 100; 
    buff[4] = (num % 100) / 10; 
    buff[5] = num % 10; 
}

void set_time(int h,int m, int s) {
    buff[0] = (h % 100)/10; 
    buff[1] = h % 10;
    buff[2] = (m % 100)/10; 
    buff[3] = m % 10;
    buff[4] = (s % 100)/10;  
    buff[5] = s % 10; 
}

void scanLED(int time_loop,int h,int m, int s) {
	set_time( h, m, s);
    for (int dl = 0; dl < time_loop; dl++) {
        for (int ledIndex = 0; ledIndex < 6; ledIndex++) {
            ledPorts_data[ledIndex]->ODR &= ~(0xFF); 
            ledPorts_data[ledIndex]->ODR |= digitHex_Anode[buff[ledIndex]]; 
            ledPorts[ledIndex]->ODR |= ledPins[ledIndex]; 
            for(int on_led=0;on_led<1000;on_led++){} 
            ledPorts[ledIndex]->ODR &= ~ledPins[ledIndex]; 
        }
    }
}




