#ifndef ADC_H
#define ADC_H

// Including a library that gives us a data type that can store 16-bit integer
#include <stdint.h>

void ADC_init();
uint16_t ADC_read();

#endif