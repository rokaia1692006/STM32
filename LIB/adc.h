#ifndef ADC_H
#define ADC_H

// Including a library that gives us a data type that can store 16-bit integer
#include <stdint.h>
#include <RCC.h>

// Base address of ADC1
#define ADC1_BASE 0x40012000

// Offset addresses
#define ADC_SR_OFFSET 0x00
#define ADC_CR2_OFFSET 0x08
#define ADC_SMPR2_OFFSET 0x10
#define ADC_SQR1_OFFSET 0x34
#define ADC_DR_OFFSET 0x4C

// Target Addresses

void ADC_init();
uint16_t ADC_read();

#endif