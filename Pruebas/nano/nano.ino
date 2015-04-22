#include <SPI.h>
#include <Goalie.h>
#include <Pixy.h>

Goalie pxy=Goalie();
Pixy pd;
char a='s';
void setup() {
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pd.init(); 
}

void loop(){
  a='s';
  a=pxy.getInfo(3,pd);
  if(a=='c'){
    digitalWrite(7, HIGH);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
  }
  else if(a=='d'){
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);
    digitalWrite(7, LOW);
  }
  else if(a=='i'){
    digitalWrite(9, HIGH);
    digitalWrite(8, LOW);
    digitalWrite(7, LOW);
  }
  else{
    digitalWrite(8, HIGH);
    digitalWrite(7, LOW);
    digitalWrite(10, LOW);
  }
}
