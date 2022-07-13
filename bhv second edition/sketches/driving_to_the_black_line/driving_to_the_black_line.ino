#include "motor.h"
unsigned long _time;

int left_sensor_line = 9;
int right_sensor_line = 8;

void setup(){
	// pins for motors
	setup_motor_system(2, 3, 4, 5);
	// motors stoped
	_stop();
	// pins on the input
	pinMode(left_sensor_line, INPUT);
	pinMode(right_sensor_line, INPUT);
	_time = millis();		
}

void loop(){
	while (true){
		bool ls = digitalRead(left_sensor_line);
		bool rs = digitalRead(right_sensor_line);
		
		if (ls != 1 && rs != 1){
			forward();
		} else {
  			if (ls == 1) {
  				forward_left();
  			} else {
  				forward_right();
  			}
  		}
		delayMicroseconds(500);
		_stop();
		delayMicroseconds(100);
	}
}
