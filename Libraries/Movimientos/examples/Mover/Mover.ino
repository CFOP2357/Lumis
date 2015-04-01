#include <Movimientos.h>
Movimientos robot= Movimientos(22, 23); //P1EN, P2EN
void setup() { 
  robot.setMotorA(24, 26, 2, 3); //in1, in2, pwm1, pwm2
  robot.setMotorB(28, 30, 4, 5);
  robot.setMotorC(25, 27, 6, 7);
  robot.setMotorD(29, 31, 8, 9);
}
void loop() {
  robot.on();
  robot.turnleft(255); //speed
  delay(500);
  robot.turnright(255);
  delay(500);
  robot.movefront(255);
  delay(500);
  robot.moveback(255);
  delay(500);
  robot.sleep();
  delay(500);
}