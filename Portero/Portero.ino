#include <CompassSensor.h>

#include <Movimientos.h>
#include <Wire.h>
#include <HTInfraredSeeker.h>

#define SPEED                   150


Movimientos robot=  Movimientos();

CompassSensor compass=CompassSensor();

InfraredSeeker seeker=InfraredSeeker();
InfraredInput seekerInput;

bool oriented=false;
bool black=true;

int startingAngle;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  
  compass.setAddress(0x21);
  startingAngle=compass.getAngle();
    // turn on Arduino's LED to indicate we are in calibration mode

}

void loop() {
  int current=compass.getAngle();
  int angle=compass.calibratedAngles(startingAngle,current);
  seekerInput=seeker.ReadAC();
    orient(angle);
    while(!oriented){
      current=compass.getAngle();
      angle=compass.calibratedAngles(startingAngle,current);
      orient(angle);
    }
    followball(seekerInput.Direction, seekerInput.Strength);
}
void followball(byte k,byte f){
    switch(k){
      case 0:
      robot.moveback(0);
      break;
      case 1:
      robot.moveback(255);
      break;
      case 2:
      robot.moveback(255);
      break;
      case 3:
      robot.moveright(SPEED);
      break;
      case 4:
      robot.moveright(SPEED);
      break;
      case 5:
      robot.movefront(75);
      break;
      case 6:
      robot.moveleft(SPEED);
      break;
      case 7:
      robot.moveleft(SPEED);
      break;
      case 8:
      robot.moveback(255);
      break;
      case 9:
      robot.moveback(255);
      break;
      
    }
}
void orient(int ang){
if(ang>5&&ang<355){
oriented=false;
if(ang<180&&ang>5){
  int vel=ang+50;
  robot.turnleft(vel);
}
if(ang>=180&&ang<355){
  int vel=360-ang+50;
  robot.turnright(vel);
}
}
else{
  oriented=true;
}
}

