#include "Movimientos.h"

#include <MC33926.h>
Movimientos::Movimientos(int en1, int en2)
{
	drive1.setEn(en1);
	drive.setEn(en2);
}
void Movimientos::setMotorA(int in1, int in2, int pwm1, int pwm2){
	drive1.setM1(in1, in2, pwm1, pm2);
}
void Movimientos::setMotorB(int in1, int in2, int pwm1, int pwm2){
	drive1.setM2(in1, in2, pwm1, pm2);
}
void Movimientos::setMotorC(int in1, int in2, int pwm1, int pwm2){
	drive2.setM1(in1, in2, pwm1, pm2);
}
void Movimientos::setMotorD(int in1, int in2, int pwm1, int pwm2){
	drive2.setM2(in1, in2, pwm1, pm2);
}
void Movimientos::motorAFwd(int speed){
	_drive1.fwd(0, speed);
}
void Movimientos::motorBFwd(int speed){
	_drive1.fwd(1, speed);
}
void Movimientos::motorCFwd(int speed){
	_drive2.fwd(0, speed);
}
void Movimientos::motorDFwd(int speed){
	_drive2.fwd(1, speed);
}
void Movimientos::motorARev(int speed){
	_drive1.rev(0, speed);
}
void Movimientos::motorBRev(int speed){
	_drive1.rev(1, speed);
}
void Movimientos::motorCRev(int speed){
	_drive2.rev(0, speed);
}
void Movimientos::motorDRev(int speed){
	_drive2.rev(1, speed);
}
void Movimientos::movefront(int speed){
	_drive1.fwd(0, speed);
	_drive1.fwd(1, speed);
	_drive2.fwd(0, speed);
	_drive2.fwd(1, speed);
}
void Movimientos::moveback(int speed){
	_drive1.rev(0, speed);
	_drive1.rev(1, speed);
	_drive2.rev(0, speed);
	_drive2.rev(1, speed);
}
void Movimientos::moveright(int speed){
	_drive1.fwd(0, speed);
	_drive1.rev(1, speed);
	_drive2.fwd(0, speed);
	_drive2.rev(1, speed);
}
void Movimientos::moveleft(int speed){
	_drive1.rev(0, speed);
	_drive1.fwd(1, speed);
	_drive2.rev(0, speed);
	_drive2.fwd(1, speed);
}
void Movimientos::turnleft(int speed){
	_drive1.fwd(0, speed);
	_drive1.rev(1, speed);
	_drive2.rev(0, speed);
	_drive2.fwd(1, speed);
}
void Movimientos::turnright(int speed){
	_drive1.rev(0, speed);
	_drive1.fwd(1, speed);
	_drive2.fwd(0, speed);
	_drive2.rev(1, speed);
}
void Movimientos::movelf(int speed){
	_drive1.fwd(0, speed);
	_drive1.off(1);
	_drive2.fwd(0, speed);
	_drive2.off(1);
}
void Movimientos::movelb(int speed){
	_drive1.rev(0, speed);
	_drive1.off(1);
	_drive2.rev(0, speed);
	_drive2.off(1);
}
void Movimientos::moverf(int speed){
	_drive1.off(0);
	_drive1.fwd(1, speed);
	_drive2.off(0);
	_drive2.fwd(1, speed);
}
void Movimientos::moverb(int speed){
	_drive1.off(0);
	_drive1.rev(1, speed);
	_drive2.off(0);
	_drive2.rev(1, speed);
}
void Movimientos::sleep(){
	_drive1.off();
	_drive2.off();
}
void Movimientos::on(){
	_drive1.on();
	_drive2.on();
}