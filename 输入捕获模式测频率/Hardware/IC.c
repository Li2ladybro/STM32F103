#include "stm32f10x.h"                  // Device header

/**
* @brief 输入捕获初始化
* @param None
* @retval None
*/
void IC_Init()
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);	   // 开启需要使用捕获引脚上的时钟
	//RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE); 	   // 打开AFIO时钟
	//GPIO_PinRemapConfig(GPIO_PartialRemap1_TIM2,ENABLE);
	//GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable,ENABLE);  // 解除默认端口功能
	
	// GPIO
	GPIO_InitTypeDef GPIO_InitStructure;
 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;			   // 配置引脚模式为：上拉输入模式
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
	// 初始化引脚配置
 	GPIO_Init(GPIOA, &GPIO_InitStructure);
	

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);		   // 开启用到的定时器挂载在总线上的时钟
	
	TIM_InternalClockConfig(TIM3);

	// 时基单元，配置标准频率
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	TIM_TimeBaseInitStructure.TIM_ClockDivision=TIM_CKD_DIV1;
	TIM_TimeBaseInitStructure.TIM_CounterMode=TIM_CounterMode_Up;	  // 向上计数模式
	TIM_TimeBaseInitStructure.TIM_Period=65536-1;  		 			  // ARR
	TIM_TimeBaseInitStructure.TIM_Prescaler=72-1;  		 			  // PSC
	TIM_TimeBaseInitStructure.TIM_RepetitionCounter=0;				  // 配置重装载值
	
	TIM_TimeBaseInit(TIM3,&TIM_TimeBaseInitStructure);				  // 初始化时基单元
	
	// 输入捕获单元一
	TIM_ICInitTypeDef TIM_ICInitStructure;
	TIM_ICInitStructure.TIM_Channel=TIM_Channel_1;   					   // 通道一
	TIM_ICInitStructure.TIM_ICFilter=0xF;  			 					   // 滤波
	TIM_ICInitStructure.TIM_ICPolarity=TIM_ICPolarity_Rising; 			   // 边沿检测模式
	TIM_ICInitStructure.TIM_ICPrescaler=TIM_ICPSC_DIV1;     			   // 咩次触发生效
	TIM_ICInitStructure.TIM_ICSelection=TIM_ICSelection_DirectTI;  		   // 直连通道
	
	TIM_ICInit(TIM3,&TIM_ICInitStructure);
	
	// 触发源选择 
	TIM_SelectInputTrigger(TIM3,TIM_TS_TI1FP1);
	
	// 从模式选择
	TIM_SelectSlaveMode(TIM3,TIM_SlaveMode_Reset);

	// 使能定时器
	TIM_Cmd(TIM3,ENABLE);
}

/**
* @brief 获取捕获信号频率
* @param None
* @retval 频率
*/
uint32_t IC_GetFreq()
{
	return 1000000/(TIM_GetCapture1(TIM3)+1);
}


