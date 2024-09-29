#include <Arduino.h>


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
  u8g2.drawLine(102, 13, 127, 13);
  u8g2.drawLine(0, 13, 25, 13);
}