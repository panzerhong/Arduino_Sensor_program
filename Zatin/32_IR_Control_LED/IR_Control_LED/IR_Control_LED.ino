#include "IRremote.h"
int receiver = 3; // IR Receiver Pin 3

const int white = 8;
const int green = 9;
const int blue = 10;
const int red = 11;
const int yellow = 12;
int i = 0;

IRrecv irrecv(receiver);// create instance of 'irrecv'
decode_results results;// create instance of 'decode_results'
/*---(Declare Variables)---*/
void setup()
{
  Serial.begin(9600); // starts serial communication
  Serial.println("IR Receiver Raw Data + Button Decode Test");
  irrecv.enableIRIn(); // Starts the receiver
  
  pinMode(white,OUTPUT);
  pinMode(green,OUTPUT);
  pinMode(blue,OUTPUT);
  pinMode(red,OUTPUT);
  pinMode(yellow,OUTPUT);
  pinMode(receiver,INPUT);
} 

void loop()
{
  digitalWrite(yellow,HIGH);
  digitalWrite(red,HIGH);
  digitalWrite(blue,HIGH);
  digitalWrite(green,HIGH);
  digitalWrite(white,HIGH);
  // decodes the infrared input
 if(irrecv.decode(&results))// have we received an IR signal or not?
 {
   translateIR();
    irrecv.resume();// Receive the next value
     delay(500);
 }
}
/*---( Declare User-written Functions )---*/
void translateIR()// takes action based on IR code received
{
  // describing Car MP3 IR codes
  switch(results.value)
  {
    case 0xFFA25D : Serial.println("CH- ");break;
    case 0xFF629D : Serial.println("CH  ");break;
    case 0xFFE21D : Serial.println("CH+ ");break;
    case 0xFF22DD : Serial.println("PREV ");break;
    case 0xFF02FD : Serial.println("NEXT ");break;
    case 0xFFC23D : Serial.println("PLAY/PAUSE ");break;
    case 0xFFE01F : Serial.println("VOL-  ");break;
    case 0xFFA857 : Serial.println("VOL+  ");break;
    case 0xFF906F : Serial.println("EQ  ");break;
    case 0xFF6897 : Serial.println("0 : Yellow is ON");break;
                    digitalWrite(yellow,HIGH);break;
                    digitalWrite(red,LOW);break;
                    digitalWrite(blue,LOW);break;
                    digitalWrite(green,LOW);break;
                    digitalWrite(white,LOW);break;
    case 0xFF9867 : Serial.println("100+  ");break;
    case 0xFFB04F : Serial.println("200+  ");break;
    case 0xFF30CF : Serial.println("1 Red is On");break;
                    digitalWrite(red,HIGH);
                    digitalWrite(yellow,LOW);
                    digitalWrite(blue,LOW);
                    digitalWrite(green,LOW);
                    digitalWrite(white,LOW);
                    break;
                    
    case 0xFF18E7 : Serial.println("2 Blue is ON");
                    digitalWrite(blue,HIGH);
                    digitalWrite(yellow,LOW);
                    digitalWrite(red,LOW);
                    digitalWrite(green,LOW);
                    digitalWrite(white,LOW);
                    break;
                    
    case 0xFF7A85 : Serial.println("3 Green is ON");
                    digitalWrite(green,HIGH);
                    digitalWrite(yellow,LOW);
                    digitalWrite(red,LOW);
                    digitalWrite(blue,LOW);
                    digitalWrite(white,LOW);
                    break;
                    
    case 0xFF10EF : Serial.println("4 White is ON");
                    digitalWrite(white,HIGH);
                    digitalWrite(green,LOW);
                    digitalWrite(blue,LOW);
                    digitalWrite(red,LOW);
                    digitalWrite(yellow,LOW);
                    break;
                    
    case 0xFF38C7 : Serial.println("5");
    case 0xFF5AA5 : Serial.println("6");
    case 0xFF42BD : Serial.println("7");
    case 0xFF4AB5 : Serial.println("8");
    case 0xFF52AD : Serial.println("9 All OFF");
                    digitalWrite(yellow,LOW);
                    digitalWrite(red,LOW);
                    digitalWrite(blue,LOW);
                    digitalWrite(green,LOW);
                    digitalWrite(white,LOW);
                    break;
                    
    default : Serial.println("Wrong Button input");
              Serial.println(results.value,HEX);
  }
  delay(500);
}



