#include "wuSolidCircle.h"

wuSolidCircle::wuSolidCircle()
{

}

wuSolidCircle::~wuSolidCircle()
{
}


void wuSolidCircle::set2d(ofxBox2d * _box2d, ofRectangle rect)
{
	wuBase2d::setup(_box2d, rect);

	// base rectangle
	base.setPhysics(0.0001, 0.79, 0.01);
	base.setup(box2d->getWorld(), rect.x+rect.width/2, rect.y+rect.height/2, rect.width/2);

}

void wuSolidCircle::setup(ofxBox2d * _box2d, ofImage *_skin, ofRectangle rect)
{
	wuBaseSkin::setSkin(_skin, rect);
	set2d(_box2d, rect);
}

void wuSolidCircle::setup(ofxBox2d * _box2d, ofRectangle rect)
{
	set2d(_box2d, rect);
}

void wuSolidCircle::draw(bool bDrawlines, int offX)
{
	wuBaseSkin::draw(offX);

	if(bDrawlines && offX==0)
         base.draw();
}

void wuSolidCircle::update()
{
	// l' skin es mou amb la base
	posSkin = base.getPosition();
	angSkin = base.getRotation()/OFX_BOX2D_SCALE;

}

void wuSolidCircle::clear()
{
	box2d->world->DestroyBody(base.body);
}

void wuSolidCircle::setPosition(int _x,int _y)
{
	base.moveTo(_x,_y);
}

void wuSolidCircle::touch(int _x,int _y, int forceX, int forceY)
{
	ofPoint pos;
	int rad;
	
    pos = base.getPosition();
	rad = base.getRadius();

	if( (_x > pos.x-rad) && (_x < pos.x+rad) && (_y > pos.y-rad) && (_y < pos.y+rad) ) 
	{
		if(forceX>0)
		{
			if( (_x > pos.x-rad) && (_x < pos.x)) 
				base.addForce(ofPoint(pos.x-rad,pos.y), ofPoint(forceX,0));
			if( (_x > pos.x) && (_x < pos.x+rad)) 
				base.addForce(ofPoint(pos.x+rad,pos.y), ofPoint(0-forceX,0));
		}
		if(forceY>0)
		{
			if( (_y > pos.y-rad) && (_y < pos.y) ) 
				base.addForce(ofPoint(pos.x,pos.y-rad), ofPoint(0,0-forceY));
			if( (_y > pos.y) && (_y < pos.y+rad) ) 
				base.addForce(ofPoint(pos.x,pos.y+rad), ofPoint(0,forceY));
		}
	}
}

void wuSolidCircle::drag(int _x,int _y)
{
	ofPoint pos;
	int rad;
	
    pos = base.getPosition();
	rad = base.getRadius();

	if( (_x > pos.x-rad) && (_x < pos.x+rad) && (_y > pos.y-rad) && (_y < pos.y+rad) ) 
		setPosition(_x,_y);
}

void wuSolidCircle::stop()
{
	base.setVelocity(0,0);
}

