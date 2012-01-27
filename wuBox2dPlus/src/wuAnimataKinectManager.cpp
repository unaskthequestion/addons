#include "wuAnimataKinectManager.h"

wuAnimataKinectManager::wuAnimataKinectManager()
{

}

wuAnimataKinectManager::~wuAnimataKinectManager()
{
}

void wuAnimataKinectManager::setup(ofxBox2d * _box2d, wuKinectSkel * _kinSkel, int _vw, int _vh)
{   
	kinSkel = _kinSkel;
	wuBase2dManager::setup(_box2d, _vw, _vh);
	bSkinOn = false;
}

bool wuAnimataKinectManager::capture(ofImage *currImg, ofImage *bgImg)
{

	wuBaseManager::capture(currImg, bgImg);

	if(skins.size() > 0)
	{
		animata.setup(box2d, 310, 9);
		animata.setSkin( &skins );
	}
	return true;
}

bool wuAnimataKinectManager::capture( vector <wuSkin> * _skins)
{
    for (int i = 0; i < _skins->size(); i++)
	{
		skins.push_back((*_skins)[i]);
	}

	if(skins.size() > 0)
	{
		animata.setup(box2d, 310, 9);
		animata.setSkin( &skins );
	}
	return false;
}

void wuAnimataKinectManager::addBitxo(ofImage *_skin, ofRectangle rect, ofxCvBlob *blob )
{
//	if(!bSkinOn)
//	{
		// capturo els skins de les peces
		wuSkin skin;
		skin.setup(_skin, rect);
		skins.push_back(skin);
//	}
}

void wuAnimataKinectManager::update()
{
//        for (int i = 0; i < animatas.size(); i++)
	if(skins.size()>0)
	{
       animata.setSkel(kinSkel->getSkeleton() );
	   animata.update();
	}
}

void wuAnimataKinectManager::draw(bool bDrawlines, int offX)
{
//        for (int i = 0; i < animatas.size(); i++)
	if(skins.size()>0)
            animata.draw(bDrawlines, offX);	
}

void wuAnimataKinectManager::clear()
{
//   for (int i = 0; i < animals.size(); i++)
//		animals[i].clear();
//   animatas.clear();
   skins.clear();
}

void wuAnimataKinectManager::touch(int _x,int _y, int forceX, int forceY)
{
 //   for (int i = 0; i < animals.size(); i++)
//		animals[i].touch(_x, _y, forceX, forceY);
}

void wuAnimataKinectManager::drag(int _x, int _y)
{
 //       for (int i = 0; i < animals.size(); i++)
 //           animals[i].drag(_x,_y);	
}
