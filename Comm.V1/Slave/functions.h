void motor1 (int s,bool d);
void motor2 (int s,bool d);
void motor3 (int s,bool d);
void motor4 (int s,bool d);
void motor5 (int s,bool d);
void motor6 (int s,bool d);
/*=========================*/
void forward (int s);
void backword (int s);
void right (int s);
void left (int s);
void fr (int s);
void fl (int s);
void br (int s);
void bl (int s);
void xystop (void);
/*=========================*/
void up (int s);
void down (int s);
void zstop (void);
/*=========================*/
void teltup (int s);
void teltdown (int s);
void rotatecw (int s);
void rotateccw (int s);
/*=========================*/
void StepperMOTOR_1(int speed,bool direction);
void StepperMOTOR_2(int speed,bool direction);
void StepperMOTOR_3(int speed,bool direction);
void StepperMOTOR_4(int speed,bool direction);
/*=========================*/
void module_U(int speed);
void module_D(int speed);
void module_F(int speed);
void module_B(int speed);
void module_R(int speed);
void module_L(int speed);
/*==========================*/
#define gap_start 0
#define gap_point 1
#define gap_end 3
/*============================*/
#define seaLevelPressure_hPa 1013.25