#include <LiquidCrystal_I2C.h>
#include "my_lcd.h"

LiquidCrystal_I2C lcd(LCD_I2C_ADDR, LCD_COL, LCD_ROW);

void setup_lcd_1602BB() {
    lcd.init();
    lcd.backlight();
    lcd.setCursor(1, 0);
    lcd.print("Hello, Wokwi!");
    //lcd.nobacklight()
}

