#include <LEDDisplay.h>

LEDDisplay *led;
 
void setup()
{
    int digitFlagPins[] = {10, 11};
    int segmentPins[] = {2, 3, 4, 5 ,6 ,7 ,8, 9};
    int decimalPointPin = 9;
    led = new LEDDisplay(2, digitFlagPins, segmentPins, decimalPointPin);
}
 
void loop()
{  
    led->displayNumber(5, 1);
    led->displayNumber(4, 0);
}
