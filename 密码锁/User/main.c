#include "stm32f10x.h"
#include "delay.h"
#include "oled.h"
#include "combination_lock.h"
#include "led.h"

int main(void)
{
   
   

    // OLED显示初始化
    LED_Init();
    OLED_Init();
    OLED_Clear();
    
    combination_lock_init();
    //uint8_t value2;
   
    ////  显示欢迎信息
    //OLED_ShowString(0, 0, "Keypad Lock V1.0", OLED_8X16);
    //OLED_ShowString(0, 16, "Press any key", OLED_8X16);
    //OLED_ShowString(0, 32, "to start...", OLED_8X16);
    
    OLED_Update();
    while (1)
    {
        // 显示系统状态
        Display_Status();
   
        // 处理按键输入
        Process_Keypad( );

       

        // 延时防止过于频繁的扫描
        Delay_ms(10);
    }
}

