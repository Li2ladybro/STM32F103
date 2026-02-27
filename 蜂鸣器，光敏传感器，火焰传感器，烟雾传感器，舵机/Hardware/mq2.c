#include "stm32f10x.h"                  // Device header
#include "mq2.h"
/**
  * @brief   初始化烟雾传感器：
  *          开启接在引脚上的时钟
  *          配置PB14：上拉输入模式
  *          并初始化PB14
  *          供电电压：5V
  * @param   None
  * @retval  None
  */
void mq_2_init(void)
{

    RCC_APB2PeriphClockCmd(MQ2_DO_GPIO_CLK, ENABLE);

    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_InitStructure.GPIO_Pin = MQ2_DO_GPIO_PIN;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

    GPIO_Init(MQ2_DO_GPIO_PORT, &GPIO_InitStructure);
}

/**
  * @brief   读取烟雾传感器的数字量
  *          有烟雾返回0，无烟雾返回1
  *          逆、时针旋转电位器，降低了比较器的参考电压（阈值）
  * @param   None
  * @retval  返回数字量
  */
uint8_t mq_2_get(void)
{
    return GPIO_ReadInputDataBit(MQ2_DO_GPIO_PORT, MQ2_DO_GPIO_PIN);
}
