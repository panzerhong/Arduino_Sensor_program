const int dangerLed = 2;
const int safeLed = 3;
const int trig = 9;
const int echo = 8;
float duration , distance;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(dangerLed, OUTPUT);
  pinMode(safeLed,OUTPUT);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
}

void loop() {
  digitalWrite(trig,LOW);// Set the ultrasound to 0 before it act.
  delayMicroseconds(2);

  digitalWrite(trig,HIGH);// Emit or generate the ultrasound wave 10 Microsecond.
  delayMicroseconds(10);

  digitalWrite(trig,LOW);
  
  // For reading the time when the echoPin receive the ultrasound after it touch the object. This statement will return the duration inn Microsencond
  duration= pulseIn(echo,HIGH); 
  //calculate the distance in centemeter based on the speed of sound
  float distance =duration*0.034/2;
  if(distance >=20 )
  {
    digitalWrite(safeLed,HIGH);
    Serial.print("The Area is secure ");
    Serial.print(distance);Serial.println("cm");
  }
  else if(distance>=400|| distance<=2)
  {
    Serial.print("Distance = ");Serial.print(distance);
    Serial.println("Out of range");
  }
  else
  {
    digitalWrite(safeLed,LOW);
    Serial.print("There is something happened in the Area. Danger!!!");Serial.print(distance);Serial.println("cm");
    digitalWrite(dangerLed,HIGH);
    delay(500);
    digitalWrite(dangerLed,LOW);
    delay(300);
  }
  
}
