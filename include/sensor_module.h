#ifndef SENSOR_MODULE_H
#define SENSOR_MODULE_H
#include <Arduino.h>
#include <queue>
#include <common.h>
using namespace std;
struct indicators_t{
    float IR_mean;
    float US_mean;
    float IR_variance;
    float US_variance;
};

class sensor_module{
    private:
        int IR_pin;
        int US_triger_pin;
        int US_echo_pin;
        indicators_t indicators;
        priority_queue<float> US_queue;
        priority_queue<float> IR_queue;
        void get_indicator(priority_queue<float> *q, float *mean, float *variance);
    public:
        float infrared();
        float ultrasonic();
        void fill_queue();
        void calculate_indicators();
        void init_indicators();
        indicators_t get_indicators();
        sensor_module(){};
        sensor_module(int IR_pin, int US_triger_pin, int US_echo_pin):IR_pin(IR_pin),US_triger_pin(US_triger_pin),US_echo_pin(US_echo_pin){
            init_indicators();
        }
};

#endif