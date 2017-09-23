int soundSensor = 5;
int LED =3;
float statusSensor = 0;
void setup()
{
  pinMode(soundSensor,INPUT);
  pinMode(LED,OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  statusSensor = analogRead(soundSensor);
  Serial.println(statusSensor);
  delay(500);
  if(statusSensor == 1)
  {
    digitalWrite(LED,HIGH);
  }
  else
  {
    digitalWrite(LED,LOW);
  }
}

