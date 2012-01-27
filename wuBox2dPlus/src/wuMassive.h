#ifndef wu_MASSIVE_H
#define wu_MASSIVE_H

#pragma once
#include "wuBaseSkin.h"
#include "wuBase2d.h"
#include "ofxTriangle.h"

class wuMassive : public wuBaseSkin, public wuBase2d
{
    public:
        wuMassive();
        ~wuMassive();

		void setup(ofxBox2d * _box2d, ofImage *_skin, ofRectangle rect, vector<ofxTriangleData> triangles, float _lin_damp=0.25, float _restitution=0.0f, float _friction=5.0);
		void makeComplexBody(b2Body* body, vector <ofxTriangleData> triangles);
		void update();
 //       void draw(bool pinta_bg=false, int offX=0);
        void clear(void);
		void setParams(float _lin_damp, float _ang_damp, float _restitution, float _friction);
		void touch(int _x,int _y, int forceX=300, int forceY=0);

		// box2d
        b2Body* body;

		float lin_damp, ang_damp, restitution, friction;

 
};
#endif

