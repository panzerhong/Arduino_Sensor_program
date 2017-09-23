
int DO = 2; //Pin for Digital Output - DO
int DA = A0; // Pin for Analog Output - AO
int threshold = 58; //Set minimum threshold for LED lit
int sensorvalue = 0;
int led=11;


void setup() {
Serial.begin(9600);
pinMode(led, OUTPUT);
}

void loop() {
sensorvalue = analogRead(DA);
  Serial.print("Analog: ");
  Serial.print(sensorvalue);
  Serial.println(" ");
  Serial.print("Digital: ");
  Serial.println(digitalRead(DO));// Print the digital value

if (sensorvalue >= threshold)//Compare analog value with threshold
{
  digitalWrite(led,HIGH);
  delay(180000);
}

else
 digitalWrite(led, LOW );

}




