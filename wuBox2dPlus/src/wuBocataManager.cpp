#include "wuBocataManager.h"

wuBocataManager::wuBocataManager()
{
}

wuBocataManager::~wuBocataManager()
{
}

void wuBocataManager::setup(int _vw, int _vh)
{
	wuBaseManager::setup(_vw, _vh);
	bBocataOn = false;
}

bool wuBocataManager::capture(ofImage *currImg, ofImage *bgImg)
{
	bool bCambiazo;

	if(bBocataOn)
	{
		bBocataOn = false;
		bCambiazo = false;
	}
	else
	{
		wuBaseManager::capture(currImg, bgImg);
		bBocataOn = true;
		bCambiazo = true;
	}
	return bCambiazo;
}

void wuBocataManager::addBitxo(ofImage *_skin, ofRectangle rect, ofxCvBlob *blob)
{
	bocata.setup(_skin, rect);
}

void wuBocataManager::update(ofPoint _pos)
{
	if(bBocataOn)
		bocata.update(_pos);	
}

void wuBocataManager::draw(int offX)
{
	if(bBocataOn)
		bocata.draw(offX);	
}
