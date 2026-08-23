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

    // Select Channel 0 (ADC_IN0) to make it first conversion (SQ1)
    CLEAR_BIT(ADC1_SQR3, 0);
    CLEAR_BIT(ADC1_SQR3, 1);
    CLEAR_BIT(ADC1_SQR3, 2);
    CLEAR_BIT(ADC1_SQR3, 3);
    CLEAR_BIT(ADC1_SQR3, 4);

    // Select Sampling time for Channel 0 (SMP0)
    CLEAR_BIT(ADC1_SMPR2, 0);
    CLEAR_BIT(ADC1_SMPR2, 1);
    SET_BIT(ADC1_SMPR2, 2);        // 84 cycles (could be changed depending on accuracy of reading and impedance)

    // Enable the ADC by setting ADON
    SET_BIT(ADC1_CR2, 0);
}