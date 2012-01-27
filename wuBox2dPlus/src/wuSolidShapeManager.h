
#ifndef wu_SOLIDSHAPEMANAGER_H
#define wu_SOLIDSHAPEMANAGER_H

#pragma once
#include "wuSolidShape.h"
#include "wuBase2dShapeManager.h"

class wuSolidShapeManager : public wuBase2dShapeManager
{
    public:
        wuSolidShapeManager();
        ~wuSolidShapeManager();

		void capture(ofImage *currImg, ofImage *bgImg);
		virtual void addBitxo(ofImage *_skin, ofRectangle rect, ofxCvBlob *blob);
		void setSimpleAmount(int _simpleAmount);
        void draw(bool pinta_bg=false, int offX=0);
		void clear();

		// box2d
        vector <wuSolidShape> shapes;

};
#endif

