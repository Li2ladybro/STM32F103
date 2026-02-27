#ifndef __MQ2_H
#define __MQ2_H

#define     MQ2_DO_GPIO_CLK                                RCC_APB2Periph_GPIOB
#define     MQ2_DO_GPIO_PORT                               GPIOB
#define     MQ2_DO_GPIO_PIN                                GPIO_Pin_14

void mq_2_init(void);
uint8_t mq_2_get(void);

#endif
