#ifndef wu_ANIMATAXML_H
#define wu_ANIMATAXML_H

#pragma once
#include "wuHumanoid.h"
#include "wuXMLvectorManager.h"
#include "wuSkin.h"
#include "wuAnimata.h"


class wuAnimataXML : public wuHumanoid
{
    public:
        wuAnimataXML();
        ~wuAnimataXML();

        void setup(ofxBox2d * _box2d, string _filename, int _vw, int _vh, vector <wuSkin> * _skins, ofRectangle rect);
		void update();
		void draw(bool pinta_bg=false, int _offX=0);

		void OrderSkins();
		void skelCorrection();

		void setSkin( vector <wuSkin> * _skins);
		void MakeFBOimage();
		void updateFrame(vector<pieceInfo> * _newframe);
//		void checkMotion();
		void frame2Skel();

		bool bCaptured, bFirstTime;
		        // ofImage skin
		vector<wuSkin>* skins;

		// XML things
		wuXMLvectorManager XML;
		vector<pieceInfo> frame;

		// animata order
		int ord[11]; // te correct skins order  (we have 11 pieces maximum)
		SkelModified modSkel; 	// new skeleton point calculation

		// Distancia entre la posició original del movie
		// i la posició on el fem apareixer
//		int kinFrameX, kinFrameY;
		int old_offX, old_offY;

};
#endif

