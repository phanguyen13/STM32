#include "LED7SEG_point.h"


char AnodeNumber[] = {
  0xC0, // 0
  0xF9, // 1
  0xA4, // 2
  0xB0, // 3
  0x99, // 4
  0x92, // 5
  0x82, // 6
  0x8F, // 7
  0x80, // 8
  0x90, // 9
    // DP
};
char CathodeNumber[] = {
  0x3F, // 0
  0x06, // 1
  0x5B, // 2
  0x4F, // 3
  0x66, // 4
  0x6D, // 5
  0x7D, // 6
  0x07, // 7
  0x7F, // 8
  0x6F, // 9
    // DP 
};


void LED7SEG_Init(LED7PORT_Data* LED7SEG, LED7TYPE Led7Type,
											GPIO_TypeDef* PORT_A,  uint16_t PORT_A_Pin,
											GPIO_TypeDef* PORT_B,  uint16_t PORT_B_Pin,
											GPIO_TypeDef* PORT_C,  uint16_t PORT_C_Pin,
											GPIO_TypeDef* PORT_D,  uint16_t PORT_D_Pin,
											GPIO_TypeDef* PORT_E,  uint16_t PORT_E_Pin,	
											GPIO_TypeDef* PORT_F,  uint16_t PORT_F_Pin,
											GPIO_TypeDef* PORT_G,  uint16_t PORT_G_Pin,	
											GPIO_TypeDef* PORT_H, 	uint16_t PORT_H_Pin)
{
	LED7SEG->Led7Type = Led7Type;
	LED7SEG->PORT_A = PORT_A;
	LED7SEG->PORT_B = PORT_B;
	LED7SEG->PORT_C = PORT_C;
	LED7SEG->PORT_D = PORT_D;
	LED7SEG->PORT_E = PORT_E;
	LED7SEG->PORT_F = PORT_F;
	LED7SEG->PORT_G = PORT_G;
	LED7SEG->PORT_H = PORT_H;
	LED7SEG->PORT_A_Pin = PORT_A_Pin;
	LED7SEG->PORT_B_Pin = PORT_B_Pin;
	LED7SEG->PORT_C_Pin = PORT_C_Pin;
	LED7SEG->PORT_D_Pin = PORT_D_Pin;
	LED7SEG->PORT_E_Pin = PORT_E_Pin;
	LED7SEG->PORT_F_Pin = PORT_F_Pin;
	LED7SEG->PORT_G_Pin = PORT_G_Pin;
	LED7SEG->PORT_H_Pin = PORT_H_Pin;
}
void LED7SEG_InitScan(LED7SEG_Num* LED7_NUM, GPIO_TypeDef* PORT_LED1, uint16_t PORT_LED1_pin, 
											GPIO_TypeDef* PORT_LED2, uint16_t PORT_LED2_pin,
											GPIO_TypeDef* PORT_LED3, uint16_t PORT_LED3_pin, 
											GPIO_TypeDef* PORT_LED4, uint16_t PORT_LED4_pin,
											GPIO_TypeDef* PORT_LED5, uint16_t PORT_LED5_pin,
											GPIO_TypeDef* PORT_LED6, uint16_t PORT_LED6_pin)
{
	LED7_NUM->PORT_LED1 = PORT_LED1;
	LED7_NUM->PORT_LED2 = PORT_LED2;
	LED7_NUM->PORT_LED3 = PORT_LED3;
	LED7_NUM->PORT_LED4 = PORT_LED4;
	LED7_NUM->PORT_LED5 = PORT_LED5;
	LED7_NUM->PORT_LED6 = PORT_LED6;
	LED7_NUM->PORT_LED1_pin = PORT_LED1_pin;
	LED7_NUM->PORT_LED2_pin = PORT_LED2_pin;
	LED7_NUM->PORT_LED3_pin = PORT_LED3_pin;
	LED7_NUM->PORT_LED4_pin = PORT_LED4_pin;
	LED7_NUM->PORT_LED5_pin = PORT_LED5_pin;
	LED7_NUM->PORT_LED6_pin = PORT_LED6_pin;
}
void LED7SEG_WriteOneNumber(LED7PORT_Data* LED7SEG, uint8_t number)
{
	if(LED7SEG->Led7Type == ANODE)
	{
		HAL_GPIO_WritePin(LED7SEG->PORT_A, LED7SEG->PORT_A_Pin, AnodeNumber[number]&0x01?GPIO_PIN_SET:GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED7SEG->PORT_B, LED7SEG->PORT_B_Pin, AnodeNumber[number]&0x02?GPIO_PIN_SET:GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED7SEG->PORT_C, LED7SEG->PORT_C_Pin, AnodeNumber[number]&0x04?GPIO_PIN_SET:GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED7SEG->PORT_D, LED7SEG->PORT_D_Pin, AnodeNumber[number]&0x08?GPIO_PIN_SET:GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED7SEG->PORT_E, LED7SEG->PORT_E_Pin, AnodeNumber[number]&0x10?GPIO_PIN_SET:GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED7SEG->PORT_F, LED7SEG->PORT_F_Pin, AnodeNumber[number]&0x20?GPIO_PIN_SET:GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED7SEG->PORT_G, LED7SEG->PORT_G_Pin, AnodeNumber[number]&0x40?GPIO_PIN_SET:GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED7SEG->PORT_H, LED7SEG->PORT_H_Pin, AnodeNumber[number]&0x80?GPIO_PIN_SET:GPIO_PIN_RESET);
	}
	else if(LED7SEG->Led7Type == CATHODE)
	{
		HAL_GPIO_WritePin(LED7SEG->PORT_A, LED7SEG->PORT_A_Pin, CathodeNumber[number]&0x01?GPIO_PIN_SET:GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED7SEG->PORT_B, LED7SEG->PORT_B_Pin, CathodeNumber[number]&0x02?GPIO_PIN_SET:GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED7SEG->PORT_C, LED7SEG->PORT_C_Pin, CathodeNumber[number]&0x04?GPIO_PIN_SET:GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED7SEG->PORT_D, LED7SEG->PORT_D_Pin, CathodeNumber[number]&0x08?GPIO_PIN_SET:GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED7SEG->PORT_E, LED7SEG->PORT_E_Pin, CathodeNumber[number]&0x10?GPIO_PIN_SET:GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED7SEG->PORT_F, LED7SEG->PORT_F_Pin, CathodeNumber[number]&0x20?GPIO_PIN_SET:GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED7SEG->PORT_G, LED7SEG->PORT_G_Pin, CathodeNumber[number]&0x40?GPIO_PIN_SET:GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED7SEG->PORT_H, LED7SEG->PORT_H_Pin, CathodeNumber[number]&0x80?GPIO_PIN_SET:GPIO_PIN_RESET);
	}
}

LED7SEG_NumberInt LED7PORT_ConvertInt(uint32_t number) 
{
	LED7SEG_NumberInt numberInt;
	numberInt.Thundredthousand = number / 100000; 
	number %= 100000; 
	numberInt.TenOfThousands = number / 10000;
	number %= 10000; 
	numberInt.Thousands = number / 1000; 
	number %= 1000; 
	numberInt.Hundreds = number / 100; 
	number %= 100; 
	numberInt.Dozens = number / 10;
	number %= 10; 
	numberInt.Uints = number / 1; 
	return numberInt;
}

void LED7SEG_Scan6Led(LED7SEG_Num* LED7_NUM, LED7PORT_Data* LED7SEG, uint32_t number)
{
	LED7SEG_NumberInt number_convert;
	number_convert = LED7PORT_ConvertInt(number);
	
	HAL_GPIO_WritePin(LED7_NUM->PORT_LED6, LED7_NUM->PORT_LED6_pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED7_NUM->PORT_LED1, LED7_NUM->PORT_LED1_pin, GPIO_PIN_SET);
	LED7SEG_WriteOneNumber(LED7SEG, number_convert.Thundredthousand);
	HAL_Delay(1);
	
	HAL_GPIO_WritePin(LED7_NUM->PORT_LED1, LED7_NUM->PORT_LED1_pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED7_NUM->PORT_LED2, LED7_NUM->PORT_LED2_pin, GPIO_PIN_SET);
	LED7SEG_WriteOneNumber(LED7SEG, number_convert.TenOfThousands);
	HAL_Delay(1);
	
	HAL_GPIO_WritePin(LED7_NUM->PORT_LED2, LED7_NUM->PORT_LED2_pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED7_NUM->PORT_LED3, LED7_NUM->PORT_LED3_pin, GPIO_PIN_SET);
	LED7SEG_WriteOneNumber(LED7SEG, number_convert.Thousands);
	HAL_Delay(1);
	
	HAL_GPIO_WritePin(LED7_NUM->PORT_LED3, LED7_NUM->PORT_LED3_pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED7_NUM->PORT_LED4, LED7_NUM->PORT_LED4_pin, GPIO_PIN_SET);
	LED7SEG_WriteOneNumber(LED7SEG, number_convert.Hundreds);
	HAL_Delay(1);
	
	HAL_GPIO_WritePin(LED7_NUM->PORT_LED4, LED7_NUM->PORT_LED4_pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED7_NUM->PORT_LED5, LED7_NUM->PORT_LED5_pin, GPIO_PIN_SET);
	LED7SEG_WriteOneNumber(LED7SEG, number_convert.Dozens);
	HAL_Delay(1);
	
	HAL_GPIO_WritePin(LED7_NUM->PORT_LED5, LED7_NUM->PORT_LED5_pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED7_NUM->PORT_LED6, LED7_NUM->PORT_LED6_pin, GPIO_PIN_SET);
	LED7SEG_WriteOneNumber(LED7SEG, number_convert.Uints);
	HAL_Delay(1);
}	
