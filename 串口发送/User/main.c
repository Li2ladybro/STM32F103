#include "stm32f10x.h"  
#include "Delay.h"
#include "OLED.h"
#include "Serial.h"



int  main()
{
	OLED_Init( );
	Serial_Init();
	
	Serial_SendByte('A');
	
	while(1)
	{
		
	}		
}
