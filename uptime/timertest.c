/* COMP2215 15/16: Task 02---SKELETON */

#include <avr/io.h>
#include <avr/interrupt.h>
#include "printf.h"

volatile unsigned long upmillis = 0UL;
volatile unsigned long upseconds = 0UL;

void init(void) {
    /* 8MHz clock, no prescaling (DS, p. 48) */
    CLKPR = (1 << CLKPCE);
    CLKPR = 0;

    TCCR0A = _BV(WGM01);  /* CTC Mode */
    TCCR0B = _BV(CS01) | _BV(CS00); /* Prescaler: F_CPU / 64 */
    OCR0A = (uint8_t)(F_CPU / (64.0 * 1000) - 1); /* 1 ms */
    TIMSK0 |= _BV(OCIE0A);  /* Enable timer interrupt */

    init_lcd();
}

void main(void) {
    init();
    sei();

    for (;;) {
    	display_move(0, 0);
    	printf("Uptime: %d", upseconds);
    }

}

ISR( TIMER0_COMPA_vect ) {
	if (upmillis == 1000) {
        upseconds++;
        upmillis = 0;
    } else {
        upmillis++;
    }
}

