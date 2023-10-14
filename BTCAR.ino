#include <SoftwareSerial.h>
char t;
int p ;
SoftwareSerial BT(2,3);
const int trigPin = 6;
const int echoPin = 8;
int distance;
long duration;

void setup() {
pinMode(7,OUTPUT);   //left motors  forward
pinMode(12,OUTPUT);   //left motors reverse
pinMode(11,OUTPUT);   //right  motors forward
pinMode(10,OUTPUT);   //right motors reverse
pinMode(9,OUTPUT);   //Led
pinMode(13,OUTPUT);  // buzzer
pinMode(trigPin,OUTPUT);
pinMode(echoPin,INPUT);
Serial.begin(9600);
BT.begin(9600);
t = 'Z';
 
}
void forward(){
  digitalWrite(7,HIGH);  //left motor fwd
  digitalWrite(10,HIGH); //right motor fwd
}
void back(){
   digitalWrite(12,HIGH); //left motor moves back
  digitalWrite(11,HIGH);  //right motor moves back
}
void left(){
  digitalWrite(7,HIGH);   // left motor back
  digitalWrite(11,HIGH);  // right motor fwd
}
void right(){
    digitalWrite(10,HIGH); //left motor fwd
  digitalWrite(12,HIGH);   //right motor back
}
void stop(){
  digitalWrite(7,LOW);     //stop
  digitalWrite(12,LOW);
  digitalWrite(11,LOW);
  digitalWrite(10,LOW);
}
// this function will calculate distance of object from vehicle
int Distance(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(1);
  // Sets the trigPin on HIGH state for 5 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2;
  return distance;
}
 
void loop() {
if(BT.available()){
  t = BT.read();
  p = BT.read();
  Serial.println(t);
}
if(t == 'F'){ 
  int p = Distance() ;  
  if (p<2 && p>0){
  stop ();
  digitalWrite(13,HIGH);
  delay(100);
  back();
  delay(500);
  left();
  delay(300);
  stop();
  digitalWrite(13,LOW);
  }  else forward();
}  
else if(t == 'S'){      //STOP (all motors stop)
  stop();
}

else if(t == 'B'){      //move reverse (all  motors rotate in reverse direction)
  back();
}
  
else if(t == 'L'){      //turn left (left side motors rotate in forward direction,  right side motors rotate back)
  left();
}
 
else  if(t == 'R'){      //turn right (right side motors rotate in forward direction, left  side motors rotate backwards)
  right();
}

else if(t ==  'W'){    //turn led on 
  digitalWrite(9,HIGH);
}
else if(t == 'w'){       //turn led of 
  digitalWrite(9,LOW);
}
else if(t == 'V'){       // turn buzzer onn
  digitalWrite(13,HIGH);
}
else if(t == 'v'){
  digitalWrite(13,LOW);   // turn buzzer off
}
}

