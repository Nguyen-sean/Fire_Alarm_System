#include <Arduino.h>
#include <WiFi.h>        // ESP32 Wi-Fi library
#include <esp_now.h>     // ESP-NOW library for ESP32

#define Buzzel 21
#define Motor_1 20  
#define Motor_2 10

const int buttonPin = 0;

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

// #include "Function.h"
// #include "Display_save.h"
// #include "Display_function.h"

// Callback function that will be executed when data is received
void OnDataRecv(const uint8_t *mac_addr, const uint8_t *data, int data_len) {
  char macStr[18];
  snprintf(macStr, sizeof(macStr), "%02x:%02x:%02x:%02x:%02x:%02x",
           mac_addr[0], mac_addr[1], mac_addr[2], mac_addr[3], mac_addr[4], mac_addr[5]);
  memcpy(&myData, data, sizeof(myData));  // Copy data from incomingData to "myData"
}

void setup() {

  Serial.begin(115200);
  pinMode(Buzzel, OUTPUT);
  pinMode(Motor_1, OUTPUT);
  pinMode(Motor_2, OUTPUT);
  
  digitalWrite(Buzzel, LOW);
  digitalWrite(Motor_1, LOW);
  digitalWrite(Motor_2, LOW);

  // Set device as a Wi-Fi Station
  WiFi.mode(WIFI_STA);

  // Init ESP-NOW
  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }

  // Register for a callback function that gets executed when data is received
  esp_now_register_recv_cb(OnDataRecv);

  // u8g2.begin();
  // u8g2.setFontMode(1);
  // u8g2.setBitmapMode(1);
}

void loop() {
  static int currentPage = 1;

  // Update condition to check if all zones are not equal to 1
  if (myData.Zone_1 != 1 && myData.Zone_2 != 1 && myData.Zone_3 != 1 && myData.Zone_4 != 1 &&
      myData.Zone_5 != 1 && myData.Zone_6 != 1 && myData.Zone_7 != 1 && myData.Zone_8 != 1) {
    // Serial.println("okeee");
  }
Serial.print("Zone_1: ");
  Serial.print(myData.Zone_1 ? "YES" : "NO");
  Serial.print(" || Zone_2: ");
  Serial.print(myData.Zone_2 ? "YES" : "NO");
  Serial.print(" || Zone_3: ");
  Serial.print(myData.Zone_3 ? "YES" : "NO");
  Serial.print(" || Zone_4: ");
  Serial.print(myData.Zone_4 ? "YES" : "NO");
  Serial.print(" || Zone_5: ");
  Serial.print(myData.Zone_5 ? "YES" : "NO");
  Serial.print(" || Zone_6: ");
  Serial.print(myData.Zone_6 ? "YES" : "NO");
  Serial.print(" || Zone_7: ");
  Serial.print(myData.Zone_7 ? "YES" : "NO");
  Serial.print(" || Zone_8: ");
  Serial.println(myData.Zone_8 ? "YES" : "NO"); 
}
