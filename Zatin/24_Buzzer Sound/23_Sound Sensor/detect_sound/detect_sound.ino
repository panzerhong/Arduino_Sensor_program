int value=0;
void setup(){
Serial.begin(9600);
pinMode(2, INPUT);
}
void loop()
{
  value = digitalRead(2);
if(value == 0) 
{
  Serial.print("no sound detected");
  Serial.print(" The value of digitalReaded : ");Serial.println(value);
}

else
Serial.println("sound detected");
Serial.print(" The value of digitalReaded : ");Serial.println(value);
delay(250);
}
