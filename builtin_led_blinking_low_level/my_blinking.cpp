#include "my_blinking.h"
#include <Arduino.h>

void init_builtin_led(){
    volatile uint8_t* p = (uint8_t*) MY_DDRB_ADDR;

    //configure PB5 to output
    *p |= 1<<5;
    //*(MY_DDRB_ADDR) |= 1<<5;
}

void turn_on_builtin_led(){
    volatile uint8_t* p = (uint8_t*) MY_PORTB_ADDR;
    p = MY_PORTB_ADDR;
    *p |= 1 << 5;
}

void turn_off_builtin_led(){
    volatile uint8_t* p = (uint8_t*) MY_PORTB_ADDR;
    p = MY_PORTB_ADDR;
    *p &= ~(1 << 5);
}