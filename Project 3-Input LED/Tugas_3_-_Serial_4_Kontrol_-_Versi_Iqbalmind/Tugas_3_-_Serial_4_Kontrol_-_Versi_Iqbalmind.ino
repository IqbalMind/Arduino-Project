int const LED_KUNING1 = 4;
int const LED_HIJAU1 = 5;
int const LED_HIJAU2 = 6;
int const LED_HIJAU3 = 7;
int const LED_MERAH1 = 8;
int const LED_MERAH2 = 9;
int const LED_MERAH3 = 10;
int const LED_BIRU1 = 11;
int const LED_BIRU2 = 12;
int const LED_KUNING2 = 13;
                    
void setup() {
 // put your setup code here, to run once:
  pinMode (LED_HIJAU1,OUTPUT);
  pinMode (LED_HIJAU2,OUTPUT);
  pinMode (LED_HIJAU3,OUTPUT);
  pinMode (LED_KUNING1,OUTPUT);
  pinMode (LED_KUNING2,OUTPUT);
  pinMode (LED_MERAH1, OUTPUT);
  pinMode (LED_MERAH2, OUTPUT);
  pinMode (LED_MERAH3, OUTPUT);
  pinMode (LED_BIRU1, OUTPUT);
  pinMode (LED_BIRU2, OUTPUT);
  
 // Set Baud reate serial
  Serial.begin(9600);
}
void loop() {
  // put your main code here, to run repeatedly:
  boolean perintahFlag = true;
  String perintah="";
  //Baca di serial port
  while (Serial.available() != 0) {
    perintah = perintah + char (Serial.read ());
    delay(20); //tunda sebelum pembaccan data selajutnya
  }
  if (perintah.length() == 0) {
    return;
  }
  perintah.trim(); //hapus karakter whitespace
  if(perintah == "HIJAU1-ON") {
    digitalWrite(LED_HIJAU1,HIGH);
  }
  if(perintah == "HIJAU1-OFF") {
    digitalWrite(LED_HIJAU1,LOW);
  }
  if(perintah == "HIJAU2-ON") {
    digitalWrite(LED_HIJAU2,HIGH);
  }
  if(perintah == "HIJAU2-OFF") {
    digitalWrite(LED_HIJAU2,LOW);
  }
  if(perintah == "HIJAU3-ON") {
    digitalWrite(LED_HIJAU3,HIGH);
  }
  if(perintah == "HIJAU3-OFF") {
    digitalWrite(LED_HIJAU3,LOW);
  }
  if(perintah == "KUNING1-ON") {
     digitalWrite(LED_KUNING1,HIGH);
  }
  if(perintah == "KUNING1-OFF") {
    digitalWrite(LED_KUNING1,LOW);
  }
  if(perintah == "KUNING2-ON") {
     digitalWrite(LED_KUNING2,HIGH);
  }
  if(perintah == "KUNING2-OFF") {
    digitalWrite(LED_KUNING2,LOW);
  }
  if(perintah == "MERAH1-ON") {
     digitalWrite(LED_MERAH1,HIGH);
  }
  if(perintah == "MERAH1-OFF") {
     digitalWrite(LED_MERAH1,LOW);
  }
  if(perintah == "MERAH2-ON") {
     digitalWrite(LED_MERAH2,HIGH);
  }
  if(perintah == "MERAH2-OFF") {
     digitalWrite(LED_MERAH2,LOW);
  }
  if(perintah == "MERAH3-ON") {
     digitalWrite(LED_MERAH3,HIGH);
  }
  if(perintah == "MERAH3-OFF") {
     digitalWrite(LED_MERAH3,LOW);
  }
  if(perintah == "BIRU1-ON") {
     digitalWrite(LED_BIRU1,HIGH);
  }
  if(perintah == "BIRU1-OFF") {
     digitalWrite(LED_BIRU1,LOW);
  }
  if(perintah == "BIRU2-ON") {
     digitalWrite(LED_BIRU2,HIGH);
  }
  if(perintah == "BIRU2-OFF") {
     digitalWrite(LED_BIRU2,LOW);
  }
  if(perintah == "BIRU-ON") {
    digitalWrite(LED_BIRU1,HIGH);
    digitalWrite(LED_BIRU2,HIGH);
  }
  if(perintah == "BIRU-OFF") {
     digitalWrite(LED_BIRU1,LOW);
     digitalWrite(LED_BIRU2,LOW);
  }
}
