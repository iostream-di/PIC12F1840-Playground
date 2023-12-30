/* 
 * File:   pins.h
 * Author: dmart
 *
 * Created on December 25, 2023, 2:45 PM
 */

#ifndef PINS_H
#define	PINS_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "dmware.h"
    
    
typedef enum __attribute__((packed)){
        LOGIC_LOW, LOGIC_HIGH
    }Logic_t;
    
    typedef enum __attribute__((packed)){
        GPIO_SECT_PORT, GPIO_SECT_LAT, GPIO_SECT_ANSEL, GPIO_SECT_TRIS
    }GPIO_Section_t;
    
    typedef enum __attribute__((packed)){
            GPIO_RA0 = 0, GPIO_RA1 = 1, GPIO_RA2 = 2, GPUO_RA3 = 3, GPIO_RA4 = 4, GPIO_RA5 = 5, GPIO_RA6 = 6, GPIO_RA7 = 7,
            GPIO_RB0 = 10, GPIO_RB1 = 11, GPIO_RB2 = 12, GPUO_RB3 = 13, GPIO_RB4 = 14, GPIO_RB5 = 15, GPIO_RB6 = 16, GPIO_RB7 = 17,
            GPIO_RC0 = 20, GPIO_RC1 = 21, GPIO_RC2 = 22, GPUO_RC3 = 23, GPIO_RC4 = 24, GPIO_RC5 = 25, GPIO_RC6 = 26, GPIO_RC7 = 27,
            GPIO_RD0 = 30, GPIO_RD1 = 31, GPIO_RD2 = 32, GPUO_RD3 = 33, GPIO_RD4 = 34, GPIO_RD5 = 35, GPIO_RD6 = 36, GPIO_RD7 = 37,
            GPIO_RE0 = 40, GPIO_RE1 = 41, GPIO_RE2 = 42, GPUO_RE3 = 43, GPIO_RE4 = 44, GPIO_RE5 = 45, GPIO_RE6 = 46, GPIO_RE7 = 47
    }GPIO_t;

    typedef enum __attribute__((packed)){
        GPIO_OUTPUT, GPIO_OUTPUT_PULL_UP, GPIO_OUTPUT_PULL_DOWN, GPIO_INPUT, 
                GPIO_INPUT_PULL_UP, GPIO_INPUT_PULL_DOWN, GPIO_INPUT_HIGH_IMPEDANCE
    }GPIO_Drive_Mode_t;

    
    typedef struct __attribute__((packed)){
        const GPIO_Drive_Mode_t drive_mode;
        const Logic_t active_dir;
        const Logic_t initial_value;
        Logic_t value;
        const GPIO_t gpio;
    }Pin_t;
    
    extern uint8_t pin_init(Pin_t * pin);
    extern void pin_on(Pin_t * pin);
    extern void pin_off(Pin_t * pin);
    extern void pin_write(Pin_t * pin, Logic_t state);
    extern Logic_t pin_read(Pin_t * pin);
    extern void pin_toggle(Pin_t * pin);
    extern void pin_deinit(Pin_t * pin);

#ifdef	__cplusplus
}
#endif

#endif	/* PINS_H */

