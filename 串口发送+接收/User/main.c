#include "stm32f10x.h"  
#include "Delay.h"
#include "OLED.h"
#include "Serial.h"

uint8_t RxData;

int main(void)
{
	OLED_Init();
	Serial_Init();
	OLED_ShowString(1,1,"RxData:");
	
	while(1)
	{
		// 使用查询方法
		if (Serial_GetRxFlag()==1)
		{
			// 接收到数据
			RxData=Serial_GetRxData( );
			// 发送至电脑端
			Serial_SendByte(RxData);
			
			OLED_ShowHexNum(1,8,RxData,2);
		}		
	}
}
