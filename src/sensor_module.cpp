#include <sensor_module.h>

/*
 * Discription: Get one distance from the infrared ray sensor
 * Input: None
 * Output: float dist: the distance from infrared ray sensor
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

void sensor_module::fill_queue(){
    US_queue.push(ultrasonic());
    IR_queue.push(infrared());
}

void sensor_module::get_indicator(priority_queue<float> *q, float *mean, float *variance){
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

void sensor_module::calculate_indicators(){
  init_indicators();
  get_indicator(&US_queue, &indicators.US_mean, &indicators.US_variance);
  get_indicator(&IR_queue, &indicators.IR_mean, &indicators.IR_variance);
}

indicators_t sensor_module::get_indicators(){
  return indicators;
}

/*
 * Description: Initialize the indicators, set all the value into 0
 * input: None
 * output: None
 * Side effect: the indicators in the sensor module will be initialized
 */
void sensor_module::init_indicators(){
  indicators.IR_mean = 0;
  indicators.US_mean = 0;
  indicators.IR_variance = 0;
  indicators.US_variance = 0;
}


