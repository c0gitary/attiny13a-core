#ifndef __ATTINY13A_GPIO_DIGITAL__
#define __ATTINY13A_GPIO_DIGITAL__

#define gpio_digital_read(pin) read_bit(PINB, pin)

#define gpio_digital_set_pin_high(pin) set_bit(PORTB, pin)

#define gpio_digital_set_pin_low(pin) clear_bit(PORTB, pin)

#define gpio_digital_pin_toggle(pin) toggle_bit(PORTB, pin)

#define gpio_digital_pin_write(pin, state) ((state) ? (gpio_digital_set_pin_high(pin)) : (gpio_digital_set_pin_low(pin)))

#endif /*__ATTINY13A_GPIO_DIGITAL__*/