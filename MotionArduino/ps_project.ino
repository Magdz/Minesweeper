#include <PS2X_lib.h> 
#define PS2_DAT        13    
#define PS2_CMD        11  
#define PS2_SEL        10  
#define PS2_CLK       12
int enPinA=22;
int rpwmPinA=2;
int lpwmPinA=3;
int enPinB=23;
int rpwmPinB=4;
int lpwmPinB=5;
int enPinC=24;
int rpwmPinC=6;
int lpwmPinC=7;
int trigPin=26;
int echoPin=27;
float echoTime;
int speedSnd=343;
float dist;
int enPinD=25;
int rpwmPinD=8;
int lpwmPinD=9;
boolean Flage=true;
//#define pressures true
#define pressures false
//#define rumble true
#define rumble false
PS2X ps2x;
 
int error = 0;
byte type = 0;
byte vibrate = 0;

void setup(){
   pinMode(trigPin,OUTPUT);
 pinMode(echoPin,INPUT);
   pinMode(enPinA,INPUT);
 pinMode(rpwmPinA,INPUT);
 pinMode(lpwmPinA,INPUT);
 pinMode(enPinB,INPUT);
 pinMode(rpwmPinB,INPUT);
 pinMode(lpwmPinB,INPUT);
 pinMode(enPinC,INPUT);
 pinMode(rpwmPinC,INPUT);
 pinMode(lpwmPinC,INPUT);
 pinMode(enPinD,INPUT);
 pinMode(rpwmPinD,INPUT);
 pinMode(lpwmPinD,INPUT);
 
  pinMode(13, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
  
  Serial.begin(9600);
  
  delay(300);
    error = ps2x.config_gamepad(PS2_CLK, PS2_CMD, PS2_SEL, PS2_DAT, pressures, rumble);
  if(error == 0){
    Serial.print("Found Controller, configured successful ");
    Serial.print("pressures = ");
      if (pressures)
    Serial.println("true ");
  else
    Serial.println("false");
  Serial.print("rumble = ");
  if (rumble)
    Serial.println("true)");
  else
    Serial.println("false");
    Serial.println("Try out all the buttons, X will vibrate the controller, faster as you press harder;");
    Serial.println("holding L1 or R1 will print out the analog stick values.");
    Serial.println("Note: Go to www.billporter.info for updates and to report bugs.");
  }  
  else if(error == 1)
    Serial.println("No controller found, check wiring, see readme.txt to enable debug. visit www.billporter.info for troubleshooting tips");
   
  else if(error == 2)
    Serial.println("Controller found but not accepting commands. see readme.txt to enable debug. Visit www.billporter.info for troubleshooting tips");

  else if(error == 3)
    Serial.println("Controller refusing to enter Pressures mode, may not support it. ");
    type = ps2x.readType(); 
  switch(type) {
    case 0:
      Serial.print("Unknown Controller type found ");
      break;
    case 1:
      Serial.print("DualShock Controller found ");
      break;
    case 2:
      Serial.print("GuitarHero Controller found ");
      break;
  case 3:
      Serial.print("Wireless Sony DualShock Controller found ");
      break;
   }
    }

   
    
void loop() {
  //  Serial.print("yes");
 if(error == 1) 
    return; 
  

  else { //DualShock Controller
 if(Flage){
    ps2x.read_gamepad(false, vibrate); 
    if(ps2x.Button(PSB_PAD_UP)) {  
      Serial.println("yes");    
      Set('F',0);
    }

 else if(ps2x.Button(PSB_PAD_DOWN)) {  
      Serial.println("no");    
      Set('B',0);
    }
     else if(ps2x.Button(PSB_PAD_RIGHT)) {  
      Serial.println("no");    
      Set('R',0);
    }
     else if(ps2x.Button(PSB_PAD_LEFT)) {  
      Serial.println("no");    
      Set('L',0);
    }
    
    else
    Set('P',255);
 }
    digitalWrite(trigPin,LOW);
    delay(2);
    digitalWrite(trigPin,HIGH);
    delay(1);
    digitalWrite(trigPin,LOW);
    echoTime=pulseIn(echoPin,HIGH)/2.0;
    dist=(speedSnd*echoTime)/(float)pow(10,4);
    Serial.println(dist);
    if(dist<5){
       Set('P',255);
       Flage=false;
    }else
     Flage=true;
  } 
}
void Set(char index,int Speed)
{
  switch(index){
 case'F':digitalWrite( enPinA,HIGH);
 digitalWrite( enPinB,HIGH);
 digitalWrite( enPinC,HIGH);
 digitalWrite( enPinD,HIGH);
 digitalWrite( lpwmPinA,HIGH);
 digitalWrite( lpwmPinB,HIGH);
 digitalWrite( lpwmPinC,HIGH);
 digitalWrite( lpwmPinD,HIGH);
 analogWrite(rpwmPinA,LOW);
 analogWrite(rpwmPinB,LOW);
 analogWrite(rpwmPinC,LOW);
 analogWrite(rpwmPinD,LOW);
 break;
 case'B':
 digitalWrite( enPinA,HIGH);
 digitalWrite( enPinB,HIGH);
 digitalWrite( enPinC,HIGH);
 digitalWrite( enPinD,HIGH);  
 digitalWrite( rpwmPinA,HIGH);
 digitalWrite( rpwmPinB,HIGH);
 digitalWrite( rpwmPinC,HIGH);
 digitalWrite( rpwmPinD,HIGH); 
 analogWrite(lpwmPinA,Speed);
 analogWrite(lpwmPinB,Speed);
 analogWrite(lpwmPinC,Speed);
 analogWrite(lpwmPinD,Speed);
 break;
 case'R':
  digitalWrite( enPinA,HIGH);
  digitalWrite( enPinB,HIGH);
  digitalWrite( enPinC,HIGH);
  digitalWrite( enPinD,HIGH); 
  digitalWrite( rpwmPinB,HIGH);  
  digitalWrite( lpwmPinA,HIGH);
  digitalWrite( lpwmPinB,HIGH);
  digitalWrite( lpwmPinC,HIGH);
  digitalWrite( lpwmPinD,HIGH);
  digitalWrite( rpwmPinD,HIGH);
  digitalWrite(rpwmPinB,HIGH);
  analogWrite( rpwmPinA,Speed);
  analogWrite( rpwmPinC,Speed);
  break;
 case'L':
  digitalWrite( enPinA,HIGH);
  digitalWrite( enPinB,HIGH);
  digitalWrite( enPinC,HIGH);
  digitalWrite( enPinD,HIGH); 
  digitalWrite( rpwmPinB,HIGH);  
  digitalWrite( lpwmPinA,HIGH);
  digitalWrite( lpwmPinB,HIGH);
  digitalWrite( lpwmPinC,HIGH);
  digitalWrite( lpwmPinD,HIGH);
  digitalWrite( rpwmPinA,HIGH);
  digitalWrite( rpwmPinC,HIGH);
   analogWrite(rpwmPinB,Speed);
    analogWrite(rpwmPinD,Speed);
    break;
   case'P': 
    digitalWrite( enPinA,HIGH);
  digitalWrite( enPinB,HIGH);
  digitalWrite( enPinC,HIGH);
  digitalWrite( enPinD,HIGH); 
  digitalWrite( rpwmPinB,HIGH);  
  digitalWrite( lpwmPinA,HIGH);
  digitalWrite( lpwmPinB,HIGH);
  digitalWrite( lpwmPinC,HIGH);
  digitalWrite( lpwmPinD,HIGH);
  digitalWrite( rpwmPinA,HIGH);
  digitalWrite( rpwmPinC,HIGH);
    digitalWrite( rpwmPinD,HIGH);
  digitalWrite(rpwmPinB,HIGH);
  break;
  }} 
