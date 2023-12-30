#include "led.h"

uint8_t led_init(LED_t * led){
    switch(led->gpio){
        default:
            return 0x01; break;
            
        case GPIO_RA0: 
            TRISAbits.TRISA0 = 0;
            PORTAbits.RA0 = 0;
            LATAbits.LATA0 = 0;
            ANSELAbits.ANSA0 = 0;
            break;
        
        case GPIO_RA1: 
            TRISAbits.TRISA1 = 0;
            PORTAbits.RA1 = 0;
            LATAbits.LATA1 = 0;
            ANSELAbits.ANSA0 = 0;
            break;
        
        case GPIO_RA2: 
            TRISAbits.TRISA2 = 0;
            PORTAbits.RA2 = 0;
            LATAbits.LATA2 = 0;
            ANSELAbits.ANSA0 = 0;
            break;
        
    }
    led->value = led->initial_value;
    return EXIT_SUCCESS;
}

void led_on(LED_t * led){
    led->value = led->active_dir;
}

void led_off(LED_t * led){
    led->value = !led->active_dir;
}

void led_toggle(LED_t * led){
    led->value = !led->value;
}

void led_deinit(LED_t * led){
    
}