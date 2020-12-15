#include "main.h"

#include "RgbChain.hpp"

#include "WS2812Driver.hpp"
#include "Encoder.hpp"
#include "Effects/ColourFollower.hpp"
#include "Effects/SteadyColour.hpp"
#include "Effects/OneColour.hpp"

extern UART_HandleTypeDef huart2;
extern TIM_HandleTypeDef htim2;

WS2812Driver ws2812(huart2);
Encoder encoder(htim2);

ColourFollower colourFollower(ws2812, encoder);
SteadyColour steadyColour(ws2812, encoder);
OneColour oneColour(ws2812, encoder);

#define NUMBER_OF_EFFECTS 3
Effect *effects[NUMBER_OF_EFFECTS] = { &colourFollower, &steadyColour, &oneColour };
uint8_t effectIndex = 0;

void RgbChain_Init() {
	HAL_GPIO_WritePin(Led_GPIO_Port, Led_Pin, GPIO_PIN_SET);
	HAL_TIM_Encoder_Start(&htim2, TIM_CHANNEL_ALL);
}

void RgbChain_Loop() {
	while (1) {
		effects[effectIndex]->loop();
		effectIndex = effectIndex < NUMBER_OF_EFFECTS - 1 ? effectIndex + 1 : 0;
	}
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
	HAL_GPIO_TogglePin(Led_GPIO_Port, Led_Pin);
	encoder.setPressed();
}
