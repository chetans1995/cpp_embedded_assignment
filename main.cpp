#include "include/millis.h"
#include "include/lcd_driver.hpp"

#include <avr/pgmspace.h>
#include <avr/interrupt.h>


int main(void) {
    millis_init();
    sei();
    
    LcdDriver lcd;
    lcd.begin(16, 2);
    lcd.print("Hello, HD44780!");
    
    /*
    while(1) {
        lcd.begin(16, 2);
        lcd.print("Hello, HD44780!");
        delay(1000);
    }
    */
    return 0;
}