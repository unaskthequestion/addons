
#ifndef wu_FOREGROUNDSKINMANAGER_H
#define wu_FOREGROUNDSKINMANAGER_H

#pragma once
#include "wuSkin.h"
#include "wuBaseManager.h"

class wuForegroundSkinManager : public wuBaseManager
{
    public:
        wuForegroundSkinManager();
        ~wuForegroundSkinManager();

		bool capture(ofImage *currImg, ofImage *bgImg);
		void addBitxo(ofImage *_skin, ofRectangle rect, ofxCvBlob *blob);
        void draw(int offX=0);
        void clear(void);

		// skins
        vector <wuSkin> skins;

};
#endif

