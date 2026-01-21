#include "stm32f10x.h"  
#include"Delay.h"
#include"OLED.h"
#include"KEY.h"
#include"Servo.h"

uint8_t KeyNum;
float angle=0;
int  main()
{
	OLED_Init();
	KEY_Init();
	Servo_Init();
	
	Servo_SetAngle(90);

	OLED_ShowString(1,1,"angle");
	while(1)
	{
		KeyNum=Key_GetNum();
			if(KeyNum==1)
			{
				angle+=30;
				if(angle>180)
					angle=0;
			}
			Servo_SetAngle(angle);
			OLED_ShowNum(1,7,angle,3);
	}
}
