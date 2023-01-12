#include <EasyTransfer.h>
//#include <Wire.h>
//#include <Adafruit_BMP085.h>
#include "functions.h"
//Adafruit_BMP085 bmp;
EasyTransfer ETin, ETout;
int x1,y1,x2,y2,p1,p3,p3_r;
struct RECEIVE_DATA_STRUCTURE{ 
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
}rxdata;

struct SEND_DATA_STRUCTURE{ 
 /* 
  float temp;
  float pres;
  float alt;
  float rspres;
  float ralt;
  */
  //int inmsg;
  
}txdata;
void setup() {
  /*THRUSTER MOTOR 1*/
  pinMode(2, OUTPUT);
  pinMode(22, OUTPUT);
  /*THRUSTER MOTOR 2*/
  pinMode(3, OUTPUT);
  pinMode(23, OUTPUT);
  /*THRUSTER MOTOR 3*/
  pinMode(4, OUTPUT);
  pinMode(24, OUTPUT);
  /*THRUSTER MOTOR 4*/
  pinMode(5, OUTPUT);
  pinMode(25, OUTPUT);
  /*THRUSTER MOTOR 5*/
  pinMode(6, OUTPUT);
  pinMode(26, OUTPUT);
  /*THRUSTER MOTOR 6*/
  pinMode(7, OUTPUT);
  pinMode(27, OUTPUT);
  /*STEPPER MOTOR 1*/
  pinMode(28, OUTPUT);
  pinMode(29, OUTPUT);
  /*STEPPER MOTOR 1*/
  pinMode(30, OUTPUT);
  pinMode(31, OUTPUT);
  /*STEPPER MOTOR 1*/
  pinMode(32, OUTPUT);
  pinMode(33, OUTPUT);
  /*STEPPER MOTOR 1*/
  pinMode(34, OUTPUT);
  pinMode(35, OUTPUT);
/*====================*/
  delay(1000);
  Serial.begin(9600);
  ETin.begin(details(rxdata), &Serial);
  ETout.begin(details(txdata), &Serial); 
 /* 
  if (!bmp.begin()) {
	Serial.println("Could not find a valid BMP085 sensor, check wiring!");
	while (1) {}
  }
*/
}

void loop() {
  ETin.receiveData();
  x1=rxdata.x1;
  y1=rxdata.y1;
  x2=rxdata.x2;
  y2=rxdata.y2;
  p1=rxdata.p1;
  p3_r=rxdata.p3_r;
  
  if (x1 < gap_point && y1 == gap_point)
  {
    forward(p1);
  }
  else if (x1 > gap_point && y1 == gap_point)
  {
    backword(p1);
  }
  else if (y1 < gap_point && x1 == gap_point)
  {
    right(p1);
  }
  else if (y1 > gap_point && x1 == gap_point)
  {
    left(p1);
  }
  else if (x1 < gap_point && y1 < gap_point)
  {
    fr(p1);
  } 
  else if (x1 < gap_point && y1 > gap_point)
  {
    fl(p1);
  } 
  else if (x1 > gap_point && y1 < gap_point)
  {
    br(p1);
  } 
  else if (x1 > gap_point && y1 > gap_point)
  {
    bl(p1);
  } 
  else if (x1==gap_point && y1==gap_point){
    xystop();
  }
  else
  {
    xystop();
  }
  //========================================================//
  if (x2 < gap_point && y2 == gap_point)
  {
    rotatecw(p1);
  }
  else if (x2 > gap_point && y2 == gap_point)
  {
    rotateccw(p1);
  }
  else
  {
    zstop();
  }
//========================================================//
  if (p3_r>=578 && p3_r<=1023)
  {
    p3 = map(p3_r, 578, 1023, 120, 255);
    up(p3);
  }
  else if (p3_r<=450 && p3_r>=0)
  {
    p3 = map(p3_r, 450, 0, 120, 255);
    down(p3);
  }
  else
  {
    p3=0;
    if (y2 < gap_point && x2 == gap_point)
    {
      p3=0;
      teltup(p1);
    }
    else if (y2 > gap_point && x2 == gap_point)
    {
      p3=0;
      teltdown(p1);
    }
    else
    {
      zstop();
    }
  }
//========================================================//
  if (rxdata.mod_F==1)
  {
   module_F(rxdata.mod_Speed);
  }
  else if (rxdata.mod_B==1)
  {
   module_B(rxdata.mod_Speed);
  }

  if (rxdata.mod_R==1)
  {
   module_R(rxdata.mod_Speed);
  }
  else if (rxdata.mod_L==1)
  {
   module_L(rxdata.mod_Speed);
  }

  if (rxdata.mod_U==1)
  {
   module_U(rxdata.mod_Speed);
  }
  else if (rxdata.mod_D==1)
  {
   module_D(rxdata.mod_Speed);
  }
  /*
  txdata.temp = bmp.readTemperature();
  txdata.pres = bmp.readPressure();
  txdata.alt = bmp.readAltitude();
  txdata.rspres = bmp.readSealevelPressure();
  txdata.ralt = bmp.readAltitude(seaLevelPressure_hPa * 100);
  */
  //ETout.sendData(); 
}
