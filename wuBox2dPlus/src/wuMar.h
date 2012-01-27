#ifndef wu_MAR_H
#define wu_MAR_H

#pragma once
#include "wuBaseSkin.h"

class wuMar : public wuBaseSkin
{
    public:
        wuMar();
        ~wuMar();

		void setup(ofImage *_skin, ofRectangle rect, vector <ofPoint> *_simpleCountour);
        void draw(bool pinta_bg=false, int offX=0);
        void clear(void);
		int getNivell(ofPoint pos);

		vector <ofPoint> simpleCountour;
};
#endif

