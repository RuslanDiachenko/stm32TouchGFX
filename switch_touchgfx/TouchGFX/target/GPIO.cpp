
#include <touchgfx/hal/GPIO.hpp>

/* USER CODE BEGIN user includes */
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_gpio.h"
/* USER CODE END user includes */

#define RENDER_TIME_PIN_PORT GPIOA
#define RENDER_TIME_PIN_PIN GPIO_PIN_9

using namespace touchgfx;

void GPIO::init()
{
    GPIO_InitTypeDef pinInit;
    pinInit.Pin = RENDER_TIME_PIN_PIN;
    pinInit.Mode = GPIO_MODE_OUTPUT_PP;
    pinInit.Pull = GPIO_NOPULL;
    pinInit.Speed = GPIO_SPEED_FREQ_HIGH;

    HAL_GPIO_Init(RENDER_TIME_PIN_PORT, &pinInit);
}

void GPIO::set(GPIO_ID id)
{
    if (id == RENDER_TIME)
    {
        HAL_GPIO_WritePin(RENDER_TIME_PIN_PORT, RENDER_TIME_PIN_PIN, GPIO_PIN_SET);
    }
}

void GPIO::clear(GPIO_ID id)
{
    if (id == RENDER_TIME)
    {
        HAL_GPIO_WritePin(RENDER_TIME_PIN_PORT, RENDER_TIME_PIN_PIN, GPIO_PIN_RESET);
    }
}

void GPIO::toggle(GPIO_ID id)
{
    if (id == RENDER_TIME)
    {
        HAL_GPIO_TogglePin(RENDER_TIME_PIN_PORT, RENDER_TIME_PIN_PIN);
    }
}

bool GPIO::get(GPIO_ID id)
{
  return true;
}
