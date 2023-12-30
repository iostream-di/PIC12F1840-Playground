#include "main.h"
#include "pins.h"

Pin_t SysLED;
void SysLED_Init(void){
    /* Instantiate and initialize the board LED */
    SysLED = (Pin_t){
        .drive_mode = GPIO_OUTPUT, 
        .gpio = GPIO_RA5, 
        .active_dir = LOGIC_HIGH,
        .initial_value = LOGIC_LOW
    };
    pin_init(&SysLED);
    /* */
}
void SysLED_Toggle(void){
    pin_toggle(&SysLED);
}



void main(void) {
    
    SysLED_Init();
    
    /* Application loop: */
    APPLICATION_LOOP{
        
        SysLED_Toggle();
        __delay_ms(500);
        
    }
    /* */
    return;
}
