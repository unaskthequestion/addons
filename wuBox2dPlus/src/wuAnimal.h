#ifndef wu_ANIMAL_H
#define wu_ANIMAL_H

#pragma once
#include "wuEnte.h"
//#include "ofxFBOTexture.h"
#include "wuXMLvectorManager.h"
#include "wuSkin.h"

class wuAnimal : public wuEnte
{
    public:
        wuAnimal();
        ~wuAnimal();

        void setup(ofxBox2d * _box2d, string _filename, int _vw, int _vh, vector <wuSkin> * _skins, ofRectangle rect);
		void update();
		void draw(bool pinta_bg=false, int _offX=0);

		void setSkin( vector <wuSkin> * _skins);
		void MakeFBOimage();
		void updateFrame(vector<pieceInfo> * _newframe);
		void checkMotion();

		bool bCaptured, bFirstTime;
		        // ofImage skin
		vector<wuSkin>* skins;
		// Texture mix
		ofxFBOTexture myFBO;

		wuXMLvectorManager XML;
		vector<pieceInfo> frame;

		// Distancia entre la posició original del movie
		// i la posició on el fem apareixer
//		int kinFrameX, kinFrameY;
		int old_offX, old_offY, offsetX, offsetY;

};
#endif

