const int sensorpin = 0;
 int bluepin = 11;
 int redpin = 10;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(bluepin,OUTPUT);
  pinMode(redpin,OUTPUT);
  pinMode(sensorpin,INPUT);
 
}
void loop() {
  // put your main code here, to run repeatedly:
  float value = analogRead(sensorpin);
  Serial.print("The analogRead value is ");Serial.print(value);Serial.print("--");
  float millivolts = (value/1024)*5000;
  float celcius = millivolts/10;
  Serial.print("Temperature in Celcius : ");Serial.print(celcius);
  Serial.print("\n");
  delay(555);
  if(celcius>27.5)
  {
      while(celcius >=27.50)
      {
        digitalWrite(bluepin,LOW);
        float value = analogRead(sensorpin);
         Serial.print("The analogRead value is ");Serial.print(value);Serial.print("--");
        float millivolts = (value/1024)*5000;
        float celcius = millivolts/10;
        Serial.print("Temperature in Celcius : ");Serial.print(celcius); Serial.print("Danger!!!!!!!!!");
        Serial.print("\n");
        delay(555);
  
        for(int i=0;i<=255;i++)
        {
          analogWrite(redpin,i);
          delay(2);
        }
        delay(5);
        for(int i=255;i>=0;i++)
        {
          analogWrite(redpin,i);
          delay(2);
        }
         delay(5);
      }
}

 digitalWrite(redpin,LOW);
  digitalWrite(bluepin,HIGH);
}

