#include "wuMarManager.h"

wuMarManager::wuMarManager()
{

}

wuMarManager::~wuMarManager()
{
}

void wuMarManager::addBitxo(ofImage *_skin, ofRectangle rect, ofxCvBlob *blob)
{
	mar.clear();
	wuBase2dShapeManager::setSimpleAmount(3);
	wuBase2dShapeManager::addBitxo(_skin, rect, blob);
	
	mar.setup(_skin, rect, &simpleCountour);
}

void wuMarManager::draw(bool bDrawlines, int offX)
{
    mar.draw(bDrawlines, offX);	
}

void wuMarManager::clear()
{
	mar.clear();
}
