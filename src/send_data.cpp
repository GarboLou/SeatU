#include <send_data.h>
/*
 * Discription: Send the data to the sever(PHP file)
 * Input: const char* serverName: Our sever name (It's a PHP web address)
 *        Device* device: Device class object
 * Output: None
 * Side effect: The data will be sent to the sever, then the sever can put the data 
 *              into the database for later use
 */
void send_data(const char* serverName, Device* device){
  //Check WiFi connection status
  if(WiFi.status()== WL_CONNECTED){
    HTTPClient http;
    // Your Domain name with URL path or IP address with path
    http.begin(serverName);
    // Specify content-type header
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");
    indicators_t indicator = device->get_indicator(0);
    String httpRequestData = "DeviceID=1&TableID=1&US_Mean=" + String(indicator.US_mean)+"&IR_Mean="+String(indicator.IR_mean)
                        + "&US_Var=" + String(indicator.US_variance) + "&IR_Var=" + String(indicator.IR_variance) + "";
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