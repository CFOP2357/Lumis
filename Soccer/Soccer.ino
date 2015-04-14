#include <CompassSensor.h>

#include <MC33926.h>
#include <Movimientos.h>
#include <Wire.h>
#include <HTInfraredSeeker.h>


Movimientos robot=  Movimientos();

CompassSensor compass=CompassSensor();

InfraredSeeker seeker=InfraredSeeker();
InfraredInput seekerInput;

int startingAngle;
void setup() {
  Wire.begin();
  startingAngle=compass.getAngle();
  compass.setAddress(0x21);
}

void loop() {
  int current=compass.getAngle();
  int angle=compass.calibratedAngles(startingAngle,current);
  seekerInput=seeker.ReadAC();
  if(1){
    robot.turnright(255);
    if(!(seekerInput.Strength>=110 && ((seekerInput.Direction<=5 && seekerInput.Direction>=3) || (seekerInput.Direction>=5 && seekerInput.Direction<=7))))
    orient(angle);
    if(1){
      followball(seekerInput.Direction, seekerInput.Strength);
    }
  }
}
void followball(byte k,byte f){
  //LEJOS
  if(f<=110){
    robot.on();
    switch(k){
      case 0:
      robot.diagonalbackright(255);
      break;
      case 1:
      robot.moveback(255);
      break;
      case 2:
      robot.moveback(255);
      break;
      case 3:
      robot.moveright(255);
      break;
      case 4:
      robot.moveright(255);
      break;
      case 5:
      robot.movefront(255);
      break;
      case 6:
      robot.moveleft(255);
      break;
      case 7:
      robot.moveleft(255);
      break;
      case 8:
      robot.moveback(255);
      break;
      case 9:
      robot.moveback(255);
      break;
      
    }
  }
  //CERCA
  else{
switch(k){
      case 0:
      robot.sleep();
      break;
      case 1:
      robot.moveright(150);
      break;
      case 2:
      robot.moveright(150);
      break;
      case 3:
      robot.turnright(200);
      break;
      case 4:
      robot.turnright(150);
      break;
      case 5:
      robot.movefront(255);
      break;
      case 6:
      robot.turnleft(150);
      break;
      case 7:
      robot.turnleft(200);
      break;
      case 8:
      robot.moveleft(255);
      break;
      case 9:
      robot.moveleft(255);
      break;
      
    }
  }
}
void orient(int ang){
if(ang<180&&ang>5){
  robot.turnright(255);
}
if(ang>=180&&ang<355){
  robot.turnleft(255);
}
}
