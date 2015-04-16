#include <SPI.h>
#include <Goalie.h>
#include <Pixy.h>

Goalie pxy=Goalie();

void setup() { 
  pxy.setYellow(0);
  pxy.setBlue(1);
  pxy.calibrate();
}

void loop(){
  pixelIn k=pxy.getInfo(pxy.getEnemy());
  Serial.print("area:"+(String)k.area);
  Serial.print("x:"+(String)k.x);
  Serial.println("y:"+(String)k.y);
}
