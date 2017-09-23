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
  while(celcius >=27.50)
  {
    digitalWrite(redpin,HIGH);
    delay(1000);
    digitalWrite(redpin,LOW);
    digitalWrite(bluepin,LOW);

     float value = analogRead(sensorpin);
     Serial.print("The analogRead value is ");Serial.print(value);Serial.print("--");
    float millivolts = (value/1024)*5000;
    float celcius = millivolts/10;
    Serial.print("Temperature in Celcius : ");Serial.print(celcius);
    Serial.print("\n");
    delay(555);
  }
  digitalWrite(redpin,0);
    digitalWrite(bluepin,HIGH);
}
