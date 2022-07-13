// pins for sonar
int trig;
int echo;
// mod pins/ports
sonar_init(int tr, int ec){
	trig = tr;
	echo = ec;

	pinMode(trig, OUTPUT);
	pinMode(echo, INPUT);
}

int sonar(unsigned long limit){
	int long_cm;
	unsigned long lim = limit * 58;
	// generate impulse
	digitalWrite(trig, LOW);
	delayMicroseconds(2);
	digitalWrite(trig, HIGH);
	delayMicroseconds(10);
	digitalWrite(trig, LOW);
	// We are waiting for the reflection of the impulse
	// We recalculate time into distance (according to the speed of sound)
	long_cm = int(pulseIn(echo, HIGH, lim) / 58);
	// If there is no reflection,
   	// Assign a value to the maximum measurable one
   	if(long_cm == 0){
   		return int(limit);
   	}
   	return long_cm;
}