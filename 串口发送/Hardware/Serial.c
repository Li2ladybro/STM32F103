#include <stdio.h> 
#include <stdarg.h>
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

// 发送一字节
void Serial_SendByte(uint8_t Byte)
{
	USART_SendData(USART1,Byte);
	// 等待
	while( USART_GetFlagStatus(USART1,USART_FLAG_TXE)==RESET );
}

// 发送一个数组
void Serial_SendArry(uint8_t* Arry,uint16_t Length)
{
	uint16_t i=0;
	while(i<Length)
		Serial_SendByte(Arry[i++]);
}
	
// 发送字符串
void Serial_SendString(char* s)
{
	uint8_t i=0;
	while(s[i]!='\0')
	Serial_SendByte(s[i++]);
}
	
	
// 乘方
uint32_t Serial_Pow(uint32_t x ,uint32_t y)
{
	uint32_t ret=1;
	while(y--)
		ret*=x;
	return ret;
}

// 发送数字字符串
void Serial_SendNum(uint32_t num,uint32_t length)
{
	uint8_t i=0;
		while(i<length)
			Serial_SendByte(num/Serial_Pow(10,length-(i++)-1)%10+'0');
}

// printf重定向，printf底层就是不断调用fputc
int fputc(int ch,FILE* f)
{
	Serial_SendByte(ch);
	return ch;
}

// 方法三
void Serial_print(char* format,...)
{
	char string[100];
	va_list arg;
va_start(arg,format);
	vsprintf(string ,format ,arg);
	va_end(arg);
	Serial_SendString(string);
	
}
