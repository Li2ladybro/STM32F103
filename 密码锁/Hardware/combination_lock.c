#include "stm32f10x.h" // Device header
#include "combination_lock.h"
#include "1x4key.h"
#include "delay.h"
#include "oled.h"
#include "led.h"

uint8_t input_buffer[PASSWORD_LENGTH];
uint8_t input_index = 0;
uint8_t password[PASSWORD_LENGTH] = { 1, 2, 3, 4 };  // 默认密码   
uint8_t attempts = 0;

System_State system_state = STATE_IDLE;


void combination_lock_init(void) 
{
//    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB, ENABLE);

//    GPIO_InitTypeDef GPIO_InitStructure;
//    
//    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;
//    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8 | GPIO_Pin_11; // 按键二，三
//    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//    GPIO_Init(GPIOA, &GPIO_InitStructure);
//    
//    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;
//    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_5; // 按键一,四
//    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//    GPIO_Init(GPIOB, &GPIO_InitStructure);
//    
    
    Key1x4_Init();
    // 初始化输入缓冲区 
    for (uint8_t i = 0; i < PASSWORD_LENGTH; i++)
    {
        input_buffer[i] = 0;
    }
    input_index = 0;
    attempts = 0;
    
}

// 显示状态   
void Display_Status()
{
    
        OLED_Clear();
        switch (system_state)
        {
            case STATE_IDLE:
            
                OLED_ShowString(0, 0, "系统初始化完毕", OLED_8X16);
                OLED_ShowString(0, 16, "请输入密码", OLED_8X16);
                OLED_Update();
                break;
           

            case STATE_INPUT:
            {
                OLED_ShowString(0, 16, "请输入密码", OLED_8X16);
                // 显示已输入的密码（用*表示）
                for (uint8_t i = 0; i < input_index; i++)
                {
                    OLED_ShowChar(16 + i * 16, 32, '*', OLED_8X16);
                   
                }
                OLED_Update();
                break;
            }

            case STATE_UNLOCKED:
            {
                OLED_ShowString(0, 16, "密码正确!", OLED_8X16);
               // OLED_ShowString(0, 16, "欢迎使用", OLED_8X16);
                led_on_pc13();
                OLED_Update();
                break;
            }

            case STATE_CHECKING:
            {
               // OLED_ShowString(0, 0, "密码错误!", OLED_8X16);
                OLED_ShowString(0, 16,  "正在效验密码...", OLED_8X16);
               // OLED_ShowString(0, 32, "重新输入", OLED_8X16);
               //  led_off_pc13();
                OLED_Update();
                break;
            }
            case STATE_LOCKED:
            {
                OLED_ShowString(0, 0, "密码错误!", OLED_8X16);
                OLED_ShowString(0, 16, "请重新输入", OLED_8X16);
                OLED_Printf(0, 32, OLED_8X16,"还有%d次尝试次数",MAX_ATTEMPTS-attempts);
                led_off_pc13();
                OLED_Update();
                break;
             }

            case STATE_ERROR:
            {
                OLED_ShowString(0, 0, "密码错误!", OLED_8X16);
                OLED_ShowString(0, 16, "系统已锁定", OLED_8X16);
                OLED_ShowString(0, 32, "5秒后解除", OLED_8X16);
                OLED_Update();
                break;
            }
        }
      //  last_state = system_state;
    }


//uint8_t get_code(void) 
//{
//    uint8_t KeyNum = 0;
//
//    if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_12) == 1)
//    {
//        Delay_ms(20);
//        while (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_12) == 1)
//        {
//            Delay_ms(20);
//            KeyNum = 1;
//        }
//    }
//
//    else if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_5) == 1) {
//        Delay_ms(20);
//        while (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_5) == 1) {
//            Delay_ms(20);
//            KeyNum = 4;
//        }
//    }
//
//    else if (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_8) == 1) 
//    {
//        Delay_ms(20);
//        while (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_8) == 1) 
//        {
//            Delay_ms(20);
//            KeyNum = 2;
//        }
//    }
//
//    else if (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_11) == 1) 
//    {
//        Delay_ms(20);
//        while (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_11) == 1) 
//        {
//            Delay_ms(20);
//            KeyNum = 3;
//        }
//    }
//    return KeyNum;
//}

// 处理按键输入
void Process_Keypad() 
{
    // uint8_t key_value = get_code(); // 键值
    uint8_t key_value = Key1x4_GetData(); // 键值
    if (key_value) 
    {

        // 处理按键输入
        if (system_state == STATE_IDLE || system_state == STATE_INPUT) 
        {
            if (system_state == STATE_IDLE) 
            {
                system_state = STATE_INPUT;
                input_index = 0;
            }

            // 存储按键值
            if (input_index < PASSWORD_LENGTH)
            {
                input_buffer[input_index] = key_value; // 按键对应数字1-4
                input_index++;
                // 如果输入了4位密码，开始检查
                if (input_index == PASSWORD_LENGTH)
                {
                    OLED_ShowChar(16 + 3 * 16, 32, '*', OLED_8X16);
                    OLED_Update();
                    system_state = STATE_CHECKING;
                    Display_Status();
                    Delay_ms(3000);
                    Check_Password();
                }
            }
        }
        else if (system_state == STATE_UNLOCKED || system_state == STATE_LOCKED)
        {
            // 按任意键返回空闲状态
            Reset_System();
        }
    }
    else if (system_state == STATE_ERROR) // KEY4长按
    {
        // 重置密码锁
        Delay_ms(5000);
        Reset_System();
    }
}


// 检查密码
void Check_Password()
{
    uint8_t correct = 1;

    // 比较密码
    for (uint8_t i = 0; i < PASSWORD_LENGTH; i++)
    {
        if (input_buffer[i] != password[i])
        {
            correct = 0;
            break;
        }
    }

    if (correct) 
    {
        // 密码正确
        system_state = STATE_UNLOCKED;
        attempts = 0;
    }
    else 
    {
        // 密码错误
        attempts++;
        if (attempts >= MAX_ATTEMPTS) 
        {
            system_state = STATE_ERROR;
        }
        else 
        {
            system_state = STATE_LOCKED;
            Display_Status();
            // 3秒后返回输入状态
            Delay_ms(3000);
            system_state = STATE_INPUT;
            input_index = 0;
        }
    }
}

// 重置系统
void Reset_System(void)
{
    system_state = STATE_IDLE;
    input_index = 0;
    // 清除输入缓冲区
    for (int i = 0; i < PASSWORD_LENGTH; i++) {
        input_buffer[i] = 0;
    }
}
