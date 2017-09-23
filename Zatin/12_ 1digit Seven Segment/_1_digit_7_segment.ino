#define segA 2// connecting segment A to PIN 2
#define segB 3 
#define segC 4
#define segD 5
#define segE 6
#define segF 7
#define segG 8
#define segDot 9
int i;
void setup() {
  // put your setup code here, to run once:
  int count ;
  for(int i=2;i<=9;i++)
  {
    pinMode(i,OUTPUT);//taking all pins from 2-9 as output
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i = 3;i>=1;i--)
  {
   digitalWrite(segA,HIGH);
  digitalWrite(segB,HIGH);
  digitalWrite(segC,HIGH);
  digitalWrite(segD,HIGH);
  digitalWrite(segE,HIGH);
  digitalWrite(segF,HIGH);
  digitalWrite(segG,HIGH);
  digitalWrite(segDot,HIGH);
  delay(1000);
  digitalWrite(segA,LOW);
  digitalWrite(segB,LOW);
  digitalWrite(segC,LOW);
  digitalWrite(segD,LOW);
  digitalWrite(segE,LOW);
  digitalWrite(segF,LOW);
  digitalWrite(segG,LOW);
  digitalWrite(segDot,LOW);
  delay(1000);
  }
  
    for(int i = 0;i<=9;i++)
    {
                 switch(i)
             {
              case 9 :   digitalWrite(segA,HIGH);
                        digitalWrite(segB,HIGH);
                        digitalWrite(segC,HIGH);
                        digitalWrite(segD,HIGH);
                        digitalWrite(segE,LOW);
                        digitalWrite(segF,HIGH);
                        digitalWrite(segG,HIGH);
                        digitalWrite(segDot,HIGH);
                        
                        break; 
          
             case 8 :   digitalWrite(segA,HIGH);
                        digitalWrite(segB,HIGH);
                        digitalWrite(segC,HIGH);
                        digitalWrite(segD,HIGH);
                        digitalWrite(segE,HIGH);
                        digitalWrite(segF,HIGH);
                        digitalWrite(segG,HIGH);
                        digitalWrite(segDot,HIGH);
                      
                        break;
          
             case 7 :   digitalWrite(segA,HIGH);
                        digitalWrite(segB,HIGH);
                        digitalWrite(segC,HIGH);
                        digitalWrite(segD,LOW);
                        digitalWrite(segE,LOW);
                        digitalWrite(segF,LOW);
                        digitalWrite(segG,LOW);
                        digitalWrite(segDot,HIGH);
                         
                        break;
            
             case 6 :   digitalWrite(segA,HIGH);
                        digitalWrite(segB,LOW);
                        digitalWrite(segC,HIGH);
                        digitalWrite(segD,HIGH);
                        digitalWrite(segE,HIGH);
                        digitalWrite(segF,HIGH);
                        digitalWrite(segG,HIGH);
                        digitalWrite(segDot,HIGH);
                        
                        break;
                        
             case 5 :   digitalWrite(segA,HIGH);
                        digitalWrite(segB,LOW);
                        digitalWrite(segC,HIGH);
                        digitalWrite(segD,HIGH);
                        digitalWrite(segE,LOW);
                        digitalWrite(segF, HIGH);
                        digitalWrite(segG,HIGH);
                        digitalWrite(segDot,HIGH);
                        
                        break;
            
             case 4 :   digitalWrite(segA,LOW);
                        digitalWrite(segB,HIGH);
                        digitalWrite(segC,HIGH);
                        digitalWrite(segD,LOW);
                        digitalWrite(segE,LOW);
                        digitalWrite(segF,HIGH);
                        digitalWrite(segG,HIGH);
                        digitalWrite(segDot,HIGH);
          
                        break;
          
             case 3 :   digitalWrite(segA,HIGH);
                        digitalWrite(segB,HIGH);
                        digitalWrite(segC,HIGH);
                        digitalWrite(segD,HIGH);
                        digitalWrite(segE,LOW);
                        digitalWrite(segF,LOW);
                        digitalWrite(segG,HIGH);
                        digitalWrite(segDot,HIGH);
                       
                        break;
            
             case 2 :   digitalWrite(segA,HIGH);
                        digitalWrite(segB,HIGH);
                        digitalWrite(segC,LOW);
                        digitalWrite(segD,HIGH);
                        digitalWrite(segE,HIGH);
                        digitalWrite(segF,LOW);
                        digitalWrite(segG,HIGH);
                        digitalWrite(segDot,HIGH);
                        
                        break;
          
              case 1 :   digitalWrite(segA,LOW);
                        digitalWrite(segB,HIGH);
                        digitalWrite(segC,HIGH);
                        digitalWrite(segD,LOW);
                        digitalWrite(segE,LOW);
                        digitalWrite(segF,LOW);
                        digitalWrite(segG,LOW);
                        digitalWrite(segDot,LOW);
                        
                        break;
            
              case 0 :  digitalWrite(segA,HIGH);
                        digitalWrite(segB,HIGH);
                        digitalWrite(segC,HIGH);
                        digitalWrite(segD,HIGH);
                        digitalWrite(segE,HIGH);
                        digitalWrite(segF,HIGH);
                        digitalWrite(segG,LOW);
                        digitalWrite(segDot,HIGH);
                        
                        break;
             }
             delay(500); 
  }

   digitalWrite(segA,LOW);
  digitalWrite(segB,LOW);
  digitalWrite(segC,LOW);
  digitalWrite(segD,LOW);
  digitalWrite(segE,LOW);
  digitalWrite(segF,LOW);
  digitalWrite(segG,LOW);
  digitalWrite(segDot,LOW);
  delay(1000);
  
   for(int i = 9;i>=0;i--)
    {
                 switch(i)
             {
              case 9 :   digitalWrite(segA,HIGH);
                        digitalWrite(segB,HIGH);
                        digitalWrite(segC,HIGH);
                        digitalWrite(segD,HIGH);
                        digitalWrite(segE,LOW);
                        digitalWrite(segF,HIGH);
                        digitalWrite(segG,HIGH);
                        digitalWrite(segDot,HIGH);
                        
                        break; 
          
             case 8 :   digitalWrite(segA,HIGH);
                        digitalWrite(segB,HIGH);
                        digitalWrite(segC,HIGH);
                        digitalWrite(segD,HIGH);
                        digitalWrite(segE,HIGH);
                        digitalWrite(segF,HIGH);
                        digitalWrite(segG,HIGH);
                        digitalWrite(segDot,HIGH);
                      
                        break;
          
             case 7 :   digitalWrite(segA,HIGH);
                        digitalWrite(segB,HIGH);
                        digitalWrite(segC,HIGH);
                        digitalWrite(segD,LOW);
                        digitalWrite(segE,LOW);
                        digitalWrite(segF,LOW);
                        digitalWrite(segG,LOW);
                        digitalWrite(segDot,HIGH);
                         
                        break;
            
             case 6 :   digitalWrite(segA,HIGH);
                        digitalWrite(segB,LOW);
                        digitalWrite(segC,HIGH);
                        digitalWrite(segD,HIGH);
                        digitalWrite(segE,HIGH);
                        digitalWrite(segF,HIGH);
                        digitalWrite(segG,HIGH);
                        digitalWrite(segDot,HIGH);
                        
                        break;
                        
             case 5 :   digitalWrite(segA,HIGH);
                        digitalWrite(segB,LOW);
                        digitalWrite(segC,HIGH);
                        digitalWrite(segD,HIGH);
                        digitalWrite(segE,LOW);
                        digitalWrite(segF, HIGH);
                        digitalWrite(segG,HIGH);
                        digitalWrite(segDot,HIGH);
                        
                        break;
            
             case 4 :   digitalWrite(segA,LOW);
                        digitalWrite(segB,HIGH);
                        digitalWrite(segC,HIGH);
                        digitalWrite(segD,LOW);
                        digitalWrite(segE,LOW);
                        digitalWrite(segF,HIGH);
                        digitalWrite(segG,HIGH);
                        digitalWrite(segDot,HIGH);
          
                        break;
          
             case 3 :   digitalWrite(segA,HIGH);
                        digitalWrite(segB,HIGH);
                        digitalWrite(segC,HIGH);
                        digitalWrite(segD,HIGH);
                        digitalWrite(segE,LOW);
                        digitalWrite(segF,LOW);
                        digitalWrite(segG,HIGH);
                        digitalWrite(segDot,HIGH);
                       
                        break;
            
             case 2 :   digitalWrite(segA,HIGH);
                        digitalWrite(segB,HIGH);
                        digitalWrite(segC,LOW);
                        digitalWrite(segD,HIGH);
                        digitalWrite(segE,HIGH);
                        digitalWrite(segF,LOW);
                        digitalWrite(segG,HIGH);
                        digitalWrite(segDot,HIGH);
                        
                        break;
          
              case 1 :   digitalWrite(segA,LOW);
                        digitalWrite(segB,HIGH);
                        digitalWrite(segC,HIGH);
                        digitalWrite(segD,LOW);
                        digitalWrite(segE,LOW);
                        digitalWrite(segF,LOW);
                        digitalWrite(segG,LOW);
                        digitalWrite(segDot,LOW);
                        
                        break;
            
              case 0 :  digitalWrite(segA,HIGH);
                        digitalWrite(segB,HIGH);
                        digitalWrite(segC,HIGH);
                        digitalWrite(segD,HIGH);
                        digitalWrite(segE,HIGH);
                        digitalWrite(segF,HIGH);
                        digitalWrite(segG,LOW);
                        digitalWrite(segDot,HIGH);
                        
                        break;
             }
             delay(500);
             
  }
}
