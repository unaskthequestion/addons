
#ifndef wu_PAPALLONAMANAGER_H
#define wu_PAPALLONAMANAGER_H

#pragma once
#include "wuPapallona.h"
#include "wuBaseManager.h"

class wuPapallonaManager : public wuBaseManager
{
    public:
        wuPapallonaManager();
        ~wuPapallonaManager();

		bool capture(ofImage *currImg, ofImage *bgImg);
		void addBitxo(ofImage *_skin, ofRectangle rect);
		void update(); 
		void draw(int offX=0);
        void clear(void);

		// papallones
        vector <wuPapallona> papallones;

};
#endif

