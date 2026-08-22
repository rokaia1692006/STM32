#ifndef ADC_H
#define ADC_H

// Including a library that gives us a data type that can store 16-bit integer
#include <stdint.h>
#include "RCC.h"

// Base address of ADC1
#define ADC1_BASE 0x40012000

// Offset addresses
#define ADC_SR_OFFSET 0x00
#define ADC_CR2_OFFSET 0x08
#define ADC_SMPR2_OFFSET 0x10
#define ADC_SQR1_OFFSET 0x34
#define ADC_SQR3_OFFSET 0x2C
#define ADC_DR_OFFSET 0x4C

// Target Addresses (Base Address + Offset address) ** Storing in 32-bit integer
#define ADC1_SR  (*(volatile uint32_t *)(ADC1_BASE + ADC_SR_OFFSET))
#define ADC1_CR2  (*(volatile uint32_t *)(ADC1_BASE + ADC_CR2_OFFSET))
#define ADC1_SMPR2  (*(volatile uint32_t *)(ADC1_BASE + ADC_SMPR2_OFFSET))
#define ADC1_SQR1  (*(volatile uint32_t *)(ADC1_BASE + ADC_SQR1_OFFSET))
#define ADC1_SQR3  (*(volatile uint32_t *)(ADC1_BASE + ADC_SQR3_OFFSET))
#define ADC1_DR  (*(volatile uint32_t *)(ADC1_BASE + ADC_DR_OFFSET))




void ADC_init();
uint16_t ADC_read();

#endif