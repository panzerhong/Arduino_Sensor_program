
void setup() {
  // put your setup code here, to run once:
  pinMode(2,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(9,OUTPUT);
}

void loop() {
  int i;
  // put your main code here, to run repeatedly:

  digitalWrite(2,HIGH);
  delay(5000);
  digitalWrite(2,LOW);
 
  for(i=0;i<4;i++)
  {
    digitalWrite(5,HIGH);
    delay(500);
    digitalWrite(5,LOW);
    delay(500);
  }

  digitalWrite(9,HIGH);
  delay(5000);
  digitalWrite(9,LOW);

  for(i=0;i<4;i++)
  {
    digitalWrite(5,HIGH);
    delay(500);
    digitalWrite(5,LOW);
    delay(500);
  }
}
