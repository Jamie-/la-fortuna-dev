#include <avr/io.h>
#include <avr/interrupt.h>
#include "rotary.h"

volatile int8_t delta;

void init_rot() {
  DDRE &= ~ROTA & ~ROTB; /* Set ROTA and ROTB as inputs */
  PORTE |= ROTA | ROTB; /* Set pull up for ROTA & ROTB */

  /* Setup rotary encoder interrupts */
  EICRB |= _BV(ISC40) | _BV(ISC50); /* Set interrupt for change of pin state */
  EIMSK |= _BV(INT4) | _BV(INT5);  /* Enable interrupts */
}

int8_t rot_delta() {
  int8_t val;

  cli();
  val = delta;
  delta &= 1;
  sei();

  return -(val >> 1);
}

ISR(INT4_vect) {
    static int8_t last;
    int8_t new, diff;
    uint8_t wheel;

    wheel = PINE;
    new = 0;

    /* Convert gray to binary */
    if (wheel & ROTA) new = 3;
    if (wheel & ROTB) new ^= 1;

    diff = last - new; /* Calculate delta */

    if (diff & 1) {
      last = new;
      delta += (diff & 2) - 1;
    }
}

ISR(INT5_vect, ISR_ALIASOF(INT4_vect));