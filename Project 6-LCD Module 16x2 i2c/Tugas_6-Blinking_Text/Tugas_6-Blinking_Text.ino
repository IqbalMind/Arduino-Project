#include <LiquidCrystal_I2C.h> // Library for LCD
LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2); // Change to (0x27,16,2) for 16x2 LCD.
void setup() {
 lcd.init();
 lcd.backlight();
 lcd.print("Blinking text");
}
void loop() {
 lcd.display();
 delay(2000);
 lcd.noDisplay();
 delay(2000);
}
