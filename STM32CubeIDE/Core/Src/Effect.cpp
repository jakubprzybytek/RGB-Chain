#include "Effect.hpp"

extern bool changeEffect;

bool Effect::tick() {
	ws2812.flush();
	HAL_Delay(50);

	if (changeEffect) {
		changeEffect = false;
		return false;
	}

	return true;
}
