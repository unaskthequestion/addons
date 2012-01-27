#include "wuNuvolManager.h"

wuNuvolManager::wuNuvolManager()
{

}

wuNuvolManager::~wuNuvolManager()
{
}

bool wuNuvolManager::capture(ofImage *currImg, ofImage *bgImg)
{
	bool bCambiazo = true;

	wuBaseManager::capture(currImg, bgImg);

	return bCambiazo;
}

void wuNuvolManager::addBitxo(ofImage *_skin, ofRectangle rect, ofxCvBlob *blob )
{
	wuNuvol nuvol;
	nuvol.setup(box2d, _skin, rect);
	nuvols.push_back(nuvol);
}

void wuNuvolManager::draw(bool bDrawlines, int offX)
{
        for (int i = 0; i < nuvols.size(); i++)
            nuvols[i].draw(bDrawlines, offX);	
}

void wuNuvolManager::update()
{
        for (int i = 0; i < nuvols.size(); i++)
            nuvols[i].update();	
}

void wuNuvolManager::startRain()
{
    for (int i = 0; i < nuvols.size(); i++)
		nuvols[i].startRain();
}
void wuNuvolManager::stopRain()
{
    for (int i = 0; i < nuvols.size(); i++)
		nuvols[i].stopRain();
}
void wuNuvolManager::clear()
{
    for (int i = 0; i < nuvols.size(); i++)
		nuvols[i].clear();
	nuvols.clear();
}

void wuNuvolManager::touch(int _x,int _y, int forceX, int forceY)
{
    for (int i = 0; i < nuvols.size(); i++)
		nuvols[i].touch(_x, _y, forceX, forceY);
}

void wuNuvolManager::drag(int _x,int _y)
{
    for (int i = 0; i < nuvols.size(); i++)
		nuvols[i].drag(_x, _y);
}