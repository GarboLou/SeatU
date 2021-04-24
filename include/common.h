#ifndef COMMON_H
#define COMMON_H
#include <Arduino.h>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <SPI.h>
#include <HTTPClient.h>
#include <Wire.h>

// 1st sensors pair 
#define TRIG_PIN1 22        // ultrasonic sensor's trigger pin number
#define ECHO_PIN1 21        // ultrasonic sensor's echo pin number
#define IR_PIN1 34          // infrared ray sensor's  pin number

// 2nd sensors pair
#define TRIG_PIN2 22
#define ECHO_PIN2 21
#define IR_PIN2 34

// 3rd sensors pair
#define TRIG_PIN3 22
#define ECHO_PIN3 21
#define IR_PIN3 34

// 4th sensors pair
#define TRIG_PIN4 22
#define ECHO_PIN4 21
#define IR_PIN4 34

#define DATA_BATCH 30       // collect DATA_BATCH data for each batch
#define MAXDIST 120         // the maximum distance between the sensor and the object
#define DISCARD_TOP 1       // discard n largest data
#define DISCARD_TAIL 1      // discard n smallest data
#define SENSOR_N 1          // sensor pair we have for one device
#define COLLECT_DELAY 500   // collect one data for each T millisenconds
static const char* ssid     = "iPhone (5)";     // WiFi name
static const char* password = "ece445mscs";     // WiFi password
static const char* serverName = "http://1.116.101.206:8001/get_data.php";   // sever name
#endif
