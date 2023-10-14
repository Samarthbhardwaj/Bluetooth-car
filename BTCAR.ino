#include <SoftwareSerial.h>
char t;
int p ;
int speed;
int enA=4;
int enB=5;
SoftwareSerial BT(2,3);
bool Extra ;

void setup() {
pinMode(7,OUTPUT);   //left motors  forward
pinMode(12,OUTPUT);   //left motors reverse
pinMode(11,OUTPUT);   //right  motors forward
pinMode(10,OUTPUT);   //right motors reverse
pinMode(enA,OUTPUT);
pinMode(enB,OUTPUT);
pinMode(9,OUTPUT);   //Led
pinMode(13,OUTPUT);  // buzzer
Serial.begin(9600);
BT.begin(9600);
speed = 255;
 
}
void forward(){
  digitalWrite(7,HIGH);
  digitalWrite(10,HIGH);
}
void back(){
   digitalWrite(12,HIGH);
  digitalWrite(11,HIGH);
}
void left(){
  digitalWrite(7,HIGH);
  digitalWrite(11,HIGH);
}
void right(){
    digitalWrite(10,HIGH);
  digitalWrite(12,HIGH);
}
void stop(){
   digitalWrite(7,LOW);
  digitalWrite(12,LOW);
  digitalWrite(11,LOW);
  digitalWrite(10,LOW);
}
 
void loop() {
if(BT.available()){
  t = BT.read();
  p = BT.read();
  Serial.println(t);
}
if(t == 'F'){            //move  forward(all motors rotate in forward direction)
  forward();
}
else if(t == 'B'){      //move reverse (all  motors rotate in reverse direction)
  back();
}
  
else if(t == 'L'){      //turn right (left side motors rotate in forward direction,  right side motors doesn't rotate)
  left();
}
 
else  if(t == 'R'){      //turn left (right side motors rotate in forward direction, left  side motors doesn't rotate)
  right();
}

else if(t ==  'W'){    //turn led on or off)
  digitalWrite(9,HIGH);
}
else if(t == 'w'){
  digitalWrite(9,LOW);
}
else if(t == 'V'){
  digitalWrite(13,HIGH);
}
else if(t == 'v'){
  digitalWrite(13,LOW);
}else if(t== 'X'){
Extra = true;
}else if (t == 'x'){
  Extra = false;
}
if (Extra){

}
 
else if(t == 'S'){      //STOP (all motors stop)
  stop();
}
if(p == '1'){
speed = 100;
}
else if(p == '2'){
speed = 130;
}
else if(p == '3'){
speed = 150;
}
else if(p == '4'){
speed = 180;
}
else if(p == '5'){
speed = 200;
}
else if(p == '6'){
speed = 210;
}
else if(p == '7'){
speed = 220;
}
else if(p == '8'){
speed = 230;
}
else if(p == '9'){
speed = 255;
}

analogWrite(enA,speed);
analogWrite(enB,speed); 
delay(1);
}
/* if (wallDist()<2){
  stop ();
  digitalWrite(13,HIGH);
  delay(100);
  back();
  delay(500);
  left();
  delay(300);
  stop();
  digitalWrite(13,LOW);
  delay (1);
  
}*/
