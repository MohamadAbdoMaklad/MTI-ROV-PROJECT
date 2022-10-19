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
  pinMode(A6, INPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(22, OUTPUT);
  pinMode(23, OUTPUT);
  pinMode(24, OUTPUT);
  pinMode(25, OUTPUT);
  pinMode(26, OUTPUT);
  pinMode(27, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int x1 = map(analogRead(A0), 1023, 0, 0, 4);
  int y1 = map(analogRead(A1), 1023, 0, 0, 4);
  int x2 = map(analogRead(A2), 1023, 0, 0, 4);
  int y2 = map(analogRead(A3), 1023, 0, 0, 4);
  int p1 = analogRead(A4) / 4;
  int p2 = analogRead(A5) / 4;
  int p3 = map(analogRead(A6), 1023, 0, 0, 255);


  if (x1 < 2 && y1 == 2) {
    forward(p1);
    Serial.println("forward");
    Serial.println(p1);
  } else if (x1 > 2 && y1 == 2) {
    backword(p1);
    Serial.println("Backword");
    Serial.println(p1);
  } else if (y1 < 2 && x1 == 2) {
    right(p1);
    Serial.println("right");
    Serial.println(p1);
  } else if (y1 > 2 && x1 == 2) {
    left(p1);
    Serial.println("left");
    Serial.println(p1);
  } else if (x1 < 2 && y1 < 2) {
    fr(p1);
    Serial.println("fr");
    Serial.print(p1);
  } else if (x1 < 2 && y1 > 2) {
    fl(p1);
    Serial.println("fl");
    Serial.print(p1);
  } else if (x1 > 2 && y1 < 2) {
    br(p1);
    Serial.println("br");
    Serial.print(p1);
  } else if (x1 > 2 && y1 > 2) {
    bl(p1);
    Serial.println("bl");
    Serial.print(p1);
  } else if (x1==2 && y1==2){
    xystop();
    Serial.println("stop");
  }
  else{
    break;
  }
  /*----------------------------*/
  if (p3 < 120) {
    up(p3);
    Serial.println("up");
    Serial.print(p3);
  } else if (p3 > 135) {
    down(p3);
    Serial.println("down");
    Serial.print(p3);
  } else {
    zstop();
  }
}