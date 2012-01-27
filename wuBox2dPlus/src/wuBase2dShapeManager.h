#ifndef wu_BASE2DSHAPEMANAGER_H
#define wu_BASE2DSHAPEMANAGER_H

#pragma once
#include "wuBase2dManager.h"
#include "ofxContourAnalysis.h"


class wuBase2dShapeManager : public wuBase2dManager
{
    public:
        wuBase2dShapeManager();
        ~wuBase2dShapeManager();

	    void setup(ofxBox2d * _box2d, int _vw, int _vh);
//		void capture(ofImage *currImg, ofImage *bgImg);
		virtual void addBitxo(ofImage *_skin, ofRectangle rect, ofxCvBlob *blob);
		void setSimpleAmount(int _simpleAmount);
		void bypass(bool _bBypass);

		// openCV
		ofxContourAnalysis	contourAnalysis;
        vector <ofPoint> simpleCountour;

		float	simpleAmount;

		bool bBypass;
};
#endif

