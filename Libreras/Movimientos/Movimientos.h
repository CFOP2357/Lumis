#ifndef Movimientos_h
#define Movimientos_h
#include "MC33926.h"
class Movimientos {
  public:	
   Movimientos(int en1, int en2);
   void setMotorA(int in1, int in2, int pwm1, int pwm2);
   void setMotorB(int in1, int in2, int pwm1, int pwm2);
   void setMotorC(int in1, int in2, int pwm1, int pwm2);
   void setMotorD(int in1, int in2, int pwm1, int pwm2);
   void MotorAFwd(int speed);
   void MotorBFwd(int speed);
   void MotorCFwd(int speed);
   void MotorDFwd(int speed);
   void MotorARev(int speed);
   void MotorBRev(int speed);
   void MotorCRev(int speed);
   void MotorDRev(int speed);
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
  	MC33926 _drive1= MC33926();
  	MC33926 _drive2= MC33926();
};
#endif