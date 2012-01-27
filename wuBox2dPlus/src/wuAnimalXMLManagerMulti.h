
#ifndef CR_ANIMALXMLMANAGER_H
#define CR_ANIMALXMLMANAGER_H

#pragma once
#include "crAnimal.h"
#include "crBase2dManager.h"
#include "crSkin.h"


class crAnimalXMLManager : public crBase2dManager
{
    public:
        crAnimalXMLManager();
        ~crAnimalXMLManager();

	    void setup(ofxBox2d * _box2d, string _XMLfilename, int _vw, int _vh);
		bool capture(ofImage *currImg, ofImage *bgImg);
		void update();
		void addBitxo(ofImage *_skin, ofRectangle rect, ofxCvBlob *blob);
        void draw(bool pinta_bg=false, int offX=0);
        void clear(void);
		void touch(int _x,int _y, int forceX=300, int forceY=0);
		void drag(int _x, int _y);

		// box2d
		vector <crAnimal> animals;
//		crAnimal animal;

		// skins of pieces
        vector <crSkin> skins;
		
		bool bSkinOn;
		string XMLfilename;
};
#endif

