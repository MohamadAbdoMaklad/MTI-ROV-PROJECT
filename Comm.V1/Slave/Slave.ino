#include <EasyTransfer.h>
#include "functions.h"
EasyTransfer ETin, ETout;
int x1,y1,x2,y2,p1,p3,p3_1,p3_2;
struct RECEIVE_DATA_STRUCTURE{ 
  int x1;
  int y1;
  int x2;
  int y2;
  int p1;
  int p3;
  int p3_1;
  int p3_2;
}rxdata;

struct SEND_DATA_STRUCTURE{ 
  int inmsg;
}txdata;
void setup() {
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
  delay(10000);
  Serial.begin(9600);
  ETin.begin(details(rxdata), &Serial);
  ETout.begin(details(txdata), &Serial); 
}

void loop() {
  ETin.receiveData();
  x1=rxdata.x1;
  y1=rxdata.y1;
  x2=rxdata.x2;
  y2=rxdata.y2;
  p1=rxdata.p1;
  p3=rxdata.p3;
  p3_1=rxdata.p3_1;
  p3_2=rxdata.p3_2;

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
  
  //========================================================//
  if (x2 < gap_point && y2 == gap_point) {
    rotatecw(p1);
  }
  else if (x2 > gap_point && y2 == gap_point) {
    rotateccw(p1);
  }
  else if (y2 < gap_point && x2 == gap_point) {
    teltup(p1);
  }
  else if (y2 > gap_point && x2 == gap_point) {
    teltdown(p1);
  }
  //========================================================//
  if (p3 > gap_point)
  {
    up(p3_1);
  }
  else if (p3 < gap_point)
  {
    down(p3_2);
  }
  else
  {
    zstop();
  }
  ETout.sendData(); 
}
