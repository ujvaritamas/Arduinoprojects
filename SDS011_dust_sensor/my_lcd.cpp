#include <LiquidCrystal_I2C.h>
#include "my_lcd.h"

LiquidCrystal_I2C lcd(LCD_I2C_ADDR, LCD_COL, LCD_ROW);

void setup_lcd_1602BB() {
    lcd.init();
    lcd.backlight();

    //lcd.noBacklight();
    lcd.setCursor(1, 0);
    lcd.print("Hello!");
    //lcd.nobacklight()
}

void print_data(char* data){
    lcd.clear();
    lcd.print(data);
}


void print_sds011_data(float data25, float data10){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("PM2.5 = ");
    lcd.setCursor(8,0);
    lcd.print(data25);
    lcd.setCursor(0,1);
    lcd.print("PM10  = ");
    lcd.setCursor(8,1);
    lcd.print(data10);
}
