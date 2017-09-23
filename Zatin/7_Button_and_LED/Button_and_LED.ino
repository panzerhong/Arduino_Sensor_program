 int button=4;// the number of the pushbutton pin
 int led=12; // the number of the LED pin

void setup()
{
  
  pinMode(led,OUTPUT);// initialize the LED pin as an output:
  pinMode(button,INPUT);// initialize the pushbutton pin as an input:
}

void loop()
{
  y:
  if(digitalRead(button)==HIGH) // check if the pushbutton is pressed then the power 5 volt will emit 
  {
    for(int i = 0;i<=0;i--)
    {
      if(digitalRead(button)==HIGH)
      {
          goto x;
      }
      else
      digitalWrite(led,HIGH);
    }
  }
  else
  {
     x:
   digitalWrite(led,LOW);
   goto y;
  }
}

/*Connect the 5v pin to one leg of the push buttton, 
 * Connect the input pin to from digital pin to the one leg of the push button then
connect the resistor as pull down resistor.*/

