
#ifndef wu_GRASSMANAGER_H
#define wu_GRASSMANAGER_H

#pragma once
#include "wuGrass.h"
#include "wuBase2dShapeManager.h"

class wuGrassManager : public wuBase2dShapeManager
{
    public:
        wuGrassManager();
        ~wuGrassManager();

		void update();
		virtual void addBitxo(ofImage *_skin, ofRectangle rect, ofxCvBlob *blob);
		void setSimpleAmount(int _simpleAmount);
        void draw(int x=0, int y=0);
		void clear();
		void mouseMoved(int x, int y );

		// box2d
        vector <wuGrass> grasses;

};
#endif

