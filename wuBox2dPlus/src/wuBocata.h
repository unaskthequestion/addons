
#ifndef wu_BOCATA_H
#define wu_BOCATA_H

#pragma once
#include "wuBaseSkin.h"
#include "wuRain.h"

class wuBocata : public wuBaseSkin
{
    public:
        wuBocata();
        ~wuBocata();

		void setup(ofImage *_skin, ofRectangle rect);
		void update(ofPoint _pos);

		float counter;
};
#endif

