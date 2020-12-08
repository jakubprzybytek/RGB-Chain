#include "Effects\SteadyColour.hpp"

#define MAX_VALUE 24

void SteadyColour::tick() {
	ws2812.flush();
	HAL_Delay(50);
}

void SteadyColour::loop() {
	while (1) {
		for (uint8_t i = 0; i < MAX_VALUE; i++) {
			ws2812.set(0, i, 0, 0);
			tick();
		}
		for (uint8_t i = 0; i < MAX_VALUE; i++) {
			ws2812.set(0, MAX_VALUE - i - 1, 0, 0);
			tick();
		}

		for (uint8_t i = 0; i < MAX_VALUE; i++) {
			ws2812.set(0, i, i, 0);
			tick();
		}
		for (uint8_t i = 0; i < MAX_VALUE; i++) {
			ws2812.set(0, MAX_VALUE - i - 1, MAX_VALUE - i - 1, 0);
			tick();
		}

		for (uint8_t i = 0; i < MAX_VALUE; i++) {
			ws2812.set(0, 0, i, 0);
			tick();
		}
		for (uint8_t i = 0; i < MAX_VALUE; i++) {
			ws2812.set(0, 0, MAX_VALUE - i - 1, 0);
			tick();
		}

		for (uint8_t i = 0; i < MAX_VALUE; i++) {
			ws2812.set(0, 0, i, i);
			tick();
		}
		for (uint8_t i = 0; i < MAX_VALUE; i++) {
			ws2812.set(0, 0, MAX_VALUE - i - 1, MAX_VALUE - i - 1);
			tick();
		}

		for (uint8_t i = 0; i < MAX_VALUE; i++) {
			ws2812.set(0, 0, 0, i);
			tick();
		}
		for (uint8_t i = 0; i < MAX_VALUE; i++) {
			ws2812.set(0, 0, 0, MAX_VALUE - i - 1);
			tick();
		}

		for (uint8_t i = 0; i < MAX_VALUE; i++) {
			ws2812.set(0, i, 0, i);
			tick();
		}
		for (uint8_t i = 0; i < MAX_VALUE; i++) {
			ws2812.set(0, MAX_VALUE - i - 1, 0, MAX_VALUE - i - 1);
			tick();
		}
	}
}
