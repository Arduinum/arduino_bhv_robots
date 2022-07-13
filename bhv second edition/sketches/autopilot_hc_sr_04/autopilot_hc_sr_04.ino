#include "motor.h"
#include "sonar.h"
#include <Servo.h>

Servo neck;
// consts for angles servo
const int front_ang = 98;
const int left_ang = 168;
const int right_ang = 28;
// const for turn time ms 
const int time_90 = 390;
const int time_180 = 750;
const int time_10cm = 220;

void setup(){
	setup_motor_system(2, 3, 4, 5); // pins for motor
	sonar_init(13, 12); //  trig = 13, echo = 12
	neck.attach(14); // pin for servo
	_stop();
}

void loop(){
	int dist_front, dist_left, dist_right;
	
	neck.write(left_ang); // turn neck on the left
	delay(150); // heck turn time
	dist_left = sonar(400);
	
	neck.write(front_ang);
	delay(150);
	dist_front = sonar(400);

	neck.write(right_ang);
	delay(150);
	dist_right = sonar(400);

	if ((dist_left > dist_right) && (dist_left > dist_front)){
		reversal_left();
		delay(time_90);
		if (dist_left > 10){
			forward();
			delay(time_10cm);
		}
	}
	else if (dist_right > dist_front){
		reversal_right();
		delay(time_90);
		if (dist_right > 10){
			forward();
			delay(time_10cm);
		}
	}
	else{
		if (dist_front > 10){
			forward();
			delay(time_10cm);
		}
		else {
			reversal_right();
			delay(time_180);
		}
	}

	// if ((dist_left > dist_front) && (dist_left > dist_right)){
 //    	reversal_left(); // поворачиваем налево 0,5 секунд.
 //    	delay(time_90);
 //    	if (dist_left > 10){
 //      		forward(); // едем вперед 0,5 секунды.
 //      		delay(time_10cm);
 //    	}
 //  	}
 //  	else{
 //    	if (dist_right > dist_front){
 //      		reversal_right(); // поворачиваем направо 0,5 секунд.
 //      		delay(time_90);
 //      		if (dist_right > 10){
 //        		forward(); // едем вперед 0,5 секунды.
 //        		delay(time_10cm);
 //      		}
 //    	}
 //    	else{
 //      		if (dist_front > 10){
 //        		forward(); // едем вперед 0,5 секунды.
 //        		delay(time_10cm);
 //      		}
 //      		else{
 //        		reversal_right(); // разворачиваемся.
 //        		delay(time_180);
 //      		}
 //    	}
 //  	}
}