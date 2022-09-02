 const int PIN_10 = 10;

void setup() {
 // put your setup code here, to run once:
  pinMode (PIN_10,OUTPUT);
  analogWrite(PIN_10,0);
}

void loop() {
  //Kecerahan dinaikan
 // put your main code here, to run repeatedly:
  for(int i=0;i<256;i +=2){
     analogWrite(PIN_10,i);
     delay(100);
  }
     delay (2000) ;
  //Kecerahan diturunkan
  for(int i=255;i<-1;i -=2) {
     analogWrite(PIN_10,1);
     delay(100);
 }
}
