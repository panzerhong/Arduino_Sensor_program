int ledPin = 3;
float valuereadphotocellInput =0.00;
int photopin = 0;
void setup() {
  pinMode(ledPin,OUTPUT);
  Serial.begin (9600);
}

void loop() {
 
  valuereadphotocellInput = (analogRead(photopin)); // divides input 0-1023
  Serial.println(valuereadphotocellInput);
  delay(500);
  if(valuereadphotocellInput >0&&valuereadphotocellInput<20)
  {
    analogWrite(ledPin,255);
  }
  else
  digitalWrite(ledPin,0);
  delay(20);
  //analogWrite(ledPin,photocellInput);
  // The delay can be chage to get the desired dimming effect
  
}
