
#ifndef wu_SKINMANAGER_H
#define wu_SKINMANAGER_H

#pragma once
#include "wuSkin.h"
#include "wuBaseManager.h"

class wuSkinManager : public wuBaseManager
{
    public:
        wuSkinManager();
        ~wuSkinManager();

		bool capture(ofImage *currImg, ofImage *bgImg);
		void addBitxo(ofImage *_skin, ofRectangle rect, ofxCvBlob *blob);
        void draw(int offX=0);
        void clear(void);
		void OrderSkins();

		vector <wuSkin> * getSkin();
		ofPoint getPosition(int i);
		ofPoint getPosition();
		float getRotation();
		float getRotation(int i);
		int getNumberSkins();
		void setPosition(int i, ofPoint _pos);
		void setPosition(ofPoint _pos);
		void setRotation(int i, float _ang);
		void setRotation(float _ang);
		int isTouched(int _x,int _y);

		// skins
        vector <wuSkin> skins;

};
#endif

