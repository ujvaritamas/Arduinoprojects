#ifndef MY_SDS011_H
#define MY_SDS011_H

#define SDS_RX_PIN  2       //pin2
#define SDS_TX_PIN  4       //pin4

void init_sds011();
void get_and_print_sds_data();
#endif