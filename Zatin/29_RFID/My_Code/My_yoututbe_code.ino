#include "SPI.h"
#include "MFRC522.h"
/*  Connect SCK pin to pin 13 of the arduino
    Connect SDA pin to pin 10 of the arduino
    Connect MOSI pin to pin 11 of the arduino
    Connect MISO pin to pin 12 of the arduino
    IRQ unconnected 
    GND to GND of the arduino
    3.3volts ot 3.3v of thea arduino
    Connect RST to pin 9 of the arduino
    */
#define SS_PIN 10
#define RST_PIN 9
#define SP_PIN 8
#define LED_PIN 2

MFRC522 rfid(SS_PIN,RST_PIN);
MFRC522 ::MIFARE_Key key;

void setup()
{
  Serial.begin(9600);
  SPI.begin();
  rfid.PCD_Init();
    pinMode(LED_PIN,OUTPUT);
}
void loop()
{
  if(!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial())
  return;

  // Serial.print (F("PICC type:"));
  MFRC522::PICC_Type piccType = rfid.PICC_GetType(rfid.uid.sak);
  // Serial.println(rfid.PICC_GetTypeName(piccType));

  //Check is the pICC of Classis MIFARE type
  if(piccType!= MFRC522::PICC_TYPE_MIFARE_MINI && 
    piccType!=MFRC522::PICC_TYPE_MIFARE_1K &&
    piccType != MFRC522::PICC_TYPE_MIFARE_4K)
    {
      Serial.println(F("Your tag is not of type MIFARE Classic."));
      return;
    }
    String strID="";
    for(byte i = 0;i<4;i++)
    {
      strID += 
      (rfid.uid.uidByte[i] <0x10?"0" : "")+
      String(rfid.uid.uidByte[i],HEX)+
      (i!=3? ":" : "");
    }

    strID.toUpperCase();
    Serial.println("Tap card key:");
    Serial.println(strID);

    // Test LED

  if(strID.indexOf("EA:75:58:C5")>=false||strID.indexOf("86:3B:90:BB")==false)
  {
    digitalWrite(LED_PIN,HIGH);
    delay(5000);
    digitalWrite(LED_PIN,LOW);
  }
  else
  digitalWrite(LED_PIN,LOW);
  
    rfid.PICC_HaltA();
    rfid.PCD_StopCrypto1();
}

