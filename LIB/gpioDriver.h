#ifndef GPIO_DRIVER_H
#define GPIO_DRIVER_H
#include <stdbool.h>
// define all ports 
// offset of modr 
// base + offset
#define MODEROFFSET 0x00
#define GPIO_BASE_A 0x40020000
#define MODER_GPIOA *((volatile unsigned int*)(MODEROFFSET + GPIO_BASE_A))
#define GPIO_OTYPER_OFFSET 0x04
#define GPIO_OTYPER *((volatile unsigned int*)(GPIO_OTYPER_OFFSET + GPIO_BASE_A))
#define OUTSPEED_REG_OFFSET 0x08
#define OUTSPEED_REG *((volatile unsigned int*)(OUTSPEED_REG_OFFSET + GPIO_BASE_A))
#define PULLDOWN_REG_OFFSET  0x0C
#define PULLDOWN_REG *((volatile unsigned int*)(PULLDOWN_REG_OFFSET + GPIO_BASE_A))
#define OUTPUT_DATA_REG_OFFSET 0x14
#define OUTPUT_DATA_REG *((volatile unsigned int*)(OUTPUT_DATA_REG_OFFSET + GPIO_BASE_A))

void LED1_STATE(bool state);
void LED2_STATE(bool state);
void LED3_STATE(bool state);
void SETUP_GPIO();
#endif 