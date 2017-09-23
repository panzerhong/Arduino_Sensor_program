#define segA 2    //Connecting segment A to PIN2
#define segB 3     //Connecting segment B to PIN3
#define segC 4
#define segD 5
#define segE 6
#define segF 7
#define segG 8

void setup() {
  // put your setup code here, to run once:
 for (int i = 2;i<9;i++)
 {
  pinMode(i,OUTPUT);
 }
}

void loop() {
  // put your main code here, to run repeatedly:
    digitalWrite(segA,HIGH);
    digitalWrite(segB,HIGH);
    digitalWrite(segC,HIGH);
    digitalWrite(segD,HIGH);
    digitalWrite(segE,HIGH);
    digitalWrite(segF,HIGH);
    digitalWrite(segG,LOW);
}
