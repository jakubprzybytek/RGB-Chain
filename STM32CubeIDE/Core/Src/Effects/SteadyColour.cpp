#include "Effects\SteadyColour.hpp"

#define MAX_VALUE 24

void SteadyColour::loop() {
	while (1) {
		for (uint8_t i = 0; i < MAX_VALUE; i++) {
			ws2812.set(0, i, 0, 0);
			if (!tick()) {
				return;
			}
		}
		for (uint8_t i = 0; i < MAX_VALUE; i++) {
			ws2812.set(0, MAX_VALUE - i - 1, 0, 0);
			if (!tick()) {
				return;
			}
		}

		for (uint8_t i = 0; i < MAX_VALUE; i++) {
			ws2812.set(0, i, i, 0);
			if (!tick()) {
				return;
			}
		}
		for (uint8_t i = 0; i < MAX_VALUE; i++) {
			ws2812.set(0, MAX_VALUE - i - 1, MAX_VALUE - i - 1, 0);
			if (!tick()) {
				return;
			}
		}

		for (uint8_t i = 0; i < MAX_VALUE; i++) {
			ws2812.set(0, 0, i, 0);
			if (!tick()) {
				return;
			}
		}
		for (uint8_t i = 0; i < MAX_VALUE; i++) {
			ws2812.set(0, 0, MAX_VALUE - i - 1, 0);
			if (!tick()) {
				return;
			}
		}

		for (uint8_t i = 0; i < MAX_VALUE; i++) {
			ws2812.set(0, 0, i, i);
			if (!tick()) {
				return;
			}
		}
		for (uint8_t i = 0; i < MAX_VALUE; i++) {
			ws2812.set(0, 0, MAX_VALUE - i - 1, MAX_VALUE - i - 1);
			if (!tick()) {
				return;
			}
		}

		for (uint8_t i = 0; i < MAX_VALUE; i++) {
			ws2812.set(0, 0, 0, i);
			if (!tick()) {
				return;
			}
		}
		for (uint8_t i = 0; i < MAX_VALUE; i++) {
			ws2812.set(0, 0, 0, MAX_VALUE - i - 1);
			if (!tick()) {
				return;
			}
		}

		for (uint8_t i = 0; i < MAX_VALUE; i++) {
			ws2812.set(0, i, 0, i);
			if (!tick()) {
				return;
			}
		}
		for (uint8_t i = 0; i < MAX_VALUE; i++) {
			ws2812.set(0, MAX_VALUE - i - 1, 0, MAX_VALUE - i - 1);
			if (!tick()) {
				return;
			}
		}
	}
}
