#include "keypad.h"
// M?ng luu giá tr? c?a các hàng và c?t
GPIO_TypeDef *row_ports[NUM_ROWS] = {GPIOA, GPIOA, GPIOA, GPIOA};
GPIO_TypeDef *col_ports[NUM_COLS] = {GPIOB, GPIOB, GPIOB};

uint16_t row_pins[NUM_ROWS] = {ROW_1_PIN, ROW_2_PIN, ROW_3_PIN, ROW_4_PIN};
uint16_t col_pins[NUM_COLS] = {COL_1_PIN, COL_2_PIN, COL_3_PIN};

// M?ng luu giá tr? c?a các nút
uint16_t keys[NUM_ROWS][NUM_COLS] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9},
    {10, 0, 11},
};

uint16_t Keypad_Scan(void) {
    static uint16_t previousKey = 0;
    uint16_t key = 0;

    for (int col = 0; col < NUM_COLS; col++) {
        HAL_GPIO_WritePin(col_ports[col], col_pins[col], GPIO_PIN_RESET);
        for (int row = 0; row < NUM_ROWS; row++) {
            if (HAL_GPIO_ReadPin(row_ports[row], row_pins[row]) == 0) {
                key = keys[row][col];
                break;
            }
        }
        HAL_GPIO_WritePin(col_ports[col], col_pins[col], GPIO_PIN_SET);
        if (key) {
            break;
        }
    }

    if (key == 0) {
        key = previousKey;
    } else {
        previousKey = key; // Luu l?i giá tr? nút m?i
    }

    return key;
}

