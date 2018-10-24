#include <Servo.h>
Servo myservo;
int pos =90;    
int BLACK= 12;   
int RED= 2;  

void setup() {
  Serial.begin(9600);          
  myservo.attach(9);  
  pinMode(RED,INPUT_PULLUP); 
  pinMode(BLACK,INPUT_PULLUP);
  myservo.write(82);
  digitalWrite(BLACK,HIGH);
  digitalWrite(RED,HIGH);
  while(!Serial);
}

void loop() {
  if(digitalRead(BLACK) == LOW){
    for (int pos = 82; pos >= 1; pos -= 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (int pos = 1; pos <= 82; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
    Serial.println(myservo.read());
  }

  else if(digitalRead(RED) == LOW){
    for (int pos = 82; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (int pos = 180; pos >= 82; pos -= 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
    
    Serial.println(myservo.read());
  }
  else{
    myservo.write(82);
    Serial.println("nothing");
    
    }
  delay(100);
}