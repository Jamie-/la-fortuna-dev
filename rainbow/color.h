#include <stdint.h>

typedef struct rgb {
  uint8_t r, g, b;
} rgb;

typedef struct hsv {
  float h, s, v;
} hsv;

hsv rgb2hsv(rgb color);
rgb hsv2rgb(hsv color);
uint16_t rgb2hex(rgb col);
uint16_t hsv2hex(hsv col);