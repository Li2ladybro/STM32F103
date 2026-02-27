#ifndef __BUEEZR_H
#define __BUEEZR_H

#define    BUZZER_IO_GPIO_CLK                                RCC_APB2Periph_GPIOB
#define    BUZZER_IO_GPIO_PORT                               GPIOB
#define    BUZZER_IO_GPIO_PIN                                GPIO_Pin_12            

void Buzzer_Init(void);
void Buzzer_ON(void);
void Buzzer_Turn(void);
void Buzzer_OFF(void);

#endif
