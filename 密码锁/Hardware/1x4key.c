#include "1x4key.h"

/*****************辰哥单片机设计******************
											STM32
 * 文件			:	1×4矩阵键盘c文件                   
 * 版本			: V1.0
 * 日期			: 2024.8.31
 * MCU			:	STM32F103C8T6
 * 接口			:	见代码									
 * IP账号		:	辰哥单片机设计（同BILIBILI|抖音|快手|小红书|CSDN|公众号|视频号等）
 * 作者			:	辰哥 
 * 工作室		: 异方辰电子工作室
 * 讲解视频	:	https://www.bilibili.com/video/BV1qYHPepEbG/?share_source=copy_web
 * 官方网站	:	www.yfcdz.cn

**********************BEGIN***********************/

void Key1x4_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	RCC_APB2PeriphClockCmd (KEY1X4_GPIO_CLK, ENABLE );				// 打开连接 单片机引脚端口时钟
	GPIO_InitStructure.GPIO_Pin = KEY1X4_COM_GPIO_PIN;				// 配置连接 单片机引脚模式
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;					// 设置为推挽输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
    
	GPIO_Init(KEY1X4_GPIO_PORT, &GPIO_InitStructure);					// 初始化 
	GPIO_ResetBits(KEY1X4_GPIO_PORT, KEY1X4_COM_GPIO_PIN);		// 公共引脚输出低电平

	GPIO_InitStructure.GPIO_Pin = KEY1_GPIO_PIN|KEY2_GPIO_PIN|KEY3_GPIO_PIN|KEY4_GPIO_PIN;			// 配置连接 单片机引脚模式
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;							// 设置为上拉输入
	GPIO_Init(KEY1X4_GPIO_PORT, &GPIO_InitStructure);					// 初始化 
	
}

uint8_t Key1x4_GetData()
{
	static uint8_t key_up=1;//按键按松开标志
	if(key_up&&(KEY1==0||KEY2==0||KEY3==0||KEY4==0))
	{
		Delay_ms(10);//去抖动 
		key_up=0;
		if(KEY1==0)return KEY1_PRES;
		else if(KEY2==0)return KEY2_PRES;
		else if(KEY3==0)return KEY3_PRES;
		else if(KEY4==0)return KEY4_PRES;
	}else if(KEY1==1&&KEY2==1&&KEY3==1&&KEY4==1)key_up=1; 	    
 	return 0;// 无按键按下
}
