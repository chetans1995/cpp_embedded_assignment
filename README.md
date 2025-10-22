# COMPANY ADSCREEN
You have been tasked with writing the application logic for the Ad Screen used by your company and finish the driver initialization of the LCD. The company's ad screen prints out the advertiser's name and then their ad message.

# Requirements Specification
The following requirements are specified by the product manager.

## Functional Requirements

### 1. Program Logic
The program should always run while powered on. When powered on the program should:
1. Choose the next advertiser
2. Show the company name for 5 seconds
3. Show the ad message for 10 seconds

### 2. Advertisement logic
Different companies have paid different amount of money for their ads. Implement a way to show ads based on how much the advertiser paid. You will find information about the advertisers further down in the document.

### 3. Proper initialization of hd44780
The team have already written a part of the driver for the company's LCD driver. You need to finish the initialization in the hd44780 constructor.

**lcd_driver.cpp**
```cpp
hd44780::hd44780() {
    /* TASK
    Set up all the pins used for the program. Look at the wokwi
    sketch and compare to a pinout diagram for Arduino Uno R3.
    Use the definitions from lcd_driver.hpp
    */
    
    /* TASK
    Set the pins LCD_E and LCD_RS to low.
    */

    [ ... Initialization Sequence ...]
}
```

### 4. Create a blink effect
Some of the companies want to blink their ad messages, therefore we need to implement a blinking effect on the hd44780. Make use of the `#defines` from `lcd_driver.hpp` and finish the `blink_text()` method.

**lcd_driver.cpp**
```cpp
void hd44780::blink_text(const char *text) {
    /* TASK
    Implement a blinking effect where the program first writes out the text
    and then blinks the message.
    */
}
```

## Non-functional Requirements
Non-business logic requirements for the system.

### 1. No heap allocated memory
Because of the small RAM, the program should only use the stack.

### 2. No blocking delays
The program should always be able to call an ISR at any given time.

## Deliverable Requirements
Requirements on how the codebase should be delivered.

### 1. Folder structure
ProjectName
├───include
│   └───header_files
└───src
    └───source_code_files



# Advertisers
The following companies are paying customers that want to show their adds on the screen: