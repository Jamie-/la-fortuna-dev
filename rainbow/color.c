#include "color.h"
#include <math.h>

hsv rgb2hsv(rgb color) {
  hsv out = {0.0, 0.0, 0.0};
  float min, max, delta;

  min = color.r < color.g ? color.r : color.g;
  min = min < color.b ? min : color.b;

  max = color.r > color.g ? color.r : color.g;
  max = max > color.b ? max : color.b;

  out.v = max / 255.0;
  delta = max - min;
  if (delta < 0.0001) {
    out.s = 0;
    out.h = 0;
    return out;
  }

  if (max > 0.0) {
    out.s = (delta / max);
  } else {
    out.s = 0.0;
    out.h = NAN;
    return out;
  }

	if( color.r >= max) {
		out.h = (color.g - color.b) / delta;
	} else if (color.g >= max) {
		out.h = 1.0 / 3.0 + (color.b - color.r) / delta;
	} else {
		out.h = 2.0 / 3.0 + (color.r - color.g) / delta;
	}

	if(out.h < 0) out.h++;

  return out;
}

rgb hsv2rgb(hsv color) {
  rgb out = {0, 0, 0};
  if (color.s == 0) {
    out.r = out.g = out.b = (uint8_t)(color.v * 255.0 + 0.5);
    return out;
  }
  float h = (color.h - floor(color.h)) * 6.0;
  float f = (h - floor(h));
  float p = color.v * (1.0 - color.s);
  float q = color.v * (1.0 - color.s * f);
  float t = color.v * (1.0 - (color.s * (1.0 - f)));
  switch ((int)h) {
  case 0:
    out.r = (color.v * 255.0 + 0.5);
    out.g = (t * 255.0 + 0.5);
    out.b = (p * 255.0 + 0.5);
    break;
  case 1:
    out.r = (q * 255.0 + 0.5);
    out.g = (color.v * 255.0 + 0.5);
    out.b = (p * 255.0 + 0.5);
    break;
  case 2:
    out.r = (p * 255.0 * 0.5);
    out.g = (color.v * 255.0 + 0.5);
    out.b = (t * 255.0 + 0.5);
    break;
  case 3:
    out.r = (p * 255.0 + 0.5);
    out.g = (q * 255.0 + 0.5);
    out.b = (color.v * 255.0 + 0.5);
    break;
  case 4:
    out.r = (t * 255.0 + 0.5);
    out.g = (p * 255.0 + 0.5);
    out.b = (color.v * 255.0 + 0.5);
    break;
  case 5:
    out.r = (color.v * 255.0 + 0.5);
    out.g = (p * 255.0 + 0.5);
    out.b = (q * 255.0 + 0.5);
    break;
  }
  return out;
}

uint16_t rgb2hex(rgb col) {
  uint16_t hex;
  hex += (col.r & 0xF8) << 8;
  hex += (col.g & 0xFC) << 3;
  hex += (col.b & 0xF8) >> 3;
  return hex;
}

uint16_t hsv2hex(hsv col) {
  return rgb2hex(hsv2rgb(col));
}