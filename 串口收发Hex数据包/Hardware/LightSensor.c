#include	"stm32f10x.h"                  // Device header

/**
  * @brief   初始化光敏电阻传感器：
  *			 开启接在引脚上的时钟
  *			 配置PB13：上拉输入模式 
  *			 并初始化PB13
  * @param   None
  * @retval  None
  */
void LightSensor_Init()
{
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_13;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOB,&GPIO_InitStructure);
}

/**
  * @brief   读取光敏电阻的数字量
  *			 光线暗返回0，光线明返回1				  
  * @param   None
  * @retval  返回数字量
  */
uint8_t LightSensor_Get()
{
	return GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_13) ;
}
