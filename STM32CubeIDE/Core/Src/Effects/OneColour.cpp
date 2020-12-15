#include "Effects\OneColour.hpp"

#include "Colours.hpp"

void OneColour::loop() {
	while (1) {
		RgbColor colour = RgbColor::fromHsv(encoder.getPosition() << 3, 255, 128);
		for (uint8_t i = 0; i < ws2812.getNumberOfDiodes(); i++) {
			ws2812.set(i, colour.r, colour.g, colour.b);
		}
		if (!tick()) {
			return;
		}
	}
}
