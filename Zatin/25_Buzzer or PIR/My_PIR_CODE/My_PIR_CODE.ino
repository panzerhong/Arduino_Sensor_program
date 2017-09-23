const int pirPin=2;
 int calibration = 10;// Give the time to calibrate the sensor
const int buzzerpin = 3;
const int led = 13;
void setup() {
  pinMode(pirPin,INPUT);
  Serial.begin(9600);
  Serial.println("Calibrate the sensor for 10 seconds");
  digitalWrite(pirPin,LOW);
  do
  {
    delay(1000);
    calibration--;
  }while(calibration>0);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("The sensor read : ");float readsensor = digitalRead(pirPin); Serial.println(readsensor);delay(1000);
  if(readsensor == 1)
  {
    tone(buzzerpin,4000);
    digitalWrite(led,HIGH);
  }
  else
  {
    noTone(buzzerpin);
    digitalWrite(led,LOW);
  }
}
