#ifndef __FMILE_H
#define __FMILE_H

#define     FLAME_DO_GPIO_CLK                                RCC_APB2Periph_GPIOB
#define     FLAME_DO_GPIO_PORT                               GPIOB
#define     FLAME_DO_GPIO_PIN                                GPIO_Pin_13            

void flame_init(void);
uint8_t flame_get(void);


#endif
