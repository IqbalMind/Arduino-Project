// Komunikasi Serial 2 parser Integer

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  while (Serial.available() != 0) { // Baca data dari serial
  //int data = Serial.parseInt();
  float data = Serial.parseFloat();
    if(data != 0) {
     // kirim kembali ke port serial
     Serial.print("Bilangan: ");
     Serial.println(data);
     delay (20); //tunda sebelum pembaccan data selajutnya
    }
  }
}
