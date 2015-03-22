#include "Movimientos.h"

#include <MC33926.h>
Movimientos::Movimientos(int P1M1IN1, int P1M1IN2, int P1M1PWMD1, int P1M1PWMD2, int P1M2IN1, int P1M2IN2, int P1M2PWMD1, int P1M2PWMD2, int P2M1IN1, int P2M1IN2, int P2M1PWMD1, int P2M1PWMD2, int P2M2IN1, int P2M2IN2, int P2M2PWMD1, int P2M2PWMD2)
{
	_puente1.setM1(P1M1IN1, P1M1IN2, P1M1PWMD1, P1M1PWMD2);
	_puente1.setM2(P1M2IN1, P1M2IN2, P1M2PWMD1, P1M2PWMD2);
	_puente2.setM1(P2M1IN1, P2M1IN2, P2M1PWMD1, P2M1PWMD2);
	_puente2.setM2(P2M2IN1, P2M2IN2, P2M2PWMD1, P2M2PWMD2);
}
void Movimientos::movefront(int speed){
	_puente1.fwd(1, speed);
	_puente1.fwd(2, speed);
	_puente2.fwd(1, speed);
	_puente2.fwd(2, speed);
}
void Movimientos::moveback(int speed){
	_puente1.rev(1, speed);
	_puente1.rev(2, speed);
	_puente2.rev(1, speed);
	_puente2.rev(2, speed);
}
void Movimientos::moveright(int speed){
	_puente1.fwd(1, speed);
	_puente1.rev(2, speed);
	_puente2.fwd(1, speed);
	_puente2.rev(2, speed);
}
void Movimientos::moveleft(int speed){
	_puente1.rev(1, speed);
	_puente1.fwd(2, speed);
	_puente2.rev(1, speed);
	_puente2.fwd(2, speed);
}
void Movimientos::turnleft(int speed){
	_puente1.fwd(1, speed);
	_puente1.rev(2, speed);
	_puente2.rev(1, speed);
	_puente2.fwd(2, speed);
}
void Movimientos::turnright(int speed){
	_puente1.rev(1, speed);
	_puente1.fwd(2, speed);
	_puente2.fwd(1, speed);
	_puente2.rev(2, speed);
}
void Movimientos::movelf(int speed){
	_puente1.fwd(1, speed);
	_puente1.off(2);
	_puente2.fwd(1, speed);
	_puente2.off(2);
}
void Movimientos::movelb(int speed){
	_puente1.rev(1, speed);
	_puente1.off(2);
	_puente2.rev(1, speed);
	_puente2.off(2);
}
void Movimientos::moverf(int speed){
	_puente1.off(1);
	_puente1.fwd(2, speed);
	_puente2.off(1);
	_puente2.fwd(2, speed);
}
void Movimientos::moverb(int speed){
	_puente1.off(1);
	_puente1.rev(2, speed);
	_puente2.off(1);
	_puente2.rev(2, speed);
}
void Movimientos::stop(){
	_puente1.off(1);
	_puente1.off(2);
	_puente2.off(1);
	_puente2.off(2);
}