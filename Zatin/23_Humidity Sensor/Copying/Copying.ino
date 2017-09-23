float adcValue = 0;
float voltage = 0;
float percentRH = 0;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  adcValue = analogRead(0);
  voltage = (adcValue/1023)*5;
  percentRH = (voltage-0.958)/0.0307;

  Serial.print("%RH ");
  Serial.println(percentRH,DEC);

  delay(1000);
}

