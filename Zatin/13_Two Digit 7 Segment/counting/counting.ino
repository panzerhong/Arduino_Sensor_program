#include<LEDDisplay.h>

LEDDisplay *led;
int millisecondsPerCount;
int counter=0;
  int number;
unsigned long lastUpdate;

void setup() {
  millisecondsPerCount = 1000;
  int digitFlagPins[] = {10,11};
  int segmentPins [] = {2,3,4,5,6,7,8,9};
  int decimalPointPin = 9;
  led = new LEDDisplay(2,digitFlagPins,segmentPins,decimalPointPin);
}

void loop() {
  unsigned long now = millis();
  if(now - lastUpdate> millisecondsPerCount)
  {
    lastUpdate = now;
    counter++;
    if(counter ==100)
    {
      counter = 99; 
    }
  }

 number = counter ;
  for(int i = 0;i<2;i++)
  {
    led-> displayNumber(number % 10,i);
    delay(2);
    number = number /10; 
  }
}
