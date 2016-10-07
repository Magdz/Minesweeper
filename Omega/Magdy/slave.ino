
void receiveEvent(int howMany) {
  if (1 < Wire.available()) { 
      get_value= Wire.read(); 
  }else 
   get_value=0;
}
