int led = 3;
int photocellInput = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led,OUTPUT);
}

void loop() {
  photocellInput = (analogRead(photocellInput));
  Serial.println(photocellInput);
  delay(500);
  analogWrite(led,photocellInput);
}
