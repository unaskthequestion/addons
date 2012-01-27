
#ifndef wu_SKIN_H
#define wu_SKIN_H

#pragma once
#include "wuBaseSkin.h"
#include "wuRain.h"

class wuSkin : public wuBaseSkin
{
    public:
        wuSkin();
        ~wuSkin();

		void setup(ofImage *_skin, ofRectangle rect);

};
#endif

