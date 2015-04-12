#include <Wire.h>
#include <CompassSensor.h>
CompassSensor compass=CompassSensor();
int angle;
void setup() {
  Wire.begin();
  Serial.begin(9600);
  compass.setAddress(0x21);
}
void loop() {
  angle=compass.getAngle();
  Serial.print("Your current angle is:");
  Serial.println(angle);
}