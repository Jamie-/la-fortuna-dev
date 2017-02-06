/*  Author: Steve Gunn
 * Licence: This work is licensed under the Creative Commons Attribution License.
 *           View this license at http://creativecommons.org/about/licenses/
 */
 
#include <avr/io.h>
#include "led.h"

void init_led()
{
	DDRB |= _BV(LED);
	PORTB &= ~_BV(LED);
}

void led_on()
{
	PORTB |= _BV(LED);
}

void led_off()
{
	TCCR0A = 0x00;
	TCCR0B = 0x00;
	PORTB &= ~_BV(LED);
}

void led_brightness(uint8_t i)
{
	/* Configure Timer 0 Fast PWM Mode 3 */
	TCCR0A = _BV(COM0A1) | _BV(WGM01) | _BV(WGM00);
	TCCR0B = _BV(CS20);
	OCR0A = i;
}



