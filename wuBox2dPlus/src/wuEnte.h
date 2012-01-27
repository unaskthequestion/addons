
#ifndef wu_ENTE_H
#define wu_ENTE_H

#pragma once
#include "ofMain.h"
#include "ofxContourAnalysis.h"
#include "ofxBox2d.h"
#include "wuImagePlus.h"
#include "wuGrayImg.h"

class wuEnte
{
    public:
        wuEnte();
        ~wuEnte();

        virtual void setup(ofxBox2d * _box2d, int _vw, int _vh);
		virtual void update();
        virtual void draw(bool pinta_bg=false, int offX=0);
		virtual void FindShape(wuGrayImg * _grayDiff);
		virtual void setPosition(int _x,int _y);
		virtual ofPoint getPosition();
		virtual bool isTouched(int _x,int _y);
		virtual void setContourAmount(int _simpleAmount);
		virtual void Touch(int _x,int _y, int forceX=300, int forceY=0);

		// box2d
        ofxBox2d * box2d;

		// base box2D
        ofxBox2dRect base;
        vector <ofxBox2dLine> lineStrips;
		int basedim;

		// openCV
		wuGrayImg 				grayDiff;
		ofxCvContourFinder		contour;
        ofxContourAnalysis		contourAnalysis;
        vector <ofPoint>		simpleCountour;
        float	simpleAmount;

		bool bTouched;

		ofRectangle rect;
		ofPoint	initPos; // init position
		int vw, vh; // camera size
		ofPoint scale;
		ofPoint framePos; // kinFrameX, framePos.y; // frame position
		ofPoint shapeOff; //X, shapeOffY;
		wuImagePlus wú;
};
#endif

