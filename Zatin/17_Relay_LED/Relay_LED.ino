#define relay 2// defining the pin 1 of the arduino for the relay module
#define led 13
void setup() {
  // put your setup code here, to run once:
  pinMode(relay,OUTPUT);
  pinMode(relay,OUTPUT);
  digitalWrite(led,HIGH);
}

/*For the connection , + Normally closed (NC) : the contact is closed when the relay is not energized
                       + Normally Open (NO) : the contact is open when the relay is not energized*/ 
void loop() {
  digitalWrite(relay,LOW);// There is no current in the relay or the relay is not ennergized
  delay(5000);
  digitalWrite(relay,HIGH);// There is current in the relay or the relay is energized.
  delay(1000);
}
