#include "Effects\SteadyColour.hpp"

#include "Colours.hpp"

#define MIN_VALUE 40
#define MAX_VALUE 128

bool SteadyColour::sendColour(uint8_t h, uint8_t v) {
	tickDelay = encoder.getPosition();
	RgbColor colour = RgbColor::fromHsv(h, 255, v);
	for (uint8_t d = 0; d < ws2812.getNumberOfDiodes(); d++) {
		ws2812.set(d, colour.r, colour.g, colour.b);
	}
	return tick();
}

void SteadyColour::loop() {
	encoder.setPosition(tickDelay);
	uint8_t h = 0;
	while (1) {
		for (uint8_t v = MIN_VALUE; v <= MAX_VALUE; v++) {
			if (!sendColour(h, v)) {
				return;
			}
		}
		for (uint8_t v = MAX_VALUE; v > MIN_VALUE; v--) {
			if (!sendColour(h, v)) {
				return;
			}
		}
		h += 255 / 6;
	}
}
