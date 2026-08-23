#include "../MCAL/RCC/RCC.h"
#include "../LIB/BIT_MATH.h"
#include "../LIB/gpioDriver.c"
#include "../LIB/gpioDriver.h"
#include "../LIB/adc.c"
#include "../LIB/adc.h"

void setup(){
    RCC_Init();
    SETUP_GPIO();
    ADC_init();

}

void loop(){
    unsigned int analogRead = ADC_read();
    unsigned int Voltage = ADC_convert(analogRead);

    LED1_STATE(true);
    LED2_STATE(false);
    LED3_STATE(true);
}

int main(void)
{
    setup();  //as you know the setups is called only once


    while (1)
    {
        loop();   //loop is called continously so it's in the while(1)
    }
}