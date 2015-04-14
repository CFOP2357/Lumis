#include <Wire.h>
#include <HTInfraredSeeker.h>
InfraredSeeker seeker=InfraredSeeker();
InfraredInput seekerInput;//data structure with the seeker's readings
void setup() {
  Wire.begin();
  Serial.begin(9600);
}
void loop() {
  seekerInput=seeker.ReadAC();
  Serial.print("Strength     Direction");
  Serial.println(seekerInput.Strength);
}
