#include "../MCAL/RCC/RCC.h"
#include "../LIB/BIT_MATH.h"
#include "../LIB/gpioDriver.c"
#include "../LIB/gpioDriver.h"

void setup(){
    RCC_Init();
    SETUP_GPIO();

}

void loop(){
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