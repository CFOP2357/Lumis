#include "MC33926.h"
#include "Arduino.h"
MC33926::MC33926()
{

}
void MC33926::setM1(int IN1, int IN2, int PWMD1, int PWMD2)
{
	_IN1[0]=IN1;
	_IN2[0]=IN2;
	_PWMD1[0]=PWMD1; 	
	_PWMD2[0]=PWMD2;
	pinMode(_IN1[0], OUTPUT);
	pinMode(_IN2[0], OUTPUT);
	pinMode(_PWMD1[0], OUTPUT);
	pinMode(_PWMD2[0], OUTPUT);
}
void MC33926::setM2(int IN1, int IN2, int PWMD1, int PWMD2)
{
	_IN1[1]=IN1;
	_IN2[1]=IN2;
	_PWMD1[1]=PWMD1; 	
	_PWMD2[1]=PWMD2;
	pinMode(_IN1[2], OUTPUT);
	pinMode(_IN2[2], OUTPUT);
	pinMode(_PWMD1[2], OUTPUT);
	pinMode(_PWMD2[2], OUTPUT);
}
void MC33926::fwd(int n, int speed)
{
	digitalWrite(_IN1[n], HIGH);
	digitalWrite(_IN2[n], LOW);
	analogWrite(_PWMD1[n], speed);
	analogWrite(_PWMD2[n], speed);
}
void MC33926::rev(int n, int speed)
{
	digitalWrite(_IN1[n], LOW);
	digitalWrite(_IN2[n], HIGH);
	analogWrite(_PWMD1[n], speed);
	analogWrite(_PWMD2[n], speed);
}

void MC33926::off(int n)
{
	digitalWrite(_IN1[n], LOW);
	digitalWrite(_IN2[n], LOW);
	analogWrite(_PWMD1[n], 0);
	analogWrite(_PWMD2[n], 0);
}

