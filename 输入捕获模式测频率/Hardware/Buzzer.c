#include "stm32f10x.h"                  // Device header

/**
  * @brief   蜂鸣器初始化
  *			 开启蜂鸣器接在引脚上的时钟
  * 		 配置蜂鸣器接在引脚上工作模式：PB12推挽输出
  *			 并初始化PB12
  * 		 初始默认设置为（不响）高电平
  * @param   None
  * @retval  None
  */
void Buzzer_Init()
{
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
		
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_12;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOB,&GPIO_InitStructure);
	
	GPIO_SetBits(GPIOA,GPIO_Pin_0|GPIO_Pin_2);
	
}

/**
  * @brief   开启蜂鸣器（低电平触发）
  * @param   None
  * @retval  None
  */
void Buzzer_ON()
{
	
	GPIO_ResetBits(GPIOB,GPIO_Pin_12);	
}

/**
  * @brief   反转蜂鸣器
  * @param   None
  * @retval  None
  */
void Buzzer_Turn()
{
	if (GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_12)==0)
		GPIO_SetBits(GPIOB,GPIO_Pin_12);
	else
		GPIO_ResetBits(GPIOB,GPIO_Pin_12);
}

/**
  * @brief   关闭蜂鸣器
  * @param   None
  * @retval  None
  */
void Buzzer_OFF()
{
	
	GPIO_SetBits(GPIOB,GPIO_Pin_12);
}
