//*************************************************************
// an skin and a box2drect (base), hanging by a 2djoint w another box2drect
// (ancora)
//*************************************************************

#ifndef wu_NUVOL_H
#define wu_NUVOL_H

#pragma once
#include "wuBaseSkin.h"
#include "wuBase2d.h"
#include "wuRain.h"

class wuNuvol : public wuBaseSkin, public wuBase2d
{
    public:
        wuNuvol();
        ~wuNuvol();

		void setup(ofxBox2d * _box2d, ofImage *_skin, ofRectangle rect);
		void setup(ofxBox2d * _box2d, ofRectangle rect);
		void set2d(ofxBox2d * _box2d, ofRectangle rect);
        void update();
        void draw(bool pinta_bg=false, int offX=0);
        void startRain(void);
        void stopRain(void);
        void clear(void);
		void setPosition(int _x,int _y);
		void touch(int _x,int _y, int forceX=300, int forceY=0);
		void drag(int _x,int _y);

		// box2d
        ofxBox2dJoint joint;
        ofxBox2dRect base;
        ofxBox2dRect ancora;

		wuRain rain;

};
#endif

