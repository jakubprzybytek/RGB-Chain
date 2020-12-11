#include "Effect.hpp"

bool Effect::tick() {
	ws2812.flush();
	HAL_Delay(tickDelay);

	return !encoder.getPressed();
}
