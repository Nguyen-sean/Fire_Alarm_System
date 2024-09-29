#include <Arduino.h>

void draw_Battery() {
  u8g2.drawXBM(102, 2, 24, 13, image_battery_empty_bits);
  if (Battery_check() > 10) {
    u8g2.drawLine(123, 4, 123, 12);
  }
  if (Battery_check() > 20) {
    u8g2.drawLine(121, 4, 121, 12);
  }
  if (Battery_check() > 30) {
    u8g2.drawLine(119, 4, 119, 12);
  }
  if (Battery_check() > 40) {
    u8g2.drawLine(117, 4, 117, 12);
  }
  if (Battery_check() > 50) {
    u8g2.drawLine(115, 4, 115, 12);
  }
  if (Battery_check() > 60) {
    u8g2.drawLine(113, 4, 113, 12);
  }
  if (Battery_check() > 70) {
    u8g2.drawLine(111, 4, 111, 12);
  }
  if (Battery_check() > 80) {
    u8g2.drawLine(109, 4, 109, 12);
  }
  if (Battery_check() > 90) {
    u8g2.drawLine(107, 4, 107, 12);
  }
  if (Battery_check() > 95) {
    u8g2.drawBox(103, 5, 3, 7);
  }
}

void draw_SOS(void) {
  u8g2.setFont(u8g2_font_t0_12b_me);
  if (myData.Zone_1 == 0) {
    u8g2.drawStr(17, 40, "1");
    u8g2.drawFrame(9, 30, 21, 12);
  } else {
    u8g2.drawXBM(12, 27, 16, 16, image_operation_warning_bits);
  }

  if (myData.Zone_2 == 0) {
    u8g2.drawStr(47, 40, "2");
    u8g2.drawFrame(39, 30, 21, 12);
  } else {
    u8g2.drawXBM(41, 27, 16, 16, image_operation_warning_bits);
  }

  if (myData.Zone_3 == 0) {
    u8g2.drawStr(77, 40, "3");
    u8g2.drawFrame(69, 30, 21, 12);
  } else {
    u8g2.drawXBM(71, 27, 16, 16, image_operation_warning_bits);
  }

  if (myData.Zone_4 == 0) {
    u8g2.drawStr(107, 40, "4");
    u8g2.drawFrame(99, 30, 21, 12);
  } else {
    u8g2.drawXBM(101, 27, 16, 16, image_operation_warning_bits);
  }

  if (myData.Zone_5 == LOW) {
    Serial.println(myData.Zone_5);
    u8g2.drawStr(17, 58, "5");
    u8g2.drawFrame(9, 48, 21, 12);
  } else {
    u8g2.drawXBM(11, 45, 16, 16, image_operation_warning_bits);
  }

  if (myData.Zone_6 == 0) {
    u8g2.drawStr(47, 58, "6");
    u8g2.drawFrame(39, 48, 21, 12);
  } else {
    u8g2.drawXBM(41, 45, 16, 16, image_operation_warning_bits);
  }

  if (myData.Zone_7 == 0) {
    u8g2.drawStr(77, 58, "7");
    u8g2.drawFrame(69, 48, 21, 12);
  } else {
    u8g2.drawXBM(71, 45, 16, 16, image_operation_warning_bits);
  }

  if (myData.Zone_8 == 0) {
    u8g2.drawStr(107, 58, "8");
    u8g2.drawFrame(99, 48, 21, 12);
  } else {
    u8g2.drawXBM(101, 45, 16, 16, image_operation_warning_bits);
  }

  u8g2.setFont(u8g_font_timR24);
  u8g2.drawStr(34, 24, "SOS");
  u8g2.drawLine(102, 16, 127, 16);
  u8g2.drawLine(0, 16, 25, 16);
}