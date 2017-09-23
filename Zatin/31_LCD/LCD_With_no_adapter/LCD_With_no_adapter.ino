/*The liquidCrystal library works with all LCD display that are
 * compatible with the Hitachi HD44780 driver. 
 * There are many of them out there and we can usually tell them by the 16-pin
 * interface. 
 * 
 * This sketch prints "HELLO WOROLD!" to the LCD and shows the time.
 * The circuit:
 * LCD RS pin to digital pin 12 
 * LCD Enable pin to digital pin 11 
 * LCD D4 pin to digial pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pi to digital pin 2
 * LCD R/W pin to ground
 * LCD VCC pin to 5v
 * 10K resistor:
 * ends to +5v and ground
 * wiper to LCD VO pin (pin 3)
 * 
*/
#include<LiquidCrystal.h>
const int rs = 12, en =11, d4=5, d5=4, d6=3, d7=2;
LiquidCrystal lcd (0x3F,rs,en,d4,d5,d6,d7);

void setup() {
  lcd.begin(16,2);
  lcd.print("hello, world1");
}

void loop() {
  // set the cursor to column 0, line 1
  // (note : line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0,1);
  // print the number of seconds since reset:
  lcd.print(millis()/1000);
  
}
