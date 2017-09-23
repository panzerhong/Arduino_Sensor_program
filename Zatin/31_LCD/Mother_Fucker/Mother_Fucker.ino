#include<Wire.h>
#include<LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F,2,1,0,4,5,6,7,3,POSITIVE);
void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  lcd.clear();
 
}

void loop() {
  // put your main code here, to run repeatedly:
   lcd.print("Mother Fucker");
   lcd.setCursor(0,1);
   lcd.print("AH JERM :-D");
   delay(800);
   lcd.clear();
   delay(800);
}
