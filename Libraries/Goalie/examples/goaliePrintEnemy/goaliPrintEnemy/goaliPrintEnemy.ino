#include <SPI.h>
#include <Goalie.h>
#include <Pixy.h>

Goalie pxy=Goalie();
Pixy pd;
char a='s';
void setup() {
  Serial.begin(9600);
  pd.init(); 
}

void loop(){
  a='s';
  a=pxy.getInfo(3,pd);
  if(a=='c' || a=='d' || a=='i'){
    Serial.println(a);
  }
}
