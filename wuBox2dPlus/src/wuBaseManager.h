#ifndef wu_BASEMANAGER_H
#define wu_BASEMANAGER_H

#pragma once
#include "ofMain.h"
#include "ofxOpenCv.h"
#include "wuImagePlus.h"

class wuBaseManager
{
    public:
        wuBaseManager();
        ~wuBaseManager();

    void setup(int _vw, int _vh);
	void capture(ofImage *currImg, ofImage *bgImg);
	virtual void addBitxo(ofImage *_skin, ofRectangle rect, ofxCvBlob *blob);
	void setMaxBlobs(int _maxBlobs);
	void setMinBlobSize(int _minBlobSize);
	void setThreshold(int _thres);

	// dimension
    int vw, vh;

		// openCV
	ofxCvColorImage			color;
	ofxCvColorImage			bgColor;
	ofxCvGrayscaleImage		gray;
	ofxCvGrayscaleImage		bgGrayImg;
	ofxCvGrayscaleImage 	grayDiff;

	ofxCvContourFinder		contour;

	int	threshold;
	int minBlobSize;
	int maxBlobs;
};
#endif

