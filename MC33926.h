#ifndef MC33926_h
#define MC33926_h
class MC33926 
{
   private:
    int _IN1[2], _IN2[2];
    int _PWMD1[2], _PWMD2[2];
  public:	
   MC33926();
   void setM1(int IN1, int IN2, int PWMD1, int PWMD2); //pin que encendido avanza, pin que apagado avanza, pwm1, pwm2
   void setM2(int IN1, int IN2, int PWMD1, int PWMD2);
   void fwd(int n, int speed);
   void rev(int n, int speed);
   void off(int n);
};
#endif
