#include "LedControl.h"
LedControl lc=LedControl(12,11,10,2); // Pins: DIN,CLK,CS, # of Display connected
unsigned long delayTime=200; // Delay between Frames
// Put values in arrays
byte hurufA[] = {0x3C,0x24,0x24,0x7E,0x62,0x62,0x62,0x00};
byte hurufB[] = {0x7C,0x24,0x24,0x3E,0x32,0x32,0x7E,0x00};
byte hurufC[] =
{
 B00111110, // First frame of invader #1
 B00100010,
 B00100000,
 B01100000,
 B01100000,
 B01100010,
 B01111110,
 B00000000
};
void setup()
{
 lc.shutdown(0,false); // Wake up displays
 lc.setIntensity(0,2); // Set intensity levels
 lc.clearDisplay(0); // Clear Displays
}

// Take values in Arrays and Display them
void A()
{
 for (int i = 0; i < 8; i++)
 {
 lc.setRow(0,i,hurufA[i]);
 }
}
void B()
{
 for (int i = 0; i < 8; i++)
 {
 lc.setRow(0,i,hurufB[i]);
 }
}
void C()
{
 for (int i = 0; i < 8; i++)
 {
 lc.setRow(0,i,hurufC[i]);
 }
}
void loop()
{
// Put #1 frame on both Display
 A();
 delay(1000);
 //lc.clearDisplay(0);
 B();
 delay(1000);
 C();
 delay(1000);

}
