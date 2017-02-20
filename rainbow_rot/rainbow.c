#include "lcd/lcd.h"
#include "color/color.h"
#include "rotary/rotary.h"

void init() {
	init_lcd(); /* Setup LCD */
	init_rot(); /* Setup rotary encoder */
}

uint16_t hue2hex(uint8_t hue) {
	return hsv2hex((hsv) {hue/255.0, 1, 1});
}

void main() {

	init();

	int hue = 0;
	for (;;) {
		int d = rot_delta();
		hue = hue + d * 10;
		if (hue < 0) hue = 0;
		if (hue > 255) hue = 255;
		
		fill_background(hue2hex(hue));
	}

}
