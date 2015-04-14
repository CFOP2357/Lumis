#ifndef Movimientos_h
#define Movimientos_h
#include "MC33926.h"
class Movimientos {
  public:	
   Movimientos();
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
   void diagonalright(int speed);
   void diagonalleft(int speed);
   void diagonalbackright(int speed);
   void diagonalbackleft(int speed);
   void turnleft(int speed);
   void turnright(int speed);
   void sleep();
   void on();
  private:
  	MC33926 _drive1= MC33926();
  	MC33926 _drive2= MC33926();
};
#endif