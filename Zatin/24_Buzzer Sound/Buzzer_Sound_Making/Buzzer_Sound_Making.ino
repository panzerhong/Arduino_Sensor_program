const int buzzer=9;// buzzer + to arduino pin9

void setup() {
  // put your setup code here, to run once:
  pinMode(buzzer,OUTPUT);//set buzzer - pin 9 as an output
}

void loop() {
   //put your main code here, to run repeatedly:
 // tone(buzzer,65535 );// Send 1 KHz sound signal
  delay(1000);// for 1 sec
  noTone(buzzer); // stop sound...
  delay(1000);
  for(int i =0;i< 4000 ;i++)
  {
    tone(buzzer,i);
  }
  for(int i=4000;i>0;i--)
  {
    tone(buzzer,i); 
  }
  /*tone (buzzerPin,frequency,millisecond */
  tone(buzzer, 1000, 500);
}
