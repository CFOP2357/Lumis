#ifndef CompassSensor_h
#define CompassSensor_h
#include "Arduino.h"
class CompassSensor{
  private:
   int address;
  public:
   int calibrateAngles(int starting,int current);
   int getAngle();
   void setAddress(int theAddress);
};
#endif
