/*
--Intelirobot-- 
	facilita el uso de MC33926
*/
#include <MC33926.h>
MC33926 drive= MC33926();
void setup() { 
	drive.setEn(7);//pin de encendido y apagado
	drive.setM1(8, 9, 10, 11); //pin1-digital-encendido-avanza, pin2-digital-apagado-avanza, pwm1, pwm-velocidad
	drive.setM2(7, 4, 5, 6); //declara los pines de el segundo motor
}
void loop() {
	drive.on(); //enciende puente
	drive.fwd(1, 255); //motor 1 avanza (pin1-HIGH y pin2-LOW)
	drive.fwd(2, 255); //motor 2 avanza
	delay(500);
	drive.rev(1, 255); //motor 1 retrocede (pin1-LOW y pin2-HIGH)
	delay(500);
	drive.off(1); //apaga motor 1
	delay(500);
	drive.fwd(1,50); //motor 1 avanza a velocidad corta
	delay(500);
	drive.off(); //apaga el puente
	delay(200);
}