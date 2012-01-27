#include "wuBase2d.h"

wuBase2d::wuBase2d()
{

}

wuBase2d::~wuBase2d()
{
}

void wuBase2d::setup(ofxBox2d * _box2d, ofRectangle rect){

    box2d = _box2d;

	// set width,height values
	width = rect.width;
	height = rect.height;
}
