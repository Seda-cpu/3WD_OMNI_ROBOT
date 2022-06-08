// Farklı hızlarda test sürüşü 
// şu an iki motorlu

#include <PID_v1.h>

double Pk1 = 4;
double Ik1 = 4;
double Dk1 = 0.03;

double SetPoint1, Input1, Output1, Output1a; //PID değerleri
PID PID1(&Input1, &Output1, &SetPoint1, Pk1, Ik1, Dk1, DIRECT); //PID setup

double Pk2 = 4;
double Ik2 = 4;
double Dk2 = 0.03;

double SetPoint2, Input2, Output2, Output2a; //PID değerleri
PID PID2(&Input2, &Output2, &SetPoint2, Pk2, Ik2, Dk2, DIRECT); //PID setup

float demand1;
float demand2;

unsigned long currentMillis;
unsigned long previousMillis;

#define encoder0PinA 2
#define encoder0PinB 3

#define encoder1PinA 18
#define encoder1PinB 19

volatile long encoder0Pos = 0;
volatile long encoder1Pos = 0;
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
