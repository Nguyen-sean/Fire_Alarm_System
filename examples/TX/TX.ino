#define time_delay(t) for (static uint32_t _lasttime; \
                           (uint32_t)((uint32_t)millis() - _lasttime) >= (t); \
                           _lasttime = millis())

#include <Arduino.h>
#include <Wire.h>
#include <WiFi.h>         // ESP32 Wi-Fi library
#include <esp_now.h>      // ESP-NOW library for ESP32
// #include "Display_save.h"
// #include "Display_function.h"

const uint8_t numBytes = 8;  // Size of array
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

// Broadcast address (example MAC address for peer)
uint8_t broadcastAddress[] = { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF };

// Callback function when data is sent
void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t sendStatus) {
  Serial.print("Last Packet Send Status: ");
  if (sendStatus == ESP_NOW_SEND_SUCCESS) {
    Serial.println("Delivery success");
  } else {
    Serial.println("Delivery fail");
  }
}

void setup() {

  Serial.begin(115200);
  Wire.begin(20,21);
  WiFi.mode(WIFI_STA);

  // Initialize ESP-NOW
  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }

  // Register for send callback function
  esp_now_register_send_cb(OnDataSent);

  // Register peer
  esp_now_peer_info_t peerInfo = {};
  memcpy(peerInfo.peer_addr, broadcastAddress, 6);  // Set peer MAC address
  peerInfo.channel = 1;                            // Set channel (match with your receiver)
  peerInfo.encrypt = false;                        // Set encryption to false

  // Add peer
  if (esp_now_add_peer(&peerInfo) != ESP_OK) {
    Serial.println("Failed to add peer");
    return;
  }
}

void loop() {
  // Use the time_delay macro to run this block every 500ms
  time_delay(500) {
    Wire.requestFrom(channel, numBytes);  // Request data from the I2C slave device
    while (Wire.available()) {            // Slave may send less than requested
      for (int i = 0; i < numBytes; i++) {
        receivedData[i] = Wire.read();    // Read byte from I2C slave
        Serial.print(receivedData[i]);    // Print received data
      }
      Serial.println();
    }

    // Map received data to struct fields
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
