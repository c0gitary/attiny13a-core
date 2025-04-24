#ifndef __ATTINY13A_MAIN_FILE__
#define __ATTINY13A_MAIN_FILE__

#ifndef __AVR_ATtiny13A__
    #define __AVR_ATtiny13A__
#endif /*__AVR_ATtiny13A__*/

#include <avr/io.h>
#include <util/delay.h>

#define bit _BV
#define set_bit(reg, bit) ((reg) |= _BV(bit))
#define clear_bit(reg, bit) ((reg) &= ~_BV(bit))
#define toggle_bit(reg, bit) ((reg) ^= _BV(bit))
#define read_bit(reg, bit) ((reg) & _BV(bit))

#include "t13a_typedefs.h"
#include "t13a_gpio.h"

#endif /*__ATTINY13A_MAIN_FILE__*/