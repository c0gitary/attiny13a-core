#ifndef __ATTINY13A_GPIO_PWM__
#define __ATTINY13A_GPIO_PWM__

/*
    MAX = 0xff
    BOTTOM = 0x00

    {mode - top}
    normal - 0xff
    pwm - 0xff
    ctc - OCRA
    fast_pwm - 0xff
    reserved - (-)
*/


__attribute__((always_inline))
static inline void 
gpio_pwm_init(const pin_t pin, const pwm_prescaler_t prescaler, const pwm_mode_t mode){
    if(prescaler){
        if(prescaler == PRESCALER_8) {
            set_bit(TCCR0B, CS01);
        }
        else if(prescaler == PRESCALER_64) {
            set_bit(TCCR0B, CS00);
            set_bit(TCCR0B, CS01);
        }
        else if(prescaler == PRESCALER_256) {
            set_bit(TCCR0B, CS02);
        }
        else if(prescaler == PRESCALER_1024) {
            set_bit(TCCR0B, CS00);
            set_bit(TCCR0B, CS02);
        }
    }
    else {
        set_bit(TCCR0B, CS00);
    }

    if(mode) {
        if(mode == CTC) {
            set_bit(TCCR0A, WGM01);
        }
        else if(mode == FAST_PWM) {
            set_bit(TCCR0A, WGM00);
            set_bit(TCCR0A, WGM01);
        }
        else if(mode == RESERVED) {
            set_bit(TCCR0A, WGM02);
        }
    }
    else {
        set_bit(TCCR0A, WGM00);
    }

    if(pin == PIN_5) set_bit(TCCR0A, COM0A1);
    else if(pin == PIN_6) set_bit(TCCR0A, COM0B1);

    if(!read_bit(DDRB, pin)) set_bit(DDRB, pin); 

    return;
}   

__attribute__((always_inline, hot))
static inline void
gpio_pwm_write(const pin_t pin, const uint8_t val){
    if(pin == PIN_5) OCR0A = val;
    else if(pin == PIN_6) OCR0B = val;
    else return;
}

#endif /*__ATTINY13A_GPIO_PWM__*/