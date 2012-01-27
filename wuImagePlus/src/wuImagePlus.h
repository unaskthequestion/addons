
#ifndef wu_IMAGEPLUS_H
#define wu_IMAGEPLUS_H

#include "ofImage.h"
#include "ofxOpenCv.h"

class wuImagePlus : public ofImage {
public:
	wuImagePlus();
	void crop(unsigned char * colorPixels, unsigned char * graymaskPixels, int vw, int vh, int cropX, int cropY, int cropWidth, int cropHeight);
	void crop(unsigned char * colorPixels, unsigned char * graymaskPixels, int vw, int vh);
	void crop(unsigned char * colorPixels, int vw, int vh, int cropX, int cropY, int cropWidth, int cropHeight);
	void crop(unsigned char * colorPixels, unsigned char * graymaskPixels, int vw, int vh, ofRectangle rect);
	void crop_unicolor(unsigned char * graymaskPixels, int vw, int vh);
	void crop_thres(unsigned char * colorPixels, unsigned char * graymaskPixels, int vw, int vh, int cropX, int cropY, int cropWidth, int cropHeight, int thres=0);
	void crop_thres(unsigned char * colorPixels, unsigned char * graymaskPixels, int vw, int vh, int thres=0);
    void deleteColor(int hue, int sat, int val, int hueRange, int satRange, int valRange, bool isolate=false);
    void deleteColor(char color, bool isolate=false);
    void getHSVPixel(int pixel, int* hue, int* sat, int* val);
	void mirror(bool horizontal, bool vertical);  
	void alpha2RGB(unsigned char * colorPixels, int vw, int vh, bool bWhite=false);
	void eraseTrans(int cropX2, int cropY2, int cropW2, int cropH2);
	bool capture(ofxCvColorImage *color, ofxCvGrayscaleImage * grayDiff, int vw, int vh);


	ofPoint pos;
	float ang;

private:
	void flipPixels(ofPixels &pix, bool horizontal, bool vertical);  

};

#endif
