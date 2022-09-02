#include "LedControl.h"
LedControl lc=LedControl(7,6,5, 1); // urutannya > DIN, CLK, CS, NRDEV
//waktu tunggu yang dideklarasikan di variabel global
unsigned long waktutunggu = 50;
int col;
int row;
int address;
void setup() {
 // jumlah perangkat yang telah dirangkai antara arduino dengan dot matrix
 int devices=lc.getDeviceCount();
 // Inisialisasi semua perangkat (didalam void loop)
 for(int address=0;address<devices;address++) {
 // IC MAX72XX berada dalam mode sleep saat startup
 lc.shutdown(address,false);
 // Atur kecerahan ke tingkat menengah.
 lc.setIntensity(address,1);
 // Kosongkan data di dotmatrix (clear display).
 lc.clearDisplay(address);
 }
}
void loop() {
 // Baca jumlah perangkat
 int devices=lc.getDeviceCount();

 // perulangan pertama untuk pengisian data 1 persatu - satu
 for(row=00;row<8;row++) {
 for(col=00;col<8;col++) {
 for(address=00;address<devices;address++) {
 lc.setLed(address,row,col,true);
 delay(waktutunggu);
 }
 }
 }
 // perulangan pertama untuk pengosongan data 1 persatu - satu
 for(row=00;row<8;row++) {
 for(col=00;col<8;col++) {
 for(address=0;address<devices;address++) {
 lc.setLed(address,row,col,false);
 delay(waktutunggu);
 }
 }
 }
}
