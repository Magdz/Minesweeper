

#include <SoftwareSerial.h>
#include <PS2X_lib.h> 
#define PS2_DAT        13    
#define PS2_CMD        11  
#define PS2_SEL        10  
#define PS2_CLK       12


SoftwareSerial myserial (2,3);

//#define pressures true
#define pressures false
//#define rumble true
#define rumble false
PS2X ps2x;

void sent(int x);
    
int error = 0;
byte type = 0;
byte vibrate = 0;

void setup() {
  myserial.begin(9600);
  Serial.begin(4800); 

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
   if(error == 1) 
    return; 
  

  else { //DualShock Controller
     ps2x.read_gamepad(false, vibrate); 
     
 if(ps2x.Button(PSB_PAD_UP))      
      sent(1);

 else if(ps2x.Button(PSB_PAD_DOWN))     
      sent(2);
    
     else if(ps2x.Button(PSB_PAD_RIGHT))     
     sent(3);
    
     else if(ps2x.Button(PSB_PAD_LEFT))     
      sent(4);
    
    
    else
    sent(5);
   if (ps2x.NewButtonState(PSB_CROSS))
     sent(0);
  
  }
delay(20);
}
