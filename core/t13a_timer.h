#ifndef __ATTINY13A_TIMER__
#define __ATTINY13A_TIMER__


__attribute__((always_inline, cold))
static inline void
timer_set_prescaler(const prescaler_t prescaler){
    if(prescaler){
        if(prescaler == PRESCALER_8) {
            set_bit(TCCR0B, CS01);
            return;
        }
        else if(prescaler == PRESCALER_64) {
            set_bit(TCCR0B, CS00);
            set_bit(TCCR0B, CS01);
            return;   
        }
        else if(prescaler == PRESCALER_256) {
            set_bit(TCCR0B, CS02);
            return;
        }
        else if(prescaler == PRESCALER_1024) {
            set_bit(TCCR0B, CS00);
            set_bit(TCCR0B, CS02);
            return;
        }
    }
    set_bit(TCCR0B, CS00);
    return;
}


__attribute__((always_inline, cold))
static inline void
timer_set_mode(const timer_mode_t mode){
    if(mode) {
        if(mode == CTC) {
            set_bit(TCCR0A, WGM01);
            return;
        }
        else if(mode == FAST_PWM) {
            set_bit(TCCR0A, WGM00);
            set_bit(TCCR0A, WGM01);
            return;
        }
        else if(mode == RESERVED) {
            set_bit(TCCR0A, WGM02);
            return;
        }
    }
    set_bit(TCCR0A, WGM00);
    return;
}

__attribute__((always_inline, hot))
static inline void
timer_set_OCR(const pin_t pin, const uint8_t value){
    if(pin == PIN_5){
        OCR0A = value;
        return;
    }
    if(pin == PIN_6){
        OCR0B = value;
        return;
    }
    return;
}


__attribute__((always_inline, cold))
static inline void
timer_set_pin(const pin_t pin){
    if(pin == PIN_5) set_bit(TCCR0A, COM0A1);
    else if(pin == PIN_6) set_bit(TCCR0A, COM0B1);
    if(!read_bit(DDRB, pin)) set_bit(DDRB, pin); 
}

#endif /*__ATTINY13A_TIMER__*/