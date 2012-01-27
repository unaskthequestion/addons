
#ifndef wu_BOCATAMANAGER_H
#define wu_BOCATAMANAGER_H

#pragma once
#include "wuBocata.h"
#include "wuBaseManager.h"

class wuBocataManager : public wuBaseManager
{
    public:
        wuBocataManager();
        ~wuBocataManager();

	    void setup(int _vw, int _vh);
		bool capture(ofImage *currImg, ofImage *bgImg);
		void addBitxo(ofImage *_skin, ofRectangle rect, ofxCvBlob *blob);
		void update(ofPoint _pos);
        void draw(int offX=0);
        void clear(void);

		// skins
        wuBocata bocata;
		bool bBocataOn;
};
#endif

