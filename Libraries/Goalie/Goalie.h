#ifndef Goalie_h
#define Goalie_h
#include "Arduino.h"
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
			int getEnemy();
			int getSelf();
			void setEnemy(int index);
			void setSelf(int index);
			void setYellow(int index);
			void setBlue(int index);
			void calibrate();
			pixelIn getInfo(int index);
	};
#endif
