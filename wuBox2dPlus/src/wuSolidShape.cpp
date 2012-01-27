#include "wuSolidShape.h"

wuSolidShape::wuSolidShape()
{

}

wuSolidShape::~wuSolidShape()
{
}


void wuSolidShape::setup(ofxBox2d * _box2d, ofRectangle rect, vector <ofPoint> *simpleCountour)
{
	// solidShape without skin
	wuBase2d::setup(_box2d, rect);

	for(int j=(*simpleCountour).size()-1; j>-1; j--) {
		lineStrip.addPoint((*simpleCountour)[j].x, (*simpleCountour)[j].y);
	}
				
	lineStrip.setWorld(box2d->getWorld());
	lineStrip.setElasticity(0.);
	lineStrip.createShape();

}

void wuSolidShape::setup(ofxBox2d * _box2d, ofImage *_skin, ofRectangle rect, vector <ofPoint> *simpleCountour)
{
	// solidShape with skin
	wuBase2d::setup(_box2d, rect);
	wuBaseSkin::setSkin(_skin, rect);

	for(int j=(*simpleCountour).size()-1; j>-1; j--) {
		lineStrip.addPoint((*simpleCountour)[j].x, (*simpleCountour)[j].y);
	}
				
	lineStrip.setWorld(box2d->getWorld());
	lineStrip.setElasticity(0.);
	lineStrip.createShape();

}

void wuSolidShape::draw(bool bDrawlines, int offX)
{
	wuBaseSkin::draw(offX);

	if(bDrawlines && offX==0)
    {
        ofSetColor(0,255,255);
		lineStrip.draw();
    }
}

void wuSolidShape::clear()
{
	lineStrip.clear();
}

