#ifndef MY_LCD_H
#define MY_SDS011_H

#define SDS_RX_PIN  0
#define SDS_TX_PIN  1

void init_sds011();
char* get_and_print_sds_data();
#endif