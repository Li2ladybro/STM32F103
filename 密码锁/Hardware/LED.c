#include "stm32f10x.h"                  // Device header

/**
  * @brief   初始化LED：开启Led接在引脚上的时钟
  *                        配置Led接在引脚上工作模式：PA0|PA2上拉输入 
  *                        并初始化PA0|PA2
  *                        初始默认设置为高电平（关灯）
  * @param   None
  * @retval  None
  */
void LED_Init()
{
    
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
    
    
    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Pin=GPIO_Pin_13;
    GPIO_InitStructure.GPIO_Speed=GPIO_Speed_2MHz;
    
    GPIO_Init(GPIOC,&GPIO_InitStructure);
    
    GPIO_SetBits(GPIOC,GPIO_Pin_13);
    
}

void led_on_pc13(void)
{
    GPIO_ResetBits(GPIOC,GPIO_Pin_13);    
}

void led_off_pc13(void)
{
    GPIO_SetBits(GPIOC,GPIO_Pin_13);    
}
/**
  * @brief   开启Led2，低电平触发                
  * @param   None
  * @retval  None
  */
void LED2_ON()
{
    
    GPIO_ResetBits(GPIOA,GPIO_Pin_2);    
}

/**
  * @brief   反转Led2
  * @param   None
  * @retval  None
  */
void LED2_Turn()
{
    if (GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_2)==0)
        GPIO_SetBits(GPIOA,GPIO_Pin_2);
    else
        GPIO_ResetBits(GPIOA,GPIO_Pin_2);
}

/**
  * @brief   关闭Led2
  * @param   None
  * @retval  None
  */
void LED2_OFF()
{
    
    GPIO_SetBits(GPIOA,GPIO_Pin_2);
}

/**
  * @brief   开启Led0，低电平触发
  * @param   None
  * @retval  None
  */
void LED0_ON()
{
    
    GPIO_ResetBits(GPIOA,GPIO_Pin_0);    
}

/**
  * @brief   反转Led2
  * @param   None
  * @retval  None
  */
void LED0_Turn()
{
    if (GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0)==0)
        GPIO_SetBits(GPIOA,GPIO_Pin_0);
    else
        GPIO_ResetBits(GPIOA,GPIO_Pin_0);
}

/**
  * @brief   关闭Led0
  * @param   None
  * @retval  None
  */
void LED0_OFF()
{
    
    GPIO_SetBits(GPIOA,GPIO_Pin_0);
}
