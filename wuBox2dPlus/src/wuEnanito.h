
#ifndef wu_ENANITO_H
#define wu_ENANITO_H

#pragma once
#include "wuHumanoid.h"
//#include "ofxFBOTexture.h"
#include "wuImagePlus.h"

class wuEnanito : public wuHumanoid 
{
    public:
        wuEnanito();
        ~wuEnanito();

		void setup(ofxBox2d * _box2d, int _vw, int _vh);
		void update(Skeleton _skel, unsigned char* colorSkin, unsigned char* graySkin);
        virtual void draw(bool pinta_bg=false, int offX=0);
		void MakeFBOimage();

		// ofImage skin
        wuImagePlus skin;
		ofImage mask;

		ofFbo myFBO;

};
#endif

