#include "stm32f10x.h"                  // Device header
#include "flame.h"

/**
  * @brief   初始化火焰传感器：
  *          开启接在引脚上的时钟
  *          配置PB13：上拉输入模式
  *          并初始化PB13
  *          供电电压：3.3V~5V
  * @param   None
  * @retval  None
  */
void flame_init(void)
{

    RCC_APB2PeriphClockCmd(FLAME_DO_GPIO_CLK, ENABLE);

    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_InitStructure.GPIO_Pin = FLAME_DO_GPIO_PIN;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

    GPIO_Init(FLAME_DO_GPIO_PORT, &GPIO_InitStructure);
}

/**
  * @brief   读取火焰传感器的数字量
  *          有光源返回0，无光源返回1
  * @param   None
  * @retval  返回数字量
  */
uint8_t flame_get(void)
{
    return GPIO_ReadInputDataBit(FLAME_DO_GPIO_PORT, FLAME_DO_GPIO_PIN);
}
