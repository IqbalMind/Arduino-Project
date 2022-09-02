// Serial komunikasi komputer - arduino
void setup() {
 //put your setup code here, to run once:
 //Set kecepatan transmisi port serial (bit per second)
 Serial.begin(9600);
}
void loop() {
 // put your main code here, to run repeatedly:
 while (Serial.available() != 0) {
  char data =Serial.read(); // terima data dari port serial
   //Kirim kembali data ke port serial
  Serial.print ( "Karakter: ");
  Serial.println (data);
  delay (20);
 }
}
