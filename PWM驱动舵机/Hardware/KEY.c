#include	"stm32f10x.h"                  // Device header
#include	"Delay.h"

/**
  * @brief   初始化按键：开启接在引脚上的时钟
  *					     配置PB0|PB10：上拉输入模式 
  *						 并初始化PB0|PB10
  * @param   None
  * @retval  None
  */
void KEY_Init()
{
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_0|GPIO_Pin_1;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOB,&GPIO_InitStructure);
	
}

/**
  * @brief   读取按键		
  *		     PB0按下返回1，PB10按下返回10，
  * @param   None
  * @retval  返回键值
  */
uint8_t Key_GetNum()
{
	uint8_t KeyNum=0;
	if (GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_0)==0)
	{
		Delay_ms(20); 
		while(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_0)==0)
		{
			Delay_ms(20); 
			KeyNum=0;
		}
	}
	
	if (GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_1)==0)
	{
		Delay_ms(20); 
		while(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_1)==0)
		{
			Delay_ms(20); 
			KeyNum=1;
		}
	}
	
	return KeyNum;
	
}
