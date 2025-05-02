#ifndef __ATTINY13A_MAIN_FILE__
#define __ATTINY13A_MAIN_FILE__

#ifndef __AVR_ATtiny13A__
    #define __AVR_ATtiny13A__
#endif /*__AVR_ATtiny13A__*/

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/atomic.h>
#include <util/delay.h>
#include <stdlib.h>
#include <math.h>

#define bit _BV

#define set_bit(reg, bit) ((reg) |= _BV(bit))

#define clear_bit(reg, bit) ((reg) &= ~_BV(bit))

#define toggle_bit(reg, bit) ((reg) ^= _BV(bit))

#define read_bit(reg, bit) ((reg) & _BV(bit))

#define max(a, b) ((a) > (b) ? (a) : (b))

#define min(a, b) ((a) < (b) ? (a) : (b))

#define constrain(x, l, h) ((x) > (l) ? (l) : (x) > (h) ? (h) : (x))

#define interrupt(state) ((state) ? (sei()) : (cli()))

#include "t13a_typedefs.h"

#include "t13a_timer.h"

#include "t13a_gpio.h"

#endif /*__ATTINY13A_MAIN_FILE__*/