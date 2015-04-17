#include <SPI.h>
#include <Goalie.h>
#include <Pixy.h>

Goalie pxy=Goalie();
Pixy pd;
void setup() {
  Serial.begin(9600);
 pd.init(); 
  pxy.setYellow(0);
  pxy.setBlue(5);
  pxy.calibrate(pd);
}

void loop(){
  pixelIn k=pxy.getEnemy(pd);
  Serial.print("area:"+(String)k.area);
  Serial.print("x:"+(String)k.x);
  Serial.println("y:"+(String)k.y);
}
