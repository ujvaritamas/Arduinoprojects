#include "my_sds011.h"
#include "SdsDustSensor.h"
#include "my_lcd.h"


SdsDustSensor sds(SDS_RX_PIN, SDS_TX_PIN);

void init_sds011(){
  //ldc init
  setup_lcd_1602BB();
  Serial.begin(9600);
  //init sds011
  sds.begin();
  Serial.println(sds.queryFirmwareVersion().toString()); // prints firmware version
  //Serial.println(sds.setActiveReportingMode().toString()); // ensures sensor is in 'active' reporting mode
  //Serial.println(sds.setContinuousWorkingPeriod().toString());
  //Serial.println(sds.setQueryReportingMode().toString()); // ensures sensor is in 'active' reporting mode
  ReportingModeResult result = sds.setQueryReportingMode();
  Serial.println(result.toString());
}


void get_and_print_sds_data(){
    //PmResult pm = sds.readPm();
    PmResult pm = sds.queryPm();
    if (pm.isOk()) {
      print_sds011_data(pm.pm25, pm.pm10);
  
      Serial.print(", PM2.5 = ");
      Serial.print(pm.pm25);
      Serial.print(", PM10 = ");
      Serial.println(pm.pm10);
  }
  else {
    //lcd.print("Could not read values from sensor.");
    Serial.print(pm.statusToString());
  }


}