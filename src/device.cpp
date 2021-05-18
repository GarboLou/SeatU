#include <device.h>
/*
 * Discription: Constructor for the Device class
 * Input: None
 * Output: None
 * Side effect: It will create N (up to 4) sensor module class object
 */

Device::Device(){
  sensor_module *module1 = new sensor_module(IR_PIN1, TRIG_PIN1, ECHO_PIN1, 1);
  sensor_module *module2 = new sensor_module(IR_PIN2, TRIG_PIN2, ECHO_PIN2, 2);
  sensor_module *module3 = new sensor_module(IR_PIN3, TRIG_PIN3, ECHO_PIN3, 3);
  sensor_module *module4 = new sensor_module(IR_PIN4, TRIG_PIN4, ECHO_PIN4, 4);
  sensor_modules[0] = *module1;
  sensor_modules[1] = *module2;
  sensor_modules[2] = *module3;
  sensor_modules[3] = *module4;

}

/*
 * Discription: Fill the data into the sensor modules' queues, and then
                call the sensor' function to calculate the indicators(Mean and Variance)
 * Input: None
 * Output: None
 * Side effect: The indicators for each sensor will be prepared
 */
void Device::fill_data(){
  // fill the data into sensors' queues
  for (int i =0; i<DATA_BATCH; i++){
    for (int module_idx=0; module_idx<SENSOR_N; module_idx++){
      sensor_modules[module_idx].fill_queue();
      delay(COLLECT_DELAY);
    }
  }
  
  // after fill the data, calculate the indicators
  for (int module_idx=0; module_idx<SENSOR_N; module_idx++){
    sensor_modules[module_idx].calculate_indicators();
  }
}

/*
 * Discription: Get the sensor pair's indicators by the input index
 * Input: int module_idx: The index for the sensor module(0 to 3)
 * Output: indicators_t indicator: the indicator structure (contains mean  
 *                                 and variance for one sensor pair)
 * Side effect: The indicator can be received from the outside
 */
indicators_t Device::get_indicator(int module_idx){
  indicators_t indicator = sensor_modules[module_idx].get_indicators();
  return indicator;
}

/*
 * Discription: Get all sensor pairs' indicators
 * Input: int module_idx: The index for the sensor module(0 to 3)
 * Output: indicators_t indicator: the indicator structure (contains mean  
 *                                 and variance for one sensor pair)
 * Side effect: The indicator can be received from the outside
 */
indicators_t* Device::get_indicators(){
  static indicators_t indicators[SENSOR_N];
  for (int n = 0; n< SENSOR_N; n++){
    indicators[n] = sensor_modules[n].get_indicators();
  }
  return indicators;
}