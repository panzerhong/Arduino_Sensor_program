int xPin = A1;     // digital pin are connected to switch output
int yPin = A0;     // analog pin connected to Y output
int buttonPin = 2;// digital pin 2 are connected to switch output
int i=0; // intialize time
int xPosition = 0;
int yPosition = 0;
int buttonState = 0;
int servoposition = 0;// variable to store the servo position

#include <Servo.h>
Servo myservo;// create servo object to control a servo, // twelve servo objects can be created on most boards

void setup() {
  myservo.attach(9);// atttach the signal servo pin to pin 9 of the arduino
  
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
  startagain:
  xPosition = analogRead(xPin);
  yPosition = analogRead(yPin);
  buttonState=digitalRead(buttonPin);

  Serial.print("X: ");Serial.println(xPosition);
  
  Serial.print("Y: ");Serial.println(yPosition);
  
  Serial.print(" | Button: "); Serial.println(buttonState);

  delay(10);//add some delay between reads
  if(xPosition>=489&&xPosition<=491&&yPosition>=522&&yPosition<=527)
  {
    myservo.write(0);
    goto startagain;
  }
  while(xPosition>1000)
  {
     xPosition = analogRead(xPin);
     yPosition = analogRead(yPin);
    buttonState=digitalRead(buttonPin);
 
    for(i=0;i<1000;i++)
    {
      myservo.write(i);
    }
    
  }
  while(xPosition>0&&xPosition<200)
  {
    xPosition = analogRead(xPin);
    yPosition = analogRead(yPin);
    buttonState=digitalRead(buttonPin);
  
    for(i = 1000;i>=0;i++)
    {
       myservo.write(i);
    }
  }
}
