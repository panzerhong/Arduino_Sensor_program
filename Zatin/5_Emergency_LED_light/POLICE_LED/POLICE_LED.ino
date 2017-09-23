int a = 3;
int b=9;

void setup() {
  // put your setup code here, to run once:
  pinMode(a,OUTPUT);
  pinMode(b,OUTPUT);
}

void loop() {
  int i;
  int j=60;
  // put your main code here, to run repeatedly:

  //pin 3
  for(int i=0;i<=300;i++)
  {
    analogWrite(a,i);
    delay(1);
  }
  for(i=300;i>=0;i--)
  {
    analogWrite(a,i);
    delayMicroseconds(100);
  }

  // PIN 9
  for(i=0;i<=300;i++)
   {
      analogWrite(b,i);
      delay(1);
   }
     for(i=300;i>=0;i--)
  {
    analogWrite(b,i);
    delayMicroseconds(100);
  }
 
