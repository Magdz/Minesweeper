
#include <SoftwareSerial.h>

SoftwareSerial mySerial(2, 3); 

int order;

void setup() {
  mySerial.begin(9600);
}

void loop() {

  
  
  if(mySerial.available() > 1){    
    order = mySerial.parseInt();
    //mafroud ta7ot 2l connection hna       
    }
   delay(20);
  }

 


