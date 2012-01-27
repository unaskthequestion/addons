
#ifndef wu_PLATFORMMANAGER_H
#define wu_PLATFORMMANAGER_H

#pragma once
#include "wuSolidShape.h"
#include "wuBase2dShapeManager.h"

class wuPlatformManager : public wuBase2dShapeManager
{
    public:
        wuPlatformManager();
        ~wuPlatformManager();

//		void capture(ofImage *currImg, ofImage *bgImg);
		virtual void addBitxo(ofImage *_skin, ofRectangle rect, ofxCvBlob *blob);
		void setSimpleAmount(int _simpleAmount);
        void draw(bool pinta_bg=false, int offX=0);
		void clear();

		// box2d
        vector <wuSolidShape> shapes;

};
#endif

