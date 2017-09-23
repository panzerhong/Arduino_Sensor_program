#include <Wire.h> 
#include <LiquidCrystal_I2C.h>



#define BACKLIGHT_PIN     13

//LiquidCrystal_I2C lcd(0x38);  // Set the LCD I2C address

//LiquidCrystal_I2C lcd(0x38, BACKLIGHT_PIN, POSITIVE);  // Set the LCD I2C address
LiquidCrystal_I2C lcd(0x3F,2,1,0,4,5,6,7,3,POSITIVE);

// Creat a set of new characters
const uint8_t charBitmap[][8] = {
   { 0xc, 0x12, 0x12, 0xc, 0, 0, 0, 0 },
   { 0x6, 0x9, 0x9, 0x6, 0, 0, 0, 0 },
   { 0x0, 0x6, 0x9, 0x9, 0x6, 0, 0, 0x0 },
   { 0x0, 0xc, 0x12, 0x12, 0xc, 0, 0, 0x0 },
   { 0x0, 0x0, 0xc, 0x12, 0x12, 0xc, 0, 0x0 },
   { 0x0, 0x0, 0x6, 0x9, 0x9, 0x6, 0, 0x0 },
   { 0x0, 0x0, 0x0, 0x6, 0x9, 0x9, 0x6, 0x0 },
   { 0x0, 0x0, 0x0, 0xc, 0x12, 0x12, 0xc, 0x0 }
   
};

void setup()
{
   int charBitmapSize = (sizeof(charBitmap ) / sizeof (charBitmap[0]));

  // Switch on the backlight
  lcd.begin(16,2);               // initialize the lcd 

   for ( int i = 0; i < charBitmapSize; i++ )
   {
      lcd.createChar ( i, (uint8_t *)charBitmap[i] );
   }

  lcd.setCursor(0,0);              // go home
  lcd.print("Welcome");  
  lcd.setCursor ( 0, 1 );        // go to the next line
  lcd.print ("Arduino");
  delay ( 1000 );
}

void loop()//lcd.home() == lcd.setCursor(0,0);
{
  lcd.home ();          // go home
  lcd.print("HELLO, WORLD :-)");  
  lcd.setCursor ( 0, 1 );        // go to the next line
  lcd.print("I AM YIN MAZATIN");
  delay ( 5000 );
  
  lcd.setCursor(0,0);
  lcd.print("LED DESIGNING    ");
  lcd.setCursor(0,1);
  lcd.print("CONTACT ME :     ");
  delay(5000);
  
  lcd.setCursor(0,0);
  lcd.print("086 683137    ");
  lcd.setCursor(0,1);
  lcd.print("068 838312    ");
  delay(5000);
  
  lcd.setCursor(0,0);
  lcd.print("THANK YOU    ");
  lcd.setCursor(0,1);
  lcd.println("VERY MUCH :-)    ");
  delay(5000);
}
