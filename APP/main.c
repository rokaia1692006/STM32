#include "../MCAL/RCC/RCC.h"
#include "../LIB/BIT_MATH.h"
//#include "../MCAL/GPIO/gpioDriver.c"
#include "../MCAL/GPIO/gpioDriver.h"
//#include "../MCAL/ADC/adc.c"
#include "../MCAL/ADC/adc.h"

void setup(){
    RCC_Init();
    SETUP_GPIO();
    ADC_init();
    
}

void loop(){
    int analogRead = ADC_read();
    if (analogRead < 0)
        return;   // Timeout Error

    float Voltage = ADC_convert(analogRead);

    if (Voltage > 2.2) {
        LED1_STATE(true);
        LED2_STATE(true);
        LED3_STATE(true);
    }
    else if (Voltage > 1.1) {
        LED1_STATE(true);
        LED2_STATE(true);
        LED3_STATE(false);
    }
    else if (Voltage > 0) {
        LED1_STATE(true);
        LED2_STATE(false);
        LED3_STATE(false);
    }
    else {
        LED1_STATE(false);
        LED2_STATE(false);
        LED3_STATE(false);
    }
}

int main(void)
{
    setup();  //as you know the setups is called only once


    while (1)
    {
        loop();   //loop is called continously so it's in the while(1)
    }
}