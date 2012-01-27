#include "wuPlatformManager.h"

wuPlatformManager::wuPlatformManager()
{

}

wuPlatformManager::~wuPlatformManager()
{
}

void wuPlatformManager::addBitxo(ofImage *_skin, ofRectangle rect, ofxCvBlob *blob)
{
	wuBase2dShapeManager::setSimpleAmount(1);

	wuBase2dShapeManager::addBitxo(_skin, rect, blob);
	
	wuSolidShape shape;
	shape.setup(box2d, _skin, rect, &simpleCountour);
	shapes.push_back(shape);
}

void wuPlatformManager::draw(bool bDrawlines, int offX)
{
        for (int i = 0; i < shapes.size(); i++)
            shapes[i].draw(bDrawlines, offX);	
}

void wuPlatformManager::clear()
{
    for (int i = 0; i < shapes.size(); i++)
		shapes[i].clear();
	shapes.clear();
}
