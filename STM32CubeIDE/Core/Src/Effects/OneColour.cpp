#include "Effects\OneColour.hpp"

#define MAX_VALUE 24

void OneColour::loop() {
	while (1) {
		ws2812.set(0, 0, 5, 0);
		if (!tick()) {
			return;
		}
	}
}
