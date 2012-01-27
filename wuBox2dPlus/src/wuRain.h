
#ifndef wu_RAIN_H
#define wu_RAIN_H

#pragma once
#include "ofMain.h"
#include "ofxOpenCv.h"
#include "ofxBox2d.h"

#define NUM_GOTES 100

// ------------------------------------------------- a simple extended box2d circle
class wuGota : public ofxBox2dCircle {
	
public:

	void draw(int offX=0) {
		float radius = getRadius();
		int valpha = ofRandom(0, 180);

		glPushMatrix();
		glTranslatef(getPosition().x, getPosition().y, 0);
		// blue
        ofEnableAlphaBlending();
//      gotes blaves (fons blanc)
//		ofSetColor(0, 0, 255, valpha);
//      gotes blanques (fons blau)
		ofSetColor(161, 161, 255, valpha);
		ofFill();
		ofCircle(offX, 0, radius);	
        ofDisableAlphaBlending();
		
		glPopMatrix();
		
	}
};

class wuRain
{
    public:
        wuRain();
        ~wuRain();

        void setup(ofxBox2d * _box2d, int _vw, int _vposx=0, int _vposy=0);

        virtual void update();
        virtual void update(int _vposx, int _vposy);
        virtual void draw(int offX=0);
		virtual	void addGota(void);
		virtual	void startRain(void);
		virtual	void stopRain(void);
  
        int vw, vposx, vposy;
		bool isAlive;

        // box2d
        ofxBox2d * box2d;

		vector		<wuGota>	gotes;		  //	default box2d circles

};
#endif

