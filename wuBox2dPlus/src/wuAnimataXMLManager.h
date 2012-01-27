
#ifndef wu_ANIMATAXMLMANAGER_H
#define wu_ANIMATAXMLMANAGER_H

#pragma once
#include "wuAnimataXML.h"
#include "wuBase2dManager.h"
#include "wuSkin.h"


class wuAnimataXMLManager : public wuBase2dManager
{
    public:
        wuAnimataXMLManager();
        ~wuAnimataXMLManager();

	    void setup(ofxBox2d * _box2d, string _XMLfilename, int _vw, int _vh);
		bool capture(ofImage *currImg, ofImage *bgImg);
		void update();
		void addBitxo(ofImage *_skin, ofRectangle rect, ofxCvBlob *blob);
        void draw(bool pinta_bg=false, int offX=0);
        void clear(void);
		void OrderSkins();
		void touch(int _x,int _y, int forceX=300, int forceY=0);
		void drag(int _x, int _y);

		// box2d
//		vector <wuAnimataXML> animatas;
		wuAnimataXML animata;

		// skins of pieces
        vector <wuSkin> skins;

		wuSkin skinInit;
		ofRectangle rectInit;
		
		bool bSkinOn, bReadyGo, bGo;
		string XMLfilename;
};
#endif

