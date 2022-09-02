#include <LiquidCrystal_I2C.h>
#include "DHT.h"
#define DHTPIN 2 // what digital pin we're connected to
#define DHTTYPE DHT22 // DHT 22 (AM2302), AM2321
LiquidCrystal_I2C lcd(0x27, 16, 2);
DHT dht(DHTPIN, DHTTYPE);
void setup() {
 lcd.init();
 lcd.backlight();
 dht.begin();
 lcd.print("Suhu & Kelembaban"); //Greeting
 delay(2000);
 lcd.clear();
}
void loop() {
 delay(2000);
 lcd.clear();
 lcd.print("Suhu ");
 lcd.print(getTemp("c"));
 lcd.print("C");
 lcd.setCursor(0,1);
 lcd.print("Kelembaban ");

 lcd.print(getTemp("h"));
 lcd.print(" %");
 //lcd.setCursor(0,3);
 //lcd.print("Baris Ke 3");
 delay(2000);
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
 return;
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
