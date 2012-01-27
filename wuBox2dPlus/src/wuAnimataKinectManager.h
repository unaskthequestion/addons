
#ifndef wu_ANIMATAKINECTMANAGER_H
#define wu_ANIMATAKINECTMANAGER_H

#pragma once
#include "wuAnimata.h"
#include "wuKinectSkel.h"
#include "wuBase2dManager.h"
#include "wuSkin.h"

class wuAnimataKinectManager : public wuBase2dManager
{
    public:
        wuAnimataKinectManager();
        ~wuAnimataKinectManager();

	    void setup(ofxBox2d * _box2d, wuKinectSkel * _kinSkel, int _vw, int _vh);
		bool capture(ofImage *currImg, ofImage *bgImg);
		bool capture( vector <wuSkin> * _skins);
		void update();
		void addBitxo(ofImage *_skin, ofRectangle rect, ofxCvBlob *blob);
        void draw(bool pinta_bg=false, int offX=0);
        void clear(void);
		void touch(int _x,int _y, int forceX=300, int forceY=0);
		void drag(int _x, int _y);

		// box2d
//		vector <wuAnimata> animatas;
		wuAnimata animata;

		// skins of pieces
        vector <wuSkin> skins;
		
		bool bSkinOn;
		wuKinectSkel * kinSkel;
};
#endif

