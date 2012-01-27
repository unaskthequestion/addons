#include "wuBase2dShapeManager.h"

wuBase2dShapeManager::wuBase2dShapeManager()
{

}

wuBase2dShapeManager::~wuBase2dShapeManager()
{
}

void wuBase2dShapeManager::setup(ofxBox2d * _box2d, int _vw, int _vh)
{
	wuBase2dManager::setup(_box2d, _vw, _vh);

	simpleAmount = 5.0;
	contourAnalysis.setSize(vw, vh);

	// if I need no shapes
	bBypass = false;
}

void wuBase2dShapeManager::setSimpleAmount(int _simpleAmount){
   	simpleAmount = _simpleAmount;
}

void wuBase2dShapeManager::bypass(bool _bBypass){
   	bBypass = _bBypass;
}


void wuBase2dShapeManager::addBitxo(ofImage *_skin, ofRectangle rect, ofxCvBlob *blob)
{
	contourAnalysis.simplify(blob->pts, simpleCountour, simpleAmount);
}