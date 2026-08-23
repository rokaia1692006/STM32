#ifndef ADC_H
#define ADC_H

// Including a library that gives us a data type that can store 32-bit integer
#include <stdint.h>

// Base address of ADC1
#define ADC1_BASE 0x40012000

// Offset addresses
#define ADC_SR_OFFSET 0x00
#define ADC_CR1_OFFSET 0x04
#define ADC_CR2_OFFSET 0x08
#define ADC_SMPR2_OFFSET 0x10
#define ADC_SQR1_OFFSET 0x2C
#define ADC_SQR3_OFFSET 0x34
#define ADC_DR_OFFSET 0x4C

// Target Addresses (Base Address + Offset address) ** Storing in 32-bit unsigned integer
#define ADC1_SR  (*(volatile uint32_t *)(ADC1_BASE + ADC_SR_OFFSET))
#define ADC1_CR1  (*(volatile uint32_t *)(ADC1_BASE + ADC_CR1_OFFSET))
#define ADC1_CR2  (*(volatile uint32_t *)(ADC1_BASE + ADC_CR2_OFFSET))
#define ADC1_SMPR2  (*(volatile uint32_t *)(ADC1_BASE + ADC_SMPR2_OFFSET))
#define ADC1_SQR1  (*(volatile uint32_t *)(ADC1_BASE + ADC_SQR1_OFFSET))
#define ADC1_SQR3  (*(volatile uint32_t *)(ADC1_BASE + ADC_SQR3_OFFSET))
#define ADC1_DR  (*(volatile uint32_t *)(ADC1_BASE + ADC_DR_OFFSET))

// defining the bits of the registers
#define ADON_BIT 0
#define SWSTART_BIT 30
#define EOC_BIT 1


void ADC_init();
unsigned int ADC_read();
float ADC_convert(unsigned int AnalogReading);

#endif