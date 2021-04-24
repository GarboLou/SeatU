#include <common.h>
#include <wifi_connect.h>
#include <device.h>
#include <send_data.h>
using namespace std;

Device *device = new Device();

// ESP-32 setup function
void setup() {
  Serial.begin(9600);
  // set pin mode for ultrasonic sensor
  pinMode(TRIG_PIN1, OUTPUT);
  pinMode(ECHO_PIN1, INPUT);
  // set pin mode for infrared ray sensor
  pinMode(IR_PIN1, INPUT);  
  // connect the wifi 
  // connect_wifi(ssid,password);
}

// ESP-32 main function
void loop() {  
  // fill the data into the device's queue
  device->fill_data();
  // get the indicator from the device
  indicators_t indicator = device->get_indicator(0);
  Serial.print(indicator.US_mean);
  Serial.print(",");
  Serial.print(indicator.IR_mean);
  Serial.print(",");
  Serial.print(indicator.US_variance);
  Serial.print(",");
  Serial.println(indicator.IR_variance);
  // send the data to sever
  // send_data(serverName,device);
  delay(500);    
}