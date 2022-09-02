#include "LedControl.h"
LedControl lc=LedControl(7,6,5,2); // Pins: DIN,CLK,CS, # of Display connected
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
 lc.setIntensity(0,1); // Set intensity levels
 lc.clearDisplay(0); // Clear Displays
 //device ke 2
 lc.shutdown(1,false); // Wake up displays
 lc.setIntensity(1,1); // Set intensity levels
 lc.clearDisplay(1); // Clear Displays
}

// Take values in Arrays and Display them
void A(int dev)
{
 for (int i = 0; i < 8; i++)
 {
 lc.setRow(dev,i,hurufA[i]);
 }
}
void B(int dev)
{
 for (int i = 0; i < 8; i++)
 {
 lc.setRow(dev,i,hurufB[i]);
 }
}
void C(int dev)
{
 for (int i = 0; i < 8; i++)
 {
 lc.setRow(dev,i,hurufC[i]);
 }
}
void loop()
{
// Put #1 frame on both Display
 A(0);
 delay(1000);
// lc.clearDisplay(0);
 A(1);
 B(0);
 delay(1000);
 B(1);
 C(0);
 delay(1000);
}
