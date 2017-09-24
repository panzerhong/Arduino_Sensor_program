#include <Servo.h> 
Servo myservoR;
Servo myservoL;  

#define SetPoshort 2933
#define threshold 300

#define sen_left 12
#define sen_righ 8
#define button 7

//=====================define pin constand===================

#define MOTORLBACK   3  
#define MOTORLFORWARD 5 
#define MOTORRBACK  11 
#define MOTORRFORWRAD 6 
#define START  1

//====================front motor gain========================

double kp = 0.8;//0.5;
double kd = 15;//20
double ki = 0;

int    set_speed=180;//255
int    speed1=0;
int    speed2=0;
int cross1=0 , cross2=0 , cross3=0, cross4=0, cnt=0 ;

int posR = 0;
int posL = 0;
//int    i=0;
int    dot=0, dot1=0, dot2=0;
int count=0;
int add1=0;
int add2=0;
//==================paramentor PID function=================

long double proposional=0.00;
double last_proposional=0.00;
double integral=0.00;
double derivat=0.00;
int error=0;
double Position=0;
int error_value=0;
//void count ();
void corner_turn();

//==================PID Function============================

void PID()
  {
      Position=Read_sensor();
    
    proposional = SetPoshort - Position;
    
    integral = integral + proposional;
    
    derivat = proposional - last_proposional;
    
    error = ((kp*proposional) + (kd*derivat) + (ki*integral) );
    
    last_proposional = proposional;
    //Serial.println(error);
   }
   
//===========================================================

double Read_sensor()
  {
       long double sensors_average = 0;
     long double sensors_sum = 0;
     double sensors[] = {0,0,0,0,0,0,0,0};
     double sensor;
     
         
         for (int n = 1; n < 6; n++){
          
              sensors[n] = analogRead(n);
              sensors_average += sensors[n] * n *1000;   //Calculating the weighted mean
              sensors_sum += sensors[n];
              
             //Serial.print(sensors[n]);
             //Serial.print("--");
         }
        // Serial.print("position  "); 
         sensor = sensors_average / sensors_sum ;
        /*Serial.print(sensor);
         Serial.print("   ");
         Serial.print(digitalRead(7));
         Serial.print(digitalRead(12));
          
         Serial.println("   ");*/
         return sensor; 
   }
   //----------------------------------Count Cross--------------------------------------
int cross(){
    
    if(analogRead(1)<threshold && analogRead(5)<threshold){
      cross1 = 1;
      cross2 = 0; 
   }  
   if(analogRead(1)>threshold && analogRead(5)>threshold){
      cross2= 1; 
   }  
   if(cross1 == 1 && cross2 == 1){
       cross3++;
      cross1 = 0;
      cross2 = 0; 
   }  
   return cross3;
}

void speed_right()

  {
       digitalWrite(MOTORLBACK,LOW);
       digitalWrite(MOTORLFORWARD,LOW);
       digitalWrite( MOTORRBACK,LOW);
       digitalWrite(MOTORRFORWRAD,LOW);
         
       error_value = error;

       if(error_value >set_speed)
             {
               error_value = set_speed;
             }

       if(error_value < -set_speed)
             {
              error_value = -set_speed;
             }

        if(error_value<0)
             {

               speed1=set_speed+error_value;
               analogWrite (MOTORRFORWRAD,speed1);   //  for motor letf
               analogWrite ( MOTORLFORWARD,set_speed); //  for motor right
             }

        if(error_value>=0)
             {
               speed2=set_speed-error_value;
               analogWrite (MOTORLFORWARD,speed2);
               analogWrite ( MOTORRFORWRAD,set_speed);
             }

             //================================================== end========== black all turn right ====================================================================================
          //===================================dot=========================================

          if((digitalRead(sen_left)==LOW && digitalRead(sen_righ)==HIGH)||(digitalRead(sen_left)==HIGH && digitalRead(sen_righ)==LOW))
             {
              
               dot++;
                             
               while((digitalRead(sen_left)==LOW && digitalRead(sen_righ)==HIGH)||(digitalRead(sen_left)==HIGH && digitalRead(sen_righ)==LOW));
               
//               if(dot==1) set_speed=200;
//          if(dot==1)dot1=0;
             }


             //===========================+++++++++++++++++++++======================
          
if(digitalRead(button)==LOW)
         {
          if(analogRead(1)>threshold && analogRead(2)>threshold && analogRead(3)>threshold &&  analogRead(4)>threshold && analogRead(5)>threshold)
         
             {
                  //digitalWrite(MOTORLBACK,LOW);
                  digitalWrite(MOTORLFORWARD,LOW);
                  digitalWrite( MOTORRBACK,LOW);
                  //digitalWrite(MOTORRFORWRAD,LOW);
               do
               {
                     
                     //speed2=65;
                  
                     analogWrite ( MOTORLBACK,set_speed-140); //cross (2)  100
                     analogWrite (MOTORRFORWRAD,set_speed-100);
               }
               while (analogRead(4)>threshold) ;
               //while(analogRead(1)<threshold);
             }
          if(analogRead(1)<threshold && analogRead(2)>threshold && analogRead(3)>threshold && analogRead(4)>threshold && analogRead(5)>threshold)
             {
               digitalWrite(MOTORLBACK,LOW);
               //digitalWrite(MOTORLFORWARD,LOW);
               //digitalWrite( MOTORRBACK,LOW);
               digitalWrite(MOTORRFORWRAD,LOW);
               do
               {
                     if(dot>=1){

                          analogWrite (MOTORRBACK,set_speed-120);   //  for motor letf
                          analogWrite (MOTORLFORWARD,set_speed-80); //  for motor right

                     }
                     else{
                    
                         analogWrite (MOTORRBACK,set_speed-205);   //175  for motor letf
                         analogWrite (MOTORLFORWARD,set_speed-80); //100  for motor right
                     }
                    
               }
               while (analogRead(3)>threshold) ;
             }

//11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111

          
               if(analogRead(1)>threshold && analogRead(2)>threshold && analogRead(3)>threshold && analogRead(4)>threshold && analogRead(5)<threshold )
             {

                  //digitalWrite(MOTORLBACK,LOW);
                  digitalWrite(MOTORLFORWARD,LOW);
                  digitalWrite( MOTORRBACK,LOW);
                  //digitalWrite(MOTORRFORWRAD,LOW);
               do
               {
                     
                    
                  if(dot>=1)
                  {
                    analogWrite ( MOTORLBACK,set_speed-120);
                     analogWrite (MOTORRFORWRAD,set_speed-80);
                  }
                  else{
                     analogWrite ( MOTORLBACK,set_speed-205);//175
                     analogWrite (MOTORRFORWRAD,set_speed-80);//100//80
                  }
               }
               while (analogRead(3)>threshold) ;
             }
             
         }
else 
         {
          if(analogRead(1)>threshold && analogRead(2)>threshold && analogRead(3)>threshold &&  analogRead(4)>threshold && analogRead(5)>threshold)
         
             {
                  digitalWrite(MOTORLBACK,LOW);
                 // digitalWrite(MOTORLFORWARD,LOW);
                  //digitalWrite( MOTORRBACK,LOW);
                  digitalWrite(MOTORRFORWRAD,LOW);
               do
               {
                     
                     //speed2=65;
                  
                     analogWrite (MOTORRBACK,set_speed-100-add1); //120
                     analogWrite (MOTORLFORWARD,set_speed-80-add2);//100
               }
               //while (analogRead(4)>threshold) ;
               while(analogRead(2)<threshold);
             }

          if(analogRead(1)<threshold && analogRead(2)>threshold && analogRead(3)>threshold && analogRead(4)>threshold && analogRead(5)>threshold)
             {
               digitalWrite(MOTORLBACK,LOW);
               //digitalWrite(MOTORLFORWARD,LOW);
               //digitalWrite( MOTORRBACK,LOW);
               digitalWrite(MOTORRFORWRAD,LOW);
               do
               {
                     if(dot>=1){

                          analogWrite (MOTORRBACK,set_speed-120);   //  for motor letf
                          analogWrite (MOTORLFORWARD,set_speed-80); //  for motor right

                     }
                     else{
                    
                         analogWrite (MOTORRBACK,set_speed-205);   //175  for motor letf
                         analogWrite (MOTORLFORWARD,set_speed-80); //100  for motor right
                     }
                    
               }
               while (analogRead(3)>threshold) ;
             }

//11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111

          
               if(analogRead(1)>threshold && analogRead(2)>threshold && analogRead(3)>threshold && analogRead(4)>threshold && analogRead(5)<threshold )
             {

                  //digitalWrite(MOTORLBACK,LOW);
                  digitalWrite(MOTORLFORWARD,LOW);
                  digitalWrite( MOTORRBACK,LOW);
                  //digitalWrite(MOTORRFORWRAD,LOW);
               do
               {
                     
                    
                  if(dot>=1)
                  {
                    analogWrite ( MOTORLBACK,set_speed-120);
                     analogWrite (MOTORRFORWRAD,set_speed-80);
                  }
                  else{
                     analogWrite ( MOTORLBACK,set_speed-205);//175
                     analogWrite (MOTORRFORWRAD,set_speed-60);//100//80
                  }
               }
               while (analogRead(3)>threshold) ;
             }
             
         }
   //*********************************************stop*********************************          

    if(analogRead(1)<threshold && analogRead(5)<threshold && digitalRead(sen_righ)==LOW && digitalRead(sen_left)==LOW)
             {
                     digitalWrite(MOTORLBACK,LOW);
                     analogWrite(MOTORLFORWARD,0);
                     digitalWrite( MOTORRBACK,LOW);
                     analogWrite(MOTORRFORWRAD,0);
                     while(1);  
             }

//==================================== Test Condition ===============================

//000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
    
          if(analogRead(1)<threshold && analogRead(2)>threshold && analogRead(3)>threshold && analogRead(4)>threshold && analogRead(5)>threshold)
             {
               digitalWrite(MOTORLBACK,LOW);
               //digitalWrite(MOTORLFORWARD,LOW);
               //digitalWrite( MOTORRBACK,LOW);
               digitalWrite(MOTORRFORWRAD,LOW);
               do
               {
                     if(dot>=1){

                          analogWrite (MOTORRBACK,set_speed-120);   //  for motor letf
                          analogWrite (MOTORLFORWARD,set_speed-80); //  for motor right

                     }
                     else{
                    
                         analogWrite (MOTORRBACK,set_speed-205);   //175  for motor letf
                         analogWrite (MOTORLFORWARD,set_speed-80); //100  for motor right
                     }
                    
               }
               while (analogRead(3)>threshold) ;
             }

//11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111

          
               if(analogRead(1)>threshold && analogRead(2)>threshold && analogRead(3)>threshold && analogRead(4)>threshold && analogRead(5)<threshold )
             {

                  //digitalWrite(MOTORLBACK,LOW);
                  digitalWrite(MOTORLFORWARD,LOW);
                  digitalWrite( MOTORRBACK,LOW);
                  //digitalWrite(MOTORRFORWRAD,LOW);
               do
               {
                     
                    
                  if(dot>=1)
                  {
                    analogWrite ( MOTORLBACK,set_speed-120);
                     analogWrite (MOTORRFORWRAD,set_speed-80);
                  }
                  else{
                     analogWrite ( MOTORLBACK,set_speed-205);//175
                     analogWrite (MOTORRFORWRAD,set_speed-60);//100//80
                  }
               }
               while (analogRead(3)>threshold) ;
             }


//22222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222
         
   }
void setup()
   {
      // put your setup code here, to run once:
     // Serial.begin(9600);
myservoR.attach(4);
myservoL.attach(2);

 myservoR.write(140);  
 myservoL.write(42);


       pinMode(MOTORLBACK,OUTPUT);
       pinMode(MOTORLFORWARD,OUTPUT);
       pinMode( MOTORRBACK,OUTPUT);
       pinMode(MOTORRFORWRAD,OUTPUT);
       pinMode(sen_left,INPUT);
       pinMode(sen_righ,INPUT);
       pinMode(button,INPUT_PULLUP);

       digitalWrite(MOTORLBACK,LOW);
       digitalWrite(MOTORLFORWARD,LOW);
       digitalWrite( MOTORRBACK,LOW);
       digitalWrite(MOTORRFORWRAD,LOW);
//       digitalWrite(sen_left,HIGH);
//       digitalWrite(sen_righ,HIGH);
       
       delay(500);

    }

void loop()
   {
          PID();
      speed_right();
    
cnt = cross();
    if(cnt==1)cross4++;
    if(cross4==1000)//1400 sp 230
{
   myservoR.write(10);
   myservoL.write(170);                   
   set_speed=130;// 190 sp230
}

 if (cnt==4)
{
set_speed=100;//140 sp 230
}  
if (cnt==5)
{
       digitalWrite(MOTORLBACK,LOW);
       digitalWrite(MOTORLFORWARD,LOW);
       digitalWrite( MOTORRBACK,LOW);
       digitalWrite(MOTORRFORWRAD,LOW);
while(1);
//add1=30;
//add2=40;//140 sp 230
}  
   
 if (cnt==6)
   {
    add1=0;
    add2=0;
    myservoR.write(140);              // tell servo to go to position in variable 'pos'                                 // in steps of 1 degree 
    myservoL.write(42);              // tell servo to go to position in variable 'pos' 

     cross3=8;
    set_speed=180; 

   }     
      

  
    }
//==========================================================================================

