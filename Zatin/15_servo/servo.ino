// code must include Servo.h library in order to work
#include<Servo.h>
Servo myservo;// creates servo object to control a servo

int angle=0;

void setup()
{
  myservo.attach(9);//attaches the servo on pin 9
}

void loop() {
    for (angle = 0;angle<180;angle+=1)
     // goes from 0 to 180 degree insteps of 1 degree
     {
      myservo.write(angle);// directs servo to go to position in variable 'angle'
      delay(20);// waits 20ms between servo commands
     }
    delay(5000);
    for (angle=180;angle>=1;angle-=1)// goes from 180 to 0 degrees
     {
       myservo.write(angle);// moves servo back in opposite direction
       delay(20);// waits 20ms between servo commands
    }
}
