
/*
--Intelirobot-- 
	facilita el uso de MC33926
*/
#include <MC33926.h>
MC33926 drive= MC33926();
MC33926 drive2= MC33926();
void setup() { //EN1-30 
	drive.setEn(30);//pin de encendido y apagado
        drive2.setEn(31);
	drive.setM1(38, 39, 2, 3); //:D pin1-digital-encendido-avanza, pin2-digital-apagado-avanza, pwm1, pwm-velocidad
	drive.setM2(37, 36, 4, 5); // :D declara los pines de el segundo motor
        drive2.setM1(34, 35, 6, 7); //:D
        drive2.setM2(33, 32, 9, 8); //:D     
}
void loop() { //1_M1-M2  
	drive.on(); //enciende puente
        drive2.on();
        //avanza
	drive.fwd(0, 255); //motor 1 avanza (pin1-HIGH y pin2-LOW)
	drive.fwd(1, 255);
        drive2.fwd(0, 255);
        drive2.fwd(1, 255);
}
