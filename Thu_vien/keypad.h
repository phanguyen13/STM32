#ifndef __KEYPAD_H
#define __KEYPAD_H
#include "main.h"

#define NUM_ROWS 4
#define NUM_COLS 3

#define ROW_1_PIN GPIO_PIN_8
#define ROW_2_PIN GPIO_PIN_9
#define ROW_3_PIN GPIO_PIN_10
#define ROW_4_PIN GPIO_PIN_11

#define COL_1_PIN GPIO_PIN_4
#define COL_2_PIN GPIO_PIN_5
#define COL_3_PIN GPIO_PIN_6

#define DEBOUNCE_DELAY_MS 500 // Th?i gian debounce (50ms, b?n có th? di?u ch?nh)

extern GPIO_TypeDef *row_ports[NUM_ROWS];
extern GPIO_TypeDef *col_ports[NUM_COLS];
extern uint16_t row_pins[NUM_ROWS];
extern uint16_t col_pins[NUM_COLS];
extern uint16_t keys[NUM_ROWS][NUM_COLS];
extern uint16_t Keypad_Scan(void);

#endif
