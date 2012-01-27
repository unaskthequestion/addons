#include "crFBOImagePlus.h"

crFBOImagePlus::crFBOImagePlus() {
//    init();
}

//----------------------------------------------------  
void crFBOImagePlus::setFromFBOTexture(ofxFBOTexture * myFBO){  

	this->setImageType(OF_IMAGE_COLOR_ALPHA);
    this->clear();
    this->setFromPixels((unsigned char*)myFBO->getPixels(), myFBO->getWidth(), myFBO->getHeight(), OF_IMAGE_COLOR_ALPHA );
	this->mirror(false,true);
}  

void crFBOImagePlus::draw(float x, float y, float w, float h){
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	this->draw(x,y,w,h);
	ofEnableAlphaBlending();
}

void crFBOImagePlus::draw(float x, float y){
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	this->draw(x,y);
	ofEnableAlphaBlending();
}

