#include <wifi_connect.h>
/*
 * Discription: Connect the ESP-32 to the WiFi
 * Input: const char* ssid: WiFi name
 *        const char* password: WiFi password
 * Output: Print the WiFi condition and ESP-32's mac address
 * Side effect: The ESP-32 will connect to the WiFi
 */
void connect_wifi(const char* ssid, const char* password){
  WiFi.begin(ssid, password);
  Serial.println("Connecting");
  while(WiFi.status() != WL_CONNECTED) { 
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());
  Serial.print("ESP32 Mac Address : ");
  Serial.println(WiFi.macAddress());

}