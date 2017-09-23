int switchPin = 8;
  int ledPin =13;
  boolean lastclick = LOW;
  boolean currentclick = LOW;
  boolean ledOn = false;
void setup() {
  // put your setup code here, to run once:
  
  pinMode(switchPin,INPUT);
  pinMode(ledPin,OUTPUT);
}

boolean debounce(boolean last)
{
  boolean current = digitalRead(switchPin);
  if(last != current)  
  {
    delay(5);
    current = digitalRead(switchPin);
        
  }
  return current;
}

void loop() {
  currentclick = debounce(lastclick);
  if(lastclick == LOW && currentclick == HIGH)
  {
    ledOn = !ledOn;
  }
  lastclick = currentclick; 
  digitalWrite(ledPin,ledOn);
}
