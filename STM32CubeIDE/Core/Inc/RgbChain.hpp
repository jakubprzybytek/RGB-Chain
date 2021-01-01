#ifndef INC_RGBCHAIN_H_
#define INC_RGBCHAIN_H_

#ifdef __cplusplus
extern "C" {
#endif

#define LED_Blink(delay) HAL_GPIO_WritePin(Led_GPIO_Port, Led_Pin, GPIO_PIN_SET); HAL_Delay(delay); HAL_GPIO_WritePin(Led_GPIO_Port, Led_Pin, GPIO_PIN_RESET);

extern void RgbChain_Init();

extern void RgbChain_Loop();

#ifdef __cplusplus
}
#endif

#endif /* INC_RGBCHAIN_H_ */
