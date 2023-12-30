#include "pins.h"

static uint16_t get_pin_addr(GPIO_t gpio){
    if (gpio >= 0 && gpio < 10){
        /* PORTA */
        return 0x00C;
    } else if (gpio >= 0 && gpio < 20){
        /* PORTB */
        return 0x00C;
    } else if (gpio >= 0 && gpio < 30){
        /* PORTC */
        return 0x00C;
    } else if (gpio >= 0 && gpio < 40){
        /* PORTD */
        return 0x00C;
    } else if (gpio >= 0 && gpio < 50){
        /* PORTE */
        return 0x00C;
    } else {
        return 0x00C;
    }
}

static void set_value(GPIO_t gpio, GPIO_Section_t sect, uint8_t val){
    uint8_t * addr = (uint8_t*)get_pin_addr(gpio);
    switch(sect){
        default: break;
        
        case GPIO_SECT_PORT:
            addr += 0u;
            break;
            
        case GPIO_SECT_TRIS:
            addr += 0x080;
            break;
            
        case GPIO_SECT_ANSEL:
            addr += 0x180;
            break;
            
        case GPIO_SECT_LAT:
            addr += 0x100;
            break;
    }
    if (val){
        *addr = *addr | 1u << gpio % 10u;
    } else {
        *addr = *addr ^ 1u << gpio % 10u;
    }
            
}

static uint8_t get_value(GPIO_t * gpio){
    return 0u;
}

uint8_t pin_init(Pin_t * pin){
    if (pin->drive_mode == GPIO_OUTPUT || pin->drive_mode == GPIO_OUTPUT_PULL_UP || pin->drive_mode == GPIO_OUTPUT_PULL_DOWN){
        set_value(pin->gpio, GPIO_SECT_ANSEL, 0u);
        set_value(pin->gpio, GPIO_SECT_PORT, pin->initial_value);
        set_value(pin->gpio, GPIO_SECT_LAT, pin->initial_value);
        set_value(pin->gpio, GPIO_SECT_TRIS, 0u);
    } else {
        set_value(pin->gpio, GPIO_SECT_ANSEL, 0u);
        set_value(pin->gpio, GPIO_SECT_PORT, 0u);
        set_value(pin->gpio, GPIO_SECT_LAT, 0u);
        set_value(pin->gpio, GPIO_SECT_TRIS, 0u);
    }
    pin->value = pin->initial_value;
    return EXIT_SUCCESS;
}

void pin_on(Pin_t * pin){
    pin->value = pin->active_dir;
    set_value(pin->gpio, GPIO_SECT_PORT, pin->value);
}

void pin_off(Pin_t * pin){
    pin->value = !pin->active_dir;
    set_value(pin->gpio, GPIO_SECT_PORT, pin->value);
}

void pin_write(Pin_t * pin, Logic_t state){
    pin->value = state;
    set_value(pin->gpio, GPIO_SECT_PORT, pin->value);
}

Logic_t pin_read(Pin_t * pin){
    pin->value = get_value(pin->gpio);
    return pin->value;
}

void pin_toggle(Pin_t * pin){
    pin->value = !pin->value;
    set_value(pin->gpio, GPIO_SECT_PORT, pin->value);
}

void pin_deinit(Pin_t * pin){
    
}