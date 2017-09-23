void setup() {
  // put your setup code here, to run once:
  pinMode(3,OUTPUT);
  pinMode(9,OUTPUT);
}

int j = 0;

void loop() {
  // put your main code here, to run repeatedly:
// Increase the brightness of LED in both pin 

    do
    {
      analogWrite(3,j);
      analogWrite(9,j);
      delay(3);
      j++;
    }
     while(j!=200);
     
// Decrease the brightness of LED in both pin

   do{
    analogWrite(9,j);
     analogWrite(3,j);
      delay(3);
      j--;
   }
   while(j!=200);


}
