#ifndef __LED7PORT_H
#define __LED7PORT_H
#include "main.h"

typedef enum
{
  ANODE = 0u,
  CATHODE
} LED7TYPE;


typedef struct {  
	LED7TYPE Led7Type;
	GPIO_TypeDef* PORT_A;  
	uint16_t PORT_A_Pin;
	GPIO_TypeDef* PORT_B;  
	uint16_t PORT_B_Pin;
	GPIO_TypeDef* PORT_C;  
	uint16_t PORT_C_Pin;
	GPIO_TypeDef* PORT_D;  
	uint16_t PORT_D_Pin;
	GPIO_TypeDef* PORT_E; 
	uint16_t PORT_E_Pin;	
	GPIO_TypeDef* PORT_F;  
	uint16_t PORT_F_Pin;
	GPIO_TypeDef* PORT_G; 
	uint16_t PORT_G_Pin;	
	GPIO_TypeDef* PORT_H;  
	uint16_t PORT_H_Pin;
}LED7PORT_Data;

typedef struct {  
	GPIO_TypeDef* PORT_LED1;  
	uint16_t PORT_LED1_pin;
	GPIO_TypeDef* PORT_LED2;  
	uint16_t PORT_LED2_pin;
	GPIO_TypeDef* PORT_LED3;  
	uint16_t PORT_LED3_pin;
	GPIO_TypeDef* PORT_LED4; 
	uint16_t PORT_LED4_pin;	
	GPIO_TypeDef* PORT_LED5; 
	uint16_t PORT_LED5_pin;
	GPIO_TypeDef* PORT_LED6; 
	uint16_t PORT_LED6_pin;
}LED7SEG_Num;

typedef struct {
	uint16_t Thundredthousand; 
	uint16_t TenOfThousands;
	uint16_t Thousands;
	uint16_t Hundreds;
	uint16_t Dozens;
	uint16_t Uints;
}LED7SEG_NumberInt;

extern char AnodeNumber[];
extern char CathodeNumber[];

void LED7SEG_Init(LED7PORT_Data* LED7SEG, LED7TYPE Led7Type,
											GPIO_TypeDef* PORT_A,  uint16_t PORT_A_Pin,
											GPIO_TypeDef* PORT_B,  uint16_t PORT_B_Pin,
											GPIO_TypeDef* PORT_C,  uint16_t PORT_C_Pin,
											GPIO_TypeDef* PORT_D,  uint16_t PORT_D_Pin,
											GPIO_TypeDef* PORT_E,  uint16_t PORT_E_Pin,	
											GPIO_TypeDef* PORT_F,  uint16_t PORT_F_Pin,
											GPIO_TypeDef* PORT_G,  uint16_t PORT_G_Pin,	
											GPIO_TypeDef* PORT_H, 	uint16_t PORT_H_Pin);

void LED7SEG_InitScan(LED7SEG_Num* LED7_NUM, GPIO_TypeDef* PORT_LED1, uint16_t PORT_LED1_pin, 
											GPIO_TypeDef* PORT_LED2, uint16_t PORT_LED2_pin,
											GPIO_TypeDef* PORT_LED3, uint16_t PORT_LED3_pin, 
											GPIO_TypeDef* PORT_LED4, uint16_t PORT_LED4_pin,
											GPIO_TypeDef* PORT_LED5, uint16_t PORT_LED5_pin,
											GPIO_TypeDef* PORT_LED6, uint16_t PORT_LED6_pin);

void LED7SEG_WriteOneNumber(LED7PORT_Data* LED7SEG, uint8_t number);
LED7SEG_NumberInt LED7PORT_ConvertInt(uint32_t number);
void LED7SEG_Scan6Led(LED7SEG_Num* LED7_NUM, LED7PORT_Data* LED7SEG, uint32_t number);


#endif

