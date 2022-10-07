#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
void setup() {
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  pinMode(A5, INPUT);
  pinMode(A6, NIPUT);
  Serial.begin(9600);
}

void loop() {
  float x1 = map((float)analogRead(A0), 512, 0, 0, 255);
  float y1 = map((float)analogRead(A1), 512, 0, 0, 255);
  float x2 = map((float)analogRead(A2), 512, 0, 0, 255);
  float y2 = map((float)analogRead(A3), 512, 0, 0, 255);
  float p1 = (float)analogRead(A4)/4;
  float p2 = (float)analogRead(A5)/4;
  float p3 = map((float)analogRead(A6), 512, 0, 0, 255);;
  
  
  if (x1<-10 && y1>-10 && y1<10) 
  {
    forward((int)p1);
    Serial.println("forward");
    Serial.println(p1);
  }
  else if(x1>10 && y1>-10 && y1<10)
  {
    backword((int)p1);
    Serial.println("Backword");
    Serial.println(p1);
  }
  else if(y1<-1 && x1>-10 && x1<100)
  {
    right((int)p1);
    Serial.println("right");
    Serial.println(p1);
  }
  else if (y1>10 && x1>-10 && x1<10)
  {
    left((int)p1);
    Serial.println("left");
    Serial.println(p1);
  }
  else if (x1<-10 && y1<10)
  else
  {
    xystop();
    Serial.println("stop");
  }
  if (p3>10)
  {
    up(p3);
    Serial.println("up");
    Serial.print(p3);
  }
  else if (p3<-10 && y1<-1)
  {
    down(p3);
    Serial.println("down");
    Serial.print(p3);
  }
  else if (x1>10 && y1<-1)
  {
    fr((int)p1);
    Serial.println("fr");
    Serial.print(p1);
  }
  else if (x1>10 && y1>10)
  {
    fl((int)p1);
    Serial.println("fl");
    Serial.print(p1);
  }
  else if (x1>10 && y1<-1)
  {
    br((int)p1);
    Serial.println("br");
    Serial.print(p1);
  }
  else if (x1>10 && y1>10)
  {
    bl((int)p1);
    Serial.println("bl");
    Serial.print(p1);
  }
  else 
  {
    zstop();
  }
}