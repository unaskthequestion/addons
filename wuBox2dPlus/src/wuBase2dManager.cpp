#include "wuBase2dManager.h"

wuBase2dManager::wuBase2dManager()
{

}

wuBase2dManager::~wuBase2dManager()
{
}

void wuBase2dManager::setup(ofxBox2d * _box2d, int _vw, int _vh)
{
	box2d = _box2d;
	wuBaseManager::setup(_vw, _vh);
}

