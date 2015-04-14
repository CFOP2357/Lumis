#include "Movimientos.h"
#include <MC33926.h>
Movimientos::Movimientos()
{
	_drive1.setEn(30);
    _drive2.setEn(31);
	_drive1.setM1(38, 39, 2, 3);
	_drive1.setM2(37, 36, 4, 5); 
    _drive2.setM1(34, 35, 6, 7); 
    _drive2.setM2(33, 32, 9, 8);
}
void Movimientos::motor1Fwd(int speed){
	_drive1.fwd(0, speed);
}
void Movimientos::motor2Fwd(int speed){
	_drive1.fwd(1, speed);
}
void Movimientos::motor3Fwd(int speed){
	_drive2.fwd(0, speed);
}
void Movimientos::motor4Fwd(int speed){
	_drive2.fwd(1, speed);
}
void Movimientos::motor1Rev(int speed){
	_drive1.rev(0, speed);
}
void Movimientos::motor2Rev(int speed){
	_drive1.rev(1, speed);
}
void Movimientos::motor3Rev(int speed){
	_drive2.rev(0, speed);
}
void Movimientos::motor4Rev(int speed){
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
void Movimientos::moveleft(int speed){
	_drive1.fwd(0, speed);
	_drive1.rev(1, speed);
	_drive2.fwd(0, speed);
	_drive2.rev(1, speed);
}
void Movimientos::moveright(int speed){
	_drive1.rev(0, speed);
	_drive1.fwd(1, speed);
	_drive2.rev(0, speed);
	_drive2.fwd(1, speed);
}
void Movimientos::turnleft(int speed){
	_drive1.fwd(0, speed);
	_drive1.fwd(1, speed);
	_drive2.rev(0, speed);
	_drive2.rev(1, speed);
}
void Movimientos::turnright(int speed){
	_drive1.rev(0, speed);
	_drive1.rev(1, speed);
	_drive2.fwd(0, speed);
	_drive2.fwd(1, speed);
}
void Movimientos::diagonalleft(int speed){
	_drive1.fwd(0, speed);
	_drive1.off(1);
	_drive2.fwd(0, speed);
	_drive2.off(1);
}
void Movimientos::diagonalright(int speed){
	_drive1.off(0);
	_drive1.fwd(1, speed);
	_drive2.off(0);
	_drive2.fwd(1, speed);
}
void Movimientos::diagonalbackright(int speed){
	_drive1.off(0);
	_drive1.rev(1, speed);
	_drive2.off(0);
	_drive2.rev(1, speed);
}
void Movimientos::diagonalbackleft(int speed){
	_drive1.off(1);
	_drive1.rev(0, speed);
	_drive2.off(1);
	_drive2.rev(0, speed);
}
void Movimientos::sleep(){
	_drive1.off();
	_drive2.off();
}
void Movimientos::on(){
	_drive1.on();
	_drive2.on();
}