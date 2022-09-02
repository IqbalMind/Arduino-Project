#define triger 4 //mendefinisikan trigger pada pin 4
#define echo 2 //mendeklarasikan echo pada pin 2
void setup() {
 Serial.begin(115200); //memulai serial
 pinMode (triger, OUTPUT); //trigger sebagai output
 pinMode (echo, INPUT); //echo sebagai input
}
void loop() {
 digitalWrite (triger, HIGH); //mengirim suara
 delayMicroseconds(10); //selama 10 mikro detik
 digitalWrite (triger, LOW); //berhenti mengirim suara
 float jarak = pulseIn(echo, HIGH); //membaca data dan di masukkan ke variabel jarak
 jarak=jarak/1000000; //konversi mikro detik ke detik
 jarak=jarak*330/2; //data mentah di ubah ke dalam meter
 jarak=jarak*100; //mengubah data ke dalam centi meter
 Serial.println(jarak); //menampilkan nilai jarak pada serial
 delay(500); //delay 500ms
}
