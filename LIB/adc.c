#include "adc.h"
#include "BIT_MATH.h"

#define V_REF 3.3
#define RES 4096  // 2^12

void ADC_init()
{
    // Enable RCC clock for GPIO Pin (in gpio driver)
    
    
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
    
    // Setting the resolution to 12-bit 
    CLEAR_BIT(ADC1_CR1, 24);
    CLEAR_BIT(ADC1_CR1, 25);

    // Select Sampling time for Channel 0 (SMP0)
    SET_BIT(ADC1_SMPR2, 0);
    SET_BIT(ADC1_SMPR2, 1);
    CLEAR_BIT(ADC1_SMPR2, 2);        // 56 cycles (could be changed depending on accuracy of reading and impedance)

    // Enable the ADC by setting ADON
    SET_BIT(ADC1_CR2, ADON_BIT);
}

// Reading the Analog input
unsigned int ADC_read()
{
    // Start conversion (SWSTART)
    SET_BIT(ADC1_CR2, SWSTART_BIT);

    // Wait for EOC flag (polling)
    int timeout = 100000;
    while (!GET_BIT(ADC1_SR, EOC_BIT))
    {
        // Keep waiting until timeout is reached
        if (timeout == 0)
        {
            return -1;  // Conversion failed (Edge case)
        }
        timeout --;
    }

    // Reading the data register
    unsigned int analogRead = (unsigned int) ADC1_DR;

    return analogRead;
}

float ADC_convert(unsigned int AnalogReading)
{
    return  (float)((AnalogReading * V_REF)/ RES);
}