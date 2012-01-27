#include "wuSolidShapeManager.h"

wuSolidShapeManager::wuSolidShapeManager()
{

}

wuSolidShapeManager::~wuSolidShapeManager()
{
}

void wuSolidShapeManager::capture(ofImage *currImg, ofImage *bgImg)
{
    for (int i = 0; i < shapes.size(); i++)
		shapes[i].clear();
	shapes.clear();

	wuBase2dShapeManager::capture(currImg, bgImg);

}

void wuSolidShapeManager::addBitxo(ofImage *_skin, ofRectangle rect, ofxCvBlob *blob)
{
	wuBase2dShapeManager::addBitxo(_skin, rect, blob);

	wuSolidShape shape;
	shape.setup(box2d, rect, &simpleCountour);
	shapes.push_back(shape);
}

void wuSolidShapeManager::draw(bool bDrawlines, int offX)
{
        for (int i = 0; i < shapes.size(); i++)
            shapes[i].draw(bDrawlines, offX);	
}

void wuSolidShapeManager::clear()
{
    for (int i = 0; i < shapes.size(); i++)
		shapes[i].clear();
	shapes.clear();
}
