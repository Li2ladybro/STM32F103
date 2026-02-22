#ifndef __OLED_H
#define __OLED_H

void OLED_SetCursor(uint8_t x,uint8_t y);
void OLED_Updata(void);
void OLED_Init(void);
void OLED_WriteData(uint8_t* Data, uint8_t Count);
void OLED_WriteCommand(uint8_t Comand);
void OLED_ClearArea(uint8_t x,uint8_t y, uint8_t width, uint8_t hight);
void OLED_Clear(void);
void OLED_ShowImage(uint8_t x,uint8_t y,uint8_t width,uint8_t hight,const uint8_t* image);
void OLED_ShowChar(uint8_t x,uint8_t y,char ch,uint8_t FrontSize);
void OLED_ShowString(uint8_t x,uint8_t y,char* str,uint8_t FrontSize);
void OLED_ShowChinese(uint8_t x,uint8_t y,const char* chinese);

void OLED_DrawPoint(uint8_t x, uint8_t y);
uint8_t OLED_GetPoint(uint8_t x, uint8_t y);

void OLED_DrawLine(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2);

#endif
