#include <MC33926.h>
MC33926 puente= MC33926();
void setup() { 
	puente.setM1(12, 11, 6, 9);
	puente.setM2(12, 11, 6, 9);
}
void loop() {
	puente.fwd(1, 255);
	delay(500);
	puente.rev(1, 255);
	delay(500);
	puente.off(1);
	delay(500);
}
