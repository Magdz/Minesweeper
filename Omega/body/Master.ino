void buttonX(byte value){
   Wire.beginTransmission(8);        
  Wire.write(value);              
  Wire.endTransmission();
}

