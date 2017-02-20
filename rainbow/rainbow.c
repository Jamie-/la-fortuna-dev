#include <util/delay.h>
//#include "lcd/lcd.h"
#include "color.h"
#include "printf.h"

void init() {
	// Set up LCD
	init_lcd();
}

void main() {

	init();

	int i;
	for (;;) {
		for (i = 0; i <= 255; i++) {
			fill_background(hsv2hex((hsv) {i/255.0, 1, 1}));
			_delay_ms(10);
			
			//display_move(0, 20);
			//printf("%s %d   \n", "Hue:", i);
		}
	}

}
