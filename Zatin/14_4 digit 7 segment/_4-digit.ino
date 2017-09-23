#include "SevSeg.h" 
SevSeg sevseg;// Initiate a seven segment controller object

void setup() {
  // put your setup code here, to run once:
  byte numDigits = 4;
  byte digitPins[] = {2,3,4,5};
  byte segmentPins[] = {6,7,8,9,10,11,12,13};
  sevseg.begin(COMMON_CATHODE, numDigits, digitPins, segmentPins);
  sevseg.setBrightness(90);
}

void loop() {
  // put your main code here, to run repeatedly:
 
  sevseg.setNumber(9929);
// delay(1000);
// sevseg.setNumber(0000);
// delay(1);
// sevseg.setNumber(9998);
//  sevseg.setNumber(0002);
  sevseg.refreshDisplay( );// Must run repeatedly
}
