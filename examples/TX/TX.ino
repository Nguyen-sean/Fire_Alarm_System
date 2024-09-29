#define time_delay(t) for (static uint32_t _lasttime; \
                           (uint32_t)((uint32_t)millis() - _lasttime) >= (t); \
                           _lasttime = millis())
// #include <Arduino.h>
#include <Wire.h>
const uint8_t numBytes = 8;  // Giá trị của mảng
const uint8_t channel = 8;
byte receivedData[numBytes];

typedef struct struct_message {
  bool Zone_1;
  bool Zone_2;
  bool Zone_3;
  bool Zone_4;
  bool Zone_5;
  bool Zone_6;
  bool Zone_7;
  bool Zone_8;
} struct_message;
struct_message myData;

#include <ESP8266WiFi.h>
#include "ESPnow.h"
#include "Display_save.h"
#include "Display_function.h"



unsigned long lastTime = 0;
unsigned long timerDelay = 1000;  // send readings timer

void setup() {

  Serial.begin(115200);
  Wire.begin();
  WiFi.mode(WIFI_STA);
    if (esp_now_init() != 0) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }

  // Once ESPNow is successfully Init, we will register for Send CB to
  // get the status of Trasnmitted packet
  esp_now_set_self_role(ESP_NOW_ROLE_CONTROLLER);
  esp_now_register_send_cb(OnDataSent);
  
  // Register peer
  esp_now_add_peer(broadcastAddress, ESP_NOW_ROLE_SLAVE, 1, NULL, 0);
}

void loop() {
  time_delay(500) {
    Wire.requestFrom(channel, numBytes);
    while (Wire.available()) {  // slave may send less than requested
      for (int i = 0; i < numBytes; i++) {
        receivedData[i] = Wire.read();
        Serial.print(receivedData[i]);
      }
      Serial.println();
    }


    myData.Zone_1 = bool(receivedData[0]);
    myData.Zone_2 = bool(receivedData[1]);
    myData.Zone_3 = bool(receivedData[2]);
    myData.Zone_4 = bool(receivedData[3]);
    myData.Zone_5 = bool(receivedData[4]);
    myData.Zone_6 = bool(receivedData[5]);
    myData.Zone_7 = bool(receivedData[6]);
    myData.Zone_8 = bool(receivedData[7]);

    // Send message via ESP-NOW
    esp_now_send(broadcastAddress, (uint8_t *)&myData, sizeof(myData));
  }
}
