#include "wuForegroundSkinManager.h"

wuForegroundSkinManager::wuForegroundSkinManager()
{
}

wuForegroundSkinManager::~wuForegroundSkinManager()
{
}

bool wuForegroundSkinManager::capture(ofImage *currImg, ofImage *bgImg)
{
	bool bCambiazo = false;

	skins.clear();

	wuBaseManager::capture(currImg, bgImg);

	return bCambiazo;
}

void wuForegroundSkinManager::addBitxo(ofImage *_skin, ofRectangle rect, ofxCvBlob *blob)
{
	wuSkin skin;
	skin.setup(_skin, rect);
	skins.push_back(skin);
}

void wuForegroundSkinManager::draw(int offX)
{
        for (int i = 0; i < skins.size(); i++)
            skins[i].draw(offX);	
}

void wuForegroundSkinManager::clear()
{
	skins.clear();
}

