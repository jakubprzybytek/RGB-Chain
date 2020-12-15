#include "Effects\SteadyColour.hpp"

#include "Colours.hpp"

#define MIN_VALUE 40
#define MAX_VALUE 128

uint8_t SteadyColour::delays[] = { 1, 2, 4, 8, 16, 32, 64, 128 };

bool SteadyColour::sendColour(uint8_t h, uint8_t s, uint8_t v) {
	delayIndex = encoder.getPosition() % sizeof(delays);
	tickDelay = delays[delayIndex];

	RgbColor colour = RgbColor::fromHsv(h, s, v);
	for (uint8_t d = 0; d < ws2812.getNumberOfDiodes(); d++) {
		ws2812.set(d, colour.r, colour.g, colour.b);
	}

	return tick();
}

void SteadyColour::loop() {
	encoder.setPosition(delayIndex);

	while (1) {
		uint8_t h = 0;
		for (uint16_t colour = 0; colour < 6; colour++) {
			for (uint8_t v = MIN_VALUE; v <= MAX_VALUE; v++) {
				if (!sendColour(h, 255, v)) {
					return;
				}
			}
			for (uint8_t v = MAX_VALUE; v > MIN_VALUE; v--) {
				if (!sendColour(h, 255, v)) {
					return;
				}
			}
			h += 255 / 6;
		}
		for (uint8_t v = MIN_VALUE; v <= MAX_VALUE; v++) {
			if (!sendColour(0, 0, v)) {
				return;
			}
		}
		for (uint8_t v = MAX_VALUE; v > MIN_VALUE; v--) {
			if (!sendColour(0, 0, v)) {
				return;
			}
		}
	}
}
