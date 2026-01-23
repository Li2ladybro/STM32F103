#include "stm32f10x.h"                  // Device header

/**
* @brief 输出比较输出PWM波初始化
* @param None
* @retval None
*/
void PWM_Init()
{
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);		// 开启输出PWM波的引脚时钟
	//RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE); 		// 打开AFIO时钟
	//GPIO_PinRemapConfig(GPIO_PartialRemap1_TIM2,ENABLE);		 
	//GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable,ENABLE);	// 解除默认端口功能
	
	GPIO_InitTypeDef GPIO_InitStructure;
 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;			    // 配置引脚模式为：复用推挽输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
	// 初始化引脚配置
 	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	// 开启用到的定时器挂载在总线上的时钟
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);
	
	TIM_InternalClockConfig(TIM2); // 配置 TIM2 内部时钟
	
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	TIM_TimeBaseInitStructure.TIM_ClockDivision=TIM_CKD_DIV1;
	TIM_TimeBaseInitStructure.TIM_CounterMode=TIM_CounterMode_Up;		// 向上计数模式
	TIM_TimeBaseInitStructure.TIM_Period=100-1;  		 				// ARR
	TIM_TimeBaseInitStructure.TIM_Prescaler=720-1;  	 				// PSC
	TIM_TimeBaseInitStructure.TIM_RepetitionCounter=0;					// 配置重装载值
	
	// 初始化时基单元
	TIM_TimeBaseInit(TIM2,&TIM_TimeBaseInitStructure);
	
	TIM_OCInitTypeDef TIM_OCInitStructure;
	TIM_OCStructInit(&TIM_OCInitStructure);
	
	/**
	* PWM模式1：
	* 向上计数：CNT<CCR时，REF置有效电平，CNT≥CCR时，REF置无效电平
	* 向下计数：CNT>CCR时，REF置无效电平，CNT≤CCR时，REF置有效电平
	*/
	// TIM_OCInitStructure.TIM_OCIdleState
	TIM_OCInitStructure.TIM_OCMode=TIM_OCMode_PWM1;
	//TIM_OCInitStructure.TIM_OCNIdleState
	//TIM_OCInitStructure.TIM_OCNPolarity
	TIM_OCInitStructure.TIM_OCPolarity=TIM_OCPolarity_High;
	//TIM_OCInitStructure.TIM_OutputNState
	TIM_OCInitStructure.TIM_OutputState=TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_Pulse=0;				   //CCR
	
	TIM_OC1Init(TIM2,&TIM_OCInitStructure);
	
	TIM_Cmd(TIM2,ENABLE);
	
}

/**
* @brief 设置PWM比较值
* @param None
* @retval None
*/
void PWM_SetCompare(uint16_t Compere)
{
	
	TIM_SetCompare1(TIM2,Compere);
}

/**
* @brief 设置PWM预分频系数
* @param None
* @retval None
*/
void PWM_SetPrescaler(uint16_t prescaler)
{
	TIM_PrescalerConfig(TIM2,prescaler,TIM_PSCReloadMode_Immediate);
}
