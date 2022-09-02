#include <LiquidCrystal_I2C.h>
#include "DHT.h"
//Modified by Muhamad Iqbal Nurmanditya
#define DHTPIN 2 // what digital pin we're connected to
#define DHTTYPE DHT22 // DHT 22 (AM2302), AM2321
#define triger 6
#define echo 4

LiquidCrystal_I2C lcd(0x27, 16, 2);
DHT dht(DHTPIN, DHTTYPE);
void setup() {
   lcd.init();
   lcd.backlight();
   dht.begin();
   lcd.print("Jarak, Suhu"); //Greeting
   lcd.setCursor(0,1);
   lcd.print("& Kelembaban");
   delay(2000);
   lcd.clear();
  pinMode (triger, OUTPUT); //trigger sebagai output
  pinMode (echo, INPUT); //echo sebagai input
  lcd.setCursor(0,0);
  lcd.print ("Suhu ");
  lcd.setCursor(12,0);
  lcd.print("C");
  lcd.setCursor(0,1);
  lcd.print("K:");
  lcd.setCursor(9,1);
  lcd.print ("J: ");
  lcd.setCursor(14,1);
  lcd.print("cm");
}
void loop() {
  //delay (1000);
  digitalWrite (triger, HIGH); //mengirim suara
  delayMicroseconds(10); //selama 10 mikro detik
  digitalWrite (triger, LOW); //berhenti mengirim suara
  
  float jarak = pulseIn(echo, HIGH); //membaca data dan di
  jarak=jarak/1000000; //konversi mikro detik ke detik
  jarak=jarak*330/2; //data mentah di ubah ke dalam meter
  jarak=jarak*100; //menguba data ke dalam centi meter
  
  //cd.clear();
  lcd.setCursor(5,0);
  lcd.print("     ");
  lcd.setCursor(5,0);
  lcd.print(getTemp( "c"));

  lcd.setCursor(2,1);
  lcd.print(getTemp( "h"));
  lcd.print("%");
  lcd.setCursor(11,1);
  lcd.print(jarak);
  
  delay (500);
}
float getTemp(String req)
{
 // Reading temperature or humidity takes about 250 milliseconds!
 // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
 float h = dht.readHumidity();
 // Read temperature as Celsius (the default)
 float t = dht.readTemperature();
 // Read temperature as Fahrenheit (isFahrenheit = true)
 float f = dht.readTemperature(true);
 
 // Compute heat index in Fahrenheit (the default)
 float hif = dht.computeHeatIndex(f, h);
 // Compute heat index in Celsius (isFahreheit = false)
 float hic = dht.computeHeatIndex(t, h, false);
 // Check if any reads failed and exit early (to try again).
 if (isnan(h) || isnan(t) || isnan(f)) {
 //Serial.println("Failed to read from DHT sensor!");
 return -273;
 }
 // Compute heat index in Kelvin
 float k = t + 273.15;
 if(req =="c"){
 return t;//return Cilsus
 }else if(req =="f"){
 return f;// return Fahrenheit
 }else if(req =="h"){
 return h;// return humidity
 }else if(req =="hif"){
 return hif;// return heat index in Fahrenheit
 }else if(req =="hic"){
 return hic;// return heat index in Cilsus
 }else if(req =="k"){
 return k;// return temprature in Kelvin
 }else{
 return 0.000;// if no reqest found, retun 0.000
 }
}
