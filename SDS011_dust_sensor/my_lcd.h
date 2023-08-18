#ifndef MY_LCD_H
#define MY_LCD_H


#define LCD_I2C_ADDR    0x27
#define LCD_COL         20
#define LCD_ROW         4


void setup_lcd_1602BB();

void print_data(char*);
void print_sds011_data(float data25, float data10);

#endif