#ifndef Goalie_h
#define Goalie_h
#include "Arduino.h"
#include "Pixy.h"

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
			char getInfo(int index,Pixy ps);
			char getEnemy(Pixy px);
			char getSelf(Pixy px);
	};
#endif
