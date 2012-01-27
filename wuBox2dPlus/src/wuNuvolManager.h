
#ifndef wu_NUVOLMANAGER_H
#define wu_NUVOLMANAGER_H

#pragma once
#include "wuNuvol.h"
#include "wuBase2dManager.h"

class wuNuvolManager : public wuBase2dManager
{
    public:
        wuNuvolManager();
        ~wuNuvolManager();

		bool capture(ofImage *currImg, ofImage *bgImg);
		void addBitxo(ofImage *_skin, ofRectangle rect, ofxCvBlob *blob);
        void update();
        void draw(bool pinta_bg=false, int offX=0);
        void startRain(void);
        void stopRain(void);
        void clear(void);

		void touch(int _x,int _y, int forceX=300, int forceY=0);
		void drag(int _x,int _y);

		// box2d
        vector <wuNuvol> nuvols;

};
#endif

