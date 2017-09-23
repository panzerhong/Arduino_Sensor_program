//PIN2 ------------------LOAD or CHIPSELECT of LED module
//PIN3------------------CLOCK of LED module
//PIN4 ------------------DATAIN of LED module
//+5V ------------------VCC of LED module
//GND ------------------GND of LED module
#include"LedControlMS.h"
#define NBR_MTX 1 //number of matrics attached is one
LedControl lc = LedControl(4,3,2,NBR_MTX);
void setup() {
  // put your setup code here, to run once:
  for(int i = 0;i<NBR_MTX;i++)
  {
    lc.shutdown(i,false);
    /*Set the brightness to medium values */
    lc.setIntensity(i,8);
    /*and clear the display*/
    lc.clearDisplay(i);
    delay(100);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  lc.writeString(0,"Apple");// sending characters to display
   delay(1000);
  lc.clearAll();//clearing the display
 

}
