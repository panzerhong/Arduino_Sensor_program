int xPin = A1;     // digital pin are connected to switch output
int yPin = A0;     // analog pin connected to Y output
int buttonPin = 2;// digital pin 2 are connected to switch output

int xPosition = 0;
int yPosition = 0;
int buttonState = 0;

void setup() {
  // intitialize serial communications at 9600 bit per seconds:
  Serial.begin(9600);

  pinMode(xPin,INPUT);
  pinMode(xPin,INPUT);

  // activate pull-up resistor on the push-button pin
  pinMode(buttonPin,INPUT_PULLUP);
  // FOr versions prior to Arudino 1.0.1
  //pinMode(buttonPini,INPUT);
  //diitialWrite(buttonPin,HIGH);
}

void loop() {
  xPosition = analogRead(xPin);
  yPosition = analogRead(yPin);
  buttonState=digitalRead(buttonPin);

  Serial.print("X: ");Serial.println(xPosition);
  
  Serial.print("Y: ");Serial.println(yPosition);
  
  Serial.print(" | Button: "); Serial.println(buttonState);

  delay(1000);//add some delay between reads
  
  
}
