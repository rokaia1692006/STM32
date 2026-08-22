#include "adc.h"
#include "BIT_MATH.h"

void ADC_init()
{
    // Enable RCC clock for GPIO Pin

    // Enable RCC clock for ADC pin

    // Configure the GPIO_A0 as Analog pin

    // Setting the ADC to do one conversion (L[20 : 23]) (4 bits to zero)
    CLEAR_BIT(ADC1_SQR1,20); 
    CLEAR_BIT(ADC1_SQR1,21); 
    CLEAR_BIT(ADC1_SQR1,22); 
    CLEAR_BIT(ADC1_SQR1,23); // 00000000000000000000 00111100000000000000 11000011111111111111




}