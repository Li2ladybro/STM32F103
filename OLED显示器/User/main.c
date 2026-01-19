#include "stm32f10x.h"  
#include"Delay.h"
#include"OLED.h"

 
int  main()
{
	 OLED_Init( );
		// OLED_ShowChar(1,1 ,'A');
	OLED_ShowString(1,1,"Hello STM32F103!");
	OLED_ShowNum(2,1,123,5);
	OLED_ShowSignedNum(2,7,-12345,5);
	OLED_ShowHexNum(3,1,0x12345,5);
	OLED_ShowBinNum(4,1,0x1111,16);
	OLED_Clear();
	while(1)
	{
 
	}
}
