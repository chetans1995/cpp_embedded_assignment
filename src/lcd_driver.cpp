#include "../include/lcd_driver.hpp"
#include "../include/millis.h"

// ------------------ PUBLIC METHODS ------------------------
hd44780::hd44780() {
    /* TASK
    Set up all the pins used for the program. Look at the wokwi
    sketch and compare to a pinout diagram for Arduino Uno R3.
    Use the definitions from lcd_driver.hpp
    */
    
    /* TASK
    Set the pins LCD_E and LCD_RS to low.
    */

    // ------------------- START NO TOUCHING BLOCK -----------------------------
    /* 
    This is an initialization sequence decided by the manufacturer
    and should not be modified.
    */
    millis_wait_ms(100);    // Wait for LCD to power up
    out_nibble(0x03);       // Function set (8-bit mode)
    millis_wait_ms(5);      // Wait for command to be processed
    out_nibble(0x03);       // Function set (8-bit mode, second attempt)
    millis_wait_ms(100);    // Short wait
    out_nibble(0x03);       // Function set (8-bit mode, third attempt)
    millis_wait_ms(100);    // Short wait
    out_nibble(0x02);       // Set to 4-bit mode
    millis_wait_ms(100);    // Short wait

    // Set functionality
    write_command(HD44780_FUNC_SET);
    millis_wait_ms(100);

    // turn on display
    write_command(HD44780_DISPLAY_ON);
    millis_wait_ms(100);

    // clear the screen
    clear();
    millis_wait_ms(2);

    // set increment behaviour
    write_command(HD44780_CURSOR_SET);
    millis_wait_ms(100);
    // ------------------- END NO TOUCHING BLOCK -----------------------------
}

void hd44780::blink_text(const char *text) {
    /* TASK
    Implement a blinking effect where the program first writes out the text
    and then blinks the message.
    */
}

void hd44780::write_text(const char *text) {
    clear();
    unsigned char row = 0;
    unsigned char col = 0;

    while (*text && row < HD44780_LINES) {
        char c = *text++;

        // Ignore carriage return (common in CRLF)
        if (c == '\r') continue;

        // Newline: move to start of next row
        if (c == '\n') {
            row++;
            if (row >= HD44780_LINES) break;
            col = 0;
            go_to(0, row);
            continue;
        }

        // Write character
        write_data(static_cast<unsigned char>(c));
        col++;

        // Wrap to next line after 16 chars
        if (col >= 16) {
            row++;
            if (row >= HD44780_LINES) break;
            col = 0;
            go_to(0, row);
        }
    }
}

void hd44780::clear(void) {
    write_command(HD44780_CLEAR);
    millis_wait_ms(2);
}

void hd44780::home(void) {
    write_command(HD44780_HOME);
    millis_wait_ms(2);
}

// ------------------ PRIVATE METHODS ------------------------
void hd44780::out_nibble(unsigned char nibble) {
    // BIT 0
    if (nibble & 1) LCD_DB4_PORT |= LCD_DB4;
    else LCD_DB4_PORT &= ~LCD_DB4;

    // BIT 1
    if (nibble & 2) LCD_DB5_PORT |= LCD_DB5;
    else LCD_DB5_PORT &= ~LCD_DB5;

    // BIT 2
    if (nibble & 4) LCD_DB6_PORT |= LCD_DB6;
    else LCD_DB6_PORT &= ~LCD_DB6;

    // BIT 3
    if (nibble & 8) LCD_DB7_PORT |= LCD_DB7;
    else LCD_DB7_PORT &= ~LCD_DB7;

    // sets Enable-pin to (1) to signal to LCD screen that there is data to be read
    LCD_E_PORT |= LCD_E;

    // short break for security
    millis_wait_ms(1);

    // sets Enable-pin to (0) stops reading the data
    LCD_E_PORT &= ~LCD_E;
}

void hd44780::write(unsigned char byte) {
    out_nibble(byte >> 4);
    out_nibble(byte);
}

void hd44780::write_command(unsigned char cmd) {
    write(cmd);
    millis_wait_ms(10);
}

void hd44780::write_data(unsigned char data) {
    LCD_RS_PORT |= LCD_RS;
    millis_wait_ms(2);

    write(data);
    millis_wait_ms(2);

    LCD_RS_PORT &= ~LCD_RS;
    millis_wait_ms(2);
}

void hd44780::go_to(unsigned char x, unsigned char y) {
    unsigned char addr = 0x80 + x + (0x40 * y);
    write_command(addr);
}