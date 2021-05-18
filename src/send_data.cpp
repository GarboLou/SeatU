#include <send_data.h>
#include <time.h>
/*
 * Discription: Send the data to the sever(PHP file)
 * Input: const char* serverName: Our sever name (It's a PHP web address)
 *        Device* device: Device class object
 * Output: None
 * Side effect: The data will be sent to the sever, then the sever can put the data 
 *              into the database for later use
 */
void send_data(const char* serverName, indicators_t* indicator){
  //Check WiFi connection status
  if(WiFi.status()== WL_CONNECTED){
    HTTPClient http;
    // Your Domain name with URL path or IP address with path
    http.begin(serverName);
    // Specify content-type header
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");
    String httpRequestData = "DeviceID="+String(indicator->ID)+"&TableID="+String(TABLE_ID)+"&US_Mean=" + String(indicator->US_mean)+"&IR_Mean="+String(indicator->IR_mean)
                        + "&US_Var=" + String(indicator->US_variance) + "&IR_Var=" + String(indicator->IR_variance) + "";
    Serial.print("httpRequestData: ");
    Serial.println(httpRequestData);
    // Send HTTP POST request
    int httpResponseCode = http.POST(httpRequestData);
    if (httpResponseCode>0) {
      Serial.print("HTTP Response code: ");
      Serial.println(httpResponseCode);
    }
    else {
      Serial.print("Error code: ");
      Serial.println(httpResponseCode);
    }
    http.end();
  }

  else {
    Serial.println("WiFi Disconnected");
  }
}

/*
 * Discription: This function is only used for the WiFi module test.
 * It will send n packet to the sever. 
 * Input: none
 * Output: Print the WiFi condition and ESP-32's mac address
 * Side effect: The ESP-32 will connect to the WiFi
 */
void speed_test(const char* serverName){
  clock_t start,finish;
  double totaltime;
  if(WiFi.status()== WL_CONNECTED){
    HTTPClient http;
    // Your Domain name with URL path or IP address with path
    http.begin(serverName);
    // Specify content-type header
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");
    String httpRequestData = "1234567890";
    for (int i =0; i <15;i++){
      httpRequestData = httpRequestData + httpRequestData;
    }
    
    Serial.print("httpRequestData string size: ");
    Serial.println(httpRequestData.length());
    
    // Send HTTP POST request
    start=clock();
    int httpResponseCode = http.POST(httpRequestData);
    finish=clock();
    if (httpResponseCode>0) {
      Serial.print("HTTP Response code: ");
      Serial.println(httpResponseCode);
      totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
      Serial.print("Sent n data spend: ");
      Serial.println(totaltime);
    }
    else {
      Serial.print("Error code: ");
      Serial.println(httpResponseCode);
    }
    http.end();
  }
  else {
    Serial.println("WiFi Disconnected");
  }
    
}