#include <EasyTransfer.h>
EasyTransfer ETin, ETout;
#define gap_start 0
#define gap_point 1
#define gap_end 3
//int x1,y1,x2,y1,p1,p3,p3_1,p3_2;
struct RECEIVE_DATA_STRUCTURE{
  /*
  float temp;
  float pres;
  float alt;
  float rspres;
  float ralt;
  */
  //int inmsg;
  
}rxdata;

struct SEND_DATA_STRUCTURE{ 
  int x1;
  int y1;
  int x2;
  int y2;
  int p1;
  int p3_r;
  int mod_R;
  int mod_L;
  int mod_F;
  int mod_B;
  int mod_U;
  int mod_D;
  int mod_Speed;
}txdata;
void setup() {
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  pinMode(A5, INPUT);
  
  pinMode(A6, INPUT);//speed
  pinMode(28,INPUT);//f
  pinMode(29,INPUT);//b
  pinMode(30,INPUT);//r
  pinMode(31,INPUT);//l
  pinMode(32,INPUT);//u
  pinMode(33,INPUT);//d
 
  delay(5000);
  Serial.begin(9600);
  ETin.begin(details(rxdata), &Serial);
  ETout.begin(details(txdata), &Serial); 
}

void loop() {
  //ETin.receiveData();
  txdata.p1 = (int) map(analogRead(A4), 0, 1023, 110, 255);
  txdata.x1 = (int) map(analogRead(A0), 1023, 0, gap_start, gap_end);
  txdata.y1 = (int) map(analogRead(A1), 1023, 0, gap_start, gap_end);
  txdata.x2 = (int) map(analogRead(A2), 1023, 0, gap_start, gap_end);
  txdata.y2 = (int) map(analogRead(A3), 1023, 0, gap_start, gap_end);
  txdata.p3_r = analogRead(A5);
  if (txdata.p1 <120)
  {
    txdata.p1 = 0;
  }
  //stepper motors//
  txdata.mod_F = digitalRead(28);
  txdata.mod_B = digitalRead(29);
  txdata.mod_R = digitalRead(30);
  txdata.mod_L = digitalRead(31);
  txdata.mod_U = digitalRead(32);
  txdata.mod_D = digitalRead(33);
  txdata.mod_Speed = map(analogRead(A6),0,1023,0,2000);
  ETout.sendData(); 
 /*
  Serial.print("Temperature = ");
  Serial.print(rxdata.temp);
  Serial.println(" *C");
  
  Serial.print("Pressure = ");
  Serial.print(rxdata.pres);
  Serial.println(" Pa");

  Serial.print("Altitude = ");
  Serial.print(rxdata.alt);
  Serial.println(" meters");

  Serial.print("Pressure at sealevel (calculated) = ");
  Serial.print(rxdata.rspres);
  Serial.println(" Pa");

  Serial.print("Real altitude = ");
  Serial.print(rxdata.ralt);
  Serial.println(" meters");

  Serial.println();
  delay(500);
*/  
}
