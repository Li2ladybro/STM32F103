#include "stm32f10x.h"                  // Device header
#include"PWM.h"

/**
* @brief 舵机初始化
* @param None
* @retval None
*/
void Servo_Init()
{
	PWM_Init();
}

/**
* @brief 设置舵机角度
* @param None
* @retval None
*/
// 0     500
// 180   2500
void Servo_SetAngle(float angle)
{
	PWM_SetCompare2(angle/180*2000+500);
}
