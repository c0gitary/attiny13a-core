#ifndef __ATTINY13A_TYPEDEFS__
#define __ATTINY13A_TYPEDEFS__

typedef unsigned char byte;

typedef enum gpio_mode_pin_t {
    INPUT_PULLUP = -1, 
    INPUT, 
    OUTPUT
} mode_pin_t;

typedef enum gpio_adc_ref_t {
    ANALOG_REF_INTERNAL,
    ANALOG_REF_DEFAULT
} adc_ref_t;

typedef enum gpio_adc_pres_t {
    ANALOG_PRESCALER_OFF,
    ANALOG_PRESCALER_4,
    ANALOG_PRESCALER_8,
    ANALOG_PRESCALER_16,
    ANALOG_PRESCALER_32,
    ANALOG_PRESCALER_64,
    ANALOG_PRESCALER_128
} adc_prescaler_t;

typedef enum gpio_pwm_mode {
    PWM_PHASE_CORRECT,
    CTC,
    FAST_PWM,
    RESERVED,
} pwm_mode_t;

typedef enum gpio_pwm_prescaler {
    PWM_NO_PRESCALER,
    PWM_PRESCALER_8,
    PWM_PRESCALER_64,
    PWM_PRESCALER_256,
    PWM_PRESCALER_1024,
} pwm_prescaler_t;

typedef enum gpio_pin {
    PIN_5 = PB0,
    PIN_6 = PB1,
    PIN_7 = PB2,
    PIN_2 = PB3,
    PIN_3 = PB4,
    PIN_1 = PB5,
} pin_t;


#endif /*__ATTINY13A_TYPEDEFS__*/