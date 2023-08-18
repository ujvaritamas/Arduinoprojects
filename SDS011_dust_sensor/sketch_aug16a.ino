#include "my_lcd.h"
#include "my_sds011.h"

void setup() {
  init_sds011();
  
}

void loop() {
  get_and_print_sds_data();
  delay(10000);                  // waits for a second
}