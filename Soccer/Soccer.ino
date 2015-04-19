#include "Ultrasonic.h"

#include <SPI.h>
#include <Pixy.h>
#include <Goalie.h>

#include <CompassSensor.h>

#include <Movimientos.h>
#include <Wire.h>
#include <HTInfraredSeeker.h>




Ultrasonic ultrasonic(12,13);


Movimientos robot=  Movimientos();

CompassSensor compass=CompassSensor();

InfraredSeeker seeker=InfraredSeeker();
InfraredInput seekerInput;
bool oriented=false;
bool closeB=false;

int startingAngle;
Pixy pd;

Goalie gl=Goalie();



void setup() {
  Serial.begin(9600);
  Wire.begin();
  
  compass.setAddress(0x21);
  startingAngle=compass.getAngle();
  while(gl.getEnemy()==0){
      gl.calibrate(pd);
  }
}

void loop() {
  
  int current=compass.getAngle();
  int angle=compass.calibratedAngles(startingAngle,current);
  seekerInput=seeker.ReadAC();
  if(!closeB){
    orient(angle);
    while(!oriented){
      current=compass.getAngle();
      angle=compass.calibratedAngles(startingAngle,current);
      orient(angle);
    }
  }
  followball(seekerInput,&millisSet);
}
void followball(InfraredInput in){
  //LEJOS
    //robot.on();
    if(in.StrengthAll>=130){
    if(in.StrengthAll<=180){
      closeB=true;
    }
    else{
      closeB=false;
    }
    switch(in.Direction){
      
      case 0:
        if(in.StrengthAll<=180){
          robot.turnleft(255);
        }
        else{
          robot.diagonalbackright(255);
        }
      break;
      case 1:
        if(in.StrengthAll<=180){
          robot.turnright(255);
        }
        else{
          robot.moveback(255);
        }
      break;
      case 2:
        if(in.StrengthAll<=180){
          robot.turnright(255);
        }
        else{
          robot.moveback(255);
        }
      break;
      case 3:
        if(in.StrengthAll<=180){
          robot.turnright(255);
        }
        else{
          robot.moveright(255);
        }
      break;
      case 4:
        if(in.StrengthAll<=180){
          robot.turnright(100);
        }
        else{
          robot.moveright(255);
        }
      break;
      case 5:
      if(in.StrengthAll<=180){
        kick();
      }
      else{
        robot.movefront(255);
      }
      break;
      case 6:
        if(in.StrengthAll<=180){
          robot.turnleft(100);
        }
        else{
          robot.moveleft(255);
        }
      break;
      case 7:
        if(in.StrengthAll<=180){
          robot.turnleft(255);
        }
        else{
          robot.moveleft(255);
        }
      
      break;
      case 8:
        if(in.StrengthAll<=180){
          robot.turnleft(255);
        }
        else{
          robot.moveback(255);
        }
      
      break;
      case 9:
        if(in.StrengthAll<=180){
          robot.turnleft(255);
        }
        else{
          robot.moveback(255);
        }
      break;
  }
  }
  else{
    robot.moveback(100);
  }
  //CERCA
  
  
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

void kick(){
  robot.movefront(255);
  delay(500);
  InfraredInput aux=seeker.ReadAC();
  int dist;
  while(aux.StrengthAll<=180){
    aux=seeker.ReadAC();
    dist=ultrasonic.Ranging(CM);
    if(dist>=15){
      randomSeed(analogRead(0));
      int side=random(0, 2);
      millisSet=millis;
      int k=millisSet-millis();
      if(side==0){
        while(analogRead(A0)>50&&k<1000){//qtr o color
          k=millisSet-millis();
          robot.moveleft(255);
        }
      }
      else{
        while(analogRead(A0)>50&&k<1000){//qtr o color
          k=millisSet-millis();
          robot.moveright(255);
        }
      }
      
      if(Goalie.getEnemyV(pd)!='c'){
        if(Goalie.getEnemyV(pd)=='d'){
          //robot.turnright(100);
        }
        if(Goalie.getEnemyV(pd)=='i'){
          //robot.turnleft(100);
        }
      }
      else{
        //kickBall();
      }
      
    }
  }
}
