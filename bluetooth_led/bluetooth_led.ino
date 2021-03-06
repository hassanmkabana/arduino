char blueToothVal;           //value sent over via bluetooth
char lastValue;              //stores last state of device (on/off)
String message; 
void setup()
{
 Serial.begin(9600); 
 pinMode(11,OUTPUT);
}
 
 
void loop()
{
  if(Serial.available())
  {//if there is data being recieved
    blueToothVal=Serial.read(); //read it
    
  }
  if (blueToothVal=='n')
  {//if value from bluetooth serial is n
    digitalWrite(11,HIGH);            //switch on LED
    if (lastValue!='n')
      Serial.println(F("LED is on")); //print LED is on
    lastValue=blueToothVal;
  }
  else if (blueToothVal=='f')
  {//if value from bluetooth serial is n
    digitalWrite(11,LOW);             //turn off LED
    if (lastValue!='f')
      Serial.println(F("LED is off")); //print LED is on
    lastValue=blueToothVal;
  }
  
  delay(1000);
}
