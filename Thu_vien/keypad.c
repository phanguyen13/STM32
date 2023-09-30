#include "keypad.h"
// M?ng luu giá tr? c?a các hàng và c?t
GPIO_TypeDef *row_ports[NUM_ROWS] = {GPIOA, GPIOA, GPIOA, GPIOA};
GPIO_TypeDef *col_ports[NUM_COLS] = {GPIOB, GPIOB, GPIOB};

uint16_t row_pins[NUM_ROWS] = {ROW_1_PIN, ROW_2_PIN, ROW_3_PIN, ROW_4_PIN};
uint16_t col_pins[NUM_COLS] = {COL_1_PIN, COL_2_PIN, COL_3_PIN};

// M?ng luu giá tr? c?a các nút
char keys[NUM_ROWS][NUM_COLS] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'},
    {'*', '0', '#'},
};

char Keypad_Scan(void) { // Thay d?i ki?u tr? v? thành char
    static char previousKey = 0; // Thay d?i ki?u bi?n thành char
    static char currentKey = 0; // Thay d?i ki?u bi?n thành char
    static uint8_t count = 0; // Bi?n d?m s? l?n g?i hàm SysTick_Handler
    char key = 0; // Thay d?i ki?u bi?n thành char

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
        currentKey = key; // Luu l?i giá tr? nút m?i
        count++; // Tang bi?n d?m lên 1
        if (count == 2) { // N?u dã g?i hàm SysTick_Handler hai l?n
            if (currentKey == previousKey) { // N?u giá tr? nút m?i b?ng giá tr? nút cu
                key = currentKey; // Xác nh?n nút du?c nh?n
            } else { // N?u không b?ng nhau
                key = 0; // B? qua nút du?c nh?n
            }
            count = 0; // Ð?t l?i bi?n d?m v? 0
        } else { // N?u chua g?i hàm SysTick_Handler hai l?n
            key = 0; // B? qua nút du?c nh?n
        }
        previousKey = currentKey; // C?p nh?t giá tr? nút cu
    }

    return key;
}
