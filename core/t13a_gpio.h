#ifndef __ATTINY13A_GPIO__
#define __ATTINY13A_GPIO__

#include "t13a_gpio_digital.h"
#include "t13a_gpio_analog.h"
#include "t13a_gpio_pwm.h"

typedef enum gpio_mode_pin_t {INPUT_PULLUP = -1, INPUT, OUTPUT} mode_pin_t;

#define gpio_set_pin_mode_input(pin) set_bit(DDRB, pin)
#define gpio_set_pin_mode_output(pin) clear_bit(DDRB, pin)

__attribute__((always_inline))
static inline void 
gpio_set_pin_mode(const uint8_t pin, const mode_pin_t mode){
    if(mode) gpio_set_pin_mode_output(pin);
    else {
        gpio_set_pin_mode_input(pin);
        if(mode == INPUT_PULLUP) {
            gpio_digital_set_pin_high(pin);
        }
    }
}



#endif /*__ATTINY13A_GPIO__*/