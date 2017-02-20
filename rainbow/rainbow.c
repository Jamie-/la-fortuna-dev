#include <util/delay.h>
#include "lcd/lcd.h"
#include "color/color.h"

void init() {
	init_lcd(); // Set up LCD
}

void main() {

	init();

	int i;
	for (;;) {
		for (i = 0; i <= 255; i++) {
			fill_background(hsv2hex((hsv) {i/255.0, 1, 1}));
			_delay_ms(10);
		}
	}

}
