
#ifndef wu_SOLIDRECT_H
#define wu_SOLIDRECT_H

#pragma once
#include "ofMain.h"
#include "ofxOpenCv.h"
#include "ofxBox2d.h"

class wuSolidRect : public ofxBox2dRect 
{

    public:
        wuSolidRect();
        ~wuSolidRect();

	    void setImg(ofImage * _img);
	    void setDim(float _w, float _h);
		void update();
		void draw(int offX=0);
		void setPosition(int _x, int _y);
		void touch(int _x,int _y, int forceX=100, int forceY=0);
		void drag(int _x,int _y);

		ofImage * img;
		float w;
		float h;
		bool isDead;

};
#endif

