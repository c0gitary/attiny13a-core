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


__attribute__((always_inline, cold))
static inline void 
gpio_pwm_init(const pin_t pin, const prescaler_t prescaler, const timer_mode_t mode){
    timer_set_prescaler(prescaler);
    timer_set_mode(mode);
    timer_set_pin(pin);
}   


__attribute__((always_inline, hot))
static inline void
gpio_pwm_write(const pin_t pin, const uint8_t val){
    timer_set_OCR(pin, val);
}

#endif /*__ATTINY13A_GPIO_PWM__*/