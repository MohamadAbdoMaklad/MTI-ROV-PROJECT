#include <Arduino.h>
#include "Function.h"
void motor1(int s, bool d)
{
    digitalWrite(22, d);
    analogWrite(2, s);
}
void motor2(int s, bool d)
{
    digitalWrite(23, d);
    analogWrite(3, s);
}
void motor3(int s, bool d)
{
    digitalWrite(24, d);
    analogWrite(4, s);
}
void motor4(int s, bool d)
{
    digitalWrite(25, d);
    analogWrite(5, s);
}
void motor5(int s, bool d)
{
    digitalWrite(26, d);
    analogWrite(6, s);
}
void motor6(int s, bool d)
{
    digitalWrite(27, d);
    analogWrite(7, s);
}
/*===================================================*/
void forward(int s)
{
    motor1(s, 1);
    motor2(s, 1);
    motor3(s, 0);
    motor4(s, 0);
    Serial.println("forward");
    Serial.println(s);
}
void backword(int s)
{
    motor1(s, 0);
    motor2(s, 0);
    motor3(s, 1);
    motor4(s, 1);
    Serial.println("Backword");
    Serial.println(s);
}
void right(int s)
{
    motor1(s, 1);
    motor2(s, 1);
    motor3(s, 1);
    motor4(s, 1);
    Serial.println("right");
    Serial.println(s);
}
void left(int s)
{
    motor1(s, 0);
    motor2(s, 0);
    motor3(s, 0);
    motor4(s, 0);
    Serial.println("left");
    Serial.println(s);
}
/*===================================================*/
void fr(int s)
{
    motor1(s, 0);
    motor3(s, 0);
    Serial.println("fr");
    Serial.println(s);
}
void fl(int s)
{
    motor2(s, 0);
    motor4(s, 0);
    Serial.println("fl");
    Serial.println(s);
}
void br(int s)
{
    motor1(s, 1);
    motor3(s, 1);
    Serial.println("br");
    Serial.println(s);
}
void bl(int s)
{
    motor2(s, 1);
    motor4(s, 1);
    Serial.println("bl");
    Serial.println(s);
}
/*===================================================*/
void xystop(void)
{
    motor1(0, 0);
    motor2(0, 0);
    motor3(0, 0);
    motor4(0, 0);
    Serial.println("stop");
}
void up(int s)
{
    motor5(s, 0);
    motor6(s, 1);
}
void down(int s)
{
    motor5(s, 1);
    motor6(s, 0);
}
void zstop(void)
{
    motor5(0, 0);
    motor6(0, 0);
}
/*===================================================*/
void teltup(int s)
{
    motor5(s, 1);
    motor6(s, 0);
    Serial.println("                            TU");
    Serial.println(s);
}
void teltdown(int s)
{
    motor5(s, 0);
    motor6(s, 1);
    Serial.println("                            TD");
    Serial.println(s);
}
void rotatecw(int s)
{
    motor1(s, 0);
    motor2(s, 1);
    motor3(s, 0);
    motor4(s, 1);
    Serial.println("                            RCW");
    Serial.println(s);
}
void rotateccw(int s)
{
    motor1(s, 1);
    motor2(s, 0);
    motor3(s, 1);
    motor4(s, 0);
    Serial.println("                            RCCW");
    Serial.println(s);
}
/*===================================================*/
