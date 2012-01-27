#ifndef wu_SOLIDSHAPE_H
#define wu_SOLIDSHAPE_H

#pragma once
#include "wuBase2d.h"
#include "wuBaseSkin.h"

class wuSolidShape : public wuBaseSkin , public wuBase2d
{
    public:
        wuSolidShape();
        ~wuSolidShape();

		void setup(ofxBox2d * _box2d, ofRectangle rect, vector <ofPoint> * simpleCountour);
		void setup(ofxBox2d * _box2d, ofImage *_skin, ofRectangle rect, vector <ofPoint> *simpleCountour);
        void draw(bool pinta_bg=false, int offX=0);
        void clear(void);

		void Touch(int _x,int _y, int forceX=300, int forceY=0);

		// box2d
		ofxBox2dLine lineStrip;
 
};
#endif

