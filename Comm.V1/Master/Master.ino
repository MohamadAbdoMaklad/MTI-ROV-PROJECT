#include <EasyTransfer.h>
EasyTransfer ETin, ETout;
#define gap_start 0
#define gap_point 1
#define gap_end 3
//int x1,y1,x2,y1,p1,p3,p3_1,p3_2;
struct RECEIVE_DATA_STRUCTURE{ 
  int inmsg;  //messages back from the slave. 
}rxdata;

struct SEND_DATA_STRUCTURE{ 
  int x1;
  int y1;
  int x2;
  int y2;
  int p1;
  int p3;
  int p3_1;
  int p3_2;


}txdata;
void setup() {
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  pinMode(A5, INPUT);
  pinMode(A6, INPUT);
  delay(5000);
  Serial.begin(9600);
  ETin.begin(details(rxdata), &Serial);
  ETout.begin(details(txdata), &Serial); 
}

void loop() {
  ETin.receiveData();
  txdata.x1 = (int) map(analogRead(A0), 1023, 0, gap_start, gap_end);
  txdata.y1 = (int) map(analogRead(A1), 1023, 0, gap_start, gap_end);
  txdata.x2 = (int) map(analogRead(A2), 1023, 0, gap_start, gap_end);
  txdata.y2 = (int) map(analogRead(A3), 1023, 0, gap_start, gap_end);
  //int p1 = (int) analogRead(A4) / 4;
  //int p2 = (int) analogRead(A5) / 4;
  txdata.p3 = (int) map(analogRead(A5), 1023, 0, gap_start, gap_end);
  txdata.p3_1 = (int) map(analogRead(A5), 500, 1023, 0, 255);
  txdata.p3_2 = (int) map(analogRead(A5), 524, 0, 0, 255);
  
  txdata.p1 = (int) map(analogRead(A4), 0, 1023, 110, 255);
  if (txdata.p1 <120)
  {
    txdata.p1 = 0;
  }
  ETout.sendData(); 
}
