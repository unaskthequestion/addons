#include "wuBaseSkin.h"

wuBaseSkin::wuBaseSkin()
{

}

wuBaseSkin::~wuBaseSkin()
{
}

void wuBaseSkin::setColor(int _r, int _g, int _b, int _alpha){
	r = _r;
	g = _g;
	b = _b;
   	alpha = _alpha;
}

void wuBaseSkin::setSkin(ofImage *_skin, ofRectangle rect){

	skin.clear();

	skin.setFromPixels(_skin->getPixels(), rect.width, rect.height, OF_IMAGE_COLOR_ALPHA);

	bSkin = true;
	// pos center skin
	posSkin.x = rect.x + rect.width/2;
	posSkin.y = rect.y + rect.height/2;
	angSkin = 0.0;

	r = 255;
	g = 255;
	b = 255;
	alpha = 255;
}

void wuBaseSkin::draw(int offX)
{

	if(bSkin)
	{
		// draw skin
		ofPushMatrix();
			ofTranslate(posSkin.x+offX, posSkin.y);
			skin.setAnchorPercent(0.5, 0.5);
			ofRotateZ(ofRadToDeg(angSkin));
			ofEnableAlphaBlending();
			ofSetColor(r,g,b,alpha);
			skin.draw(0, 0);
			ofDisableAlphaBlending();
		ofPopMatrix();
	}
}

ofPoint wuBaseSkin::getPosition()
{
	return posSkin;
}

float wuBaseSkin::getRotation()
{
	return angSkin;
}

void wuBaseSkin::setPosition(ofPoint _pos)
{
	posSkin =_pos;
}

void wuBaseSkin::setRotation(float _ang)
{
	angSkin = _ang;
}

bool wuBaseSkin::isTouched(int _x,int _y)
{
	bool bTouched = false;

	if( (_x > posSkin.x-skin.getWidth()/2) && (_x < posSkin.x + skin.getWidth()/2) && (_y > posSkin.y - skin.getHeight()/2) && (_y < posSkin.y + skin.getHeight()/2) ) 
			bTouched = true;
	return bTouched;
}
int wuBaseSkin::getWidth()
{
	return skin.getWidth();
}
int wuBaseSkin::getHeight()
{
	return skin.getHeight();
}

