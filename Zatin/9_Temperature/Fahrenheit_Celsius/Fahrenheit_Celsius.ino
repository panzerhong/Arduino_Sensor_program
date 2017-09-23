// Setup displays temperature inn Farenheit and Celsius using LM35 heat detection sencsor
const int inPin =0;
void setup() {
  // put your setup code here, to run once:

Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int value = analogRead(inPin); // VALUE OF THE CURRENT
  Serial.print(value); Serial.print(">");
  float millivolts = (value/1024.0)*5000;
  float celsius = millivolts /10;// Sensor output is 10 mV per degree Celsius
  Serial.print(celsius);
  Serial.print("degree Celsius");
  Serial.print((celsius*9)/5+32);// convert to fahrenheit
  Serial.println("degree Fahrenheit\n");
  delay(1000);
}
