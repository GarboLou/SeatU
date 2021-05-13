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
  pinMode(TRIG_PIN2, OUTPUT);
  pinMode(ECHO_PIN2, INPUT);
  // set pin mode for infrared ray sensor
  pinMode(IR_PIN1, INPUT);  
  pinMode(IR_PIN2, INPUT);  
  // connect the wifi 
  connect_wifi(ssid,password);
}

// ESP-32 main function
void loop() {  
  // get the indicator from the device
  device->fill_data();
  for (int module_idx = 0; module_idx < SENSOR_N; module_idx++){
    // fill the data into the device's queue
    indicators_t indicator = device->get_indicator(module_idx);
    // send the data to sever
    send_data(serverName,&indicator);
  }
  delay(500);    
}