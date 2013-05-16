//Define Pins
int motorPin1 = 8;
int motorPin2 = 9;
int Press2 = 2;
int Press3 = 3;
int Press4 = 4;
int Press5 = 5;
int stada2 = 0;
int stada3 = 0;
int stada4 = 0;
int stada5 = 0;

void setup()
{
  //Set the pin as an output
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(Press2, INPUT);
  pinMode(Press3, INPUT);
  pinMode(Press4, INPUT);
  pinMode(Press5, INPUT); 

}

void loop()
{
  stada2 = digitalRead(Press2);
  stada3 = digitalRead(Press3);
  stada4 = digitalRead(Press4);
  stada5 = digitalRead(Press5);
  
  if (stada2 == HIGH)
  {
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, HIGH);
    delay(3000);
  }
  else  if (stada3 == HIGH) 
  { 
    digitalWrite(motorPin1, HIGH);
    delay(6000);
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, HIGH);
    delay(3000);
  }
  else if (stada4 == HIGH)
  {
    digitalWrite(motorPin1, HIGH);
    delay(9000);
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, HIGH);
    delay(3000);
  }
  else if (stada5 == HIGH)
  {
    digitalWrite(motorPin1, HIGH);
    delay(9000);
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, HIGH);
    delay(3000);
  }
  else
  {
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, LOW);
  }
  }
