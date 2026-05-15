#include "stm32f4xx_hal.h"
#include <string.h>

UART_HandleTypeDef huart2;

void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART2_UART_Init(void);

int main(void)
{
    HAL_Init();

    SystemClock_Config();

    MX_GPIO_Init();
    MX_USART2_UART_Init();

    char tx_msg[] = "USART Communication Started\r\n";
    uint8_t rx_data;

    // Transmit starting message
    HAL_UART_Transmit(&huart2,
                      (uint8_t*)tx_msg,
                      strlen(tx_msg),
                      HAL_MAX_DELAY);

    while (1)
    {
        // Receive one byte
        HAL_UART_Receive(&huart2,
                         &rx_data,
                         1,
                         HAL_MAX_DELAY);

        // Transmit received byte back
        HAL_UART_Transmit(&huart2,
                          &rx_data,
                          1,
                          HAL_MAX_DELAY);
    }
}

/* USART2 Initialization Function */
static void MX_USART2_UART_Init(void)
{
    huart2.Instance = USART2;

    huart2.Init.BaudRate = 9600;
    huart2.Init.WordLength = UART_WORDLENGTH_8B;
    huart2.Init.StopBits = UART_STOPBITS_1;
    huart2.Init.Parity = UART_PARITY_NONE;
    huart2.Init.Mode = UART_MODE_TX_RX;
    huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
    huart2.Init.OverSampling = UART_OVERSAMPLING_16;

    if (HAL_UART_Init(&huart2) != HAL_OK)
    {
        while (1);
    }
}

/* GPIO Initialization */
static void MX_GPIO_Init(void)
{
    __HAL_RCC_GPIOA_CLK_ENABLE();
}

/* System Clock Configuration */
void SystemClock_Config(void)
{
    // Default system clock configuration
}
