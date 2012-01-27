#include "wuPapallona.h"

wuPapallona::wuPapallona()
{

}

wuPapallona::~wuPapallona()
{
}

void wuPapallona::setup(ofImage *_skin, ofRectangle rect)
{
	wuBaseSkin::setSkin(_skin, rect);

    counter_pos =0.0;
    counter_wid =0.0;
	vel.x=0;
	vel.y=0;
}

void wuPapallona::update()
{
		if(ofRandom(0,30)<2)
			vel.x = -15.0*ofRandomuf();
		if(ofRandom(0,50)<2)
			vel.x = 15.0*ofRandomuf();
		if(ofRandom(0,30)<2)
			vel.y = -15.0*ofRandomuf();
		if(ofRandom(0,50)<2)
			vel.y = 15.0*ofRandomuf();

		posSkin.x = posSkin.x + vel.x;
		posSkin.y = posSkin.y + vel.y -1;

		counter_pos=counter_pos+0.2;
		if(counter_pos>1.0)
			counter_pos=0.0;

		counter_wid=counter_wid+0.1;
		if(counter_wid>1.0)
			counter_wid=0.0;

}

void wuPapallona::draw(int offX)
{

	if(bSkin)
	{
		float offY = 30 * sin(counter_pos*TWO_PI);  
		float offW = abs(sin(counter_wid*TWO_PI));  

		// draw skin
		ofPushMatrix();
			ofTranslate(posSkin.x+offX, posSkin.y);
			skin.setAnchorPercent(0.5, 0.5);
			ofRotateZ(ofRadToDeg(angSkin));
			ofEnableAlphaBlending();
			ofSetColor(255,255,255,alpha);
			if(skin.getWidth()> skin.getHeight())
				skin.draw(0, 0, skin.getWidth()*offW, skin.getHeight());
			else
				skin.draw(0, 0, skin.getWidth(), skin.getHeight()*offW);
			ofDisableAlphaBlending();
		ofPopMatrix();
	}
}
