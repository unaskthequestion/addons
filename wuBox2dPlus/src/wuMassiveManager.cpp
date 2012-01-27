#include "wuMassiveManager.h"

wuMassiveManager::wuMassiveManager()
{

}

wuMassiveManager::~wuMassiveManager()
{
}

void wuMassiveManager::setup(ofxBox2d * _box2d, int _vw, int _vh)
{
	wuBase2dManager::setup(_box2d, _vw, _vh);
	tri_res=50;
	lin_damp = 0.25;
	restitution = 0.0f;
	friction = 5.0;
}

void wuMassiveManager::setResolution(int res)
{
	tri_res = res; 
}

void wuMassiveManager::setParams(float _lin_damp, float _restitution, float _friction)
{
	lin_damp = _lin_damp;
	restitution = _restitution;
	friction = _friction;
}

void wuMassiveManager::addBitxo(ofImage *_skin, ofRectangle rect, ofxCvBlob *blob)
{
	ofxTriangle tri;
	tri.clear();
	tri.triangulate(*blob, tri_res);

	wuMassive massive;
	massive.setup(box2d, _skin, rect, tri.triangles, lin_damp, restitution, friction);
	massives.push_back(massive);
}
void wuMassiveManager::update()
{
        for (int i = 0; i < massives.size(); i++)
            massives[i].update();	
}

void wuMassiveManager::draw(bool bDrawlines, int offX)
{
        for (int i = 0; i < massives.size(); i++)
            massives[i].draw(offX);	
}

void wuMassiveManager::clear()
{
    for (int i = 0; i < massives.size(); i++)
		massives[i].clear();
	massives.clear();
}

void wuMassiveManager::touch(int _x,int _y, int forceX, int forceY)
{
   for (int i = 0; i < massives.size(); i++)
		massives[i].touch(_x, _y, forceX, forceY);
}
