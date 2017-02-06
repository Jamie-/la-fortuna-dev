#include "lcd/lcd.h"

void main() {

	// Set up LCD
	init_lcd();

	// Display green rectangle in top left
	rectangle r;
	r.top = 5;
	r.bottom = 15;
	r.left = 5;
	r.right = 15;
	fill_rectangle(r, GREEN);

	// Display red rectangle in bottom right
	rectangle r2;
	r2.top = display.height - 15;
	r2.bottom = display.height - 5;
	r2.left = display.width - 15;
	r2.right = display.width - 5;
	fill_rectangle(r2, RED);
	
	// Display some text at given location
	display_string_xy("Hello world!", 50, 50);
}
