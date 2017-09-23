void setup() {
  Serial.begin (9600);  // Open USB port
}

void loop() {
  // put your main code here, to run repeatedly:
  float temp = 0;
  temp = (5.0*analogRead(0) *100.0) / 1024 ;/*Equation to approximately convert analog reading into actual Temperature*/
  Serial.println(temp); //Print temp to serial monitor
}
