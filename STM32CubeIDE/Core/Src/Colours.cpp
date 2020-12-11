#include "Colours.hpp"

RgbColor RgbColor::fromHsv(uint8_t h, uint8_t s, uint8_t v) {
	RgbColor rgb(0, 0, 0);
	uint8_t region, remainder, p, q, t;

	if (s == 0) {
		RgbColor rgb(v, v, v);
		return rgb;
	}

	region = h / 43;
	remainder = (h - (region * 43)) * 6;

	p = (v * (255 - s)) >> 8;
	q = (v * (255 - ((s * remainder) >> 8))) >> 8;
	t = (v * (255 - ((s * (255 - remainder)) >> 8))) >> 8;

	switch (region) {
	case 0:
		rgb.r = v;
		rgb.g = t;
		rgb.b = p;
		break;
	case 1:
		rgb.r = q;
		rgb.g = v;
		rgb.b = p;
		break;
	case 2:
		rgb.r = p;
		rgb.g = v;
		rgb.b = t;
		break;
	case 3:
		rgb.r = p;
		rgb.g = q;
		rgb.b = v;
		break;
	case 4:
		rgb.r = t;
		rgb.g = p;
		rgb.b = v;
		break;
	default:
		rgb.r = v;
		rgb.g = p;
		rgb.b = q;
		break;
	}

	return rgb;
}

HsvColor HsvColor::fromRgb(uint8_t r, uint8_t g, uint8_t b) {
	HsvColor hsv(0, 0, 0);
	uint8_t rgbMin, rgbMax;

	rgbMin = r < g ? (r < b ? r : b) : (g < b ? g : b);
	rgbMax = r > g ? (r > b ? r : b) : (g > b ? g : b);

	hsv.v = rgbMax;
	if (hsv.v == 0) {
		hsv.h = 0;
		hsv.s = 0;
		return hsv;
	}

	hsv.s = 255 * long(rgbMax - rgbMin) / hsv.v;
	if (hsv.s == 0) {
		hsv.h = 0;
		return hsv;
	}

	if (rgbMax == r)
		hsv.h = 0 + 43 * (g - b) / (rgbMax - rgbMin);
	else if (rgbMax == g)
		hsv.h = 85 + 43 * (b - r) / (rgbMax - rgbMin);
	else
		hsv.h = 171 + 43 * (r - g) / (rgbMax - rgbMin);

	return hsv;
}
