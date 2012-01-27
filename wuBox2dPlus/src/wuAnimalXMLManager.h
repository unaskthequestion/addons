
#ifndef wu_ANIMALXMLMANAGER_H
#define wu_ANIMALXMLMANAGER_H

#pragma once
#include "wuAnimal.h"
#include "wuBase2dManager.h"
#include "wuSkin.h"


class wuAnimalXMLManager : public wuBase2dManager
{
    public:
        wuAnimalXMLManager();
        ~wuAnimalXMLManager();

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
//		vector <wuAnimal> animals;
		wuAnimal animal;

		// skins of pieces
        vector <wuSkin> skins;

		wuSkin skinInit;
		ofRectangle rectInit;
		
		bool bSkinOn, bReadyGo, bGo;
		string XMLfilename;
};
#endif

