#include "mini_game.h"

void initializeLEDs() {
	for(int i=0;i<10;i++){
led_ports_game[i]->ODR &= ~led_pins_game[i];
	}
}

void runGame() {
    initializeLEDs();
    static int selectedPosition = -1;
    int start;
		static int winningPosition;
    while (1) {
				while(1){
							while(1){
								selectedPosition = Keypad_Scan();
								print_led(selectedPosition);
								scanLED(10);
								if(selectedPosition!=(-1)){
								break;
								}
							}	
					start = Keypad_Scan();
					if(start==10){
					print_led(0003);
					scanLED(100);
					print_led(0002);
					scanLED(100);
					print_led(0001);
					scanLED(100);
						break;
					}
				}
				winningPosition = rand() % 21;
				print_led(winningPosition);
				scanLED(10);
				for (int i = 0; i < winningPosition; i++) {
					int currentPosition = i % NUM_LEDS;
					led_ports_game[currentPosition]->ODR |= led_pins_game[currentPosition];
					HAL_Delay(500);						
					led_ports_game[currentPosition]->ODR &= ~led_pins_game[currentPosition];
				}
				while(1){

					int result = winningPosition % 10;
					if(result==1){result=1;}
					if(selectedPosition==12){selectedPosition=0;}
					if(selectedPosition==result){
						for (int i = 0; i < 10; i++) {
							print_led(selectedPosition*100+winningPosition);
							scanLED(1);
							led_ports_game[i]->ODR |= led_pins_game[i];
							HAL_Delay(50);
							led_ports_game[i]->ODR &= ~led_pins_game[i];
						}
					}
					else{
	
						for (int i = 0; i < 10; i++) {
							print_led(selectedPosition*100+winningPosition);
							scanLED(1);
							led_ports_game[i]->ODR |= led_pins_game[i];

						}

					}
					start = Keypad_Scan();
					if(start==11){
						break;
					}
				}
				initializeLEDs();
				selectedPosition=-1;
		}
}

