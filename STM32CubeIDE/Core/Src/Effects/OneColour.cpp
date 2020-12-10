#include "Effects\OneColour.hpp"

#include "Colours.hpp"

extern TIM_HandleTypeDef htim2;

void OneColour::loop() {
	HsvColor hsv;
	hsv.s = 255;
	hsv.v = 128;
	while (1) {
		hsv.h = htim2.Instance->CNT;
		RgbColor colour = HsvToRgb(hsv);
		for (uint8_t i = 0; i < ws2812.getNumberOfDiodes(); i++) {
			ws2812.set(i, colour.r, colour.g, colour.b);
		}
		if (!tick()) {
			return;
		}
	}
}
