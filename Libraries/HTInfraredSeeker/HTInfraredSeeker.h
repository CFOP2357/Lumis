#ifndef HTInfraredSeeker_h
#define HTInfraredSeeker_h
#include "Arduino.h"
	struct InfraredInput
	{
	  	byte Direction;
	  	byte Strength;
	};
	class InfraredSeeker
	{
		public:
			static void Initialize();
			static void ReadACRaw(byte* buffer);
			static InfraredInput ReadAC();
	  	private:
			static InfraredInput PopulateValues(byte* buffer);
			static void ReadValues(byte OffsetAddress, byte* buffer);
			static const int Address = 0x10 / 2; //Divide by two as 8bit-I2C address is provided
	};
#endif
