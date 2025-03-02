#include <ESP32Servo.h>

// Create servo object
Servo s1;  //hip
Servo s2;   // knee


float i1L1 = 0;
float i1L2 = 0;
float i1L3 = 0;
float i1L4 = 0;
float i1L5 = 0;


boolean l1status = LOW;
boolean l2status = LOW;
boolean aStatus = LOW;
boolean attStatus = LOW;

unsigned long time_now = 0;
int flag = 0;

void setup() {
 
  // Leg 3
  s1.attach(33, 600, 2400);
  s2.attach(32, 600, 2400);
  
  s1.write(90);
  s2.write(90);

  delay(3000);
}
void loop() {

  moveLeg1();
  delay(30);
    
}

void moveLeg1() {
  if (i1L1 <= 10 ) {
    s1.write(88 + i1L1 * 1);
    s2.write(92 - i1L1 * 1.6);
    i1L1++;
  }
    if (i1L1 >= 10 && i1L2 <= 10) {
    s1.write(99 + i1L2 * 2);
    s2.write(76 + i1L2 * 2.4);
    i1L2++;
  }
  if (i1L2 >= 10 && i1L3 <= 10) {
  s1.write(118 - i1L3 * 2);
  s2.write(100 + i1L3 * 2);
  i1L3++;  
  }
  if (i1L3 >= 10 && i1L4 <= 10) {
  s1.write(91 - i1L4 * 1.7);
  s2.write(118 - i1L4 * 2);
  i1L4++;  
  }
  if(i1L4 >= 10){
    i1L1 = 0;
    i1L2 = 0;
    i1L3 = 0;
    i1L4 = 0;
    i1L5 = 0;
  }
}
