#ifndef __SERIAL_H
#define __SERIAL_H

#include <stdio.h>

extern uint8_t Serial_RxFlag;
extern char Serial_RxPacket[];

void Serial_Init(void);
void Serial_SendByte(uint8_t Byte);
void Serial_SendArry(uint8_t* Arry,uint16_t Length);
void Serial_SendString(char* s);

uint32_t Serial_Pow(uint32_t x ,uint32_t y);
void Serial_SendNum(uint32_t num,uint32_t length);

void Serial_print(char* format,...);

// 判断是否收到数据包
uint8_t Serial_GetRxFlag(void);


#endif
