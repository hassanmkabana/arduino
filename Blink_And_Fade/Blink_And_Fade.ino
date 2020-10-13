/*
  Code by Hassan
  written on 24/01/2020
*/
 int trig = 7;
 int echo = 6;
 const int led1 = 12;
 const int led2 = 10;           
 const int led3 = 11;
 long timeperiod, cm, inches;    
 int outputValue = 0;  
 int brightness = 0;
 int fadeAmount = 5;

// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  timeperiod= pulseIn(echo, HIGH);

  analogWrite(led1, outputValue);
  analogWrite(led2, outputValue);
  analogWrite(led3, outputValue);

  Serial.print("distance in inches=");
  Serial.print(inches);
  Serial.print("    distance in centimeters=");
  Serial.print(cm);
  Serial.println();
  outputValue = map(cm,0,60,254,0);
  inches = microsecondsToInches(timeperiod);
  cm = microsecondsToCentimeters(duration);
  // change the brightness for next time through the loop:
  //cm = cm + outputValue;
   
  // reverse the direction of the fading at the ends of the fade:
  if (cm <= 0 || cm >= 60) {
   cm = -cm;
  }
  if (cm == 60) {
      analogWrite(led1, LOW);
  analogWrite(led2, LOW);
  analogWrite(led3, LOW);
  }else if(cm==0){
    analogWrite(led1, HIGH);
  analogWrite(led2, HIGH);
  analogWrite(led3, HIGH);*/
  
  delay(100);
}  
  // wait for 30 milliseconds to see the dimming effect
  
  long microsecondsToInches(long microseconds) {
  // According to Parallax's datasheet for the PING))), there are 73.746
  // microseconds per inch (i.e. sound travels at 1130 feet per second).
  // This gives the distance travelled by the ping, outbound and return,
  // so we divide by 2 to get the distance of the obstacle.
  // See: http://www.parallax.com/dl/docs/prod/acc/28015-PING-v1.3.pdf
  return microseconds / 74 / 2;
  }

 long microsecondsToCentimeters(long microseconds){ 
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the object we
  // take half of the distance travelled.
  return microseconds / 29 / 2;
}
