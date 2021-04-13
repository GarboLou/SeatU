#include <common.h>
#include <wifi_connect.h>
#include <device.h>
#include <send_data.h>
// String apiKeyValue = "tPmAT5Ab3j7F9";

using namespace std;
Device *device = new Device();
void setup() {
  Serial.begin(9600);
  // The Trigger pin will tell the sensor to range find
  pinMode(TRIG_PIN1, OUTPUT);
  pinMode(ECHO_PIN1, INPUT);

  pinMode(IR_PIN1, INPUT);  
  // We'll use the serial monitor to view the sensor output
  
  connect_wifi(ssid,password);
}



void loop() {  
  device->fill_data();
  indicators_t indicator = device->get_indicator(0);
  Serial.print(indicator.US_mean);
  Serial.print(",");
  Serial.print(indicator.IR_mean);
  Serial.print(",");
  Serial.print(indicator.US_variance);
  Serial.print(",");
  Serial.println(indicator.IR_variance);
  send_data(serverName,device);
  delay(500);    
}