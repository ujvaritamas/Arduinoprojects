#include "my_sds011.h"
#include "SdsDustSensor.h"
#include "my_lcd.h"


SdsDustSensor sds(SDS_RX_PIN, SDS_TX_PIN);

void init_sds011(){
    //ldc init
    setup_lcd_1602BB()

    //init sds011
    Serial.begin(9600);
    sds.begin();
    sds.setActiveReportingMode();
    sds.setContinuousWorkingPeriod()
}

char* get_sds_data(){
    //char pm2_buffer[20];
    //char pm10_buffer[20];
    PmResult pm = sds.readPm();
  if (pm.isOk()) {

    //convert data to char*
    //sprintf(buffer, "PM2.5 = %.2f", pm.pm25)
    //sprintf(buffer, "PM10 = %.2f", pm.pm10)

    //Serial.print("PM2.5 = ");
    //Serial.print(pm.pm25);
    //Serial.print(", PM10 = ");
    //Serial.println(pm.pm10);

    print_data(pm.toString());
  } else {
    // notice that loop delay is set to 0.5s and some reads are not available
    print_data("Could not read values from sensor, reason: ");
  }
}