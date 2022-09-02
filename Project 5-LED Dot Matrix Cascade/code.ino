void setup() {
 // put your setup code here, to run once:
 //Led berjalan
 for (int i=4;i<=13;i++) {
   pinMode (i, OUTPUT);
   //set output awal
   digitalWrite(i,LOW);
 }
}
 
void loop() {
  // put your main code here, to run repeatedl y:
  // nyalakan LED satu demi satu
   for(int i=4;i<=13;i++) {
     digitalWrite(i,HIGH);
     delay (500);
     digitalWrite(i,LOW);
   }
 }
