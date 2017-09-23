#define Grove_Water_Sensor A0// Attach Water sensor to Arduino pin 8
#define LED 9// Attach an LED to Digital Pin 13

void setup() {
  Serial.begin(9600);
  pinMode(Grove_Water_Sensor, INPUT);// The signal of water sensor is an input
  pinMode(LED,OUTPUT);// The LED is and OUTPUT
  digitalWrite(LED,LOW);
}

void loop() {
  /*the Water sensor will switch LOW when water is detected
  Get the arduino to illuminate the LED and activate the buzzer
  when water is detected , and switch both off when no water is present*/
  float ws = digitalRead(Grove_Water_Sensor);
  Serial.print("The value of reading the sensor is ");Serial.println(ws);

  if(ws == HIGH)
  {
    digitalWrite(LED,HIGH);
  }
  else
  {
    digitalWrite(LED,LOW);
  }
  delay(500);
}
