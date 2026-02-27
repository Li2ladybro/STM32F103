#include "stm32f10x.h"                  // Device header
#include "buzzer.h"

/**
  * @brief   蜂鸣器初始化
  *          开启蜂鸣器接在引脚上的时钟
  *          配置蜂鸣器接在引脚上工作模式：PB12推挽输出
  *          并初始化PB12
  *          初始默认设置为（不响）高电平
  *          工作模式：低电平触发
  *          供电电压：3.3V~5V
  * @param   None
  * @retval  None
  */
void Buzzer_Init()
{
    
    RCC_APB2PeriphClockCmd(BUZZER_IO_GPIO_CLK,ENABLE);
        
    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Pin=BUZZER_IO_GPIO_PIN;
    GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
    
    GPIO_Init(BUZZER_IO_GPIO_PORT,&GPIO_InitStructure);
    
    GPIO_SetBits(BUZZER_IO_GPIO_PORT,BUZZER_IO_GPIO_PIN);
    
}

/**
  * @brief   开启蜂鸣器（低电平触发）
  * @param   None
  * @retval  None
  */
void Buzzer_ON()
{
    
    GPIO_ResetBits(BUZZER_IO_GPIO_PORT,BUZZER_IO_GPIO_PIN);    
}

/**
  * @brief   反转蜂鸣器
  * @param   None
  * @retval  None
  */
void Buzzer_Turn()
{
    if (GPIO_ReadInputDataBit(BUZZER_IO_GPIO_PORT,BUZZER_IO_GPIO_PIN)==0)
        GPIO_SetBits(BUZZER_IO_GPIO_PORT,BUZZER_IO_GPIO_PIN);
    else
        GPIO_ResetBits(BUZZER_IO_GPIO_PORT,BUZZER_IO_GPIO_PIN);
}

/**
  * @brief   关闭蜂鸣器
  * @param   None
  * @retval  None
  */
void Buzzer_OFF()
{
    
    GPIO_SetBits(BUZZER_IO_GPIO_PORT,BUZZER_IO_GPIO_PIN);
}
