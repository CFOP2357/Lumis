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
void Goalie::calibrate(Pixy send){
	int area=0;
	int area2=0;
	pixelIn pixels=getInfo(yellow,send);
	area=pixels.area;
	pixels=getInfo(blue,send);
	area2=pixels.area;
	if(area>area2){
		setEnemy(yellow);
		setSelf(blue);
	}
	else{
		setEnemy(blue);
		setSelf(yellow);
	}
}
pixelIn Goalie::getInfo(int index,Pixy ps){
pixelIn pixelInf;
static int i = 0;
int j;
uint16_t blocks;
blocks = pixy.getBlocks();
if (blocks){
	i++;
	if (i%50==0){
			
				pixelInf.x=ps.blocks[index].x;
				pixelInf.y=ps.blocks[index].y;
				pixelInf.height=ps.blocks[index].height;
				pixelInf.width=ps.blocks[index].width;
				pixelInf.area=pixelInf.height*pixelInf.width;

			
		}
	}
	return pixelInf;
}
pixelIn Goalie::getEnemy(Pixy px){
	pixelIn enemyIn;
	enemyIn=getInfo(enemy,px);
	return enemyIn;
}
pixelIn Goalie::getSelf(Pixy px){
	pixelIn selfIn;
	selfIn=getInfo(self,px);
	return selfIn;
}
