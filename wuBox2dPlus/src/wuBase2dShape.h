//*************************************************************
// Generic Physics_object
// with box2d Shape 
//*************************************************************

#ifndef wu_BASE2DSHAPE_H
#define wu_BASE2DSHAPE_H

#pragma once
#include "wuBase2d.h"

class wuBase2dShape : public wuBase2d
{
    public:
        wuBase2dShape();
        ~wuBase2dShape();

        virtual void setup(ofxBox2d * _box2d, ofRectangle rect);
		void setSimpleAmount(int _simpleAmount);
		void byPass(bool _bBypass);
		void draw(bool pinta_bg=false, int offX=0);

		// box2d
		ofxBox2dLine lineStrip;
 

};
#endif

