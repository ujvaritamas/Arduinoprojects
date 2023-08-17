#ifndef MY_BLINKING_H
#define MY_BLINKING_H

//builtin led connected to PB5
#define MY_PORTB_ADDR   (volatile uint8*)0x05
#define MY_DDRB_ADDR    (volatile uint8*)0x04
//#define MY PINB_ADDR   not needed -> read only

void init_builtin_led();

void turn_on_builtin_led();
void turn_off_builtin_led();

#endif