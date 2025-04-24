#ifndef __ATTINY13A_TYPEDEFS__
#define __ATTINY13A_TYPEDEFS__

typedef enum gpio_pwm_mode {
    PWM_PHASE_CORRECT,
    CTC,
    FAST_PWM,
    RESERVED,
} pwm_mode_t;

typedef enum gpio_pwm_prescaler {
    NO_PRESCALER,
    PRESCALER_8,
    PRESCALER_64,
    PRESCALER_256,
    PRESCALER_1024,
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