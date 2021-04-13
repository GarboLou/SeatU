#include <device.h>
Device::Device(){
  sensor_module *module1 = new sensor_module(IR_PIN1, TRIG_PIN1, ECHO_PIN1);
  // module2 = new sensor_module(IR_PIN2, TRIG_PIN2, ECHO_PIN2);
  // module3 = new sensor_module(IR_PIN3, TRIG_PIN3, ECHO_PIN3);
  // module4 = new sensor_module(IR_PIN4, TRIG_PIN4, ECHO_PIN4);
  sensor_modules[0] = *module1;

}

void Device::fill_data(){
  // fill the data into sensors' queues
  for (int i =0; i<DATA_BATCH; i++){
    for (int module_idx=0; module_idx<SENSOR_N; module_idx++){
        sensor_modules[module_idx].fill_queue();
      }
    delay(COLLECT_DELAY);
  }
  // after fill the data, calculate the indicators
  for (int module_idx=0; module_idx<SENSOR_N; module_idx++){
    sensor_modules[module_idx].calculate_indicators();
  }
}

indicators_t Device::get_indicator(int module_idx){
  indicators_t indicator = sensor_modules[module_idx].get_indicators();
  return indicator;
}