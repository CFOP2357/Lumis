#include <Soccer.h>
Soccer robot = Soccer();
bool btn, ball, white, orient, goal;
int s=2;
void setup() {
 //:D
}

void loop() {
  btn = robot.btn();
  ball = robot.ball();
  white = robot.white();
  orient = robot.oriented();
  goal= robot.goal(s);
  if (btn) {
    if(orient){
      robot.on();
      if (!ball){
        robot.followball();  
      }
      else{
        robot.searchgoal(s);
        if(goal){
          robot.shoot();
        }
      }
    }
    else{
      robot.orient();
    }
  }
  else {
    robot.off();
  }
}
