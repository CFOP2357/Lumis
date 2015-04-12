#ifndef Movimientos_h
#define Movimientos_h
#include "MC33926.h"
class Movimientos {
  public:	
   Movimientos(int en1, int en2);
   void motor1Fwd(int speed);
   void motor2Fwd(int speed);
   void motor3Fwd(int speed);
   void motor4Fwd(int speed);
   void motor1Rev(int speed);
   void motor2Rev(int speed);
   void motor3Rev(int speed);
   void motor4Rev(int speed);
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
   void sleep();
   void on();
  private:
  	MC33926 _drive1= MC33926();
  	MC33926 _drive2= MC33926();
};
#endif