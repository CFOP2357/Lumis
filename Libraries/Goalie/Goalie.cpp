#include "Goalie.h"
#include "Arduino.h"
#include "SPI.h"
#include "Pixy.h"

void Goalie::setEnemy(int index){
	enemy=index;
}
void Goalie::setSelf(int index){
	self=index;
}
void Goalie::setYellow(int index){
	yellow=index;
}
void Goalie::setBlue(int index){
	blue=index;
}

char Goalie::getInfo(int index,Pixy ps){

static int i = 0;
int j;
int x;
uint16_t blocks;
blocks = ps.getBlocks();
if (blocks){
	i++;
	if (i%50==0){
			if(ps.blocks[index].x>110 && ps.blocks[index].x<=210){
				return 'c';
			}
			else if(ps.blocks[index].x<=110){
				return 'i';
			}
			else if(ps.blocks[index].x>210){
				return 'd';
			}
			
			/*	pixelInf.x=ps.blocks[index].x;
				pixelInf.y=ps.blocks[index].y;
				pixelInf.height=ps.blocks[index].height;
				pixelInf.width=ps.blocks[index].width;
				pixelInf.area=pixelInf.height*pixelInf.width;*/   


			
		}
	}
}
char Goalie::getEnemy(Pixy px){
	char enemyIn;
	enemyIn=getInfo(enemy,px);
	return enemyIn;
}
char Goalie::getSelf(Pixy px){
	char selfIn;
	selfIn=getInfo(self,px);
	return selfIn;
}
