#ifndef SEND_DATA_H
#define SEND_DATA_H
#include <common.h>
#include <WiFiClientSecure.h>
#include <device.h>
void send_data(const char* serverName, Device* device);
#endif