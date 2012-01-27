
#ifndef wu_SOLIDRECTMANAGER_H
#define wu_SOLIDRECTMANAGER_H

#pragma once
#include "wuSolidRect.h"
#include "wuBase2dManager.h"

class wuSolidRectManager : public wuBase2dManager
{
    public:
        wuSolidRectManager();
        ~wuSolidRectManager();

	    void setup(ofxBox2d * _box2d, int _vw, int _vh);
		bool capture(ofImage *currImg, ofImage *bgImg, ofPoint _pos);
		void update();
		void addBitxo(ofImage *_skin, ofRectangle rect, ofxCvBlob *blob);
        void draw(bool pinta_bg=false, int offX=0);
        void clear(void);
		void createNewSolidRect(ofPoint _pos);
		void touch(int _x,int _y, int forceX=300, int forceY=0);
		void drag(int _x, int _y);

		// box2d
		vector <wuSolidRect> boxes;

		ofImage generalSkin;
		
		bool bSkinOn;
};
#endif

