
#ifndef wu_GRAYIMG_H
#define wu_GRAYIMG_H

#include "ofxOpenCv.h"

class wuGrayImg : public ofxCvGrayscaleImage {
public:
	wuGrayImg();

	void isolateColor(ofxCvColorImage *videoColorCvImage, int hue, int sat, int val, int hueRange, int satRange, int valRange);
	void mix(ofxCvGrayscaleImage *grayInput, bool invert=false);
	void set_antiTocata(int centreX, int centreY, int radi, int vw, int vh, bool invert=false);
	void setFromAlphaPixels(unsigned char * colorPixels, int vw, int vh, bool isTexture=false);

private:

};

#endif
