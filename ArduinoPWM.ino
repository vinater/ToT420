//Define Pins
int motorPin = 9;

void setup()
{
  //Set the PWM Motor pin as an output
  pinMode(motorPin, OUTPUT);
}

void loop()
{
  //Increase Motor Speed from 0 -> 255
  for (int i=245; i<=255; i++)
  {
    analogWrite(motorPin, i);
    delay(10);
  }
  
  delay(1900); //Hold it!
  
  //Decrease Motor Speed from 255 -> 0
  for(int i=255; i>=0; i--)
  {
    analogWrite(motorPin, i);
    delay(10);
  }
  
  delay(500000000); //Hold it!
  
}
