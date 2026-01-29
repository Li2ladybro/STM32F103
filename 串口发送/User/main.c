#include "stm32f10x.h"  
#include "Delay.h"
#include "OLED.h"
#include "Serial.h"

int main(void)
{//OLED_Init();
	Serial_Init();
	
	//Serial_SendByte('A');
	
	uint8_t MyArry[]={0x42,0x43,0x44,0x45};
	Serial_SendArry(MyArry,4);                        
	
	while(1)
	{}		
}
