#ifndef wu_MASSIVEMANAGER_H
#define wu_MASSIVEMANAGER_H

#pragma once
#include "wuBase2dManager.h"
#include "ofxTriangle.h"
#include "wuMassive.h"

class wuMassiveManager : public wuBase2dManager
{
    public:
        wuMassiveManager();
        ~wuMassiveManager();

		void setup(ofxBox2d * _box2d, int _vw, int _vh);
		void setParams(float _lin_damp, float _restitution, float _friction);
		void update();
		void addBitxo(ofImage *_skin, ofRectangle rect, ofxCvBlob *blob);
        void draw(bool pinta_bg=false, int offX=0);
		void clear();
		void setResolution(int _res);
		void touch(int _x,int _y, int forceX=300, int forceY=0);

		// box2d
        vector <wuMassive> massives;

		int tri_res;
		float lin_damp, restitution, friction;
};
#endif

