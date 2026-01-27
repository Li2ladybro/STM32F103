#include "stm32f10x.h"                  // Device header

void Serial_Init()
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1|RCC_APB2Periph_GPIOA,ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_9;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	
	USART_InitTypeDef USART_InitStructure;
	USART_InitStructure.USART_BaudRate=9600;					// 波特率
	USART_InitStructure.USART_HardwareFlowControl=USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode=USART_Mode_Tx;  				// 发送引脚
	USART_InitStructure.USART_Parity=USART_Parity_No;  			// 无校验
	USART_InitStructure.USART_StopBits=USART_StopBits_1;		// 一位停止位
	USART_InitStructure.USART_WordLength=USART_WordLength_8b; 	// 8位字长
	
	USART_Init(USART1,&USART_InitStructure);
	// 使能串口一
	USART_Cmd(USART1,ENABLE);
}

void Serial_SendByte(uint8_t Byte)
{
	USART_SendData(USART1,Byte);
	// 等待
	while( USART_GetFlagStatus(USART1,USART_FLAG_TXE)==RESET );
}
