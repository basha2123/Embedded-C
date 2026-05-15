#include "stm32f4xx_hal.h"

SPI_HandleTypeDef hspi1;

uint8_t data[] = {
    0xAE,
    0xA6,
    0xAF
};

int main(void)
{
    HAL_Init();

    while(1)
    {
        HAL_SPI_Transmit(&hspi1,
                         data,
                         sizeof(data),
                         HAL_MAX_DELAY);

        HAL_Delay(1000);
    }
}
