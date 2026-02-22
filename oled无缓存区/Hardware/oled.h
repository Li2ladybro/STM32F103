#ifndef __OLED_H
#define __OLED_H

void OLED_SetCursor(uint8_t x,uint8_t Page);
void OLED_Init(void);
void OLED_WriteData(uint8_t Data);
void OLED_WriteCommand(uint8_t Comand);
void OLED_Clear(void);
void OLED_ShowChar(uint8_t x,uint8_t Page,char ch,uint8_t FrontSize);
void OLED_ShowString(uint8_t x,uint8_t Page,char* str,uint8_t FrontSize);
void OLED_ShowImage(uint8_t x,uint8_t page,uint8_t width,uint8_t hight,const uint8_t* image);
void OLED_ShowChinese(uint8_t x,uint8_t Page,const char* chinese);

#endif
