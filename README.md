# COMPANY ADSCREEN
You have been tasked with writing the application logic for the Ad Screen used by your company and finish the driver initialization of the LCD. The company's ad screen prints out the advertiser's name and then their ad message.

# Sources
For this project you will use the Requirements Specification down below and a provided Wokwi sketch.

Link to the sketch is here: https://wokwi.com/projects/445497618841194497

# Requirements Specification
The following requirements are specified by the product manager.

## Functional Requirements

### 1. Program Logic
The program should always run while powered on. When powered on the program should:
1. Choose the next advertiser
2. Show the company name for 5 seconds
3. Show one of the company's ad messages for 10 seconds

### 2. Advertisement logic
**2.1.**
Paid weighting: probability of the next selected advertiser co-relates to how much they've paid for their ads / the total ad sum.

**2.2.** 
Companies will have different amount of ad messages. Make sure to rotate their ads independently and that all of their ads will have be shown at some point. This should be sequential and not randomly generated.

### 3. Proper initialization of hd44780
The team has already written a part of the driver for the company's LCD driver. You need to finish the initialization in the hd44780 constructor.

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

---

## Non-functional Requirements
Non-business logic requirements for the system.

### 1. No heap allocated memory
Because of the small RAM, the program should only use the stack.

### 2. No blocking delays
The program should always be able to call an ISR at any given time.

---

## Deliverable Requirements
Requirements on how the codebase should be delivered.

### 1. Folder structure
The following folder structure should be uphold in this project.
```
ProjectName
├─── Makefile
├─── main.cpp
├─── include
│    └───header files
└─── src
     └───source code files
```

### 2. Code Separation
Build cohesive files where every file represent a specific functionality for the program.

---

# Advertisers
The following companies are paying customers that want to show their ads on the screen:

## 1. CoolCars LLC
* **Company name:** CoolCars LLC
* **Paid amount:** 5 000 SEK
* **Messages:**
    * *Drive me crazy!* `plain`
    * *30-day moneyback guarantee* `plain`

## 2. Pie People
* **Company name:** Pie People
* **Paid amount:** 2 500 SEK
* **Messages:**
    * *Making people float* `blink`
    * *They are hot and jammy* `plain`

## 3. Washomania
* **Company name:** Washomania
* **Paid amount:** 4 900 SEK
* **Messages:**
    * *Clean customers happy customers* `blink`

## 4. Holy Burgers
* **Company name:** Holy Burgers
* **Paid amount:** 1 750 SEK
* **Messages:**
    * *Free drinks included in menu* `plain`
    * *Burgermania! 2 for 59 SEK* `blink`
    * *Badabim... Bada BURGER!* `blink`

## 5. Gymbo James
* **Company name:** Gymbo James
* **Paid amount:** 6 700 SEK
* **Messages:**
    * *No more excuses! Only GAINS!* `blink`
    * *Pro Gymbono - 14 days free* `plain`

---