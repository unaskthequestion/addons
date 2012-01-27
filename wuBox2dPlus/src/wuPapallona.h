//*************************************************************
// byrds & butterflies. just skins w random movement
//*************************************************************

#ifndef wu_PAPALLONA_H
#define wu_PAPALLONA_H

#pragma once
#include "wuBaseSkin.h"

class wuPapallona : public wuBaseSkin
{
    public:
        wuPapallona();
        ~wuPapallona();

		void setup(ofImage *_skin, ofRectangle rect);
        void update();
        void draw(int offX=0);

		ofPoint vel; // skin's velocity 

		float counter_pos; // counter for add a sinus offset to pos.y
		float counter_wid; // counter for change the width 

};
#endif

