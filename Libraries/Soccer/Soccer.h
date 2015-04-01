#ifndef Soccer_h
#define Soccer_h
#include "arduino.h"
#include "Movimientos.h"
#include "CompassSensor.h"
#include "HTInfradeSeeker.h"
#include "Wire.h"
#include "SPI.h"
#include "Pixy.h"
class Soccer {
  public:
   Soccer();
   void followball();
   void shoot();
   void searchgoal(int s);
   void off();
   void on();
   void orient();
   bool goal(int s);
   bool oriented();
   bool ball();
   bool white();
   bool btn();
  private:  
   Movimientos robot = Movimientos(22,23);
   InfraredSeeker seeker=InfraredSeeker();
   InfraredInput seekerInput;
   CompassSensor compass=CompassSensor();
   Pixy pixy;
   int angle;
};
#endif