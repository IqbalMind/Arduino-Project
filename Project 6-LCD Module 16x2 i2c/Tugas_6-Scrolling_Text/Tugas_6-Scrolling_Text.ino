#include <LiquidCrystal_I2C.h> // Library for LCD
// Wiring: SDA pin is connected to A4 and SCL pin to A5.
// Connect to LCD via I2C, default address 0x27 (A0-A2 not jumpered)
LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2); // Change to (0x27,16,2) for 16x2 LCD.
void setup() {
 lcd.init();
 lcd.backlight();
}
void loop() {
 lcd.autoscroll();
 lcd.setCursor(20, 0);
 for (int x = 0; x < 14; x++) {
 lcd.print(x);
 delay(500);
 }
 lcd.clear();
}
