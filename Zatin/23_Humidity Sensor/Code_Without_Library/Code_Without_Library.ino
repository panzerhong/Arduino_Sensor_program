
    // Simple sketch to demonstrate the HIH-4030 Humidity Sensor from SparkFun
// Outputs %RH based on voltage coming from sensor
// Written 01/28/11

float adcValue = 0;
float voltage = 0;
float percentRH = 0;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  adcValue = analogRead(0); // Read voltage coming from sensor (adcValue will be between 0-1023)
  voltage = (adcValue/1023.0)*5.0; // Translate ADC value into a voltage value
  percentRH = (voltage-0.958)/0.0307; // Translate voltage into percent relative humidity
  
  // Print value
  Serial.print("%RH = ");
  Serial.println(percentRH,DEC); 
  
  // Delay for one second
  delay(1000);
}
