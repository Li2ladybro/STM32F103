#ifndef __COMBINATION_LOCK_H
#define __COMBINATION_LOCK_H

// 系统状态   
typedef enum {
    STATE_IDLE = 0,      // 空闲状态
    STATE_INPUT,         // 输入状态
    STATE_CHECKING,      // 检查密码
    STATE_UNLOCKED,      // 解锁成功
    STATE_LOCKED,        // 锁定状态
    STATE_ERROR          // 错误状态
} System_State;

// 密码相关   
#define PASSWORD_LENGTH  4   
#define MAX_ATTEMPTS     3     // 最大尝试次数

// uint8_t get_code(void);
void Display_Status(void);
void combination_lock_init(void);
void Process_Keypad(void);
void Check_Password(void);
void Reset_System(void);

#endif
