#include <Wire.h>

#include <SoftwareSerial.h>
SoftwareSerial myserial(2,3);
void Set(int order);
  
int rpwmPinA=10;


int rpwmPinB=5;

int commanlpwmA=4;

int rpwmPinC=6;

 
int rpwmPinD=9;

int commanlpwmC=7;

int order ;

 void setup() {
myserial.begin(9600)  ;
 
 pinMode(rpwmPinA,OUTPUT);
 pinMode(commanlpwmA,OUTPUT);

 pinMode(rpwmPinB,OUTPUT);

 
 pinMode(rpwmPinC,OUTPUT);
 pinMode(commanlpwmC,OUTPUT);
 
 pinMode(rpwmPinD,OUTPUT);
  pinMode(13,OUTPUT);
 Wire.begin();
}

void loop() {
  if(myserial.available()>1){
  order= myserial.parseInt();
digitalWrite(13,HIGH);
delay(500);
  Set(order);
  }
  myserial.flush();
  delay(20);
}
