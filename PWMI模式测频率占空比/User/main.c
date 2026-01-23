#include "stm32f10x.h"  
#include"Delay.h"
#include"OLED.h"
#include"PWM.h"
#include"IC.h"

int  main()
{
	OLED_Init();
	PWM_Init();
	IC_Init();
	
	OLED_ShowString(1,1,"Freq:00000Hz");
	OLED_ShowString(2,1,"Duty:00%");
	
	PWM_SetPrescaler(7200-1);
	PWM_SetCompare(56);
	
	while(1)
	{
		//uint8_t i=0;
		//for(i=2;i<255;i++)
		{
		//	PWM_SetPrescaler(i-1);
			OLED_ShowNum(1,6,IC_GetFreq(),5);
			OLED_ShowNum(2,6,IC_GetDuty(),2);
		}	
	}
}
