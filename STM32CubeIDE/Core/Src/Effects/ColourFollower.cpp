#include <stdlib.h>

#include "Effects\ColourFollower.hpp"

#include "Colours.hpp"

#define MIN_VALUE 40
#define MAX_VALUE 128

uint8_t ColourFollower::delays[] = { 1, 2, 4, 8, 16, 32, 64, 128 };

bool ColourFollower::sendColour(uint8_t h, uint8_t v) {
	delayIndex = encoder.getPosition() % sizeof(delays);
	tickDelay = delays[delayIndex];

	uint16_t whiteDiodeMaxCount = ws2812.getNumberOfDiodes() * delays[sizeof(delays) - delayIndex - 1] * 2;

	for (uint8_t d = 0; d < ws2812.getNumberOfDiodes(); d++) {

		uint16_t diodeCounter = whiteDiodeMaxCount / 2 + d * delays[sizeof(delays) - delayIndex - 1] * 2;
		uint16_t sRaw = abs(whiteDiodeCounter - diodeCounter) * (delayIndex + 1);
		uint8_t s = sRaw > 255 ? 255 : sRaw;

		RgbColor colour = RgbColor::fromHsv(h, s, v);

		ws2812.set(d, colour.r, colour.g, colour.b);
		h -= 6;
	}

	whiteDiodeCounter = whiteDiodeCounter < whiteDiodeMaxCount * 2 ? whiteDiodeCounter + 1 : 0;

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
