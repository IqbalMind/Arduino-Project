const int PIN_MERAH=12;
const int PIN_KUNING=11;
const int PIN_HIJAU =10;

const int TUNDA_MERAH= 8000;
const int TUNDA_KUNING = 1000;
const int TUNDA_HIJAU = 3000;

void setup() {
 // put your setup code here, to run once:
  pinMode (PIN_MERAH, OUTPUT);
  pinMode (PIN_KUNING,OUTPUT);
  pinMode (PIN_HIJAU,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(PIN_HIJAU,HIGH);
  delay (TUNDA_HIJAU);
  //Hijau kita matikan
  digitalWrite(PIN_HIJAU, LOW);
  
  digitalWrite(PIN_KUNING, HIGH);
  delay (TUNDA_KUNING);
  
  //Kuning kita matikan
  digitalWrite(PIN_KUNING,LOW);

  digitalWrite(PIN_MERAH, HIGH);
  delay (TUNDA_MERAH);
  
  //Merah kita matikan
  digitalWrite(PIN_MERAH,LOW);

}
