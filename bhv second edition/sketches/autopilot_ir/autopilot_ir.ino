#include "motor.h"

const int front = 6, right = 0, left = 7;

void setup() {
  Serial.begin(9600);

  pinMode(front, INPUT);
  pinMode(right, INPUT);
  pinMode(left, INPUT);
  setup_motor_system(2, 3, 4, 5);
}

void loop() {
  if (digitalRead(left) == 0 && digitalRead(front) == 0){
    reversal_right();
  }
  else if (digitalRead(right) == 0 && digitalRead(front) == 0){
    reversal_right();
  }
  else if (digitalRead(right) == 0 && digitalRead(front) == 0 && digitalRead(left) == 0){
    reversal_right();
  }
  else if (digitalRead(front) == 0){
    reversal_right();
  }
  else if (digitalRead(right) == 0){
    reversal_right();
  }
  else if (digitalRead(left) == 0){
    reversal_right();
  }
  else {
    forward();
  }
}
