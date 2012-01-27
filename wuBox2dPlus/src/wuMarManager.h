
#ifndef wu_MARMANAGER_H
#define wu_MARMANAGER_H

#pragma once
#include "wuMar.h"
#include "wuBase2dShapeManager.h"

class wuMarManager : public wuBase2dShapeManager
{
    public:
        wuMarManager();
        ~wuMarManager();

		virtual void addBitxo(ofImage *_skin, ofRectangle rect, ofxCvBlob *blob);
		void setSimpleAmount(int _simpleAmount);
        void draw(bool pinta_bg=false, int offX=0);
		void clear();

		// box2d
        wuMar mar;

};
#endif

