#include "gpioDriver.h"
#include "../../LIB/BIT_MATH.h"
#include <stdbool.h>
void SETUP_GPIO(){
    //moder = 2pin
    //first led pin 1
    SET_BIT(MODER_GPIOA,2);
    CLEAR_BIT(MODER_GPIOA,3);
    // second led pin 2
    SET_BIT(MODER_GPIOA,4);
    CLEAR_BIT(MODER_GPIOA,5);
    // third led pin 3
    SET_BIT(MODER_GPIOA,6);
    CLEAR_BIT(MODER_GPIOA,7);
    // output speed
    CLEAR_BIT(OUTSPEED_REG,2);
    CLEAR_BIT(OUTSPEED_REG,3);
    CLEAR_BIT(OUTSPEED_REG,4);
    CLEAR_BIT(OUTSPEED_REG,5);
    CLEAR_BIT(OUTSPEED_REG,6);
    CLEAR_BIT(OUTSPEED_REG,7);
    //push pull type
    CLEAR_BIT(GPIO_OTYPER,1);
    CLEAR_BIT(GPIO_OTYPER,2);
    CLEAR_BIT(GPIO_OTYPER,3);
    //SET firts pin as analog
    SET_BIT(MODER_GPIOA, 0);
    SET_BIT(MODER_GPIOA, 1);
    //switches w inshallah yeb2o sa7 
    CLEAR_BIT(MODER_GPIOA,8);
    CLEAR_BIT(MODER_GPIOA,9);
    //switch 2 
    CLEAR_BIT(MODER_GPIOA,10);
    CLEAR_BIT(MODER_GPIOA,11);
    //switch 3 
     CLEAR_BIT(MODER_GPIOA,12);
     CLEAR_BIT(MODER_GPIOA,13);
     //pulldown 
      CLEAR_BIT(PULLDOWN_REG,8);
    SET_BIT(PULLDOWN_REG,9);
    //switch 2 
    CLEAR_BIT(PULLDOWN_REG,10);
    SET_BIT(PULLDOWN_REG,11);
    //switch 3 
     CLEAR_BIT(PULLDOWN_REG,12);
     SET_BIT(PULLDOWN_REG,13);

}
void LED1_STATE(bool state){
    if (state) {
        SET_BIT(OUTPUT_DATA_REG,1);
    }
    else{
        CLEAR_BIT(OUTPUT_DATA_REG,1);
    }
}
void LED2_STATE(bool state){
    if (state) {
        SET_BIT(OUTPUT_DATA_REG,2);
    }
    else{
        CLEAR_BIT(OUTPUT_DATA_REG,2);
    }
}
void LED3_STATE(bool state){
    if (state) {
        SET_BIT(OUTPUT_DATA_REG,3);
    }
    else{
        CLEAR_BIT(OUTPUT_DATA_REG,3);
    }
}
bool ReadSwitch1(){
    return GET_BIT(INPUT_DATA_REG,4);
}
bool ReadSwitch2(){
    return GET_BIT(INPUT_DATA_REG,5);
}
bool ReadSwitch3(){
    return GET_BIT(INPUT_DATA_REG,6);
}