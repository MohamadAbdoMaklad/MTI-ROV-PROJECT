void motor1 (int s,bool d)
{
  digitalWrite(22,d);
  analogWrite(2,s);
}
void motor2 (int s,bool d)
{
  digitalWrite(23,d);
  analogWrite(3,s);
}
void motor3 (int s,bool d)
{
  digitalWrite(24,d);
  analogWrite(4,s);
}
void motor4 (int s,bool d)
{
  digitalWrite(25,d);
  analogWrite(5,s); 
}
void motor5 (int s,bool d)
{
  digitalWrite(26,d);
  analogWrite(6,s);
}
void motor6 (int s,bool d)
{
  digitalWrite(27,d);
  analogWrite(7,s);
}
/*===================================================*/
void forward (int s)
{ 
  motor1(0,1);
  motor2(0,1);
  motor3(s,0);
  motor4(s,0);
  Serial.println("forward");
  Serial.println(s);
}
void backword (int s)
{
  motor1(s,0);
  motor2(s,0);
  motor3(0,1);
  motor4(0,1);
  Serial.println("Backword");
  Serial.println(s);
}
void right (int s)
{
  motor1(s,1);
  motor2(0,1);
  motor3(s,1);
  motor4(0,1);
  Serial.println("right");
  Serial.println(s);
}
void left (int s)
{
  motor1(0,0);
  motor2(s,0);
  motor3(0,0);
  motor4(s,0);
  Serial.println("left");
  Serial.println(s);
}
/*===================================================*/
void fr (int s)
{
  motor1(0,0);
  motor2(s,0);
  motor3(s,1);
  motor4(0,0);
  Serial.println("fr");
  Serial.print(s);
}
void fl (int s)
{
  motor1(s,0);
  motor2(0,0);
  motor3(0,0);
  motor4(s,1);
  Serial.println("fl");
  Serial.print(s);
}
void br (int s)
{
  motor1(0,0);
  motor2(s,1);
  motor3(s,0);
  motor4(0,0);
  Serial.println("br");
  Serial.print(s);
}
void bl (int s)
{
  motor1(s,1);
  motor2(0,0);
  motor3(0,0);
  motor4(s,0);
  Serial.println("bl");
  Serial.print(s);
}
/*===================================================*/
void xystop (void)
{
  motor1(0,0);
  motor2(0,0);
  motor3(0,0);
  motor4(0,0);
  Serial.println("stop");
}
void up (int s)
{
  motor5(s,1);
  motor6(s,1);
}
void down (int s)
{
  motor5(s,0);
  motor6(s,0);
}
void zstop (void)
{
  motor5(0,0);
  motor6(0,0);
}
/*===================================================*/
void teltup (int s)
{
  motor5(s,1);
  motor6(s,0);
}
void teltdown (int s)
{
  motor5(s,0);
  motor6(s,1);
}
void rotatecw (int s)
{
  motor1(0,0);
  motor2(s,1);
  motor3(s,1);
  motor4(0,0);
}
void rotateccw (int s)
{
  motor1(s,1);
  motor2(0,0);
  motor3(0,0);
  motor4(s,1);
}
/*===================================================*/
void StepperMOTOR_1(int speed,bool direction)
{
int stepsPerRevolution = 10;
  digitalWrite(28, direction);
  for(int x = 0; x < stepsPerRevolution; x++)
  {
  digitalWrite(29, HIGH);
  delayMicroseconds(speed);
  digitalWrite(29, LOW);
  delayMicroseconds(speed);
  }
  stepsPerRevolution ++;
}

void StepperMOTOR_2(int speed,bool direction)
{
int stepsPerRevolution = 10;
  digitalWrite(30, direction);
  for(int x = 0; x < stepsPerRevolution; x++)
  {
  digitalWrite(31, HIGH);
  delayMicroseconds(speed);
  digitalWrite(31, LOW);
  delayMicroseconds(speed);
  }
  stepsPerRevolution ++;
}

void StepperMOTOR_3(int speed,bool direction)
{
int stepsPerRevolution = 10;
  digitalWrite(32, direction);
  for(int x = 0; x < stepsPerRevolution; x++)
  {
  digitalWrite(33, HIGH);
  delayMicroseconds(speed);
  digitalWrite(33, LOW);
  delayMicroseconds(speed);
  }
  stepsPerRevolution ++;
}

void StepperMOTOR_4(int speed,bool direction)
{
int stepsPerRevolution = 10;
  digitalWrite(34, direction);
  for(int x = 0; x < stepsPerRevolution; x++)
  {
  digitalWrite(35, HIGH);
  delayMicroseconds(speed);
  digitalWrite(35, LOW);
  delayMicroseconds(speed);
  }
  stepsPerRevolution ++;
}
/*===================================================*/
void module_U(int Speed)
{
  StepperMOTOR_1(Speed,HIGH);
  StepperMOTOR_2(Speed,HIGH);
}
void module_D(int Speed)
{
  StepperMOTOR_1(Speed,LOW);
  StepperMOTOR_2(Speed,LOW);
}
void module_R(int Speed)
{
  StepperMOTOR_3(Speed,HIGH);
}
void module_L(int Speed)
{
  StepperMOTOR_3(Speed,LOW);
}
void module_F(int Speed)
{
  StepperMOTOR_4(Speed,HIGH);
}
void module_B(int Speed)
{
  StepperMOTOR_4(Speed,LOW);
}