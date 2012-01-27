#ifndef _wuGrass_H
#define _wuGrass_H

#pragma once
#include "ofMain.h"
#include "ofxBox2d.h"
#include "ofxOpenCv.h"

#include "wuBlade.h"

#define MAX_NUM_BLADES 100

class wuGrass {
  public:
	wuGrass();

	void setup(ofxBox2d * _box2d);
	void setup(ofxBox2d * _box2d, vector<ofPoint> &points);
	void update();
	void draw(int x=0, int y=0);
	void mouseMoved(int x, int y);
	void setFlatField();
	void setFieldFromPoints(vector<ofPoint> &points);
	void setRandomField();
	void addBlade(ofPoint pt);
	void setBladePoints(vector<ofPoint> points);
	void setLoc(float x, float y);
	void setWidth(float w);
    void capture(ofxCvColorImage *color, ofxCvGrayscaleImage * grayDiff);
    void clear();

	ofxBox2d		*box2d;

	vector<wuBlade>	mBlades;
	int				mBladeCount;
	ofPoint			mLoc;
	float			mWidth;
	float			alive;

	vector<ofPoint> mBladePoints;
	vector<ofPoint> grabContourPoints();
	vector<ofPoint>	grassPoints;

	ofxCvContourFinder	contour;

	int mouseX;
	int mouseY;

};

#endif
