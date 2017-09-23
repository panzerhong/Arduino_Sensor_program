float sensorvalue = 0.00;
int DO = 2;// Pin for Digital Output -DO
int DA = A0;// Pin for Analog Output - A0
unsigned int led = 11;
/*It doesn't work because the the sensor is not sensitive unless we make the sound next to the sensor
*/
void setup() {
  Serial.begin(9600);
  pinMode(led,OUTPUT);
}

void loop() {
  sensorvalue = analogRead(DA);// Read the analog value
  
  Serial.print("The sensorsensorvalue of analogread DO is : ");Serial.println(sensorvalue);
  sensorvalue=sensorvalue-0;
  for(int i =0;i<sensorvalue;i++)
  {
    analogWrite(led,sensorvalue);
  }
}
