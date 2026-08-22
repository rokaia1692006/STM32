#include "gpioDriver.h"
#include "BIT_MATH.h"
#include <stdbool.h>
void SETUP_GPIO(){
    //moder = 2pin
    //first led pin 0
    SET_BIT(MODER_GPIOA,0);
    CLEAR_BIT(MODER_GPIOA,1);
    // second led pin 1
    SET_BIT(MODER_GPIOA,2);
    CLEAR_BIT(MODER_GPIOA,3);
    // third led pin 2
    SET_BIT(MODER_GPIOA,4);
    CLEAR_BIT(MODER_GPIOA,5);
    // output speed
    CLEAR_BIT(OUTSPEED_REG,0);
    CLEAR_BIT(OUTSPEED_REG,1);
    CLEAR_BIT(OUTSPEED_REG,2);
    CLEAR_BIT(OUTSPEED_REG,3);
    CLEAR_BIT(OUTSPEED_REG,4);
    CLEAR_BIT(OUTSPEED_REG,5);
    //push pull type
    CLEAR_BIT(GPIO_OTYPER,0);
    CLEAR_BIT(GPIO_OTYPER,1);
    CLEAR_BIT(GPIO_OTYPER,2);

}
void LED1_STATE(bool state){
    if (state) {
        SET_BIT(OUTPUT_DATA_REG,0);
    }
    else{
        CLEAR_BIT(OUTPUT_DATA_REG,0);
    }
}
void LED2_STATE(bool state){
    if (state) {
        SET_BIT(OUTPUT_DATA_REG,1);
    }
    else{
        CLEAR_BIT(OUTPUT_DATA_REG,1);
    }
}
void LED3_STATE(bool state){
    if (state) {
        SET_BIT(OUTPUT_DATA_REG,2);
    }
    else{
        CLEAR_BIT(OUTPUT_DATA_REG,2);
    }
}