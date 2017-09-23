#define echoPin 11 // Echo Pin
#define trigPin 12 // Trigger Pin 

long duration, distance; // Duration used to calculate distance
void setup() {
  // put your setup code here, to run once:
  Serial.begin (9600);  // 
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
 digitalWrite(trigPin, LOW);// Clear all the emitting ultrasonic sound
  delayMicroseconds(2);

  digitalWrite(trigPin,HIGH); // For generating ultrasonic sound wave
  delayMicroseconds(1000);

  digitalWrite(trigPin,LOW);// Clear all the ultrasonic sound again
 
  float duration = pulseIn(echoPin,HIGH); // For reading the time when the echoPin emit the ultrasound until it stop

  //Caluculate the distance (in cm) based on the speed of sound. 
  //float distance = duration/58.2;   
  float distance = duration*0.034/2;

  Serial.print("This is the distance in centremeter : ");Serial.println(distance);
  delay(500);

}
