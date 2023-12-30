/* 
 * File:   led.h
 * Author: dmart
 *
 * Created on December 25, 2023, 1:55 PM
 */

#ifndef LED_H
#define	LED_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "dmware.h"


    typedef struct __attribute__((packed)){
        GPIO_Drive_Mode_t drive_mode;
        Logic_t active_dir;
        Logic_t initial_value;
        Logic_t value;
        GPIO_t gpio;
    }LED_t;
    
    extern uint8_t led_init(LED_t * led);
    extern void led_on(LED_t * led);
    extern void led_off(LED_t * led);
    extern void pin_write(LED_t * led);
    extern void pin_read(LED_t * led);
    extern void led_toggle(LED_t * led);
    extern void led_deinit(LED_t * led);

#ifdef	__cplusplus
}
#endif

#endif	/* LED_H */

