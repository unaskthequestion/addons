//*************************************************************
// Generic Physics_object
// with 0 box2d objects 
//*************************************************************

#ifndef wu_BASE2D_H
#define wu_BASE2D_H

#pragma once
#include "ofxBox2d.h"

class wuBase2d
{
    public:
        wuBase2d();
        ~wuBase2d();

        virtual void setup(ofxBox2d * _box2d, ofRectangle rect);

		// box2d
        ofxBox2d * box2d;

		int width, height;

};
#endif

