#include "Effects\ColourFollower.hpp"

#include "Colours.hpp"

#define MIN_VALUE 40
#define MAX_VALUE 128

uint8_t ColourFollower::delays[] = { 1, 2, 4, 8, 16, 32, 64, 128 };

bool ColourFollower::sendColour(uint8_t h, uint8_t v) {
	delayIndex = encoder.getPosition() % sizeof(delays);
	tickDelay = delays[delayIndex];

	uint8_t whiteDiodeIndex = (whiteDiodeCounter / (sizeof(delays) - delayIndex) / 4) % ws2812.getNumberOfDiodes();

	for (uint8_t d = 0; d < ws2812.getNumberOfDiodes(); d++) {

		uint8_t s;
		if (d == whiteDiodeIndex) {
			s = 0; // white
		} else if (d == (whiteDiodeIndex - 1) % ws2812.getNumberOfDiodes() || d == (whiteDiodeIndex + 1) % ws2812.getNumberOfDiodes()) {
			s = 128; // half white
		} else {
			s = 255; // actual colour
		}

		RgbColor colour = RgbColor::fromHsv(h, s, v);

		ws2812.set(d, colour.r, colour.g, colour.b);
		h -= 6;
	}

	whiteDiodeCounter++;

	return tick();
}

void ColourFollower::loop() {
	encoder.setPosition(delayIndex);

	uint8_t h = 0;
	while (1) {
		if (!sendColour(h, 128)) {
			return;
		}
		h++;
	}
}
