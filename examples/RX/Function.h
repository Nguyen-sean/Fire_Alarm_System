#include <Arduino.h>
// -------------------Check_Battery_level--------------------
#define V_MAX 4.2
#define V_MIN 3.6
int Battery_check() {
  return constrain(map(analogRead(Pin_BAT), (1024 / 5) * V_MIN, (1024 / 5) * V_MAX, 0, 100), 0, 100);
}
// Constrain: hàm giới hạn 
// Map: Hàm chuyển đổi tín hiệu
