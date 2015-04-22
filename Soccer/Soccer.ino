#include <CompassSensor.h>

#include <Movimientos.h>
#include <Wire.h>
#include <HTInfraredSeeker.h>

Movimientos robot=  Movimientos();

CompassSensor compass=CompassSensor();

InfraredSeeker seeker=InfraredSeeker();
InfraredInput seekerInput;
bool oriented=false;
int btn;
int startingAngle;

int drx, dry, dr;


const int s0 = 14;  
const int s1 = 15;  
const int s2 = 17;  
const int s3 = 18;  
const int out = 16;
// Variables  
int red = 0;  
int green = 0;  
int blue = 0; 

void setup() {
  //Serial.begin(9600);
  Wire.begin();
  compass.setAddress(0x21);
  startingAngle=compass.getAngle();

}

void loop() {
  Line();
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
  if(f<170){
    //robot.on();
    switch(k){
      case 0:
        robot.diagonalbackright(255);
        drx=1;
        dry=0;
      break;
      case 1:
      robot.moveback(255);
      dry=0;
      break;
      case 2:
      robot.moveback(255);
      dry=0;
      break;
      case 3:
      robot.moveright(255);
      drx=1;
      break;
      case 4:
      robot.moveright(255);
      drx=1;
      break;
      case 5:
      robot.movefront(255);
      dry=1;
      break;
      case 6:
      robot.moveleft(255);
      drx=0;
      break;
      case 7:
      robot.moveleft(255);
      drx=0;
      break;
      case 8:
      robot.moveback(255);
      dry=0;
      break;
      case 9:
      robot.moveback(255);
      dry=0;
      break;
      
    }
  }
  //CERCA
  else{
 switch(k){
      case 1:
      robot.diagonalbackleft(255);
      dry=0;
      drx=0;
      break;
      case 2:
      robot.diagonalbackleft(100);
      dry=0;
      drx=0;
      break;
      case 3:
      robot.moveright(150);
      dry=0;
      break;
      case 4:
      robot.moveright(100);
      dry=0;
      break;
      case 5:
      robot.movefront(255);
      delay(300);
      /*robot.turnright(255);
      delay(100);*/
      
      /*a='s';
      a=pxy.getInfo(6,pd);
      if(a=='c' || a=='d' || a=='i'){
        if(a=='c'){
          robot.movefront(255);
        }
        if(a=='d'){
          robot.diagonalright(255);
          delay(300);
        }
        if(a=='i'){
         robot.diagonalleft(255);
          delay(300);
        }
        
      }
      else{
        robot.movefront(255);
      }*/
      break;
      case 6:
      robot.moveleft(100);
      drx=0;
      break;
      case 7:
      robot.moveleft(150);
      drx=0;
      break;
      case 8:
      robot.diagonalbackright(100);
      dry=0;
      drx=1;
      break;
      case 9:
      robot.diagonalbackright(255);
      dry=0;
      drx=1;
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
void color()  
{    
  digitalWrite(s2, LOW);  
  digitalWrite(s3, LOW);  
  //count OUT, pRed, RED  
  red = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  
  digitalWrite(s3, HIGH);  
  //count OUT, pBLUE, BLUE  
  blue = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  
  digitalWrite(s2, HIGH);  
  //count OUT, pGreen, GREEN  
  green = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  
}
void Line(){
  color();
  if (green < 10 && blue < 10 && red < 10)  
  {  
   if(drx==1)
   {
       robot.moveleft(255);
       delay(500);
   } 
   if(drx==0)
   {
       robot.moveright(255);
       delay(500);
   } 
   if(dry==1)
   {
       robot.moveback(255);
       delay(500);
   } 
   if(dry==0)
   {
       robot.movefront(255);
       delay(500);
   } 
  } 
}
