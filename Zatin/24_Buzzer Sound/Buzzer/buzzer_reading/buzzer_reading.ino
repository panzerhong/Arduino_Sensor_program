int sensor = 7; // The output of PIR sensor connected to pin 7
int sensor_value;// variable to hold read sensor value

void setup() {
  pinMode(sensor,INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  sensor_value = digitalRead(sensor);// Reading sensor value from pin 7
  Serial.println(sensor_value);// Printing output to serial monitor
}
