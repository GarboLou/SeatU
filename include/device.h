#ifndef DEVICE_H
#define DEVICE_H
#include <Arduino.h>
#include <queue>
#include <common.h>
#include <sensor_module.h>
using namespace std;

class Device{
    private:
        sensor_module sensor_modules[SENSOR_N];
    public:
        Device();
        void fill_data();
        indicators_t get_indicator(int module_idx);
};

#endif


