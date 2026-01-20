#include "stm32f10x.h"

/**
  * @brief   定时器初始化
  *			 开启内部定时器外设的时钟
  *			 设置定时器使用内部时钟
  * 		 配置定时器工作模式：
  *			 TIM_CounterMode：向上计数
  *			 TIM_Period（满载值）：10000
  *			 TIM_Prescaler（分频系数）：7200
  *			 TIM_RepetitionCounter（起始值）：0
  *			 并设置定时器配置模式
  * 		 打开定时器中断使能
  *			 配置NVIC
  *			 开启定时器
  * @param   None
  * @retval  None
  */
void Timer_Init()
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);
	
	TIM_InternalClockConfig(TIM2);
	
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	TIM_TimeBaseInitStructure.TIM_ClockDivision=TIM_CKD_DIV1;
	TIM_TimeBaseInitStructure.TIM_CounterMode=TIM_CounterMode_Up;
	TIM_TimeBaseInitStructure.TIM_Period=10000-1;
	TIM_TimeBaseInitStructure.TIM_Prescaler=7200-1;
	TIM_TimeBaseInitStructure.TIM_RepetitionCounter=0;
	
	TIM_TimeBaseInit(TIM2,&TIM_TimeBaseInitStructure);
	
	TIM_ClearFlag(TIM2,TIM_FLAG_Update);
	TIM_ITConfig(TIM2,TIM_IT_Update,ENABLE);
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel=TIM2_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=2;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=1;
	
	NVIC_Init(&NVIC_InitStructure);
	
	TIM_Cmd(TIM2,ENABLE);
}


/*void TIM2_IRQHandler()
{
	if(TIM_GetITStatus(TIM2,TIM_IT_Update)==SET)
	{TIM_ClearITPendingBit(TIM2,TIM_IT_Update);
Num++;
	}
}*/


	
	
	
	
	
	
	
	
	
	
	