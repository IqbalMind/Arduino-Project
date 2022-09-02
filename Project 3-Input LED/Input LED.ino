const int PIN_7=7;
const int PIN_12 = 12;
boolean ledMenyala = false;

void setup() {
 // put your setup code here, to run once:
  pinMode (PIN_7, INPUT);
  pinMode (PIN_12, OUTPUT);
}

void loop() {
 // put your main code here, to run repeatedly:
  int TombolSaklar = digitalRead(PIN_7);
  if( TombolSaklar == HIGH) {
    ledMenyala = not ledMenyala;
    if(ledMenyala) {
      digitalWrite(PIN_12,HIGH);
    }
    else {
      digitalWrite(PIN_12,LOW);
    }
  }
}
