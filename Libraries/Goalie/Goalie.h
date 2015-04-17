#ifndef Goalie_h
#define Goalie_h
#include "Arduino.h"
#include "Pixy.h"
	struct pixelIn{
		int area;
		int height;
		int width;
		int x;
		int y;
	};
	class Goalie
	{
		private:
			int yellow;
			int blue;
			int enemy;
			int self;
		public:
			void setEnemy(int index);
			void setSelf(int index);
			void setYellow(int index);
			void setBlue(int index);
			void calibrate(Pixy send);
			pixelIn getInfo(int index,Pixy ps);
			pixelIn getEnemy(Pixy px);
			pixelIn getSelf(Pixy px);
	};
#endif
