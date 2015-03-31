#include <Movimientos.h>
Movimientos lum(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
void setup() { 
  
}
void loop() {
  lum.movefront(255);
  delay(500);
  lum.stop();
  delay(500);
}
