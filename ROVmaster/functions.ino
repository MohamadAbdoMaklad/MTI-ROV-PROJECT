void motor1 (int s,int d)
{
  digitalWrite(22,d);
  analogWrite(2,s);
}
void motor2 (int s,int d)
{
  digitalWrite(23,d);
  analogWrite(3,s);
}
void motor3 (int s,int d)
{
  digitalWrite(24,d);
  analogWrite(4,s);
}
void motor4 (int s,int d)
{
  digitalWrite(25,d);
  analogWrite(5,s); 
}
void motor5 (int s,int d)
{
  digitalWrite(26,d);
  analogWrite(6,s);
}
void motor6 (int s,int d)
{
  digitalWrite(27,d);
  analogWrite(7,s);
}
void forward (int s)
{
  motor1(s,1);
  motor2(s,1);
  motor3(s,0);
  motor4(s,0);
}
void backword (int s)
{
  motor1(s,0);
  motor2(s,0);
  motor3(s,1);
  motor4(s,1);
}
void right (int s)
{
  motor1(s,1);
  motor2(s,1);
  motor3(s,1);
  motor4(s,1);
}
void left (int s)
{
  motor1(s,0);
  motor2(s,0);
  motor3(s,0);
  motor4(s,0);
}
void xystop (void)
{
  motor1(0,0);
  motor2(0,0);
  motor3(0,0);
  motor4(0,0);
}
void up (int s)
{
  motor5(s,0);
  motor6(s,1);
}
void down (int s)
{
  motor5(s,1);
  motor6(s,0);
}
void zstop (void)
{
  motor5(0,0);
  motor6(0,0);
}