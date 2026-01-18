#include "stm32f10x.h"  
#include"Delay.h"
#include"LED.h"
#include"KEY.h"

uint8_t KeyNum=0;
 
int  main()
{
	LED_Init();
	KEY_Init();
	
	while(1)
	{
		KeyNum=Key_GetNum();
		
		if (KeyNum==1)
		{
			LED0_Turn();
		}
		
		
		if (KeyNum==10)
		{
			LED2_Turn();
		}
		
	}
}
