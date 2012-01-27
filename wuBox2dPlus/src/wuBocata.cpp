#include "wuBocata.h"

wuBocata::wuBocata()
{

}

wuBocata::~wuBocata()
{
}

void wuBocata::setup(ofImage *_skin, ofRectangle rect)
{
	wuBaseSkin::setSkin(_skin, rect);
}

void wuBocata::update(ofPoint _pos)
{
	posSkin = _pos;

	// posició oscil.lant
	counter=counter+0.02;
	if(counter>1.0)
		counter=0.0;

	float offSIN = 5*sin(counter*TWO_PI);
	posSkin.x = posSkin.x + skin.getWidth() -8;
	posSkin.y = posSkin.y + skin.getHeight() -3 - offSIN; 

}