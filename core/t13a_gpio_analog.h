#ifndef __ATTINY13A_GPIO_ANALOG__
#define __ATTINY13A_GPIO_ANALOG__


__attribute__((always_inline, hot))
static inline uint16_t 
gpio_analog_read(const uint8_t pin) {

    set_bit(ADCSRA, ADEN);
    set_bit(ADCSRA, ADSC);

    #if defined(ANALOG_REF_INTERNAL)
        clear_bit(ADMUX, REFS0);
    #else
        set_bit(ADMUX, REFS0);
    #endif
    
    ADMUX = (ADMUX & 0xFC) | (pin);

    #if defined(ANALOG_PRESCALER_4) 
        set_bit(ADCSRA, ADPS1);
    #elif defined(ANALOG_PRESCALER_8)
        set_bit(ADCSRA, ADPS1);
        set_bit(ADSSRA, ADPC0);
    #elif defined(ANALOG_PRESCALER_16)
        set_bit(ADCSRA, ADPS2);
    #elif defined(ANALOG_PRESCALER_32)
        set_bit(ADCSRA, ADPS2);
        set_bit(ADCSRA, ADPS0);
    #elif defined(ANALOG_PRESCALER_64)
        set_bit(ADCSRA, ADPS2);
        set_bit(ADCSRA, ADPS1);
    #elif defined(ANALOG_PRESCALER_128)
        set_bit(ADCSRA, ADPS2);
        set_bit(ADCSRA, ADPS1);
        set_bit(ADCSRA, ADPS0);
    #else
        set_bit(ADCSRA, ADPS1);
    #endif

    while(read_bit(ADCSRA, ADSC)); //wait
    return ADCH;
}

#endif /*__ATTINY13A_GPIO_ANALOG__*/