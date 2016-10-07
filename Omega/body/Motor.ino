void Set(int order)
{
  switch(order){
 case'1'://forward
 digitalWrite( commanlpwmA,HIGH);

 digitalWrite( commanlpwmC,HIGH);
 
 analogWrite(rpwmPinA,LOW);
 analogWrite(rpwmPinB,LOW);
 analogWrite(rpwmPinC,LOW);
 analogWrite(rpwmPinD,LOW);
 break;
 case'2'://backward 
 digitalWrite( rpwmPinA,HIGH);
 digitalWrite( rpwmPinB,HIGH);
 digitalWrite( rpwmPinC,HIGH);
 digitalWrite( rpwmPinD,HIGH); 
 digitalWrite(commanlpwmA,LOW);
 
 digitalWrite(commanlpwmC,LOW);
 
 break;
 case'3'://right 
  digitalWrite( rpwmPinB,HIGH);  
  digitalWrite( commanlpwmA,HIGH);
 
  digitalWrite( commanlpwmC,HIGH);
 
  
  digitalWrite( rpwmPinD,HIGH);
  digitalWrite( rpwmPinB,HIGH);
  analogWrite( rpwmPinA,LOW);
  analogWrite( rpwmPinC,LOW);
  break;
 case'4'://left
  digitalWrite( rpwmPinB,HIGH);  
  digitalWrite( commanlpwmA,HIGH);
  
  digitalWrite( commanlpwmC,HIGH);

  
  digitalWrite( rpwmPinA,HIGH);
  digitalWrite( rpwmPinC,HIGH);
   analogWrite(rpwmPinB,LOW);
    analogWrite(rpwmPinD,LOW);
    break;
   case'5': //stop 
  digitalWrite( rpwmPinB,HIGH);  
  digitalWrite( commanlpwmA,HIGH);
  
  digitalWrite( commanlpwmC,HIGH);

  
  digitalWrite( rpwmPinA,HIGH);
  digitalWrite( rpwmPinC,HIGH);
  digitalWrite( rpwmPinD,HIGH);
  digitalWrite(rpwmPinB,HIGH);
  break;
  }} 
