#include <ESP32Servo.h>

// Create servo objects for 4 legs (8 servos)
Servo s1, s2, s3, s4, s5, s6, s7, s8;

// Variables for individual leg movements
float i1L1 = 0, i1L2 = 0, i1L3 = 0, i1L4 = 0, i1L5 = 0, i1L6 = 0; // Leg 1
float i2L1 = 0, i2L2 = 0, i2L3 = 0, i2L4 = 0, i2L5 = 0, i2L6 = 0; // Leg 2
float i3L1 = 0, i3L2 = 0, i3L3 = 0, i3L4 = 0, i3L5 = 0, i3L6 = 0; // Leg 3
float i4L1 = 0, i4L2 = 0, i4L3 = 0, i4L4 = 0, i4L5 = 0, i4L6 = 0; // Leg 4


int flag = 0;

//leg_1
float val_1 = 0;
float val_2 = 0;

//leg_2
float val_3 = 0;
float val_4 = 0;

//leg_3
float val_5 = 0;
float val_6 = 0;

//leg_4
float val_7 = 0;
float val_8 = 0;


void setup() {
  // Initialize Serial Monitor
  Serial.begin(115200);

  // Attach servos for each leg
  s1.attach(33, 600, 2400); // Leg 1
  s2.attach(32, 600, 2400);
  s3.attach(13, 600, 2400); // Leg 2
  s4.attach(12, 600, 2400);
  s5.attach(25, 600, 2400); // Leg 3
  s6.attach(26, 600, 2400);
  s7.attach(27, 600, 2400);  // Leg 4
  s8.attach(14, 600, 2400);

  // Initialize all servos to their starting positions
  s1.write(92); s2.write(88);
  s3.write(92); s4.write(88);
  s5.write(92); s6.write(88);
  s7.write(92); s8.write(88);

  delay(3000);
}

void loop() {
//  Call individual functions for each leg
  if(flag == 0){
    forward();
  }
  if(flag == 1){
    backword();
  }

  if(flag == 2){
    left();
  }

  if(flag == 3){
    right();
  }

  delay(10); // Small delay for smooth movement
}

// Function to print variables for debugging
void printVariables(const char* legName, float i1, float i2, float i3, float i4, float i5, float i6) {
  Serial.print(legName);
  Serial.print("  i1: "); Serial.print(i1);
  Serial.print(", i2: "); Serial.print(i2);
  Serial.print(", i3: "); Serial.print(i3);
  Serial.print(", i4: "); Serial.print(i4);
  Serial.print(", i5: "); Serial.print(i5);
  Serial.print(", i6: "); Serial.println(i6);
}
void forward(){
  moveLeg1();
  moveLeg2();
  moveLeg3();
  moveLeg4();
}
void backword(){
  moveLeg1_backward();
  moveLeg2_backward();
  moveLeg3_backward();
  moveLeg4_backward();
}
void left(){
  moveLeg1_backward();
  moveLeg2_backward();
  moveLeg3();
  moveLeg4();
}

void right(){
  moveLeg1();
  moveLeg2();
  moveLeg3_backward();
  moveLeg4_backward();
}

// Individual movement function for Leg 1
void moveLeg1() {
  if (i1L1 <= 15) {
    s1.write(90 - i1L1 * 1.13);
    s2.write(90 - i1L1 * 1.06);
    i1L1++;
  }
  if (i1L2 <= 10 && i1L1 > 15) {
    s1.write(73 - i1L2 * 1.6);
    s2.write(74 + i1L2 * 2.1);
    i1L2++;
  }
  if (i1L2 > 10 && i1L3 <= 5) {
    s1.write(57 + i1L3 * 2.6);
    s2.write(95 + i1L3 * 2.2);
    i1L3++;
  }
  if (i1L3 > 5 && i1L4 <= 5) {
    s1.write(70 + i1L4 * 2.8);
    s2.write(106 + i1L4 * 1.4);
    i1L4++;
  }
  if (i1L4 > 5 && i1L5 <= 10) {
    s1.write(84 + i1L5 * 1.8);
    s2.write(114 - i1L5 * 1.9);
    i1L5++;
  }
  if (i1L5 > 10 && i1L6 <= 15) {
    s1.write(102 - i1L6 * 0.8);
    s2.write(95 - i1L6 * 0.34);
    i1L6++;
  }

  if (i1L6 > 15) {
    i1L1 = 0; i1L2 = 0; i1L3 = 0; i1L4 = 0; i1L5 = 0; i1L6 = 0;
  }

  // Print leg 1 variables
  printVariables("Leg 1", i1L1, i1L2, i1L3, i1L4, i1L5, i1L6);
}

void moveLeg2() {
  if (i2L1 <= 5) {
    s3.write(70 + i2L1 * 2.8);
    s4.write(106 + i2L1 * 1.4);
    i2L1++;
  }
  if (i2L1 > 5 && i2L2 <= 10) {
    s3.write(84 + i2L2 * 1.8);
    s4.write(114 - i2L2 * 1.9);
    i2L2++;
  }
  if (i2L2 > 10 && i2L3 <= 15) {
    s3.write(102 - i2L3 * 0.8);
    s4.write(95 - i2L3 * 0.34);
    i2L3++;
  }
  if (i2L3 > 15 && i2L4 <= 15) {
    s3.write(90 - i2L4 * 1.13);
    s4.write(90 - i2L4 * 1.06);
    i2L4++;
  }
  if (i2L4 > 15 && i2L5 <= 10) {
    s3.write(73 - i2L5 * 1.6);
    s4.write(74 + i2L5 * 2.1);
    i2L5++;
  }
  if (i2L5 > 10 && i2L6 <= 5) {
    s3.write(57 + i2L6 * 2.6);
    s4.write(95 + i2L6 * 2.2);
    i2L6++;
  }

  if (i2L6 > 5) {
    i2L1 = 0; i2L2 = 0; i2L3 = 0; i2L4 = 0; i2L5 = 0; i2L6 = 0;
  }

  // Print leg 2 variables
  printVariables("Leg 2", i2L1, i2L2, i2L3, i2L4, i2L5, i2L6);
}

void moveLeg3() {
  if ( i3L1 <= 5) {
    s5.write(103 - i3L1 * 2.6);
    s6.write(73 - i3L1 * 1.4);
    i3L1++;
  }
  if (i3L1 > 5 && i3L2 <= 10) {
    s5.write(90 - i3L2 * 1.7);
    s6.write(66 + i3L2 * 1.7);
    i3L2++;
  }
  if (i3L2 > 10 && i3L3 <= 15) {
    s5.write(73 + i3L3 * 1.13);
    s6.write(83 + i3L3 * 0.6);
    i3L3++;
  }
  if (i3L3 > 15 && i3L4 <= 15) {
    s5.write(90 + i3L4 * 0.86);
    s6.write(92 + i3L4 * 0.93);
    i3L4++;
  }
  if (i3L4 > 15 && i3L5 <= 10) {
    s5.write(103 + i3L5 * 1.5);
    s6.write(106 - i3L5 * 2);
    i3L5++;
  }
  if (i3L5 > 10 && i3L6 <= 5) {
    s5.write(118 - i3L6 * 3);
    s6.write(86 - i3L6 * 2.6);
    i3L6++;
  }
  
  
  
  if (i3L6 > 5) {
    i3L1 = 0; i3L2 = 0; i3L3 = 0; i3L4 = 0; i3L5 = 0, i3L6 = 0;
  }
}

// Individual movement function for Leg 4
void moveLeg4() {
  if (i4L1 <= 15 ) {
    s7.write(90 + i4L1 * 0.86);
    s8.write(92 + i4L1 * 0.93);
    i4L1++;
  }
  if (i4L1 > 15 && i4L2 <= 10) {
    s7.write(103 + i4L2 * 1.5);
    s8.write(106 - i4L2 * 2);
    i4L2++;
  }
  if (i4L2 > 10 && i4L3 <= 5) {
    s7.write(118 - i4L3 * 3);
    s8.write(86 - i4L3 * 2.6);
    i4L3++;
  }
  if (i4L3 > 5 && i4L4 <= 5) {
    s7.write(103 - i4L4 * 2.6);
    s8.write(73 - i4L4 * 1.4);
    i4L4++;
  }
  if (i4L4 > 5 && i4L5 <= 10) {
    s7.write(90 - i4L5 * 1.7);
    s8.write(66 + i4L5 * 1.7);
    i4L5++;
  }
  if (i4L5 > 10 && i4L6 <= 15) {
    s7.write(73 + i4L6 * 1.13);
    s8.write(83 + i4L6 * 0.6);
    i4L6++;
  }
  if (i4L6 > 15) {
    i4L1 = 0; i4L2 = 0; i4L3 = 0; i4L4 = 0; i4L5 = 0, i4L6 = 0;
  }
}

void moveLeg1_backward() {
  if (i1L1 <= 15) {
    s1.write(90 + i1L1 * 0.8);
    s2.write(90 + i1L1 * 0.3);
    i1L1++;
  }
  if (i1L2 <= 10 && i1L1 > 15) {
    s1.write(102 - i1L2 * 1.8);
    s2.write(95 + i1L2 * 1.9);
    i1L2++;
  }
  if (i1L2 > 10 && i1L3 <= 5) {
    s1.write(84 - i1L3 * 2.8);
    s2.write(114 - i1L3 * 1.4);
    i1L3++;
  }
  if (i1L3 > 5 && i1L4 <= 5) {
    s1.write(70 - i1L4 * 2.6);
    s2.write(106 - i1L4 * 2.2);
    i1L4++;
  }
  if (i1L4 > 5 && i1L5 <= 10) {
    s1.write(57 + i1L5 * 1.6);
    s2.write(95 - i1L5 * 2.1);
    i1L5++;
  }
  if (i1L5 > 10 && i1L6 <= 15) {
    s1.write(73 + i1L6 * 1.13);
    s2.write(74 + i1L6 * 1.06);
    i1L6++;
  }

  if (i1L6 > 15) {
    i1L1 = 0; i1L2 = 0; i1L3 = 0; i1L4 = 0; i1L5 = 0; i1L6 = 0;
  }

  // Print leg 1 variables
  printVariables("Leg 1", i1L1, i1L2, i1L3, i1L4, i1L5, i1L6);
}

void moveLeg2_backward() {
  if (i2L1 <= 5) {
    s3.write(70 - i2L1 * 2.6);
    s4.write(106 - i2L1 * 2.2);
    i2L1++;
  }
  if (i2L1 > 5 && i2L2 <= 10) {
    s3.write(57 + i2L2 * 1.6);
    s4.write(95 - i2L2 * 2.1);
    i2L2++;
  }
  if (i2L2 > 10 && i2L3 <= 15) {
    s3.write(73 + i2L3 * 1.13);
    s4.write(74 + i2L3 * 1.06);
    i2L3++;
  }
  if (i2L3 > 15 && i2L4 <= 15) {
    s3.write(90 + i2L4 * 0.8);
    s4.write(90 + i2L4 * 0.3);
    i2L4++;
  }
  if (i2L4 > 15 && i2L5 <= 10) {
    s3.write(102 - i2L5 * 1.8);
    s4.write(95 + i2L5 * 1.9);
    i2L5++;
  }
  if (i2L5 > 10 && i2L6 <= 5) {
    s3.write(84 - i2L6 * 2.8);
    s4.write(114 - i2L6 * 1.4);
    i2L6++;
  }

  if (i2L6 > 5) {
    i2L1 = 0; i2L2 = 0; i2L3 = 0; i2L4 = 0; i2L5 = 0; i2L6 = 0;
  }

  // Print leg 2 variables
  printVariables("Leg 2", i2L1, i2L2, i2L3, i2L4, i2L5, i2L6);
}

void moveLeg3_backward() {
  if ( i3L1 <= 5) {
    s5.write(103 + i3L1 * 3);
    s6.write(73 + i3L1 * 2.6);
    i3L1++;
  }
  if (i3L1 > 5 && i3L2 <= 10) {
    s5.write(118 - i3L2 * 1.5);
    s6.write(86 + i3L2 * 2);
    i3L2++;
  }
  if (i3L2 > 10 && i3L3 <= 15) {
    s5.write(103 - i3L3 * 0.86);
    s6.write(106 - i3L3 * 0.93);
    i3L3++;
  }
  if (i3L3 > 15 && i3L4 <= 15) {
    s5.write(90 - i3L4 * 1.13);
    s6.write(92 - i3L4 * 0.6);
    i3L4++;
  }
  if (i3L4 > 15 && i3L5 <= 10) {
    s5.write(73 + i3L5 * 1.7);
    s6.write(83 - i3L5 * 1.7);
    i3L5++;
  }
  if (i3L5 > 10 && i3L6 <= 5) {
    s5.write(90 + i3L6 * 2.6);
    s6.write(66 + i3L6 * 1.4);
    i3L6++;
  }
  if (i3L6 > 5) {
    i3L1 = 0; i3L2 = 0; i3L3 = 0; i3L4 = 0; i3L5 = 0, i3L6 = 0;
  }
}

void moveLeg4_backward() {
  if (i4L1 <= 15 ) {
    s7.write(90 - i4L1 * 1.26);
    s8.write(92 - i4L1 * 0.6);
    i4L1++;
  }
  if (i4L1 > 15 && i4L2 <= 10) {
    s7.write(73 + i4L2 * 1.7);
    s8.write(83 - i4L2 * 1.7);
    i4L2++;
  }
  if (i4L2 > 10 && i4L3 <= 5) {
    s7.write(90 + i4L3 * 2.6);
    s8.write(66 + i4L3 * 1.4);
    i4L3++;
  }
  if (i4L3 > 5 && i4L4 <= 5) {
    s7.write(103 + i4L4 * 3);
    s8.write(73 + i4L4 * 2.6);
    i4L4++;
  }
  if (i4L4 > 5 && i4L5 <= 10) {
    s7.write(118 - i4L5 * 1.5);
    s8.write(86 + i4L5 * 2);
    i4L5++;
  }
  if (i4L5 > 10 && i4L6 <= 15) {
    s7.write(103 - i4L6 * 0.86);
    s8.write(106 - i4L6 * 0.93);
    i4L6++;
  }
  if (i4L6 > 15) {
    i4L1 = 0; i4L2 = 0; i4L3 = 0; i4L4 = 0; i4L5 = 0, i4L6 = 0;
  }
}

