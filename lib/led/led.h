/*  Author: Steve Gunn
 * Licence: This work is licensed under the Creative Commons Attribution License.
 *           View this license at http://creativecommons.org/about/licenses/
 */
 
#include <stdint.h>

#define LED		PB7

void init_led();
void led_on();
void led_off();
void led_brightness(uint8_t i);

