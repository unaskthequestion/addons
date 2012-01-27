
#ifndef CR_FBOIMAGEPLUS_H
#define CR_FBOIMAGEPLUS_H

#include "crImagePlus.h"
#include "ofxFBOTexture.h"


class crFBOImagePlus : public crImagePlus {
public:
	crFBOImagePlus();
	void setFromFBOTexture(ofxFBOTexture * myFBO);  
	void draw(float x, float y, float w, float h);
	void draw(float x, float y);

};

#endif
