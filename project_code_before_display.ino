byte directionPin = 7;
byte stepPin = 8;
int R1 = A3;
int R2 = A5;
int d = 15;
void setup()
{
  pinMode(directionPin, OUTPUT);
  pinMode(stepPin, OUTPUT);

  pinMode(R1, INPUT);
  pinMode(R2, INPUT);
  
  digitalWrite(directionPin, HIGH);
  digitalWrite(stepPin, LOW);
  
}
void loop()
{ 
  if (analogRead(R1)<500)
  {
    digitalWrite(directionPin, HIGH);
  }
  else
  {
    digitalWrite(directionPin, LOW);
  }

  d=70-50*analogRead(R2)/1000;       // for potentiometer
  

    digitalWrite(stepPin,HIGH);
    delay(d);
    digitalWrite(stepPin,LOW);
    delay(d);
  // digitalWrite(directionPin, HIGH);
  // for(int i=0;i<201;i++)
  // {
  //   digitalWrite(stepPin,HIGH);
  //   delay(15);
  //   digitalWrite(stepPin,LOW);
  //   delay(15);
  // }
  
  // digitalWrite(directionPin, LOW);
  
  // for(int i=0;i<201;i++)
  // {
  //   digitalWrite(stepPin,HIGH);
  //   delay(d);
  //   digitalWrite(stepPin,LOW);
  //   delay(d);
  // }
}               