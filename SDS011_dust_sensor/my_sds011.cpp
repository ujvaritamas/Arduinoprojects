#include "my_sds011.h"
#include "SdsDustSensor.h"
#include "my_lcd.h"


SdsDustSensor sds(SDS_RX_PIN, SDS_TX_PIN);

void init_sds011(){
  //ldc init
  setup_lcd_1602BB();
  //init sds011
  Serial.begin(9600);
  sds.begin();

  Serial.println(sds.queryFirmwareVersion().toString()); // prints firmware version
  Serial.println(sds.setActiveReportingMode().toString()); // ensures sensor is in 'active' reporting mode
  Serial.println(sds.setContinuousWorkingPeriod().toString());
}

void get_and_print_sds_data(){
  char pm2_buffer[10];
  char pm10_buffer[20];
  PmResult pm = sds.readPm();
  if (pm.isOk()) {

    //convert data to char*
    print_pm25_res(pm.pm25)

    Serial.print(", PM2.5 = ");
    Serial.print(pm.pm25);
    Serial.print(", PM10 = ");
    Serial.println(pm.pm10);

    //lcd.print(pm.toString());
  }
  else {
    // notice that loop delay is set to 0.5s and some reads are not available
    //lcd.print("Could not read values from sensor.");
    Serial.print(pm.statusToString());
  }

  void print_pm25_res(float res){
    char buffer[30];
    snprintf(buffer, sizeof buffer, "%f", res);
    print_data(buffer)
  }
}
