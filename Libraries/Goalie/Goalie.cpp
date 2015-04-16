#include "Goalie.h"
#include "Arduino.h"
#include "SPI.h"
#include "Pixy.h"
int Goalie::getEnemy(){
	return enemy;
}
int Goalie::getSelf(){
	return self;
}
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
void Goalie::calibrate(){
	int area=0;
	int area2=0;
	pixelIn pixels=getInfo(yellow);
	area=pixels.area;
	pixels=getInfo(blue);
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
pixelIn Goalie::getInfo(int index){
	Pixy pixy;
	pixy.init();
	pixelIn pixelInf;
	pixelInf.x=pixy.blocks[index].x;
	pixelInf.y=pixy.blocks[index].y;
	pixelInf.height=pixy.blocks[index].height;
	pixelInf.width=pixy.blocks[index].width;
	pixelInf.area=pixelInf.height*pixelInf.width;
	return pixelInf;
}
