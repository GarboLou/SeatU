#ifndef SEND_DATA_H
#define SEND_DATA_H
#include <common.h>
#include <WiFiClientSecure.h>
#include <device.h>
#include <sensor_module.h>
void send_data(const char* serverName, indicators_t* indicator);
void speed_test(const char* serverName);
#endif