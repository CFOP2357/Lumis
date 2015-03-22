#ifndef Movimientos_h
#define Movimientos_h
#include "MC33926.h"
class Movimientos {
  public:	
   Movimientos(int P1M1IN1, int P1M1IN2, int P1M1PWMD1, int P1M1PWMD2, int P1M2IN1, int P1M2IN2, int P1M2PWMD1, int P1M2PWMD2, int P2M1IN1, int P2M1IN2, int P2M1PWMD1, int P2M1PWMD2, int P2M2IN1, int P2M2IN2, int P2M2PWMD1, int P2M2PWMD2);
   void movefront(int speed);
   void moveback(int speed);
   void moveright(int speed);
   void moveleft(int speed);
   void movelf(int speed);
   void movelb(int speed);
   void moverf(int speed);
   void moverb(int speed);
   void turnleft(int speed);
   void turnright(int speed);
   void stop();
  private:
  	MC33926 _puente1= MC33926();
  	MC33926 _puente2= MC33926();
};
#endif