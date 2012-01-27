#include "wuSolidRectManager.h"

wuSolidRectManager::wuSolidRectManager()
{

}

wuSolidRectManager::~wuSolidRectManager()
{
}

void wuSolidRectManager::setup(ofxBox2d * _box2d, int _vw, int _vh)
{   
	wuBase2dManager::setup(_box2d, _vw, _vh);
	bSkinOn = false;
}

bool wuSolidRectManager::capture(ofImage *currImg, ofImage *bgImg, ofPoint _pos)
{

	if(!bSkinOn)
	{
		wuBaseManager::capture(currImg, bgImg);
		bSkinOn = true;
	}
	else
		createNewSolidRect(_pos);

	return false;
}

void wuSolidRectManager::addBitxo(ofImage *_skin, ofRectangle rect, ofxCvBlob *blob )
{
	generalSkin.setFromPixels(_skin->getPixels(), rect.width, rect.height, OF_IMAGE_COLOR_ALPHA);
}

void wuSolidRectManager::update()
{
        for (int i = 0; i < boxes.size(); i++)
            boxes[i].update();	
}

void wuSolidRectManager::draw(bool bDrawlines, int offX)
{
        for (int i = 0; i < boxes.size(); i++)
            boxes[i].draw(offX);	
}

void wuSolidRectManager::clear()
{
//   for (int i = 0; i < boxes.size(); i++)
//		boxes[i].clear();
	boxes.clear();
}

void wuSolidRectManager::touch(int _x,int _y, int forceX, int forceY)
{
    for (int i = 0; i < boxes.size(); i++)
		boxes[i].touch(_x, _y, forceX, forceY);
}

void wuSolidRectManager::drag(int _x, int _y)
{
        for (int i = 0; i < boxes.size(); i++)
            boxes[i].drag(_x,_y);	
}

void wuSolidRectManager::createNewSolidRect(ofPoint _pos)
{
		float w = ofRandom(7, 30);	
		float h = ofRandom(7, 30);	

		wuSolidRect box;
		box.setPhysics(3.0, 0.53, 0.1);
		box.setup(box2d->getWorld(), _pos.x, _pos.y, w, h);
		box.setDim(w,h);
		box.setImg( &generalSkin );
		boxes.push_back(box);
}
