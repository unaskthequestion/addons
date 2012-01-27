#include "wuEnanito.h"

wuEnanito::wuEnanito()
{
}

wuEnanito::~wuEnanito()
{
}

void wuEnanito::setup(ofxBox2d * _box2d, int _vw, int _vh)
{
		wuHumanoid::setup(_box2d, _vw, _vh);
		myFBO.allocate(vw, vh, GL_RGBA);
		myFBO.clear(0, 0, 0, 0);
		mask.allocate(vw,vh, OF_IMAGE_GRAYSCALE);
}

void wuEnanito::update(Skeleton _skel, unsigned char* colorSkin, unsigned char* graySkin)
{
	wuHumanoid::setSkel( _skel);

	if (skel.bDetected)
	{
		// crop bitmap
		skin.crop(colorSkin, graySkin, vw, vh);
		mask.setFromPixels( graySkin, vw, vh, OF_IMAGE_GRAYSCALE);
		MakeFBOimage();
//		FindShape(&grayDiff);
	}

	wuHumanoid::update();
}
void wuEnanito::draw(bool bDrawlines, int offX)
{
	wuHumanoid::draw(bDrawlines, offX);

    // pinta skin
	if (skel.bDetected)
	{
		ofPushMatrix();
			ofEnableAlphaBlending();
			ofSetColor(255, 255, 255, 255);
			skin.draw(framePos.x, framePos.y, vw*scale.x, vh*scale.y);
			ofDisableAlphaBlending();
		ofPopMatrix();
//		ofEnableAlphaBlending();
//		myFBO.draw(offX,0);
//		ofDisableAlphaBlending();
	}

}

void wuEnanito::MakeFBOimage()
{
	float angle;
	float lineX;
	float lineY;

//	ofSetColor(255, 255, 255, 255);

    //  2 body pieces minimum
	if (skel.bDetected) 
	{

		myFBO.clear(0, 0, 0, 0);

		myFBO.begin();
		glClearColor(0, 0, 0, 0);

		ofPushMatrix();
			ofEnableAlphaBlending();
			ofSetColor(255, 255, 255, 255);
			mask.draw(framePos.x, framePos.y, vw*scale.x, vh*scale.y);
			ofDisableAlphaBlending();
		ofPopMatrix();

		myFBO.end();
 
		grayDiff.setFromAlphaPixels((unsigned char *)myFBO.getPixels(), vw, vh, true);
		grayDiff.blur(5);

	}

}
