#ifndef __1X4KEY_H
#define	__1X4KEY_H
#include "stm32f10x.h"
#include "delay.h"

/*****************辰哥单片机设计******************
											STM32
 * 文件			:	1×4矩阵键盘h文件                   
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

/***************根据自己需求更改****************/
// 1×4矩阵键盘 GPIO宏定义

#define		KEY1X4_GPIO_CLK								RCC_APB2Periph_GPIOA
#define 	KEY1X4_GPIO_PORT							GPIOA
#define 	KEY1X4_COM_GPIO_PIN						GPIO_Pin_8	
#define 	KEY1_GPIO_PIN									GPIO_Pin_11	
#define 	KEY2_GPIO_PIN									GPIO_Pin_12	
#define 	KEY3_GPIO_PIN									GPIO_Pin_9	
#define 	KEY4_GPIO_PIN									GPIO_Pin_10	
	
/*********************END**********************/

#define KEY1  GPIO_ReadInputDataBit(KEY1X4_GPIO_PORT,KEY1_GPIO_PIN)		//读取按键1
#define KEY2  GPIO_ReadInputDataBit(KEY1X4_GPIO_PORT,KEY2_GPIO_PIN)		//读取按键2
#define KEY3  GPIO_ReadInputDataBit(KEY1X4_GPIO_PORT,KEY3_GPIO_PIN)		//读取按键3 
#define KEY4	GPIO_ReadInputDataBit(KEY1X4_GPIO_PORT,KEY4_GPIO_PIN)		//读取按键4 



#define KEY1_PRES 1	//KEY1按下
#define KEY2_PRES	2	//KEY2按下
#define KEY3_PRES	3	//KEY3按下
#define KEY4_PRES 4	//KEY4按下


void Key1x4_Init(void);
uint8_t Key1x4_GetData(void);

#endif 

