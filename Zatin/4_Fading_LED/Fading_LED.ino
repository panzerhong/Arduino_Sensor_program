#define LED 6 // Declare LED at pin 6
void setup() {
  // put your setup code here, to run once:
  pinMode(6,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int i ; // declare i

 for(i=0;i<=2000;i++)
 {
    analogWrite(6,i);// sets the analogue, value of pin 6 as i
    delay (10);// pause for 100ms
 }
     for(i=2000;i>0;i--) 
 {
     analogWrite(6,i);
     delay(10);
 }
}
