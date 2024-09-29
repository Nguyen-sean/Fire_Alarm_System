#include <Wire.h>
#include <U8g2lib.h>

U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/U8X8_PIN_NONE);

static const unsigned char image_battery_empty_bits[] = {0xf0,0xff,0x7f,0x08,0x00,0x80,0x08,0x00,0x80,0x0e,0x00,0x80,0x01,0x00,0x80,0x01,0x00,0x80,0x01,0x00,0x80,0x01,0x00,0x80,0x01,0x00,0x80,0x0e,0x00,0x80,0x08,0x00,0x80,0x08,0x00,0x80,0xf0,0xff,0x7f};
u8g2.setFontMode(1);
u8g2.setBitmapMode(1);
void draw(void) {
    u8g2.drawXBM(102, 2, 24, 13, image_battery_empty_bits);
    u8g2.drawLine(123, 4, 123, 12);
    u8g2.drawLine(121, 4, 121, 12);
    u8g2.drawLine(119, 4, 119, 12);
    u8g2.drawLine(117, 4, 117, 12);
    u8g2.drawLine(115, 4, 115, 12);
    u8g2.drawLine(113, 4, 113, 12);
    u8g2.drawLine(111, 4, 111, 12);
    u8g2.drawLine(109, 4, 109, 12);
    u8g2.drawLine(107, 4, 107, 12);
    u8g2.drawBox(103, 5, 3, 7);
}