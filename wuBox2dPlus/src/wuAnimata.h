
#ifndef wu_ANIMATA_H
#define wu_ANIMATA_H

#pragma once
#include "wuHumanoid.h"
//#include "ofxFBOTexture.h"
#include "wuImagePlus.h"
#include "wuSkin.h"


struct SkelModified
{
	ofPoint Lelbow;
	ofPoint Relbow;
	ofPoint Lhand;
	ofPoint Rhand;
	ofPoint Lknee;
	ofPoint Rknee;
	ofPoint Lfoot;
	ofPoint Rfoot;
};

class wuAnimata : public wuHumanoid
{
    public:
        wuAnimata();
        ~wuAnimata();

        virtual void setup(ofxBox2d * _box2d, int _vw, int _vh);
		void setSkel(Skeleton _skel);
		void setSkin( vector <wuSkin> * _skins);
        virtual void draw(bool pinta_bg=false, int offX=0);

		void OrderSkins();
		void skelCorrection();
		virtual void update();
		virtual void update(Skeleton _skel);
		void MakeFBOimage();

        // ofImage skin
//		vector<wuImagePlus>* skins;
		vector<wuSkin>* skins;
		// Texture mix
		ofFbo myFBO;
 
		int ord[11]; // te correct skins order  (we have 11 pieces maximum)
		SkelModified modSkel; 	// new skeleton point calculation


};
#endif

