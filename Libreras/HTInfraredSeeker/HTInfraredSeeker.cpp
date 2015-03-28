#include "Arduino.h"
#include "Wire.h"
#include "HTInfraredSeeker.h"

void InfraredSeeker::Initialize()
{
	Wire.begin();
  	Wire.beginTransmission(InfraredSeeker::Address);
  	Wire.write(0x00);
  	Wire.endTransmission();
}
void InfraredSeeker::ReadValues(byte OffsetAddress, byte* buffer)
{
	InfraredSeeker::Initialize();
	Wire.beginTransmission(InfraredSeeker::Address);
	Wire.write(OffsetAddress);
	Wire.endTransmission();
	Wire.requestFrom(InfraredSeeker::Address, 6);
	for(byte i = 0; i < 6; i++)
	{
		buffer[i] = Wire.read();
	}
	while(Wire.available() > 0)
	Wire.read();
	Wire.endTransmission();
}

void InfraredSeeker::ReadACRaw(byte* buffer)
{
	ReadValues(0x49, buffer);
}

InfraredInput InfraredSeeker::PopulateValues(byte* buffer)
{
	InfraredInput Data;
	Data.Direction = buffer[0];
	if(buffer[0] != 0)
	{
		if(buffer[0] % 2 == 0)
		{
			Data.Strength = (buffer[buffer[0] / 2] + buffer[buffer[0] / 2 + 1]) / 2;
		}
		else
		{
			Data.Strength = buffer[buffer[0] / 2 + 1];
		}
	}
	else
	{
		Data.Strength = 0;
	}
	return Data;
}
InfraredInput InfraredSeeker::ReadAC()
{
	byte buffer[6];
	ReadACRaw(buffer);
	return PopulateValues(buffer);
}
