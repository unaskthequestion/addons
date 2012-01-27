
#ifndef wu_SOLIDCIRCLEMANAGER_H
#define wu_SOLIDCIRCLEMANAGER_H

#pragma once
#include "wuSolidCircle.h"
#include "wuBase2dManager.h"

class wuSolidCircleManager : public wuBase2dManager
{
    public:
        wuSolidCircleManager();
        ~wuSolidCircleManager();

		bool capture(ofImage *currImg, ofImage *bgImg);
		void addBitxo(ofImage *_skin, ofRectangle rect, ofxCvBlob *blob);
        void update();
        void draw(bool pinta_bg=false, int offX=0);
        void clear(void);

		void touch(int _x,int _y, int forceX=300, int forceY=0);
		void drag(int _x,int _y);

		// box2d
        vector <wuSolidCircle> circles;

};
#endif

