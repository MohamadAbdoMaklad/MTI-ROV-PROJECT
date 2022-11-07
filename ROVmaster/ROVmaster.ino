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
  //int gap_start = 0;
  //int gap_point = 1;
  //int gap_end = 3;

  int x1 = (int) map(analogRead(A0), 1023, 0, gap_start, gap_end);
  int y1 = (int) map(analogRead(A1), 1023, 0, gap_start, gap_end);
  int x2 = (int) map(analogRead(A2), 1023, 0, gap_start, gap_end);
  int y2 = (int) map(analogRead(A3), 1023, 0, gap_start, gap_end);
  //int p1 = (int) analogRead(A4) / 4;
  //int p2 = (int) analogRead(A5) / 4;
  //int p3 = (int) map(analogRead(A6), 1023, 0, 0, 255);
  int p1 = (int) map(analogRead(A4), 0, 1023, 110, 255);
  if (p1 <120)
  {
    p1 = 0;
  }
  
  if (x1 < gap_point && y1 == gap_point) {
    forward(p1);
  } else if (x1 > gap_point && y1 == gap_point) {
    backword(p1);
  } else if (y1 < gap_point && x1 == gap_point) {
    right(p1);
  } else if (y1 > gap_point && x1 == gap_point) {
    left(p1);
  } else if (x1 < gap_point && y1 < gap_point) {
    fr(p1);
  } else if (x1 < gap_point && y1 > gap_point) {
    fl(p1);
  } else if (x1 > gap_point && y1 < gap_point) {
    br(p1);
  } else if (x1 > gap_point && y1 > gap_point) {
    bl(p1);
  } else if (x1==gap_point && y1==gap_point){
    xystop();
  }
  else{
    xystop();
  }
  /*
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
  */
}