int inPin = A0;//
int led=13;
float sensorVal = 0;
boolean tf = true;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Serial Communication started...");
  pinMode(led,OUTPUT);
  digitalWrite(led,LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  sensorVal = analogRead(inPin);
  Serial.println(sensorVal);
  delay(500);
  while(sensorVal>10)
  {
    //Flame
    Serial.print("Flame");Serial.println(sensorVal);
    digitalWrite(led,HIGH);
    delay(700);
    digitalWrite(led,LOW);
    delay(500);
    sensorVal=analogRead(inPin);
  }
  digitalWrite(led,LOW);
}
