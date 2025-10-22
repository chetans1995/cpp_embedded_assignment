#include "include/millis.h"
#include "include/lcd_driver.hpp"

#include <avr/pgmspace.h>
#include <avr/interrupt.h>

int main(void) {
    millis_init();
    sei();

    while(1) {

    }

    return 0;
}