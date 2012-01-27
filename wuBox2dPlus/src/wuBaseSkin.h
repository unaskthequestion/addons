#ifndef wu_BASESKIN_H
#define wu_BASESKIN_H

#pragma once
#include "ofMain.h"

class wuBaseSkin
{
    public:
        wuBaseSkin();
        ~wuBaseSkin();

		void setSkin(ofImage *_skin, ofRectangle rect);
        void draw(int offX=0);
		ofPoint getPosition();
		float getRotation();
		void setPosition(ofPoint _pos);
		void setRotation(float _ang);
		void setColor(int _r, int _g, int _b, int _alpha);
		bool isTouched(int _x,int _y);
		int getWidth();
		int getHeight();

		ofImage skin;

		ofPoint posSkin;
		float angSkin;

		int r,g,b,alpha;

		bool bSkin;

};
#endif

