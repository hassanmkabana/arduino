
#include<SoftwareSerial.h>      
SoftwareSerial firstSerial(03,04);      
int led=11;    
void setup()      
{      
  pinMode(led,OUTPUT);    
  firstSerial.begin(9600);      
  Serial.begin(9600);      
  delay(1000);      
}      
void loop()      
{      
  if(Serial.available()>0)    
  digitalWrite(led,HIGH);      
  switch(Serial.read());      
}      
void sndmsg()      
{      
  firstSerial.println("AT+CMGF=1");      
  delay(1000);      
  firstSerial.println("AT+CMGS=\"+xxxxxxxxxx\"\r");  //Enter Your Mobile Number instead XXXX while Testing    
  delay(1000);      
  firstSerial.println("sms messagers sender ");      
  delay(100);      
  firstSerial.println((char)23);      
  delay(1000);      
}      
