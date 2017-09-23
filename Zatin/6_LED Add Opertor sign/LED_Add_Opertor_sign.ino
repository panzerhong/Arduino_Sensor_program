void setup() {
  // put your setup code here, to run once:
  pinMode(3,OUTPUT);

  pinMode(6,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int i;
  //pinMode3
  for(i=0;i<=255;i++)
  {
    analogWrite(3,i);
    delayMicroseconds(500);
  }
  delay(100);
  for(i=255;i>=0;i--)
  {
    analogWrite(3,i);
    delayMicroseconds(500);
  }
  analogWrite(3,0);
  delay(100);
  
  // pinMode 6

  for(i=0;i<=255;i++)
  {
    analogWrite(6,i);
    delayMicroseconds(500);
  }
  delay(100);
  
  for(i=255;i>=0;i--)
  {
    analogWrite(6,i);
    delayMicroseconds(500);
  }
  analogWrite(6,0);
  delay(100);
}
