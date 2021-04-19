#ifndef COMMON_H
#define COMMON_H
#include <Arduino.h>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <SPI.h>
#include <HTTPClient.h>
#include <Wire.h>

#define TRIG_PIN1 22
#define ECHO_PIN1 21
#define IR_PIN1 34

#define TRIG_PIN2 22
#define ECHO_PIN2 21
#define IR_PIN2 34

#define TRIG_PIN3 22
#define ECHO_PIN3 21
#define IR_PIN3 34

#define TRIG_PIN4 22
#define ECHO_PIN4 21
#define IR_PIN4 34

#define TRIG_PIN4 22
#define ECHO_PIN4 21
#define IR_PIN4 34

#define DATA_BATCH 5
#define MAXDIST 150
#define DISCARD_TOP 1
#define DISCARD_TAIL 1
#define SENSOR_N 1
#define COLLECT_DELAY 500
static const char* ssid     = "iPhone (5)";
static const char* password = "ece445mscs";
static const char* serverName = "http://1.116.101.206:8001/get_data.php";
#endif
