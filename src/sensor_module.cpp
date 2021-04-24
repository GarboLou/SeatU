#include <sensor_module.h>

/*
 * Discription: Get one distance from the infrared ray sensor
 * Input: None
 * Output: float dist: the distance from infrared ray sensor
 * Side effect: The distance calculated by infrared ray sensor will be received
 */
float sensor_module::infrared(){
  // get the voltage from the pin
  float volts = (float)analogRead(IR_pin);
  // get the distance
  float dist = 65 * pow(volts/1000.,-1.10);
  if (isinf(dist)){
    dist=MAXDIST;
  }
  dist = fmax(0,fmin(dist,MAXDIST));

  return dist;
}

/*
 * Discription: Get one distance from the ultrasonic sensor
 * Input: None
 * Output: float dist: the distance from ultrasonic sensor
 * Side effect: The code will wait for 18 microsenconds.
 *              The distance calculated by ultrasonic sensor will be received
 */
float sensor_module::ultrasonic(){
  // Create a square wave 
  digitalWrite(US_triger_pin, LOW);
  delayMicroseconds(8);
  digitalWrite(US_triger_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(US_triger_pin, LOW);
  // measure the length of high echo wave to get the time, 
  // then calculate the distance
  float dist = pulseIn(US_echo_pin, HIGH) / 58.00;
  if (isinf(dist)){
    dist=MAXDIST;
  }
  dist = fmax(0,fmin(dist,MAXDIST));
  return dist;
}

/*
 * Discription: push one data into the queue
 * Input: None
 * Output: None
 * Side effect: the queue will be filled by one data
 */
void sensor_module::fill_queue(){
    US_queue.push(ultrasonic());
    IR_queue.push(infrared());
}

/*
 * Discription: Get the indicator(Mean and Variance) from the full queue
 * Input: priority_queue<float> *q: Pointer to the queue, which contains the distance data
 * Output: float *mean: Mean value after calculation
 *         float *variance: Variance value after calculation
 * Side effect: The queue in the sensor module will be cleaned, the indicators will be filled
 */
void sensor_module::cal_indicator(priority_queue<float> *q, float *mean, float *variance){
  int data_size = DATA_BATCH-DISCARD_TOP-DISCARD_TAIL;
  float data[data_size]; // used to store each data
  if (q->size()==DATA_BATCH){
    // discard the largest distance
    for (int i=0; i< DISCARD_TOP; i++){
      q->pop();
    }
    // record the distance
    for (int i =0; i< data_size;i++){
      *mean += q->top();
      data[i] = q->top();
      q->pop();
    }
    // clear the queue (discard the smallest distance)
    for (int i=0; i< DISCARD_TAIL; i++){
      q->pop();
    }
    // divide by the total number
    *mean /= data_size;
    
    for (int i =0; i< data_size;i++){
      *variance += pow(data[i] - *mean,2);
    } 
    *variance /= data_size; 
  }else{
    printf("wrong size of queue");
    exit(1);
  }
}

/*
 * Discription: calculate both ultrasonic and infrared ray sensors' indicators
 * Input: None
 * Output: None
 * Side effect: The queue in the sensor module will be cleaned, the indicators will be filled
 */
void sensor_module::calculate_indicators(){
  init_indicators();
  cal_indicator(&US_queue, &indicators.US_mean, &indicators.US_variance);
  cal_indicator(&IR_queue, &indicators.IR_mean, &indicators.IR_variance);
}

/*
 * Discription: Get the indicators structure
 * Input: None
 * Output: indicators_t indicators: Four indicators, mean value and variance of both 
 *                                  ultrasonic and infrared ray sensor
 * Side effect: The indicators can be received from outside
 */
indicators_t sensor_module::get_indicators(){
  return indicators;
}

/*
 * Description: Initialize the indicators, set all the value into 0
 * input: None
 * output: None
 * Side effect: The indicators in the sensor module will be initialized
 */
void sensor_module::init_indicators(){
  indicators.IR_mean = 0;
  indicators.US_mean = 0;
  indicators.IR_variance = 0;
  indicators.US_variance = 0;
}


