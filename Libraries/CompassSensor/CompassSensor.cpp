#include "Arduino.h"
#include "Wire.h"
#include "CompassSensor.h"

int CompassSensor::getAngle(){
  	Wire.beginTransmission(address);
  	Wire.write("A");
  	Wire.endTransmission();
  	delay(10); 
  	byte headingData[2];
  	int headingValue;
  	Wire.requestFrom(address, 2);
	for(int i=0;i < 2;i++)
	{ 
		headingData[i] = Wire.read();
	}
	headingValue = headingData[0]*256 + headingData[1];
	Wire.endTransmission();
	return int(headingValue/10);
}
void CompassSensor::setAddress(int theAddress){
	address=theAddress;
}
