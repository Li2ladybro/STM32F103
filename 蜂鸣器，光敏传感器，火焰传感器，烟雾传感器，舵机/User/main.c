#include "stm32f10x.h"  
#include "Delay.h"
#include "Buzzer.h"
#include "flame.h"
#include "mq2.h"
#include "oled.h"
#include "Servo.h"

uint8_t angle_f = 0;

int main()
{
    Buzzer_Init();
    flame_init(); 
    mq_2_init();
    OLED_Init();
    Servo_Init();
    Servo_SetAngle(0);
    uint8_t flame_value = 1, mq_2_value = 1;
    
    while(1)
    {
        if (angle_f)
        {
            angle = 180;
            Servo_SetAngle(angle);
            angle_f = 0;
        }
        else
        {
            angle = 0;
            Servo_SetAngle(angle);
            angle_f = 1;
        }
        
        flame_value = flame_get();
        mq_2_value = mq_2_get();
        OLED_Printf(0, 0, OLED_8X16, "huo_yan:%d", flame_value);
        OLED_Printf(0, 16, OLED_8X16, "yan_wu:%d", mq_2_value);
        OLED_Printf(0, 32, OLED_8X16,"angle:%05.1f",angle);
        OLED_Update();
        while (flame_value == 0 || mq_2_value == 0)
        {
             Buzzer_ON();
            flame_value = flame_get();
            mq_2_value = mq_2_get();
            OLED_Printf(0, 0, OLED_8X16, "huo_yan:%d", flame_value);
            OLED_Printf(0, 16, OLED_8X16, "yan_wu:%d", mq_2_value);
            OLED_Printf(0, 32, OLED_8X16,"angle:%05.1f",angle);
            OLED_Update();
            
           
        }
        if (GPIO_ReadInputDataBit(BUZZER_IO_GPIO_PORT,BUZZER_IO_GPIO_PIN)==0)
        {
            Buzzer_OFF();
        }
        Delay_s(3);
    }
}
