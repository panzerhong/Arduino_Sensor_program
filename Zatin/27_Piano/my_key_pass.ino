#include<Keypad.h>

const int buzz = 12;// speaker connected to digital pin 12
const byte ROWS = 4;// four rows
const byte COLS = 4;// four columnns
const int redled = 6;// connnect led pin to digital pin 6 of arduino
const int blueled = 7;// connnect led pin to digital pin 7 of arduino
unsigned int i=0;
float j = 0;
boolean tf = false;
char keys[ROWS][COLS]=
 {
  {'a','b','c','d'},
  {'e','f','g','h'},
  {'i','j','k','l'},
  {'m','n','o','p'}
};
byte rowPins[ROWS] = {2,3,4,5};// connect to the row pinoouts of the keypad
byte colPins[COLS] = {8,9,10,11};// connect to the column pinoutsof the keypad

Keypad keypad = Keypad(makeKeymap(keys),rowPins,colPins,ROWS,COLS);

void setup()
{
  Serial.begin(9600);
  pinMode(buzz,OUTPUT);
  pinMode(redled,OUTPUT);
  pinMode(blueled,OUTPUT);
  digitalWrite(redled,LOW);
  digitalWrite(blueled,LOW);
}
void loop()
{
  char key = keypad.getKey();
  
  if(key != NO_KEY)
  {
    if(key == 'a'){Serial.print("Key Number : 1");Serial.println(key);keys1();}
    else if (key == 'b'){Serial.print("Key Number : 2 ");Serial.println(key);tf = false; keys2();}
    else if (key == 'c'){Serial.print("Key Number : 3 ");Serial.println(key); tf = false;keys3();}
    else if (key == 'd'){Serial.print("Key Number : 4 ");Serial.println(key); tf = false;keys4();}
    else if (key == 'e'){Serial.print("Key Number : 5 ");Serial.println(key);tf = false; keys5();}
    else if (key == 'f'){Serial.print("Key Number : 6 ");Serial.println(key);tf = false; keys6();}
    else if (key == 'g'){Serial.print("Key Number : 7 ");Serial.println(key);tf = false;keys7();}
    else if (key == 'h'){Serial.print("Key Number : 8 ");Serial.println(key); tf = false;keys8();}
    else if (key == 'i'){Serial.print("Key Number : 9 ");Serial.println(key);tf = false; keys9();}
    else if (key == 'j'){Serial.print("Key Number : 10 ");Serial.println(key);tf = false;keys10();}
    else if (key == 'k'){Serial.print("Key Number : 11 ");Serial.println(key);tf = false;keys11();}
    else if (key == 'l'){Serial.print("Key Number : 12 ");Serial.println(key);tf = false;keys12();}
    else if (key == 'm'){Serial.print("Key Number : 13 ");Serial.println(key);tf = false;keys13();}
    else if (key== 'n'){Serial.print("Key Number : 14 ");Serial.println(key);tf = false;keys14();}
    else if (key =='o'){Serial.print("Key Number : 15 ");Serial.println(key);tf = false;keys15();}
    else if (key == 'p'){Serial.print("Key Number : 16 ");Serial.println(key);tf=true;keys16(); }
    else
    Serial.print("No key is pressed");
   }
}
void keys1()
{
 digitalWrite(redled,LOW);digitalWrite(blueled,LOW);
 noTone(buzz);// stop the sound
}
void keys2()
{
  digitalWrite(redled,LOW);digitalWrite(blueled,HIGH);
  tone(buzz,250*2);
}
void keys3()
{
  digitalWrite(redled,HIGH);digitalWrite(blueled,LOW);
  tone(buzz,250*3);
}
void keys4()
{
 digitalWrite(redled,LOW);digitalWrite(blueled,HIGH);
  tone(buzz,250*4);
}
void keys5()
{
   digitalWrite(redled,HIGH);digitalWrite(blueled,LOW);
  tone(buzz,250*5);
}
void keys6()
{
  digitalWrite(redled,LOW);digitalWrite(blueled,HIGH);
  tone(buzz,250*6);
}
void keys7()
{
  digitalWrite(redled,HIGH);digitalWrite(blueled,LOW);
 tone(buzz,250*7);
}
void keys8()
{
  digitalWrite(redled,LOW);digitalWrite(blueled,HIGH);
  tone(buzz,250*8);
}
void keys9()
{
   digitalWrite(redled,HIGH);digitalWrite(blueled,LOW);
 tone(buzz,250*9);
}
void keys10()
{
  digitalWrite(redled,LOW);digitalWrite(blueled,HIGH);
  tone(buzz,250*10);
}
void keys11()
{
  digitalWrite(redled,HIGH);digitalWrite(blueled,LOW);
 tone(buzz,250*11);
}
void keys12()
{
  digitalWrite(redled,LOW);digitalWrite(blueled,HIGH);
  tone(buzz,250*12);
}
void keys13()
{
   digitalWrite(redled,HIGH);digitalWrite(blueled,LOW);
 tone(buzz,250*13);
}
void keys14()
{
 digitalWrite(redled,LOW);digitalWrite(blueled,HIGH);
  tone(buzz,250*14);
}
void keys15()
{
   digitalWrite(redled,HIGH);digitalWrite(blueled,LOW);
 tone(buzz,250*15);
}

void keys16()
{ 
  while(tf==true)
  {
   digitalWrite(redled,LOW);
   digitalWrite(blueled,LOW);
        for(i = 0;i<4000;i++)
      {
        tone(buzz,i);
      }
       digitalWrite(redled,HIGH);
       delay(250);
       digitalWrite(redled,LOW);
       delay(250);
      for(i=4000;i>0;i--)
      {
        tone(buzz,i);
      }
       digitalWrite(blueled,HIGH);
       delay(250);
       digitalWrite(blueled,LOW);
       delay(250);
       char key = keypad.getKey();
       if(keypad.key!='p')
       tf=false;
  }
  
}


