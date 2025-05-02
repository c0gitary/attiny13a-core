#ifndef __ATTINY13A_GPIO_ANALOG__
#define __ATTINY13A_GPIO_ANALOG__

__attribute__((cold))
static inline void
gpio_analog_init(const pin_t pin, const adc_ref_t ref, const adc_prescaler_t presc){
    if(ref) clear_bit(ADMUX, REFS0);
    else set_bit(ADMUX, REFS0);

    if(presc == ANALOG_PRESCALER_4) {
        set_bit(ADCSRA, ADPS1);
    }
    else if(presc == ANALOG_PRESCALER_8){
        set_bit(ADCSRA, ADPS1);
        set_bit(ADCSRA, ADPS0);
    }
    else if(presc == ANALOG_PRESCALER_16){
        set_bit(ADCSRA, ADPS2);
    }
    else if(presc == ANALOG_PRESCALER_32){
        set_bit(ADCSRA, ADPS2);
        set_bit(ADCSRA, ADPS0);
    }
    else if(presc == ANALOG_PRESCALER_64){
        set_bit(ADCSRA, ADPS2);
        set_bit(ADCSRA, ADPS1);
    }
    else if(presc == ANALOG_PRESCALER_128){
        set_bit(ADCSRA, ADPS2);
        set_bit(ADCSRA, ADPS1);
        set_bit(ADCSRA, ADPS0);
    } 
    else {
        set_bit(ADCSRA, ADPS1);
    }

    set_bit(DDRB, pin);
    set_bit(ADCSRA, ADEN);
    return;
}

__attribute__((always_inline, hot))
static inline uint16_t 
gpio_analog_read(const pin_t pin) {
    ADMUX = (ADMUX & 0xFC) | (pin);
    set_bit(ADCSRA, ADSC);
    while(read_bit(ADCSRA, ADSC)); //wait
    return ADC;
}

#endif /*__ATTINY13A_GPIO_ANALOG__*/