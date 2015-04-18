#include <CompassSensor.h>

#include <Movimientos.h>
#include <Wire.h>
#include <HTInfraredSeeker.h>


Movimientos robot=  Movimientos();

CompassSensor compass=CompassSensor();

InfraredSeeker seeker=InfraredSeeker();
InfraredInput seekerInput;
bool oriented=false;
bool closeB=false;

int startingAngle;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  
  compass.setAddress(0x21);
  startingAngle=compass.getAngle();
  
}

void loop() {
  int current=compass.getAngle();
  int angle=compass.calibratedAngles(startingAngle,current);
  seekerInput=seeker.ReadAC();
    orient(angle);
    //Serial.println(angle);
    while(!oriented){
      current=compass.getAngle();
      angle=compass.calibratedAngles(startingAngle,current);
      orient(angle);
    }
    followball(seekerInput.Direction, seekerInput.Strength);
}
void followball(byte k,byte f){
  //LEJOS
  if(f<130){
    //robot.on();
    switch(k){
      case 0:
        robot.diagonalbackright(255);
      break;
      case 1:
      robot.moveback(255);
      closeB=false;
      break;
      case 2:
      robot.moveback(255);
      closeB=false;
      break;
      case 3:
      robot.moveright(255);
      closeB=false;
      break;
      case 4:
      robot.moveright(255);
      closeB=false;
      break;
      case 5:
      robot.movefront(255);
      break;
      case 6:
      robot.moveleft(255);
      closeB=false;
      break;
      case 7:
      robot.moveleft(255);
      closeB=false;
      break;
      case 8:
      robot.moveback(255);
      closeB=false;
      break;
      case 9:
      robot.moveback(255);
      closeB=false;
      break;
      
    }
  }
  //CERCA
  else{
    //robot.sleep();
  closeB=true;  
  switch(k){
      case 0:
      robot.sleep();
      break;
      case 1:
      robot.diagonalbackleft(255);
      break;
      case 2:
      robot.diagonalbackleft(100);
      break;
      case 3:
      robot.moveright(150);
      break;
      case 4:
      robot.moveright(100);
      break;
      case 5:
      robot.movefront(255);
      break;
      case 6:
      robot.moveleft(100);
      break;
      case 7:
      robot.moveleft(150);
      break;
      case 8:
      robot.diagonalbackright(100);
      break;
      case 9:
      robot.diagonalbackright(255);
      break;
      
    }
  }
}
void orient(int ang){
if(ang>5&&ang<355){
oriented=false;
if(ang<180&&ang>5){
  int vel=ang+50;
  robot.turnleft(vel);
  //Serial.println(vel);
}
if(ang>=180&&ang<355){
  int vel=360-ang+50;
  robot.turnright(vel);
  
  //Serial.println(vel);
}
}
else{
  //Serial.println("nada!");
  oriented=true;
}
}
