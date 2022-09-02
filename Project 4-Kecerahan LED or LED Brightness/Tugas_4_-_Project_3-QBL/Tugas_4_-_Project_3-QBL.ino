#include "LedControl.h"
LedControl lc=LedControl(12,11,10,2); // Pins: DIN,CLK,CS, # of Display connected
unsigned long delayTime=200; // Delay between Frames
// Put values in arrays
byte hurufQ[] = {0x00,0x3c,0x42,0x42,0x52,0x4a,0x44,0x3a};
byte hurufB[] = {0x00,0x78,0x44,0x44,0x78,0x44,0x44,0x7c};
byte hurufL[] = {0x00,0x40,0x40,0x40,0x40,0x40,0x40,0x7c};
void setup()
{
 lc.shutdown(0,false); // Wake up displays
 lc.setIntensity(0,2); // Set intensity levels
 lc.clearDisplay(0); // Clear Displays
}

// Take values in Arrays and Display them
void Q()
{
 for (int i = 0; i < 8; i++)
 {
 lc.setRow(0,i,hurufQ[i]);
 }
}
void B()
{
 for (int i = 0; i < 8; i++)
 {
 lc.setRow(0,i,hurufB[i]);
 }
}
void L()
{
 for (int i = 0; i < 8; i++)
 {
 lc.setRow(0,i,hurufL[i]);
 }
}
void loop()
{
// Put #1 frame on both Display
 Q();
 delay(1000);
 //lc.clearDisplay(0);
 B();
 delay(1000);
 L();
 delay(1000);

}
