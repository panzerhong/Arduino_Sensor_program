#define redpin 11 // RED
#define greenpin 10 // GREEN
#define bluepin 6 // BLUE
void setup() {
  // put your setup code here, to run once:
  pinMode(redpin,OUTPUT);
  pinMode(greenpin,OUTPUT);
  pinMode(greenpin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  //RED
  analogWrite(redpin,255);
  analogWrite(greenpin,0);
  analogWrite(bluepin,0);
   delay(1000);
//  BLUE
  analogWrite(redpin,0);
  analogWrite(greenpin,0);
  analogWrite(bluepin,255);
   delay(1000);
  //GREEN
  analogWrite(redpin,0);
  analogWrite(greenpin,255);
  analogWrite(bluepin,0);
  delay(1000);
}
