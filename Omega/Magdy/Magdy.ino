#include <Wire.h>

#include <SoftwareSerial.h>

SoftwareSerial mySerial(2, 3); //RX, TX

int buttonPin = 8;
int order ;
int get_value;
void setup() {
  pinMode(buttonPin, INPUT);
  mySerial.begin(9600);
  Wire.begin(8);                
  Wire.onReceive(receiveEvent);
}

void loop() {
 

  
  if(digitalWrite(buttonPin,HIGH)){
    mySerial.println(1);
  }else if(get_value==1){
    mySerial.println(2);
  }else{
    mySerial.println(3);
  }

  delay(20);//delay little for better serial communication
}

